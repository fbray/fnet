<?php
/**
 * @file
 * products.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function products_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_3d_img|node|product|default';
  $field_group->group_name = 'group_prod_3d_img';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '3D (360) Image',
    'weight' => '19',
    'children' => array(
      0 => 'field_prod_360_img_lg_1',
      1 => 'field_prod_360_img_t_1',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_3d_img|node|product|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_3d_img|node|product|form';
  $field_group->group_name = 'group_prod_3d_img';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
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
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_3d_img|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_3d_img|node|product|teaser';
  $field_group->group_name = 'group_prod_3d_img';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '3D (360) Image',
    'weight' => '19',
    'children' => array(
      0 => 'field_prod_360_img_lg_1',
      1 => 'field_prod_360_img_t_1',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_3d_img|node|product|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_caroimages|node|product|default';
  $field_group->group_name = 'group_prod_caroimages';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Carousel Images',
    'weight' => '21',
    'children' => array(
      0 => 'field_prod_carousel_img_lg_10',
      1 => 'field_prod_carousel_img_lg_2',
      2 => 'field_prod_carousel_img_lg_3',
      3 => 'field_prod_carousel_img_lg_4',
      4 => 'field_prod_carousel_img_lg_5',
      5 => 'field_prod_carousel_img_lg_6',
      6 => 'field_prod_carousel_img_lg_7',
      7 => 'field_prod_carousel_img_lg_8',
      8 => 'field_prod_carousel_img_lg_9',
      9 => 'field_prod_carousel_img_srt_1',
      10 => 'field_prod_carousel_img_srt_10',
      11 => 'field_prod_carousel_img_srt_2',
      12 => 'field_prod_carousel_img_srt_3',
      13 => 'field_prod_carousel_img_srt_4',
      14 => 'field_prod_carousel_img_srt_5',
      15 => 'field_prod_carousel_img_srt_6',
      16 => 'field_prod_carousel_img_srt_7',
      17 => 'field_prod_carousel_img_srt_8',
      18 => 'field_prod_carousel_img_srt_9',
      19 => 'field_prod_carousel_img_t_1',
      20 => 'field_prod_carousel_img_t_10',
      21 => 'field_prod_carousel_img_t_2',
      22 => 'field_prod_carousel_img_t_3',
      23 => 'field_prod_carousel_img_t_4',
      24 => 'field_prod_carousel_img_t_5',
      25 => 'field_prod_carousel_img_t_6',
      26 => 'field_prod_carousel_img_t_7',
      27 => 'field_prod_carousel_img_t_8',
      28 => 'field_prod_carousel_img_t_9',
      29 => 'field_prod_carousel_img_lg_1',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_caroimages|node|product|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_caroimages|node|product|form';
  $field_group->group_name = 'group_prod_caroimages';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Carousel Images',
    'weight' => '22',
    'children' => array(
      0 => 'field_prod_carousel_img_lg_10',
      1 => 'field_prod_carousel_img_lg_2',
      2 => 'field_prod_carousel_img_lg_3',
      3 => 'field_prod_carousel_img_lg_4',
      4 => 'field_prod_carousel_img_lg_5',
      5 => 'field_prod_carousel_img_lg_6',
      6 => 'field_prod_carousel_img_lg_7',
      7 => 'field_prod_carousel_img_lg_8',
      8 => 'field_prod_carousel_img_lg_9',
      9 => 'field_prod_carousel_img_srt_1',
      10 => 'field_prod_carousel_img_srt_10',
      11 => 'field_prod_carousel_img_srt_2',
      12 => 'field_prod_carousel_img_srt_3',
      13 => 'field_prod_carousel_img_srt_4',
      14 => 'field_prod_carousel_img_srt_5',
      15 => 'field_prod_carousel_img_srt_6',
      16 => 'field_prod_carousel_img_srt_7',
      17 => 'field_prod_carousel_img_srt_8',
      18 => 'field_prod_carousel_img_srt_9',
      19 => 'field_prod_carousel_img_t_1',
      20 => 'field_prod_carousel_img_t_10',
      21 => 'field_prod_carousel_img_t_2',
      22 => 'field_prod_carousel_img_t_3',
      23 => 'field_prod_carousel_img_t_4',
      24 => 'field_prod_carousel_img_t_5',
      25 => 'field_prod_carousel_img_t_6',
      26 => 'field_prod_carousel_img_t_7',
      27 => 'field_prod_carousel_img_t_8',
      28 => 'field_prod_carousel_img_t_9',
      29 => 'field_prod_carousel_img_lg_1',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_caroimages|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_caroimages|node|product|teaser';
  $field_group->group_name = 'group_prod_caroimages';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Carousel Images',
    'weight' => '21',
    'children' => array(
      0 => 'field_prod_carousel_img_lg_1',
      1 => 'field_prod_carousel_img_lg_10',
      2 => 'field_prod_carousel_img_lg_2',
      3 => 'field_prod_carousel_img_lg_3',
      4 => 'field_prod_carousel_img_lg_4',
      5 => 'field_prod_carousel_img_lg_5',
      6 => 'field_prod_carousel_img_lg_6',
      7 => 'field_prod_carousel_img_lg_7',
      8 => 'field_prod_carousel_img_lg_8',
      9 => 'field_prod_carousel_img_lg_9',
      10 => 'field_prod_carousel_img_srt_1',
      11 => 'field_prod_carousel_img_srt_10',
      12 => 'field_prod_carousel_img_srt_2',
      13 => 'field_prod_carousel_img_srt_3',
      14 => 'field_prod_carousel_img_srt_4',
      15 => 'field_prod_carousel_img_srt_5',
      16 => 'field_prod_carousel_img_srt_6',
      17 => 'field_prod_carousel_img_srt_7',
      18 => 'field_prod_carousel_img_srt_8',
      19 => 'field_prod_carousel_img_srt_9',
      20 => 'field_prod_carousel_img_t_1',
      21 => 'field_prod_carousel_img_t_10',
      22 => 'field_prod_carousel_img_t_2',
      23 => 'field_prod_carousel_img_t_3',
      24 => 'field_prod_carousel_img_t_4',
      25 => 'field_prod_carousel_img_t_5',
      26 => 'field_prod_carousel_img_t_6',
      27 => 'field_prod_carousel_img_t_7',
      28 => 'field_prod_carousel_img_t_8',
      29 => 'field_prod_carousel_img_t_9',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_caroimages|node|product|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_cta|node|product|default';
  $field_group->group_name = 'group_prod_cta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Button Call to Action',
    'weight' => '3',
    'children' => array(
      0 => 'field_prod_btn_calltoaction',
      1 => 'field_prod_btn_cta_size',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_cta|node|product|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_cta|node|product|form';
  $field_group->group_name = 'group_prod_cta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Button Call to Action',
    'weight' => '8',
    'children' => array(
      0 => 'field_prod_btn_calltoaction',
      1 => 'field_prod_btn_cta_size',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_cta|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_cta|node|product|teaser';
  $field_group->group_name = 'group_prod_cta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Button Call to Action',
    'weight' => '3',
    'children' => array(
      0 => 'field_prod_btn_calltoaction',
      1 => 'field_prod_btn_cta_size',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_cta|node|product|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_grp_review|node|product|default';
  $field_group->group_name = 'group_prod_grp_review';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Ratings and Reviews',
    'weight' => '0',
    'children' => array(
      0 => 'field_prod_rating_review',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_grp_review|node|product|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_grp_review|node|product|form';
  $field_group->group_name = 'group_prod_grp_review';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Ratings and Reviews',
    'weight' => '4',
    'children' => array(
      0 => 'field_prod_rating_review',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_grp_review|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_grp_review|node|product|teaser';
  $field_group->group_name = 'group_prod_grp_review';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Ratings and Reviews',
    'weight' => '0',
    'children' => array(
      0 => 'field_prod_rating_review',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_grp_review|node|product|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_pcat|node|product|default';
  $field_group->group_name = 'group_prod_pcat';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'PCAT Data',
    'weight' => '24',
    'children' => array(
      0 => 'field_onyxhierarchyid',
      1 => 'field_pcatid',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_pcat|node|product|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_pcat|node|product|form';
  $field_group->group_name = 'group_prod_pcat';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'PCAT Data',
    'weight' => '25',
    'children' => array(
      0 => 'field_onyxhierarchyid',
      1 => 'field_pcatid',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_pcat|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_pcat|node|product|teaser';
  $field_group->group_name = 'group_prod_pcat';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'PCAT Data',
    'weight' => '24',
    'children' => array(
      0 => 'field_onyxhierarchyid',
      1 => 'field_pcatid',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_pcat|node|product|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_tabs|node|product|default';
  $field_group->group_name = 'group_prod_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Custom Tabs',
    'weight' => '11',
    'children' => array(
      0 => 'field_prod_ctab_data_1',
      1 => 'field_prod_ctab_data_2',
      2 => 'field_prod_ctab_data_3',
      3 => 'field_prod_ctab_data_4',
      4 => 'field_prod_ctab_data_5',
      5 => 'field_prod_ctab_name_1',
      6 => 'field_prod_ctab_name_2',
      7 => 'field_prod_ctab_name_3',
      8 => 'field_prod_ctab_name_4',
      9 => 'field_prod_ctab_name_5',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_tabs|node|product|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_tabs|node|product|form';
  $field_group->group_name = 'group_prod_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Custom Tabs',
    'weight' => '17',
    'children' => array(
      0 => 'field_prod_ctab_data_1',
      1 => 'field_prod_ctab_data_2',
      2 => 'field_prod_ctab_data_3',
      3 => 'field_prod_ctab_data_4',
      4 => 'field_prod_ctab_data_5',
      5 => 'field_prod_ctab_name_1',
      6 => 'field_prod_ctab_name_2',
      7 => 'field_prod_ctab_name_3',
      8 => 'field_prod_ctab_name_4',
      9 => 'field_prod_ctab_name_5',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_tabs|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_tabs|node|product|teaser';
  $field_group->group_name = 'group_prod_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Custom Tabs',
    'weight' => '11',
    'children' => array(
      0 => 'field_prod_ctab_data_1',
      1 => 'field_prod_ctab_data_2',
      2 => 'field_prod_ctab_data_3',
      3 => 'field_prod_ctab_data_4',
      4 => 'field_prod_ctab_data_5',
      5 => 'field_prod_ctab_name_1',
      6 => 'field_prod_ctab_name_2',
      7 => 'field_prod_ctab_name_3',
      8 => 'field_prod_ctab_name_4',
      9 => 'field_prod_ctab_name_5',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_tabs|node|product|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_video|node|product|default';
  $field_group->group_name = 'group_prod_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Product Video',
    'weight' => '20',
    'children' => array(
      0 => 'field_prod_video_img_t_1',
      1 => 'field_prod_video_lg_1',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_video|node|product|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_video|node|product|form';
  $field_group->group_name = 'group_prod_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Product Video',
    'weight' => '21',
    'children' => array(
      0 => 'field_prod_video_img_t_1',
      1 => 'field_prod_video_lg_1',
      2 => 'field_prod_video_youtube_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_video|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_video|node|product|teaser';
  $field_group->group_name = 'group_prod_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Product Video',
    'weight' => '20',
    'children' => array(
      0 => 'field_prod_video_img_t_1',
      1 => 'field_prod_video_lg_1',
      2 => 'field_prod_video_youtube_url',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_video|node|product|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_wtb_grp|node|product|default';
  $field_group->group_name = 'group_prod_wtb_grp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Where To Buy',
    'weight' => '8',
    'children' => array(
      0 => 'field_prod_wtb_img',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_wtb_grp|node|product|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_wtb_grp|node|product|form';
  $field_group->group_name = 'group_prod_wtb_grp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Where To Buy',
    'weight' => '13',
    'children' => array(
      0 => 'field_prod_wtb_img',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_wtb_grp|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_prod_wtb_grp|node|product|teaser';
  $field_group->group_name = 'group_prod_wtb_grp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Where To Buy',
    'weight' => '8',
    'children' => array(
      0 => 'field_prod_wtb_img',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_prod_wtb_grp|node|product|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product_solutions|node|product|default';
  $field_group->group_name = 'group_product_solutions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Solutions',
    'weight' => '26',
    'children' => array(
      0 => 'field_prod_sol_desc_1',
      1 => 'field_prod_sol_desc_2',
      2 => 'field_prod_sol_desc_3',
      3 => 'field_prod_sol_desc_4',
      4 => 'field_prod_sol_link_1',
      5 => 'field_prod_sol_link_2',
      6 => 'field_prod_sol_link_3',
      7 => 'field_prod_sol_link_4',
      8 => 'field_prod_sol_title',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_product_solutions|node|product|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product_solutions|node|product|form';
  $field_group->group_name = 'group_product_solutions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Solutions',
    'weight' => '27',
    'children' => array(
      0 => 'field_prod_sol_desc_1',
      1 => 'field_prod_sol_desc_2',
      2 => 'field_prod_sol_desc_3',
      3 => 'field_prod_sol_desc_4',
      4 => 'field_prod_sol_link_1',
      5 => 'field_prod_sol_link_2',
      6 => 'field_prod_sol_link_3',
      7 => 'field_prod_sol_link_4',
      8 => 'field_prod_sol_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_product_solutions|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product_solutions|node|product|teaser';
  $field_group->group_name = 'group_product_solutions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Solutions',
    'weight' => '26',
    'children' => array(
      0 => 'field_prod_sol_desc_1',
      1 => 'field_prod_sol_desc_2',
      2 => 'field_prod_sol_desc_3',
      3 => 'field_prod_sol_desc_4',
      4 => 'field_prod_sol_link_1',
      5 => 'field_prod_sol_link_2',
      6 => 'field_prod_sol_link_3',
      7 => 'field_prod_sol_link_4',
      8 => 'field_prod_sol_title',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_product_solutions|node|product|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_products|node|product|default';
  $field_group->group_name = 'group_related_products';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related Products',
    'weight' => '25',
    'children' => array(
      0 => 'field_prod_relatedprod',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_related_products|node|product|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_products|node|product|form';
  $field_group->group_name = 'group_related_products';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related Products',
    'weight' => '26',
    'children' => array(
      0 => 'field_prod_relatedprod',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_related_products|node|product|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_products|node|product|teaser';
  $field_group->group_name = 'group_related_products';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related Products',
    'weight' => '25',
    'children' => array(
      0 => 'field_prod_relatedprod',
    ),
    'format_type' => 'hidden',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(),
    ),
  );
  $export['group_related_products|node|product|teaser'] = $field_group;

  return $export;
}
