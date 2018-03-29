<?php

/**
 * @file
 * AJAX backend for product_distributor module: FNET WTB AJAX backend.
 */

/**
 * AJAX Callback handler: Get regions in a country.
 *
 * This will only be used only if Storefront buying method is selected.
 *
 * @param null $country_code
 *   The code used to represent this country.
 *
 * @return array
 *   A list of regions from this country code.
 */
function wheretobuy_get_regions($country_code = NULL) {
  if ($country_code) {
    // Check if country marked to 'Skip region search'.
    $flagged_countries = variable_get('wtb_countries_skip_region', []);
    if ((isset($flagged_countries[$country_code])) && ($flagged_countries[$country_code] != 0)) {
      return [
        'status' => FALSE,
        'submitCallback' => $flagged_countries[$country_code],
        //'get_distributors',
        'submitCallbackData' => FALSE,
      ];
    }
    else {
      // Make sure the country code isn't upper case.
      // $country_code = strtolower($country_code);
      $administrative_areas = addressfield_get_administrative_areas($country_code);
      // Filter out regions which will be treated as countries.
      if ($country_code == 'US') {
        $filtered_regions = [
          'AS' => 'American Samoa',
          'FM' => 'Federated States of Micronesia',
          'GU' => 'Guam',
          'MH' => 'Marshall Islands',
          'MP' => 'Northern Mariana Islands',
          'PW' => 'Palau',
          'PR' => 'Puerto Rico',
          'VI' => 'Virgin Islands',
        ];
        foreach ($filtered_regions as $key => $val) {
          unset($administrative_areas[$key]);
        }
      }
      if (!empty($administrative_areas)) {
        // Sort the areas.
        asort($administrative_areas);
        $administrative_areas = [0 => '--Select a Region--'] + $administrative_areas;
      }
      $choice_form = [
        '#type' => 'select',
        '#attributes' => ['id' => 'edit-regions'],
        '#title' => t('Select a Region'),
        '#options' => $administrative_areas,
      ];
      $output = drupal_render($choice_form);

      // Final rendering callback.
      if (empty($administrative_areas)) {
        // No provinces found in the Selected Country: ERROR matrix case 1 ?
        return [
          'status' => FALSE,
          'submitCallback' => 'wtb_error_message',
          'submitCallbackData' => 'error_id=1',
        ];
      }
      else {
        return [
          'status' => TRUE,
          'data' => $output,
        ];
      }
    }
  }
}

/**
 * AJAX Callback handler.
 *
 * Get cities in a region of a country based on the country and product
 * in the GET array. Returns a json array of cities.
 *
 * Example URL: /wheretobuy_ajax/get_cities?country=ES&product=88928&buying=S%7CO%7CN&region=B
 */
function wheretobuy_get_cities() {
  $country = $_GET['country'];
  // Query on this at the end.
  $product = isset($_GET['product']) ? $_GET['product'] : 0;
  $sales_channel = isset($_GET['channel']) ? $_GET['channel'] : 0;
  $region = isset($_GET['region']) ? $_GET['region'] : '';
  // Not to be used in Query.
  $buying_method = $_GET['buying'];
  $json_arr = [];

  if ($country && $region && $product && $buying_method) {
    $buying_methods = explode('|', $buying_method);
    if (in_array('N', $buying_methods) && !in_array('S', $buying_methods)) {
      // If only buying method 'national default' is present, show Go button.
      $json_arr += [
        'status' => FALSE,
        'submitCallback' => 'get_distributors',
        'submitCallbackData' => FALSE,
      ];
      echo json_encode($json_arr);
      exit;
    }
    else {
      // Else, only buying method that should be considered is S => Storefront.
      $buying_method = 'S';
    }
    $nds_found = FALSE;
    $cities = [];
    if ($product == 0) {
      // Handle error: Product dd option not selected.
      $output = 'Please select a Product!';
      echo json_encode([
        'status' => FALSE,
        'data' => $output,
      ]);
      exit;
    }

    if ($pnode = node_load($product)) {
      // Get list of locations supplying the product.
      // Array of location nids.
      $locations = get_product_locations($pnode->nid);
      // $json_arr['test'] = $locations;
      // Filter the locations according to the filtering criteria.
      if (!empty($locations)) {
        $query = db_select('node', 'n')->distinct();
        $query->join('field_data_field_address', 'address', 'address.entity_id = n.nid AND address.revision_id = n.vid');
        $query->join('field_data_field_delivery_type', 'cfdt', 'cfdt.entity_id = n.nid AND cfdt.revision_id = n.vid');
        $query
          ->fields('address', ['field_address_locality'])
          ->condition('n.status', 1, '=')
          ->condition('address.field_address_country', $country, '=')
          ->condition('cfdt.field_delivery_type_value', 'S', '=')
          ->condition('address.field_address_locality', '', '<>')
          ->condition('address.field_address_administrative_area', $region, '=');
        // $query->orderBy('address.field_address_locality');
        /*
        if ($country == 'US' && $sales_channel == 1) {
        $query->join('field_data_field_gsa_schedule', 'ctd5',
        'ctd5.entity_id = n.nid AND ctd5.revision_id = n.vid');
        $query->condition('ctd5.field_gsa_schedule_value', 1, '=');
        }

        if ($product != -1) {
        $query->condition('n.nid', $locations, 'IN');
        }
         */
        $results = $query->execute();

        // Generate the array of cities for the form.
        foreach ($results as $data) {
          if (trim($data->field_address_locality) != '') {
            $cities[$data->field_address_locality] = $data->field_address_locality;
          }
        }
        $json_arr['test'] = $cities;
        if (!empty($cities)) {
          $cities = [
            0 => '--Select a City--',
            -1 => 'All',
          ] + $cities;
        }
        $choice_form = [
          '#type' => 'select',
          '#attributes' => ['id' => 'edit-cities'],
          '#title' => t('Select a City'),
          '#options' => $cities,
        ];
        $output = drupal_render($choice_form);
      }
    }

    // Final rendering callback.
    /* No cities have been found for the region. Get the count of storefronts. */
    if (empty($cities)) {
      $region_query = db_select('node', 'n');
      $region_query->join('field_data_field_address', 'address', 'address.entity_id = n.nid ANd address.revision_id = n.vid');
      $region_query->join('field_data_field_delivery_type', 'cfdt', 'cfdt.entity_id = n.nid AND cfdt.revision_id = n.vid');
      $region_query
        ->fields('address', ['field_address_administrative_area'])
        ->condition('n.status', 1, '=')
        ->condition('address.field_address_country', $country, '=')
        ->condition('cfdt.field_delivery_type_value', 'S', '=')
        ->condition('address.field_address_administrative_area', '', '<>');

      // GSA Only results.
      if ($country == 'US' && $sales_channel == 1) {
        $region_query->join('field_data_field_gsa_schedule', 'fdfgs', 'fdfgs.entity_id = n.nid AND fdfgs.revision_id = n.vid');
        $region_query->condition('fdfgs.field_gsa_schedule_value', 1, '=');
      }
      if ($product != -1) {
        $region_query->condition('n.nid', $locations, 'IN');
      }

      $storefronts_in_country = $region_query->countQuery()
        ->execute()
        ->fetchField();
      /* For testing.
      $output = 'Storefronts in country: ' . $storefronts_in_country;
       */

      $json_arr += [
        'status' => FALSE,
        'storefrontsInCountry' => $storefronts_in_country,
        // Expected response is Integer.
        'submitCallback' => 'get_distributors',
        'submitCallbackData' => FALSE,
      ];
      echo json_encode($json_arr);
      exit;
    }
    else {
      $json_arr += [
        'status' => TRUE,
        'data' => $output,
        'submitCallback' => FALSE,
        'submitCallbackData' => FALSE,
      ];
      echo json_encode($json_arr);
      exit;
    }
  }
}

/**
 * The parameters to this function are passed via GET method only.
 */
function get_national_distributors($type = NULL, $data_nids = NULL) {
  // Search if National Distributors are present.
  $country = $_GET['country'];
  // Query on this at the end.
  $product = $_GET['product'];
  // To be used in Query: Set buying method as national distributor.
  $delivery_type = 'N';
  $sales_channel = isset($_GET['channel']) ? $_GET['channel'] : 0;
  $nds_found = FALSE;
  $output = '';
  if ($product == 0) {
    // Handle error: Product dd option not selected.
    $output = 'Please select a Product!';
    return [
      'status' => FALSE,
      'errorData' => $output,
    ];
  }

  if ($product != -1) {
    $pnode = node_load($product);
    // Get list of locations supplying the product.
    // array of location nids.
    $locations = get_product_locations($pnode->nid);
  }
  // Filter the locations according to the filtering criteria.
  // TODO: Rewrite this.
  if (!empty($locations)) {
    $query = db_select('node', 'n')
      ->fields('n', ['nid']);
    $query->join('field_data_field_address', 'address', 'address.entity_id = n.nid ANd address.revision_id = n.vid');
    $query->join('field_data_field_stocking_rating', 'stocking', 'stocking.entity_id = n.nid AND stocking.revision_id = n.vid');
    $query->join('field_data_field_salesforce_rating', 'salesforce', 'salesforce.entity_id = n.nid AND salesforce.revision_id = n.vid');
    $query->join('field_data_field_distributor_type_rating', 'distributor', 'distributor.entity_id = n.nid AND distributor.revision_id = n.vid');
    $query->join('field_data_field_point_of_sale_rating', 'pos', 'pos.entity_id = n.nid AND pos.revision_id = n.vid');
    $query->join('field_data_field_delivery_type', 'delivery', 'delivery.entity_id = n.nid AND delivery.revision_id = n.vid');
    if ($country == 'US' && $sales_channel == 1) {
      $query->join('field_data_field_gsa_schedule', 'gsa', 'gsa.entity_id = n.nid AND gsa.revision_id = n.vid');
      $query->condition('gsa.field_gsa_schedule_value', 1, '=');
    }
    $query
      ->condition('n.status', 1, '=')
      ->condition('address.field_address_country', $country, '=')
      ->condition('delivery.field_delivery_type_value', $delivery_type, '=');
    if ($product != -1) {
      $query->condition('n.nid', $locations, 'IN');
    }
    $query->orderBy('(stocking.field_stocking_rating_value+salesforce.field_salesforce_rating_value+distributor.field_distributor_type_rating_value+pos.field_point_of_sale_rating_value)', 'DESC');
    $query->orderBy('n.title', 'ASC');
    $results = $query->execute();

    $data_arr = [];

    foreach ($results as $data) {
      // Skip if result already contains the location nid.
      if (in_array($data->nid, $data_nids)) {
        continue;
      }
      else {
        $data_nids[] = $data->nid;
      }

      $dnode = node_load($data->nid);
      /*
      // TODO: This language stuff is going to be a problem later on. We'll want to fix it soon. -rositis
      // If the URL doesn't have http:// on the front, tack it on.
      if (!strstr($dnode->field_website_url[LANGUAGE_NONE][0]['value'], 'http://')) {
        $dnode->field_website_url[LANGUAGE_NONE][0]['value'] = 'http://' . $dnode->field_website_url[LANGUAGE_NONE][0]['value'];
      }
      if (!strstr($dnode->field_buy_online_url[LANGUAGE_NONE][0]['value'], 'http://')) {
        $dnode->field_buy_online_url[LANGUAGE_NONE][0]['value'] = 'http://' . $dnode->field_buy_online_url[LANGUAGE_NONE][0]['value'];
      }

      $location_street = '';
      if (trim($dnode->location['street']) != '') {
        $location_street .= $dnode->location['street'];
      }
      if (trim($dnode->location['additional']) != '') {
        if (trim($dnode->location['street']) != '') {
          $location_street .= '<br/>';
        }
        $location_street .= $dnode->location['additional'];
      }

      $data_arr[] = array(
        'nid' => $dnode->nid,
        'type' => 'N',
        'is_online' => is_online_location($dnode),
        'name' => $dnode->field_display_name[LANGUAGE_NONE][0]['value'],
        'address' => $location_street . '<br/>' . $dnode->location['city'] . ', ' . $dnode->location['province_name'] . ' ' . $dnode->location['postal_code'] . '<br/>' . $dnode->location['country_name'],
        'toll_free_phone' => $dnode->field_toll_free_phone[LANGUAGE_NONE][0]['value'],
        'phone' => $dnode->location['phone'],
        'fax' => $dnode->location['fax'],
        'email' => !empty($dnode->field_email_contact) ? trim($dnode->field_email_contact[LANGUAGE_NONE][0]['value']) : '',
        'url' => (strlen(trim($dnode->field_website_url[LANGUAGE_NONE][0]['value'])) > 7) ? trim($dnode->field_website_url[LANGUAGE_NONE][0]['value']) : '',
        'buy_online_url' => (strlen(trim($dnode->field_buy_online_url[LANGUAGE_NONE][0]['value'])) > 7) ? trim($dnode->field_buy_online_url[LANGUAGE_NONE][0]['value']) : '',
      );
      */
    }
    if (count($data_arr)) {
      $nds_found = TRUE;
      return [
        'status' => TRUE,
        'data' => $data_arr,
      ];

    }
  }
  // Cleanup of below code might be required.
  // Set Error message.
  if ($type == NO_REGIONS_IN_COUNTRY) {
    $error_msg = 'No distributors are available in the selected country.';
  }
  elseif ($type == NO_RESULTS_FOR_PROXIMITY_SEARCH) {
    $error_msg = "This product is not available through the buying method you chose. Please try again or contact Fluke Networks directly for more information.";
  }
  else {
    $error_msg = 'No distributors are available in the selected region.';
  }

  if ($nds_found) {
    return [
      'status' => TRUE,
      'data' => $output,
    ];
  }
  else {
    return [
      'status' => FALSE,
      'errorData' => $error_msg,
    ];
  }
}

/**
 * AJAX Callback handler: Get available delivery types in a country.
 *
 * Example URL: /wheretobuy_ajax/get_delivery_types?country=US&product=88928
 */
function wheretobuy_get_delivery_types() {
  $country_code = $_GET['country'];
  $product_code = $_GET['product'] ? $_GET['product'] : 0;
  $image = '';
  $json_arr = [];
  if ((isset($country_code)) && (isset($product_code))) {

    // Image section.
    if ($product_code > 0) {
      $img_query = 'SELECT
        ctp.field_prod_wtb_img_fid fid,
        ctp.field_prod_wtb_img_alt alt,
        ctp.field_prod_wtb_img_title title,
        ctp.field_prod_wtb_img_width width,
        ctp.field_prod_wtb_img_height height,
        f.uri uri
        FROM {node} n
        INNER JOIN {field_data_field_prod_wtb_img} ctp ON ctp.entity_id = n.nid AND ctp.revision_id = n.vid
        INNER JOIN {file_managed} f ON f.fid = ctp.field_prod_wtb_img_fid
        WHERE n.nid = :product_code';
      $iresult = db_query($img_query, [':product_code' => $product_code]);

      if ($idata = (object) $iresult->fetchObject()) {
        if (isset($idata->uri)) {
          // Needs attributes or it blows up.
          $image = theme_image([
            'path' => $idata->uri,
            'width' => $idata->width,
            'height' => $idata->height,
            'alt' => $idata->alt,
            'title' => $idata->title,
            'attributes' => [],
          ]);
        }
      }

      // Use first carousel image if WTB image is not available.
      // TODO: Look closely at this.
      if (empty($image)) {
        $idata = (object) db_query('SELECT ctp.field_prod_carousel_img_lg_1_fid, f.uri'
          . ' FROM {node} n, {field_data_field_prod_carousel_img_lg_1} ctp'
          . ' INNER JOIN {file_managed} f ON f.fid = ctp.field_prod_carousel_img_lg_1_fid'
          . ' WHERE ctp.entity_id = n.nid AND ctp.revision_id = n.vid AND ctp.entity_id = :productCode ', [':productCode' => $product_code])->fetchObject();

        if (isset($idata->filepath)) {
          $image = theme_image([
            'path' => $idata->filepath,
            'width' => '',
            'height' => '',
            'alt' => '',
            'title' => '',
            'attributes' => [],
          ]);

        }
      }
      // Add image to json array.
      if ($image != '') {
        $json_arr += [
          'image' => $image,
        ];
      }

      // GET Flag to decide whether to show Price spider WTB button
      // or traditional functionality on WTB page.
      $wtb_check_query = "SELECT fdipsc.field_include_price_spider_code_value code
        FROM {field_data_field_include_price_spider_code} fdipsc
        WHERE fdipsc.entity_id = :product_code";
      $wtb_check_result = db_query($wtb_check_query, [':product_code' => $product_code])->fetchAssoc();
      $wtb_check_output = $wtb_check_result['code'];
      $json_arr += ['wtbcheck' => $wtb_check_output];

      // GET PRODUCT MODEL FOR PRICE SPIDER WTB BUTTON TO WORK.
      $ps_query = "SELECT field_wtb_ps_model_sku_value sku
        FROM {field_data_field_wtb_ps_model_sku} fdfwpm
        WHERE fdfwpm.entity_id = :product_code";
      $ps_result = db_query($ps_query, [':product_code' => $product_code])->fetchAssoc();
      $ps_output = $ps_result['sku'];
      $json_arr += ['psmodel' => $ps_output];

      // Not available for distribution.
      $gresults = db_query('SELECT n.nid FROM {node} n'
        . ' INNER JOIN {field_data_field_do_not_distribute} cfdnd ON cfdnd.revision_id = n.vid AND cfdnd.field_do_not_distribute_value = :dndValue '
        . ' WHERE n.nid = :productCode AND n.status = 1',
        [
          ':dndValue' => strtolower($country_code),
          ':productCode' => $product_code,
        ]);

      if ($gresults->rowCount() > 0) {
        $json_arr += [
          'status' => FALSE,
          'deliveryTypes' => FALSE,
          'submitCallback' => 'wtb_error_message',
          'submitCallbackData' => 'error_id=0',
        ];
        echo json_encode($json_arr);
        exit;
      }
    }

    // Address query.
    $address_query = "SELECT DISTINCT(delivery.field_delivery_type_value)
      FROM {field_data_field_delivery_type} delivery
      INNER JOIN {field_data_field_address} address ON address.entity_id = delivery.entity_id
      AND address.revision_id = delivery.revision_id
      INNER JOIN {node} n ON n.vid = delivery.revision_id
      WHERE address.field_address_country = :country
      AND n.status = 1";
    $results = db_query($address_query, [':country' => strtoupper($country_code)]);

    $items = [];
    foreach ($results as $data) {
      $val = '';
      $key = $data->field_delivery_type_value;
      switch ($key) {
        case 'O':
          $val = 'Online';
          break;

        case 'S':
          $val = 'Storefront';
          break;

        case 'N':
          $val = 'National Default';
          break;
      }
      if ($val != '') {
        $items[$key] = $val;
      }
    }
    arsort($items);

    if (empty($items)) {
      // Buying methods not found.
      $json_arr += [
        'status' => FALSE,
        'deliveryTypes' => FALSE,
        'submitCallback' => 'wtb_error_message',
        'submitCallbackData' => 'error_id=1',
      ];
    }

    else {
      // Buying methods found.
      $delivery_types = array_keys($items);
      $json_arr += [
        'deliveryTypes' => implode('|', $delivery_types),
      ];

      if ((count($items) == 1) && (isset($items['O']))) {
        // Only online buying method present: Show go button.
        $json_arr += [
          'status' => FALSE,
          'submitCallback' => 'feck', //'get_distributors',
          'submitCallbackData' => FALSE,
        ];
      }

      else {
        // Storefront/National Default buying methods present:
        // Try to dislay region drop-down.
        $tmp = wheretobuy_get_regions($country_code);

        if ((isset($tmp['status'])) && (isset($tmp['data']))) {
          $json_arr += [
            'status' => TRUE,
            'data' => $tmp['data'],
          ];
        }
        else {
          // No regions found OR Skip region search: Show go button.
          $json_arr += [
            'status' => FALSE,
            'submitCallback' => $tmp['submitCallback'],
            'submitCallbackData' => $tmp['submitCallbackData'],
          ];
        }
      }
    }
  }
  else {
    $json_arr += [
      'status' => FALSE,
      'deliveryTypes' => FALSE,
      'errorData' => 'Please select a product',
    ];
  }
  echo json_encode($json_arr);
}

/**
 * AJAX Callback handler.
 *
 * Get search results for Distributors
 * Refer requirement specification document.
 */
function wheretobuy_get_distributors() {
  $buying_methods = explode('|', $_GET['buying']);
  $country = $_GET['country'];
  $online_results = FALSE;
  $storefront_results = FALSE;
  $national_default_results = FALSE;
  $data_nids = [];
  $data_arr = [];
  $invalid_postal_code = FALSE;

  // Check if postal_code search and validate postal code.
  if (isset($_GET['postal'])) {
    $invalid_postal_code = TRUE;
    if (ltrim($_GET['postal'], '0') <= 99999) {
      $address = $country . ' ' . $_GET['postal'];
      $point = geocoder('google', $address);
      $geoJSON = $point->out('json');
      $coordinates = isset($geoJSON->coordinates) ? $geoJSON->coordinates : FALSE;
      // If there are coordinates, they are in an array.
      if (is_array($coordinates)) {
        $invalid_postal_code = FALSE;
      }
    }

  }

  if (in_array('S', $buying_methods)) {
    // Storefront locations.
    $data = get_distributors('S', $data_nids);
    if ($data && $data['status']) {
      $storefront_results = TRUE;
      foreach ($data['data'] as $val) {
        $data_arr[] = $val;
      }
      // Always show National Defaults.
      $always_show_countries = variable_get('wtb_countries_show_always', []);
      if (array_key_exists($country, $always_show_countries)) {
        $data = get_national_distributors(NULL, $data_nids);
        if ($data && $data['status']) {
          $national_default_results = TRUE;
          foreach ($data['data'] as $val) {
            $data_arr[] = $val;
          }
        }
      }
    }
    elseif (in_array('N', $buying_methods) && !$invalid_postal_code) {
      // No storefront locations found. Show National Defaults.
      $data = get_national_distributors(NULL, $data_nids);
      if ($data && $data['status']) {
        $national_default_results = TRUE;
        foreach ($data['data'] as $val) {
          $data_arr[] = $val;
        }
      }
    }
  }
  elseif (in_array('N', $buying_methods)) {
    // National Defaults.
    $data = get_national_distributors(NULL, $data_nids);
    if ($data && $data['status']) {
      $national_default_results = TRUE;
      foreach ($data['data'] as $val) {
        $data_arr[] = $val;
      }
    }
  }
  if (in_array('O', $buying_methods) && !$invalid_postal_code) {
    // Online.
    $data = get_distributors('O', $data_nids);
    if ($data && $data['status']) {
      $online_results = TRUE;
      foreach ($data['data'] as $val) {
        $data_arr[] = $val;
      }
    }
  }
  if (count($data_arr)) {
    // Locations found, return results.
    echo json_encode([
      'status' => TRUE,
      'storefrontData' => $storefront_results,
      'nationalDefaultData' => $national_default_results,
      'onlineData' => $online_results,
    ] + wtb_format_results($data_arr, $country));
  }
  else {
    // No locations found. Check error matrix and display error message.
    if (isset($_GET['channel']) && !$invalid_postal_code) {
      // Case Six: Filter by GSA Schedule.
      echo json_encode([
        'status' => FALSE,
        'errorData' => wtb_get_error_message(6),
      ]);
    }
    elseif (isset($_GET['postal'])) {
      if ($invalid_postal_code) {
        // Case Five: Invalid Postal Code.
        echo json_encode([
          'status' => FALSE,
          'errorData' => wtb_get_error_message(5),
        ]);
      }
      else {
        // Case Four: Search by Postal Code: No results found.
        echo json_encode([
          'status' => FALSE,
          'errorData' => wtb_get_error_message(4),
        ]);
      }
    }
    elseif (isset($_GET['storefronts']) && $_GET['storefronts'] > 0) {
      // Case Three: Search by Region: No locations in selected region.
      echo json_encode([
        'status' => FALSE,
        'errorData' => wtb_get_error_message(3),
      ]);
    }
    else {
      $flagged_countries = variable_get('wtb_countries_skip_region', []);
      if (isset($_GET['region']) && !isset($flagged_countries[$country])) {
        // Case Three: Search by Region: No locations in entire country
        // & skip-region-search not selected.
        echo json_encode([
          'status' => FALSE,
          'errorData' => wtb_get_error_message(3),
        ]);
      }
      else {
        // Case Three:  Search by Region: No locations found for entire country
        // & skip-region-search active for selected country.
        echo json_encode([
          'status' => FALSE,
          'errorData' => wtb_get_error_message(2),
        ]);
      }
    }
  }
}

/**
 * Helper function: Returns results for Online and Storefront locations.
 */
function get_distributors($buying_method = NULL, &$data_nids = NULL) {
  if (!$buying_method) {
    return FALSE;
  }
  $country = $_GET['country'];
  $product = $_GET['product']; //query on this at the end.
  $sales_channel = isset($_GET['channel']) ? $_GET['channel'] : 0;
  $coordinates = [];

  if ($product == 0) {
    //Handle error: Product dd option not selected
    $output = 'Please select a Product!';
    return [
      'status' => FALSE,
      'errorData' => $output,
    ];
  }
  /*
  if ($product != -1) {
    $pnode = node_load($product);
    //Get list of locations supplying the product - deprecated
    $locations = get_product_locations($pnode->nid);
  }
  */
  //Filter the locations according to the filtering criteria.
  // if (!empty($locations)) {
  $query = db_select('node', 'n')
    ->fields('n', ['nid']);
  $query->join('field_data_field_address', 'address', 'address.entity_id = n.nid AND address.revision_id = n.vid');
  $query->join('field_data_field_stocking_rating', 'stocking', 'stocking.entity_id = n.nid AND stocking.revision_id = n.vid');
  $query->join('field_data_field_salesforce_rating', 'salesforce', 'salesforce.entity_id = n.nid AND salesforce.revision_id = n.vid');
  $query->join('field_data_field_distributor_type_rating', 'distributor_rating', 'distributor_rating.entity_id = n.nid AND distributor_rating.revision_id = n.vid');
  $query->join('field_data_field_point_of_sale_rating', 'pos', 'pos.entity_id = n.nid AND pos.revision_id = n.vid');
  $query->join('field_data_field_delivery_type', 'delivery', 'delivery.entity_id = n.nid AND delivery.revision_id = n.vid');
  $query->join('field_data_field_product_distributor_groups', 'distributor', 'distributor.entity_id = n.nid');
  $query->join('field_data_field_related_products', 'products', 'products.entity_id = distributor.field_product_distributor_groups_target_id');
  $query
    ->condition('n.status', 1, '=')
    ->condition('address.field_address_country', $country, '=')
    ->condition('delivery.field_delivery_type_value', $buying_method, '=');

  if ($country == 'US' && $sales_channel == 1) {
    $query->join('field_data_field_gsa_schedule', 'gsa', 'gsa.entity_id = n.nid AND gsa.revision_id = n.vid');
    $query->condition('gsa.field_gsa_schedule_value', 1, '=');
  }

  if ($product != -1) {
    $query->condition('products.field_related_products_target_id', $product, '=');
    // $query->condition('n.nid', $locations, 'IN');
  }

  // Latitude/Longitude
  // TODO: Rework with different module than Location.
  if ($buying_method == 'S') {
    watchdog('wtb', 'Buying Method:S');
    // TODO: This is tabled while getting onto Pantheon 2/15/2018 - rositis.

    if (isset($_GET['postal'])) {
      /*
      //postal code processing
      if (ltrim($_GET['postal'], '0') < 99999) {
        $coordinates = location_latlon_rough(array(
          'country' => $_GET['country'],
          'postal_code' => $_GET['postal']
        ));
        if (!$coordinates) {
          return FALSE;
        }
      }
      else {
        return FALSE;
      }

      $lat = $coordinates['lat'];
      $lon = $coordinates['lon'];
      $distance = 50; // integer
      if ($country == 'US') {
        $units = 'mile';
      }
      else {
        $units = 'km';
      }

      $distance_meters = _location_convert_distance_to_meters($distance, $units);
      $latrange = earth_latitude_range($lon, $lat, $distance_meters);
      $lonrange = earth_longitude_range($lon, $lat, $distance_meters);

      // Add MBR check (always).
      // In case we go past the 180/-180 mark for longitude.
      if ($lonrange[0] > $lonrange[1]) {
        $query
          ->condition('l.latitude', $latrange[0], '>')
          ->condition('l.latitude', $latrange[1], '<')
          ->condition(
            db_or()
              ->condition(
                db_and()
                  ->condition('l.longitude', 180, '<')
                  ->condition('l.longitude', $lonrange[0], '>')
              )
              ->condition(
                db_and()
                  ->condition('l.longitude', $lonrange[1], '<')
                  ->condition('l.longitude', -180, '>')
              )
          );
      }
      else {
        $query
          ->condition('l.latitude', $latrange[0], '>')
          ->condition('l.latitude', $latrange[1], '<')
          ->condition('l.longitude', $lonrange[0], '>')
          ->condition('l.longitude', $lonrange[1], '<');
      }
      */
    }
    elseif (isset($_GET['region'])) {
      $region = $_GET['region'];
      $query->condition('address.field_address_administrative_area', $region, '=');

      if ((isset($_GET['city'])) && ($_GET['city'] != -1)) {
        $city = $_GET['city'];;
        $query->condition('address.field_address_locality', $city, '=');
      }
    }
  }
  $query->orderBy('(stocking.field_stocking_rating_value+salesforce.field_salesforce_rating_value+distributor_rating.field_distributor_type_rating_value+pos.field_point_of_sale_rating_value)', 'DESC');
  $query->orderBy('n.title', 'ASC');
  // dpm((string) $query);
  // dpm($query->arguments());
  $results = $query->execute();

  $data_arr = [];
  $nids_arr = [];
  foreach ($results as $data) {
    // Skip if result already contains the location nid.
    if (!in_array($data->nid, $data_nids)) {
      $data_nids[] = $data->nid;
    }

    // Load the full node data for the distributor.
    $dnode = node_load($data->nid);
    $nids_arr[$data->nid] = $dnode->title;

    // Make sure the URLs start with HTTP://.
    if (isset($dnode->field_website_url[LANGUAGE_NONE][0]['value']) && !strstr($dnode->field_website_url[LANGUAGE_NONE][0]['value'], 'http://')) {
      $dnode->field_website_url[LANGUAGE_NONE][0]['value'] = 'http://' . $dnode->field_website_url[LANGUAGE_NONE][0]['value'];
    }

    if (isset($dnode->field_buy_online_url[LANGUAGE_NONE][0]['value']) && !strstr($dnode->field_buy_online_url[LANGUAGE_NONE][0]['value'], 'http://')) {
      $dnode->field_buy_online_url[LANGUAGE_NONE][0]['value'] = 'http://' . $dnode->field_buy_online_url[LANGUAGE_NONE][0]['value'];
    }

    // Storefronts.
    if ($buying_method == 'S') {
      // TODO: Geocoding to replace Location module functionality?
      /*
      // This is for Postal Codes, since $coordinates has been set.
      if (!empty($coordinates)) { // Set the Distance Between.
        $distance_between = location_distance_between($coordinates, array(
          'lat' => $dnode->location['latitude'],
          'lon' => $dnode->location['longitude']
        ));
        if ($country == 'US') {
          $distance_between['scalar'] = round(($distance_between['scalar'] * 0.621371192), 1);
          $distance_between['distance_unit'] = 'miles';
        }
      }
       */
      $location_street = '';
      if (trim($dnode->field_address[LANGUAGE_NONE][0]['thoroughfare']) != '') {
        $location_street .= $dnode->field_address[LANGUAGE_NONE][0]['thoroughfare'];
      }
      if (trim($dnode->field_address[LANGUAGE_NONE][0]['premise']) != '') {
        if (trim($dnode->field_address[LANGUAGE_NONE][0]['thoroughfare']) != '') {
          $location_street .= '<br/>';
        }
        $location_street .= $dnode->field_address[LANGUAGE_NONE][0]['premise'];
      }
      $buy_online_url = '';
      if (!empty($dnode->field_buy_online_url)) {
        if (strlen(trim($dnode->field_buy_online_url[LANGUAGE_NONE][0]['url'])) > 7) {
          $buy_online_url = (trim($dnode->field_buy_online_url[LANGUAGE_NONE][0]['url']));
        }
      }

      // TODO: Some stuff here is weird. Needs QA.
      $data_arr[] = [
        'nid' => $dnode->nid,
        'type' => 'S',
        'is_online' => is_online_location($dnode),
        'name' => $dnode->field_display_title[LANGUAGE_NONE][0]['value'],
        'address' => $location_street . '<br/>' . $dnode->field_address[LANGUAGE_NONE][0]['locality'] . ', ' . $dnode->field_address[LANGUAGE_NONE][0]['administrative_area'] . ' ' . $dnode->field_address[LANGUAGE_NONE][0]['postal_code'] . '<br/>' . $dnode->field_address[LANGUAGE_NONE][0]['country'],
        'toll_free_phone' => isset($dnode->field_toll_free_phone[LANGUAGE_NONE][0]['value']) ? $dnode->field_toll_free_phone[LANGUAGE_NONE][0]['value'] : "",
        //'phone' => $dnode->location['phone'],
        //'fax' => $dnode->location['fax'],
        'email' => !empty($dnode->field_email_contact) ? trim($dnode->field_email_contact[LANGUAGE_NONE][0]['value']) : '',
        'url' => (strlen(trim($dnode->field_website_url[LANGUAGE_NONE][0]['url'])) > 7) ? trim($dnode->field_website_url[LANGUAGE_NONE][0]['url']) : '',
        'buy_online_url' => $buy_online_url,
        //'dist' => isset($distance_between['scalar']) ? $distance_between['scalar'] : 0,
        //'dist_unit' => isset($distance_between['distance_unit']) ? $distance_between['distance_unit'] : 'km',
        //'lat' => (($dnode->location['source'] != 0) ? $dnode->location['latitude'] : 'NULL'),
        //Check if the lat/lons exist.
        //'lon' => (($dnode->location['source'] != 0) ? $dnode->location['longitude'] : 'NULL'),

      ];

    }
  }

  // TODO: Online?
  // TODO: National?
  if (count($data_arr)) {
    return [
      'status' => TRUE,
      'data' => $data_arr,
    ];
  }
  else {
    // Show National distributors if no results found for proximty search.
    if (isset($_GET['postal'])) {
      return get_national_distributors(NO_RESULTS_FOR_PROXIMITY_SEARCH, $data_nids);
    }
    else {
      return FALSE;
    }
  }
  /* }
  else {
    //Error handling for no nids of dist-prod groups
    return array(
      'status' => FALSE,
      'errorData' => 'This product is not available through the buying method you chose. Please try again or contact Fluke Networks directly for more information.',
    );
  } */
}


/**
 * Return the locations results as HTML.
 *
 * @param $data_arr
 * @param string $country
 * @return array
 * @throws \Exception
 */
function wtb_format_results($data_arr, $country = "US") {
  // Sort the list of results by title.
  /*
   if (isset($_GET['postal'])) {
   foreach ($data_arr AS $c => $key) {
   $sort_dist[] = $key['dist'];
   }
   array_multisort($sort_dist, SORT_ASC, $data_arr);
   }
   */
  // Display logic for results.
  $rec_counter = 0;
  $output = '<ol>';
  $lats = '';
  $lons = '';
  $gmap_title = '';
  $gmap_address = '';
  foreach ($data_arr as $data_ele) {
    $item_classes = "dsearch-item";
    if (($rec_counter % 3) == 0) {
      $item_classes .= " new-row";
      $output .= '<li class="dsearch-item-clearence">&nbsp</li>';
    }
    $data_ele['classes'] = $item_classes;
    if ($data_ele['type'] == 'S') {
      // Storefront Locations.
      $output .= theme('fnet_wtb_storefront_location_list_item', ['data' => $data_ele]);

      if (isset($data_ele['lat'])) {
        $gmap_title .= $data_ele['name'] . '|';
        $gmap_address .= $data_ele['address'] . '|';
        $lats .= $data_ele['lat'] . '|';
        $lons .= $data_ele['lon'] . '|';
      }
    }
    elseif ($data_ele['type'] == 'N') {
      // National Default Locations.
      $output .= theme('fnet_wtb_national_default_location_list_item', ['data' => $data_ele]);
    }
    elseif ($data_ele['type'] == 'O') {
      // Online Locations.
      $output .= theme('fnet_wtb_online_location_list_item', ['data' => $data_ele]);
    }
    $rec_counter++;
  }
  if ($lats != '') {
    // GMap Lat-Lon, Title and Address fields for each storefront location.
    $gmap_title = trim($gmap_title, '|');
    $gmap_address = trim($gmap_address, '|');
    $lats = trim($lats, '|');
    $lons = trim($lons, '|');
  }
  $output .= '</ol>';
  /*
   * HACK HACK HACK
   */
  $alertMessage = "";
  if ($country == "CN" && $rec_counter > 0) {
    $siteReg = module_invoke('fnet_helper', 'site_region');
    $lang = $siteReg["lang"];
    $alertMessage = "<div style='padding-bottom: 15px;'>";
    switch (strtoupper($lang)) {
      case "ZH":
        $alertMessage .= <<<MESSAGE
<span style='color: red;'>鉴于某些未经授权的经销商可能企图转售福禄克网络的产品, 我方特此声明: 如果您的产品是从未授权经销商处采购, 福禄克网络将无法保证该产品的可靠性, 针对该产品的相关支持和保修也将不适用。并且，您可能需要承担包括缴纳关税等在内的财务，法律及其他风险。因此，我们强烈建议您只从授权的中国大陆福禄克网络经销商处购买产品。</span>
<p>以下名单里的公司均不是福禄克（中国）正规渠道指定经销商, 未被福禄克公司授权销售或代理任何福禄克公司产品:</p>
<ul>
<li>福克网络公司</li>
<li>深圳市连讯达电子技术开发有限公司</li>
<li>深圳连讯电子有限公司</li>
<li>朗成电子（深圳）有限公司</li>
<li>深圳维信仪器仪表有限公司</li>
<li>北京今日星马科技有限公司</li>
<li>深圳市东方欣亚科技开发有限公司</li>
</ul>
<p>查询未经授权的经销商列表，请点击链接：<a href='/content/Channel_parnter_clarification_CN'>http://cn.flukenetworks.com/content/Channel_parnter_clarification_CN</a></p>
<p>如果您有任何疑问或问题，欢迎您随时联系我们：<a href='mailto:china-marketing@flukenetworks.com'>china-marketing@flukenetworks.com</a></p>
MESSAGE;
        break;

      default:
        $alertMessage .= "<span style='color: red;'>Be aware that some resellers may attempt to resell Fluke Networks products that are not authorized to do so. If you purchase a product from these resellers, Fluke Networks cannot guarantee the authenticity of the product, support the product and the warranty will not apply. You will also bear customs tax risk. We encourage you to purchase only from the authorized local Fluke Networks partners listed here. </span><br /><br />For unauthorized partners list, please click the attached link. <a href='/content/Channel_parnter_clarification_CN'>http://cn.flukenetworks.com/content/Channel_parnter_clarification_CN</a><br /><br />Please feel free to contact with us if you have any questions. <a href='mailto:china-marketing@flukenetworks.com'>china-marketing@flukenetworks.com</a>";
    }
    $alertMessage .= "</div>";
  }
  $output = $alertMessage . $output;

  $wtb_results = [
    'data' => $output,
  ];
  if ($lats != '') {
    $wtb_results += [
      'lats' => $lats,
      'lons' => $lons,
      'gtitle' => $gmap_title,
      'gaddress' => $gmap_address,
    ];
  }
  return $wtb_results;
}

/**
 * Check whether or not to show buy online button.
 */
function is_online_location($dnode) {
  $online = FALSE;
  if (!empty($dnode->field_buy_online_url)) {
    if (strlen(trim($dnode->field_buy_online_url[LANGUAGE_NONE][0]['value'])) > 7) {
      $online = TRUE;
    }
  }
  return $online;
}

/**
 * Helper function.
 *
 * Return the most recent Node ID for location nodes of a product.
 *
 * @param $pid
 * @return mixed
 */
function get_product_locations($pid) {
  $query = "SELECT n.nid
  FROM node n
  JOIN field_data_field_product_distributor_groups distributor ON  distributor.entity_id = n.nid
  JOIN field_data_field_related_products products ON products.entity_id = distributor.field_product_distributor_groups_target_id
  WHERE products.field_related_products_target_id = :pid
  AND n.status = 1";
  $results = db_query($query, [':pid' => $pid])->fetchCol();
  return $results;
  // TODO: error handling if no results?
}

/**
 * Check if skip-region-search is activated for a country.
 */
function is_country_flagged() {
  if (isset($_GET['country'])) {
    $country = strtoupper($_GET['country']);
    $flagged_countries = variable_get('wtb_countries_skip_region', []);
    if (array_key_exists($country, $flagged_countries)) {
      echo json_encode(['status' => TRUE]);
    }
    else {
      echo json_encode(['status' => FALSE]);
    }
  }
}

/**
 * AJAX Callback for error messages.
 */
function wtb_error_message() {
  $error_id = $_GET['error_id'];
  if (is_numeric($error_id)) {
    echo json_encode([
      'status' => FALSE,
      'errorData' => wtb_get_error_message($error_id),
    ]);
  }
}

/**
 * Helper function: Returns error message HTML.
 */
function wtb_get_error_message($error_id = NULL) {
  if (isset($_COOKIE["regLang"])) {
    $language = substr($_COOKIE["regLang"], 0, 2);
  }
  else {
    $language = 'EN';
  }
  $error_text = '';
  $text_only = TRUE;
  $contact_form = FALSE;
  if (is_numeric($error_id)) {
    switch ($error_id) {
      case 0:
        $text_only = FALSE;
        $contact_form = TRUE;
        switch (strtoupper($language)) {
          case 'FR':
            $error_text = "Le pays que vous avez choisi n'a aucun distributeur local qui dispose actuellement de ce produit particulier. Pour des informations sur les autres options disponibles dans votre zone, veuillez nous contacter à :";
            break;

          case 'DE':
            $error_text = "Das Land, das Sie ausgewählt haben, hat keine regionalen Vertreiber, die dieses Produkt zur Zeit auf Lager haben. Für Informationen über andere Optionen in Ihrer Region kontaktieren Sie uns bitte unter: ";
            break;

          case 'ES':
            $error_text = "El país que usted seleccionó no tiene ningún distribuidor local que cuente con este producto en particular en este momento. Para información sobre otras opciones para su área comuníquese con nosotros al: ";
            break;

          case 'CN':
            $error_text = "您选择的国家当前没有当地分销商销售此产品。 如需您所在地区的其他选项信息，请与我们联系：";
            break;

          case 'JP':
            $error_text = "現在のところ、お客様が選択された国にはこの製品を取り扱っている現地販売店がございません。 お客様の地域におけるその他のオプションについて当社までお問い合わせください。 ";
            break;

          case 'KO':
            $error_text = "귀하가 선택한 국가에는 현재 이 특정 제품을 취급하는 지역 유통 업체가 없습니다. 해당 지역의 다른 옵션에 대한 정보는 다음으로 문의하십시오: ";
            break;

          case 'PT':
            $error_text = "O país que você selecionou não tem nenhum distribuidor local oferecendo este produto específico neste momento. Para obter informações sobre outras opções para a sua área, entre em contato conosco em: ";
            break;

          case 'RU':
            $error_text = "Местные дистрибьюторы выбранной вами страны не имеют в наличии этот конкретный продукт в данное время. Для получения информации относительно других вариантов для вашего района, пожалуйста, свяжитесь с нами по: ";
            break;

          case 'EN':
          default:
            $error_text = 'The country you have selected does not have any local distributors carrying this particular product at this time. For information on other options for your area please contact us at:';
            break;
        }
      case 1:
        $text_only = FALSE;
        $contact_form = TRUE;
        switch (strtoupper($language)) {
          case 'FR':
            $error_text = "Nous n'avons actuellement aucune entrée disponible pour ce lieu ; pour des informations ou des options de commande supplémentaires pour votre zone, veuillez nous contacter à :";
            break;

          case 'DE':
            $error_text = "Wir haben keine gegenwärtigen Auflistungen, die für diese Niederlassung vorhanden sind; für weitere Informationen oder Bestelloptionen in Ihrer Region kontaktieren Sie uns bitte unter:";
            break;

          case 'ES':
            $error_text = "No tenemos ningún listado actual disponible para esta ubicación; para información adicional o opciones de pedidos para su área por favor comuníquese con nosotros al:";
            break;

          case 'CN':
            $error_text = "我们在该地区没有当前列表，如需您所在地区的更多信息或订购选项，请与我们联系： ";
            break;

          case 'KO':
            $error_text = "이 위치에 대한 유효 목록이 현재 없습니다. 해당 지역의 추가 정보나 주문 옵션에 대해 다음으로 문의하십시오: ";
            break;

          case 'JP':
            $error_text = "この地域では現在のリストがありません。お客様の地域における追加情報または注文オプションについて当社までお問い合わせください。 ";
            break;

          case 'PT':
            $error_text = "Atualmente, não temos nenhuma lista disponível para este local; para obter informações adicionais ou para ver suas opções para fazer pedidos em sua área, entre em contato conosco em: ";
            break;

          case 'RU':
            $error_text = "Мы не имеем текущих записей для этого местоположения; для дополнительной информации или вариантов заказа для вашего района, пожалуйста, свяжитесь с нами по: ";
            break;

          case 'EN':
          default:
            $error_text = 'We do not have any current listings available for this location; for additional information or ordering options for your area please contact us at:';
            break;
        }
        break;

      case 2:
        $text_only = FALSE;
        $contact_form = TRUE;
        switch (strtoupper($language)) {
          case 'FR':
            $error_text = "Le pays que vous avez choisi n'a aucun distributeur local qui dispose actuellement de ce produit particulier. Vous pouvez changer votre préférence de lieu ou nous contacter pour des informations ou des options de commande supplémentaires ; veuillez nous contacter à:";
            break;

          case 'DE':
            $error_text = "Das Land, das Sie ausgewählt haben, hat keine regionalen Vertreiber, die dieses Produkt zur Zeit auf Lager haben. Sie können Ihre bevorzugte Niederlassung ändern oder kontaktieren Sie uns für weitere Informationen oder Bestelloptionen - bitte kontaktieren Sie uns unter:";
            break;

          case 'ES':
            $error_text = "El país que usted seleccionó no tiene ningún distribuidor local que cuente con este producto en particular en este momento. Puede cambiar la preferencia de ubicación o comunicarse con nosotros para información adicional u opciones de pedido, comuníquese con nosotros al:";
            break;

          case 'CN':
            $error_text = "您选择的国家当前没有当地分销商销售此产品。 您可以更改您的地点首选项，或如需更多信息或订购选项，请与我们联系：";
            break;

          case 'JP':
            $error_text = "現在のところ、お客様が選択された国にはこの製品を取り扱っている現地販売店がございません。 場所の選択を変更するか、または追加情報、注文オプションについて当社までお問い合わせください。 – お問い合わせ先：";
            break;

          case 'KO':
            $error_text = "귀하가 선택한 국가에는 현재 이 특정 제품을 취급하는 지역 유통 업체가 없습니다. 선호 위치를 변경할 수 있으며, 아니면 추가 정보나 주문 옵션에 대해 문의해 주십시오 ㅡ 다음으로 문의하십시오:";
            break;

          case 'PT':
            $error_text = "O país que você selecionou não tem nenhum distribuidor local oferecendo este produto específico neste momento. Você pode mudar suas preferências de local ou entrar em contato conosco para obter mais informações ou para ver suas opções para fazer pedidos. Entre em contato conosco em:";
            break;

          case 'RU':
            $error_text = "Местные дистрибьюторы выбранной вами страны не имеют в наличии этот конкретный продукт в данное время. Вы можете изменить свое предпочитаемое местоположение или связаться с нами для дополнительной информации или вариантов заказа. Свяжитесь с нами по:";
            break;

          case 'EN':
          default:
            $error_text = 'The country you have selected does not have any local distributors carrying this particular product at this time. You may change your location preference or contact us for additional information or ordering options - please contact us at:';
            break;
        }
        break;

      case 3:
        $text_only = FALSE;
        $contact_form = TRUE;
        switch (strtoupper($language)) {
          case 'FR':
            $error_text = "La région que vous avez choisie n'a actuellement aucune entrée de distributeur local, veuillez essayer une autre région proche ou nous contacter pour savoir quelles autres options il y a dans votre zone: ";
            break;

          case 'DE':
            $error_text = "Die Region, die Sie ausgewählt haben, hat z.Z. keine lokalen Vertreiberauflistungen, versuchen Sie es bitte mit einer anderen, nahe gelegenen Region oder kontaktieren Sie uns für andere Optionen für Ihre Region unter:";
            break;

          case 'ES':
            $error_text = "La región que usted seleccionó no tiene actualmente ningún listado de distribuidor local, intente con otra región próxima o comuníquese con nosotros para otras opciones para su área en:";
            break;

          case 'CN':
            $error_text = "您选择的地区目前没有当地分销商列表，请尝试附近的其他地区，或如需您所在地区的其他选项，请与我们联系：";
            break;

          case 'JP':
            $error_text = "現在のところ、お客様が選択された地域にはこの製品を取り扱っている現地販売店リストがございません。別のお近くの地域を選択するか、またはお客様の地域におけるその他のオプションについて当社までお問い合わせください。 ";
            break;

          case 'KO':
            $error_text = "선택하신 지역에는 현재, 지역 유통 업체 목록이 없으므로, 근처의 다른 지역으로 시도하거나 또는 그 지역의 다른 옵션에 대해 다음으로 문의하십시오:";
            break;

          case 'PT':
            $error_text = "A região que você selecionou atualmente não tem nenhuma lista de distribuidores locais, tente outra região próxima ou entre em contato conosco para ver outras opções para a sua área em:";
            break;

          case 'RU':
            $error_text = "Выбранный вами регион в настоящее время не имеет местных дистрибьюторов, пожалуйста, попробуйте другой близлежащий регион или свяжитесь с нами для других вариантов в вашем регионе по:";
            break;

          case 'EN':
          default:
            $error_text = 'The region you have selected does not currently have any local distributor listings, please try another nearby region or contact us for other options for your area at:';
            break;
        }
        break;

      case 4:
        $text_only = FALSE;
        $contact_form = TRUE;
        switch (strtoupper($language)) {
          case 'FR':
            $error_text = "La région que vous avez choisie n'a actuellement aucune entrée de distributeur local, veuillez essayer une autre région proche ou nous contacter pour savoir quelles autres options il y a dans votre zone :";
            break;

          case 'DE':
            $error_text = "Die Region, die Sie ausgewählt haben, hat z.Z. keine lokalen Vertreiberauflistungen, versuchen Sie es bitte mit einer anderen, nahe gelegenen Region oder kontaktieren Sie uns für andere Optionen für Ihre Region unter:";
            break;

          case 'ES':
            $error_text = "La región que usted seleccionó no tiene actualmente ningún listado de distribuidor local, intente con otra región próxima o comuníquese con nosotros para otras opciones para su área en:";
            break;

          case 'CN':
            $error_text = "您选择的地区目前没有当地分销商列表，请尝试附近的其他地区，或如需您所在地区的其他选项，请与我们联系：";
            break;

          case 'JP':
            $error_text = "現在のところ、お客様が選択された地域にはこの製品を取り扱っている現地販売店リストがございません。別のお近くの地域を選択するか、またはお客様の地域におけるその他のオプションについて当社までお問い合わせください。";
            break;

          case 'KO':
            $error_text = "선택하신 지역에는 현재, 지역 유통 업체 목록이 없으므로, 근처의 다른 지역으로 시도하거나 또는 그 지역의 다른 옵션에 대해 다음으로 문의하십시오:";
            break;

          case 'PT':
            $error_text = "A região que você selecionou atualmente não tem nenhuma lista de distribuidores locais, tente outra região próxima ou entre em contato conosco para ver outras opções para a sua área em:";
            break;

          case 'RU':
            $error_text = "Выбранный вами регион в настоящее время не имеет местных дистрибьюторов, пожалуйста, попробуйте другой близлежащий регион или свяжитесь с нами для других вариантов в вашем регионе по:";
            break;

          case 'EN':
          default:
            $error_text = 'The region you have selected does not currently have any local distributor listings, please try another nearby region or contact us for other options for your area at:';
            break;
        }
        break;

      case 5:
        $text_only = TRUE;
        $contact_form = FALSE;
        switch (strtoupper($language)) {
          case 'FR':
            $error_text = "Entrée de code postal non valide, veuillez réessayer.";
            break;

          case 'DE':
            $error_text = "Unzulässiger Postleitzahleintrag, versuchen bitte noch einmal.";
            break;

          case 'ES':
            $error_text = "El código postal no es válido, intente nuevamente.";
            break;

          case 'CN':
            $error_text = "输入的邮政编码无效，请再试一次。";
            break;

          case 'JP':
            $error_text = "無効な郵便番号が入力されています。やり直してください。";
            break;

          case 'KO':
            $error_text = "유효하지 않은 우편번호입니다, 다시 시도하십시오.";
            break;

          case 'PT':
            $error_text = "Código Postal/CEP inválido. Tente novamente.";
            break;

          case 'RU':
            $error_text = "Недействительный индекса, пожалуйста, попробуйте ввести его еще раз.";
            break;

          case 'EN':
          default:
            $error_text = 'Invalid postal code entry, please try again.';
            break;
        }
        break;

      case 6:
        $text_only = FALSE;
        $contact_form = TRUE;
        switch (strtoupper($language)) {
          case 'FR':
            $error_text = "Nous n'avons actuellement aucune entrée de distributeurs dans un programme GSA dans la zone sélectionnée.  Veuillez changer vos préférences de sélections ou nous contacter pour obtenir plus d'information sur les distributeurs disponibles dans un programme GSA ; veuillez nous contacter à ";
            break;

          case 'DE':
            $error_text = "Zur Zeit haben wir keine Auflistungen für Vertreiber auf einem GSA Schedule in der ausgewählten Region.  Bitte ändern Sie Ihre gewählten Präferenzen oder kontaktieren Sie uns für weitere Information über vorhandene GSA Schedule Vertreiber - bitte kontaktieren Sie uns unter:";
            break;

          case 'ES':
            $error_text = "Actualmente no tenemos listados para los distribuidores en un horario GSA en el área seleccionada.  Modifique las preferencias de la selección o comuníquese con nosotros para más información sobre los distribuidores de horario GSA disponibles, comuníquese con nosotros en:";
            break;

          case 'CN':
            $error_text = "当前我们在所选区域没有 GSA 计划分销商列表。  请更改您的首选项，如需可用的 GSA 计划分销商的更多信息，请与我们联系：";
            break;

          case 'JP':
            $error_text = "現在のところ、選択地域での GSA スケジュールの販売店リストがありません。  選択を変更するか、または GSA スケジュール販売店の追加情報について当社までお問い合わせください。 – お問合せ先：";
            break;

          case 'KO':
            $error_text = "현재, 선택하신 지역의 GSA 일정에 유통 업체 목록이 없습니다.  선호하는 선택을 변경하거나 또는 유효한 GSA 일정 유통 업체의 추가 정보에 대해 문의하십시오 ㅡ 다음으로 문의하십시오:";
            break;

          case 'PT':
            $error_text = "Atualmente não temos nenhuma lista de distribuidores do Programa GSA na área selecionada.  Por favor, altere suas preferências da seleção ou entre em contato conosco para obter mais informações sobre distribuidores do Programa GSA disponíveis - Entre em contato conosco em:";
            break;

          case 'RU':
            $error_text = "В настоящее время у нас нет никаких записей о дистрибьюторах по графика GSA в выбранном районе.  Пожалуйста измените свой выбор предпочтения или свяжитесь с нами для получения дополнительной информации о доступных дистрибьюторах графика GSA. Свяжитесь с нами по:";
            break;

          case 'EN':
          default:
            $error_text = 'Currently we do not have any listings for distributors on a GSA schedule in the selected area. Please alter your selection preferences or contact us for more information on available GSA schedule distributors - please contact us at:';
            break;
        }
        break;
    }
    $error_message = '';
    if ($text_only) {
      $error_message = '<div id="wtb-error-msg"><span class="msg">' . $error_text . '</span></div>';
    }
    else {
      $error_message = '<div id="wtb-error-msg"><span class="msg">' . $error_text . '</span>'
        . '<div id="wtb-contact-info">'
        . '<b>U.S.</b>:1-800-283-5853<br/>'
        . '<b>International</b>:1-425-446-5500<br/>'
        . '<b>Email</b>: info@flukenetworks.com'
        . '</div>'
        . '</div>';
    }
    if ($contact_form) {
      $error_message .= '<div id="wtb-contact-form-wrapper">&nbsp;</div>';
    }

    if ($error_message != '') {
      return $error_message;
    }
    else {
      return FALSE;
    }
  }
  else {
    return FALSE;
  }
}
