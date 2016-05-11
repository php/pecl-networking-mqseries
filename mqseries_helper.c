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

    $Id: 6aecc573e7cfc52d5b8f0da9c097cd80767d515a $

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

/* {{{ Macros */
#define MQSERIES_UNSUPPRTED_VERSION(n,s) \
	zend_error(E_WARNING, #n "_VERSION_%d not supported, using " #n "_VERSION_%d instead", s->Version, n ## _CURRENT_VERSION)

#ifdef ZEND_ENGINE_3

#define MQSERIES_SETOPT_LONG(s,m) \
    do { \
        if ((tmp = zend_hash_str_find(ht, #m, sizeof(#m)-1)) != NULL) {\
            convert_to_long(tmp); \
            s->m = Z_LVAL_P(tmp); \
        } \
    } while(0)

#define MQSERIES_SETOPT_STRING(s,m) \
	do { \
		if ((tmp = zend_hash_str_find(ht, #m, sizeof(#m)-1)) != NULL && \
			Z_TYPE_P(tmp) == IS_STRING) { \
			strncpy(s->m, Z_STRVAL_P(tmp), sizeof(s->m)); \
		} \
	} while(0)

#define MQSERIES_SETOPT_CHAR(s, m) \
	do { \
		if ((tmp = zend_hash_str_find(ht, #m, sizeof(#m)-1)) != NULL && \
			Z_TYPE_P(tmp) == IS_STRING && Z_STRLEN_P(tmp) > 0) { \
			s->m = Z_STRVAL_P(tmp)[0]; \
		} \
	} while(0)

#define MQSERIES_SETOPT_RESBYTES(s,m) \
	do { \
		if ((tmp = zend_hash_str_find(ht, #m, sizeof(#m)-1)) != NULL) { \
			if (Z_TYPE_P(tmp) == IS_RESOURCE) { \
				mqseries_bytes *mqbytes = (mqseries_bytes *) zend_fetch_resource(Z_RES_P(tmp), PHP_MQSERIES_BYTES_RES_NAME, le_mqseries_bytes); \
				if (mqbytes != NULL) { \
					memcpy(s->m, mqbytes->bytes, sizeof(s->m)); \
				} \
			} else if (Z_TYPE_P(tmp) != IS_NULL) { \
				convert_to_string(tmp); \
				strncpy((MQCHAR *) s->m, Z_STRVAL_P(tmp), sizeof(s->m)); \
			} \
		} \
	} while(0)

#define MQSERIES_SETOPT_PTR(s,m) \
	do { \
		if ((tmp = zend_hash_str_find(ht, #m, sizeof(#m)-1)) != NULL) {\
			zend_error(E_WARNING, "'%s' is not yet supported.", #m); \
		} \
	} while(0)

#define MQSERIES_SETOPT_CHARV(s,m) \
	do { \
		if ((tmp = zend_hash_str_find(ht, #m, sizeof(#m)-1)) != NULL && \
			Z_TYPE_P(tmp) == IS_STRING) { \
			s->m.VSPtr = Z_STRVAL_P(tmp); \
			s->m.VSOffset = 0; \
			s->m.VSLength = Z_STRLEN_P(tmp); \
			s->m.VSBufSize = Z_STRLEN_P(tmp) + 1; \
		} \
	} while(0)

#define MQSERIES_SETOPT_HOBJ(s,m) \
	do { \
		if ((tmp = zend_hash_str_find(ht, #m, sizeof(#m)-1)) != NULL && \
			Z_TYPE_P(tmp) == IS_RESOURCE) { \
				mqseries_obj *mqobj = (mqseries_obj *) zend_fetch_resource(Z_RES_P(tmp), PHP_MQSERIES_OBJ_RES_NAME, le_mqseries_obj); \
				if (mqobj != NULL) { \
					s->m = mqobj->obj; \
				} \
		} \
	} while(0)

#else

#define MQSERIES_SETOPT_LONG(s,m) \
	do { \
		if (zend_hash_find(ht, #m, sizeof(#m), (void**)&tmp) == SUCCESS) {\
			convert_to_long(*tmp); \
			s->m = Z_LVAL_PP(tmp); \
		} \
	} while(0)

#define MQSERIES_SETOPT_STRING(s,m) \
	do { \
		if (zend_hash_find(ht, #m, sizeof(#m), (void**)&tmp) == SUCCESS && \
			Z_TYPE_PP(tmp) == IS_STRING) { \
			strncpy(s->m, Z_STRVAL_PP(tmp), sizeof(s->m)); \
		} \
	} while(0)

#define MQSERIES_SETOPT_CHAR(s, m) \
	do { \
		if (zend_hash_find(ht, #m, sizeof(#m), (void**)&tmp) == SUCCESS && \
			Z_TYPE_PP(tmp) == IS_STRING && Z_STRLEN_PP(tmp) > 0) { \
			s->m = Z_STRVAL_PP(tmp)[0]; \
		} \
	} while(0)

#define MQSERIES_SETOPT_RESBYTES(s,m) \
	do { \
		if (zend_hash_find(ht, #m, sizeof(#m), (void**)&tmp) == SUCCESS) { \
			if (Z_TYPE_PP(tmp) == IS_RESOURCE) { \
				mqseries_bytes *mqbytes = (mqseries_bytes *) zend_fetch_resource(tmp TSRMLS_CC, -1, PHP_MQSERIES_BYTES_RES_NAME, NULL, 1, le_mqseries_bytes); \
				if (mqbytes != NULL) { \
					memcpy(s->m, mqbytes->bytes, sizeof(s->m)); \
				} \
			} else if (Z_TYPE_PP(tmp) != IS_NULL) { \
				convert_to_string(*tmp); \
				strncpy((MQCHAR *) s->m, Z_STRVAL_PP(tmp), sizeof(s->m)); \
			} \
		} \
	} while(0)

#define MQSERIES_SETOPT_PTR(s,m) \
	do { \
		if (zend_hash_find(ht, #m, sizeof(#m), (void**)&tmp) == SUCCESS) {\
			zend_error(E_WARNING, "'%s' is not yet supported.", #m); \
		} \
	} while(0)

#define MQSERIES_SETOPT_CHARV(s,m) \
	do { \
		if (zend_hash_find(ht, #m, sizeof(#m), (void**)&tmp) == SUCCESS && \
			Z_TYPE_PP(tmp) == IS_STRING) { \
			s->m.VSPtr = Z_STRVAL_PP(tmp); \
			s->m.VSOffset = 0; \
			s->m.VSLength = Z_STRLEN_PP(tmp); \
			s->m.VSBufSize = Z_STRLEN_PP(tmp) + 1; \
		} \
	} while(0)

#define MQSERIES_SETOPT_HOBJ(s,m) \
	do { \
		if (zend_hash_find(ht, #m, sizeof(#m), (void**)&tmp) == SUCCESS && \
			Z_TYPE_PP(tmp) == IS_RESOURCE) { \
				mqseries_obj *mqobj = (mqseries_obj *) zend_fetch_resource(tmp TSRMLS_CC, -1, PHP_MQSERIES_OBJ_RES_NAME, NULL, 1, le_mqseries_obj); \
				if (mqobj != NULL) { \
					s->m = mqobj->obj; \
				} \
		} \
	} while(0)

#endif

#define MQSERIES_ADD_ASSOC_LONG(s, m) \
	add_assoc_long(array, #m, s->m)

#ifdef ZEND_ENGINE_3

#define MQSERIES_ADD_ASSOC_STRING(s, m) \
	do { \
		if (s->m != NULL && strlen(s->m) > 0) { \
			add_assoc_stringl(array, #m, s->m, sizeof(s->m)); \
		} \
	} while(0)

#else

#define MQSERIES_ADD_ASSOC_STRING(s, m) \
	do { \
		if (s->m != NULL && strlen(s->m) > 0) { \
			add_assoc_stringl(array, #m, s->m, sizeof(s->m), 1); \
		} \
	} while(0)

#endif

#ifdef ZEND_ENGINE_3

#define MQSERIES_ADD_ASSOC_RESOURCE(s, m) \
	do { \
		zval *ref = create_mqseries_bytes_resource(s->m, sizeof(s->m) TSRMLS_CC); \
	    add_assoc_zval(array, #m, ref); \
		efree(ref);  \
	} while(0)

#else

#define MQSERIES_ADD_ASSOC_RESOURCE(s, m) \
	do { \
		zval *ref = create_mqseries_bytes_resource(s->m, sizeof(s->m) TSRMLS_CC); \
	    add_assoc_resource(array, #m, Z_RESVAL_P(ref)); \
		zend_list_addref(Z_RESVAL_P(ref)); \
		zval_ptr_dtor(&ref); \
	} while(0)

#endif

#ifdef ZEND_ENGINE_3

#define MQSERIES_ADD_ASSOC_CHARV(s, m) \
	do { \
		if (s->m.VSPtr != NULL && s->m.VSLength > 0) { \
			add_assoc_stringl(array, #m, (char *) s->m.VSPtr, s->m.VSLength); \
		} \
	} while(0)

#else

#define MQSERIES_ADD_ASSOC_CHARV(s, m) \
	do { \
		if (s->m.VSPtr != NULL && s->m.VSLength > 0) { \
			add_assoc_stringl(array, #m, (char *) s->m.VSPtr, s->m.VSLength, 1); \
		} \
	} while(0)

#endif

#ifdef ZEND_ENGINE_3

#define MQSERIES_ADD_ASSOC_CHAR(s, m) \
	do { \
		char str[2]; \
		sprintf(str, "%c", s->m); \
		add_assoc_string(array, #m, str); \
	} while(0)

#else

#define MQSERIES_ADD_ASSOC_CHAR(s, m) \
	do { \
		char str[2]; \
		sprintf(str, "%c", s->m); \
		add_assoc_string(array, #m, str, 1); \
	} while(0)

#endif

/* }}} */

/* {{{ create_mqseries_bytes_resource
 * makes an mqseries_bytes reference, needed when returning message and correlation id's
 */
static zval* create_mqseries_bytes_resource(PMQBYTE bytes, size_t size TSRMLS_DC)
{
	mqseries_bytes *pBytes;

	zval *z_bytes;

#ifdef ZEND_ENGINE_3
	z_bytes = (zval *) emalloc(sizeof(zval));
#else
	MAKE_STD_ZVAL(z_bytes);
#endif

	pBytes = (mqseries_bytes *) emalloc(sizeof(mqseries_bytes));
	pBytes->bytes = (PMQBYTE) emalloc(size*sizeof(MQBYTE));
	memcpy(pBytes->bytes, bytes, size);

#ifdef ZEND_ENGINE_3
	ZVAL_RES(z_bytes, zend_register_resource(pBytes, le_mqseries_bytes));
	pBytes->id = Z_RES_P(z_bytes)->handle;
#else
	ZEND_REGISTER_RESOURCE(z_bytes, pBytes, le_mqseries_bytes);
	pBytes->id = Z_RESVAL_P(z_bytes);
#endif

	return z_bytes;
}
/* }}} */

/******************************************************************************/
/* Following are methods to make structs from arrays and vice verse           */
/* TODO Check if all fields are specified (hopefully the MQ API will not      */
/* change verry soon as we have to do this all over again). 'zucht'.          */
/******************************************************************************/

static void _mqseries_set_authentication_information_record_from_array(zval *array, PMQAIR authentication_information_record, PMQCHAR LDAPUserName) /* {{{ */
{
	HashTable *ht = Z_ARRVAL_P(array);

#ifdef ZEND_ENGINE_3
	zval *tmp;
#else
	zval **tmp;
#endif

	MQSERIES_SETOPT_LONG(authentication_information_record, Version);
	MQSERIES_SETOPT_LONG(authentication_information_record, AuthInfoType);
	MQSERIES_SETOPT_STRING(authentication_information_record, AuthInfoConnName);
	MQSERIES_SETOPT_STRING(authentication_information_record, LDAPPassword);
	MQSERIES_SETOPT_STRING(authentication_information_record, OCSPResponderURL);

#ifdef ZEND_ENGINE_3
	if ((tmp = zend_hash_str_find(ht, "LDAPUserName", sizeof("LDAPUserName")-1)) != NULL &&
		Z_TYPE_P(tmp) == IS_STRING) {
		strncpy(LDAPUserName, Z_STRVAL_P(tmp), sizeof(LDAPUserName));
#else
	if (zend_hash_find(ht, "LDAPUserName", sizeof("LDAPUserName"), (void**)&tmp) == SUCCESS &&
		Z_TYPE_PP(tmp) == IS_STRING) {
		strncpy(LDAPUserName, Z_STRVAL_PP(tmp), sizeof(LDAPUserName));
#endif
		authentication_information_record->LDAPUserNamePtr = LDAPUserName;
		authentication_information_record->LDAPUserNameLength = strlen(LDAPUserName);
	}
}
/* }}} */

static void _mqseries_set_ssl_configuration_from_array(zval *array, PMQSCO ssl_configuration, PMQAIR authentication_information_record, PMQCHAR LDAPUserName) /* {{{ */
{
	HashTable *ht = Z_ARRVAL_P(array);
#ifdef ZEND_ENGINE_3
	zval *tmp;
#else
	zval **tmp;
#endif

	MQSERIES_SETOPT_LONG(ssl_configuration, Version);
	MQSERIES_SETOPT_STRING(ssl_configuration, KeyRepository);
	MQSERIES_SETOPT_STRING(ssl_configuration, CryptoHardware);

#ifdef ZEND_ENGINE_3
	if ((tmp = zend_hash_str_find(ht, "MQAIR", sizeof("MQAIR")-1)) != NULL &&
		Z_TYPE_P(tmp) == IS_ARRAY) {
		_mqseries_set_authentication_information_record_from_array(tmp, authentication_information_record, LDAPUserName);
#else
	if (zend_hash_find(ht, "MQAIR", sizeof("MQAIR"), (void**)&tmp) == SUCCESS &&
		Z_TYPE_PP(tmp) == IS_ARRAY) {
		_mqseries_set_authentication_information_record_from_array(*tmp, authentication_information_record, LDAPUserName);
#endif
		ssl_configuration->AuthInfoRecCount = 1;
		ssl_configuration->AuthInfoRecPtr = authentication_information_record;
	}
}
/* }}} */

static void _mqseries_set_channel_definition_from_array(zval *array, PMQCD channel_definition TSRMLS_DC) /* {{{ */
{
	HashTable *ht = Z_ARRVAL_P(array);
#ifdef ZEND_ENGINE_3
	zval *tmp;
#else
	zval **tmp;
#endif

	MQSERIES_SETOPT_LONG(channel_definition, Version);

	switch (channel_definition->Version) {
		default:
			MQSERIES_UNSUPPRTED_VERSION(MQCD, channel_definition);

#ifdef MQCD_VERSION_10
		case MQCD_VERSION_10:
			MQSERIES_SETOPT_LONG(channel_definition, BatchDataLimit);
			MQSERIES_SETOPT_LONG(channel_definition, UseDLQ);
			MQSERIES_SETOPT_LONG(channel_definition, DefReconnect);
			// no break intentional
#endif /* MQCD_VERSION_10 */

#ifdef MQCD_VERSION_9
		case MQCD_VERSION_9:
			MQSERIES_SETOPT_LONG(channel_definition, SharingConversations);
			MQSERIES_SETOPT_LONG(channel_definition, PropertyControl);
			MQSERIES_SETOPT_LONG(channel_definition, MaxInstances);
			MQSERIES_SETOPT_LONG(channel_definition, MaxInstancesPerClient);
			MQSERIES_SETOPT_LONG(channel_definition, ClientChannelWeight);
			MQSERIES_SETOPT_LONG(channel_definition, ConnectionAffinity);
			// no break intentional
#endif /* MQCD_VERSION_9 */

#ifdef MQCD_VERSION_8
		case MQCD_VERSION_8:
			// HdrCompList
			// MsgCompList
			MQSERIES_SETOPT_LONG(channel_definition, CLWLChannelRank);
			MQSERIES_SETOPT_LONG(channel_definition, CLWLChannelPriority);
			MQSERIES_SETOPT_LONG(channel_definition, CLWLChannelWeight);
			MQSERIES_SETOPT_LONG(channel_definition, ChannelMonitoring);
			MQSERIES_SETOPT_LONG(channel_definition, ChannelStatistics);
			// no break intentional
#endif /* MQCD_VERSION_8 */

#ifdef MQCD_VERSION_7
		case MQCD_VERSION_7:
			MQSERIES_SETOPT_STRING(channel_definition, SSLCipherSpec);
			MQSERIES_SETOPT_PTR(channel_definition, SSLPeerNamePtr);
			MQSERIES_SETOPT_LONG(channel_definition, SSLPeerNameLength);
			MQSERIES_SETOPT_LONG(channel_definition, SSLClientAuth);
			MQSERIES_SETOPT_LONG(channel_definition, KeepAliveInterval);
			MQSERIES_SETOPT_STRING(channel_definition, LocalAddress);
			MQSERIES_SETOPT_LONG(channel_definition, BatchHeartbeat);
			// no break intentional
#endif /* MQCD_VERSION_7 */

#ifdef MQCD_VERSION_6
		case MQCD_VERSION_6:
			MQSERIES_SETOPT_LONG(channel_definition, LongMCAUserIdLength);
			MQSERIES_SETOPT_LONG(channel_definition, LongRemoteUserIdLength);
			MQSERIES_SETOPT_PTR(channel_definition, LongMCAUserIdPtr);
			MQSERIES_SETOPT_PTR(channel_definition, LongRemoteUserIdPtr);
			MQSERIES_SETOPT_RESBYTES(channel_definition, MCASecurityId);
			MQSERIES_SETOPT_RESBYTES(channel_definition, RemoteSecurityId);
			// no break intentional
#endif /* MQCD_VERSION_6 */

#ifdef MQCD_VERSION_5
		case MQCD_VERSION_5:
			MQSERIES_SETOPT_PTR(channel_definition, ClusterPtr);
			MQSERIES_SETOPT_LONG(channel_definition, ClustersDefined);
			MQSERIES_SETOPT_LONG(channel_definition, NetworkPriority);
			// no break intentional
#endif /* MQCD_VERSION_5 */

#ifdef MQCD_VERSION_4
		case MQCD_VERSION_4:
			MQSERIES_SETOPT_LONG(channel_definition, HeartbeatInterval);
			MQSERIES_SETOPT_LONG(channel_definition, BatchInterval);
			MQSERIES_SETOPT_LONG(channel_definition, NonPersistentMsgSpeed);
			MQSERIES_SETOPT_LONG(channel_definition, StrucLength);
			MQSERIES_SETOPT_LONG(channel_definition, ExitNameLength);
			MQSERIES_SETOPT_LONG(channel_definition, ExitDataLength);
			MQSERIES_SETOPT_LONG(channel_definition, MsgExitsDefined);
			MQSERIES_SETOPT_LONG(channel_definition, SendExitsDefined);
			MQSERIES_SETOPT_LONG(channel_definition, ReceiveExitsDefined);
			MQSERIES_SETOPT_PTR(channel_definition, MsgExitPtr);
			MQSERIES_SETOPT_PTR(channel_definition, MsgUserDataPtr);
			MQSERIES_SETOPT_PTR(channel_definition, SendExitPtr);
			MQSERIES_SETOPT_PTR(channel_definition, SendUserDataPtr);
			MQSERIES_SETOPT_PTR(channel_definition, ReceiveExitPtr);
			MQSERIES_SETOPT_PTR(channel_definition, ReceiveUserDataPtr);
			// no break intentional
#endif /* MQCD_VERSION_4 */

#ifdef MQCD_VERSION_3
		case MQCD_VERSION_3:
			MQSERIES_SETOPT_STRING(channel_definition, MsgRetryExit);
			MQSERIES_SETOPT_STRING(channel_definition, MsgRetryUserData);
			MQSERIES_SETOPT_LONG(channel_definition, MsgRetryCount);
			MQSERIES_SETOPT_LONG(channel_definition, MsgRetryInterval);
			// no break intentional
#endif /* MQCD_VERSION_3 */

#ifdef MQCD_VERSION_2
		case MQCD_VERSION_2:
			MQSERIES_SETOPT_STRING(channel_definition, UserIdentifier);
			MQSERIES_SETOPT_STRING(channel_definition, Password);
			MQSERIES_SETOPT_STRING(channel_definition, MCAUserIdentifier);
			MQSERIES_SETOPT_LONG(channel_definition, MCAType);
			MQSERIES_SETOPT_STRING(channel_definition, ConnectionName);
			MQSERIES_SETOPT_STRING(channel_definition, RemoteUserIdentifier);
			MQSERIES_SETOPT_STRING(channel_definition, RemotePassword);
			// no break intentional
#endif /* MQCD_VERSION_2 */

#ifdef MQCD_VERSION_1
		case MQCD_VERSION_1:
			MQSERIES_SETOPT_STRING(channel_definition, ChannelName);
			MQSERIES_SETOPT_LONG(channel_definition, ChannelType);
			MQSERIES_SETOPT_LONG(channel_definition, TransportType);
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
			// no break intentional
#endif /* MQCD_VERSION_1 */
	}
}
/* }}} */

void _mqseries_set_mqcno_from_array(zval *array, PMQCNO connect_opts, PMQCD channel_definition, PMQSCO ssl_configuration, PMQAIR authentication_information_record, 	PMQCHAR LDAPUserName TSRMLS_DC) /* {{{ */
{
	HashTable *ht = Z_ARRVAL_P(array);
#ifdef ZEND_ENGINE_3
	zval *tmp;
#else
	zval **tmp;
#endif

	MQSERIES_SETOPT_LONG(connect_opts, Options);
	MQSERIES_SETOPT_LONG(connect_opts, Version);

#ifdef ZEND_ENGINE_3
	if ((tmp = zend_hash_str_find(ht, "MQCD", sizeof("MQCD")-1)) != NULL &&
		Z_TYPE_P(tmp) == IS_ARRAY) {
		_mqseries_set_channel_definition_from_array(tmp, channel_definition TSRMLS_CC);
#else
	if (zend_hash_find(ht, "MQCD", sizeof("MQCD"), (void**)&tmp) == SUCCESS &&
		Z_TYPE_PP(tmp) == IS_ARRAY) {
		_mqseries_set_channel_definition_from_array(*tmp, channel_definition TSRMLS_CC);
#endif
		connect_opts->ClientConnPtr = channel_definition;
	}

#ifdef ZEND_ENGINE_3
	if ((tmp = zend_hash_str_find(ht, "MQSCO", sizeof("MQSCO")-1)) != NULL &&
		Z_TYPE_P(tmp) == IS_ARRAY) {
		_mqseries_set_ssl_configuration_from_array(tmp, ssl_configuration, authentication_information_record, LDAPUserName);
#else
	if (zend_hash_find(ht, "MQSCO", sizeof("MQSCO"), (void**)&tmp) == SUCCESS &&
		Z_TYPE_PP(tmp) == IS_ARRAY) {
		_mqseries_set_ssl_configuration_from_array(*tmp, ssl_configuration, authentication_information_record, LDAPUserName);
#endif
		connect_opts->SSLConfigPtr = ssl_configuration;
	}
}
/* }}} */

void _mqseries_set_mqpmo_from_array(zval *array, PMQPMO put_msg_opts TSRMLS_DC) /* {{{ */
{
	HashTable *ht = Z_ARRVAL_P(array);
#ifdef ZEND_ENGINE_3
	zval *tmp;
#else
	zval **tmp;
#endif

	MQSERIES_SETOPT_LONG(put_msg_opts, Version);

	switch (put_msg_opts->Version) {
		default:
			MQSERIES_UNSUPPRTED_VERSION(MQPMO, put_msg_opts);

#ifdef MQPMO_VERSION_3
		case MQPMO_VERSION_3:
			// MQHMSG    OriginalMsgHandle;
			// MQHMSG    NewMsgHandle;
			MQSERIES_SETOPT_LONG(put_msg_opts, Action);
			MQSERIES_SETOPT_LONG(put_msg_opts, PubLevel);
			// no break intentional
#endif /* MQPMO_VERSION_3 */

#ifdef MQPMO_VERSION_2
		case MQPMO_VERSION_2:
			MQSERIES_SETOPT_LONG(put_msg_opts, RecsPresent);
			MQSERIES_SETOPT_LONG(put_msg_opts, PutMsgRecFields);
			MQSERIES_SETOPT_LONG(put_msg_opts, PutMsgRecOffset);
			MQSERIES_SETOPT_LONG(put_msg_opts, ResponseRecOffset);
			MQSERIES_SETOPT_PTR(put_msg_opts, PutMsgRecPtr);
			MQSERIES_SETOPT_PTR(put_msg_opts, ResponseRecPtr);
			// no break intentional
#endif /* MQPMO_VERSION_2 */

#ifdef MQPMO_VERSION_1
		case MQPMO_VERSION_1:
			MQSERIES_SETOPT_LONG(put_msg_opts, Options);
			MQSERIES_SETOPT_LONG(put_msg_opts, Timeout);
			MQSERIES_SETOPT_HOBJ(put_msg_opts, Context);
			MQSERIES_SETOPT_LONG(put_msg_opts, KnownDestCount);
			MQSERIES_SETOPT_LONG(put_msg_opts, UnknownDestCount);
			MQSERIES_SETOPT_LONG(put_msg_opts, InvalidDestCount);
			MQSERIES_SETOPT_STRING(put_msg_opts, ResolvedQName);
			MQSERIES_SETOPT_STRING(put_msg_opts, ResolvedQMgrName);
			// no break intentional
#endif /* MQPMO_VERSION_1 */
	}
}
/* }}} */

void _mqseries_set_array_from_mqpmo(zval *array, PMQPMO put_msg_opts) { /* {{{ */
	zval_dtor(array);
	array_init(array);

	switch (put_msg_opts->Version) {
		default:
			MQSERIES_UNSUPPRTED_VERSION(MQPMO, put_msg_opts);

#ifdef MQPMO_VERSION_3
		case MQPMO_VERSION_3:
			// MQHMSG    OriginalMsgHandle;
			// MQHMSG    NewMsgHandle;
			MQSERIES_ADD_ASSOC_LONG(put_msg_opts, Action);
			MQSERIES_ADD_ASSOC_LONG(put_msg_opts, PubLevel);
			// no break intentional
#endif /* MQPMO_VERSION_3 */

#ifdef MQPMO_VERSION_2
		case MQPMO_VERSION_2:
			MQSERIES_ADD_ASSOC_LONG(put_msg_opts, RecsPresent);
			MQSERIES_ADD_ASSOC_LONG(put_msg_opts, PutMsgRecFields);
			MQSERIES_ADD_ASSOC_LONG(put_msg_opts, PutMsgRecOffset);
			MQSERIES_ADD_ASSOC_LONG(put_msg_opts, ResponseRecOffset);
			// MQSERIES_SETOPT_PTR(put_msg_opts, PutMsgRecPtr);
			// MQSERIES_SETOPT_PTR(put_msg_opts, ResponseRecPtr);
			// no break intentional
#endif /* MQPMO_VERSION_2 */

#ifdef MQPMO_VERSION_1
		case MQPMO_VERSION_1:
			MQSERIES_ADD_ASSOC_LONG(put_msg_opts, Version);
			MQSERIES_ADD_ASSOC_LONG(put_msg_opts, Timeout);
			// MQHOBJ Context
			MQSERIES_ADD_ASSOC_LONG(put_msg_opts, KnownDestCount);
			MQSERIES_ADD_ASSOC_LONG(put_msg_opts, UnknownDestCount);
			MQSERIES_ADD_ASSOC_LONG(put_msg_opts, InvalidDestCount);
			MQSERIES_ADD_ASSOC_STRING(put_msg_opts, ResolvedQName);
			MQSERIES_ADD_ASSOC_STRING(put_msg_opts, ResolvedQMgrName);
			// no break intentional
#endif /* MQPMO_VERSION_1 */
	}
}
/* }}} */

void _mqseries_set_mqmd_from_array(zval *array, PMQMD msg_desc TSRMLS_DC) /* {{{ */
{
	HashTable *ht = Z_ARRVAL_P(array);
#ifdef ZEND_ENGINE_3
	zval *tmp;
#else
	zval **tmp;
#endif

	MQSERIES_SETOPT_LONG(msg_desc, Version);
	switch (msg_desc->Version) {
		default:
			MQSERIES_UNSUPPRTED_VERSION(MQMD, msg_desc);

#ifdef MQMD_VERSION_2
		case MQMD_VERSION_2:
			MQSERIES_SETOPT_RESBYTES(msg_desc, GroupId);
			MQSERIES_SETOPT_LONG(msg_desc, MsgSeqNumber);
			MQSERIES_SETOPT_LONG(msg_desc, Offset);
			MQSERIES_SETOPT_LONG(msg_desc, MsgFlags);
			MQSERIES_SETOPT_LONG(msg_desc, OriginalLength);
			// no break intentional
#endif /* MQMD_VERSION_2 */

#ifdef MQMD_VERSION_1
		case MQMD_VERSION_1:
			MQSERIES_SETOPT_LONG(msg_desc, Report);
			MQSERIES_SETOPT_LONG(msg_desc, MsgType);
			MQSERIES_SETOPT_LONG(msg_desc, Expiry);
			MQSERIES_SETOPT_LONG(msg_desc, Feedback);
			MQSERIES_SETOPT_LONG(msg_desc, Encoding);
			MQSERIES_SETOPT_LONG(msg_desc, CodedCharSetId);
			MQSERIES_SETOPT_STRING(msg_desc, Format);
			MQSERIES_SETOPT_LONG(msg_desc, Priority);
			MQSERIES_SETOPT_LONG(msg_desc, Persistence);
			MQSERIES_SETOPT_RESBYTES(msg_desc, MsgId);
			MQSERIES_SETOPT_RESBYTES(msg_desc, CorrelId);
			MQSERIES_SETOPT_LONG(msg_desc, BackoutCount);
			MQSERIES_SETOPT_STRING(msg_desc, ReplyToQ);
			MQSERIES_SETOPT_STRING(msg_desc, ReplyToQMgr);
			MQSERIES_SETOPT_STRING(msg_desc, UserIdentifier);
			MQSERIES_SETOPT_RESBYTES(msg_desc, AccountingToken);
			MQSERIES_SETOPT_STRING(msg_desc, ApplIdentityData);
			MQSERIES_SETOPT_LONG(msg_desc, PutApplType);
			MQSERIES_SETOPT_STRING(msg_desc, PutApplName);
			MQSERIES_SETOPT_STRING(msg_desc, PutDate);
			MQSERIES_SETOPT_STRING(msg_desc, PutTime);
			MQSERIES_SETOPT_STRING(msg_desc, ApplOriginData);
			// no break intentional
#endif /* MQMD_VERSION_1 */
	}
}
/* }}} */

void _mqseries_set_array_from_mqmd(zval *array, PMQMD msg_desc TSRMLS_DC) /* {{{ */
{
	zval_dtor(array);
	array_init(array);

	switch (msg_desc->Version) {
		default:
			MQSERIES_UNSUPPRTED_VERSION(MQMD, msg_desc);

#ifdef MQMD_VERSION_2
		case MQMD_VERSION_2:
			MQSERIES_ADD_ASSOC_RESOURCE(msg_desc, GroupId);
			MQSERIES_ADD_ASSOC_LONG(msg_desc, MsgSeqNumber);
			MQSERIES_ADD_ASSOC_LONG(msg_desc, Offset);
			MQSERIES_ADD_ASSOC_LONG(msg_desc, MsgFlags);
			MQSERIES_ADD_ASSOC_LONG(msg_desc, OriginalLength);
#endif /* MQMD_VERSION_2 */

#ifdef MQMD_VERSION_1
		case MQMD_VERSION_1:
			MQSERIES_ADD_ASSOC_LONG(msg_desc, Version);
			MQSERIES_ADD_ASSOC_LONG(msg_desc, Report);
			MQSERIES_ADD_ASSOC_LONG(msg_desc, MsgType);
			MQSERIES_ADD_ASSOC_LONG(msg_desc, Expiry);
			MQSERIES_ADD_ASSOC_LONG(msg_desc, Feedback);
			MQSERIES_ADD_ASSOC_LONG(msg_desc, Encoding);
			MQSERIES_ADD_ASSOC_LONG(msg_desc, CodedCharSetId);
			MQSERIES_ADD_ASSOC_STRING(msg_desc, Format);
			MQSERIES_ADD_ASSOC_LONG(msg_desc, Priority);
			MQSERIES_ADD_ASSOC_LONG(msg_desc, Persistence);
			MQSERIES_ADD_ASSOC_RESOURCE(msg_desc, MsgId);
			MQSERIES_ADD_ASSOC_RESOURCE(msg_desc, CorrelId);
			MQSERIES_ADD_ASSOC_LONG(msg_desc, BackoutCount);
			MQSERIES_ADD_ASSOC_STRING(msg_desc, ReplyToQ);
			MQSERIES_ADD_ASSOC_STRING(msg_desc, ReplyToQMgr);
			MQSERIES_ADD_ASSOC_STRING(msg_desc, UserIdentifier);
			MQSERIES_ADD_ASSOC_RESOURCE(msg_desc, AccountingToken);
			MQSERIES_ADD_ASSOC_STRING(msg_desc, ApplIdentityData);
			MQSERIES_ADD_ASSOC_LONG(msg_desc, PutApplType);
			MQSERIES_ADD_ASSOC_STRING(msg_desc, PutApplName);
			MQSERIES_ADD_ASSOC_STRING(msg_desc, PutDate);
			MQSERIES_ADD_ASSOC_STRING(msg_desc, PutTime);
			MQSERIES_ADD_ASSOC_STRING(msg_desc, ApplOriginData);
#endif /* MQMD_VERSION_1 */
	}
}
/* }}} */

void _mqseries_set_mqod_from_array(zval *array, PMQOD obj_desc TSRMLS_DC) /* {{{ */
{
	HashTable *ht = Z_ARRVAL_P(array);
#ifdef ZEND_ENGINE_3
	zval *tmp;
#else
	zval **tmp;
#endif

	MQSERIES_SETOPT_LONG(obj_desc, Version);
	switch (obj_desc->Version) {
		default:
			MQSERIES_UNSUPPRTED_VERSION(MQOD, obj_desc);

#ifdef MQOD_VERSION_4
		case MQOD_VERSION_4:
			MQSERIES_SETOPT_CHARV(obj_desc, ObjectString);
			MQSERIES_SETOPT_CHARV(obj_desc, SelectionString);
			MQSERIES_SETOPT_CHARV(obj_desc, ResObjectString);
			MQSERIES_SETOPT_LONG(obj_desc, ResolvedType);
#endif /* MQOD_VERSION_4 */

#ifdef MQOD_VERSION_3
		case MQOD_VERSION_3:
			MQSERIES_SETOPT_RESBYTES(obj_desc, AlternateSecurityId);
			MQSERIES_SETOPT_STRING(obj_desc, ResolvedQName);
			MQSERIES_SETOPT_STRING(obj_desc, ResolvedQMgrName);
#endif /* MQOD_VERSION_3 */

#ifdef MQOD_VERSION_2
		case MQOD_VERSION_2:
			MQSERIES_SETOPT_LONG(obj_desc, RecsPresent);
			MQSERIES_SETOPT_LONG(obj_desc, KnownDestCount);
			MQSERIES_SETOPT_LONG(obj_desc, UnknownDestCount);
			MQSERIES_SETOPT_LONG(obj_desc, InvalidDestCount);
			MQSERIES_SETOPT_LONG(obj_desc, ObjectRecOffset);
			MQSERIES_SETOPT_LONG(obj_desc, ResponseRecOffset);
			MQSERIES_SETOPT_PTR(obj_desc, ObjectRecPtr);
			MQSERIES_SETOPT_PTR(obj_desc, ResponseRecPtr);
#endif /* MQOD_VERSION_2 */

#ifdef MQOD_VERSION_1
		case MQOD_VERSION_1:
			MQSERIES_SETOPT_LONG(obj_desc, ObjectType);
			MQSERIES_SETOPT_STRING(obj_desc, ObjectName);
			MQSERIES_SETOPT_STRING(obj_desc, ObjectQMgrName);
			MQSERIES_SETOPT_STRING(obj_desc, DynamicQName);
			MQSERIES_SETOPT_STRING(obj_desc, AlternateUserId);
			break;
#endif /* MQOD_VERSION_1 */
	}
}
/* }}} */

void _mqseries_set_array_from_mqod(zval *array, PMQOD obj_desc TSRMLS_DC) /* {{{ */
{
	zval_dtor(array);
	array_init(array);

	switch(obj_desc->Version) {
		default:
			MQSERIES_UNSUPPRTED_VERSION(MQOD, obj_desc);

#ifdef MQOD_VERSION_4
		case MQOD_VERSION_4:
			MQSERIES_ADD_ASSOC_CHARV(obj_desc, ObjectString);
			MQSERIES_ADD_ASSOC_CHARV(obj_desc, SelectionString);
			MQSERIES_ADD_ASSOC_CHARV(obj_desc, ResObjectString);
			MQSERIES_ADD_ASSOC_LONG(obj_desc, ResolvedType);
#endif /* MQOD_VERSION_4 */

#ifdef MQOD_VERSION_3
		case MQOD_VERSION_3:
			MQSERIES_ADD_ASSOC_RESOURCE(obj_desc, AlternateSecurityId);
			MQSERIES_ADD_ASSOC_STRING(obj_desc, ResolvedQName);
			MQSERIES_ADD_ASSOC_STRING(obj_desc, ResolvedQMgrName);
#endif /* MQOD_VERSION_3 */

#ifdef MQOD_VERSION_2
		case MQOD_VERSION_2:
			MQSERIES_ADD_ASSOC_LONG(obj_desc, RecsPresent);
			MQSERIES_ADD_ASSOC_LONG(obj_desc, KnownDestCount);
			MQSERIES_ADD_ASSOC_LONG(obj_desc, UnknownDestCount);
			MQSERIES_ADD_ASSOC_LONG(obj_desc, InvalidDestCount);
			MQSERIES_ADD_ASSOC_LONG(obj_desc, ObjectRecOffset);
			MQSERIES_ADD_ASSOC_LONG(obj_desc, ResponseRecOffset);
			// MQPTR     ObjectRecPtr;
			// MQPTR     ResponseRecPtr;
#endif /* MQOD_VERSION_2 */

		case MQOD_VERSION_1:
			MQSERIES_ADD_ASSOC_LONG(obj_desc, Version);
			MQSERIES_ADD_ASSOC_LONG(obj_desc, ObjectType);
			MQSERIES_ADD_ASSOC_STRING(obj_desc, ObjectName);
			MQSERIES_ADD_ASSOC_STRING(obj_desc, ObjectQMgrName);
			MQSERIES_ADD_ASSOC_STRING(obj_desc, DynamicQName);
			MQSERIES_ADD_ASSOC_STRING(obj_desc, AlternateUserId);
			break;

	}
}
/* }}} */

void _mqseries_set_mqgmo_from_array(zval *array, PMQGMO get_msg_opts  TSRMLS_DC) /* {{{ */
{
	HashTable *ht = Z_ARRVAL_P(array);
#ifdef ZEND_ENGINE_3
	zval *tmp;
#else
	zval **tmp;
#endif

	MQSERIES_SETOPT_LONG(get_msg_opts, Version);
	switch (get_msg_opts->Version) {
		default:
			MQSERIES_UNSUPPRTED_VERSION(MQGMO, get_msg_opts);

#ifdef MQGMO_VERSION_4
		case MQGMO_VERSION_4:
			// MQHMSG    MsgHandle;
			MQSERIES_SETOPT_LONG(get_msg_opts, Reserved2);
			// no break intentional
#endif /* MQGMO_VERSION_4 */

#ifdef MQGMO_VERSION_3
		case MQGMO_VERSION_3:
			MQSERIES_SETOPT_LONG(get_msg_opts, ReturnedLength);
			MQSERIES_SETOPT_RESBYTES(get_msg_opts, MsgToken);
			// no break intentional
#endif /* MQGMO_VERSION_3 */

#ifdef MQGMO_VERSION_2
		case MQGMO_VERSION_2:
			MQSERIES_SETOPT_LONG(get_msg_opts, MatchOptions);
			MQSERIES_SETOPT_CHAR(get_msg_opts, GroupStatus);
			MQSERIES_SETOPT_CHAR(get_msg_opts, SegmentStatus);
			MQSERIES_SETOPT_CHAR(get_msg_opts, Segmentation);
			MQSERIES_SETOPT_CHAR(get_msg_opts, Reserved1);
			// no break intentional
#endif /* MQGMO_VERSION_2 */

#ifdef MQGMO_VERSION_1
		case MQGMO_VERSION_1:
			MQSERIES_SETOPT_LONG(get_msg_opts, Options);
			MQSERIES_SETOPT_LONG(get_msg_opts, WaitInterval);
			MQSERIES_SETOPT_LONG(get_msg_opts, Signal1);
			MQSERIES_SETOPT_LONG(get_msg_opts, Signal2);
			MQSERIES_SETOPT_STRING(get_msg_opts, ResolvedQName);
			// no break intentional
#endif /* MQGMO_VERSION_1 */
	}
}
/* }}} */

void _mqseries_set_array_from_mqgmo(zval *array, PMQGMO get_msg_opts TSRMLS_DC) /* {{{ */
{
	zval_dtor(array);
	array_init(array);

	switch (get_msg_opts->Version) {
		default:
			MQSERIES_UNSUPPRTED_VERSION(MQGMO, get_msg_opts);

#ifdef MQGMO_VERSION_4
		case MQGMO_VERSION_4:
			// MQHMSG    MsgHandle;
			MQSERIES_ADD_ASSOC_LONG(get_msg_opts, Reserved2);
			// no break intentional
#endif /* MQGMO_VERSION_4 */

#ifdef MQGMO_VERSION_3
		case MQGMO_VERSION_3:
			MQSERIES_ADD_ASSOC_LONG(get_msg_opts, ReturnedLength);
			MQSERIES_ADD_ASSOC_RESOURCE(get_msg_opts, MsgToken);
			// no break intentional
#endif /* MQGMO_VERSION_3 */

#ifdef MQGMO_VERSION_2
		case MQGMO_VERSION_2:
			MQSERIES_ADD_ASSOC_LONG(get_msg_opts, MatchOptions);
			MQSERIES_ADD_ASSOC_CHAR(get_msg_opts, GroupStatus);
			MQSERIES_ADD_ASSOC_CHAR(get_msg_opts, SegmentStatus);
			MQSERIES_ADD_ASSOC_CHAR(get_msg_opts, Segmentation);
			MQSERIES_ADD_ASSOC_CHAR(get_msg_opts, Reserved1);
			// no break intentional
#endif /* MQGMO_VERSION_2 */

#ifdef MQGMO_VERSION_1
		case MQGMO_VERSION_1:
			MQSERIES_ADD_ASSOC_LONG(get_msg_opts, Version);
			MQSERIES_ADD_ASSOC_LONG(get_msg_opts, Options);
			MQSERIES_ADD_ASSOC_LONG(get_msg_opts, WaitInterval);
			MQSERIES_ADD_ASSOC_LONG(get_msg_opts, Signal1);
			MQSERIES_ADD_ASSOC_LONG(get_msg_opts, Signal2);
			MQSERIES_ADD_ASSOC_STRING(get_msg_opts, ResolvedQName);
			// no break intentional
#endif /* MQGMO_VERSION_1 */
	}
}
/* }}} */

void _mqseries_set_mqbo_from_array(zval *array, PMQBO mqbo) /* {{{ */
{
	HashTable *ht = Z_ARRVAL_P(array);
#ifdef ZEND_ENGINE_3
	zval *tmp;
#else
	zval **tmp;
#endif

	switch (mqbo->Version) {
		default:
			MQSERIES_UNSUPPRTED_VERSION(MQBO, mqbo);

#ifdef MQBO_VERSION_1
		case MQBO_VERSION_1:
			MQSERIES_SETOPT_LONG(mqbo, Version);
			MQSERIES_SETOPT_LONG(mqbo, Options);
#endif /* MQBO_VERSION_1 */
	}
}
/* }}} */

#ifdef HAVE_MQSERIESLIB_V7

void _mqseries_set_mqsd_from_array(zval *array, PMQSD sub_desc TSRMLS_DC) /* {{{ */
{
	HashTable *ht = Z_ARRVAL_P(array);
#ifdef ZEND_ENGINE_3
	zval *tmp;
#else
	zval **tmp;
#endif

	MQSERIES_SETOPT_LONG(sub_desc, Version);
	switch (sub_desc->Version) {
		default:
			MQSERIES_UNSUPPRTED_VERSION(MQSD, sub_desc);

#ifdef MQSD_VERSION_1
		case MQSD_VERSION_1:
			MQSERIES_SETOPT_LONG(sub_desc, Options);
			MQSERIES_SETOPT_STRING(sub_desc, ObjectName);
			MQSERIES_SETOPT_STRING(sub_desc, AlternateUserId);
			MQSERIES_SETOPT_RESBYTES(sub_desc, AlternateSecurityId);
			MQSERIES_SETOPT_LONG(sub_desc, SubExpiry);
			MQSERIES_SETOPT_CHARV(sub_desc, ObjectString);
			MQSERIES_SETOPT_CHARV(sub_desc, SubName);
			MQSERIES_SETOPT_CHARV(sub_desc, SubUserData);
			MQSERIES_SETOPT_RESBYTES(sub_desc, SubCorrelId);
			MQSERIES_SETOPT_LONG(sub_desc, PubPriority);
			MQSERIES_SETOPT_RESBYTES(sub_desc, PubAccountingToken);
			MQSERIES_SETOPT_STRING(sub_desc, PubApplIdentityData);
			MQSERIES_SETOPT_CHARV(sub_desc, SelectionString);
			MQSERIES_SETOPT_LONG(sub_desc, SubLevel);
			MQSERIES_SETOPT_CHARV(sub_desc, ResObjectString);
	}
#endif /* MQSD_VERSION_1 */
}
/* }}} */

void _mqseries_set_array_from_mqsd(zval *array, PMQSD sub_desc TSRMLS_DC) /* {{{ */
{
	zval_dtor(array);
	array_init(array);

	switch (sub_desc->Version) {
		default:
			MQSERIES_UNSUPPRTED_VERSION(MQSD, sub_desc);

#ifdef MQSD_VERSION_1
		case MQSD_VERSION_1:
			MQSERIES_ADD_ASSOC_LONG(sub_desc, Version);
			MQSERIES_ADD_ASSOC_LONG(sub_desc, Options);
			MQSERIES_ADD_ASSOC_STRING(sub_desc, ObjectName);
			MQSERIES_ADD_ASSOC_STRING(sub_desc, AlternateUserId);
			MQSERIES_ADD_ASSOC_RESOURCE(sub_desc, AlternateSecurityId);
			MQSERIES_ADD_ASSOC_LONG(sub_desc, SubExpiry);
			MQSERIES_ADD_ASSOC_CHARV(sub_desc, ObjectString);
			MQSERIES_ADD_ASSOC_CHARV(sub_desc, SubName);
			MQSERIES_ADD_ASSOC_CHARV(sub_desc, SubUserData);
			MQSERIES_ADD_ASSOC_RESOURCE(sub_desc, SubCorrelId);
			MQSERIES_ADD_ASSOC_LONG(sub_desc, PubPriority);
			MQSERIES_ADD_ASSOC_RESOURCE(sub_desc, PubAccountingToken);
			MQSERIES_ADD_ASSOC_STRING(sub_desc, PubApplIdentityData);
			MQSERIES_ADD_ASSOC_CHARV(sub_desc, SelectionString);
			MQSERIES_ADD_ASSOC_LONG(sub_desc, SubLevel);
			MQSERIES_ADD_ASSOC_CHARV(sub_desc, ResObjectString);
#endif /* MQSD_VERSION_1 */
	}
}
/* }}} */

void _mqseries_set_mqsts_from_array(zval *array, PMQSTS status) /* {{{ */
{
	HashTable *ht = Z_ARRVAL_P(array);
#ifdef ZEND_ENGINE_3
	zval *tmp;
#else
	zval **tmp;
#endif

	MQSERIES_SETOPT_LONG(status, Version);
	switch (status->Version) {
		default:
			MQSERIES_UNSUPPRTED_VERSION(MQSTS, status);

#ifdef MQSTS_VERSION_2
		case MQSTS_VERSION_2:
			MQSERIES_SETOPT_CHARV(status, ObjectString);
			MQSERIES_SETOPT_CHARV(status, SubName);
			MQSERIES_SETOPT_LONG(status, OpenOptions);
			MQSERIES_SETOPT_LONG(status, SubOptions);
			// no break intentional
#endif /* MQSTS_VERSION_2 */

#ifdef MQSTS_VERSION_1
		case MQSTS_VERSION_1:
			MQSERIES_SETOPT_LONG(status, CompCode);
			MQSERIES_SETOPT_LONG(status, Reason);
			MQSERIES_SETOPT_LONG(status, PutSuccessCount);
			MQSERIES_SETOPT_LONG(status, PutWarningCount);
			MQSERIES_SETOPT_LONG(status, PutFailureCount);
			MQSERIES_SETOPT_LONG(status, ObjectType);
			MQSERIES_SETOPT_STRING(status, ObjectName);
			MQSERIES_SETOPT_STRING(status, ObjectQMgrName);
			MQSERIES_SETOPT_STRING(status, ResolvedObjectName);
			MQSERIES_SETOPT_STRING(status, ResolvedQMgrName);
			// no break intentional
#endif /* MQSTS_VERSION_1 */
	}
}
/* }}} */

void _mqseries_set_array_from_mqsts(zval *array, PMQSTS status) /* {{{ */
{
	zval_dtor(array);
	array_init(array);

	switch (status->Version) {
		default:
			MQSERIES_UNSUPPRTED_VERSION(MQSTS, status);

#ifdef MQSTS_VERSION_2
		case MQSTS_VERSION_2:
			MQSERIES_ADD_ASSOC_CHARV(status, ObjectString);
			MQSERIES_ADD_ASSOC_CHARV(status, SubName);
			MQSERIES_ADD_ASSOC_LONG(status, OpenOptions);
			MQSERIES_ADD_ASSOC_LONG(status, SubOptions);
			// no break intentional
#endif /* MQSTS_VERSION_2 */

#ifdef MQSTS_VERSION_1
		case MQSTS_VERSION_1:
			MQSERIES_ADD_ASSOC_LONG(status, CompCode);
			MQSERIES_ADD_ASSOC_LONG(status, Reason);
			MQSERIES_ADD_ASSOC_LONG(status, PutSuccessCount);
			MQSERIES_ADD_ASSOC_LONG(status, PutWarningCount);
			MQSERIES_ADD_ASSOC_LONG(status, PutFailureCount);
			MQSERIES_ADD_ASSOC_LONG(status, ObjectType);
			MQSERIES_ADD_ASSOC_STRING(status, ObjectName);
			MQSERIES_ADD_ASSOC_STRING(status, ObjectQMgrName);
			MQSERIES_ADD_ASSOC_STRING(status, ResolvedObjectName);
			MQSERIES_ADD_ASSOC_STRING(status, ResolvedQMgrName);
			// no break intentional
#endif /* MQSTS_VERSION_1 */
	}
}
/* }}} */

#endif /* HAVE_MQSERIESLIB_V7 */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
