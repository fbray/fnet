<?php
// $Id$


/**
 * @file
 * Class wrapper for the user profile
 *
 */
class UserProfile {

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
  public $phone;
  public $postal_code;
  public $gold_number;
  public $gold_pin;
  public $onyx_id;
  public $timezone;
  public $language;
  public $job_role;
  public $changed;

  public function __construct($uid) {
    global $user;
    $this->uid = $uid;
    if ($user->uid == $uid) {
      $account = $user;
    }
    else {
      $account = user_load($uid);
    }
    $this->email = $account->mail;
    $this->timezone = $account->timezone ? isset($account->timezone) : 'America/Los_Angeles';

    foreach ($this as $field => $value) {
      switch ($field) {
        case 'first_name':
          $this->$field = $account->field_address[LANGUAGE_NONE][0]['first_name'];
          break;
        case 'last_name':
          $this->$field = $account->field_address[LANGUAGE_NONE][0]['last_name'];
          break;
        case 'company':
          $this->$field = $account->field_address[LANGUAGE_NONE][0]['organisation_name'];
          break;
        case 'phone':
          $this->$field = fnet_common_get_field_value('user', $account, 'field_user_telephone');
          break;
        case 'address1':
          $this->$field = $account->field_address[LANGUAGE_NONE][0]['thoroughfare'];
          break;
        case 'address2':
          $this->$field = $account->field_address[LANGUAGE_NONE][0]['premise'];
          break;
        case 'city':
          $this->$field = $account->field_address[LANGUAGE_NONE][0]['locality'];
          break;
        case 'province':
          $this->$field = $account->field_address[LANGUAGE_NONE][0]['administrative_area'];
          break;
        case 'country':
          $this->$field = $account->field_address[LANGUAGE_NONE][0]['country'];
          break;
        case 'postal_code':
          $this->$field = $account->field_address[LANGUAGE_NONE][0]['postal_code'];
          break;
        case 'gold_number':
          $this->$field = fnet_common_get_field_value('user', $account, 'field_user_gold_number');
          break;
        case 'gold_pin':
          $this->$field = fnet_common_get_field_value('user', $account, 'field_user_gold_pin');
          break;
        case 'job_role':
          $this->$field = fnet_common_get_field_value('user', $account, 'field_user_job_role');
          break;
        case 'language':
          $this->$field = fnet_common_get_field_value('user', $account, 'field_user_preferred_language');
          if (empty($this->language)) {
            $this->language = 'en';
          }
          break;
        case 'changed':
          $this->$field = $account->access;
          break;
      }
    }
  }

  public function has_unicode_characters() {
    $unicode = FALSE;
    foreach ($this as $field => $value) {
      if (ascii_profile_contains_unicode($value)) {
        $unicode = TRUE;
      }
    }
    return $unicode;
  }

  public function is_complete() {
    $complete = TRUE;
    $fields = array(
      'first_name',
      'last_name',
      'company',
      'phone',
      'address1',
      'city',
      'country',
      'postal_code',
      'job_role',
    );
    foreach ($fields as $field) {
      $value = $this->$field;
      // the none and not applicable roles were removed from job_role options, but
      // some users have these in their profile. treat them as empty.
      if (($field == 'job_role') && (($value == 'none') || ($value == 'Not Applicable'))) {
        $value = '';
        $this->job_role = $value;
        $account = user_load($this->uid);
        $account->field_user_job_role[LANGUAGE_NONE][0]['value'] = $value;
        user_save($account);
      }
      if (empty($value)) {
        $complete = FALSE;
      }
    }
    return $complete;
  }
}
