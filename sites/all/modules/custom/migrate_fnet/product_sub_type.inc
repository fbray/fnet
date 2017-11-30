<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/26/17
 * Time: 3:14 PM
 */

/*
 *  Product Sub Type Migration Class
*/
class FNETProductSubTypeMigration extends DrupalNode7Migration {
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
    $this->addFieldMapping('field_expertise_intro', 'field_expertise_intro');
    $this->addFieldMapping('field_expertise_relatedcontent', 'field_expertise_related_content');
    $this->addFieldMapping('weight', 'field_expertise_sortorder');

    // TODO: Image file!
    $this->addFieldMapping('field_image', 'field_productsub_image')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_image:alt', 'field_productsub_image:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_image:title', 'field_productsub_image:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_image:file_class')
      ->defaultValue('MigrateFileFid');

    // Entity References
    // Product Sub Types Taxonomy
    $this->addFieldMapping('field_product_sub_types', 'taxonomy_vocabulary_2')
      ->sourceMigration('ProductSubtypes');

    // Uses Product Content: Gold Support Contracts references view for nodes that can be referenced.
    $this->addFieldMapping('field_available_support_options', 'field_support_options')
      ->sourceMigration('ProductSubType');

    $this->addFieldMapping('field_products', 'field_productsub_product')
      ->sourceMigration('ProductDisplay');

  }
}