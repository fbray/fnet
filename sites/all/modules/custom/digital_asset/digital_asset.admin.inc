<?php
// $Id$

/**
 * @file
 * Admin forms for digital asset module
 *
 */

/**
 * Admin form
 */
function digital_asset_admin_form($form, &$form_state) {
  $form = array();
  $form['digital_asset_next_document_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Next Document ID to assign'),
    '#size' => 10,
    '#required' => FALSE,
    '#default_value' => variable_get('digital_asset_next_document_id', '7000000'),
    '#attributes' => array('autocomplete' => 'off'),
  );
  $form['digital_asset_show_hidden_fields'] = array(
    '#type' => 'checkbox',
    '#title' => 'Show hidden form fields',
    '#default_value' => variable_get('digital_asset_show_hidden_fields', FALSE),
  );
  $form['digital_asset_asset_types'] = array(
    '#type' => 'textarea',
    '#title' => t('Asset Types'),
    '#rows' => 10,
    '#cols' => 60,
    '#required' => FALSE,
    '#default_value' => variable_get('digital_asset_asset_types', ''),
  );
  $form['rebuild_owner_table'] = array(
    '#type' => 'button',
    '#value' => 'Rebuild owner table',
    '#validate' => array(),
    '#executes_submit_callback' => TRUE,
    '#submit' => array('digital_asset_admin_rebuild_owner_table'),
  );
  return system_settings_form($form);
}

/**
 * Submit function to rebuild owner table
 * @param $form
 * @param $form_state
 */
function digital_asset_admin_rebuild_owner_table($form, &$form_state) {
  $result = digital_asset_rebuild_owners_table();
  if ($result) {
    drupal_set_message('Owner table rebuilt.');
  }
  else {
    drupal_set_message('Owner table rebuild failed.', 'error');
  }
}

/**
 * Form for third party printer settings
 *
 * @param $form
 * @param $form_state
 * @return array
 */
function digital_asset_admin_ccs_form($form, &$form_state) {
  $form = array();
  $form['digital_asset_ccs_email_enable_cron'] = array(
    '#type' => 'select',
    '#title' => t('Enable Send CCS email via cron'),
    '#options' => drupal_map_assoc(array('No', 'Yes')),
    '#required' => TRUE,
    '#default_value' => variable_get('digital_asset_ccs_email_enable_cron', 'No'),
  );
  $form['digital_asset_ccs_email_to'] = array(
    '#type' => 'textfield',
    '#title' => t('Email To'),
    '#description' => 'Comma separated list of email addresses to receive print vendor extract',
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => variable_get('digital_asset_ccs_email_to', ''),
  );
  $form['digital_asset_ccs_email_cc'] = array(
    '#type' => 'textfield',
    '#title' => t('Email CC'),
    '#description' => 'Comma separated list of email to be copied on print vendor extract email',
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => variable_get('digital_asset_ccs_email_cc', ''),
  );
  $form['digital_asset_ccs_email_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Email Subject'),
    '#description' => 'Subject for print vendor extract email',
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => variable_get('digital_asset_ccs_email_subject', ''),
  );
  $form['digital_asset_ccs_spreadsheet_date'] = array(
    '#type' => 'textfield',
    '#title' => t('Start date for CCS spreadsheet'),
    '#description' => 'Date to start history for spreadsheet',
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => date('m/d/Y', strtotime('-1 week')),
  );
  $form['digital_asset_ccs_spreadsheet'] = array(
    '#type' => 'item',
    '#title' => 'CCS Spreadsheet',
    '#markup' => l('CCS Spreadsheet', file_create_url('public://ams/digital_assets.csv'))
  );
  $form['digital_asset_send_print_vendor_email'] = array(
    '#type' => 'button',
    '#value' => 'Send print vendor email',
    '#validate' => array(),
    '#executes_submit_callback' => TRUE,
    '#submit' => array('digital_asset_admin_print_vendor_mail_send_submit'),
  );
  $form['digital_asset_create_ccs_spreadsheet'] = array(
    '#type' => 'button',
    '#value' => 'Create print vendor spreadsheet',
    '#validate' => array(),
    '#executes_submit_callback' => TRUE,
    '#submit' => array('digital_asset_admin_create_ccs_spreadsheet_submit'),
  );
  $form['spacer'] = array(
    '#markup' => '<div>&nbsp;</div>',
  );
  $form['digital_asset_ccs_cost_centers'] = array(
    '#type' => 'textarea',
    '#title' => t('Cost Centers'),
    '#rows' => 10,
    '#cols' => 60,
    '#required' => FALSE,
    '#default_value' => variable_get('digital_asset_ccs_cost_centers', ''),
  );
  $form['digital_asset_ccs_unit_of_measure'] = array(
    '#type' => 'textarea',
    '#title' => t('Units of Measure'),
    '#rows' => 10,
    '#cols' => 20,
    '#required' => FALSE,
    '#default_value' => variable_get('digital_asset_ccs_unit_of_measure', implode("\r\n", array(
      'each',
      'packet'
    ))),
  );

  $form['#submit'][0] = 'digital_asset_admin_ccs_form_submit';
  return system_settings_form($form);
}

/**
 * submit function to send ccs email
 * @param $form
 * @param $form_state
 */
function digital_asset_admin_print_vendor_mail_send_submit($form, &$form_state) {
  if (digital_asset_send_print_vendor_mail()) {
    drupal_set_message('Email sent.');
  }
  else {
    drupal_set_message('Failed to send email.', 'error');
  }
}

/**
 * form submit function
 *
 * @param $form
 * @param $form_state
 * TODO: WTF?
 */
function digital_asset_admin_ccs_form_submit($form, &$form_state) {
  unset($form_state['values']['digital_asset_send_print_vendor_email']);
  unset($form_state['values']['digital_asset_create_ccs_spreadsheet']);
  unset($form_state['values']['digital_asset_ccs_spreadsheet']);
  unset($form_state['values']['digital_asset_ccs_spreadsheet_date']);
  return system_settings_form_submit($form, $form_state);
}

/**
 * CDN Settings form
 * @param $form
 * @param $form_state
 * @return array
 */
function digital_asset_admin_cdn_form($form, &$form_state) {
  $form = array();
  $form['digital_asset_cdn_enable_cron'] = array(
    '#type' => 'select',
    '#title' => t('Enable CDN background processing via cron'),
    '#options' => drupal_map_assoc(array('No', 'Yes')),
    '#required' => TRUE,
    '#default_value' => variable_get('digital_asset_cdn_enable_cron', 'No'),
  );
  $form['digital_asset_cdn_download_server'] = array(
    '#type' => 'textfield',
    '#title' => t('CDN download server'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => variable_get('digital_asset_cdn_download_server', 'http://download.flukenetworks.com/'),
  );
  $form['digital_asset_cdn_download_folder'] = array(
    '#type' => 'textfield',
    '#title' => t('CDN asset download folder'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => variable_get('digital_asset_cdn_download_folder', 'download/assets'),
  );
  $form['digital_asset_cdn_download_folder_pod'] = array(
    '#type' => 'textfield',
    '#title' => t('CDN asset POD download folder'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => variable_get('digital_asset_cdn_download_folder_pod', 'download/assets/pod'),
  );
  $form['digital_asset_cdn_upload_server'] = array(
    '#type' => 'textfield',
    '#title' => t('CDN upload server'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => variable_get('digital_asset_cdn_upload_server', ''),
  );
  $form['digital_asset_cdn_upload_folder'] = array(
    '#type' => 'textfield',
    '#title' => t('CDN asset upload folder'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => variable_get('digital_asset_cdn_upload_folder', ''),
  );
  $form['digital_asset_cdn_upload_folder_pod'] = array(
    '#type' => 'textfield',
    '#title' => t('CDN POD upload folder'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => variable_get('digital_asset_cdn_upload_folder_pod', ''),
  );
  $form['digital_asset_cdn_username'] = array(
    '#type' => 'textfield',
    '#title' => t('CDN user name'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => variable_get('digital_asset_cdn_username', ''),
  );
  $form['digital_asset_cdn_ftp_retries'] = array(
    '#type' => 'select',
    '#title' => t('CDN FTP retries'),
    '#options' => drupal_map_assoc(range(0, 10)),
    '#required' => TRUE,
    '#default_value' => variable_get('digital_asset_cdn_ftp_retries', 3),
  );
  $form['digital_asset_cdn_password'] = array(
    '#type' => 'password',
    '#title' => t('CDN password'),
    '#size' => 60,
    '#required' => FALSE,
  );
  $form['test_ftp_connection'] = array(
    '#type' => 'button',
    '#value' => 'Test FTP Connection',
    '#validate' => array(),
    '#executes_submit_callback' => TRUE,
    '#submit' => array('digital_asset_admin_cdn_ftp_test'),
  );
  $form['spacer'] = array(
    '#markup' => '<div>&nbsp;</div>',
  );
  if (isset($form_state['digital_asset']) && isset($form_state['digital_asset']['ftp_test_result'])) {
    $form['test_result'] = array(
      '#type' => 'item',
      '#title' => 'FTP Test Result',
      '#markup' => $form_state['digital_asset']['ftp_test_result'],
    );
  }
  $form = system_settings_form($form);
  $form['#submit'][0] = 'digital_asset_admin_cdn_form_submit';
  return $form;
}

/**
 * form submit function
 * @param $form
 * @param $form_state
 * TODO: WTF?
 */
function digital_asset_admin_cdn_form_submit($form, &$form_state) {
  unset($form_state['values']['test_ftp_connection']);
  unset($form_state['values']['process_pending_ftp']);
  if (empty($form_state['values']['digital_asset_cdn_password'])) {
    unset($form_state['values']['digital_asset_cdn_password']);
  }
  return system_settings_form_submit($form, $form_state);
}

/**
 * Test FTP settings
 * @param $form
 * @param $form_state
 */
function digital_asset_admin_cdn_ftp_test($form, &$form_state) {
  $output = '';
  $output .= "<pre>\n";
  // set up basic connection
  $ftp_server = $form_state['values']['digital_asset_cdn_upload_server'];
  $conn_id = ftp_connect($ftp_server);

  // login with username and password
  $ftp_user_name = $form_state['values']['digital_asset_cdn_username'];
  if (empty($form_state['values']['digital_asset_cdn_password'])) {
    $ftp_user_pass = variable_get('digital_asset_cdn_password', '');
  }
  else {
    $ftp_user_pass = $form_state['values']['digital_asset_cdn_password'];
  }
  $login_result = ftp_login($conn_id, $ftp_user_name, $ftp_user_pass);
  ftp_pasv($conn_id, TRUE);
  // check connection
  if ((!$conn_id) || (!$login_result)) {
    $output .= "FTP connection has failed!\n";
    $output .= "Attempted to connect to $ftp_server for user $ftp_user_name\n";
  }
  else {
    $output .= "Connected to $ftp_server, for user $ftp_user_name\n";
  }
  $output .= "Current directory: " . ftp_pwd($conn_id) . "\n";

  $ftp_folder = $form_state['values']['digital_asset_cdn_upload_folder'];
  // try to change the directory to somedir

  if (ftp_chdir($conn_id, $ftp_folder)) {
    $folder = ftp_pwd($conn_id);
    $output .= "Current directory is now: $folder\n";
  }
  else {
    $folder = '';
    $output .= "Couldn't change directory\n";
  }
  ftp_close($conn_id);
  if ($folder == $ftp_folder) {
    $output .= "FTP connection test passed.\n";
    drupal_set_message("FTP connection test passed.");
  }
  else {
    $output .= "FTP connection test failed.\n";
    drupal_set_message('FTP connection test failed.', 'error');
  }
  $output .= "</pre>\n";
  $form_state['digital_asset']['ftp_test_result'] = $output;
  $form_state['rebuild'] = TRUE;
}

/**
 * Force processing of FTP queue
 * @param $form
 * @param $form_state
 */
function digital_asset_admin_cdn_process_pending_ftp($form, &$form_state) {
  $files_uploaded = digital_asset_ftp_upload();
  $output = format_plural($files_uploaded, '1 file', '@count files') . ' processed.';
  drupal_set_message($output);
}

/**
 * Import ccs categories table
 *
 * @param $form
 * @param $form_state
 * @return array
 */
function digital_asset_admin_ccs_import_form($form, &$form_state) {
  $form = array(
    '#attributes' => array('enctype' => "multipart/form-data"),
  );
  $form['input_file'] = array(
    '#type' => 'file',
    '#required' => FALSE,
    '#title' => 'Input file',
    '#description' => 'Import a csv file to digital_asset_ccs_categories table.',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'submit',
  );
  return $form;
}

/**
 * form validate function
 *
 * @param $form
 * @param $form_state
 */
function digital_asset_admin_ccs_import_form_validate($form, &$form_state) {
  $source = "input_file";
  //if no file was uploaded, don't validate
  $destination = 'public://ams';
  if (file_prepare_directory($destination)) {
    $file = file_save_upload($source, array('file_validate_extensions' => array('csv')), $destination, FILE_EXISTS_REPLACE);
    // If the file passed validation:
    if (isset($file->filename)) {
      // Move the file, into the Drupal file system
      $form_state['digital_asset'][$source] = $file;

    }
    else {
      form_set_error("input_file", t('Invalid file name, only file with the extension csv are allowed.'));
    }
  }
}

/**
 * form submit function
 *
 * @param $form
 * @param $form_state
 */
function digital_asset_admin_ccs_import_form_submit($form, &$form_state) {
  $file = $form_state['digital_asset']['input_file'];
  if (is_object($file)) {
    $result = db_query('TRUNCATE TABLE digital_asset_ccs_categories');
    if (!$result) {
      drupal_set_message('Error truncating table digital_asset_ccs_categories', 'error');
      return;
    }
    $input = fopen($file->uri, 'r');
    if (!$input) {
      drupal_set_message('Error opening input file', 'error');
    }
    else {
      $field_names = fgetcsv($input);
      if (!is_array($field_names)) {
        drupal_set_message('Error processing input file.', 'error');
      }
      while ($data = fgetcsv($input)) {
        $row = array_combine($field_names, $data);
        $row = (object) $row;
        $result = drupal_write_record('digital_asset_ccs_categories', $row);
        if ($result !== SAVED_NEW) {
          drupal_set_message('Error writing database record.', 'error', FALSE);
        }
      }
      drupal_set_message('Import is complete.');
      $file->status &= ~FILE_STATUS_PERMANENT;
      $file = file_save($file);
      fclose($input);
    }
  }
}

/**
 * Export ccs categories table to CSV file
 *
 * @param $form
 * @param $form_state
 * @return array
 */
function digital_asset_admin_ccs_export_categories_form($form, &$form_state) {
  $form = array();
  $destination = 'public://ams';
  if (!is_dir($destination)) {
    file_prepare_directory($destination);
  }
  $output_file = $destination . '/ccs_categories.csv';
  $output_file_url = (file_exists($output_file)) ? l($output_file . ' ' . 'Click to download', file_create_url($output_file)) : '';
  $form['output_filename'] = array(
    '#type' => 'value',
    '#value' => $output_file,
  );
  $form['output_file'] = array(
    '#title' => 'Output file',
    '#type' => 'item',
    '#markup' => $output_file_url,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Export',
  );
  if (file_exists($output_file)) {
    $form['delete'] = array(
      '#type' => 'button',
      '#value' => 'Delete output file',
      '#validate' => array(),
      '#executes_submit_callback' => TRUE,
      '#submit' => array('digital_asset_admin_ccs_export_categories_delete_output_file'),
    );
  }
  return $form;
}

/**
 * form submit function
 *
 * @param $form
 * @param $form_state
 */
function digital_asset_admin_ccs_export_categories_form_submit($form, &$form_state) {
  $output_file = fopen($form_state['values']['output_filename'], 'w');
  fputcsv($output_file, array(
    'level_1_entity',
    'level_2_catalog',
    'level_3_group',
    'level_4_sub_group',
    'level_5_end_group',
  ));
  $sql = "SELECT * FROM {digital_asset_ccs_categories} ";
  $sql .= "ORDER BY level_1_entity, level_2_catalog, level_3_group, level_4_sub_group, level_5_end_group ASC";
  $result = db_query($sql);
  foreach ($result as $data) {
    $output = array();
    foreach (array(
               'level_1_entity',
               'level_2_catalog',
               'level_3_group',
               'level_4_sub_group',
               'level_5_end_group',
             ) as $field) {
      $output[$field] = $data->$field;
    }
    fputcsv($output_file, $output);
  }
  fclose($output_file);
}

/**
 * @param $form
 * @param $form_state
 * @return array
 */
function digital_asset_admin_cdn_ftp_form($form, $form_state) {
  $form = array();
  $form['queue_list'] = array(
    '#type' => 'markup',
    '#markup' => digital_asset_admin_cdn_processing_queue(),
  );
  $form['spacer'] = array(
    '#markup' => '<div>&nbsp;</div>',
  );
  $form['process_pending_ftp'] = array(
    '#type' => 'button',
    '#value' => 'Process pending FTP operations',
    '#validate' => array(),
    '#executes_submit_callback' => TRUE,
    '#submit' => array('digital_asset_admin_cdn_process_pending_ftp'),
  );
  $form['spacer1'] = array(
    '#markup' => '<div>&nbsp;</div>',
  );
  $form['purge_ftp_queue'] = array(
    '#type' => 'button',
    '#value' => 'Purge FTP queue',
    '#validate' => array(),
    '#executes_submit_callback' => TRUE,
    '#submit' => array('digital_asset_admin_cdn_purge_ftp_queue'),
  );
  $form['spacer2'] = array(
    '#markup' => '<div>&nbsp;</div>',
  );
  return $form;
}

/**
 * @param $form
 * @param $form_state
 */
function digital_asset_admin_ccs_export_categories_delete_output_file($form, &$form_state) {
  $output_file = $form_state['values']['output_filename'];
  if (file_exists($output_file)) {
    unlink($output_file);
    drupal_set_message(t('Output file !file deleted', array('!file' => $output_file)));
  }
}

/**
 * @return string
 */
function digital_asset_admin_cdn_processing_queue() {
  $rows = array();
  $query = db_select('digital_asset_ftp', 'f')
    ->fields('f', array(
      'local_file_path',
      'local_file_size',
      'remote_file_name',
      'ftp_operation',
      'operation_status',
      'retries'
    ))
    ->orderBy('updated', 'DESC');
  $query->addExpression('FROM_UNIXTIME(created)', 'created');
  $query->addExpression('FROM_UNIXTIME(updated)', 'updated');
  $result = $query->execute();
  foreach ($result as $data) {
    $row = (array) $data;
    $row['operation_status'] = $row['operation_status'] ? 'Complete' : 'Pending';
    $rows[] = $row;
  }
  $header = array(
    'Local File',
    'Local File Size',
    'Remote File',
    'Operation',
    'Status',
    'Retries',
    'Created',
    'Updated',
  );
  $output = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'caption' => 'FTP Queue',
  ));
  return $output;
}

/**
 * Submit function for button on digital_asset_admin_cdn_form
 */
function digital_asset_admin_cdn_purge_ftp_queue() {
  digital_asset_purge_ftp_queue();
  drupal_set_message('Done.');
}

function digital_asset_admin_create_ccs_spreadsheet_submit($form, &$form_state) {
  digital_asset_create_print_vendor_spreadsheet($form_state['values']['digital_asset_ccs_spreadsheet_date']);
  drupal_set_message('Spreadsheet created.');
}
