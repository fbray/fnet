<?php

/**
 * Creates the admin setting form.
 * 
 * @return mixed
 */
function box_connect_admin() {
  $form = array();

  $form['box_connect_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Client ID'),
    '#default_value' => variable_get('box_connect_client_id', 'ID'),
    '#size' => 40,
    '#maxlength' => 40,
    '#required' => TRUE,
  );

  $form['box_connect_client_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Client Secret'),
    '#default_value' => variable_get('box_connect_client_secret', 'SECRET'),
    '#size' => 40,
    '#maxlength' => 40,
    '#required' => TRUE,
  );

  $form['box_connect_parent_folder'] = array(
    '#type' => 'textfield',
    '#title' => t('Top Level Folder ID'),
    '#default_value' => variable_get('box_connect_parent_folder', '0'),
    '#size' => 40,
    '#maxlength' => 40,
    '#required' => TRUE,
  );

  $form['box_connect_thumbnail_directory'] = array(
    '#type' => 'textfield',
    '#title' => t('Thumbnail Base Directory, ie public://box'),
    '#default_value' => variable_get('box_connect_thumbnail_directory', 'public://extranet/box'),
    '#size' => 40,
    '#maxlength' => 40,
    '#required' => TRUE,
  );

  return system_settings_form($form);

}

/**
 * Validates the Admin form.
 *
 * @param $form
 * @param $form_state
 */
function box_connect_admin_validate($form, &$form_state) {
  // Trim the input fields of any whitespace. Box is really picky about that.
  foreach ($form_state['values'] as $key => $value) {
    $form_state['values'][$key] = trim($value);
  }
}

/**
 * Creates the Sync with Box form. It's really just a button.
 *
 * @param $form
 * @param $form_state
 * @return array
 */
function box_connect_directory_scan_form($form, &$form_state) {
  $form = array();
  $last_updated = variable_get('box_connect_last_synced', '');
  if (($last_updated == '') || ($last_updated == 0)) {
    $message = t('The site has never been synced with Box. Would you like to sync now?');
  }
  else {
    // Show the last time it was updated.
    $update_data = array(
      '@time' => format_date($last_updated, 'custom', 'g:ia T'),
      '@day'  => format_date($last_updated, 'custom', 'F jS, Y'),
    );
    $message = t('The site was last synced on @day at @time', $update_data);
  }
  $form['instructions'] = array(
    '#markup' => '<p>' . $message . '</p>',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Sync with Box'),
  );

  return $form;
}

/**
 * Submit handler for the Sync with Box form.
 *
 * @param $form
 * @param $form_state
 */
function box_connect_directory_scan_form_submit($form, &$form_state) {
  try {
    box_batch_sync();
  }
  catch(Exception $e) {
    drupal_set_message('The scan of Box failed for the following reason: ' . $e->getMessage() . '<br />Please try again later.');
  }
}

function box_connect_payload_test_form($form, &$form_state) {
  $form = array();
  $message = t('Enter a Box ID for a file to test.');
  $form['instructions'] = array(
    '#markup' => '<p>' . $message . '</p>',
  );
  $form['item_type'] = array(
    '#type' => 'select',
    '#title' => t('Item Type'),
    '#options' => array(
      'File',
      'Folder',
    )
  );
  $form['item_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Box Item ID'),
    '#size' => 40,
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Get Details'),
  );

  return $form;
}

function box_connect_payload_test_form_submit($form, &$form_state) {
  $box = get_box();
  $output = '';
  if ((isset($form_state['values']['item_id'])) && (isset($form_state['values']['item_type']))) {
    $file_id = $form_state['values']['item_id'];
    dpm($file_id);
    $type = $form_state['values']['item_type'];
    switch ($type) {
      case 0:
        $data = $box->get_file_details($file_id);
        break;
      case 1:
        $data = $box->get_folder_details($file_id);
        break;
      default:
        $data = $box->get_file_details($file_id);
        break;
    }

    if ($data) {
      if (module_exists('devel')) {
        dpm($data);

      }
      else {
        $output = print_r($data);
      }
    }
  }
  dpm($form_state);

  return $output;
}



