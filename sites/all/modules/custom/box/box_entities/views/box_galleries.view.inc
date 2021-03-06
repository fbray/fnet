<?php

/**
 * @file
 * box_galleries.view.inc
 */

$view = new view();
$view->name = 'box_galleries';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'box_ent_gallery';
$view->human_name = 'Box Galleries';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Product Photos';
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
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Box Gallery: Gallery ID */
$handler->display->display_options['fields']['gid_1']['id'] = 'gid_1';
$handler->display->display_options['fields']['gid_1']['table'] = 'box_ent_gallery';
$handler->display->display_options['fields']['gid_1']['field'] = 'gid';
$handler->display->display_options['fields']['gid_1']['label'] = '';
$handler->display->display_options['fields']['gid_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['gid_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['gid_1']['separator'] = '';
/* Field: Box Gallery: Title */
$handler->display->display_options['fields']['box_title_1']['id'] = 'box_title_1';
$handler->display->display_options['fields']['box_title_1']['table'] = 'box_ent_gallery';
$handler->display->display_options['fields']['box_title_1']['field'] = 'box_title';
$handler->display->display_options['fields']['box_title_1']['label'] = '';
$handler->display->display_options['fields']['box_title_1']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['box_title_1']['alter']['path'] = 'admin/extranet/box_galleries/[gid_1]/edit';
$handler->display->display_options['fields']['box_title_1']['element_label_colon'] = FALSE;
/* Field: Box Gallery: Product Node */
$handler->display->display_options['fields']['content_nid']['id'] = 'content_nid';
$handler->display->display_options['fields']['content_nid']['table'] = 'box_ent_gallery';
$handler->display->display_options['fields']['content_nid']['field'] = 'content_nid';
$handler->display->display_options['fields']['content_nid']['label'] = '';
$handler->display->display_options['fields']['content_nid']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['content_nid']['separator'] = '';
/* Sort criterion: Box Gallery: Title */
$handler->display->display_options['sorts']['box_title']['id'] = 'box_title';
$handler->display->display_options['sorts']['box_title']['table'] = 'box_ent_gallery';
$handler->display->display_options['sorts']['box_title']['field'] = 'box_title';

/* Display: Gallery Admin list */
$handler = $view->new_display('page', 'Gallery Admin list', 'page_1');
$handler->display->display_options['display_description'] = 'List of Box Galleries and edit links.';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'gid_1' => 'gid_1',
  'box_title_1' => 'box_title_1',
  'content_nid' => 'content_nid',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'gid_1' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'box_title_1' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'content_nid' => array(
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
$handler->display->display_options['defaults']['relationships'] = FALSE;
/* Relationship: Field: Related product(s) (field_dam_related_product) */
$handler->display->display_options['relationships']['field_dam_related_product_nid']['id'] = 'field_dam_related_product_nid';
$handler->display->display_options['relationships']['field_dam_related_product_nid']['table'] = 'field_data_field_dam_related_product';
$handler->display->display_options['relationships']['field_dam_related_product_nid']['field'] = 'field_dam_related_product_nid';
$handler->display->display_options['relationships']['field_dam_related_product_nid']['label'] = 'Products Related to Box Folder';
$handler->display->display_options['relationships']['field_dam_related_product_nid']['delta'] = '-1';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Box Gallery: Gallery ID */
$handler->display->display_options['fields']['gid_1']['id'] = 'gid_1';
$handler->display->display_options['fields']['gid_1']['table'] = 'box_ent_gallery';
$handler->display->display_options['fields']['gid_1']['field'] = 'gid';
$handler->display->display_options['fields']['gid_1']['label'] = '';
$handler->display->display_options['fields']['gid_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['gid_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['gid_1']['separator'] = '';
/* Field: Box Gallery: Title */
$handler->display->display_options['fields']['box_title_1']['id'] = 'box_title_1';
$handler->display->display_options['fields']['box_title_1']['table'] = 'box_ent_gallery';
$handler->display->display_options['fields']['box_title_1']['field'] = 'box_title';
$handler->display->display_options['fields']['box_title_1']['label'] = 'Box Gallery folder';
$handler->display->display_options['fields']['box_title_1']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['box_title_1']['alter']['path'] = 'admin/fnet/extranet/box_galleries/[gid_1]/edit';
$handler->display->display_options['fields']['box_title_1']['element_label_colon'] = FALSE;
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['relationship'] = 'field_dam_related_product_nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'field_dam_related_product_nid';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Box Gallery: Title */
$handler->display->display_options['sorts']['box_title']['id'] = 'box_title';
$handler->display->display_options['sorts']['box_title']['table'] = 'box_ent_gallery';
$handler->display->display_options['sorts']['box_title']['field'] = 'box_title';
$handler->display->display_options['path'] = 'admin/fnet/extranet/box_galleries';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Box Galleries';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'management';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Page 2 */
$handler = $view->new_display('page', 'Page 2', 'page_2');
$handler->display->display_options['path'] = 'admin/fnet/extranet/%/box_galleries';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Box Galleries';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Gallery Titles */
$handler = $view->new_display('page', 'Gallery Titles', 'page_3');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Product Photos';
$handler->display->display_options['display_description'] = 'List of titles for Product Photos menu item, used to select Box gallery.';
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  23 => '23',
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Box Gallery: Gallery ID */
$handler->display->display_options['fields']['gid_1']['id'] = 'gid_1';
$handler->display->display_options['fields']['gid_1']['table'] = 'box_ent_gallery';
$handler->display->display_options['fields']['gid_1']['field'] = 'gid';
$handler->display->display_options['fields']['gid_1']['label'] = '';
$handler->display->display_options['fields']['gid_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['gid_1']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['gid_1']['separator'] = '';
/* Field: Box Gallery: Title */
$handler->display->display_options['fields']['box_title_1']['id'] = 'box_title_1';
$handler->display->display_options['fields']['box_title_1']['table'] = 'box_ent_gallery';
$handler->display->display_options['fields']['box_title_1']['field'] = 'box_title';
$handler->display->display_options['fields']['box_title_1']['label'] = '';
$handler->display->display_options['fields']['box_title_1']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['box_title_1']['alter']['path'] = 'extranet/tools/galleries/[gid_1]';
$handler->display->display_options['fields']['box_title_1']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
$handler->display->display_options['path'] = 'extranet/tools/galleries';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Product Photos';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'extranet';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Extranet Gallery Display */
$handler = $view->new_display('page', 'Extranet Gallery Display', 'page_4');
$handler->display->display_options['display_description'] = 'View to display a Box gallery by gallery id';
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  23 => '23',
);
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Global: Messages */
$handler->display->display_options['empty']['messages']['id'] = 'messages';
$handler->display->display_options['empty']['messages']['table'] = 'views';
$handler->display->display_options['empty']['messages']['field'] = 'messages';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Box Gallery: Rendered Box Gallery */
$handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
$handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_box_gallery';
$handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
$handler->display->display_options['fields']['rendered_entity']['label'] = '';
$handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 0;
$handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
$handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'gallery_paged';
$handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Box Gallery: Gallery ID */
$handler->display->display_options['arguments']['gid']['id'] = 'gid';
$handler->display->display_options['arguments']['gid']['table'] = 'box_ent_gallery';
$handler->display->display_options['arguments']['gid']['field'] = 'gid';
$handler->display->display_options['arguments']['gid']['default_action'] = 'default';
$handler->display->display_options['arguments']['gid']['default_argument_type'] = 'node';
$handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['path'] = 'extranet/tools/galleries/%';
$handler->display->display_options['menu']['title'] = 'Product Photos';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'extranet';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$translatables['box_galleries'] = array(
  t('Master'),
  t('Product Photos'),
  t('more'),
  t('Apply'),
  t('Reset'),
  t('Sort by'),
  t('Asc'),
  t('Desc'),
  t('.'),
  t('Gallery Admin list'),
  t('List of Box Galleries and edit links.'),
  t('Products Related to Box Folder'),
  t('Box Gallery folder'),
  t('Title'),
  t('Page 2'),
  t('Gallery Titles'),
  t('List of titles for Product Photos menu item, used to select Box gallery.'),
  t('Extranet Gallery Display'),
  t('View to display a Box gallery by gallery id'),
  t('All'),
);
