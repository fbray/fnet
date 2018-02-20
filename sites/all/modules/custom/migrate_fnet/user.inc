<?php

/*
 *  User Migration Class
*/
class FNETUserMigration extends DrupalUser7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_user_onyx_id');

    // Individual Fields
    $this->addFieldMapping('field_user_gold_number', 'field_user_gold_number');
    $this->addFieldMapping('field_user_gold_pin', 'field_user_gold_pin');
    $this->addFieldMapping('field_user_job_role', 'field_user_job_role');
    $this->addFieldMapping('field_user_telephone', 'field_user_phone');
    $this->addFieldMapping('field_user_preferred_language', 'field_user_preferred_language');

    // Migrate to using the Address Field module
    // Country
    $this->addFieldMapping('field_address', 'field_user_country')
      ->defaultValue(NULL);
    // State/Province/Region
    $this->addFieldMapping('field_address:administrative_area', 'field_user_province')
      ->defaultValue(NULL);
    // County/District
    $this->addFieldMapping('field_address:sub_administrative_area')
      ->defaultValue(NULL);
    // City
    $this->addFieldMapping('field_address:locality', 'field_user_city')
      ->defaultValue(NULL);
    // Dependent Locality
    $this->addFieldMapping('field_address:dependent_locality')
      ->defaultValue(NULL);
    // Postal Code
    $this->addFieldMapping('field_address:postal_code', 'field_user_postal_code')
      ->defaultValue(NULL);
    // Street Address
    $this->addFieldMapping('field_address:thoroughfare', 'field_user_address_line_1')
      ->defaultValue(NULL);
    // Apartment/Suite/Box Number
    $this->addFieldMapping('field_address:premise')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_address:sub_premise')
      ->defaultValue(NULL);
    // Company Name
    $this->addFieldMapping('field_address:organisation_name', 'field_user_company')
      ->defaultValue(NULL);
    // Full Name
    $this->addFieldMapping('field_address:name_line', 'name')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_address:first_name', 'field_user_first_name')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_address:last_name', 'field_user_last_name')
      ->defaultValue(NULL);
    // Additional Data
    $this->addFieldMapping('field_address:data', 'field_user_address_line_2')
      ->defaultValue(NULL);
  }

  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Data import rules to filter out junk users.
    // First Name and Last Name the same? NOPE.
    if ($row->field_user_first_name[0] == $row->field_user_last_name[0]) {
      return FALSE;
    }
    // User has never logged in? TOAST.
    if ($row->login[0] == 0) {
      return FALSE;
    }

    // Blocked user? BYE, FELICIA.
    if($row->status[0] == 0) {
      return FALSE;
    }

    // If they haven't logged in within the last two years.
    $two_years = strtotime('-2 years', time());
    if ($row->access < $two_years) {
      return FALSE;
    }
  }
}