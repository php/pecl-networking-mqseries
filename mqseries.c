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
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "php_network.h"
#include "ext/standard/info.h"
#include "php_mqseries.h"

static void _mqseries_disc(zend_rsrc_list_entry *rsrc TSRMLS_DC);
static void _mqseries_close(zend_rsrc_list_entry *rsrc TSRMLS_DC);

static void set_msg_desc_from_array(zval *array, MQMD *msg_desc);

/* If you declare any globals in php_mqseries.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(mqseries)
*/

/* True global resources - no need for thread safety here */
static int le_mqseries_conn;
static int le_mqseries_obj;
static zval *z_reason_texts;

/* {{{ mqseries_functions[]
 *
 * Every user visible function must have an entry in mqseries_functions[].
 */
function_entry mqseries_functions[] = {
	PHP_FE(mqseries_conn,	NULL)
	PHP_FE(mqseries_disc,	NULL)
	PHP_FE(mqseries_open,	NULL)
	PHP_FE(mqseries_get,	NULL)
	PHP_FE(mqseries_put,	NULL)
	PHP_FE(mqseries_begin,	NULL)
	PHP_FE(mqseries_cmit,	NULL)
	PHP_FE(mqseries_back,	NULL)
	PHP_FE(mqseries_close,	NULL)
	PHP_FE(mqseries_error,	NULL)
	PHP_FE(mqseries_strerror,	NULL)
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
	"0.7", /* Replace with version number for your extension */
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
	/* don't change the order of these, objects must be freed before connections */
	le_mqseries_obj = zend_register_list_destructors_ex(_mqseries_close, NULL, "mqseries_obj", module_number);
	le_mqseries_conn = zend_register_list_destructors_ex(_mqseries_disc, NULL, "mqseries_conn", module_number);

#include "mqseries_init_const.h"

	MAKE_STD_ZVAL(z_reason_texts);
	array_init(z_reason_texts);
#include "mqseries_reason_texts.h"

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(mqseries)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(mqseries)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "mqseries support", "enabled");
	php_info_print_table_row(2, "Revision", "$Revision$");
	php_info_print_table_end();
}
/* }}} */

/* {{{ proto ressource mqseries_conn(string name)
	Connect to the Queue-Manager with the given Name. You need either the Channel-Table (usualy in /var/mqm) or	set the environment var MQSERVER=<channel>/<proto>/<host>[(port)] MQSERVER=example/TCP/mqs.example.com
*/
PHP_FUNCTION(mqseries_conn)
{
	char *name;
	int name_len;
	mqseries_descriptor *mqdesc;
	MQLONG comp_code;  /* Completion code	*/
	MQLONG reason;     /* Qualifying reason */

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name, &name_len)
		== FAILURE) {
		return;
	}

	mqdesc = emalloc(sizeof(mqseries_descriptor));
	MQCONN(name, &mqdesc->conn, &comp_code, &reason);

	if ((comp_code != MQCC_OK) || (reason != MQRC_NONE)) {
		array_init(return_value);
		add_assoc_long(return_value, "comp_code", comp_code);
		add_assoc_long(return_value, "reason", reason);

	} else {
		ZEND_REGISTER_RESOURCE(return_value, mqdesc, le_mqseries_conn);
		mqdesc->id = Z_LVAL_P(return_value);
	}
}
/* }}} */

/* {{{ proto ressource mqseries_open(resource mqdesc, array obj_desc, int open_options)
		Open a Queue. */
PHP_FUNCTION(mqseries_open)
{
	mqseries_descriptor *mqdesc;
	mqseries_obj *mqobj;
	zval *z_mqdesc, *z_array, **option_val;
	char  *string_key;
	uint  string_key_len;
	ulong  num_key;
	HashPosition pos;

	MQOD obj_desc = {MQOD_DEFAULT}; /* Object descriptor */
	MQLONG open_options; /* Options control MQOPEN */

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ral", &z_mqdesc,
		&z_array, &open_options) == FAILURE) {
		return;
	}

	ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, "mqseries_conn", le_mqseries_conn);

	zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(z_array), &pos);
	while (zend_hash_get_current_data_ex(Z_ARRVAL_P(z_array), (void **)&option_val, &pos) == SUCCESS) {

		/* Set up the key */
		if (zend_hash_get_current_key_ex(Z_ARRVAL_P(z_array), &string_key, &string_key_len, &num_key, 0, &pos) == HASH_KEY_IS_STRING) {
    		if (!strcmp(string_key, "ObjectQMgrName")) {
				strncpy(obj_desc.ObjectQMgrName, Z_STRVAL_PP(option_val), MQ_Q_NAME_LENGTH);
			} else if (!strcmp(string_key, "ObjectName")) {
				strncpy(obj_desc.ObjectName, Z_STRVAL_PP(option_val), MQ_Q_NAME_LENGTH);
			} else if (!strcmp(string_key, "DynamicQName")) {
				strncpy(obj_desc.DynamicQName, Z_STRVAL_PP(option_val), MQ_Q_NAME_LENGTH);
			}
		}

		zend_hash_move_forward_ex(Z_ARRVAL_P(z_array), &pos);
	}

	mqobj = emalloc(sizeof(mqseries_obj));
	MQOPEN(
		mqdesc->conn,
		&obj_desc,
		open_options,
		&mqobj->obj,
		&mqdesc->comp_code,
		&mqdesc->reason);

	if (mqdesc->comp_code == MQCC_OK) {
		mqobj->conn = &mqdesc->conn;
		ZEND_REGISTER_RESOURCE(return_value, mqobj, le_mqseries_obj);
		mqobj->id = Z_LVAL_P(return_value);
	} else {
 		RETURN_FALSE;
	}
}
/* }}} */

/* {{{ proto ressource mqseries_get(resource mqdesc, resource mqobj, array msg_desc, array get_msg_opts, int buf_len)
	Read data from an opened queue. */
PHP_FUNCTION(mqseries_get)
{
	mqseries_descriptor *mqdesc;
	mqseries_obj *mqobj;
	zval *z_mqdesc, *z_mqobj, *z_msg_desc, *z_get_msg_opts, **option_val;
	char  *string_key;
	uint  string_key_len;
	ulong  num_key;
	HashPosition pos;

	MQLONG buf_len, msg_len;
	MQCHAR *buf;
	MQMD msg_desc = { MQMD_DEFAULT }; /* Message descriptor */
	MQGMO get_msg_opts = { MQGMO_DEFAULT }; /* Options which control the MQGET call */

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rraal", &z_mqdesc, &z_mqobj,
		&z_msg_desc, &z_get_msg_opts, &buf_len)
		== FAILURE) {
		return;
	}

	ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, "mqseries_conn", le_mqseries_conn);
	ZEND_FETCH_RESOURCE(mqobj, mqseries_obj *, &z_mqobj, -1, "mqseries_obj", le_mqseries_obj);

	set_msg_desc_from_array(z_msg_desc, &msg_desc);

	zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(z_get_msg_opts), &pos);
	while (zend_hash_get_current_data_ex(Z_ARRVAL_P(z_get_msg_opts), (void **)&option_val, &pos) == SUCCESS) {

		if (zend_hash_get_current_key_ex(Z_ARRVAL_P(z_get_msg_opts), &string_key, &string_key_len, &num_key, 0, &pos) == HASH_KEY_IS_STRING) {
			if (!strcmp(string_key, "Options")) {
				get_msg_opts.Options = Z_LVAL_PP(option_val);
			} else if (!strcmp(string_key, "WaitInterval") > 0) {
				get_msg_opts.WaitInterval = Z_LVAL_PP(option_val);
			}
		}

		zend_hash_move_forward_ex(Z_ARRVAL_P(z_get_msg_opts), &pos);
	}

	buf = (MQCHAR *)emalloc(buf_len);
	MQGET(
		mqdesc->conn,
		mqobj->obj,
		&msg_desc,
		&get_msg_opts,
		buf_len,
		buf,
		&msg_len,
		&mqdesc->comp_code,
		&mqdesc->reason);

	if (mqdesc->comp_code == MQCC_OK) {
		RETVAL_STRINGL(buf, msg_len, 1);
		efree(buf);
	} else {
		efree(buf);
 		RETURN_FALSE;
	}
}
/* }}} */

/* {{{ proto ressource mqseries_put(resource mqdesc, resource mqobj, array msg_desc, array put_msg_opts, string msg)
	Write message into the queue. */
PHP_FUNCTION(mqseries_put)
{
	mqseries_descriptor *mqdesc;
	mqseries_obj *mqobj;
	zval *z_mqdesc, *z_mqobj, *z_msg_desc, *z_put_msg_opts, **option_val;
	char  *string_key, *msg;
	uint  string_key_len;
	ulong  num_key;
	HashPosition pos;

	MQLONG msg_len;
	MQMD msg_desc; /* Message descriptor */
	MQPMO put_msg_opts; /* Options which control the MQPUT call */

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rraas", &z_mqdesc, &z_mqobj,
		&z_msg_desc, &z_put_msg_opts, &msg, &msg_len)
		== FAILURE) {
		return;
	}

	ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, "mqseries_conn", le_mqseries_conn);
	ZEND_FETCH_RESOURCE(mqobj, mqseries_obj *, &z_mqobj, -1, "mqseries_obj", le_mqseries_obj);

	memset(&msg_desc, '\0', sizeof(msg_desc));
	set_msg_desc_from_array(z_msg_desc, &msg_desc);

	memset(&put_msg_opts, '\0', sizeof(put_msg_opts));
	zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(z_put_msg_opts), &pos);
	while (zend_hash_get_current_data_ex(Z_ARRVAL_P(z_put_msg_opts), (void **)&option_val, &pos) == SUCCESS) {

		if (zend_hash_get_current_key_ex(Z_ARRVAL_P(z_put_msg_opts), &string_key, &string_key_len, &num_key, 0, &pos) == HASH_KEY_IS_STRING) {
			if (!strcmp(string_key, "Options")) {
				put_msg_opts.Options = Z_LVAL_PP(option_val);
			} else if (!strcmp(string_key, "Version")) {
				put_msg_opts.Version = Z_LVAL_PP(option_val);
			} else if (!strcmp(string_key, "StrucId")) {
				strncpy(put_msg_opts.StrucId, Z_STRVAL_PP(option_val), sizeof(put_msg_opts.StrucId));
			}
		}

		zend_hash_move_forward_ex(Z_ARRVAL_P(z_put_msg_opts), &pos);
	}

	MQPUT(
		mqdesc->conn,
		mqobj->obj,
		&msg_desc,
		&put_msg_opts,
		msg_len,
		msg,
		&mqdesc->comp_code,
		&mqdesc->reason);

	if (mqdesc->comp_code == MQCC_OK) {
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
}
/* }}} */

/* {{{ proto ressource mqseries_begin(resource mqdesc, array begin_opts)
	Begin a transaction. */
PHP_FUNCTION(mqseries_begin)
{
	mqseries_descriptor *mqdesc;
	zval *z_mqdesc, *z_array, **option_val, *key;
	char  *string_key;
	uint  string_key_len;
	ulong  num_key;
	HashPosition pos;

	MQBO begin_opts = {MQBO_DEFAULT};

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ra", &z_mqdesc,
		&z_array) == FAILURE) {
		return;
	}

	ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, "mqseries_conn", le_mqseries_conn);

	zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(z_array), &pos);
	while (zend_hash_get_current_data_ex(Z_ARRVAL_P(z_array), (void **)&option_val, &pos) == SUCCESS) {
		MAKE_STD_ZVAL(key);

		if (zend_hash_get_current_key_ex(Z_ARRVAL_P(z_array), &string_key, &string_key_len, &num_key, 0, &pos) == HASH_KEY_IS_STRING) {
			if (strcmp(string_key, "StrucId") > 0) {
				strncpy(begin_opts.StrucId, Z_STRVAL_PP(option_val), sizeof(begin_opts.StrucId));
			} else if (strcmp(string_key, "Version") > 0) {
				begin_opts.Version = Z_LVAL_PP(option_val);
			} else if (strcmp(string_key, "Options") > 0) {
				begin_opts.Options = Z_LVAL_PP(option_val);
			}
		}

		zval_ptr_dtor(&key);
		zend_hash_move_forward_ex(Z_ARRVAL_P(z_array), &pos);
	}

	MQBEGIN(
		mqdesc->conn,
		&begin_opts,
		&mqdesc->comp_code,
		&mqdesc->reason);

	if (mqdesc->comp_code == MQCC_OK) {
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
}
/* }}} */

/* {{{ proto ressource mqseries_cmit(resource mqdesc)
	Commit the transaction. */
PHP_FUNCTION(mqseries_cmit)
{
	mqseries_descriptor *mqdesc;
	zval *z_mqdesc;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r", &z_mqdesc)
		== FAILURE) {
		return;
	}

	ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, "mqseries_conn", le_mqseries_conn);

	MQCMIT(
		mqdesc->conn,
		&mqdesc->comp_code,
		&mqdesc->reason);

	if (mqdesc->comp_code == MQCC_OK) {
		RETURN_TRUE;
	} else {
		RETURN_FALSE;
	}
}
/* }}} */

/* {{{ proto ressource mqseries_back(resource mqdesc)
	Rollback the transaction. */
PHP_FUNCTION(mqseries_back)
{
	mqseries_descriptor *mqdesc;
	zval *z_mqdesc;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r", &z_mqdesc)
		== FAILURE) {
		return;
	}

	ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, "mqseries_conn", le_mqseries_conn);

	MQBACK(
		mqdesc->conn,
		&mqdesc->comp_code,
		&mqdesc->reason);

	if (mqdesc->comp_code == MQCC_OK) {
		RETVAL_TRUE;
	} else {
		RETURN_FALSE;
	}
}
/* }}} */

/* {{{ proto bool mqseries_close(mqobj)
	Close a queue. */
PHP_FUNCTION(mqseries_close)
{
	mqseries_obj *mqobj;
	zval *z_mqobj;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r", &z_mqobj) == FAILURE) {
		return;
	}

	ZEND_FETCH_RESOURCE(mqobj, mqseries_obj *, &z_mqobj, -1, "mqseries_obj", le_mqseries_obj);
	zend_list_delete(mqobj->id);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool mqseries_disc(mqdesc)
	Disconnect from the queue manager. */
PHP_FUNCTION(mqseries_disc)
{
	mqseries_descriptor *mqdesc;
	zval *z_mqdesc;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r", &z_mqdesc) == FAILURE) {
		return;
	}

	ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, "mqseries_conn", le_mqseries_conn);
	zend_list_delete(mqdesc->id);
	RETURN_TRUE;
}
/* }}} */

/* {{{ proto bool mqseries_error(mqdesc)
	Return the completion-code and the reason from the last call. */
PHP_FUNCTION(mqseries_error)
{
	mqseries_descriptor *mqdesc;
	zval *z_mqdesc;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r", &z_mqdesc) == FAILURE) {
		return;
	}

	ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, "mqseries_conn", le_mqseries_conn);

	array_init(return_value);
	add_assoc_long(return_value, "comp_code", mqdesc->comp_code);
	add_assoc_long(return_value, "reason", mqdesc->reason);
}
/* }}} */

/* {{{ proto bool mqseries_strerror(reason_code)
	Return the detailed error text for the given reason_code. */
PHP_FUNCTION(mqseries_strerror)
{
	zval **text;
	int reason_code;
	HashTable *target_hash;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &reason_code) == FAILURE) {
		return;
	}

	RETVAL_NULL();

	target_hash = HASH_OF(z_reason_texts);
	if (zend_hash_index_find(target_hash, reason_code, (void **) &text) == SUCCESS) {
		RETVAL_STRING(Z_STRVAL_PP(text), 0);
	}

}
/* }}} */

/* {{{ proto static void set_msg_desc_from_array()
	Put options from the given array into the MQMD structure. */
static void set_msg_desc_from_array(zval *array, MQMD *msg_desc)
{
	zval **option_val;
	char *string_key;
	uint  string_key_len;
	ulong  num_key;
	HashPosition pos;

	zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(array), &pos);
	while (zend_hash_get_current_data_ex(Z_ARRVAL_P(array), (void **)&option_val, &pos) == SUCCESS) {

		if (zend_hash_get_current_key_ex(Z_ARRVAL_P(array), &string_key, &string_key_len, &num_key, 0, &pos) == HASH_KEY_IS_STRING) {
			if (!strcmp(string_key, "CorrelId")) {
				strncpy(msg_desc->CorrelId, Z_STRVAL_PP(option_val), sizeof(msg_desc->CorrelId));
			} else if (!strcmp(string_key, "StrucId")) {
				strncpy(msg_desc->StrucId, Z_STRVAL_PP(option_val),sizeof(msg_desc->StrucId));
			} else if (!strcmp(string_key, "Version")) {
				msg_desc->Version = Z_LVAL_PP(option_val);
			} else if (!strcmp(string_key, "Report")) {
				msg_desc->Report = Z_LVAL_PP(option_val);
			} else if (!strcmp(string_key, "MsgType")) {
				msg_desc->MsgType = Z_LVAL_PP(option_val);
			} else if (!strcmp(string_key, "Expiry")) {
				msg_desc->Expiry = Z_LVAL_PP(option_val);
			} else if (!strcmp(string_key, "Format")) {
				strncpy(msg_desc->Format, Z_STRVAL_PP(option_val),sizeof(msg_desc->Format));
			} else if (!strcmp(string_key, "Priority")) {
				msg_desc->Priority = Z_LVAL_PP(option_val);
			} else if (!strcmp(string_key, "Persistence")) {
				msg_desc->Persistence = Z_LVAL_PP(option_val);
			} else if (!strcmp(string_key, "ReplyToQ")) {
				strncpy(msg_desc->ReplyToQ, Z_STRVAL_PP(option_val), sizeof(msg_desc->ReplyToQ));
			}

		}

		zend_hash_move_forward_ex(Z_ARRVAL_P(array), &pos);
	}

}
/* }}} */

/* {{{ proto static void _mqseries_close() */
static void _mqseries_close(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
	MQLONG comp_code;  /* Completion code	*/
	MQLONG reason;     /* Qualifying reason */
	mqseries_obj *mqobj = (mqseries_obj *)rsrc->ptr;

	MQCLOSE(
		*mqobj->conn,
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
				zend_error(E_WARNING, "_mqseries_close Error %d %d\n", comp_code, reason);
		}
    }
	efree(mqobj);
}
/* }}} */

/* {{{ proto static void _mqseries_disc() */
static void _mqseries_disc(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
	mqseries_descriptor *mqdesc = (mqseries_descriptor *)rsrc->ptr;

	MQDISC(
		&mqdesc->conn,
		&mqdesc->comp_code,
		&mqdesc->reason);

	if ((mqdesc->comp_code != MQCC_OK) || (mqdesc->reason != MQRC_NONE)) {
		switch(mqdesc->reason) {
			case MQRC_CONNECTION_BROKEN:
			case MQRC_HCONN_ERROR:
				break;

			default:
				zend_error(E_WARNING, "_mqseries_disc Error %d %d\n", mqdesc->comp_code, mqdesc->reason);
		}
    }
	efree(mqdesc);
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
