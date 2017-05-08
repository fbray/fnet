<?php
/**
 * @file
 * software_notifications.features.inc
 */

/**
 * Implements hook_views_api().
 */
function software_notifications_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function software_notifications_node_info() {
  $items = array(
    'software_notifications' => array(
      'name' => t('Software Notifications'),
      'base' => 'node_content',
      'description' => t('This content type will store meta data for software notifications to be remotely accessed by Fluke Networks products.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
