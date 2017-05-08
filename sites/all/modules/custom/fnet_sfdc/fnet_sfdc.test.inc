<?php
// $Id$

/**
 * @file
 * Test functions for fnet_sfdc module.
 *
 */
function fnet_sfdc_test($form, &$form_state) {
  $form = array();
  $methods = drupal_map_assoc(array(
    'getAssets',
    'getCase',
    'getCases',
    'getContact',
    'getWebProducts',
    'insertCase',
    'insertCaseComment',
    'insertContact',
    'updateContact',
    'validateGold',
  ));

  $form['method'] = array(
    '#type' => 'select',
    '#title' => 'method',
    '#options' => $methods,
    '#default_value' => isset($form_state['values']['method']) ? $form_state['values']['method'] : '',
    '#description' => 'Method to test',
  );

  $form['for_contact']['#value'] = '<h2>For getContact and insertContact</h2>';
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['email']) ? $form_state['values']['email'] : '',
  );

  $form['for_case']['#value'] = '<h2>For insertCase</h2>';

  $form['asset_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Asset Id'),
    '#size' => 30,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['asset_id']) ? $form_state['values']['asset_id'] : '',
  );

  $form['subject'] = array(
    '#type' => 'textfield',
    '#title' => t('subject'),
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['subject']) ? $form_state['values']['subject'] : '',
  );

  $form['description'] = array(
    '#type' => 'textfield',
    '#title' => t('Description'),
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['description']) ? $form_state['values']['description'] : '',
  );

  $form['for_get_case']['#value'] = '<h2>For getCase and insertCaseComment</h2>';

  $form['case_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Case Number'),
    '#size' => 30,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['case_number']) ? $form_state['values']['case_number'] : '',
  );

  $form['for_case_comment']['#value'] = '<h2>For insertCaseComment</h2>';

  $form['comment'] = array(
    '#type' => 'textfield',
    '#title' => t('Comment'),
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['comment']) ? $form_state['values']['comment'] : '',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  if (isset($form_state['fnet_sfdc']['result'])) {
    $form['result'] = array(
      '#title' => 'Result',
      '#markup' => '<pre>' . $form_state['fnet_sfdc']['result'] . '</pre>',
    );
  }
  return $form;
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function fnet_sfdc_test_submit($form, &$form_state) {
  if ($form_state['values']['email'] != '') {
    $email = $form_state['values']['email'];
    $uid = db_query("SELECT uid FROM {users} WHERE mail = :mail LIMIT 1", array(':mail' => $email))->fetchField();
    $account = user_load($uid);
    $contact = fnet_sfdc_create_contact_from_profile($email, $account);
  }
  else {
    $contact = new sfdc_Contact();
    $contact->FirstName = 'John';
    $contact->LastName = 'Smith';
    $contact->Email = 'John.Smith@example.com';
    $contact->Phone = '650-453-8529';
    $contact->IndividualId__c = '89562312';
    $contact->Company__c = 'Fluke Networks';
  }

  $case = new sfdc_SupportCase();
  $case->ContactId = $form_state['values']['email'];
  $case->AssetId = $form_state['values']['asset_id'];
  $case->Subject = $form_state['values']['subject'];
  $case->Description = $form_state['values']['description'];

  $case_number = $form_state['values']['case_number'];
  $comment = new sfdc_CaseComment();
  $comment->CommentBody = $form_state['values']['comment'];

  $result = '';
  switch ($form_state['values']['method']) {
    case 'getAssets':
      $result .= print_r(fnet_sfdc_get_assets($form_state['values']['email'], 30), TRUE) . "\n";
      break;
    case 'getCase':
      $result .= print_r(fnet_sfdc_get_case($form_state['values']['case_number']), TRUE) . "\n";
      break;
    case 'getCases':
      $result .= print_r(fnet_sfdc_get_cases($form_state['values']['email'], 120), TRUE) . "\n";
      break;
    case 'getContact':
      $result .= print_r(fnet_sfdc_get_contact($form_state['values']['email']), TRUE) . "\n";
      break;
    case 'getWebProducts':
      $result .= print_r(fnet_sfdc_get_web_products(), TRUE) . "\n";
      break;
    case 'insertCase':
      $result .= print_r(fnet_sfdc_insert_case($case), TRUE) . "\n";
      break;
    case 'insertCaseComment':
      $result .= print_r(fnet_sfdc_insert_case_comment($case_number, $comment), TRUE) . "\n";
      break;
    case 'insertContact':
      $result .= print_r($contact, TRUE);
      $result .= print_r(fnet_sfdc_insert_contact($contact), TRUE) . "\n";
      break;
    case 'updateContact':
      $result .= print_r(fnet_sfdc_update_contact($contact), TRUE) . "\n";
      break;
    case 'validateGold':
      $result .= "fnet_sfdc_validate_gold('5309-0002', '3320') " . ((fnet_sfdc_validate_gold('5309-0002', '3320')) ? 'true' : 'false') . " \n";
      $result .= "fnet_sfdc_validate_gold('5401-0001', '6440') " . ((fnet_sfdc_validate_gold('5401-0001', '6440')) ? 'true' : 'false') . " \n";
      $result .= "fnet_sfdc_validate_gold('5307-0001', '6130') " . ((fnet_sfdc_validate_gold('5307-0001', '6130')) ? 'true' : 'false') . " \n";
      $result .= "fnet_sfdc_validate_gold('53090002', '3320') " . ((fnet_sfdc_validate_gold('53090002', '3320')) ? 'true' : 'false') . " \n";
      $result .= "fnet_sfdc_validate_gold('54010001', '6440') " . ((fnet_sfdc_validate_gold('54010001', '6440')) ? 'true' : 'false') . " \n";
      $result .= "fnet_sfdc_validate_gold('53070001', '6130') " . ((fnet_sfdc_validate_gold('53070001', '6130')) ? 'true' : 'false') . " \n";
      $result .= "fnet_sfdc_validate_gold('5309x0002', '3320') " . ((fnet_sfdc_validate_gold('5309x0002', '3320')) ? 'true' : 'false') . " \n";
      $result .= "fnet_sfdc_validate_gold('5401_0001', '6440') " . ((fnet_sfdc_validate_gold('5401_0001', '6440')) ? 'true' : 'false') . " \n";
      $result .= "fnet_sfdc_validate_gold('5307!0001', '6130') " . ((fnet_sfdc_validate_gold('5307!0001', '6130')) ? 'true' : 'false') . " \n";
      $result .= "fnet_sfdc_validate_gold('53099999', '3320') " . ((fnet_sfdc_validate_gold('53099999', '3320')) ? 'true' : 'false') . " \n";
      $result .= "fnet_sfdc_validate_gold('54010001', '1234') " . ((fnet_sfdc_validate_gold('54010001', '1234')) ? 'true' : 'false') . " \n";
      $result .= "fnet_sfdc_validate_gold('5307-0001', '1234') " . ((fnet_sfdc_validate_gold('5307-0001', '1234')) ? 'true' : 'false') . " \n";
      $result .= "fnet_sfdc_validate_gold('', '') " . ((fnet_sfdc_validate_gold('', '')) ? 'true' : 'false') . " \n";
      $result .= "fnet_sfdc_validate_gold(null, null) " . ((fnet_sfdc_validate_gold(NULL, NULL)) ? 'true' : 'false') . " \n";
      break;
  }
  $form_state['rebuild'] = TRUE;
  $form_state['fnet_sfdc']['result'] = $result . "\n";
}

/**
 * @file
 * Test functions for fnet_sfdc module.
 *
 */
function fnet_sfdc_test_assets($form, &$form_state) {
  $form = array();
  $methods = drupal_map_assoc(array(
    'createAsset',
    'getAssets',
    'getGoldContracts',
    'getWebProducts',
    'getProductFamilies',
  ));

  $form['method'] = array(
    '#type' => 'select',
    '#title' => 'method',
    '#options' => $methods,
    '#default_value' => isset($form_state['values']['method']) ? $form_state['values']['method'] : '',
    '#description' => 'Method to test',
  );

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['email']) ? $form_state['values']['email'] : '',
  );

  $form['gold_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Gold number'),
    '#size' => 30,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['gold_number']) ? $form_state['values']['gold_number'] : '',
  );

  $form['gold_pin'] = array(
    '#type' => 'textfield',
    '#title' => t('Gold PIN'),
    '#size' => 30,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['gold_pin']) ? $form_state['values']['gold_pin'] : '',
  );

  $form['for_create_asset']['#markup'] = '<h2>For createAsset</h2>';

  $form['product_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Product Code'),
    '#size' => 30,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['product_code']) ? $form_state['values']['product_code'] : '',
  );

  $form['serial_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Serial Number'),
    '#size' => 30,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['serial_number']) ? $form_state['values']['serial_number'] : '',
  );

  $form['purchase_date'] = array(
    '#type' => 'textfield',
    '#title' => t('Purchase Date'),
    '#size' => 30,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['purchase_date']) ? $form_state['values']['purchase_date'] : '',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  $form['result'] = array(
    '#type' => 'item',
    '#title' => 'Result',
    '#markup' => '<pre>' . $form_state['fnet_sfdc']['result'] . '</pre>',
  );
  return $form;
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function fnet_sfdc_test_assets_submit($form, &$form_state) {
  global $user;
  if ($form_state['values']['email'] != '') {
    $email = $form_state['values']['email'];
  }
  else {
    $email = $user->mail;
    $form_state['values']['email'] = $email;
  }
  if ($form_state['values']['gold_number'] != '') {
    $gold_number = $form_state['values']['gold_number'];
    $gold_pin = $form_state['values']['gold_pin'];
  }
  else {
    $gold_number = $user->field_user_gold_number[LANGUAGE_NONE][0]['value'];
    $gold_pin = $user->field_user_gold_pin[LANGUAGE_NONE][0]['value'];
    $form_state['values']['gold_number'] = $gold_number;
    $form_state['values']['gold_pin'] = $gold_pin;
  }

  $product_code = $form_state['values']['product_code'];
  $purchase_date = $form_state['values']['purchase_date'];
  $serial_number = $form_state['values']['serial_number'];

  $result = '';
  switch ($form_state['values']['method']) {
    case 'getAssets':
      $result .= print_r(fnet_sfdc_get_assets($email), TRUE) . "\n";
      break;
    case 'createAsset':
      $result .= print_r(fnet_sfdc_create_asset($email, $product_code, $purchase_date, $serial_number), TRUE) . "\n";
      break;
    case 'getGoldContracts':
      $result .= print_r(fnet_sfdc_get_gold_contracts($gold_number, $gold_pin), TRUE) . "\n";
      break;
    case 'getWebProducts':
      $result .= print_r(fnet_sfdc_get_web_products(), TRUE) . "\n";
      break;
    case 'getProductFamilies':
      $result .= print_r(fnet_sfdc_get_product_families(), TRUE) . "\n";
      break;
  }
  $form_state['rebuild'] = TRUE;
  $form_state['fnet_sfdc']['result'] = $result . "\n";
}
