<?php
/*
 *  Intent Migration Class
*/
class PlayOn6IntentMigration extends Migration {
  public function __construct(array $arguments) {
    $this->sourceFields['parsed_author'] = t('');
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
        'req_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'alias' => 'ir',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );
    $query = Database::getConnection('default', $arguments['source_connection'])
      ->select('intent_request', 'ir')
      ->fields('ir', array('req_id', 'name', 'email', 'url', 'created', 'finish_date', 'i_id', 'previously'))
      ->fields('u', array('uid'));
    $query->leftJoin('users', 'u', 'ir.name = u.name');
    $this->source = new MigrateSourceSQL($query);
    $this->addUnmigratedDestinations(array('is_new', 'revision',
      'revision_uid', 'log'));
      
    // Put mapping logic here.
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration($arguments['user_migration']); 
    $this->addFieldMapping('language')->defaultValue('en');
    $this->addFieldMapping('status')->defaultValue(TRUE);
    $this->addFieldMapping('sticky')->defaultValue('0');
    $this->addFieldMapping('promote')->defaultValue('0');
    $this->addFieldMapping(NULL, 'name');
    $this->addFieldMapping('field_previous_plugins', 'previously');
    $this->addFieldMapping('field_previous_plugins:language')
      ->defaultValue('en');
    $this->addFieldMapping('field_intent_bounty', 'i_id')
      ->sourceMigration('Bounty');   
    
    $this->addFieldMapping('field_intent_completion_date', 'finish_date');
    $this->addFieldMapping('field_intent_completion_date:timezone')
      ->defaultValue('America/Los_Angeles');
    $this->addFieldMapping('field_intent_completion_date:rrule')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_intent_completion_date:to')
      ->defaultValue(NULL);
  }
  
  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    
    // Convert the Finish Date to a Datetime value.
    
 }
  

}