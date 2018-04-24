<?php

/**
 * @file
 * digital_asset.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function digital_asset_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cdn|node|digital_asset|form';
  $field_group->group_name = 'group_cdn';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_asset';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'CDN Information',
    'weight' => '12',
    'children' => array(
      0 => 'field_dam_storage_file_folder',
      1 => 'field_dam_storage_file_name',
      2 => 'field_dam_cdn_status',
      3 => 'field_dam_file_size',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cdn field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_cdn|node|digital_asset|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_dam_ccs_printing|node|digital_asset|form';
  $field_group->group_name = 'group_dam_ccs_printing';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'digital_asset';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'CCS Printing',
    'weight' => '25',
    'children' => array(
      0 => 'field_dam_bulk_fulfillment',
      1 => 'field_dam_asset_file_pod',
      2 => 'field_dam_storage_file_folder_po',
      3 => 'field_dam_storage_filename_pod',
      4 => 'field_dam_cdn_status_pod',
      5 => 'field_dam_cost_center',
      6 => 'field_dam_print_on_demand',
      7 => 'field_dam_quantity',
      8 => 'field_dam_unit_of_measure',
      9 => 'field_dam_uom_quantity',
      10 => 'field_dam_order_quantity_max',
      11 => 'field_dam_l1_category',
      12 => 'field_dam_l2_category',
      13 => 'field_dam_l3_category',
      14 => 'field_dam_l4_category',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-dam-ccs-printing field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_dam_ccs_printing|node|digital_asset|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('CCS Printing');
  t('CDN Information');

  return $field_groups;
}
