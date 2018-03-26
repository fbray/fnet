<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 1/12/18
 * Time: 2:42 PM
 */


/**
 * Implements Admin Page for text instructions.
 * @param $form
 * @param $form_state
 * @return mixed
 */
function sales_insider_admin_instructions_form($form, &$form_state) {
  $form = [];

  $form['extranet_instructions_request_access'] = [
    '#type' => 'textarea',
    '#title' => t('Request Access'),
    '#description' => t('The instruction text for when a user requests access to the Extranet'),
    '#default_value' => variable_get('extranet_instructions_request_access', ''),
  ];

  $form['extranet_instructions_main'] = [
    '#type' => 'textarea',
    '#title' => t('Main Page'),
    '#description' => t('The instruction text for the main page.'),
    '#default_value' => variable_get('extranet_instructions_main', ''),
  ];

  $form['extranet_instructions_sales_tools'] = [
    '#type' => 'textarea',
    '#title' => t('Sales Tools'),
    '#description' => t('The instruction text for the Sales Tools page.'),
    '#default_value' => variable_get('extranet_instructions_sales_tools', ''),
  ];

  $form['extranet_instructions_contacts'] = [
    '#type' => 'textarea',
    '#title' => t('Contacts Page text'),
    '#description' => t('The instruction text for the Contacts page.'),
    '#default_value' => variable_get('extranet_instructions_contacts', ''),
  ];

  $form['extranet_instructions_access_denied'] = [
    '#type' => 'textarea',
    '#title' => t('Access Denied text'),
    '#description' => t('Instruction text for the Access Denied page'),
    '#default_value' => variable_get('extranet_instructions_access_denied', ''),
  ];

  return system_settings_form($form);
}