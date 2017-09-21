<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 9/20/17
 * Time: 9:45 AM
 */
/**
 * Implementation of hook_views_default_views()
 *
 * @return array
 */
function industries_families_views_default_views() {
  $views = array();
  $files = file_scan_directory(drupal_get_path('module', 'industries_families') . '/views', '/.*\.view$/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}
