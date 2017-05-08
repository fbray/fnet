<?php

/*
 *  Forum Topic Migration Class
*/
class PlayOn6ForumMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    
    // Put mapping logic here for fields.
    $this->addFieldMapping('taxonomy_forums', 1)
      ->sourceMigration('Forums');
    $this->addFieldMapping('taxonomy_forums:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('taxonomy_forums:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('taxonomy_forums:ignore_case')
      ->defaultValue(TRUE);
      
    // Upload field
    $this->addFieldMapping('field_attachments', 'upload')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_attachments:file_class')->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_attachments:preserve_files')->defaultValue(FALSE);
    // $this->addFieldMapping('field_attachments:source_dir')->defaultValue('/webdev/playon.tv/drupal-6.30/sites/default/files/');
    $this->addFieldMapping('field_attachments:description', 'upload:description');
    $this->addFieldMapping('field_attachments:display')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_attachments:language')
      ->defaultValue('en');
    // $this->addFieldMapping('field_attachments:urlencode')
      // ->defaultValue(TRUE);
    }
}