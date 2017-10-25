<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 10/20/17
 * Time: 2:29 PM
 */

/**
 * Implementation of hook_views_default_views()
 */
function promotions_views_default_views() {
  $views = array();
  $files = file_scan_directory(drupal_get_path('module', 'promotions') . '/views', '/.*\.view$/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}

?>