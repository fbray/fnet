<?php
// $Id: fnet_ma.common_functions.inc 1940 2016-05-06 16:58:53Z mositis $

/**
 * @file
 * This file contains common functions used by other sections of the My Account module.
 */

/**
 * Sends a notification email to "My Account" Admins in case there is a mismatch in Drupal Country Code with Onyx Country Code.
 *
 * @param string $drupal_country_code
 * @param string $drupal_country_name
 * @return bool
 */
function fnet_ma_countrycode_missing_email_trigger($drupal_country_code = '', $drupal_country_name = '') {
  if ($drupal_country_code == '') {
    return TRUE;
  }

  global $user;
  $user_info = array();
  $user_info['fullname'] = check_plain(trim($user->field_user_first_name[LANGUAGE_NONE][0]['value'])) . " " . check_plain(trim($user->field_user_last_name[LANGUAGE_NONE][0]['value']));

  // TODO: Is Onyx still relevant? Might be deprecated. -rositis 5/6/16
  $user_info['onyx_memberID'] = check_plain(trim($user->field_user_onyx_id[LANGUAGE_NONE][0]['value']));

  // TODO: Rework to remove HTML from translated string.
  $message = t('
    <b>Notification for an issue that occurred when mapping the Country code of Drupal Addresses module with the Country Code of Onyx System<br/><br/>
    <b>There is an issue with Drupal to Onyx country mappings in fnet_country_data_cleansing module.  The country that is not mapping correctly is: </b>%country_name (%country_code)<br/><br/>
    <b>Drupal User ID of user</b>: %user_id<br/><br/>
    <b>Drupal Username</b>: %user_name<br/><br/>
    <b>Full Name of the user</b>: %full_name<br/><br/>
    <b>User\'s Onyx individual ID for whom the mapping issue occurred and due to which the Country is defaulted to "United States" for this user and State/Region to "NULL"</b>: %assignedId<br/><br/>
    <b>Issue occured at</b>: %time_date<br/><br/>
  ');

  $variables = array(
    '%country_name' => $drupal_country_name,
    '%country_code' => $drupal_country_code,
    '%user_id' => $user->uid,
    '%user_name' => $user->name,
    '%assignedId' => $user_info['onyx_memberID'],
    '%time_date' => date("h:i  l m/d/Y"),
    '%full_name' => $user_info['fullname'],
  );

  watchdog('My Account', $message, $variables, $severity = WATCHDOG_ERROR, NULL);

  // Function to email the issue to specific email ID here!!!
  // Build the default headers
  $headers = array(
    'MIME-Version' => '1.0',
    'Content-Type' => 'text/html;charset=utf-8',
    'Content-Transfer-Encoding' => '8Bit',
    'X-Mailer' => 'Drupal',
  );

  $email_subject = t('Issue with fnet_country_data_cleansing module while mapping the Country: %country_name', array('%country_name' => $drupal_country_name));
  $email_content = t($message, $variables);

  $default_from = variable_get('site_mail', ini_get('sendmail_from'));
  $headers['From'] = $headers['Sender'] = $headers['Return-Path'] = $headers['Errors-To'] = $default_from;
  $message = array(
    'to' => check_plain(variable_get('myaccount_webservices_failure_notification_email_address', 'example@flukenetworks.com')),
    'from' => $default_from,
    'subject' => $email_subject,
    'body' => $email_content,
    'headers' => $headers,
  );
  fnet_helper_mail_send($message);
}

/**
 * Returns an array of address field defaults based on the value of the cookie "regCountry"
 * This is used in the 'profile' content type configuration: address field configuration: default values: php code
 * as return  fnet_ma_get_address_defaults();
 *
 * @return array
 */
function fnet_ma_get_address_defaults() {
  $country_code = drupal_strtolower($_COOKIE['regCountry']);
  switch ($country_code) {
    case 'gb':
      $country_code = 'uk';
      break;
  }
  $address = array(
    'is_primary' => TRUE,
    'aname' => '',
    'country' => $country_code,
    'province' => '',
    'city' => '',
    'street' => '',
    'additional' => '',
    'postal_code' => '',
  );
  return array($address);
}

/**
 * Writes the error to Watch Dog table and email/notify the issue to an Admin on Fluke Networks.
 */
function fnet_ma_save_errors_to_watch_dog_and_email_to_admin($url = '', $reason = '') {
  global $user;
  $user_info = array();
  $user_info['fullname'] = check_plain(trim($user->field_user_first_name[LANGUAGE_NONE][0]['value'])) . " " . check_plain(trim($user->field_user_last_name[LANGUAGE_NONE][0]['value']));
  $user_info['onyx_memberID'] = check_plain(trim($user->field_user_onyx_id[LANGUAGE_NONE][0]['value']));

  // TODO: Rework to remove HTML from translated string.
  $message = t('
    <b>Notification for an issue that occurred when interacting with the Web service at URL</b>: "%url".<br/><br/>
    <b>Reason</b>: !reason<br/><br/>
    <b>Drupal User ID of user for whom the error occurred</b>: %user_id<br/><br/>
    <b>Drupal Username</b>: %user_name<br/><br/>
    <b>User\'s Email Address</b>: %user_emailaddress<br/><br/>
    <b>Full Name</b>: %full_name<br/><br/>
    <b>User\'s Onyx individual ID</b>: %assignedId<br/><br/>
    <b>Issue occured at</b>: %time_date<br/><br/>
  ');

  $variables = array(
    '%url' => $url,
    '!reason' => $reason,
    '%user_id' => $user->uid,
    '%user_name' => $user->name,
    '%user_emailaddress' => $user->mail,
    '%assignedId' => $user_info['onyx_memberID'],
    '%time_date' => date("h:i  l m/d/Y"),
    '%full_name' => $user_info['fullname'],
  );

  watchdog('My Account', $message, $variables, $severity = WATCHDOG_ERROR, NULL);

  // Function to email the issue to specific email ID here!!!
  // Build the default headers
  $headers = array(
    'MIME-Version' => '1.0',
    'Content-Type' => 'text/html;charset=utf-8',
    'Content-Transfer-Encoding' => '8Bit',
    'X-Mailer' => 'Drupal',
  );

  $email_subject = t('Notification for Web service failure: URL - ') . $url;
  $email_content = t($message, $variables);

  $default_from = variable_get('site_mail', ini_get('sendmail_from'));
  $headers['From'] = $headers['Sender'] = $headers['Return-Path'] = $headers['Errors-To'] = $default_from;
  $message = array(
    'to' => check_plain(variable_get('myaccount_webservices_failure_notification_email_address', 'example@flukenetworks.com')),
    'from' => $default_from,
    'subject' => $email_subject,
    'body' => $email_content,
    'headers' => $headers,
  );
  fnet_helper_mail_send($message);
}

/**
 * Extra Testing related Code.
 * Prints a formatted
 * Array for Testing ONLY.
 */

// This function will be deleted soon!!!
/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function fnet_ma_save_errors_to_watch_dog($url = '', $issue_occured_at = '', $userid = '', $username = '', $individualId = '', $date = '') {
  $message = t('
    <b>Unable to access the contents from the </b>: "%url".<br/><br/>
    <b>Issues occurred during</b>: %reason<br/><br/>
    <b>User ID</b>: %user_id<br/><br/>
    <b>Username</b>: %user_name<br/><br/>
    <b>User\'s Onyx individual ID</b>: %assignedId<br/><br/>
    <b>Issues occured at</b>: %time_date<br/><br/>
  ');
  watchdog('My account module', $message, $variables = array(
    '%url' => $url,
    '%reason' => $issue_occured_at,
    '%user_id' => $userid,
    '%user_name' => $username,
    '%assignedId' => $individualId,
    '%time_date' => $date,
  ), $severity = WATCHDOG_ERROR, NULL);
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function fnet_ma_product_assets_get_region($language) {
  switch ($language) {
    case 'de':
      $region = 'de';
      break;
    case 'fr':
      $region = 'fr';
      break;
    case 'ru':
      $region = 'ru';
      break;
    case 'pt':
      $region = 'br';
      break;
    case 'ja':
      $region = 'jp';
      break;
    case 'ko':
      $region = 'kr';
      break;
    case 'zh':
      $region = 'cn';
      break;
    case 'es':
      $region = 'es';
      break;
    default:
      $region = 'us';
  }
  return $region;
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function fnet_ma_fetch_LMS_product_ids() {
  $domain_url = trim(variable_get("myaccount_webservices_domain_name", 'http://services.test.intranet.danahertm.com'));
  $url = $domain_url . "/ActivateOptions/ActivateOptions.svc/pox/GetConfiguredProduct";
  $http_result = drupal_http_request($url);

  if ($http_result->code == 200) {
    $doc = simplexml_load_string($http_result->data);
    if ($doc === FALSE) {
      fnet_ma_save_errors_to_watch_dog_and_email_to_admin($url, 'The issue occurred when the web service was trying to fetch the list of all LMS Product along with their Ids and the reason being the web service was not able to parse the XML in the result.') . "<br /><br />" . $http_result->data;
      return array();
    }
    else {
      $counter = 0;
      if (trim($doc->string) != '') {
        foreach ($doc->string as $keys => $values) {
          $master_product_id_array_from_LMS[$counter] = check_plain(trim($values));
          $counter++;
        }
      }
      if (count($master_product_id_array_from_LMS) != 0) {
        return $master_product_id_array_from_LMS;
      }
      else {
        return array();
      }
    }
  }
  else {
    fnet_ma_save_errors_to_watch_dog_and_email_to_admin($url, 'The issue occurred when the web service was trying to fetch the list of all LMS Product along with their Ids and the reason being the web service was not able to access to access the content/web service is down.');
    return array();
  }
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
// TODO: Determine if Onyx is still even relevant. Might be deprecated.
function fnet_ma_get_onyx_country_region($country_code = '', $region_code = '') {
  $sql = <<<sql
SELECT
c.onyx_country_code,
c.onyx_region_code
FROM
country_region AS c
WHERE
c.country_code = '%s' AND
c.region_code = '%s';
sql;

  $sql2 = <<<sql2
SELECT DISTINCT
c.onyx_country_code,
'' AS onyx_region_code
FROM
country_region AS c
WHERE
c.country_code = '%s'
sql2;

  // TODO Please convert this statement to the D7 database API syntax.
  $result = db_query($sql, drupal_strtoupper($country_code), drupal_strtoupper($region_code));
  if ($result) {
    $country_region = db_fetch_array($result);
    if (!is_array($country_region)) {
      // TODO Please convert this statement to the D7 database API syntax.
      $result = db_query($sql2, drupal_strtoupper($country_code));
      if ($result) {
        $country_region = db_fetch_array($result);
      }
    }
  }
  if (!is_array($country_region)) {
    $country_region = array(
      'country_code' => '',
      'region_code' => '',
    );
  }
  return $country_region;
}

/* TODO: This has been made redundant and should be replaced, preferably with user_access() and a permission.
 * https://api.drupal.org/api/drupal/modules!user!user.module/function/user_access/7.x
 *
 */
function fnet_ma_user_has_gold_role() {
  global $user;
  //Gold Member Role fetched from My Account configuration page.
  $gold_customer_role_id = variable_get('fluke_networks_gold_member_role', '');
  $user_roles = $user->roles;

  //Check if user has Gold Member role
  return array_key_exists($gold_customer_role_id, $user_roles);
}
