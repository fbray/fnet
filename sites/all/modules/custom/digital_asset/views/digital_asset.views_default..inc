<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 1/5/18
 * Time: 10:05 AM
 */

/**
 * Implementation of hook_views_default_views()
 */
function digital_asset_views_default_views() {
  $views = array();
  $files = file_scan_directory(drupal_get_path('module', 'digital_asset') . '/views', '/.*\.view$/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}
?>