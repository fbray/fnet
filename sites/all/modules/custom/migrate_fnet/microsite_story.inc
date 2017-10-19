<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/26/17
 * Time: 3:03 PM
 */

/*
 *  Microsite Story Migration Class
*/
class FNETMicrositeStoryMigration extends FNETNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity')
      ->description(t('No longer necessary as NetScout split is complete.'))
      ->issueGroup(t('DNM'));

    // Individual Fields
    $this->addFieldMapping('field_display_title', 'field_display_title');
    $this->addFieldMapping('field_background_color', 'field_ms_story_bg_color');

    // Image field
    $this->addFieldMapping('field_background_image', 'field_ms_story_bg_image')
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