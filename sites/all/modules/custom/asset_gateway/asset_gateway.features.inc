<?php

/**
 * @file
 * asset_gateway.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function asset_gateway_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function asset_gateway_node_info() {
  $items = array(
    'asset_gateway' => array(
      'name' => t('Asset Gateway'),
      'base' => 'node_content',
      'description' => t('The purpose of this type is to serve as a data collection point before sending the user onto the target page (which likely does not allow us to track)'),
      'has_title' => '1',
      'title_label' => t('Internal Title'),
      'help' => t('The "internal title" is used for internal use and does not display to the end user. The "page title" is shown to users and will also appear in the breadcrumbs and the overall document title (HEAD > TITLE).'),
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
