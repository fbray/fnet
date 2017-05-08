<?php
// $Id$

/**
 * @file
 * class description for bedrock user
 *
 */
class fnet_bedrock_user {
  public $id;
  public $email;
  public $password;
  public $first_name;
  public $middle_name;
  public $last_name;
  public $company_name;
  public $company_address1;
  public $company_address2;
  public $city;
  public $state_code;
  public $postal_code;
  public $country_code;
  public $language_code;
  public $phone_number;
  public $time_zone;
  public $time_zone_offset;

  public function __construct($data = NULL) {
    if (is_object($data) || is_array($data)) {
      foreach ($data as $key => $value) {
        $this->$key = $value;
      }
    }
  }
}
