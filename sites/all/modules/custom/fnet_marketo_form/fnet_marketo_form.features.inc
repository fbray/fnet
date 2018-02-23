<?php
/**
 * @file
 * fnet_marketo_form.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function fnet_marketo_form_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function fnet_marketo_form_node_info() {
  $items = array(
    'fnet_marketo_form' => array(
      'name' => t('FNET Marketo Form'),
      'base' => 'node_content',
      'description' => t('Marketo form for responsive theme.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
