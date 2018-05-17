<?php

/**
 * @file
 * page_region.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function page_region_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function page_region_node_info() {
  $items = array(
    'page_region' => array(
      'name' => t('Page Region'),
      'base' => 'node_content',
      'description' => t('Similar to Page, but with added regionality control'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'page_region_language' => array(
      'name' => t('Page Region Language'),
      'base' => 'node_content',
      'description' => t('Language overwrite for content type Page Region.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
