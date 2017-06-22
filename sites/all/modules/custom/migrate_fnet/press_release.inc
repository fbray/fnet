<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/26/17
 * Time: 3:11 PM
 */

/*
 *  Press Release Migration Class
*/
class FNETPressReleaseMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity');

    // Individual Fields
    $this->addFieldMapping('field_language_region', 'field_news_langreg');

    // Date fields
    $this->addFieldMapping('field_release_date', 'field_news_date');
    $timezone = variable_get('date_default_timezone', '');
    $this->addFieldMapping('field_release:timezone')
      ->defaultValue($timezone);
    $this->addFieldMapping('field_release_date:rrule')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_release_date:to')
      ->defaultValue(NULL);
  }
}