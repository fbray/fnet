<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/26/17
 * Time: 2:05 PM
 */

/*
 *  Microsite Page Migration Class
*/
class FNETMicrositePageMigration extends FNETNode7Migration {
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
    $this->addFieldMapping(NULL, 'field_removenav');

    // Individual Fields
    $this->addFieldMapping('body:language', 'body:language')
      ->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('field_intro', 'field_ms_page_intro_content');
    $this->addFieldMapping('field_intro:format', 'field_ms_page_intro_content:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_background_color', 'field_ms_page_bg_color');
    $this->addFieldMapping('field_tracking_code', 'field_microsite_page_adtracker');
    $this->addFieldMapping('field_tracking_code:format', 'field_microsite_page_adtracker:format')
      ->defaultValue('full_html');

    // Image field
    $this->addFieldMapping('field_background_image', 'field_ms_page_bg_image')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_background_image:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_background_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_background_image:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_background_image:title')
      ->defaultValue(NULL);

    // Entity References
    $this->addFieldMapping('field_microsite', 'taxonomy_vocabulary_18')
      ->sourceMigration('Microsites');
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

  protected function stripDomain($string) {
    $domains = ['http://www.flukenetworks.com/', 'https://www.flukenetworks.com/', 'http://flukenetworks.com/', 'https://flukenetworks.com/'];
    $stripped = str_ireplace($domains, '/', $string);
    return $stripped;
  }
}