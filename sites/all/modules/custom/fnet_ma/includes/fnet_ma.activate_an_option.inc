<?php
// $Id: fnet_ma.activate_an_option.inc 98 2015-05-26 19:58:17Z sogden1 $

/**
 * @file
 * This section is related to - "Activate a Product/Option" on Fluke Networks.
 * Section starts from here and this code set is triggered on the URL - "'myaccount/activate-product'"
 */

/**
 * Activate an option
 * @param $form
 * @param $form_state
 * @return array
 */
function fnet_ma_product_activation_form($form, $form_state) {
  global $user;

  drupal_add_js(drupal_get_path('module', 'fnet_ma') . '/js/fnet_ma_helper.js');
  $form = array();
  $current_form_array = $_REQUEST;
  $page_reference = trim(check_plain($current_form_array['reference']));
  $current_step_for_activate_product_process = check_plain($current_form_array['step']);

  // FORM NO - 1
  if ($current_step_for_activate_product_process == '') {
    $form['page_header'] = array(
      '#markup' => '<div class="my-account-headlines header-border_bottom">' . t('Activate a Purchased Option') . '</div>',
      '#weight' => '-50',
    );

    $form['message'] = array(
      '#markup' => t('This page will guide you through the process for activating your Fluke Networks product or option. Please enter your Proof of Purchase Code below and click Submit to continue.') . "<br />",
    );

    $form['proof_of_purchase_code'] = array(
      '#type' => 'textfield',
      '#title' => t('Enter a Proof of Purchase Code'),
      '#required' => TRUE,
      '#default_value' => '',
      '#suffix' => '<span class = "red-text">' . t('* Option codes are 16 numeric characters') . '</span><br /><br />',
      '#size' => 26,
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#attributes' => array('class' => array('customfn-buttons')),
      '#weight' => 50,
      '#value' => t('Submit'),
    );
  }

  // FORM NO - 2
  if ($current_step_for_activate_product_process == 'two') {
    $ProductCode = trim(check_plain($current_form_array['ProductCode']));
    $OptionCode = trim(check_plain($current_form_array['OptionCode']));
    $POP_code = trim(check_plain($current_form_array['POPcode']));

    if ($ProductCode == '' || $OptionCode == '' || $POP_code == '') {
      $form['message'] = array(
        '#markup' => "<span class = 'red-text'>" . t('The requested page could not be found.') . "</span><br />",
      );
      return $form;
    }

    if ($POP_code != '') {
      if (!(preg_match("/^([1]-)?[0-9]{4}-[0-9]{4}-[0-9]{4}-[0-9]{4}$/i", $POP_code))) {
        $form['message'] = array(
          '#markup' => "<span class = 'red-text'>" . t('Invalid POP code, please try again.') . "</span><br />",
        );
        return $form;
      }
    }

    if ($POP_code != '') {
      $proof_of_purchase_code_status = fnet_ma_validate_proof_of_purchase_code($POP_code);
      if ($proof_of_purchase_code_status['status'] != 'POP_code_is_valid') {
        $form['message'] = array(
          '#markup' => "<span class = 'red-text'>" . t('The POP code is in-valid, please try again.') . "</span><br />",
        );
        return $form;
      }
    }

    $product_info_fetched_from_POP_code = fnet_ma_fetch_product_information_based_on_POPcode($ProductCode, $OptionCode);
    if ($product_info_fetched_from_POP_code['-1'] == 'webservice_exception_error') {
      $form['message'] = array(
        '#markup' => "<span class = 'red-text'>" . variable_get('myaccount_webservices_failure_notification_message', t('Our apologies. Your request is not currently available. A notification has been delivered to our web team to correct. If you need immediate assistance please call us at +1 425 446-4519.')) . '</div>',
      );
      return $form;
    }

    if (count($product_info_fetched_from_POP_code) == 0) {
      $form['message'] = array(
        '#markup' => t('Invalid arguments provided.(1)'),
      );
      return $form;
    }

    $form['page_header'] = array(
      '#markup' => '<div class="my-account-headlines header-border_bottom">' . t('Activate a Purchased Option') . '</div>',
      '#weight' => '-50',
    );

    $form['message'] = array(
      '#markup' => t('Please review the information below to ensure the Proof of Purchase Code entered corresponds with the product/option you wish to activate. If the information is correct, click Submit. If this is not the product/option you wish to activate, please enter a different Proof of Purchase Code for the correct product/option.') . "<br /><br />",
    );

    $form['page_start'] = array(
      '#markup' => '<div class="margin-left-50px">',
    );

    $form['product_section_header_message'] = array(
      '#markup' => '<div class="my-account-headlines">' . check_plain($product_info_fetched_from_POP_code->vchHierarchyDesc) . '</div>',
    );

    $form['static_product_group_name'] = array(
      '#type' => 'item',
      '#title' => '',
      '#markup' => '<b>' . t('Product Group') . ': </b>' . check_plain($product_info_fetched_from_POP_code->productGroupName),
    );

    $form['static_product_options_to_enable'] = array(
      '#type' => 'item',
      '#title' => '',
      '#markup' => '<b>' . t('Option to Enable') . ': </b>' . check_plain($product_info_fetched_from_POP_code->optionname),
    );

    $form['static_product_pop_code'] = array(
      '#type' => 'item',
      '#title' => '',
      '#markup' => '<b>' . t('Proof of Purchase Code') . ': </b>' . $POP_code,
    );

    $form['hidden_ProductGroupCode'] = array(
      '#type' => 'value',
      '#value' => check_plain($product_info_fetched_from_POP_code->ProductGroupCode),
    );

    $form['hidden_proof_of_purchase_code'] = array(
      '#type' => 'value',
      '#value' => $POP_code,
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#attributes' => array('class' => array('customfn-buttons')),
      '#weight' => 50,
      '#value' => t('Submit'),
    );

    $form['page_end'] = array(
      '#markup' => '</div>',
    );
  }

  // FORM NO - 3
  elseif ($current_step_for_activate_product_process == 'three') {
    if (trim(check_plain($current_form_array['POPcode'])) == '') {
      $form['message'] = array(
        '#markup' => "<span class = 'red-text'>" . t('The requested page could not be found.') . "</span><br />",
      );
      return $form;
    }

    if (trim(check_plain($current_form_array['POPcode'])) != '') {
      if (!(preg_match("/^([1]-)?[0-9]{4}-[0-9]{4}-[0-9]{4}-[0-9]{4}$/i", trim(check_plain($current_form_array['POPcode']))))) {
        $form['message'] = array(
          '#markup' => "<span class = 'red-text'>" . t('Invalid POP code, please try again.') . "</span><br />",
        );
        return $form;
      }
    }

    $proof_of_purchase_code = trim(check_plain($current_form_array['POPcode']));
    $product_group_details = fnet_ma_validate_proof_of_purchase_code($proof_of_purchase_code);
    if ($product_group_details['status'] == 'POP_code_is_valid') {
      $product_info_fetched_from_POP_code = fnet_ma_fetch_product_information_based_on_POPcode($product_group_details['productCodeField'], $product_group_details['optionCodeField']);

      $form['page_header'] = array(
        '#markup' => '<div class="my-account-headlines header-border_bottom">' . t('Register a Product for Option Activation') . '</div>',
        '#weight' => '-50',
      );

      $form['message'] = array(
        '#markup' => t('Please enter the Serial Number from your product and the purchase date. Click Submit. WARNING -Verify that the Serial Number entered matches the one on your product. If it does not, the Key Code generated to activate the option on your product will not work.') . "<br /><br />",
      );

      $form['page_start'] = array(
        '#markup' => '<div class = "margin-left-50px">',
      );

      $form['product_section_header_message'] = array(
        '#markup' => '<div class="my-account-headlines">' . check_plain($product_info_fetched_from_POP_code->productGroupName) . '</div>',
      );

      $fetch_product_model = fnet_ma_fetch_product_model($product_group_details['productCodeField'], $proof_of_purchase_code);
      if ($fetch_product_model['-1'] == 'webservice_exception_error') {
        $form['message'] = array(
          '#markup' => "<span class = 'red-text'>" . variable_get('myaccount_webservices_failure_notification_message', t('Our apologies. Your request is not currently available. A notification has been delivered to our web team to correct. If you need immediate assistance please call us at +1 425 446-4519.')) . "</span><br />",
        );
        return $form;
      }

      $form['product_model'] = array(
        '#type' => 'select',
        '#title' => t('Model'),
        '#options' => array('-1' => ' - Select Product Model - ') + $fetch_product_model,
        '#required' => TRUE,
        '#default_value' => '',
      );

      $form['product_serial_number'] = array(
        '#type' => 'textfield',
        '#title' => t('Serial Number'),
        '#default_value' => '',
        '#maxlength' => 7,
        '#required' => TRUE,
        '#size' => 25,
      );

      $form['product_purchase_date'] = array(
        '#type' => 'textfield',
        '#title' => t('Purchase Date'),
        '#default_value' => variable_get('textfield', NULL),
        '#attributes' => array(
          'class' => 'datepicker notranslate',
          'readonly' => 'yes',
        ),
        '#required' => TRUE,
        '#size' => 25,
      );

      $form['submit'] = array(
        '#type' => 'submit',
        '#attributes' => array('class' => array('customfn-buttons')),
        '#prefix' => '<div id = "fn-myaccount-pro-act-form-three">',
        '#suffix' => '</div>',
        '#weight' => 50,
        '#value' => t('Submit'),
      );

      $form['page_end'] = array(
        '#markup' => '</div>',
      );

    }
    else {
      $form['message'] = array(
        '#markup' => "<span class = 'red-text'>" . variable_get('myaccount_webservices_failure_notification_message', t('Our apologies. Your request is not currently available. A notification has been delivered to our web team to correct. If you need immediate assistance please call us at +1 425 446-4519.')) . "</span><br />",
      );
    }
  }

  // FORM NO - 4
  elseif ($current_step_for_activate_product_process == 'four') {

    $proof_of_purchase_code = trim(check_plain($current_form_array['POPcode']));
    $ocp = trim(check_plain($current_form_array['ocp']));
    $serialNumber = trim(check_plain($current_form_array['serialNumber']));
    $model_number = trim(check_plain($current_form_array['model-number']));
    //if ($ocp == '' || $serialNumber == '' || $model_number == '') {
    if ($ocp == '' || $model_number == '') {
      $form['message'] = array(
        '#markup' => "<span class = 'red-text'>" . t('Invalid arguments provided.(2)') . "</span><br />",
      );
      return $form;
    }

    if ($page_reference != 'product-detail-page') {
      if ($proof_of_purchase_code != '') {
        $product_group_details = fnet_ma_validate_proof_of_purchase_code($proof_of_purchase_code);
        // If the POP code is provided in the URL and the POP code is NOT valid then display error message and return the form.
        if ($product_group_details['status'] == 'error_in_operations') {
          $form['message'] = array(
            '#markup' => "<span class = 'red-text'>" . variable_get('myaccount_webservices_failure_notification_message', t('Our apologies. Your request is not currently available. A notification has been delivered to our web team to correct. If you need immediate assistance please call us at +1 425 446-4519.')) . "</span><br />",
          );
          return $form;
        }
        elseif ($product_group_details['status'] != 'POP_code_is_valid') {
          $form['message'] = array(
            '#markup' => "<span class = 'red-text'>" . t('The POP code is in-valid, please try again.') . "</span><br />",
          );
          return $form;
        }
        $fetch_product_model = fnet_ma_fetch_product_model($product_group_details['productCodeField'], $proof_of_purchase_code);
        if ($fetch_product_model['-1'] == 'webservice_exception_error') {
          $form['message'] = array(
            '#markup' => "<span class = 'red-text'>" . variable_get('myaccount_webservices_failure_notification_message', t('Our apologies. Your request is not currently available. A notification has been delivered to our web team to correct. If you need immediate assistance please call us at +1 425 446-4519.')) . "</span><br />",
          );
          return $form;
        }

        $product_info_fetched_from_POP_code = fnet_ma_fetch_product_information_based_on_POPcode($product_group_details['productCodeField'], $product_group_details['optionCodeField']);

        $form['page_title_main'] = array(
          '#markup' => '<div class="my-account-headlines activate-a-purchased-option">' . t('Activate a Purchased Option') . '</div>',
          '#weight' => '-50',
        );

        $form['page_header_one'] = array(
          '#markup' => '<div class="my-account-headlines">' . $fetch_product_model[check_plain($current_form_array['model-number'])] . t(' Options') . '</div>',
          '#weight' => '-49',
        );

        $form['message_one'] = array(
          '#markup' => '<div class="header-border_bottom">' . t('The @product_name selected has the following options enabled:', array('@product_name' => $fetch_product_model[check_plain($current_form_array['model-number'])])) . '<br /></div>',
          '#weight' => '-48',
        );

        $form['static_product_name'] = array(
          '#type' => 'item',
          '#title' => '',
          '#prefix' => '<div class = "fn-myaccount-product-details-section">',
          '#markup' => '<b>' . t('Product') . '</b><br />' . $fetch_product_model[check_plain($current_form_array['model-number'])],
        );

        $form['static_model_name'] = array(
          '#type' => 'item',
          '#title' => '',
          '#markup' => '<b>' . t('Model') . '</b><br />' . check_plain($product_info_fetched_from_POP_code->vchHierarchyDesc),
        );

        $previously_enabled_options = fnet_ma_fetch_previously_enabled_options($fetch_product_model[check_plain($current_form_array['model-number'])], check_plain($current_form_array['serialNumber']));

        $form['static_serial_number'] = array(
          '#type' => 'item',
          '#title' => '',
          '#markup' => '<b>' . t('Serial Number') . '</b><br />' . $serialNumber,
          '#suffix' => '</div><div class = "fn-myaccount-previously-enabled-options-section">' . $previously_enabled_options . "<br /><br /><div class = 'fn-myaccount-float-right'>" . l(t("Details for ") . $fetch_product_model[check_plain($current_form_array['model-number'])], "myaccount/view-registered-product/" . $ocp, array(
              'html' => TRUE,
              'attributes' => array('class' => '')
            )) . "</div></div>",
        );
      }
      else {
        /**
         * If the POP code is not provided in the URL this means we are coming
         * to the fourth step/form of "Activate an option" flow from the Registered Product Listing page
         * in this case just fetch the details related to the specific product in action by another
         * web service which is - "GetCustomerProduct".
         */
        $fetch_product_details = array();
        $fetch_product_details = fnet_ma_get_asset_details($ocp);
        if ($fetch_product_details['status'] == 'error') {
          $form['error_message'] = array(
            '#markup' => "<span class = 'red-text'>" . $fetch_product_details['message'] . "</span><br />",
          );
          return $form;
        }

        $form['page_title_main'] = array(
          '#markup' => '<div class="my-account-headlines activate-a-purchased-option">' . t('Activate a Purchased Option') . '</div>',
          '#weight' => '-50',
        );

        $form['page_header_one'] = array(
          '#markup' => '<div class="my-account-headlines">' . check_plain($fetch_product_details['message']->vchDescription) . t(' Options') . '</div>',
          '#weight' => '-49',
        );

        $form['message_one'] = array(
          '#markup' => '<div class="header-border_bottom">' . t('The @product_name selected has the following options enabled:', array('@product_name' => check_plain($fetch_product_details['message']->vchDescription))) . '<br /></div>',
          '#weight' => '-48',
        );

        $form['static_product_name'] = array(
          '#type' => 'item',
          '#title' => '',
          '#prefix' => '<div class = "fn-myaccount-product-details-section">',
          '#markup' => '<b>' . t('Product') . '</b><br />' . check_plain($fetch_product_details['message']->vchDescription),
          '#weight' => '-47',
        );

        $form['static_model_name'] = array(
          '#type' => 'item',
          '#title' => '',
          '#weight' => '-46',
          '#markup' => '<b>' . t('Model') . '</b><br />' . check_plain($fetch_product_details['message']->vchHierarchyDesc),
        );

        $previously_enabled_options = fnet_ma_fetch_previously_enabled_options(check_plain($fetch_product_details['message']->vchDescription), check_plain($current_form_array['serialNumber']));

        $form['static_serial_number'] = array(
          '#type' => 'item',
          '#title' => '',
          '#weight' => '-45',
          '#markup' => '<b>' . t('Serial Number') . '</b><br />' . $serialNumber,
          '#suffix' => '</div><div class = "fn-myaccount-previously-enabled-options-section">' . $previously_enabled_options . "<br /><br /><div class = 'fn-myaccount-float-right'>" . l(t("Details for ") . check_plain($fetch_product_details['message']->vchDescription), "myaccount/view-registered-product/" . $ocp, array(
              'html' => TRUE,
              'attributes' => array('class' => '')
            )) . "</div></div>",
        );
      }

      $form['static_ruler_one'] = array(
        '#type' => 'item',
        '#title' => '',
        '#markup' => '<div class="ruler-bar" id = "fn-myaccount-static-ruler-one">&nbsp;</div>',
      );
    }

    if ($page_reference == 'product-detail-page') {
      $form['page_header'] = array(
        '#markup' => '<div class="my-account-headlines header-border_bottom">' . t('Add a previously enabled Key Code') . '</div>',
        '#weight' => '-50',
      );

      $form['message_two'] = array(
        '#markup' => '<div class="">' . t('If you activated a Key Code for this product before our online activation process was available, you can add it now. First, enter the Key Code or Serial Number, as indicated below. Next, enter the Proof of Purchase Code for the option and click Submit. Your Key Code and option should appear in the list of options registered for your product. ') . "<br /><br /><span class = 'red-text'>" . t('WARNING') . "</span>" . t(' - Please verify that the Serial Number entered matches the one on your product. If it does not, the Key Code generated to activate the option on your product will not work. ') . '<br /></div>',
      );
    }
    else {
      $form['page_header_two'] = array(
        '#markup' => '<div class = "fn-myaccount-float-left"><div class="my-account-headlines">' . t('Generate a new Key Code') . '</div>',
      );

      $form['message_two'] = array(
        '#markup' => '<div class="">' . "<span class = 'red-text'>" . t('WARNING') . "</span>" . t(' - Submitting a Proof of Purchase code will generate a Key Code that can be used to activate an option on the selected product. Verify the Serial Number entered matches the serial number on the product. If it does not, the Key Code generated will not work.') . '<br /></div>',
      );
    }

    if ($serialNumber == '') {
      $form['product_serial_number_one'] = array(
        '#type' => 'textfield',
        '#title' => t('Enter the Serial Number'),
        '#default_value' => '',
        '#maxlength' => 7,
        '#required' => TRUE,
        '#size' => 40,
      );
    }
    else {
      $form['product_serial_number_one'] = array(
        '#type' => 'textfield',
        '#title' => t('Enter the Serial Number'),
        '#default_value' => '',
        '#maxlength' => 7,
        '#required' => TRUE,
        '#value' => $serialNumber,
        '#size' => 40,
        '#disabled' => TRUE,
      );
    }

    if ($serialNumber == '') {
      $form['product_serial_number_two'] = array(
        '#type' => 'textfield',
        '#title' => t('Re-enter the Serial Number'),
        '#default_value' => '',
        '#maxlength' => 7,
        '#required' => TRUE,
        '#size' => 40,
      );
    }
    else {
      $form['product_serial_number_two'] = array(
        '#type' => 'textfield',
        '#title' => t('Re-enter the Serial Number'),
        '#default_value' => '',
        '#maxlength' => 7,
        '#required' => TRUE,
        '#value' => $serialNumber,
        '#size' => 40,
        '#disabled' => TRUE,
      );
    }

    $form['popcode_one'] = array(
      '#type' => 'textfield',
      '#title' => t('Enter the Proof of Purchase Code'),
      '#required' => TRUE,
      '#default_value' => check_plain(trim($current_form_array['POPcode'])),
      '#size' => 40,
    );

    $form['popcode_two'] = array(
      '#type' => 'textfield',
      '#title' => t('Re-enter the Proof of Purchase Code'),
      '#required' => TRUE,
      '#default_value' => check_plain(trim($current_form_array['POPcode'])),
      '#size' => 40,
    );

    $form['message_three'] = array(
      '#markup' => '<div>' . "<span class = 'red-text'>" . t('*') . "</span>" . t(' Indicates Required Fields') . '<br /></div>',
    );

    $form['hidden_ocp'] = array(
      '#type' => 'value',
      '#value' => check_plain($current_form_array['ocp']),
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#attributes' => array('class' => array('customfn-buttons')),
      '#weight' => 49,
      '#value' => t('Submit'),
    );

    $form['static_ruler_two'] = array(
      '#type' => 'item',
      '#title' => '',
      '#weight' => 50,
      '#markup' => '<div class="ruler-bar" id = "fn-myaccount-static-ruler-two">&nbsp;</div></div>',
    );


    unset($form['product_serial_number_one']);
    unset($form['product_serial_number_two']);
    unset($form['popcode_one']);
    unset($form['popcode_two']);
    unset($form['message_three']);
    unset($form['static_ruler_two']);
    unset($form['submit']);
    unset($form['page_title_main']);
    unset($form['page_header']);
    unset($form['page_header_two']);
    unset($form['message_two']);
  }
  // FORM NO - 5
  elseif ($current_step_for_activate_product_process == 'five') {
    global $user;
    $proof_of_purchase_code = trim(check_plain($current_form_array['POPcode']));
    $ocp = trim(check_plain($current_form_array['ocp']));
    $serialNumber = trim(check_plain($current_form_array['serialNumber']));
    $model_number = trim(check_plain($current_form_array['model-number']));
    $CDKey = trim(check_plain($current_form_array['CDKey']));

    if ($proof_of_purchase_code == '' || $ocp == '' || $serialNumber == '' || $model_number == '' || $CDKey == '') {
      $form['message'] = array(
        '#markup' => t('Invalid arguments provided.(3)'),
      );
      return $form;
    }

    $product_group_details = fnet_ma_validate_proof_of_purchase_code($proof_of_purchase_code);
    if ($product_group_details['status'] == 'pop_code_already_used') {
      $product_info_fetched_from_POP_code = fnet_ma_fetch_product_information_based_on_POPcode($product_group_details['productCodeField'], $product_group_details['optionCodeField']);

      $form['page_header_one'] = array(
        '#markup' => '<div class="my-account-headlines">' . t('Activate a Purchased Option') . '</div>',
        '#weight' => '-50',
      );

      $form['message_one'] = array(
        '#markup' => '<div class="header-border_bottom">' . t('Confirmation Page: Your Key Code has been generated successfully.  Links to print a certificate are located below. ') . '</div><br />',
      );

      $fetch_product_model = fnet_ma_fetch_product_model($product_group_details['productCodeField'], $proof_of_purchase_code);
      if ($fetch_product_model['-1'] == 'webservice_exception_error') {
        $form['message'] = array(
          //'#markup' => "<span class = 'red-text'>". t('Error in fetching Product Models details, please try again later, Thanks.') ."</span><br />",
          '#markup' => "<span class = 'red-text'>" . variable_get('myaccount_webservices_failure_notification_message', t('Our apologies. Your request is not currently available. A notification has been delivered to our web team to correct. If you need immediate assistance please call us at +1 425 446-4519.')) . "</span><br />",
        );
        return $form;
      }

      $form['static_product_name'] = array(
        '#type' => 'item',
        '#title' => '',
        '#prefix' => '<div class = "fn-myaccount-product-details-section">',
        '#markup' => '<b>' . t('Product') . '</b><br />' . $fetch_product_model[check_plain($current_form_array['model-number'])],
      );

      $form['static_model_name'] = array(
        '#type' => 'item',
        '#title' => '',
        '#markup' => '<b>' . t('Model') . '</b><br />' . check_plain($product_info_fetched_from_POP_code->vchHierarchyDesc),
      );


      $previously_enabled_options = fnet_ma_fetch_previously_enabled_options($fetch_product_model[check_plain($current_form_array['model-number'])], check_plain($current_form_array['serialNumber']));
      $form['static_serial_number'] = array(
        '#type' => 'item',
        '#title' => '',
        '#markup' => '<b>' . t('Serial Number') . '</b><br />' . check_plain($current_form_array['serialNumber']),
        '#suffix' => '</div><div class = "fn-myaccount-previously-enabled-options-section">' . $previously_enabled_options . "</div>",
      );

      $form['static_ruler_one'] = array(
        '#type' => 'item',
        '#title' => '',
        '#markup' => '<div class="ruler-bar" id = "fn-myaccount-static-ruler-one">&nbsp;</div>',
      );

      $form['page_header_two'] = array(
        '#markup' => '<div class="my-account-headlines fn-myaccount-activate-options-header-text">' . t('Activation Key Code Created for <br />@item_name', array('@item_name' => $fetch_product_model[check_plain($current_form_array['model-number'])])) . '</div>',
      );

      $form['message_two'] = array(
        '#markup' => '<div id = "fn-myaccount-aao-print-cdkey">' . trim(check_plain($current_form_array['CDKey'])) . '</div>',
      );

      $key_code_printing_URL = 'myaccount/print-keycode/';

      $individualid = check_plain($user->field_user_onyx_id[LANGUAGE_NONE][0]['value']);
      $model_number = check_plain($_GET['model-number']);
      $serialNumber = check_plain($_GET['serialNumber']);
      $fetch_already_enabled_options = fnet_ma_get_enabled_options_for_product($individualid, $model_number, $serialNumber, 'specific');
      if (count($fetch_already_enabled_options)) {
        if ($fetch_already_enabled_options['status'] == 'fetched_valid_enabled_options') {
          $form['static_links'] = array(
            '#markup' => '
                        <div id = "fn-myaccount-aao-print-static-links">
                        <span style="margin-right:50px">' . l('Return To My Products', 'myaccount/registered-products') . '</span>' . l('Print Product Activation Certificate', $key_code_printing_URL, array(
                'attributes' => array("target" => "_blank"),
                'html' => TRUE,
                'query' => 'enabled-options=' . urlencode($fetch_already_enabled_options['OptionCodeName']) . '&activation-date=' . urlencode($fetch_already_enabled_options['dtInsertDateTime']) . '&key-code=' . urlencode(str_replace("-", "", trim(check_plain($current_form_array['CDKey'])))) . '&product-name=' . urlencode(check_plain($fetch_product_model[check_plain($current_form_array['model-number'])])) . '&serialnumber=' . urlencode(check_plain($current_form_array['serialNumber']))
              )) . '</div>',
          );
        }
      }

      $form['static_ruler_two'] = array(
        '#type' => 'item',
        '#title' => '',
        '#markup' => '<div class = "ruler-bar" id = "fn-myaccount-static-ruler-two">&nbsp;</div>',
      );

    }
    else {
      $form['message'] = array(
        '#markup' => t('The Pop code is either in-valid or its already used, please try again.'),
      );
      return $form;
    }
  }

  // FORM with Product listing as per the Product Group.
  elseif ($current_step_for_activate_product_process == 'ProductGroup') {

    $ProductCode = trim(check_plain($current_form_array['ProductCode']));
    $OptionCode = trim(check_plain($current_form_array['OptionCode']));
    $POP_code = trim(check_plain($current_form_array['POPcode']));
    $opn = trim(check_plain($current_form_array['opn']));

    if ($ProductCode == '' || $OptionCode == '' || $POP_code == '' || $opn == '') {
      $form['message'] = array(
        '#markup' => "<span class = 'red-text'>" . t('The requested page could not be found.') . "</span><br />",
      );
      return $form;
    }

    if ($POP_code != '') {
      if (!(preg_match("/^([1]-)?[0-9]{4}-[0-9]{4}-[0-9]{4}-[0-9]{4}$/i", $POP_code))) {
        $form['message'] = array(
          '#markup' => "<span class = 'red-text'>" . t('Invalid POP code, please try again.') . "</span><br />",
        );
        return $form;
      }
    }

    if ($POP_code != '') {
      $proof_of_purchase_code_status = fnet_ma_validate_proof_of_purchase_code($POP_code);
      if ($proof_of_purchase_code_status['status'] != 'POP_code_is_valid') {
        $form['message'] = array(
          '#markup' => "<span class = 'red-text'>" . t('The POP code is in-valid, please try again.') . "</span><br />",
        );
        return $form;
      }
    }

    $productnumber = $opn;
    $master_array_already_registered_products = fnet_ma_registered_products_in_product_group($productnumber);

    $form['header_link_to_product_listing_page'] = array(
      '#weight' => '-50',
      '#markup' => l('Registered Products', "myaccount/registered-products", array(
          'html' => TRUE,
          'attributes' => array('class' => '')
        )) . "<br /><br />",
    );

    if ($master_array_already_registered_products['status'] == 'success') {

      $form['page_header'] = array(
        '#markup' => '<div class="my-account-headlines header-border_bottom">' . $master_array_already_registered_products['header_title'] . '</div>',
        '#weight' => '-49',
      );

      $form['message'] = array(
        '#weight' => '-48',
        '#markup' => t('The site has identified that you have one or more products registered. Find the Serial Number for the product corresponding to the option you wish to activate and click the Activate an Option link. If you do not see the Serial Number below, click the \'Activate an option for a unit with a different serial number\' link to register your product and continue the option activation process. ') . "<br /><br />",
      );

      $query = array(
        'step' => 'three',
        'POPcode' => $POP_code,
      );
      $url_to_add = "<br />" . l("Activate an option for a unit with a different serial number.", "myaccount/activate-product", $options = array('query' => $query));
      $form['html_of_already_registered_products_within_group'] = array(
        '#weight' => '-47',
        '#markup' => $master_array_already_registered_products['message'] . $url_to_add,
      );
    }
    elseif ($master_array_already_registered_products['status'] == 'error') {
      $form['html_of_already_registered_products_within_group'] = array(
        '#weight' => '-47',
        '#markup' => $master_array_already_registered_products['message'],
      );
    }
    else {
      $form['html_of_already_registered_products_within_group'] = array(
        '#weight' => '-47',
        '#markup' => "<span class = 'red-text'>" . variable_get('myaccount_webservices_failure_notification_message', t('Our apologies. Your request is not currently available. A notification has been delivered to our web team to correct. If you need immediate assistance please call us at +1 425 446-4519.')) . "</span><br />",
      );
    }

  }

  // Validation : Validate POP code just before generating a new key code.
  // System Response: For any other validation error(status code=800), system displays localized message as per below:
  elseif ($current_step_for_activate_product_process == 'popcode-validation-error' || $current_step_for_activate_product_process == 'duplicate-serial-number-error') {
    $proof_of_purchase_code = trim(check_plain($current_form_array['POPcode']));
    $ocp = trim(check_plain($current_form_array['ocp']));
    $serialNumber = trim(check_plain($current_form_array['serialNumber']));
    $model_number = trim(check_plain($current_form_array['model-number']));
    //if ($ocp == '' || $serialNumber == '' || $model_number == '') {
    if ($ocp == '' || $model_number == '') {
      $form['message'] = array(
        '#markup' => "<span class = 'red-text'>" . t('Invalid arguments provided.(4)') . "</span><br />",
      );
      return $form;
    }

    if ($proof_of_purchase_code != '') {
      $product_group_details = fnet_ma_validate_proof_of_purchase_code($proof_of_purchase_code);
      // If the POP code is provided in the URL and the POP code is NOT valid then display error message and return the form.
      if ($product_group_details['status'] == 'error_in_operations') {
        $form['message'] = array(
          '#markup' => "<span class = 'red-text'>" . variable_get('myaccount_webservices_failure_notification_message', t('Our apologies. Your request is not currently available. A notification has been delivered to our web team to correct. If you need immediate assistance please call us at +1 425 446-4519.')) . "</span><br />",
        );
        return $form;
      }
      elseif ($product_group_details['status'] != 'POP_code_is_valid') {
        $form['message'] = array(
          '#markup' => "<span class = 'red-text'>" . t('The POP code is in-valid, please try again.') . "</span><br />",
        );
        return $form;
      }

      $fetch_product_model = fnet_ma_fetch_product_model($product_group_details['productCodeField'], $proof_of_purchase_code);
      if ($fetch_product_model['-1'] == 'webservice_exception_error') {
        $form['message'] = array(
          //'#markup' => "<span class = 'red-text'>". t('Error in fetching Product Models details, please try again later, Thanks.') ."</span><br />",
          '#markup' => "<span class = 'red-text'>" . variable_get('myaccount_webservices_failure_notification_message', t('Our apologies. Your request is not currently available. A notification has been delivered to our web team to correct. If you need immediate assistance please call us at +1 425 446-4519.')) . "</span><br />",
        );
        return $form;
      }

      $product_info_fetched_from_POP_code = fnet_ma_fetch_product_information_based_on_POPcode($product_group_details['productCodeField'], $product_group_details['optionCodeField']);

      $form['page_title_main'] = array(
        '#markup' => '<div class="my-account-headlines activate-a-purchased-option">' . t('Activate a Purchased Option') . '</div>',
        '#weight' => '-50',
      );

      $form['page_header_one'] = array(
        '#markup' => '<div class="my-account-headlines">' . $fetch_product_model[check_plain($current_form_array['model-number'])] . t(' Options') . '</div>',
        '#weight' => '-49',
      );

      $form['message_one'] = array(
        '#markup' => '<div class="header-border_bottom">' . t('The @product_name selected has the following options enabled:', array('@product_name' => $fetch_product_model[check_plain($current_form_array['model-number'])])) . '<br /></div>',
        '#weight' => '-48',
      );

      $form['static_product_name'] = array(
        '#type' => 'item',
        '#title' => '',
        '#prefix' => '<div class = "fn-myaccount-product-details-section">',
        '#markup' => '<b>' . t('Product') . '</b><br />' . $fetch_product_model[check_plain($current_form_array['model-number'])],
      );

      $form['static_model_name'] = array(
        '#type' => 'item',
        '#title' => '',
        '#markup' => '<b>' . t('Model') . '</b><br />' . check_plain($product_info_fetched_from_POP_code->vchHierarchyDesc),
      );

      $previously_enabled_options = fnet_ma_fetch_previously_enabled_options($fetch_product_model[check_plain($current_form_array['model-number'])], check_plain($current_form_array['serialNumber']));

      $form['static_serial_number'] = array(
        '#type' => 'item',
        '#title' => '',
        '#markup' => '<b>' . t('Serial Number') . '</b><br />' . $serialNumber,
        '#suffix' => '</div><div class = "fn-myaccount-previously-enabled-options-section">' . $previously_enabled_options . "<br /><br /><div class = 'fn-myaccount-float-right'>" . l(t("Details for ") . $fetch_product_model[check_plain($current_form_array['model-number'])], "myaccount/view-registered-product/" . $ocp, array(
            'html' => TRUE,
            'attributes' => array('class' => '')
          )) . "</div></div>",
      );
    }
    else {
      /**
       * If the POP code is not provided in the URL this means we are coming
       * to the fourth step/form of "Activate an option" flow from the Registered Product Listing page
       * in this case just fetch the details related to the specific product in action by another
       * web service which is - "GetCustomerProduct".
       */
      $fetch_product_details = array();
      $fetch_product_details = fnet_ma_get_asset_details($ocp);
      if ($fetch_product_details['status'] == 'error') {
        $form['error_message'] = array(
          '#markup' => "<span class = 'red-text'>" . $fetch_product_details['message'] . "</span><br />",
        );
        return $form;
      }

      $form['page_title_main'] = array(
        '#markup' => '<div class="my-account-headlines activate-a-purchased-option">' . t('Activate a Purchased Option') . '</div>',
        '#weight' => '-50',
      );

      $form['page_header_one'] = array(
        '#markup' => '<div class="my-account-headlines">' . check_plain($fetch_product_details['message']->vchDescription) . t(' Options') . '</div>',
        '#weight' => '-49',
      );

      $form['message_one'] = array(
        '#markup' => '<div class="header-border_bottom">' . t('The @product_name selected has the following options enabled:', array('@product_name' => check_plain($fetch_product_details['message']->vchDescription))) . '<br /></div>',
        '#weight' => '-48',
      );

      $form['static_product_name'] = array(
        '#type' => 'item',
        '#title' => '',
        '#prefix' => '<div class = "fn-myaccount-product-details-section">',
        '#markup' => '<b>' . t('Product') . '</b><br />' . check_plain($fetch_product_details['message']->vchDescription),
        '#weight' => '-47',
      );

      $form['static_model_name'] = array(
        '#type' => 'item',
        '#title' => '',
        '#weight' => '-46',
        '#markup' => '<b>' . t('Model') . '</b><br />' . check_plain($fetch_product_details['message']->vchHierarchyDesc),
      );

      $previously_enabled_options = fnet_ma_fetch_previously_enabled_options(check_plain($fetch_product_details['message']->vchDescription), check_plain($current_form_array['serialNumber']));

      $form['static_serial_number'] = array(
        '#type' => 'item',
        '#title' => '',
        '#weight' => '-45',
        '#markup' => '<b>' . t('Serial Number') . '</b><br />' . $serialNumber,
        '#suffix' => '</div><div class = "fn-myaccount-previously-enabled-options-section">' . $previously_enabled_options . "<br /><br /><div class = 'fn-myaccount-float-right'>" . l(t("Details for ") . check_plain($fetch_product_details['message']->vchDescription), "myaccount/view-registered-product/" . $ocp, array(
            'html' => TRUE,
            'attributes' => array('class' => '')
          )) . "</div></div>",
      );
    }

    if ($current_step_for_activate_product_process == 'popcode-validation-error') {
      $form['static_ruler_one'] = array(
        '#type' => 'item',
        '#title' => '',
        '#weight' => '-44',
        '#markup' => '<div class="ruler-bar" id = "fn-myaccount-static-ruler-one">&nbsp;</div>',
      );

      $form['page_header_two'] = array(
        '#markup' => '<div class = "fn-myaccount-float-left"><div class="my-account-headlines">' . t('Error in Generating a new Key Code') . '</div>',
        '#weight' => '-43',
      );

      $form['message_one'] = array(
        '#weight' => '-42',
        '#markup' => "<div class=''><span class = 'red-text'><b>" . t('The Proof of Purchase Code entered is not valid for the selected product.') . "</b></span></div>",
      );

      $form['message_two'] = array(
        '#weight' => '-40',
        '#markup' => fnet_ma_display_activate_error_800_links() . "</div>",
      );
    }
    elseif ($current_step_for_activate_product_process == 'duplicate-serial-number-error') {
      $form['static_ruler_one'] = array(
        '#type' => 'item',
        '#title' => '',
        '#weight' => '10',
        '#markup' => '<div class="ruler-bar" id = "fn-myaccount-static-ruler-one">&nbsp;</div>',
      );

      $form['page_header_two'] = array(
        '#markup' => '<div class = "fn-myaccount-float-left"><div class="my-account-headlines red-text">' . t('Duplicate Serial Number Found') . '</div>',
        '#weight' => '15',
      );

      $form['message_one'] = array(
        '#weight' => '20',
        '#markup' => "<div class=''><span>" . t('Warning: This Serial Number is registered to two or more people. Please verify that the Serial Number entered matches the Serial Number on the product for which you are activating this option.') . "</span></div>",
      );

      $form['message_two'] = array(
        '#weight' => '25',
        '#markup' => fnet_ma_display_activate_error_700_links() . "</div>",
      );
    }
    return $form;
  } // elseif ($current_step_for_activate_product_process == 'popcode-validation-error') { ....

  // Validation: Validate serial number is registered by other user of product group.
  // System Response: For duplicate serial number(status code=700), system displays localized message as per below:

  /*
   elseif ($current_step_for_activate_product_process == 'duplicate-serial-number-error') {

   }
   */

  // No Form selected Error Message.
  elseif ($current_step_for_activate_product_process != '') {
    $form['message'] = array(
      '#markup' => t('The requested page could not be found.'),
    );
    return $form;
  }

  return $form;
}

/**
 * @return string
 */
function fnet_ma_display_activate_error_700_links() {
  global $base_url, $user;
  $user_id = $user->uid;
  $html = '';
  $query_string_elements['POPcode'] = check_plain(trim($_GET['POPcode']));
  $query_string_elements['ocp'] = check_plain(trim($_GET['ocp']));
  $query_string_elements['serialNumber'] = check_plain(trim($_GET['serialNumber']));
  $query_string_elements['model-number'] = check_plain(trim($_GET['model-number']));
  $submit_link = l('Submit', "myaccount/activate-product-duplicate-serial-number", array('query' => $query_string_elements));
  $cancel_link = l('Cancel', "myaccount/activate-product");
  $html .= "<table class = 'activate-error-800-links-table-class' border='0' cellspacing='20' cellpadding='5'>
              <tr>
                <td valign='top' width='30%' align = 'center'>" . theme('fnet_button', array(
      'link' => $submit_link,
      'auto' => TRUE
    )) . "</td>
                <td valign='top' align = 'center'>" . theme('fnet_button', array(
      'link' => $cancel_link,
      'auto' => TRUE
    )) . "</td>
              </tr>
            </table>
            <div id='fn-myaccount-static-ruler-one' class='ruler-bar'>&nbsp;</div>";
  return $html;
}

/**
 * @return string
 */
function fnet_ma_display_activate_error_800_links() {
  global $base_url, $user;
  $user_id = $user->uid;
  $html = '';

  $query_string_elements['step'] = 'four';
  $query_string_elements['ocp'] = check_plain($_GET['ocp']);
  $query_string_elements['serialNumber'] = check_plain($_GET['serialNumber']);
  $query_string_elements['model-number'] = check_plain($_GET['model-number']);
  $html .= "<table class = 'activate-error-800-links-table-class' border='0' cellspacing='20' cellpadding='5'>
              <tr>
                <td valign='top' width='32%'>" . l('Update Popcode/Try Again', "myaccount/activate-product", $options = array('query' => $query_string_elements)) . "</td>
                <td valign='top' width='36%'>" . l('View my Registered Products', "myaccount/registered-products") . "</td>
                <td valign='top'  width='30%'>" . l('Register a New Product', "myaccount/register-products-step-one") . "</td>
                <td valign='top'>" . l('Cancel', "myaccount/activate-product") . "</td>
              </tr>
            </table>
            <div id='fn-myaccount-static-ruler-one' class='ruler-bar'>&nbsp;</div>";
  return $html;
}

/**
 * Function for activating a product with duplicate serial numbers.
 * TODO: Onyx ID is deprecated and no longer used. Rework?
 */
function fnet_ma_activate_product_with_duplicate_serial_number() {
  global $user;
  $profile_content_type = variable_get('profile_content_type', 'profile');
  $current_form_array = $_REQUEST;
  $current_step_for_activate_product_process = check_plain(trim($current_form_array['step']));

  $individualid = check_plain($user->field_user_onyx_id[LANGUAGE_NONE][0]['value']);
  $popcode = check_plain(trim($current_form_array['POPcode']));
  $ocp_product_ID = check_plain(trim($current_form_array['ocp']));
  $serialnumber = check_plain(trim($current_form_array['serialNumber']));
  $reenterserialnumber = check_plain(trim($current_form_array['serialNumber']));
  $model_number = check_plain(trim($current_form_array['model-number']));
  $resubmit_flag = "TRUE";

  $status = fnet_ma_generate_non_optiview_keycode($individualid, $popcode, $ocp_product_ID, $serialnumber, $reenterserialnumber, $resubmit_flag);

  if ($status['status'] == 'NonOptiviewKeycode_generated_correctly') {

    $CDKey = $status['CDKey'];

    $path = isset($_GET['q']) ? $_GET['q'] : '<front>';
    $main_url_of_step_five = "user/" . $user->uid . "/activate-product";
    $query_string_elements = array();
    $query_string_elements['step'] = 'five';
    $query_string_elements['POPcode'] = check_plain(trim($popcode));
    $query_string_elements['ocp'] = check_plain(trim($ocp_product_ID));
    $query_string_elements['serialNumber'] = check_plain(trim($serialnumber));
    $query_string_elements['model-number'] = check_plain(trim($model_number));
    $query_string_elements['CDKey'] = check_plain(trim($CDKey));

    $query = array(
      'step' => $query_string_elements['step'],
      'POPcode' => $query_string_elements['POPcode'],
      'ocp' => $query_string_elements['ocp'],
      'serialNumber' => $query_string_elements['serialNumber'],
      'model-number' => $query_string_elements['model-number'],
      'CDKey' => $query_string_elements['CDKey'],
    );
    $message = t('Key code generated successfully.');
    drupal_set_message($message, 'status', TRUE);
    drupal_goto($main_url_of_step_five, array('query' => $query));
  }
  elseif ($status['status'] == 'error_in_NonOptiviewKeycode_generation') {
    $main_url_of_error_page_one = 'user/' . $user->uid . '/activate-product';
    $query_string_elements = array();
    $query_string_elements['step'] = 'four';
    $query_string_elements['POPcode'] = check_plain(trim($popcode));
    $query_string_elements['ocp'] = check_plain(trim($ocp_product_ID));
    $query_string_elements['serialNumber'] = check_plain(trim($serialnumber));
    $query_string_elements['model-number'] = check_plain(trim($model_number));

    $query = array(
      'step' => $query_string_elements['step'],
      'ocp' => $query_string_elements['ocp'],
      'serialNumber' => $query_string_elements['serialNumber'],
      'model-number' => $query_string_elements['model-number'],
      'POPcode' => $query_string_elements['POPcode'],
    );
    $message_one = $status['error_message_from_webservice'];
    $message_two = "<br />" . t('For assistance, email fnetlicensing@flukenetworks.com or call 800-283-5853 (US and Canada) or 425-446-4519 (outside U.S. and Canada).');
    drupal_set_message($message_one . $message_two, 'error', TRUE);
    drupal_goto($main_url_of_error_page_one, array('query' => $query));
  }
}

/**
 * Function to generate "NonOptiview Keycode".
 */
function fnet_ma_generate_non_optiview_keycode($individualid = '', $pop_code = '', $asset_id = '', $serialnumber = '', $reenterserialnumber = '', $resubmit_flag = "FALSE") {
  $status_with_results = array();
  if ($individualid != '' || $pop_code != '' || $asset_id != '' || $serialnumber != '' || $reenterserialnumber) {
    //Fetch the ChProduct number which is required when we generate the Key code for a specific POP code.
    $chProductnumber = fnet_ma_get_product_number_for_asset($asset_id);
    $pop_code = trim(str_replace('-', '', $pop_code));

    $domain_url = trim(variable_get("myaccount_webservices_domain_name", 'http://services.test.intranet.danahertm.com'));
    $url = $domain_url . "/ActivateOptions/ActivateOptions.svc/pox/GenerateNonOptiviewKeycode" . "?individualid=" . $individualid . "&popcode=" . $pop_code . "&chProductnumber=" . $chProductnumber . "&serialnumber=" . $serialnumber . "&reenterserialnumber=" . $reenterserialnumber . "&resubmit=" . $resubmit_flag;
    $http_result = drupal_http_request($url);

    if ($http_result->code == 200) {
      $doc = simplexml_load_string($http_result->data);
      if ($doc === FALSE) {
        fnet_ma_save_errors_to_watch_dog_and_email_to_admin($url, 'The issue occurred when the web service was trying to generate "NonOptiview Keycode" for the logged in user and the reason being unable to parse the XML.') . "<br /><br />" . $http_result->data;
        $status_with_results['status'] = 'error_in_parsing_XML';
        return $status_with_results;
      }
      else {
        if ($doc->ErrorMessage[0] == '') {
          $status_with_results['CDKey'] = check_plain($doc->POPCode);
          $status_with_results['status'] = 'NonOptiviewKeycode_generated_correctly';
          return $status_with_results;
        }
        elseif ($doc->ErrorMessage[0] != '' || $doc->ErrorCode[0] != '') {
          $status_with_results['status'] = 'error_in_NonOptiviewKeycode_generation';
          $status_with_results['error_message_from_webservice'] = $doc->ErrorMessage[0];
          $status_with_results['error_ID_from_webservice'] = $doc->ErrorCode[0];
          return $status_with_results;
        }
      }
    }
    else {
      fnet_ma_save_errors_to_watch_dog_and_email_to_admin($url, 'The issue occurred when the web service was trying to generate "NonOptiview Keycode" for the logged in user and the reason being unable to access the .');
      $status_with_results['status'] = 'webservice_is_down';
      return $status_with_results;
    }
  }
  else {
    $status_with_results['status'] = 'required_parameters_not_supplied';
    return $status_with_results;
  }
}

/**
 * Validation Rules for "Activate an option" forms.
 *
 * @param $form
 * @param $form_state
 */
function fnet_ma_product_activation_form_validate($form, &$form_state) {

  $current_form_array = $_REQUEST;
  $current_step_for_activate_product_process = check_plain($current_form_array['step']);

  // FORM 1
  if ($current_step_for_activate_product_process == '') {

    $proof_of_purchase_code = trim($form_state['values']['proof_of_purchase_code']);
    $proof_of_purchase_code_error_status = 0;
    if ($proof_of_purchase_code != '') {
      if (!(preg_match("/^([1]-)?[0-9]{4}-[0-9]{4}-[0-9]{4}-[0-9]{4}$/i", $proof_of_purchase_code))) {
        // This is for IE 7 or below ONLY.
        $form_state['values']['proof_of_purchase_code'] = join('-', str_split($proof_of_purchase_code, 4));
        if (!(preg_match("/^([1]-)?[0-9]{4}-[0-9]{4}-[0-9]{4}-[0-9]{4}$/i", $form_state['values']['proof_of_purchase_code']))) {
          form_set_error('proof_of_purchase_code', t('Please enter a valid Proof of Purchase Code.'));
          $proof_of_purchase_code_error_status++;
        }

      }
    }

    if (($proof_of_purchase_code_error_status == 0) && ($proof_of_purchase_code != '')) {
      $proof_of_purchase_code_status = array();
      $proof_of_purchase_code_status = fnet_ma_validate_proof_of_purchase_code($proof_of_purchase_code);
      if ($proof_of_purchase_code_status['status'] != 'POP_code_is_valid' && $proof_of_purchase_code_status['status'] != 'valid_gold_type_pop_code') {
        $status_string = trim(check_plain($proof_of_purchase_code_status['status']));
        if ($status_string == 'pop_code_already_used') {
          form_set_error('proof_of_purchase_code', $proof_of_purchase_code_status['actual_error_message'] . t('<br />For assistance, email fnetlicensing@flukenetworks.com or call 800-283-5853 (US and Canada) or 425-446-4519 (outside U.S. and Canada).'));
        }
        elseif ($status_string == 'POP_code_is_invalid') {
          form_set_error('proof_of_purchase_code', t('Please enter a valid Proof of Purchase Code.<br />For assistance, email fnetlicensing@flukenetworks.com or call 800-283-5853 (US and Canada) or 425-446-4519 (outside U.S. and Canada).'));
        }
        else {
          form_set_error('proof_of_purchase_code', variable_get('myaccount_webservices_failure_notification_message', t('Our apologies. Your request is not currently available. A notification has been delivered to our web team to correct. If you need immediate assistance please call us at +1 425 446-4519.')));
        }
      }
    }
  }

  // FORM 3
  elseif ($current_step_for_activate_product_process == 'three') {
    if (trim(check_plain($form_state['values']['product_purchase_date'])) != '') {
      $product_purchase_date = check_plain($form_state['values']['product_purchase_date']);
      $error_status = fnet_ma_evaluate_valid_dates($product_purchase_date, 1);
      $error_message = t('Purchase Date cannot be a future date.');
      if ($error_status) {
        form_set_error('product_purchase_date', $error_message);
      }
    }

    if (trim($form_state['values']['product_model']) == '-1') {
      $error_message = t('Please select a Product Model from the drop down.');
      form_set_error('product_model', $error_message);
    }

    if (!preg_match('/^[0-9]*$/', check_plain(trim($form_state['values']['product_serial_number'])))) {
      $error_message = t('Please enter a valid Serial Number.');
      form_set_error('product_serial_number', $error_message);
    }

    if (check_plain(trim($form_state['values']['product_serial_number'])) != '') {
      $product_serial_number_character_count = drupal_strlen(trim(check_plain($form_state['values']['product_serial_number'])));
      if ($product_serial_number_character_count < 7) {
        //$error_message = t('Please enter a  valid serial number containing 7 or 8 digits only.', array('!textbox' => $i));
        $error_message = t('Please enter a  valid serial number containing 7 digits only.');
        form_set_error('product_serial_number', $error_message);
      }
    }

  }

  // FORM 4
  elseif ($current_step_for_activate_product_process == 'four') {

    $proof_of_purchase_code_error_status = 0;
    $proof_of_purchase_code_error_status_two = 0;

    $proof_of_purchase_code = trim($form_state['values']['popcode_one']);
    $proof_of_purchase_code_two = trim($form_state['values']['popcode_two']);

    $serial_number_one = trim($form_state['values']['product_serial_number_one']);
    $serial_number_two = trim($form_state['values']['product_serial_number_two']);

    $heavy_validation_status = 0;

    if ($proof_of_purchase_code != $proof_of_purchase_code_two) {
      $heavy_validation_status++;
      form_set_error('', t('The Proof of Purchase Codes do not match.'));
    }

    if ($serial_number_one != $serial_number_two) {
      $heavy_validation_status++;
      form_set_error('', t('The Serial Numbers do not match.'));
    }

    if (!preg_match('/^[0-9]*$/', $serial_number_one)) {
      $error_message = t('Please enter a valid Serial Number.');
      form_set_error('product_serial_number_one', $error_message);
      $heavy_validation_status++;
    }

    if (!preg_match('/^[0-9]*$/', $serial_number_two)) {
      $error_message = t('Please Re-enter a valid Serial Number.');
      form_set_error('product_serial_number_two', $error_message);
      $heavy_validation_status++;
    }

    if ($heavy_validation_status == 0) {
      if ($proof_of_purchase_code != '') {
        if (!(preg_match("/^([1]-)?[0-9]{4}-[0-9]{4}-[0-9]{4}-[0-9]{4}$/i", $proof_of_purchase_code))) {
          //form_set_error('popcode_one', t('Please enter a valid Proof of Purchase Code.'));
          //$proof_of_purchase_code_error_status++;
          // This is for IE 7 or below ONLY.
          $form_state['values']['popcode_one'] = join('-', str_split($proof_of_purchase_code, 4));
          if (!(preg_match("/^([1]-)?[0-9]{4}-[0-9]{4}-[0-9]{4}-[0-9]{4}$/i", $form_state['values']['popcode_one']))) {
            form_set_error('popcode_one', t('Please enter a valid Proof of Purchase Code.'));
            $proof_of_purchase_code_error_status++;
          }
        }
      }

      if (($proof_of_purchase_code_error_status == 0) && ($proof_of_purchase_code != '')) {
        $proof_of_purchase_code_status = array();
        $proof_of_purchase_code_status = fnet_ma_validate_proof_of_purchase_code($proof_of_purchase_code);
        if ($proof_of_purchase_code_status['status'] == 'error_in_operations') {
          $status_string = trim($proof_of_purchase_code_status['status']);
          form_set_error('popcode_one', variable_get('myaccount_webservices_failure_notification_message', t('Our apologies. Your request is not currently available. A notification has been delivered to our web team to correct. If you need immediate assistance please call us at +1 425 446-4519.')));
        }
        elseif ($proof_of_purchase_code_status['status'] != 'POP_code_is_valid') {
          $status_string = trim($proof_of_purchase_code_status['status']);
          if ($status_string == 'pop_code_already_used') {
            form_set_error('', $proof_of_purchase_code_status['actual_error_message']);
          }
          elseif ($status_string == 'POP_code_is_invalid') {
            form_set_error('', t('Please enter a valid Proof of Purchase Code.'));
          }
        }
      }

      if ($proof_of_purchase_code_two != '') {
        if (!(preg_match("/^([1]-)?[0-9]{4}-[0-9]{4}-[0-9]{4}-[0-9]{4}$/i", $proof_of_purchase_code_two))) {
          $form_state['values']['popcode_two'] = join('-', str_split($proof_of_purchase_code_two, 4));
          if (!(preg_match("/^([1]-)?[0-9]{4}-[0-9]{4}-[0-9]{4}-[0-9]{4}$/i", $form_state['values']['popcode_two']))) {
            form_set_error('popcode_two', t('Please re-enter a valid Proof of Purchase Code.'));
            $proof_of_purchase_code_error_status++;
          }
        }
      }

      if (($proof_of_purchase_code_error_status_two == 0) && ($proof_of_purchase_code_two != '')) {
        $proof_of_purchase_code_status_two = fnet_ma_validate_proof_of_purchase_code($proof_of_purchase_code_two);
        if ($proof_of_purchase_code_status['status'] == 'error_in_operations') {
          $status_string = trim($proof_of_purchase_code_status['status']);
          form_set_error('popcode_two', variable_get('myaccount_webservices_failure_notification_message', t('Our apologies. Your request is not currently available. A notification has been delivered to our web team to correct. If you need immediate assistance please call us at +1 425 446-4519.')));
        }
        elseif ($proof_of_purchase_code_status_two['status'] != 'POP_code_is_valid') {
          $status_string = trim($proof_of_purchase_code_status_two['status']);
        }
      }
    }
  }
}


/**
 * Submit Rules for "Activate an option" forms.
 *
 * @param $form
 * @param $form_state
 */
function fnet_ma_product_activation_form_submit($form, &$form_state) {
  global $user;
  $current_form_array = $_REQUEST;
  $current_step_for_activate_product_process = check_plain(trim($current_form_array['step']));
  if ($current_step_for_activate_product_process == '') {
    $proof_of_purchase_code = trim(check_plain($form_state['values']['proof_of_purchase_code']));
    $product_group_details_based_on_pop_code = fnet_ma_validate_proof_of_purchase_code($proof_of_purchase_code);
    if ($product_group_details_based_on_pop_code['status'] == 'POP_code_is_valid') {
      $query = array(
        'step' => 'two',
        'ProductCode' => $product_group_details_based_on_pop_code['productCodeField'],
        'OptionCode' => $product_group_details_based_on_pop_code['optionCodeField'],
        'POPcode' => $proof_of_purchase_code,
      );
      drupal_goto("user/" . $user->uid . "/activate-product", array('query' => $query));
    }
    elseif ($product_group_details_based_on_pop_code['status'] == 'valid_gold_type_pop_code') {
      $query = array(
        'step' => 'two',
        'itemnumber' => $product_group_details_based_on_pop_code['gold_type_pop_code_item_number'],
        'infoCode' => $product_group_details_based_on_pop_code['infoCodeField'],
        'ProductCode' => $product_group_details_based_on_pop_code['productCodeField'],
        'OptionCode' => $product_group_details_based_on_pop_code['optionCodeField'],
        'POPcode' => $proof_of_purchase_code,
      );
      drupal_goto("myaccount/activate-product-gold-type", array('query' => $query));
    }
  }

  elseif ($current_step_for_activate_product_process == 'two') {
    $onyx_individualId = trim(check_plain($user->field_user_onyx_id[LANGUAGE_NONE][0]['value']));
    $productGroupCode = trim(check_plain($form_state['values']['hidden_ProductGroupCode']));
    $proof_of_purchase_code = trim(check_plain($form_state['values']['hidden_proof_of_purchase_code']));
    if ($onyx_individualId != '' && $productGroupCode != '') {
      $status_for_product_group = fnet_ma_verify_has_registered_product_for_prd_group($productGroupCode, $onyx_individualId);
      if ($status_for_product_group['status'] == 'webservice_exception_error') {
        drupal_set_message(variable_get('myaccount_webservices_failure_notification_message', t('Our apologies. Your request is not currently available. A notification has been delivered to our web team to correct. If you need immediate assistance please call us at +1 425 446-4519.')), 'error');
      }
      if ($status_for_product_group['status'] == 'no_products_registered_within_supplied_product_group') {
        $query = array(
          'step' => 'three',
          'POPcode' => $proof_of_purchase_code,
        );
        drupal_goto("user/" . $user->uid . "/activate-product", array('query' => $query));
      }
      elseif ($status_for_product_group['status'] == 'products_already_registered_within_supplied_product_group') {
        $product_group_details_based_on_pop_code = fnet_ma_validate_proof_of_purchase_code($proof_of_purchase_code);
        $query = array(
          'step' => 'ProductGroup',
          'POPcode' => $proof_of_purchase_code,
          'opn' => $status_for_product_group['chProductNumber'],
          'ProductCode' => $product_group_details_based_on_pop_code['productCodeField'],
          'OptionCode' => $product_group_details_based_on_pop_code['optionCodeField'],
          'POPcode' => $proof_of_purchase_code,
        );
        drupal_goto("user/" . $user->uid . "/activate-product", array('query' => $query));
      }
    }
  }

  elseif ($current_step_for_activate_product_process == 'three') {
    global $user;
    $individualId = check_plain($user->field_user_onyx_id[LANGUAGE_NONE][0]['value']);

    $domain_url = trim(variable_get("myaccount_webservices_domain_name", 'http://services.test.intranet.danahertm.com'));

    $serialNumber = check_plain(trim($form_state['values']['product_serial_number']));
    $purchaseDate = check_plain(trim($form_state['values']['product_purchase_date']));
    $productNumber = check_plain(trim($form_state['values']['product_model']));
    $proof_of_purchase_code = check_plain($current_form_array['POPcode']);

    if ($serialNumber != '' && $productNumber != '') {
      $http_result = new stdClass();
      $http_result->code = 200;
      $url = '';
      $result = fnet_sfdc_register_product($user->mail, $productNumber, $purchaseDate, $serialNumber);
      if ($result) {
        $doc = $productNumber;
      }
      else {
        $doc = '';
      }
      if ($http_result->code == 200) {
        if (!empty($http_result->data)) {
          $doc = simplexml_load_string($http_result->data);
        }
        if ($doc === FALSE) {
          $issue_occured_at = 'Error parsing the XML for URL when registering a product from within "Activate an option" flow.';
          fnet_ma_save_errors_to_watch_dog_and_email_to_admin($url, $issue_occured_at . "<br /><br />" . $http_result->data);
          $query = array(
            'step' => 'three',
            'POPcode' => $proof_of_purchase_code,
            'serialNumber' => $serialNumber,
            'model-number' => $productNumber,
          );
          drupal_set_message(variable_get('myaccount_webservices_failure_notification_message', t('Our apologies. Your request is not currently available. A notification has been delivered to our web team to correct. If you need immediate assistance please call us at +1 425 446-4519.')), 'error');
          drupal_goto("user/" . $user->uid . "/activate-product", array('query' => $query));
        }
        else {
          $ocp = check_plain(trim($doc));
          if ($ocp != '') {
            // Email the user on successful Product Registration.
            $email_status = fnet_ma_send_product_registration_email_to_user();
            $query = array(
              'step' => 'four',
              'POPcode' => $proof_of_purchase_code,
              'ocp' => $ocp,
              'serialNumber' => $serialNumber,
              'model-number' => $productNumber,
            );
            drupal_goto("user/" . $user->uid . "/activate-product", array('query' => $query));
          }
          else {
            // TO DO
            $query = array(
              'step' => 'three',
              'POPcode' => $proof_of_purchase_code,
              'serialNumber' => $serialNumber,
              'model-number' => $productNumber,
            );
            drupal_set_message(variable_get('myaccount_webservices_failure_notification_message', t('Our apologies. Your request is not currently available. A notification has been delivered to our web team to correct. If you need immediate assistance please call us at +1 425 446-4519.')), 'error');
            drupal_goto("user/" . $user->uid . "/activate-product", array('query' => $query));
          }
        }
      }
      else {
        $issue_occured_at = 'Unable to access the contents from the URL when registering a product from within "Activate an option" flow.';
        fnet_ma_save_errors_to_watch_dog_and_email_to_admin($url, $issue_occured_at);
        $query = array(
          'step' => 'three',
          'POPcode' => $proof_of_purchase_code,
          'serialNumber' => $serialNumber,
          'model-number' => $productNumber,
        );
        drupal_set_message(variable_get('myaccount_webservices_failure_notification_message', t('Our apologies. Your request is not currently available. A notification has been delivered to our web team to correct. If you need immediate assistance please call us at +1 425 446-4519.')), 'error');
        drupal_goto("user/" . $user->uid . "/activate-product", array('query' => $query));
      }
    }
  }

  elseif ($current_step_for_activate_product_process == 'four') {
    global $user;

    $individualid = check_plain($user->field_user_onyx_id[LANGUAGE_NONE][0]['value']);
    $popcode = check_plain($form_state['values']['popcode_one']);
    $ocp_product_ID = check_plain($form_state['values']['hidden_ocp']);
    $serialnumber = check_plain($form_state['values']['product_serial_number_one']);
    $reenterserialnumber = check_plain($form_state['values']['product_serial_number_two']);
    $resubmit_flag = "FALSE";

    $status = fnet_ma_generate_non_optiview_keycode($individualid, $popcode, $ocp_product_ID, $serialnumber, $reenterserialnumber, $resubmit_flag);

    if ($status['status'] == 'NonOptiviewKeycode_generated_correctly') {
      $CDKey = $status['CDKey'];

      $path = isset($_GET['q']) ? $_GET['q'] : '<front>';
      $main_url_of_step_five = url($path, array('absolute' => TRUE));
      $query_string_elements = array();
      $query_string_elements['step'] = 'five';
      $query_string_elements['POPcode'] = check_plain($popcode);
      $query_string_elements['ocp'] = check_plain($_GET['ocp']);
      $query_string_elements['serialNumber'] = check_plain($serialnumber);
      $query_string_elements['model-number'] = check_plain($_GET['model-number']);
      $query_string_elements['CDKey'] = check_plain($CDKey);

      $query = array(
        'step' => $query_string_elements['step'],
        'POPcode' => $query_string_elements['POPcode'],
        'ocp' => $query_string_elements['ocp'],
        'serialNumber' => $query_string_elements['serialNumber'],
        'model-number' => $query_string_elements['model-number'],
        'CDKey' => $query_string_elements['CDKey'],
      );
      $message = t('Key code generated successfully.');
      drupal_set_message($message, 'status', TRUE);
      drupal_goto($main_url_of_step_five, array('query' => $query));
    }
    elseif ($status['status'] == 'error_in_NonOptiviewKeycode_generation') {

      // Validation : Validate POP code just before generating a new key code.
      // System Response: For any other validation error(status code=800), system displays localized message as per below:
      if (trim($status['error_ID_from_webservice']) == '800') {
        $path = isset($_GET['q']) ? $_GET['q'] : '<front>';
        $main_url_of_error_page_one = url($path, array('absolute' => TRUE));
        $query_string_elements = array();
        $query_string_elements['step'] = 'popcode-validation-error';
        //$query_string_elements['POPcode']       = check_plain($popcode);
        $query_string_elements['ocp'] = check_plain(trim($_GET['ocp']));
        $query_string_elements['serialNumber'] = check_plain($serialnumber);
        $query_string_elements['model-number'] = check_plain(trim($_GET['model-number']));
        $query = array(
          'step' => $query_string_elements['step'],
          'ocp' => $query_string_elements['ocp'],
          'serialNumber' => $query_string_elements['serialNumber'],
          'model-number' => $query_string_elements['model-number'],
        );
        drupal_goto($main_url_of_error_page_one, array('query' => $query));
      }
      // Validation : Validate POP code just before generating a new key code.
      // System Response: For any other validation error(status code=700), system displays localized message as per below:
      elseif (trim($status['error_ID_from_webservice']) == '700') {
        $path = isset($_GET['q']) ? $_GET['q'] : '<front>';
        $main_url_of_error_page_one = url($path, array('absolute' => TRUE));
        $query_string_elements = array();
        $query_string_elements['step'] = 'duplicate-serial-number-error';
        $query_string_elements['POPcode'] = check_plain(trim($popcode));
        $query_string_elements['ocp'] = check_plain(trim($_GET['ocp']));
        $query_string_elements['serialNumber'] = check_plain(trim($serialnumber));
        $query_string_elements['model-number'] = check_plain(trim($_GET['model-number']));
        $query = array(
          'step' => $query_string_elements['step'],
          'POPcode' => $query_string_elements['POPcode'],
          'ocp' => $query_string_elements['ocp'],
          'serialNumber' => $query_string_elements['serialNumber'],
          'model-number' => $query_string_elements['model-number'],
        );
        drupal_goto($main_url_of_error_page_one, array('query' => $query));
      }
      else {
        $path = isset($_GET['q']) ? $_GET['q'] : '<front>';
        $main_url_of_error_page_one = url($path, array('absolute' => TRUE));
        $main_url_of_step_five = url($path, array('absolute' => TRUE));
        $query_string_elements = array();
        $query_string_elements['step'] = 'four';
        $query_string_elements['POPcode'] = check_plain(trim($_GET['POPcode']));
        $query_string_elements['ocp'] = check_plain(trim($_GET['ocp']));
        $query_string_elements['serialNumber'] = check_plain(trim($serialnumber));
        $query_string_elements['model-number'] = check_plain(trim($_GET['model-number']));
        $query = array(
          'step' => $query_string_elements['step'],
          'ocp' => $query_string_elements['ocp'],
          'serialNumber' => $query_string_elements['serialNumber'],
          'model-number' => $query_string_elements['model-number'],
          'POPcode' => $query_string_elements['POPcode'],
        );
        $message_one = $status['error_message_from_webservice'];
        $message_two = "<br />" . t('For assistance, email fnetlicensing@flukenetworks.com or call 800-283-5853 (US and Canada) or 425-446-4519 (outside U.S. and Canada).');
        drupal_set_message($message_one . $message_two, 'error', TRUE);
        drupal_goto($main_url_of_error_page_one, array('query' => $query));
      }
    }
  }
}

/**
 * This section is related to - "Activate a Product/Option using Gold type POP code" on Fluke Networks.
 * this code set is triggered on the URL - "'myaccount/activate-product-gold-type'"
 *
 * @param $form
 * @param $form_state
 * @return array
 */
function fnet_ma_gold_type_product_activation_form($form, $form_state) {
  include_once DRUPAL_ROOT . '/includes/locale.inc';
  module_load_include('inc', 'addressfield', 'addressfield.administrative_areas');
  $current_form_array = array();
  $form = array();
  $current_form_array = $_REQUEST;
  $current_step_for_activate_product_process = check_plain($current_form_array['step']);

  global $user;
  $account = user_load($user->uid);

  // FORM NO 2 and FORM NO 3.
  if ($current_step_for_activate_product_process == 'two' || $current_step_for_activate_product_process == 'three') {
    $ProductCode = trim(check_plain($current_form_array['ProductCode']));
    $OptionCode = trim(check_plain($current_form_array['OptionCode']));
    $POP_code = trim(check_plain($current_form_array['POPcode']));

    if ($ProductCode == '' || $OptionCode == '' || $POP_code == '') {
      $form['message'] = array(
        '#markup' => "<span class = 'red-text'>" . t('The requested page could not be found.') . "</span><br />",
      );
      return $form;
    }

    if ($POP_code != '') {
      if (!(preg_match("/^([1]-)?[0-9]{4}-[0-9]{4}-[0-9]{4}-[0-9]{4}$/i", $POP_code))) {
        $form['message'] = array(
          '#markup' => "<span class = 'red-text'>" . t('Invalid gold type POP code, please try again.') . "</span><br />",
        );
        return $form;
      }
    }

    if ($POP_code != '') {
      $proof_of_purchase_code_status = fnet_ma_validate_proof_of_purchase_code($POP_code);
      if ($proof_of_purchase_code_status['status'] != 'valid_gold_type_pop_code') {
        $form['message'] = array(
          '#markup' => "<span class = 'red-text'>" . t('The Pop code you have entered is an in-valid "Gold Type POP code", please try again.') . "</span><br />",
        );
        return $form;
      }
    }

    $product_info_fetched_from_POP_code = fnet_ma_fetch_product_information_based_on_POPcode($ProductCode, $OptionCode);
    if (count($product_info_fetched_from_POP_code) == 0) {
      $form['message'] = array(
        '#markup' => t('Invalid arguments provided.(5)'),
      );
      return $form;
    }

    $form['page_header'] = array(
      '#markup' => '<div class="my-account-headlines">' . t('Product/Gold Bundle Contract Activation') . '</div>',
      '#weight' => '-50',
    );

    $form['product_section_header_message'] = array(
      '#markup' => '<div class="my-account-headlines">' . check_plain($product_info_fetched_from_POP_code->vchHierarchyDesc) . '</div>',
    );

    $form['static_product_options_to_enable'] = array(
      '#type' => 'item',
      '#title' => '',
      '#markup' => '<b>' . t('Option to Enable') . ': </b>' . check_plain($product_info_fetched_from_POP_code->optionname),
    );

    $form['static_product_pop_code'] = array(
      '#type' => 'item',
      '#title' => '',
      '#markup' => '<b>' . t('Proof of Purchase Code') . ': </b>' . $POP_code,
    );

    $form['static_ruler_one'] = array(
      '#type' => 'item',
      '#title' => '',
      '#markup' => '<div class="ruler-bar" id = "fn-myaccount-static-ruler-one">&nbsp;</div>',
    );

    $form['hidden_gold_type_proof_of_purchase_code'] = array(
      '#type' => 'value',
      '#value' => $POP_code,
    );

    $form['hidden_gold_type_product_group_code'] = array(
      '#type' => 'value',
      '#value' => check_plain($proof_of_purchase_code_status['productCodeField']),
    );
  }

  // FORM NO 2
  if ($current_step_for_activate_product_process == 'two') {
    $proof_of_purchase_code = trim(check_plain($current_form_array['POPcode']));
    $product_group_details_based_on_pop_code = fnet_ma_validate_proof_of_purchase_code($proof_of_purchase_code);

    if ($product_group_details_based_on_pop_code['status'] == 'valid_gold_type_pop_code') {

      // If the POP code is a valid Gold Type POP code then check if the key code is already activated or not.
      $gold_type_popcode_already_activated_status = fnet_ma_verify_gold_type_popcode_already_activated_status($proof_of_purchase_code);
      if ($gold_type_popcode_already_activated_status['status'] != 0) {
        $form['message'] = array(
          '#markup' => "<span class = 'red-text'>" . t('The key code you are using is already activated. For assistance please email support@flukenetworks.com or call 800-283-5853 (U.S. and Canada) or 425-446-4519 (outside U.S. and Canada).') . "</span><br />",
        );
        return $form;
      }
      $form['message_one'] = array(
        '#markup' => variable_get('fnet_ma_gold_type_pop_code_page_introduction', t("Please verify your Gold Contract information. The person listed below will receive all Gold benefit notification for this Gold Contract.")) . "<br /><br />",
      );

      $form['message_two'] = array(
        '#markup' => "<span class = 'red-text'>" . t('* indicates required fields') . "</span><br />",
      );

      $form['sItem_Number'] = array(
        '#type' => 'value',
        '#markup' => $product_group_details_based_on_pop_code['gold_type_pop_code_item_number'],
      );

      $form['strPurchaseDate'] = array(
        '#type' => 'textfield',
        '#title' => t('Purchase Date'),
        '#default_value' => variable_get('textfield', NULL),
        '#attributes' => array(
          'class' => array('datepicker', 'notranslate'),
          'readonly' => 'yes',
        ),
        '#required' => TRUE,
        '#size' => 25,
        '#suffix' => '<br />',
      );

      $form['page_header_two'] = array(
        '#markup' => '<div class="my-account-headlines">' . t('Personal Information') . '</div>',
        '#prefix' => '<div id = "gold-type-pop-code-profile-form-left-section">',
      );

      $form['strFirstName'] = array(
        '#type' => 'textfield',
        '#title' => t('First Name'),
        '#default_value' => trim(check_plain($account->field_address[LANGUAGE_NONE][0]['first_name'])),
        '#required' => TRUE,
        '#size' => 35,
        '#maxlength' => 100,
      );

      $form['strLastName'] = array(
        '#type' => 'textfield',
        '#title' => t('Last Name'),
        '#default_value' => trim(check_plain($user->field_address[LANGUAGE_NONE][0]['last_name'])),
        '#required' => TRUE,
        '#size' => 35,
        '#maxlength' => 100,
      );

      $form['strOrigEmail'] = array(
        '#type' => 'textfield',
        '#title' => t('Email Address'),
        '#default_value' => trim(check_plain($account->mail)),
        '#required' => TRUE,
        '#size' => 35,
        '#maxlength' => 255,
      );

      $form['strPhone'] = array(
        '#type' => 'textfield',
        '#title' => t('Phone'),
        '#default_value' => trim(check_plain($account->field_user_telephone[LANGUAGE_NONE][0]['value'])),
        '#required' => TRUE,
        '#size' => 35,
        '#suffix' => '</div>',
        '#maxlength' => 80,
      );

      $form['page_header_three'] = array(
        '#markup' => '<div class="my-account-headlines">' . t('Company Information') . '</div>',
        '#prefix' => '<div id = "gold-type-pop-code-profile-form-right-section">',
      );

      $form['strCompanyName'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Name'),
        '#default_value' => trim(check_plain($account->field_address[LANGUAGE_NONE][0]['organisation_name'])),
        '#required' => TRUE,
        '#size' => 35,
        '#maxlength' => 100,
      );

      $form['strAdd1'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Address Line1'),
        '#default_value' => trim(check_plain($account->field_address[LANGUAGE_NONE][0]['thoroughfare'])),
        '#required' => TRUE,
        '#size' => 35,
        '#maxlength' => 150,
      );

      $form['strAdd2'] = array(
        '#type' => 'textfield',
        '#title' => t('Company Address Line2'),
        '#default_value' => trim(check_plain($account->field_address[LANGUAGE_NONE][0]['premise'])),
        '#size' => 35,
        '#maxlength' => 150,
      );

      $form['strCityName'] = array(
        '#type' => 'textfield',
        '#title' => t('City Name'),
        '#default_value' => trim(check_plain($account->field_address[LANGUAGE_NONE][0]['locality'])),
        '#required' => TRUE,
        '#size' => 35,
        '#maxlength' => 100,
      );

      // Include the main module file
      $country_array = country_get_list();
      $form['strCountryCode'] = array(
        '#type' => 'select',
        '#title' => t('Country'),
        '#default_value' => trim(check_plain($account->field_address[LANGUAGE_NONE][0]['value'])),
        '#options' => $country_array,
        '#required' => TRUE,
        '#ahah' => array(
          'event' => 'change',
          'callback' => 'fnet_ma_country_state_callback',
          'wrapper' => 'wrapper-2',
          'method' => 'replace',
        ),
      );
      // define the second tier select dropdown element
      $country_code = $form_state['values']['strCountryCode'];
      if (!empty($country_code)) {
        $states = addressfield_get_administrative_areas($country_code);
        asort($states);
        // If there are NO states present in the Country as per the Addresses module code base then display - "Not applicable"
        if (count($states) == 0) {
          $states = array('Not applicable');
        }
      }
      else {
        $states = addressfield_get_administrative_areas($account->field_address[LANGUAGE_NONE][0]['country']);
      }
      $form['strRegionCode'] = array(
        '#type' => 'select',
        '#title' => t('State'),
        '#default_value' => trim(check_plain($account->field_address[LANGUAGE_NONE][0]['administrative_area'])),
        '#options' => $states,
        '#required' => TRUE,
        '#prefix' => '<div id="wrapper-2" class = "full-available-width fn-myaccount-float-left">',
        '#suffix' => '</div>',
      );

      $form['strPostalCode'] = array(
        '#type' => 'textfield',
        '#title' => t('Postal Code'),
        '#default_value' => trim(check_plain($user->field_address[LANGUAGE_NONE][0]['postal_code'])),
        '#required' => TRUE,
        '#size' => 35,
        '#suffix' => '</div>',
        '#maxlength' => 16,
      );

      $form['submit'] = array(
        '#type' => 'submit',
        '#attributes' => array('class' => array('customfn-buttons')),
        '#weight' => 50,
        '#value' => t('Submit'),
      );
    }
    elseif ($product_group_details_based_on_pop_code['status'] == 'pop_code_already_used') {
      $form['message'] = array(
        '#markup' => "<span class = 'red-text'>" . t('This Proof of Purchase Code has already been used.<br />For assistance, email fnetlicensing@flukenetworks.com or call 800-283-5853 (US and Canada) or 425-446-4519 (outside U.S. and Canada).') . "</span><br />",
      );
    }
    else {
      $form['message'] = array(
        '#markup' => "<span class = 'red-text'>" . t('Invalid gold type POP code, please try again.') . "</span><br />",
      );
    }
  }

  // FORM NO 3
  if ($current_step_for_activate_product_process == 'three') {
    if (check_plain($current_form_array['status']) == 'success') {
      $form['message'] = array(
        '#markup' => "<span>" . check_markup(variable_get('fnet_ma_gold_type_pop_code_success_status_message', t("Your request has been sent to Gold Contract Administrator, Thanks.")), filter_fallback_format(), $langcode = '' /* TODO Set this variable. */, TRUE) . "</span><br />",
      );
    }
    elseif (check_plain($current_form_array['status']) == 'failure') {
      $form['message'] = array(
        '#markup' => "<span class = 'red-text'>" . variable_get('myaccount_webservices_failure_notification_message', t('Our apologies. Your request is not currently available. A notification has been delivered to our web team to correct. If you need immediate assistance please call us at +1 425 446-4519.')) . "</span><br />",
      );
    }
  }
  return $form;
}

/**
 * The Gold Product activation form.
 *
 * @param $form
 * @param $form_state
 */
function fnet_ma_gold_type_product_activation_form_validate($form, &$form_state) {
  if (trim(check_plain($form_state['values']['strPurchaseDate'])) != '') {
    $product_purchase_date = trim(check_plain($form_state['values']['strPurchaseDate']));
    $error_status = fnet_ma_evaluate_valid_dates($product_purchase_date, 1);
    $error_message = t('Purchase Date cannot be a future date.');
    if ($error_status) {
      form_set_error('strPurchaseDate', $error_message);
    }
  }

  if (trim(check_plain($form_state['values']['strOrigEmail'])) != '') {
    if (valid_email_address(trim(check_plain($form_state['values']['strOrigEmail']))) != TRUE) {
      $error_message = t('The e-mail address %email is not valid.', array('%email' => trim(check_plain($form_state['values']['strOrigEmail']))));
      form_set_error('strOrigEmail', $error_message);
    }
  }
}

/**
 * Gold Product activation form submit handler.
 * @param $form
 * @param $form_state
 */
function fnet_ma_gold_type_product_activation_form_submit($form, &$form_state) {
  global $user;
  $values_submitted = $form_state['values'];
  $domain_url = trim(variable_get("myaccount_webservices_domain_name", 'http://services.test.intranet.danahertm.com'));
  $gold_type_pop_code = str_replace("-", '', $values_submitted['hidden_gold_type_proof_of_purchase_code']);

  $countryCode = trim(check_plain($values_submitted['strCountryCode']));
  $regionCode = trim(check_plain($values_submitted['strRegionCode']));

  // Below are the region code and country code fetched from the "country_region" table in the database.
  $country_region = fnet_ma_get_onyx_country_region($countryCode, $regionCode);
  $countryCode = urlencode(check_plain(trim(drupal_strtoupper($country_region['onyx_country_code']))));
  $regionCode = urlencode(check_plain(trim(drupal_strtoupper($country_region['onyx_region_code']))));


  $url = $domain_url . "/ActivateOptions/ActivateOptions.svc/POX/InsertGoldActivationRequest" . "?sItem_Number=" . urlencode(trim(check_plain($values_submitted['sItem_Number']))) . "&strPurchaseDate=" . urlencode(trim(check_plain($values_submitted['strPurchaseDate']))) . "&strFirstName=" . urlencode(trim(check_plain($values_submitted['strFirstName']))) . "&strLastName=" . urlencode(trim(check_plain($values_submitted['strLastName']))) . "&strEmail=" . urlencode(trim(check_plain($values_submitted['strOrigEmail']))) . "&strPhone=" . urlencode(trim(check_plain($values_submitted['strPhone']))) . "&strCompanyName=" . urlencode(trim(check_plain($values_submitted['strCompanyName']))) . "&strAdd1=" . urlencode(trim(check_plain($values_submitted['strAdd1']))) . "&strAdd2=" . urlencode(trim(check_plain($values_submitted['strAdd2']))) . "&strCityName=" . urlencode(trim(check_plain($values_submitted['strCityName']))) . "&strCountryCode=" . $countryCode . "
    &strRegionCode=" . $regionCode . "&strPostalCode=" . urlencode(trim(check_plain($values_submitted['strPostalCode']))) . "&strOrigFirstName=" . urlencode(trim(check_plain($user->field_user_first_name[0]['value']))) . "&strOrigLastName=" . urlencode(trim(check_plain($user->field_lastname[0]['value']))) . "&strOrigEmail=" . urlencode(trim(check_plain($user->mail))) . "&strKeyCode=" . urlencode(trim(check_plain($gold_type_pop_code))) . "&strPurchasedFrom=";
  $http_result = drupal_http_request($url);
  if ($http_result->code == 200) {
    $doc = simplexml_load_string($http_result->data);
    if ($doc === FALSE) {
      fnet_ma_save_errors_to_watch_dog_and_email_to_admin($url, 'The issue occurred when the web service was trying to insert the profile data along with the Gold Type POP code using the web service - InsertGoldActivationRequest and the reason being there was an error while parsing the XML.') . "<br /><br />" . $http_result->data;
      $status_with_results['status'] = 'error_in_parsing_XML';
      /**
       * This use case is when user has failed to
       * submit the form successfully and the form values are NOT
       * stored/inserted in the Database.
       */
      $path = isset($_GET['q']) ? $_GET['q'] : '<front>';
      $main_url_of_step_three = url($path, array('absolute' => TRUE));
      $query_string_elements = array();
      $query_string_elements['step'] = 'three';
      $query_string_elements['ProductCode'] = check_plain($_GET['ProductCode']);
      $query_string_elements['OptionCode'] = check_plain($_GET['OptionCode']);
      $query_string_elements['POPcode'] = check_plain($_GET['POPcode']);

      $query = array(
        'step' => $query_string_elements['step'],
        'POPcode' => $query_string_elements['POPcode'],
        'ProductCode' => $query_string_elements['ProductCode'],
        'OptionCode' => $query_string_elements['OptionCode'],
        'status' => 'failure',
      );
      $message = t('There was some error while parsing the XML, please try again after some time, Thanks.');
      drupal_set_message($message, 'error', TRUE);
      drupal_goto($main_url_of_step_three, array('query' => $query));
    }
    else {
      if ($doc[0] != '' && $doc[0] != '0') {

        $path = isset($_GET['q']) ? $_GET['q'] : '<front>';
        $main_url_of_step_three = url($path, array('absolute' => TRUE));
        $query_string_elements = array();
        $query_string_elements['step'] = 'three';
        $query_string_elements['ProductCode'] = check_plain($_GET['ProductCode']);
        $query_string_elements['OptionCode'] = check_plain($_GET['OptionCode']);
        $query_string_elements['POPcode'] = check_plain($_GET['POPcode']);
        $query_string_elements['infoCode'] = check_plain($_GET['infoCode']);
        $query_string_elements['itemnumber'] = check_plain($_GET['itemnumber']);

        /**
         * This use case is when user has successfully
         * submitted the form and the form values are
         * stored/inserted in the Database.
         */
        // Fetch all the registered product for the logged in user below.
        $registered_products = fnet_ma_display_registered_products('gold_type_popcode_flow');

        // Array of vchSerialNumber and chProductNumber ONLY
        if (count($registered_products)) {
          $counter = 0;
          foreach ($registered_products as $keys => $value) {
            $product_vchSerialNumber_array[$counter] = $value['vchSerialNumber'];
            $product_chProductNumber_array[$counter] = $value['chProductNumber'];
            $counter++;
          }

          if (in_array($query_string_elements['infoCode'], $product_vchSerialNumber_array) && in_array($query_string_elements['itemnumber'], $product_chProductNumber_array)) {
            // The given serial number is already registered.
            $status_with_results['status'] = 'error';
          }
          else {
            // The given serial number is NOT registered then register the Product with the given serial number.
            global $user;
            $status_with_results = array();
            $individualId = urlencode(check_plain($user->field_user_onyx_id[LANGUAGE_NONE][0]['value']));
            $productNumber = urlencode($query_string_elements['itemnumber']);
            $serialNumber = urlencode($query_string_elements['infoCode']);
            $purchaseDate = urlencode(check_plain($values_submitted['strPurchaseDate']));

            if ($individualId == '' || $productNumber == '' || $serialNumber == '') {
              $status_with_results['status'] = 'arguments_not_supplied';
            }
            $http_result = new stdClass();
            $http_result->code = 200;
            $result = fnet_sfdc_register_product($user->mail, $productNumber, $purchaseDate, $serialNumber);
            if ($result) {
              $doc = $productNumber;
            }
            else {
              $doc = '';
            }
            if (!empty($http_result->data)) {
              $doc = simplexml_load_string($http_result->data);
            }
            $doc = check_plain(trim($doc));
            if ($doc === FALSE) {
              $issue_occured_at = 'Error parsing the XML for URL when registering a product from within "Activate an option" flow.';
              fnet_ma_save_errors_to_watch_dog_and_email_to_admin($url, $issue_occured_at . "<br /><br />" . $http_result->data);
              $status_with_results['status'] = 'error_in_parsing_XML';
            }
            else {
              if ($doc != '') {
                $status_with_results['status'] = 'success';
              }
              else {
                $status_with_results['status'] = 'error';
              }
            }
          }
        }

        /**
         * Email interaction between User/Admin
         * and System when the Gold Type POP code
         * is submitted.
         */
        if (check_plain(trim($values_submitted['hidden_gold_type_product_group_code'])) != '') {
          $email_status = fnet_ma_send_pop_code_emails($values_submitted);
        }

        $query = array(
          'step' => $query_string_elements['step'],
          'POPcode' => $query_string_elements['POPcode'],
          'ProductCode' => $query_string_elements['ProductCode'],
          'OptionCode' => $query_string_elements['OptionCode'],
          'status' => 'success',
        );
        drupal_goto($main_url_of_step_three, array('query' => $query));
      }
      else {
        /**
         * This use case is when user has fails to
         * submitted the form and the form values are NOT
         * stored/inserted in the Database.
         */
        $path = isset($_GET['q']) ? $_GET['q'] : '<front>';
        $main_url_of_step_three = url($path, array('absolute' => TRUE));
        $query_string_elements = array();
        $query_string_elements['step'] = 'three';
        $query_string_elements['ProductCode'] = check_plain($_GET['ProductCode']);
        $query_string_elements['OptionCode'] = check_plain($_GET['OptionCode']);
        $query_string_elements['POPcode'] = check_plain($_GET['POPcode']);

        $query = array(
          'step' => $query_string_elements['step'],
          'POPcode' => $query_string_elements['POPcode'],
          'ProductCode' => $query_string_elements['ProductCode'],
          'OptionCode' => $query_string_elements['OptionCode'],
          'status' => 'failure',
        );
        $message = t('There was some error, please try again after some time, Thanks.');
        drupal_set_message($message, 'error', TRUE);
        drupal_goto($main_url_of_step_three, array('query' => $query));
      }
    }
  }
  else {
    fnet_ma_save_errors_to_watch_dog_and_email_to_admin($url, 'The issue occurred when the web service was trying to insert the profile data along with the Gold Type POP code using the web service - InsertGoldActivationRequest and the reason being unable to access the contents from the Web service./ Web service is down.');
    $status_with_results['status'] = 'webservice_is_down';
    /**
     * This use case is when user has failed to
     * submit the form successfully and the form values are NOT
     * stored/inserted in the Database.
     */
    $path = isset($_GET['q']) ? $_GET['q'] : '<front>';
    $main_url_of_step_three = url($path, array('absolute' => TRUE));
    $query_string_elements = array();
    $query_string_elements['step'] = 'three';
    $query_string_elements['ProductCode'] = check_plain($_GET['ProductCode']);
    $query_string_elements['OptionCode'] = check_plain($_GET['OptionCode']);
    $query_string_elements['POPcode'] = check_plain($_GET['POPcode']);

    $query = array(
      'step' => $query_string_elements['step'],
      'POPcode' => $query_string_elements['POPcode'],
      'ProductCode' => $query_string_elements['ProductCode'],
      'OptionCode' => $query_string_elements['OptionCode'],
      'status' => 'failure',
    );
    drupal_goto($main_url_of_step_three, array('query' => $query));
  }
}

/**
 * Function for checking the POP code supplied by the user using the web service to know if its a valid one or not,
 * this function also for fetches the Product group details based on the POP code supplied by the user
 * using the same web service but by a different parameter supplied in the function call.
 *
 * @param string $proof_of_purchase_code
 * @return array
 */
function fnet_ma_validate_proof_of_purchase_code($proof_of_purchase_code = '') {
  global $user;
  $status_with_results = array();
  $POP_code = trim(str_replace('-', '', check_plain($proof_of_purchase_code)));
  if ($proof_of_purchase_code == '') {
    $status_with_results['status'] = 'pop_code_not_supplied';
    return $status_with_results;
  }
  $domain_url = trim(variable_get("myaccount_webservices_domain_name", 'http://services.test.intranet.danahertm.com'));
  $url = $domain_url . "/ActivateOptions/ActivateOptions.svc/POX/ValidateEnigmaKeyCode?Popcode=" . $POP_code;
  $http_result = drupal_http_request($url, array(
    'headers' => $headers = array(),
    'method' => $method = 'GET',
    'data' => $data = NULL,
    'max_redirects' => $retry = 3
  ));

  if ($http_result->code == 200) {
    $doc = simplexml_load_string($http_result->data);
    if ($doc === FALSE) {
      fnet_ma_save_errors_to_watch_dog_and_email_to_admin($url, 'The issue occurred when the web service was trying to check the POP code supplied by the user to know if its a valid one or not, this function also for fetches the Product group details based on the POP code supplied by the user using the same web service but by a different parameter supplied in the function call and the reason being there was an error in parsing the XML for URL.') . "<br /><br />" . $http_result->data;
      $status_with_results['status'] = 'error_in_parsing_XML';
      return $status_with_results;
    }
    else {
      /**
       * If the first web service function - "ValidateEnigmaKeyCode"
       * finds the POP code to be valid then we test for the Gold
       * Type of that POP code.
       */
      if ($doc->isValidField == 'true') {
        $status_with_results['productCodeField'] = trim(check_plain($doc->productCodeField));
        $status_with_results['infoCodeField'] = trim(check_plain($doc->infoCodeField));
        $status_with_results['optionCodeField'] = trim(check_plain($doc->optionCodeField));

        // If the POP code was valid then check if this POP code belongs to the "Gold Type".
        $gold_type_status = fnet_ma_validate_gold_type_proof_of_purchase_code($POP_code);

        if ($gold_type_status['status'] == 'gold_type_POP_code') {
          /**
           * If the POP code was valid but not a Gold POP code
           * then check if this POP code is already being used by some one using
           * the function - "ValidatePOPCode_OptionActivation".
           */
          $status_with_results['productCodeField'] = trim($doc->productCodeField);
          $status_with_results['infoCodeField'] = trim($doc->infoCodeField);
          $status_with_results['optionCodeField'] = trim($doc->optionCodeField);
          $status_with_results['gold_type_pop_code_item_number'] = $gold_type_status['gold_type_pop_code_item_number'];
          $status_with_results['status'] = 'valid_gold_type_pop_code';
          return $status_with_results;
        }
        elseif ($gold_type_status['status'] == 'POP_code_not_gold_type') {
          /**
           * If the POP code was valid but not a Gold POP code
           * then check if this POP code is already being used by some one using
           * the function - "ValidatePOPCode_OptionActivation".
           */
          $popcode_already_used_status = fnet_ma_validate_proof_of_purchase_code_being_already_used($POP_code, $status_with_results['productCodeField'], $status_with_results['optionCodeField'], $status_with_results['infoCodeField']);
          if ($popcode_already_used_status['status'] == 'pop_code_already_used') {
            $status_with_results['status'] = 'pop_code_already_used';
            $status_with_results['actual_error_message'] = $popcode_already_used_status['actual_error_message'];
            return $status_with_results;
          }
          elseif ($popcode_already_used_status['status'] == 'pop_code_not_used_before') {
            $status_with_results['productCodeField'] = trim($doc->productCodeField);
            $status_with_results['infoCodeField'] = trim($doc->infoCodeField);
            $status_with_results['optionCodeField'] = trim($doc->optionCodeField);
            $status_with_results['status'] = 'POP_code_is_valid';
            return $status_with_results;
          }
        }
        else {
          $status_with_results['status'] = 'error_in_operations';
          return $status_with_results;
        }
      }
      elseif ($doc->isValidField == 'false') {
        $status_with_results['status'] = 'POP_code_is_invalid';
        return $status_with_results;
      }
    }
  }
  else {
    fnet_ma_save_errors_to_watch_dog_and_email_to_admin($url, 'The issue occurred when the web service was trying to check the POP code supplied by the user to know if its a valid one or not, this function also for fetches the Product group details based on the POP code supplied by the user using the same web service but by a different parameter supplied in the function call and the reason being there was an issue in trying to access the contents of the web service URL/Web service was down.');
    $status_with_results['status'] = 'webservice_is_down';
    return $status_with_results;
  }
}

/**
 * Validates Gold based the Proof of Purchase code.
 *
 * @param string $proof_of_purchase_code
 * @return array
 */
function fnet_ma_validate_gold_type_proof_of_purchase_code($proof_of_purchase_code = '') {
  $status_with_results = array();
  $POP_code = trim(str_replace('-', '', check_plain($proof_of_purchase_code)));
  if ($proof_of_purchase_code == '') {
    $status_with_results['status'] = 'pop_code_not_supplied';
    return $status_with_results;
  }
  $domain_url = trim(variable_get("myaccount_webservices_domain_name", 'http://services.test.intranet.danahertm.com'));
  $url = $domain_url . "/ActivateOptions/ActivateOptions.svc/POX/ValidateGoldKeyCode?KeyCode=" . $POP_code;
  $http_result = drupal_http_request($url, array(
    'headers' => $headers = array(),
    'method' => $method = 'GET',
    'data' => $data = NULL,
    'max_redirects' => $retry = 3
  ));

  if ($http_result->code == 200) {
    $doc = simplexml_load_string($http_result->data);
    if ($doc === FALSE) {
      fnet_ma_save_errors_to_watch_dog_and_email_to_admin($url, 'The issue occurred when the web service was trying to check the POP code supplied by the user to be a valid or an invalid one, the reason being there was an error in parsing the XML for URL.') . "<br /><br />" . $http_result->data;
      $status_with_results['status'] = 'error_in_parsing_XML';
      return $status_with_results;
    }
    else {
      if (trim($doc) == 'Null') {
        $status_with_results['status'] = 'POP_code_not_gold_type';
        return $status_with_results;
      }
      elseif (trim($doc) != 'Null') {
        $status_with_results['status'] = 'gold_type_POP_code';
        $status_with_results['gold_type_pop_code_item_number'] = trim($doc);
        return $status_with_results;
      }
    }
  }
  else {
    fnet_ma_save_errors_to_watch_dog_and_email_to_admin($url, 'The issue occurred when the web service was trying to check the POP code supplied by the user to be a valid or an invalid one, the reason being there was an error in accessing the content from the URL/ Web server was down.');
    $status_with_results['status'] = 'webservice_is_down';
    return $status_with_results;
  }
}

/**
 * @param string $proof_of_purchase_code
 * @param string $productCode
 * @param string $optionCode
 * @param string $SerialNumber
 * @return array
 */
function fnet_ma_validate_proof_of_purchase_code_being_already_used($proof_of_purchase_code = '', $productCode = '', $optionCode = '', $SerialNumber = '') {
  $status_with_results = array();
  $POP_code = trim(str_replace('-', '', check_plain($proof_of_purchase_code)));

  if ($proof_of_purchase_code == '' || $productCode == '' || $optionCode == '' || $SerialNumber == '') {
    $status_with_results['status'] = 'all_arguments_not_supplied';
    return $status_with_results;
  }

  $domain_url = trim(variable_get("myaccount_webservices_domain_name", 'http://services.test.intranet.danahertm.com'));
  $url = $domain_url . "/ActivateOptions/ActivateOptions.svc/POX/ValidatePOPCode_OptionActivation" . "?popcode=" . $POP_code . "&productCode=" . $productCode . "&optionCode=" . $optionCode . "&SerialNumber=" . $SerialNumber;
  $http_result = drupal_http_request($url, array(
    'headers' => $headers = array(),
    'method' => $method = 'GET',
    'data' => $data = NULL,
    'max_redirects' => $retry = 3
  ));

  if ($http_result->code == 200) {
    $doc = simplexml_load_string($http_result->data);
    if ($doc === FALSE) {
      fnet_ma_save_errors_to_watch_dog_and_email_to_admin($url, 'The issue occurred when the web service was trying to validate the Gold Type POP code to be already used before from Onyx, the reason being there was an error in parsing the XML for URL.') . "<br /><br />" . $http_result->data;
      $status_with_results['status'] = 'error_in_parsing_XML';
      return $status_with_results;
    }
    else {
      if (trim($doc) == '0') {
        $status_with_results['status'] = 'pop_code_not_used_before';
        return $status_with_results;
      }
      else {
        $status_with_results['status'] = 'pop_code_already_used';
        $status_with_results['actual_error_message'] = trim($doc);
        return $status_with_results;
      }
    }
  }
  else {
    fnet_ma_save_errors_to_watch_dog_and_email_to_admin($url, 'The issue occurred when the web service was trying to validate the Gold Type POP code to be already used before from Onyx, the reason being web service was not able to access the Content from the URL/ Web server was down.');
    $status_with_results['status'] = 'webservice_is_down';
    return $status_with_results;
  }
}

/**
 * @return null|string
 */
function fnet_ma_print_keycodes() {
  $current_form_array = $_REQUEST;
  $html_content = '';

  $enabled_options = trim(check_plain($current_form_array['enabled-options']));
  $activation_date = trim(check_plain($current_form_array['activation-date']));
  $key_code = trim(check_plain($current_form_array['key-code']));
  $product_name = trim(check_plain($current_form_array['product-name']));
  $serialnumber = trim(check_plain($current_form_array['serialnumber']));
  if ($enabled_options == '' || $activation_date == '' || $key_code == '' || $product_name == '' || $serialnumber == '') {
    $html_content = t('Invalid arguments provided.(6)');
    return $html_content;
  }

  $html_content .= '<div id = "fn-myaccount-print-keycode-page-wrapper-div">';
  $html_content .= '<div class = "key-code-print-page-header"><div class = "keycode-print-page-header-one">' . t("FLUKE") . "</div><div id = 'keycode-print-page-header-two'>" . t("networks") . "<span id = 'keycode-print-page-header-three'>&reg;</span></div></div>";
  $html_content .= t("You have purchased the option(s) listed below and successfully<br /> generated the Key Code for your product.") . "<br /><br /><br />";
  $html_content .= "<table width='100%' border='0' cellspacing='0' cellpadding='5' align='center'>";

  $html_content .= "<tr>
                        <td valign='top' align='right' width = '50%'><b>" . t('Product Name :') . "
                        </b></td>
                        <td valign='top' align='left' width = '50%'>" . urldecode(check_plain($current_form_array['product-name'])) . "
                        </td>
                      </tr>";

  $html_content .= "<tr>
                        <td valign='top' align='right' width = '50%'><b>" . t('Serial Number :') . "
                        </b></td>
                        <td valign='top' align='left' width = '50%'>" . urldecode(check_plain($current_form_array['serialnumber'])) . "
                        </td>
                      </tr>";

  $html_content .= "<tr>
                        <td valign='top' align='right' width = '50%'><b>" . t('Enabled Options :') . "
                        </b></td>
                        <td valign='top' align='left' width = '50%'>" . urldecode(check_plain($current_form_array['enabled-options'])) . "
                        </td>
                      </tr>";

  $html_content .= "<tr>
                        <td valign='top' align='right' width = '50%'><b>" . t('Activation Date :') . "
                        </b></td>
                        <td valign='top' align='left' width = '50%'>" . urldecode(check_plain($current_form_array['activation-date'])) . "
                        </td>
                      </tr>";

  $html_content .= "<tr>
                        <td valign='top' colspan = '2' width = '100%' >" . "<span class='keycode-text'>" . t("Key Code") . "</span>
                        </td>
                      </tr>";

  $html_content .= "<tr>
                        <td valign='top' colspan = '2' width = '100%'>
                          <span class='keycode-text'>" . implode("-", str_split(urldecode(trim(check_plain($current_form_array['key-code']))), 4)) . "</span>
                        </td>
                      </tr>";
  global $base_root;
  $main_path = $base_root . request_uri();
  $html_content .= "<tr>
                        <td valign='top' colspan = '2' align='center' width = '100%'>" . l('<div class="customfn-buttons" id = "keycode-print-button">' . t("Print") . "</div>", $main_path, array(
      'attributes' => array("onclick" => "window.print();"),
      'html' => TRUE
    )) . "</td>
                      </tr>";
  $html_content .= "</table>";
  $html_content .= "</div>";
  return $html_content;
}

/**
 * This function will check if whether any product is registered
 * for the product group code, and it returns a product number.
 *
 * @param string $productGroupCode
 * @param string $onyx_individualId
 * @return array
 */
function fnet_ma_verify_has_registered_product_for_prd_group($productGroupCode = '', $onyx_individualId = '') {
  $status_with_results = array();
  if ($productGroupCode == '' || $onyx_individualId == '') {
    $status_with_results['status'] = 'required_parameters_not_supplied';
    return $status_with_results;
  }

  $domain_url = trim(variable_get("myaccount_webservices_domain_name", 'http://services.test.intranet.danahertm.com'));
  $url = $domain_url . "/ActivateOptions/ActivateOptions.svc?wsdl";
  try {
    $soap_options = array('connection_timeout' => variable_get('myaccount_soap_connection_timeout', 20));
    $client = @new soapclient($url, $soap_options);
    $my_result = $client->HasRegisteredProductForPrdGroup(array(
      'productGroupCode' => $productGroupCode,
      'individualId' => $onyx_individualId,
      'siteId' => 1,
    ));
    $tidy_options = array(
      'input-xml' => TRUE,
      'output-xml' => TRUE,
      'indent' => TRUE,
      'wrap' => TRUE,
      "char-encoding" => TRUE,
      "wrap" => 0,
    );
    $tidy = new tidy();
    $tidy->parseString($my_result->HasRegisteredProductForPrdGroupResult->any, $tidy_options);
    $tidy->cleanRepair();
    $xml_string = $tidy;
    $doc = simplexml_load_string($xml_string->value);
    if (trim(check_plain($doc->prodDetails->Table->chProductNumber)) != '') {
      $status_with_results['status'] = 'products_already_registered_within_supplied_product_group';
      $status_with_results['chProductNumber'] = trim(check_plain($doc->prodDetails->Table->chProductNumber));
      return $status_with_results;
    }
    else {
      $status_with_results['status'] = 'no_products_registered_within_supplied_product_group';
      return $status_with_results;
    }
  } catch (Exception $e) {
    fnet_ma_save_errors_to_watch_dog_and_email_to_admin($url, 'The issue occurred when the web service was trying to check if whether any product is registered for the product group code and if yes then it returns a product number for the logged in user and the reason is as follows: ' . $e->getMessage());
    $status_with_results['status'] = 'webservice_exception_error';
    return $status_with_results;
  }
}

/**
 * Function for fetching the product details upon successful validation of pop code,
 * this service method will extract the  product details like product group name,
 * option name, product group code and image.
 *
 * @param string $ProductCode
 * @param string $OptionCode
 * @return array
 */
function fnet_ma_fetch_product_information_based_on_POPcode($ProductCode = '', $OptionCode = '') {
  $status_with_results = array();
  if ($ProductCode == '' || $OptionCode == '') {
    $status_with_results['status'] = 'required_parameters_not_supplied';
    return $status_with_results;
  }

  $domain_url = trim(variable_get("myaccount_webservices_domain_name", 'http://services.test.intranet.danahertm.com'));
  $url = $domain_url . "/ActivateOptions/ActivateOptions.svc?wsdl";
  try {
    $soap_options = array('connection_timeout' => variable_get('myaccount_soap_connection_timeout', 20));
    $client = @new soapclient($url, $soap_options);
    $my_result = $client->GetProdGroup_OptionActivation(array(
      'productCode' => $ProductCode,
      'optionCode' => $OptionCode
    ));
    $tidy_options = array(
      'input-xml' => TRUE,
      'output-xml' => TRUE,
      'indent' => TRUE,
      'wrap' => TRUE,
      "char-encoding" => TRUE,
      "wrap" => 0,
    );
    $tidy = new tidy();
    $tidy->parseString($my_result->GetProdGroup_OptionActivationResult->any, $tidy_options);
    $tidy->cleanRepair();
    $xml_string = $tidy;
    $doc = simplexml_load_string($xml_string->value);
    if (check_plain($doc->ProdGroup->Table->vchHierarchyDesc) != '') {
      return $doc->ProdGroup->Table;
    }
    else {
      return array();
    }
  } catch (Exception $e) {
    fnet_ma_save_errors_to_watch_dog_and_email_to_admin($url, 'An issue occurred when the web service was trying to fetch the product details upon successful validation of POP code, this service method will extract the  product details like product group name, option name, product group code and image &  the reason is as follows: ' . $e->getMessage());
    return array("-1" => 'webservice_exception_error');
  }
}

/**
 * @param $proof_of_purchase_code
 * @return array
 */
function fnet_ma_verify_gold_type_popcode_already_activated_status($proof_of_purchase_code) {
  global $user;
  $status_with_results = array();
  $POP_code = trim(str_replace('-', '', check_plain($proof_of_purchase_code)));
  if ($proof_of_purchase_code == '') {
    $status_with_results['status'] = 'pop_code_not_supplied';
    return $status_with_results;
  }
  $domain_url = trim(variable_get("myaccount_webservices_domain_name", 'http://services.test.intranet.danahertm.com'));
  $url = $domain_url . "/ActivateOptions/ActivateOptions.svc/POX/GetSalesOrderNo?KeyCode=" . $POP_code;
  $http_result = drupal_http_request($url, array(
    'headers' => $headers = array(),
    'method' => $method = 'GET',
    'data' => $data = NULL,
    'max_redirects' => $retry = 3
  ));

  if ($http_result->code == 200) {
    $doc = simplexml_load_string($http_result->data);
    if ($doc === FALSE) {
      fnet_ma_save_errors_to_watch_dog_and_email_to_admin($url, 'The issue occurred when the web service was trying to fetch the status of Gold Type POP code to know that if its already activated or NOT and the reason being the web service was not able to parse the XML in the result.') . "<br /><br />" . $http_result->data;
      $status_with_results['status'] = 'error_in_parsing_XML';
      return $status_with_results;
    }
    else {
      /**
       * If the first web service function - "ValidateEnigmaKeyCode"
       * finds the POP code to be valid then we test for the Gold
       * Type of that POP code.
       */
      if (trim($doc[0]) != '') {
        $status_with_results['status'] = trim(check_plain(trim($doc[0])));
        return $status_with_results;
      }
    }
  }
  else {
    fnet_ma_save_errors_to_watch_dog_and_email_to_admin($url, 'The issue occurred when the web service was trying to fetch the status of Gold Type POP code to know that if its already activated or NOT and the reason being the web service was not able to access the content/web server is down.');
    $status_with_results['status'] = 'webservice_is_down';
    return $status_with_results;
  }

}

/**
 * @param string $productnumber
 * @return array
 */
function fnet_ma_registered_products_in_product_group($productnumber = '') {
  $resultant_array = array();
  $current_form_array = $_REQUEST;
  if ($productnumber == '') {
    $resultant_array['status'] = 'error';
    $resultant_array['message'] = "<span class = 'red-text'>" . t('A required paramater - "Product Group code" is missing, please try again.') . "</span><br />";
    return $resultant_array;
  }

  global $user;
  $individual_id = $user->field_user_onyx_id[LANGUAGE_NONE][0]['value'];
  $html_listing = '';
  $domain_url = trim(variable_get("myaccount_webservices_domain_name", 'http://services.test.intranet.danahertm.com'));
  $url = $domain_url . "/ActivateOptions/ActivateOptions.svc?wsdl";
  try {
    $soap_options = array('connection_timeout' => variable_get('myaccount_soap_connection_timeout', 20));
    $client = @new soapclient($url, $soap_options);
    $my_result = $client->GetProductGroupDetails(array(
      'individualid' => $individual_id,
      'productnumber' => $productnumber
    ));
    $tidy_options = array(
      'input-xml' => TRUE,
      'output-xml' => TRUE,
      'indent' => TRUE,
      'wrap' => TRUE,
      "char-encoding" => TRUE,
      "wrap" => 0,
    );
    $tidy = new tidy();
    $tidy->parseString($my_result->GetProductGroupDetailsResult->any, $tidy_options);
    $tidy->cleanRepair();
    $xml_string = $tidy;
    $doc = simplexml_load_string($xml_string->value);

    if (trim(check_plain($doc->NewDataSet->Table[0]->chProductNumber)) == $productnumber) {
      $simple_master_array = array();
      $count = 0;
      foreach ($doc->NewDataSet->Table as $key => $value) {
        $simple_master_array[$count] = $value;
        $count++;
      }
      $html_listing .= "
      <div class = 'full-available-width'>
          <table class = 'all_contracts_listing_table' class = 'full-available-width' border='0' cellspacing='0' cellpadding='5'>";


      $html_listing .= "
              <tr>
                <td valign='top' class='tableHead' width='33%'>
                  " . t("Serial Number") . "
                </td>
                <td valign='top' class='tableHead' width='33%'>
                   " . t("Registration Date") . "
                </td>
                <td valign='top' class='tableHead' width='33%'>
                   " . t("Activation") . "
                </td>
             </tr>";
      if (count($simple_master_array)) {
        foreach ($simple_master_array as $key => $value) {
          // Fetch the header title
          $header_title = check_plain(trim($value->vchDescription));

          // Format the Date as per requirment before they get displayed on listing page.
          $insert_date_time = check_plain(trim($value->dtPurchaseDate));
          $insert_date_time = explode("T0", $insert_date_time);
          $insert_date_time = explode("-", $insert_date_time[0]);
          $final_insert_date_time_value = $insert_date_time[1] . '/' . $insert_date_time[2] . '/' . $insert_date_time[0];

          // Get the list of all products configured in LMS.
          $lms_product_ID_array = fnet_ma_fetch_LMS_product_ids();
          $activate_an_option_link = '';
          if (count($lms_product_ID_array) != 0) {
            if (in_array($productnumber, $lms_product_ID_array)) {
              $query = array(
                'step' => 'four',
                'POPcode' => trim(check_plain($current_form_array['POPcode'])),
                'ocp' => $value->iProductId,
                'serialNumber' => $value->vchSerialNumber,
                'model-number' => $value->chProductNumber,
              );
              $actual_link = "user/" . $user->uid . "/activate-product";
              $activate_an_option_link = l('Activate an Option', $actual_link, $options = array('query' => $query));
            }
          }

          $html_listing .= "
                <tr>
                  <td valign='top'>
                    " . $value->vchSerialNumber . "
                  </td>
                  <td valign='top'>
                    " . $final_insert_date_time_value . "
                  </td>
                  <td valign='top'>
                     " . $activate_an_option_link . "
                  </td>
               </tr>";
        }
      }
      $html_listing .= "
          </table>
      </div>";
      $resultant_array['message'] = $html_listing;
      $resultant_array['header_title'] = $header_title;
      $resultant_array['status'] = 'success';
      return $resultant_array;
    }
    else {
      $resultant_array['status'] = 'error';
      $resultant_array['message'] = "<span class = 'red-text'>" . t("Activating an option for this device is currently not available from My Account. For assistance, please email fnetlicensing@flukenetworks.com or call 800-283-5853 (U.S. and Canada) or 425-446-4519 (outside U.S. and Canada). ") . "</span><br />";
      return $resultant_array;
    }
  } catch (Exception $e) {
    fnet_ma_save_errors_to_watch_dog_and_email_to_admin($url, 'The issue occurred when the web service was trying to fetch already registered products within a product group for a logged in user and the reason is as follows: ' . $e->getMessage());
    $resultant_array['status'] = 'error';
    $resultant_array['message'] = "<span class = 'red-text'>" . variable_get('myaccount_webservices_failure_notification_message', t('Our apologies. Your request is not currently available. A notification has been delivered to our web team to correct. If you need immediate assistance please call us at +1 425 446-4519.')) . "</span><br />";
    return $resultant_array;
  }
}

/**
 * @return string
 */
function flukenetworks_myaccount_activate_option_page() {
  $mail_to_link = l('fnetlicensing@flukenetworks.com', 'mailto:fnetlicensing@flukenetworks.com');
  $output = '';
  $output .= '<div class="myaccount-activation-message">';
  $output .= '<h1>Activate a purchased option</h1>';
  $output .= '<p>To activate a purchased option please email your Fluke Networks Proof of Purchase Code (16 digits) ';
  $output .= 'and the Serial Number (7 digits) to ' . $mail_to_link . ' or call us direct at 800.283.5853 for assistance.</p>';
  $output .= '</div>';
  return $output;
}