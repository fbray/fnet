<?php
/**
 * @file
 * cio_brief.features.inc
 */

/**
 * Implements hook_views_api().
 */
function cio_brief_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function cio_brief_node_info() {
  $items = array(
    'cio_brief' => array(
      'name' => t('CIO Brief'),
      'base' => 'node_content',
      'description' => t('The CIO Brief newsletter is a blog-like collection of articles'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
