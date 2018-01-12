<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 1/12/18
 * Time: 2:42 PM
 */


/**
 * Implements Admin Page for text instructions.
 */
function sales_insider_admin_instructions_form($form, &$form_state) {
  $form = array();

  $form['extranet_instructions_request_access'] = array(
    '#type' => 'textarea',
    '#title' => t('Request Access'),
    '#description' => t('The instruction text for when a user requests access to the Extranet'),
    '#default_value' => variable_get('extranet_instructions_request_access', ''),
  );

  $form['extranet_instructions_main'] = array(
    '#type' => 'textarea',
    '#title' => t('Main Page'),
    '#description' => t('The instruction text for the main page.'),
    '#default_value' => variable_get('extranet_instructions_main', ''),
  );

  $form['extranet_instructions_sales_tools'] = array(
    '#type' => 'textarea',
    '#title' => t('Sales Tools'),
    '#description' => t('The instruction text for the Sales Tools page.'),
    '#default_value' => variable_get('extranet_instructions_sales_tools', ''),
  );

  $form['extranet_instructions_services'] = array(
    '#type' => 'textarea',
    '#title' => t('Services & Support text'),
    '#description' => t('The instruction text for the Services & Support page.'),
    '#default_value' => variable_get('extranet_instructions_services', ''),
  );

  $form['extranet_instructions_access_denied'] = array(
    '#type' => 'textarea',
    '#title' => t('Access Denied text'),
    '#description' => t('Instruction text for the Access Denied page'),
    '#default_value' => variable_get('extranet_instructions_access_denied', ''),
  );

  return system_settings_form($form);
}