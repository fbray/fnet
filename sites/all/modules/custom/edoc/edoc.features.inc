<?php

/**
 * @file
 * edoc.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function edoc_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function edoc_node_info() {
  $items = array(
    'edoc' => array(
      'name' => t('eDoc'),
      'base' => 'node_content',
      'description' => t('A more formal style of node used for presentation of brochures, white papers and so on. Includes nicely formatted PDF documentation download option.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
