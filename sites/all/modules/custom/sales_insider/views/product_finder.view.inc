<?php

/**
 * @file
 * product_finder.view.inc
 */

$view = new view();
$view->name = 'sales_insider_products';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Sales Insider Products';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Product Information';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['group_by'] = TRUE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  5 => '5',
  4 => '4',
);
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '3600';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '3600';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'input_required';
$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
$handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
$handler->display->display_options['exposed_form']['options']['text_input_required'] = '';
$handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'plain_text';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '50';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['grouping'] = array(
  0 => array(
    'field' => 'field_dam_asset_type',
    'rendered' => 1,
    'rendered_strip' => 0,
  ),
);
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['inline'] = array(
  'title' => 'title',
);
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['empty'] = TRUE;
$handler->display->display_options['header']['area']['content'] = 'Select the Product that you want information for.';
$handler->display->display_options['header']['area']['format'] = 'plain_text';
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['label'] = 'No information found';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'No information for this Product was found.';
$handler->display->display_options['empty']['area']['format'] = 'plain_text';
/* Relationship: Content: Parent group */
$handler->display->display_options['relationships']['parent_group']['id'] = 'parent_group';
$handler->display->display_options['relationships']['parent_group']['table'] = 'node';
$handler->display->display_options['relationships']['parent_group']['field'] = 'parent_group';
/* Relationship: Group: Group membership */
$handler->display->display_options['relationships']['group_membership']['id'] = 'group_membership';
$handler->display->display_options['relationships']['group_membership']['table'] = 'groups';
$handler->display->display_options['relationships']['group_membership']['field'] = 'group_membership';
$handler->display->display_options['relationships']['group_membership']['relationship'] = 'parent_group';
/* Field: Content: Document ID */
$handler->display->display_options['fields']['field_dam_document_id']['id'] = 'field_dam_document_id';
$handler->display->display_options['fields']['field_dam_document_id']['table'] = 'field_data_field_dam_document_id';
$handler->display->display_options['fields']['field_dam_document_id']['field'] = 'field_dam_document_id';
$handler->display->display_options['fields']['field_dam_document_id']['label'] = '';
$handler->display->display_options['fields']['field_dam_document_id']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_dam_document_id']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_dam_document_id']['settings'] = array(
  'thousand_separator' => '',
  'prefix_suffix' => 1,
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Asset Type */
$handler->display->display_options['fields']['field_dam_asset_type']['id'] = 'field_dam_asset_type';
$handler->display->display_options['fields']['field_dam_asset_type']['table'] = 'field_data_field_dam_asset_type';
$handler->display->display_options['fields']['field_dam_asset_type']['field'] = 'field_dam_asset_type';
$handler->display->display_options['fields']['field_dam_asset_type']['label'] = '';
$handler->display->display_options['fields']['field_dam_asset_type']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_dam_asset_type']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_dam_asset_type']['settings'] = array(
  'bypass_access' => 0,
  'link' => 0,
);
/* Sort criterion: Content: Asset Type (field_dam_asset_type) */
$handler->display->display_options['sorts']['field_dam_asset_type_target_id']['id'] = 'field_dam_asset_type_target_id';
$handler->display->display_options['sorts']['field_dam_asset_type_target_id']['table'] = 'field_data_field_dam_asset_type';
$handler->display->display_options['sorts']['field_dam_asset_type_target_id']['field'] = 'field_dam_asset_type_target_id';
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
/* Contextual filter: Group membership: User uid */
$handler->display->display_options['arguments']['user']['id'] = 'user';
$handler->display->display_options['arguments']['user']['table'] = 'group_membership';
$handler->display->display_options['arguments']['user']['field'] = 'user';
$handler->display->display_options['arguments']['user']['relationship'] = 'group_membership';
$handler->display->display_options['arguments']['user']['default_action'] = 'default';
$handler->display->display_options['arguments']['user']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['user']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['user']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['user']['summary_options']['items_per_page'] = '25';
/* Contextual filter: Group: Group ID */
$handler->display->display_options['arguments']['gid']['id'] = 'gid';
$handler->display->display_options['arguments']['gid']['table'] = 'groups';
$handler->display->display_options['arguments']['gid']['field'] = 'gid';
$handler->display->display_options['arguments']['gid']['relationship'] = 'parent_group';
$handler->display->display_options['arguments']['gid']['default_action'] = 'default';
$handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['gid']['default_argument_options']['argument'] = 'fnord';
$handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
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
/* Filter criterion: Content: Products (field_related_products) */
$handler->display->display_options['filters']['field_related_products_target_id']['id'] = 'field_related_products_target_id';
$handler->display->display_options['filters']['field_related_products_target_id']['table'] = 'field_data_field_related_products';
$handler->display->display_options['filters']['field_related_products_target_id']['field'] = 'field_related_products_target_id';
$handler->display->display_options['filters']['field_related_products_target_id']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_related_products_target_id']['expose']['operator_id'] = 'field_related_products_target_id_op';
$handler->display->display_options['filters']['field_related_products_target_id']['expose']['label'] = 'Products';
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
/* Filter criterion: Content: Asset Type (field_dam_asset_type) */
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['id'] = 'field_dam_asset_type_target_id';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['table'] = 'field_data_field_dam_asset_type';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['field'] = 'field_dam_asset_type_target_id';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['expose']['operator_id'] = 'field_dam_asset_type_target_id_op';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['expose']['label'] = 'Asset Type';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['expose']['operator'] = 'field_dam_asset_type_target_id_op';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['expose']['identifier'] = 'field_dam_asset_type_target_id';
$handler->display->display_options['filters']['field_dam_asset_type_target_id']['expose']['multiple'] = TRUE;
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
/* Filter criterion: Content: Language (field_dam_language) */
$handler->display->display_options['filters']['field_dam_language_value']['id'] = 'field_dam_language_value';
$handler->display->display_options['filters']['field_dam_language_value']['table'] = 'field_data_field_dam_language';
$handler->display->display_options['filters']['field_dam_language_value']['field'] = 'field_dam_language_value';
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

/* Display: Product Page */
$handler = $view->new_display('page', 'Product Page', 'product_page');
$handler->display->display_options['path'] = 'extranet/tools/products';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Product Information';
$handler->display->display_options['menu']['name'] = 'extranet';

/* Display: Content by Group */
$handler = $view->new_display('page', 'Content by Group', 'content_by_group');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Content by Group';
$handler->display->display_options['display_description'] = 'Listing of content that is a within a given group.';
$handler->display->display_options['defaults']['group_by'] = FALSE;
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '25';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'field_dam_document_id' => 'field_dam_document_id',
  'title' => 'title',
  'field_dam_asset_type' => 'field_dam_asset_type',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'field_dam_document_id' => array(
    'sortable' => 0,
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
  'field_dam_asset_type' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = 'Content for [title_1]';
$handler->display->display_options['header']['area']['format'] = 'plain_text';
$handler->display->display_options['header']['area']['tokenize'] = TRUE;
$handler->display->display_options['defaults']['empty'] = FALSE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Content: Parent group */
$handler->display->display_options['relationships']['parent_group']['id'] = 'parent_group';
$handler->display->display_options['relationships']['parent_group']['table'] = 'node';
$handler->display->display_options['relationships']['parent_group']['field'] = 'parent_group';
/* Relationship: Content: Author */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'node';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Group: Title */
$handler->display->display_options['fields']['title_1']['id'] = 'title_1';
$handler->display->display_options['fields']['title_1']['table'] = 'groups';
$handler->display->display_options['fields']['title_1']['field'] = 'title';
$handler->display->display_options['fields']['title_1']['relationship'] = 'parent_group';
$handler->display->display_options['fields']['title_1']['label'] = '';
$handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
/* Field: Content: Type */
$handler->display->display_options['fields']['type']['id'] = 'type';
$handler->display->display_options['fields']['type']['table'] = 'node';
$handler->display->display_options['fields']['type']['field'] = 'type';
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['relationship'] = 'uid';
$handler->display->display_options['fields']['name']['label'] = 'Author';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Published */
$handler->display->display_options['fields']['status']['id'] = 'status';
$handler->display->display_options['fields']['status']['table'] = 'node';
$handler->display->display_options['fields']['status']['field'] = 'status';
$handler->display->display_options['fields']['status']['not'] = 0;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Posted On';
$handler->display->display_options['fields']['created']['date_format'] = 'long';
$handler->display->display_options['fields']['created']['second_date_format'] = 'long';
/* Field: Content: Edit link */
$handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
$handler->display->display_options['fields']['edit_node']['label'] = 'Edit';
/* Field: Content: Author uid */
$handler->display->display_options['fields']['uid']['id'] = 'uid';
$handler->display->display_options['fields']['uid']['table'] = 'node';
$handler->display->display_options['fields']['uid']['field'] = 'uid';
$handler->display->display_options['fields']['uid']['label'] = '';
$handler->display->display_options['fields']['uid']['exclude'] = TRUE;
$handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Group: Group ID */
$handler->display->display_options['arguments']['gid']['id'] = 'gid';
$handler->display->display_options['arguments']['gid']['table'] = 'groups';
$handler->display->display_options['arguments']['gid']['field'] = 'gid';
$handler->display->display_options['arguments']['gid']['relationship'] = 'parent_group';
$handler->display->display_options['arguments']['gid']['default_action'] = 'default';
$handler->display->display_options['arguments']['gid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['gid']['default_argument_options']['argument'] = 'fnord';
$handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
$handler->display->display_options['path'] = 'admin/extranet/%/content';
