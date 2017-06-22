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
class FNETMicrositeStoryMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity');

    // Individual Fields
    $this->addFieldMapping('field_display_title', 'field_display_title');

    // TODO: Image file!
    $this->addFieldMapping('field_ms_story_bg_image', 'field_ms_story_bg_image')
      ->sourceMigration('Files');

    // Taxonomy References
    $this->addFieldMapping('microsites', 'taxonomy_vocabulary_18')
      ->sourceMigration('Microsites');
    $this->addFieldMapping('microsites:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('microsites:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('microsites:ignore_case')
      ->defaultValue(TRUE);

  }
}