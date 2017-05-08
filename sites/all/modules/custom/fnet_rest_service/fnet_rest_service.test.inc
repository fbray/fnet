<?php
// $Id$

/**
 * @file
 * Test harness for fnet_rest_service.module
 *
 */

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function fnet_rest_service_test_form($form, &$form_state) {
  $form = array();
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#size' => 40,
    '#required' => FALSE,
    '#default_value' => $form_state['values']['email'],
  );
  $form['password'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#size' => 40,
    '#required' => FALSE,
    '#default_value' => $form_state['values']['password'],
  );
  $form['first_name'] = array(
    '#type' => 'textfield',
    '#title' => t('First Name'),
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => $form_state['storage']['first_name'],
  );
  $form['last_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Last Name'),
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => $form_state['storage']['last_name'],
  );
  $form['company_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Company'),
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => $form_state['storage']['company_name'],
  );
  $form['company_address1'] = array(
    '#type' => 'textfield',
    '#title' => t('Address'),
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => $form_state['storage']['company_address1'],
  );
  $form['city'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => $form_state['storage']['city'],
  );
  $form['state_code'] = array(
    '#type' => 'textfield',
    '#title' => t('State'),
    '#size' => 2,
    '#required' => FALSE,
    '#default_value' => $form_state['storage']['state_code'],
  );
  $form['postal_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Postal Code'),
    '#size' => 20,
    '#required' => FALSE,
    '#default_value' => $form_state['storage']['postal_code'],
  );
  $form['country_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Country'),
    '#size' => 2,
    '#required' => FALSE,
    '#default_value' => $form_state['storage']['country_code'],
  );
  $form['uid'] = array(
    '#type' => 'textfield',
    '#title' => t('uid'),
    '#size' => 10,
    '#required' => FALSE,
    '#default_value' => $form_state['storage']['uid'],
  );
  $form['aid'] = array(
    '#type' => 'textfield',
    '#title' => t('aid'),
    '#size' => 10,
    '#required' => FALSE,
    '#default_value' => $form_state['storage']['aid'],
  );
  $form['resource'] = array(
    '#type' => 'select',
    '#title' => t('Resource'),
    '#options' => drupal_map_assoc(array('users', 'login', 'addresses')),
    '#required' => TRUE,
    '#default_value' => $form_state['values']['resource'],
  );
  $form['method'] = array(
    '#type' => 'select',
    '#title' => t('Method'),
    '#options' => drupal_map_assoc(array('get', 'put', 'post')),
    '#required' => TRUE,
    '#default_value' => $form_state['values']['method'],
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );
  $form['spacer'] = array(
    '#type' => 'markup',
    '#markup' => '<div>&nbsp;</div>',
  );
  $form['result'] = array(
    '#type' => 'item',
    '#title' => t('Result'),
    '#markup' => $form_state['fnet_rest_service']['result'],
  );
  return $form;
}

/**
 * Validation for test form
 * @param $form
 * @param $form_state
 */
function fnet_rest_service_test_form_validate($form, &$form_state) {
  if (empty($form_state['values']['email'])) {
    $form_state['values']['email'] = 'steveogden.emstest@gmail.com';
  }
}

/**
 * Submit function for test form
 * @param $form
 * @param $form_state
 */
function fnet_rest_service_test_form_submit($form, &$form_state) {
  $resource = $form_state['values']['resource'];
  $method = $form_state['values']['method'];
  $values = $form_state['values'];
  $data = array();
  switch ($resource) {
    case 'users':
      switch ($method) {
        case 'get':
          $data = array(
            'email' => $form_state['values']['email'],
            'password' => $form_state['values']['password'],
          );
          break;
        case 'post':
          $user = new fnet_bedrock_user();
          foreach ($user as $key => $value) {
            $user->$key = $form_state['values'][$key];
          }
          $data['user'] = $user;
          break;
        case 'put':
          $user = new fnet_bedrock_user();
          foreach ($user as $key => $value) {
            $user->$key = $form_state['values'][$key];
          }
          if (empty($user->password)) {
            unset($user->password);
          }
          $data['user'] = $user;
          break;
      }
      break;
    case 'login':
      $email = $form_state['values']['email'];
      $password = $form_state['values']['password'];
      $data = array(
        'type' => 'basic',
        'value' => base64_encode($email . ':' . $password),
      );
      break;
    case 'addresses':
      $address = new stdClass();
      switch ($method) {
        case 'get':
          $data = array('uid' => $values['uid']);
          break;
        case 'put':
          $address->aid = $values['aid'];
        case 'post':
          $address->uid = $values['uid'];
          $address->address_type = 'billing';
          $address->contact_email = $values['email'];
          $address->contact_name = $values['first_name'] . ' ' . $values['last_name'];
          $address->company = $values['company_name'];
          $address->address1 = $values['company_address1'];
          $address->city = $values['city'];
          $address->province = $values['state_code'];
          $address->country = $values['country_code'];
          $address->postal_code = $values['postal_code'];
          $data['address'] = $address;
          break;
      }
  }
  $result = fnet_rest_service_client($resource, $method, $data);
  $form_state['fnet_rest_service'] = fnet_rest_service_test_process_result($resource, $method, $values, $result);
  $form_state['fnet_rest_service']['result'] = '<pre>' . print_r($result, TRUE) . '</pre>';
  $form_state['rebuild'] = TRUE;
}

/**
 * Simple rest client for testing rest server
 *
 * @param $resource
 * @param string $method
 * @param null $data
 * @return \stdClass
 */
function fnet_rest_service_client($resource, $method = 'get', $data = NULL) {
  $base_url = 'http://' . $_SERVER['HTTP_HOST'] . '/rest/';
  $curl_handle = curl_init();
  $username = variable_get('fnet_rest_service_key', '');
  $password = variable_get('fnet_rest_service_secret', '');
  $options = array(
    CURLOPT_RETURNTRANSFER => TRUE,
    CURLOPT_CUSTOMREQUEST => strtoupper($method),
    CURLOPT_HTTPAUTH => CURLAUTH_BASIC,
    CURLOPT_USERPWD => $username . ':' . $password,
    CURLOPT_FOLLOWLOCATION => TRUE,
    CURLOPT_MAXREDIRS => 3,
  );
  switch ($method) {
    case 'get':
      $url = $base_url . $resource . '?' . http_build_query($data);
      $options[CURLOPT_URL] = $url;
      break;
    case 'post':
    case 'put':
      $url = $base_url . $resource;
      $options[CURLOPT_URL] = $url;
      $options[CURLOPT_HTTPHEADER] = array('Content-type: application/json');
      $options[CURLOPT_POSTFIELDS] = json_encode($data);
      break;
  }
  curl_setopt_array($curl_handle, $options);
  $body = curl_exec($curl_handle);
  $code = curl_getinfo($curl_handle, CURLINFO_HTTP_CODE);
  curl_close($curl_handle);
  $result = new stdClass();
  $result->code = $code;
  if (substr($body, 0, 1) == '{') {
    $result->data = json_decode($body);
  }
  else {
    $result->data = $body;
  }
  return $result;
}

/**
 * Helper function for rest service testing
 *
 * @param $resource
 * @param $method
 * @param $values
 * @param $result
 * @return array
 */
function fnet_rest_service_test_process_result($resource, $method, $values, $result) {
  $storage = array();
  switch ($resource) {
    case 'users':
    case 'login':
      if ($result->code == 200 || $result->code == 201) {
        foreach ($result->data as $key => $value) {
          $storage[$key] = $value;
        }
      }
      else {
        foreach ($values as $key => $value) {
          $storage[$key] = $value;
        }
      }
      break;
    case 'addresses':
      $address = $result->data;
      if ($result->code == 200 || $result->code == 201) {
        $storage['email'] = $address->contact_email;
        list($first, $last) = explode(' ', $address->contact_name);
        $storage['first_name'] = $first;
        $storage['last_name'] = $last;
        $storage['company_name'] = $address->company;
        $storage['company_address1'] = $address->address1;
        $storage['city'] = $address->city;
        $storage['state_code'] = $address->province;
        $storage['postal_code'] = $address->postal_code;
        $storage['country_code'] = $address->country;
        $storage['aid'] = $address->aid;
        $storage['uid'] = $address->uid;
      }
      else {
        foreach ($values as $key => $value) {
          $storage[$key] = $value;
        }
      }
      break;
    case 'login':
      break;
  }
  return $storage;
}

