<?php
/**
 * @file
 * products.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function products_field_default_field_bases() {
  $field_bases = [];

  // Exported field_base: 'body'.
  $field_bases['body'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [
      0 => 'node',
    ],
    'field_name' => 'body',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 1,
    'type' => 'text_with_summary',
  ];

  // Exported field_base: 'field_at_a_glance'.
  $field_bases['field_at_a_glance'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_at_a_glance',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 1,
    'type' => 'text_long',
  ];

  // Exported field_base: 'field_available_support_options'.
  $field_bases['field_available_support_options'] = [
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_available_support_options',
    'indexes' => [
      'target_id' => [
        0 => 'target_id',
      ],
    ],
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => [
      'entity_translation_sync' => FALSE,
      'handler' => 'views',
      'handler_settings' => [
        'behaviors' => [
          'views-select-list' => [
            'status' => 1,
          ],
        ],
        'view' => [
          'args' => [],
          'display_name' => 'gold_support_contracts',
          'view_name' => 'product_content',
        ],
      ],
      'target_type' => 'node',
    ],
    'translatable' => 0,
    'type' => 'entityreference',
  ];

  // Exported field_base: 'field_conversion_code'.
  $field_bases['field_conversion_code'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_conversion_code',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'text_long',
  ];

  // Exported field_base: 'field_description'.
  $field_bases['field_description'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_description',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 1,
    'type' => 'text_long',
  ];

  // Exported field_base: 'field_do_not_distribute'.
  $field_bases['field_do_not_distribute'] = [
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_do_not_distribute',
    'indexes' => [
      'value' => [
        0 => 'value',
      ],
    ],
    'locked' => 0,
    'module' => 'list',
    'settings' => [
      'allowed_values' => [],
      'allowed_values_function' => 'country_get_list',
      'allowed_values_php' => '',
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'list_text',
  ];

  // Exported field_base: 'field_image'.
  $field_bases['field_image'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_image',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_include_price_spider_code'.
  $field_bases['field_include_price_spider_code'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_include_price_spider_code',
    'indexes' => [
      'value' => [
        0 => 'value',
      ],
    ],
    'locked' => 0,
    'module' => 'list',
    'settings' => [
      'allowed_values' => [
        0 => '',
        1 => '',
      ],
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'list_boolean',
  ];

  // Exported field_base: 'field_language_region'.
  $field_bases['field_language_region'] = [
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_language_region',
    'indexes' => [
      'value' => [
        0 => 'value',
      ],
    ],
    'locked' => 0,
    'module' => 'list',
    'settings' => [
      'allowed_values' => [
        'en-us' => 'en-us (English/United States)',
        'en-au' => 'en-au (English/Australia)',
        'en-ca' => 'en-ca (English/Canada)',
        'en-eu' => 'en-eu (English/Europe)',
        'en-in' => 'en-in (English/India)',
        'en-ln' => 'en-ln (English/Latin America)',
        'en-su' => 'en-su (English/Southeast Asia)',
        'fr-eu' => 'fr-eu (French/Europe)',
        'fr-ca' => 'fr-ca (French/Canada)',
        'de-eu' => 'de-eu (German/Europe)',
        'es-eu' => 'es-eu (Spanish/Europe)',
        'es-ln' => 'es-ln (Spanish/Latin America)',
        'pt-eu' => 'pt-eu (Portuguese/Europe)',
        'pt-br' => 'pt-br (Portuguese/Brazil)',
        'cn-zh' => 'cn-zh (Chinese/China)',
        'jp-ja' => 'jp-ja (Japanese/Japan)',
        'ko-kr' => 'ko-kr (Korean/Korea)',
        'ru-ru' => 'ru-ru (Russian/Russia)',
      ],
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'list_text',
  ];

  // Exported field_base: 'field_pcatid'.
  $field_bases['field_pcatid'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_pcatid',
    'indexes' => [],
    'locked' => 0,
    'module' => 'number',
    'settings' => [
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'number_integer',
  ];

  // Exported field_base: 'field_prod_360_img_lg_1'.
  $field_bases['field_prod_360_img_lg_1'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_360_img_lg_1',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ],
    'translatable' => 0,
    'type' => 'text',
  ];

  // Exported field_base: 'field_prod_360_img_t_1'.
  $field_bases['field_prod_360_img_t_1'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_360_img_t_1',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_btn_calltoaction'.
  $field_bases['field_prod_btn_calltoaction'] = [
    'active' => 1,
    'cardinality' => 4,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_btn_calltoaction',
    'indexes' => [],
    'locked' => 0,
    'module' => 'link',
    'settings' => [
      'attributes' => [
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ],
      'display' => [
        'url_cutoff' => 80,
      ],
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ],
    'translatable' => 0,
    'type' => 'link_field',
  ];

  // Exported field_base: 'field_prod_btn_cta_size'.
  $field_bases['field_prod_btn_cta_size'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_btn_cta_size',
    'indexes' => [
      'value' => [
        0 => 'value',
      ],
    ],
    'locked' => 0,
    'module' => 'list',
    'settings' => [
      'allowed_values' => [
        '1 line' => '1 line',
        '2 lines' => '2 lines',
      ],
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'list_text',
  ];

  // Exported field_base: 'field_prod_carousel_img_lg_1'.
  $field_bases['field_prod_carousel_img_lg_1'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_lg_1',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_carousel_img_lg_10'.
  $field_bases['field_prod_carousel_img_lg_10'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_lg_10',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_carousel_img_lg_2'.
  $field_bases['field_prod_carousel_img_lg_2'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_lg_2',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_carousel_img_lg_3'.
  $field_bases['field_prod_carousel_img_lg_3'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_lg_3',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_carousel_img_lg_4'.
  $field_bases['field_prod_carousel_img_lg_4'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_lg_4',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_carousel_img_lg_5'.
  $field_bases['field_prod_carousel_img_lg_5'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_lg_5',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_carousel_img_lg_6'.
  $field_bases['field_prod_carousel_img_lg_6'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_lg_6',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_carousel_img_lg_7'.
  $field_bases['field_prod_carousel_img_lg_7'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_lg_7',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_carousel_img_lg_8'.
  $field_bases['field_prod_carousel_img_lg_8'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_lg_8',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_carousel_img_lg_9'.
  $field_bases['field_prod_carousel_img_lg_9'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_lg_9',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_carousel_img_srt_1'.
  $field_bases['field_prod_carousel_img_srt_1'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_srt_1',
    'indexes' => [
      'value' => [
        0 => 'value',
      ],
    ],
    'locked' => 0,
    'module' => 'list',
    'settings' => [
      'allowed_values' => [
        1 => 1,
        2 => 2,
        3 => 3,
        4 => 4,
        5 => 5,
        6 => 6,
        7 => 7,
        8 => 8,
        9 => 9,
        10 => 10,
        11 => 11,
        12 => 12,
        13 => 13,
        14 => 14,
        15 => 15,
        16 => 16,
        17 => 17,
        18 => 18,
        19 => 19,
        20 => 20,
      ],
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'list_integer',
  ];

  // Exported field_base: 'field_prod_carousel_img_srt_10'.
  $field_bases['field_prod_carousel_img_srt_10'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_srt_10',
    'indexes' => [
      'value' => [
        0 => 'value',
      ],
    ],
    'locked' => 0,
    'module' => 'list',
    'settings' => [
      'allowed_values' => [
        1 => 1,
        2 => 2,
        3 => 3,
        4 => 4,
        5 => 5,
        6 => 6,
        7 => 7,
        8 => 8,
        9 => 9,
        10 => 10,
        11 => 11,
        12 => 12,
        13 => 13,
        14 => 14,
        15 => 15,
        16 => 16,
        17 => 17,
        18 => 18,
        19 => 19,
        20 => 20,
      ],
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'list_integer',
  ];

  // Exported field_base: 'field_prod_carousel_img_srt_2'.
  $field_bases['field_prod_carousel_img_srt_2'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_srt_2',
    'indexes' => [
      'value' => [
        0 => 'value',
      ],
    ],
    'locked' => 0,
    'module' => 'list',
    'settings' => [
      'allowed_values' => [
        1 => 1,
        2 => 2,
        3 => 3,
        4 => 4,
        5 => 5,
        6 => 6,
        7 => 7,
        8 => 8,
        9 => 9,
        10 => 10,
        11 => 11,
        12 => 12,
        13 => 13,
        14 => 14,
        15 => 15,
        16 => 16,
        17 => 17,
        18 => 18,
        19 => 19,
        20 => 20,
      ],
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'list_integer',
  ];

  // Exported field_base: 'field_prod_carousel_img_srt_3'.
  $field_bases['field_prod_carousel_img_srt_3'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_srt_3',
    'indexes' => [
      'value' => [
        0 => 'value',
      ],
    ],
    'locked' => 0,
    'module' => 'list',
    'settings' => [
      'allowed_values' => [
        1 => 1,
        2 => 2,
        3 => 3,
        4 => 4,
        5 => 5,
        6 => 6,
        7 => 7,
        8 => 8,
        9 => 9,
        10 => 10,
        11 => 11,
        12 => 12,
        13 => 13,
        14 => 14,
        15 => 15,
        16 => 16,
        17 => 17,
        18 => 18,
        19 => 19,
        20 => 20,
      ],
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'list_integer',
  ];

  // Exported field_base: 'field_prod_carousel_img_srt_4'.
  $field_bases['field_prod_carousel_img_srt_4'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_srt_4',
    'indexes' => [
      'value' => [
        0 => 'value',
      ],
    ],
    'locked' => 0,
    'module' => 'list',
    'settings' => [
      'allowed_values' => [
        1 => 1,
        2 => 2,
        3 => 3,
        4 => 4,
        5 => 5,
        6 => 6,
        7 => 7,
        8 => 8,
        9 => 9,
        10 => 10,
        11 => 11,
        12 => 12,
        13 => 13,
        14 => 14,
        15 => 15,
        16 => 16,
        17 => 17,
        18 => 18,
        19 => 19,
        20 => 20,
      ],
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'list_integer',
  ];

  // Exported field_base: 'field_prod_carousel_img_srt_5'.
  $field_bases['field_prod_carousel_img_srt_5'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_srt_5',
    'indexes' => [
      'value' => [
        0 => 'value',
      ],
    ],
    'locked' => 0,
    'module' => 'list',
    'settings' => [
      'allowed_values' => [
        1 => 1,
        2 => 2,
        3 => 3,
        4 => 4,
        5 => 5,
        6 => 6,
        7 => 7,
        8 => 8,
        9 => 9,
        10 => 10,
        11 => 11,
        12 => 12,
        13 => 13,
        14 => 14,
        15 => 15,
        16 => 16,
        17 => 17,
        18 => 18,
        19 => 19,
        20 => 20,
      ],
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'list_integer',
  ];

  // Exported field_base: 'field_prod_carousel_img_srt_6'.
  $field_bases['field_prod_carousel_img_srt_6'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_srt_6',
    'indexes' => [
      'value' => [
        0 => 'value',
      ],
    ],
    'locked' => 0,
    'module' => 'list',
    'settings' => [
      'allowed_values' => [
        1 => 1,
        2 => 2,
        3 => 3,
        4 => 4,
        5 => 5,
        6 => 6,
        7 => 7,
        8 => 8,
        9 => 9,
        10 => 10,
        11 => 11,
        12 => 12,
        13 => 13,
        14 => 14,
        15 => 15,
        16 => 16,
        17 => 17,
        18 => 18,
        19 => 19,
        20 => 20,
      ],
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'list_integer',
  ];

  // Exported field_base: 'field_prod_carousel_img_srt_7'.
  $field_bases['field_prod_carousel_img_srt_7'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_srt_7',
    'indexes' => [
      'value' => [
        0 => 'value',
      ],
    ],
    'locked' => 0,
    'module' => 'list',
    'settings' => [
      'allowed_values' => [
        1 => 1,
        2 => 2,
        3 => 3,
        4 => 4,
        5 => 5,
        6 => 6,
        7 => 7,
        8 => 8,
        9 => 9,
        10 => 10,
        11 => 11,
        12 => 12,
        13 => 13,
        14 => 14,
        15 => 15,
        16 => 16,
        17 => 17,
        18 => 18,
        19 => 19,
        20 => 20,
      ],
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'list_integer',
  ];

  // Exported field_base: 'field_prod_carousel_img_srt_8'.
  $field_bases['field_prod_carousel_img_srt_8'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_srt_8',
    'indexes' => [
      'value' => [
        0 => 'value',
      ],
    ],
    'locked' => 0,
    'module' => 'list',
    'settings' => [
      'allowed_values' => [
        1 => 1,
        2 => 2,
        3 => 3,
        4 => 4,
        5 => 5,
        6 => 6,
        7 => 7,
        8 => 8,
        9 => 9,
        10 => 10,
        11 => 11,
        12 => 12,
        13 => 13,
        14 => 14,
        15 => 15,
        16 => 16,
        17 => 17,
        18 => 18,
        19 => 19,
        20 => 20,
      ],
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'list_integer',
  ];

  // Exported field_base: 'field_prod_carousel_img_srt_9'.
  $field_bases['field_prod_carousel_img_srt_9'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_srt_9',
    'indexes' => [
      'value' => [
        0 => 'value',
      ],
    ],
    'locked' => 0,
    'module' => 'list',
    'settings' => [
      'allowed_values' => [
        1 => 1,
        2 => 2,
        3 => 3,
        4 => 4,
        5 => 5,
        6 => 6,
        7 => 7,
        8 => 8,
        9 => 9,
        10 => 10,
        11 => 11,
        12 => 12,
        13 => 13,
        14 => 14,
        15 => 15,
        16 => 16,
        17 => 17,
        18 => 18,
        19 => 19,
        20 => 20,
      ],
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'list_integer',
  ];

  // Exported field_base: 'field_prod_carousel_img_t_1'.
  $field_bases['field_prod_carousel_img_t_1'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_t_1',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_carousel_img_t_10'.
  $field_bases['field_prod_carousel_img_t_10'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_t_10',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_carousel_img_t_2'.
  $field_bases['field_prod_carousel_img_t_2'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_t_2',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_carousel_img_t_3'.
  $field_bases['field_prod_carousel_img_t_3'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_t_3',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_carousel_img_t_4'.
  $field_bases['field_prod_carousel_img_t_4'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_t_4',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_carousel_img_t_5'.
  $field_bases['field_prod_carousel_img_t_5'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_t_5',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_carousel_img_t_6'.
  $field_bases['field_prod_carousel_img_t_6'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_t_6',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_carousel_img_t_7'.
  $field_bases['field_prod_carousel_img_t_7'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_t_7',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_carousel_img_t_8'.
  $field_bases['field_prod_carousel_img_t_8'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_t_8',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_carousel_img_t_9'.
  $field_bases['field_prod_carousel_img_t_9'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_carousel_img_t_9',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_contact_sales_button'.
  $field_bases['field_prod_contact_sales_button'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_contact_sales_button',
    'indexes' => [
      'value' => [
        0 => 'value',
      ],
    ],
    'locked' => 0,
    'module' => 'list',
    'settings' => [
      'allowed_values' => [
        0 => '',
        1 => '',
      ],
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'list_boolean',
  ];

  // Exported field_base: 'field_prod_ctab_data_1'.
  $field_bases['field_prod_ctab_data_1'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_ctab_data_1',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'text_long',
  ];

  // Exported field_base: 'field_prod_ctab_data_2'.
  $field_bases['field_prod_ctab_data_2'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_ctab_data_2',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'text_long',
  ];

  // Exported field_base: 'field_prod_ctab_data_3'.
  $field_bases['field_prod_ctab_data_3'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_ctab_data_3',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'text_long',
  ];

  // Exported field_base: 'field_prod_ctab_data_4'.
  $field_bases['field_prod_ctab_data_4'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_ctab_data_4',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'text_long',
  ];

  // Exported field_base: 'field_prod_ctab_data_5'.
  $field_bases['field_prod_ctab_data_5'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_ctab_data_5',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'text_long',
  ];

  // Exported field_base: 'field_prod_ctab_link_1'.
  $field_bases['field_prod_ctab_link_1'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_ctab_link_1',
    'indexes' => [],
    'locked' => 0,
    'module' => 'link',
    'settings' => [
      'attributes' => [
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ],
      'display' => [
        'url_cutoff' => 80,
      ],
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ],
    'translatable' => 0,
    'type' => 'link_field',
  ];

  // Exported field_base: 'field_prod_ctab_link_2'.
  $field_bases['field_prod_ctab_link_2'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_ctab_link_2',
    'indexes' => [],
    'locked' => 0,
    'module' => 'link',
    'settings' => [
      'attributes' => [
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ],
      'display' => [
        'url_cutoff' => 80,
      ],
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ],
    'translatable' => 0,
    'type' => 'link_field',
  ];

  // Exported field_base: 'field_prod_ctab_link_3'.
  $field_bases['field_prod_ctab_link_3'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_ctab_link_3',
    'indexes' => [],
    'locked' => 0,
    'module' => 'link',
    'settings' => [
      'attributes' => [
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ],
      'display' => [
        'url_cutoff' => 80,
      ],
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ],
    'translatable' => 0,
    'type' => 'link_field',
  ];

  // Exported field_base: 'field_prod_ctab_link_4'.
  $field_bases['field_prod_ctab_link_4'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_ctab_link_4',
    'indexes' => [],
    'locked' => 0,
    'module' => 'link',
    'settings' => [
      'attributes' => [
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ],
      'display' => [
        'url_cutoff' => 80,
      ],
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ],
    'translatable' => 0,
    'type' => 'link_field',
  ];

  // Exported field_base: 'field_prod_ctab_link_5'.
  $field_bases['field_prod_ctab_link_5'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_ctab_link_5',
    'indexes' => [],
    'locked' => 0,
    'module' => 'link',
    'settings' => [
      'attributes' => [
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ],
      'display' => [
        'url_cutoff' => 80,
      ],
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ],
    'translatable' => 0,
    'type' => 'link_field',
  ];

  // Exported field_base: 'field_prod_ctab_name_1'.
  $field_bases['field_prod_ctab_name_1'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_ctab_name_1',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ],
    'translatable' => 0,
    'type' => 'text',
  ];

  // Exported field_base: 'field_prod_ctab_name_2'.
  $field_bases['field_prod_ctab_name_2'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_ctab_name_2',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ],
    'translatable' => 0,
    'type' => 'text',
  ];

  // Exported field_base: 'field_prod_ctab_name_3'.
  $field_bases['field_prod_ctab_name_3'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_ctab_name_3',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ],
    'translatable' => 0,
    'type' => 'text',
  ];

  // Exported field_base: 'field_prod_ctab_name_4'.
  $field_bases['field_prod_ctab_name_4'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_ctab_name_4',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ],
    'translatable' => 0,
    'type' => 'text',
  ];

  // Exported field_base: 'field_prod_ctab_name_5'.
  $field_bases['field_prod_ctab_name_5'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_ctab_name_5',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ],
    'translatable' => 0,
    'type' => 'text',
  ];

  // Exported field_base: 'field_prod_hide_models_accessory'.
  $field_bases['field_prod_hide_models_accessory'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_hide_models_accessory',
    'indexes' => [
      'value' => [
        0 => 'value',
      ],
    ],
    'locked' => 0,
    'module' => 'list',
    'settings' => [
      'allowed_values' => [
        0 => '',
        1 => '',
      ],
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'list_boolean',
  ];

  // Exported field_base: 'field_prod_hub_img'.
  $field_bases['field_prod_hub_img'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_hub_img',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_rating_review'.
  $field_bases['field_prod_rating_review'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_rating_review',
    'indexes' => [
      'value' => [
        0 => 'value',
      ],
    ],
    'locked' => 0,
    'module' => 'list',
    'settings' => [
      'allowed_values' => [
        0 => '',
        1 => '',
      ],
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'list_boolean',
  ];

  // Exported field_base: 'field_prod_sol_desc_1'.
  $field_bases['field_prod_sol_desc_1'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_sol_desc_1',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ],
    'translatable' => 0,
    'type' => 'text',
  ];

  // Exported field_base: 'field_prod_sol_desc_2'.
  $field_bases['field_prod_sol_desc_2'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_sol_desc_2',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ],
    'translatable' => 0,
    'type' => 'text',
  ];

  // Exported field_base: 'field_prod_sol_desc_3'.
  $field_bases['field_prod_sol_desc_3'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_sol_desc_3',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ],
    'translatable' => 0,
    'type' => 'text',
  ];

  // Exported field_base: 'field_prod_sol_desc_4'.
  $field_bases['field_prod_sol_desc_4'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_sol_desc_4',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ],
    'translatable' => 0,
    'type' => 'text',
  ];

  // Exported field_base: 'field_prod_sol_link_1'.
  $field_bases['field_prod_sol_link_1'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_sol_link_1',
    'indexes' => [],
    'locked' => 0,
    'module' => 'link',
    'settings' => [
      'attributes' => [
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ],
      'display' => [
        'url_cutoff' => 80,
      ],
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ],
    'translatable' => 0,
    'type' => 'link_field',
  ];

  // Exported field_base: 'field_prod_sol_link_2'.
  $field_bases['field_prod_sol_link_2'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_sol_link_2',
    'indexes' => [],
    'locked' => 0,
    'module' => 'link',
    'settings' => [
      'attributes' => [
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ],
      'display' => [
        'url_cutoff' => 80,
      ],
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ],
    'translatable' => 0,
    'type' => 'link_field',
  ];

  // Exported field_base: 'field_prod_sol_link_3'.
  $field_bases['field_prod_sol_link_3'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_sol_link_3',
    'indexes' => [],
    'locked' => 0,
    'module' => 'link',
    'settings' => [
      'attributes' => [
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ],
      'display' => [
        'url_cutoff' => 80,
      ],
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ],
    'translatable' => 0,
    'type' => 'link_field',
  ];

  // Exported field_base: 'field_prod_sol_link_4'.
  $field_bases['field_prod_sol_link_4'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_sol_link_4',
    'indexes' => [],
    'locked' => 0,
    'module' => 'link',
    'settings' => [
      'attributes' => [
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ],
      'display' => [
        'url_cutoff' => 80,
      ],
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ],
    'translatable' => 0,
    'type' => 'link_field',
  ];

  // Exported field_base: 'field_prod_sol_title'.
  $field_bases['field_prod_sol_title'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_sol_title',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ],
    'translatable' => 0,
    'type' => 'text',
  ];

  // Exported field_base: 'field_prod_video_img_t_1'.
  $field_bases['field_prod_video_img_t_1'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_video_img_t_1',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_video_lg_1'.
  $field_bases['field_prod_video_lg_1'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_video_lg_1',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'file',
    'settings' => [
      'display_default' => 1,
      'display_field' => 1,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'file',
  ];

  // Exported field_base: 'field_prod_video_youtube_url'.
  $field_bases['field_prod_video_youtube_url'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_video_youtube_url',
    'indexes' => [],
    'locked' => 0,
    'module' => 'link',
    'settings' => [
      'attributes' => [
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ],
      'display' => [
        'url_cutoff' => 80,
      ],
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ],
    'translatable' => 0,
    'type' => 'link_field',
  ];

  // Exported field_base: 'field_prod_where_to_buy_button'.
  $field_bases['field_prod_where_to_buy_button'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_where_to_buy_button',
    'indexes' => [
      'value' => [
        0 => 'value',
      ],
    ],
    'locked' => 0,
    'module' => 'list',
    'settings' => [
      'allowed_values' => [
        0 => '',
        1 => '',
      ],
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'list_boolean',
  ];

  // Exported field_base: 'field_prod_wtb_img'.
  $field_bases['field_prod_wtb_img'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_wtb_img',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_prod_wtb_online'.
  $field_bases['field_prod_wtb_online'] = [
    'active' => 1,
    'cardinality' => 3,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prod_wtb_online',
    'indexes' => [],
    'locked' => 0,
    'module' => 'link',
    'settings' => [
      'attributes' => [
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ],
      'display' => [
        'url_cutoff' => 80,
      ],
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ],
    'translatable' => 0,
    'type' => 'link_field',
  ];

  // Exported field_base: 'field_prodlang_btnact_disable'.
  $field_bases['field_prodlang_btnact_disable'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prodlang_btnact_disable',
    'indexes' => [
      'value' => [
        0 => 'value',
      ],
    ],
    'locked' => 0,
    'module' => 'list',
    'settings' => [
      'allowed_values' => [
        'Yes' => 'Yes',
        'No' => 'No',
      ],
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'list_text',
  ];

  // Exported field_base: 'field_prodlang_sol_disable'.
  $field_bases['field_prodlang_sol_disable'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_prodlang_sol_disable',
    'indexes' => [
      'value' => [
        0 => 'value',
      ],
    ],
    'locked' => 0,
    'module' => 'list',
    'settings' => [
      'allowed_values' => [
        'Yes' => 'Yes',
        'No' => 'No',
      ],
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'list_text',
  ];

  // Exported field_base: 'field_product_attributes'.
  $field_bases['field_product_attributes'] = [
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_product_attributes',
    'indexes' => [
      'target_id' => [
        0 => 'target_id',
      ],
    ],
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => [
      'entity_translation_sync' => FALSE,
      'handler' => 'base',
      'handler_settings' => [
        'behaviors' => [
          'views-select-list' => [
            'status' => 0,
          ],
        ],
        'sort' => [
          'type' => 'none',
        ],
        'target_bundles' => [],
      ],
      'target_type' => 'taxonomy_term',
    ],
    'translatable' => 0,
    'type' => 'entityreference',
  ];

  // Exported field_base: 'field_product_details'.
  $field_bases['field_product_details'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_product_details',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 1,
    'type' => 'text_long',
  ];

  // Exported field_base: 'field_product_family'.
  $field_bases['field_product_family'] = [
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_product_family',
    'indexes' => [
      'target_id' => [
        0 => 'target_id',
      ],
    ],
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => [
      'entity_translation_sync' => FALSE,
      'handler' => 'base',
      'handler_settings' => [
        'behaviors' => [
          'views-select-list' => [
            'status' => 0,
          ],
        ],
        'sort' => [
          'type' => 'none',
        ],
        'target_bundles' => [
          'product_family' => 'product_family',
        ],
      ],
      'target_type' => 'node',
    ],
    'translatable' => 0,
    'type' => 'entityreference',
  ];

  // Exported field_base: 'field_product_image'.
  $field_bases['field_product_image'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_product_image',
    'indexes' => [
      'fid' => [
        0 => 'fid',
      ],
    ],
    'locked' => 0,
    'module' => 'image',
    'settings' => [
      'default_image' => 0,
      'entity_translation_sync' => [
        0 => 'fid',
      ],
      'uri_scheme' => 'public',
    ],
    'translatable' => 0,
    'type' => 'image',
  ];

  // Exported field_base: 'field_product_language_override'.
  $field_bases['field_product_language_override'] = [
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_product_language_override',
    'indexes' => [
      'target_id' => [
        0 => 'target_id',
      ],
    ],
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => [
      'entity_translation_sync' => FALSE,
      'handler' => 'views',
      'handler_settings' => [
        'behaviors' => [
          'views-select-list' => [
            'status' => 0,
          ],
        ],
        'view' => [
          'args' => [],
          'display_name' => 'product_reference',
          'view_name' => 'translations_hack',
        ],
      ],
      'target_type' => 'node',
    ],
    'translatable' => 0,
    'type' => 'entityreference',
  ];

  // Exported field_base: 'field_product_specs'.
  $field_bases['field_product_specs'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_product_specs',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 0,
    'type' => 'text_long',
  ];

  // Exported field_base: 'field_product_status'.
  $field_bases['field_product_status'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_product_status',
    'indexes' => [
      'target_id' => [
        0 => 'target_id',
      ],
    ],
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => [
      'entity_translation_sync' => FALSE,
      'handler' => 'base',
      'handler_settings' => [
        'behaviors' => [
          'views-select-list' => [
            'status' => 0,
          ],
        ],
        'sort' => [
          'type' => 'none',
        ],
        'target_bundles' => [
          'product_status' => 'product_status',
        ],
      ],
      'target_type' => 'taxonomy_term',
    ],
    'translatable' => 0,
    'type' => 'entityreference',
  ];

  // Exported field_base: 'field_product_sub_types'.
  $field_bases['field_product_sub_types'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_product_sub_types',
    'indexes' => [
      'target_id' => [
        0 => 'target_id',
      ],
    ],
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => [
      'entity_translation_sync' => FALSE,
      'handler' => 'base',
      'handler_settings' => [
        'behaviors' => [
          'views-select-list' => [
            'status' => 0,
          ],
        ],
        'sort' => [
          'type' => 'none',
        ],
        'target_bundles' => [
          'product_sub_types' => 'product_sub_types',
        ],
      ],
      'target_type' => 'taxonomy_term',
    ],
    'translatable' => 0,
    'type' => 'entityreference',
  ];

  // Exported field_base: 'field_related_products'.
  $field_bases['field_related_products'] = [
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_related_products',
    'indexes' => [
      'target_id' => [
        0 => 'target_id',
      ],
    ],
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => [
      'entity_translation_sync' => FALSE,
      'handler' => 'base',
      'handler_settings' => [
        'behaviors' => [
          'views-select-list' => [
            'status' => 1,
          ],
        ],
        'sort' => [
          'type' => 'none',
        ],
        'target_bundles' => [
          'product_display' => 'product_display',
        ],
      ],
      'target_type' => 'node',
    ],
    'translatable' => 0,
    'type' => 'entityreference',
  ];

  // Exported field_base: 'field_source_product'.
  $field_bases['field_source_product'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_source_product',
    'indexes' => [
      'target_id' => [
        0 => 'target_id',
      ],
    ],
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => [
      'entity_translation_sync' => FALSE,
      'handler' => 'base',
      'handler_settings' => [
        'behaviors' => [
          'views-select-list' => [
            'status' => 1,
          ],
        ],
        'sort' => [
          'type' => 'none',
        ],
        'target_bundles' => [
          'product_display' => 'product_display',
        ],
      ],
      'target_type' => 'node',
    ],
    'translatable' => 0,
    'type' => 'entityreference',
  ];

  // Exported field_base: 'field_tracking_code'.
  $field_bases['field_tracking_code'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_tracking_code',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
    ],
    'translatable' => 1,
    'type' => 'text_long',
  ];

  // Exported field_base: 'field_wtb_ps_model_sku'.
  $field_bases['field_wtb_ps_model_sku'] = [
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => [],
    'field_name' => 'field_wtb_ps_model_sku',
    'indexes' => [
      'format' => [
        0 => 'format',
      ],
    ],
    'locked' => 0,
    'module' => 'text',
    'settings' => [
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ],
    'translatable' => 0,
    'type' => 'text',
  ];

  return $field_bases;
}
