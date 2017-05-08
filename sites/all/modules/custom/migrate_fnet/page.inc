<?php
/*
 *  Basic Page Migration Class
*/
class PlayOn6PageMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    
    // Put mapping logic here for fields.
    $this->addFieldMapping('', 'field_title');
    $this->addFieldMapping(NULL, 'field_decoration');
    $this->addFieldMapping(NULL, 'field_sidebarsize');
    $this->addFieldMapping(NULL, 'field_image');
    }
}