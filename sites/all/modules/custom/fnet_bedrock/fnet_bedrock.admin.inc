<?php
/**
 * @file
 * Admin forms and functions for fnet_bedrock module
 *
 */

/**
 * Administrative settings form for FNET Bedrock module.
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function fnet_bedrock_admin_form($form, &$form_state) {
  $form = [];
  $form['fnet_bedrock_url_scheme'] = [
    '#type' => 'select',
    '#title' => t('Bedrock url scheme'),
    '#required' => TRUE,
    '#options' => drupal_map_assoc(['http:', 'https:']),
    '#default_value' => variable_get('fnet_bedrock_url_scheme', ''),
    '#description' => t("Bedrock server scheme"),
  ];
  $form['fnet_bedrock_base_url'] = [
    '#type' => 'textfield',
    '#title' => t('Bedrock base url'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => variable_get('fnet_bedrock_base_url', ''),
    '#description' => t("url of Bedrock server"),
  ];
  $form['fnet_bedrock_basic_auth_user'] = [
    '#type' => 'textfield',
    '#title' => t('Basic AUTH user'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => variable_get('fnet_bedrock_basic_auth_user', ''),
    '#description' => t('Username for Bedrock basic AUTH'),
  ];

  $form['fnet_bedrock_basic_auth_password'] = [
    '#type' => 'textfield',
    '#title' => t('Basic AUTH password'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => variable_get('fnet_bedrock_basic_auth_password', ''),
    '#description' => t('Password for Bedrock basic AUTH'),
  ];
  $form['fnet_bedrock_authentication'] = [
    '#type' => 'radios',
    '#title' => t('Use Bedrock for authentication'),
    '#options' => ['No', 'Yes'],
    '#required' => TRUE,
    '#default_value' => variable_get('fnet_bedrock_authentication', FALSE),
    '#description' => t('Should Bedrock be used to authenticate users attempting to log in.'),
  ];
  return system_settings_form($form);
}
