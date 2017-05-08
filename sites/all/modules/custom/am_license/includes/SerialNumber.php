<?php

class SerialNumber {
  var $sku, $serialPrefix, $serialNumber, $serialKey, $macAddress, $activationDate;
  var $familyName, $licType, $language, $companyId, $familyMinor, $serialPrefixType;
  var $skuLicenseTypeArray = array();

  function SerialNumber ($sn = null) {
    if ($sn) {
      $this->serialNumber = $sn;
      $snPart = explode ("-", $this->serialNumber);
      $this->sku = $snPart[0];
      $this->serialPrefix = substr($snPart [1], 0, 4);
      $this->getSerialPrefixType();
    }
  }

  function getSerialPrefixType () {
    $pre = array();
    $pre["0508"] = "marketing";   //choice "internal", "resAndDev", and "marketing" "eval",
    $pre["0518"] = "trainer";
    $pre["0550"] = "student";
    $pre["0551"] = "student";
    $pre["0552"] = "student";
    $pre["0553"] = "student";
    $pre["0554"] = "student";
    $pre["0555"] = "student";
    $pre["0556"] = "student";
    $pre["0557"] = "student";
    $pre["0558"] = "student";
    $pre["0559"] = "student";
    $pre["0560"] = "student";
    $pre["0561"] = "student";
    $pre["0562"] = "student";
    $pre["0563"] = "student";
    $pre["0564"] = "student";
    $pre["0565"] = "student";
    $pre["0566"] = "student";
    $pre["0567"] = "student";
    $pre["0568"] = "student";
    $pre["0569"] = "student";

    $pre["0708"] = "resAndDev";   // both will exclude S/N from auto quotes.
    $pre["0908"] = "demoNFR";     //Kevin Chung's old assignment
    $pre["0918"] = "demoNFR";     //new NFR for Su-Ling to ship

    $pre["0208"] = "eval";        //For ProductActivation.php, will set the order status and eval times
    $pre["0218"] = "eval";
    $pre["0228"] = "eval";
    $pre["0238"] = "eval";
    $pre["0248"] = "eval";
    $pre["0258"] = "eval";
    $pre["0268"] = "eval";
    $pre["0278"] = "eval";
    $pre["0288"] = "eval";
    $pre["0290"] = "eval";

    $pre["0108"] = "beta";
    $pre["0118"] = "beta";
    $pre["0128"] = "beta";
    $pre["0138"] = "beta";
    $pre["0148"] = "beta";
    $pre["0158"] = "beta";
    $pre["0168"] = "beta";
    $pre["0178"] = "beta";
    $pre["0188"] = "beta";
    $pre["0198"] = "beta";

    $pre["0318"] = "rental";    //7 day rental  11/16/07  RA

    $pre["0408"] = "prodInclSupport";  //used for all AirMagnet shipped product before 11/9/09 RA.

    $pre["0448"] = "AcerBundle";    //components of Acer bundle with Dlink adapter  6/9/09  RA
    $pre["0458"] = "AcerBundle";    //components of Acer bundle with Ubiquity adapter  6/9/09  RA
    $pre["0428"] = "prodNoSupport";   //added for all products no support Fluke Model effective 11/1/09.  RA
    $pre["0438"] = "prodNoSupport";   //added for all products Optiview bundles no support Fluke Model effective 11/1/09.  RA
    $pre["0468"] = "INABundle";  //added for FNET INA bundle  11/20/09 RA
    $pre["0478"] = "prodNoSupport";   //added for contiuation of 0428 as it reaches 9999, TH 02/26/14

    $pre["0418"] = "RuckusOEM";  //added for Ruckus Planner OEM RA
    $pre["0419"] = "RuckusOEM";  //added for Ruckus Planner OEM RA
    $pre["0420"] = "DlinkOEM";  //added for Dlink Planner OEM RA
    $pre["0421"] = "CiscoOEM";  //added for Cisco Planner OEM RA
    $pre["0422"] = "SonicOEM";

    // Use on A3001 bulk licenses
    $pre["1500"] = "prodNoSupport";
    $pre["1501"] = "prodNoSupport";
    $pre["1502"] = "prodNoSupport";
    $pre["1503"] = "prodNoSupport";
    $pre["1504"] = "prodNoSupport";
    $pre["1505"] = "prodNoSupport";
    $pre["1506"] = "prodNoSupport";
    $pre["1507"] = "prodNoSupport";
    $pre["1508"] = "prodNoSupport";
    $pre["1509"] = "prodNoSupport";
    $pre["1510"] = "prodNoSupport";
    $pre["1511"] = "prodNoSupport";
    $pre["1512"] = "prodNoSupport";
    $pre["1513"] = "prodNoSupport";
    $pre["1514"] = "prodNoSupport";
    $pre["1515"] = "prodNoSupport";
    $pre["1516"] = "prodNoSupport";
    $pre["1517"] = "prodNoSupport";
    $pre["1518"] = "prodNoSupport";
    $pre["1519"] = "prodNoSupport";
    $pre["1520"] = "prodNoSupport";
    $pre["1521"] = "prodNoSupport";
    $pre["1522"] = "prodNoSupport";
    $pre["1523"] = "prodNoSupport";
    $pre["1524"] = "prodNoSupport";
    $pre["1525"] = "prodNoSupport";
    $pre["1526"] = "prodNoSupport";
    $pre["1527"] = "prodNoSupport";
    $pre["1528"] = "prodNoSupport";
    $pre["1529"] = "prodNoSupport";
    $pre["1530"] = "prodNoSupport";
    $pre["1531"] = "prodNoSupport";
    $pre["1532"] = "prodNoSupport";
    $pre["1533"] = "prodNoSupport";
    $pre["1534"] = "prodNoSupport";
    $pre["1535"] = "prodNoSupport";
    $pre["1536"] = "prodNoSupport";
    $pre["1537"] = "prodNoSupport";
    $pre["1538"] = "prodNoSupport";
    $pre["1539"] = "prodNoSupport";
    $pre["1540"] = "prodNoSupport";
    $pre["1541"] = "prodNoSupport";
    $pre["1542"] = "prodNoSupport";
    $pre["1543"] = "prodNoSupport";
    $pre["1544"] = "prodNoSupport";
    $pre["1545"] = "prodNoSupport";
    $pre["1546"] = "prodNoSupport";
    $pre["1547"] = "prodNoSupport";
    $pre["1548"] = "prodNoSupport";
    $pre["1549"] = "prodNoSupport";
    $pre["1550"] = "prodNoSupport";
    $pre["1551"] = "prodNoSupport";
    $pre["1552"] = "prodNoSupport";
    $pre["1553"] = "prodNoSupport";
    $pre["1554"] = "prodNoSupport";
    $pre["1555"] = "prodNoSupport";
    $pre["1556"] = "prodNoSupport";
    $pre["1557"] = "prodNoSupport";
    $pre["1558"] = "prodNoSupport";
    $pre["1559"] = "prodNoSupport";
    $pre["1560"] = "prodNoSupport";
    $pre["1561"] = "prodNoSupport";
    $pre["1562"] = "prodNoSupport";
    $pre["1563"] = "prodNoSupport";
    $pre["1564"] = "prodNoSupport";
    $pre["1565"] = "prodNoSupport";
    $pre["1566"] = "prodNoSupport";
    $pre["1567"] = "prodNoSupport";
    $pre["1568"] = "prodNoSupport";
    $pre["1569"] = "prodNoSupport";
    $pre["1570"] = "prodNoSupport";
    $pre["1571"] = "prodNoSupport";
    $pre["1572"] = "prodNoSupport";
    $pre["1573"] = "prodNoSupport";
    $pre["1574"] = "prodNoSupport";
    $pre["1575"] = "prodNoSupport";
    $pre["1576"] = "prodNoSupport";
    $pre["1577"] = "prodNoSupport";
    $pre["1578"] = "prodNoSupport";
    $pre["1579"] = "prodNoSupport";
    $pre["1580"] = "prodNoSupport";
    $pre["1581"] = "prodNoSupport";
    $pre["1582"] = "prodNoSupport";
    $pre["1583"] = "prodNoSupport";
    $pre["1584"] = "prodNoSupport";
    $pre["1585"] = "prodNoSupport";
    $pre["1586"] = "prodNoSupport";
    $pre["1587"] = "prodNoSupport";
    $pre["1588"] = "prodNoSupport";
    $pre["1589"] = "prodNoSupport";
    $pre["1590"] = "prodNoSupport";
    $pre["1591"] = "prodNoSupport";
    $pre["1592"] = "prodNoSupport";
    $pre["1593"] = "prodNoSupport";
    $pre["1594"] = "prodNoSupport";
    $pre["1595"] = "prodNoSupport";
    $pre["1596"] = "prodNoSupport";
    $pre["1597"] = "prodNoSupport";
    $pre["1598"] = "prodNoSupport";
    $pre["1599"] = "prodNoSupport";
    $this->serialPrefixType = $pre[$this->serialPrefix];
  }

  function getSerialInfo () {
    $row = (object)db_query("SELECT sku, family_name, lic_type, language, company_id, lic_80bit, digi_sku_ver, family_minor, rd_build_number FROM {am_lic_config} WHERE sku=:sku LIMIT 1", array(':sku' => $this->sku))->fetchObject();

    if (isset($row->sku)) {
      $this->familyName = $row->family_name;
      $this->licType = $row->lic_type;
      $this->language = $row->language;
      $this->companyId = $row->company_id;
      $this->familyMinor = $row->family_minor;
    }
  }

  function getSkuLicenseTypeArray () { $i = 0;
    $result = db_query("SELECT sku, lic_type FROM {am_lic_config} ; ");

    //while ($row = db_fetch_array($result)) {
    foreach ($result as $row) {
        //$row = db_fetch_array($result);
      $this->skuLicenseTypeArray[$row->sku] = $row->lic_type;

      //print $i++ .") ".$row->sku . "=". $row->lic_type."<br>";
    }

  }
}
?>