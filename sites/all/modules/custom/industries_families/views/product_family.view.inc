<?php

/**
 * @file
 * product_family.view.inc
 */

$view = new view();
$view->name = 'product_family';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Product Family';
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
/* Relationship: Entity Reference: Referenced Entity */
$handler->display->display_options['relationships']['field_product_category_target_id']['id'] = 'field_product_category_target_id';
$handler->display->display_options['relationships']['field_product_category_target_id']['table'] = 'field_data_field_product_category';
$handler->display->display_options['relationships']['field_product_category_target_id']['field'] = 'field_product_category_target_id';
$handler->display->display_options['relationships']['field_product_category_target_id']['required'] = TRUE;
/* Field: Content: Product Category */
$handler->display->display_options['fields']['field_product_category']['id'] = 'field_product_category';
$handler->display->display_options['fields']['field_product_category']['table'] = 'field_data_field_product_category';
$handler->display->display_options['fields']['field_product_category']['field'] = 'field_product_category';
$handler->display->display_options['fields']['field_product_category']['settings'] = array(
  'bypass_access' => 0,
  'link' => 1,
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Product';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
  'product_family' => 'product_family',
);

/* Display: Families by Product Category */
$handler = $view->new_display('embed', 'Families by Product Category', 'families_by_product_category');
$handler->display->display_options['display_description'] = 'List Product Families by Product Category';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Product Category */
$handler->display->display_options['fields']['field_product_category']['id'] = 'field_product_category';
$handler->display->display_options['fields']['field_product_category']['table'] = 'field_data_field_product_category';
$handler->display->display_options['fields']['field_product_category']['field'] = 'field_product_category';
$handler->display->display_options['fields']['field_product_category']['settings'] = array(
  'bypass_access' => 0,
  'link' => 1,
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Family';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Family Page Active */
$handler->display->display_options['fields']['field_family_page_active']['id'] = 'field_family_page_active';
$handler->display->display_options['fields']['field_family_page_active']['table'] = 'field_data_field_family_page_active';
$handler->display->display_options['fields']['field_family_page_active']['field'] = 'field_family_page_active';
$handler->display->display_options['fields']['field_family_page_active']['label'] = '';
$handler->display->display_options['fields']['field_family_page_active']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_family_page_active']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Content: Nid */
$handler->display->display_options['arguments']['nid']['id'] = 'nid';
$handler->display->display_options['arguments']['nid']['table'] = 'node';
$handler->display->display_options['arguments']['nid']['field'] = 'nid';
$handler->display->display_options['arguments']['nid']['relationship'] = 'field_product_category_target_id';
$handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
$handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

/* Display: Products by Family */
$handler = $view->new_display('embed', 'Products by Family', 'products_by_family');
$handler->display->display_options['display_description'] = 'List Products by Family';
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Entity Reference: Referenced Entity */
$handler->display->display_options['relationships']['field_product_family_target_id']['id'] = 'field_product_family_target_id';
$handler->display->display_options['relationships']['field_product_family_target_id']['table'] = 'field_data_field_product_family';
$handler->display->display_options['relationships']['field_product_family_target_id']['field'] = 'field_product_family_target_id';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title_1']['id'] = 'title_1';
$handler->display->display_options['fields']['title_1']['table'] = 'node';
$handler->display->display_options['fields']['title_1']['field'] = 'title';
$handler->display->display_options['fields']['title_1']['relationship'] = 'field_product_family_target_id';
$handler->display->display_options['fields']['title_1']['label'] = 'Family';
$handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Product';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Description */
$handler->display->display_options['fields']['field_description']['id'] = 'field_description';
$handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
$handler->display->display_options['fields']['field_description']['field'] = 'field_description';
$handler->display->display_options['fields']['field_description']['type'] = 'text_plain';
$handler->display->display_options['fields']['field_description']['settings'] = array(
  'field_formatter_filter' => '',
);
/* Field: Draggableviews: Content */
$handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
$handler->display->display_options['fields']['draggableviews']['table'] = 'node';
$handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
$handler->display->display_options['fields']['draggableviews']['label'] = 'Sort';
$handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
/* Field: Content: Hub Image */
$handler->display->display_options['fields']['field_prod_hub_img']['id'] = 'field_prod_hub_img';
$handler->display->display_options['fields']['field_prod_hub_img']['table'] = 'field_data_field_prod_hub_img';
$handler->display->display_options['fields']['field_prod_hub_img']['field'] = 'field_prod_hub_img';
$handler->display->display_options['fields']['field_prod_hub_img']['label'] = '';
$handler->display->display_options['fields']['field_prod_hub_img']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_prod_hub_img']['click_sort_column'] = 'fid';
$handler->display->display_options['fields']['field_prod_hub_img']['settings'] = array(
  'image_style' => '',
  'image_link' => '',
);
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Draggableviews: Weight */
$handler->display->display_options['sorts']['weight']['id'] = 'weight';
$handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
$handler->display->display_options['sorts']['weight']['field'] = 'weight';
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Content: Product Family (field_product_family) */
$handler->display->display_options['arguments']['field_product_family_target_id']['id'] = 'field_product_family_target_id';
$handler->display->display_options['arguments']['field_product_family_target_id']['table'] = 'field_data_field_product_family';
$handler->display->display_options['arguments']['field_product_family_target_id']['field'] = 'field_product_family_target_id';
$handler->display->display_options['arguments']['field_product_family_target_id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['field_product_family_target_id']['summary']['format'] = 'default_summary';
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
  'product_display' => 'product_display',
);

/* Display: Expertise by Product Category */
$handler = $view->new_display('embed', 'Expertise by Product Category', 'expertise_by_family');
$handler->display->display_options['display_description'] = 'List Expertises by Product Category';
$handler->display->display_options['defaults']['relationships'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: All taxonomy terms */
$handler->display->display_options['fields']['term_node_tid']['id'] = 'term_node_tid';
$handler->display->display_options['fields']['term_node_tid']['table'] = 'node';
$handler->display->display_options['fields']['term_node_tid']['field'] = 'term_node_tid';
$handler->display->display_options['fields']['term_node_tid']['label'] = 'Expertise';
$handler->display->display_options['fields']['term_node_tid']['link_to_taxonomy'] = FALSE;
$handler->display->display_options['fields']['term_node_tid']['limit'] = TRUE;
$handler->display->display_options['fields']['term_node_tid']['vocabularies'] = array(
  'expertise_types' => 'expertise_types',
  'asset_tags' => 0,
  'blog_categories' => 0,
  'blog_tags' => 0,
  'brand' => 0,
  'business_entity' => 0,
  'digital_asset_types' => 0,
  'distributor_delivery_type' => 0,
  'distributor_type' => 0,
  'edoc_type' => 0,
  'event_types' => 0,
  'image_galleries' => 0,
  'industries' => 0,
  'knowledge_base' => 0,
  'media_folders' => 0,
  'microsites' => 0,
  'product_attributes' => 0,
  'product_status' => 0,
  'product_sub_types' => 0,
  'promotion_product_category' => 0,
  'promotion_type' => 0,
  'tags' => 0,
);
/* Field: Content: Body */
$handler->display->display_options['fields']['body']['id'] = 'body';
$handler->display->display_options['fields']['body']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body']['field'] = 'body';
$handler->display->display_options['fields']['body']['label'] = 'Summary';
$handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body']['settings'] = array(
  'trim_length' => '600',
  'field_formatter_filter' => 'plain_text',
);
/* Field: Draggableviews: Content */
$handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
$handler->display->display_options['fields']['draggableviews']['table'] = 'node';
$handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
$handler->display->display_options['fields']['draggableviews']['label'] = 'Order';
$handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Draggableviews: Weight */
$handler->display->display_options['sorts']['weight']['id'] = 'weight';
$handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
$handler->display->display_options['sorts']['weight']['field'] = 'weight';
$handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'product_family:expertise_by_family';
$handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 0;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Content: Product Category (field_product_category) */
$handler->display->display_options['arguments']['field_product_category_target_id']['id'] = 'field_product_category_target_id';
$handler->display->display_options['arguments']['field_product_category_target_id']['table'] = 'field_data_field_product_category';
$handler->display->display_options['arguments']['field_product_category_target_id']['field'] = 'field_product_category_target_id';
$handler->display->display_options['arguments']['field_product_category_target_id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['field_product_category_target_id']['summary']['format'] = 'default_summary';
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

/* Display: List Families */
$handler = $view->new_display('entityreference', 'List Families', 'list_families_reference');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['display_description'] = 'List Product Families linked to sort order tool.';
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'entityreference_style';
$handler->display->display_options['style_options']['search_fields'] = array(
  'title' => 'title',
  'nid' => 0,
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'entityreference_fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['text'] = 'Sort Products (Right Click to Open in New Window)';
$handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['path'] = '/admin/viewsorder/industry_family_products/[nid]';
$handler->display->display_options['fields']['nid']['alter']['target'] = '_new';
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';

/* Display: List Industries */
$handler = $view->new_display('entityreference', 'List Industries', 'list_industries_reference');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['display_description'] = 'List Product Categories linked to sort families order';
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'entityreference_style';
$handler->display->display_options['style_options']['search_fields'] = array(
  'title' => 'title',
  'nid' => 0,
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'entityreference_fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['text'] = 'Sort Family for Industry "[title]" (Right Click to Open in New Window)';
$handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['path'] = '/admin/viewsorder/industry_family/[nid]';
$handler->display->display_options['fields']['nid']['alter']['target'] = '_new';
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
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
  'product_category' => 'product_category',
);

/* Display: List Datasheets */
$handler = $view->new_display('entityreference', 'List Datasheets', 'list_datasheets_reference');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['display_description'] = 'List products with linkto Data Sheets sort order';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'entityreference_style';
$handler->display->display_options['style_options']['search_fields'] = array(
  'title' => 'title',
  'nid' => 0,
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'entityreference_fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['relationships'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['text'] = 'Sort Data Sheet (Right Click to Open in New Window)';
$handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['path'] = '/admin/viewsorder/product_datasheet/[nid]';
$handler->display->display_options['fields']['nid']['alter']['target'] = '_new';
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
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
  'product_display' => 'product_display',
);
