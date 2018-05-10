<?php

/**
 * @file
 * homepage.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function homepage_ctools_plugin_api($module = NULL, $api = NULL) {
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
function homepage_node_info() {
  $items = array(
    'homepage2013' => array(
      'name' => t('Homepage2013'),
      'base' => 'node_content',
      'description' => t('Hero banners, New & Events box, Our Blogs box, Great Deals box & Topics box'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'homepage2013_language' => array(
      'name' => t('Homepage2013 Language'),
      'base' => 'node_content',
      'description' => t('Homepage Hero banners, Expertise Topic/Role/Industry and promotion boxes in supported languages'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
