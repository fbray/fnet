<?php
/*
 *  Download Count Migration Class
*/

class PlayOn6PluginDownloadCountMigration extends Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    // We can do shared field mappings in the common class
    if (module_exists('path')) {
      $this->addFieldMapping('path')
           ->issueGroup(t('DNM'));
      if (module_exists('pathauto')) {
        $this->addFieldMapping('pathauto')
             ->issueGroup(t('DNM'));
      }
    }
    // Download Counts
    $this->description = $arguments['description'];    
    $table_name = 'pubdlcnt';    

    // Set the source index field
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'alias' => 'dc',
        )
      ),
        MigrateDestinationTable::getKeySchema($table_name) 
    );
      
    $query = Database::getConnection('default', $arguments['source_connection'])
      ->select('download_count', 'dc')
      ->fields('dc', array('nid', 'vid', 'dc_count'))
      ->fields('ctp', array('field_plugin_upload_plugin_value'))
      ->isNotNull('field_plugin_upload_plugin_value');
    $query->leftJoin('content_type_plugin', 'ctp', 'dc.vid = ctp.vid');
    $source_fields = array(
      'file_name' => t('The extracted name of the file.'),
      'full_url' => t('The processed full URL path'),
    );
    // Should we get most recent 
    $this->source = new MigrateSourceSQL($query, $source_fields);
    $this->destination = new MigrateDestinationTable($table_name); // we will send the data to the pubdlcnt table
      
    // Put mapping logic here.
    $this->addFieldMapping('count', 'dc_count'); // count
    $this->addFieldMapping('url', 'full_url'); // url 
    
    // fid  // This gets put in by default.
    $this->addFieldMapping('fid')
      ->defaultValue(NULL);
    // nid // source migration: Plugin
    // This is where things get weird.
    $this->addFieldMapping('nid', 'nid')
      ->sourceMigration('Plugin');
    // name // File name
    $this->addFieldMapping('name', 'file_name');
    // utime (upload time or last download time?)
    $this->addFieldMapping('utime')
      ->defaultValue(time());
    
  }
  
  public function prepareRow($row) {
    global $base_url;
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    // if URL is empty, don't add it!!
    if(empty($row->field_plugin_upload_plugin_value)) {
      return FALSE;
    }
    
    // Modify URL to be full for the pubdlcnt table.
    // $row->full_url = 'http://localhost' . $row->field_plugin_upload_plugin_value;
    $row->full_url = $base_url . $row->field_plugin_upload_plugin_value;
    
    $row->file_name = basename($row->field_plugin_upload_plugin_value);
    // Get file name from URL
    
    
 }
 
  protected function createStub(Migration $migration, array $source_id) {
    return FALSE;
  }
}