<?php
// $Id:  $

/**
 * @file
 * Admin functions for site_split module.
 *
 */

function site_split_admin_form($form, &$form_state) {
  $form = array();
  $form['site_split_personality'] = array(
    '#type' => 'select',
    '#title' => t('Select personality for site'),
    '#options' => drupal_map_assoc(array('Pre-split', 'FNET', 'NETSCOUT')),
    '#required' => TRUE,
    '#default_value' => variable_get('site_split_personality', 'Pre-split'),
  );

  $form = system_settings_form($form);
  return $form;
}