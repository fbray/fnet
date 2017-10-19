<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/26/17
 * Time: 3:09 PM
 */

/*
 *  Page Region Migration Class
*/
class FNETPageRegionMigration extends FNETNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Redirects
    $this->addFieldMapping('migrate_redirects', 'path');

    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity')
      ->description(t('No longer necessary as NetScout split is complete.'))
      ->issueGroup(t('DNM'));

    // Individual Fields
    $this->addFieldMapping('field_removenav', 'field_removenav');
    $this->addFieldMapping('field_tracking_code', 'field_page_adtracker');
    $this->addFieldMapping('field_tracking_code:format', 'field_page_adtracker:format');

  }

}