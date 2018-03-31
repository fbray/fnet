<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/26/17
 * Time: 3:10 PM
 */

/*
 *  Page Region Language Migration Class
*/
class FNETPageRegionLanguageMigration extends FNETNode7Migration {
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
    $this->addFieldMapping('field_language_region', 'field_page_reg_lang_lng');
    $this->addFieldMapping('field_tracking_code', 'field_page_adtracker');

    // Entity References
    $this->addFieldMapping('field_page_region', 'field_page_reg_lang_pagereg')
      ->sourceMigration('PageRegion');
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

    // The language/region thing seems to be problematic with the allowed values.
    // Let's trim it down to just the first five characters.
    $row->field_page_reg_lang_lng[0] = substr($row->field_page_reg_lang_lng[0], 0, 5);
  }

  protected function stripDomain($string) {
    $domains = ['http://www.flukenetworks.com/', 'https://www.flukenetworks.com/', 'http://flukenetworks.com/', 'https://flukenetworks.com/'];
    $stripped = str_ireplace($domains, '/', $string);
    return $stripped;
  }
}