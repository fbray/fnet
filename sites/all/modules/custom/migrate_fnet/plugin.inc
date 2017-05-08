<?php
/*
 *  Plugin Migration Class
*/
class PlayOn6PluginMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    $this->sourceFields['parsed_premium'] = t('The parsed Requires PlayOn Premium value.');
    $this->sourceFields['parsed_provider'] = t('The parsed Requires Provider Subscription value.');
    $this->sourceFields['parsed_decline'] = t('The parsed Decline Plugin value.');
    $this->sourceFields['parsed_path'] = t('The altered path for the plugin');
    parent::__construct($arguments);
    
    // TODO: FIX PATH, DAMMIT
    
    // Put mapping logic here.
    $this->addFieldMapping(NULL, 'language');
    $this->addFieldMapping(NULL, 'field_plugin_upload_plugin'); // Convert filepath to File field data.
    
    $this->addFieldMapping('field_upload_plugin', 'field_plugin_upload_plugin');
      // ->sourceMigration('PluginFiles');  // This needs to be a file name. No URL, No path.
    $this->addFieldMapping('field_upload_plugin:file_class')
      ->defaultValue('MigrateFileUri');
    if (variable_get('environment') == 'local') {
      $this->addFieldMapping('field_upload_plugin:source_dir') 
        ->defaultValue('/webdev/playon.tv/plugin/sites/default/files/plugins/files'); // Localhost
    }
    else {
      $this->addFieldMapping('field_upload_plugin:source_dir') 
        ->defaultValue('/home/dev/plugin-import-files/plugins/files'); // Dev
    }
    $this->addFieldMapping('field_upload_plugin:destination_dir')
      ->defaultValue('public://plugins/files');

    $this->addFieldMapping('field_upload_plugin:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    /* $this->addFieldMapping('field_upload_plugin:language')
      ->defaultValue('en'); */
    $this->addFieldMapping('field_upload_plugin:preserve_files')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_upload_plugin:description')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_upload_plugin:display')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_upload_plugin:urlencode')
      ->defaultValue(TRUE);
      
    $this->addFieldMapping('field_plugin_thumbnail', 'field_plugin_picture');
      // ->sourceMigration('PluginFiles');
    $this->addFieldMapping('field_plugin_thumbnail:file_class')
      ->defaultValue('MigrateFileUri');
    if (variable_get('environment') == 'local') {
      $this->addFieldMapping('field_plugin_thumbnail:source_dir')
        ->defaultValue('/webdev/playon.tv/plugin/sites/default/files/plugins/images'); // Localhost
    }
    else {
      $this->addFieldMapping('field_plugin_thumbnail:source_dir')
        ->defaultValue('/home/dev/plugin-import-files/plugins/images'); // Dev
    }
    $this->addFieldMapping('field_plugin_thumbnail:destination_dir')
      ->defaultValue('public://plugins/images');
    $this->addFieldMapping('field_plugin_thumbnail:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    /* $this->addFIeldMapping('field_plugin_thumbnail:language')
      ->defaultValue('en'); */
    $this->addFieldMapping('field_plugin_thumbnail:preserve_files')
      ->defaultValue(TRUE);
    
    $this->addFieldMapping('field_plugin_thumbnail:urlencode')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_plugin_thumbnail:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_plugin_thumbnail:title')
      ->defaultValue(NULL);
      
    
    $this->addFieldMapping('field_plugin_version', 'field_plugin_version'); 
    $this->addFieldMapping('field_plugin_version:language')
      ->defaultValue('en');
    $this->addFieldMapping('field_plugin_website', 'field_plugin_website');
    $this->addFieldMapping('field_plugin_website:title', 'field_plugin_website:title');
    $this->addFieldMapping('field_plugin_website:attributes', 'field_plugin_website:attributes');
    $this->addFieldMapping('field_plugin_website:language')
      ->defaultValue(NULL);
    $this->addFieldMapping(NULL, 'field_plugin_premium');
    $this->addFieldMapping('field_plugin_premium', 'parsed_premium');   
    $this->addFieldMapping(NULL, 'field_plugin_provider');
    $this->addFieldMapping('field_requires_provider', 'parsed_provider'); 
    
    $this->addFieldMapping(NULL, 'field_plugin_decline');    
    $this->addFieldMapping('workbench_moderation_state_new', 'parsed_decline');
      
    /* KEYWORDS HAVE BEEN DROPPED AS REDUNDANT - 12/4/2014
    $this->addFieldMapping('field_plugin_keywords', 'field_plugin_keywords')
      ->sourceMigration('PluginKeywords');;
    $this->addFieldMapping('field_plugin_keywords:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_plugin_keywords:create_term')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_plugin_keywords:ignore_case')
      ->defaultValue(TRUE);
      */
    
    $this->addFieldMapping('field_plugin_categories', 'field_plugin_categories')
      ->sourceMigration('PluginCategory');
    $this->addFieldMapping('field_plugin_categories:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_plugin_categories:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_plugin_categories:ignore_case')
      ->defaultValue(TRUE);  
    $this->addFieldMapping('field_plugin_description', 'body');
    $this->addFieldMapping('field_plugin_description:summary', 'teaser');
    $this->addFieldMapping('field_plugin_description:language')
      ->defaultValue('en');
    
    $this->addFieldMapping('path', 'parsed_path');
  }
  
  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $row->parsed_path = 'channel-store/' . $row->path;
    $row->parsed_premium = $this->parseYesNo($row->field_plugin_premium);
    $row->parsed_provided = $this->parseYesNo($row->field_plugin_provider);
    $plugin_file_data = file_uri_to_object($row->field_plugin_upload_plugin);
    $row->plugin_fid = $plugin_file_data->fid;
    
    // Set the Plugin comments to Read/Write.
    $row->comment = ($row->comment == 0) ? 2 : $row->comment; // TODO: test this.
    
    if ($row->field_plugin_decline == 'on') {
      $row->parsed_decline = 'declined';
    }
    else {
      $row->parsed_decline = ($row->status == 1) ? 'published' : 'draft';
    }
    // $row->field_plugin_picture = ltrim($row->field_plugin_picture, 'sites/default/files/plugins/images/');  // cleans up the file path.
    $row->field_plugin_picture = str_replace('sites/default/files/plugins/images/', '', $row->field_plugin_picture);
    // $row->field_plugin_upload_plugin = ltrim($row->field_plugin_upload_plugin, 'sites/default/files/plugins/files/');
    $row->field_plugin_upload_plugin = str_replace('sites/default/files/plugins/files/', '', $row->field_plugin_upload_plugin);
  }
  
  private function parseYesNo($value) {
    if ($value == 'Y') {
        $parsed = 1;
    }
    else {
        $parsed = 0;
    }
    return $parsed;
  }
  
   private function parseOnOff($value) {
    if ($value == 'on') {
        $parsed = 1;
    }
    else {
        $parsed = 0;
    }
    return $parsed;
  }
  
  protected function createStub($migration) {
    return FALSE;
  }
  
}