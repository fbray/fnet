<?php

/*
 *  Supported Device Migration Class
*/
class PlayOn6DeviceMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    
    // Put mapping logic here for fields.
    $this->addFieldMapping('field_device_icon', 'field_devicon')
      ->sourceMigration('Files');  // IMAGE
    $this->addFieldMapping('field_device_icon:file_class')
      ->defaultValue('migrateFileFid');
    $this->addFieldMapping('field_device_icon:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_device_icon:language')
      ->defaultValue('en');
    $this->addFieldMapping('field_device_icon:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_device_icon:title')
      ->defaultValue(NULL);
    
    // $this->addFieldMapping('field_device_icon', 'field_devicon:list'); 
    // $this->addFieldMapping('field_device_icon', 'field_devicon:data'); 
    
    $this->addFieldMapping('field_video_url', 'field_videourl'); // Link
    $this->addFieldMapping('field_video_url:language')
      ->defaultValue('en');
    $this->addFieldMapping('field_video_url:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_video_url:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_js_tracking', 'field_tracking');
    $this->addFieldMapping('field_js_tracking:language')
      ->defaultValue('en');
    }
}