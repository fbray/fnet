<?php

/**
 * @file
 * ocr_log.view.inc
 */

$view = new view();
$view->name = 'ocr_log';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'ocr_log';
$view->human_name = 'OCR Log';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'OCR Log';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  3 => '3',
  22 => '22',
);
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '3600';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '3600';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '50';
$handler->display->display_options['style_plugin'] = 'table';
/* Relationship: OCR Log: User Id */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'ocr_log';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
/* Field: OCR Log: User Id */
$handler->display->display_options['fields']['uid']['id'] = 'uid';
$handler->display->display_options['fields']['uid']['table'] = 'ocr_log';
$handler->display->display_options['fields']['uid']['field'] = 'uid';
/* Field: User: E-mail */
$handler->display->display_options['fields']['mail']['id'] = 'mail';
$handler->display->display_options['fields']['mail']['table'] = 'users';
$handler->display->display_options['fields']['mail']['field'] = 'mail';
$handler->display->display_options['fields']['mail']['relationship'] = 'uid';
$handler->display->display_options['fields']['mail']['link_to_user'] = 'user';
/* Field: OCR Log: Entity name */
$handler->display->display_options['fields']['entity_name']['id'] = 'entity_name';
$handler->display->display_options['fields']['entity_name']['table'] = 'ocr_log';
$handler->display->display_options['fields']['entity_name']['field'] = 'entity_name';
/* Field: OCR Log: Date created */
$handler->display->display_options['fields']['date_created']['id'] = 'date_created';
$handler->display->display_options['fields']['date_created']['table'] = 'ocr_log';
$handler->display->display_options['fields']['date_created']['field'] = 'date_created';
$handler->display->display_options['fields']['date_created']['date_format'] = 'long';
$handler->display->display_options['fields']['date_created']['second_date_format'] = 'long';
/* Field: OCR Log: OCR DPL date */
$handler->display->display_options['fields']['ocr_dpl_date']['id'] = 'ocr_dpl_date';
$handler->display->display_options['fields']['ocr_dpl_date']['table'] = 'ocr_log';
$handler->display->display_options['fields']['ocr_dpl_date']['field'] = 'ocr_dpl_date';
$handler->display->display_options['fields']['ocr_dpl_date']['date_format'] = 'long';
$handler->display->display_options['fields']['ocr_dpl_date']['second_date_format'] = 'long';
/* Field: OCR Log: Check count */
$handler->display->display_options['fields']['ocr_check_count']['id'] = 'ocr_check_count';
$handler->display->display_options['fields']['ocr_check_count']['table'] = 'ocr_log';
$handler->display->display_options['fields']['ocr_check_count']['field'] = 'ocr_check_count';
/* Field: OCR Log: OCR status */
$handler->display->display_options['fields']['ocr_status']['id'] = 'ocr_status';
$handler->display->display_options['fields']['ocr_status']['table'] = 'ocr_log';
$handler->display->display_options['fields']['ocr_status']['field'] = 'ocr_status';
/* Field: OCR Log: Email sent */
$handler->display->display_options['fields']['email_sent']['id'] = 'email_sent';
$handler->display->display_options['fields']['email_sent']['table'] = 'ocr_log';
$handler->display->display_options['fields']['email_sent']['field'] = 'email_sent';
$handler->display->display_options['fields']['email_sent']['not'] = 0;
/* Field: OCR Log: OCR key */
$handler->display->display_options['fields']['ocr_key']['id'] = 'ocr_key';
$handler->display->display_options['fields']['ocr_key']['table'] = 'ocr_log';
$handler->display->display_options['fields']['ocr_key']['field'] = 'ocr_key';
/* Filter criterion: OCR Log: OCR status */
$handler->display->display_options['filters']['ocr_status']['id'] = 'ocr_status';
$handler->display->display_options['filters']['ocr_status']['table'] = 'ocr_log';
$handler->display->display_options['filters']['ocr_status']['field'] = 'ocr_status';
$handler->display->display_options['filters']['ocr_status']['exposed'] = TRUE;
$handler->display->display_options['filters']['ocr_status']['expose']['operator_id'] = 'ocr_status_op';
$handler->display->display_options['filters']['ocr_status']['expose']['label'] = 'OCR status';
$handler->display->display_options['filters']['ocr_status']['expose']['operator'] = 'ocr_status_op';
$handler->display->display_options['filters']['ocr_status']['expose']['identifier'] = 'ocr_status';
$handler->display->display_options['filters']['ocr_status']['expose']['remember_roles'] = array(
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
/* Filter criterion: User: E-mail */
$handler->display->display_options['filters']['mail']['id'] = 'mail';
$handler->display->display_options['filters']['mail']['table'] = 'users';
$handler->display->display_options['filters']['mail']['field'] = 'mail';
$handler->display->display_options['filters']['mail']['relationship'] = 'uid';
$handler->display->display_options['filters']['mail']['exposed'] = TRUE;
$handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
$handler->display->display_options['filters']['mail']['expose']['label'] = 'E-mail';
$handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
$handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
$handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
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
$handler->display->display_options['path'] = 'admin/fnet/ocr-log';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'OCR Log';
$handler->display->display_options['menu']['name'] = 'management';
