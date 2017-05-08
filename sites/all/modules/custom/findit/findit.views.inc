<?php
// $Id$
/**
 * @file
 * Describe the purpose of the file here.
 *
 */
/**
 * Implementation of hook_views_data
 * @return array
 */
function findit_views_data() {
  $data = array();
  $data['ocr_log']['table']['group'] = t('OCR Log');
  $data['ocr_log']['table']['base'] = array(
    'field' => 'oid',
    'title' => t('OCR Log'),
    'help' => t("ocr_log is a record of all recent calls to the OCR Ease service"),
    'weight' => -10,
  );
  $data['ocr_log']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
  );
  $data['ocr_log']['oid'] = array(
    'title' => t('OCR id'),
    'help' => t('Primary key for ocr_log table.'),
  );
  $data['ocr_log']['uid'] = array(
    'title' => t('User Id'),
    'help' => t('Link to user table'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
      'label' => t('User Id'),
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['ocr_log']['locale'] = array(
    'title' => t('Locale'),
    'help' => t('Digital asset locale'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
      'label' => t('Locale'),
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['ocr_log']['document_id'] = array(
    'title' => t('Document Id'),
    'help' => t('Digital asset document number'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
      'label' => t('Document Id'),
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['ocr_log']['date_created'] = array(
    'title' => t('Date created'),
    'help' => 'Date the log entry was created',
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
      'label' => t('Date created'),
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
  $data['ocr_log']['date_updated'] = array(
    'title' => t('Date updated'),
    'help' => 'Date the entry was last updated',
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
      'label' => t('Date updated'),
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
  $data['ocr_log']['entity_name'] = array(
    'title' => t('Entity name'),
    'help' => t('Name of entity checked in OCR'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
      'label' => t('Entity name'),
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['ocr_log']['entity_type'] = array(
    'title' => t('Entity type'),
    'help' => t('(I)dividual or (C)ompany'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter',
      'label' => t('Entity_type'),
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['ocr_log']['ocr_key'] = array(
    'title' => t('OCR key'),
    'help' => t('Key in OCR entity table'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['ocr_log']['ocr_status'] = array(
    'title' => t('OCR status'),
    'help' => t('Status returned by OCR or set by Export Compliance'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_in_operator',
      'label' => t('OCR status'),
      'options callback' => 'findit_ocr_status_options',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['ocr_log']['ocr_dpl_date'] = array(
    'title' => t('OCR DPL date'),
    'help' => t('OCR denied party list date'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
      'label' => t('OCR DPL date'),
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
  $data['ocr_log']['email_sent'] = array(
    'title' => t('Email sent'),
    'help' => t('Has status email been sent to user'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean',
      'label' => t('Email sent'),
      'type' => 'yes-no',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data['ocr_log']['uid'] = array(
    'title' => t('User Id'),
    'help' => t('Link to user table'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'label' => t('User Id'),
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'base' => 'users',
      'field' => 'uid',
      'handler' => 'views_handler_relationship',
      'label' => t('Users'),
    ),
  );
  $data['ocr_log']['ocr_check_count'] = array(
    'title' => t('Check count'),
    'help' => t('Number of times this entity has been checked with OCR'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
      'label' => t('Check count'),
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  $data['findit_log'] = array(
    'table' => array(
      'base' => array(
        'field' => 'did',
        'title' => 'Findit Log',
        'help' => 'Log of Findit downloads',
      ),
      'group' => 'Findit Log',
    ),
    'did' => array(
      'title' => 'Did',
      'help' => 'Download ID, unique ID of log entry',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
    ),
    'user_id' => array(
      'title' => 'User Id',
      'help' => 'User ID, the uid of user downloading the asset',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
        'label' => t('User Id'),
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'relationship' => array(
        'base' => 'users',
        'field' => 'user_id',
        'handler' => 'views_handler_relationship',
        'label' => t('Users'),
      ),
    ),
    'asset_id' => array(
      'title' => 'Asset Id',
      'help' => 'Asset ID, the nid of the asset that was downloaded',
      'field' => array(
        'handler' => 'views_handler_field_numeric',
        'click sortable' => FALSE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
        'label' => t('User Id'),
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
      'relationship' => array(
        'base' => 'node',
        'field' => 'asset_id',
        'handler' => 'views_handler_relationship',
        'label' => t('Asset node'),
      ),

    ),
    'date_downloaded' => array(
      'title' => 'Date Downloaded',
      'help' => 'Date that the download occurred.',
      'field' => array(
        'handler' => 'views_handler_field_date',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_date',
        'label' => t('Download date'),
      ),
      'sort' => array(
        'handler' => 'views_handler_sort_date',
      ),
    ),
  );

  return $data;
}

/**
 * Implements hook_views_default_views().
 */
function findit_views_default_views() {
  $views = array();

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
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_user_first_name']['id'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['table'] = 'field_data_field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['field'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['relationship'] = 'user_id';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_user_last_name']['id'] = 'field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['table'] = 'field_data_field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['field'] = 'field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['relationship'] = 'user_id';
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
  /* Field: Content: Storage file name */
  $handler->display->display_options['fields']['field_dam_storage_filename']['id'] = 'field_dam_storage_filename';
  $handler->display->display_options['fields']['field_dam_storage_filename']['table'] = 'field_data_field_dam_storage_filename';
  $handler->display->display_options['fields']['field_dam_storage_filename']['field'] = 'field_dam_storage_filename';
  $handler->display->display_options['fields']['field_dam_storage_filename']['relationship'] = 'asset_id';
  $handler->display->display_options['fields']['field_dam_storage_filename']['label'] = 'File name';
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
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_user_first_name']['id'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['table'] = 'field_data_field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['field'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['relationship'] = 'user_id';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_user_last_name']['id'] = 'field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['table'] = 'field_data_field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['field'] = 'field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['relationship'] = 'user_id';
  /* Field: User: Company */
  $handler->display->display_options['fields']['field_user_company']['id'] = 'field_user_company';
  $handler->display->display_options['fields']['field_user_company']['table'] = 'field_data_field_user_company';
  $handler->display->display_options['fields']['field_user_company']['field'] = 'field_user_company';
  $handler->display->display_options['fields']['field_user_company']['relationship'] = 'user_id';
  /* Field: User: Address line 1 */
  $handler->display->display_options['fields']['field_user_address_line_1']['id'] = 'field_user_address_line_1';
  $handler->display->display_options['fields']['field_user_address_line_1']['table'] = 'field_data_field_user_address_line_1';
  $handler->display->display_options['fields']['field_user_address_line_1']['field'] = 'field_user_address_line_1';
  $handler->display->display_options['fields']['field_user_address_line_1']['relationship'] = 'user_id';
  /* Field: User: Address line 2 */
  $handler->display->display_options['fields']['field_user_address_line_2']['id'] = 'field_user_address_line_2';
  $handler->display->display_options['fields']['field_user_address_line_2']['table'] = 'field_data_field_user_address_line_2';
  $handler->display->display_options['fields']['field_user_address_line_2']['field'] = 'field_user_address_line_2';
  $handler->display->display_options['fields']['field_user_address_line_2']['relationship'] = 'user_id';
  /* Field: User: City */
  $handler->display->display_options['fields']['field_user_city']['id'] = 'field_user_city';
  $handler->display->display_options['fields']['field_user_city']['table'] = 'field_data_field_user_city';
  $handler->display->display_options['fields']['field_user_city']['field'] = 'field_user_city';
  $handler->display->display_options['fields']['field_user_city']['relationship'] = 'user_id';
  /* Field: User: Province */
  $handler->display->display_options['fields']['field_user_province']['id'] = 'field_user_province';
  $handler->display->display_options['fields']['field_user_province']['table'] = 'field_data_field_user_province';
  $handler->display->display_options['fields']['field_user_province']['field'] = 'field_user_province';
  $handler->display->display_options['fields']['field_user_province']['relationship'] = 'user_id';
  /* Field: User: Country */
  $handler->display->display_options['fields']['field_user_country']['id'] = 'field_user_country';
  $handler->display->display_options['fields']['field_user_country']['table'] = 'field_data_field_user_country';
  $handler->display->display_options['fields']['field_user_country']['field'] = 'field_user_country';
  $handler->display->display_options['fields']['field_user_country']['relationship'] = 'user_id';
  /* Field: User: Zip/Postal code */
  $handler->display->display_options['fields']['field_user_postal_code']['id'] = 'field_user_postal_code';
  $handler->display->display_options['fields']['field_user_postal_code']['table'] = 'field_data_field_user_postal_code';
  $handler->display->display_options['fields']['field_user_postal_code']['field'] = 'field_user_postal_code';
  $handler->display->display_options['fields']['field_user_postal_code']['relationship'] = 'user_id';
  /* Field: User: Job Role */
  $handler->display->display_options['fields']['field_user_job_role']['id'] = 'field_user_job_role';
  $handler->display->display_options['fields']['field_user_job_role']['table'] = 'field_data_field_user_job_role';
  $handler->display->display_options['fields']['field_user_job_role']['field'] = 'field_user_job_role';
  $handler->display->display_options['fields']['field_user_job_role']['relationship'] = 'user_id';
  /* Field: User: Phone */
  $handler->display->display_options['fields']['field_user_phone']['id'] = 'field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['table'] = 'field_data_field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['field'] = 'field_user_phone';
  $handler->display->display_options['fields']['field_user_phone']['relationship'] = 'user_id';
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
  /* Field: Content: Storage file name */
  $handler->display->display_options['fields']['field_dam_storage_filename']['id'] = 'field_dam_storage_filename';
  $handler->display->display_options['fields']['field_dam_storage_filename']['table'] = 'field_data_field_dam_storage_filename';
  $handler->display->display_options['fields']['field_dam_storage_filename']['field'] = 'field_dam_storage_filename';
  $handler->display->display_options['fields']['field_dam_storage_filename']['relationship'] = 'asset_id';
  $handler->display->display_options['fields']['field_dam_storage_filename']['label'] = 'File name';
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

  $views[] = $view;

  return $views;
}

