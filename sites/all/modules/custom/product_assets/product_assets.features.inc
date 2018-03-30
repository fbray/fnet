<?php

/**
 * @file
 * product_assets.features.inc
 */

/**
 * Implements hook_node_info().
 */
function product_assets_node_info() {
  $items = array(
    'expertise' => array(
      'name' => t('Expertise'),
      'base' => 'node_content',
      'description' => t('Expertise article (Learn About, Featured Topic, Case Study, Testimonial)'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
