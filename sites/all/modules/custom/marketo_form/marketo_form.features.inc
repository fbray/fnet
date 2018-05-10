<?php

/**
 * @file
 * marketo_form.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function marketo_form_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function marketo_form_node_info() {
  $items = array(
    'marketo_form' => array(
      'name' => t('Marketo Form'),
      'base' => 'node_content',
      'description' => t('Build Web Form with submission to Marketo. Uses Marketo Forms 1.0'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
