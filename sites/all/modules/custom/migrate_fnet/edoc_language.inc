<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/18/17
 * Time: 1:21 PM
 */

/*
 *  eDoc Language Migration Class
 *
 * Note: This will be deprecated and will move to the eDoc content type using
 * internationalization in the future.
*/
class FNETeDocLanguageMigration extends FNETNode7Migration {
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

    // Individual fields
    $this->addFieldMapping('body:language', 'language');
    $this->addFieldMapping('body:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_language_region', 'field_edoc_lang_lng');

    // Entity References
    $this->addFieldMapping('field_edoc', 'field_edoc_lang_edoc')
      ->sourceMigration('eDoc');

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
    // The language/region thing seems to be problematic with the allowed values.
    // Let's trim it down to just the first five characters.
    $row->field_edoc_lang_lng[0] = substr($row->field_edoc_lang_lng[0], 0, 5);

    // Check the various fields. Remove the hard URLs.
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