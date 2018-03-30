<?php

/**
 * @file
 * product_distributor.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function product_distributor_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-product_distributor-field_related_products'.
  $field_instances['node-product_distributor-field_related_products'] = array(
    'bundle' => 'product_distributor',
    'deleted' => 0,
    'description' => 'Select products that belong to this Product Distributor.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_related_products',
    'label' => 'Stocked Products',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multiselect',
      'settings' => array(),
      'type' => 'multiselect',
      'weight' => 41,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Stocked Products');
  t('Select products that belong to this Product Distributor.');

  return $field_instances;
}
