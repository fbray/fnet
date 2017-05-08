<?php
if (!class_exists("SerialNumber"))
  include drupal_get_path('module', 'am_license')."/includes/SerialNumber.php";

class License {
  var $serialNumber, $serialKey, $macAddress, $serviceStartDate, $serviceEndDate, $productType, $productLicenseCode, $sku, $isEval;
  var $timeStamp, $license, $serialPrefix, $serialPrefixType, $currentSoftwareVersion;

  var $serviceEvalStartDate, $serviceEvalEndDate; // Legacy stuffs

  var $familyName, $licType, $language, $companyId, $lic80bit, $digiSkuVer, $familyMinor, $rdBuildNumber, $buildNumber;
  var $minorBuildNumber, $currentBuildNumber;
  var $productComponent;
  var $filename;



  function License ($input="") {
    $this->serialNumber = $input["serialNumber"];
    $this->serialKey = $input["serialKey"];
    $this->macAddress = $input["macAddress"];
    $this->serviceStartDate = $input["serviceStartDate"];
    $this->serviceEndDate = $input["serviceEndDate"];
    $this->serviceEvalStartDate = $input["serviceEvalStartDate"];
    $this->serviceEvalEndDate = $input["serviceEvalEndDate"];
    $this->productType = $input["productType"]; // license_type
    $this->productLicenseCode = $input["productLicenseCode"];
    //$this->serialPrefixType = $input["serialPrefixType"];
    $this->currentSoftwareVersion = $input["currentSoftwareVersion"];
    if (isset($input["currentBuildNumber"])) $this->currentBuildNumber = $input["currentBuildNumber"];
    //$timeStamp = date ("Y.m.d.H:i:s");
    $snPart = explode ("-", $this->serialNumber);
    $this->sku = $snPart[0];
    $this->serialPrefix = substr($snPart [1], 0, 4);

    $sn = new SerialNumber($this->serialNumber);
    $this->serialPrefixType = $sn->serialPrefixType;

    $this->isEval = $input["isEval"];
    if ($this->sku == "T1250" || $this->sku == "T4015")
      $this->isEval = "1";

    $this->timeStamp = date ("Y.m.d.H:i:s");
    $this->filename = $this->serialNumber . ".lic";

    $row = (object)db_query("SELECT sku, family_name, lic_type, language, company_id, lic_80bit, digi_sku_ver, family_minor, rd_build_number FROM {am_lic_config} WHERE sku=:sku ; ", array(":sku"=>$this->sku))->fetchObject();
    if (isset($row->sku)) {
      $this->familyName = $row->family_name;
      $this->licType = $row->lic_type;
      $this->language = $row->language;
      $this->companyId = $row->company_id;
      $this->lic80bit = $row->lic_80bit;
      $this->digiSkuVer = $row->digi_sku_ver;
      $this->familyMinor = $row->family_minor;
      $this->rdBuildNumber = $row->rd_build_number;
      if (isset($this->rdBuildNumber) && ($this->serialPrefixType == "resAndDev" || $this->serialPrefixType == "beta")) {
        $this->buildNumber = $this->rdBuildNumber;
      } else {
        $this->buildNumberLookup($this->familyName, $this->serviceEndDate);
      }
    }
    if (! $this->currentBuildNumber) $this->currentBuildNumber = $this->buildNumber;
    // AME Specific
    if (isset($input["productComponent"])) {
      parse_str(html_entity_decode($input["productComponent"]), $this->productComponent);
    }
  }

  function addSignature () {
//    $curr_pwd = getcwd();
    $sigPath = drupal_get_path('module', 'am_license')."/licenses/sig";
//    $filePermission = substr(sprintf('%o', fileperms($sigPath)), -4);
//    print $filePermission;

    // chdir(drupal_get_path('module', 'am_license')."/licenses");
    $file_directory_temp = variable_get('file_directory_path', '/tmp');
//    $rootDir = "C:\\xampp\\htdocs\\flukenetworks.localhost\\sites\\local.flukenetworks.com\\files\\" . $this->serialNumber;
    $rootDir = $file_directory_temp ."/". $this->serialNumber;

    $finalFile =   $rootDir . "/" . $this->filename;
    mkdir ($rootDir);
//    print $finalFile;

    $savefile = fopen ($finalFile, "w");
    fwrite ($savefile, $this->license);
    fclose ($savefile);
    chmod ($finalFile, 0777);
    exec ("$sigPath $finalFile");
//    exec ("./sig $finalFile");
    `unix2dos $finalFile`;
    $savefile = fopen ($finalFile, "r");
    $this->license = "";
    $sigStampFlag = false;
    $sigStamp = "";
    while (!feof ($savefile)) {
      $buffer = fgets($savefile, 4096);
      $this->license .= $buffer;

      if ($sigStampFlag) {
        $sigStamp .= $buffer;
      } else if (strpos($buffer, 'SIGNATURE')) {
        $sigStampFlag = true;
      }
    }
    if (strlen($sigStamp) == 0) {
      watchdog("am_license", "Legacy license signature stamp is not functioning, please check file permission!", array(), WATCHDOG_CRITICAL);
    }

    fclose ($savefile);
    unlink ($finalFile);
    rmdir ($rootDir);
//     chdir($curr_pwd);
  }

  function addSignature_80bits ($buildNumber = 1) {
//    require ("config/LicSkuVerConfig.php");
    $licServer = "128.181.14.67";   // LICENSE_SERVER_IP; // Old License Server
    $lic = explode ("\n", $this->license);
    foreach ($lic as $val) {
      if (strpos($val, "=")) {
        $licComp = explode("=", $val);
        $lic[$licComp[0]] = $licComp[1];
      }
    }
    $licSku = substr($lic["SERIALNUMBER"],0,5);
    $licVer = $buildNumber;
    $digiSkuVer = (is_numeric($this->digiSkuVer)) ? $this->digiSkuVer:9999999999;
//    echo $licSku . "--" . $licVer . "~~" . $this->digiSkuVer ."==<br>";
    if (isset($licSku) && isset($licVer) && $licVer >= $digiSkuVer) {
      $licServer = "128.181.14.44"; //LICENSE_SERVER_IP_DIGI;
    }
//    echo $licServer; exit;
    $vars = "MfcISAPICommand=FormRequest&LIC=".$this->license;
    # compose HTTP request header
    $header = "POST /AMLicenseIISExt.dll HTTP/1.1\r\n";
    $header .= "Host: ".$licServer."\r\n";
    //		$header .= "Authorization: Basic ".base64_encode("administrator:airmagnet")."\r\n";
    $header .= "Content-Type: application/x-www-form-urlencoded\r\n";
    $header .= "Content-Length: ".strlen($vars)."\r\n";
    $header .= "Connection: close\r\n\r\n";

//    $curr_pwd = getcwd();
//    chdir(LICENSE_DIR);
    //$rootDir = $this->serialNumber->serialNumber;
    $file_directory_temp = variable_get('file_directory_path', '/tmp');
    $rootDir = $file_directory_temp ."/". $this->serialNumber;
    $finalFile = $rootDir . "/" . $this->filename;
    mkdir ($rootDir);
    $savefile = fopen ($finalFile, "w");

    $fp = fsockopen("ssl://".$licServer, 443, $errno, $errstr, 30);
    stream_set_timeout($fp, 30);
    if (!$fp) {
      fwrite ($savefile, $errno ." - ". $errstr);
//		   echo "ERROR: $errno - $errstr<br />\n";
    } else {
      fwrite($fp, $header.$vars);
      sleep(5);
      $start = false;
      while (!feof($fp)) {
        $buf = fread ($fp, 4096);
        if ($start) {
          fwrite ($savefile, $buf);
        } else if (strpos($buf, "Property") > 0) {
          if (strpos($buf, "Property") > 1) $buf = substr($buf, (strpos($buf, "Property")-1));
          fwrite ($savefile, $buf);
          $start = true;
        }
        $buf = "";
      }
    }
    fclose($fp);
    fclose ($savefile);
    chmod ($finalFile, 0777);
    `unix2dos $finalFile`;
    $savefile = fopen ($finalFile, "r");
    $this->license = "";
    while (!feof ($savefile)) {
      $this->license .= fread($savefile, 4096);
    }
    fclose ($savefile);
    unlink ($finalFile);
    rmdir ($rootDir);
//    chdir($curr_pwd);
  }

  /*
  function setSerialNumber ($sn="") {
    if ($sn) {
      $this->serialNumber = new SerialNumber ($sn);
      $this->serialNumber->getFromDatabase ($sn);
      $this->filename = $sn . ".lic";
      $this->isEval = $this->serialNumber->isEval ();
      if ($this->serialNumber->serialNumber) $this->serialNumber->generateKey ();
      $snPart = explode ("-", $sn);
      $this->sku = $snPart[0];
      if ($this->sku == "T1250" || $this->sku == "T4015")
        $this->isEval = true;
    }
  } */

  function generateLicense ($buildNumber="", $userName="") {
    print ("ERROR: Invalid Call of abstract object License.<br>");
//    exit;
  }

  function getLicenseFileComponents ($sku, $sPrefix){
    $licBuf1 = "";
    $licBuf2 = "";
    $result = db_query("SELECT param, value, sort_order FROM {am_lic_file_config} WHERE sku = :sku ORDER BY sort_order ; ", array(':sku'=>$sku));
    foreach ($result as $row) {
      if ($sku == "A4016" && $row->param == "SiteSurveyorUpgradePlanner" && $sPrefix == "0408") continue;
      $licBuf1 .= $row->param ."=". $row->value ."\n";

      if ($row->param != "LICENSES") {
        if ($licBuf2) $licBuf2 .= "\n";
        $licBuf2 .= "[". $row->param ."]\n";
        $licBuf2 .= "LICENSES=". $row->value ."\n";
      }
    }
    if ($licBuf2) $licBuf2 = "\n" . $licBuf2;
    return $licBuf1 . $licBuf2;
  }

  function buildNumberLookup ($familyName, $supportEndDate){
    $row = (object)db_query("SELECT build_number, build_date FROM {am_lic_family_release} WHERE family_name = :familyName AND build_date < :buildDate ORDER BY build_date DESC LIMIT 1 ; ", array(':familyName'=>$familyName, ':buildDate'=>$supportEndDate))->fetchObject();
    if ($row->build_number)
      $this->buildNumber = $row->build_number;
  }

  function minorReleaseLookup ($familyMinor, $supportStartDate, $supportEndDate) {
    $row = (object)db_query("SELECT minor_build, minor_version, minor_filename, build_date FROM {am_lic_minor_release} WHERE family_minor=:familyMinor AND build_date < :buildDate ORDER BY build_date DESC LIMIT 1 ; ", array(":familyMinor"=>$familyMinor, ":buildDate"=>$supportEndDate))->fetchObject();
    if ($row->minor_build) {
      $this->buildNumber = $row->minor_build;
      $minorVersion = $row->minor_version;
      $versionCheckPt = strpos($minorVersion, ".", 2);
      if ($minorVersion && $versionCheckPt) {
        $minorVersionLead = substr($minorVersion, 0, ($versionCheckPt + 1));
        $rowTmp = (object)db_query("SELECT minor_build, minor_filename, build_date FROM {am_lic_minor_release} WHERE family_minor=:familyMinor AND minor_version LIKE :minorVersionLead ORDER BY build_date DESC LIMIT 1 ; ", array(":familyMinor"=>$familyMinor, ":minorVersionLead"=> $minorVersionLead.'%'))->fetchObject();
        if ($rowTmp->minor_build) {
          $this->buildNumber = $rowTmp->minor_build;
        }
      }
    }
  }
}

class MobileLicense extends License {
//  var $productLicenseCode;

  function MobileLicense ($input="") {
    parent::License ($input);
//    $this->productLicenseCode = $plc;
  }

  function generateLicense ($buildNumber="", $userName="") {

//require ("config/licCfgSkuOption.php");

    $this->license = "";
    $this->license .= ("[Property]\n");
    $this->license .= ("SERIALNUMBER=" . $this->serialNumber . "\n");
    $this->license .= ("SERIALKEY=" . $this->serialKey . "\n");
    $this->license .= ("TIMESTAMP=" . $this->timeStamp . "\n");

    $supportStartDate = str_replace("-", ".", $this->serviceStartDate);
    $supportEndDate =  str_replace("-", ".", $this->serviceEndDate);
    if ($userName == "evallic@airmagnet.com" || $this->serialPrefixType == "eval" || $this->serialPrefixType == "beta" || $this->serialPrefixType == "trainer" ||
        $this->serialPrefixType == "student" || $this->serialPrefixType == "rental") {
      $this->license .= ("STARTDATE=" . $supportStartDate . "\n");
      if ($this->sku == "A4115" && $this->serialPrefix == "0318")
        $supportEndDate =  date("Y.m.d", strtotime('+24 day', strtotime($this->serviceEndDate)));
      else
        $supportEndDate =  date("Y.m.d", strtotime('+1 day',  strtotime($this->serviceEndDate)));
      $this->license .= ("EXPIRATIONDATE=" . $supportEndDate . "\n");

    } else if (($this->isEval || $this->sku == "D1906") && ($this->serialPrefixType != "eval")) {
      if ($this->isEval && $this->serviceEvalStartDate) {
        $supportStartDate = str_replace("-", ".", $this->serviceEvalStartDate);
        $supportEndDate =  date("Y.m.d", strtotime('+1 day', strtotime($this->serviceEvalEndDate)));
      } else
        $supportEndDate =  date("Y.m.d", strtotime('+1 day', strtotime($this->serviceEndDate)));
      $this->license .= ("STARTDATE=" . $supportStartDate . "\n");
      $this->license .= ("EXPIRATIONDATE=" . $supportEndDate . "\n");
    }

    $this->license .= ("HOSTLOCKADDRESS=" . $this->macAddress . "\n");
    //require ("config/licenseSign80Bits.php");
    if ($this->lic80bit == "2" || $this->lic80bit == "4") {
      if (strlen($this->buildNumber)> 3){
        //require ("config/licCfgBuildNumber.php");
        //require ("config/licCfgMinorRelease.php");
        //require ("config/licCfgSkuOption.php");
        if ($this->serialPrefixType == "resAndDev" || $this->serialPrefixType == "beta" ){     //developers license and beta testers RA
          $this->license .= ("VERSIONCONTROL=" . $this->rdBuildNumber . "\n");
          //} elseif(($skuArray[$this->sku] == "AirMedicBase" || strpos($skuArray[$this->sku] ,"B") > -1) && $supportEndDate == $supportStartDate ) {  //Express license with no support.  RA
        } elseif( $supportEndDate == $supportStartDate ) {  //Any license with no support.  RA
          if(! is_null($this->familyMinor)) {
            $this->minorReleaseLookup($this->familyMinor, $this->serviceStartDate, $this->serviceEndDate);
            $this->license .= ("VERSIONCONTROL=" . $this->buildNumber . "\n");
          }
        } else { //production or eval license RA
          if(! is_null($this->buildNumber)) {
            $this->license .= "VERSIONCONTROL=" . ($this->buildNumber + 100) . "\n";
          }
        }
      }
    } else if ($this->lic80bit == "3") {
//  require ("config/licCfgBuildNumber.php");
//  require ("config/licCfgMinorRelease.php");
//  require ("config/licCfgSkuOption.php");
      if ($this->serialPrefixType == "resAndDev" || $this->serialPrefixType == "beta"){
        $this->license .= ("VERSIONCONTROL=" . $this->rdBuildNumber . "\n");
      }elseif($supportEndDate == $supportStartDate ) {
        if(! is_null($this->familyMinor)) {
          $this->minorReleaseLookup($this->familyMinor, $this->serviceStartDate, $this->serviceEndDate);
          $this->license .= ("VERSIONCONTROL=" . $this->buildNumber . "\n");
        }
      } else {
        if(! is_null($this->buildNumber)) {
          $this->license .= "VERSIONCONTROL=" . ($this->buildNumber + 50) . "\n";
        }
      }
    }
//add for language localization 5/13/10  RA.
    if( $this->language && $this->language >= 1 ) { //language other than english  RA
      $this->license .= ("CULTURECODE=" . $this->language . "\n");
    } else {
      $this->license .= ("CULTURECODE=0 \n");
    }
//add comapny ID for China Telcos  1/18/11 RA
    if( $this->companyId && $this->companyId >= 1 ) { //Company ID for China telcos RA
      $this->license .= ("COMPANYID=" . $this->companyId . "\n");
    } else {
      $this->license .= ("COMPANYID=0 \n");
    }

    $this->license .= ("\n");
    $this->license .= ("[".trim($this->productLicenseCode)."]\n");
//$this->license .= ("VERSION=" . getCurrentSoftwareVersionForProduct ($this->product) . "\n");
    $this->license .= ("VERSION=" . $this->currentSoftwareVersion . "\n");

    $this->license .= $this->getLicenseFileComponents($this->sku, $this->serialPrefix);

    // SIGNATURE
    $this->license .= "\n";
    $this->license .= "[SIGNATURE]\n";

    return ($this->license);
  }
}

class EnterpriseLicense extends License {
  var $quickLookup = array (
    "A5501" => "Mothership",
    "A5503" => "Mothership",
    "A5504" => "Mothership",
    "A5505" => "Mothership",
    "A5507" => "Mothership",
    "A5511" => "Mothership",
    "A5601" => "Mothership",
    "A5611" => "Mothership",
    "A5621" => "Mothership",
    "A5705" => "Mothership",
    "A5105" => "Mothership",
    "A5106" => "Mothership", //added BS spectrum sensors
    //	"A5605" => "Mothership", //added new WEP Shield RA
    "DIST-2" => "SensorSW",
    "DIST-3" => "SensorHW",
    "DIST-4" => "ConsoleLT",
    "DIST-5" => "ConsoleHH",
    "DIST-6" => "RemoteUILT",
    "DIST-7" => "RemoteUIHH",
    "DIST-8" => "ReporterDT",
    "DIST-9" => "SpectrumSensor",
    //	"DIST-10" => "AgentSA",
    "DIST-11" => "SensorXR",
    "DIST-12" => "SensorFR",
    "DIST-13" => "SensorCS",
    "A5630" => "AHCSensor",  //added new Automated Health Check (AHC)
    "A5605" => "WEPShield",  //added new WEP Shield RA
    "A5230" => "11nSensor",  //added new 11n Sensor RA
    "A5110" => "11nSensor",  //added new 11n Sensor RA
    "A5115" => "11nSensor",  //added new 11n Sensor RA
    "A5101" => "ConsoleLT",
    "A5301" => "AgentSA",
    "A5305" => "AgentSA",
    "A5311" => "AgentSA",
    "A5312" => "AgentSA",
    "A5315" => "AgentSA",
    "A5321" => "AgentSA",
    "A4020" => "ReporterDT",
    "A4050" => "ReporterDT",
    "A4100" => "ReporterDT",
    "A4250" => "ReporterDT"
  );


  function EnterpriseLicense ($input) {
    parent::License ($input);
  }

  function getLicenseFileComponents ($sku, $sPrefix){
    $licBuf1 = "";
    $licBuf2 = "";
    $result = db_query("SELECT param, value, sort_order FROM {am_lic_file_config} WHERE sku = :sku ORDER BY sort_order ; ", array(':sku'=>$sku));
    foreach ($result as $row) {
      $licBuf1 .= $row->param ."=". $row->value ."\n";

      if ($row->param != "LICENSES") {
        if ($licBuf2) $licBuf2 .= "\n";
        $licBuf2 .= "[". $row->param ."]\n";
        $licBuf2 .= "LICENSES=". $row->value ."\n";
      }
    }
//    if ($licBuf2) $licBuf2 = "\n" . $licBuf2;
    return $licBuf1 ."~~". $licBuf2;
  }

  function generateLicense ($buildNumber="", $userName="") {
    $components = $this->productComponent;
    $skus = array_keys ($components);

    $this->license = "";
    $this->license .= ("[Property]\n");
    $this->license .= ("SERIALNUMBER=" . $this->serialNumber . "\n");
    $this->license .= ("SERIALKEY=" . $this->serialKey . "\n");
    $this->license .= ("TIMESTAMP=" . $this->timeStamp . "\n");

    $a = explode("-" , $this->serialNumber);
    $snPrefix = substr($a [1], 0, 4);
    $snQuantity = substr($a [1], 0, 3);  //added for A5110, 11n sensor qty RA 10/28/09

    $supportStartDate = str_replace("-", ".", $this->serviceStartDate);
    $supportEndDate =  str_replace("-", ".", $this->serviceEndDate);
    if ($userName == "evallic@airmagnet.com" || $this->serialPrefixType == "eval" || $this->serialPrefixType == "beta" || $this->serialPrefixType == "trainer" ||
      $this->serialPrefixType == "student" || $this->serialPrefixType == "rental") {
      $this->license .= ("STARTDATE=" . $supportStartDate . "\n");
      if ($this->sku == "A4115" && $this->serialPrefix == "0318")
        $supportEndDate =  date("Y.m.d", strtotime('+24 day', strtotime($this->serviceEndDate)));
      else
        $supportEndDate =  date("Y.m.d", strtotime('+1 day',  strtotime($this->serviceEndDate)));
      $this->license .= ("EXPIRATIONDATE=" . $supportEndDate . "\n");

    } else if ($this->isEval) {
      if ($this->serviceEvalStartDate && $this->serviceEvalEndDate) {
        $supportStartDate = str_replace("-", ".", $this->serviceEvalStartDate);
        $supportEndDate =  date("Y.m.d", strtotime('+1 day', strtotime($this->serviceEvalEndDate)));
      } else
        $supportEndDate =  date("Y.m.d", strtotime('+1 day', strtotime($this->serviceEndDate)));
      $this->license .= ("STARTDATE=" . $supportStartDate . "\n");
      $this->license .= ("EXPIRATIONDATE=" . $supportEndDate . "\n");
    }

    $this->license .= ("HOSTLOCKADDRESS=" . $this->macAddress . "\n");
    if ($this->lic80bit == "2") {
      if (strlen($this->buildNumber)> 3){
        if ($this->serialPrefixType == "resAndDev" || $this->serialPrefixType == "beta" ){     //developers license and beta testers RA
          $this->license .= ("VERSIONCONTROL=" . $this->rdBuildNumber . "\n");
          //} elseif(($skuArray[$this->sku] == "AirMedicBase" || strpos($skuArray[$this->sku] ,"B") > -1) && $supportEndDate == $supportStartDate ) {  //Express license with no support.  RA
        } elseif( $supportEndDate == $supportStartDate ) {  //Any license with no support.  RA
          if(! is_null($this->familyMinor)) {
            $this->minorReleaseLookup($this->familyMinor, $this->serviceStartDate, $this->serviceEndDate);
            $this->license .= ("VERSIONCONTROL=" . $this->buildNumber . "\n");
          }
        } else { //production or eval license RA
          if(! is_null($this->buildNumber)) {
            $this->license .= "VERSIONCONTROL=" . ($this->buildNumber + 100) . "\n";
          } else {
            $this->license .= "VERSIONCONTROL=" . ($this->buildNumber + 1000) . "\n";
          }
        }
      }
    }
    $this->license .= ("\n");

    $additionLicInfo = $this->getLicenseFileComponents($this->sku, $this->serialPrefix);
    $licPart = preg_split("/~~/", $additionLicInfo);
    ## Mothership first
    $this->license .=  ("[Mothership]\n");
    $mySku = "A5501";
    for ($i = 0; $i < count ($skus); $i++) {
      if ($skus [$i] == "A5501" || $skus [$i] == "A5504" || $skus [$i] == "A5505" || $skus [$i] == "A5503" || $skus [$i] == "A5507" ||
        $skus [$i] == "A5705" || $skus [$i] == "A5105" || $skus [$i] == "A5106" || $skus [$i] == "A5601" || $skus [$i] == "A5611" ||
        $skus [$i] == "A5621" || $skus [$i] == "A5605" || $skus [$i] == "A5230" || $skus [$i] == "A5110" || $skus [$i] == "A5115" ||
        $skus [$i] == "A5630" || $skus [$i] == "A5301" || $skus [$i] == "A5305" || $skus [$i] == "A5311" || $skus [$i] == "A5312" || $skus [$i] == "A5315" || $skus [$i] == "A5321") {
        $mySku = $skus [$i];
        break;
      }
    }
    $this->license .= ("VERSION=" . $this->currentSoftwareVersion . "\n");

    if ($mySku != "A5105" && $mySku != "A5106" && $mySku != "A5605" && $mySku != "A5230" && $mySku != "A5110" && $mySku != "A5115" && $mySku != "A5630" &&
      $mySku != "A5301" &&  $mySku != "A5305" && $mySku != "A5311" && $mySku != "A5312" && $mySku != "A5315" && $mySku != "A5321" ) { // Strip off for Spectrum Sensor lic
      $this->license .=  ("LICENSES=1\n");
    }
    for ($i = 0; $i < count ($skus); $i++) {
      if ($skus [$i] != "A5501" && $skus [$i] != "A5504" && $skus [$i] != "A5505" && $skus [$i] != "A5503" && $skus [$i] != "A5507" &&
        $skus [$i] != "A5705" && $skus [$i] != "A5105" && $skus [$i] != "A5106" && $skus [$i] != "A5511" && $skus [$i] != "A5601" &&
        $skus [$i] != "A5611" && $skus [$i] != "A5621" ) {
        if ($mySku == "A5507") {
          // Small Starter kit
          if ($skus [$i] == "DIST-2" || $skus [$i] == "DIST-3") {
            // $components [$skus [$i]] = 40;
          } else if ($skus[$i] == "DIST-4") {
            $components [$skus [$i]] = 3;
          } else if ($skus[$i] == "DIST-8") {
            $components [$skus [$i]] = 10000;
          }  //added DIST-9 sprectrum sensors to unlimited count 12/6/06 RA
        } else if ($skus [$i] == "DIST-3" || $skus[$i] == "DIST-4" || $skus[$i] == "DIST-8" || $skus[$i] == "DIST-2" || $skus[$i] == "DIST-9") {
          $components [$skus [$i]] = 10000;
          // we're doing this so that users basically get unlimited HW licenses.  The license isn't
          // going to be the limiting factor here, it's the actual possession of the hardware devices.

          //	} else if ($skus [$i] == "DIST-10" ) {  //added for AgentSA testing
          //	    $components [$skus [$i]] = 50;

        } else if ($skus [$i] == "A5630" ) {  //added for AHC
          $components [$skus [$i]] = 10000;
        } else if ($skus [$i] == "A5301" ) {  //added for ssa
          $components [$skus [$i]] = 10;
        } else if ($skus [$i] == "A5305" ) {  //added for ssa
          $components [$skus [$i]] = 50;
        } else if ($skus [$i] == "A5311" ) {  //added for ssa
          $components [$skus [$i]] = 100;
        } else if ($skus [$i] == "A5312" ) {  //added for ssa
          $components [$skus [$i]] = 250;
        } else if ($skus [$i] == "A5315" ) {  //added for ssa
          $components [$skus [$i]] = 500;
        } else if ($skus [$i] == "A5321" ) {  //added for ssa
          $components [$skus [$i]] = 1000;

        } else if ($skus [$i] == "A5605" ) {  //double check this one
          $components [$skus [$i]] = 10000;
        } else if ($skus [$i] == "A5230" ) {
          $components [$skus [$i]] = 100;
        } else if ($skus [$i] == "A5115" ) {  //unlimited 11n sensors  RA
          $components [$skus [$i]] = 10000;

        } else if ($skus [$i] == "A5110" ) {  //specified qty 11n sensors  RA
          //require ("config/licCfgSkuOption.php");
          if( $this->serialPrefixType == "eval" || $this->serialPrefixType == "resAndDev" || $this->serialPrefixType == "beta"
            || $this->serialPrefixType == "demoNFR"  || $this->serialPrefixType == "marketing" ){    //if eval, beta, demo, RD license, then default to 50 sensors  RA
            $components [$skus [$i]] = 10;
          } else {
            $snQuantity = ltrim($snQuantity,"0");
            $components [$skus [$i]] = $snQuantity;
          }
        }
        if ($components [$skus [$i]] > 0) {
          $this->license .=  ($this->quickLookup [$skus [$i]] . "=" . $components [$skus [$i]] . "\n");
        }

      }
    }
    if ($licPart[0]) $this->license .= $licPart[0];
    $this->license .= ("\n");

    // ALL OTHER PRODUCTS
    for ($i = 0; $i < count ($skus); $i++) {
      $mySku = $skus [$i];

      if ($mySku != "A5501" && $mySku != "A5504" && $mySku != "A5505" && $mySku != "A5503" && $mySku != "A5507" &&
        $mySku != "A5705" && $mySku != "A5105" && $mySku != "A5106" && $mySku != "A5511" && $mySku != "A5601" &&
        $mySku != "A5611" && $mySku != "A5621" ) {

        if ($components [$mySku] > 0) {
          $this->license .= ("[" . $this->quickLookup [$mySku] . "]\n");
          switch ($mySku) {
            case "DIST-8":
              $this->license .= ("VERSION=300\n");
              $this->license .= ("LICENSES=" . $components [$mySku] . "\n");
              break;

            default:
              $this->license .= ("LICENSES=" . $components [$mySku] . "\n");
              break;
          }
          $this->license .= ("\n");
        }
      }
    }
    if ($licPart[1]) {
      $this->license .= $licPart[1];
      $this->license .= "\n";
    }

    // $this->license .= ("\n");
    // SIGNATURE
    $this->license .= "[SIGNATURE]\n";
    return ($this->license);
  }
}
?>
