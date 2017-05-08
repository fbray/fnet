<?php
/**
 * @file
 * software_notifications.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function software_notifications_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-software_notifications-field_latest_version'
  $field_instances['node-software_notifications-field_latest_version'] = array(
    'bundle' => 'software_notifications',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_latest_version][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -4,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -4,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -4,
      ),
      'search_index' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -4,
      ),
      'search_result' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -4,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -4,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_latest_version',
    'label' => 'Latest Version',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => -4,
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -4,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-software_notifications-field_release_notes'
  $field_instances['node-software_notifications-field_release_notes'] = array(
    'bundle' => 'software_notifications',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_release_notes][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 18,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -3,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -3,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -3,
      ),
      'search_index' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -3,
      ),
      'search_result' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -3,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -3,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_release_notes',
    'label' => 'Release Notes',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => -3,
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => -3,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance:
  // 'node-software_notifications-field_version_location'
  $field_instances['node-software_notifications-field_version_location'] = array(
    'bundle' => 'software_notifications',
    'default_value' => array(
      0 => array(
        'title' => '',
        'url' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 74,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => -2,
      ),
      'print' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => -2,
      ),
      'rss' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => -2,
      ),
      'search_index' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => -2,
      ),
      'search_result' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => -2,
      ),
      'teaser' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => -2,
      ),
      'token' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => -2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_version_location',
    'label' => 'Version Location',
    'required' => 1,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 0,
      'title' => 'none',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'weight' => -2,
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'link_field',
      'weight' => -2,
    ),
    'widget_type' => 'link',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Latest Version');
  t('Release Notes');
  t('Version Location');

  return $field_instances;
}
