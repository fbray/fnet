<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 6/7/17
 * Time: 1:39 PM
 */
/*
 *  Digital Asset Migration Class
*/
class FNETDigitalAssetMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity');

    // Individual Fields
    $this->addFieldMapping('field_dam_document_id', 'field_dam_document_id');
    $this->addFieldMapping('field_dam_ams_id', 'field_dam_ams_id');
    $this->addFieldMapping('field_dam_revision_letter', 'field_dam_revision_letter');
    $this->addFieldMapping('field_dam_language', 'field_dam_language');
    $this->addFieldMapping('field_dam_storage_file_folder', 'field_dam_storage_file_folder');
    $this->addFieldMapping('field_dam_storage_file_name', 'field_dam_storage_file_name');
    $this->addFieldMapping('field_dam_cdn_status', 'field_dam_cdn_status');
    $this->addFieldMapping('field_dam_file_size', 'field_dam_file_size');
    $this->addFieldMapping('field_dam_original_filename', 'field_dam_original_filename');
    $this->addFieldMapping('field_dam_keep_original_filename', 'field_dam_keep_original_filename');
    $this->addFieldMapping('field_dam_asset_type', 'field_dam_asset_type');
    $this->addFieldMapping('field_dam_export_controlled', 'field_dam_export_controlled');
    $this->addFieldMapping('field_dam_document_status', 'field_dam_document_status');
    $this->addFieldMapping('ffield_dam_entitlement_level', 'field_dam_entitlement_level');

    $this->addFieldMapping('field_dam_bulk_fulfillment', 'field_dam_bulk_fulfillment');
    $this->addFieldMapping('field_dam_keep_original_filename', 'field_dam_keep_original_filename');
    $this->addFieldMapping('field_dam_storage_file_folder_po', 'field_dam_storage_file_folder_po');
    $this->addFieldMapping('field_dam_storage_filename_pod', 'field_dam_storage_filename_pod');
    $this->addFieldMapping('field_dam_cdn_status_pod', 'field_dam_cdn_status_pod');
    $this->addFieldMapping('field_dam_cost_center', 'field_dam_cost_center');
    $this->addFieldMapping('field_dam_print_on_demand', 'field_dam_print_on_demand');
    $this->addFieldMapping('field_dam_quantity', 'field_dam_quantity');
    $this->addFieldMapping('field_dam_unit_of_measure', 'field_dam_unit_of_measure');
    $this->addFieldMapping('field_dam_uom_quantity', 'field_dam_uom_quantity');
    $this->addFieldMapping('field_dam_order_quantity_max', 'field_dam_order_quantity_max');
    $this->addFieldMapping('field_dam_l1_category', 'field_dam_l1_category');
    $this->addFieldMapping('field_dam_l2_category', 'field_dam_l2_category');
    $this->addFieldMapping('field_dam_l3_category', 'field_dam_l3_category');
    $this->addFieldMapping('field_dam_l4_category', 'field_dam_l4_category');

    // TODO: Special processing. These two fields need to be made into an Entity Reference field, referencing the Product Category content type.
    // field_product_category
    $this->addFieldMapping('field_dam_industry', 'field_dam_industry');
    $this->addFieldMapping('field_dam_industry', 'field_dam_new_industry');

    // Link Fieldss
    $this->addFieldMapping('field_dam_edoc_url', 'field_dam_edoc_url');
    $this->addFieldMapping('field_dam_edoc_url:title', 'field_dam_edoc_url:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_dam_edoc_url:attributes', 'field_dam_edoc_url:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_dam_edoc_url:language', 'field_dam_edoc_url:language')
      ->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_sortorder', 'field_dam_form_url');

    // Date Fields
    $this->addFieldMapping('field_dam_availability_dates', 'field_dam_availability_date');

    // Entity References
    $this->addFieldMapping('field_products', 'field_dam_related_product')
      ->sourceMigration('ProductDisplay');

    $this->addFieldMapping('field_dam_parent', 'field_dam_parent')
      ->sourceMigration('DigitalAsset'); // TODO: Self Reference

    $this->addFieldMapping('field_expertise_product', 'taxonomy_vocabulary_19')
      ->sourceMigration('AssetTags');

    // File Fields
    $this->addFieldMapping('field_asset_file', 'field_dam_asset_file')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_asset_file:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_dam_asset_file_pod', 'field_dam_asset_file_pod')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_dam_asset_file_pod:file_class')
      ->defaultValue('MigrateFileFid');
  }

  /**
   * Implementation of prepareRow()
   *
   * @param $row
   * @return bool
   */
  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $row->field_dam_industry;
  }

  // TODO: Flesh this out.
  protected function productCategoryNidFromTitle($title) {
    $nid = 0;
    // look up the NID from the title.

    return $nid;
  }
}