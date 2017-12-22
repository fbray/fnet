<?php
/*
 *  Basic Page Migration Class
*/
class FNETPageMigration extends FNETNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    
    // Put mapping logic here for fields.
    // Redirects
    $this->addFieldMapping('migrate_redirects', 'path');

    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity')
      ->description(t('No longer necessary as NetScout split is complete.'))
      ->issueGroup(t('DNM'));
    $this->addFieldMapping(NULL, 'field_onyxhierarchyid')
      ->description(t('Onyx is no longer used.'))
      ->issueGroup(t('DNM'));

    $this->addFieldMapping('field_removenav', 'field_removenav');
    $this->addFieldMapping('field_tracking_code', 'field_page_adtracker');
    $this->addFieldMapping('field_tracking_code:format', 'field_page_adtracker:format');
  }

}