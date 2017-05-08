<?php
// $Id$
/**
 * @file
 * Describe the purpose of the file here.
 *
 */
class SFDCWebService extends sfdc_FNETDataService {

  public function __construct() {
    $fnet_wsdl = drupal_get_path('module', 'fnet_sfdc') . '/wsdl/' . variable_get('fnet_sfdc_wsdl_version', 'dev') . '/FNETDataService.wsdl';
    parent::__construct($fnet_wsdl);
    $this->login();
  }

  private function login() {
    if (isset($_SESSION['sfdc_session_id'])) {
      $session_id = $_SESSION['sfdc_session_id'];
      $session_start = $_SESSION['sfdc_session_start'];
      $session_age = (time() - $session_start) / 60;
    }
    else {
      $session_age = 0;
      $session_id = NULL;
    }
    if (!isset($_SESSION['sfdc_session_id']) || ($session_age > variable_get('fnet_sfdc_session_lifetime', 60))) {
      $user_name = variable_get('fnet_sfdc_user_id', '');
      $password = variable_get('fnet_sfdc_password', '');
      $token = variable_get('fnet_sfdc_security_token', '');
      $enterprise_wsdl = drupal_get_path('module', 'fnet_sfdc') . '/wsdl/' . variable_get('fnet_sfdc_wsdl_version', 'dev') . '/enterprise.wsdl';

      $sfdc = new SforceEnterpriseClient();
      try {
        $sfdc->createConnection($enterprise_wsdl);
        $sfdc->login($user_name, $password . $token);
        $session_id = $sfdc->getSessionId();
        $location = $sfdc->getLocation();
        $location = parse_url($location);
        $_SESSION['sfdc_soap_location'] = $location['scheme'] . '://' . $location['host'] . '/services/Soap/class/FNETDataService';
        $_SESSION['sfdc_session_id'] = $session_id;
        $_SESSION['sfdc_session_start'] = time();
      } catch (Exception $e) {
        unset($_SESSION['sfdc_session_id']);
        unset($_SESSION['sfdc_session_start']);
        watchdog('fnet_sfdc', $e->getMessage(), array(), WATCHDOG_ERROR);
      }
    }
    if (isset($session_id)) {
      $webservice_name = 'FNETDataService';
      $webservice_namespace = 'http://soap.sforce.com/schemas/class/' . $webservice_name;
      $header = new SoapHeader($webservice_namespace, "SessionHeader", array("sessionId" => $session_id));
      $this->soapClient->__setSoapHeaders(array($header));
      $location = $_SESSION['sfdc_soap_location'];
      $this->soapClient->__setLocation($location);
    }
  }
}