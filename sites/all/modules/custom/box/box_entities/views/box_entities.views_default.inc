<?php
/**
 * Implementation of hook_views_default_views()
 */
function box_entities_views_default_views() {
  $views = array();
  $files = file_scan_directory(drupal_get_path('module', 'box_entities') . '/views', '/.*\.view$/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}
?>