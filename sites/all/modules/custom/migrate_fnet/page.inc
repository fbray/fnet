<?php
/*
 *  Basic Page Migration Class
*/
class FNETPageMigration extends FNETNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    
    // Put mapping logic here for fields.
    $this->addFieldMapping(NULL, 'field_business_entity')
      ->description(t('No longer necessary as NetScout split is complete.'))
      ->issueGroup(t('DNM'));

    $this->addFieldMapping('field_removenav', 'field_removenav');
    $this->addFieldMapping('field_tracking_code', 'field_page_adtracker');
    $this->addFieldMapping('field_tracking_code:format', 'field_page_adtracker:format');
  }

  public function complete($node, stdClass $row) {
    // Generate URL Redirects.
    parent::generateNodeRedirect($node, $row);
  }
}