<?php
/**
 * @file
 * products.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function products_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-product-body'
  $field_instances['node-product-body'] = array(
    'bundle' => 'product',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Use this content type for all product pages.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 27,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 27,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 27,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 27,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 27,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => 0,
    'settings' => array(
      'display_summary' => TRUE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 28,
    ),
  );

  // Exported field_instance: 'node-product-field_business_entity'
  $field_instances['node-product-field_business_entity'] = array(
    'bundle' => 'product',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 76,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'print' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'rss' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_index' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_business_entity',
    'label' => 'Business Entity',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-product-field_conversion_code'
  $field_instances['node-product-field_conversion_code'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_conversion_code][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'fnet_content_alter',
        'settings' => array(),
        'type' => 'text_raw',
        'weight' => 7,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_conversion_code',
    'label' => 'Conversion Code',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 7,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 12,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-product-field_do_not_distribute'
  $field_instances['node-product-field_do_not_distribute'] = array(
    'bundle' => 'product',
    'default_value' => NULL,
    'default_value_function' => '',
    'default_value_php' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 74,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 74,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 74,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 74,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 76,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 74,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_do_not_distribute',
    'label' => 'Do not distribute',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multiselect',
      'settings' => array(),
      'type' => 'multiselect',
      'weight' => 33,
    ),
  );

  // Exported field_instance: 'node-product-field_onyxhierarchyid'
  $field_instances['node-product-field_onyxhierarchyid'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_onyxhierarchyid][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_onyxhierarchyid',
    'label' => 'Onyx Hierarchy ID',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 0,
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'number',
      'weight' => 0,
    ),
    'widget_type' => 'number',
  );

  // Exported field_instance: 'node-product-field_pcatid'
  $field_instances['node-product-field_pcatid'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pcatid][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'PCATID from legacy FNET system.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -1,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'hidden',
        'weight' => -1,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -1,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pcatid',
    'label' => 'PCATID',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => -1,
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'number',
      'weight' => -1,
    ),
    'widget_type' => 'number',
  );

  // Exported field_instance: 'node-product-field_prod_360_img_lg_1'
  $field_instances['node-product-field_prod_360_img_lg_1'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prod_360_img_lg_1][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Example Path (URL): http://images.flukenetworks.com/360/Products/XG/config.xml',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 55,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 54,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 55,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 55,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 63,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 54,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 54,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_360_img_lg_1',
    'label' => '360 Image - Path to XML',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 54,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 200,
      ),
      'type' => 'text_textfield',
      'weight' => 54,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-product-field_prod_360_img_t_1'
  $field_instances['node-product-field_prod_360_img_t_1'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 16,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 55,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 16,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 16,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 64,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 55,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 55,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_360_img_t_1',
    'label' => '3D (360) Thumb Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '73x58',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 55,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 55,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_btn_calltoaction'
  $field_instances['node-product-field_prod_btn_calltoaction'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'title' => '',
        'url' => '',
        'attributes' => array(
          'target' => '_blank',
        ),
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 25,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 25,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 25,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 25,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 62,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 53,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 53,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_btn_calltoaction',
    'label' => 'BTN Call to Action',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'user',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => '',
      ),
      'enable_tokens' => 0,
      'title' => 'required',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'weight' => 53,
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'link_field',
      'weight' => 53,
    ),
    'widget_type' => 'link',
  );

  // Exported field_instance: 'node-product-field_prod_btn_cta_size'
  $field_instances['node-product-field_prod_btn_cta_size'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '1 line',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 52,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 61,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_btn_cta_size',
    'label' => 'Button Size',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 52,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'options_select',
      'weight' => 52,
    ),
    'widget_type' => 'optionwidgets_buttons',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_lg_1'
  $field_instances['node-product-field_prod_carousel_img_lg_1'] = array(
    'bundle' => 'product',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 75,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'print' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'rss' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_index' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_lg_1',
    'label' => 'Carousel Image LG-1',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 76,
    ),
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_lg_10'
  $field_instances['node-product-field_prod_carousel_img_lg_10'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 16,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 40,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 16,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 16,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 48,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 40,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 40,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_lg_10',
    'label' => 'Carousel Image LG-10',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'images/prod_carousel',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '488x385',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 40,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 103,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_lg_2'
  $field_instances['node-product-field_prod_carousel_img_lg_2'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 19,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 16,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 19,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 19,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_lg_2',
    'label' => 'Carousel Image LG-2',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'images/prod_carousel',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '488x385',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 16,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 79,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_lg_3'
  $field_instances['node-product-field_prod_carousel_img_lg_3'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 22,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 19,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 22,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 22,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_lg_3',
    'label' => 'Carousel Image LG-3',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'images/prod_carousel',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '488x385',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 19,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 82,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_lg_4'
  $field_instances['node-product-field_prod_carousel_img_lg_4'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 25,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 22,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 25,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 25,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_lg_4',
    'label' => 'Carousel Image LG-4',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'images/prod_carousel',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '488x385',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 22,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 85,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_lg_5'
  $field_instances['node-product-field_prod_carousel_img_lg_5'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 28,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 25,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 28,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 28,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_lg_5',
    'label' => 'Carousel Image LG-5',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'images/prod_carousel',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '488x385',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 25,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 88,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_lg_6'
  $field_instances['node-product-field_prod_carousel_img_lg_6'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 31,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 28,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 31,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 31,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 28,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_lg_6',
    'label' => 'Carousel Image LG-6',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'images/prod_carousel',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '488x385',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 28,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 91,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_lg_7'
  $field_instances['node-product-field_prod_carousel_img_lg_7'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 34,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 31,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 34,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 34,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 31,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_lg_7',
    'label' => 'Carousel Image LG-7',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'images/prod_carousel',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '488x385',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 31,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 94,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_lg_8'
  $field_instances['node-product-field_prod_carousel_img_lg_8'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 37,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 34,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 37,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 37,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 34,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_lg_8',
    'label' => 'Carousel Image LG-8',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'images/prod_carousel',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '488x385',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 34,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 97,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_lg_9'
  $field_instances['node-product-field_prod_carousel_img_lg_9'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 15,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 37,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 15,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 15,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 45,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 37,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 37,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_lg_9',
    'label' => 'Carousel Image LG-9',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'images/prod_carousel',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '488x385',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 37,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 100,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_srt_1'
  $field_instances['node-product-field_prod_carousel_img_srt_1'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => 20,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_srt_1',
    'label' => 'Carousel Image Sort-1',
    'required' => 0,
    'settings' => array(
      'max' => 20,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 15,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'options_select',
      'weight' => 78,
    ),
    'widget_type' => 'optionwidgets_select',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_srt_10'
  $field_instances['node-product-field_prod_carousel_img_srt_10'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => 20,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_srt_10',
    'label' => 'Carousel Image Sort-10',
    'required' => 0,
    'settings' => array(
      'max' => 20,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 42,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'options_select',
      'weight' => 105,
    ),
    'widget_type' => 'optionwidgets_select',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_srt_2'
  $field_instances['node-product-field_prod_carousel_img_srt_2'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => 20,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 21,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_srt_2',
    'label' => 'Carousel Image Sort-2',
    'required' => 0,
    'settings' => array(
      'max' => 20,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 18,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'options_select',
      'weight' => 81,
    ),
    'widget_type' => 'optionwidgets_select',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_srt_3'
  $field_instances['node-product-field_prod_carousel_img_srt_3'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => 20,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 24,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_srt_3',
    'label' => 'Carousel Image Sort-3',
    'required' => 0,
    'settings' => array(
      'max' => 20,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 21,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'options_select',
      'weight' => 84,
    ),
    'widget_type' => 'optionwidgets_select',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_srt_4'
  $field_instances['node-product-field_prod_carousel_img_srt_4'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => 20,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_srt_4',
    'label' => 'Carousel Image Sort-4',
    'required' => 0,
    'settings' => array(
      'max' => 20,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 24,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'options_select',
      'weight' => 87,
    ),
    'widget_type' => 'optionwidgets_select',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_srt_5'
  $field_instances['node-product-field_prod_carousel_img_srt_5'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => 20,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_srt_5',
    'label' => 'Carousel Image Sort-5',
    'required' => 0,
    'settings' => array(
      'max' => 20,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 27,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'options_select',
      'weight' => 90,
    ),
    'widget_type' => 'optionwidgets_select',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_srt_6'
  $field_instances['node-product-field_prod_carousel_img_srt_6'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => 20,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_srt_6',
    'label' => 'Carousel Image Sort-6',
    'required' => 0,
    'settings' => array(
      'max' => 20,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 30,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'options_select',
      'weight' => 93,
    ),
    'widget_type' => 'optionwidgets_select',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_srt_7'
  $field_instances['node-product-field_prod_carousel_img_srt_7'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => 20,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_srt_7',
    'label' => 'Carousel Image Sort-7',
    'required' => 0,
    'settings' => array(
      'max' => 20,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 33,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'options_select',
      'weight' => 96,
    ),
    'widget_type' => 'optionwidgets_select',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_srt_8'
  $field_instances['node-product-field_prod_carousel_img_srt_8'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => 20,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 39,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_srt_8',
    'label' => 'Carousel Image Sort-8',
    'required' => 0,
    'settings' => array(
      'max' => 20,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 36,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'options_select',
      'weight' => 99,
    ),
    'widget_type' => 'optionwidgets_select',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_srt_9'
  $field_instances['node-product-field_prod_carousel_img_srt_9'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => 20,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_srt_9',
    'label' => 'Carousel Image Sort-9',
    'required' => 0,
    'settings' => array(
      'max' => 20,
      'min' => 1,
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 39,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'options_select',
      'weight' => 102,
    ),
    'widget_type' => 'optionwidgets_select',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_t_1'
  $field_instances['node-product-field_prod_carousel_img_t_1'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 41,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 14,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 41,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 41,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 19,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_t_1',
    'label' => 'Carousel Image Thumb-1',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/prod_carousel/thumb',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '73x58',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 14,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 77,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_t_10'
  $field_instances['node-product-field_prod_carousel_img_t_10'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 17,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 41,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 17,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 17,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 49,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 41,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 41,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_t_10',
    'label' => 'Carousel Image Thumb-10',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/prod_carousel/thumb',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '73x58',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 41,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 104,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_t_2'
  $field_instances['node-product-field_prod_carousel_img_t_2'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 20,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 17,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 20,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 20,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_t_2',
    'label' => 'Carousel Image Thumb-2',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/prod_carousel/thumb',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '73x58',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 17,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 80,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_t_3'
  $field_instances['node-product-field_prod_carousel_img_t_3'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 23,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 20,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 23,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 23,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 25,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 20,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_t_3',
    'label' => 'Carousel Image Thumb-3',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/prod_carousel/thumb',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '73x58',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 20,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 83,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_t_4'
  $field_instances['node-product-field_prod_carousel_img_t_4'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 26,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 23,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 26,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 26,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_t_4',
    'label' => 'Carousel Image Thumb-4',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/prod_carousel/thumb',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '73x58',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 23,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 86,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_t_5'
  $field_instances['node-product-field_prod_carousel_img_t_5'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 29,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 26,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 29,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 29,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 33,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 26,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_t_5',
    'label' => 'Carousel Image Thumb-5',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/prod_carousel/thumb',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '73x58',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 26,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 89,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_t_6'
  $field_instances['node-product-field_prod_carousel_img_t_6'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 32,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 29,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 32,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 32,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 36,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_t_6',
    'label' => 'Carousel Image Thumb-6',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/prod_carousel/thumb',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '73x58',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 29,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 92,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_t_7'
  $field_instances['node-product-field_prod_carousel_img_t_7'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 35,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 32,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 35,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 35,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 40,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_t_7',
    'label' => 'Carousel Image Thumb-7',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/prod_carousel/thumb',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '73x58',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 32,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 95,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_t_8'
  $field_instances['node-product-field_prod_carousel_img_t_8'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 38,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 35,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 38,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 38,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 43,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_t_8',
    'label' => 'Carousel Image Thumb-8',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/prod_carousel/thumb',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '73x58',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 35,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 98,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_carousel_img_t_9'
  $field_instances['node-product-field_prod_carousel_img_t_9'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 15,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 38,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 15,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 15,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 46,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 38,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 38,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_carousel_img_t_9',
    'label' => 'Carousel Image Thumb-9',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/prod_carousel/thumb',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '73x58',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 38,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 101,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_contact_sales_button'
  $field_instances['node-product-field_prod_contact_sales_button'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => 'off',
      ),
    ),
    'deleted' => 0,
    'description' => '<strong>Note:</strong> If any Online Store is present for the region, then the Contact Sales button will not display even if it is checked.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 7,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 4,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_contact_sales_button',
    'label' => 'Contact Sales Button',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 4,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
        'display_label' => 0,
      ),
      'type' => 'options_buttons',
      'weight' => 9,
    ),
    'widget_type' => 'optionwidgets_onoff',
  );

  // Exported field_instance: 'node-product-field_prod_ctab_data_1'
  $field_instances['node-product-field_prod_ctab_data_1'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prod_ctab_data_1][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 46,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 44,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 46,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 46,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 44,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 44,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_ctab_data_1',
    'label' => 'CustomTab Data-1',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 44,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 44,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-product-field_prod_ctab_data_2'
  $field_instances['node-product-field_prod_ctab_data_2'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prod_ctab_data_2][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 48,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 46,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 48,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 48,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 54,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 46,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 46,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_ctab_data_2',
    'label' => 'CustomTab Data-2',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 46,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 46,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-product-field_prod_ctab_data_3'
  $field_instances['node-product-field_prod_ctab_data_3'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prod_ctab_data_3][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 50,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 48,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 50,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 50,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 56,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 48,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 48,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_ctab_data_3',
    'label' => 'CustomTab Data-3',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 48,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 48,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-product-field_prod_ctab_data_4'
  $field_instances['node-product-field_prod_ctab_data_4'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prod_ctab_data_4][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 52,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 50,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 52,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 52,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 58,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 50,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 50,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_ctab_data_4',
    'label' => 'CustomTab Data-4',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 50,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 50,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-product-field_prod_ctab_data_5'
  $field_instances['node-product-field_prod_ctab_data_5'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 43,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 52,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 43,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 43,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 60,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_ctab_data_5',
    'label' => 'CustomTab Data-5',
    'required' => 0,
    'settings' => array(
      'text_processing' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 52,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'rows' => NULL,
        'size' => NULL,
      ),
      'type' => 'text_textarea',
      'weight' => 52,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-product-field_prod_ctab_name_1'
  $field_instances['node-product-field_prod_ctab_name_1'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prod_ctab_name_1][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 45,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 43,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 45,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 45,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 51,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 43,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 43,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_ctab_name_1',
    'label' => 'CustomTab Name-1',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 43,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 43,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-product-field_prod_ctab_name_2'
  $field_instances['node-product-field_prod_ctab_name_2'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prod_ctab_name_2][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 47,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 45,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 47,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 47,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 53,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 45,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 45,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_ctab_name_2',
    'label' => 'CustomTab Name-2',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 45,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 45,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-product-field_prod_ctab_name_3'
  $field_instances['node-product-field_prod_ctab_name_3'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prod_ctab_name_3][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 49,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 47,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 49,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 49,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 55,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 47,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 47,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_ctab_name_3',
    'label' => 'CustomTab Name-3',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 47,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 47,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-product-field_prod_ctab_name_4'
  $field_instances['node-product-field_prod_ctab_name_4'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prod_ctab_name_4][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 51,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 49,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 51,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 51,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 57,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 49,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 49,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_ctab_name_4',
    'label' => 'CustomTab Name-4',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 49,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 49,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-product-field_prod_ctab_name_5'
  $field_instances['node-product-field_prod_ctab_name_5'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 51,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 59,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 51,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 51,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_ctab_name_5',
    'label' => 'CustomTab Name-5',
    'required' => 0,
    'settings' => array(
      'text_processing' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 51,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'rows' => NULL,
        'size' => NULL,
      ),
      'type' => 'text_textfield',
      'weight' => 51,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-product-field_prod_hide_models_accessory'
  $field_instances['node-product-field_prod_hide_models_accessory'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'default_value_function' => '',
    'default_value_php' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 77,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'print' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'rss' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_index' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_hide_models_accessory',
    'label' => 'Hide Models & Accessories',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'node-product-field_prod_hub_img'
  $field_instances['node-product-field_prod_hub_img'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 22,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 10,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 10,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 27,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 22,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_hub_img',
    'label' => 'Hub Image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/prod/hub',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '146x116',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 22,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 23,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_language'
  $field_instances['node-product-field_prod_language'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'nid' => NULL,
      ),
    ),
    'deleted' => 0,
    'description' => '<ul>
<li>en-us (<strong>English/United States</strong>)</li>
<li>en-au (<strong>English/Australia</strong>)</li>
<li>en-ca (<strong>English/Canada</strong>)</li>
<li>en-eu (<strong>English/Europe</strong>)</li>
<li>en-in (<strong>English/India</strong>)</li>
<li>en-ln (<strong>English/Latin America</strong>)</li>
<li>en-su (<strong>English/Southeast Asia</strong>)</li>
<li>fr-eu (<strong>French/Europe</strong>)</li>
<li>fr-ca (<strong>French/Canada</strong>)</li>
<li>de-eu (<strong>German/Europe</strong>)</li>
<li>es-eu (<strong>Spanish/Europe</strong>)</li>
<li>es-ln (<strong>Spanish/Latin America</strong>)</li>
<li>pt-eu (<strong>Portuguese/Europe</strong>)</li>
<li>pt-br (<strong>Portuguese/Brazil</strong>)</li>
<li>cn-zh (<strong>Chinese/China</strong>)</li>
<li>jp-ja (<strong>Japanese/Japan</strong>)</li>
<li>ko-kr (<strong>Korean/Korea</strong>)</li>
<li>ru-ru (<strong>Russian/Russia</strong>)</li>
</ul>',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -1,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -1,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_language',
    'label' => 'Language Override',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => -1,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'options_buttons',
      'weight' => 2,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-product-field_prod_rating_review'
  $field_instances['node-product-field_prod_rating_review'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => NULL,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 57,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 65,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 57,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 57,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_rating_review',
    'label' => 'Enable Ratings and Reviews',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 57,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
        'display_label' => 0,
      ),
      'type' => 'options_buttons',
      'weight' => 57,
    ),
    'widget_type' => 'optionwidgets_onoff',
  );

  // Exported field_instance: 'node-product-field_prod_related_img'
  $field_instances['node-product-field_prod_related_img'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 20,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 23,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 20,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 20,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 30,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 23,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_related_img',
    'label' => 'Related Product Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/prod/related',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '122x96',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 23,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 24,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_relatedprod'
  $field_instances['node-product-field_prod_relatedprod'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'nid' => '',
      ),
    ),
    'deleted' => 0,
    'description' => 'Choose 4 related products',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 6,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 18,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 6,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 6,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_plain',
        'weight' => 4,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_relatedprod',
    'label' => 'Releated Products',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 18,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'options_buttons',
      'weight' => 18,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-product-field_prod_sol_desc_1'
  $field_instances['node-product-field_prod_sol_desc_1'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prod_sol_desc_1][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 22,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 60,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 22,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 22,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 67,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 60,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 60,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_sol_desc_1',
    'label' => 'Solution Description #1',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 60,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 60,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-product-field_prod_sol_desc_2'
  $field_instances['node-product-field_prod_sol_desc_2'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prod_sol_desc_2][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 24,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 62,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 24,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 24,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 69,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 62,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 62,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_sol_desc_2',
    'label' => 'Solution Description #2',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 62,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 62,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-product-field_prod_sol_desc_3'
  $field_instances['node-product-field_prod_sol_desc_3'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prod_sol_desc_3][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 26,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 64,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 26,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 26,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 71,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 64,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 64,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_sol_desc_3',
    'label' => 'Solution Description #3',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 64,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 64,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-product-field_prod_sol_desc_4'
  $field_instances['node-product-field_prod_sol_desc_4'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prod_sol_desc_4][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 19,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 66,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 19,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 19,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 73,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 66,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 66,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_sol_desc_4',
    'label' => 'Solution Description #4',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 66,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 66,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-product-field_prod_sol_link_1'
  $field_instances['node-product-field_prod_sol_link_1'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'title' => '',
        'url' => '',
        'attributes' => array(
          'target' => '_blank',
        ),
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 21,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 21,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 21,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 21,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 66,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 59,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 59,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_sol_link_1',
    'label' => 'Solution Link #1',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'user',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => '',
      ),
      'enable_tokens' => 0,
      'title' => 'required',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'weight' => 59,
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'link_field',
      'weight' => 59,
    ),
    'widget_type' => 'link',
  );

  // Exported field_instance: 'node-product-field_prod_sol_link_2'
  $field_instances['node-product-field_prod_sol_link_2'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'title' => '',
        'url' => '',
        'attributes' => array(
          'target' => '_blank',
        ),
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 23,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 23,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 23,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 23,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 68,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 61,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 61,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_sol_link_2',
    'label' => 'Solution Link #2',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'user',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => '',
      ),
      'enable_tokens' => 0,
      'title' => 'required',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'weight' => 61,
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'link_field',
      'weight' => 61,
    ),
    'widget_type' => 'link',
  );

  // Exported field_instance: 'node-product-field_prod_sol_link_3'
  $field_instances['node-product-field_prod_sol_link_3'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'title' => '',
        'url' => '',
        'attributes' => array(
          'target' => '_blank',
        ),
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 25,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 25,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 25,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 25,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 70,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 63,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 63,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_sol_link_3',
    'label' => 'Solution Link #3',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'user',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => '',
      ),
      'enable_tokens' => 0,
      'title' => 'required',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'weight' => 63,
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'link_field',
      'weight' => 63,
    ),
    'widget_type' => 'link',
  );

  // Exported field_instance: 'node-product-field_prod_sol_link_4'
  $field_instances['node-product-field_prod_sol_link_4'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'title' => '',
        'url' => '',
        'attributes' => array(
          'target' => '_blank',
        ),
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 18,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 18,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 18,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 18,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 72,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 65,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 65,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_sol_link_4',
    'label' => 'Solution Link #4',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'user',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => '',
      ),
      'enable_tokens' => 0,
      'title' => 'required',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'weight' => 65,
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'link_field',
      'weight' => 65,
    ),
    'widget_type' => 'link',
  );

  // Exported field_instance: 'node-product-field_prod_sol_title'
  $field_instances['node-product-field_prod_sol_title'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => 'Solutions',
        '_error_element' => 'default_value_widget][field_prod_sol_title][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 58,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 5,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 58,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 58,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_sol_title',
    'label' => 'Solutions Title',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 58,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 58,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-product-field_prod_video_img_t_1'
  $field_instances['node-product-field_prod_video_img_t_1'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -5,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 72,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 72,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -5,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 74,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 72,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 72,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_video_img_t_1',
    'label' => 'Video Image Thumb',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '73x58',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 72,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 72,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_video_lg_1'
  $field_instances['node-product-field_prod_video_lg_1'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 27,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 74,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 27,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 27,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 77,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 74,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 74,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_video_lg_1',
    'label' => 'Video File',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'swf',
      'max_filesize' => '50M',
      'user_register_form' => FALSE,
    ),
    'weight' => 74,
    'widget' => array(
      'active' => 0,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'bar',
      ),
      'type' => 'file_generic',
      'weight' => 74,
    ),
    'widget_type' => 'filefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_video_youtube_url'
  $field_instances['node-product-field_prod_video_youtube_url'] = array(
    'bundle' => 'product',
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
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 73,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 73,
      ),
      'print' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 73,
      ),
      'rss' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 73,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 75,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 73,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 73,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_video_youtube_url',
    'label' => 'YouTube Embeded URL',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 250,
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
    'weight' => 73,
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'link_field',
      'weight' => 73,
    ),
    'widget_type' => 'link',
  );

  // Exported field_instance: 'node-product-field_prod_where_to_buy_button'
  $field_instances['node-product-field_prod_where_to_buy_button'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => 'off',
      ),
    ),
    'deleted' => 0,
    'description' => '<strong>Note:</strong> If any Online Store is present for the region, then the Where to Buy button will not display even if it is checked. Instead, this will be included as a link titled "See more online resellers or buy locally".',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 7,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 5,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_where_to_buy_button',
    'label' => 'Where to Buy Button',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 5,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
        'display_label' => 0,
      ),
      'type' => 'options_buttons',
      'weight' => 10,
    ),
    'widget_type' => 'optionwidgets_onoff',
  );

  // Exported field_instance: 'node-product-field_prod_wtb_img'
  $field_instances['node-product-field_prod_wtb_img'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => 'If this field left blank, WTB will use the image from carousel image #1',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 28,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 7,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 7,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 28,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_wtb_img',
    'label' => 'Where To Buy Product Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'images/wtb',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '488x385',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 7,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 7,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-product-field_prod_wtb_online'
  $field_instances['node-product-field_prod_wtb_online'] = array(
    'bundle' => 'product',
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
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 0,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 0,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 0,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_wtb_online',
    'label' => 'Online Stores',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 255,
      ),
      'enable_tokens' => 0,
      'title' => 'required',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'weight' => 6,
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'link_field',
      'weight' => 11,
    ),
    'widget_type' => 'link',
  );

  // Exported field_instance: 'node-product-field_product_adtracker'
  $field_instances['node-product-field_product_adtracker'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_product_adtracker][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'fnet_content_alter',
        'settings' => array(),
        'type' => 'text_raw',
        'weight' => 29,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 37,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 29,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_product_adtracker',
    'label' => 'Ad Tracking Code',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 29,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 29,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-product-field_product_ataglance'
  $field_instances['node-product-field_product_ataglance'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        'format' => 1,
        '_error_element' => 'default_value_widget][field_product_ataglance][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'At a glance bullets for right side of product page',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 24,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 24,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 24,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_product_ataglance',
    'label' => 'At a Glance',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 2,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 20,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 7,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-product-field_product_desc'
  $field_instances['node-product-field_product_desc'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_product_desc][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 1,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_product_desc',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 1,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 6,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-product-field_product_details'
  $field_instances['node-product-field_product_details'] = array(
    'bundle' => 'product',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<strong>Preview <a href=\'/products/product_features/[current-page:url:args:value:1]\' target=\'_new\'>All Product Features</a></strong>',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 2,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_product_details',
    'label' => 'Details',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 9,
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
      ),
      'type' => 'text_textarea',
      'weight' => 14,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-product-field_product_family'
  $field_instances['node-product-field_product_family'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'nid' => NULL,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 12,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 9,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 9,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_plain',
        'weight' => 3,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_product_family',
    'label' => 'Family',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 12,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'options_buttons',
      'weight' => 18,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-product-field_product_specs'
  $field_instances['node-product-field_product_specs'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        'format' => 1,
        '_error_element' => 'default_value_widget][field_product_specs][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_product_specs',
    'label' => 'Specs',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 10,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 20,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 15,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-product-taxonomy_vocabulary_1'
  $field_instances['node-product-taxonomy_vocabulary_1'] = array(
    'bundle' => 'product',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 10,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'taxonomy_vocabulary_1',
    'label' => 'Product Status',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-product-taxonomy_vocabulary_6'
  $field_instances['node-product-taxonomy_vocabulary_6'] = array(
    'bundle' => 'product',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 10,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'token' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'taxonomy_vocabulary_6',
    'label' => 'Product Attributes',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('360 Image - Path to XML');
  t('3D (360) Thumb Image');
  t('<strong>Note:</strong> If any Online Store is present for the region, then the Contact Sales button will not display even if it is checked.');
  t('<strong>Note:</strong> If any Online Store is present for the region, then the Where to Buy button will not display even if it is checked. Instead, this will be included as a link titled "See more online resellers or buy locally".');
  t('<strong>Preview <a href=\'/products/product_features/[current-page:url:args:value:1]\' target=\'_new\'>All Product Features</a></strong>');
  t('<ul>
<li>en-us (<strong>English/United States</strong>)</li>
<li>en-au (<strong>English/Australia</strong>)</li>
<li>en-ca (<strong>English/Canada</strong>)</li>
<li>en-eu (<strong>English/Europe</strong>)</li>
<li>en-in (<strong>English/India</strong>)</li>
<li>en-ln (<strong>English/Latin America</strong>)</li>
<li>en-su (<strong>English/Southeast Asia</strong>)</li>
<li>fr-eu (<strong>French/Europe</strong>)</li>
<li>fr-ca (<strong>French/Canada</strong>)</li>
<li>de-eu (<strong>German/Europe</strong>)</li>
<li>es-eu (<strong>Spanish/Europe</strong>)</li>
<li>es-ln (<strong>Spanish/Latin America</strong>)</li>
<li>pt-eu (<strong>Portuguese/Europe</strong>)</li>
<li>pt-br (<strong>Portuguese/Brazil</strong>)</li>
<li>cn-zh (<strong>Chinese/China</strong>)</li>
<li>jp-ja (<strong>Japanese/Japan</strong>)</li>
<li>ko-kr (<strong>Korean/Korea</strong>)</li>
<li>ru-ru (<strong>Russian/Russia</strong>)</li>
</ul>');
  t('Ad Tracking Code');
  t('At a Glance');
  t('At a glance bullets for right side of product page');
  t('BTN Call to Action');
  t('Body');
  t('Business Entity');
  t('Button Size');
  t('Carousel Image LG-1');
  t('Carousel Image LG-10');
  t('Carousel Image LG-2');
  t('Carousel Image LG-3');
  t('Carousel Image LG-4');
  t('Carousel Image LG-5');
  t('Carousel Image LG-6');
  t('Carousel Image LG-7');
  t('Carousel Image LG-8');
  t('Carousel Image LG-9');
  t('Carousel Image Sort-1');
  t('Carousel Image Sort-10');
  t('Carousel Image Sort-2');
  t('Carousel Image Sort-3');
  t('Carousel Image Sort-4');
  t('Carousel Image Sort-5');
  t('Carousel Image Sort-6');
  t('Carousel Image Sort-7');
  t('Carousel Image Sort-8');
  t('Carousel Image Sort-9');
  t('Carousel Image Thumb-1');
  t('Carousel Image Thumb-10');
  t('Carousel Image Thumb-2');
  t('Carousel Image Thumb-3');
  t('Carousel Image Thumb-4');
  t('Carousel Image Thumb-5');
  t('Carousel Image Thumb-6');
  t('Carousel Image Thumb-7');
  t('Carousel Image Thumb-8');
  t('Carousel Image Thumb-9');
  t('Choose 4 related products');
  t('Contact Sales Button');
  t('Conversion Code');
  t('CustomTab Data-1');
  t('CustomTab Data-2');
  t('CustomTab Data-3');
  t('CustomTab Data-4');
  t('CustomTab Data-5');
  t('CustomTab Name-1');
  t('CustomTab Name-2');
  t('CustomTab Name-3');
  t('CustomTab Name-4');
  t('CustomTab Name-5');
  t('Description');
  t('Details');
  t('Do not distribute');
  t('Enable Ratings and Reviews');
  t('Example Path (URL): http://images.flukenetworks.com/360/Products/XG/config.xml');
  t('Family');
  t('Hide Models & Accessories');
  t('Hub Image');
  t('If this field left blank, WTB will use the image from carousel image #1');
  t('Language Override');
  t('Online Stores');
  t('Onyx Hierarchy ID');
  t('PCATID');
  t('PCATID from legacy FNET system.');
  t('Product Attributes');
  t('Product Status');
  t('Related Product Image');
  t('Releated Products');
  t('Solution Description #1');
  t('Solution Description #2');
  t('Solution Description #3');
  t('Solution Description #4');
  t('Solution Link #1');
  t('Solution Link #2');
  t('Solution Link #3');
  t('Solution Link #4');
  t('Solutions Title');
  t('Specs');
  t('Use this content type for all product pages.');
  t('Video File');
  t('Video Image Thumb');
  t('Where To Buy Product Image');
  t('Where to Buy Button');
  t('YouTube Embeded URL');

  return $field_instances;
}
