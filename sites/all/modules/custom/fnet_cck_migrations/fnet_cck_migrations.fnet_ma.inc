<?php
// $Id$
/**
 * @file
 * Migrate fnet_ma data functions
 *
 */
function fnet_cck_migrations_fnet_ma() {
  $fnet_ma_custom_login_page_error_message = variable_get('flukenetworks_myaccount_custom_login_page_error_message', NULL);
  $fnet_ma_custom_reset_password_page_error_message = variable_get('flukenetworks_myaccount_custom_reset_password_page_error_message', NULL);
  $fnet_ma_download_and_updates_text = variable_get('flukenetworks_myaccount_download_and_updates_text', NULL);
  $fnet_ma_dsx_product_code = variable_get('flukenetworks_myaccount_dsx_product_code', NULL);
  $fnet_ma_dtx_product_code = variable_get('flukenetworks_myaccount_dtx_product_code', NULL);
  $fnet_ma_gold_contract_admin_in_INT = variable_get('flukenetworks_myaccount_gold_contract_admin_in_INT', NULL);
  $fnet_ma_gold_contract_admin_in_JAPAN = variable_get('flukenetworks_myaccount_gold_contract_admin_in_JAPAN', NULL);
  $fnet_ma_gold_contract_admin_in_US = variable_get('flukenetworks_myaccount_gold_contract_admin_in_US', NULL);
  $fnet_ma_gold_type_pop_code_email_content_for_admin = variable_get('flukenetworks_myaccount_gold_type_pop_code_email_content_for_admin', NULL);
  $fnet_ma_gold_type_pop_code_email_subject_for_admin = variable_get('flukenetworks_myaccount_gold_type_pop_code_email_subject_for_admin', NULL);
  $fnet_ma_gold_type_pop_code_page_introduction = variable_get('flukenetworks_myaccount_gold_type_pop_code_page_introduction', NULL);
  $fnet_ma_gold_type_pop_code_success_status_message = variable_get('flukenetworks_myaccount_gold_type_pop_code_success_status_message', NULL);
  $fnet_ma_user_login_page_notification_message = variable_get('flukenetworks_myaccount_user_login_page_notification_message', NULL);

  variable_del('flukenetworks_myaccount_custom_login_page_error_message');
  variable_del('flukenetworks_myaccount_custom_reset_password_page_error_message');
  variable_del('flukenetworks_myaccount_download_and_updates_text');
  variable_del('flukenetworks_myaccount_dsx_product_code');
  variable_del('flukenetworks_myaccount_dtx_product_code');
  variable_del('flukenetworks_myaccount_gold_contract_admin_in_INT');
  variable_del('flukenetworks_myaccount_gold_contract_admin_in_JAPAN');
  variable_del('flukenetworks_myaccount_gold_contract_admin_in_US');
  variable_del('flukenetworks_myaccount_gold_type_pop_code_email_content_for_admin');
  variable_del('flukenetworks_myaccount_gold_type_pop_code_email_subject_for_admin');
  variable_del('flukenetworks_myaccount_gold_type_pop_code_page_introduction');
  variable_del('flukenetworks_myaccount_gold_type_pop_code_success_status_message');
  variable_del('flukenetworks_myaccount_user_login_page_notification_message');

  variable_set('fnet_ma_custom_login_page_error_message', $fnet_ma_custom_login_page_error_message);
  variable_set('fnet_ma_custom_reset_password_page_error_message', $fnet_ma_custom_reset_password_page_error_message);
  variable_set('fnet_ma_download_and_updates_text', $fnet_ma_download_and_updates_text);
  variable_set('fnet_ma_dsx_product_code', $fnet_ma_dsx_product_code);
  variable_set('fnet_ma_dtx_product_code', $fnet_ma_dtx_product_code);
  variable_set('fnet_ma_gold_contract_admin_in_INT', $fnet_ma_gold_contract_admin_in_INT);
  variable_set('fnet_ma_gold_contract_admin_in_JAPAN', $fnet_ma_gold_contract_admin_in_JAPAN);
  variable_set('fnet_ma_gold_contract_admin_in_US', $fnet_ma_gold_contract_admin_in_US);
  variable_set('fnet_ma_gold_type_pop_code_email_content_for_admin', $fnet_ma_gold_type_pop_code_email_content_for_admin);
  variable_set('fnet_ma_gold_type_pop_code_email_subject_for_admin', $fnet_ma_gold_type_pop_code_email_subject_for_admin);
  variable_set('fnet_ma_gold_type_pop_code_page_introduction', $fnet_ma_gold_type_pop_code_page_introduction);
  variable_set('fnet_ma_gold_type_pop_code_success_status_message', $fnet_ma_gold_type_pop_code_success_status_message);
  variable_set('fnet_ma_user_login_page_notification_message', $fnet_ma_user_login_page_notification_message);

  drupal_set_message('Done.');
}

