<?php

/**
 * @file
 * View Hook implementations for the Alternative Language Views module.
 */

/**
 * Implements hook_views_data_alter().
 */
function alternative_language_views_views_data_alter(&$data) {
  $data['node']['alternative_language'] = array(
    'group'  => t('Content'),
    'title'  => t('Language (with Alternative Language)'),
    'help'   => t('The language the content is in (with an alternative language option).'),
    'filter' => array(
      'handler' => 'alternative_language_views_filter_handler',
    ),
  );
}

/**
 * Implements hook_views_handlers().
 */
function alternative_language_views_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'alternative_language_views'),
    ),
    'handlers' => array(
      'alternative_language_views_filter_handler' => array(
        'parent' => 'views_handler_filter`',
      ),
    ),
  );
}
