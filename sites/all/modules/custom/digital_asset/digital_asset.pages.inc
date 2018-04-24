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
  $items = [
    'List' => l('List digital assets', 'digital_asset/list'),
    'Query by related product' => l('Query by related product', 'digital_asset/product_query'),
    'Add' => l('Add an asset', 'digital_asset/add'),
  ];
  try {
    return theme('digital_asset_main_menu', ['menu_items' => $items]);
  } catch (Exception $e) {
    watchdog('Digital Asset', $e->getMessage());
  }
}

/**
 * @param $node
 * @return string
 */
function digital_asset_page_view($node) {
  drupal_set_title(digital_asset_page_title($node));
  try {
    return theme('digital_asset', ['node' => $node]);
  } catch (Exception $e) {
    watchdog('Digital Asset', $e->getMessage());
  }
}

/**
 * TODO: This is funky. Shouldn't this just modify the Node Edit page?
 * @param $node
 * @return array|mixed
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
  $node = [
    'uid' => $user->uid,
    'name' => (isset($user->name) ? $user->name : ''),
    'type' => 'digital_asset',
    'language' => LANGUAGE_NONE,
  ];
  if ($parent) {
    $node_extra = [
      'field_dam_parent' => [LANGUAGE_NONE => [['nid' => $parent->nid]]],
      'field_dam_asset_type' => $parent->field_dam_asset_type,
      'field_dam_entitlement_level' => $parent->field_dam_entitlement_level,
      // DEPRECATED.
      // 'field_dam_asset_groups' => $parent->field_dam_access_groups,
      'field_dam_industry' => $parent->field_dam_industry,
      'field_related_products' => $parent->field_related_products,
    ];
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
 * @param null $level_4
 * @param bool $all
 * @return array
 */
function digital_asset_ccs_categories($level_1 = NULL, $level_2 = NULL, $level_3 = NULL, $level_4 = NULL, $all = TRUE) {
  $options = [];
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
  $result = db_query($sql, [
    ':level1' => $level_1,
    ':level2' => $level_2,
    ':level3' => $level_3,
    ':level4' => $level_4,
  ]);
  foreach ($result as $option) {
    if (!empty($option->$column)) {
      $options[strtoupper($option->$column)] = ucwords($option->$column);
    }
  }
  return $options;
}

/**
 * The alternative to the normal Node view form.
 *
 * @param $form
 * @param $form_state
 * @param $node
 * @return array
 */
function digital_asset_page_view_form($form, &$form_state, $node) {
  $form = [];
  $form['title'] = [
    '#type' => 'item',
    '#title' => t('Title'),
    '#markup' => $node->title,
  ];
  $form['description'] = [
    '#type' => 'item',
    '#title' => t('Description'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'body', 'value'),
  ];
  $tags = '';
  if (isset($node->taxonomy_vocabulary_17) && is_array($node->taxonomy_vocabulary_17)) {
    foreach ($node->taxonomy_vocabulary_17 as $key => $term) {
      $tags .= ', ' . $term->name;
    }
    $tags = trim($tags, " \t\n\r\0\x0B,");
  }
  $form['tags'] = [
    '#type' => 'item',
    '#title' => t('Tags'),
    '#markup' => $tags,
  ];
  $form['document_status'] = [
    '#type' => 'item',
    '#title' => t('Document Status'),
    '#markup' => ucfirst(fnet_common_get_field_value('digital_asset', $node, 'field_dam_document_status', 'value')),
  ];
  $form['changed'] = [
    '#type' => 'item',
    '#title' => 'Updated',
    '#markup' => date('Y-m-d', $node->changed),
  ];
  $form['document_id'] = [
    '#type' => 'item',
    '#title' => t('Document ID'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_document_id', 'value'),
  ];
  $form['revision'] = [
    '#type' => 'item',
    '#title' => t('Rev'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_revision_letter', 'value'),
  ];
  $form['language'] = [
    '#type' => 'item',
    '#title' => t('Language'),
    '#markup' => fnet_helper_iso_language_to_english(fnet_common_get_field_value('digital_asset', $node, 'field_dam_language', 'value')),
  ];
  $parent_nid = fnet_common_get_field_value('digital_asset', $node, 'field_dam_parent', 'nid');
  if (!empty($parent_nid)) {
    $parent_document_id = digital_asset_get_document_id($parent_nid);
    $link = l($parent_document_id, 'digital_asset/' . $parent_nid);
    $form['parent'] = [
      '#type' => 'item',
      '#title' => t('Parent Asset'),
      '#markup' => $link,
    ];
  }
  else {
    $form['add_child'] = [
      '#type' => 'markup',
      '#markup' => l('Add child asset', "digital_asset/$node->nid/add_child"),
    ];
    $form['children'] = [
      '#type' => 'item',
      '#title' => t('Children'),
      '#markup' => views_embed_view('digital_assets', 'children', $node->nid),
    ];
  }

  $edoc_url = fnet_common_get_field_value('digital_asset', $node, 'field_dam_edoc_url', 'url');
  if (!empty($edoc_url)) {
    $link = str_replace('http://www.flukenetworks.com/', '', $edoc_url);
    $link = l($edoc_url, $link, ['attributes' => ['target' => '_blank']]);
    $form['edoc_url'] = [
      '#type' => 'item',
      '#title' => t('eDoc URL'),
      '#markup' => $link,
    ];
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
    $link = l($filename, $url, ['attributes' => ['target' => '_blank']]);
    $form['storage_filename'] = [
      '#type' => 'item',
      '#title' => t('Filename'),
      '#markup' => $filename,
    ];
    $server = $_SERVER['HTTP_HOST'];
    $findit_url = "http://$server/findit/" . fnet_common_get_field_value('digital_asset', $node, 'field_dam_document_id', 'value');
    $form['findit_link'] = [
      '#type' => 'item',
      '#title' => 'Public Download (FindIt) Link',
      '#markup' => l($findit_url, $findit_url),
    ];
    $vftf_url = "http://$server/vftf/" . fnet_common_get_field_value('digital_asset', $node, 'field_dam_document_id', 'value');
    $form['vftf_link'] = [
      '#type' => 'item',
      '#title' => 'Private Download (VFTF) Link',
      '#markup' => l($vftf_url, $vftf_url),
    ];
    $form['cdn_status'] = [
      '#type' => 'item',
      '#title' => t('CDN Status'),
      '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_cdn_status', 'value'),
    ];
    $form['file_size'] = [
      '#type' => 'item',
      '#title' => t('File Size'),
      '#markup' => format_size(fnet_common_get_field_value('digital_asset', $node, 'field_dam_file_size', 'value')),
    ];
  }
  $form['asset_type'] = [
    '#type' => 'item',
    '#title' => t('Asset Type'),
    '#markup' => ucwords(fnet_common_get_field_value('digital_asset', $node, 'field_dam_asset_type', 'value')),
  ];
  if (($node->field_dam_export_controlled[LANGUAGE_NONE][0]['value'] == 1) || (strtolower($node->field_dam_export_controlled[LANGUAGE_NONE][0]['value']) == 'yes')) {
    $export_controlled = 'Yes';
  }
  else {
    $export_controlled = 'No';
  }
  $form['export_controlled'] = [
    '#type' => 'item',
    '#title' => t('Export Controlled'),
    '#markup' => $export_controlled,
  ];
  $form['entitlement_level'] = [
    '#type' => 'item',
    '#title' => t('Entitlement'),
    '#markup' => ucwords(fnet_common_get_field_value('digital_asset', $node, 'field_dam_entitlement_level', 'value')),
  ];
  if (fnet_common_get_field_value('digital_asset', $node, 'field_dam_entitlement_level', 'value') == 'form') {
    $form['form_processing_url'] = [
      '#type' => 'item',
      '#title' => t('Form Processing URL'),
      '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_form_url', 'url'),
    ];
  }

  $value = '<ul>';
  $products = digital_asset_get_related_products($node->nid);
  foreach ($products as $product) {
    $value .= '<li>' . $product['title'] . '</li>';
  }
  $value .= '</ul>';
  $form['related_products'] = [
    '#type' => 'item',
    '#title' => t('Related Products'),
    '#markup' => $value,
  ];
  $form['industry'] = [
    '#type' => 'item',
    '#title' => t('Industry'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_industry', 'value'),
  ];
  $form['new_industry'] = [
    '#type' => 'item',
    '#title' => t('New Industry'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_new_industry', 'value'),
  ];
  $options = [
    'dci' => 'DCI',
    'ent' => 'Enterprise',
    'all' => 'All',
  ];

  $form['bulk_fulfillment'] = [
    '#type' => 'item',
    '#title' => t('Bulk Fulfillment Eligible'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_bulk_fulfillment', 'value'),
  ];
  $form['asset_file_pod'] = [
    '#type' => 'item',
    '#title' => t('Asset File POD Resolution'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_storage_filename_pod', 'value'),
  ];
  $server = $_SERVER['HTTP_HOST'];
  $filename = fnet_common_get_field_value('digital_asset', $node, 'field_dam_storage_filename_pod', 'value');
  if (!empty($filename)) {
    $findit_pod_url = "http://$server/findit/pod/" . fnet_common_get_field_value('digital_asset', $node, 'field_dam_document_id', 'value');
    $form['findit_pod_link'] = [
      '#type' => 'item',
      '#title' => 'POD Download (FindIt) Link',
      '#markup' => l($findit_pod_url, $findit_pod_url),
    ];
  }
  $form['cost_center'] = [
    '#type' => 'item',
    '#title' => t('Cost Center'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_cost_center', 'value'),
  ];
  $form['print_on_demand'] = [
    '#type' => 'item',
    '#title' => t('Print On Demand'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_print_on_demand', 'value'),
  ];
  $owners = [0 => 'none'] + digital_asset_get_document_owners();
  $form['owner'] = [
    '#type' => 'item',
    '#title' => t('Owner'),
    '#markup' => $owners[$node->uid],
  ];
  $form['unit_of_measure'] = [
    '#type' => 'item',
    '#title' => t('Unit Of Measure'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_unit_of_measure', 'value'),
  ];
  $form['uom_quantity'] = [
    '#type' => 'item',
    '#title' => t('UOM Quantity'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_uom_quantity', 'value'),
  ];
  $form['order_quantity_max'] = [
    '#type' => 'item',
    '#title' => t('Order Quantity Max'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_order_quantity_max', 'value'),
  ];
  $form['l1_category'] = [
    '#type' => 'item',
    '#title' => t('Level 1 Entity'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_l1_category', 'value'),
  ];
  $form['l2_category'] = [
    '#type' => 'item',
    '#title' => t('Level 2 Catalog'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_l2_category', 'value'),
  ];
  $form['l3_category'] = [
    '#type' => 'item',
    '#title' => t('Level 3 Group'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_l3_category', 'value'),
  ];
  $form['l4_category'] = [
    '#type' => 'item',
    '#title' => t('Level 4 Sub Group'),
    '#markup' => fnet_common_get_field_value('digital_asset', $node, 'field_dam_l4_category', 'value'),
  ];
  $form['link'] = [
    '#markup' => l(t('Return to asset list'), 'digital_asset/list'),
  ];

  return $form;
}

/**
 * @param $form
 * @param $form_state
 * @return array
 */
function digital_asset_asset_query_form($form, &$form_state) {
  $form = [];
  $form['document_id'] = [
    '#type' => 'textfield',
    '#title' => t('Document ID'),
    '#size' => 10,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['document_id']) ? $form_state['values']['document_id'] : (isset($_REQUEST['document_id'])) ? $_REQUEST['document_id'] : '',
  ];
  $form['title'] = [
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#size' => 30,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['title']) ? $form_state['values']['title'] : (isset($_REQUEST['title'])) ? $_REQUEST['title'] : '',
  ];
  $options = ['any' => 'any'] + digital_asset_asset_types();
  $form['asset_type'] = [
    '#type' => 'select',
    '#title' => t('Asset type'),
    '#options' => $options,
    '#multiple' => TRUE,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['asset_type']) ? $form_state['values']['asset_type'] : (isset($_REQUEST['asset_type'])) ? $_REQUEST['asset_type'] : '',
  ];
  $form['tags'] = [
    '#type' => 'textfield',
    '#title' => t('Tags'),
    '#size' => 30,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['tags']) ? $form_state['values']['tags'] : (isset($_REQUEST['tags'])) ? $_REQUEST['tags'] : '',
  ];
  $form['language'] = [
    '#type' => 'select',
    '#title' => t('Language'),
    '#options' => ['any' => 'any'] + digital_asset_languages(),
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['language']) ? $form_state['values']['language'] : (isset($_REQUEST['language'])) ? $_REQUEST['language'] : '',
  ];
  $status_options = [
    'any' => 'any',
    'live' => 'Live',
    'review' => 'Review',
    'archive' => 'Archive',
  ];
  $form['status'] = [
    '#type' => 'select',
    '#title' => t('Status'),
    '#options' => $status_options,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['status']) ? $form_state['values']['status'] : (isset($_REQUEST['status'])) ? $_REQUEST['status'] : '',
  ];
  $owner_options = ['any' => 'any'] + digital_asset_get_document_owners();
  $form['owner'] = [
    '#type' => 'select',
    '#title' => t('Owner'),
    '#options' => $owner_options,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['owner']) ? $form_state['values']['owner'] : (isset($_REQUEST['owner'])) ? $_REQUEST['owner'] : '',
  ];
  $form['submit'] = [
    '#type' => 'submit',
    '#value' => 'Search',
  ];
  if (empty($form_state['digital_asset']['table'])) {
    $parameters = $_REQUEST;
    unset($parameters['page']);
    $table = digital_asset_asset_query($parameters);
  }
  else {
    $table = $form_state['digital_asset']['table'];
  }
  $form['table'] = [
    '#markup' => $table,
  ];
  return $form;
}

/**
 * @param $form
 * @param $form_state
 */
function digital_asset_asset_query_form_submit($form, &$form_state) {
  $parameters = [
    'language' => $form_state['values']['language'],
    'owner' => $form_state['values']['owner'],
    'status' => $form_state['values']['status'],
    'document_id' => $form_state['values']['document_id'],
    'asset_type' => $form_state['values']['asset_type'],
    'tags' => $form_state['values']['tags'],
    'title' => $form_state['values']['title'],
  ];
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
  $query->fields('n', ['nid', 'uid', 'created', 'changed']);
  $query->addJoin('INNER', 'node_revision', 'r', 'n.vid = r.vid');
  $query->fields('r', ['title']);
  $query->addJoin('INNER', 'field_data_field_dam_document_id', 'doc_id', 'r.vid = doc_id.revision_id');
  $query->fields('doc_id', ['field_dam_document_id_value']);
  $query->addJoin('INNER', 'field_data_field_dam_language', 'lang', 'r.vid = lang.revision_id');
  $query->fields('lang', ['field_dam_language_value']);
  $query->addJoin('INNER', 'field_data_field_asset_type', 'type', 'r.vid = type.revision_id');
  $query->fields('type', ['field_asset_type_value']);
  $query->addJoin('INNER', 'field_data_field_dam_document_status', 'status', 'r.vid = status.revision_id');
  $query->fields('status', ['field_dam_document_status_value']);
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
    $query->condition('field_asset_type_value', $asset_type);
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
  $header = [
    [
      'data' => 'Document ID',
      'field' => 'field_dam_document_id_value',
    ],
    [
      'data' => 'Language',
      'field' => 'field_dam_language_value',
    ],
    [
      'data' => 'Title',
      'field' => 'r.title',
      'sort' => 'asc',
    ],
    [
      'data' => 'Type',
      'field' => 'field_asset_type_value',
    ],
    [
      'data' => 'Status',
      'field' => 'field_dam_document_status_value',
    ],
    [
      'data' => 'Owner',
    ],
    [
      'data' => 'Created',
      'field' => 'created'
    ],
    [
      'data' => 'Updated',
      'field' => 'changed'
    ]
  ];
  $owners = [0 => 'none'] + digital_asset_get_document_owners();
  $result = $query->extend('PagerDefault')
    ->limit(50)
    ->extend('TableSort')
    ->orderByHeader($header)
    ->execute();
  $data = [];
  foreach ($result as $row) {
    $data[] = [
      l($row->field_dam_document_id_value, 'digital_asset/' . $row->nid),
      fnet_helper_iso_language_to_english($row->field_dam_language_value),
      $row->title,
      ucwords($row->field_asset_type_value),
      ucwords($row->field_dam_document_status_value),
      $owners[$row->uid],
      date('m/d/Y', $row->created),
      date('m/d/Y', $row->changed),
    ];
  }
  $output = '<div id="digital-asset-query-result">';
  try {
    $output .= theme('table', ['header' => $header, 'rows' => $data]);
  } catch (Exception $e) {
    watchdog('Digital Asset', $e->getMessage());
  }
  try {
    $output .= theme('pager', [
      'tags' => NULL,
      'element' => 0,
      'parameters' => $parameters
    ]);
  } catch (Exception $e) {
    watchdog('Digital Asset', $e->getMessage());
  }
  $output .= '</div>';
  $output .= '<div>' . l('Add an asset', 'digital_asset/add') . '</div>';
  return $output;
}

/**
 * @param $form
 * @param $form_state
 * @return array
 */
function digital_asset_query_by_product_form($form, &$form_state) {
  $form = [];
  $query = db_select('node', 'n')
    ->fields('n', ['nid', 'title'])
    ->distinct()
    ->orderBy('title');
  $query->addJoin('INNER', 'field_data_field_pcatid', 'p', 'n.nid = p.entity_id');
  $query->fields('p', ['field_pcatid_value']);
  $query->addJoin('INNER', 'field_data_field_related_products', 'rp', 'n.nid = rp.field_related_products_target_id');
  $query->isNotNull('field_pcatid_value');
  $result = $query->execute();
  $product_options = [];
  if ($result) {
    foreach ($result as $row) {
      $product_options[$row->nid] = $row->title;
    }
  }

  $form['product'] = [
    '#type' => 'select',
    '#title' => 'Product',
    '#options' => $product_options,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['product']) ? $form_state['values']['product'] : (isset($_REQUEST['product'])) ? $_REQUEST['product'] : '',
  ];
  $form['language'] = [
    '#type' => 'select',
    '#title' => t('Language'),
    '#options' => ['any' => 'any'] + digital_asset_languages(),
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['language']) ? $form_state['values']['language'] : (isset($_REQUEST['language'])) ? $_REQUEST['language'] : '',
  ];
  $type_options = ['any' => 'any'] + digital_asset_asset_types();
  $form['asset_type'] = [
    '#type' => 'select',
    '#title' => t('Asset type'),
    '#options' => $type_options,
    '#required' => FALSE,
    '#default_value' => isset($form_state['values']['asset_type']) ? $form_state['values']['asset_type'] : (isset($_REQUEST['asset_type'])) ? $_REQUEST['asset_type'] : '',
  ];
  $form['submit'] = [
    '#type' => 'submit',
    '#value' => 'Search',
  ];
  if (empty($form_state['digital_asset']['table'])) {
    $parameters = $_REQUEST;
    unset($parameters['page']);
    if (empty($parameters['product'])) {
      $option_keys = array_keys($product_options);
      $parameters['product'] = array_shift($option_keys);
    }
    try {
      $table = digital_asset_query_by_product($parameters);
    } catch (Exception $e) {
      watchdog('Digital Asset', $e->getMessage());
    }
  }
  else {
    $table = $form_state['digital_asset']['table'];
  }
  $form['table'] = [
    '#markup' => $table,
  ];
  return $form;
}

/**
 * @param $form
 * @param $form_state
 */
function digital_asset_query_by_product_form_submit($form, &$form_state) {
  $parameters = [
    'product' => $form_state['values']['product'],
    'language' => $form_state['values']['language'],
    'asset_type' => $form_state['values']['asset_type'],
  ];
  foreach ($parameters as $key => $value) {
    unset($_GET[$key]);
  }
  unset($_GET['page']);
  global $pager_page_array, $pager_total, $pager_total_items, $pager_limits;
  unset($pager_page_array);
  unset($pager_total);
  unset($pager_total_items);
  unset($pager_limits);
  try {
    $form_state['digital_asset']['table'] = digital_asset_query_by_product($parameters);
  } catch (Exception $e) {
    watchdog('Digital Asset', $e->getMessage());
  }
  $form_state['rebuild'] = TRUE;
}

/**
 * Returns a table of documents based on Product
 *
 * TODO: This should really just be a view. Replace.
 *
 * @param $parameters
 * @return string
 * @throws \Exception
 */
function digital_asset_query_by_product($parameters) {
  $product = (isset($parameters['product'])) ? $parameters['product'] : '';
  $language = (isset($parameters['language'])) ? $parameters['language'] : '';
  $asset_type = (isset($parameters['asset_type'])) ? $parameters['asset_type'] : '';
  $query = db_select('node', 'n')->fields('n', ['nid', 'title']);
  $query->addJoin('INNER', 'field_data_field_dam_document_id', 'doc_id', 'n.nid = doc_id.entity_id');
  $query->fields('doc_id', ['field_dam_document_id_value']);
  $query->addJoin('LEFT', 'field_data_field_dam_revision_letter', 'rev', 'n.nid = rev.entity_id');
  $query->fields('rev', ['field_dam_revision_letter_value']);
  $query->addJoin('LEFT', 'field_data_field_dam_language', 'lang', 'n.nid = lang.entity_id');
  $query->fields('lang', ['field_dam_language_value']);
  $query->addJoin('LEFT', 'field_data_field_asset_type', 'type', 'n.nid = type.entity_id');
  $query->fields('type', ['field_asset_type_value']);
  $query->addJoin('LEFT', 'field_data_field_dam_document_status', 'status', 'n.nid = status.entity_id');
  $query->fields('status', ['field_dam_document_status_value']);
  $query->addJoin('INNER', 'field_data_field_related_products', 'rp', 'n.nid = rp.entity_id');
  $query->condition('field_related_products_target_id', $product);
  if (!empty($language) && ($language != 'any')) {
    $query->condition('field_dam_language_value', $language);
  }
  if (!empty($asset_type) && ($asset_type != 'any')) {
    $query->condition('field_asset_type_value', $asset_type);
  }

  $header = [
    [
      'data' => 'Document ID',
      'field' => 'field_dam_document_id_value',
    ],
    [
      'data' => 'Language',
      'field' => 'field_dam_language_value',
    ],
    [
      'data' => 'Title',
      'field' => 'title',
      'sort' => 'asc',
    ],
    [
      'data' => 'Type',
      'field' => 'field_asset_type_value',
    ],
    [
      'data' => 'Status',
      'field' => 'field_dam_document_status_value',
    ],
  ];
  $result = $query->extend('PagerDefault')
    ->limit(50)
    ->extend('TableSort')
    ->orderByHeader($header)
    ->execute();
  $data = [];
  // Get the array of possible asset types. We need this to display the proper label.
  $asset_type_values = field_info_field('field_asset_type');
  $asset_types = list_allowed_values($asset_type_values);
  foreach ($result as $row) {
    $data[] = [
      l($row->field_dam_document_id_value, 'digital_asset/' . $row->nid),
      fnet_helper_iso_language_to_english($row->field_dam_language_value),
      $row->title,
      $asset_types[$row->field_asset_type_value],
      $row->field_dam_document_status_value,
    ];
  }
  $parameters = [
    'asset_type' => $asset_type,
    'language' => $language,
    'product' => $product,
  ];
  $output = '<div id="digital-asset-query-result">';
  $output .= theme('table', ['header' => $header, 'rows' => $data]);
  $output .= theme('pager', [
    'tags' => NULL,
    'element' => 0,
    'parameters' => $parameters
  ]);
  $output .= '</div>';
  return $output;
}
