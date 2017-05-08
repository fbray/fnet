<?php

/*
 *  User Migration Class
*/
class PlayOn6UserMigration extends DrupalUser6Migration {
  public function __construct(array $arguments) {
    //$this->sourceFields['first_name'] = t('The parsed First Name field.');
    //$this->sourceFields['last_name'] = t('The parsed Last Name field.');
    parent::__construct($arguments);
    // Put mapping logic here for Profile fields. 

    $this->addFieldMapping(NULL, 'profile_realname');
    $this->addFieldMapping(NULL, 'profile_website');
    $this->addFieldMapping(NULL, 'profile_email');	
    $this->addFieldMapping(NULL, 'profile_devices');    
    $this->addFieldMapping(NULL, 'profile_ownsplayon');
    }
    
    public function prepareRow($row) {
      // Always include this snippet, in case our parent class decides to ignore the row
      if (parent::prepareRow($row) === FALSE) {
        return FALSE;
      }
      // Filter out the known spammers
      $blacklist = array(
      
      );
      
    }
    
    // TODO: Log Duplicate entries.
}