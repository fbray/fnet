<?php
// $Id$

/**
 * @file
 * Request data for OCR Ease web service.
 *
 */
class OCREaseRequest {

  private $load_data;
  private $screen_data;
  private $email;
  private $version_no;
  private $username;
  private $a_entityid;
  private $contact_no;

  protected $response;
  protected $status;
  protected $error;
  protected $ocr_dpl_date;

  public $address1;
  public $address2;
  public $city;
  public $cntry_code;
  public $key_nm;
  public $name;
  public $state_name;
  public $zip_code;
  public $uid;
  public $entity_type;

  public function __construct() {
    $this->status = 'Unchecked';
    $this->error = FALSE;
    $this->load_data = 'U'; //save person to OCR database for future use.
    $this->screen_data = 'Y'; //return screening data in XML format
    $this->email = variable_get('findit_ocr_email', 'export-screenings@fluke.com');
    $this->version_no = '1';
    $this->username = variable_get('findit_ocr_username', 'flukeweb');
    $this->a_entityid = '1';
    $this->contact_no = '';
  }

  private function toQueryString() {
    $query = '';
    $keys = array(
      'load_data',
      'screen_data',
      'email',
      'version_no',
      'username',
      'address1',
      'address2',
      'city',
      'cntry_code',
      'key_nm',
      'name',
      'state_name',
      'zip_code'
    );
    foreach ($keys as $key) {
      if (strlen($this->$key) > 0) {
        if ($key == 'name') {
          $value = $this->name;
          $value = preg_replace('/[&"+\/?%#]/', '_', $value);
        }
        elseif ($key == 'cntry_code') {
          if ($this->cntry_code == 'uk') {
            $value = 'gb';
          }
          else {
            $value = $this->$key;
          }
        }
        else {
          $value = $this->$key;
        }
        if ($key == 'email') {
          $query .= $key . '=' . substr(rawurlencode(utf8_encode($value)), 0, 198) . '&';
        }
        else {
          $query .= $key . '=' . substr(rawurlencode(utf8_encode($value)), 0, 48) . '&';
        }
      }
    }
    $query = rtrim($query, '&');
    return $query;
  }

  public function approve() {
    $log_record = new OCRLog($this->uid, $this->entity_type);
    if ($log_record->ocr_dpl_date == date('Y-m-d')) {
      // we have already checked this person today so if they are approved we don't have to check again.
      $this->status = $log_record->ocr_status;
      $this->ocr_dpl_date = $log_record->ocr_dpl_date;
      if ((strtolower($this->status) == 'approved') || (strtolower($this->status) == 'overridden')) {
        return TRUE;
      }
    }
    $this->response = NULL;
    $this->error = FALSE;

    $request_url = variable_get('findit_ocr_url', 'http://easehost.ocr-inc.com/dpss/resultHostedService.ocr');
    $request_url .= '?' . $this->toQueryString();
    $request_method = 'GET';
    $request_timeout = 60;
    // Send the request.
    $result = drupal_http_request($request_url, array(
      'method' => $request_method,
      'timeout' => $request_timeout,
    ));
    if (($result->code != '200') || empty($result->data)) {
      return FALSE;
    }
    else {
      $this->response = $this->parse_xml(trim($result->data));
      $each_given_name = $this->response->EachGivenName;
      $error = isset($this->response->HostedError) ? $this->response->HostedError : NULL;
      $this->status = $each_given_name->Status;
      $this->ocr_dpl_date = $each_given_name->DplDate;
      if (!empty($error)) {
        $this->error = $error->Errortag;
        $this->status = 'error';
        return FALSE;
      }
      if ($each_given_name->TotalHits == 0) {
        return TRUE;
      }
      else {
        return FALSE;
      }
    }
  }

  public function ocr_dpl_date() {
    return $this->ocr_dpl_date;
  }

  public function response() {
    return $this->response;
  }

  public function status() {
    return $this->status;
  }

  public function error() {
    return $this->error;
  }

  public function set_compliance_email($email) {
    $this->email = $email;
  }

  private function parse_xml($xml) {
    $tidy_options = array(
      'input-xml' => TRUE,
      'output-xml' => TRUE,
      'indent' => TRUE,
      'wrap' => TRUE,
      "char-encoding" => TRUE,
      "wrap" => 0
    );
    $xml = drupal_convert_to_utf8(trim($xml), 'ISO-8859-1');
    $xml = preg_replace('/[\r\n\t]/', '', $xml);
    $tidy = new tidy();
    $tidy->parseString($xml, $tidy_options);
    $tidy->cleanRepair();
    $xml = $tidy->value;
    $doc = simplexml_load_string($xml);
    $doc = json_decode(json_encode($doc));
    return $doc;
  }
}
