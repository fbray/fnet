<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 1/8/18
 * Time: 2:03 PM
 */

// Extranet Page only uses a Body Field. No definition necessary.

/**
 * Field Instances for the Extranet Page content type.
 *
 * @return array
 */
function _sales_insider_extranet_page_field_instances() {
  $field_instances = [];

  // Exported field_instance: 'node-extranet_page-body'.
  $field_instances['node-extranet_page-body'] = [
    'bundle' => 'extranet_page',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => [
      'default' => [
        'label' => 'hidden',
        'module' => 'text',
        'settings' => [
          'field_formatter_filter' => NULL,
        ],
        'type' => 'text_default',
        'weight' => 0,
      ],
      'teaser' => [
        'label' => 'hidden',
        'module' => 'text',
        'settings' => [
          'field_formatter_filter' => NULL,
          'trim_length' => 600,
        ],
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ],
    ],
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => FALSE,
    'settings' => [
      'display_summary' => TRUE,
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ],
    'widget' => [
      'module' => 'text',
      'settings' => [
        'rows' => 20,
        'summary_rows' => 5,
      ],
      'type' => 'text_textarea_with_summary',
      'weight' => 41,
    ],
  ];
  return $field_instances;
}