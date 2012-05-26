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
		philippe Tjon A Hen <tjonahen@zonnet.nl>
		Pierrick Charron <pierrick@php.net>
*/

#ifndef PHP_MQSERIES_H
#define PHP_MQSERIES_H

#include "cmqc.h"                          /* MQI                             */
#include "cmqcfc.h"                        /* PCF                             */
#include "cmqbc.h"                         /* MQAI                            */
#include "cmqxc.h"                         /* MQCD                            */

#define phpext_mqseries_ptr &mqseries_module_entry

#define PHP_MQSERIES_VERSION "0.13.0-dev"

#ifdef PHP_WIN32
#define PHP_MQSERIES_API __declspec(dllexport)
#else
#define PHP_MQSERIES_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

extern zend_module_entry mqseries_module_entry;

typedef struct {
	int id;
	MQHCONN conn;
} mqseries_descriptor;
#define PHP_MQSERIES_DESCRIPTOR_RES_NAME "mqseries_conn"

typedef struct {
	int id;
	MQHOBJ obj;
	MQHCONN *conn;
} mqseries_obj;
#define PHP_MQSERIES_OBJ_RES_NAME "mqseries_obj"

typedef struct {
	int id;
	PMQBYTE bytes;
} mqseries_bytes;
#define PHP_MQSERIES_BYTES_RES_NAME "mqseries_bytes"

PHP_MINIT_FUNCTION(mqseries);
PHP_MSHUTDOWN_FUNCTION(mqseries);
PHP_RINIT_FUNCTION(mqseries);
PHP_RSHUTDOWN_FUNCTION(mqseries);
PHP_MINFO_FUNCTION(mqseries);

PHP_FUNCTION(mqseries_back);
PHP_FUNCTION(mqseries_begin);
PHP_FUNCTION(mqseries_close);
PHP_FUNCTION(mqseries_cmit);
PHP_FUNCTION(mqseries_conn);
PHP_FUNCTION(mqseries_connx);
PHP_FUNCTION(mqseries_disc);
PHP_FUNCTION(mqseries_get);
PHP_FUNCTION(mqseries_inq);
PHP_FUNCTION(mqseries_open);
PHP_FUNCTION(mqseries_put);
PHP_FUNCTION(mqseries_put1);
PHP_FUNCTION(mqseries_set);
PHP_FUNCTION(mqseries_error);
PHP_FUNCTION(mqseries_strerror);

#ifdef ZTS
#define MQSERIES_G(v) TSRMG(mqseries_globals_id, zend_mqseries_globals *, v)
#else
#define MQSERIES_G(v) (mqseries_globals.v)
#endif

#endif	/* PHP_MQSERIES_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * indent-tabs-mode: t
 * End:
 */
