<?php
// $Id$

/**
 * @file
 * This section related to - "Download and Updates" on Fluke Networks starts here.
 * Section starts from here and this code set is triggered on the URL - "'myaccount/all-downloads-updates'"
 */

/**
 * @param $form
 * @param $form_state
 * @return array
 * @throws \Exception
 */
function fnet_ma_downloads_and_updates_form($form, $form_state) {
  $form = array();

  if (check_plain(trim(arg(3))) != '') {
    $product_id = check_plain(trim(arg(3)));
  }
  $download_and_updates = fnet_ma_fetch_product_list_related_to_download_updates();
  if ($download_and_updates['-1'] != 'webservice_exception_error') {
    $form['download_and_updates_product_list'] = array(
      '#type' => 'select',
      '#title' => t('Select a registered product'),
      '#options' => $download_and_updates,
      '#required' => TRUE,
      '#default_value' => $product_id,
      '#post_render' => array('fnet_ma_process_text'),
    );
    $form['flukecal_wtb_submit_button'] = array(
      '#markup' => '<input type = "button" name = "Go" value = "GO" class = "customfn-buttons" id = "flukenetworks-submit-button" style="display: inline-block !important;"/>',
      '#suffix' => '<div id="loading-bar-image" style="float: right;margin-right:10px;margin-top:6px;display:none;">' . theme('image', array(
          'path' => drupal_get_path("module", "fnet_ma") . '/images/loadingbar2.gif',
          'width' => '',
          'height' => '',
          'alt' => '',
          'title' => '',
          'attributes' => array()
        )) . t(' Please wait...') . '</div>',
    );
    return $form;
  }
  else {
    $form['webservice_exception_error_message'] = array(
      '#type' => 'item',
      '#markup' => '<span class = "red-text">' . variable_get('myaccount_webservices_failure_notification_message', t('Our apologies. Your request is not currently available. A notification has been delivered to our web team to correct. If you need immediate assistance please call us at +1 425 446-4519.')) . "</span>",
    );
    return $form;
  }
}

/**
 * @param $element
 * @param $children
 * @return string
 */
function fnet_ma_process_text($element, $children) {
  $src_strs = array('&lt;sup&gt;TM&lt;/sup&gt;', '&#0153;');
  $rep_strs = array('&trade;', '&trade;');
  return html_entity_decode(str_replace($src_strs, $rep_strs, $element));
}

/**
 * Function to populate the Drop down that user sees on the top of "Download and Updates" page.
 */
function fnet_ma_fetch_product_list_related_to_download_updates() {
  global $user;
  $gold_number = check_plain(trim($user->field_user_gold_number[LANGUAGE_NONE][0]['value']));
  $gold_pin = check_plain(trim($user->field_user_gold_pin[LANGUAGE_NONE][0]['value']));
  $products = fnet_sfdc_get_download_category_ids($user->mail, $gold_number, $gold_pin);
  $table = array();
  foreach ($products as $product => $details) {
    $row = new stdClass();
    $row->ProductId = $product;
    $row->ProductName = $details['description'];
    $table[$product] = $row;
  }
  $total_registered_product = count($table);
  if ($total_registered_product) {
    $registered_product_list = array();
    foreach ($table as $key => $value) {
      $registered_product_list[trim($value->ProductId)] = trim(htmlentities($value->ProductName, ENT_QUOTES, 'UTF-8'));
    }
  }
  else {
    $registered_product_list = array(' - No Registered Products were found. - ');
  }
  return $registered_product_list;
}

/**
 * @return string
 */
function fnet_ma_display_all_user_download_and_updates() {
  drupal_add_js(drupal_get_path('module', 'fnet_ma') . '/js/fnet_ma_helper.js');
  $form = drupal_get_form('fnet_ma_downloads_and_updates_form');
  $output = '';
  $text = variable_get('myaccount_download_and_updates_page_text', t('This is page introduction for Non-Gold User'));
  $output .= '<div class="posRel">
                  <div class="dvValid" id="helping-instruction-support-incidents-listing-page">
                    <div class="cnt">' . t("Click to expand and view content.") . '</div>
                  </div>
                </div>

                <div id = "all-support-incidents-listing-section-expanding-master-key-div" Onclick="return toggle_sections(\'all-support-incidents-listing-section\');" class=\'my-account-headlines my-account-header-minus-background\'>' . t('Downloads and Updates') . '
                </div>

                <div id = \'all-support-incidents-listing-section\' class=\'listing-page-helper-section\'>' . check_markup($text, FILTER_FORMAT_DEFAULT, $langcode = '' /* TODO Set this variable. */, TRUE) . '</div>

                <div id= \'download-and-updates-search-form\'>' . drupal_render($form) . '</div>';

  $output .= "<div id='gold_support_section_wrapper' style='margin-top:10px'>";
  $output .= theme("all_download_and_updates_display", array('download_and_updates_array' => NULL));
  $output .= "</div>";
  return $output;
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function fnet_ma_get_downloads_ajax($category) {
  global $user;
  if ($user->uid == '' || $user->uid == '0') {
    drupal_goto('user', array(), 301);
  }

  if (check_plain(trim($category)) == '' || (!is_numeric(check_plain(trim($category))))) {
    return array();
  }

  if (check_plain(trim($category)) == '-1') {
    $error_message = '<span class = "red-text">' . t("Please select a registered product from the list before you click 'Go' button.") . "</span>";
    $final_HTML_result = fnet_ma_print_download_update_messages($error_message);
    header('Content-type: application/json');
    echo json_encode(array(
      'status' => 'no_product_selected',
      'data' => $final_HTML_result
    ));
    exit();
  }

  //Check the current language of the website.
  $siteReg = module_invoke('fnet_helper', 'site_region');
  $language = $siteReg["lang"];
  $table = array();
  $pcat_id = check_plain(trim($category));
  $asset_types = array('product software', 'product software release notes');
  $assets = digital_asset_list_by_product($pcat_id, $language, $asset_types);
  foreach ($assets->Asset as $asset) {
    $row = new stdClass();
    $row->OracleID = $asset->AssetID;
    $row->AssetName = $asset->AssetTitle;
    $row->Description = $asset->AssetDescription;
    $row->PID = 0;
    $row->FileSize = $asset->FileSize;
    $row->ImageAccessLevel = $asset->Locked == 'True' ? '/fnet_www/images/lock.gif' : '/fnet_www/images/unlock.gif';
    $table[] = $row;
  }
  $content_array = array();
  $total_items_in_content_array = count($table);
  if ($total_items_in_content_array) {
    $counter = 0;
    foreach ($table as $key => $values) {
      $content_array[$counter]['OracleID'] = check_plain(trim($values->OracleID));
      $content_array[$counter]['AssetName'] = check_plain(trim($values->AssetName));
      $content_array[$counter]['Description'] = check_plain(trim($values->Description));
      $content_array[$counter]['PID'] = check_plain(trim($values->PID));
      $content_array[$counter]['FileSize'] = check_plain(trim($values->FileSize));
      $content_array[$counter]['ImageAccessLevel'] = check_plain(trim($values->ImageAccessLevel));
      $content_array[$counter]['FNET_URL'] = l('Download', 'findit/' . check_plain(trim($values->OracleID)), array(
          'html' => TRUE,
          'attributes' => array('target' => '_blank'),
        )) . "<br />";
      $counter++;
    }
    $final_HTML_result = theme("all_download_and_updates_display", array('download_and_updates_array' => $content_array));
    header('Content-type: application/json');
    echo json_encode(array(
      'status' => 'download_and_updates_found',
      'data' => $final_HTML_result,
    ));
    exit();

  }
  else {
    // No content found as per the criteria.
    $final_HTML_result = fnet_ma_print_download_update_messages(t('No records to display.'));
    header('Content-type: application/json');
    echo json_encode(array(
      'status' => 'no_download_and_updates_found',
      'data' => $final_HTML_result
    ));
    exit();
  }
  //return $content_array;
}

// Generic Function for printing the "Download and Updates" layout.
/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function fnet_ma_print_download_update_messages($message = '') {
  $complete_message = '';
  $complete_message = "<div class='data_divs'>
                      <table style = 'display:table;width:100%' border=\"0\" cellspacing=\"5\" cellpadding=\"5\">
                        <tr style = 'display:table;width:100%'>
                          <td valign=\"top\" class='tableHead' width=\"70%\">
                            " . t('Title') . "
                          </td>
                          <td valign=\"top\" class='tableHead' width=\"20%\">" . t('Download <br /> Options') . "
                          </td>
                          <td valign=\"top\" class='tableHead' width=\"10%\">

                            </td>
                        </tr>
                        <tr style = 'display:table;width:100%'>
                          <td valign=\"top\" colspan='3'>" . $message . "</td>
                        </tr>
                      </table>
                    </div>";
  return $complete_message;
}
