<?php

/**
 * @file
 * ems.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ems_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function ems_views_api($module = NULL, $api = NULL) {
  return array(
    "api" => "3.0",
    "path" => drupal_get_path('module', 'ems'),
  );
}

/**
 * Implements hook_node_info().
 */
function ems_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('Training, Workshops, Webcasts. Relate event to industry and products, add link to Registration.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'event_occurrence' => array(
      'name' => t('Event Occurrence'),
      'base' => 'node_content',
      'description' => t('An occurrence of an event at a specific time and location, or a webinar at a specific time.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
