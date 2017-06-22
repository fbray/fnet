<?php
/*
 *  Basic Page Migration Class
*/
class FNETPageMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    
    // Put mapping logic here for fields.
    $this->addFieldMapping('field_removenav', 'field_removenav');
    $this->addFieldMapping(NULL, 'field_business_entity');
    $this->addFieldMapping('field_adtracker', 'field_page_adtracker');
    }
}