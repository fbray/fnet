<?php
// $Id$

/**
 * @file
 * testing functions for findit module.
 *
 */

function findit_test($form, &$form_state) {
  $form = array();
  $document_id = (!empty($form_state['values']['document_number'])) ? $form_state['values']['document_number'] : '9827999';
  $form['document_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Document number'),
    '#size' => 20,
    '#required' => FALSE,
    '#default_value' => $document_id,
  );

  $form['locale'] = array(
    '#type' => 'textfield',
    '#title' => t('Locale'),
    '#size' => 20,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['locale']) ? $form_state['values']['locale'] : '',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  if (isset($form_state['storage']['result'])) {
    $form['result'] = array(
      '#type' => 'item',
      '#title' => 'Result',
      '#markup' => '<pre>' . $form_state['storage']['result'] . '</pre>',
    );
  }
  return $form;
}

function findit_test_submit($form, &$form_state) {
  $document_number = $form_state['values']['document_number'];
  $locale = $form_state['values']['locale'];

  $response = findit_check($document_number, $locale);

  $form_state['storage']['result'] = print_r($response, TRUE);
  $form_state['rebuild'] = TRUE;
}

function findit_test_ocr($form, &$form_state) {
  $form = array();

  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('User to check (email)'),
    '#size' => 40,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['email']) ? $form_state['values']['email'] : '',
  );
  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#size' => 40,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['name']) ? $form_state['values']['name'] : '',
  );
  $form['address1'] = array(
    '#type' => 'textfield',
    '#title' => t('Address 1'),
    '#size' => 40,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['address1']) ? $form_state['values']['address1'] : '',
  );
  $form['address2'] = array(
    '#type' => 'textfield',
    '#title' => t('Address 2'),
    '#size' => 40,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['address2']) ? $form_state['values']['address2'] : '',
  );
  $form['city'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#size' => 40,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['city']) ? $form_state['values']['city'] : '',
  );
  $form['state'] = array(
    '#type' => 'textfield',
    '#title' => t('State'),
    '#size' => 40,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['state']) ? $form_state['values']['state'] : '',
  );
  $form['zip'] = array(
    '#type' => 'textfield',
    '#title' => t('Zip'),
    '#size' => 40,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['zip']) ? $form_state['values']['zip'] : '',
  );
  $form['country'] = array(
    '#type' => 'textfield',
    '#title' => t('Country'),
    '#size' => 40,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['country']) ? $form_state['values']['country'] : '',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  if (isset($form_state['storage']['result'])) {
    $form['result'] = array(
      '#type' => 'item',
      '#title' => 'Result',
      '#markup' => '<pre>' . $form_state['storage']['result'] . '</pre>',
    );
  }
  return $form;
}

function findit_test_ocr_submit($form, &$form_state) {
  global $user;
  $asset = new DigitalAsset('9827999', 'en-us');
  $ocr = new OCREaseRequest();
  $ocr->entity_type = 'I';
  $ocr->uid = $user->uid;
  $ocr->key_nm = 'FNET_TEST_' . $form_state['values']['email'];
  $ocr->name = $form_state['values']['name'];
  $ocr->address1 = $form_state['values']['address1'];
  $ocr->address2 = $form_state['values']['address2'];
  $ocr->city = $form_state['values']['city'];
  $ocr->state_name = $form_state['values']['state'];
  $ocr->zip_code = $form_state['values']['zip'];
  $ocr->cntry_code = $form_state['values']['country'];
  $individual_approved = $ocr->approve();
  $form_state['storage']['result'] = "\nApproved: ";
  $form_state['storage']['result'] .= ($individual_approved) ? 'true' : 'false';
  $form_state['storage']['result'] .= "\nStatus: " . $ocr->status();
  $form_state['storage']['result'] .= "\n" . print_r($ocr->response(), TRUE);
  findit_write_ocr_log($ocr, $asset, $user, $entity_type = 'I');
  $form_state['rebuild'] = TRUE;
}
