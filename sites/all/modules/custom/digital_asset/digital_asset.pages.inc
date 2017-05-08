<?php
// $Id$

/**
 * @file
 * support pages for digital asset system
 *
 */

/**
 * AMS Main menu page
 *
 * @return string
 */
function digital_asset_main_menu() {
  $items = array(
    'List' => l('List digital assets', 'digital_asset/list'),
    'Query by related product' => l('Query by related product', 'digital_asset/product_query'),
    'Add' => l('Add an asset', 'digital_asset/add'),
  );
  return theme('digital_asset_main_menu', array('menu_items' => $items));
}

/**
 * @param $node
 * @return string
 */
function digital_asset_page_view($node) {
  drupal_set_title(digital_asset_page_title($node));
  return theme('digital_asset', array('node' => $node));
}

/**
 * @param $node
 */
function digital_asset_edit($node) {

  // Oopsie.
  /*
  $path = 'node/' . $node->nid . '/edit';
  drupal_goto($path);
  */
  if (fnet_common_get_field_value('digital_asset', $node, 'field_dam_parent', 'nid')) {
    $output = drupal_get_form('digital_asset_node_form', $node, $is_child = TRUE);
  }
  else {
    $output = drupal_get_form('digital_asset_node_form', $node, $is_child = FALSE);
  }
  drupal_set_title(digital_asset_page_title($node));
  return $output;
}

/**
 * @param null $parent
 * @return array|mixed
 */
function digital_asset_add($parent = NULL) {
  global $user;
  // Initialize settings:
  $node = array(
    'uid' => $user->uid,
    'name' => (isset($user->name) ? $user->name : ''),
    'type' => 'digital_asset',
    'language' => LANGUAGE_NONE,
  );
  if ($parent) {
    $node_extra = array(
      'field_dam_parent' => array(LANGUAGE_NONE => array(array('nid' => $parent->nid))),
      'field_dam_asset_type' => $parent->field_dam_asset_type,
      'field_dam_entitlement_level' => $parent->field_dam_entitlement_level,
      // DEPRECATED.
      // 'field_dam_asset_groups' => $parent->field_dam_access_groups,
      'field_dam_industry' => $parent->field_dam_industry,
      'field_dam_related_product' => $parent->field_dam_related_product,
    );
    $node = array_merge($node, $node_extra);
    $is_child = TRUE;
  }
  else {
    $is_child = FALSE;
  }
  drupal_set_title(t('Create digital asset'));
  $node = (object) $node;
  $output = drupal_get_form('digital_asset_node_form', $node, $is_child);

  return $output;
}

/**
 * Help function for ccs categories ajax
 *
 * @param null $level_1
 * @param null $level_2
 * @param null $level_3
 * @param null $Level_4
 * @param bool $all
 * @return array
 */
function digital_asset_ccs_categories($level_1 = NULL, $level_2 = NULL, $level_3 = NULL, $level_4 = NULL, $all = TRUE) {
  $options = array();
  $column = 'level_1_entity';
  $where = '';
  if (!empty($level_1)) {
    if ($level_1 !== TRUE) {
      $where = "where level_1_entity = ':level1' ";
    }
    $column = 'level_2_catalog';
    if (!empty($level_1) && !empty($level_2)) {
      if ($level_2 !== TRUE) {
        $where .= "AND level_2_catalog = ':level2' ";
      }
      $column = 'level_3_group';
      if (!empty($level_1) && !empty($level_2) && !empty($level_3)) {
        if ($level_3 !== TRUE) {
          $where .= "AND level_3_group = ':level3' ";
        }
        $column = 'level_4_sub_group';
        if (!empty($level_1) && !empty($level_2) && !empty($level_3) && !empty($level_4)) {
          if ($level_4 !== TRUE) {
            $where .= "AND level_4_sub_group = ':level4' ";
          }
          $column = 'level_5_end_group';
        }
      }
    }
  }
  // for now don't limit selection by higher level category
  if ($all) {
    $where = '';
  }
  $sql = "SELECT DISTINCT $column FROM {digital_asset_ccs_categories} $where ORDER BY $column";
  $result = db_query($sql, array(
    ':level1' => $level_1,
    ':level2' => $level_2,
    ':level3' => $level_3,
    ':level4' => $level_4,
  ));
  foreach ($result as $option) {
    if (!empty($option->$column)) {
      $options[strtoupper($option->$column)] = ucwords($option->$column);
    }
  }
  return $options;
}

/**
 * @param $form
 * @param $form_state
 * @param $node
 * @return array
 */
function digital_asset_page_view_form($form, &$form_state, $node) {
  $form = array();
  $form['title'] = array(
    '#type' => 'item',
    '#title' => t('Title'),
    '#markup' => $node->title,
  );
  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('Description'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'body', 'value'),
  );
  $tags = '';
  if (isset($node->taxonomy_vocabulary_17) && is_array($node->taxonomy_vocabulary_17)) {
    foreach ($node->taxonomy_vocabulary_17 as $key => $term) {
      $tags .= ', ' . $term->name;
    }
    $tags = trim($tags, " \t\n\r\0\x0B,");
  }
  $form['tags'] = array(
    '#type' => 'item',
    '#title' => t('Tags'),
    '#markup' => $tags,
  );
  $form['document_status'] = array(
    '#type' => 'item',
    '#title' => t('Document Status'),
    '#markup' => ucfirst(fnet_common_get_field_value('digital_asset', $node, 'field_dam_document_status', 'value')),
  );
  $form['changed'] = array(
    '#type' => 'item',
    '#title' => 'Updated',
    '#markup' => date('Y-m-d', $node->changed),
  );
  $form['document_id'] = array(
    '#type' => 'item',
    '#title' => t('Document ID'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_document_id', 'value'),
  );
  $form['revision'] = array(
    '#type' => 'item',
    '#title' => t('Rev'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_revision_letter', 'value'),
  );
  $form['language'] = array(
    '#type' => 'item',
    '#title' => t('Language'),
    '#markup' => fnet_helper_iso_language_to_english(fnet_common_get_field_value('digital_asset', $node, 'field_dam_language', 'value')),
  );
  $parent_nid = fnet_common_get_field_value('digital_asset', $node, 'field_dam_parent', 'nid');
  if (!empty($parent_nid)) {
    $parent_document_id = digital_asset_get_document_id($parent_nid);
    $link = l($parent_document_id, 'digital_asset/' . $parent_nid);
    $form['parent'] = array(
      '#type' => 'item',
      '#title' => t('Parent Asset'),
      '#markup' => $link,
    );
  }
  else {
    $form['add_child'] = array(
      '#type' => 'markup',
      '#markup' => l('Add child asset', "digital_asset/$node->nid/add_child"),
    );
    $form['children'] = array(
      '#type' => 'item',
      '#title' => t('Children'),
      '#markup' => views_embed_view('digital_asset_children', 'default', $node->nid),
    );
  }
  $edoc_url = fnet_common_get_field_value('digital_asset', $node, 'field_dam_edoc_url', 'url');
  if (!empty($edoc_url)) {
    $link = str_replace('http://www.flukenetworks.com/', '', $edoc_url);
    $link = l($edoc_url, $link, array('attributes' => array('target' => '_blank')));
    $form['edoc_url'] = array(
      '#type' => 'item',
      '#title' => t('eDoc URL'),
      '#markup' => $link,
    );
  }
  else {
    $server = variable_get('digital_asset_cdn_download_server', 'http://download.flukenetworks.com/');
    $server = trim($server, "/ \t\n\r\0\x0B");
    $folder = trim(fnet_common_get_field_value('digital_asset', $node, 'field_dam_storage_file_folder', 'value'), "/ \t\n\r\0\x0B");
    $url = $server . '/' . $folder . '/' . fnet_common_get_field_value('digital_asset', $node, 'field_dam_storage_filename', 'value');
    if (function_exists('findit_level3_auth_cookie')) {
      findit_level3_auth_cookie($url);
    }
    $filename = fnet_common_get_field_value('digital_asset', $node, 'field_dam_storage_filename', 'value');
    $link = l($filename, $url, array('attributes' => array('target' => '_blank')));
    $form['storage_filename'] = array(
      '#type' => 'item',
      '#title' => t('Filename'),
      '#markup' => $filename,
    );
    $server = $_SERVER['HTTP_HOST'];
    $findit_url = "http://$server/findit/" . fnet_common_get_field_value('digital_asset', $node, 'field_dam_document_id', 'value');
    $form['findit_link'] = array(
      '#type' => 'item',
      '#title' => 'Public Download (FindIt) Link',
      '#markup' => l($findit_url, $findit_url),
    );
    $vftf_url = "http://$server/vftf/" . fnet_common_get_field_value('digital_asset', $node, 'field_dam_document_id', 'value');
    $form['vftf_link'] = array(
      '#type' => 'item',
      '#title' => 'Private Download (VFTF) Link',
      '#markup' => l($vftf_url, $vftf_url),
    );
    $form['cdn_status'] = array(
      '#type' => 'item',
      '#title' => t('CDN Status'),
      '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_cdn_status', 'value'),
    );
    $form['file_size'] = array(
      '#type' => 'item',
      '#title' => t('File Size'),
      '#markup' => format_size(fnet_common_get_field_value('digital_asset', $node, 'field_dam_file_size', 'value')),
    );
  }
  $form['asset_type'] = array(
    '#type' => 'item',
    '#title' => t('Asset Type'),
    '#markup' => ucwords(fnet_common_get_field_value('digital_asset', $node, 'field_dam_asset_type', 'value')),
  );
  if (($node->field_dam_export_controlled[LANGUAGE_NONE][0]['value'] == 1) || (strtolower($node->field_dam_export_controlled[LANGUAGE_NONE][0]['value']) == 'yes')) {
    $export_controlled = 'Yes';
  }
  else {
    $export_controlled = 'No';
  }
  $form['export_controlled'] = array(
    '#type' => 'item',
    '#title' => t('Export Controlled'),
    '#markup' => $export_controlled,
  );
  $form['entitlement_level'] = array(
    '#type' => 'item',
    '#title' => t('Entitlement'),
    '#markup' => ucwords(fnet_common_get_field_value('digital_asset', $node, 'field_dam_entitlement_level', 'value')),
  );
  if (fnet_common_get_field_value('digital_asset', $node, 'field_dam_entitlement_level', 'value') == 'form') {
    $form['form_processing_url'] = array(
      '#type' => 'item',
      '#title' => t('Form Processing URL'),
      '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_form_url', 'url'),
    );
  }
  if (count($node->field_dam_access_groups) > 0) {
    $value = '<ul>';
    foreach ($node->field_dam_access_groups as $item) {
      if (!empty($item['value'])) {
        $value .= '<li>' . $item['value'] . '</li>';
      }
    }
    $value .= '</ul>';
    $form['access_groups'] = array(
      '#type' => 'item',
      '#title' => t('Access Groups'),
      '#markup' => $value,
    );
  }
  $value = '<ul>';
  $products = digital_asset_get_related_products($node->nid);
  foreach ($products as $product) {
    $value .= '<li>' . $product['title'] . '</li>';
  }
  $value .= '</ul>';
  $form['related_products'] = array(
    '#type' => 'item',
    '#title' => t('Related Products'),
    '#markup' => $value,
  );
  $form['industry'] = array(
    '#type' => 'item',
    '#title' => t('Industry'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_industry', 'value'),
  );
  $form['new_industry'] = array(
    '#type' => 'item',
    '#title' => t('New Industry'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_new_industry', 'value'),
  );
  $options = array(
    'dci' => 'DCI',
    'ent' => 'Enterprise',
    'all' => 'All',
  );
  $business_entity_key = strtolower(fnet_common_get_field_value('digital_asset', $node, 'field_dam_business_entity', 'value'));
  if (!empty($business_entity_key) && isset($options[$business_entity_key])) {
    $business_entity = $options[$business_entity_key];
  }
  else {
    $business_entity = '';
  }
  $form['business_entity'] = array(
    '#type' => 'item',
    '#title' => t('Business Entity'),
    '#markup' => $business_entity,
  );
  $form['bulk_fulfillment'] = array(
    '#type' => 'item',
    '#title' => t('Bulk Fulfillment Eligible'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_bulk_fulfillment', 'value'),
  );
  $form['asset_file_pod'] = array(
    '#type' => 'item',
    '#title' => t('Asset File POD Resolution'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_storage_filename_pod', 'value'),
  );
  $server = $_SERVER['HTTP_HOST'];
  $filename = fnet_common_get_field_value('digital_asset', $node, 'field_dam_storage_filename_pod', 'value');
  if (!empty($filename)) {
    $findit_pod_url = "http://$server/findit/pod/" . fnet_common_get_field_value('digital_asset', $node, 'field_dam_document_id', 'value');
    $form['findit_pod_link'] = array(
      '#type' => 'item',
      '#title' => 'POD Download (FindIt) Link',
      '#markup' => l($findit_pod_url, $findit_pod_url),
    );
  }
  $form['cost_center'] = array(
    '#type' => 'item',
    '#title' => t('Cost Center'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_cost_center', 'value'),
  );
  $form['print_on_demand'] = array(
    '#type' => 'item',
    '#title' => t('Print On Demand'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_print_on_demand', 'value'),
  );
  $owners = array(0 => 'none') + digital_asset_get_document_owners();
  $form['owner'] = array(
    '#type' => 'item',
    '#title' => t('Owner'),
    '#markup' => $owners[$node->uid],
  );
  $form['unit_of_measure'] = array(
    '#type' => 'item',
    '#title' => t('Unit Of Measure'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_unit_of_measure', 'value'),
  );
  $form['uom_quantity'] = array(
    '#type' => 'item',
    '#title' => t('UOM Quantity'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_uom_quantity', 'value'),
  );
  $form['order_quantity_max'] = array(
    '#type' => 'item',
    '#title' => t('Order Quantity Max'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_order_quantity_max', 'value'),
  );
  $form['l1_category'] = array(
    '#type' => 'item',
    '#title' => t('Level 1 Entity'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_l1_category', 'value'),
  );
  $form['l2_category'] = array(
    '#type' => 'item',
    '#title' => t('Level 2 Catalog'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_l2_category', 'value'),
  );
  $form['l3_category'] = array(
    '#type' => 'item',
    '#title' => t('Level 3 Group'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_l3_category', 'value'),
  );
  $form['l4_category'] = array(
    '#type' => 'item',
    '#title' => t('Level 4 Sub Group'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_l4_category', 'value'),
  );
  $form['link'] = array(
    '#markup' => l(t('Return to asset list'), 'digital_asset/list'),
  );

  return $form;
}

/**
 * @param $form
 * @param $form_state
 * @param $parameters
 * @return array
 */
function digital_asset_asset_query_form($form, &$form_state) {
  $form = array();
  $form['document_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Document ID'),
    '#size' => 10,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['document_id']) ? $form_state['values']['document_id'] : (isset($_REQUEST['document_id'])) ? $_REQUEST['document_id'] : '',
  );
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#size' => 30,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['title']) ? $form_state['values']['title'] : (isset($_REQUEST['title'])) ? $_REQUEST['title'] : '',
  );
  $options = array('any' => 'any') + digital_asset_asset_types();
  $form['asset_type'] = array(
    '#type' => 'select',
    '#title' => t('Asset type'),
    '#options' => $options,
    '#multiple' => TRUE,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['asset_type']) ? $form_state['values']['asset_type'] : (isset($_REQUEST['asset_type'])) ? $_REQUEST['asset_type'] : '',
  );
  $form['tags'] = array(
    '#type' => 'textfield',
    '#title' => t('Tags'),
    '#size' => 30,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['tags']) ? $form_state['values']['tags'] : (isset($_REQUEST['tags'])) ? $_REQUEST['tags'] : '',
  );
  $form['language'] = array(
    '#type' => 'select',
    '#title' => t('Language'),
    '#options' => array('any' => 'any') + digital_asset_languages(),
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['language']) ? $form_state['values']['language'] : (isset($_REQUEST['language'])) ? $_REQUEST['language'] : '',
  );
  $status_options = array(
    'any' => 'any',
    'live' => 'Live',
    'review' => 'Review',
    'archive' => 'Archive',
  );
  $form['status'] = array(
    '#type' => 'select',
    '#title' => t('Status'),
    '#options' => $status_options,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['status']) ? $form_state['values']['status'] : (isset($_REQUEST['status'])) ? $_REQUEST['status'] : '',
  );
  $owner_options = array('any' => 'any') + digital_asset_get_document_owners();
  $form['owner'] = array(
    '#type' => 'select',
    '#title' => t('Owner'),
    '#options' => $owner_options,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['owner']) ? $form_state['values']['owner'] : (isset($_REQUEST['owner'])) ? $_REQUEST['owner'] : '',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Search',
  );
  if (empty($form_state['digital_asset']['table'])) {
    $parameters = $_REQUEST;
    unset($parameters['page']);
    $table = digital_asset_asset_query($parameters);
  }
  else {
    $table = $form_state['digital_asset']['table'];
  }
  $form['table'] = array(
    '#markup' => $table,
  );
  return $form;
}

/**
 * @param $form
 * @param $form_state
 */
function digital_asset_asset_query_form_submit($form, &$form_state) {
  $parameters = array(
    'language' => $form_state['values']['language'],
    'owner' => $form_state['values']['owner'],
    'status' => $form_state['values']['status'],
    'document_id' => $form_state['values']['document_id'],
    'asset_type' => $form_state['values']['asset_type'],
    'tags' => $form_state['values']['tags'],
    'title' => $form_state['values']['title'],
  );
  foreach ($parameters as $key => $value) {
    unset($_GET[$key]);
  }
  unset($_GET['page']);
  global $pager_page_array, $pager_total, $pager_total_items, $pager_limits;
  unset($pager_page_array);
  unset($pager_total);
  unset($pager_total_items);
  unset($pager_limits);
  $form_state['digital_asset']['table'] = digital_asset_asset_query($parameters);
  $form_state['rebuild'] = TRUE;
}

function digital_asset_asset_query($parameters) {
  $language = (isset($parameters['language'])) ? $parameters['language'] : '';
  $owner = (isset($parameters['owner'])) ? $parameters['owner'] : '';
  $status = (isset($parameters['status'])) ? $parameters['status'] : '';
  $document_id = (isset($parameters['document_id'])) ? $parameters['document_id'] : '';
  $asset_type = (isset($parameters['asset_type'])) ? $parameters['asset_type'] : '';
  $tags = (isset($parameters['tags'])) ? $parameters['tags'] : '';
  $title = (isset($parameters['title'])) ? $parameters['title'] : '';

  $query = db_select('node', 'n');
  $query->fields('n', array('nid', 'uid', 'created', 'changed'));
  $query->addJoin('INNER', 'node_revision', 'r', 'n.vid = r.vid');
  $query->fields('r', array('title'));
  $query->addJoin('INNER', 'field_data_field_dam_document_id', 'doc_id', 'r.vid = doc_id.revision_id');
  $query->fields('doc_id', array('field_dam_document_id_value'));
  $query->addJoin('INNER', 'field_data_field_dam_language', 'lang', 'r.vid = lang.revision_id');
  $query->fields('lang', array('field_dam_language_value'));
  $query->addJoin('INNER', 'field_data_field_dam_asset_type', 'type', 'r.vid = type.revision_id');
  $query->fields('type', array('field_dam_asset_type_value'));
  $query->addJoin('INNER', 'field_data_field_dam_document_status', 'status', 'r.vid = status.revision_id');
  $query->fields('status', array('field_dam_document_status_value'));
  if (!empty($language) && ($language != 'any')) {
    $query->condition('field_dam_language_value', $language);
  }
  if (!empty($document_id)) {
    $query->condition('field_dam_document_id_value', '%' . $document_id . '%', 'LIKE');
  }
  if (!empty($title)) {
    $query->condition('r.title', '%' . $title . '%', 'LIKE');
  }
  if (!empty($asset_type) && (!in_array('any', $asset_type))) {
    $query->condition('field_dam_asset_type_value', $asset_type);
  }
  if (!empty($status) && ($status != 'any')) {
    $query->condition('field_dam_document_status_value', $status);
  }
  if (!empty($owner) && ($owner != 'any')) {
    $query->condition('n.uid', $owner);
  }
  if (!empty($tags)) {
    $query->addJoin('LEFT', 'taxonomy_index', 'ti', 'n.nid = ti.nid');
    $query->addJoin('LEFT', 'taxonomy_term_data', 'td', 'ti.tid = td.tid');
    $terms = explode(' ', $tags);
    $or = db_or();
    foreach ($terms as $term) {
      $or->condition('td.name', $term);
    }
    $query->condition($or);
    $query->distinct();
  }
  $header = array(
    array(
      'data' => 'Document ID',
      'field' => 'field_dam_document_id_value',
    ),
    array(
      'data' => 'Language',
      'field' => 'field_dam_language_value',
    ),
    array(
      'data' => 'Title',
      'field' => 'r.title',
      'sort' => 'asc',
    ),
    array(
      'data' => 'Type',
      'field' => 'field_dam_asset_type_value',
    ),
    array(
      'data' => 'Status',
      'field' => 'field_dam_document_status_value',
    ),
    array(
      'data' => 'Owner',
    ),
    array(
      'data' => 'Created',
      'field' => 'created'
    ),
    array(
      'data' => 'Updated',
      'field' => 'changed'
    )
  );
  $owners = array(0 => 'none') + digital_asset_get_document_owners();
  $result = $query->extend('PagerDefault')
    ->limit(50)
    ->extend('TableSort')
    ->orderByHeader($header)
    ->execute();
  $data = array();
  foreach ($result as $row) {
    $data[] = array(
      l($row->field_dam_document_id_value, 'digital_asset/' . $row->nid),
      fnet_helper_iso_language_to_english($row->field_dam_language_value),
      $row->title,
      ucwords($row->field_dam_asset_type_value),
      ucwords($row->field_dam_document_status_value),
      $owners[$row->uid],
      date('m/d/Y', $row->created),
      date('m/d/Y', $row->changed),
    );
  }
  $output = '<div id="digital-asset-query-result">';
  $output .= theme('table', array('header' => $header, 'rows' => $data));
  $output .= theme('pager', array(
    'tags' => NULL,
    'element' => 0,
    'parameters' => $parameters
  ));
  $output .= '</div>';
  $output .= '<div>' . l('Add an asset', 'digital_asset/add') . '</div>';
  return $output;
}

/**
 * @param $form
 * @param $form_state
 * @param $parameters
 * @return array
 */
function digital_asset_query_by_product_form($form, &$form_state) {
  $form = array();
  $query = db_select('node', 'n')
    ->fields('n', array('nid', 'title'))
    ->distinct()
    ->orderBy('title');
  $query->addJoin('INNER', 'field_data_field_pcatid', 'p', 'n.nid = p.entity_id');
  $query->fields('p', array('field_pcatid_value'));
  $query->addJoin('INNER', 'field_data_field_dam_related_product', 'rp', 'n.nid = rp.field_dam_related_product_nid');
  $query->isNotNull('field_pcatid_value');
  $result = $query->execute();
  $product_options = array();
  if ($result) {
    foreach ($result as $row) {
      $product_options[$row->nid] = $row->title;
    }
  }
  $form['product'] = array(
    '#type' => 'select',
    '#title' => 'Product',
    '#options' => $product_options,
    '#required' => FALSE,
    '#default_value' => $form_state['values']['product'] ? $form_state['values']['product'] : (isset($_REQUEST['product'])) ? $_REQUEST['product'] : '',
  );
  $form['language'] = array(
    '#type' => 'select',
    '#title' => t('Language'),
    '#options' => array('any' => 'any') + digital_asset_languages(),
    '#required' => FALSE,
    '#default_value' => $form_state['values']['language'] ? $form_state['values']['language'] : (isset($_REQUEST['language'])) ? $_REQUEST['language'] : '',
  );
  $type_options = array('any' => 'any') + digital_asset_asset_types();
  $form['asset_type'] = array(
    '#type' => 'select',
    '#title' => t('Asset type'),
    '#options' => $type_options,
    '#required' => FALSE,
    '#default_value' => $form_state['values']['asset_type'] ? $form_state['values']['asset_type'] : (isset($_REQUEST['asset_type'])) ? $_REQUEST['asset_type'] : '',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Search',
  );
  if (empty($form_state['digital_asset']['table'])) {
    $parameters = $_REQUEST;
    unset($parameters['page']);
    if (empty($parameters['product'])) {
      $parameters['product'] = array_shift(array_keys($product_options));
    }
    $table = digital_asset_query_by_product($parameters);
  }
  else {
    $table = $form_state['digital_asset']['table'];
  }
  $form['table'] = array(
    '#markup' => $table,
  );
  return $form;
}

/**
 * @param $form
 * @param $form_state
 */
function digital_asset_query_by_product_form_submit($form, &$form_state) {
  $parameters = array(
    'product' => $form_state['values']['product'],
    'language' => $form_state['values']['language'],
    'asset_type' => $form_state['values']['asset_type'],
  );
  foreach ($parameters as $key => $value) {
    unset($_GET[$key]);
  }
  unset($_GET['page']);
  global $pager_page_array, $pager_total, $pager_total_items, $pager_limits;
  unset($pager_page_array);
  unset($pager_total);
  unset($pager_total_items);
  unset($pager_limits);
  $form_state['digital_asset']['table'] = digital_asset_query_by_product($parameters);
  $form_state['rebuild'] = TRUE;
}

/**
 * @return string
 * @throws \Exception
 */
function digital_asset_query_by_product($parameters) {
  $product = (isset($parameters['product'])) ? $parameters['product'] : '';
  $language = (isset($parameters['language'])) ? $parameters['language'] : '';
  $asset_type = (isset($parameters['asset_type'])) ? $parameters['asset_type'] : '';
  $query = db_select('node', 'n')->fields('n', array('nid', 'title'));
  $query->addJoin('INNER', 'field_data_field_dam_document_id', 'doc_id', 'n.nid = doc_id.entity_id');
  $query->fields('doc_id', array('field_dam_document_id_value'));
  $query->addJoin('LEFT', 'field_data_field_dam_revision_letter', 'rev', 'n.nid = rev.entity_id');
  $query->fields('rev', array('field_dam_revision_letter_value'));
  $query->addJoin('LEFT', 'field_data_field_dam_language', 'lang', 'n.nid = lang.entity_id');
  $query->fields('lang', array('field_dam_language_value'));
  $query->addJoin('LEFT', 'field_data_field_dam_asset_type', 'type', 'n.nid = type.entity_id');
  $query->fields('type', array('field_dam_asset_type_value'));
  $query->addJoin('LEFT', 'field_data_field_dam_document_status', 'status', 'n.nid = status.entity_id');
  $query->fields('status', array('field_dam_document_status_value'));
  $query->addJoin('INNER', 'field_data_field_dam_related_product', 'rp', 'n.nid = rp.entity_id');
  $query->condition('field_dam_related_product_nid', $product);
  if (!empty($language) && ($language != 'any')) {
    $query->condition('field_dam_language_value', $language);
  }
  if (!empty($asset_type) && ($asset_type != 'any')) {
    $query->condition('field_dam_asset_type_value', $asset_type);
  }
  $header = array(
    array(
      'data' => 'Document ID',
      'field' => 'field_dam_document_id_value',
    ),
    array(
      'data' => 'Language',
      'field' => 'field_dam_language_value',
    ),
    array(
      'data' => 'Title',
      'field' => 'title',
      'sort' => 'asc',
    ),
    array(
      'data' => 'Type',
      'field' => 'field_dam_asset_type_value',
    ),
    array(
      'data' => 'Status',
      'field' => 'field_dam_document_status_value',
    ),
  );
  $result = $query->extend('PagerDefault')
    ->limit(50)
    ->extend('TableSort')
    ->orderByHeader($header)
    ->execute();
  $data = array();
  foreach ($result as $row) {
    $data[] = array(
      l($row->field_dam_document_id_value, 'digital_asset/' . $row->nid),
      fnet_helper_iso_language_to_english($row->field_dam_language_value),
      $row->title,
      ucwords($row->field_dam_asset_type_value),
      $row->field_dam_document_status_value,
    );
  }
  $parameters = array(
    'asset_type' => $asset_type,
    'language' => $language,
    'product' => $product,
  );
  $output = '<div id="digital-asset-query-result">';
  $output .= theme('table', array('header' => $header, 'rows' => $data));
  $output .= theme('pager', array(
    'tags' => NULL,
    'element' => 0,
    'parameters' => $parameters
  ));
  $output .= '</div>';
  return $output;
}
