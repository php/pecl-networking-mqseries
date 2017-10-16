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
#include "ext/standard/info.h"
#include "php_mqseries.h"

/* {{{ helper methods
 */
#ifdef ZEND_ENGINE_3
static void _mqseries_disc(zend_resource *rsrc TSRMLS_DC);
static void _mqseries_close(zend_resource *rsrc TSRMLS_DC);
static void _mqseries_bytes(zend_resource *rsrc TSRMLS_DC);
static void _mqseries_hmsg(zend_resource *rsrc TSRMLS_DC);
#else
static void _mqseries_disc(zend_rsrc_list_entry *rsrc TSRMLS_DC);
static void _mqseries_close(zend_rsrc_list_entry *rsrc TSRMLS_DC);
static void _mqseries_bytes(zend_rsrc_list_entry *rsrc TSRMLS_DC);
#endif

#ifndef ZEND_ENGINE_3
static int _mqseries_is_compcode_reason_ref(zval *, zval *);
static int _mqseries_is_called_by_ref(zval *, char *);
#endif

/* }}} */

/* If you declare any globals in php_mqseries.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(mqseries)
*/

/* True global resources - no need for thread safety here */
int le_mqseries_conn;
int le_mqseries_obj;
int le_mqseries_bytes;
int le_mqseries_message;

static HashTable *ht_reason_texts;

/* {{{ arginfo */

/****************************************************************/
/*  Parameter usage in functions and structures                 */
/*    I:    input                                               */
/*    IB:   input, data buffer                                  */
/*    IL:   input, length of data buffer                        */
/*    IO:   input and output                                    */
/*    IOB:  input and output, data buffer                       */
/*    IOL:  input and output, length of data buffer             */
/*    O:    output                                              */
/*    OB:   output, data buffer                                 */
/*    OC:   output, completion code                             */
/*    OR:   output, reason code                                 */
/*    FP:   function pointer                                    */
/****************************************************************/

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_back, 0, 0, 3)
ZEND_ARG_INFO(0, hconn)         /* I: Connection handle */
ZEND_ARG_INFO(1, compCode)        /* OC: Completion code */
ZEND_ARG_INFO(1, reason)        /* OR: Reason code qualifying CompCode */
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_begin, 0, 0, 4)
ZEND_ARG_INFO(0, hconn)         /* I: Connection handle */
ZEND_ARG_ARRAY_INFO(0, beginOptions, 0) /* IO: Options that control the action of MQBEGIN */
ZEND_ARG_INFO(1, compCode)        /* OC: Completion code */
ZEND_ARG_INFO(1, reason)        /* OR: Reason code qualifying CompCode */
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_close, 0, 0, 5)
ZEND_ARG_INFO(0, hconn)         /* I: Connection handle */
ZEND_ARG_INFO(1, hobj)          /* IO: Object handle */
ZEND_ARG_INFO(0, options)       /* I: Options that control the action of MQCLOSE */
ZEND_ARG_INFO(1, compCode)        /* OC: Completion code */
ZEND_ARG_INFO(1, reason)        /* OR: Reason code qualifying CompCode */
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_cmit, 0, 0, 3)
ZEND_ARG_INFO(0, hconn)         /* I: Connection handle */
ZEND_ARG_INFO(1, compCode)        /* OC: Completion code */
ZEND_ARG_INFO(1, reason)        /* OR: Reason code qualifying CompCode */
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_conn, 0, 0, 4)
ZEND_ARG_INFO(0, qMgrName)        /* I: Name of queue manager */
ZEND_ARG_INFO(1, hconn)         /* O: Connection handle */
ZEND_ARG_INFO(1, compCode)        /* OC: Completion code */
ZEND_ARG_INFO(1, reason)        /* OR: Reason code qualifying CompCode */
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_connx, 0, 0, 5)
ZEND_ARG_INFO(0, qMgrName)        /* I: Name of queue manager */
ZEND_ARG_ARRAY_INFO(1, connectOpts, 0)  /* IO: Options that control the action of MQCONNX */
ZEND_ARG_INFO(1, hconn)         /* O: Connection handle */
ZEND_ARG_INFO(1, compCode)        /* OC: Completion code */
ZEND_ARG_INFO(1, reason)        /* OR: Reason code qualifying CompCode */
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_disc, 0, 0, 3)
ZEND_ARG_INFO(0, hconn)         /* IO: Connection handle */
ZEND_ARG_INFO(1, compCode)        /* OC: Completion code */
ZEND_ARG_INFO(1, reason)        /* OR: Reason code qualifying CompCode */
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_get, 0, 0, 9)
ZEND_ARG_INFO(0, hconn)         /* I: Connection handle */
ZEND_ARG_INFO(0, hobj)          /* I: Object handle */
ZEND_ARG_ARRAY_INFO(1, msgDesc, 0)    /* IO: Message descriptor */
ZEND_ARG_ARRAY_INFO(1, getMsgOts, 0)  /* IO: Options that control the action of MQGET */
ZEND_ARG_INFO(0, bufferlength)      /* IL: Length in bytes of the Buffer area */
ZEND_ARG_INFO(1, buffer)        /* OB: Area to contain the message data */
ZEND_ARG_INFO(1, dataLength)      /* O: Length of the message */
ZEND_ARG_INFO(1, compCode)        /* OC: Completion code */
ZEND_ARG_INFO(1, reason)        /* OR: Reason code qualifying CompCode */
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_inq, 0, 0, 10)
ZEND_ARG_INFO(0, hconn)         /* I: Connection handle */
ZEND_ARG_INFO(0, hobj)          /* I: Object handle */
ZEND_ARG_INFO(0, selectorCount)     /* I: Count of selectors */
ZEND_ARG_ARRAY_INFO(0, selectors, 0)  /* I: Array of attribute selectors */
ZEND_ARG_INFO(0, intAttrCount)      /* I: Count of integer attributes */
ZEND_ARG_INFO(1, intAttrs)        /* O: Array of integer attributes */
ZEND_ARG_INFO(0, charAttrLength)    /* IL: Length of character attributes buffer */
ZEND_ARG_INFO(1, charAttrs)       /* OB: Character attributes */
ZEND_ARG_INFO(1, compCode)        /* OC: Completion code */
ZEND_ARG_INFO(1, reason)        /* OR: Reason code qualifying CompCode */
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_open, 0, 0, 6)
ZEND_ARG_INFO(0, hconn)         /* I: Connection handle */
ZEND_ARG_ARRAY_INFO(1, objDesc, 0)    /* IO: Object descriptor */
ZEND_ARG_INFO(0, options)       /* I: Options that control the action of MQOPEN */
ZEND_ARG_INFO(1, hobj)          /* O: Object handle */
ZEND_ARG_INFO(1, compCode)        /* OC: Completion code */
ZEND_ARG_INFO(1, reason)        /* OR: Reason code qualifying CompCode */
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_put, 0, 0, 7)
ZEND_ARG_INFO(0, hconn)         /* I: Connection handle */
ZEND_ARG_INFO(0, hobj)          /* I: Object handle */
ZEND_ARG_ARRAY_INFO(1, msgDesc, 0)    /* IO: Message descriptor */
ZEND_ARG_ARRAY_INFO(1, putMsgOpts, 0) /* IO: Options that control the action of MQPUT */
ZEND_ARG_INFO(0, buffer)        /* IB: Message data */
ZEND_ARG_INFO(1, compCode)        /* OC: Completion code */
ZEND_ARG_INFO(1, reason)        /* OR: Reason code qualifying CompCode */
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_put1, 0, 0, 7)
ZEND_ARG_INFO(0, hconn)         /* I: Connection handle */
ZEND_ARG_ARRAY_INFO(0, objDesc, 0)    /* IO: Object descriptor */
ZEND_ARG_ARRAY_INFO(1, msgDesc, 0)    /* IO: Message descriptor */
ZEND_ARG_ARRAY_INFO(1, putMsgOpts, 0) /* IO: Options that control the action of MQPUT1 */
ZEND_ARG_INFO(0, buffer)        /* IB: Message data */
ZEND_ARG_INFO(1, compCode)        /* OC: Completion code */
ZEND_ARG_INFO(1, reason)        /* OR: Reason code qualifying CompCode */
ZEND_END_ARG_INFO()


ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_set, 0, 0, 10)
ZEND_ARG_INFO(0, hconn)         /* I: Connection handle */
ZEND_ARG_INFO(0, hobj)          /* I: Object handle */
ZEND_ARG_INFO(0, selectorCount)     /* I: Count of selectors */
ZEND_ARG_ARRAY_INFO(0, selectors, 0)  /* I: Array of attribute selectors */
ZEND_ARG_INFO(0, intAttrCount)      /* I: Count of integer attributes */
ZEND_ARG_ARRAY_INFO(0, intAttrs, 0)   /* I: Array of integer attributes */
ZEND_ARG_INFO(0, charAttrLength)    /* IL: Length of character attributes buffer */
ZEND_ARG_ARRAY_INFO(0, charAttrs, 0)  /* IB: Character attributes */
ZEND_ARG_INFO(1, compCode)        /* OC: Completion code */
ZEND_ARG_INFO(1, reason)        /* OR: Reason code qualifying CompCode */
ZEND_END_ARG_INFO()

#ifdef HAVE_MQSERIESLIB_V7
ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_sub, 0, 0, 6)
ZEND_ARG_INFO(0, hconn)         /* I: Connection handle */
ZEND_ARG_ARRAY_INFO(1, subDesc, 0)    /* IO: Subscription descriptor */
ZEND_ARG_INFO(1, hobj)          /* IO: Object handle */
ZEND_ARG_INFO(1, hsub)          /* O: Subscription object handle */
ZEND_ARG_INFO(1, compCode)        /* OC: Completion code */
ZEND_ARG_INFO(1, reason)        /* OR: Reason code qualifying CompCode */
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_stat, 0, 0, 5)
ZEND_ARG_INFO(0, hconn)         /* I: Connection handle */
ZEND_ARG_INFO(0, type)          /* I: Status information type */
ZEND_ARG_ARRAY_INFO(1, status, 0)       /* IO: Status information */
ZEND_ARG_INFO(1, compCode)        /* OC: Completion code */
ZEND_ARG_INFO(1, reason)        /* OR: Reason code qualifying CompCode */
ZEND_END_ARG_INFO()


ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_bufmh, 0, 0, 8)
ZEND_ARG_INFO(0, hconn)         /* I: Connection handle */
ZEND_ARG_INFO(1, hmsg)
ZEND_ARG_ARRAY_INFO(1, bufMsgHOpts, 0)
ZEND_ARG_ARRAY_INFO(1, msgDesc, 0)    /* IO: Message descriptor */
ZEND_ARG_INFO(0, buffer)        /* IB: Message data */
ZEND_ARG_INFO(1, dataLength)      /* O: Length of the message */
ZEND_ARG_INFO(1, compCode)        /* OC: Completion code */
ZEND_ARG_INFO(1, reason)        /* OR: Reason code qualifying CompCode */
ZEND_END_ARG_INFO()


ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_crtmh, 0, 0, 5)
ZEND_ARG_INFO(0, hconn)         /* I: Connection handle */
ZEND_ARG_ARRAY_INFO(1, crtMsgHOpt, 0)
ZEND_ARG_INFO(1, hmsg)
ZEND_ARG_INFO(1, compCode)        /* OC: Completion code */
ZEND_ARG_INFO(1, reason)        /* OR: Reason code qualifying CompCode */
ZEND_END_ARG_INFO()


ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_dltmh, 0, 0, 5)
ZEND_ARG_INFO(0, hconn)          /* I: Connection handle */
ZEND_ARG_INFO(1, hmsg)
ZEND_ARG_ARRAY_INFO(1, dltMsgHOpt, 0)
ZEND_ARG_INFO(1, compCode)       /* OC: Completion code */
ZEND_ARG_INFO(1, reason)           /* OR: Reason code qualifying CompCode */
ZEND_END_ARG_INFO()


ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_dltmp, 0, 0, 6)
ZEND_ARG_INFO(0, hconn)             /* I: Connection handle */
ZEND_ARG_INFO(1, hmsg)
ZEND_ARG_ARRAY_INFO(1, dltPropOpts, 0)
ZEND_ARG_INFO(0, name)                /* I: Name  */
ZEND_ARG_INFO(1, compCode)            /* OC: Completion code */
ZEND_ARG_INFO(1, reason)            /* OR: Reason code qualifying CompCode */
ZEND_END_ARG_INFO()


ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_inqmp, 0, 0, 11)
ZEND_ARG_INFO(0, hconn)             /* I: Connection handle */
ZEND_ARG_INFO(1, hmsg)
ZEND_ARG_ARRAY_INFO(1, inqPropOpts, 0)
ZEND_ARG_INFO(1, name)                /* I: Name  */
ZEND_ARG_ARRAY_INFO(1, propDesc, 0)       /* IO: Message descriptor */
ZEND_ARG_INFO(1, type)              /* I: Status information type */
ZEND_ARG_INFO(0, bufferlength)      /* IL: Length in bytes of the Buffer area */
ZEND_ARG_INFO(1, value)        /* IB: Message data */
ZEND_ARG_INFO(1, dataLength)          /* O: Length of the message */
ZEND_ARG_INFO(1, compCode)            /* OC: Completion code */
ZEND_ARG_INFO(1, reason)            /* OR: Reason code qualifying CompCode */
ZEND_END_ARG_INFO()


ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_mhbuf, 0, 0, 9)
ZEND_ARG_INFO(0, hconn)             /* I: Connection handle */
ZEND_ARG_INFO(1, hmsg)
ZEND_ARG_ARRAY_INFO(1, msgHBufOpts, 0)
ZEND_ARG_INFO(0, name)                /* I: Name  */
ZEND_ARG_ARRAY_INFO(1, msgDesc, 0)        /* IO: Message descriptor */
ZEND_ARG_INFO(0, buffer)        /* IB: Message data */
ZEND_ARG_INFO(1, dataLength)          /* O: Length of the message */
ZEND_ARG_INFO(1, compCode)            /* OC: Completion code */
ZEND_ARG_INFO(1, reason)            /* OR: Reason code qualifying CompCode */
ZEND_END_ARG_INFO()


ZEND_BEGIN_ARG_INFO_EX(arginfo_mqseries_setmp, 0, 0, 10)
ZEND_ARG_INFO(0, hconn)             /* I: Connection handle */
ZEND_ARG_INFO(1, hmsg)
ZEND_ARG_ARRAY_INFO(1, setPropOpts, 0)
ZEND_ARG_INFO(0, name)                /* I: Name  */
ZEND_ARG_ARRAY_INFO(1, propDesc, 0)       /* IO: Message descriptor */
ZEND_ARG_INFO(0, type)              /* I: Status information type */
ZEND_ARG_INFO(0, value)        /* IB: Message data */
ZEND_ARG_INFO(1, compCode)            /* OC: Completion code */
ZEND_ARG_INFO(1, reason)            /* OR: Reason code qualifying CompCode */
ZEND_END_ARG_INFO()



#endif /* HAVE_MQSERIESLIB_V7 */

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
  PHP_FE(mqseries_back,   arginfo_mqseries_back)
  PHP_FE(mqseries_begin,    arginfo_mqseries_begin)
  PHP_FE(mqseries_close,    arginfo_mqseries_close)
  PHP_FE(mqseries_cmit,   arginfo_mqseries_cmit)
  PHP_FE(mqseries_conn,   arginfo_mqseries_conn)
  PHP_FE(mqseries_connx,    arginfo_mqseries_connx)
  PHP_FE(mqseries_disc,   arginfo_mqseries_disc)
  PHP_FE(mqseries_get,    arginfo_mqseries_get)
  PHP_FE(mqseries_inq,    arginfo_mqseries_inq)
  PHP_FE(mqseries_open,   arginfo_mqseries_open)
  PHP_FE(mqseries_put,    arginfo_mqseries_put)
  PHP_FE(mqseries_put1,   arginfo_mqseries_put1)
  PHP_FE(mqseries_set,    arginfo_mqseries_set)
  PHP_FE(mqseries_strerror, arginfo_mqseries_strerror)
  PHP_FE(mqseries_bytes_val,  arginfo_mqseries_bytes_val)
#ifdef HAVE_MQSERIESLIB_V7
  PHP_FE(mqseries_sub,        arginfo_mqseries_sub)
  PHP_FE(mqseries_stat,       arginfo_mqseries_stat)
  PHP_FE(mqseries_bufmh,      arginfo_mqseries_bufmh)
  PHP_FE(mqseries_crtmh,      arginfo_mqseries_crtmh)
  PHP_FE(mqseries_dltmh,      arginfo_mqseries_dltmh)
  PHP_FE(mqseries_dltmp,      arginfo_mqseries_dltmp)
  PHP_FE(mqseries_inqmp,      arginfo_mqseries_inqmp)
  PHP_FE(mqseries_mhbuf,      arginfo_mqseries_mhbuf)
  PHP_FE(mqseries_setmp,      arginfo_mqseries_setmp)
#endif /* HAVE_MQSERIESLIB_V7 */
  {
    NULL, NULL, NULL
  }  /* Must be the last line in mqseries_functions[] */
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

//#ifdef COMPILE_DL_MQSERIES
ZEND_GET_MODULE(mqseries)
//#endif


/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(mqseries) {
  char *vp = NULL;

  /* don't change the order of these, objects must be freed before connections */
  le_mqseries_obj = zend_register_list_destructors_ex(_mqseries_close, NULL, PHP_MQSERIES_OBJ_RES_NAME, module_number);

  le_mqseries_conn = zend_register_list_destructors_ex(_mqseries_disc, NULL, PHP_MQSERIES_DESCRIPTOR_RES_NAME, module_number);

  le_mqseries_bytes = zend_register_list_destructors_ex(_mqseries_bytes, NULL, PHP_MQSERIES_BYTES_RES_NAME, module_number);

  le_mqseries_message = zend_register_list_destructors_ex(_mqseries_hmsg, NULL, PHP_MQSERIES_MESSAGE_RES_NAME, module_number);

#include "mqseries_init_const.h"

  ht_reason_texts = (HashTable *) malloc(sizeof(HashTable));
  zend_hash_init(ht_reason_texts, 0, NULL, NULL, 1);

#ifdef ZEND_ENGINE_3
#define ADD_MQ_REASON_TXT(key, value) { vp = value; zend_hash_index_update_ptr(ht_reason_texts, key, vp); }
#else
#define ADD_MQ_REASON_TXT(key, value) { vp = value; zend_hash_index_update(ht_reason_texts, key, &vp, sizeof(char*), NULL); }
#endif
#include "mqseries_reason_texts.h"

  return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(mqseries) {
  zend_hash_destroy(ht_reason_texts);
  free(ht_reason_texts);
  return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(mqseries) {
  php_info_print_table_start();
  php_info_print_table_header(2, "mqseries support", "enabled");
  php_info_print_table_row(2, "Version", PHP_MQSERIES_VERSION);
  php_info_print_table_row(2, "Revision", "$Id$");
  php_info_print_table_end();
}
/* }}} */

/* {{{ proto void mqseries_conn(string name, resource &hconn, int &compcode, int &reason)

The mqseries_conn call connects an application program to a queue manager.
It provides a queue manager connection handle, which the application uses on subsequent message queuing calls.

PHP sample:

  mqseries_conn('QM_donald', $hconn, $compCode, $reason);
  if ($compCode !== MQSERIES_MQCC_OK) {
    printf("CompCode:%d Reason:%d Text:%s\n", $compCode, $reason, mqseries_strerror($reason));
  }

MQ call:

  MQCONN (QMgrName, &Hconn, &CompCode, &Reason);

  MQCHAR48  QMgrName;  -- Name of queue manager
  MQHCONN   Hconn;     -- Connection handle
  MQLONG    CompCode;  -- Completion code
  MQLONG    Reason;    -- Reason code qualifying CompCode

*/
PHP_FUNCTION(mqseries_conn) {
  char *name = NULL;
#ifdef ZEND_ENGINE_3
  size_t name_len = 0;
#else
  long name_len;
#endif
  zval *z_conn, *z_comp_code, *z_reason;

  mqseries_descriptor *mqdesc;

  MQCHAR48 qManagerName;
  MQLONG comp_code = 0;
  MQLONG reason = 0;

#ifdef ZEND_ENGINE_3
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sz/z/z/", &name, &name_len, &z_conn, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }
#else
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "szzz", &name, &name_len, &z_conn, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if (!_mqseries_is_called_by_ref(z_conn, "conn")) return;
  if (!_mqseries_is_compcode_reason_ref(z_comp_code, z_reason)) return;
#endif

  strncpy(qManagerName, name, sizeof(MQCHAR48));

  mqdesc = (mqseries_descriptor *) emalloc(sizeof(mqseries_descriptor));
  MQCONN(qManagerName, &mqdesc->conn, &comp_code, &reason);

  ZVAL_LONG(z_comp_code, (long) comp_code);
  ZVAL_LONG(z_reason, (long) reason);

  if (comp_code == MQCC_OK) {
    zval_dtor(z_conn);
#ifdef ZEND_ENGINE_3
    ZVAL_RES(z_conn, zend_register_resource(mqdesc, le_mqseries_conn));
    mqdesc->id = Z_RES_P(z_conn)->handle;
#else
    ZEND_REGISTER_RESOURCE(z_conn, mqdesc, le_mqseries_conn);
    mqdesc->id = Z_RESVAL_P(z_conn);
#endif
  }
  else {
    efree(mqdesc);
  }
}
/* }}} */

/* {{{ proto void mqseries_connx(string name, array &connect_opts, resource &hconn, int &compCode, int &reason)

The mqseries_connx call connects an application program to a queue manager. It provides a queue manager connection handle, which is used by the application on subsequent MQ calls.
The mqseries_connx call is similar to the mqseries_conn call, except that mqseries_connx allows options to be specified to control the way that the call works.

PHP sample:

  $mqcno = array(
    'StrucId' => MQSERIES_MQCNO_STRUC_ID,
    'Version' => MQSERIES_MQCNO_VERSION_2,
    'Options' => MQSERIES_MQCNO_STANDARD_BINDING,
    'MQCD' => array(
      'ChannelName' => 'D800MQ.CLIENT',
      'ConnectionName' => 'localhost',
      'TransportType' => MQSERIES_MQXPT_TCP,
    ),
  );
  mqseries_connx('D800MQ', $mqcno, $hconn, $compCode, $reason);
  if ($compCode !== MQSERIES_MQCC_OK) {
    printf("CompCode:%d Reason:%d Text:%s\n", $compCode, $reason, mqseries_strerror($reason));
  }

MQ call:

  MQCONNX (QMgrName, &ConnectOpts, &Hconn, &CompCode, &Reason);

  MQCHAR48  QMgrName;     -- Name of queue manager
  MQCNO     ConnectOpts;  -- Options that control the action of MQCONNX
  MQHCONN   Hconn;        -- Connection handle
  MQLONG    CompCode;     -- Completion code
  MQLONG    Reason;       -- Reason code qualifying CompCode
*/
PHP_FUNCTION(mqseries_connx) {
  char *name;
#ifdef ZEND_ENGINE_3
  size_t name_len;
#else
  int name_len;
#endif
  mqseries_descriptor *mqdesc;
  zval *z_connect_opts, *z_conn, *z_comp_code, *z_reason;

  MQLONG comp_code;
  MQLONG reason;
  MQCNO connect_opts                      = {MQCNO_DEFAULT};
  MQCD  channel_definition                = {MQCD_CLIENT_CONN_DEFAULT};
  MQSCO ssl_configuration                 = {MQSCO_DEFAULT};
  MQAIR authentication_information_record = {MQAIR_DEFAULT}; /* Only 1 (one) record is supported for now. */
  MQCHAR LDAPUserName[MQ_DISTINGUISHED_NAME_LENGTH];



#ifdef ZEND_ENGINE_3
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "saz/z/z/", &name, &name_len, &z_connect_opts, &z_conn, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }
#else
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "sazzz", &name, &name_len, &z_connect_opts, &z_conn, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if (!_mqseries_is_called_by_ref(z_conn, "hconn")) return;
  if (!_mqseries_is_compcode_reason_ref(z_comp_code, z_reason)) return;
#endif

  _mqseries_set_mqcno_from_array(z_connect_opts, &connect_opts, &channel_definition, &ssl_configuration, &authentication_information_record, LDAPUserName TSRMLS_CC);

  mqdesc = (mqseries_descriptor *) emalloc(sizeof(mqseries_descriptor));



  MQCONNX(name, &connect_opts, &mqdesc->conn, &comp_code, &reason);

  ZVAL_LONG(z_comp_code, (long) comp_code);
  ZVAL_LONG(z_reason, (long) reason);

  if (comp_code == MQCC_OK) {
    zval_dtor(z_conn);
#ifdef ZEND_ENGINE_3
    ZVAL_RES(z_conn, zend_register_resource(mqdesc, le_mqseries_conn));
    mqdesc->id = Z_RES_P(z_conn)->handle;
#else
    ZEND_REGISTER_RESOURCE(z_conn, mqdesc, le_mqseries_conn);
    mqdesc->id = Z_RESVAL_P(z_conn);
#endif
  }
  else {
    efree(mqdesc);
  }
}
/* }}} */

/* {{{ proto void mqseries_open(resource hconn, array &objDesc, int options, resource &hobj, int &compCode, int &reason)

The mq_open call establishes access to an object.

PHP sample:

  mqseries_open(
    $conn,
    array('ObjectName' => 'TESTQ', 'ObjectQMgrName' => 'D800MQ'),
    MQSERIES_MQOO_INPUT_AS_Q_DEF | MQSERIES_MQOO_FAIL_IF_QUIESCING | MQSERIES_MQOO_OUTPUT,
    $obj,
    $compCode,
    $reason
  );
  if ($compCode !== MQSERIES_MQCC_OK) {
    printf("CompCode:%d Reason:%d Text:%s\n", $compCode, $reason, mqseries_strerror($reason));
  }

MQ call:

  MQOPEN (Hconn, &ObjDesc, Options, &Hobj, &CompCode, &Reason);

  MQHCONN  Hconn;     -- Connection handle
  MQOD     ObjDesc;   -- Object descriptor
  MQLONG   Options;   -- Options that control the action of MQOPEN
  MQHOBJ   Hobj;      -- Object handle
  MQLONG   CompCode;  -- Completion code
  MQLONG   Reason;    -- Reason code qualifying CompCode
*/
PHP_FUNCTION(mqseries_open) {
  mqseries_descriptor *mqdesc;
  mqseries_obj *mqobj;
  zval *z_mqdesc, *z_obj_desc, *z_obj, *z_comp_code, *z_reason;

#ifdef ZEND_ENGINE_3
  zend_long open_options;
#else
  long open_options;
#endif

  MQLONG comp_code;
  MQLONG reason;
  MQOD obj_desc = {MQOD_DEFAULT};

#ifdef ZEND_ENGINE_3
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ra/lz/z/z/", &z_mqdesc, &z_obj_desc, &open_options, &z_obj, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if ((mqdesc = (mqseries_descriptor *) zend_fetch_resource(Z_RES_P(z_mqdesc), PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn)) == NULL) {
    RETURN_FALSE;
  }
#else
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ralzzz", &z_mqdesc, &z_obj_desc, &open_options, &z_obj, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if (!_mqseries_is_called_by_ref(z_obj, "hobj")) return;
  if (!_mqseries_is_compcode_reason_ref(z_comp_code, z_reason)) return;

  ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);
#endif

  _mqseries_set_mqod_from_array(z_obj_desc, &obj_desc TSRMLS_CC);

  mqobj = (mqseries_obj *) emalloc(sizeof(mqseries_obj));

  MQOPEN(mqdesc->conn, &obj_desc, (MQLONG) open_options, &mqobj->obj, &comp_code, &reason);

  ZVAL_LONG(z_comp_code, (long) comp_code);
  ZVAL_LONG(z_reason, (long) reason);

#ifdef ZEND_ENGINE_3
  _mqseries_set_array_from_mqod(z_obj_desc, &obj_desc TSRMLS_CC);
#else
  if (PZVAL_IS_REF(z_obj_desc)) {
    _mqseries_set_array_from_mqod(z_obj_desc, &obj_desc TSRMLS_CC);
  }
#endif

  if (comp_code == MQCC_OK) {
    zval_dtor(z_obj);
    mqobj->conn = &mqdesc->conn;
#ifdef ZEND_ENGINE_3
    ZVAL_RES(z_obj, zend_register_resource(mqobj, le_mqseries_obj));
    mqobj->id = Z_RES_P(z_obj)->handle;
#else
    ZEND_REGISTER_RESOURCE(z_obj, mqobj, le_mqseries_obj);
    mqobj->id = Z_RESVAL_P(z_obj);
#endif
  }
  else {
    /* So we don't register the ref. But we already allocated some memory lets free that */
    efree(mqobj);
  }
}
/* }}} */

/* {{{ proto void mqseries_get(resource hconn, resource hobj, array &msgDesc, array &getMsgOpts, int bufferLength, string &buffer, int &dataLength, int &compCode, int &reason)

The mqseries_get call retrieves a message from a local queue that has been opened using the mqseries_open call.

PHP sample:

  $mqmd = array();
  $mqgmo = array(
    'Options' => MQSERIES_MQGMO_FAIL_IF_QUIESCING | MQSERIES_MQGMO_WAIT,
       'WaitInterval' => MQSERIES_MQWI_UNLIMITED
  );
  mqseries_get($conn, $obj, $mqmd, $mqmo, 10, $msg, $dataLength, $compCode, $reason);
  if ($compCode !== MQSERIES_MQCC_OK) {
    printf("CompCode:%d Reason:%d Text:%s\n", $compCode, $reason, mqseries_strerror($reason));
  }

MQ call:

  MQGET (Hconn, Hobj, &MsgDesc, &GetMsgOpts, BufferLength, Buffer, &DataLength, &CompCode, &Reason);

  MQHCONN  Hconn;         -- Connection handle
  MQHOBJ   Hobj;          -- Object handle
  MQMD     MsgDesc;       -- Message descriptor
  MQGMO    GetMsgOpts;    -- Options that control the action of MQGET
  MQLONG   BufferLength;  -- Length in bytes of the Buffer area
  MQBYTE   Buffer[n];     -- Area to contain the message data
  MQLONG   DataLength;    -- Length of the message
  MQLONG   CompCode;      -- Completion code
  MQLONG   Reason;        -- Reason code qualifying CompCode

*/
PHP_FUNCTION(mqseries_get) {
  mqseries_descriptor *mqdesc;
  mqseries_obj *mqobj;
  zval *z_mqdesc, *z_mqobj, *z_msg_desc, *z_get_msg_opts, *z_comp_code, *z_reason, *z_data_length, *z_buffer;

  MQLONG comp_code;
  MQLONG reason;

#ifdef ZEND_ENGINE_3
  zend_long buf_len = 0L;
#else
  long buf_len = 0L;
#endif

  MQLONG data_length = 0L;
  MQBYTE *buf, *data;
  MQMD msg_desc =    { MQMD_DEFAULT };  /* Message descriptor */
  MQGMO get_msg_opts = { MQGMO_DEFAULT }; /* Options which control the MQGET call */

#ifdef ZEND_ENGINE_3
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rra/a/lz/z/z/z/", &z_mqdesc, &z_mqobj, &z_msg_desc, &z_get_msg_opts, &buf_len, &z_buffer, &z_data_length, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if ((mqdesc = (mqseries_descriptor *) zend_fetch_resource(Z_RES_P(z_mqdesc), PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn)) == NULL) {
    RETURN_FALSE;
  }
  if ((mqobj = (mqseries_obj *) zend_fetch_resource(Z_RES_P(z_mqobj), PHP_MQSERIES_OBJ_RES_NAME, le_mqseries_obj)) == NULL) {
    RETURN_FALSE;
  }
#else
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rraalzzzz", &z_mqdesc, &z_mqobj, &z_msg_desc, &z_get_msg_opts, &buf_len, &z_buffer, &z_data_length, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if (!_mqseries_is_called_by_ref(z_data_length, "dataLength")) return;
  if (!_mqseries_is_called_by_ref(z_buffer, "buffer")) return;
  if (!_mqseries_is_compcode_reason_ref(z_comp_code, z_reason)) return;

  ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);
  ZEND_FETCH_RESOURCE(mqobj, mqseries_obj *, &z_mqobj, -1, PHP_MQSERIES_OBJ_RES_NAME, le_mqseries_obj);
#endif

  _mqseries_set_mqmd_from_array(z_msg_desc, &msg_desc TSRMLS_CC);
  _mqseries_set_mqgmo_from_array(z_get_msg_opts, &get_msg_opts TSRMLS_CC);

  data = buf = (MQBYTE *) emalloc(sizeof(MQBYTE) * buf_len);
  MQGET(mqdesc->conn, mqobj->obj, &msg_desc, &get_msg_opts, (MQLONG) buf_len, buf, &data_length, &comp_code, &reason);

  if (!strncmp(msg_desc.Format, MQFMT_RF_HEADER, sizeof(msg_desc.Format))) {
    MQRFH rfh = {MQRFH_DEFAULT};
    memcpy(&rfh, buf, MQRFH_STRUC_LENGTH_FIXED);
    data = buf + rfh.StrucLength;
    buf_len -= rfh.StrucLength;
  }
  else if (!strncmp(msg_desc.Format, MQFMT_RF_HEADER_2, sizeof(msg_desc.Format))) {
    MQRFH2 rfh2 = {MQRFH2_DEFAULT};
    memcpy(&rfh2, buf, MQRFH_STRUC_LENGTH_FIXED_2);
    data = buf + rfh2.StrucLength;
    buf_len -= rfh2.StrucLength;
  }
  else if (!strncmp(msg_desc.Format, MQFMT_MD_EXTENSION, sizeof(msg_desc.Format))) {
    MQMDE rfhe = { MQMDE_DEFAULT };
    memcpy(&rfhe, buf, MQMDE_LENGTH_2);
    data = buf + rfhe.StrucLength;
    buf_len -= rfhe.StrucLength;
  }

  ZVAL_LONG(z_comp_code, (long) comp_code);
  ZVAL_LONG(z_reason, (long) reason);
  ZVAL_LONG(z_data_length, (long) data_length);

  zval_dtor(z_buffer);

#ifdef ZEND_ENGINE_3
  ZVAL_STRINGL(z_buffer, (char *) data, (buf_len > 0) ? (buf_len < (long) data_length ? buf_len : (long) data_length) : 0);

  _mqseries_set_array_from_mqmd(z_msg_desc, &msg_desc TSRMLS_CC);
  _mqseries_set_array_from_mqgmo(z_get_msg_opts, &get_msg_opts TSRMLS_CC);
#else
  ZVAL_STRINGL(z_buffer, (char *) data, (buf_len > 0) ? (buf_len < (long) data_length ? buf_len : (long) data_length) : 0, 1);

  if (PZVAL_IS_REF(z_msg_desc)) {
    _mqseries_set_array_from_mqmd(z_msg_desc, &msg_desc TSRMLS_CC);
  }
  if (PZVAL_IS_REF(z_get_msg_opts)) {
    _mqseries_set_array_from_mqgmo(z_get_msg_opts, &get_msg_opts TSRMLS_CC);
  }
#endif

  efree(buf);
}
/* }}} */

/* {{{ proto void mqseries_put(resource hconn, resource hobj, array &msgDesc, array &putMsgOpts, string buffer, int &compCode, int &reason)

The mqseries_put call puts a message on a queue or distribution list, or to a topic. The queue, distribution list or topic must already be open.

PHP sample:

  $md =   array(
    'Version' => MQSERIES_MQMD_VERSION_1,
    'Expiry' => MQSERIES_MQEI_UNLIMITED,
    'Report' => MQSERIES_MQRO_NONE,
    'MsgType' => MQSERIES_MQMT_DATAGRAM,
    'Format' => MQSERIES_MQFMT_STRING,
    'Priority' => 1,
    'Persistence' => MQSERIES_MQPER_PERSISTENT,
    'ReplyToQ' => 'RCVQ'
  );
  mqseries_put($conn, $obj_snd, $md, array('Options' => MQSERIES_MQPMO_NEW_MSG_ID), 'Ping', $compCode, $reason);
  if ($compCode !== MQSERIES_MQCC_OK) {
    printf("CompCode:%d Reason:%d Text:%s\n", $compCode, $reason, mqseries_strerror($reason));
  }

MQ call:

  MQPUT (Hconn, Hobj, &MsgDesc, &PutMsgOpts, BufferLength, Buffer, &CompCode, &Reason);

  MQHCONN  Hconn;         -- Connection handle
  MQHOBJ   Hobj;          -- Object handle
  MQMD     MsgDesc;       -- Message descriptor
  MQPMO    PutMsgOpts;    -- Options that control the action of MQPUT
  MQLONG   BufferLength;  -- Length of the message in Buffer
  MQBYTE   Buffer[n];     -- Message data
  MQLONG   CompCode;      -- Completion code
  MQLONG   Reason;        -- Reason code qualifying CompCode
*/
PHP_FUNCTION(mqseries_put) {
  mqseries_descriptor *mqdesc;
  mqseries_obj *mqobj;
  zval *z_mqdesc, *z_mqobj, *z_msg_desc, *z_put_msg_opts, *z_comp_code, *z_reason;
  char  *msg;
#ifdef ZEND_ENGINE_3
  zend_long msg_len;
#else
  long msg_len;
#endif

  MQMD msg_desc = {MQMD_DEFAULT}; /* Message descriptor */
  MQPMO put_msg_opts = {MQPMO_DEFAULT}; /* Options which control the MQPUT call */
  MQLONG comp_code;
  MQLONG reason;

#ifdef ZEND_ENGINE_3
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rra/a/sz/z/", &z_mqdesc, &z_mqobj, &z_msg_desc, &z_put_msg_opts, &msg, &msg_len, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if ((mqdesc = (mqseries_descriptor *) zend_fetch_resource(Z_RES_P(z_mqdesc), PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn)) == NULL) {
    RETURN_FALSE;
  }
  if ((mqobj = (mqseries_obj *) zend_fetch_resource(Z_RES_P(z_mqobj), PHP_MQSERIES_OBJ_RES_NAME, le_mqseries_obj)) == NULL) {
    RETURN_FALSE;
  }
#else
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rraaszz", &z_mqdesc, &z_mqobj, &z_msg_desc, &z_put_msg_opts, &msg, &msg_len, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if (!_mqseries_is_compcode_reason_ref(z_comp_code, z_reason)) return;

  ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);
  ZEND_FETCH_RESOURCE(mqobj, mqseries_obj *, &z_mqobj, -1, PHP_MQSERIES_OBJ_RES_NAME, le_mqseries_obj);
#endif

  _mqseries_set_mqmd_from_array(z_msg_desc, &msg_desc TSRMLS_CC);
  _mqseries_set_mqpmo_from_array(z_put_msg_opts, &put_msg_opts TSRMLS_CC);

  MQPUT(mqdesc->conn, mqobj->obj, &msg_desc,  &put_msg_opts, (MQLONG) msg_len, msg, &comp_code, &reason);

  ZVAL_LONG(z_comp_code, (long) comp_code);
  ZVAL_LONG(z_reason, (long) reason);

#ifdef ZEND_ENGINE_3
  _mqseries_set_array_from_mqmd(z_msg_desc, &msg_desc TSRMLS_CC);
  _mqseries_set_array_from_mqpmo(z_put_msg_opts, &put_msg_opts);
#else
  if (PZVAL_IS_REF(z_msg_desc)) {
    _mqseries_set_array_from_mqmd(z_msg_desc, &msg_desc TSRMLS_CC);
  }
  if (PZVAL_IS_REF(z_put_msg_opts)) {
    _mqseries_set_array_from_mqpmo(z_put_msg_opts, &put_msg_opts);
  }
#endif
}
/* }}} */

/* {{{ proto void mqseries_begin(resource hconn, array &beginOptions, int &compCode, int &reason)

The mqseries_begin call begins a unit of work that is coordinated by the queue manager, and that may involve external resource managers.

PHP sample:

  mqseries_begin(
    $conn,
    array('Options' => MQSERIES_MQBO_NONE),
    $compCcode,
    $reason
  );

MQ call:

  MQBEGIN (Hconn, &BeginOptions, &CompCode, &Reason);

  MQHCONN  Hconn;         -- Connection handle
  MQBO     BeginOptions;  -- Options that control the action of MQBEGIN
  MQLONG   CompCode;      -- Completion code
  MQLONG   Reason;        -- Reason code qualifying CompCode
*/
PHP_FUNCTION(mqseries_begin) {
  mqseries_descriptor *mqdesc;
  zval *z_mqdesc, *z_array, *z_comp_code, *z_reason;
  MQLONG comp_code;
  MQLONG reason;

  MQBO begin_opts = {MQBO_DEFAULT};

#ifdef ZEND_ENGINE_3
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "raz/z/", &z_mqdesc, &z_array, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if ((mqdesc = (mqseries_descriptor *) zend_fetch_resource(Z_RES_P(z_mqdesc), PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn)) == NULL) {
    RETURN_FALSE;
  }
#else
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "razz", &z_mqdesc, &z_array, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if (!_mqseries_is_compcode_reason_ref(z_comp_code, z_reason)) return;

  ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);
#endif

  _mqseries_set_mqbo_from_array(z_array, &begin_opts);

  MQBEGIN(mqdesc->conn, &begin_opts, &comp_code, &reason);

  ZVAL_LONG(z_comp_code, (long) comp_code);
  ZVAL_LONG(z_reason, (long) reason);
}
/* }}} */

/* {{{ proto void mqseries_cmit(resource hconn, int &compCode, int &reason)

The mqseries_cmit call indicates to the queue manager that the application has reached a syncpoint, and that all the message
gets and puts that have occurred since the last syncpoint are to be made permanent.

PHP sample:

  mqseries_cmit($conn, $compCode, $reason);

MQ call:

  MQCMIT (Hconn, &CompCode, &Reason);

  MQHCONN  Hconn;     -- Connection handle
  MQLONG   CompCode;  -- Completion code
  MQLONG   Reason;    -- Reason code qualifying CompCode
*/
PHP_FUNCTION(mqseries_cmit) {
  MQLONG comp_code;
  MQLONG reason;

  mqseries_descriptor *mqdesc;
  zval *z_mqdesc, *z_comp_code, *z_reason;

#ifdef ZEND_ENGINE_3
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rz/z/", &z_mqdesc, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if ((mqdesc = (mqseries_descriptor *) zend_fetch_resource(Z_RES_P(z_mqdesc), PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn)) == NULL) {
    RETURN_FALSE;
  }
#else
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rzz", &z_mqdesc, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if (!_mqseries_is_compcode_reason_ref(z_comp_code, z_reason)) return;

  ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);
#endif

  MQCMIT(mqdesc->conn, &comp_code, &reason);

  ZVAL_LONG(z_comp_code, (long) comp_code);
  ZVAL_LONG(z_reason, (long) reason);
}
/* }}} */

/* {{{ proto void mqseries_back(resource hconn, int &compcode, int &reason)

The mqseries_back call indicates to the queue manager that all the message gets and puts that have occurred since the last syncpoint are to be backed out.

PHP sample:

  mqseries_back($conn, $compCode, $reason);

MQ call:

  MQBACK (Hconn, &CompCode, &Reason);

  MQHCONN  Hconn;     -- Connection handle
  MQLONG   CompCode;  -- Completion code
  MQLONG   Reason;    -- Reason code qualifying CompCode
*/
PHP_FUNCTION(mqseries_back) {
  MQLONG comp_code;
  MQLONG reason;

  mqseries_descriptor *mqdesc;
  zval *z_mqdesc, *z_comp_code, *z_reason;

#ifdef ZEND_ENGINE_3
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rz/z/", &z_mqdesc, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if ((mqdesc = (mqseries_descriptor *) zend_fetch_resource(Z_RES_P(z_mqdesc), PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn)) == NULL) {
    RETURN_FALSE;
  }
#else
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rzz", &z_mqdesc, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if (!_mqseries_is_compcode_reason_ref(z_comp_code, z_reason)) return;

  ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);
#endif

  MQBACK(mqdesc->conn, &comp_code, &reason);

  ZVAL_LONG(z_comp_code, (long) comp_code);
  ZVAL_LONG(z_reason, (long) reason);
}
/* }}} */

/* {{{ proto void mqseries_close(resoure hconn, resource &hobj, int options, int &compCode, int &reason)

The mqseries_close call relinquishes access to an object, and is the inverse of the mqseries_open and mqseries_sub calls.

PHP sample:

  mqseries_close($conn, $obj, MQSERIES_MQCO_NONE, $compCode, $reason);

MQ call:

  MQCLOSE (Hconn, &Hobj, Options, &CompCode, &Reason);

  MQHCONN  Hconn;     -- Connection handle
  MQHOBJ   Hobj;      -- Object handle
  MQLONG   Options;   -- Options that control the action of MQCLOSE
  MQLONG   CompCode;  -- Completion code
  MQLONG   Reason;    -- Reason code qualifying CompCode
*/
PHP_FUNCTION(mqseries_close) {
  MQLONG comp_code;
  MQLONG reason;
#ifdef ZEND_ENGINE_3
  zend_long close_options;
#else
  long close_options;
#endif

  mqseries_obj *mqobj;
  mqseries_descriptor *mqdesc;
  zval *z_mqdesc, *z_mqobj, *z_comp_code, *z_reason;

  zend_output_debug_string(1, "%s", "MQClose - start");

#ifdef ZEND_ENGINE_3
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rrlz/z/", &z_mqdesc, &z_mqobj, &close_options, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if ((mqdesc = (mqseries_descriptor *) zend_fetch_resource(Z_RES_P(z_mqdesc), PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn)) == NULL) {
    RETURN_FALSE;
  }
  if ((mqobj = (mqseries_obj *) zend_fetch_resource(Z_RES_P(z_mqobj), PHP_MQSERIES_OBJ_RES_NAME, le_mqseries_obj)) == NULL) {
    RETURN_FALSE;
  }
#else
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rrlzz", &z_mqdesc, &z_mqobj, &close_options, &z_comp_code, &z_reason) == FAILURE) {
    zend_output_debug_string(1, "%s", "MQClose - parse error");
    return;
  }

  if (!_mqseries_is_compcode_reason_ref(z_comp_code, z_reason)) {
    zend_output_debug_string(1, "%s", "MQClose - call by ref error");
    return;
  }

  ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);
  ZEND_FETCH_RESOURCE(mqobj, mqseries_obj *, &z_mqobj, -1, PHP_MQSERIES_OBJ_RES_NAME, le_mqseries_obj);
#endif

  MQCLOSE(mqdesc->conn, &mqobj->obj, (MQLONG) close_options, &comp_code, &reason);

  ZVAL_LONG(z_comp_code, (long) comp_code);
  ZVAL_LONG(z_reason, (long) reason);

#ifdef ZEND_ENGINE_3
  zend_list_close(Z_RES_P(z_mqobj));
#else
  zend_list_delete(mqobj->id);
#endif
  zend_output_debug_string(1, "%s", "MQClose - end");
}
/* }}} */

/* {{{ internal used nethod to close resources void _mqseries_close() */
#ifdef ZEND_ENGINE_3
static void _mqseries_close(zend_resource *rsrc TSRMLS_DC)
#else
static void _mqseries_close(zend_rsrc_list_entry *rsrc TSRMLS_DC)
#endif
{
  MQLONG comp_code;  /* Completion code */
  MQLONG reason;     /* Qualifying reason */
  mqseries_obj *mqobj = (mqseries_obj *)rsrc->ptr;

  if (mqobj->obj != MQHO_UNUSABLE_HOBJ) {        /* Already closed */
    if (*mqobj->conn != MQHC_UNUSABLE_HCONN) { /* Already disconeccted */
      /* Should not be posible but just in case */

      MQCLOSE(*mqobj->conn, &mqobj->obj, MQCO_NONE, &comp_code, &reason);

      if ((comp_code != MQCC_OK) || (reason != MQRC_NONE && reason)) {
        switch (reason) {
          case MQRC_CONNECTION_BROKEN:
          case MQRC_HCONN_ERROR:
          case MQRC_HOBJ_ERROR:
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

/* {{{ proto void mqseries_disc(resource &hconn, int &compCode, int &reason)

The mqseries_disc call breaks the connection between the queue manager and the application program, and is the inverse of the mqseries_conn or mqseries_connx call.

PHP sample:

  mqseries_disc($conn, $compCode, $reason);
  if ($compCode !== MQSERIES_MQCC_OK) {
    printf("CompCode:%d Reason:%d Text:%s\n", $compCode, $reason, mqseries_strerror($reason));
  }

MQ call:

  MQDISC (&Hconn, &CompCode, &Reason);

  MQHCONN  Hconn;     -- Connection handle
  MQLONG   CompCode;  -- Completion code
  MQLONG   Reason;    -- Reason code qualifying CompCode
  Parent topic: Language invocations for MQDISC
*/
PHP_FUNCTION(mqseries_disc) {
  MQLONG comp_code;  /* Completion code */
  MQLONG reason;     /* Qualifying reason */

  mqseries_descriptor *mqdesc;
  zval *z_mqdesc, *z_comp_code, *z_reason;

  zend_output_debug_string(1, "%s", "MQDisc - start");

#ifdef ZEND_ENGINE_3
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rz/z/", &z_mqdesc, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if ((mqdesc = (mqseries_descriptor *) zend_fetch_resource(Z_RES_P(z_mqdesc), PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn)) == NULL) {
    RETURN_FALSE;
  }
#else
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rzz", &z_mqdesc, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if (!_mqseries_is_compcode_reason_ref(z_comp_code, z_reason)) return;

  ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);
#endif

  MQDISC(&mqdesc->conn, &comp_code, &reason);

  ZVAL_LONG(z_comp_code, (long) comp_code);
  ZVAL_LONG(z_reason, (long) reason);

#ifdef ZEND_ENGINE_3
  zend_list_close(Z_RES_P(z_mqdesc));
#else
  zend_list_delete(mqdesc->id);
#endif
  zend_output_debug_string(1, "%s", "MQDisc - end");
}
/* }}} */

/* {{{ internal used disconnect method _mqseries_disc() */
#ifdef ZEND_ENGINE_3
static void _mqseries_disc(zend_resource *rsrc TSRMLS_DC)
#else
static void _mqseries_disc(zend_rsrc_list_entry *rsrc TSRMLS_DC)
#endif
{
  MQLONG comp_code;  /* Completion code */
  MQLONG reason;     /* Qualifying reason */

  mqseries_descriptor *mqdesc = (mqseries_descriptor *)rsrc->ptr;

  if (mqdesc->conn != MQHC_UNUSABLE_HCONN) {

    MQBACK(mqdesc->conn, &comp_code, &reason);
    MQDISC(&mqdesc->conn, &comp_code, &reason);

    if ((comp_code != MQCC_OK) || (reason != MQRC_NONE)) {
      switch (reason) {
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

/* {{{ proto string mqseries_strerror(int reason)

Returns the detailed error text for the given reason code.

PHP sample:

  echo mqseries_strerror($reason);
*/
PHP_FUNCTION(mqseries_strerror) {
#ifdef ZEND_ENGINE_3
  char *text;
  zend_long reason_code;
#else
  char **text;
  long reason_code;
#endif

  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "l", &reason_code) == FAILURE) {
    return;
  }

  RETVAL_NULL();

#ifdef ZEND_ENGINE_3
  if ((text = zend_hash_index_find_ptr(ht_reason_texts, reason_code)) != NULL) {
    RETVAL_STRING(text);
  }
#else
  if (zend_hash_index_find(ht_reason_texts, reason_code, (void **) &text) == SUCCESS) {
    RETVAL_STRING(*text, 1);
  }
#endif
}
/* }}} */

/* {{{ proto void mqseries_put1(resource hconn, array &objDesc, array &msgDesc, array &putMsgOpts, string buffer, int &compCode, int &reason)

The mqseries_put1 call puts one message on a queue, or distribution list, or to a topic.

PHP sample:



MQ call:

  MQPUT1 (Hconn, &ObjDesc, &MsgDesc, &PutMsgOpts, BufferLength, Buffer, &CompCode, &Reason);

  MQHCONN  Hconn;         -- Connection handle
  MQOD     ObjDesc;       -- Object descriptor
  MQMD     MsgDesc;       -- Message descriptor
  MQPMO    PutMsgOpts;    -- Options that control the action of MQPUT1
  MQLONG   BufferLength;  -- Length of the message in Buffer
  MQBYTE   Buffer[n];     -- Message data
  MQLONG   CompCode;      -- Completion code
  MQLONG   Reason;        -- Reason code qualifying CompCode
*/
PHP_FUNCTION(mqseries_put1) {
  mqseries_descriptor *mqdesc;
  zval *z_mqdesc, *z_msg_desc, *z_put_msg_opts, *z_obj_desc, *z_comp_code, *z_reason;
  char  *msg;
#ifdef ZEND_ENGINE_3
  zend_long msg_len;
#else
  long msg_len;
#endif
  MQMD msg_desc = {MQMD_DEFAULT};   /* Message descriptor */
  MQOD obj_desc = {MQOD_DEFAULT};   /* Object descriptor */
  MQPMO put_msg_opts = {MQPMO_DEFAULT};   /* Options which control the MQPUT call */
  MQLONG comp_code;
  MQLONG reason;

#ifdef ZEND_ENGINE_3
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ra/a/a/sz/z/", &z_mqdesc, &z_obj_desc, &z_msg_desc, &z_put_msg_opts, &msg, &msg_len, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if ((mqdesc = (mqseries_descriptor *) zend_fetch_resource(Z_RES_P(z_mqdesc), PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn)) == NULL) {
    RETURN_FALSE;
  }
#else
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "raaaszz", &z_mqdesc, &z_obj_desc, &z_msg_desc, &z_put_msg_opts, &msg, &msg_len, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if (!_mqseries_is_compcode_reason_ref(z_comp_code, z_reason)) return;

  ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);
#endif

  _mqseries_set_mqod_from_array(z_obj_desc, &obj_desc TSRMLS_CC);
  _mqseries_set_mqmd_from_array(z_msg_desc, &msg_desc TSRMLS_CC);
  _mqseries_set_mqpmo_from_array(z_put_msg_opts, &put_msg_opts TSRMLS_CC);

  MQPUT1(mqdesc->conn, &obj_desc, &msg_desc, &put_msg_opts, (MQLONG) msg_len, msg, &comp_code, &reason);

  ZVAL_LONG(z_comp_code, (long) comp_code);
  ZVAL_LONG(z_reason, (long) reason);

#ifdef ZEND_ENGINE_3
  _mqseries_set_array_from_mqod(z_obj_desc, &obj_desc TSRMLS_CC);
  _mqseries_set_array_from_mqmd(z_msg_desc, &msg_desc TSRMLS_CC);
  _mqseries_set_array_from_mqpmo(z_put_msg_opts, &put_msg_opts);
#else
  if (PZVAL_IS_REF(z_obj_desc)) {
    _mqseries_set_array_from_mqod(z_obj_desc, &obj_desc TSRMLS_CC);
  }
  if (PZVAL_IS_REF(z_msg_desc)) {
    _mqseries_set_array_from_mqmd(z_msg_desc, &msg_desc TSRMLS_CC);
  }
  if (PZVAL_IS_REF(z_put_msg_opts)) {
    _mqseries_set_array_from_mqpmo(z_put_msg_opts, &put_msg_opts);
  }
#endif
}
/* }}} */

/* {{{ proto void mqseries_inq(resource hconn, resource hobj, int selectorCount, array selectors, int intAttrCount, array &initAttrs, int charAttrLength, string &charAttrs, int &compCode, int &reason)

The mqseries_inc call returns an array of integers and a set of character strings containing the attributes of an object.

PHP Sample:

  mqseries_inq($conn, $obj, 1, array(MQSERIES_MQCA_Q_MGR_NAME), 0, $int_attr, 48, $char_attr, $comp_code, $reason);

MQ call:

  MQINQ (Hconn, Hobj, SelectorCount, Selectors, IntAttrCount, IntAttrs, CharAttrLength, CharAttrs, &CompCode, &Reason);

  MQHCONN  Hconn;           -- Connection handle
  MQHOBJ   Hobj;            -- Object handle
  MQLONG   SelectorCount;   -- Count of selectors
  MQLONG   Selectors[n];    -- Array of attribute selectors
  MQLONG   IntAttrCount;    -- Count of integer attributes
  MQLONG   IntAttrs[n];     -- Array of integer attributes
  MQLONG   CharAttrLength;  -- Length of character attributes buffer
  MQCHAR   CharAttrs[n];    -- Character attributes
  MQLONG   CompCode;        -- Completion code
  MQLONG   Reason;          -- Reason code qualifying CompCode
*/
PHP_FUNCTION(mqseries_inq) {
  mqseries_descriptor *mqdesc;
  mqseries_obj *mqobj;
#ifdef ZEND_ENGINE_3
  zval *option_val;
#else
  zval **option_val;
#endif
  zval *z_mqdesc, *z_mqobj, *z_selectors, *z_intAttrs, *z_charAttrs, *z_comp_code, *z_reason;
  HashPosition pos;
  long current = 0;
#ifdef ZEND_ENGINE_3
  zend_long selectorCount, intAttrLength, i, charAttrLength;
#else
  long selectorCount, intAttrLength, i, charAttrLength;
#endif
  MQLONG *selectors;
  MQCHAR *charAttrs = NULL;
  MQLONG *intAttrs = NULL;
  MQLONG comp_code;
  MQLONG reason;

#ifdef ZEND_ENGINE_3
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rrlalz/lz/z/z/", &z_mqdesc, &z_mqobj, &selectorCount, &z_selectors, &intAttrLength, &z_intAttrs, &charAttrLength, &z_charAttrs, &z_comp_code, &z_reason)  == FAILURE) {
    return;
  }

  if ((mqdesc = (mqseries_descriptor *) zend_fetch_resource(Z_RES_P(z_mqdesc), PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn)) == NULL) {
    RETURN_FALSE;
  }
  if ((mqobj = (mqseries_obj *) zend_fetch_resource(Z_RES_P(z_mqobj), PHP_MQSERIES_OBJ_RES_NAME, le_mqseries_obj)) == NULL) {
    RETURN_FALSE;
  }
#else
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rrlalzlzzz", &z_mqdesc, &z_mqobj, &selectorCount, &z_selectors, &intAttrLength, &z_intAttrs, &charAttrLength, &z_charAttrs, &z_comp_code, &z_reason)  == FAILURE) {
    return;
  }

  if (!_mqseries_is_compcode_reason_ref(z_comp_code, z_reason)) return;
  if (!_mqseries_is_called_by_ref(z_intAttrs, "intAttrs")) return;
  if (!_mqseries_is_called_by_ref(z_charAttrs, "charAttrs")) return;

  ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);
  ZEND_FETCH_RESOURCE(mqobj,  mqseries_obj *, &z_mqobj, -1, PHP_MQSERIES_OBJ_RES_NAME, le_mqseries_obj);
#endif

  selectors = (MQLONG *) emalloc(selectorCount * sizeof(MQLONG));

#ifdef ZEND_ENGINE_3
  ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(z_selectors), option_val) {
    if (current < selectorCount) {
      selectors[current++] = Z_LVAL_P(option_val);
    }
  }
  ZEND_HASH_FOREACH_END();
#else
  zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(z_selectors), &pos);
  while (zend_hash_get_current_data_ex(Z_ARRVAL_P(z_selectors), (void **)&option_val, &pos) == SUCCESS) {
    if (current < selectorCount) {
      selectors[current++] = Z_LVAL_PP(option_val);
    }
    zend_hash_move_forward_ex(Z_ARRVAL_P(z_selectors), &pos);
  }
#endif

  if (charAttrLength > 0) { /* Are charAttr requested */
    charAttrs = (MQCHAR *) emalloc(charAttrLength + 1);
    memset(charAttrs, 0, charAttrLength + 1); // set to zero
  }
  if (intAttrLength > 0) { /*  Are intAttr requested */
    intAttrs = (MQLONG *) emalloc(intAttrLength * sizeof(MQLONG));
  }

  MQINQ(mqdesc->conn, mqobj->obj, (MQLONG) selectorCount, selectors, (MQLONG) intAttrLength, intAttrs, (MQLONG) charAttrLength, charAttrs, &comp_code, &reason);

  ZVAL_LONG(z_comp_code, (long) comp_code);
  ZVAL_LONG(z_reason, (long) reason);

  if (comp_code == MQCC_OK) {
    if (charAttrLength > 0) { /* set only when charAttrs where requested */
#ifdef ZEND_ENGINE_3
      ZVAL_STRING(z_charAttrs, charAttrs);
#else
      ZVAL_STRING(z_charAttrs, charAttrs, 1);
#endif
    }
    if (intAttrLength > 0) { /*  set only when intAttrs where requested */
      /* create an indexed array of long values */
      zval_dtor(z_intAttrs);
      array_init(z_intAttrs);

      for (i = 0; i < intAttrLength; i++) {
        add_index_long(z_intAttrs, i, (long) intAttrs[i]);
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

/* {{{ proto void mqseries_set(resource hconn, resource hobj, int selectorCount, array selectors, int intAttrCount, array intAttrs, int charAttrLength, array &charAttrs, int &compCode, int &reason)

Use the mqseries_set call to change the attributes of an object represented by a handle. The object must be a queue.

PHP sample:

MQ call:

  MQSET (Hconn, Hobj, SelectorCount, Selectors, IntAttrCount, IntAttrs, CharAttrLength, CharAttrs, &CompCode, &Reason);

  MQHCONN  Hconn;           -- Connection handle
  MQHOBJ   Hobj;            -- Object handle
  MQLONG   SelectorCount;   -- Count of selectors
  MQLONG   Selectors[n];    -- Array of attribute selectors
  MQLONG   IntAttrCount;    -- Count of integer attributes
  MQLONG   IntAttrs[n];     -- Array of integer attributes
  MQLONG   CharAttrLength;  -- Length of character attributes buffer
  MQCHAR   CharAttrs[n];    -- Character attributes
  MQLONG   CompCode;        -- Completion code
  MQLONG   Reason;          -- Reason code qualifying CompCode
*/
PHP_FUNCTION(mqseries_set) {
  mqseries_descriptor *mqdesc;
  mqseries_obj *mqobj;
#ifdef ZEND_ENGINE_3
  zval *option_val;
#else
  zval **option_val;
#endif
  zval *z_mqdesc, *z_mqobj, *z_selectors, *z_intAttrs, *z_charAttrs, *z_comp_code, *z_reason;
  HashPosition pos;
#ifdef ZEND_ENGINE_3
  zend_long selectorCount, intAttrLength, charAttrLength;
#else
  long selectorCount, intAttrLength, charAttrLength;
#endif
  MQLONG current = 0, *selectors;
  MQCHAR *charAttrs = NULL;
  MQLONG *intAttrs = NULL;
  MQLONG comp_code;
  MQLONG reason;

#ifdef ZEND_ENGINE_3
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rrlalalaz/z/", &z_mqdesc, &z_mqobj, &selectorCount, &z_selectors, &intAttrLength, &z_intAttrs, &charAttrLength, &z_charAttrs, &z_comp_code, &z_reason)  == FAILURE) {
    return;
  }

  if ((mqdesc = (mqseries_descriptor *) zend_fetch_resource(Z_RES_P(z_mqdesc), PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn)) == NULL) {
    RETURN_FALSE;
  }
  if ((mqobj = (mqseries_obj *) zend_fetch_resource(Z_RES_P(z_mqobj), PHP_MQSERIES_OBJ_RES_NAME, le_mqseries_obj)) == NULL) {
    RETURN_FALSE;
  }
#else
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rrlalalazz", &z_mqdesc, &z_mqobj, &selectorCount, &z_selectors, &intAttrLength, &z_intAttrs, &charAttrLength, &z_charAttrs, &z_comp_code, &z_reason)  == FAILURE) {
    return;
  }

  if (!_mqseries_is_compcode_reason_ref(z_comp_code, z_reason)) return;

  ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);
  ZEND_FETCH_RESOURCE(mqobj,  mqseries_obj *, &z_mqobj, -1, PHP_MQSERIES_OBJ_RES_NAME, le_mqseries_obj);
#endif

  selectors = (MQLONG *) emalloc(selectorCount * sizeof(MQLONG));

  current = 0;

#ifdef ZEND_ENGINE_3
  ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(z_selectors), option_val) {
    if (current < selectorCount) {
      selectors[current++] = Z_LVAL_P(option_val);
    }
  }
  ZEND_HASH_FOREACH_END();
#else
  zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(z_selectors), &pos);
  while (zend_hash_get_current_data_ex(Z_ARRVAL_P(z_selectors), (void **)&option_val, &pos) == SUCCESS) {
    if (current < selectorCount) {
      selectors[current++] = Z_LVAL_PP(option_val);
    }
    zend_hash_move_forward_ex(Z_ARRVAL_P(z_selectors), &pos);
  }
#endif

  if (intAttrLength > 0) { /*  Are intAttr requested */
    intAttrs = (MQLONG *) emalloc(intAttrLength * sizeof(MQLONG));
    current = 0;

#ifdef ZEND_ENGINE_3
    ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(z_intAttrs), option_val) {
      if (current < intAttrLength) {
        intAttrs[current++] = (MQLONG) Z_LVAL_P(option_val);
      }
    }
    ZEND_HASH_FOREACH_END();
#else
    zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(z_intAttrs), &pos);
    while (zend_hash_get_current_data_ex(Z_ARRVAL_P(z_intAttrs), (void **)&option_val, &pos) == SUCCESS) {
      if (current < intAttrLength) {
        intAttrs[current++] = (MQLONG) Z_LVAL_PP(option_val);
      }
      zend_hash_move_forward_ex(Z_ARRVAL_P(z_intAttrs), &pos);
    }
#endif

  }

  if (charAttrLength > 0) { /* Are charAttr requested */
    charAttrs = (MQCHAR *) emalloc(charAttrLength + 1);
    current = 0;

#ifdef ZEND_ENGINE_3
    ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(z_charAttrs), option_val) {
      if (current < charAttrLength) {
        charAttrs[current++] = Z_LVAL_P(option_val); /* hoe helen we char uit een array? */
      }
    }
    ZEND_HASH_FOREACH_END();
#else
    zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(z_charAttrs), &pos);
    while (zend_hash_get_current_data_ex(Z_ARRVAL_P(z_charAttrs), (void **)&option_val, &pos) == SUCCESS) {
      if (current < charAttrLength) {
        charAttrs[current++] = Z_LVAL_PP(option_val); /* hoe helen we char uit een array? */
      }
      zend_hash_move_forward_ex(Z_ARRVAL_P(z_charAttrs), &pos);
    }
#endif
  }

  MQSET(mqdesc->conn, mqobj->obj, (MQLONG) selectorCount, selectors, (MQLONG) intAttrLength, intAttrs, (MQLONG) charAttrLength, charAttrs, &comp_code, &reason);

  ZVAL_LONG(z_comp_code, (long) comp_code);
  ZVAL_LONG(z_reason, (long) reason);

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

Returns the string of bytes contained in the mqseries bytes resource

PHP sample:

  mqseries_bytes_val($res);

*/
PHP_FUNCTION(mqseries_bytes_val) {
  zval *z_bytes;
  mqseries_bytes *bytes;

  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r", &z_bytes) == FAILURE) {
    return;
  }

#ifdef ZEND_ENGINE_3
  if ((bytes = (mqseries_bytes *) zend_fetch_resource(Z_RES_P(z_bytes), PHP_MQSERIES_BYTES_RES_NAME, le_mqseries_bytes)) == NULL) {
    RETURN_FALSE;
  }
#else
  ZEND_FETCH_RESOURCE(bytes, mqseries_bytes *, &z_bytes, -1, PHP_MQSERIES_BYTES_RES_NAME, le_mqseries_bytes);
#endif

  if (bytes && bytes->bytes) {
#ifdef ZEND_ENGINE_3
    if (bytes->size > 0) {

      RETVAL_STRINGL((char *)bytes->bytes, bytes->size);
    }
    else {
      RETVAL_STRING((char *)bytes->bytes);
    }
#else
    RETVAL_STRING((char *) bytes->bytes, 1);
#endif
  }
  else {
    RETVAL_NULL();
  }
}
/* }}} */

#ifdef HAVE_MQSERIESLIB_V7

/* {{{ proto void mqseries_sub(resource hconn, array &subDesc, resource &hobj, resource &hsub, int &compCode, int &reason)

The mqseries_sub call registers the applications subscription to a particular topic.

PHP sample:

  mqseries_sub($connection, $subDesc, $queue, $sub, $compCode, $reason);
  if ($compCode !== MQSERIES_MQCC_OK) {
    printf("CompCode:%d Reason:%d Text:%s\n", $compCode, $reason, mqseries_strerror($reason));
  }

MQ call:

  MQSUB (Hconn, &SubDesc, &Hobj, &Hsub, &CompCode, &Reason);

  MQHCONN Hconn;    -- Connection handle
  MQSD    SubDesc;  -- Subscription descriptor
  MQHOBJ  Hobj;     -- Object handle
  MQHOBJ  Hsub;     -- Subscription handle
  MQLONG  CompCode; -- Completion code
  MQLONG  Reason;   -- Reason code qualifying CompCode
*/
PHP_FUNCTION(mqseries_sub) {
  mqseries_descriptor *mqdesc;
  mqseries_obj *mqobj = NULL, *mqsub;
  zval *z_mqdesc,
       *z_sub_desc,
       *z_obj,
       *z_sub,
       *z_comp_code,
       *z_reason;

  MQSD sub_desc = {MQSD_DEFAULT};
  MQLONG comp_code;  /* Completion code */
  MQLONG reason;     /* Qualifying reason */

#ifdef ZEND_ENGINE_3
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ra/z/zz/z/", &z_mqdesc, &z_sub_desc, &z_obj, &z_sub, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }
#else
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "razzzz", &z_mqdesc, &z_sub_desc, &z_obj, &z_sub, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }
#endif

  if (Z_TYPE_P(z_obj) == IS_RESOURCE) {
#ifdef ZEND_ENGINE_3
    if ((mqobj = (mqseries_obj *) zend_fetch_resource(Z_RES_P(z_obj), PHP_MQSERIES_OBJ_RES_NAME, le_mqseries_obj)) == NULL) {
      RETURN_FALSE;
    }
#else
    ZEND_FETCH_RESOURCE(mqobj, mqseries_obj *, &z_obj, -1, PHP_MQSERIES_OBJ_RES_NAME, le_mqseries_obj);
  }
  else if (!_mqseries_is_called_by_ref(z_obj, "hobj")) {
    return;
#endif
  }
  else {
    mqobj = (mqseries_obj *) emalloc(sizeof(mqseries_obj));
  }

#ifdef ZEND_ENGINE_3
  if ((mqdesc = (mqseries_descriptor *) zend_fetch_resource(Z_RES_P(z_mqdesc), PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn)) == NULL) {
    RETURN_FALSE;
  }
#else
  if (!_mqseries_is_called_by_ref(z_obj, "hsub") || !_mqseries_is_compcode_reason_ref(z_comp_code, z_reason)) return;

  ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);
#endif

  _mqseries_set_mqsd_from_array(z_sub_desc, &sub_desc TSRMLS_CC);

  mqsub = (mqseries_obj *) emalloc(sizeof(mqseries_obj));

  MQSUB(mqdesc->conn, &sub_desc, &mqobj->obj, &mqsub->obj, &comp_code, &reason);

  ZVAL_LONG(z_comp_code, (long) comp_code);
  ZVAL_LONG(z_reason, (long) reason);

#ifdef ZEND_ENGINE_3
  _mqseries_set_array_from_mqsd(z_sub_desc, &sub_desc TSRMLS_CC);
#else
  if (PZVAL_IS_REF(z_sub_desc)) {
    _mqseries_set_array_from_mqsd(z_sub_desc, &sub_desc TSRMLS_CC);
  }
#endif
  if (comp_code == MQCC_OK) {
    if (Z_TYPE_P(z_obj) != IS_RESOURCE) {
      zval_dtor(z_obj);
      mqobj->conn = &mqdesc->conn;
#ifdef ZEND_ENGINE_3
      ZVAL_RES(z_obj, zend_register_resource(mqobj, le_mqseries_obj));
      mqobj->id = Z_RES_P(z_obj)->handle;
#else
      ZEND_REGISTER_RESOURCE(z_obj, mqobj, le_mqseries_obj);
      mqobj->id = Z_RESVAL_P(z_obj);
#endif
    }

    zval_dtor(z_sub);
    mqsub->conn = &mqdesc->conn;
#ifdef ZEND_ENGINE_3
    ZVAL_RES(z_sub, zend_register_resource(mqsub, le_mqseries_obj));
    mqsub->id = Z_RES_P(z_sub)->handle;
#else
    ZEND_REGISTER_RESOURCE(z_sub, mqsub, le_mqseries_obj);
    mqsub->id = Z_RESVAL_P(z_sub);
#endif
  }
  else {
    /* So we don't register the ref. But we already allocated some memory lets free that */
    if (Z_TYPE_P(z_obj) != IS_RESOURCE) {
      efree(mqobj);
    }
    efree(mqsub);
  }
}
/* }}} */

/* {{{ proto void mqseries_stat(resource hconn, int type, array &status, int &compCode, int &reason)

Use the mqseries_stat call to retrieve status information. The type of status information returned is determined by the Type value specified on the call.

PHP sample:

  $status = array();
  mqseries_stat($conn, MQSERIES_MQSTAT_TYPE_RECONNECTION, $status, $compCode, $reason);
  if ($compCode !== MQSERIES_MQCC_OK) {
    printf("CompCode:%d Reason:%d Text:%s\n", $compCode, $reason, mqseries_strerror($reason));
  }

MQ call:

  MQSTAT (Hconn, StatType, &Stat, &CompCode, &Reason);

  MQHCONN Hconn;    -- Connection Handle
  MQLONG StatType;  -- Status type
  MQSTS Stat;       -- Status information structure
  MQLONG CompCode;  -- Completion code
  MQLONG Reason;    -- Reason code qualifying CompCode
*/
PHP_FUNCTION(mqseries_stat) {
  mqseries_descriptor *mqdesc;
#ifdef ZEND_ENGINE_3
  zend_long type;
#else
  long type;
#endif
  MQLONG comp_code, reason;
  zval *z_mqdesc,
       *z_status,
       *z_comp_code,
       *z_reason;

  MQSTS status = {MQSTS_DEFAULT};

#ifdef ZEND_ENGINE_3
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rlaz/z/", &z_mqdesc, &type, &z_status, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if ((mqdesc = (mqseries_descriptor *) zend_fetch_resource(Z_RES_P(z_mqdesc), PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn)) == NULL) {
    RETURN_FALSE;
  }
#else
  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rlazz", &z_mqdesc, &type, &z_status, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if (!_mqseries_is_called_by_ref(z_status, "status") || !_mqseries_is_compcode_reason_ref(z_comp_code, z_reason)) return;

  ZEND_FETCH_RESOURCE(mqdesc, mqseries_descriptor *, &z_mqdesc, -1, PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn);
#endif

  _mqseries_set_mqsts_from_array(z_status, &status);

  MQSTAT(mqdesc->conn, (MQLONG) type, &status, &comp_code, &reason);

  ZVAL_LONG(z_comp_code, (long) comp_code);
  ZVAL_LONG(z_reason, (long) reason);

  _mqseries_set_array_from_mqsts(z_status, &status);
}

/* 21.07.2017 */
/*
 MQ call:

 MQBUFMH (Hconn, Hmsg, &BufMsgHOpts, &MsgDesc, BufferLength, Buffer, &DataLength, &CompCode, &Reason);

    MQHCONN Hconn;       -- Connection handle
    MQHMSG  Hmsg;         -- Message handle
    MQBMHO  BufMsgHOpts;  -- Options that control the action of MQBUFMH
    MQMD    MsgDesc;      -- Message descriptor
    MQLONG  BufferLength; -- Length in bytes of the Buffer area
    MQBYTE  Buffer[n];    -- Area to contain the message buffer
    MQLONG  DataLength;   -- Length of the output buffer
    MQLONG  CompCode;     -- Completion code
    MQLONG  Reason;       -- Reason code qualifying CompCode
*/


PHP_FUNCTION(mqseries_bufmh) {




  mqseries_descriptor *mqdesc;
  mqseries_message *mqhandle;
  MQCHARV  prop_name = { MQCHARV_DEFAULT };
  zend_long type;
  MQLONG comp_code = 0, reason = 0;
  zval *z_mqdesc,
       *z_hmsg,
       *z_msg_desc,
       *z_buf_msg_hopts,
       *z_buffer,
       *z_data_length,
       *z_comp_code,
       *z_reason;

  MQLONG data_length = 0, buffer_size = 0;
  MQBYTE *data;

  zend_long buf_len = 0L;
  MQBYTE *buf;


  MQBMHO  buf_msg_hopts = { MQBMHO_DEFAULT };
  MQMD msg_desc = { MQMD_DEFAULT };



  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rraaslz/z/", &z_mqdesc, &z_hmsg, &z_buf_msg_hopts, &z_msg_desc,  &data, &data_length, &buf_len, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if ((mqdesc = (mqseries_descriptor *)zend_fetch_resource(Z_RES_P(z_mqdesc), PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn)) == NULL) {
    RETURN_FALSE;
  }
  if ((mqhandle = (mqseries_message *)zend_fetch_resource(Z_RES_P(z_hmsg), PHP_MQSERIES_MESSAGE_RES_NAME, le_mqseries_message)) == NULL) {
    RETURN_FALSE;
  }

  _mqseries_set_mqmd_from_array(z_msg_desc, &msg_desc TSRMLS_CC);
  _mqseries_set_mqbmho_from_array(z_buf_msg_hopts, &buf_msg_hopts TSRMLS_CC);

  //data = buf = (MQBYTE *)emalloc(sizeof(MQBYTE) * buf_len);
  MQBUFMH(mqdesc->conn, mqhandle->handle, &buf_msg_hopts, &msg_desc, (MQLONG)buf_len, data, &data_length, &comp_code, &reason);
//TODO обратную функцию по занесению свойств в стуктуру
  ZVAL_LONG(z_comp_code, (long)comp_code);
  ZVAL_LONG(z_reason, (long)reason);
  _mqseries_set_array_from_mqmd(z_msg_desc, &msg_desc TSRMLS_CC);
}


/*
MQ call:

MQMHBUF (Hconn, Hmsg, &MsgHBufOpts, &Name, &MsgDesc, BufferLength, Buffer, &DataLength, &CompCode, &Reason);

MQHCONN Hconn;        -- Connection handle
MQHMSG  Hmsg;         -- Message handle
MQMHBO  MsgHBufOpts;  -- Options that control the action of MQMHBUF
MQCHARV Name;         -- Property name
MQMD    MsgDesc;      -- Message descriptor
MQLONG  BufferLength; -- Length in bytes of the Buffer area
MQBYTE  Buffer[n];    -- Area to contain the properties
MQLONG  DataLength;   -- Length of the properties
MQLONG  CompCode;     -- Completion code
MQLONG  Reason;       -- Reason code qualifying CompCode
*/


PHP_FUNCTION(mqseries_mhbuf) {
  mqseries_descriptor *mqdesc;
  mqseries_message *mqhandle;
  MQLONG comp_code, reason;
  MQCHARV  prop_name = { MQCHARV_DEFAULT };
  zval *z_mqdesc,
       *z_hmsg,
       *z_msg_desc,
       *z_buffer,
       *z_data_length,
       *z_buf_msg_hopts,
       *z_comp_code,
       *z_reason;



  char *name = NULL;
  size_t name_len = 0;
  zend_long buf_len = 0L;
  MQLONG data_length = 0L;
  MQBYTE *buf, *data;
  MQMHBO buf_msg_hopts = { MQMHBO_DEFAULT };
  MQMD  msg_desc = { MQMD_DEFAULT };

  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rra/s/al/z/z/z/z/", &z_mqdesc, &z_hmsg, &z_buf_msg_hopts, &name,  &name_len, &z_msg_desc, &buf_len, &z_buffer, &z_data_length, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if ((mqdesc = (mqseries_descriptor *)zend_fetch_resource(Z_RES_P(z_mqdesc), PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn)) == NULL) {
    RETURN_FALSE;
  }
  if ((mqhandle = (mqseries_message *)zend_fetch_resource(Z_RES_P(z_hmsg), PHP_MQSERIES_MESSAGE_RES_NAME, le_mqseries_message)) == NULL) {
    RETURN_FALSE;
  }

  _mqseries_set_mqmhbo_from_array(z_buf_msg_hopts, &buf_msg_hopts);
  _mqseries_set_mqmd_from_array(z_msg_desc, &msg_desc);

  data = buf = (MQBYTE *)emalloc(sizeof(MQBYTE) * buf_len);
  prop_name.VSPtr = name;
  prop_name.VSLength = name_len;
  MQMHBUF(mqdesc->conn, mqhandle->handle, &buf_msg_hopts, &prop_name, &msg_desc, (MQLONG)buf_len, buf, &data_length, &comp_code, &reason);
  //TODO обратную функцию по занесению свойств в стуктуру
  if (comp_code == MQCC_OK) {
    ZVAL_LONG(z_data_length, (long)data_length);
    zval_dtor(z_buffer);
    ZVAL_STRINGL(z_buffer, (char *)data, (buf_len > 0) ? (buf_len < (long)data_length ? buf_len : (long)data_length) : 0);
  }
  _mqseries_set_array_from_mqmd(z_msg_desc, &msg_desc TSRMLS_CC);
  ZVAL_LONG(z_comp_code, (long)comp_code);
  ZVAL_LONG(z_reason, (long)reason);
  efree(buf);

}

/*
MQ call:

MQCRTMH (Hconn, &CrtMsgHOpts, &Hmsg, &CompCode, &Reason);

MQHCONN  Hconn;       -- Connection handle
MQCMHO   CrtMsgHOpts; -- Options that control the action of MQCRTMH
MQHMSG   Hmsg;        -- Message handle
MQLONG   CompCode;    -- Completion code
MQLONG   Reason;      -- Reason code qualifying CompCode
*/

PHP_FUNCTION(mqseries_crtmh) {
  mqseries_descriptor *mqdesc;
  mqseries_message *mqmsg;
  MQLONG comp_code, reason;
  zval *z_mqdesc,
       *z_mhandle,
       *z_crt_msg_opts,
       *z_comp_code,
       *z_reason;

  MQCMHO   crt_msg_opts = { MQCMHO_DEFAULT };

  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z/a/z/z/z/", &z_mqdesc, &z_crt_msg_opts, &z_mhandle, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }
  if ((mqdesc = (mqseries_descriptor *)zend_fetch_resource(Z_RES_P(z_mqdesc), PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn)) == NULL) {
    RETURN_FALSE;
  }
  _mqseries_set_mqcmho_from_array(z_crt_msg_opts, &crt_msg_opts);

  mqmsg = (mqseries_message *)emalloc(sizeof(mqseries_message));
  MQCRTMH(mqdesc->conn, &crt_msg_opts, &mqmsg->handle, &comp_code, &reason);
  ZVAL_LONG(z_comp_code, (long)comp_code);
  ZVAL_LONG(z_reason, (long)reason);
  if (comp_code == MQCC_OK) {
    zval_dtor(z_mhandle);
    ZVAL_RES(z_mhandle, zend_register_resource(mqmsg, le_mqseries_message));
    mqmsg->id = Z_RES_P(z_mhandle)->handle;
  }
  else {
    efree(mqmsg);
  }
}

/*
MQ call:

MQDLTMH (Hconn, &Hmsg, &DltMsgHOpts, &CompCode, &Reason);

MQHCONN  Hconn;       -- Connection handle
MQHMSG   Hmsg;        -- Message handle
MQDMHO   DltMsgHOpts; -- Options that control the action of MQDLTMH
MQLONG   CompCode;    -- Completion code
MQLONG   Reason;      -- Reason code qualifying CompCode
*/

PHP_FUNCTION(mqseries_dltmh) {
  mqseries_descriptor *mqdesc;
  mqseries_message *mqhandle;
  MQLONG comp_code, reason;
  zval *z_mqdesc,
       *z_hmsg,
       *z_dlt_msg_hopts,
       *z_comp_code,
       *z_reason;

  MQDMHO dmho = { MQDMHO_DEFAULT };


  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rra/z/z/", &z_mqdesc, &z_hmsg, &z_dlt_msg_hopts, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }

  if ((mqdesc = (mqseries_descriptor *)zend_fetch_resource(Z_RES_P(z_mqdesc), PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn)) == NULL) {
    RETURN_FALSE;
  }
  if ((mqhandle = (mqseries_message *)zend_fetch_resource(Z_RES_P(z_hmsg), PHP_MQSERIES_MESSAGE_RES_NAME, le_mqseries_message)) == NULL) {
    RETURN_FALSE;
  }

  _mqseries_set_mqdmho_from_array(z_dlt_msg_hopts, &dmho);

  MQDLTMH(mqdesc->conn, &mqhandle->handle, &dmho, &comp_code, &reason);

  ZVAL_LONG(z_comp_code, (long)comp_code);
  ZVAL_LONG(z_reason, (long)reason);
  if (comp_code == MQCC_OK) {
    zend_list_close(Z_RES_P(z_hmsg));
  }
}

/*
MQ call:

MQDLTMP (Hconn, Hmsg, &DltPropOpts, &Name, &CompCode, &Reason)

MQHCONN Hconn;       -- Connection handle
MQHMSG  Hmsg;        -- Message handle
MQDMPO  DltPropOpts; -- Options that control the action of MQDLTMP
MQCHARV Name;        -- Property name
MQLONG  CompCode;    -- Completion code
MQLONG  Reason;      -- Reason code qualifying CompCode
*/

PHP_FUNCTION(mqseries_dltmp) {
  mqseries_descriptor *mqdesc;
  mqseries_message *mqhandle;
  char *name = NULL;
  size_t name_len = 0;
  MQCHARV  prop_name = { MQCHARV_DEFAULT };
  MQLONG comp_code, reason;
  zval *z_mqdesc,
       *z_hmsg,
       *z_dlt_prop_opts,
       *z_comp_code,
       *z_reason;



  MQDMPO dlt_prop_opts = { MQDMPO_DEFAULT};


  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rra/s/z/z/", &z_mqdesc, &z_hmsg, &z_dlt_prop_opts, &name, &name_len, &z_comp_code, &z_reason) == FAILURE) {
    return;
  }
  if ((mqdesc = (mqseries_descriptor *)zend_fetch_resource(Z_RES_P(z_mqdesc), PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn)) == NULL) {
    RETURN_FALSE;
  }
  if ((mqhandle = (mqseries_message *)zend_fetch_resource(Z_RES_P(z_hmsg), PHP_MQSERIES_MESSAGE_RES_NAME, le_mqseries_message)) == NULL) {
    RETURN_FALSE;
  }
  _mqseries_set_mqdmpo_from_array(z_dlt_prop_opts, &dlt_prop_opts);

  prop_name.VSPtr = name;
  prop_name.VSLength = name_len;


  MQDLTMP(mqdesc->conn, mqhandle->handle, &dlt_prop_opts, &prop_name, &comp_code, &reason);

  ZVAL_LONG(z_comp_code, (long)comp_code);
  ZVAL_LONG(z_reason, (long)reason);
}

/*
MQ call:

MQINQMP (Hconn, Hmsg, &InqPropOpts, &Name, &PropDesc, &Type, ValueLength, Value, &DataLength, &CompCode, &Reason);

MQHCONN Hconn;       -- Connection handle
MQHMSG  Hmsg;        -- Message handle
MQIMPO InqPropOpts;  -- Options that control the action of MQINQMP
MQCHARV Name;        -- Property name
MQPD    PropDesc;    -- Property descriptor
MQLONG  Type;        -- Property data type
MQLONG  ValueLength; -- Length in bytes of the Value area
MQBYTE  Value[n];    -- Area to contain the property value
MQLONG  DataLength;  -- Length of the property value
MQLONG  CompCode;    -- Completion code
MQLONG  Reason;      -- Reason code qualifying CompCode
*/

PHP_FUNCTION(mqseries_inqmp) {
  mqseries_descriptor *mqdesc;
  mqseries_message *mqhandle;
  MQLONG type = 0;
  MQLONG comp_code, reason;
  zval *z_mqdesc,
       *z_hmsg,
       *z_inq_prop_opts,
       *z_proc_desc,
       *z_comp_code,
       *z_reason,
       *z_data_length,
       *z_value,
       *z_type,
       *z_name;
  MQPD pd = { MQPD_DEFAULT };
  MQCHARV  prop_name = { MQPROP_INQUIRE_ALL };
  MQLONG data_length = 0, buffer_size = 0;
  MQBYTE *data;
  //char *name = NULL;
  //size_t name_len = 0;

  MQIMPO inq_prop_opts = { MQIMPO_DEFAULT};

  MQCHARV tmp_name_property = { MQPROP_INQUIRE_ALL };


  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rraz/a/z/lz/z/z/z/",
                            &z_mqdesc,
                            &z_hmsg,
                            &z_inq_prop_opts,
                            &z_name,
                            //&name_len,
                            &z_proc_desc,
                            &z_type,
                            &buffer_size,
                            &z_value,
                            &z_data_length,
                            &z_comp_code,
                            &z_reason) == FAILURE) {
    return;
  }

  if ((mqdesc = (mqseries_descriptor *)zend_fetch_resource(Z_RES_P(z_mqdesc), PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn)) == NULL) {
    RETURN_FALSE;
  }
  if ((mqhandle = (mqseries_message *)zend_fetch_resource(Z_RES_P(z_hmsg), PHP_MQSERIES_MESSAGE_RES_NAME, le_mqseries_message)) == NULL) {
    RETURN_FALSE;
  }
// TODO проверку на не 0 буфер

  _mqseries_set_mqpd_from_array(z_proc_desc, &pd);
  _mqseries_set_mqimpo_from_array(z_inq_prop_opts, &inq_prop_opts);

  //if (memcmp(name, "-3", name_len) != 0) {
  //  prop_name.VSPtr = name;
  //  prop_name.VSLength = MQVS_NULL_TERMINATED;
  //}
  //MQPROP_INQUIRE_ALL
  if (Z_TYPE_P(z_name) != IS_NULL) {
    prop_name.VSPtr = Z_STRVAL_P(z_name);
    prop_name.VSLength = Z_STRLEN_P(z_name); //MQVS_NULL_TERMINATED;
  }
  data = (MQBYTE *)emalloc(sizeof(MQBYTE) * buffer_size);
  MQBYTE *tmp_buffer = (MQBYTE *)emalloc(sizeof(MQBYTE) * buffer_size);
  memset(tmp_buffer, 0, (sizeof(MQBYTE) * buffer_size));
  //type = z_type->value.lval;

  tmp_name_property.VSPtr = (MQBYTE *)emalloc(sizeof(MQBYTE) * MQ_MAX_PROPERTY_NAME_LENGTH);
  tmp_name_property.VSBufSize = MQ_MAX_PROPERTY_NAME_LENGTH;
  inq_prop_opts.ReturnedName = tmp_name_property;

  MQINQMP(mqdesc->conn, mqhandle->handle, &inq_prop_opts, &prop_name, &pd, &type, (MQLONG)buffer_size, data, &data_length, &comp_code, &reason);
  if (comp_code == MQCC_OK) {
    zval_dtor(z_name);
    ZVAL_STRINGL(z_name, (char *)inq_prop_opts.ReturnedName.VSPtr, inq_prop_opts.ReturnedName.VSLength);
    zval_dtor(z_value);
    // Конвертируем в строку
    MQINT8     value_int8;
    MQINT16    value_int16;
    MQINT32    value_int32;
    MQINT64    value_int64;
    // TODO написать проверку строки на число для числовых типов
    switch (type) {
      case MQTYPE_BOOLEAN: /* 4 bytes */
        memcpy(&value_int32, data, data_length);
        sprintf(tmp_buffer, "%d", value_int32);
        ZVAL_BOOL(z_value, value_int32);
        break;
      case MQTYPE_BYTE_STRING: /* zero size allowed */
      case MQTYPE_STRING: /* zero size allowed */
        if (buffer_size > 0) {
          memcpy(tmp_buffer, data, MIN(data_length, buffer_size));
          data_length = MIN(data_length, buffer_size);
        }
        ZVAL_STRINGL(z_value, (char *)tmp_buffer, (buffer_size > 0) ? (buffer_size < (long)data_length ? buffer_size : (long)data_length) : 0);
        break;
      case MQTYPE_INT8:
        if (buffer_size > 0) {
          memcpy(&value_int8, data, data_length);
          //sprintf(tmp_buffer, "%d", value_int8);
          ZVAL_LONG(z_value, value_int8);
        }
        break;
      case MQTYPE_INT16:
        if (buffer_size > 0) {
          memcpy(&value_int16, data, data_length);
          //sprintf(tmp_buffer, "%d", value_int16);
          ZVAL_LONG(z_value, value_int16);
        }
        break;
      case MQTYPE_INT32:
        if (buffer_size > 0) {
          memcpy(&value_int32, data, data_length);
          //sprintf(tmp_buffer, "%d", value_int32);
          ZVAL_LONG(z_value, value_int32);
        }
        break;
      case MQTYPE_INT64:
        if (buffer_size > 0) {
          memcpy(&value_int64, data, data_length);
          //sprintf(tmp_buffer, "%ld", value_int64);
          ZVAL_LONG(z_value, value_int64);
        }
        break;
      case MQTYPE_FLOAT32: {
        MQFLOAT32  value_float32;
        if (buffer_size > 0) {
          memcpy(&value_float32, data, data_length);
          sprintf(tmp_buffer, "%g", value_float32);
          ZVAL_DOUBLE(z_value, atof(tmp_buffer));
        }
        break;
      }
      case MQTYPE_FLOAT64: {
        MQFLOAT64  value_float64;
        if (buffer_size > 0) {
          memcpy(&value_float64, data, data_length);
          sprintf(tmp_buffer, "%g", value_float64);
          ZVAL_DOUBLE(z_value, atof(tmp_buffer));
        }
        break;
      }
      case MQTYPE_NULL: /* Must be zero bytes */
        data_length = 0;
        break;
      default:
        break;
    }

    //

    ZVAL_LONG(z_data_length, (long)data_length);
    ZVAL_LONG(z_type, (long)type);
    _mqseries_set_array_from_mqpd(z_proc_desc, &pd);
  }
  efree(tmp_name_property.VSPtr);
  efree(data);
  efree(tmp_buffer);
  ZVAL_LONG(z_comp_code, (long)comp_code);
  ZVAL_LONG(z_reason, (long)reason);
}

/*
MQ call:

MQSETMP (Hconn, Hmsg, &SetPropOpts, &Name, &PropDesc, Type, ValueLength, &Value, &CompCode, &Reason);

MQHCONN  Hconn;       -- Connection handle
MQHMSG   Hmsg;        -- Message handle
MQSMPO   SetPropOpts; -- Options that control the action of MQSETMP
MQCHARV  Name;        -- Property name
MQPD     PropDesc;    -- Property descriptor
MQLONG   Type;        -- Property data type
MQLONG   ValueLength; -- Length of property value in Value
MQBYTE   Value[n];    -- Property value
MQLONG   CompCode;    -- Completion code
MQLONG   Reason;      -- Reason code qualifying CompCode
*/

PHP_FUNCTION(mqseries_setmp) {
  mqseries_descriptor *mqdesc;
  mqseries_message *mqhandle;
  zend_long type = 0;
  char *name = NULL;
  size_t name_len = 0;
  char  *value;
  zend_long value_len;

  MQLONG comp_code, reason;
  zval *z_mqdesc,
       *z_hmsg,
       *z_set_prop_opts,
       *z_proc_desc,
       *z_comp_code,
       *z_reason;

  MQSMPO msg_po = { MQSMPO_DEFAULT };
  MQSTS status = { MQSTS_DEFAULT };
  MQPD pd = { MQPD_DEFAULT};
  MQCHARV  prop_name = { MQCHARV_DEFAULT };

  if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rra/s/a/ls/z/z/",
                            &z_mqdesc,
                            &z_hmsg,
                            &z_set_prop_opts,
                            &name,
                            &name_len,
                            &z_proc_desc,
                            &type,
                            &value,
                            &value_len,
                            &z_comp_code,
                            &z_reason) == FAILURE) {
    return;
  }

  if ((mqdesc = (mqseries_descriptor *)zend_fetch_resource(Z_RES_P(z_mqdesc), PHP_MQSERIES_DESCRIPTOR_RES_NAME, le_mqseries_conn)) == NULL) {
    RETURN_FALSE;
  }

  if ((mqhandle = (mqseries_message *)zend_fetch_resource(Z_RES_P(z_hmsg), PHP_MQSERIES_MESSAGE_RES_NAME, le_mqseries_message)) == NULL) {
    RETURN_FALSE;
  }

  void      *value_ptr = NULL;
  MQINT8     value_int8;
  MQINT16    value_int16;
  MQINT32    value_int32;
  MQINT64    value_int64;
  MQFLOAT32  value_float32;
  MQFLOAT64  value_float64;

// TODO написать проверку строки на число для числовых типов
  /* Convert value, based on declared type*/

  switch (type) {
    case MQTYPE_BOOLEAN: /* 4 bytes */
      if (value[0] == '1') {
        value_int32 = 1;
      }
      else {
        value_int32 = 0;
      }
      value_ptr = &value_int32;
      value_len = sizeof(MQINT32);
      break;
    case MQTYPE_BYTE_STRING: /* zero size allowed */
    case MQTYPE_STRING: /* zero size allowed */
      if (value_len) {
        value_ptr = value;
      }
      else {
        value_ptr = NULL;
        value_len = 0;
      }
      break;
    case MQTYPE_INT8:
      if (!sscanf(value, "%d", &value_int8)) {
        RETURN_FALSE;
      }
      value_ptr = &value_int8;
      value_len = sizeof(MQTYPE_INT8);
      break;
    case MQTYPE_INT16:
      if (!sscanf(value, "%d", &value_int16)) {
        RETURN_FALSE;
      }
      value_ptr = &value_int16;
      value_len = sizeof(MQTYPE_INT16);
      break;
    case MQTYPE_INT32:
      if (!sscanf(value, "%d", &value_int32)) {
        RETURN_FALSE;
      }
      value_ptr = &value_int32;
      value_len = sizeof(MQTYPE_INT32);
      break;
    case MQTYPE_INT64:
      if (!sscanf(value, "%ld", &value_int64)) {
        RETURN_FALSE;
      }
      value_ptr = &value_int64;
      value_len = sizeof(MQTYPE_INT64);
      break;
    case MQTYPE_FLOAT32:
      if (!sscanf(value, "%f", &value_float32)) {
        RETURN_FALSE;
      }
      value_ptr = &value_float32;
      value_len = sizeof(MQTYPE_FLOAT32);
      break;
    case MQTYPE_FLOAT64:
      if (!sscanf(value, "%lf", &value_float64)) {
        RETURN_FALSE;
      }
      value_ptr = &value_float64;
      value_len = sizeof(MQTYPE_FLOAT64);
    // break;
    case MQTYPE_NULL: /* Must be zero bytes */
      value_len = 0;
      break;
    default:
      break;
  }
  _mqseries_set_array_from_mqpd(z_proc_desc, &pd);
  _mqseries_set_mqsmpo_from_array(z_set_prop_opts, &msg_po);
  prop_name.VSPtr = name;
  prop_name.VSLength = name_len;

  MQSETMP(mqdesc->conn, mqhandle->handle, &msg_po, &prop_name, &pd, type, (MQLONG)value_len, value_ptr, &comp_code, &reason);

  ZVAL_LONG(z_comp_code, (long)comp_code);
  ZVAL_LONG(z_reason, (long)reason);

}


////////////////////////////////////////////////
/* }}} */

#endif /* HAVE_MQSERIESLIB_V7 */

/* {{{ _mqseries_bytes
 * frees memomory previuosly allocated
 */
#ifdef ZEND_ENGINE_3
void _mqseries_bytes(zend_resource *rsrc TSRMLS_DC)
#else
void _mqseries_bytes(zend_rsrc_list_entry *rsrc TSRMLS_DC)
#endif
{
  //if (((mqseries_bytes *)rsrc->ptr)->bytes) {
  efree(((mqseries_bytes *)rsrc->ptr)->bytes);
  //}
  efree(rsrc->ptr);
}

void _mqseries_hmsg(zend_resource *rsrc TSRMLS_DC) {
  //if (((mqseries_bytes *)rsrc->ptr)->bytes) {
  //efree(((mqseries_message *)rsrc->ptr)->handle);
  //}
  efree(rsrc->ptr);
}







/* }}} */

#ifndef ZEND_ENGINE_3
/* {{{ _mqseries_is_compcode_reason_ref
 * test to see if compcode and reason where passed by reference.
 */
static int _mqseries_is_compcode_reason_ref(zval *z_comp_code, zval *z_reason) {
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

/* {{{ _mqseries_is_called_by_ref
 * Test to see if a parameters was passed by reference.
 */
static int _mqseries_is_called_by_ref(zval *param, char *param_name) {
  if (!PZVAL_IS_REF(param)) {
    zend_error(E_WARNING, "Parameter %s wasn't passed by reference", param_name);
    return 0;
  }
  return 1;
}
/* }}} */
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
