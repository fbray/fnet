<?php
/**
 * @file
 * File for handling Administration pages functionality.
 */

/**
 * Configuration form for FNET Where To Buy Tab settings
 *
 * @return mixed
 */
function product_distributor_admin() {
  $form = array();

  $form['product_distributor_tab1_title'] = array(
    '#type' => 'textarea',
    '#title' => t('First Tab Title'),
    '#default_value' => variable_get('product_distributor_tab1_title', ''),
    '#required' => FALSE,
  );

  $form['product_distributor_tab2_title'] = array(
    '#type' => 'textarea',
    '#title' => t('Second Tab Title'),
    '#default_value' => variable_get('product_distributor_tab2_title', ''),
    '#required' => TRUE,
  );

  $form['product_distributor_tab2_content'] = array(
    '#type' => 'textarea',
    '#title' => t('Second Tab Content'),
    '#default_value' => variable_get('product_distributor_tab2_content', ''),
    '#required' => TRUE,
  );
  
  $form['product_distributor_contact_us'] = array(
    '#type' => 'textarea',
    '#title' => t('Contact Us Page Title'),
    '#default_value' => variable_get('product_distributor_contact_us', ''),
    '#required' => TRUE,
  );
  
  return system_settings_form($form);
}

/**
 * Implementation of hook_form() for configuring FNET WTB countries settings
 * TODO: Update with better country list using Locale module.
 * @return array
 */
function wtb_configure_countries_form() {
  $form = array();

  drupal_add_js(drupal_get_path('module', 'product_distributor') . '/javascripts/wtb_countries_form.js');
  drupal_add_css(drupal_get_path('module', 'product_distributor') . '/styles/wtb_countries_form.css');

  $countries = array_change_key_case(location_get_iso3166_list(), CASE_UPPER);
  $inactive_countries = get_inactive_countries();
  $countries = array_diff_key($countries, $inactive_countries);
  $skip_region = variable_get('wtb_countries_skip_region', array());
  $show_always = variable_get('wtb_countries_show_always', array());

  $form['help_text'] = array(
    '#value' => '<div id="wtb-help-text"><p>Below you will find the option to make a country "skip region" or to make National Distributors show all the time.
If you choose neither, search results will only show the distributor locations for a product within the region and city filtered upon.  If there are no local responses, only then will National Distributor locations with the product show for the country.
</p><p>
If you choose to "skip region" the results displayed will be all the distributor locations with the product in the entire country at once.  If a distributor has more than one location in the country, each location will show.
</p><p>
If you choose to make National Distributors always show, the results displayed will be the distributor locations for a product within the selected region/city, AND any distributor locations with the product that have been flagged as a National Distributor in the country.  This is useful for any premier distributor relationships.
</p><p>
Please note you can choose not to check neither of these features, or only one.
</p></div>',
  );

  $form['skip_region'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Skip region selection'),
    '#prefix' => '<div id="countries-checkbox-wrapper">',
    '#default_value' => $skip_region,
    '#options' => $countries,
    '#description' => t('Setting a country to skip the region will disable the ability for a customer to refine their search by region and city.'),
  );
  $form['show_always'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Always show National/Default'),
    '#suffix' => '<input type="submit" class="form-submit" value="Save" id="edit-Save-1" name="op"></div>',
    '#default_value' => $show_always,
    '#options' => $countries,
    '#description' => t('Setting a country to "Always show National/Default" will result in National/Default appearing always in results.'),
  );

  $form['Save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 10,
  );

  return $form;
}


/**
 * Implementation of hook_submit for FNET WTB countries settings form
 *
 * @param $form
 * @param $form_state
 */
function wtb_configure_countries_form_submit($form, &$form_state) {
  if (isset($form['#post']['skip_region'])) {
    $countries = array_change_key_case(location_get_iso3166_list(), CASE_UPPER);
    variable_set('wtb_countries_skip_region', $form['#post']['skip_region']);
  }
  else {
    variable_set('wtb_countries_skip_region', array());
  }

  if (isset($form['#post']['show_always'])) {
    $countries = array_change_key_case(location_get_iso3166_list(), CASE_UPPER);
    variable_set('wtb_countries_show_always', $form['#post']['show_always']);
  }
  else {
    variable_set('wtb_countries_show_always', array());
  }

  drupal_set_message('Configurations have been saved successfully');

}


/**
 * Views field extension for formatting data
 *
 * @param $data
 */
function views_distributor_list_customfield($data) {
/*  $results = db_query('SELECT n.nid, n.title FROM {node} n'
             . ' INNER JOIN {content_field_product_groups} cfpg ON n.nid = cfpg.nid'
             . ' WHERE cfpg.field_product_groups_nid = %d', $data->nid); */
  $results = db_query('SELECT n.nid, n.title FROM {node} n'
    . ' INNER JOIN {field_data_field_product_groups} cfpg ON n.nid = cfpg.entity_id'
    . ' WHERE cfpg.field_product_groups_nid = %d', $data->nid);

  while ($rdata = db_fetch_object($results)) {
    echo l($rdata->title, 'node/' . $rdata->nid) . '<br/>';
  }
}


/**
 * Functionality to build custom view for Countries and their regions
 * TODO: Uhh...countries from the Locale module, plz. KTHXBYE!
 *
 * @return string
 */
function wtb_countries_regions_listing() {
  $countries = array();
  $countries_base = array_change_key_case(location_get_iso3166_list(), CASE_UPPER);

  if ((isset($_GET['country'])) && (isset($countries_base[$_GET['country']]))) {
    $countries[$_GET['country']] = $countries_base[$_GET['country']];
  }
  else {
    $countries = $countries_base;
  }
  asort($countries);

  $flagged_countries = variable_get('wtb_countries_skip_region', array());
  $listing = '';
  $listing = ' <div><fieldset>';
  $listing .= drupal_render(drupal_get_form('wtb_country_region_form', $countries_base));
  $listing .= '<br/><table><th> Country Name </th> <th> Country Code </th> <th> Status </th> <th> Region Name </th> <th> Region Code </th> ';

  $pagination_counter = 50;
  $page_no = (isset($_GET['page']) && is_numeric($_GET['page'])) ? $_GET['page'] : 1;
  $counter = 50;
  foreach ($countries as $key => $value) {
    if ((isset($_GET['status'])) && ($_GET['status'] == 1) && (isset($flagged_countries[$key]))) {
      continue;
    }
    if ((isset($_GET['status'])) && ($_GET['status'] == 2) && (!isset($flagged_countries[$key]))) {
      continue;
    }

    $regions = location_get_provinces($key);
    if (count($regions) > 0) {
      asort($regions);
      foreach ($regions as $rkey => $rvalue) {
        if ($counter < ($page_no * $pagination_counter)) {
          $counter++;
          continue;
        }
        else {
          if ($counter < ($page_no * $pagination_counter + $pagination_counter)) {
            $listing .= '<tr> <td> ' . $value . ' </td> <td> ' . $key . ' </td> <td> ' . ((isset($flagged_countries[$key])) ? 'Inactive' : 'Active') . ' </td> <td>' . $rvalue . ' </td> <td> ' . $rkey . ' </td></tr>';
          }
          $counter++;
        }
      }
    }
    else {
      if ($counter < ($page_no * $pagination_counter)) {
        $counter++;
        continue;
      }
      else {
        if ($counter < ($page_no * $pagination_counter + $pagination_counter)) {
          $listing .= '<tr> <td> ' . $value . ' </td> <td> ' . $key . ' </td> <td> ' . ((isset($flagged_countries[$key])) ? 'Inactive' : 'Active') . ' </td> <td> - </td> <td> - </td></tr>';
        }
        $counter++;
      }
    }
  }
  $wtb_listing_base = base_path() . 'admin/content/countries-regions/';
  $param = array();
  if ((isset($_GET['country'])) && (isset($countries_base[$_GET['country']]))) {
    $param[] = 'country=' . $_GET['country'];
  }
  else {
    $param[] = 'country=0';
  }
  if (isset($_GET['status'])) {
    $param[] = 'status=' . $_GET['status'];
  }
  else {
    $param[] = 'status=0';
  }
  $counter -= 50;
  $param_str = implode('&', $param);
  $max_pages = ceil($counter / $pagination_counter);
  $first = $wtb_listing_base . '?' . $param_str . '&page=1';
  $prev = $wtb_listing_base . '?' . $param_str . '&page=' . ((($page_no - 1) > 1) ? ($page_no - 1) : 1);
  $prev2 = $wtb_listing_base . '?' . $param_str . '&page=' . ((($page_no - 2) > 1) ? ($page_no - 2) : 2);
  $next = $wtb_listing_base . '?' . $param_str . '&page=' . ((($page_no + 1) < $max_pages) ? ($page_no + 1) : $max_pages);
  $next2 = $wtb_listing_base . '?' . $param_str . '&page=' . ((($page_no + 2) < $max_pages) ? ($page_no + 2) : $max_pages);
  $last = $wtb_listing_base . '?' . $param_str . '&page=' . $max_pages;
  $listing .= "</table></fieldset><div class='pager clear-block'><ul class='links pager pager-list'>";
  if ($page_no > 1) {
    $listing .= "<li class='pager-item active'><a class='active' href='$first'>First</a></li>";
  }
  if ($page_no > 1) {
    $listing .= "<li class='pager-item active'><a class='active' href='$prev'>Prev</a></li>";
  }
  if ($page_no > 2) {
    $listing .= "<li class='pager-item active'><a class='active' href='$prev2'>" . ($page_no - 2) . "</a></li>";
  }
  if ($page_no > 1) {
    $listing .= "<li class='pager-item active'><a class='active' href='$prev'>" . ($page_no - 1) . "</a></li>";
  }
  if ($counter > 0) {
    $listing .= "<li class='pager-current active'><span>$page_no</span></li>";
  }
  else {
    $listing .= "<li>No results found.</li>";
  }
  if (($page_no + 1) <= $max_pages) {
    $listing .= "<li class='pager-item active'><a class='active' href='$next'>" . ($page_no + 1) . "</a></li>";
  }
  if (($page_no + 2) <= $max_pages) {
    $listing .= "<li class='pager-item active'><a class='active' href='$next2'>" . ($page_no + 2) . "</a></li>";
  }
  if (($page_no + 1) <= $max_pages) {
    $listing .= "<li class='pager-item active'><a class='active' href='$next'>Next</a></li>";
  }
  if (($page_no + 1) <= $max_pages) {
    $listing .= "<li class='pager-item active'><a class='active' href='$last'>Last</a></li>";
  }
  $listing .= "</ul></div>
    </div>";
  return $listing;
}


/**
 * Implementation of hook_form().
 * For building countries & regions filter
 *
 * @param $form
 * @param $form_state
 * @param null $countries
 * @return array
 */
function wtb_country_region_form($form, $form_state, $countries = NULL) {
  $form = array();
  $countries = array(0 => 'Select Country') + $countries;
  $get_country = (isset($_GET['country']) ? $_GET['country'] : '');
  $form['country'] = array(
    '#type' => 'select',
    '#title' => t('Country List'),
    '#description' => t('Select to filter by Country name'),
    '#default_value' => isset($countries[$get_country]) ? $get_country : 0,
    '#options' => $countries,
  );
  $form['status'] = array(
    '#type' => 'select',
    '#title' => t('Country Status'),
    '#description' => t('Select to filter by Country status'),
    '#default_value' => isset($_GET['status']) ? $_GET['status'] : 0,
    '#options' => array(
      0 => 'Select Status',
      1 => 'Active',
      2 => 'Inactive',
    ),
  );
  $form['apply'] = array(
    '#type' => 'submit',
    '#value' => t('Apply'),
  );
  $form['clear-field'] = array(
    '#type' => 'submit',
    '#value' => t('Clear Selection'),
  );
  return $form;
}


/**
 * Implementation of hook_submit for countries & regions filter form
 *
 * @param $form
 * @param $form_state
 */
function wtb_country_region_form_submit(&$form, &$form_state) {
  if ($form_state['values']['op'] == 'Apply') {
    drupal_goto('/admin/content/countries-regions', array(
      'query' => array(
        'country' => $form_state['values']['country'],
        'status' => $form_state['values']['status']
      )
    ));
//    $form_state['#redirect'] = array(base_path() . '/admin/content/countries-regions', 'country=' . $form_state['values']['country'] . '&status=' . $form_state['values']['status']);
  }
  else {
    drupal_goto('/admin/content/countries-regions');
  }
}


/**
 * Export distributors and their products.
 * Output is in CSV format
 * TODO: Switch this to a View.
 */
function export_distributor_records() {
  $data = array();
  $prod_arr = array();
  //Build product array("nid"=>title)
  $iresults = db_query('SELECT node.nid, node.title FROM {node} node WHERE node.type = :node_type', array(':node_type' => "product"));
  foreach ($iresults as $idata) {
    $prod_arr[$idata->nid] = $idata->title;
  }
  //Base query to get distributors and its products
  db_query('SET SESSION group_concat_max_len = 1000000'); //Prevent GROUP_CONCAT from truncating data
/*  $fresults = db_query("SELECT node.title AS GroupName,
                      node.nid AS GroupNid,
                      GROUP_CONCAT(DISTINCT gn.nid SEPARATOR ', ') AS ProductNids,
                      GROUP_CONCAT(DISTINCT gn.title SEPARATOR '||') AS ProductNames
                      FROM {node} node
                      LEFT JOIN {content_type_product_distributor_group} node_data_field_not_available ON node.vid = node_data_field_not_available.vid
                      LEFT JOIN {content_field_products} node_data_field_products ON node.vid = node_data_field_products.vid
                      LEFT JOIN {node} gn ON node_data_field_products.field_products_nid = gn.nid
                      LEFT JOIN {content_type_product} ctp ON node_data_field_products.field_products_nid = ctp.nid
                      WHERE node.type in ('product_distributor_group')
                      GROUP BY node.title
                      ORDER BY node.title ASC", array()); */
  $fresults = db_query("SELECT node.title AS GroupName,
                      node.nid AS GroupNid,
                      GROUP_CONCAT(DISTINCT gn.nid SEPARATOR ', ') AS ProductNids,
                      GROUP_CONCAT(DISTINCT gn.title SEPARATOR '||') AS ProductNames
                      FROM {node} node
                      LEFT JOIN {field_data_field_products} node_data_field_products ON node.vid = node_data_field_products.revision_id
                      LEFT JOIN {node} gn ON node_data_field_products.field_products_nid = gn.nid
                      WHERE node.type in ('product_distributor_group')
                      GROUP BY node.title
                      ORDER BY node.title ASC", array());  // CONFUSE ???

  //export in CSV format
  $filename = "distributors.csv";
  header('Content-type: application/text');
  header('Content-Disposition: attachment; filename=' . $filename);
  $output = '';
  $output .= '"Distributor",';
  $output .= '"Products"';
  echo $output . "\r\n";
  foreach ($fresults as $fdata) {
    $output = '';
    $output .= '"' . $fdata->GroupName . '",';
    $output .= '"' . $fdata->ProductNames . '"';
    echo $output . "\r\n";
  }
}
