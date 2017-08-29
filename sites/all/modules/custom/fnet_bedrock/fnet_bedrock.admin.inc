<?php
// $Id: fnet_bedrock.admin.inc 25 2015-03-31 20:12:49Z sogden1 $
/**
 * @file
 * Admin forms and functions for fnet_bedrock module
 *
 */

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function fnet_bedrock_admin_form($form, &$form_state) {
  $form = array();
  $form['fnet_bedrock_url_scheme'] = array(
    '#type' => 'select',
    '#title' => t('Bedrock url scheme'),
    '#required' => TRUE,
    '#options' => drupal_map_assoc(array('http:', 'https:')),
    '#default_value' => variable_get('fnet_bedrock_url_scheme', ''),
    '#description' => t("Bedrock server scheme"),
  );
  $form['fnet_bedrock_base_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Bedrock base url'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => variable_get('fnet_bedrock_base_url', ''),
    '#description' => t("url of Bedrock server"),
  );
  $form['fnet_bedrock_basic_auth_user'] = array(
    '#type' => 'textfield',
    '#title' => t('Basic AUTH user'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => variable_get('fnet_bedrock_basic_auth_user', ''),
    '#description' => t('Username for Bedrock basic AUTH'),
  );

  $form['fnet_bedrock_basic_auth_password'] = array(
    '#type' => 'textfield',
    '#title' => t('Basic AUTH password'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => variable_get('fnet_bedrock_basic_auth_password', ''),
    '#description' => t('Password for Bedrock basic AUTH'),
  );
  $form['fnet_bedrock_authentication'] = array(
    '#type' => 'radios',
    '#title' => t('Use Bedrock for authentication'),
    '#options' => array('No', 'Yes'),
    '#required' => TRUE,
    '#default_value' => variable_get('fnet_bedrock_authentication', FALSE),
    '#description' => t('Should Bedrock be used to authenticate users attempting to log in.'),
  );
  $form = system_settings_form($form);
  return $form;
}
