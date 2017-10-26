<?php
/**
 * @file
 * products.views_default.inc
 */

/**
 * Implementation of hook_views_default_views()
 */
function products_views_default_views() {
  $views = array();
  $files = file_scan_directory(drupal_get_path('module', 'products') . '/views', '/.*\.view$/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}
