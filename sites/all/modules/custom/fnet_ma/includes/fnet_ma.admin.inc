<?php
// $Id: fnet_ma.admin.inc 25 2015-03-31 20:12:49Z sogden1 $

define('NUMBER_OF_T2W_REDIRECT_CATEGORIES', 10);

/**
 * @file
 * My Account administration and module settings UI.
 */

/**
 * Admin configuration form for Fluke Networks website's - "My Account" functionality is build here.
 * This code set is triggered on the URL - "admin/config/fluke_networks_myaccount".
 */
function fnet_ma_admin_settings($form, &$form_state) {

  $form = array();

  $form['admin_page_header'] = array(
    '#value' => '<h2 class="with-tabs">My Account Configurations</h2>',
  );

  // Configurations related to Web Services.
  $form['fluke_networks_webservices_related_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configurations related to Web Services'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['fluke_networks_webservices_related_fieldset']['myaccount_webservices_domain_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Domain of the web services'),
    '#default_value' => variable_get('myaccount_webservices_domain_name', 'http://services.test.intranet.danahertm.com'),
    '#description' => t("Enter the domain name for web services.  Please don't include trailing slashes. <br />(e.g., 'http://services.fluke.com')."),
    '#required' => TRUE,
  );

  $form['fluke_networks_webservices_related_fieldset']['myaccount_soap_connection_timeout'] = array(
    '#type' => 'textfield',
    '#title' => 'SOAP connection timeout',
    '#default_value' => variable_get('myaccount_soap_connection_timeout', 20),
    '#description' => 'SOAP connection timeout (in seconds)',
    '#required' => TRUE,
  );

  $form['fluke_networks_webservices_related_fieldset']['fluke_networks_myaccount_fnet_base_URL'] = array(
    '#type' => 'textfield',
    '#title' => t('Base URL of FNET file download link'),
    '#default_value' => variable_get('fluke_networks_myaccount_fnet_base_URL', 'http://myaccount.flukenetworks.com/FNet/'),
    '#description' => t("Enter the Base URL of FNET file download link. <br />(e.g., 'http://myaccount.flukenetworks.com/FNet/')."),
    '#required' => TRUE,
  );

  $form['fluke_networks_webservices_related_fieldset']['myaccount_webservices_failure_notification_email_address'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the email address to whom the notification emails would be send in case of Web Service failures'),
    '#default_value' => variable_get('myaccount_webservices_failure_notification_email_address', 'example@flukenetworks.com'),
    '#description' => "<div class = 'red-text'>" . t("Enter email addresses separated with commas only.") . "</div>",
    '#required' => TRUE,
    '#maxlength' => 500,
  );

  $form['fluke_networks_webservices_related_fieldset']['myaccount_webservices_failure_notification_message'] = array(
    '#type' => 'textarea',
    '#title' => t("Enter the text content to be displayed on the top of any page/form when ever a Web Service failure occurs"),
    '#default_value' => variable_get('myaccount_webservices_failure_notification_message', t('Our apologies. Your request is not currently available. A notification has been delivered to our web team to correct. If you need immediate assistance please call us at +1 425 446-4519.')),
    '#description' => t("Enter the content to display on any page/form, when the web service in action fails due to any reason and fails to deliver the required results to the logged in user."),
  );

  $form['fluke_networks_webservices_related_fieldset']['myaccount_pager_count'] = array(
    '#type' => 'select',
    '#title' => t('Number of rows per page on listing pages'),
    '#default_value' => variable_get('myaccount_pager_count', 20),
    '#description' => t("Enter the number of rows you want displayed per page on the listing pages (i.e. support incidents, gold contracts etc). "),
    '#required' => TRUE,
    '#options' => array(
      '5' => '5',
      '10' => '10',
      '15' => '15',
      '20' => '20',
      '25' => '25',
      '30' => '30',
      '50' => '50',
      '100' => '100',
      '150' => '150',
      '200' => '200',
    ),
  );

  $form['fluke_networks_webservices_related_fieldset']['fnet_ma_dtx_product_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the Product CODE for DTX Model for the website (DEV, TEST or PROD Tier)'),
    '#default_value' => variable_get('fnet_ma_dtx_product_code', '0003'),
    '#description' => t("This configuration is to support data differences in the Test and Dev environments. "),
    '#required' => TRUE,
  );

  $form['fluke_networks_webservices_related_fieldset']['fnet_ma_dsx_product_code'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the Product CODE for DSX Model for the website (DEV, TEST or PROD Tier)'),
    '#default_value' => variable_get('fnet_ma_dsx_product_code', '0004'),
    '#description' => t("This configuration is to support data differences in the Test and Dev environments. "),
    '#required' => TRUE,
  );

  // Configurations related to User's Content Profile.
  $form['fluke_networks_users_content_profile_related_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configurations related to User\'s Content Profile.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  //Fetch all the content types on the website and display it in drop down list.
  $node_types_array = array();
  $node_types = node_type_get_types();
  if (count($node_types)) {
    foreach ($node_types as $content_machine_readable_name => $content_human_readable_name) {
      $node_types_array[$content_machine_readable_name] = $content_human_readable_name->name;
    }
  }

  $form['fluke_networks_users_content_profile_related_fieldset']['profile_content_type'] = array(
    '#type' => 'select',
    '#multiple' => FALSE,
    '#title' => t('Select the content type used as profile content'),
    '#default_value' => variable_get('profile_content_type', 'profile'),
    '#options' => $node_types_array,
    '#description' => t(''),
    '#required' => TRUE,
  );

  $fluke_networks_user_roles = user_roles($membersonly = TRUE, $permission = NULL);
  $form['fluke_networks_users_content_profile_related_fieldset']['fluke_networks_gold_member_role'] = array(
    '#type' => 'select',
    '#title' => t("Select the role which is considered to be the role of \"Gold Customer\" for \"My Account\" related functionality"),
    '#default_value' => variable_get('fluke_networks_gold_member_role', array()),
    '#options' => $fluke_networks_user_roles,
    '#required' => TRUE,
  );

  $form['fluke_networks_users_content_profile_related_fieldset']['fluke_networks_non_gold_member_role'] = array(
    '#type' => 'select',
    '#title' => t("Select the role which is considered to be the role of \"NON Gold Customer\" for \"My Account\" related functionality"),
    '#default_value' => variable_get('fluke_networks_non_gold_member_role', array()),
    '#options' => $fluke_networks_user_roles,
    '#required' => TRUE,
  );

  $form['fluke_networks_users_content_profile_related_fieldset']['fnet_ma_user_login_page_notification_message'] = array(
    '#type' => 'textarea',
    '#title' => t("Text content to be displayed on the top of Login page/form"),
    '#default_value' => variable_get('fnet_ma_user_login_page_notification_message', ''),
    '#description' => t("Enter the content to display to the top of Login page/form, this content section is added to the top of the login page so that Content Team can put a migration message at the top and change it when most users have reset their password. If the message is completely deleted, then resaving the configuration form would hide that section on top of 'Login page'."),
  );


  // Configurations related to different Static Contents displayed on the website.
  $form['fluke_networks_static_contents_related_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configurations related to different Static Contents displayed on the website'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['fluke_networks_static_contents_related_fieldset']['fnet_ma_download_and_updates_text'] = array(
    '#type' => 'textarea',
    '#title' => t("Text to display in 'Download and Updates' section of My Account Summary page"),
    '#default_value' => variable_get('fnet_ma_download_and_updates_text', t('Click on the "Download & Updates link to view all the Assets that you can download."')),
    '#description' => t("Enter the content to display to the user on 'Download and Updates' section of My Account Summary page."),
    '#required' => TRUE,
  );

  $form['fluke_networks_static_contents_related_fieldset']['user_registration_thankyou_page_content'] = array(
    '#type' => 'textarea',
    '#title' => t("Text to display on the user registration thank-you page"),
    '#default_value' => variable_get('user_registration_thankyou_page_content', t('Thank you for registering on Fluke Networks website.')),
    '#description' => t("Enter the thank-you message to display to the user after completing the registration process successfully."),
    '#required' => TRUE,
  );

  $form['fluke_networks_static_contents_related_fieldset']['users_myaccount_page_static_content'] = array(
    '#type' => 'textarea',
    '#title' => t("Text to display on the top section of user's my account page, i.e. after the Welcome [User's First-Name header]"),
    '#default_value' => variable_get('users_myaccount_page_static_content', t('Welcome to Fluke Networks!!!')),
    '#description' => t("Enter the text content to display to user on the top section of their My Account page once they log-in on Fluke Networks website."),
    '#required' => TRUE,
  );

  $form['fluke_networks_static_contents_related_fieldset']['fn_myaccount_product_registered_thankyou_message'] = array(
    '#type' => 'textarea',
    '#title' => t("Content thats displayed on the Product Registration status page after user submits the Product Registration form"),
    '#default_value' => variable_get('fn_myaccount_product_registered_thankyou_message', t('Thank you for registering your products.')),
    '#required' => TRUE,
  );

  $form['fluke_networks_static_contents_related_fieldset']['myaccount_thankyou_message_support_incident'] = array(
    '#type' => 'textarea',
    '#title' => t("Text to display on the Support Incident's thank-you page"),
    '#default_value' => variable_get('myaccount_thankyou_message_support_incident', t('Thank you for posting the support incident.')),
    '#description' => t("Enter the thank-you message to display after successful submission of a support incident. "),
    '#required' => TRUE,
  );

  $form['fluke_networks_static_contents_related_fieldset']['myaccount_registered_products_page_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Text to display on the top of Registered Product Listing page'),
    '#default_value' => variable_get('myaccount_registered_products_page_text', t('Registering your products enables you to create support incidents. You will need to have the serial number (Or enter SOFTWARE if registering software) and the purchase date of the product.')),
    '#description' => t("Enter the text to display on the top of Registered Product Listing page, this may contain the steps to help user registering the products on Fluke Networks."),
    '#required' => TRUE,
  );

  $form['fluke_networks_static_contents_related_fieldset']['myaccount_support_incidents_page_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Text to display on the top of the Support Incidents Listing page'),
    '#default_value' => variable_get('myaccount_support_incidents_page_text', t('You must register a product before opening a support incident for it. Then select the product for the support incident. You can come back at a later time to see updates to the incident.')),
    '#description' => t("Enter the text to display on the top of Support Incidents Listing page, this may contain the steps to help user with posting support incidents for the products they have registered on Fluke Networks."),
    '#required' => TRUE,
  );

  $form['fluke_networks_static_contents_related_fieldset']['myaccount_download_and_updates_page_text'] = array(
    '#type' => 'textarea',
    '#title' => t('Text to display on the top of the Download & Updates Listing page'),
    '#default_value' => variable_get('myaccount_download_and_updates_page_text', t('This is page introduction for Non-Gold User')),
    '#description' => t("Enter the text to display on the top of Download & Updates Listing page Listing page, this may contain some help for user to understand the flow and results displayed on the page."),
    '#required' => TRUE,
  );

  $form['fluke_networks_static_contents_related_fieldset']['fn_myaccount_support_incident_header_text'] = array(
    '#type' => 'textarea',
    '#title' => t("Content thats displayed on the top of Support Incident form as a header"),
    '#default_value' => variable_get('fn_myaccount_support_incident_header_text', t('DESCRIBE YOUR PROBLEM OR ENTER A QUESTION: ')),
    '#required' => TRUE,
  );

  // Configurations related to different links that points to various static pages on the website.
  $form['fluke_networks_static_links_related_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configurations related to different links that points to various static pages on the website'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['fluke_networks_static_links_related_fieldset']['fn_myaccount_learn_more_about_the_benefits_of_creating_an_account'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the Node ID of the page that links to - "<i>Learn more about the benefits of creating an account</i>." on user log-in page'),
    '#default_value' => variable_get('fn_myaccount_learn_more_about_the_benefits_of_creating_an_account', ''),
  );

  $form['fluke_networks_static_links_related_fieldset']['fn_myaccount_learn_more_about_the_benefits_of_gold_Support'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the Node ID of the page that links to - "<i>Learn more about the benefits of Gold Support</i>." on user log-in page'),
    '#default_value' => variable_get('fn_myaccount_learn_more_about_the_benefits_of_gold_Support', ''),
  );

  /*
   $form['fluke_networks_static_links_related_fieldset']['fn_myaccount_email_privacy_policy'] = array(
   '#type' => 'textfield',
   '#title' => t('Enter the Node ID of the page that links to - "<i>Email privacy policy</i>." on user registration page'),
   '#default_value' => variable_get('fn_myaccount_email_privacy_policy', ''),
   );
   */

  $form['fluke_networks_static_links_related_fieldset']['fn_myaccount_gold_credentials_learn_more'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the Node ID of the page that links to - "<i>(Learn More)</i>." related to Gold Crendentials on user registration page'),
    '#default_value' => variable_get('fn_myaccount_gold_credentials_learn_more', ''),
  );

  $form['fluke_networks_static_links_related_fieldset']['fn_myaccount_gold_credentials_terms_and_condition'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the Node ID of the page that links to - "<i>Terms and Conditions</i>." on user registration page'),
    '#default_value' => variable_get('fn_myaccount_gold_credentials_terms_and_condition', ''),
  );

  $form['fluke_networks_static_links_related_fieldset']['fn_myaccount_wtf_location_of_serial_numbers'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the Node ID of the page that links to - "<i>How to find the Serial Number</i>." on Product Registration page'),
    '#default_value' => variable_get('fn_myaccount_wtf_location_of_serial_numbers', ''),
  );

  $form['fluke_networks_static_links_related_fieldset']['fn_myaccount_accessing_your_gold_benefits'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the Node ID of the page that links to - "<i>Accessing your Gold Benefits</i>." from the My Account navigation block'),
    '#default_value' => variable_get('fn_myaccount_accessing_your_gold_benefits', ''),
  );

  $form['fluke_networks_static_links_related_fieldset']['fn_myaccount_analysis_service_element'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the Node ID of the page that links to - "<i>Analysis Service Element (ASE)</i>." from the My Account navigation block'),
    '#default_value' => variable_get('fn_myaccount_analysis_service_element', ''),
  );

  $form['fluke_networks_static_links_related_fieldset']['fn_myaccount_gold_support_contact_numbers'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the Node ID of the page that links to - "<i>Gold Support Contact Numbers</i>." from the My Account navigation block'),
    '#default_value' => variable_get('fn_myaccount_gold_support_contact_numbers', ''),
  );

  // Configurations related to Web Services process flow that is used for Gold type POP code or Activate an option.
  $form['fluke_networks_gold_type_pop_code_related_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configurations related to "Activate an option" with Gold Type POP codes'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['fluke_networks_gold_type_pop_code_related_fieldset']['fnet_ma_gold_contract_admin_in_US'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the Email ID of Gold Contract Admin in US'),
    '#default_value' => variable_get('fnet_ma_gold_contract_admin_in_US', 'example@flukenetworks.com'),
    '#required' => TRUE,
    '#maxlength' => 500,
    '#description' => t('If a logged in user, making a gold contract request, has selected "US" or "USA" from the country dropdown box, then system sends an email to "US" Gold contract admin to activate this Gold Contract Request.') . "<div class = 'red-text'>" . t("Enter email addresses separated with commas only.") . "</div>",
  );

  $form['fluke_networks_gold_type_pop_code_related_fieldset']['fnet_ma_gold_contract_admin_in_INT'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the Email ID of Gold Contract Admin in NON US Country or INT'),
    '#default_value' => variable_get('fnet_ma_gold_contract_admin_in_INT', 'example@flukenetworks.com'),
    '#required' => TRUE,
    '#maxlength' => 500,
    '#description' => t('If a logged in user, making a gold contract request, has selected options other than "US" or "USA" from the country dropdown box, then system sends an email to "INT" Gold contract admin to activate this Gold Contract Request.') . "<div class = 'red-text'>" . t("Enter email addresses separated with commas only.") . "</div>",
  );

  $form['fluke_networks_gold_type_pop_code_related_fieldset']['fnet_ma_gold_contract_admin_in_JAPAN'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the Email ID of Gold Contract Admin in JAPAN'),
    '#default_value' => variable_get('fnet_ma_gold_contract_admin_in_JAPAN', 'example@flukenetworks.com'),
    '#required' => TRUE,
    '#maxlength' => 500,
    '#description' => t('If a logged in user, making a gold contract request, has selected option - "Japan" from the country dropdown box, then system sends an email to "Japanese" Gold contract admin to activate this Gold Contract Request.') . "<div class = 'red-text'>" . t("Enter email addresses separated with commas only.") . "</div>",
  );

  $form['fluke_networks_gold_type_pop_code_related_fieldset']['fnet_ma_gold_type_pop_code_email_subject_for_admin'] = array(
    '#type' => 'textfield',
    '#title' => t('Enter the "Subject" of email that is sent to Gold Contract Admin on Fluke Networks when a logged in user applies with a Gold type POP code for Product/Option Activation'),
    '#default_value' => variable_get('fnet_ma_gold_type_pop_code_email_subject_for_admin', 'Fluke Networks: Gold Contract Activation Request - Country:'),
    '#required' => TRUE,
    '#description' => t("Enter the Subject of the Email. The Country Code will be automatically added at the end of this subject line, so the Subject would be some thing like - 'Fluke Networks: Gold Contract Activation Request - Country: US' if the user selects 'United States' from country drop down.."),
  );

  $form['fluke_networks_gold_type_pop_code_related_fieldset']['fnet_ma_gold_type_pop_code_email_content_for_admin'] = array(
    '#type' => 'textarea',
    '#title' => t('Enter the "Content" of email that is sent to Gold Contract Admin on Fluke Networks when a logged in user applies with a Gold type POP code for Product/Option Activation:'),
    '#default_value' => variable_get('fnet_ma_gold_type_pop_code_email_content_for_admin', t('A Gold Pop Code request has been received from the web. Please process this request from the LMS System.')),
    '#description' => t("Enter the Content of the Email, this content would be displayed on the top of the email which would be followed by all the Profile Information supplied by the user in a table format below."),
    '#required' => TRUE,
  );

  $form['fluke_networks_gold_type_pop_code_related_fieldset']['fnet_ma_gold_type_pop_code_success_status_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Enter the message that\'s displayed to the logged in user when the system successfully saves gold contract related profile information values they have submitted'),
    '#default_value' => variable_get('fnet_ma_gold_type_pop_code_success_status_message', t("Your request has been sent to Gold Contract Administrator, Thanks.")),
    '#required' => TRUE,
  );

  $form['fluke_networks_gold_type_pop_code_related_fieldset']['fnet_ma_gold_type_pop_code_page_introduction'] = array(
    '#type' => 'textarea',
    '#title' => t('Enter the text that\'s displayed to the logged in user on the Gold Type POP code related profile information form'),
    '#default_value' => variable_get('fnet_ma_gold_type_pop_code_page_introduction', t("Please verify your Gold Contract information. The person listed below will receive all Gold benefit notification for this Gold Contract.")),
    '#required' => TRUE,
  );

  // Configurations related to displaying the Custom Error messages on Login page and Reset password page.
  $form['fluke_networks_custom_error_messages_fieldset'] = array(
    '#type' => 'fieldset',
    '#title' => t('Configurations for displaying the Custom Error messages on "Login page" and "Reset password" page.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['fluke_networks_custom_error_messages_fieldset']['fnet_ma_custom_login_page_error_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Enter the text that\'s displayed to the user when they enter a in-correct combination of Email ID/Password on the Login page, if you leave this text area empty then the default error message would be displayed to that user.'),
    '#default_value' => variable_get('fnet_ma_custom_login_page_error_message', t("Our apologies. We have recently migrated our customer accounts to a new system and need to have you reset your password. Please select 'Forgot Password' to begin that process.")),
  );

  $form['fluke_networks_custom_error_messages_fieldset']['fnet_ma_custom_reset_password_page_error_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Enter the text that\'s displayed to the user when they enter a in-correct Email ID on the Forgot password page, if you leave this text area empty then the default error message would be displayed to that user.'),
    '#default_value' => variable_get('fnet_ma_custom_reset_password_page_error_message', t("Our apologies. We have recently migrated our customer accounts to a new system and need to have you reregister with your email address. Please select 'create account' to begin that process.")),
  );

  return system_settings_form($form);
}

/**
 * @param $form
 * @param $form_state
 * @return array
 */
function fnet_ma_t2w_redirect_settings_form($form, &$form_state) {
  $form = array();

  $products = fnet_sfdc_get_web_products()->data;
  $options = array_keys($products);
  asort($options);
  $categories[0] = '';
  $categories += drupal_map_assoc($options);
  $redirect_categories = variable_get('fnet_t2w_redirect_categories', array());
  $redirect_nodes = variable_get('fnet_t2w_redirect_nodes', array());
  $message = '<h2>Tool to Web redirects</h2>';
  $message .= '<p>When a user attempts to register a product in any of the categories listed below, they will be ';
  $message .= 'redirected to the node coresponding to the category.</p>';

  $form['message'] = array(
    '#value' => $message,
  );

  for ($i = 0; $i < NUMBER_OF_T2W_REDIRECT_CATEGORIES; $i++) {
    $form["category_$i"] = array(
      '#type' => 'fieldset',
      '#title' => 'Category ' . ($i + 1),
      '#collapsible' => FALSE,
    );
    $form["category_$i"]["redirect_category_$i"] = array(
      '#type' => 'select',
      '#title' => "Product Category",
      '#default_value' => $redirect_categories[$i],
      '#options' => $categories,
    );
    $form["category_$i"]["redirect_node_$i"] = array(
      '#type' => 'textfield',
      '#title' => 'Node # of redirect page',
      '#size' => '10',
      '#default_value' => $redirect_nodes[$redirect_categories[$i]],
    );
  }
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  return $form;
}

/**
 * @param $form
 * @param $form_state
 */
function fnet_ma_t2w_redirect_settings_form_submit($form, &$form_state) {
  $redirect_categories = array();
  $redirect_nodes = array();
  for ($i = 0; $i < NUMBER_OF_T2W_REDIRECT_CATEGORIES; $i++) {
    $redirect_categories[] = $form_state['values']["redirect_category_$i"];
    $redirect_nodes[$form_state['values']["redirect_category_$i"]] = $form_state['values']["redirect_node_$i"];
  }
  variable_set('fnet_t2w_redirect_categories', $redirect_categories);
  variable_set('fnet_t2w_redirect_nodes', $redirect_nodes);
  drupal_set_message(t('The configuration options have been saved.'));
}
