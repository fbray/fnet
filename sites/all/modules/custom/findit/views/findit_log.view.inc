<?php

/**
 * @file
 * findit_log.view.inc
 */

$view = new view();
$view->name = 'findit_log';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'findit_log';
$view->human_name = 'Findit log (short)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Findit log (short)';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  5 => '5',
  6 => '6',
  21 => '21',
  8 => '8',
  10 => '10',
);
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '3600';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '3600';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '25';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'field_user_first_name' => 'field_user_first_name',
  'field_user_last_name' => 'field_user_last_name',
  'mail' => 'mail',
  'field_dam_document_id' => 'field_dam_document_id',
  'title' => 'title',
  'field_dam_storage_filename' => 'field_dam_storage_filename',
  'date_downloaded' => 'date_downloaded',
);
$handler->display->display_options['style_options']['default'] = 'date_downloaded';
$handler->display->display_options['style_options']['info'] = array(
  'field_user_first_name' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_user_last_name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'mail' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_dam_document_id' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_dam_storage_filename' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'date_downloaded' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Relationship: Findit Log: Asset Id */
$handler->display->display_options['relationships']['asset_id']['id'] = 'asset_id';
$handler->display->display_options['relationships']['asset_id']['table'] = 'findit_log';
$handler->display->display_options['relationships']['asset_id']['field'] = 'asset_id';
$handler->display->display_options['relationships']['asset_id']['required'] = TRUE;
/* Relationship: Findit Log: User Id */
$handler->display->display_options['relationships']['user_id']['id'] = 'user_id';
$handler->display->display_options['relationships']['user_id']['table'] = 'findit_log';
$handler->display->display_options['relationships']['user_id']['field'] = 'user_id';
$handler->display->display_options['relationships']['user_id']['required'] = TRUE;
/* Field: User: E-mail */
$handler->display->display_options['fields']['mail']['id'] = 'mail';
$handler->display->display_options['fields']['mail']['table'] = 'users';
$handler->display->display_options['fields']['mail']['field'] = 'mail';
$handler->display->display_options['fields']['mail']['relationship'] = 'user_id';
/* Field: Content: Document ID */
$handler->display->display_options['fields']['field_dam_document_id']['id'] = 'field_dam_document_id';
$handler->display->display_options['fields']['field_dam_document_id']['table'] = 'field_data_field_dam_document_id';
$handler->display->display_options['fields']['field_dam_document_id']['field'] = 'field_dam_document_id';
$handler->display->display_options['fields']['field_dam_document_id']['relationship'] = 'asset_id';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'asset_id';
/* Field: Findit Log: Date Downloaded */
$handler->display->display_options['fields']['date_downloaded']['id'] = 'date_downloaded';
$handler->display->display_options['fields']['date_downloaded']['table'] = 'findit_log';
$handler->display->display_options['fields']['date_downloaded']['field'] = 'date_downloaded';
$handler->display->display_options['fields']['date_downloaded']['date_format'] = 'custom';
$handler->display->display_options['fields']['date_downloaded']['custom_date_format'] = 'm/d/Y';
$handler->display->display_options['fields']['date_downloaded']['second_date_format'] = 'long';
/* Filter criterion: Findit Log: Date Downloaded */
$handler->display->display_options['filters']['date_downloaded']['id'] = 'date_downloaded';
$handler->display->display_options['filters']['date_downloaded']['table'] = 'findit_log';
$handler->display->display_options['filters']['date_downloaded']['field'] = 'date_downloaded';
$handler->display->display_options['filters']['date_downloaded']['operator'] = 'between';
$handler->display->display_options['filters']['date_downloaded']['exposed'] = TRUE;
$handler->display->display_options['filters']['date_downloaded']['expose']['operator_id'] = 'date_downloaded_op';
$handler->display->display_options['filters']['date_downloaded']['expose']['label'] = 'Downloaded between';
$handler->display->display_options['filters']['date_downloaded']['expose']['operator'] = 'date_downloaded_op';
$handler->display->display_options['filters']['date_downloaded']['expose']['identifier'] = 'date_downloaded';
$handler->display->display_options['filters']['date_downloaded']['expose']['remember_roles'] = array(
  2 => '2',
  5 => 0,
  19 => 0,
  1 => 0,
  6 => 0,
  20 => 0,
  4 => 0,
  7 => 0,
  3 => 0,
  21 => 0,
  18 => 0,
  17 => 0,
  12 => 0,
  11 => 0,
  14 => 0,
  16 => 0,
  8 => 0,
  10 => 0,
  13 => 0,
  15 => 0,
  9 => 0,
);
/* Filter criterion: Content: Document ID (field_dam_document_id) */
$handler->display->display_options['filters']['field_dam_document_id_value']['id'] = 'field_dam_document_id_value';
$handler->display->display_options['filters']['field_dam_document_id_value']['table'] = 'field_data_field_dam_document_id';
$handler->display->display_options['filters']['field_dam_document_id_value']['field'] = 'field_dam_document_id_value';
$handler->display->display_options['filters']['field_dam_document_id_value']['relationship'] = 'asset_id';
$handler->display->display_options['filters']['field_dam_document_id_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_dam_document_id_value']['expose']['operator_id'] = 'field_dam_document_id_value_op';
$handler->display->display_options['filters']['field_dam_document_id_value']['expose']['label'] = 'Document ID';
$handler->display->display_options['filters']['field_dam_document_id_value']['expose']['operator'] = 'field_dam_document_id_value_op';
$handler->display->display_options['filters']['field_dam_document_id_value']['expose']['identifier'] = 'field_dam_document_id_value';
$handler->display->display_options['filters']['field_dam_document_id_value']['expose']['remember_roles'] = array(
  2 => '2',
  5 => 0,
  19 => 0,
  1 => 0,
  6 => 0,
  20 => 0,
  4 => 0,
  7 => 0,
  3 => 0,
  21 => 0,
  18 => 0,
  17 => 0,
  12 => 0,
  11 => 0,
  14 => 0,
  16 => 0,
  8 => 0,
  10 => 0,
  13 => 0,
  15 => 0,
  9 => 0,
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Findit Log: Date Downloaded */
$handler->display->display_options['filters']['date_downloaded']['id'] = 'date_downloaded';
$handler->display->display_options['filters']['date_downloaded']['table'] = 'findit_log';
$handler->display->display_options['filters']['date_downloaded']['field'] = 'date_downloaded';
$handler->display->display_options['filters']['date_downloaded']['operator'] = 'between';
$handler->display->display_options['filters']['date_downloaded']['exposed'] = TRUE;
$handler->display->display_options['filters']['date_downloaded']['expose']['operator_id'] = 'date_downloaded_op';
$handler->display->display_options['filters']['date_downloaded']['expose']['label'] = 'Downloaded between';
$handler->display->display_options['filters']['date_downloaded']['expose']['description'] = 'Enter date in YYYY-MM-DD HH:MM:SS format e.g. 2018-01-20 59:59:20';
$handler->display->display_options['filters']['date_downloaded']['expose']['operator'] = 'date_downloaded_op';
$handler->display->display_options['filters']['date_downloaded']['expose']['identifier'] = 'date_downloaded';
$handler->display->display_options['filters']['date_downloaded']['expose']['remember_roles'] = array(
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
/* Filter criterion: Content: Document ID (field_dam_document_id) */
$handler->display->display_options['filters']['field_dam_document_id_value']['id'] = 'field_dam_document_id_value';
$handler->display->display_options['filters']['field_dam_document_id_value']['table'] = 'field_data_field_dam_document_id';
$handler->display->display_options['filters']['field_dam_document_id_value']['field'] = 'field_dam_document_id_value';
$handler->display->display_options['filters']['field_dam_document_id_value']['relationship'] = 'asset_id';
$handler->display->display_options['filters']['field_dam_document_id_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_dam_document_id_value']['expose']['operator_id'] = 'field_dam_document_id_value_op';
$handler->display->display_options['filters']['field_dam_document_id_value']['expose']['label'] = 'Document ID';
$handler->display->display_options['filters']['field_dam_document_id_value']['expose']['operator'] = 'field_dam_document_id_value_op';
$handler->display->display_options['filters']['field_dam_document_id_value']['expose']['identifier'] = 'field_dam_document_id_value';
$handler->display->display_options['filters']['field_dam_document_id_value']['expose']['remember_roles'] = array(
  2 => '2',
  5 => 0,
  19 => 0,
  1 => 0,
  6 => 0,
  20 => 0,
  4 => 0,
  7 => 0,
  3 => 0,
  21 => 0,
  18 => 0,
  17 => 0,
  12 => 0,
  11 => 0,
  14 => 0,
  16 => 0,
  8 => 0,
  10 => 0,
  13 => 0,
  15 => 0,
  9 => 0,
);
/* Filter criterion: Content: Asset Type (field_dam_asset_type) */
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['id'] = 'field_dam_asset_type_target_id';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['table'] = 'field_data_field_dam_asset_type';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['field'] = 'field_dam_asset_type_target_id';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['relationship'] = 'asset_id';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['expose']['operator_id'] = 'field_dam_asset_type_target_id_op';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['expose']['label'] = 'Asset Type';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['expose']['operator'] = 'field_dam_asset_type_target_id_op';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['expose']['identifier'] = 'field_dam_asset_type_target_id';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['expose']['remember_roles'] = array(
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
$handler->display->display_options['path'] = 'admin/fnet/findit/findit-log';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Findit Log (short)';
$handler->display->display_options['menu']['description'] = 'Findit download log';
$handler->display->display_options['menu']['weight'] = '3';
$handler->display->display_options['menu']['name'] = 'management';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Data export */
$handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'views_data_export_csv';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Findit Log: Date Downloaded */
$handler->display->display_options['filters']['date_downloaded']['id'] = 'date_downloaded';
$handler->display->display_options['filters']['date_downloaded']['table'] = 'findit_log';
$handler->display->display_options['filters']['date_downloaded']['field'] = 'date_downloaded';
$handler->display->display_options['filters']['date_downloaded']['operator'] = 'between';
$handler->display->display_options['filters']['date_downloaded']['exposed'] = TRUE;
$handler->display->display_options['filters']['date_downloaded']['expose']['operator_id'] = 'date_downloaded_op';
$handler->display->display_options['filters']['date_downloaded']['expose']['label'] = 'Downloaded between';
$handler->display->display_options['filters']['date_downloaded']['expose']['operator'] = 'date_downloaded_op';
$handler->display->display_options['filters']['date_downloaded']['expose']['identifier'] = 'date_downloaded';
$handler->display->display_options['filters']['date_downloaded']['expose']['remember_roles'] = array(
  2 => '2',
  5 => 0,
  19 => 0,
  1 => 0,
  6 => 0,
  20 => 0,
  4 => 0,
  7 => 0,
  3 => 0,
  21 => 0,
  18 => 0,
  17 => 0,
  12 => 0,
  11 => 0,
  14 => 0,
  16 => 0,
  8 => 0,
  10 => 0,
  13 => 0,
  15 => 0,
  9 => 0,
);
/* Filter criterion: Content: Document ID (field_dam_document_id) */
$handler->display->display_options['filters']['field_dam_document_id_value']['id'] = 'field_dam_document_id_value';
$handler->display->display_options['filters']['field_dam_document_id_value']['table'] = 'field_data_field_dam_document_id';
$handler->display->display_options['filters']['field_dam_document_id_value']['field'] = 'field_dam_document_id_value';
$handler->display->display_options['filters']['field_dam_document_id_value']['relationship'] = 'asset_id';
$handler->display->display_options['filters']['field_dam_document_id_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_dam_document_id_value']['expose']['operator_id'] = 'field_dam_document_id_value_op';
$handler->display->display_options['filters']['field_dam_document_id_value']['expose']['label'] = 'Document ID';
$handler->display->display_options['filters']['field_dam_document_id_value']['expose']['operator'] = 'field_dam_document_id_value_op';
$handler->display->display_options['filters']['field_dam_document_id_value']['expose']['identifier'] = 'field_dam_document_id_value';
$handler->display->display_options['filters']['field_dam_document_id_value']['expose']['remember_roles'] = array(
  2 => '2',
  5 => 0,
  19 => 0,
  1 => 0,
  6 => 0,
  20 => 0,
  4 => 0,
  7 => 0,
  3 => 0,
  21 => 0,
  18 => 0,
  17 => 0,
  12 => 0,
  11 => 0,
  14 => 0,
  16 => 0,
  8 => 0,
  10 => 0,
  13 => 0,
  15 => 0,
  9 => 0,
);
/* Filter criterion: Content: Asset Type (field_dam_asset_type) */
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['id'] = 'field_dam_asset_type_target_id';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['table'] = 'field_data_field_dam_asset_type';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['field'] = 'field_dam_asset_type_target_id';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['relationship'] = 'asset_id';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['expose']['operator_id'] = 'field_dam_asset_type_target_id_op';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['expose']['label'] = 'Asset Type';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['expose']['operator'] = 'field_dam_asset_type_target_id_op';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['expose']['identifier'] = 'field_dam_asset_type_target_id';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['expose']['remember_roles'] = array(
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
$handler->display->display_options['path'] = 'admin/fnet/findit/findit-log.csv';
$handler->display->display_options['displays'] = array(
  'page' => 'page',
  'default' => 0,
);

$views[] = $view;

$view = new view();
$view->name = 'findit_log_long';
$view->description = 'Findit log with user profile info';
$view->tag = 'default';
$view->base_table = 'findit_log';
$view->human_name = 'Findit log (long)';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Findit Log (long)';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  5 => '5',
  6 => '6',
  21 => '21',
  18 => '18',
  8 => '8',
  10 => '10',
);
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '25';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'mail' => 'mail',
  'field_user_first_name' => 'field_user_first_name',
  'field_user_last_name' => 'field_user_last_name',
  'field_user_company' => 'field_user_company',
  'field_user_address_line_1' => 'field_user_address_line_1',
  'field_user_address_line_2' => 'field_user_address_line_2',
  'field_user_city' => 'field_user_city',
  'field_user_province' => 'field_user_province',
  'field_user_country' => 'field_user_country',
  'field_user_postal_code' => 'field_user_postal_code',
  'field_user_job_role' => 'field_user_job_role',
  'field_user_phone' => 'field_user_phone',
  'field_dam_document_id' => 'field_dam_document_id',
  'title' => 'title',
  'field_dam_storage_filename' => 'field_dam_storage_filename',
  'date_downloaded' => 'date_downloaded',
);
$handler->display->display_options['style_options']['default'] = 'date_downloaded';
$handler->display->display_options['style_options']['info'] = array(
  'mail' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_user_first_name' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_user_last_name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_user_company' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_user_address_line_1' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_user_address_line_2' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_user_city' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_user_province' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_user_country' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_user_postal_code' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_user_job_role' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_user_phone' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_dam_document_id' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_dam_storage_filename' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'date_downloaded' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Relationship: Findit Log: Asset Id */
$handler->display->display_options['relationships']['asset_id']['id'] = 'asset_id';
$handler->display->display_options['relationships']['asset_id']['table'] = 'findit_log';
$handler->display->display_options['relationships']['asset_id']['field'] = 'asset_id';
$handler->display->display_options['relationships']['asset_id']['required'] = TRUE;
/* Relationship: Findit Log: User Id */
$handler->display->display_options['relationships']['user_id']['id'] = 'user_id';
$handler->display->display_options['relationships']['user_id']['table'] = 'findit_log';
$handler->display->display_options['relationships']['user_id']['field'] = 'user_id';
$handler->display->display_options['relationships']['user_id']['required'] = TRUE;
/* Field: User: E-mail */
$handler->display->display_options['fields']['mail']['id'] = 'mail';
$handler->display->display_options['fields']['mail']['table'] = 'users';
$handler->display->display_options['fields']['mail']['field'] = 'mail';
$handler->display->display_options['fields']['mail']['relationship'] = 'user_id';
$handler->display->display_options['fields']['mail']['link_to_user'] = '0';
/* Field: Field: Address - First name */
$handler->display->display_options['fields']['field_address_first_name']['id'] = 'field_address_first_name';
$handler->display->display_options['fields']['field_address_first_name']['table'] = 'field_data_field_address';
$handler->display->display_options['fields']['field_address_first_name']['field'] = 'field_address_first_name';
$handler->display->display_options['fields']['field_address_first_name']['relationship'] = 'user_id';
$handler->display->display_options['fields']['field_address_first_name']['label'] = 'First name';
/* Field: Field: Address - Last name */
$handler->display->display_options['fields']['field_address_last_name']['id'] = 'field_address_last_name';
$handler->display->display_options['fields']['field_address_last_name']['table'] = 'field_data_field_address';
$handler->display->display_options['fields']['field_address_last_name']['field'] = 'field_address_last_name';
$handler->display->display_options['fields']['field_address_last_name']['relationship'] = 'user_id';
$handler->display->display_options['fields']['field_address_last_name']['label'] = 'Last name';
/* Field: Field: Address - Company */
$handler->display->display_options['fields']['field_address_organisation_name']['id'] = 'field_address_organisation_name';
$handler->display->display_options['fields']['field_address_organisation_name']['table'] = 'field_data_field_address';
$handler->display->display_options['fields']['field_address_organisation_name']['field'] = 'field_address_organisation_name';
$handler->display->display_options['fields']['field_address_organisation_name']['relationship'] = 'user_id';
$handler->display->display_options['fields']['field_address_organisation_name']['label'] = 'Company';
/* Field: Field: Address - Thoroughfare (i.e. Street address) */
$handler->display->display_options['fields']['field_address_thoroughfare']['id'] = 'field_address_thoroughfare';
$handler->display->display_options['fields']['field_address_thoroughfare']['table'] = 'field_data_field_address';
$handler->display->display_options['fields']['field_address_thoroughfare']['field'] = 'field_address_thoroughfare';
$handler->display->display_options['fields']['field_address_thoroughfare']['relationship'] = 'user_id';
$handler->display->display_options['fields']['field_address_thoroughfare']['label'] = 'Address Line 1';
/* Field: Field: Address - Premise (i.e. Apartment / Suite number) */
$handler->display->display_options['fields']['field_address_premise']['id'] = 'field_address_premise';
$handler->display->display_options['fields']['field_address_premise']['table'] = 'field_data_field_address';
$handler->display->display_options['fields']['field_address_premise']['field'] = 'field_address_premise';
$handler->display->display_options['fields']['field_address_premise']['relationship'] = 'user_id';
$handler->display->display_options['fields']['field_address_premise']['label'] = 'Address Line 2';
/* Field: Field: Address - Locality (i.e. City) */
$handler->display->display_options['fields']['field_address_locality']['id'] = 'field_address_locality';
$handler->display->display_options['fields']['field_address_locality']['table'] = 'field_data_field_address';
$handler->display->display_options['fields']['field_address_locality']['field'] = 'field_address_locality';
$handler->display->display_options['fields']['field_address_locality']['relationship'] = 'user_id';
$handler->display->display_options['fields']['field_address_locality']['label'] = 'City';
/* Field: Field: Address - Administrative area (i.e. State / Province) */
$handler->display->display_options['fields']['field_address_administrative_area']['id'] = 'field_address_administrative_area';
$handler->display->display_options['fields']['field_address_administrative_area']['table'] = 'field_data_field_address';
$handler->display->display_options['fields']['field_address_administrative_area']['field'] = 'field_address_administrative_area';
$handler->display->display_options['fields']['field_address_administrative_area']['relationship'] = 'user_id';
$handler->display->display_options['fields']['field_address_administrative_area']['label'] = 'Province';
$handler->display->display_options['fields']['field_address_administrative_area']['display_name'] = 1;
/* Field: Field: Address - Country */
$handler->display->display_options['fields']['field_address_country']['id'] = 'field_address_country';
$handler->display->display_options['fields']['field_address_country']['table'] = 'field_data_field_address';
$handler->display->display_options['fields']['field_address_country']['field'] = 'field_address_country';
$handler->display->display_options['fields']['field_address_country']['relationship'] = 'user_id';
$handler->display->display_options['fields']['field_address_country']['label'] = 'Country';
$handler->display->display_options['fields']['field_address_country']['display_name'] = 1;
/* Field: Field: Address - Postal code */
$handler->display->display_options['fields']['field_address_postal_code']['id'] = 'field_address_postal_code';
$handler->display->display_options['fields']['field_address_postal_code']['table'] = 'field_data_field_address';
$handler->display->display_options['fields']['field_address_postal_code']['field'] = 'field_address_postal_code';
$handler->display->display_options['fields']['field_address_postal_code']['relationship'] = 'user_id';
$handler->display->display_options['fields']['field_address_postal_code']['label'] = 'ZIP/Postal code';
/* Field: User: Job Role */
$handler->display->display_options['fields']['field_user_job_role']['id'] = 'field_user_job_role';
$handler->display->display_options['fields']['field_user_job_role']['table'] = 'field_data_field_user_job_role';
$handler->display->display_options['fields']['field_user_job_role']['field'] = 'field_user_job_role';
$handler->display->display_options['fields']['field_user_job_role']['relationship'] = 'user_id';
/* Field: User: Telephone */
$handler->display->display_options['fields']['field_user_telephone']['id'] = 'field_user_telephone';
$handler->display->display_options['fields']['field_user_telephone']['table'] = 'field_data_field_user_telephone';
$handler->display->display_options['fields']['field_user_telephone']['field'] = 'field_user_telephone';
$handler->display->display_options['fields']['field_user_telephone']['relationship'] = 'user_id';
/* Field: Content: Document ID */
$handler->display->display_options['fields']['field_dam_document_id']['id'] = 'field_dam_document_id';
$handler->display->display_options['fields']['field_dam_document_id']['table'] = 'field_data_field_dam_document_id';
$handler->display->display_options['fields']['field_dam_document_id']['field'] = 'field_dam_document_id';
$handler->display->display_options['fields']['field_dam_document_id']['relationship'] = 'asset_id';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'asset_id';
/* Field: Content: Storage File Name */
$handler->display->display_options['fields']['field_dam_storage_file_name']['id'] = 'field_dam_storage_file_name';
$handler->display->display_options['fields']['field_dam_storage_file_name']['table'] = 'field_data_field_dam_storage_file_name';
$handler->display->display_options['fields']['field_dam_storage_file_name']['field'] = 'field_dam_storage_file_name';
$handler->display->display_options['fields']['field_dam_storage_file_name']['relationship'] = 'asset_id';
$handler->display->display_options['fields']['field_dam_storage_file_name']['label'] = 'File Name';
$handler->display->display_options['fields']['field_dam_storage_file_name']['settings'] = array(
  'field_formatter_filter' => '',
);
/* Field: Findit Log: Date Downloaded */
$handler->display->display_options['fields']['date_downloaded']['id'] = 'date_downloaded';
$handler->display->display_options['fields']['date_downloaded']['table'] = 'findit_log';
$handler->display->display_options['fields']['date_downloaded']['field'] = 'date_downloaded';
$handler->display->display_options['fields']['date_downloaded']['date_format'] = 'short';
$handler->display->display_options['fields']['date_downloaded']['second_date_format'] = 'long';
/* Filter criterion: Findit Log: Date Downloaded */
$handler->display->display_options['filters']['date_downloaded']['id'] = 'date_downloaded';
$handler->display->display_options['filters']['date_downloaded']['table'] = 'findit_log';
$handler->display->display_options['filters']['date_downloaded']['field'] = 'date_downloaded';
$handler->display->display_options['filters']['date_downloaded']['operator'] = 'between';
$handler->display->display_options['filters']['date_downloaded']['exposed'] = TRUE;
$handler->display->display_options['filters']['date_downloaded']['expose']['operator_id'] = 'date_downloaded_op';
$handler->display->display_options['filters']['date_downloaded']['expose']['label'] = 'Downloaded between';
$handler->display->display_options['filters']['date_downloaded']['expose']['description'] = 'Enter date in YYYY-MM-DD HH:MM:SS format e.g. 2018-01-20 59:59:20';
$handler->display->display_options['filters']['date_downloaded']['expose']['operator'] = 'date_downloaded_op';
$handler->display->display_options['filters']['date_downloaded']['expose']['identifier'] = 'date_downloaded';
$handler->display->display_options['filters']['date_downloaded']['expose']['remember_roles'] = array(
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
/* Filter criterion: Content: Document ID (field_dam_document_id) */
$handler->display->display_options['filters']['field_dam_document_id_value']['id'] = 'field_dam_document_id_value';
$handler->display->display_options['filters']['field_dam_document_id_value']['table'] = 'field_data_field_dam_document_id';
$handler->display->display_options['filters']['field_dam_document_id_value']['field'] = 'field_dam_document_id_value';
$handler->display->display_options['filters']['field_dam_document_id_value']['relationship'] = 'asset_id';
$handler->display->display_options['filters']['field_dam_document_id_value']['operator'] = 'contains';
$handler->display->display_options['filters']['field_dam_document_id_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_dam_document_id_value']['expose']['operator_id'] = 'field_dam_document_id_value_op';
$handler->display->display_options['filters']['field_dam_document_id_value']['expose']['label'] = 'Document ID';
$handler->display->display_options['filters']['field_dam_document_id_value']['expose']['operator'] = 'field_dam_document_id_value_op';
$handler->display->display_options['filters']['field_dam_document_id_value']['expose']['identifier'] = 'field_dam_document_id_value';
$handler->display->display_options['filters']['field_dam_document_id_value']['expose']['remember_roles'] = array(
  2 => '2',
  5 => 0,
  19 => 0,
  1 => 0,
  6 => 0,
  20 => 0,
  4 => 0,
  7 => 0,
  3 => 0,
  21 => 0,
  18 => 0,
  17 => 0,
  12 => 0,
  11 => 0,
  14 => 0,
  16 => 0,
  8 => 0,
  10 => 0,
  13 => 0,
  15 => 0,
  9 => 0,
);
/* Filter criterion: Findit Log: User Id */
$handler->display->display_options['filters']['user_id']['id'] = 'user_id';
$handler->display->display_options['filters']['user_id']['table'] = 'findit_log';
$handler->display->display_options['filters']['user_id']['field'] = 'user_id';
$handler->display->display_options['filters']['user_id']['operator'] = '>';
$handler->display->display_options['filters']['user_id']['value']['value'] = '0';
/* Filter criterion: Content: Asset Type (field_asset_type) */
$handler->display->display_options['filters']['field_asset_type_value']['id'] = 'field_asset_type_value';
$handler->display->display_options['filters']['field_asset_type_value']['table'] = 'field_data_field_asset_type';
$handler->display->display_options['filters']['field_asset_type_value']['field'] = 'field_asset_type_value';
$handler->display->display_options['filters']['field_asset_type_value']['relationship'] = 'asset_id';
$handler->display->display_options['filters']['field_asset_type_value']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_asset_type_value']['expose']['operator_id'] = 'field_asset_type_value_op';
$handler->display->display_options['filters']['field_asset_type_value']['expose']['label'] = 'Asset Type';
$handler->display->display_options['filters']['field_asset_type_value']['expose']['operator'] = 'field_asset_type_value_op';
$handler->display->display_options['filters']['field_asset_type_value']['expose']['identifier'] = 'field_asset_type_value';
$handler->display->display_options['filters']['field_asset_type_value']['expose']['remember_roles'] = array(
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

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'admin/fnet/findit/findit-log-long';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Findit Log (long)';
$handler->display->display_options['menu']['description'] = 'Findit log with full user profile info';
$handler->display->display_options['menu']['weight'] = '6';
$handler->display->display_options['menu']['name'] = 'management';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Data export */
$handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'views_data_export_csv';
$handler->display->display_options['path'] = 'admin/fnet/findit/findit-log-long.csv';
$handler->display->display_options['displays'] = array(
  'page' => 'page',
  'default' => 0,
);
