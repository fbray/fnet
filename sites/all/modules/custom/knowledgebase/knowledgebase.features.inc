<?php
/**
 * @file
 * knowledgebase.features.inc
 */
/**
 * Implements hook_views_api()
 */
function knowledgebase_views_api() {
  return array(
    'api' => 3.0,
    'path' => drupal_get_path('module', 'knowledgebase') . '/views',
  );
}
