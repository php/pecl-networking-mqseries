<?php
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

if(!extension_loaded('mqseries')) {
	if (preg_match('/windows/i', getenv('OS'))) {
		dl('php_mqseries.dll');
	} else {
		if (!dl('mqseries.so')) exit;
	}
}

$functions = get_extension_funcs('mqseries');
echo "Functions available in the test extension:<br>\n";
foreach($functions as $func) echo $func . "<br>\n";

//              <CHANNEL>/<PROTO>/<HOST(PORT)>
//export MQSERVER=S_donald/TCP/donald

echo 'mqseries_conn ';
$conn = mqseries_conn('QM_donald');
if (is_resource($conn)) {
	echo "mqseries_conn ok $conn\n";
} else {
	printf("CompCode:%d Reason:%d Text:%s\n", $conn['comp_code'], $conn['reason'], mqseries_strerror($conn['reason']));
	exit;
}

echo 'mqseries_open ';
$obj = mqseries_open(
	$conn,
	array('ObjectName' => 'sft.qpf.sam', 'ObjectQMgrName' => 'QM_donald'),
	MQSERIES_MQOO_INPUT_AS_Q_DEF | MQSERIES_MQOO_FAIL_IF_QUIESCING | MQSERIES_MQOO_OUTPUT);
if (is_resource($obj)) {
	echo "mqseries_open ok $obj\n";
} else {
	$err = mqseries_error($conn);
	printf("CompCode:%d Reason:%d Text:%s\n", $err['comp_code'], $err['reason'], mqseries_strerror($err['reason']));
	exit;
}

echo 'mqseries_put ';
$msg = mqseries_put(
	$conn, $obj,
	array(
		'StrucId' => MQSERIES_MQMD_STRUC_ID,
		'Version' => MQSERIES_MQMD_VERSION_1,
		'Expiry' => MQSERIES_MQEI_UNLIMITED,
		'Report' => MQSERIES_MQRO_NONE,
		'MsgType' => MQSERIES_MQMT_DATAGRAM,
		'Format' => MQSERIES_MQFMT_STRING,
		'Priority' => 1,
		'Persistence' => MQSERIES_MQPER_PERSISTENT
	),
	array(
		'Version' => MQSERIES_MQPMO_VERSION_1,
		'Options' => MQSERIES_MQPMO_SYNCPOINT,
		'StrucId' => MQSERIES_MQPMO_STRUC_ID
	),
	'Hallo alter fuchs');
if ($msg === false) {
	$err = mqseries_error($conn);
	printf("CompCode:%d Reason:%d Text:%s\n", $err['comp_code'], $err['reason'], mqseries_strerror($err['reason']));
} else {
	echo "ok\n";
}

echo 'mqseries_get ';
$msg = mqseries_get(
	$conn, $obj,
	array(),
	array(
		'Options' => MQSERIES_MQGMO_FAIL_IF_QUIESCING | MQSERIES_MQGMO_SYNCPOINT | MQSERIES_MQGMO_WAIT,
		'WaitInterval' => MQSERIES_MQWI_UNLIMITED),
	65535);
if ($msg === false) {
	$err = mqseries_error($conn);
	printf("CompCode:%d Reason:%d Text:%s\n", $err['comp_code'], $err['reason'], mqseries_strerror($err['reason']));
} else {
	echo "$msg\n";
}

mqseries_close($obj);
mqseries_disc($conn);

?>
