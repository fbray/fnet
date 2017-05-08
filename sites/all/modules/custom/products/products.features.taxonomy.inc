<?php
/**
 * @file
 * products.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function products_taxonomy_default_vocabularies() {
  return array(
    'business_entity' => array(
      'name' => 'Business Entity',
      'machine_name' => 'business_entity',
      'description' => 'Entity (NetScout or Fluke) responsible for content',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'vocabulary_1' => array(
      'name' => 'Product Status',
      'machine_name' => 'vocabulary_1',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'features_productstatus',
      'weight' => 0,
    ),
    'vocabulary_6' => array(
      'name' => 'Product Attributes',
      'machine_name' => 'vocabulary_6',
      'description' => 'Used for display products on Product Finder.',
      'hierarchy' => 1,
      'module' => 'features_productattributes',
      'weight' => 0,
    ),
  );
}
