<?php

if(!extension_loaded('mqseries')) {
	if (preg_match('/windows/i', getenv('OS'))) {
		dl('php_mqseries.dll');
	} else {
		if (!dl('mqseries.so')) exit;
	}
}


mqseries_conn('',
		$conn,
		$comp_code,
		$reason);
if ($comp_code !== MQSERIES_MQCC_OK) {		
	printf("conn CompCode:%d Reason:%d Text:%s<br>\n", $comp_code, $reason, mqseries_strerror($reason));
	exit;
}

mqseries_disc($conn, $comp_code, $reason);
if ($comp_code !== MQSERIES_MQCC_OK) {
	printf("disc CompCode:%d Reason:%d Text:%s<br>\n", $comp_code, $reason, mqseries_strerror($reason));
}

echo "done.<br>";
?>