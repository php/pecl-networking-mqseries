<?php
/*
Copyright (c) 2005,Philippe Tjon-A-Hen
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

Author: Philippe Tjon-A-Hen <tjonahen@zonnet.at>
*/

if(!extension_loaded('mqseries')) {
	if (preg_match('/windows/i', getenv('OS'))) {
		dl('php_mqseries.dll');
	} else {
		if (!dl('mqseries.so')) exit;
	}
}


$mqcno = array(
		'Version' => MQSERIES_MQCNO_VERSION_2,
		'Options' => MQSERIES_MQCNO_STANDARD_BINDING,
		'MQCD' => array('ChannelName' => 'MQNX9420.CLIENT',
				'ConnectionName' => 'localhost',
				'TransportType' => MQSERIES_MQXPT_TCP)
				);

mqseries_connx('MQNX9420', $mqcno, $conn, $comp_code,$reason);
if ($comp_code !== MQSERIES_MQCC_OK) {		
	printf("CONNX CompCode:%d Reason:%d Text:%s<br>\n", $comp_code, $reason, mqseries_strerror($reason));
	exit;
}

$mqods = array('ObjectName' => 'TESTQ', 'ObjectQMgrName' => 'MQNX9420');
mqseries_open(
	$conn,
	$mqods,
	MQSERIES_MQOO_INPUT_AS_Q_DEF | MQSERIES_MQOO_FAIL_IF_QUIESCING | MQSERIES_MQOO_OUTPUT,
	$obj,
	$comp_code,
	$reason);
if ($comp_code !== MQSERIES_MQCC_OK) {
	printf("OPEN CompCode:%d Reason:%d Text:%s<br>\n", $comp_code, $reason, mqseries_strerror($reason));
	exit;
}

$mdg = array();
$gmo = array('Options' => MQSERIES_MQGMO_FAIL_IF_QUIESCING | MQSERIES_MQGMO_WAIT, 'WaitInterval' => 3000);
mqseries_get(
	$conn, $obj,
	$mdg,
	$gmo,
	255,
	$msg,
	$data_length,
	$comp_code,
	$reason);
	
if ($comp_code !== MQSERIES_MQCC_OK) {
	printf("GET CompCode:%d Reason:%d Text:%s<br>", $comp_code, $reason, mqseries_strerror($reason));
}

echo $msg."<br>";

mqseries_close($conn, $obj, MQSERIES_MQCO_NONE, $comp_code, $reason);
if ($comp_code !== MQSERIES_MQCC_OK) {
	printf("CLOSE CompCode:%d Reason:%d Text:%s<br>\n", $comp_code, $reason, mqseries_strerror($reason));
}
mqseries_disc($conn, $comp_code, $reason);
if ($comp_code !== MQSERIES_MQCC_OK) {
	printf("DISC CompCode:%d Reason:%d Text:%s<br>\n", $comp_code, $reason, mqseries_strerror($reason));
}

?>