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
    // Path Alias
    $this->addFieldMapping('path', 'path');

    // Disable Pathauto for now.
    $this->addFieldMapping('pathauto')->defaultValue(0);

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