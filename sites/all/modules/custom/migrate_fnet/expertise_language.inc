<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 4/2/18
 * Time: 10:45 AM
 */

/*
 *  Expertise Migration Class
*/
class FNETExpertiseLanguageMigration extends FNETNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

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
    $this->addFieldMapping('field_expertise_related_content', 'field_related_content');
    $this->addFieldMapping('field_expertise_related_content:language', 'field_related_content:language');
    $this->addFieldMapping('field_expertise_related_content:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_language_region_exp', 'field_language_region_exp');

    // Entity References
    $this->addFieldMapping('field_expertise', 'field_expertise')
    ->sourceMigration('Expertise');
  }

  /**
   * Implementation of prepareRow().
   *
   * @param $row
   * @return bool
   */
  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Check the various fields. Remove the hard URLs.
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