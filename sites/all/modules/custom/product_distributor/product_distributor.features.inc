<?php

/**
 * @file
 * product_distributor.features.inc
 */

/**
 * Implements hook_node_info().
 */
function product_distributor_node_info() {
  $items = array(
    'product_distributor' => array(
      'name' => t('Product Distributor'),
      'base' => 'node_content',
      'description' => t('Create a new Distributor'),
      'has_title' => '1',
      'title_label' => t('Group Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
