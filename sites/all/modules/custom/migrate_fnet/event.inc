<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/18/17
 * Time: 1:43 PM
 */

/*
 *  Event Migration Class
*/
class FNETEventMigration extends FNETNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Path Alias
    $this->addFieldMapping('path', 'path');

    // Disable Pathauto for now.
    $this->addFieldMapping('pathauto')->defaultValue(0);

    // Redirects
    $this->addFieldMapping('migrate_redirects', 'path');

    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity')
      ->description(t('No longer necessary as NetScout split is complete.'))
      ->issueGroup(t('DNM'));

    // Individual Fields
    $this->addFieldMapping('body:language', 'body:language');
    $this->addFieldMapping('field_intro', 'field_event_intro');
    $this->addFieldMapping('field_intro:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_intro:language', 'language')
      ->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('weight', 'field_event_priority'); // Move to Weight
    $this->addFieldMapping('field_tracking_code', 'field_event_adtracker');
    $this->addFieldMapping('field_tracking_code:format', 'field_event_adtracker:format')
      ->defaultValue('full_html');;

    // Link fields
    $this->addFieldMapping('field_workshop_reglink', 'field_workshop_link');
    $this->addFieldMapping('field_workshop_reglink:title', 'field_workshop_link:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_workshop_reglink:attributes', 'field_workshop_link:attributes');
    $this->addFieldMapping('field_workshop_reglink:language', 'field_workshop_link:language')
      ->defaultValue(LANGUAGE_NONE);

    // Date fields
    $this->addFieldMapping('field_event_date', 'field_event_date');
    $this->addFieldMapping('field_event_date:timezone', 'field_event_date:timezone');
    $this->addFieldMapping('field_event_date:rrule', 'field_event_date:rrule');
    $this->addFieldMapping('field_event_date:to', 'field_event_date:to');


    // Entity References
    $this->addFieldMapping('field_event_types', 'taxonomy_vocabulary_10')
      ->sourceMigration('EventTypes');
    $this->addFieldMapping('field_product_category', 'field_workshop_industry')
      ->sourceMigration('ProductCategory')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_related_products', 'field_workshop_product')
      ->sourceMigration('ProductDisplay')
      ->defaultValue(NULL);

    // Internationalization
    $this->addFieldMapping('field_language_region', 'field_event_langreg');
  }

  /**
   * Implementation of prepareRow()
   *
   * @param $row
   * @return bool
   */
  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Set the sort order field to accomodate the weight field.
    if (!is_null($row->field_event_priority)) {
      $row->field_event_priority = $row->field_event_priority[0];
    }

    $row->body = $this->stripDomain($row->body);
    $row->body = str_ireplace('/flukenetworks.com/files', '/default/files', $row->body);
    $row->body = str_ireplace('/flukenetworks.com/theme', '/all/theme', $row->body);
  }

  /**
   * Remove the hard-coded Fluke Networks domain from a field.
   *
   * @param $string
   * @return mixed
   */
  protected function stripDomain($string) {
    $domains = ['http://www.flukenetworks.com/', 'https://www.flukenetworks.com/', 'http://flukenetworks.com/', 'https://flukenetworks.com/'];
    $stripped = str_ireplace($domains, '/', $string);
    return $stripped;
  }

}