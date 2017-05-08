<?php
/**
 * @file
 * products.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function products_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'body'
  $field_bases['body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'node',
    ),
    'field_name' => 'body',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_business_entity'
  $field_bases['field_business_entity'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_business_entity',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'business_entity',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_conversion_code'
  $field_bases['field_conversion_code'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_conversion_code',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => '',
      'text_processing' => 1,
    ),
    'translatable' => 0,
    'type' => 'text_long',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_do_not_distribute'
  $field_bases['field_do_not_distribute'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_do_not_distribute',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => 'cck_allowed_values_php',
      'allowed_values_php' => 'if (function_exitsts(\'location_get_iso3166_list\')) return location_get_iso3166_list(); //Location module is required',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_onyxhierarchyid'
  $field_bases['field_onyxhierarchyid'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_onyxhierarchyid',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_php' => '',
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
    ),
    'translatable' => 0,
    'type' => 'number_integer',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_pcatid'
  $field_bases['field_pcatid'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_pcatid',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_php' => '',
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
    ),
    'translatable' => 0,
    'type' => 'number_integer',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_360_img_lg_1'
  $field_bases['field_prod_360_img_lg_1'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_360_img_lg_1',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_360_img_t_1'
  $field_bases['field_prod_360_img_t_1'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_360_img_t_1',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_btn_calltoaction'
  $field_bases['field_prod_btn_calltoaction'] = array(
    'active' => 1,
    'cardinality' => 4,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_btn_calltoaction',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_btn_cta_size'
  $field_bases['field_prod_btn_cta_size'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_btn_cta_size',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        '1 line' => '1 line',
        '2 lines' => '2 lines',
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'legacy_values' => array(),
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'list_text',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_lg_1'
  $field_bases['field_prod_carousel_img_lg_1'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_lg_1',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_prod_carousel_img_lg_10'
  $field_bases['field_prod_carousel_img_lg_10'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_lg_10',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 1,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_lg_2'
  $field_bases['field_prod_carousel_img_lg_2'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_lg_2',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 1,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_lg_3'
  $field_bases['field_prod_carousel_img_lg_3'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_lg_3',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 1,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_lg_4'
  $field_bases['field_prod_carousel_img_lg_4'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_lg_4',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 1,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_lg_5'
  $field_bases['field_prod_carousel_img_lg_5'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_lg_5',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 1,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_lg_6'
  $field_bases['field_prod_carousel_img_lg_6'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_lg_6',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 1,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_lg_7'
  $field_bases['field_prod_carousel_img_lg_7'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_lg_7',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 1,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_lg_8'
  $field_bases['field_prod_carousel_img_lg_8'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_lg_8',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 1,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_lg_9'
  $field_bases['field_prod_carousel_img_lg_9'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_lg_9',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 1,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_srt_1'
  $field_bases['field_prod_carousel_img_srt_1'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_srt_1',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
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
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'max' => 20,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_srt_10'
  $field_bases['field_prod_carousel_img_srt_10'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_srt_10',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
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
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'max' => 20,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_srt_2'
  $field_bases['field_prod_carousel_img_srt_2'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_srt_2',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
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
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'max' => 20,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_srt_3'
  $field_bases['field_prod_carousel_img_srt_3'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_srt_3',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
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
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'max' => 20,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_srt_4'
  $field_bases['field_prod_carousel_img_srt_4'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_srt_4',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
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
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'max' => 20,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_srt_5'
  $field_bases['field_prod_carousel_img_srt_5'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_srt_5',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
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
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'max' => 20,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_srt_6'
  $field_bases['field_prod_carousel_img_srt_6'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_srt_6',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
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
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'max' => 20,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_srt_7'
  $field_bases['field_prod_carousel_img_srt_7'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_srt_7',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
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
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'max' => 20,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_srt_8'
  $field_bases['field_prod_carousel_img_srt_8'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_srt_8',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
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
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'max' => 20,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_srt_9'
  $field_bases['field_prod_carousel_img_srt_9'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_srt_9',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
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
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'max' => 20,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_t_1'
  $field_bases['field_prod_carousel_img_t_1'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_t_1',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_t_10'
  $field_bases['field_prod_carousel_img_t_10'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_t_10',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_t_2'
  $field_bases['field_prod_carousel_img_t_2'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_t_2',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_t_3'
  $field_bases['field_prod_carousel_img_t_3'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_t_3',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_t_4'
  $field_bases['field_prod_carousel_img_t_4'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_t_4',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_t_5'
  $field_bases['field_prod_carousel_img_t_5'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_t_5',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_t_6'
  $field_bases['field_prod_carousel_img_t_6'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_t_6',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_t_7'
  $field_bases['field_prod_carousel_img_t_7'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_t_7',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_t_8'
  $field_bases['field_prod_carousel_img_t_8'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_t_8',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_carousel_img_t_9'
  $field_bases['field_prod_carousel_img_t_9'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_carousel_img_t_9',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_contact_sales_button'
  $field_bases['field_prod_contact_sales_button'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_contact_sales_button',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Off',
        1 => 'Display Contact Sales Button',
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'legacy_values' => array(),
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_ctab_data_1'
  $field_bases['field_prod_ctab_data_1'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_ctab_data_1',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => '',
      'text_processing' => 1,
    ),
    'translatable' => 0,
    'type' => 'text_long',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_ctab_data_2'
  $field_bases['field_prod_ctab_data_2'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_ctab_data_2',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => '',
      'text_processing' => 1,
    ),
    'translatable' => 0,
    'type' => 'text_long',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_ctab_data_3'
  $field_bases['field_prod_ctab_data_3'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_ctab_data_3',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => '',
      'text_processing' => 1,
    ),
    'translatable' => 0,
    'type' => 'text_long',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_ctab_data_4'
  $field_bases['field_prod_ctab_data_4'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_ctab_data_4',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => '',
      'text_processing' => 1,
    ),
    'translatable' => 0,
    'type' => 'text_long',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_ctab_data_5'
  $field_bases['field_prod_ctab_data_5'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_ctab_data_5',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => '',
      'text_processing' => '',
    ),
    'translatable' => 0,
    'type' => 'text_long',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_ctab_name_1'
  $field_bases['field_prod_ctab_name_1'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_ctab_name_1',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_ctab_name_2'
  $field_bases['field_prod_ctab_name_2'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_ctab_name_2',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_ctab_name_3'
  $field_bases['field_prod_ctab_name_3'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_ctab_name_3',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_ctab_name_4'
  $field_bases['field_prod_ctab_name_4'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_ctab_name_4',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_ctab_name_5'
  $field_bases['field_prod_ctab_name_5'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_ctab_name_5',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => '',
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_hide_models_accessory'
  $field_bases['field_prod_hide_models_accessory'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_hide_models_accessory',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 0,
        1 => 1,
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_prod_hub_img'
  $field_bases['field_prod_hub_img'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_hub_img',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'promotion_product',
  );

  // Exported field_base: 'field_prod_language'
  $field_bases['field_prod_language'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_language',
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'asset_gateway' => 0,
        'award' => 0,
        'blog_article' => 0,
        'digital_asset' => 0,
        'distributor' => 0,
        'edoc' => 0,
        'edoclanguage' => 0,
        'email_page' => 0,
        'event' => 0,
        'event_occurrence' => 0,
        'exp_ind' => 0,
        'exp_ind_lng' => 0,
        'exp_rle' => 0,
        'exp_rle_lng' => 0,
        'exp_tpc' => 0,
        'exp_tpc_lng' => 0,
        'expertise' => 0,
        'family' => 0,
        'feature' => 0,
        'homepage2013' => 0,
        'homepage2013language' => 0,
        'industry' => 0,
        'industrylanguage' => 0,
        'knowledge_base_article' => 0,
        'localized_email' => 0,
        'marketo_form' => 0,
        'microsite_page' => 0,
        'microsite_page_language' => 0,
        'microsite_story' => 0,
        'microsite_story_language' => 0,
        'page' => 0,
        'page_reg' => 0,
        'page_reg_lang' => 0,
        'pressrelease' => 0,
        'product' => 0,
        'product_distributor_group' => 0,
        'productlanguage' => 0,
        'productsubtype' => 0,
        'profile' => 0,
        'promotion' => 0,
        'promotion_form' => 0,
        'promotion_fulfillment' => 0,
        'promotion_product' => 0,
        'software_notifications' => 0,
        'story' => 0,
        'suite' => 0,
        'translation_text' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'admin_product_language',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_rating_review'
  $field_bases['field_prod_rating_review'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_rating_review',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'No',
        1 => 'Enable Ratings and Reviews',
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'legacy_values' => array(),
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_related_img'
  $field_bases['field_prod_related_img'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_related_img',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_relatedprod'
  $field_bases['field_prod_relatedprod'] = array(
    'active' => 1,
    'cardinality' => 6,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_relatedprod',
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'distributor' => 0,
        'event' => 0,
        'expertise' => 0,
        'family' => 0,
        'feature' => 0,
        'homepage' => 0,
        'image' => 0,
        'industry' => 0,
        'page' => 0,
        'pressrelease' => 0,
        'product' => 'product',
        'productsubtype' => 0,
        'promotion' => 0,
        'story' => 0,
        'suite' => 0,
      ),
      'view' => array(
        'args' => array(
          0 => '',
        ),
        'display_name' => 'default',
        'view_name' => '--',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_sol_desc_1'
  $field_bases['field_prod_sol_desc_1'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_sol_desc_1',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_sol_desc_2'
  $field_bases['field_prod_sol_desc_2'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_sol_desc_2',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_sol_desc_3'
  $field_bases['field_prod_sol_desc_3'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_sol_desc_3',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_sol_desc_4'
  $field_bases['field_prod_sol_desc_4'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_sol_desc_4',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_sol_link_1'
  $field_bases['field_prod_sol_link_1'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_sol_link_1',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_sol_link_2'
  $field_bases['field_prod_sol_link_2'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_sol_link_2',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_sol_link_3'
  $field_bases['field_prod_sol_link_3'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_sol_link_3',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_sol_link_4'
  $field_bases['field_prod_sol_link_4'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_sol_link_4',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_sol_title'
  $field_bases['field_prod_sol_title'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_sol_title',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => 255,
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_video_img_t_1'
  $field_bases['field_prod_video_img_t_1'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_video_img_t_1',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_video_lg_1'
  $field_bases['field_prod_video_lg_1'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_video_lg_1',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'description_field' => 0,
      'display_default' => 1,
      'display_field' => 1,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'file',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_video_youtube_url'
  $field_bases['field_prod_video_youtube_url'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_video_youtube_url',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_where_to_buy_button'
  $field_bases['field_prod_where_to_buy_button'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_where_to_buy_button',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Off',
        1 => 'Display Where To Buy Button',
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
      'legacy_values' => array(),
      'text_processing' => 0,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_wtb_img'
  $field_bases['field_prod_wtb_img'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_wtb_img',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => NULL,
      'description_field' => 0,
      'list_default' => 1,
      'list_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_prod_wtb_online'
  $field_bases['field_prod_wtb_online'] = array(
    'active' => 1,
    'cardinality' => 3,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_prod_wtb_online',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_product_adtracker'
  $field_bases['field_product_adtracker'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_product_adtracker',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => '',
      'text_processing' => 1,
    ),
    'translatable' => 0,
    'type' => 'text_long',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_product_ataglance'
  $field_bases['field_product_ataglance'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_product_ataglance',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => '',
      'text_processing' => 1,
    ),
    'translatable' => 0,
    'type' => 'text_long',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_product_desc'
  $field_bases['field_product_desc'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_product_desc',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => '',
      'text_processing' => 1,
    ),
    'translatable' => 0,
    'type' => 'text_long',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_product_details'
  $field_bases['field_product_details'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_product_details',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => '',
      'text_processing' => 1,
    ),
    'translatable' => 0,
    'type' => 'text_long',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_product_family'
  $field_bases['field_product_family'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_product_family',
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'asset_gateway' => 0,
        'award' => 0,
        'blog_article' => 0,
        'digital_asset' => 0,
        'distributor' => 0,
        'edoc' => 0,
        'edoclanguage' => 0,
        'email_page' => 0,
        'event' => 0,
        'event_occurrence' => 0,
        'exp_ind' => 0,
        'exp_ind_lng' => 0,
        'exp_rle' => 0,
        'exp_rle_lng' => 0,
        'exp_tpc' => 0,
        'exp_tpc_lng' => 0,
        'expertise' => 0,
        'family' => 0,
        'feature' => 0,
        'homepage2013' => 0,
        'homepage2013language' => 0,
        'industry' => 0,
        'industrylanguage' => 0,
        'knowledge_base_article' => 0,
        'localized_email' => 0,
        'marketo_form' => 0,
        'microsite_page' => 0,
        'microsite_page_language' => 0,
        'microsite_story' => 0,
        'microsite_story_language' => 0,
        'page' => 0,
        'page_reg' => 0,
        'page_reg_lang' => 0,
        'pressrelease' => 0,
        'product' => 0,
        'product_distributor_group' => 0,
        'productlanguage' => 0,
        'productsubtype' => 0,
        'profile' => 0,
        'promotion' => 0,
        'promotion_form' => 0,
        'promotion_fulfillment' => 0,
        'promotion_product' => 0,
        'software_notifications' => 0,
        'story' => 0,
        'suite' => 0,
        'translation_text' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => 'references_1',
        'view_name' => 'admin_family_ls_products',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
    'type_name' => 'product',
  );

  // Exported field_base: 'field_product_specs'
  $field_bases['field_product_specs'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_product_specs',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'allowed_values' => '',
      'allowed_values_php' => '',
      'max_length' => '',
      'text_processing' => 1,
    ),
    'translatable' => 0,
    'type' => 'text_long',
    'type_name' => 'product',
  );

  // Exported field_base: 'taxonomy_vocabulary_1'
  $field_bases['taxonomy_vocabulary_1'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'taxonomy_vocabulary_1',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'vocabulary_1',
          'parent' => 0,
        ),
      ),
      'required' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'taxonomy_vocabulary_6'
  $field_bases['taxonomy_vocabulary_6'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'taxonomy_vocabulary_6',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'vocabulary_6',
          'parent' => 0,
        ),
      ),
      'required' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}
