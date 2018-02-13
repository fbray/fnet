<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/22/17
 * Time: 1:09 PM
 */

/*
 *  Product Feature Migration Class
*/
class FNETProductFeatureMigration extends DrupalNode7Migration {
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
    // Move to a common Sort Order field using an integer
    $this->addFieldMapping('weight', 'field_feature_sortorder');
    $this->addFieldMapping('body:language', 'body:language')
      ->defaultValue(LANGUAGE_NONE);

    // Entity References
    // Move to a common Product field
    $this->addFieldMapping('field_products', 'field_feature_product')
      ->sourceMigration('ProductDisplay');

  }
}