<?php

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
		'MQCD' => array('ChannelName' => 'D800MQ.CLIENT',
				'ConnectionName' => 'localhost',
				'TransportType' => MQSERIES_MQXPT_TCP)
				);

mqseries_connx('D800MQ',
		&$mqcno,
		&$conn,
		&$comp_code,
		&$reason);
		
/*
if ($comp_code !== MQSERIES_MQCC_OK) {		
	printf("CompCode:%d Reason:%d Text:%s<br>\n", $comp_code, $reason, mqseries_strerror($reason));
	exit;
}


echo "done.<br>";
*/
?>