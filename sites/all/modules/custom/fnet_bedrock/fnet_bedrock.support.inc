<?php
// $Id: fnet_bedrock.support.inc 578 2015-08-10 16:07:59Z sogden1 $

/**
 * @file
 * functions used to support Bedrock authentication
 *
 */

/**
 * Drupal for for fnet_bedrock troubleshooting
 * @param $form
 * @param $form_state
 * @return array
 */
function fnet_bedrock_support($form, &$form_state) {
  $form = array();
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => isset($form_state['values']['email']) ? $form_state['values']['email'] : '',
  );
  $form['password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['password']) ? $form_state['values']['password'] : '',
  );
  $form['method'] = array(
    '#type' => 'select',
    '#title' => t('Operation'),
    '#options' => drupal_map_assoc(array(
      'Get Bedrock User',
      'Get FNET User',
      'Change Password',
      'Authenticate',
      'Enable locked bedrock account',
      'Create Bedrock User from FNET user',
    )),
    '#default_value' => isset($form_state['values']['method']) ? $form_state['values']['method'] : '',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  $result = isset($form_state['fnet_bedrock']['result']) ? $form_state['fnet_bedrock']['result'] : '';
  $form['result'] = array(
    '#type' => 'item',
    '#title' => 'Result',
    '#markup' => '<pre>' . $result . '</pre>',
  );
  return $form;
}

/**
 * Implementation of hook_submit
 * @param $form
 * @param $form_state
 */
function fnet_bedrock_support_submit($form, &$form_state) {
  $result = NULL;
  switch ($form_state['values']['method']) {
    case 'Get Bedrock User':
      $result = fnet_bedrock_get_user($form_state['values']['email']);
      break;
    case 'Enable locked bedrock account':
      $result = fnet_bedrock_get_user($form_state['values']['email']);
      $bedrock_user = new stdClass();
      $bedrock_user->id = $result->id;
      $bedrock_user->status = 'enabled';
      $result = fnet_bedrock_update_user($bedrock_user);
      break;
    case 'Change Password':
      $result = fnet_bedrock_get_user($form_state['values']['email']);
      $bedrock_user = new stdClass();
      $bedrock_user->id = $result->id;
      $bedrock_user->password = $form_state['values']['password'];
      $bedrock_user->status = 'enabled';
      $result = fnet_bedrock_update_user($bedrock_user);
      break;
    case 'Authenticate':
      $email = $form_state['values']['email'];
      $password = $form_state['values']['password'];
      $credentials = new stdClass();
      $credentials->type = 'basic';
      $credentials->value = base64_encode("$email:$password");
      $data = json_encode($credentials);
      $rest_method = 'login';
      $result = fnet_bedrock_rest('POST', $rest_method, $data);
      if ($result->data) {
        $result->data = json_decode($result->data);
      }
      break;
    case 'Get FNET User':
      $result = array_shift(user_load_multiple(array(), array('mail' => $form_state['values']['email'])));
      break;
    case 'Create Bedrock User from FNET user':
      $result = fnet_bedrock_support_create_bedrock_user($form_state['values']['email'], $form_state['values']['password']);
      break;
    case 'Recreate FNET User from Bedrock user':
      $result = fnet_bedrock_support_recreate_fnet_user($form_state['values']['email'], $form_state['values']['password']);
      break;
  }

  switch (gettype($result)) {
    case 'string':
      $form_state['fnet_bedrock']['result'] = _format_json($result);
      break;
    case 'boolean':
      $form_state['fnet_bedrock']['result'] = ($result) ? 'true' : 'false';
      break;
    default:
      $form_state['fnet_bedrock']['result'] = print_r($result, TRUE);
      break;
  }
  $form_state['rebuild'] = TRUE;
}

function fnet_bedrock_support_validate($form, &$form_state) {
  $form_state['fnet_bedrock']['result'] = NULL;
  switch ($form_state['values']['method']) {
    case 'Get Bedrock User':
      break;
    case 'Change Password':
    case 'Authenticate':
    case 'Create Bedrock User from FNET user':
      if (empty($form_state['values']['email'])) {
        form_set_error('email', 'Email required');
      }
      if (empty($form_state['values']['password'])) {
        form_set_error('email', 'Password required');
      }
      break;
    case 'Get FNET User':
    case 'Recreate FNET User from Bedrock user':
      if (empty($form_state['values']['email'])) {
        form_set_error('email', 'Email required');
      }
      break;
  }
}

function fnet_bedrock_support_create_bedrock_user($email, $password) {
  $bedrock_user = fnet_bedrock_make_bedrock_user($email, $password);
  $result = fnet_bedrock_insert_user($bedrock_user);
  return $result;
}

function fnet_bedrock_support_recreate_fnet_user($email) {
  $account = array_shift(user_load_multiple(array(), array('mail' => $email)));
  if ($account) {
    user_delete($account->uid);
  }
  $bedrock_user = fnet_bedrock_get_user($email);
  $account = fnet_bedrock_create_drupal_user($bedrock_user);
  fnet_bedrock_create_user_profile($account->uid, $bedrock_user);
  $account = user_load($account->uid);
  drupal_set_message('FNET user account record created');
  return $account;
}
