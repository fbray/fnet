<?php
 // $Id:  $
/**
 * @file
 * Admin form and processing for idoco.
 *
 */
/**
 * Module configuration admin form.
 *
 */
function idoco_admin_configuration_form($form, &$form_state) {
  global $user;

  $form['idoco_flush_cache'] = array(
    '#markup' => l('Flush Idoco page cache', 'admin/fnet/idoco/flush_cache'),
  );
  $form['idoco_caching'] = array(
    '#type' => 'checkbox',
    '#title' => t('Caching enabled'),
    '#description' => t('Enabling caching allows the results of HTML pre-processing
      to be re-used. The cached content will be used until a manual cache flush
      is requested or new content is uploaded. This should only be disabled for
      testing purposes.'),
    '#default_value' => variable_get('idoco_caching', 1),
  );
  $form['idoco_redirect'] = array(
    '#type' => 'textfield',
    '#title' => t('Redirect URL'),
    '#description' => t('Url to redirect to if no version qualifier is used (with trailing /).'),
    '#size' => 60,
    '#default_value' => variable_get('idoco_redirect', 'idoco/vpm/v081/'),
  );

  $form = system_settings_form($form);

  return $form;
}

/**
 * Administer idoco_version table.  Displays list of records and a form to add or edit records
 *
 * @param null $vid - Version_id
 * @param null $op - delete, import or edit
 * @return null|string
 */
function idoco_admin_versions_page($vid = NULL, $op = NULL) {
  if ($op == 'delete') {
    $form = drupal_get_form('idoco_delete_confirmation_form', $vid);
    return drupal_render($form);
  }
  elseif ($op == 'import') {
    $form = drupal_get_form('idoco_import_confirmation_form', $vid);
    return drupal_render($form);
  }
  $rows = array();
  $count = 7;

/*  $sql = 'SELECT vid, product_name, product_identifier, version_name, ';
  $sql .= 'version_identifier, import_location, import_filename, last_update ';
  $sql .= 'FROM idoco_version ';
  $sql .= 'ORDER BY product_identifier ASC, version_identifier ASC';
  $query = pager_query($sql, $count);
*/
  $query = db_select('idoco_version', 'idv')->fields('idv', array(
    'vid',
    'product_name',
    'product_identifier',
    'version_name',
    'version_identifier',
    'import_location',
    'import_filename',
    'last_update',
    'idoco_version',
    'document_root',
    'home_page',
    ))
      ->extend('PagerDefault')
      ->limit($count)
      ->orderBy('product_identifier','ASC')
      ->orderBy('version_identifier','ASC');
  $result = $query->execute();
  // Process the query...
//  while ($record = db_fetch_object($query)) {
  foreach ($result as $record) {
    if (isset($_GET['page'])) {
      $options = array('query' => array('page' => $_GET['page']));
    }
    else {
      $options = array();
    }
    $edit_link = l('edit', 'admin/fnet/idoco/versions' . '/' . $record->vid . '/edit', $options);
    $delete_link = l('delete', 'admin/fnet/idoco/versions' . '/' . $record->vid . '/delete', $options);
    $import_link = l('import', 'admin/fnet/idoco/versions' . '/' . $record->vid . '/import', $options);
    $doc_link = l($record->document_root . '/' . $record->product_identifier . '/' . $record->version_identifier, $record->document_root . '/' . $record->product_identifier . '/' . $record->version_identifier . '/' . $record->home_page);
    $rows[] = array(
      $record->product_name,
      $record->version_name,
      $doc_link,
      $record->import_location,
      $record->import_filename,
      $record->idoco_version,
      $record->last_update,
      $edit_link,
      $delete_link,
      $import_link,
    );
  }
  $header = array(
    'Product Name',
    'Version Name',
    'Documentation Path',
    'Import Folder',
    'Import File Name',
    'Idoco Version',
    'Last Import',
    '',
    '',
    '',
  );
  $content =  theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('width' => '900')));
  // TODO Please change this theme call to use an associative array for the $variables parameter.
  $content .= theme('pager');
  $content .= '<br/>';
  $form = drupal_get_form('idoco_admin_versions_form', $vid, $op);
  $content .= drupal_render($form);
  return $content;
}

/**
 * Form for adding or editing version records
 *
 * @param $form
 * @param $version_id
 * @param $op
 * @return array
 */
function idoco_admin_versions_form($form, $form_state, $version_id, $op) {
  if ($op == 'edit') {
    $button = 'Save';
    $record = _idoco_get_version_record($version_id);
    if (!$record) {
      drupal_set_message('Record not found', 'warning');
      drupal_goto('admin/fnet/idoco/versions');
    }
  }
  else {
    $record = new stdClass();
    $record->product_name = '';
    $record->product_identifier = '';
    $record->version_name = '';
    $record->version_identifier = '';
    $record->import_location = '';
    $record->import_filename = '';
    $record->index_filename = '';
    $record->home_page = '';
    $record->idoco_version = '';
    $record->document_root = '';
    $button = 'Add';
  }
  $form = array();
  $form['vid'] = array(
    '#type' => 'value',
    '#value' => $version_id,
  );
  $form['product_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Product name'),
    '#attributes' => array('class' => array('idoco-form-field')),
    '#size' => 40,
    '#required' => TRUE,
    '#default_value' => $record->product_name,
    '#prefix' => '<div class="idoco-form-left">',
  );
  $form['product_identifier'] = array(
    '#type' => 'textfield',
    '#title' => t('Product path'),
    '#attributes' => array('class' => array('idoco-form-field')),
    '#size' => 40,
    '#required' => ($op == 'edit') ? false : true,
    '#default_value' => $record->product_identifier,
    '#disabled' => ($op == 'edit') ? true : false,
  );
  $form['version_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Version name'),
    '#attributes' => array('class' => array('idoco-form-field')),
    '#size' => 40,
    '#required' => TRUE,
    '#default_value' => $record->version_name,
  );
  $form['version_identifier'] = array(
    '#type' => 'textfield',
    '#title' => t('Version path'),
    '#attributes' => array('class' => array('idoco-form-field')),
    '#size' => 40,
    '#required' => ($op == 'edit') ? false : true,
    '#default_value' => $record->version_identifier,
    '#suffix' => '</div>',
    '#disabled' => ($op == 'edit') ? true : false,
  );
  $form['import_location'] = array(
    '#type' => 'textfield',
    '#title' => t('Import base path'),
    '#attributes' => array('class' => array('idoco-form-field')),
    '#size' => 40,
    '#required' => TRUE,
    '#default_value' => $record->import_location,
    '#prefix' => '<div class="idoco-form-right">',
  );
  $form['import_filename'] = array(
    '#type' => 'textfield',
    '#title' => t('Import file name'),
    '#attributes' => array('class' => array('idoco-form-field')),
    '#size' => 40,
    '#required' => TRUE,
    '#default_value' => $record->import_filename,
  );
  $form['index_filename'] = array(
    '#type' => 'textfield',
    '#title' => t('Index file name'),
    '#attributes' => array('class' => array('idoco-form-field')),
    '#size' => 40,
    '#required' => TRUE,
    '#default_value' => $record->index_filename,
  );
  $form['home_page'] = array(
    '#type' => 'textfield',
    '#title' => t('Home page'),
    '#attributes' => array('class' => array('idoco-form-field')),
    '#size' => 40,
    '#required' => TRUE,
    '#default_value' => $record->home_page,
    '#suffix' => '</div>',
  );
  $form['idoco_version'] = array(
    '#type' => 'textfield',
    '#title' => t('Idoco Version'),
    '#description' => t('1 for old style, 2 for new style help'),
    '#size' => 10,
    '#required' => TRUE,
    '#default_value' => $record->idoco_version,
    '#prefix' => '<div class="idoco-form-right">',
  );
  $form['document_root'] = array(
    '#type' => 'textfield',
    '#title' => t('Document root'),
    '#description' => t('Path relative to Drupal base_path()'),
    '#size' => 40,
    '#required' => TRUE,
    '#default_value' => $record->document_root,
    '#suffix' => '</div>',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => $button,
    '#prefix' => '<div class="idoco-form-action"><div class="idoco-form-button">',
    '#suffix' => '</div>',
  );
  $form['cancel'] = array(
    '#prefix' => '<div class="idoco-form-cancel-link">',
    '#value' => l(t('Cancel'), 'admin/fnet/idoco/versions'),
    '#suffix' => '</div></div>',
  );
  return $form;
}

/**
 * Form for confirming the deletion of a version record
 *
 * @param $form
 * @param $vid
 * @return mixed
 */
function idoco_delete_confirmation_form($form, $form_state, $vid) {
  $cancel_path = 'admin/fnet/idoco/versions';
  if (isset($_GET['page'])) {
    $query = array('page' => $_GET['page']);
  }
  $form = array();
  $form['vid'] = array(
    '#type' => 'value',
    '#value' => $vid,
  );
//  $sql = 'SELECT product_name, version_name FROM {idoco_version} WHERE vid = %d';
  $result = db_query('SELECT product_name, version_name FROM {idoco_version} WHERE vid = :vid ;', array(':vid' => $vid));
  if ($result) {
//    $record = db_fetch_object($result);
    $record = $result->fetchObject();
  }
  else {
    drupal_set_message('Record not found', 'warning');
    // TODO $query needs to be an array of keys and values instead of a string.
    drupal_goto($cancel_path, array('query' => $query));
  }
  $description = t('This will delete product/version record.
  It will not delete the files or directory structure. This action cannot be undone.');
  $confirm_form = confirm_form($form, t("Delete the %product %version record?", 
    array('%product' => $record->product_name, '%version' => $record->version_name)), $cancel_path, $description);
  return $confirm_form;
}

/**
 * Submit function for idoco_delete_confirmation_form
 *
 * @param $form
 * @param $form_state
 */
function idoco_delete_confirmation_form_submit($form, &$form_state) {
  if (isset($_GET['page'])) {
    $form_state['redirect'] = array(
      'admin/fnet/idoco/versions',
      array('page' => $_GET['page']),
    );
  }
  else {
    $form_state['redirect'] = 'admin/fnet/idoco/versions';
  }
  $vid = $form_state['values']['vid'];
//  $sql = 'DELETE FROM {idoco_version} WHERE vid = %d';
  // TODO Please review the conversion of this statement to the D7 database API syntax.
  /* db_query($sql, $vid) */
  $result = db_delete('idoco_version')
  ->condition('vid', $vid)
  ->execute();
  if ($result) {
    drupal_set_message('Version record deleted');
  }
  else {
    drupal_set_message('Version record NOT deleted', 'warning');
  }
}

/**
 * Validate function for idoco_admin_versions_form
 *
 * @param $form
 * @param $form_state
 */
function idoco_admin_versions_form_validate($form, &$form_state) {
  //check for duplicates product/version
  $product_identifier = $form_state['values']['product_identifier'];
  $version_identifier = $form_state['values']['version_identifier'];

//  $sql = "SELECT COUNT(*) FROM {idoco_version} WHERE `product_identifier` = '%s' AND `version_identifier` = '%s'";
  $result = db_query("SELECT COUNT(*) FROM {idoco_version} WHERE product_identifier = :product_identifier AND version_identifier = :version_identifier", array(':product_identifier' => $product_identifier, ':version_identifier' => $version_identifier));
  $count = $result->fetchField();
  if ((($form_state['values']['op'] == 'Add') && ($count != 0)) || 
    (($form_state['values']['op'] == 'Save') && ($count > 1))  ) {
    form_set_error('product_version', t('A record already exists for %product/%version', 
                                        array(
      '%product' => $product_identifier,
      '%version' => $version_identifier,
    )));
  }
  // make sure import folder is valid
  $files_dir = variable_get('file_directory_path', NULL);
  // Get rid of any leading slashes, path must be relative
  $form_state['values']['import_location'] = preg_replace('/^\/+/', '', $form_state['values']['import_location']);
  $dir = $files_dir . '/' . $form_state['values']['import_location'];

  if (is_dir($dir)) {
    if (!is_readable($dir)) {
      form_set_error('import_location', t('The specified directory is not readable: !dir', array('!dir' => $dir)));
    }
  }
  else {
    form_set_error('import_location', t('The specified directory does not exist: !dir', array('!dir' => $dir)));
  }

}

/**
 * Submit function for idoco_admin_versions_form
 *
 * @param $form
 * @param $form_state
 */
function idoco_admin_versions_form_submit($form, &$form_state) {
  if (isset($_GET['page'])) {
    $form_state['redirect'] = array(
      'admin/fnet/idoco/versions',
      array('page' => $_GET['page']),
    );
  }
  else {
    $form_state['redirect'] = 'admin/fnet/idoco/versions';
  }
  $record = new stdClass();
  $fields = array(
    'product_name',
    'product_identifier',
    'version_name',
    'version_identifier',
    'import_location',
    'import_filename',
    'index_filename',
    'home_page',
    'idoco_version',
    'document_root',
  );
  foreach ($fields as $field) {
    if (!empty($form_state['values'][$field])) {
      $record->$field = $form_state['values'][$field];
    }
  }
  if ($form_state['values']['op'] == 'Add') {
    $files_dir = variable_get('file_directory_path', NULL);
    $import_dir = $files_dir . '/' . $form_state['values']['import_location'];
    $import_dir .= '/' . $form_state['values']['product_identifier'];
    $import_dir .= '/' . $form_state['values']['version_identifier'];
    if (!is_dir($import_dir)) {
      $result = mkdir($import_dir, 0777, TRUE);
      if (!$result) {
        drupal_set_message("$import_dir could not be created.", 'warning');
      }
    }
    $result = drupal_write_record('idoco_version', $record);
  }
  else {
    $record->vid = $form_state['values']['vid'];
    $result = drupal_write_record('idoco_version', $record, 'vid');
  }
  if ($result == SAVED_NEW) {
    drupal_set_message('Version record added');
  }
  elseif ($result == SAVED_UPDATED) {
    drupal_set_message('Version record saved');
  }
  else {
    drupal_set_message('idoco_versions update failed', 'warning');
  }

}

/**
 * Form for confirming the import of idoco help files
 *
 * @param $form
 * @param $vid
 * @return mixed
 */
function idoco_import_confirmation_form($form, $form_state, $vid) {
  $cancel_path = 'admin/fnet/idoco/versions';
  if (isset($_GET['page'])) {
    $query = array('page' => $_GET['page']);
  }
  $form = array();
  $form['vid'] = array(
    '#type' => 'value',
    '#value' => $vid,
  );
  $sql = 'SELECT product_name, version_name, import_location, import_filename, product_identifier, version_identifier ';
  $sql .= 'FROM {idoco_version} WHERE vid = :vid ';
  $result = db_query($sql, array(':vid'=>$vid));
  if ($result) {
//    $record = db_fetch_object($result);
    $record = $result->fetchObject();
  }
  else {
    drupal_set_message('Record not found', 'warning');
    // TODO $query needs to be an array of keys and values instead of a string.
    drupal_goto($cancel_path, array('query' => $query));
  }
  $description = t('This action cannot be undone.');
  $message = t("Update the %product %version from %import_location/%product_id/%version_id/%import_filename", array(
    '%product' => $record->product_name,
    '%version' => $record->version_name,
    '%import_location' => $record->import_location,
    '%import_filename' => $record->import_filename,
    '%product_id' => $record->product_identifier,
    '%version_id' => $record->version_identifier,
  ));
  $confirm_form = confirm_form($form, $message, $cancel_path, $description);
  return $confirm_form;
}

/**
 * Submit function for idoco_import_confirmation_form
 *
 * @param $form
 * @param $form_state
 */
function idoco_import_confirmation_form_submit($form, &$form_state) {
  if (isset($_GET['page'])) {
    $form_state['redirect'] = array(
      'admin/fnet/idoco/versions',
      array('page' => $_GET['page']),
    );
  }
  else {
    $form_state['redirect'] = 'admin/fnet/idoco/versions';
  }
  $vid = $form_state['values']['vid'];
  $result = _idoco_updater($vid);
  if ($result) {
    drupal_set_message('Version files updated');
  }
  else {
    drupal_set_message('Version files NOT updated', 'warning');
  }
}
