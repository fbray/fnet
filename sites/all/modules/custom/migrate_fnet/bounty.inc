<?php
/*
 *  Plugin Bounty Migration Class
*/
class PlayOn6PluginBountyMigration extends Migration {
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
    $this->description = $arguments['description'];
    $this->destination = new MigrateDestinationNode($arguments['destination_type']);
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'alias' => 'i',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );
    
    $query = Database::getConnection('default', $arguments['source_connection'])
             ->select('intent', 'i')
             ->fields('i', array('id', 'image', 'name', 'url', 'cost', 'desription', 'lablel_text', 'status'));
    $source_fields = array(
      'parsed_status' => t('The parsed Status value.'),
    );
    $this->source = new MigrateSourceSQL($query, $source_fields);
    $this->sourceFields[''] = t('');
     $this->addUnmigratedDestinations(array('is_new', 'revision',
      'revision_uid', 'log'));
      
    // Put mapping logic here.
    $this->addFieldMapping('title', 'name');
    $this->addFieldMapping('uid')->defaultValue('1');
    $this->addFieldMapping('language')->defaultValue('en');
    $this->addFieldMapping('status')->defaultValue(TRUE); 
    $this->addFieldMapping('sticky')->defaultValue('0');
    $this->addFieldMapping('promote')->defaultValue('0');
    $this->addFieldMapping('body', 'desription');
    $this->addFieldMapping('body:summary', 'lablel_text');
    $this->addFieldMapping('body:format')
      ->defaultValue('plain_text');
    $this->addFieldMapping('body:language')
      ->defaultValue('en');
    $this->addFieldMapping('field_plugin_cost', 'cost');
    $this->addFieldMapping('field_plugin_bounty_url', 'url');
    $this->addFieldMapping('field_plugin_bounty_url:title', 'name');
    $this->addFieldMapping('field_plugin_bounty_url:attributes')
      ->defaultValue('');
    $this->addFieldMapping('field_plugin_bounty_url:language')
      ->defaultValue('en');
    // $this->addFieldMapping(NULL, 'field_plugin_upload_plugin'); // Convert filepath to File field data.
    

    $this->addFieldMapping('field_plugin_bounty_image', 'image');
      // ->sourceMigration('PluginFiles');
    $this->addFieldMapping('field_plugin_bounty_image:file_class')
      ->defaultValue('MigrateFileUri');
    
    if (variable_get('environment') == 'local') {
      $this->addFieldMapping('field_plugin_bounty_image:source_dir')
        ->defaultValue('/webdev/playon.tv/plugin/sites/default/files/intent');  // Localhost
    }
    else {
      $this->addFieldMapping('field_plugin_bounty_image:source_dir')
        ->defaultValue('/home/dev/plugin-import-files/intent'); // Dev
    }
    $this->addFieldMapping('field_plugin_bounty_image:destination_dir')
      ->defaultValue('public://bounties/images/');

    $this->addFieldMapping('field_plugin_bounty_image:file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    /* $this->addFieldMapping('field_plugin_bounty_image:language')
      ->defaultValue('en'); */
    $this->addFieldMapping('field_plugin_bounty_image:preserve_files')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_plugin_bounty_image:title', 'name');
    $this->addFieldMapping('field_plugin_bounty_image:alt', 'name');
    $this->addFieldMapping('field_plugin_bounty_image:urlencode')
      ->defaultValue(TRUE);
    $this->addFieldMapping(NULL, 'status');   
    $this->addFieldMapping('field_plugin_status', 'parsed_status');
  }
  
  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    
    switch($row->status) {
      case 1:
        $row->parsed_status = 'new';
        break;
      case 2:
        $row->parsed_status = 'not_developed';
        break;
      case 4:
        $row->parsed_status = 'process';
        break;
      case 8:
        $row->parsed_status = 'developed';
        break;
      case 16:
        $row->parsed_status = 'closed';
        break;
      default:
        $row->parsed_status = 'not_developed';
        break;
    }
    $row->image = str_replace('/channel-store/sites/default/files/intent/', '', $row->image);  // cleans up the file path.
  }
}