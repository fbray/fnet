<?php

/**
 * @file
 * product_assets.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function product_assets_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function product_assets_views_api($module = NULL, $api = NULL) {
  return [
    'api' => 3.0,
    'path' => drupal_get_path('module', 'product_assets') . '/views',
    'template path' => drupal_get_path('module', 'product_assets') . '/theme',
  ];
}

/**
 * Implements hook_node_info().
 */
function product_assets_node_info() {
  $items = array(
    'expertise' => array(
      'name' => t('Expertise'),
      'base' => 'node_content',
      'description' => t('Expertise article (Learn About, Featured Topic, Case Study, Testimonial)'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
