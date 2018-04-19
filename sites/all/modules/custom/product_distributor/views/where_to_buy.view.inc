<?php

/**
 * @file
 * where_to_buy.view.inc
 */

$view = new view();
$view->name = 'distributor';
$view->description = 'Views around Distributors, their locations, and the Where to Buy section.';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Distributor';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Distributor';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'access administration menu';
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '3600';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '3600';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '50';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'field_product_distributor_groups' => 'field_product_distributor_groups',
  'field_address_country' => 'field_address_country',
  'field_address_administrative_area' => 'field_address_administrative_area',
  'field_address_locality' => 'field_address_locality',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'field_product_distributor_groups' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_address_country' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_address_administrative_area' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_address_locality' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Field: Content: Product Distributor Groups */
$handler->display->display_options['fields']['field_product_distributor_groups']['id'] = 'field_product_distributor_groups';
$handler->display->display_options['fields']['field_product_distributor_groups']['table'] = 'field_data_field_product_distributor_groups';
$handler->display->display_options['fields']['field_product_distributor_groups']['field'] = 'field_product_distributor_groups';
$handler->display->display_options['fields']['field_product_distributor_groups']['settings'] = array(
  'bypass_access' => 0,
  'link' => 1,
);
$handler->display->display_options['fields']['field_product_distributor_groups']['delta_offset'] = '0';
/* Field: Field: Address - Country */
$handler->display->display_options['fields']['field_address_country']['id'] = 'field_address_country';
$handler->display->display_options['fields']['field_address_country']['table'] = 'field_data_field_address';
$handler->display->display_options['fields']['field_address_country']['field'] = 'field_address_country';
$handler->display->display_options['fields']['field_address_country']['label'] = 'Country';
$handler->display->display_options['fields']['field_address_country']['display_name'] = 1;
/* Field: Field: Address - Administrative area (i.e. State / Province) */
$handler->display->display_options['fields']['field_address_administrative_area']['id'] = 'field_address_administrative_area';
$handler->display->display_options['fields']['field_address_administrative_area']['table'] = 'field_data_field_address';
$handler->display->display_options['fields']['field_address_administrative_area']['field'] = 'field_address_administrative_area';
$handler->display->display_options['fields']['field_address_administrative_area']['label'] = 'Administrative area';
$handler->display->display_options['fields']['field_address_administrative_area']['display_name'] = 1;
/* Field: Field: Address - Locality (i.e. City) */
$handler->display->display_options['fields']['field_address_locality']['id'] = 'field_address_locality';
$handler->display->display_options['fields']['field_address_locality']['table'] = 'field_data_field_address';
$handler->display->display_options['fields']['field_address_locality']['field'] = 'field_address_locality';
$handler->display->display_options['fields']['field_address_locality']['label'] = 'City';
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
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
  'distributor_location' => 'distributor_location',
);
$handler->display->display_options['filters']['type']['group'] = 1;
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['group'] = 1;
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Location Name';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
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
/* Filter criterion: Content: Product Distributor Groups (field_product_distributor_groups) */
$handler->display->display_options['filters']['field_product_distributor_groups_target_id']['id'] = 'field_product_distributor_groups_target_id';
$handler->display->display_options['filters']['field_product_distributor_groups_target_id']['table'] = 'field_data_field_product_distributor_groups';
$handler->display->display_options['filters']['field_product_distributor_groups_target_id']['field'] = 'field_product_distributor_groups_target_id';
$handler->display->display_options['filters']['field_product_distributor_groups_target_id']['group'] = 1;
$handler->display->display_options['filters']['field_product_distributor_groups_target_id']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_product_distributor_groups_target_id']['expose']['operator_id'] = 'field_product_distributor_groups_target_id_op';
$handler->display->display_options['filters']['field_product_distributor_groups_target_id']['expose']['label'] = 'Distributor Name';
$handler->display->display_options['filters']['field_product_distributor_groups_target_id']['expose']['operator'] = 'field_product_distributor_groups_target_id_op';
$handler->display->display_options['filters']['field_product_distributor_groups_target_id']['expose']['identifier'] = 'field_product_distributor_groups_target_id';
$handler->display->display_options['filters']['field_product_distributor_groups_target_id']['expose']['remember_roles'] = array(
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
/* Filter criterion: Field: Address - Country */
$handler->display->display_options['filters']['field_address_country']['id'] = 'field_address_country';
$handler->display->display_options['filters']['field_address_country']['table'] = 'field_data_field_address';
$handler->display->display_options['filters']['field_address_country']['field'] = 'field_address_country';
$handler->display->display_options['filters']['field_address_country']['group'] = 1;
$handler->display->display_options['filters']['field_address_country']['exposed'] = TRUE;
$handler->display->display_options['filters']['field_address_country']['expose']['operator_id'] = 'field_address_country_op';
$handler->display->display_options['filters']['field_address_country']['expose']['label'] = 'Country';
$handler->display->display_options['filters']['field_address_country']['expose']['operator'] = 'field_address_country_op';
$handler->display->display_options['filters']['field_address_country']['expose']['identifier'] = 'field_address_country';
$handler->display->display_options['filters']['field_address_country']['expose']['remember_roles'] = array(
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

/* Display: Distributor Locations */
$handler = $view->new_display('page', 'Distributor Locations', 'page');
$handler->display->display_options['display_description'] = 'Locations of Distributors for Where to Buy';
$handler->display->display_options['path'] = 'admin/content/wtb-distributor-locations';

/* Display: Do Not Distribute */
$handler = $view->new_display('page', 'Do Not Distribute', 'page_1');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'title' => 'title',
  'field_do_not_distribute' => 'field_do_not_distribute',
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
  'field_do_not_distribute' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Product Name';
/* Field: Content: Do not distribute */
$handler->display->display_options['fields']['field_do_not_distribute']['id'] = 'field_do_not_distribute';
$handler->display->display_options['fields']['field_do_not_distribute']['table'] = 'field_data_field_do_not_distribute';
$handler->display->display_options['fields']['field_do_not_distribute']['field'] = 'field_do_not_distribute';
$handler->display->display_options['fields']['field_do_not_distribute']['delta_offset'] = '0';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'product_display' => 'product_display',
);
/* Filter criterion: Content: Do not distribute (field_do_not_distribute) */
$handler->display->display_options['filters']['field_do_not_distribute_value']['id'] = 'field_do_not_distribute_value';
$handler->display->display_options['filters']['field_do_not_distribute_value']['table'] = 'field_data_field_do_not_distribute';
$handler->display->display_options['filters']['field_do_not_distribute_value']['field'] = 'field_do_not_distribute_value';
$handler->display->display_options['filters']['field_do_not_distribute_value']['operator'] = 'not empty';
$handler->display->display_options['path'] = 'admin/content/wtb-do-not-distribute-products';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'WTB Do Not Distribute';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
