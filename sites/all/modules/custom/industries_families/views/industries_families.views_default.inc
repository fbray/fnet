<?php

/**
 * @file
 * industries_families.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function industries_families_views_default_views() {
  $views = array();
  $files = file_scan_directory(drupal_get_path('module', 'industries_families') . '/views', '/.*\.view.inc$/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}
