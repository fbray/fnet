<?php
// $Id: fnet_ma.support_incident.inc 98 2015-05-26 19:58:17Z sogden1 $

/**
 * @file
 * This section is related to - "Support Incidents" on Fluke Networks.
 * Section starts from here and this code set is triggered on the URL - "'myaccount/all-support-incidents'"
 */

/**
 * The Support Incident form
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function fnet_ma_support_incident_form($form, $form_state) {

  $registered_product_list = fnet_ma_load_registered_products();
  $product_name_array = fnet_ma_load_registered_products('name only');
  if (count($registered_product_list)) {
    $registered_products = array("-1" => ' - Select a Product - ') + $registered_product_list;
    $form['static_message_three'] = array(
      '#type' => 'item',
      '#title' => '',
      '#value' => '<div class="my-account-headlines header-border_bottom">' . t("Submit a Support Incident") . '</div>',
    );
  }
  else {
    $registered_products = array('0' => t('-No registered products found-'));
    drupal_set_message('You must have a registered product to open a support incident', 'error');
  }

  $form['complete_product_array'] = array(
    '#type' => 'value',
    '#value' => $product_name_array,
  );

  $form['static_message_two'] = array(
    '#type' => 'item',
    '#title' => '',
    '#value' => '<b>' . variable_get('fn_myaccount_support_incident_header_text', t('DESCRIBE YOUR PROBLEM OR ENTER A QUESTION: ')) . '</b>',
  );

  $form['product_numbers'] = array(
    '#type' => 'select',
    '#title' => t('Registered Products'),
    '#options' => $registered_products,
    '#required' => TRUE,
    '#default_value' => '',
  );

  $form['support_incident_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter a Subject'),
    '#required' => TRUE,
    '#default_value' => '',
  );

  $form['support_incident_description'] = array(
    '#type' => 'textarea',
    '#title' => t('Please describe your problem or question. Maximum of 4000 characters allowed'),
    '#required' => TRUE,
    '#default_value' => '',
    '#cols' => 80,
    '#rows' => 15,
    '#attributes' => array('maxlength' => 4000),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

/**
 * The Support Incident form validation callback.
 *
 * @param $form
 * @param $form_state
 */
function fnet_ma_support_incident_form_validate($form, &$form_state) {
  // Any validation code can be placed here.
  if (trim($form_state['values']['product_numbers']) == '0') {
    form_set_error('product_numbers', t('No products are registered yet.'));
  }
  if (trim($form_state['values']['product_numbers']) == '-1') {
    form_set_error('product_numbers', t("Select a value from - 'Registered Products'."));
  }
}

/**
 * The Support Incident form submit callback.
 *
 * @param $form
 * @param $form_state
 */
function fnet_ma_support_incident_form_submit($form, &$form_state) {
  fnet_ma_report_product_incidents($form_state, 'insert');
}


/**
 * The Product Support Incident form.
 *
 * @param $form
 * @param $form_state
 * @param $asset_id
 * @return mixed
 */
function fnet_ma_product_support_incident_form($form, $form_state, $asset_id) {
  $registered_product_list = fnet_ma_load_registered_products();
  $product_names = fnet_ma_load_registered_products('name only');
  $form['asset_id'] = array(
    '#type' => 'value',
    '#value' => $asset_id,
  );
  if (count($registered_product_list)) {
    if (array_key_exists($asset_id, $registered_product_list)) {
      $form['static_message_one'] = array(
        '#type' => 'item',
        '#title' => '',
        '#value' => '<div class="my-account-headlines header-border_bottom ">' . t("Submit a Support Incident for @product_name", array('@product_name' => htmlspecialchars_decode($product_names[$asset_id]))) . '</div>',
      );

      $product_name = $registered_product_list[$asset_id];
      $substitute_array = array(
        '%product_name' => $product_name,
        '%asset_id' => $asset_id,
      );
      $form['static_message'] = array(
        '#type' => 'item',
        '#title' => t('<b>DESCRIBE YOUR PROBLEM OR ENTER A QUESTION FOR PRODUCT - "%product_name" (Asset Id: %asset_id)</b>', $substitute_array),
        '#value' => '',
      );
    }
    else {
      $registered_product_list = array('0' => t('- No registered products found -'));
      $form['static_message_two'] = array(
        '#type' => 'item',
        '#title' => '',
        '#value' => '<span title="This field is required." class="form-required">*</span>' . t(' You have not registered the product for which you are trying to post support incident, please click !link_to_register to see the list of all products you have registered on Fluke Networks. ', array('!link_to_register' => l('here', 'myaccount/registered-products'))),
      );
    }
  }
  else {
    $registered_product_list = array('0' => t('- No registered products found -'));
    $form['static_message_two'] = array(
      '#type' => 'item',
      '#title' => '',
      '#value' => '<span title="This field is required." class="form-required">*</span>' . t(' There are no products registered yet, click !link_to_register to register a product.', array('!link_to_register' => l('here', 'myaccount/register-products-step-one'))),
    );
  }

  $form['product_numbers'] = array(
    '#type' => 'select',
    '#title' => t('Registered Products'),
    '#options' => $registered_product_list,
    '#required' => TRUE,
    '#default_value' => $asset_id,
    '#attributes' => array('disabled' => TRUE),
  );

  $form['support_incident_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter a Subject'),
    '#required' => TRUE,
    '#default_value' => '',
  );

  $form['support_incident_description'] = array(
    '#type' => 'textarea',
    '#title' => t('Please describe your problem or question'),
    '#required' => TRUE,
    '#default_value' => '',
    '#cols' => 80,
    '#rows' => 15,
  );

  $form['complete_product_array'] = array(
    '#type' => 'value',
    '#value' => $product_names,
  );

  $form['static_link_to_KB'] = array(
    '#type' => 'item',
    '#title' => '',
    '#value' => "<br />" . t('Please refer to the following article when submitting a ticket for the Network Time Machine: !link', array(
        '!link' => l('NTM Support Request Questionnaire', 'http://myaccount.flukenetworks.com/fnet/en-us/supportAndDownloads/KB/IT+Networking/Network+Time+Machine/NTM+Support+Request+Questionnaire+-+Network+Time+Machine.htm', array(
          'html' => TRUE,
          'attributes' => array('target' => '_blank')
        ))
      )) . "<br />",
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );

  return $form;
}

/**
 * The Product Support Incident form validate callback.
 *
 * @param $form
 * @param $form_state
 */
function fnet_ma_product_support_incident_form_validate($form, &$form_state) {
  // Any validation code can be placed here.
  if (trim($form_state['values']['product_numbers']) == '0') {
    form_set_error('product_numbers', t('No products are registered yet.'));
  }
}

/**
 * The Product Support Incident form submit callback.
 *
 * @param $form
 * @param $form_state
 */
function fnet_ma_product_support_incident_form_submit($form, &$form_state) {
  fnet_ma_report_product_incidents($form_state, 'insert');
}

/**
 * The View Support Incident form.
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function fnet_ma_view_support_incident_form($form, $form_state, $incident_id) {
  $support_incident_details = fnet_sfdc_get_support_incident($incident_id, 'details');
  if (empty($support_incident_details)) {
    drupal_set_message(variable_get('myaccount_webservices_failure_notification_message', 'Error retrieving support incident'), 'error', $repeat = FALSE);
  }

  $asset_id = $support_incident_details['product_id'];
  $product_details = fnet_sfdc_get_support_incident($incident_id, 'asset');
  if (empty($product_details)) {
    drupal_set_message(variable_get('myaccount_webservices_failure_notification_message', 'Error retrieving support incident'), 'error', $repeat = FALSE);
  }

  $detail_history_support_incidents = fnet_sfdc_get_support_incident($incident_id, 'comments');
  if (empty($detail_history_support_incidents)) {
    drupal_set_message(variable_get('myaccount_webservices_failure_notification_message', 'Error retrieving support incident'), 'error', $repeat = FALSE);
  }
  $incident_history_detail_string = '';

  if (count($detail_history_support_incidents)) {
    foreach ($detail_history_support_incidents as $keys => $values) {
      $incident_history_detail_string .= '<div class = "support-incident-details-history-section">';
      $incident_history_detail_string .= '<b>' . t('Posted on: ') . '</b>' . $values['date'] . '<br /><br />' . nl2br($values['message']);
      $incident_history_detail_string .= '</div><br/>';
    }
  }

  $form['product_section_header_message'] = array(
    '#markup' => '<div class="my-account-headlines header-border_bottom">' . t('Support Incident - @support_incident_ID', array('@support_incident_ID' => check_plain($incident_id))) . '</div>',
  );
  if ($product_details['has_product_details']) {
    $form['static_product_name'] = array(
      '#type' => 'item',
      '#title' => t('Product'),
      '#markup' => $product_details['vchDescription'],
    );

    $form['static_product_model'] = array(
      '#type' => 'item',
      '#title' => t('Model'),
      '#markup' => $product_details['vchSecondaryId'],
    );

    $form['static_product_serial_number'] = array(
      '#type' => 'item',
      '#title' => t('Serial Number'),
      '#markup' => $product_details['vchSerialNumber'],
    );

    $gold_support = ($product_details['isGoldProduct']) ? t('Yes') : t('No');
    $form['static_network_supervision_gold_support'] = array(
      '#type' => 'item',
      '#title' => t('Gold Support'),
      '#markup' => $gold_support,
      '#suffix' => '<div class = "ruler-bar"></div>',
    );
  }

  $form['supportincident_section_header_message'] = array(
    '#markup' => '<div class="my-account-headlines top-margin-20px">' . t('PROBLEM OR QUESTION') . '</div>',
  );

  $form['static_support_incident_subject'] = array(
    '#type' => 'item',
    '#title' => t('Subject'),
    '#markup' => check_plain($support_incident_details['vchDesc1']),
  );

  $form['static_support_incident_status'] = array(
    '#type' => 'item',
    '#title' => t('Status'),
    '#markup' => check_plain($support_incident_details['vchStatusDesc']),
    '#suffix' => '<div class = "ruler-bar"></div>',
  );

  if (trim(check_plain($support_incident_details['vchStatusDesc'])) != 'Closed') {
    $form['support_incident_description'] = array(
      '#type' => 'textarea',
      '#title' => t('You can add comments to this support incident here. Maximum of 4000 characters allowed'),
      '#required' => TRUE,
      '#default_value' => '',
      '#cols' => 80,
      '#rows' => 10,
      '#attributes' => array('maxlength' => 4000),
    );

    $form['support_incident_ID'] = array(
      '#type' => 'hidden',
      '#value' => $support_incident_details['iIncidentId'],
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Submit'),
      '#suffix' => '<br /><br /><div class = "ruler-bar"></div>',
    );
  }

  $form['supportincident_detail_history'] = array(
    '#markup' => '<div class="my-account-headlines header-border_bottom top-margin-20px">' . t('Detail History') . '</div>',
  );

  $form['supportincident_detail_history_string'] = array(
    '#type' => 'item',
    '#title' => 'History',
    '#markup' => $incident_history_detail_string,
  );

  return $form;
}

/**
 * The View Support Incident submit callback.
 * @param $form
 * @param $form_state
 */
function fnet_ma_view_support_incident_form_submit($form, &$form_state) {
  fnet_ma_report_product_incidents($form_state, 'update');
}


/**
 * Displays a list of the Support Incidents.
 * TODO: Can this be replaced by a View?
 *
 * @param int $user_id
 * @param int $asset_id
 * @return string
 */
function fnet_ma_display_all_support_incidents($days_history = 30, $asset_id = NULL) {
  global $user;
  if(user_is_anonymous()) {
    drupal_goto('/user');
  }
  $html = '';
  $days = (!empty($_REQUEST['days'])) ? $_REQUEST['days'] : $days_history;
  drupal_add_js(drupal_get_path('module', 'fnet_ma') . '/js/fnet_ma_helper.js');
  if (!empty($asset_id)) {
    $support_incidents = fnet_ma_fetch_support_incidents($days);
    $incidents = [];
    foreach ($support_incidents as $incident) {
      if ($incident['asset_id'] == $asset_id) {
        $incidents[] = $incident;
      }
    }
    $support_incidents = $incidents;
    $html .= '<div class="my-account-headlines">Support Incidents related to the Product: ' . fnet_ma_get_model_name($asset_id) . '</div>';
  }
  else {
    $support_incidents = fnet_ma_fetch_support_incidents($days);
  }
  $search_form = drupal_get_form('fnet_ma_support_incident_search_form');
  $rendered_search_form = drupal_render($search_form);
  $html .= theme("all_support_incident_display", [
    'support_incidents' => $support_incidents,
    'search_form' => $rendered_search_form
  ]);
  return $html;
}

/**
 * A helper function that, given the model number, will return the name of the model .
 *
 * @param $model_number
 * @return mixed
 */
function fnet_ma_get_model_name($model_number) {
  $categories = fnet_sfdc_get_web_products()->data;
  foreach ($categories as $products) {
    if (array_key_exists($model_number, $categories)) {
      return $products[$model_number];
    }
  }
}

/**
 * This function generates a 'Thank You' message.
 *
 * @return mixed|string
 */
function fnet_ma_display_support_incident_thanks_message() {
  $text = variable_get('myaccount_thankyou_message_support_incident', t('Thank you for posting the support incident.'));
  $html = check_markup($text,  	filter_fallback_format(), $langcode = '' /* TODO Set this variable. */, TRUE);
  $html .= '<br /><br />';
  $html .= t('Click to !link_to_register_again', array(
    '!link_to_register_again' => l(t("Create a support incident."), 'myaccount/report-support-incidents', $options = array(
      'attributes' => array('style' => ''),
      'html' => TRUE
    ))
  ));
  return $html;
}
