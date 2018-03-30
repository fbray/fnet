<?php

/**
 * @file
 * ems.features.inc
 */

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
  );
  drupal_alter('node_info', $items);
  return $items;
}
