<?php

/**
 * @file
 * products.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function products_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function products_views_api($module = NULL, $api = NULL) {
  return array(
    'api' => 3.0,
    'path' => drupal_get_path('module', 'products') . '/views',
  );
}

/**
 * Implements hook_node_info().
 */
function products_node_info() {
  $items = array(
    'product_display' => array(
      'name' => t('Product Display'),
      'base' => 'node_content',
      'description' => t('The <em>Product Display</em> is the way to display products for purchase.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'product_feature' => array(
      'name' => t('Product Feature'),
      'base' => 'node_content',
      'description' => t('Product Feature'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'product_language' => array(
      'name' => t('Product Language'),
      'base' => 'node_content',
      'description' => t('The product languages content in parallel with the product pages. This is a old hack that will be replaced by proper Entity Translation.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'product_sub_type' => array(
      'name' => t('Product Sub Type'),
      'base' => 'node_content',
      'description' => t('Add models, accessories, options, etc.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
