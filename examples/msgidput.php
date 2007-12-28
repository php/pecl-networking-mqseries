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


echo 'mqseries_connx D800MQ<br>';
$mqcno = array(
		'Version' => MQSERIES_MQCNO_VERSION_2,
		'Options' => MQSERIES_MQCNO_STANDARD_BINDING,
		'MQCD' => array('ChannelName' => 'D800MQ.CLIENT',
				'ConnectionName' => 'localhost',
				'TransportType' => MQSERIES_MQXPT_TCP)
				);

mqseries_connx('D800MQ',
		&$mqcno,
		&$conn,
		&$comp_code,
		&$reason);
if ($comp_code !== MQSERIES_MQCC_OK) {		
	printf("CompCode:%d Reason:%d Text:%s<br>\n", $comp_code, $reason, mqseries_strerror($reason));
	exit;
}
echo 'mqcno<br>';
print_r($mqcno);
echo "<hr><br>";

echo 'mqseries_open sendQ<br>';
$mqods = array('ObjectName' => 'TESTQ', 'ObjectQMgrName' => 'D800MQ');
mqseries_open(
	$conn,
	&$mqods,
	MQSERIES_MQOO_INPUT_AS_Q_DEF | MQSERIES_MQOO_FAIL_IF_QUIESCING | MQSERIES_MQOO_OUTPUT,
	&$obj_snd,
	&$comp_code,
	&$reason);
if ($comp_code !== MQSERIES_MQCC_OK) {
	printf("CompCode:%d Reason:%d Text:%s<br>\n", $comp_code, $reason, mqseries_strerror($reason));
	exit;
}

echo 'mqod send<br>';
print_r($mqods);
echo "<hr><br>";

echo 'mqseries_open receiveQ<br>';
$mqodr = array('ObjectName' => 'RCVQ', 'ObjectQMgrName' => 'D800MQ');

mqseries_open(
	$conn,
	&$mqodr,
	MQSERIES_MQOO_INPUT_AS_Q_DEF | MQSERIES_MQOO_FAIL_IF_QUIESCING | MQSERIES_MQOO_OUTPUT,
	&$obj_rcv,
	&$comp_code,
	&$reason);
if ($comp_code !== MQSERIES_MQCC_OK) {
	printf("CompCode:%d Reason:%d Text:%s<br>\n", $comp_code, $reason, mqseries_strerror($reason));
	exit;
}
echo 'mqod receive<br>';
print_r($mqodr);
echo "<hr><br>";


echo 'mqseries_put<br>';

$md = 	array(
		'Version' => MQSERIES_MQMD_VERSION_1,
		'Expiry' => MQSERIES_MQEI_UNLIMITED,
		'Report' => MQSERIES_MQRO_NONE,
		'MsgType' => MQSERIES_MQMT_DATAGRAM,
		'Format' => MQSERIES_MQFMT_STRING,
		'Priority' => 1,
		'Persistence' => MQSERIES_MQPER_PERSISTENT,
		'ReplyToQ' => 'RCVQ',
		'MsgId' => 'MyGeneratedId');
$pmo = 	array();	
mqseries_put(
	$conn, 
	$obj_snd,
	&$md,
	&$pmo,
	'Ping',
	&$comp_code,
	&$reason);
	
if ($comp_code !== MQSERIES_MQCC_OK) {
	printf("CompCode:%d Reason:%d Text:%s<br>\n", $comp_code, $reason, mqseries_strerror($reason));
}
echo 'mqmd put<br>';
print_r($md);
echo "<hr><br>";
echo 'mqpmo put<br>';
print_r($pmo);
echo "<hr><br>";

echo 'mqseries_get<br>';
$mdg = array("CorrelId" => $md["MsgId"]);
$gmo = 	array('Options' => MQSERIES_MQGMO_FAIL_IF_QUIESCING | MQSERIES_MQGMO_WAIT | MQSERIES_MQGMO_CONVERT,
	      'WaitInterval' => 3000); 

mqseries_get(
	$conn, $obj_rcv,
	&$mdg,
	&$gmo,
	255,
	&$msg,
	&$data_length,
	&$comp_code,
	&$reason);
	
if ($comp_code !== MQSERIES_MQCC_OK) {
	printf("CompCode:%d Reason:%d Text:%s<br>", $comp_code, $reason, mqseries_strerror($reason));
}
echo 'mqmd get<br>';
print_r($mdg);
echo "<hr><br>";
echo 'mqgmo<br>';
print_r($gmo);
echo "<hr><br>";

echo "received=".$msg."<br>";

echo 'mqseries_close<br>';
mqseries_close($conn, $obj_snd, MQSERIES_MQCO_NONE, &$comp_code, &$reason);
if ($comp_code !== MQSERIES_MQCC_OK) {
	printf("CompCode:%d Reason:%d Text:%s<br>\n", $comp_code, $reason, mqseries_strerror($reason));
}
mqseries_close($conn, $obj_rcv, MQSERIES_MQCO_NONE, &$comp_code, &$reason);
if ($comp_code !== MQSERIES_MQCC_OK) {
	printf("CompCode:%d Reason:%d Text:%s<br>\n", $comp_code, $reason, mqseries_strerror($reason));
}
echo 'mqseries_disc<br>';
mqseries_disc($conn, &$comp_code, &$reason);
if ($comp_code !== MQSERIES_MQCC_OK) {
	printf("CompCode:%d Reason:%d Text:%s<br>\n", $comp_code, $reason, mqseries_strerror($reason));
}

?>
