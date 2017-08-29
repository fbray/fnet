<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/16/17
 * Time: 4:23 PM
 */

/*
 *  Award Migration Class
*/
class FNETAwardMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity');

    // Individual Fields
    $this->addFieldMapping('field_intro', 'field_award_intro'); // Long text
    $this->addFieldMapping('field_intro:format', 'field_award_intro:format'); // Long text
    $this->addFieldMapping('field_intro:language', 'field_award_intro:language')
      ->defaultValue(LANGUAGE_NONE); // Long text

    $this->addFieldMapping('field_external_url', 'field_award_link'); // Link
    $this->addFieldMapping('field_external_url:title', 'field_award_link:title');
    $this->addFieldMapping('field_external_url:attributes', 'field_award_link:attributes');
    $this->addFieldMapping('field_external_url:language', 'field_award_link:language')
      ->defaultValue(NULL);

    // Date fields
    $this->addFieldMapping('field_award_date', 'field_award_date'); // Date
    $timezone = variable_get('date_default_timezone', '');
    $this->addFieldMapping('field_award_date:timezone')
      ->defaultValue($timezone);
    $this->addFieldMapping('field_award_date:rrule')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_award_date:to')
      ->defaultValue(NULL);

    // Convert this one to use the Weight module.
    $this->addFieldMapping('weight', 'field_award_sort');

    // Internationalization
    // We're going to keep this for now.
    $this->addFieldMapping('field_language_region', 'field_award_langreg'); //
  }
}