<?php

/**
 * @file
 * fnet_news_events.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function fnet_news_events_views_default_views() {
  $views = array();
  $files = file_scan_directory(drupal_get_path('module', 'fnet_news_events') . '/views', '/.*\.view.inc$/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}
