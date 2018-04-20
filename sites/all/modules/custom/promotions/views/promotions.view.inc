<?php

/**
 * @file
 * promotions.view.inc
 */

$view = new view();
$view->name = 'promotions';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Promotions';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Free Software Trials';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['group_by'] = TRUE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '3600';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '3600';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['grouping'] = array(
  0 => array(
    'field' => 'field_promotion_type',
    'rendered' => 1,
    'rendered_strip' => 0,
  ),
);
$handler->display->display_options['row_plugin'] = 'fields';
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
/* Relationship: File Usage: File */
$handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
$handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
$handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
/* Field: Content: Promotion Type */
$handler->display->display_options['fields']['field_promotion_type']['id'] = 'field_promotion_type';
$handler->display->display_options['fields']['field_promotion_type']['table'] = 'field_data_field_promotion_type';
$handler->display->display_options['fields']['field_promotion_type']['field'] = 'field_promotion_type';
$handler->display->display_options['fields']['field_promotion_type']['label'] = '';
$handler->display->display_options['fields']['field_promotion_type']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_promotion_type']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_promotion_type']['settings'] = array(
  'bypass_access' => 0,
  'link' => 0,
);
/* Field: Content: External URL */
$handler->display->display_options['fields']['field_external_url']['id'] = 'field_external_url';
$handler->display->display_options['fields']['field_external_url']['table'] = 'field_data_field_external_url';
$handler->display->display_options['fields']['field_external_url']['field'] = 'field_external_url';
$handler->display->display_options['fields']['field_external_url']['label'] = '';
$handler->display->display_options['fields']['field_external_url']['element_type'] = '0';
$handler->display->display_options['fields']['field_external_url']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_external_url']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_external_url']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['field_external_url']['click_sort_column'] = 'url';
$handler->display->display_options['fields']['field_external_url']['type'] = 'link_plain';
$handler->display->display_options['fields']['field_external_url']['group_column'] = 'url';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Intro */
$handler->display->display_options['fields']['field_intro']['id'] = 'field_intro';
$handler->display->display_options['fields']['field_intro']['table'] = 'field_data_field_intro';
$handler->display->display_options['fields']['field_intro']['field'] = 'field_intro';
$handler->display->display_options['fields']['field_intro']['label'] = '';
$handler->display->display_options['fields']['field_intro']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_intro']['type'] = 'text_plain';
$handler->display->display_options['fields']['field_intro']['settings'] = array(
  'field_formatter_filter' => '',
);
/* Field: Content: Promotion Date */
$handler->display->display_options['fields']['field_promotion_date']['id'] = 'field_promotion_date';
$handler->display->display_options['fields']['field_promotion_date']['table'] = 'field_data_field_promotion_date';
$handler->display->display_options['fields']['field_promotion_date']['field'] = 'field_promotion_date';
$handler->display->display_options['fields']['field_promotion_date']['label'] = '';
$handler->display->display_options['fields']['field_promotion_date']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_promotion_date']['alter']['text'] = 'Expires [field_promotion_date]';
$handler->display->display_options['fields']['field_promotion_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_promotion_date']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_promotion_date']['settings'] = array(
  'format_type' => 'long',
  'custom_date_format' => '',
  'fromto' => 'value2',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
);
$handler->display->display_options['fields']['field_promotion_date']['group_columns'] = array(
  'value2' => 'value2',
);
/* Field: File: Path */
$handler->display->display_options['fields']['uri']['id'] = 'uri';
$handler->display->display_options['fields']['uri']['table'] = 'file_managed';
$handler->display->display_options['fields']['uri']['field'] = 'uri';
$handler->display->display_options['fields']['uri']['relationship'] = 'node_to_file';
$handler->display->display_options['fields']['uri']['label'] = '';
$handler->display->display_options['fields']['uri']['element_type'] = '0';
$handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['uri']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
/* Sort criterion: Weight: Weight */
$handler->display->display_options['sorts']['weight']['id'] = 'weight';
$handler->display->display_options['sorts']['weight']['table'] = 'weight_weights';
$handler->display->display_options['sorts']['weight']['field'] = 'weight';
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'promotion' => 'promotion',
);
/* Filter criterion: Content: RegLang Filter */
$handler->display->display_options['filters']['region_language']['id'] = 'region_language';
$handler->display->display_options['filters']['region_language']['table'] = 'node';
$handler->display->display_options['filters']['region_language']['field'] = 'region_language';
/* Filter criterion: Content: Promotion Date - end date (field_promotion_date:value2) */
$handler->display->display_options['filters']['field_promotion_date_value2']['id'] = 'field_promotion_date_value2';
$handler->display->display_options['filters']['field_promotion_date_value2']['table'] = 'field_data_field_promotion_date';
$handler->display->display_options['filters']['field_promotion_date_value2']['field'] = 'field_promotion_date_value2';
$handler->display->display_options['filters']['field_promotion_date_value2']['operator'] = '>=';
$handler->display->display_options['filters']['field_promotion_date_value2']['form_type'] = 'date_text';
$handler->display->display_options['filters']['field_promotion_date_value2']['default_date'] = 'now';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Promotions';
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'There are no active Promotions at this time. Check back later.';
$handler->display->display_options['empty']['area']['format'] = 'plain_text';
$handler->display->display_options['path'] = 'promotions';

/* Display: Free Software Trials */
$handler = $view->new_display('page', 'Free Software Trials', 'page_1');
$handler->display->display_options['defaults']['group_by'] = FALSE;
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'There are no active Software Trials at this time. Check back later.';
$handler->display->display_options['empty']['area']['format'] = 'plain_text';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: External URL */
$handler->display->display_options['fields']['field_external_url']['id'] = 'field_external_url';
$handler->display->display_options['fields']['field_external_url']['table'] = 'field_data_field_external_url';
$handler->display->display_options['fields']['field_external_url']['field'] = 'field_external_url';
$handler->display->display_options['fields']['field_external_url']['label'] = '';
$handler->display->display_options['fields']['field_external_url']['element_type'] = '0';
$handler->display->display_options['fields']['field_external_url']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_external_url']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_external_url']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['field_external_url']['click_sort_column'] = 'url';
$handler->display->display_options['fields']['field_external_url']['type'] = 'link_plain';
$handler->display->display_options['fields']['field_external_url']['group_column'] = 'url';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Intro */
$handler->display->display_options['fields']['field_intro']['id'] = 'field_intro';
$handler->display->display_options['fields']['field_intro']['table'] = 'field_data_field_intro';
$handler->display->display_options['fields']['field_intro']['field'] = 'field_intro';
$handler->display->display_options['fields']['field_intro']['label'] = '';
$handler->display->display_options['fields']['field_intro']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_intro']['type'] = 'text_plain';
$handler->display->display_options['fields']['field_intro']['settings'] = array(
  'field_formatter_filter' => '',
);
/* Field: Content: Promotion Date */
$handler->display->display_options['fields']['field_promotion_date']['id'] = 'field_promotion_date';
$handler->display->display_options['fields']['field_promotion_date']['table'] = 'field_data_field_promotion_date';
$handler->display->display_options['fields']['field_promotion_date']['field'] = 'field_promotion_date';
$handler->display->display_options['fields']['field_promotion_date']['label'] = '';
$handler->display->display_options['fields']['field_promotion_date']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_promotion_date']['alter']['text'] = 'Expires [field_promotion_date]';
$handler->display->display_options['fields']['field_promotion_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_promotion_date']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_promotion_date']['settings'] = array(
  'format_type' => 'long',
  'custom_date_format' => '',
  'fromto' => 'value2',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
);
$handler->display->display_options['fields']['field_promotion_date']['group_columns'] = array(
  'value2' => 'value2',
);
/* Field: File: Path */
$handler->display->display_options['fields']['uri']['id'] = 'uri';
$handler->display->display_options['fields']['uri']['table'] = 'file_managed';
$handler->display->display_options['fields']['uri']['field'] = 'uri';
$handler->display->display_options['fields']['uri']['relationship'] = 'node_to_file';
$handler->display->display_options['fields']['uri']['label'] = '';
$handler->display->display_options['fields']['uri']['element_type'] = '0';
$handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['uri']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'promotion' => 'promotion',
);
/* Filter criterion: Content: RegLang Filter */
$handler->display->display_options['filters']['region_language']['id'] = 'region_language';
$handler->display->display_options['filters']['region_language']['table'] = 'node';
$handler->display->display_options['filters']['region_language']['field'] = 'region_language';
/* Filter criterion: Content: Promotion Date - end date (field_promotion_date:value2) */
$handler->display->display_options['filters']['field_promotion_date_value2']['id'] = 'field_promotion_date_value2';
$handler->display->display_options['filters']['field_promotion_date_value2']['table'] = 'field_data_field_promotion_date';
$handler->display->display_options['filters']['field_promotion_date_value2']['field'] = 'field_promotion_date_value2';
$handler->display->display_options['filters']['field_promotion_date_value2']['operator'] = '>=';
$handler->display->display_options['filters']['field_promotion_date_value2']['form_type'] = 'date_text';
$handler->display->display_options['filters']['field_promotion_date_value2']['default_date'] = 'now';
/* Filter criterion: Content: Promotion Type (field_promotion_type) */
$handler->display->display_options['filters']['field_promotion_type_target_id']['id'] = 'field_promotion_type_target_id';
$handler->display->display_options['filters']['field_promotion_type_target_id']['table'] = 'field_data_field_promotion_type';
$handler->display->display_options['filters']['field_promotion_type_target_id']['field'] = 'field_promotion_type_target_id';
$handler->display->display_options['filters']['field_promotion_type_target_id']['value'] = array(
  305 => '305',
);
$handler->display->display_options['path'] = 'free-software-trials-downloads';