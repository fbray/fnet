<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 10/17/17
 * Time: 10:12 AM
 */
/**
 * Implementation of hook_views_default_views()
 */
function product_assets_views_default_views() {
  $views = array();
  $files = file_scan_directory(drupal_get_path('module', 'product_assets') . '/views', '/.*\.view$/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}