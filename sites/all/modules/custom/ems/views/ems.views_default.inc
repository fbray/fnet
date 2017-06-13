<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 6/13/17
 * Time: 1:00 PM
 */

/**
 * Implementation of hook_views_default_views()
 *
 * @return array
 */
function ems_views_default_views() {
  $views = array();
  $files = file_scan_directory(drupal_get_path('module', 'ems') . '/views', '/.*\.view$/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}
?>