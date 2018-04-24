<?php

/**
 * @file
 * news_events_awards.view.inc
 */

$view = new view();
$view->name = 'news_events_and_awards';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'News, Events, and Awards';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Awards';
$handler->display->display_options['css_class'] = 'newsview';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '3600';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '3600';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Field: Content: Date Awarded */
$handler->display->display_options['fields']['field_award_date']['id'] = 'field_award_date';
$handler->display->display_options['fields']['field_award_date']['table'] = 'field_data_field_award_date';
$handler->display->display_options['fields']['field_award_date']['field'] = 'field_award_date';
$handler->display->display_options['fields']['field_award_date']['label'] = '';
$handler->display->display_options['fields']['field_award_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_award_date']['settings'] = array(
  'format_type' => 'custom',
  'custom_date_format' => 'F j, Y',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '[title] <br/><br/>';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Sort criterion: Weight: Weight */
$handler->display->display_options['sorts']['weight']['id'] = 'weight';
$handler->display->display_options['sorts']['weight']['table'] = 'weight_weights';
$handler->display->display_options['sorts']['weight']['field'] = 'weight';
/* Sort criterion: Content: Date Awarded (field_award_date) */
$handler->display->display_options['sorts']['field_award_date_value']['id'] = 'field_award_date_value';
$handler->display->display_options['sorts']['field_award_date_value']['table'] = 'field_data_field_award_date';
$handler->display->display_options['sorts']['field_award_date_value']['field'] = 'field_award_date_value';
$handler->display->display_options['sorts']['field_award_date_value']['order'] = 'DESC';
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
  'award' => 'award',
);

/* Display: Awards */
$handler = $view->new_display('page', 'Awards', 'page');
$handler->display->display_options['display_description'] = 'A list of Awards';
$handler->display->display_options['path'] = 'awards-list';
