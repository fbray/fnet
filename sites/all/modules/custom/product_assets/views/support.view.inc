<?php

/**
 * @file
 * support.view.inc
 */

$view = new view();
$view->name = 'support';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Support';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Downloads';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '3600';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '3600';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Go';
$handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
$handler->display->display_options['exposed_form']['options']['bef'] = array(
  'general' => array(
    'input_required' => 1,
    'text_input_required' => array(
      'text_input_required' => array(
        'value' => 'Select any Product and click on Go to see results',
        'format' => 'plain_text',
      ),
    ),
    'allow_secondary' => 0,
    'secondary_label' => 'Advanced options',
    'secondary_collapse_override' => '0',
  ),
  'field_products_target_id' => array(
    'bef_format' => 'default',
    'more_options' => array(
      'bef_select_all_none' => FALSE,
      'bef_collapsible' => 0,
      'autosubmit' => 0,
      'is_secondary' => 0,
      'any_label' => '',
      'bef_filter_description' => '',
      'tokens' => array(
        'available' => array(
          0 => 'global_types',
        ),
      ),
      'rewrite' => array(
        'filter_rewrite_values' => '',
      ),
    ),
  ),
);
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '50';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'title' => 'title',
  'body' => 'title',
  'field_dam_document_id' => 'field_dam_document_id',
  'field_dam_file_size' => 'field_dam_document_id',
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
  'body' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_dam_document_id' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '<br />',
    'empty_column' => 0,
  ),
  'field_dam_file_size' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'No software available for download.';
$handler->display->display_options['empty']['area']['format'] = 'plain_text';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = '';
$handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body']['settings'] = array(
  'field_formatter_filter' => '',
);
/* Field: Content: Document ID */
$handler->display->display_options['fields']['field_dam_document_id']['id'] = 'field_dam_document_id';
$handler->display->display_options['fields']['field_dam_document_id']['table'] = 'field_data_field_dam_document_id';
$handler->display->display_options['fields']['field_dam_document_id']['field'] = 'field_dam_document_id';
$handler->display->display_options['fields']['field_dam_document_id']['label'] = 'Download';
$handler->display->display_options['fields']['field_dam_document_id']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_dam_document_id']['alter']['text'] = 'Download';
$handler->display->display_options['fields']['field_dam_document_id']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['field_dam_document_id']['alter']['path'] = '/findit/[field_dam_document_id]';
$handler->display->display_options['fields']['field_dam_document_id']['settings'] = array(
  'thousand_separator' => '',
  'prefix_suffix' => 0,
);
/* Field: Content: File Size */
$handler->display->display_options['fields']['field_dam_file_size']['id'] = 'field_dam_file_size';
$handler->display->display_options['fields']['field_dam_file_size']['table'] = 'field_data_field_dam_file_size';
$handler->display->display_options['fields']['field_dam_file_size']['field'] = 'field_dam_file_size';
$handler->display->display_options['fields']['field_dam_file_size']['label'] = '';
$handler->display->display_options['fields']['field_dam_file_size']['alter']['text'] = '([field_dam_file_size])';
$handler->display->display_options['fields']['field_dam_file_size']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_dam_file_size']['type'] = 'number_unformatted';
$handler->display->display_options['fields']['field_dam_file_size']['settings'] = array(
  'thousand_separator' => '',
  'prefix_suffix' => 1,
);
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
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
  'digital_asset' => 'digital_asset',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Products (field_related_products) */
$handler->display->display_options['filters']['field_related_products_target_id']['id'] = 'field_related_products_target_id';
$handler->display->display_options['filters']['field_related_products_target_id']['table'] = 'field_data_field_related_products';
$handler->display->display_options['filters']['field_related_products_target_id']['field'] = 'field_related_products_target_id';
$handler->display->display_options['filters']['field_related_products_target_id']['group'] = 1;
$handler->display->display_options['filters']['field_related_products_target_id']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_related_products_target_id']['expose']['operator_id'] = 'field_related_products_target_id_op';
$handler->display->display_options['filters']['field_related_products_target_id']['expose']['label'] = 'Product';
$handler->display->display_options['filters']['field_related_products_target_id']['expose']['operator'] = 'field_related_products_target_id_op';
$handler->display->display_options['filters']['field_related_products_target_id']['expose']['identifier'] = 'field_related_products_target_id';
$handler->display->display_options['filters']['field_related_products_target_id']['expose']['remember_roles'] = array(
  2 => '2',
  3 => 0,
  7 => 0,
  1 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  14 => 0,
  15 => 0,
  16 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  6 => 0,
  22 => 0,
  23 => 0,
  4 => 0,
  5 => 0,
  13 => 0,
);
/* Filter criterion: Content: Language (field_dam_language) */
$handler->display->display_options['filters']['field_dam_language_value']['id'] = 'field_dam_language_value';
$handler->display->display_options['filters']['field_dam_language_value']['table'] = 'field_data_field_dam_language';
$handler->display->display_options['filters']['field_dam_language_value']['field'] = 'field_dam_language_value';
$handler->display->display_options['filters']['field_dam_language_value']['group'] = 1;
$handler->display->display_options['filters']['field_dam_language_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_dam_language_value']['expose']['operator_id'] = 'field_dam_language_value_op';
$handler->display->display_options['filters']['field_dam_language_value']['expose']['label'] = 'Language';
$handler->display->display_options['filters']['field_dam_language_value']['expose']['operator'] = 'field_dam_language_value_op';
$handler->display->display_options['filters']['field_dam_language_value']['expose']['identifier'] = 'field_dam_language_value';
$handler->display->display_options['filters']['field_dam_language_value']['expose']['remember_roles'] = array(
  2 => '2',
  3 => 0,
  7 => 0,
  1 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  14 => 0,
  15 => 0,
  16 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  6 => 0,
  22 => 0,
  23 => 0,
  4 => 0,
  5 => 0,
  13 => 0,
);

/* Display: Downloads */
$handler = $view->new_display('page', 'Downloads', 'page');
$handler->display->display_options['path'] = 'support/downloads';
