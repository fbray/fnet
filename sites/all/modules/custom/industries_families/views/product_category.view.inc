<?php

/**
 * @file
 * product_category.view.inc
 */

$view = new view();
$view->name = 'product_category';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Product Category';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['use_more_always'] = FALSE;
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
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'title' => 'title',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'title' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Document ID */
$handler->display->display_options['fields']['field_dam_document_id']['id'] = 'field_dam_document_id';
$handler->display->display_options['fields']['field_dam_document_id']['table'] = 'field_data_field_dam_document_id';
$handler->display->display_options['fields']['field_dam_document_id']['field'] = 'field_dam_document_id';
$handler->display->display_options['fields']['field_dam_document_id']['label'] = '';
$handler->display->display_options['fields']['field_dam_document_id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_dam_document_id']['settings'] = array(
  'thousand_separator' => '',
  'prefix_suffix' => 0,
);
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
/* Contextual filter: Content: Language (field_dam_language) */
$handler->display->display_options['arguments']['field_dam_language_value']['id'] = 'field_dam_language_value';
$handler->display->display_options['arguments']['field_dam_language_value']['table'] = 'field_data_field_dam_language';
$handler->display->display_options['arguments']['field_dam_language_value']['field'] = 'field_dam_language_value';
$handler->display->display_options['arguments']['field_dam_language_value']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['field_dam_language_value']['summary']['format'] = 'default_summary';
/* Contextual filter: Content: Industry (field_dam_industry) */
$handler->display->display_options['arguments']['field_dam_industry_value']['id'] = 'field_dam_industry_value';
$handler->display->display_options['arguments']['field_dam_industry_value']['table'] = 'field_data_field_dam_industry';
$handler->display->display_options['arguments']['field_dam_industry_value']['field'] = 'field_dam_industry_value';
$handler->display->display_options['arguments']['field_dam_industry_value']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['field_dam_industry_value']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_dam_industry_value']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_dam_industry_value']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['field_dam_industry_value']['limit'] = '0';
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
  'digital_asset' => 'digital_asset',
);
/* Filter criterion: Content: Document Status (field_dam_document_status) */
$handler->display->display_options['filters']['field_dam_document_status_value']['id'] = 'field_dam_document_status_value';
$handler->display->display_options['filters']['field_dam_document_status_value']['table'] = 'field_data_field_dam_document_status';
$handler->display->display_options['filters']['field_dam_document_status_value']['field'] = 'field_dam_document_status_value';
$handler->display->display_options['filters']['field_dam_document_status_value']['value'] = array(
  'live' => 'live',
);
/* Filter criterion: Content: Entitlement Level (field_dam_entitlement_level) */
$handler->display->display_options['filters']['field_dam_entitlement_level_value']['id'] = 'field_dam_entitlement_level_value';
$handler->display->display_options['filters']['field_dam_entitlement_level_value']['table'] = 'field_data_field_dam_entitlement_level';
$handler->display->display_options['filters']['field_dam_entitlement_level_value']['field'] = 'field_dam_entitlement_level_value';
$handler->display->display_options['filters']['field_dam_entitlement_level_value']['operator'] = 'not';
$handler->display->display_options['filters']['field_dam_entitlement_level_value']['value'] = array(
  'do_not_display' => 'do_not_display',
);

/* Display: Whitepapers */
$handler = $view->new_display('embed', 'Whitepapers', 'whitepapers');
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
  'digital_asset' => 'digital_asset',
);
/* Filter criterion: Content: Document Status (field_dam_document_status) */
$handler->display->display_options['filters']['field_dam_document_status_value']['id'] = 'field_dam_document_status_value';
$handler->display->display_options['filters']['field_dam_document_status_value']['table'] = 'field_data_field_dam_document_status';
$handler->display->display_options['filters']['field_dam_document_status_value']['field'] = 'field_dam_document_status_value';
$handler->display->display_options['filters']['field_dam_document_status_value']['value'] = array(
  'live' => 'live',
);
/* Filter criterion: Content: Entitlement Level (field_dam_entitlement_level) */
$handler->display->display_options['filters']['field_dam_entitlement_level_value']['id'] = 'field_dam_entitlement_level_value';
$handler->display->display_options['filters']['field_dam_entitlement_level_value']['table'] = 'field_data_field_dam_entitlement_level';
$handler->display->display_options['filters']['field_dam_entitlement_level_value']['field'] = 'field_dam_entitlement_level_value';
$handler->display->display_options['filters']['field_dam_entitlement_level_value']['operator'] = 'not';
$handler->display->display_options['filters']['field_dam_entitlement_level_value']['value'] = array(
  'do_not_display' => 'do_not_display',
);
/* Filter criterion: Content: Asset Type (field_asset_type) */
$handler->display->display_options['filters']['field_asset_type_value']['id'] = 'field_asset_type_value';
$handler->display->display_options['filters']['field_asset_type_value']['table'] = 'field_data_field_asset_type';
$handler->display->display_options['filters']['field_asset_type_value']['field'] = 'field_asset_type_value';
$handler->display->display_options['filters']['field_asset_type_value']['value'] = array(
  'white_paper' => 'white_paper',
);

/* Display: Webcasts */
$handler = $view->new_display('embed', 'Webcasts', 'webcasts');
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Document ID */
$handler->display->display_options['fields']['field_dam_document_id']['id'] = 'field_dam_document_id';
$handler->display->display_options['fields']['field_dam_document_id']['table'] = 'field_data_field_dam_document_id';
$handler->display->display_options['fields']['field_dam_document_id']['field'] = 'field_dam_document_id';
$handler->display->display_options['fields']['field_dam_document_id']['label'] = 'Webcast';
$handler->display->display_options['fields']['field_dam_document_id']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_dam_document_id']['alter']['text'] = 'View Webcast';
$handler->display->display_options['fields']['field_dam_document_id']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['field_dam_document_id']['alter']['path'] = 'findit/[field_dam_document_id]';
$handler->display->display_options['fields']['field_dam_document_id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_dam_document_id']['settings'] = array(
  'thousand_separator' => '',
  'prefix_suffix' => 0,
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
  'digital_asset' => 'digital_asset',
);
/* Filter criterion: Content: Document Status (field_dam_document_status) */
$handler->display->display_options['filters']['field_dam_document_status_value']['id'] = 'field_dam_document_status_value';
$handler->display->display_options['filters']['field_dam_document_status_value']['table'] = 'field_data_field_dam_document_status';
$handler->display->display_options['filters']['field_dam_document_status_value']['field'] = 'field_dam_document_status_value';
$handler->display->display_options['filters']['field_dam_document_status_value']['value'] = array(
  'live' => 'live',
);
/* Filter criterion: Content: Entitlement Level (field_dam_entitlement_level) */
$handler->display->display_options['filters']['field_dam_entitlement_level_value']['id'] = 'field_dam_entitlement_level_value';
$handler->display->display_options['filters']['field_dam_entitlement_level_value']['table'] = 'field_data_field_dam_entitlement_level';
$handler->display->display_options['filters']['field_dam_entitlement_level_value']['field'] = 'field_dam_entitlement_level_value';
$handler->display->display_options['filters']['field_dam_entitlement_level_value']['operator'] = 'not';
$handler->display->display_options['filters']['field_dam_entitlement_level_value']['value'] = array(
  'do_not_display' => 'do_not_display',
);
/* Filter criterion: Content: Asset Type (field_asset_type) */
$handler->display->display_options['filters']['field_asset_type_value']['id'] = 'field_asset_type_value';
$handler->display->display_options['filters']['field_asset_type_value']['table'] = 'field_data_field_asset_type';
$handler->display->display_options['filters']['field_asset_type_value']['field'] = 'field_asset_type_value';
$handler->display->display_options['filters']['field_asset_type_value']['value'] = array(
  'webcast' => 'webcast',
);

/* Display: Case Studies */
$handler = $view->new_display('embed', 'Case Studies', 'case_studies');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Case Studies';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['settings'] = array(
  'field_formatter_filter' => '',
);
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Content: Product Category (field_product_category) */
$handler->display->display_options['arguments']['field_product_category_target_id']['id'] = 'field_product_category_target_id';
$handler->display->display_options['arguments']['field_product_category_target_id']['table'] = 'field_data_field_product_category';
$handler->display->display_options['arguments']['field_product_category_target_id']['field'] = 'field_product_category_target_id';
$handler->display->display_options['arguments']['field_product_category_target_id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['field_product_category_target_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_product_category_target_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_product_category_target_id']['summary_options']['items_per_page'] = '25';
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
/* Filter criterion: Content: Expertise Types (field_expertise_types) */
$handler->display->display_options['filters']['field_expertise_types_target_id']['id'] = 'field_expertise_types_target_id';
$handler->display->display_options['filters']['field_expertise_types_target_id']['table'] = 'field_data_field_expertise_types';
$handler->display->display_options['filters']['field_expertise_types_target_id']['field'] = 'field_expertise_types_target_id';
$handler->display->display_options['filters']['field_expertise_types_target_id']['value'] = array(
  575 => '575',
);
