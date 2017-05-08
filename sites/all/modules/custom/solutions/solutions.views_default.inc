<?php
/**
 * @file
 * solutions.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function solutions_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'solutions';
  $view->description = 'This view contains displays for the various pages under the "Solutions" menu heading.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Solutions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Solutions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Node: translations Language-Region */
  $handler->display->display_options['arguments']['langreg']['id'] = 'langreg';
  $handler->display->display_options['arguments']['langreg']['table'] = 'language_region';
  $handler->display->display_options['arguments']['langreg']['field'] = 'langreg';
  $handler->display->display_options['arguments']['langreg']['default_action'] = 'default';
  $handler->display->display_options['arguments']['langreg']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['langreg']['default_argument_options']['code'] = 'return fnet_helper_reg_lang();';
  $handler->display->display_options['arguments']['langreg']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['langreg']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['langreg']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['langreg']['limit'] = '0';
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
    'expertise' => 'expertise',
    'exp_ind' => 'exp_ind',
    'exp_rle' => 'exp_rle',
    'exp_tpc' => 'exp_tpc',
  );
  /* Filter criterion: Node: translations language-region status */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'language_region';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';

  /* Display: Solutions Topics (Page) */
  $handler = $view->new_display('page', 'Solutions Topics (Page)', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Solutions Topics';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_exp_tpc_thumbnail']['id'] = 'field_exp_tpc_thumbnail';
  $handler->display->display_options['fields']['field_exp_tpc_thumbnail']['table'] = 'field_data_field_exp_tpc_thumbnail';
  $handler->display->display_options['fields']['field_exp_tpc_thumbnail']['field'] = 'field_exp_tpc_thumbnail';
  $handler->display->display_options['fields']['field_exp_tpc_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_exp_tpc_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_exp_tpc_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_exp_tpc_thumbnail']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Language Override (field_exp_tpc_lng:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_exp_tpc_lng';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['label'] = '';
  $handler->display->display_options['fields']['delta']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
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
    'exp_tpc' => 'exp_tpc',
  );
  /* Filter criterion: Node: translations language-region status */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'language_region';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['path'] = 'solutions/topics';

  /* Display: Solutions Roles (Page) */
  $handler = $view->new_display('page', 'Solutions Roles (Page)', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Solutions Roles';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_exp_rle_thumbnail']['id'] = 'field_exp_rle_thumbnail';
  $handler->display->display_options['fields']['field_exp_rle_thumbnail']['table'] = 'field_data_field_exp_rle_thumbnail';
  $handler->display->display_options['fields']['field_exp_rle_thumbnail']['field'] = 'field_exp_rle_thumbnail';
  $handler->display->display_options['fields']['field_exp_rle_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_exp_rle_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_exp_rle_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_exp_rle_thumbnail']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Language Override (field_exp_rle_lng:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_exp_rle_lng';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['label'] = '';
  $handler->display->display_options['fields']['delta']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
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
    'exp_rle' => 'exp_rle',
  );
  /* Filter criterion: Node: translations language-region status */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'language_region';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['path'] = 'solutions/roles';

  /* Display: Solutions Industries (Page) */
  $handler = $view->new_display('page', 'Solutions Industries (Page)', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Solutions Industries';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_exp_ind_thumbnail']['id'] = 'field_exp_ind_thumbnail';
  $handler->display->display_options['fields']['field_exp_ind_thumbnail']['table'] = 'field_data_field_exp_ind_thumbnail';
  $handler->display->display_options['fields']['field_exp_ind_thumbnail']['field'] = 'field_exp_ind_thumbnail';
  $handler->display->display_options['fields']['field_exp_ind_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_exp_ind_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_exp_ind_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_exp_ind_thumbnail']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Language Override (field_exp_ind_lng:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_exp_ind_lng';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['label'] = '';
  $handler->display->display_options['fields']['delta']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
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
    'exp_ind' => 'exp_ind',
  );
  /* Filter criterion: Node: translations language-region status */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'language_region';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['path'] = 'solutions/industries';

  /* Display: Learn About (Page) */
  $handler = $view->new_display('page', 'Learn About (Page)', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Learn About';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Intro */
  $handler->display->display_options['fields']['field_expertise_intro']['id'] = 'field_expertise_intro';
  $handler->display->display_options['fields']['field_expertise_intro']['table'] = 'field_data_field_expertise_intro';
  $handler->display->display_options['fields']['field_expertise_intro']['field'] = 'field_expertise_intro';
  $handler->display->display_options['fields']['field_expertise_intro']['label'] = '';
  $handler->display->display_options['fields']['field_expertise_intro']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'expertise' => 'expertise',
  );
  /* Filter criterion: Content: Expertise Types (taxonomy_vocabulary_8) */
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['id'] = 'taxonomy_vocabulary_8_tid';
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['table'] = 'field_data_taxonomy_vocabulary_8';
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['field'] = 'taxonomy_vocabulary_8_tid';
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['value'] = array(
    0 => '36',
  );
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['vocabulary'] = 'vocabulary_8';
  $handler->display->display_options['path'] = 'solutions/learn-about';

  /* Display: Case Studies (Page) */
  $handler = $view->new_display('page', 'Case Studies (Page)', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Case Studies';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'taxonomy_vocabulary_15',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Intro */
  $handler->display->display_options['fields']['field_expertise_intro']['id'] = 'field_expertise_intro';
  $handler->display->display_options['fields']['field_expertise_intro']['table'] = 'field_data_field_expertise_intro';
  $handler->display->display_options['fields']['field_expertise_intro']['field'] = 'field_expertise_intro';
  $handler->display->display_options['fields']['field_expertise_intro']['label'] = '';
  $handler->display->display_options['fields']['field_expertise_intro']['element_label_colon'] = FALSE;
  /* Field: Content: Industries */
  $handler->display->display_options['fields']['taxonomy_vocabulary_15']['id'] = 'taxonomy_vocabulary_15';
  $handler->display->display_options['fields']['taxonomy_vocabulary_15']['table'] = 'field_data_taxonomy_vocabulary_15';
  $handler->display->display_options['fields']['taxonomy_vocabulary_15']['field'] = 'taxonomy_vocabulary_15';
  $handler->display->display_options['fields']['taxonomy_vocabulary_15']['label'] = '';
  $handler->display->display_options['fields']['taxonomy_vocabulary_15']['exclude'] = TRUE;
  $handler->display->display_options['fields']['taxonomy_vocabulary_15']['element_type'] = 'h3';
  $handler->display->display_options['fields']['taxonomy_vocabulary_15']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['taxonomy_vocabulary_15']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'expertise' => 'expertise',
  );
  /* Filter criterion: Content: Expertise Types (taxonomy_vocabulary_8) */
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['id'] = 'taxonomy_vocabulary_8_tid';
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['table'] = 'field_data_taxonomy_vocabulary_8';
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['field'] = 'taxonomy_vocabulary_8_tid';
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['value'] = array(
    0 => '38',
  );
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['vocabulary'] = 'vocabulary_8';
  $handler->display->display_options['path'] = 'solutions/case-studies';

  /* Display: Solutions (Page) */
  $handler = $view->new_display('page', 'Solutions (Page)', 'page_6');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>Topics</h3>';
  $handler->display->display_options['header']['area']['format'] = '5';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="btn_143w"><a href="/solutions/topics">All Topics</a></div>';
  $handler->display->display_options['footer']['area']['format'] = '5';
  /* Footer: Global: View area */
  $handler->display->display_options['footer']['view']['id'] = 'view';
  $handler->display->display_options['footer']['view']['table'] = 'views';
  $handler->display->display_options['footer']['view']['field'] = 'view';
  $handler->display->display_options['footer']['view']['view_to_insert'] = 'solutions:block_1';
  /* Footer: Global: View area */
  $handler->display->display_options['footer']['view_1']['id'] = 'view_1';
  $handler->display->display_options['footer']['view_1']['table'] = 'views';
  $handler->display->display_options['footer']['view_1']['field'] = 'view';
  $handler->display->display_options['footer']['view_1']['view_to_insert'] = 'solutions:block_2';
  /* Footer: Global: View area */
  $handler->display->display_options['footer']['view_3']['id'] = 'view_3';
  $handler->display->display_options['footer']['view_3']['table'] = 'views';
  $handler->display->display_options['footer']['view_3']['field'] = 'view';
  $handler->display->display_options['footer']['view_3']['view_to_insert'] = 'solutions:block_4';
  /* Footer: Global: View area */
  $handler->display->display_options['footer']['view_2']['id'] = 'view_2';
  $handler->display->display_options['footer']['view_2']['table'] = 'views';
  $handler->display->display_options['footer']['view_2']['field'] = 'view';
  $handler->display->display_options['footer']['view_2']['view_to_insert'] = 'solutions:block_3';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
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
    'exp_tpc' => 'exp_tpc',
  );
  /* Filter criterion: Node: translations language-region status */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'language_region';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['path'] = 'solutions';

  /* Display: Solutions Roles (Block) */
  $handler = $view->new_display('block', 'Solutions Roles (Block)', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Roles';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>Roles</h3>';
  $handler->display->display_options['header']['area']['format'] = '5';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="btn_143w"><a href="/solutions/roles">All Roles</a></div>';
  $handler->display->display_options['footer']['area']['format'] = '5';
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
    'exp_rle' => 'exp_rle',
  );
  /* Filter criterion: Node: translations language-region status */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'language_region';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['block_description'] = 'Solutions Roles (Block)';

  /* Display: Solutions Industries (Block) */
  $handler = $view->new_display('block', 'Solutions Industries (Block)', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Industries';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>Industries</h3>';
  $handler->display->display_options['header']['area']['format'] = '5';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="btn_143w"><a href="/solutions/industries">All Industries</a></div>';
  $handler->display->display_options['footer']['area']['format'] = '5';
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
    'exp_ind' => 'exp_ind',
  );
  /* Filter criterion: Node: translations language-region status */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'language_region';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['block_description'] = 'Solutions Industries (Block)';

  /* Display: Case Studies (Block) */
  $handler = $view->new_display('block', 'Case Studies (Block)', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Case Studies';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>Case Studies</h3>';
  $handler->display->display_options['header']['area']['format'] = '2';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="btn_143w"><a href="/solutions/case-studies">All Case Studies</a></div>';
  $handler->display->display_options['footer']['area']['format'] = '5';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'expertise' => 'expertise',
  );
  /* Filter criterion: Content: Expertise Types (taxonomy_vocabulary_8) */
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['id'] = 'taxonomy_vocabulary_8_tid';
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['table'] = 'field_data_taxonomy_vocabulary_8';
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['field'] = 'taxonomy_vocabulary_8_tid';
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['value'] = array(
    38 => '38',
  );
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['type'] = 'select';
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['vocabulary'] = 'vocabulary_8';
  $handler->display->display_options['block_description'] = 'Case Studies (Block)';

  /* Display: Learn About (Block) */
  $handler = $view->new_display('block', 'Learn About (Block)', 'block_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Learn About (Block)';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h3>Learn About</h3>';
  $handler->display->display_options['header']['area']['format'] = '2';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="btn_143w"><a href="solutions/learn-about">All Learn About Topics</a></div>';
  $handler->display->display_options['footer']['area']['format'] = '5';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
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
    'expertise' => 'expertise',
  );
  /* Filter criterion: Content: Expertise Types (taxonomy_vocabulary_8) */
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['id'] = 'taxonomy_vocabulary_8_tid';
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['table'] = 'field_data_taxonomy_vocabulary_8';
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['field'] = 'taxonomy_vocabulary_8_tid';
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['value'] = array(
    36 => '36',
  );
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['type'] = 'select';
  $handler->display->display_options['filters']['taxonomy_vocabulary_8_tid']['vocabulary'] = 'vocabulary_8';
  $handler->display->display_options['block_description'] = 'Learn About (Block)';
  $export['solutions'] = $view;

  return $export;
}
