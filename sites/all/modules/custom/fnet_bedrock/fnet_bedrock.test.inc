<?php
// $Id$

/**
 * @file
 * functions used for testing the bedrock interface during development
 *
 */

/**
 * Test form
 * @param $form
 * @param $form_state
 * @return array
 */
function fnet_bedrock_test($form, &$form_state) {
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
    '#title' => t('Method'),
    '#options' => drupal_map_assoc(array(
      'CREATE',
      'READ',
      'UPDATE',
      'DELETE',
      'AUTHENTICATE',
      'OTHER'
    )),
    '#default_value' => isset($form_state['values']['method']) ? $form_state['values']['method'] : array(),
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  $form['spacer'] = array(
    '#type' => 'markup',
    '#markup' => '<div>&nbsp;</div>',
  );
  $form['result'] = array(
    '#type' => 'item',
    '#title' => 'Result',
    '#markup' => isset($form_state['fnet_bedrock']['result']) ? '<pre>' . $form_state['fnet_bedrock']['result'] . '</pre>' : '',
  );
  return $form;
}

/**
 * @param $form
 * @param $form_state
 */
function fnet_bedrock_test_submit($form, &$form_state) {
  $result = NULL;
  switch ($form_state['values']['method']) {
    case 'READ':
      $result = fnet_bedrock_get_user($form_state['values']['email']);
      break;
    case 'CREATE':
      $bedrock_user = fnet_bedrock_make_bedrock_user($form_state['values']['email'], $form_state['values']['password']);
      $result = fnet_bedrock_insert_user($bedrock_user);
      break;
    case 'UPDATE':
      $result = fnet_bedrock_get_user($form_state['values']['email']);
      $bedrock_user = new stdClass();
      $bedrock_user->id = $result->id;
      $bedrock_user->password = $form_state['values']['password'];
      $result = fnet_bedrock_update_user($bedrock_user);
      break;
    case 'DELETE':
      $result = fnet_bedrock_get_user($form_state['values']['email']);
      $bedrock_user = new stdClass();
      $bedrock_user->id = $result->id;
      $result = fnet_bedrock_delete_user($bedrock_user);
      break;
    case 'AUTHENTICATE':
      //$result = fnet_bedrock_user_authenticate($form_state['values']['email'], $form_state['values']['password']);
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
    case 'OTHER':
      //node_delete($nid);
      $result = array_shift(user_load_multiple(array(), array('mail' => $form_state['values']['email'])));
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
