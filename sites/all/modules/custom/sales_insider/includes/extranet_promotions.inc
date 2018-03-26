<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 1/8/18
 * Time: 2:05 PM
 */

/**
 * Field Instances for the Extranet Promotions content type.
 *
 * @return array
 */
function _sales_insider_extranet_promotions_field_instances() {
  $field_instances = [];

  // Exported field_instance: 'node-extranet_promotion-body'.
  $field_instances['node-extranet_promotion-body'] = [
    'bundle' => 'extranet_promotion',
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
      'weight' => 31,
    ],
  ];

  // Exported field_instance: 'node-extranet_promotion-field_display_title'.
  $field_instances['node-extranet_promotion-field_display_title'] = [
    'bundle' => 'extranet_promotion',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The Title for this content which will appear to the public.  The Title field will not appear.  ',
    'display' => [
      'default' => [
        'label' => 'above',
        'module' => 'text',
        'settings' => [
          'field_formatter_filter' => NULL,
        ],
        'type' => 'text_default',
        'weight' => 1,
      ],
      'teaser' => [
        'label' => 'above',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 0,
      ],
    ],
    'entity_type' => 'node',
    'field_name' => 'field_display_title',
    'label' => 'Display Title',
    'required' => 0,
    'settings' => [
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ],
    'widget' => [
      'active' => 1,
      'module' => 'text',
      'settings' => [
        'size' => 60,
      ],
      'type' => 'text_textfield',
      'weight' => 42,
    ],
  ];

  // Exported field_instance: 'node-extranet_promotion-field_promotion_date'.
  $field_instances['node-extranet_promotion-field_promotion_date'] = [
    'bundle' => 'extranet_promotion',
    'deleted' => 0,
    'description' => '',
    'display' => [
      'default' => [
        'label' => 'above',
        'module' => 'date',
        'settings' => [
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
        ],
        'type' => 'date_default',
        'weight' => 2,
      ],
      'teaser' => [
        'label' => 'above',
        'settings' => [],
        'type' => 'hidden',
        'weight' => 0,
      ],
    ],
    'entity_type' => 'node',
    'field_name' => 'field_promotion_date',
    'label' => 'Promotion Date',
    'required' => 0,
    'settings' => [
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ],
    'widget' => [
      'active' => 1,
      'module' => 'date',
      'settings' => [
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'text_parts' => [],
        'year_range' => '-3:+3',
      ],
      'type' => 'date_popup',
      'weight' => 43,
    ],
  ];

  return $field_instances;
}