<?php

/**
 * @file
 * content.view.inc
 */

$view = new view();
$view->name = 'sales_insider';
$view->description = 'Various view pages of Sales Insider content.';
$view->tag = 'default';
$view->base_table = 'users';
$view->human_name = 'Sales Insider';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'News';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  3 => '3',
  5 => '5',
  4 => '4',
);
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'mini';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Relationship: User: Group membership */
$handler->display->display_options['relationships']['group_membership']['id'] = 'group_membership';
$handler->display->display_options['relationships']['group_membership']['table'] = 'users';
$handler->display->display_options['relationships']['group_membership']['field'] = 'group_membership';
/* Relationship: Group membership: Group gid */
$handler->display->display_options['relationships']['group']['id'] = 'group';
$handler->display->display_options['relationships']['group']['table'] = 'group_membership';
$handler->display->display_options['relationships']['group']['field'] = 'group';
$handler->display->display_options['relationships']['group']['relationship'] = 'group_membership';
/* Relationship: Group: Parent group */
$handler->display->display_options['relationships']['parent_group']['id'] = 'parent_group';
$handler->display->display_options['relationships']['parent_group']['table'] = 'groups';
$handler->display->display_options['relationships']['parent_group']['field'] = 'parent_group';
$handler->display->display_options['relationships']['parent_group']['relationship'] = 'group';
$handler->display->display_options['relationships']['parent_group']['label'] = 'Parent Group';
/* Relationship: Group: Content entities */
$handler->display->display_options['relationships']['group_entity_node']['id'] = 'group_entity_node';
$handler->display->display_options['relationships']['group_entity_node']['table'] = 'groups';
$handler->display->display_options['relationships']['group_entity_node']['field'] = 'group_entity_node';
$handler->display->display_options['relationships']['group_entity_node']['relationship'] = 'group';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'group_entity_node';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['relationship'] = 'group_entity_node';
$handler->display->display_options['fields']['created']['label'] = 'Posted';
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
$handler->display->display_options['fields']['created']['second_date_format'] = 'long';
/* Field: Entity translation: Body: translated */
$handler->display->display_options['fields']['body_et']['id'] = 'body_et';
$handler->display->display_options['fields']['body_et']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body_et']['field'] = 'body_et';
$handler->display->display_options['fields']['body_et']['relationship'] = 'group_entity_node';
$handler->display->display_options['fields']['body_et']['label'] = '';
$handler->display->display_options['fields']['body_et']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body_et']['type'] = 'smart_trim_format';
$handler->display->display_options['fields']['body_et']['settings'] = array(
  'trim_link' => '0',
  'trim_length' => '300',
  'trim_type' => 'chars',
  'trim_suffix' => '...',
  'more_link' => '0',
  'more_text' => 'Read more',
  'summary_handler' => 'full',
  'trim_options' => array(
    'text' => 'text',
  ),
  'trim_preserve_tags' => '<p><a><style>',
);
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created_1']['id'] = 'created_1';
$handler->display->display_options['sorts']['created_1']['table'] = 'node';
$handler->display->display_options['sorts']['created_1']['field'] = 'created';
$handler->display->display_options['sorts']['created_1']['relationship'] = 'group_entity_node';
$handler->display->display_options['sorts']['created_1']['order'] = 'DESC';
/* Contextual filter: User: Uid */
$handler->display->display_options['arguments']['uid']['id'] = 'uid';
$handler->display->display_options['arguments']['uid']['table'] = 'users';
$handler->display->display_options['arguments']['uid']['field'] = 'uid';
$handler->display->display_options['arguments']['uid']['default_action'] = 'default';
$handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
$handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['relationship'] = 'group_entity_node';
$handler->display->display_options['filters']['type']['value'] = array(
  'extranet_news' => 'extranet_news',
);
/* Filter criterion: Group membership: Membership status */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'group_membership';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['relationship'] = 'group_membership';
$handler->display->display_options['filters']['status']['value'] = array(
  'active' => 'active',
);
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status_1']['id'] = 'status_1';
$handler->display->display_options['filters']['status_1']['table'] = 'node';
$handler->display->display_options['filters']['status_1']['field'] = 'status';
$handler->display->display_options['filters']['status_1']['relationship'] = 'group_entity_node';
$handler->display->display_options['filters']['status_1']['value'] = '1';
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['relationship'] = 'group_entity_node';
$handler->display->display_options['filters']['language']['value'] = array(
  '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
);

/* Display: News Page */
$handler = $view->new_display('page', 'News Page', 'sales_insider_news_page');
$handler->display->display_options['display_description'] = 'List of Sales Insider news articles.';
$handler->display->display_options['path'] = 'extranet/news';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'News';
$handler->display->display_options['menu']['name'] = 'extranet';

/* Display: News Block */
$handler = $view->new_display('block', 'News Block', 'sales_insider_news_block');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'News';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '3';
$handler->display->display_options['block_description'] = 'Sales Insider News Block';

/* Display: Promotions Page */
$handler = $view->new_display('page', 'Promotions Page', 'sales_insider_promotions_page');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Promotions';
$handler->display->display_options['display_description'] = 'List of Sales Insider promotions.';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'group_entity_node';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['relationship'] = 'group_entity_node';
$handler->display->display_options['fields']['created']['label'] = 'Posted';
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
$handler->display->display_options['fields']['created']['second_date_format'] = 'long';
/* Field: Content: Promotion Date */
$handler->display->display_options['fields']['field_promotion_date']['id'] = 'field_promotion_date';
$handler->display->display_options['fields']['field_promotion_date']['table'] = 'field_data_field_promotion_date';
$handler->display->display_options['fields']['field_promotion_date']['field'] = 'field_promotion_date';
$handler->display->display_options['fields']['field_promotion_date']['relationship'] = 'group_entity_node';
$handler->display->display_options['fields']['field_promotion_date']['label'] = '';
$handler->display->display_options['fields']['field_promotion_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_promotion_date']['settings'] = array(
  'format_type' => 'custom',
  'custom_date_format' => 'F j, Y',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
);
/* Field: Entity translation: Body: translated */
$handler->display->display_options['fields']['body_et']['id'] = 'body_et';
$handler->display->display_options['fields']['body_et']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body_et']['field'] = 'body_et';
$handler->display->display_options['fields']['body_et']['relationship'] = 'group_entity_node';
$handler->display->display_options['fields']['body_et']['label'] = '';
$handler->display->display_options['fields']['body_et']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body_et']['type'] = 'smart_trim_format';
$handler->display->display_options['fields']['body_et']['settings'] = array(
  'trim_link' => '0',
  'trim_length' => '300',
  'trim_type' => 'chars',
  'trim_suffix' => '...',
  'more_link' => '0',
  'more_text' => 'Read more',
  'summary_handler' => 'full',
  'trim_options' => array(
    'text' => 'text',
  ),
  'trim_preserve_tags' => '<p><a><style>',
);
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['relationship'] = 'group_entity_node';
$handler->display->display_options['filters']['type']['value'] = array(
  'extranet_promotion' => 'extranet_promotion',
);
/* Filter criterion: Group membership: Membership status */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'group_membership';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['relationship'] = 'group_membership';
$handler->display->display_options['filters']['status']['value'] = array(
  'active' => 'active',
);
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status_1']['id'] = 'status_1';
$handler->display->display_options['filters']['status_1']['table'] = 'node';
$handler->display->display_options['filters']['status_1']['field'] = 'status';
$handler->display->display_options['filters']['status_1']['relationship'] = 'group_entity_node';
$handler->display->display_options['filters']['status_1']['value'] = '1';
$handler->display->display_options['path'] = 'extranet/promotions';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Promotions';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'extranet';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Promotions Block */
$handler = $view->new_display('block', 'Promotions Block', 'sales_insider_promotions_block');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Promotions';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '3';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'group_entity_node';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['relationship'] = 'group_entity_node';
$handler->display->display_options['fields']['created']['label'] = 'Posted';
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
$handler->display->display_options['fields']['created']['second_date_format'] = 'long';
/* Field: Content: Promotion Date */
$handler->display->display_options['fields']['field_promotion_date']['id'] = 'field_promotion_date';
$handler->display->display_options['fields']['field_promotion_date']['table'] = 'field_data_field_promotion_date';
$handler->display->display_options['fields']['field_promotion_date']['field'] = 'field_promotion_date';
$handler->display->display_options['fields']['field_promotion_date']['relationship'] = 'group_entity_node';
$handler->display->display_options['fields']['field_promotion_date']['label'] = '';
$handler->display->display_options['fields']['field_promotion_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_promotion_date']['settings'] = array(
  'format_type' => 'custom',
  'custom_date_format' => 'F j, Y',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
);
/* Field: Entity translation: Body: translated */
$handler->display->display_options['fields']['body_et']['id'] = 'body_et';
$handler->display->display_options['fields']['body_et']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body_et']['field'] = 'body_et';
$handler->display->display_options['fields']['body_et']['relationship'] = 'group_entity_node';
$handler->display->display_options['fields']['body_et']['label'] = '';
$handler->display->display_options['fields']['body_et']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body_et']['type'] = 'smart_trim_format';
$handler->display->display_options['fields']['body_et']['settings'] = array(
  'trim_link' => '0',
  'trim_length' => '300',
  'trim_type' => 'chars',
  'trim_suffix' => '...',
  'more_link' => '0',
  'more_text' => 'Read more',
  'summary_handler' => 'full',
  'trim_options' => array(
    'text' => 'text',
  ),
  'trim_preserve_tags' => '<p><a><style>',
);
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['relationship'] = 'group_entity_node';
$handler->display->display_options['filters']['type']['value'] = array(
  'extranet_promotion' => 'extranet_promotion',
);
/* Filter criterion: Group membership: Membership status */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'group_membership';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['relationship'] = 'group_membership';
$handler->display->display_options['filters']['status']['value'] = array(
  'active' => 'active',
);
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status_1']['id'] = 'status_1';
$handler->display->display_options['filters']['status_1']['table'] = 'node';
$handler->display->display_options['filters']['status_1']['field'] = 'status';
$handler->display->display_options['filters']['status_1']['relationship'] = 'group_entity_node';
$handler->display->display_options['filters']['status_1']['value'] = '1';
$handler->display->display_options['block_description'] = 'Sales Insider Promotions Block';

/* Display: Featured Block */
$handler = $view->new_display('block', 'Featured Block', 'sales_insider_featured_block');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Featured';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '5';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['relationship'] = 'group_entity_node';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['relationship'] = 'group_entity_node';
$handler->display->display_options['fields']['created']['label'] = 'Posted';
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'F j, Y';
$handler->display->display_options['fields']['created']['second_date_format'] = 'long';
/* Field: Content: Promotion Date */
$handler->display->display_options['fields']['field_promotion_date']['id'] = 'field_promotion_date';
$handler->display->display_options['fields']['field_promotion_date']['table'] = 'field_data_field_promotion_date';
$handler->display->display_options['fields']['field_promotion_date']['field'] = 'field_promotion_date';
$handler->display->display_options['fields']['field_promotion_date']['relationship'] = 'group_entity_node';
$handler->display->display_options['fields']['field_promotion_date']['label'] = '';
$handler->display->display_options['fields']['field_promotion_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_promotion_date']['settings'] = array(
  'format_type' => 'custom',
  'custom_date_format' => 'F j, Y',
  'fromto' => 'both',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
);
/* Field: Entity translation: Body: translated */
$handler->display->display_options['fields']['body_et']['id'] = 'body_et';
$handler->display->display_options['fields']['body_et']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body_et']['field'] = 'body_et';
$handler->display->display_options['fields']['body_et']['relationship'] = 'group_entity_node';
$handler->display->display_options['fields']['body_et']['label'] = '';
$handler->display->display_options['fields']['body_et']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body_et']['type'] = 'smart_trim_format';
$handler->display->display_options['fields']['body_et']['settings'] = array(
  'trim_link' => '0',
  'trim_length' => '300',
  'trim_type' => 'chars',
  'trim_suffix' => '...',
  'more_link' => '0',
  'more_text' => 'Read more',
  'summary_handler' => 'full',
  'trim_options' => array(
    'text' => 'text',
  ),
  'trim_preserve_tags' => '<p><a><style>',
);
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['relationship'] = 'group_entity_node';
$handler->display->display_options['filters']['type']['value'] = array(
  'extranet_news' => 'extranet_news',
  'extranet_promotion' => 'extranet_promotion',
);
/* Filter criterion: Group membership: Membership status */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'group_membership';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['relationship'] = 'group_membership';
$handler->display->display_options['filters']['status']['value'] = array(
  'active' => 'active',
);
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status_1']['id'] = 'status_1';
$handler->display->display_options['filters']['status_1']['table'] = 'node';
$handler->display->display_options['filters']['status_1']['field'] = 'status';
$handler->display->display_options['filters']['status_1']['relationship'] = 'group_entity_node';
$handler->display->display_options['filters']['status_1']['value'] = '1';
/* Filter criterion: Content: Promoted to front page */
$handler->display->display_options['filters']['promote']['id'] = 'promote';
$handler->display->display_options['filters']['promote']['table'] = 'node';
$handler->display->display_options['filters']['promote']['field'] = 'promote';
$handler->display->display_options['filters']['promote']['relationship'] = 'group_entity_node';
$handler->display->display_options['filters']['promote']['value'] = '1';
$handler->display->display_options['block_description'] = 'Sales Insider Featured Block';
