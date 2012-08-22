/*
Copyright (c) 2003, JAWA Management Software GmbH http://www.jawa.at
All rights reserved.

Redistribution and use in source and binary forms, with or without 
modification, are permitted provided that the following conditions 
are met:

1. Redistributions of source code must retain the above copyright 
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright 
   notice, this list of conditions and the following disclaimer in the 
   documentation and/or other materials provided with the distribution.
3. The names of the authors may not be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND 
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY 
OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

This code cannot simply be copied and put under the GNU Public License or 
any other GPL-like (LGPL, GPL2) License.

    $Id$

Author: Michael Bretterklieber <mbretter@jawa.at>
	    Philippe Tjon A Hen <philippe@tjonahen.nl>
		Pierrick Charron <pierrick@php.net>

*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "php_network.h"
#include "ext/standard/info.h"
#include "php_mqseries.h"

/* {{{ helper methods 
 */
static void _mqseries_disc(zend_rsrc_list_entry *rsrc TSRMLS_DC);
static void _mqseries_close(zend_rsrc_list_entry *rsrc TSRMLS_DC);
static void _mqseries_bytes(zend_rsrc_list_entry *rsrc TSRMLS_DC);

#define MQSERIES_TRUE  1
#define MQSERIES_FALSE 0

static void set_msg_desc_from_array(zval *array, PMQMD msg_desc TSRMLS_DC);
static void set_array_from_msg_desc(zval *return_value, PMQMD msg_desc TSRMLS_DC);

static void set_obj_desc_from_array(zval *array, PMQOD obj_desc);
static void set_array_from_obj_desc(zval *array, PMQOD obj_desc);

static void set_put_msg_opts_from_array(zval *array, PMQPMO put_msg_opts TSRMLS_DC);
static void set_array_from_put_msg_opts(zval *array, PMQPMO put_msg_opts);

static void set_get_msg_opts_from_array(zval *array, PMQGMO get_msg_opts TSRMLS_DC);
static void set_array_from_get_msg_opts(zval *array, PMQGMO get_msg_opts TSRMLS_DC);


static void set_connect_opts_from_array(zval *array,
						PMQCNO connect_opts, 
						PMQCD channel_definition,
						PMQSCO ssl_configuration,
						PMQAIR auth_inf_record,
						PMQCHAR LDAPUserName);

static int is_compcode_reason_ref(zval *z_comp_code, zval *z_reason);
static int is_called_by_ref(zval *param, char *param_name);
/* }}} */

/* If you declare any globals in php_mqseries.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(mqseries)
*/

/* True global resources - no need for thread safety here */
static int le_mqseries_conn;
static int le_mqseries_obj;
static int le_mqseries_bytes;

static HashTable *ht_reason_texts;

/* {{{ Macros */
#define MQSERIES_SETOPT_LONG(s,m) \
    if (zend_hash_find(ht, #m, sizeof(#m), (void**)&tmp) == SUCCESS) {\
        convert_to_long(*tmp); \
        s->m = Z_LVAL_PP(tmp); \
    }
#define MQSERIES_SETOPT_STRING(s,m) \
    if (zend_hash_find(ht, #m, sizeof(#m), (void**)&tmp) == SUCCESS && \
        Z_TYPE_PP(tmp) == IS_STRING) { \
        strncpy(s->m, Z_STRVAL_PP(tmp), sizeof(s->m)); \
    }
/* }}} */

/* {{{ arginfo */
ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_back, 0 ,0, 3)
	ZEND_ARG_INFO(0, hconn)
	ZEND_ARG_INFO(1, compCode)
	ZEND_ARG_INFO(1, reason)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_begin,0 ,0, 4)
	ZEND_ARG_INFO(0, hconn)
	ZEND_ARG_ARRAY_INFO(0, beginOptions, 0)
	ZEND_ARG_INFO(1, compCode)
	ZEND_ARG_INFO(1, reason)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_close,0 ,0, 5)
	ZEND_ARG_INFO(0, hconn)
	ZEND_ARG_INFO(1, hobj)
	ZEND_ARG_INFO(0, options)
	ZEND_ARG_INFO(1, compCode)
	ZEND_ARG_INFO(1, reason)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_cmit,0 ,0, 3)
	ZEND_ARG_INFO(0, hconn)
	ZEND_ARG_INFO(1, compCode)
	ZEND_ARG_INFO(1, reason)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_conn, 0, 0, 4)
         ZEND_ARG_INFO(0, qMgrName)
         ZEND_ARG_INFO(1, hconn)
         ZEND_ARG_INFO(1, compCode)
         ZEND_ARG_INFO(1, reason)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_connx, 0, 0, 5)
         ZEND_ARG_INFO(0, qMgrName)
         ZEND_ARG_ARRAY_INFO(1, connectOpts, 0)
         ZEND_ARG_INFO(1, hconn)
         ZEND_ARG_INFO(1, compCode)
         ZEND_ARG_INFO(1, reason)
ZEND_END_ARG_INFO()
      
ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_disc,0 ,0, 3)
	ZEND_ARG_INFO(0, hconn)
	ZEND_ARG_INFO(1, compCode)
	ZEND_ARG_INFO(1, reason)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_get,0 ,0, 9)
	ZEND_ARG_INFO(0, hconn)
	ZEND_ARG_INFO(0, hobj)
	ZEND_ARG_ARRAY_INFO(1, msgDesc, 0)
	ZEND_ARG_ARRAY_INFO(1, getMsgOts, 0)
	ZEND_ARG_INFO(0, bufferlength)
	ZEND_ARG_INFO(1, buffer)
	ZEND_ARG_INFO(1, dataLength)
	ZEND_ARG_INFO(1, compCode)
	ZEND_ARG_INFO(1, reason)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_inq,0 ,0, 10)
	ZEND_ARG_INFO(0, hconn)
	ZEND_ARG_INFO(0, hobj)
	ZEND_ARG_INFO(0, selectorCount)
	ZEND_ARG_ARRAY_INFO(0, selectors, 0)
	ZEND_ARG_INFO(0, intAttrCount)
	ZEND_ARG_INFO(1, intAttrs)
	ZEND_ARG_INFO(0, charAttrLength)
	ZEND_ARG_INFO(1, charAttrs)
	ZEND_ARG_INFO(1, compCode)
	ZEND_ARG_INFO(1, reason)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_open,0 ,0, 6)
	ZEND_ARG_INFO(0, hconn)
	ZEND_ARG_ARRAY_INFO(1, objDesc, 0)
	ZEND_ARG_INFO(0, options)
	ZEND_ARG_INFO(1, hobj)
	ZEND_ARG_INFO(1, compCode)
	ZEND_ARG_INFO(1, reason)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_put,0 ,0, 7)
	ZEND_ARG_INFO(0, hconn)
	ZEND_ARG_INFO(0, hobj)
	ZEND_ARG_ARRAY_INFO(1, msgDesc, 0) 
	ZEND_ARG_ARRAY_INFO(1, putMsgOpts, 0) 
	ZEND_ARG_INFO(0, buffer) 
	ZEND_ARG_INFO(1, compCode)
	ZEND_ARG_INFO(1, reason)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_put1,0 ,0, 7)
	ZEND_ARG_INFO(0, hconn)
	ZEND_ARG_ARRAY_INFO(0, objDesc, 0)
	ZEND_ARG_ARRAY_INFO(1, msgDesc, 0) 
	ZEND_ARG_ARRAY_INFO(1, putMsgOpts, 0) 
	ZEND_ARG_INFO(0, buffer) 
	ZEND_ARG_INFO(1, compCode)
	ZEND_ARG_INFO(1, reason)
ZEND_END_ARG_INFO()
	
	
ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_set,0 ,0, 10)
	ZEND_ARG_INFO(0, hconn)
	ZEND_ARG_INFO(0, hobj)
	ZEND_ARG_INFO(0, selectorCount)
	ZEND_ARG_ARRAY_INFO(0, selectors, 0)
	ZEND_ARG_INFO(0, intAttrCount)
	ZEND_ARG_ARRAY_INFO(0, intAttrs, 0)
	ZEND_ARG_INFO(0, charAttrLength)
	ZEND_ARG_ARRAY_INFO(0, charAttrs, 0)
	ZEND_ARG_INFO(1, compCode)
	ZEND_ARG_INFO(1, reason)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_strerror, 0, 0, 1)
    ZEND_ARG_INFO(0, reason)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_bytes_val, 0, 0, 1)
    ZEND_ARG_INFO(0, resource)
ZEND_END_ARG_INFO()
/* }}} */

/* {{{ mqseries_functions[]
 *
 * Every user visible function must have an entry in mqseries_functions[].
 */
zend_function_entry mqseries_functions[] = {
	PHP_FE(mqseries_back,	arginfo_mqseries_back)
	PHP_FE(mqseries_begin,	arginfo_mqseries_begin)
	PHP_FE(mqseries_close,	arginfo_mqseries_close)
	PHP_FE(mqseries_cmit,	arginfo_mqseries_cmit)
	PHP_FE(mqseries_conn,	arginfo_mqseries_conn)
	PHP_FE(mqseries_connx,  arginfo_mqseries_connx)
	PHP_FE(mqseries_disc,	arginfo_mqseries_disc)
	PHP_FE(mqseries_get,	arginfo_mqseries_get)
	PHP_FE(mqseries_inq,    arginfo_mqseries_inq)
	PHP_FE(mqseries_open,	arginfo_mqseries_open)
	PHP_FE(mqseries_put,	arginfo_mqseries_put)
	PHP_FE(mqseries_put1,   arginfo_mqseries_put1)
	PHP_FE(mqseries_set,    arginfo_mqseries_set)	
	PHP_FE(mqseries_strerror, arginfo_mqseries_strerror)
	PHP_FE(mqseries_bytes_val, arginfo_mqseries_bytes_val)
	{NULL, NULL, NULL}	/* Must be the last line in mqseries_functions[] */
};
/* }}} */

/* {{{ mqseries_module_entry
 */
zend_module_entry mqseries_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"mqseries",
	mqseries_functions,
	PHP_MINIT(mqseries),
	PHP_MSHUTDOWN(mqseries),
	NULL,
	NULL,
	PHP_MINFO(mqseries),
#if ZEND_MODULE_API_NO >= 20010901
	PHP_MQSERIES_VERSION,
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_MQSERIES
ZEND_GET_MODULE(mqseries)
#endif


/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(mqseries)
{
	char *vp = NULL;

	/* don't change the order of these, objects must be freed before connections */
	le_mqseries_obj = zend_register_list_destructors_ex(_mqseries_close, NULL, PHP_MQSERIES_OBJ_RES_NAME, module_number);
	
	le_mqseries_conn = zend_register_list_destructors_ex(_mqseries_disc, NULL, PHP_MQSERIES_DESCRIPTOR_RES_NAME, module_number);
	
	le_mqseries_bytes = zend_register_list_destructors_ex(_mqseries_bytes, NULL, PHP_MQSERIES_BYTES_RES_NAME, module_number);

#include "mqseries_init_const.h"
	
	ht_reason_texts = (HashTable *) malloc(sizeof(HashTable));
	zend_hash_init(ht_reason_texts, 0, NULL, NULL, 1);

#define ADD_MQ_REASON_TXT(key, value) { vp = value; zend_hash_index_update(ht_reason_texts, key, &vp, sizeof(char*), NULL); }
#include "mqseries_reason_texts.h"

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(mqseries)
{
	zend_hash_destroy(ht_reason_texts);
	free(ht_reason_texts);
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(mqseries)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "mqseries support", "enabled");
	php_info_print_table_row(2, "Version", PHP_MQSERIES_VERSION);
	php_info_print_table_row(2, "Revision", "$Revision$");
	php_info_print_table_end();
}
/* }}} */

/* {{{ proto mqseries_conn(string name, resourceref connection, resourceref compcode, resourceref reason )
	Connect to the Queue-Manager with the given name. */
/*
 
	You need either the Channel-Table (usualy in /var/mqm) 
	or set the environment var MQSERVER=<channel>/<proto>/<host>[(port)] MQSERVER=example/TCP/mqs.example.com

PHP sample:	
	
	mqseries_conn('QM_donald', $conn, $compcode, $reason);
	
	if ($compcode !== MQSERIES_MQCC_OK) {
		printf("CompCode:%d Reason:%d Text:%s\n", $compcode, $reason, mqseries_strerror($reason));
		
	}
	
MQ call:	
	MQCONN ( QMgrName   -- input  : QManager name
			, Hconn     -- output : Connection Handle
			, CompCode  -- output : completion code
			, Reason)   -- output : reason code
*/
PHP_FUNCTION(mqseries_conn)
{
	char *name;
	int name_len;
	zval *z_conn, *z_comp_code, *z_reason;

	mqseries_descriptor *mqdesc;

	MQCHAR48 qManagerName;
	MQLONG comp_code;
	MQLONG reason;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "szzz", &name, &name_len,
		&z_conn, &z_comp_code, &z_reason) 
		== FAILURE) {
		return;
	}
	if (!is_called_by_ref(z_conn, "conn")) return ;
	if (!is_compcode_reason_ref(z_comp_code, z_reason)) return;
	
	strncpy(qManagerName, name, sizeof(MQCHAR48));

	mqdesc = (mqseries_descriptor *) emalloc(sizeof(mqseries_descriptor));
	MQCONN(qManagerName, &mqdesc->conn, &comp_code, &reason);

	ZVAL_LONG(z_comp_code, comp_code);
	ZVAL_LONG(z_reason, reason);
	
	if (comp_code == MQCC_OK) {
		ZEND_REGISTER_RESOURCE(z_conn, mqdesc, le_mqseries_conn);
		mqdesc->id = Z_RESVAL_P(z_conn);
	} else {
		efree(mqdesc);
	}
}
/* }}} */

/* {{{ proto mqseries_connx(string name, array connect_opts, resourceref connextion, resourceref compcode, resourceref reason )
	The mqseries_connx call is similar to the mqseries_conn call, except that mqseries_connx allows options to be specified to control the way that the call works.*/
/*

PHP sample:	
	$mqcno = array(
				'StrucId' => MQSERIES_MQCNO_STRUC_ID,
				'Version' => MQSERIES_MQCNO_VERSION_2,
				'Options' => MQSERIES_MQCNO_STANDARD_BINDING,
				'MQCD' => array('ChannelName' => 'D800MQ.CLIENT'
								,'ConnectionName' => 'localhost'
								,'TransportType' => MQSERIES_MQXPT_TCP
-- SSL configuration with one Authorisation Information Record is also posible								
--								,'MQSCO' => array('MQAIR' => array() )
								)
				);

	mqseries_connx('D800MQ',
					$mqcno,
					$conn,
					$comp_code,
					$reason
				);
	if ($comp_code !== MQSERIES_MQCC_OK) {
		printf("CompCode:%d Reason:%d Text:%s<br>\n", $comp_code, $reason, mqseries_strerror($reason));
		exit;
	}

MQ call:		
	The MQCONNX call is similar to the MQCONN call, except that MQCONNX allows 
	options to be specified to control the way that the call works.
	MQCONNX ( QMgrName   	-- input  		 : QManager name
			, ConnectOpts 	-- input/output  : Connction options
			, Hconn     	-- output 		 : Connection Handle
			, CompCode  	-- output   	 : completion code
			, Reason)   	-- output        : reason code
*/
PHP_FUNCTION(mqseries_connx)
{
	char *name;
	int name_len;
	mqseries_descriptor *mqdesc;
	zval *z_connect_opts, *z_conn, *z_comp_code, *z_reason;

	MQLONG comp_code; 
	MQLONG reason;
	MQCNO connect_opts 			= {MQCNO_DEFAULT};
	MQCD  channel_definition    = {MQCD_CLIENT_CONN_DEFAULT};
	MQSCO ssl_configuration     = {MQSCO_DEFAULT};
	MQAIR authentication_information_record = {MQAIR_DEFAULT} ; /* Only 1 (one) record is supported for now. */
	MQCHAR LDAPUserName[MQ_DISTINGUISHED_NAME_LENGTH];

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sazzz", &name, &name_len, 
		&z_connect_opts, &z_conn, &z_comp_code, &z_reason)
		== FAILURE) {
		return ;
	}

	if (!is_called_by_ref(z_conn, "conn")) return ;
	if (!is_compcode_reason_ref(z_comp_code, z_reason)) return;
	
	set_connect_opts_from_array(z_connect_opts, &connect_opts, &channel_definition, &ssl_configuration, &authentication_information_record, LDAPUserName);
		
	mqdesc = (mqseries_descriptor *) emalloc(sizeof(mqseries_descriptor));
	
	MQCONNX(name, &connect_opts, &mqdesc->conn, &comp_code, &reason);

/*
 *  TODO: what fields can be output for the connect opts? 
 */

	ZVAL_LONG(z_comp_code, comp_code);
	ZVAL_LONG(z_reason, reason);

	if (comp_code == MQCC_OK) {
		ZEND_REGISTER_RESOURCE(z_conn, mqdesc, le_mqseries_conn);
		mqdesc->id = Z_RESVAL_P(z_conn);
	} else {
		efree(mqdesc);
	}
}
/* }}} */

/* {{{ proto mqseries_open(resource connection, array obj_desc, int options, resourceref object_handle, resourceref compcode, resourceref reason) 
	Open a Queue. */
/*

	
PHP sample
	mqseries_open(
		$conn,
		array('ObjectName' => 'TESTQ', 'ObjectQMgrName' => 'D800MQ'),
		MQSERIES_MQOO_INPUT_AS_Q_DEF | MQSERIES_MQOO_FAIL_IF_QUIESCING | MQSERIES_MQOO_OUTPUT,
		$obj,
		$comp_code,
		$reason);
		
	if ($comp_code !== MQSERIES_MQCC_OK) {
		printf("CompCode:%d Reason:%d Text:%s<br>\n", $comp_code, $reason, mqseries_strerror($reason));
		exit;
	}

MQ call:	
	MQOPEN (Hconn, -- input : connection handle 
		ObjDesc,   -- input/output : object description
		Options,   -- input : open options
		Hobj,      -- output : object handle
		CompCode,  -- output : completion code 
		Reason)	   -- output : reason code
*/
PHP_FUNCTION(mqseries_open)
{
	mqseries_descriptor *mqdesc;
	mqseries_obj *mqobj;
	zval *z_mqdesc, *z_obj_desc, *z_obj, *z_comp_code, *z_reason;

	MQLONG open_options; 
	MQLONG comp_code; 
	MQLONG reason;
	MQOD obj_desc = {MQOD_DEFAULT}; 

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ralzzz", &z_mqdesc, 
		&z_obj_desc, &open_options, &z_obj, &z_comp_code, &z_reason) 
		== FAILURE) {
		return;
	}

	if (!is_called_by_ref(z_obj, "obj")) return ;
	if (!is_compcode_reason_ref(z_comp_code, z_reason)) return;

	ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);
	
	set_obj_desc_from_array(z_obj_desc, &obj_desc);

	mqobj = (mqseries_obj *) emalloc(sizeof(mqseries_obj));
	
	MQOPEN(	mqdesc->conn, &obj_desc, open_options, &mqobj->obj, &comp_code, &reason);

	ZVAL_LONG(z_comp_code, comp_code);
	ZVAL_LONG(z_reason, reason);
	if (PZVAL_IS_REF(z_obj_desc)) {
		set_array_from_obj_desc(z_obj_desc, &obj_desc);
	}
	if (comp_code == MQCC_OK) {
		mqobj->conn = &mqdesc->conn;
		ZEND_REGISTER_RESOURCE(z_obj, mqobj, le_mqseries_obj);
		mqobj->id = Z_RESVAL_P(z_obj);
	} else {
		/* So we don't register the ref. But we already allocated some memory lets free that */
		efree(mqobj);		
	}
}
/* }}} */

/* {{{ proto mqseries_get(resource mqdesc, resource mqobj,resourceref msg_desc, resourceref get_msg_opts, int buf_len, resourceref buffer, resourceref data_length, resourceref compcode, resourceref reason)
	Read data from an opened queue. */
/*


PHP sample

-- Make default message description the get method will fill this in with defaults.
$mqmd = array();

$mqgmo = array('Options' => MQSERIES_MQGMO_FAIL_IF_QUIESCING | MQSERIES_MQGMO_WAIT,
	           'WaitInterval' => MQSERIES_MQWI_UNLIMITED);
mqseries_get(
	$conn, 
	$obj,
	$mqmd,              
	$mqmo,
	10,
	$msg,
	$data_length,
	$comp_code,
	$reason);
	
if ($comp_code !== MQSERIES_MQCC_OK) {
	printf("CompCode:%d Reason:%d Text:%s<br>", $comp_code, $reason, mqseries_strerror($reason));
}
	
	
MQ call:	
	MQGET ( Hconn, 			-- input
			Hobj, 			-- input
			MsgDesc, 		-- input/output
			GetMsgOpts,     -- input/output
			BufferLength,   -- input
			Buffer,         -- output
			DataLength     -- output
			, CompCode  -- output : completion code
			, Reason)   -- output : reason code

Note: MQMD - Message Descriptor fields are first set to MQMD_DEFAULT. Before the 
      values of the array are taken.			
*/
PHP_FUNCTION(mqseries_get)
{
	mqseries_descriptor *mqdesc;
	mqseries_obj *mqobj;
	zval *z_mqdesc, *z_mqobj, *z_msg_desc, *z_get_msg_opts, *z_comp_code, *z_reason, *z_data_length, *z_buffer;
	
	MQLONG comp_code; 
	MQLONG reason;
	MQLONG buf_len = 0L, data_length = 0L;
	MQBYTE *buf, *data;
	MQMD msg_desc = 	 { MQMD_DEFAULT }; 	/* Message descriptor */
	MQGMO get_msg_opts = { MQGMO_DEFAULT }; /* Options which control the MQGET call */
	MQRFH rfh = {MQRFH_DEFAULT};
	MQRFH2 rfh2 = {MQRFH2_DEFAULT};

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rraalzzzz",&z_mqdesc, &z_mqobj,
		&z_msg_desc, &z_get_msg_opts, &buf_len, &z_buffer, &z_data_length,&z_comp_code, &z_reason)
		== FAILURE) {
		return;
	}
	
	if (!is_called_by_ref(z_data_length, "datalength")) return ;
	if (!is_called_by_ref(z_buffer, "buffer")) return ;
	if (!is_compcode_reason_ref(z_comp_code, z_reason)) return;
	

	ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);
	ZEND_FETCH_RESOURCE(mqobj, mqseries_obj *, &z_mqobj, -1, PHP_MQSERIES_OBJ_RES_NAME, le_mqseries_obj);

	set_msg_desc_from_array(z_msg_desc, &msg_desc TSRMLS_CC);
	set_get_msg_opts_from_array(z_get_msg_opts, &get_msg_opts TSRMLS_CC);

	data = buf = (MQBYTE *)emalloc(sizeof(MQBYTE)*buf_len);
	MQGET(mqdesc->conn, mqobj->obj, &msg_desc, &get_msg_opts, buf_len, buf, &data_length, &comp_code, &reason);

/*
 * TODO: add these Rules and formatting header as an resource to the PHP environment
 * There is no other way I can think of to get this to the user.
 * TODO: Other formatting headers, if there are any
 */
	if (!strncmp(msg_desc.Format, MQFMT_RF_HEADER, sizeof(msg_desc.Format))) {
		memcpy(&rfh, buf, MQRFH_STRUC_LENGTH_FIXED);
		data = buf + rfh.StrucLength;
	} else if (!strncmp(msg_desc.Format, MQFMT_RF_HEADER_2, sizeof(msg_desc.Format))) {
		memcpy(&rfh2, buf, MQRFH_STRUC_LENGTH_FIXED_2);
		data = buf + rfh2.StrucLength;
	}

	ZVAL_LONG(z_comp_code, comp_code);
	ZVAL_LONG(z_reason, reason);
	ZVAL_LONG(z_data_length, data_length);

	zval_dtor(z_buffer);
	ZVAL_STRINGL(z_buffer,(char *) data, data_length, 1);
	efree(buf);

	if (PZVAL_IS_REF(z_msg_desc)) {
		set_array_from_msg_desc(z_msg_desc, &msg_desc TSRMLS_CC);
	}
	if (PZVAL_IS_REF(z_get_msg_opts)) {
		set_array_from_get_msg_opts(z_get_msg_opts, &get_msg_opts TSRMLS_CC);
	}

}
/* }}} */

/* {{{ proto mqseries_put(resource mqdesc, resource mqobj, array msg_desc, array put_msg_opts, string msg, resourceref compcode, resourceref reason)
	The MQPUT call puts a message on a queue or distribution list. The queue or distribution list must already be open. */
/*	

PHP sample: 
$md = 	array(
		'Version' => MQSERIES_MQMD_VERSION_1,
		'Expiry' => MQSERIES_MQEI_UNLIMITED,
		'Report' => MQSERIES_MQRO_NONE,
		'MsgType' => MQSERIES_MQMT_DATAGRAM,
		'Format' => MQSERIES_MQFMT_STRING,
		'Priority' => 1,
		'Persistence' => MQSERIES_MQPER_PERSISTENT,
		'ReplyToQ' => 'RCVQ');
mqseries_put($conn, 
				$obj_snd,
				$md,
				array('Options' => MQSERIES_MQPMO_NEW_MSG_ID),
				'Ping',
				$comp_code,
				$reason);
	
if ($comp_code !== MQSERIES_MQCC_OK) {
	printf("CompCode:%d Reason:%d Text:%s<br>\n", $comp_code, $reason, mqseries_strerror($reason));
}


MQ call:

	MQPUT (
			Hconn,			-- input 
			Hobj, 			-- input
			MsgDesc, 		-- input/output
			PutMsgOpts, 	-- input/output
			BufferLength,  	-- input
			Buffer 			-- input
			, CompCode  	-- output : completion code
			, Reason)   	-- output : reason code

Note: MQMD - Message Descriptor fields are first set to MQMD_DEFAULT. Before the 
      values of the array are taken.			
	
*/
PHP_FUNCTION(mqseries_put)
{
	mqseries_descriptor *mqdesc;
	mqseries_obj *mqobj;
	zval *z_mqdesc, *z_mqobj, *z_msg_desc, *z_put_msg_opts, *z_comp_code, *z_reason;
	char  *msg;
	MQLONG msg_len;
	
	MQMD msg_desc = {MQMD_DEFAULT}; /* Message descriptor */
	MQPMO put_msg_opts = {MQPMO_DEFAULT}; /* Options which control the MQPUT call */
	MQLONG comp_code; 
	MQLONG reason; 

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rraaszz", &z_mqdesc, &z_mqobj,
		&z_msg_desc, &z_put_msg_opts, &msg, &msg_len, &z_comp_code, &z_reason)
		== FAILURE) {
		return;
	}

	if (!is_compcode_reason_ref(z_comp_code, z_reason)) return;

	ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);
	ZEND_FETCH_RESOURCE(mqobj, mqseries_obj *, &z_mqobj, -1, PHP_MQSERIES_OBJ_RES_NAME, le_mqseries_obj);

	set_msg_desc_from_array(z_msg_desc, &msg_desc TSRMLS_CC);
	set_put_msg_opts_from_array(z_put_msg_opts, &put_msg_opts TSRMLS_CC);

	MQPUT(mqdesc->conn,	mqobj->obj, &msg_desc, 	&put_msg_opts, msg_len, msg, &comp_code, &reason);

	ZVAL_LONG(z_comp_code, comp_code);
	ZVAL_LONG(z_reason, reason);
	if (PZVAL_IS_REF(z_msg_desc)) {
		set_array_from_msg_desc(z_msg_desc, &msg_desc TSRMLS_CC);
	}
	if (PZVAL_IS_REF(z_put_msg_opts)) {
		set_array_from_put_msg_opts(z_put_msg_opts, &put_msg_opts);
	}	

}
/* }}} */

/* {{{ proto mqseries_begin(resource mqdesc, array begin_opts, resourceref compcode, resourceref reason)
	The MQBEGIN call begins a unit of work that is coordinated by the queue manager, and that may involve external resource managers. */
/*


PHP sample:

	mqseries_begin($conn, 
					array("Options" -> MQSERIES_MQBO_NONE),
					$comp_code,
					$reason)	

MQ call:
	MQBEGIN (Hconn         	-- input  : Connection handle
			, BeginOptions  -- input  : MQBO begin options
			, CompCode  	-- output : completion code
			, Reason)   	-- output : reason code
*/
PHP_FUNCTION(mqseries_begin)
{
	mqseries_descriptor *mqdesc;
	zval *z_mqdesc, *z_array, **option_val, *key, *z_comp_code, *z_reason;
	char  *string_key;
	uint  string_key_len;
	ulong  num_key;
	HashPosition pos;
	MQLONG comp_code; 
	MQLONG reason;

	MQBO begin_opts = {MQBO_DEFAULT};

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "razz", &z_mqdesc,
		&z_array, &z_comp_code, &z_reason) == FAILURE) {
		return;
	}
	
	if (!is_compcode_reason_ref(z_comp_code, z_reason)) return;

	ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);

	zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(z_array), &pos);
	while (zend_hash_get_current_data_ex(Z_ARRVAL_P(z_array), (void **)&option_val, &pos) == SUCCESS) {
		MAKE_STD_ZVAL(key);

		if (zend_hash_get_current_key_ex(Z_ARRVAL_P(z_array), &string_key, &string_key_len, &num_key, 0, &pos) == HASH_KEY_IS_STRING) {
			if (!strcmp(string_key, "Version")) {
				begin_opts.Version = Z_LVAL_PP(option_val);
			} else if (!strcmp(string_key, "Options")) {
				begin_opts.Options = Z_LVAL_PP(option_val);
			}
		}

		zval_ptr_dtor(&key);
		zend_hash_move_forward_ex(Z_ARRVAL_P(z_array), &pos);
	}

	MQBEGIN(mqdesc->conn, &begin_opts, &comp_code, &reason);
	
	ZVAL_LONG(z_comp_code, comp_code);
	ZVAL_LONG(z_reason, reason);
}
/* }}} */

/* {{{ proto  mqseries_cmit(resource mqdesc, resourceref compcode, resourceref reason)
	The MQCMIT call indicates to the queue manager that the application has reached 
	a syncpoint, and that all of the message gets and puts that have occurred 
	since the last syncpoint are to be made permanent. Messages put as part of 
	a unit of work are made available to other applications; messages retrieved 
	as part of a unit of work are deleted. */
/*
	
PHP sample:
	mqseries_cmit($conn,
				&$comp_code,
				&$reason);
	
MQ call:

	MQCMIT (Hconn			-- input  : Connection handle
			, CompCode  	-- output : completion code
			, Reason)   	-- output : reason code
	
*/
PHP_FUNCTION(mqseries_cmit)
{
	MQLONG comp_code; 
	MQLONG reason;

	mqseries_descriptor *mqdesc;
	zval *z_mqdesc, *z_comp_code, *z_reason;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rzz", &z_mqdesc, &z_comp_code, &z_reason)
		== FAILURE) {
		return;
	}

	if (!is_compcode_reason_ref(z_comp_code, z_reason)) return;

	ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);

	MQCMIT(mqdesc->conn, &comp_code, &reason);
	
	ZVAL_LONG(z_comp_code, comp_code);
	ZVAL_LONG(z_reason, reason);

}
/* }}} */

/* {{{ proto mqseries_back(resource mqdesc, resourceref compcode, resourceref reason)
	The MQBACK call indicates to the queue manager that all the message gets and 
	puts that have occurred since the last syncpoint are to be backed out. 
	Messages put as part of a unit of work are deleted; messages retrieved as 
	part of a unit of work are reinstated on the queue.	*/
/*
	
PHP sample:	

MQ call:

	MQBACK (Hconn			-- input  : Connection handle
			, CompCode  	-- output : completion code
			, Reason)   	-- output : reason code
*/
PHP_FUNCTION(mqseries_back)
{
	MQLONG comp_code; 
	MQLONG reason;

	mqseries_descriptor *mqdesc;
	zval *z_mqdesc, *z_comp_code, *z_reason;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rzz", &z_mqdesc, &z_comp_code, &z_reason)
		== FAILURE) {
		return;
	}

	if (!is_compcode_reason_ref(z_comp_code, z_reason)) return;

	ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);

	MQBACK(mqdesc->conn, &comp_code, &reason);
	
	ZVAL_LONG(z_comp_code, comp_code);
	ZVAL_LONG(z_reason, reason);

}
/* }}} */

/* {{{ proto mqseries_close(resoure mqobj, resourceref compcode, resourceref reason)
	The MQCLOSE call relinquishes access to an object, 
	and is the inverse of the MQOPEN call.	*/
/*

Note the way it now works is that an internal delete of the resources is done
this will dan trigger the php delete mechanism	
	
PHP sample:
	mqseries_close($conn, $obj, MQSERIES_MQCO_NONE, $comp_code, $reason);
	
MQ call:
	MQCLOSE (Hconn, 		-- input 
			Hobj, 			-- input
			Options, 		-- input
			, CompCode  	-- output : completion code
			, Reason)   	-- output : reason code
			
*/
PHP_FUNCTION(mqseries_close)
{
	MQLONG comp_code; 
	MQLONG reason;
	MQLONG close_options;

	mqseries_obj *mqobj;
	mqseries_descriptor *mqdesc;
	zval *z_mqdesc, *z_mqobj, *z_comp_code, *z_reason;
	
	zend_output_debug_string(1, "%s", "MQClose - start");

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rrlzz", &z_mqdesc, &z_mqobj, &close_options, &z_comp_code, &z_reason) == FAILURE) {
		zend_output_debug_string(1, "%s", "MQClose - parse error");
		return;
	}
	if (!is_compcode_reason_ref(z_comp_code, z_reason)) {
		zend_output_debug_string(1, "%s", "MQClose - call by ref error");
		return;
	}

	ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);
	ZEND_FETCH_RESOURCE(mqobj, mqseries_obj *, &z_mqobj, -1, PHP_MQSERIES_OBJ_RES_NAME, le_mqseries_obj);
	
	MQCLOSE(mqdesc->conn,
		&mqobj->obj,
		close_options,
		&comp_code,
		&reason);
	
	
	ZVAL_LONG(z_comp_code, comp_code);
	ZVAL_LONG(z_reason, reason);
	
	zend_list_delete(mqobj->id);
	zend_output_debug_string(1, "%s", "MQClose - end");

}
/* }}} */

/* {{{ internal used nethod to close resources void _mqseries_close() */
static void _mqseries_close(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
	MQLONG comp_code;  /* Completion code	*/
	MQLONG reason;     /* Qualifying reason */
	mqseries_obj *mqobj = (mqseries_obj *)rsrc->ptr;

	if (mqobj->obj != MQHO_UNUSABLE_HOBJ) {        /* Already closed */
		if (*mqobj->conn != MQHC_UNUSABLE_HCONN) { /* Already disconeccted */
												   /* Should not be posible but just in case */	
			MQCLOSE(*mqobj->conn,
				&mqobj->obj,
				MQCO_NONE,
				&comp_code,
				&reason);
		
			if ((comp_code != MQCC_OK) || (reason != MQRC_NONE && reason)) {
				switch(reason) {
					case MQRC_CONNECTION_BROKEN:
					case MQRC_HCONN_ERROR:
						break;
		
					default:
#if defined(MQ_64_BIT)						
						zend_error(E_WARNING, "_mqseries_close Error %d %d\n", comp_code, reason);
#else 
						zend_error(E_WARNING, "_mqseries_close Error %ld %ld\n", comp_code, reason);
#endif
				}
		    }
		}
	}
	
	efree(mqobj);
}
/* }}} */

/* {{{ proto mqseries_disc(resource mqdesc, resourceref compcode , resourceref reason)
	The MQDISC call breaks the connection between the queue manager and the 
	application program, and is the inverse of the MQCONN or MQCONNX call.*/
/*
			
PHP sample:

mqseries_disc($conn, $compcode, $reason);
if ($compcode !== MQSERIES_MQCC_OK) {
	printf("CompCode:%d Reason:%d Text:%s<br>\n", $compcode, $reason, mqseries_strerror($reason));
}
	
MQ call:
	MQDISC (Hconn
			, CompCode  	-- output : completion code
			, Reason)   	-- output : reason code
	
*/
PHP_FUNCTION(mqseries_disc)
{
	MQLONG comp_code;  /* Completion code	*/
	MQLONG reason;     /* Qualifying reason */

	mqseries_descriptor *mqdesc;
	zval *z_mqdesc, *z_comp_code, *z_reason;

	zend_output_debug_string(1, "%s", "MQDisc - start");
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rzz", &z_mqdesc, &z_comp_code, &z_reason) == FAILURE) {
		return;
	}
	if (!is_compcode_reason_ref(z_comp_code, z_reason)) return;	

	ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);

	MQDISC(
		&mqdesc->conn,
		&comp_code,
		&reason);


	ZVAL_LONG(z_comp_code, comp_code);
	ZVAL_LONG(z_reason, reason);

	zend_list_delete(mqdesc->id);
	zend_output_debug_string(1, "%s", "MQDisc - end");

}
/* }}} */

/* {{{ internal used disconnect method _mqseries_disc() */
static void _mqseries_disc(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
	MQLONG comp_code;  /* Completion code	*/
	MQLONG reason;     /* Qualifying reason */

	mqseries_descriptor *mqdesc = (mqseries_descriptor *)rsrc->ptr;

	if (mqdesc->conn != MQHC_UNUSABLE_HCONN) { 
		MQDISC(
			&mqdesc->conn,
			&comp_code,
			&reason);
	
		if ((comp_code != MQCC_OK) || (reason != MQRC_NONE)) {
			switch(reason) {
				case MQRC_CONNECTION_BROKEN:
				case MQRC_HCONN_ERROR:
					break;
	
				default:
#if defined(MQ_64_BIT)                      
					zend_error(E_WARNING, "_mqseries_disc Error %d %d\n", comp_code, reason);
#else
					zend_error(E_WARNING, "_mqseries_disc Error %ld %ld\n", comp_code, reason);
#endif
			}
	    }
	}

	efree(mqdesc);
}
/* }}} */

/* {{{ proto string mqseries_strerror(resource reason)
	Returns the detailed error text for the given reason code. */
PHP_FUNCTION(mqseries_strerror)
{
	char **text;
	int reason_code;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &reason_code) == FAILURE) {
		return;
	}

	RETVAL_NULL();

	if (zend_hash_index_find(ht_reason_texts, reason_code, (void **) &text) == SUCCESS) {
		RETVAL_STRING(*text, 1);
	}

}
/* }}} */

/* {{{ proto mqseries_put1(resource mqdesc, array obj_desc, array msg_desc, array put_msg_opts, string msg, resourceref compcode, resourceref reason)
	The MQPUT1 call puts one message on a queue. The queue need not be open. */
/*

MQ call:
	MQPUT1 (
		Hconn (MQHCONN) 				-- input
		ObjDesc (MQOD) 					-- input/output
		MsgDesc (MQMD) 					-- input/output
		PutMsgOpts (MQPMO) 				-- input/output
		BufferLength (MQLONG) 			-- input
		Buffer (MQBYTE×BufferLength) 	-- input		
		CompCode, 						-- output
		Reason)							-- output
		
Note: MQMD - Message Descriptor fields are first set to MQMD_DEFAULT. Before the 
      values of the array are taken.			
	
*/
PHP_FUNCTION(mqseries_put1)
{
	mqseries_descriptor *mqdesc;
	zval *z_mqdesc, *z_msg_desc, *z_put_msg_opts, *z_obj_desc, *z_comp_code, *z_reason;
	char  *msg;
	MQLONG msg_len;
	MQMD msg_desc = {MQMD_DEFAULT}; 	/* Message descriptor */
	MQOD obj_desc = {MQOD_DEFAULT}; 	/* Object descriptor */
	MQPMO put_msg_opts = {MQPMO_DEFAULT}; 	/* Options which control the MQPUT call */
	MQLONG comp_code; 
	MQLONG reason;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "raaaszz", 
		&z_mqdesc, &z_obj_desc, &z_msg_desc, &z_put_msg_opts, &msg, &msg_len, &z_comp_code, &z_reason)
		== FAILURE) {
		return;
	}

	if (!is_compcode_reason_ref(z_comp_code, z_reason)) return;

	ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);
	
	set_obj_desc_from_array(z_obj_desc, &obj_desc);
	set_msg_desc_from_array(z_msg_desc, &msg_desc TSRMLS_CC);
	set_put_msg_opts_from_array(z_put_msg_opts, &put_msg_opts TSRMLS_CC);
	
	MQPUT1(mqdesc->conn, &obj_desc, &msg_desc, &put_msg_opts, msg_len, msg, &comp_code, &reason);
	
	ZVAL_LONG(z_comp_code, comp_code);
	ZVAL_LONG(z_reason, reason);
	
	if (PZVAL_IS_REF(z_obj_desc)) {
		set_array_from_obj_desc(z_obj_desc, &obj_desc);
	}
	if (PZVAL_IS_REF(z_msg_desc)) {
		set_array_from_msg_desc(z_msg_desc, &msg_desc TSRMLS_CC);
	}
	if (PZVAL_IS_REF(z_put_msg_opts)) {
		set_array_from_put_msg_opts(z_put_msg_opts, &put_msg_opts);
	}
	

}
/* }}} */

/* {{{ proto mqseries_inq(resource mqdesc, resource mqobj, int selectorCount, array selectors, int intAttrCount, int charAttrLength, resourceref compcode, resourceref reason)
	The MQINQ call returns an array of integers and a set of character strings containing the attributes of an object. */
/*

PHP Sample:
	mqseries_inq($conn, $obj, 1, array(MQSERIES_MQCA_Q_MGR_NAME), 0, &$int_attr, 48, &$char_attr, &$comp_code, &$reason);	
	
	The following types of object are valid: 
	- Queue 
	- Namelist 
	- Process definition 
	- Queue manager
	
MQINQ (Hconn 			-- input
	, Hobj				-- input
	, SelectorCount		-- input
	, Selectors			-- input
	, IntAttrCount		-- input
	, IntAttrs			-- output
	, CharAttrLength	-- input
	, CharAttrs 		-- output
	, CompCode			-- output
	, Reason			-- output)	
*/
PHP_FUNCTION(mqseries_inq)
{
	mqseries_descriptor *mqdesc;
	mqseries_obj *mqobj;
	zval *z_mqdesc, *z_mqobj, *z_selectors, **option_val, *z_intAttrs, *z_charAttrs, *z_comp_code, *z_reason;
	HashPosition pos;
	MQLONG current=0, selectorCount, *selectors, intAttrLength, i, charAttrLength; 
	MQCHAR *charAttrs = NULL;
	MQLONG *intAttrs = NULL;
	MQLONG comp_code; 
	MQLONG reason;
	
	

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rrlalzlzzz", 
			&z_mqdesc, 
			&z_mqobj, 
			&selectorCount, 
			&z_selectors, 
			&intAttrLength,
			&z_intAttrs, 
			&charAttrLength, 
			&z_charAttrs,
			&z_comp_code, 
			&z_reason)	== FAILURE) {
		return;
	}

	if (!is_compcode_reason_ref(z_comp_code, z_reason)) return;
	if (!is_called_by_ref(z_intAttrs, "intAttrs")) return;
	if (!is_called_by_ref(z_charAttrs, "charAttrs")) return;

	ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);
	ZEND_FETCH_RESOURCE(mqobj,  mqseries_obj *, &z_mqobj, -1, PHP_MQSERIES_OBJ_RES_NAME, le_mqseries_obj);
	
	selectors = (MQLONG *)emalloc(selectorCount * sizeof(MQLONG));
	
	zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(z_selectors), &pos);
	while (zend_hash_get_current_data_ex(Z_ARRVAL_P(z_selectors), (void **)&option_val, &pos) == SUCCESS) {
		if (current < selectorCount) {
			selectors[current++] = Z_LVAL_PP(option_val);
		}
		zend_hash_move_forward_ex(Z_ARRVAL_P(z_selectors), &pos);
	}
	
	
	if (charAttrLength > 0) { /* Are charAttr requested */
		charAttrs = (MQCHAR *)emalloc(charAttrLength+1);
		memset(charAttrs, 0, charAttrLength+1); // set to zero
	}
	if (intAttrLength > 0) { /*  Are intAttr requested */
		intAttrs = (MQLONG *)emalloc(intAttrLength+sizeof(MQLONG));
	}
	
	MQINQ(
		mqdesc->conn,
		mqobj->obj,
		selectorCount,
		selectors,
		intAttrLength,
		intAttrs,
		charAttrLength,
		charAttrs,
		&comp_code,
		&reason);
		
	ZVAL_LONG(z_comp_code, comp_code);
	ZVAL_LONG(z_reason, reason);
	
	if (comp_code == MQCC_OK) {
		if (charAttrLength > 0) { /* set only when charAttrs where requested */
			ZVAL_STRING(z_charAttrs, charAttrs, MQSERIES_TRUE);
		}
		if (intAttrLength > 0) { /*  set only when intAttrs where requested */
			/* create an indexed array of long values */
			for (i = 0; i < intAttrLength; i++) {
				add_index_long(z_intAttrs, i, intAttrs[i]);
			}
		}
	}

	if (charAttrLength > 0) { /* set only when charAttrs where requested */
		efree(charAttrs);
	}
	if (intAttrLength > 0) { /* set only when charAttrs where requested */
		efree(intAttrs);
	}
	efree(selectors);

}
/* }}} */

/* {{{ proto resource mqseries_set(resource connection resource object_handle, int selector_count, array selectors, int int_attribute_count, array int_attribute, int char_attr_length, array char_attr, resourceref compcode, resourceref reason)
	The MQSET call is used to change the attributes of an object represented by a handle. The object must be a queue. */
/*
	
	MQSET (
		Hconn, 
		Hobj, 
		SelectorCount, 
		Selectors, 
		IntAttrCount, 
		IntAttrs, 
		CharAttrLength, 
		CharAttrs, 
		CompCode, 
		Reason)
*/
PHP_FUNCTION(mqseries_set)
{
	mqseries_descriptor *mqdesc;
	mqseries_obj *mqobj;
	zval *z_mqdesc, *z_mqobj, *z_selectors, **option_val, *z_intAttrs, *z_charAttrs, *z_comp_code, *z_reason;
	HashPosition pos;
	MQLONG current=0, selectorCount, *selectors, intAttrLength, charAttrLength; 
	MQCHAR *charAttrs = NULL;
	MQLONG *intAttrs = NULL;
	MQLONG comp_code; 
	MQLONG reason;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rrlalalazz", 
			&z_mqdesc, 
			&z_mqobj, 
			&selectorCount, 
			&z_selectors, 
			&intAttrLength,
			&z_intAttrs, 
			&charAttrLength, 
			&z_charAttrs,
			&z_comp_code, 
			&z_reason)	== FAILURE) {
		return;
	}

	if (!is_compcode_reason_ref(z_comp_code, z_reason)) return;

	ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);
	ZEND_FETCH_RESOURCE(mqobj,  mqseries_obj *, &z_mqobj, -1, PHP_MQSERIES_OBJ_RES_NAME, le_mqseries_obj);
	
	selectors = (MQLONG *)emalloc(selectorCount * sizeof(MQLONG));
	
	zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(z_selectors), &pos);
	current = 0;
	while (zend_hash_get_current_data_ex(Z_ARRVAL_P(z_selectors), (void **)&option_val, &pos) == SUCCESS) {
		if (current < selectorCount) {
			selectors[current++] = Z_LVAL_PP(option_val);
		}
		zend_hash_move_forward_ex(Z_ARRVAL_P(z_selectors), &pos);
	}
	
	if (intAttrLength > 0) { /*  Are intAttr requested */
		intAttrs = (MQLONG *)emalloc(intAttrLength+sizeof(MQLONG));
		current = 0;
		zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(z_intAttrs), &pos);
		while (zend_hash_get_current_data_ex(Z_ARRVAL_P(z_intAttrs), (void **)&option_val, &pos) == SUCCESS) {
			if (current < intAttrLength) {
				intAttrs[current++] = Z_LVAL_PP(option_val);
			}
			zend_hash_move_forward_ex(Z_ARRVAL_P(z_intAttrs), &pos);
		}
	}

	
	if (charAttrLength > 0) { /* Are charAttr requested */
		charAttrs = (MQCHAR *)emalloc(charAttrLength+1);
		current = 0;
		zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(z_charAttrs), &pos);
		while (zend_hash_get_current_data_ex(Z_ARRVAL_P(z_charAttrs), (void **)&option_val, &pos) == SUCCESS) {
			if (current < charAttrLength) {
				charAttrs[current++] = Z_LVAL_PP(option_val); /* hoe helen we char uit een array? */
			}
			zend_hash_move_forward_ex(Z_ARRVAL_P(z_charAttrs), &pos);
		}
	}

	MQSET(
		mqdesc->conn,
		mqobj->obj,
		selectorCount,
		selectors,
		intAttrLength,
		intAttrs,
		charAttrLength,
		charAttrs,
		&comp_code,
		&reason);


	ZVAL_LONG(z_comp_code, comp_code);
	ZVAL_LONG(z_reason, reason);


	if (charAttrLength > 0) { /* set only when charAttrs where requested */
		efree(charAttrs);
	}
	if (intAttrLength > 0) { /* set only when charAttrs where requested */
		efree(intAttrs);
	}
	efree(selectors);

}
/* }}} */

/* {{{ proto string mqseries_bytes_val(resource bytes)
       Returns the string of bytes contained in the mqseries bytes resource */
PHP_FUNCTION(mqseries_bytes_val)
{
    zval *z_bytes;
	mqseries_bytes *bytes;	
    
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r", &z_bytes) == FAILURE) {
		return;
	}

	ZEND_FETCH_RESOURCE(bytes, mqseries_bytes *, &z_bytes, -1, PHP_MQSERIES_BYTES_RES_NAME, le_mqseries_bytes);

	if (bytes && bytes->bytes) {
		RETVAL_STRING((char *) bytes->bytes, 1);
	} else {
		RETVAL_NULL();
	}
}
/* }}} */

/******************************************************************************/
/* Following are methods to make structs from arrays and vice verse           */
/* TODO Check if all fields are specified (hopefully the MQ API will not      */
/* change verry soon as we have to do this all over again). 'zucht'.          */
/******************************************************************************/
/* {{{ set_authentication_information_record_from_array
 * set authenication information from an array
 */
static void set_authentication_information_record_from_array(zval *array, 
								PMQAIR authentication_information_record, 
								PMQCHAR LDAPUserName)
{
	HashTable *ht = Z_ARRVAL_P(array);
	zval **tmp;

	MQSERIES_SETOPT_LONG(authentication_information_record, Version);
	MQSERIES_SETOPT_LONG(authentication_information_record, AuthInfoType);
	MQSERIES_SETOPT_STRING(authentication_information_record, AuthInfoConnName);
	MQSERIES_SETOPT_STRING(authentication_information_record, LDAPPassword);

	if (zend_hash_find(ht, "LDAPUserName", sizeof("LDAPUserName"), (void**)&tmp) == SUCCESS &&
		Z_TYPE_PP(tmp) == IS_STRING) {
		strncpy(LDAPUserName, Z_STRVAL_PP(tmp), sizeof(LDAPUserName));
		authentication_information_record->LDAPUserNamePtr = LDAPUserName;
		authentication_information_record->LDAPUserNameLength = strlen(LDAPUserName);
	}
}
/* }}} */

/* {{{ set_ssl_configuration_from_array 
 * sets the ssl configuration from an array
 */
static void set_ssl_configuration_from_array(zval *array, 
									PMQSCO ssl_configuration, 
									PMQAIR authentication_information_record, 
									PMQCHAR LDAPUserName)
{
	HashTable *ht = Z_ARRVAL_P(array);
	zval **tmp;

	MQSERIES_SETOPT_LONG(ssl_configuration, Version);
	MQSERIES_SETOPT_STRING(ssl_configuration, KeyRepository);
	MQSERIES_SETOPT_STRING(ssl_configuration, CryptoHardware);

	if (zend_hash_find(ht, "MQAIR", sizeof("MQAIR"), (void**)&tmp) == SUCCESS &&
		Z_TYPE_PP(tmp) == IS_ARRAY) {
		set_authentication_information_record_from_array(*tmp, authentication_information_record, LDAPUserName);
		ssl_configuration->AuthInfoRecCount = 1;
		ssl_configuration->AuthInfoRecPtr = authentication_information_record;
	}
}
/* }}} */

/* {{{ set_channel_definition_from_array
 * Set the MQCD struct from array.
 * TODO: Findout whether all fields are needed. Do thay all have meaning during a
 * connx call?
 * 
 */
static void set_channel_definition_from_array(zval *array, PMQCD channel_definition)
{
	HashTable *ht = Z_ARRVAL_P(array);
	zval **tmp;

	MQSERIES_SETOPT_LONG(channel_definition, Version);
	MQSERIES_SETOPT_STRING(channel_definition, ChannelName);
	MQSERIES_SETOPT_STRING(channel_definition, ConnectionName);
	MQSERIES_SETOPT_LONG(channel_definition, TransportType);
	MQSERIES_SETOPT_LONG(channel_definition, ChannelType);
	MQSERIES_SETOPT_STRING(channel_definition, Desc);
	MQSERIES_SETOPT_STRING(channel_definition, QMgrName);
	MQSERIES_SETOPT_STRING(channel_definition, XmitQName);
	MQSERIES_SETOPT_STRING(channel_definition, ShortConnectionName);
	MQSERIES_SETOPT_STRING(channel_definition, MCAName);
	MQSERIES_SETOPT_STRING(channel_definition, ModeName);
	MQSERIES_SETOPT_STRING(channel_definition, TpName);
	MQSERIES_SETOPT_LONG(channel_definition, BatchSize);
	MQSERIES_SETOPT_LONG(channel_definition, DiscInterval);
	MQSERIES_SETOPT_LONG(channel_definition, ShortRetryCount);
	MQSERIES_SETOPT_LONG(channel_definition, ShortRetryInterval);
	MQSERIES_SETOPT_LONG(channel_definition, LongRetryCount);
	MQSERIES_SETOPT_LONG(channel_definition, LongRetryInterval);
	MQSERIES_SETOPT_STRING(channel_definition, SecurityExit);
	MQSERIES_SETOPT_STRING(channel_definition, MsgExit);
	MQSERIES_SETOPT_STRING(channel_definition, SendExit);
	MQSERIES_SETOPT_STRING(channel_definition, ReceiveExit);
	MQSERIES_SETOPT_LONG(channel_definition, SeqNumberWrap);
	MQSERIES_SETOPT_LONG(channel_definition, MaxMsgLength);
	MQSERIES_SETOPT_LONG(channel_definition, PutAuthority);
	MQSERIES_SETOPT_LONG(channel_definition, DataConversion);
	MQSERIES_SETOPT_STRING(channel_definition, SecurityUserData);
	MQSERIES_SETOPT_STRING(channel_definition, MsgUserData);
	MQSERIES_SETOPT_STRING(channel_definition, SendUserData);
	MQSERIES_SETOPT_STRING(channel_definition, ReceiveUserData);
	MQSERIES_SETOPT_STRING(channel_definition, UserIdentifier);	
	MQSERIES_SETOPT_STRING(channel_definition, Password);
	MQSERIES_SETOPT_STRING(channel_definition, MCAUserIdentifier);
	MQSERIES_SETOPT_LONG(channel_definition, MCAType);
	MQSERIES_SETOPT_STRING(channel_definition, RemoteUserIdentifier);
	MQSERIES_SETOPT_STRING(channel_definition, RemotePassword);
	MQSERIES_SETOPT_STRING(channel_definition, MsgRetryExit);
	MQSERIES_SETOPT_STRING(channel_definition, MsgRetryUserData);
	MQSERIES_SETOPT_LONG(channel_definition, MsgRetryCount);
	MQSERIES_SETOPT_LONG(channel_definition, MsgRetryInterval);
	MQSERIES_SETOPT_LONG(channel_definition, HeartbeatInterval);
	MQSERIES_SETOPT_LONG(channel_definition, BatchInterval);
	MQSERIES_SETOPT_LONG(channel_definition, NonPersistentMsgSpeed);
	MQSERIES_SETOPT_LONG(channel_definition, StrucLength);
	MQSERIES_SETOPT_LONG(channel_definition, ExitNameLength);
	MQSERIES_SETOPT_LONG(channel_definition, ExitDataLength);
	MQSERIES_SETOPT_LONG(channel_definition, MsgExitsDefined);
	MQSERIES_SETOPT_LONG(channel_definition, SendExitsDefined);
	MQSERIES_SETOPT_LONG(channel_definition, ReceiveExitsDefined);

/* TODO: Do we need these? Or are they only needed during the creation of a channel?				
   MQPTR     MsgExitPtr;                 Address of first MsgExit field 
   MQPTR     MsgUserDataPtr;             Address of first MsgUserData field 
   MQPTR     SendExitPtr;                Address of first SendExit field 
   MQPTR     SendUserDataPtr;            Address of first SendUserData field 
   MQPTR     ReceiveExitPtr;             Address of first ReceiveExit field 
   MQPTR     ReceiveUserDataPtr;         Address of first ReceiveUserData field 
   MQPTR     ClusterPtr;                 Address of a list of cluster names 
 */

	MQSERIES_SETOPT_LONG(channel_definition, ClustersDefined);
	MQSERIES_SETOPT_LONG(channel_definition, NetworkPriority);
	MQSERIES_SETOPT_LONG(channel_definition, LongMCAUserIdLength);
	MQSERIES_SETOPT_LONG(channel_definition, LongRemoteUserIdLength);

/*   MQPTR     LongMCAUserIdPtr;           Address of long MCA user identifier 
   MQPTR     LongRemoteUserIdPtr;        Address of long remote user identifier 
   MQBYTE40  MCASecurityId;              MCA security identifier 
   MQBYTE40  RemoteSecurityId;           Remote security identifier 
			} else if (!strcmp(string_key, "SSLCipherSpec")) {
				strncpy(channel_definition->SSLCipherSpec, Z_STRVAL_PP(option_val), sizeof(channel_definition->SSLCipherSpec));
   MQPTR     SSLPeerNamePtr;             Address of SSL peer name 
 */

	MQSERIES_SETOPT_LONG(channel_definition, SSLPeerNameLength);
	MQSERIES_SETOPT_LONG(channel_definition, SSLClientAuth);
	MQSERIES_SETOPT_LONG(channel_definition, KeepAliveInterval);
	MQSERIES_SETOPT_STRING(channel_definition, LocalAddress);
	MQSERIES_SETOPT_LONG(channel_definition, BatchHeartbeat);
}
/* }}} */

/* {{{ set_connect_opts_from_array
 * Set MQCNO connect options from array.
 * The MQCD struct is part of the connect options. Fields for this struct are
 * prefixed with MQCD.
 * 
 */
static void set_connect_opts_from_array(zval *array, 
				PMQCNO connect_opts, 
				PMQCD channel_definition, 
				PMQSCO ssl_configuration, 
				PMQAIR authentication_information_record,
				PMQCHAR LDAPUserName)
{
	HashTable *ht = Z_ARRVAL_P(array);
	zval **tmp;

	MQSERIES_SETOPT_LONG(connect_opts, Options);
	MQSERIES_SETOPT_LONG(connect_opts, Version);

	if (zend_hash_find(ht, "MQCD", sizeof("MQCD"), (void**)&tmp) == SUCCESS &&
		Z_TYPE_PP(tmp) == IS_ARRAY) {
		set_channel_definition_from_array(*tmp, channel_definition);
		connect_opts->ClientConnPtr = channel_definition;
	}

	if (zend_hash_find(ht, "MQSCO", sizeof("MQSCO"), (void**)&tmp) == SUCCESS &&
		Z_TYPE_PP(tmp) == IS_ARRAY) {
		set_ssl_configuration_from_array(*tmp, ssl_configuration, authentication_information_record, LDAPUserName);
		connect_opts->SSLConfigPtr = ssl_configuration;
	}
/*
   QManager connection Tag
   This field is used only on z/OS. In other environments, the value MQCT_NONE should be specified. |
   MQBYTE128  ConnTag;          Queue-manager connection tag 
*/
}
/* }}} */

/* {{{ set_put_msg_opts_from_array
 * fills the put message options struct from an array
 */
static void set_put_msg_opts_from_array(zval *array, PMQPMO put_msg_opts TSRMLS_DC)
{
	HashTable *ht = Z_ARRVAL_P(array);
	zval **tmp;
	mqseries_obj *mqobj;

	MQSERIES_SETOPT_LONG(put_msg_opts, Options); 
	MQSERIES_SETOPT_LONG(put_msg_opts, Version);

	if (zend_hash_find(ht, "Context", sizeof("Context"), (void**)&tmp) == SUCCESS &&
		Z_TYPE_PP(tmp) == IS_RESOURCE) {
		mqobj = (mqseries_obj *) zend_fetch_resource(tmp TSRMLS_CC, -1, PHP_MQSERIES_OBJ_RES_NAME, NULL, 1, le_mqseries_obj);
		if (mqobj != NULL) {
			put_msg_opts->Context = mqobj->obj;
		}
	}

/* input fields not supported yet
   MQLONG    RecsPresent;        
   MQLONG    PutMsgRecFields;    
   MQLONG    PutMsgRecOffset;    
   MQPTR     PutMsgRecPtr;       
   MQLONG    ResponseRecOffset;  
   MQPTR     ResponseRecPtr;     
*/			
}
/* }}} */

/* {{{ set_array_from_put_msg_opts
 * makes an array from the put message options struct for output
 */
static void set_array_from_put_msg_opts(zval *array, PMQPMO put_msg_opts) {
	zval_dtor(array);
	array_init(array);
	if (put_msg_opts->ResolvedQName != NULL && strlen(put_msg_opts->ResolvedQName) > 0) {
		add_assoc_stringl(array, "ResolvedQName",put_msg_opts->ResolvedQName, strlen(put_msg_opts->ResolvedQName),1);
	}
	if (put_msg_opts->ResolvedQMgrName != NULL && strlen(put_msg_opts->ResolvedQMgrName) >0) {
		add_assoc_stringl(array, "ResolvedQMgrName",put_msg_opts->ResolvedQMgrName, strlen(put_msg_opts->ResolvedQMgrName),1);
	}
	add_assoc_long(array, "KnownDestCount",put_msg_opts->KnownDestCount);
	add_assoc_long(array, "UnknownDestCount",put_msg_opts->UnknownDestCount);
	add_assoc_long(array, "InvalidDestCount",put_msg_opts->InvalidDestCount);
}
/* }}} */

/* {{{ set_msg_desc_from_array
	Put options from the given array into the MQMD structure.
	Only version_1 of the MQMD is supported.

Not supported:
	AccountingToken
		
*/
static void set_msg_desc_from_array(zval *array, PMQMD msg_desc TSRMLS_DC)
{
	HashTable *ht = Z_ARRVAL_P(array);
	zval **tmp;
	mqseries_bytes *byte24;

	MQSERIES_SETOPT_LONG(msg_desc, Report);
	MQSERIES_SETOPT_LONG(msg_desc, MsgType);
	MQSERIES_SETOPT_LONG(msg_desc, Expiry);
	MQSERIES_SETOPT_STRING(msg_desc, Format);
	MQSERIES_SETOPT_LONG(msg_desc, Priority);
	MQSERIES_SETOPT_LONG(msg_desc, Persistence);
	MQSERIES_SETOPT_STRING(msg_desc, ReplyToQ);
	MQSERIES_SETOPT_LONG(msg_desc, Feedback);
	MQSERIES_SETOPT_LONG(msg_desc, Encoding);
	MQSERIES_SETOPT_LONG(msg_desc, CodedCharSetId);

	if (zend_hash_find(ht, "MsgId", sizeof("MsgId"), (void**)&tmp) == SUCCESS) {
		if (Z_TYPE_PP(tmp) == IS_RESOURCE) {
			byte24 = (mqseries_bytes *) zend_fetch_resource(tmp TSRMLS_CC, -1, PHP_MQSERIES_BYTES_RES_NAME, NULL, 1, le_mqseries_bytes);
			if (byte24 != NULL) {
				memcpy(msg_desc->MsgId, byte24->bytes, sizeof(msg_desc->MsgId));
			}
		} else {
			convert_to_string(*tmp);
			strncpy((MQCHAR *) msg_desc->MsgId,Z_STRVAL_PP(tmp), sizeof(msg_desc->MsgId));
		}
	}

	if (zend_hash_find(ht, "CorrelId", sizeof("CorrelId"), (void**)&tmp) == SUCCESS) {
		if (Z_TYPE_PP(tmp) == IS_RESOURCE) {
			byte24 = (mqseries_bytes *) zend_fetch_resource(tmp TSRMLS_CC, -1, PHP_MQSERIES_BYTES_RES_NAME, NULL, 1, le_mqseries_bytes);
			if (byte24 != NULL) {
				memcpy(msg_desc->CorrelId, byte24->bytes, sizeof(msg_desc->CorrelId));
			}
		} else {
			convert_to_string(*tmp);
			strncpy((MQCHAR *) msg_desc->CorrelId, Z_STRVAL_PP(tmp), sizeof(msg_desc->CorrelId));
		}
	}

	MQSERIES_SETOPT_STRING(msg_desc, ReplyToQMgr);
	MQSERIES_SETOPT_LONG(msg_desc, PutApplType);
	MQSERIES_SETOPT_LONG(msg_desc, MsgSeqNumber);
	MQSERIES_SETOPT_LONG(msg_desc, MsgFlags);
}
/* }}} */

/* {{{ make_reference
 * makes an mqseries_bytes reference, needed when returning message and correlation id's
 */
static zval* make_reference(PMQBYTE bytes, MQLONG size TSRMLS_DC) {
	mqseries_bytes *pBytes;
	zval *z_byte24;
	

	MAKE_STD_ZVAL(z_byte24);
	
	pBytes = (mqseries_bytes *) emalloc(sizeof(mqseries_bytes));
	pBytes->bytes = (PMQBYTE) emalloc(size*sizeof(MQBYTE));
	memcpy(pBytes->bytes, bytes, size);
	ZEND_REGISTER_RESOURCE(z_byte24, pBytes, le_mqseries_bytes);
	pBytes->id = Z_RESVAL_P(z_byte24);
	
	return z_byte24;
}
/* }}} */

/* {{{ set_array_from_msg_desc
 * makes an array from the message descriptor struct for output.
 */
static  void set_array_from_msg_desc(zval *array, PMQMD msg_desc TSRMLS_DC) {
	zval *ref;

	zval_dtor(array);
	array_init(array);
	
	if (msg_desc->ApplIdentityData != NULL && strlen(msg_desc->ApplIdentityData) > 0) {
		add_assoc_stringl(array, "ApplIdentityData",msg_desc->ApplIdentityData, sizeof(msg_desc->ApplIdentityData), 1);
	}
	if (msg_desc->ApplOriginData != NULL && strlen(msg_desc->ApplOriginData) > 0) {
		add_assoc_stringl(array, "ApplOriginData",msg_desc->ApplOriginData, sizeof(msg_desc->ApplOriginData), 1);
	}
	add_assoc_long(array, "BackoutCount",msg_desc->BackoutCount);
	add_assoc_long(array, "CodedCharSetId",msg_desc->CodedCharSetId);

	ref = make_reference(msg_desc->CorrelId, 24 TSRMLS_CC);
	add_assoc_resource(array, "CorrelId", Z_RESVAL_P(ref));
	zend_list_addref(Z_RESVAL_P(ref));
	zval_ptr_dtor(&ref);

	add_assoc_long(array, "Encoding",msg_desc->Encoding);
	add_assoc_long(array, "Expiry",msg_desc->Expiry);
	add_assoc_long(array, "Feedback",msg_desc->Feedback);
	if (msg_desc->Format != NULL && strlen(msg_desc->Format) > 0) {
		add_assoc_stringl(array, "Format",msg_desc->Format, strlen(msg_desc->Format),1);
	}
/*	BYTE string with special meaning 
	add_assoc_string(array, "GroupId",msg_desc->GroupId, sizeof(msg_desc->GroupId));
*/
	
	add_assoc_long(array, "Report",msg_desc->Report);
	add_assoc_long(array, "MsgType",msg_desc->MsgType);
	add_assoc_long(array, "Priority",msg_desc->Priority);
	add_assoc_long(array, "Persistence",msg_desc->Persistence);

	ref = make_reference(msg_desc->MsgId, 24 TSRMLS_CC);
	add_assoc_resource(array, "MsgId", Z_RESVAL_P(ref));
	zend_list_addref(Z_RESVAL_P(ref));
	zval_ptr_dtor(&ref);

	if (msg_desc->ReplyToQ != NULL && strlen(msg_desc->ReplyToQ)>0)
		add_assoc_stringl(array, "ReplyToQ",msg_desc->ReplyToQ, sizeof(msg_desc->ReplyToQ), 1);
	if (msg_desc->ReplyToQMgr != NULL && strlen(msg_desc->ReplyToQMgr)>0)	
		add_assoc_stringl(array, "ReplyToQMgr",msg_desc->ReplyToQMgr, sizeof(msg_desc->ReplyToQMgr), 1);
	if (msg_desc->UserIdentifier != NULL && strlen(msg_desc->UserIdentifier) >0)	
		add_assoc_stringl(array, "UserIdentifier",msg_desc->UserIdentifier, sizeof(msg_desc->UserIdentifier), 1);

	
	add_assoc_long(array, "PutApplType",msg_desc->PutApplType);
	if (msg_desc->PutApplName != NULL && strlen(msg_desc->PutApplName) >0)
		add_assoc_stringl(array, "PutApplName",msg_desc->PutApplName, sizeof(msg_desc->PutApplName), 1);
	if (msg_desc->PutDate != NULL && strlen(msg_desc->PutDate)>0)	
		add_assoc_stringl(array, "PutDate",msg_desc->PutDate, sizeof(msg_desc->PutDate), 1);
	if (msg_desc->PutTime != NULL && strlen(msg_desc->PutTime) >0)	
		add_assoc_stringl(array, "PutTime",msg_desc->PutTime, sizeof(msg_desc->PutTime), 1);

	add_assoc_long(array, "MsgSeqNumber",msg_desc->MsgSeqNumber);
	add_assoc_long(array, "MsgFlags",msg_desc->MsgFlags);
	add_assoc_long(array, "OriginalLength",msg_desc->OriginalLength);
}
/* }}} */

/* {{{ set_obj_desc_from_array
 * Set the MQOD Object Descriptor from array
 */
static void set_obj_desc_from_array(zval *array, PMQOD obj_desc)
{
	HashTable *ht = Z_ARRVAL_P(array);
	zval **tmp;

	MQSERIES_SETOPT_LONG(obj_desc, Version);
	MQSERIES_SETOPT_LONG(obj_desc, ObjectType);
	MQSERIES_SETOPT_STRING(obj_desc, ObjectName);
	MQSERIES_SETOPT_STRING(obj_desc, ObjectQMgrName);
	MQSERIES_SETOPT_STRING(obj_desc, DynamicQName);
	MQSERIES_SETOPT_STRING(obj_desc, AlternateUserId);

/* TODO: Implement these ?
   MQLONG    RecsPresent;          
   MQLONG    ObjectRecOffset;      
   MQLONG    ResponseRecOffset;    
   MQPTR     ObjectRecPtr;         
   MQPTR     ResponseRecPtr;       

 Will not support this.
  not supported MQBYTE40  AlternateSecurityId;  
*/
}
/* }}} */

/* {{{ set_array_from_obj_desc
 * Set array from MQOD  Object Descriptor
 */
static void set_array_from_obj_desc(zval *array, PMQOD obj_desc) {
	zval_dtor(array);
	array_init(array);

	add_assoc_string(array, "ObjectQMgrName",obj_desc->ObjectQMgrName, sizeof(obj_desc->ObjectQMgrName));
	add_assoc_string(array, "ObjectName",obj_desc->ObjectName, sizeof(obj_desc->ObjectName));
	add_assoc_long(array, "KnownDestCount",obj_desc->KnownDestCount);
	add_assoc_long(array, "UnknownDestCount",obj_desc->UnknownDestCount);
	add_assoc_long(array, "InvalidDestCount",obj_desc->InvalidDestCount);
	add_assoc_string(array, "ResolvedQName",obj_desc->ResolvedQName, sizeof(obj_desc->ResolvedQName));
	add_assoc_string(array, "ResolvedQMgrName",obj_desc->ResolvedQMgrName, sizeof(obj_desc->ResolvedQMgrName));
	
}
/* }}} */

/* {{{ set_get_msg_opts_from_array
 * sets the get message struct from an array.
 */
static void set_get_msg_opts_from_array(zval *array, PMQGMO get_msg_opts  TSRMLS_DC) {
	HashTable *ht = Z_ARRVAL_P(array);
	zval **tmp;
	mqseries_bytes * byte16;

	MQSERIES_SETOPT_LONG(get_msg_opts, Version);
	MQSERIES_SETOPT_LONG(get_msg_opts, Options);
	MQSERIES_SETOPT_LONG(get_msg_opts, WaitInterval);
	MQSERIES_SETOPT_LONG(get_msg_opts, MatchOptions);
	MQSERIES_SETOPT_LONG(get_msg_opts, Signal1);
	MQSERIES_SETOPT_LONG(get_msg_opts, Signal2);

	if (zend_hash_find(ht, "MsgToken", sizeof("MsgToken"), (void**)&tmp) == SUCCESS &&
		Z_TYPE_PP(tmp) == IS_RESOURCE) {
		/*
		 * tmp should contain the resource reference
		 */
		byte16 = (mqseries_bytes *) zend_fetch_resource(tmp TSRMLS_CC, -1, PHP_MQSERIES_BYTES_RES_NAME, NULL, 1, le_mqseries_bytes);
		if (byte16 != NULL) {
			memcpy(get_msg_opts->MsgToken, byte16->bytes, sizeof(get_msg_opts->MsgToken));
		}
	}
}
/* }}} */

/* {{{ set_array_from_get_msg_opts
 * Builds an array from the get message options struct for output
 */
static void set_array_from_get_msg_opts(zval *array, PMQGMO get_msg_opts TSRMLS_DC) {
	zval *ref;
	char str[2];

	zval_dtor(array);
	array_init(array);
	
	ref = make_reference(get_msg_opts->MsgToken, 16 TSRMLS_CC);
	add_assoc_resource(array, "MsgToken", Z_RESVAL_P(ref));
	zend_list_addref(Z_RESVAL_P(ref));
	zval_ptr_dtor(&ref);

	if (get_msg_opts->ResolvedQName != NULL && strlen(get_msg_opts->ResolvedQName) > 0) {
		add_assoc_stringl(array, "ResolvedQName",get_msg_opts->ResolvedQName, sizeof(get_msg_opts->ResolvedQName), 1);
	}
	sprintf(str, "%c", get_msg_opts->GroupStatus);
	add_assoc_string(array, "GroupStatus",str, sizeof(get_msg_opts->GroupStatus));
	sprintf(str, "%c", get_msg_opts->SegmentStatus);
	add_assoc_string(array, "SegmentStatus",str, sizeof(get_msg_opts->SegmentStatus));
	sprintf(str, "%c", get_msg_opts->Segmentation);
	add_assoc_string(array, "Segmentation",str, sizeof(get_msg_opts->Segmentation));

	add_assoc_long(array, "ReturnedLength",get_msg_opts->ReturnedLength);
	
}
/* }}} */

/******************************************************************************/
/* End of conversion methods                                                  */
/******************************************************************************/

/* {{{ _mqseries_bytes
 * frees memomory previuosly allocated 
 */
static void _mqseries_bytes(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{	
	efree(((mqseries_bytes *)rsrc->ptr)->bytes);
	efree(rsrc->ptr);
}
/* }}} */

/* {{{ is_compcode_reason_ref
 * test to see if compcode and reason where passed by reference.
 */
static int is_compcode_reason_ref(zval *z_comp_code, zval *z_reason) {
	if (!PZVAL_IS_REF(z_comp_code)) {
	    zend_error(E_WARNING, "Parameter CompCode wasn't passed by reference");
		return 0;
	}
	if (!PZVAL_IS_REF(z_reason)) {
	    zend_error(E_WARNING, "Parameter Reason wasn't passed by reference");
		return 0;
	}
	return 1;
}
/* }}} */

/* {{{ is_called_by_ref
 * Test to see if a parameters was passed by reference.
 */
static int is_called_by_ref(zval *param, char *param_name) {
	char str[255];
	if (!PZVAL_IS_REF(param)) {
		sprintf(str, "Parameter %s wasn't passed by reference", param_name);
	    zend_error(E_WARNING, str);
		return 0;
	}
	return 1;
}
/* }}} */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */

