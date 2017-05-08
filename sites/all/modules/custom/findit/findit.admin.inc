<?php
// $Id$
/**
 * @file
 * Admin forms and functions for findit module
 *
 */

/**
 * Main settings for for FindIt module
 * @return array
 */
function findit_admin_form($form, &$form_state) {
  $form = array();

  $form['findit_tek_geoip_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Tek geoip web service url'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => variable_get('findit_tek_geoip_url', 'http://www2.tek.com/cmswpt/tekipvalidate/'),
    '#description' => t("URL for web service returning embargo status for an ip address"),
  );

  $form['findit_restricted_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Asset restricted message'),
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => variable_get('findit_restricted_message', 'Access to this asset is restricted. Please contact support.'),
    '#description' => t("Message to display if software compliance check fails"),
  );

  $form['findit_restricted_redirect_path'] = array(
    '#type' => 'textfield',
    '#title' => t('Asset restricted redirect path'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => variable_get('findit_restricted_redirect_path', ''),
    '#description' => t("Path for page to redirect to if software compliance check fails"),
  );

  $form['findit_not_found_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Asset not found message'),
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => variable_get('findit_not_found_message', 'The asset you requested could not be found'),
    '#description' => t("Message to display if requested asset is not found"),
  );

  $form['findit_date_range_message'] = array(
    '#type' => 'textfield',
    '#title' => t('Asset not active for date message'),
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => variable_get('findit_date_range_message', 'The asset you requested in not currently available'),
    '#description' => t("Message to display if requested asset fails date range validation"),
  );

  $form['findit_gold_required_message'] = array(
    '#type' => 'textfield',
    '#title' => t('User not entitled to Gold download message'),
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => variable_get('findit_gold_required_message', 'A Gold support contract is required to download this asset'),
    '#description' => t("Message to display if user does not have required Gold status"),
  );

  $form['findit_gold_required_redirect_path'] = array(
    '#type' => 'textfield',
    '#title' => t('User not entitled to Gold download redirect path'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => variable_get('findit_gold_required_redirect_path', ''),
    '#description' => t("Path for page to redirect to if user does not have required Gold status"),
  );

  $form['findit_login_required_message'] = array(
    '#type' => 'textfield',
    '#title' => t('User must be logged in to download message'),
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => variable_get('findit_login_required_message', 'You must be logged in to download this asset'),
    '#description' => t("Message to display if user is not logged in"),
  );

  $form = system_settings_form($form);
  return $form;
}

/**
 * Validation function for findit_admin_form
 *
 * @param $form
 * @param $form_state
 */
function findit_admin_form_validate($form, &$form_state) {
  $form_fields = array(
    'findit_restricted_redirect_path',
    'findit_gold_required_redirect_path',
  );
  foreach ($form_fields as $field) {
    $value = $form_state['values'][$field];
    $path = drupal_lookup_path('source', $value);
    if (!$path) {
      $path = drupal_lookup_path('alias', $value);
      if ($path) {
        $form_state['values'][$field] = $path;
      }
    }
    if (!$path) {
      form_set_error($field, t('%path is not a valid path', array('%path' => $value)));
    }
  }
}

/**
 * Form for settings related to OCR Ease export compliance checks
 *
 * @param $form_state
 * @return array
 */
function findit_admin_ocr_form($form, &$form_state) {
  $form = array();
  $form['findit_download_link'] = array(
    '#type' => 'item',
    '#title' => t('OCR Log Download'),
    '#markup' => l('Downloads.csv', '/findit/downloads.csv'),
  );
  $form['findit_ocr_url'] = array(
    '#type' => 'textfield',
    '#title' => t('OCR Ease web service url'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => variable_get('findit_ocr_url', 'http://easehost.ocr-inc.com/dpss/resultHostedService.ocr'),
    '#description' => t("URL for web service returning embargo status for a person or company."),
  );
  $form['findit_ocr_username'] = array(
    '#type' => 'textfield',
    '#title' => t('OCR Ease user name'),
    '#size' => 30,
    '#required' => TRUE,
    '#default_value' => variable_get('findit_ocr_username', 'flukeweb'),
    '#description' => t("Username for OCR Ease web service."),
  );
  $form['findit_ocr_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Export control notification email address'),
    '#size' => 60,
    '#required' => TRUE,
    '#default_value' => variable_get('findit_ocr_email', 'export-screenings@fluke.com'),
    '#description' => t("Email address that receives message when a user is flagged by OCR."),
  );
  $form['findit_ocr_log_history'] = array(
    '#type' => 'select',
    '#title' => t('OCR log history days'),
    '#options' => drupal_map_assoc(array(7, 14, 21, 30, 60, 180)),
    '#required' => TRUE,
    '#default_value' => variable_get('findit_ocr_log_history', 5),
    '#description' => t("Number of days history to keep in OCR log."),
  );
  $form['findit_ocr_log_recheck_delay'] = array(
    '#type' => 'select',
    '#title' => t('OCR log recheck delay (days)'),
    '#options' => drupal_map_assoc(array(1, 2, 3, 4, 5)),
    '#required' => TRUE,
    '#default_value' => variable_get('findit_ocr_log_recheck_delay', 2),
    '#description' => t("Number of days to wait before rechecking OCR 'holds'."),
  );
  $form['findit_ocr_log_max_check_count'] = array(
    '#type' => 'select',
    '#title' => t('Maximum OCR status checks'),
    '#options' => drupal_map_assoc(array(
      1,
      2,
      3,
      4,
      5,
      6,
      7,
      8,
      9,
      10,
      11,
      12,
      13,
      14,
      15,
      16
    )),
    '#required' => TRUE,
    '#default_value' => variable_get('findit_ocr_log_max_check_count', 2),
    '#description' => t("Maximum number of times to check OCR status."),
  );
  $form = system_settings_form($form);
  return $form;
}

/**
 * Form for settings related to assets stored on the Level 3 CDN
 *
 * @param $form_state
 * @return array
 */
function findit_admin_level3_form($form, &$form_state) {
  $form = array();

  $form['findit_level3_base_http_url'] = array(
    '#type' => 'textfield',
    '#title' => t('Base http url for files'),
    '#default_value' => variable_get('findit_level3_base_http_url', 'http://download.flukenetworks.com/'),
    '#description' => t("e.g. http://download.flukenetworks.com/"),
    '#required' => TRUE,
  );
  $form['findit_level3_shared_secret_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Level 3 shared secret number'),
    '#description' => t('Location (0-9) of the stored shared secret to use for token hash generation.'),
    '#size' => 10,
    '#required' => FALSE,
    '#default_value' => variable_get('findit_level3_shared_secret_number', 0),
  );
  $form['findit_level3_shared_secret_string'] = array(
    '#type' => 'textfield',
    '#title' => t('Level 3 shared secret'),
    '#description' => t('Shared secret to use for token hash generation.'),
    '#size' => 60,
    '#required' => FALSE,
    '#default_value' => variable_get('findit_level3_shared_secret_string', 'fIndIt_level3_sh@red_secret_string'),
  );
  $form['findit_level3_valid_time_interval'] = array(
    '#type' => 'textfield',
    '#title' => t('Level 3 token valid time interval'),
    '#description' => t('Length of time that authentication token is valid in minutes.'),
    '#size' => 10,
    '#required' => FALSE,
    '#default_value' => variable_get('findit_level3_valid_time_interval', 15),
  );
  $form = system_settings_form($form);
  return $form;
}
