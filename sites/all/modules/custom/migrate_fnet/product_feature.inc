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
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity');

    // Individual Fields
    // Move to a common Sort Order field using an integer
    $this->addFieldMapping('field_sortorder', 'field_feature_sortorder');

    // Entity References
    // Move to a common Product field
    $this->addFieldMapping('field_product', 'field_feature_product')
      ->sourceMigration('FNETProductMigration'); // TODO: Find migration - Uses checkboxes/radio

  }
}