<?php

/**
 * @file
 * blog_fnet.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function blog_fnet_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function blog_fnet_node_info() {
  $items = array(
    'blog_article' => array(
      'name' => t('Blog Article'),
      'base' => 'node_content',
      'description' => t('The "Blog Article" content type can be used to create a set of articles to be organized under one or more categories.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
