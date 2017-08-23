<?php
/**
 * @file
 * knowledgebase.views_default.inc
 */

/**
 * Implementation of hook_views_default_views()
 *
 * @return array
 */
function knowledgebase_views_default_views() {
  $views = array();
  $files = file_scan_directory(drupal_get_path('module', 'knowledgebase') . '/views', '/.*\.view$/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}
