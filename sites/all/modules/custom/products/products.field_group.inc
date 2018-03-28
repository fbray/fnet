<?php

/**
 * @file
 * products.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function products_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_3d_img|node|product_display|form';
  $field_group->group_name = 'group_prod_3d_img';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_display';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '3D (360) Image',
    'weight' => '20',
    'children' => array(
      0 => 'field_prod_360_img_lg_1',
      1 => 'field_prod_360_img_t_1',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-prod-3d-img field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_prod_3d_img|node|product_display|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_caroimages|node|product_display|form';
  $field_group->group_name = 'group_prod_caroimages';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_display';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Carousel Images',
    'weight' => '22',
    'children' => array(
      0 => 'field_prod_carousel_img_lg_1',
      1 => 'field_prod_carousel_img_lg_2',
      2 => 'field_prod_carousel_img_lg_3',
      3 => 'field_prod_carousel_img_lg_4',
      4 => 'field_prod_carousel_img_lg_5',
      5 => 'field_prod_carousel_img_lg_6',
      6 => 'field_prod_carousel_img_lg_7',
      7 => 'field_prod_carousel_img_lg_8',
      8 => 'field_prod_carousel_img_lg_9',
      9 => 'field_prod_carousel_img_lg_10',
      10 => 'field_prod_carousel_img_t_1',
      11 => 'field_prod_carousel_img_t_2',
      12 => 'field_prod_carousel_img_t_3',
      13 => 'field_prod_carousel_img_t_4',
      14 => 'field_prod_carousel_img_t_5',
      15 => 'field_prod_carousel_img_t_6',
      16 => 'field_prod_carousel_img_t_7',
      17 => 'field_prod_carousel_img_t_8',
      18 => 'field_prod_carousel_img_t_9',
      19 => 'field_prod_carousel_img_t_10',
      20 => 'field_prod_carousel_img_srt_1',
      21 => 'field_prod_carousel_img_srt_2',
      22 => 'field_prod_carousel_img_srt_3',
      23 => 'field_prod_carousel_img_srt_4',
      24 => 'field_prod_carousel_img_srt_5',
      25 => 'field_prod_carousel_img_srt_6',
      26 => 'field_prod_carousel_img_srt_7',
      27 => 'field_prod_carousel_img_srt_8',
      28 => 'field_prod_carousel_img_srt_9',
      29 => 'field_prod_carousel_img_srt_10',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-prod-caroimages field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_prod_caroimages|node|product_display|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_cta|node|product_display|form';
  $field_group->group_name = 'group_prod_cta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_display';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Button Call to Action',
    'weight' => '9',
    'children' => array(
      0 => 'field_prod_btn_cta_size',
      1 => 'field_prod_btn_calltoaction',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-prod-cta field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_prod_cta|node|product_display|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_pcat|node|product_display|form';
  $field_group->group_name = 'group_prod_pcat';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_display';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'PCATID Data',
    'weight' => '24',
    'children' => array(
      0 => 'field_pcatid',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-prod-pcat field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_prod_pcat|node|product_display|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_tabs|node|product_display|form';
  $field_group->group_name = 'group_prod_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_display';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Custom Tabs',
    'weight' => '18',
    'children' => array(
      0 => 'field_prod_ctab_name_2',
      1 => 'field_prod_ctab_name_3',
      2 => 'field_prod_ctab_name_4',
      3 => 'field_prod_ctab_name_5',
      4 => 'field_prod_ctab_link_1',
      5 => 'field_prod_ctab_link_2',
      6 => 'field_prod_ctab_link_3',
      7 => 'field_prod_ctab_link_4',
      8 => 'field_prod_ctab_link_5',
      9 => 'field_prod_ctab_data_1',
      10 => 'field_prod_ctab_data_2',
      11 => 'field_prod_ctab_data_3',
      12 => 'field_prod_ctab_data_4',
      13 => 'field_prod_ctab_data_5',
      14 => 'field_prod_ctab_name_1',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-prod-tabs field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_prod_tabs|node|product_display|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_video|node|product_display|form';
  $field_group->group_name = 'group_prod_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_display';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Product Video',
    'weight' => '21',
    'children' => array(
      0 => 'field_prod_video_img_t_1',
      1 => 'field_prod_video_youtube_url',
      2 => 'field_prod_video_lg_1',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-prod-video field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_prod_video|node|product_display|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_wtb|node|product_display|form';
  $field_group->group_name = 'group_prod_wtb';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_display';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Where To Buy',
    'weight' => '12',
    'children' => array(
      0 => 'field_include_price_spider_code',
      1 => 'field_wtb_ps_model_sku',
      2 => 'field_prod_wtb_img',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-prod-wtb field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_prod_wtb|node|product_display|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product_solutions|node|product_display|form';
  $field_group->group_name = 'group_product_solutions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_display';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Product Solutions',
    'weight' => '26',
    'children' => array(
      0 => 'field_prod_sol_title',
      1 => 'field_prod_sol_link_1',
      2 => 'field_prod_sol_link_2',
      3 => 'field_prod_sol_link_3',
      4 => 'field_prod_sol_link_4',
      5 => 'field_prod_sol_desc_1',
      6 => 'field_prod_sol_desc_2',
      7 => 'field_prod_sol_desc_3',
      8 => 'field_prod_sol_desc_4',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-product-solutions field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_product_solutions|node|product_display|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_products|node|product_display|form';
  $field_group->group_name = 'group_related_products';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_display';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related Products',
    'weight' => '25',
    'children' => array(
      0 => 'field_related_products',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related-products field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_related_products|node|product_display|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('3D (360) Image');
  t('Button Call to Action');
  t('Carousel Images');
  t('Custom Tabs');
  t('PCATID Data');
  t('Product Solutions');
  t('Product Video');
  t('Related Products');
  t('Where To Buy');

  return $field_groups;
}
