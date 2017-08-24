<?php
// $Id: ems.admin.inc 25 2015-03-31 20:12:49Z sogden1 $

/**
 * Module configuration admin form.
 *
 */
function ems_admin_form($form, &$form_state) {
  global $user;
  $form = array();
  $campaign_name = variable_get('ems_marketo_campaign_name', 'EMS Registration');
  $form['ems_marketo_campaign_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Marketo Campaign Name'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => $campaign_name,
    '#description' => t("The name of the 'Smart Campaign' to use in the Marketo program selected for an event occurrence "),
  );
  $default_thank_you = variable_get('ems_default_thank_you_message_text', '');
  $form['ems_default_thank_you_message_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Default Thank You for Registering message'),
    '#cols' => 60,
    '#rows' => 4,
    '#required' => FALSE,
    '#default_value' => $default_thank_you,
    '#description' => t('Default thank you message to use if the Thank You message in the event occurrence is left blank. Full HTML is allowed.'),
  );
  $event_full = variable_get('ems_event_full_message_text', '');
  $form['ems_event_full_message_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Event Full message'),
    '#cols' => 60,
    '#rows' => 4,
    '#required' => FALSE,
    '#default_value' => $event_full,
    '#description' => t('Message displayed to users who try to register for an event that is at it\'s capacity. Full HTML is allowed.'),
  );
  $form = system_settings_form($form);
  return $form;
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function ems_admin_resubmit_ems_registration($form, &$form_state) {
  $form = array();
  $form['ems_registration_data'] = array(
    '#type' => 'textarea',
    '#title' => t('Registration Data'),
    '#cols' => 60,
    '#rows' => 10,
    '#required' => FALSE,
    '#default_value' => '',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );
  $form['spacer'] = array(
    '#markup' => '<div><p>&nbsp;</p></div>',
  );
  $form['result'] = array(
    '#type' => 'item',
    '#title' => 'Result',
    '#markup' => $form_state['ems']['result'],
  );
  return $form;
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function ems_admin_resubmit_ems_registration_submit($form, &$form_state) {
  if (!function_exists('marketo_api_user_sync')) {
    drupal_set_message('marketo_api_user_sync not found', 'error');
    $form_state['ems']['result'] = '';
    return;
  }
  $registration_code = $form_state['values']['ems_registration_data'];
  if (!empty($registration_code)) {
    $registration_code .= 'return "Success";';
    $result = eval($registration_code);
    $form_state['ems']['result'] = $result;
  }
}
