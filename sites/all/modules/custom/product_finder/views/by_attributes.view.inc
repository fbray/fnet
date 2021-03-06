<?php

/**
 * @file
 * by_attributes.view.inc
 */

$view = new view();
$view->name = 'product_finder';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Product Finder';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Product Finder';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['group_by'] = TRUE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '3600';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '3600';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['distinct'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['grouping'] = array(
  0 => array(
    'field' => 'name_i18n',
    'rendered' => 0,
    'rendered_strip' => 0,
  ),
);
$handler->display->display_options['row_plugin'] = 'fields';
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'Sorry, no records were found for your selection.';
$handler->display->display_options['empty']['area']['format'] = 'plain_text';
/* Relationship: Content: Taxonomy terms on node */
$handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
$handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
$handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
/* Field: Taxonomy term: Name (translated) */
$handler->display->display_options['fields']['name_i18n']['id'] = 'name_i18n';
$handler->display->display_options['fields']['name_i18n']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['name_i18n']['field'] = 'name_i18n';
$handler->display->display_options['fields']['name_i18n']['relationship'] = 'term_node_tid';
$handler->display->display_options['fields']['name_i18n']['label'] = '';
$handler->display->display_options['fields']['name_i18n']['exclude'] = TRUE;
$handler->display->display_options['fields']['name_i18n']['element_label_colon'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Description */
$handler->display->display_options['fields']['field_description']['id'] = 'field_description';
$handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
$handler->display->display_options['fields']['field_description']['field'] = 'field_description';
$handler->display->display_options['fields']['field_description']['label'] = '';
$handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_description']['type'] = 'text_plain';
$handler->display->display_options['fields']['field_description']['settings'] = array(
  'field_formatter_filter' => '',
);
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
/* Contextual filter: Content: Has taxonomy term ID (translated) */
$handler->display->display_options['arguments']['tid_i18n']['id'] = 'tid_i18n';
$handler->display->display_options['arguments']['tid_i18n']['table'] = 'taxonomy_index';
$handler->display->display_options['arguments']['tid_i18n']['field'] = 'tid_i18n';
$handler->display->display_options['arguments']['tid_i18n']['default_action'] = 'empty';
$handler->display->display_options['arguments']['tid_i18n']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['tid_i18n']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['tid_i18n']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['tid_i18n']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['tid_i18n']['break_phrase'] = TRUE;
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

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page_1');
$handler->display->display_options['path'] = 'product-finder/%';
