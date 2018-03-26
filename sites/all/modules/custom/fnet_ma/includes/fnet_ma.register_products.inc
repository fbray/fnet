<?php
/**
 * @file
 * This file is used to store the functionality that registers products using web services.
 */

/**
 * This section is related to - "Register a Product" on Fluke Networks.
 * Section starts from here and this code set is triggered on the URL - "'myaccount/register-products-step-one'"
 */

/**
 * First form/step in Register a Product Flow.
 *
 * @param $form
 * @param $form_state
 * @return mixed
 */
function fnet_ma_product_registration_form($form, $form_state) {

  // Unregistered users are redirected to the login page.
  if(user_is_anonymous()) {
    drupal_goto('/user');
  }
  drupal_add_js(drupal_get_path('module', 'fnet_ma') . '/js/fnet_ma_helper.js');

  $product_category = fnet_ma_load_product_category();

  $form['page_header'] = [
    '#value' => '<div class="my-account-headlines header-border_bottom">' . t('Register Products') . '</div>',
    '#weight' => '-50',
  ];

  $form['message'] = [
    '#type' => 'item',
    '#title' => '<b>' . t('STEP 1 OF 2: SELECT A PRODUCT CATEGORY') . '</b>',
    '#value' => '',
  ];

  $form['product_category'] = [
    '#type' => 'select',
    '#title' => t('Product Category'),
    '#options' => $product_category,
    '#required' => TRUE,
    '#default_value' => '',
    '#ajax' => [
      'event' => 'change',
      'callback' => 'fnet_ma_product_model_callback',
      'wrapper' => 'wrapper-1',
      'method' => 'replace',
    ],
  ];
  if (isset($form_state['values']['product_category'])){
    $product_category_selected = $form_state['values']['product_category'];
  }

  $product_models = [];
  if (!empty($product_category_selected)) {
    $products = fnet_sfdc_get_web_products()->data;
    $product_models = $products[$product_category_selected];
    asort($product_models);
  }
  $form['product_models'] = [
    '#type' => 'select',
    '#options' => $product_models,
    '#title' => t('Product Models'),
    '#prefix' => '<div id="wrapper-1" class = "full-available-width fn-myaccount-float-left">',
    '#suffix' => '</div>',
    '#multiple' => FALSE,
    '#required' => TRUE,
  ];

  $form['submit'] = [
    '#type' => 'submit',
    '#attributes' => ['class' => ['customfn-buttons']],
    '#weight' => 50,
    '#value' => t('GO'),
  ];
  return $form;

}

/**
 * Validation of Step One form
 *
 * @param $form
 * @param $form_state
 */
function fnet_ma_product_registration_form_validate($form, &$form_state) {
//  if (trim($form_state['values']['product_category']) == '0') {
//    form_set_error('product_category', t('Please select a Product Category.'));
//  }
//  if (trim($form_state['values']['product_models']) == '0') {
//    form_set_error('product_models', variable_get('myaccount_webservices_failure_notification_message', t('Our apologies. Your request is not currently available. A notification has been delivered to our web team to correct. If you need immediate assistance please call us at +1 425 446-4519.')));
//  }
}

/**
 * Submission of Step One form.
 *
 * @param $form
 * @param $form_state
 */
function fnet_ma_product_registration_form_submit($form, &$form_state) {
  $product_category = $form_state['values']['product_category'];
  $product_models = $form_state['values']['product_models'];
  $t2w_redirect_categories = variable_get('fnet_t2w_redirect_categories', []);
  $t2w_redirect_nodes = variable_get('fnet_t2w_redirect_nodes', []);
  if (in_array($product_category, $t2w_redirect_categories)) {
    drupal_goto('node/' . $t2w_redirect_nodes[$product_category]);
  }
  else {
    $product_category = str_replace('/', '-', $product_category);
    drupal_goto('myaccount/register-products-step-two/' . urlencode($product_category) . "/" . urlencode($product_models), [], 301);
  }
}

/**
 * Second form/step in Register a Product Flow.
 *
 * @param $form
 * @param $form_state
 * @param $category
 * @param $model
 * @return mixed
 */
// TODO: Rework this form to use the 'Add More' functionality
// https://api.drupal.org/api/examples/ajax_example%21ajax_example_graceful_degradation.inc/function/ajax_example_add_more/7.x-1.x

function fnet_ma_product_registration_form_two($form, &$form_state, $category, $model) {
  drupal_add_js(drupal_get_path('module', 'fnet_ma') . '/js/fnet_ma.js');

  $second_headline_reg_form = t("STEP 2 OF 2: Enter Serial Number(s) (a seven digit numeric code) or enter 'SOFTWARE' if registering software.");
  $key = check_plain($model);
  $form['category'] = [
    '#type' => 'value',
    '#value' => $category,
  ];
  $form['model'] = [
    '#type' => 'value',
    '#value' => $model,
  ];

  $form['product_id_registered'] = [
    '#type' => 'value',
    '#value' => check_plain($category . '/' . $model),
  ];

  $form['message_submit_form'] = [
    '#type' => 'item',
    '#value' => '<b>' . $second_headline_reg_form . "</b>",
    '#title' => '',
  ];

  $form['product_serial_number_1'] = [
    '#type' => 'textfield',
    '#title' => '1. ' . t('Product Serial Number'),
    '#required' => TRUE,
    '#default_value' => '',
    '#size' => 35,
    '#maxlength' => 8,
  ];

  $form['product_purchase_date_1'] = [
    '#type' => 'textfield',
    '#title' => t('Product Purchase Date'),
    // TODO: WTF?
    '#default_value' => variable_get('textfield', NULL),
    '#attributes' => [
      'class' => ['datepicker', 'notranslate'],
      'readonly' => 'yes',
    ],
    '#required' => TRUE,
    '#size' => 25,
  ];

  $form['message'] = [
    '#type' => 'item',
    '#title' => '<span title="' . t('This field is required.') . '" class="form-required">*</span> ' . t('Indicates a required field') . '<br /><br />' . t('Additional Products'),
    '#value' => '',
  ];

  $form['product_serial_number_2'] = [
    '#type' => 'textfield',
    '#title' => '2. ' . t('Product Serial Number'),
    '#required' => FALSE,
    '#default_value' => '',
    '#size' => 35,
    '#maxlength' => 8,
  ];

  $form['product_purchase_date_2'] = [
    '#type' => 'textfield',
    '#title' => t('Product Purchase Date'),
    '#default_value' => variable_get('textfield', NULL),
    '#attributes' => [
      'class' => ['datepicker', 'notranslate'],
      'readonly' => 'yes',
    ],
    '#required' => FALSE,
    '#size' => 25,
  ];

  $form['product_serial_number_3'] = [
    '#type' => 'textfield',
    '#title' => '3. ' . t('Product Serial Number'),
    '#required' => FALSE,
    '#default_value' => '',
    '#size' => 35,
    '#maxlength' => 8,
  ];

  $form['product_purchase_date_3'] = [
    '#type' => 'textfield',
    '#title' => t('Product Purchase Date'),
    '#default_value' => variable_get('textfield', NULL),
    '#attributes' => [
      'class' => ['datepicker', 'notranslate'],
      'readonly' => 'yes',
    ],
    '#required' => FALSE,
    '#size' => 25,
  ];

  $form['product_serial_number_4'] = [
    '#type' => 'textfield',
    '#title' => '4. ' . t('Product Serial Number'),
    '#required' => FALSE,
    '#default_value' => '',
    '#size' => 35,
    '#maxlength' => 8,
  ];

  $form['product_purchase_date_4'] = [
    '#type' => 'textfield',
    '#title' => t('Product Purchase Date'),
    '#default_value' => variable_get('textfield', NULL),
    '#attributes' => [
      'class' => ['datepicker', 'notranslate'],
      'readonly' => 'yes',
    ],
    '#required' => FALSE,
    '#size' => 25,
  ];

  $form['product_serial_number_5'] = [
    '#type' => 'textfield',
    '#title' => '5. ' . t('Product Serial Number'),
    '#required' => FALSE,
    '#default_value' => '',
    '#size' => 35,
    '#maxlength' => 8,
  ];

  $form['product_purchase_date_5'] = [
    '#type' => 'textfield',
    '#title' => t('Product Purchase Date'),
    '#default_value' => variable_get('textfield', NULL),
    '#attributes' => [
      'class' => ['datepicker', 'notranslate'],
      'readonly' => 'yes',
    ],
    '#required' => FALSE,
    '#size' => 25,
  ];

  $form['add_more_serial_no'] = [
    '#type' => 'item',
    '#title' => t('Click to add more products (optional)'),
    '#value' => '',
  ];

  $form['product_serial_number_6'] = [
    '#type' => 'textfield',
    '#title' => '6. ' . t('Product Serial Number'),
    '#required' => FALSE,
    '#default_value' => '',
    '#size' => 35,
    '#maxlength' => 8,
  ];

  $form['product_purchase_date_6'] = [
    '#type' => 'textfield',
    '#title' => t('Product Purchase Date'),
    '#default_value' => variable_get('textfield', NULL),
    '#attributes' => [
      'class' => ['datepicker', 'notranslate'],
      'readonly' => 'yes',
    ],
    '#required' => FALSE,
    '#size' => 25,
  ];

  $form['product_serial_number_7'] = [
    '#type' => 'textfield',
    '#title' => '7. ' . t('Product Serial Number'),
    '#required' => FALSE,
    '#default_value' => '',
    '#size' => 35,
    '#maxlength' => 8,
  ];

  $form['product_purchase_date_7'] = [
    '#type' => 'textfield',
    '#title' => t('Product Purchase Date'),
    '#default_value' => variable_get('textfield', NULL),
    '#attributes' => [
      'class' => ['datepicker', 'notranslate'],
      'readonly' => 'yes',
    ],
    '#required' => FALSE,
    '#size' => 25,
  ];

  $form['product_serial_number_8'] = [
    '#type' => 'textfield',
    '#title' => '8. ' . t('Product Serial Number'),
    '#required' => FALSE,
    '#default_value' => '',
    '#size' => 35,
    '#maxlength' => 8,
  ];

  $form['product_purchase_date_8'] = [
    '#type' => 'textfield',
    '#title' => t('Product Purchase Date'),
    // TODO: Replace the default value.
    '#default_value' => NULL,
    '#attributes' => [
      'class' => ['datepicker', 'notranslate'],
      'readonly' => 'yes',
    ],
    '#required' => FALSE,
    '#size' => 25,
  ];

  $form['product_serial_number_9'] = [
    '#type' => 'textfield',
    '#title' => '9. ' . t('Product Serial Number'),
    '#required' => FALSE,
    '#default_value' => '',
    '#size' => 35,
    '#maxlength' => 8,
  ];

  $form['product_purchase_date_9'] = [
    '#type' => 'textfield',
    '#title' => t('Product Purchase Date'),
    // TODO: Replace the default value.
    '#default_value' => variable_get('textfield', NULL),
    '#attributes' => [
      'class' => ['datepicker', 'notranslate'],
      'readonly' => 'yes',
    ],
    '#required' => FALSE,
    '#size' => 25,
  ];

  $form['product_serial_number_10'] = [
    '#type' => 'textfield',
    '#title' => '10. ' . t('Product Serial Number'),
    '#required' => FALSE,
    '#default_value' => '',
    '#size' => 35,
    '#maxlength' => 8,
  ];

  $form['product_purchase_date_10'] = [
    '#type' => 'textfield',
    '#title' => t('Product Purchase Date'),
    // TODO: Replace the default value.
    '#default_value' => variable_get('textfield', NULL),
    '#attributes' => [
      'class' => ['datepicker', 'notranslate'],
      'readonly' => 'yes',
    ],
    '#required' => FALSE,
    '#size' => 25,
  ];

  $form['extra_section_open_status'] = [
    '#type' => 'hidden',
    '#value' => 0,
  ];

  $form['clear_form'] = [
    '#type' => 'markup',
    '#value' => '<input type="button" id = "register-product-clear-button" value="Clear Form" class="customfn-buttons customfn-buttons-margin" />',
  ];


  $form['submit'] = [
    '#type' => 'submit',
    '#attributes' => ['class' => ['customfn-buttons']],
    '#value' => t('Save Changes'),
  ];
  return $form;
}

/**
 * Step Two form validation.
 *
 * @param $form
 * @param $form_state
 */
function fnet_ma_product_registration_form_two_validate($form, &$form_state) {
  for ($i = 1; $i <= 10; $i++) {
    if (trim($form_state['values']['product_purchase_date_' . $i]) != '' && trim($form_state['values']['product_serial_number_' . $i]) != '') {
      $product_purchase_date = check_plain($form_state['values']['product_purchase_date_' . $i]);
      $error_status = fnet_ma_evaluate_valid_dates($product_purchase_date, $i);
      $error_message = t('Invalid product purchase date for the product on line !textbox.', ['!textbox' => $error_status]);
      if ($error_status) {
        form_set_error('product_purchase_date_' . $error_status, $error_message);
      }
    }
  }

  for ($i = 1; $i <= 10; $i++) {
    if (trim($form_state['values']['product_serial_number_' . $i]) != '') {
      $product_serial_number = trim(check_plain($form_state['values']['product_serial_number_' . $i]));
      if (strtoupper($product_serial_number) == 'SOFTWARE') {
        $form_state['values']['product_serial_number_' . $i] = 'SOFTWARE';
      }
      else {
        // Check to see if any Serial Number has only the digits/numbers in it.
        if (!is_numeric($product_serial_number)) {
          // Some products contain one or two alpha characters at the beginning of the serial number.
          $pattern = '/^(H|HY)[0-9]{6,6}$/';
          if (preg_match($pattern, $product_serial_number) != 1) {
            $error_message_one = t('Please enter a valid serial number for line !textbox.', ['!textbox' => $i]);
            form_set_error('product_serial_number_' . $i, $error_message_one);
          }
        }
        else {  // The product serial number IS all numeric...
          // Check to see if any Serial Number is less than 7 digits in length.
          $product_serial_number_character_count = drupal_strlen($product_serial_number);
          if ($product_serial_number_character_count < 7) {
            //$error_message_two = t('Please enter a  valid serial number containing 7 or 8 digits only for line !textbox.', array('!textbox' => $i));
            $error_message_two = t('Please enter a  valid serial number containing 7 digits only for line !textbox.', ['!textbox' => $i]);
            form_set_error('product_serial_number_' . $i, $error_message_two);
          }
        }
      }
    }
  }

  for ($i = 1; $i <= 10; $i++) {
    if ((trim($form_state['values']['product_serial_number_' . $i]) != '' && trim($form_state['values']['product_purchase_date_' . $i]) == '')) {
      if (trim($form_state['values']['product_serial_number_' . $i]) == '') {
        $display_error_at_field = 'product_serial_number_' . $i;
      }
      else {
        $display_error_at_field = 'product_purchase_date_' . $i;
      }
      $error_message = t('You must enter both a serial number and purchase date (or neither) on line !serial_number.', ['!serial_number' => $i]);
      form_set_error($display_error_at_field, $error_message);
    }
  }
}



/**
 * Step Two form submission
 * 
 * @param $form
 * @param $form_state
 * @return null|string
 */
// TODO: Rework this form to use the 'Add More' functionality
// https://api.drupal.org/api/examples/ajax_example%21ajax_example_graceful_degradation.inc/function/ajax_example_add_more/7.x-1.x
function fnet_ma_product_registration_form_two_submit($form, &$form_state) {
  global $user;
  $model = check_plain($form_state['values']['model']);
  $total_serial_number_string = '';
  /*
  for ($i = 1; $i <= 10; $i++) {
    $serialNumber = check_plain(trim($form_state['values']['product_serial_number_' . $i]));
    $purchaseDate = check_plain(trim($form_state['values']['product_purchase_date_' . $i]));
    if ($serialNumber != '' && $purchaseDate != '') {
      $result = fnet_sfdc_register_product($user->mail, $model, $purchaseDate, $serialNumber);
      if (!$result) {
        drupal_set_message("Error registering product with serial number $serialNumber", 'error');
      }
      else {
        $total_serial_number_string .= $serialNumber . ", ";
      }
    }
  }
  */
  // Is the total serial number string blank?
  if (trim($total_serial_number_string) == '') { // TEST NOTE: Should be does not equal
    // Email the user on successful Product Registration.
    fnet_ma_send_product_registration_email_to_user();

    // Take the user to the Success Page
    drupal_goto('myaccount/product-register-success/' . $form_state['values']['product_id_registered'] . '/' . $model, [], 301);
  }
  else {
    drupal_set_message( t('Could not register the product at this time.  The site admin has been notified.'), 'error');
  }
}

/**
 * Provides a Thanks message.
 *
 * @param $category
 * @param $model
 * @return string
 */
function fnet_ma_display_product_registration_thanks_message($category, $model) {
  global $user;
  // TODO: Move this to a theming template.
  $html = '';
  $products = fnet_sfdc_get_web_products()->data;
  $product_category_selected = urldecode($category);
  $product_models = $products[$product_category_selected];
  $key = check_plain($model);

  $html .= '<br /><b>' . t('You have successfully registered the product - <i>"@product_name"</i>', ['@product_name' => $product_models[$key]]) . '</b>';
  $fn_myaccount_product_registered_thankyou_message = variable_get('fn_myaccount_product_registered_thankyou_message', t('Thank you for registering your products.'));
  $html .= '<br /><br />';
  // TODO: Set the $langcode variable?
  $html .= check_markup($fn_myaccount_product_registered_thankyou_message, NULL, $langcode = '', TRUE);
  $html .= '<br /><br />';
  $html .= t('Click to !link_to_register_again', ['!link_to_register_again' => l(t("Register more products."), 'myaccount/register-products-step-one')]);
  $html .= '<br /><br />';
  $html .= t('Click to !link_to_register_again', ['!link_to_register_again' => l(t("Create a Support Incident."), 'myaccount/report-support-incidents')]);

  return $html;
}

// Function to display the product details on a page based on asset id.
/**
 * @param string $asset_id
 * @return string
 * @throws \Exception
 */
function fnet_ma_view_registered_product_details($asset_id = '') {
  $html = '';
  global $user;
  $fetch_product_details = fnet_ma_get_asset_details($asset_id);
  if ($fetch_product_details['status'] == 'error') {
    return $html .= "<span class = 'red-text'>" . $fetch_product_details['message'] . "</span><br />";
  }

  $html .= '<div class="my-account-headlines header-border_bottom">' . check_plain($fetch_product_details['message']->vchDescription) . '</div>';
  $html .= '<b>' . t('Serial Number: ') . '</b>' . check_plain($fetch_product_details['message']->vchSerialNumber) . "<br /><br />";
  $insert_date_time = explode("T", check_plain($fetch_product_details['message']->dtPurchaseDate));
  $insert_date_time = explode("-", $insert_date_time[0]);
  $final_insert_date_time_value = $insert_date_time[1] . '/' . $insert_date_time[2] . '/' . $insert_date_time[0];
  $html .= '<b>' . t('Registration Date: ') . '</b>' . $final_insert_date_time_value . "<br /><br />";
  if (check_plain($fetch_product_details['message']->iHierarchyId) == '2244' || check_plain($fetch_product_details['message']->iHierarchyId) == '2254' || check_plain($fetch_product_details['message']->iHierarchyId) == '2473') {
    $html .= '<b>' . t('Registration Code: ') . '</b><span class = "red-text">' . "965w35" . "</span><br /><br />";
  }
  elseif (check_plain($fetch_product_details['message']->iHierarchyId) == '2548') {
    $html .= '<b>' . t('Registration Code: ') . '</b><span class = "red-text">' . "4487302238822187" . "</span><br /><br />";
  }
  elseif (check_plain($fetch_product_details['message']->chProductNumber) == 'wbOPV-Options008') {
    $html .= '<b>' . t('Registration Code: ') . '</b><span class = "red-text">' . "4487302238822187" . "</span><br /><br />";
  }

  $html .= '<b>' . t('Model: ') . '</b>' . check_plain($fetch_product_details['message']->vchDescription) . "<br /><br />";

  $html .= "<div class = 'full-available-width'>
              <div id = 'support-incident-summary-section-expanding-master-key-div' Onclick=\"return toggle_sections('support-incident-summary-section');\" class='my-account-headlines my-account-header-minus-background'>" . t('Support Incidents') . "</div>
            </div>";

  $support_incidents = fnet_ma_fetch_support_incidents(30, $asset_id);
  $support_incidents_html = theme("tabular_support_incident_display", ['support_incidents' => $support_incidents]);
  $html .= "<div id = 'support-incident-summary-section'>" . $support_incidents_html . "</div>";

  // Get the list of all products configured in LMS.
  $lms_product_ID_array = fnet_ma_fetch_LMS_product_ids();
  if (count($lms_product_ID_array) != 0) {
    if (in_array(check_plain(trim($fetch_product_details['message']->chProductNumber)), $lms_product_ID_array)) {
      $previously_enabled_options = fnet_ma_fetch_previously_enabled_options(check_plain(trim($fetch_product_details['message']->vchDescription)), check_plain(trim($fetch_product_details['message']->vchSerialNumber)), 'product_detail_page', check_plain(trim($fetch_product_details['message']->chProductNumber)));
      $html .= '<br />';

      $html .= "<div class = 'full-available-width'>
                    <div id = 'downloads-and-updates-summary-section-expanding-master-key-div' Onclick=\"return toggle_sections('downloads-and-updates-summary-section');\" class='my-account-headlines my-account-header-minus-background'>" . t('Previously Enabled Options') . "</div>
                  </div>";
      $html .= "<div id = 'downloads-and-updates-summary-section'>" . $previously_enabled_options . "</div>";

      $html .= '<br />';
    }
  }

  $html .= '<div style="float:right;">' . l('See all registered products...', 'myaccount/registered-products') . '</div>';
  //$html .=  t('!link to remove products from your list.', array("!link" => l('Contact us', "wheretobuy", array('attributes' => array("target" => "_blank"), 'html' => TRUE, 'query' => array('tab' => '2')))));
  $support_incident_link = '<div style="float:left;">' . t('Please Submit a  !link if you don\'t see a your key code or <br />no longer own this product', ['!link' => l('New Support Incident', 'myaccount/product-support-incidents/' . $asset_id)]) . "</div>";
  $html .= $support_incident_link;
  return $html;
}
