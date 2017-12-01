<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 11/2/17
 * Time: 1:21 PM
 */

/**
 * Implementation of hook_views_default_views()
 */
function fextranet_views_default_views() {
  $views = array();
  $files = file_scan_directory(drupal_get_path('module', 'translations') . '/views', '/.*\.view$/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}
