<?php

/**
 * @file
 * Describe the purpose of the file here.
 */

/**
 * Implements hook_views_data().
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
