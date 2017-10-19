<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/18/17
 * Time: 11:32 AM
 */

/*
 *  Distributor Migration Class
*/
class FNETProductDistributorMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Redirects
    $this->addFieldMapping('migrate_redirects', 'path');

    $this->addFieldMapping(NULL, 'field_business_entity')
      ->description(t('No longer necessary as NetScout split is complete.'))
      ->issueGroup(t('DNM'));
    $this->addFieldMapping(NULL, 'field_custom_publish_content')
      ->description(t('This was redundant with node status.'))
      ->issueGroup(t('DNM'));

    // Entity References
    $this->addFieldMapping('field_product', 'field_products')
      ->sourceMigration('ProductDisplay');

  }
}