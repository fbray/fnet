<?php
// $Id$


/**
 * @file
 * Object wrapper for ascii_profile table
 *
 */
class AsciiProfile extends DatabaseRecord {

  public $uid;
  public $email;
  public $first_name;
  public $last_name;
  public $company;
  public $address1;
  public $address2;
  public $city;
  public $province;
  public $country;
  public $postal_code;
  public $changed;

  public function __construct($uid = NULL) {
    $this->table = 'ascii_profile';
    parent::__construct($uid);
  }

  public function write() {
    $this->changed = time();
    parent::write();
  }

}