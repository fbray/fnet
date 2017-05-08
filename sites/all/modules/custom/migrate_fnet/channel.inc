<?php
/*
 *  Channel Migration Class
*/
class PlayOn6ChannelMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    $this->sourceFields += array(

      'reversed_playlater' => t('The reversed version of the PlayLater flag field.'),
    );
    parent::__construct($arguments);
    
    // Put mapping logic here for fields.
    $this->addFieldMapping(NULL, 'field_channel_name'); // Field is redundant.
    $this->addFieldMapping(NULL, 'body'); // Body field is going to be used by the Description.
    $this->addFieldMapping('body', 'field_po_channels_description');
    $this->addFieldMapping('body:format', 'field_po_channels_description:format');
    $this->addFieldMapping('field_display_order', 'field_po_channels_display_order');

    
    $this->addFieldMapping('field_channel_image', 'field_po_channel_image')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_channel_image:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_channel_image:language')
      ->defaultValue('en');
    $this->addFieldMapping('field_channel_image:preserve_files')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_channel_image:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_channel_image:title')
      ->defaultValue(NULL);
    
    $this->addFieldMapping('field_channel_thumbnail', 'field_po_channel_image_thumbnail')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_channel_thumbnail:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_channel_thumbnail:language')
      ->defaultValue('en');
    $this->addFieldMapping('field_channel_thumbnail:preserve_files')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_channel_thumbnail:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_channel_thumbnail:title')
      ->defaultValue(NULL);
      
    $this->addFieldMapping('field_plugin_channel', 'field_po_channel_isplugin');
    $this->addFieldMapping(NULL, 'field_is_not_playlater_channel'); // This field gets reversed.
    $this->addFieldMapping('field_playlater_channel', 'reversed_playlater'); 
    
    // Upload field
    $this->addFieldMapping('field_attachments', 'upload')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_attachments:file_class')->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_attachments:preserve_files')->defaultValue(FALSE);
    // $this->addFieldMapping('field_attachments:source_dir')->defaultValue('/webdev/playon.tv/drupal-6.30/sites/default/files/');
    $this->addFieldMapping('field_attachments:description', 'upload:description');
    // $this->addFieldMapping('field_attachments:display', 'attachements_display');
    $this->addFieldMapping('field_attachments:language')
      ->defaultValue('en');
    $this->addFieldMapping('field_attachments:urlencode')
      ->defaultValue(TRUE);
  }
  
  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    
    $data = $row->field_is_not_paylater_channel;
    if($data == 'Yes, exclude this from PlayLater channels') {
      $reversed = 0;
    }
    else {
      $reversed = 1;
    }
    $row->reversed_playlater = $reversed;
  }
}