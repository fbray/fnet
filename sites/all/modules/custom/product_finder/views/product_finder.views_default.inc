<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 8/31/17
 * Time: 3:28 PM
 */

/**
 * Implementation of hook_views_default_views()
 *
 * @return array
 */
function product_finder_views_default_views() {
  $views = array();
  $files = file_scan_directory(drupal_get_path('module', 'product_finder') . '/views', '/.*\.view$/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}