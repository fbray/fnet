<?php

/**
 * @file
 * digital_asset.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function digital_asset_ctools_plugin_api($module = NULL, $api = NULL) {
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
function digital_asset_views_api() {
  return array(
    'api' => 3.0,
    'path' => drupal_get_path('module', 'digital_asset') . '/views',
  );
}

/**
 * Implements hook_node_info().
 */
function digital_asset_node_info() {
  $items = array(
    'digital_asset' => array(
      'name' => t('Digital Asset'),
      'base' => 'node_content',
      'description' => t('Digital asset (software, document, etc.) under control of the Asset Management System (AMS)'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
