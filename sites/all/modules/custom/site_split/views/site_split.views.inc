<?php
/**
 * Implements hook_views_data()
 */
function site_split_views_data() {

}

/*
 * Implements hook_views_data_alter().
 */
function site_split_views_data_alter(&$data) {
  $data['workbench_moderation_node_history']['all_states'] = array(
    'title' => t('All Moderation States'),
    'help' => t('Moderation States. Yes, even if it is null. The magic of outer joins.'),
    'field' => array(
      'handler' => 'site_split_field_handler_moderation_state_all',
    ),
  );
}

/*
 * Implements hook_views_handlers().
 */
function site_split_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'site_split') . '/views',
    ),
    'handlers' => array(
      'site_split_field_handler_moderation_state_all' => array(
        'parent' => 'views_field_handler',
      ),
    ),
  );
}