<?php
if(!extension_loaded('mqseries')) {
	if (preg_match('/windows/i', getenv('OS'))) {
		dl('php_mqseries.dll');
	} else {
		if (!dl('mqseries.so')) exit;
	}
}

$depth = mqGetCurDepth("TESTQ");

function mqGetCurDepth($mqqueue) {
  $int_attr = array();	
	$conn=mqConnect();
  $res = mqOpen($conn, $mqqueue, false, false, true);  
  mqseries_inq($conn,
               $res['obj'],
               1, array(MQSERIES_MQIA_CURRENT_Q_DEPTH),
               1, &$int_attr,
               0, &$char_attr,
               &$comp_code,
               &$reason);
  if ($comp_code != MQSERIES_MQCC_OK) {
    prodLog("mqGetCurDepth", "", "Code: $comp_code, Reason: " . mqseries_strerror($reason));
    return 0;
  }
  mqCloseDiscon($conn, $res['obj']);
 
  return $int_attr[0];
}

function mqConnect() {
   $mqcno = array(
                'StrucId' => MQSERIES_MQCNO_STRUC_ID,
                'Version' => MQSERIES_MQCNO_VERSION_2,
                'Options' => MQSERIES_MQCNO_STANDARD_BINDING,
                'MQCD' => array('ChannelName' => 'D800MQ.CLIENT',
                                'ConnectionName' => 'localhost',
                                'TransportType' => MQSERIES_MQXPT_TCP)
                                );
 
   mqseries_connx('BATCH01', &$mqcno, &$conn, &$comp_code, &$reason);
   if ($comp_code !== MQSERIES_MQCC_OK) {
      prodLog("mqConnect", "", "Code: $comp_code, Reason: " . 
mqseries_strerror($reason));
      return null;
   } else {
      print "handtag finns till BATCH01\n";
   }
   return($conn);
}

function mqOpen($conn, $queue, $write=false, $browse=false, 
$inquire=false) {
   $mqods = array('ObjectName' => $queue, 'ObjectQMgrName' => 'BATCH01');
   $opt = MQSERIES_MQOO_INPUT_AS_Q_DEF | MQSERIES_MQOO_FAIL_IF_QUIESCING;
   if ($write) {
     $opt |= MQSERIES_MQOO_OUTPUT;
   }
   if ($browse) {
     $opt |= MQSERIES_MQOO_BROWSE;
   }
   if ($inquire) {
     $opt |= MQSERIES_MQOO_INQUIRE;
   }
   mqseries_open(
                $conn,
                &$mqods,
                $opt,
                &$obj,
                &$comp_code,
                &$reason);
 
   if ($comp_code !== MQSERIES_MQCC_OK) {
      printf("CompCode1:%d Reason:%d Text:%s<br>\n", $comp_code, 
$reason, mqseries_strerror($reason));
      exit;
   } else {
      print "$queue är öppen\n";
   }
 
   $md =   array(
                'Version' => MQSERIES_MQMD_VERSION_1,
                'Expiry' => MQSERIES_MQEI_UNLIMITED,
                'Report' => MQSERIES_MQRO_NONE,
                'MsgType' => MQSERIES_MQMT_DATAGRAM,
                'Format' => MQSERIES_MQFMT_STRING,
                'Priority' => 1,
                'Persistence' => MQSERIES_MQPER_PERSISTENT);
 
   $res['md'] = $md;
   $res['obj'] = $obj;
 
   return($res);
}

?>