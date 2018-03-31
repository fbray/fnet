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
class FNETAwardMigration extends FNETNode7Migration {
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
    $this->addFieldMapping('field_intro', 'field_award_intro'); // Long text
    $this->addFieldMapping('field_intro:format', 'field_award_intro:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_intro:language', 'field_award_intro:language')
      ->defaultValue(LANGUAGE_NONE); // Long text

    // Link
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

  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $row->body = $this->stripDomain($row->body);
    $row->body = str_ireplace('/flukenetworks.com/files', '/default/files', $row->body);
    $row->body = str_ireplace('/flukenetworks.com/theme', '/all/theme', $row->body);
  }

  protected function stripDomain($string) {
    $domains = ['http://www.flukenetworks.com/', 'https://www.flukenetworks.com/', 'http://flukenetworks.com/', 'https://flukenetworks.com/'];
    $stripped = str_ireplace($domains, '/', $string);
    return $stripped;
  }

}