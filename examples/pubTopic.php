<?php

$cfg = array();
$cfg['ESB_ADDRESS']                = '';
$cfg['ESB_CHANNEL']                = '';
$cfg['ESB_QUEUE_MANAGER']          = '';
$cfg['ESB_QUEUE_NAME']             = '';
$cfg['ESB_TOPIC_STRING']           = '';


$connectionOptions = array(
    'Version' => MQSERIES_MQCNO_VERSION_2,
    'Options' => MQSERIES_MQCNO_STANDARD_BINDING | 64,
    'MQCD' => array(
        'ChannelName' => $cfg['ESB_CHANNEL'],
        'ConnectionName' => $cfg['ESB_ADDRESS'],
        'TransportType' => MQSERIES_MQXPT_TCP
    )
);

mqseries_connx($cfg['ESB_QUEUE_MANAGER'], $connectionOptions, $connection, $completionCode, $reason);
if ($completionCode !== MQSERIES_MQCC_OK) {
    die("Connx CompCode : {$completionCode} Reason : {$reason} Text : " . mqseries_strerror($reason));
}

$objDesc = array(
    'Version' => MQSERIES_MQOD_VERSION_4,
    'ObjectType' => MQSERIES_MQOT_TOPIC,
//    'ObjectName' => $cfg['ESB_QUEUE_NAME'],
    'ObjectString' => $cfg['ESB_TOPIC_STRING'],
);
mqseries_open($connection, $objDesc, MQSERIES_MQOO_OUTPUT | MQSERIES_MQOO_FAIL_IF_QUIESCING, $queue, $completionCode, $reason);
if ($completionCode !== MQSERIES_MQCC_OK) {
    die("Connx CompCode : {$completionCode} Reason : {$reason} Text : " . mqseries_strerror($reason));
}
var_dump($objDesc);

$md = array(
    'Version' => MQSERIES_MQMD_VERSION_2,
    'Format' => MQSERIES_MQFMT_STRING,
    'CodedCharSetId' => 1208,
);

$pmo = array(
    'Options' => MQSERIES_MQPMO_FAIL_IF_QUIESCING
);
mqseries_put($connection, $queue, $md, $pmo, 'Hello world', $completionCode, $reason);
if ($completionCode !== MQSERIES_MQCC_OK) {
    die("Connx CompCode : {$completionCode} Reason : {$reason} Text : " . mqseries_strerror($reason));
}

mqseries_close($connection, $queue, MQSERIES_MQCO_NONE, $completionCode, $reason);
if ($completionCode !== MQSERIES_MQCC_OK) {
    die("Connx CompCode : {$completionCode} Reason : {$reason} Text : " . mqseries_strerror($reason));
}

mqseries_disc($connection, $completionCode, $reason);
if ($completionCode !== MQSERIES_MQCC_OK) {
    die("Connx CompCode : {$completionCode} Reason : {$reason} Text : " . mqseries_strerror($reason));
}

die('FIN');
