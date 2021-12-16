<?php
/**
 * Connect to MQ using authentication.
 * If you specify SSLCipherSpec you need to specify a key repository in MQCSO.
 * For two way ssl, specify CertificateLabel in MQCSO with version >= 5.
 * User/pass auth is used if you use the MSCSP structure.
 * The maximum length of a user name is 1024 bytes, for more information see
 * https://www.ibm.com/docs/en/ibm-mq/9.2?topic=application-user-ids
 * 
 * Tested with php 7.4 and MQ client 9.2 on MQ Server 9.0
 * 
 * Author:  Al Saleh <alayham.saleh@gu.se>
 */

if(!extension_loaded('mqseries')) {
    exit;
}

$config = [
    'host' => 'mqserver.domain.tld',
    'port' => '1234',
    'qmanager' => 'QMNAME',
    'channel' => 'CHANNEL',
    'queue' => 'PHPQUEUE',
    'user' => 'phpuser',
    'pass' => 'phppass',
    'key_repo' => '/var/www/mqkeys/client', // https://www.ibm.com/docs/en/ibm-mq/9.2?topic=mqsco-keyrepository-mqchar256
    'max_message_size' => 104857600, // https://www.ibm.com/docs/en/ibm-mq/9.2?topic=mqcbd-maxmsglength-mqlong
    'cert_label' => 'mykey',  // https://www.ibm.com/docs/en/ibm-mq/9.2?topic=mqsco-certificatelabel-mqchar64
];

$mqcno = [
    'Version' =>  MQSERIES_MQCNO_VERSION_5,
    'Options' => MQSERIES_MQCNO_STANDARD_BINDING,
    'MQCD' =>[
      'Version' => 7,
      'ChannelName' => $config['channel'],
      'ConnectionName' => $config['host'] . '(' . $config['port'] . ')', // https://www.ibm.com/docs/en/ibm-mq/9.2?topic=order-connection-name-conname
      'TransportType' => MQSERIES_MQXPT_TCP,
      'SSLCipherSpec' => 'TLS_RSA_WITH_AES_128_CBC_SHA256', // Set by the server.
      'SSLClientAuth' => MQSERIES_MQSCA_REQUIRED, // https://www.ibm.com/docs/en/ibm-mq/9.2?topic=fields-sslclientauth-mqlong
      'MaxMsgLength' => $config['max_message_size'],
    ],
    'MQCSP' => [
      'Version' => 1,
      'AuthenticationType'=> MQSERIES_MQCSP_AUTH_USER_ID_AND_PWD, 
      'CSPUserId' => $config['user'],
      'CSPPassword' => $config['pass'],
    ],
    'MQSCO' => [                                       // SSL configuration
      'Version' => 5,                                  // Version needs to be >= 5 to support CertificateLabel
      'KeyRepository' => $config['key_repo'],          // https://www.ibm.com/docs/en/ibm-mq/9.2?topic=mqsco-keyrepository-mqchar256
      'CertificateLabel' => ''                         // Required for two-way SSL, Keep empty for server-side SSL.
    ],
];

printf("Connecting ...\n");
mqseries_connx($config['qmanager'], $mqcno, $conn, $comp_code, $reason);
if ($comp_code !== MQSERIES_MQCC_OK) {		
	printf("Connx CompCode:%d Reason:%d Text:%s\n", $comp_code, $reason, mqseries_strerror($reason));
}
if($conn) {
    printf("Connected, disconnecting ...\n");
    mqseries_disc($conn, $comp_code, $reason);
}
