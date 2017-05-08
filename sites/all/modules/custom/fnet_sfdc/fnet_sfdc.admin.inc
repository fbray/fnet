<?php
// $Id$
/**
 * @file
 * Admin forms and functions for fnet_sfdc module
 *
 */

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function fnet_sfdc_admin_form($form, &$form_state) {
  $form = array();

  $form['fnet_sfdc_wsdl_version'] = array(
    '#type' => 'select',
    '#title' => t('SFDC WSDL Version'),
    '#required' => TRUE,
    '#options' => drupal_map_assoc(array('dev', 'test', 'prod', 'na20')),
    '#default_value' => variable_get('fnet_sfdc_wsdl_version', 'dev'),
    '#description' => t("Which SFDC WSDL files should be used: Prod, Test, or Development?"),
  );

  $form['fnet_sfdc_user_id'] = array(
    '#type' => 'textfield',
    '#title' => t('SFDC User Id'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => variable_get('fnet_sfdc_user_id', ''),
    '#description' => t("User Id for SFDC web service calls"),
  );

  $form['fnet_sfdc_password'] = array(
    '#type' => 'textfield',
    '#title' => t('SFDC password'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => variable_get('fnet_sfdc_password', ''),
    '#description' => t("Password for SFDC web service calls"),
  );

  $form['fnet_sfdc_security_token'] = array(
    '#type' => 'textfield',
    '#title' => t('SFDC Security Token'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => variable_get('fnet_sfdc_security_token', ''),
    '#description' => t("Security token for SFDC web service calls"),
  );

  $form['fnet_sfdc_session_lifetime'] = array(
    '#type' => 'select',
    '#title' => t('SFDC Session Lifetime'),
    '#required' => TRUE,
    '#options' => drupal_map_assoc(array('0', '15', '30', '60', '120')),
    '#default_value' => variable_get('fnet_sfdc_session_lifetime', 60),
    '#description' => t("SOAP session lifetime in minutes"),
  );

  $form['fnet_sfdc_cache_soap_responses'] = array(
    '#type' => 'select',
    '#title' => t('Cache SFDC SOAP responses'),
    '#required' => TRUE,
    '#options' => drupal_map_assoc(array('yes', 'no')),
    '#default_value' => variable_get('fnet_sfdc_cache_soap_responses', 'yes'),
    '#description' => t("Should SFDC SOAP responses be cached for performance?"),
  );

  $form['fnet_sfdc_watchdog_log_level'] = array(
    '#type' => 'select',
    '#title' => t('Watchdog logging level'),
    '#required' => TRUE,
    '#options' => array(
      'debug' => 'Debug',
      'normal' => 'Errors only',
    ),
    '#default_value' => variable_get('fnet_sfdc_watchdog_log_level', 'normal'),
    '#description' => t("How verbose should watchdog logging be?"),
  );

  $form['fnet_sfdc_clear_cache'] = array(
    '#type' => 'button',
    '#value' => 'Clear SFDC Cache',
    '#validate' => array(),
    '#executes_submit_callback' => TRUE,
    '#submit' => array('fnet_sfdc_admin_clear_cache'),
  );

  $form = system_settings_form($form);
  return $form;
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function fnet_sfdc_admin_clear_cache($form, &$form_state) {
  fnet_sfdc_cache_clear();
  unset($_SESSION['sfdc_session_id']);
  unset($_SESSION['sfdc_session_start']);
  drupal_set_message('SFDC Cache cleared.');
}
