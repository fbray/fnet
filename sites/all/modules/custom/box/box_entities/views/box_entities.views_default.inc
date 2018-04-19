<?php

/**
 * @file
 * box_entities.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function box_entities_views_default_views() {
  $views = array();
  $files = file_scan_directory(drupal_get_path('module', 'box_entities') . '/views', '/.*\.view.inc$/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}
