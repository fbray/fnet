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
}

/**
 * Implements hook_views_api().
 */
function products_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function products_node_info() {
  $items = array(
    'product' => array(
      'name' => t('Product'),
      'base' => 'node_content',
      'description' => t('Use this content type for all product pages.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_weight_features_default_settings().
 */
function products_weight_features_default_settings() {
  $settings = array();

  $settings['family'] = array(
    'enabled' => 1,
    'range' => 20,
    'menu_weight' => 0,
    'default' => 0,
    'sync_translations' => 0,
  );

  return $settings;
}
