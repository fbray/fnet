<?php
/**
 * @file
 * Admin forms for am_license
 *
 */

/**
 * This will let user to import AirMagnet legacy license configuration data file in CSV format
 */
function am_license_admin_import_form($form, &$form_state) {
  $form = array(
    '#attributes' => array('enctype' => "multipart/form-data"),
  );

  $form['input_file'] = array(
    '#type' => 'file',
    '#required' => FALSE,
    '#title' => 'Input file',
    '#description' => 'Import a csv file.',
  );

  $options = array(
    'am_lic_config' => 'am_lic_config',
    'am_lic_family_release' => 'am_lic_family_release',
    'am_lic_minor_release' => 'am_lic_minor_release',
    'am_lic_file_config' => 'am_lic_file_config',
  );

  $form['db_table_name'] = array(
    '#title' => t('DB Table Name'),
    '#type' => 'select',
    '#options' => $options,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'submit',
  );
  return $form;
}

/**
 * AirMagnet legacy configuration data file import: check for valid file type
 */
function am_license_admin_import_form_validate($form, &$form_state) {
  $source = "input_file";

  $file = file_save_upload($source, array(
    'file_validate_extensions' => array('csv'), // Validate extensions.
    FILE_EXISTS_REPLACE
  ));

  if ($file) {
    // Save file name for submit handler.
    $form_state['storage']['input_file'] = $file;
  } else {
    form_set_error("input_file", t('Invalid file name, only file with the extension csv are allowed.'));
  }
}

/**
 * AirMagnet legacy configuration data file import: process truncate database table and re-submit data per configuration set
 */
function am_license_admin_import_form_submit($form, &$form_state) {
  $file = $form_state['storage']['input_file'];
  $filepath = $file->uri;
  $dbTableName = $form_state['values']['db_table_name'];

  if (isset($filepath) && isset($dbTableName)) {
    db_truncate($dbTableName)->execute();
    $input = fopen($filepath, 'r');
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
        $result = drupal_write_record($dbTableName, $row);
        if ($result !== SAVED_NEW) {
          drupal_set_message('Error writing database record onto ' . $dbTableName, 'error', FALSE);
        }
      }
      drupal_set_message('Import is complete onto Database Table ' . $dbTableName);
    }
    fclose($input);
  }
  // clean up uploaded file
  am_license_admin_import_file_delete($file);
}

/**
 * Clean up uploaded file from temporary directory and also database records
 */
function am_license_admin_import_file_delete(stdClass $file, $force = FALSE) {
  if (!file_valid_uri($file->uri)) {
    if (($realpath = drupal_realpath($file->uri)) !== FALSE) {
      watchdog('file', 'File %file (%realpath) could not be deleted because it is not a valid URI. This may be caused by improper use of file_delete() or a missing stream wrapper.', array('%file' => $file->uri, '%realpath' => $realpath));
    }
    else {
      watchdog('file', 'File %file could not be deleted because it is not a valid URI. This may be caused by improper use of file_delete() or a missing stream wrapper.', array('%file' => $file->uri));
    }
    drupal_set_message(t('The specified file %file could not be deleted, because it is not a valid URI. More information is available in the system log.', array('%file' => $file->uri)), 'error');
    return FALSE;
  }

  // If any module still has a usage entry in the file_usage table, the file
  // will not be deleted, but file_delete() will return a populated array
  // that tests as TRUE.
  if (!$force && ($references = file_usage_list($file))) {
    return $references;
  }

  // Let other modules clean up any references to the deleted file.
  module_invoke_all('file_delete', $file);
  module_invoke_all('entity_delete', $file, 'file');

  // Make sure the file is deleted before removing its row from the
  // database, so UIs can still find the file in the database.
  if (file_unmanaged_delete($file->uri)) {
    db_delete('file_managed')->condition('fid', $file->fid)->execute();
    db_delete('file_usage')->condition('fid', $file->fid)->execute();
    entity_get_controller('file')->resetCache();
    return TRUE;
  }
  return FALSE;
}
