<?php
// $Id$

/**
 * @file
 * Administer settings for fnet_rest_service.module
 *
 */

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function fnet_rest_service_admin_form($form, &$form_state) {
  $form = array();
  $form['fnet_rest_service_key'] = array(
    '#type' => 'textfield',
    '#title' => t('API key for service'),
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => variable_get('fnet_rest_service_key', ''),
  );
  $form['fnet_rest_service_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Secret for the API service key'),
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => variable_get('fnet_rest_service_secret', ''),
  );
  $form = system_settings_form($form);
  return $form;
}
