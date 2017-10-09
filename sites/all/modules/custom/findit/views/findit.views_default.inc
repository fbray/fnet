<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 10/9/17
 * Time: 3:01 PM
 */
/**
 * Implementation of hook_views_default_views()
 */
function findit_views_default_views() {
  $views = array();
  $files = file_scan_directory(drupal_get_path('module', 'findit') . '/views', '/.*\.view$/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}