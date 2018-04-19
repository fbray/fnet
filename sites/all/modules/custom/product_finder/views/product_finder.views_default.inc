<?php

/**
 * @file
 * product_finder.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function product_finder_views_default_views() {
  $views = array();
  $files = file_scan_directory(drupal_get_path('module', 'product_finder') . '/views', '/.*\.view.inc$/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}
