<?php

/**
 * @file
 * product_distributor.views_default.inc
 *
 * Views module related extension functions of the product_distributor module.
 */

/**
 * Implements hook_views_default_views().
 */
function product_distributor_views_default_views() {
  $views = [];
  $files = file_scan_directory(drupal_get_path('module', 'product_distributor') . '/views', '/.*\.view.inc$/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}
