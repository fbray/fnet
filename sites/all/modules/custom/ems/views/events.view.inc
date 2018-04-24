<?php

/**
 * @file
 * events.view.inc
 */

$view = new view();
$view->name = 'events';
$view->description = 'Views of Events and Event Occurrances';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Events';
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
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'field_event_date' => 'field_event_date',
  'field_event_date_1' => 'field_event_date_1',
  'field_address_locality' => 'field_address_locality',
  'field_address_administrative_area' => 'field_address_locality',
  'field_address_country' => 'field_address_country',
  'nid' => 'nid',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'field_event_date' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_event_date_1' => array(
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
    'separator' => ', ',
    'empty_column' => 0,
  ),
  'field_address_administrative_area' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => ', ',
    'empty_column' => 0,
  ),
  'field_address_country' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'nid' => array(
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
$handler->display->display_options['empty']['area']['label'] = 'No Results Text';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'No Results';
$handler->display->display_options['empty']['area']['format'] = 'plain_text';
/* Field: Content: Date */
$handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
$handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
$handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
$handler->display->display_options['fields']['field_event_date']['settings'] = array(
  'format_type' => 'custom',
  'custom_date_format' => 'F j, Y',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
);
/* Field: Content: Date */
$handler->display->display_options['fields']['field_event_date_1']['id'] = 'field_event_date_1';
$handler->display->display_options['fields']['field_event_date_1']['table'] = 'field_data_field_event_date';
$handler->display->display_options['fields']['field_event_date_1']['field'] = 'field_event_date';
$handler->display->display_options['fields']['field_event_date_1']['label'] = 'Time';
$handler->display->display_options['fields']['field_event_date_1']['settings'] = array(
  'format_type' => 'custom',
  'custom_date_format' => 'g:ia',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
);
/* Field: Field: Address - Locality (i.e. City) */
$handler->display->display_options['fields']['field_address_locality']['id'] = 'field_address_locality';
$handler->display->display_options['fields']['field_address_locality']['table'] = 'field_data_field_address';
$handler->display->display_options['fields']['field_address_locality']['field'] = 'field_address_locality';
$handler->display->display_options['fields']['field_address_locality']['label'] = '';
$handler->display->display_options['fields']['field_address_locality']['element_label_colon'] = FALSE;
/* Field: Field: Address - Administrative area (i.e. State / Province) */
$handler->display->display_options['fields']['field_address_administrative_area']['id'] = 'field_address_administrative_area';
$handler->display->display_options['fields']['field_address_administrative_area']['table'] = 'field_data_field_address';
$handler->display->display_options['fields']['field_address_administrative_area']['field'] = 'field_address_administrative_area';
$handler->display->display_options['fields']['field_address_administrative_area']['label'] = 'Location';
$handler->display->display_options['fields']['field_address_administrative_area']['alter']['text'] = '[field_address_locality], [field_address_administrative_area]';
$handler->display->display_options['fields']['field_address_administrative_area']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_address_administrative_area']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['field_address_administrative_area']['display_name'] = 1;
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['text'] = 'Register';
$handler->display->display_options['fields']['nid']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['path'] = 'ems/registration/add/[nid]';
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Sort criterion: Content: Date -  start date (field_event_date) */
$handler->display->display_options['sorts']['field_event_date_value']['id'] = 'field_event_date_value';
$handler->display->display_options['sorts']['field_event_date_value']['table'] = 'field_data_field_event_date';
$handler->display->display_options['sorts']['field_event_date_value']['field'] = 'field_event_date_value';
/* Contextual filter: Content: Language/Region (field_language_region) */
$handler->display->display_options['arguments']['field_language_region_value']['id'] = 'field_language_region_value';
$handler->display->display_options['arguments']['field_language_region_value']['table'] = 'field_data_field_language_region';
$handler->display->display_options['arguments']['field_language_region_value']['field'] = 'field_language_region_value';
$handler->display->display_options['arguments']['field_language_region_value']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['field_language_region_value']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_language_region_value']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_language_region_value']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['field_language_region_value']['limit'] = '0';
/* Contextual filter: Content: Parent Event (field_event_parent) */
$handler->display->display_options['arguments']['field_event_parent_target_id']['id'] = 'field_event_parent_target_id';
$handler->display->display_options['arguments']['field_event_parent_target_id']['table'] = 'field_data_field_event_parent';
$handler->display->display_options['arguments']['field_event_parent_target_id']['field'] = 'field_event_parent_target_id';
$handler->display->display_options['arguments']['field_event_parent_target_id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['field_event_parent_target_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_event_parent_target_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_event_parent_target_id']['summary_options']['items_per_page'] = '25';
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
  'event_occurrence' => 'event_occurrence',
);
/* Filter criterion: Content: Date -  start date (field_event_date) */
$handler->display->display_options['filters']['field_event_date_value']['id'] = 'field_event_date_value';
$handler->display->display_options['filters']['field_event_date_value']['table'] = 'field_data_field_event_date';
$handler->display->display_options['filters']['field_event_date_value']['field'] = 'field_event_date_value';
$handler->display->display_options['filters']['field_event_date_value']['operator'] = '>=';
$handler->display->display_options['filters']['field_event_date_value']['default_date'] = 'now';

/* Display: Event Occurrences Embed */
$handler = $view->new_display('embed', 'Event Occurrences Embed', 'event_occurrences_embed');

/* Display: Parent Event Reference */
$handler = $view->new_display('entityreference', 'Parent Event Reference', 'parent_event_reference');
$handler->display->display_options['defaults']['title'] = FALSE;
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
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['exclude'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['text'] = 'Register';
$handler->display->display_options['fields']['nid']['alter']['path'] = 'ems/registration/add/[nid]';
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['text'] = '[title] - ([nid])';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
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
  'event' => 'event',
);

/* Display: Event with Occurrence List */
$handler = $view->new_display('page', 'Event with Occurrence List', 'event_with_occurence_page');
$handler->display->display_options['defaults']['access'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['footer'] = FALSE;
/* Footer: Global: View area */
$handler->display->display_options['footer']['view']['id'] = 'view';
$handler->display->display_options['footer']['view']['table'] = 'views';
$handler->display->display_options['footer']['view']['field'] = 'view';
$handler->display->display_options['footer']['view']['view_to_insert'] = 'events:event_occurrence_block';
$handler->display->display_options['footer']['view']['inherit_arguments'] = TRUE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['element_type'] = 'h2';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Entity translation: Intro: translated */
$handler->display->display_options['fields']['field_intro_et']['id'] = 'field_intro_et';
$handler->display->display_options['fields']['field_intro_et']['table'] = 'field_data_field_intro';
$handler->display->display_options['fields']['field_intro_et']['field'] = 'field_intro_et';
$handler->display->display_options['fields']['field_intro_et']['label'] = '';
$handler->display->display_options['fields']['field_intro_et']['element_label_colon'] = FALSE;
$handler->display->display_options['defaults']['sorts'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Content: Nid */
$handler->display->display_options['arguments']['nid']['id'] = 'nid';
$handler->display->display_options['arguments']['nid']['table'] = 'node';
$handler->display->display_options['arguments']['nid']['field'] = 'nid';
$handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
$handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
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
  'event' => 'event',
);
$handler->display->display_options['path'] = 'ems/list';

/* Display: Event Occurrence Block */
$handler = $view->new_display('block', 'Event Occurrence Block', 'event_occurrence_block');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'nid' => 'nid',
  'title' => 'title',
  'field_event_date' => 'field_event_date',
  'field_event_date_1' => 'field_event_date_1',
  'field_address_name_line' => 'field_address_name_line',
  'field_address_locality' => 'field_address_administrative_area',
  'field_address_administrative_area' => 'field_address_administrative_area',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'nid' => array(
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
  'field_event_date' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_event_date_1' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_address_name_line' => array(
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
    'separator' => ', ',
    'empty_column' => 0,
  ),
  'field_address_administrative_area' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => ', ',
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
$handler->display->display_options['fields']['title']['label'] = 'Event';
/* Field: Content: Date */
$handler->display->display_options['fields']['field_event_date']['id'] = 'field_event_date';
$handler->display->display_options['fields']['field_event_date']['table'] = 'field_data_field_event_date';
$handler->display->display_options['fields']['field_event_date']['field'] = 'field_event_date';
$handler->display->display_options['fields']['field_event_date']['settings'] = array(
  'format_type' => 'custom',
  'custom_date_format' => 'F j, Y',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
);
/* Field: Content: Date */
$handler->display->display_options['fields']['field_event_date_1']['id'] = 'field_event_date_1';
$handler->display->display_options['fields']['field_event_date_1']['table'] = 'field_data_field_event_date';
$handler->display->display_options['fields']['field_event_date_1']['field'] = 'field_event_date';
$handler->display->display_options['fields']['field_event_date_1']['label'] = 'Time';
$handler->display->display_options['fields']['field_event_date_1']['settings'] = array(
  'format_type' => 'custom',
  'custom_date_format' => 'g:ia',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
);
/* Field: Field: Address - Full name */
$handler->display->display_options['fields']['field_address_name_line']['id'] = 'field_address_name_line';
$handler->display->display_options['fields']['field_address_name_line']['table'] = 'field_data_field_address';
$handler->display->display_options['fields']['field_address_name_line']['field'] = 'field_address_name_line';
$handler->display->display_options['fields']['field_address_name_line']['label'] = 'Venue';
/* Field: Field: Address - Locality (i.e. City) */
$handler->display->display_options['fields']['field_address_locality']['id'] = 'field_address_locality';
$handler->display->display_options['fields']['field_address_locality']['table'] = 'field_data_field_address';
$handler->display->display_options['fields']['field_address_locality']['field'] = 'field_address_locality';
$handler->display->display_options['fields']['field_address_locality']['label'] = '';
$handler->display->display_options['fields']['field_address_locality']['element_label_colon'] = FALSE;
/* Field: Field: Address - Administrative area (i.e. State / Province) */
$handler->display->display_options['fields']['field_address_administrative_area']['id'] = 'field_address_administrative_area';
$handler->display->display_options['fields']['field_address_administrative_area']['table'] = 'field_data_field_address';
$handler->display->display_options['fields']['field_address_administrative_area']['field'] = 'field_address_administrative_area';
$handler->display->display_options['fields']['field_address_administrative_area']['label'] = 'Location';
$handler->display->display_options['fields']['field_address_administrative_area']['alter']['text'] = '[field_address_locality], [field_address_administrative_area]';
$handler->display->display_options['fields']['field_address_administrative_area']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_address_administrative_area']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['field_address_administrative_area']['display_name'] = 1;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Content: Parent Event (field_event_parent) */
$handler->display->display_options['arguments']['field_event_parent_target_id']['id'] = 'field_event_parent_target_id';
$handler->display->display_options['arguments']['field_event_parent_target_id']['table'] = 'field_data_field_event_parent';
$handler->display->display_options['arguments']['field_event_parent_target_id']['field'] = 'field_event_parent_target_id';
$handler->display->display_options['arguments']['field_event_parent_target_id']['default_action'] = 'not found';
$handler->display->display_options['arguments']['field_event_parent_target_id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['field_event_parent_target_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['field_event_parent_target_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['field_event_parent_target_id']['summary_options']['items_per_page'] = '25';
