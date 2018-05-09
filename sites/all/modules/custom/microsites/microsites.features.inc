<?php

/**
 * @file
 * microsites.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function microsites_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function microsites_node_info() {
  $items = array(
    'microsite_page' => array(
      'name' => t('Microsite Page'),
      'base' => 'node_content',
      'description' => t('Page content type to be used for microsites.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'microsite_story' => array(
      'name' => t('Microsite Story'),
      'base' => 'node_content',
      'description' => t('Story content type to be used for microsite'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
