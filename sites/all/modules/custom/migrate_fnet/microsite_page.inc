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
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity')
      ->description(t('No longer necessary as NetScout split is complete.'))
      ->issueGroup(t('DNM'));
    $this->addFieldMapping(NULL, 'field_removenav');

    // Individual Fields
    $this->addFieldMapping('field_intro', 'field_ms_page_intro_content');
    $this->addFieldMapping('field_intro:format', 'field_ms_page_intro_content:format');
    $this->addFieldMapping('field_background_color', 'field_ms_page_bg_color');
    $this->addFieldMapping('field_tracking_code', 'field_microsite_page_adtracker');
    $this->addFieldMapping('field_tracking_code:format', 'field_microsite_page_adtracker:format');

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

  public function complete($node, stdClass $row) {
    // Generate URL Redirects.
    parent::generateNodeRedirect($node, $row);
  }
}