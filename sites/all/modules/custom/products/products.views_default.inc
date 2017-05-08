<?php
/**
 * @file
 * products.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function products_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'product_listing_page';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Product Listing Page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Products';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_product_family',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Family (field_product_family) */
  $handler->display->display_options['relationships']['field_product_family_nid']['id'] = 'field_product_family_nid';
  $handler->display->display_options['relationships']['field_product_family_nid']['table'] = 'field_data_field_product_family';
  $handler->display->display_options['relationships']['field_product_family_nid']['field'] = 'field_product_family_nid';
  $handler->display->display_options['relationships']['field_product_family_nid']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_product_family_nid']['delta'] = '-1';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print str_ireplace(\' \', \'_\', $data->field_field_product_family[0][\'rendered\'][\'#markup\']); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Family */
  $handler->display->display_options['fields']['field_product_family']['id'] = 'field_product_family';
  $handler->display->display_options['fields']['field_product_family']['table'] = 'field_data_field_product_family';
  $handler->display->display_options['fields']['field_product_family']['field'] = 'field_product_family';
  $handler->display->display_options['fields']['field_product_family']['label'] = '';
  $handler->display->display_options['fields']['field_product_family']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_product_family']['alter']['path'] = '/enterprise-network?td=products#[php]';
  $handler->display->display_options['fields']['field_product_family']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_family']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_product_family']['delta_offset'] = '0';
  /* Field: Family Node ID */
  $handler->display->display_options['fields']['field_product_family_1']['id'] = 'field_product_family_1';
  $handler->display->display_options['fields']['field_product_family_1']['table'] = 'field_data_field_product_family';
  $handler->display->display_options['fields']['field_product_family_1']['field'] = 'field_product_family';
  $handler->display->display_options['fields']['field_product_family_1']['ui_name'] = 'Family Node ID';
  $handler->display->display_options['fields']['field_product_family_1']['label'] = '';
  $handler->display->display_options['fields']['field_product_family_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_product_family_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_family_1']['type'] = 'node_reference_nid';
  $handler->display->display_options['fields']['field_product_family_1']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Weight: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'weight_weights';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_product_family_nid';
  /* Contextual filter: Content: Industry (field_family_industry) */
  $handler->display->display_options['arguments']['field_family_industry_nid']['id'] = 'field_family_industry_nid';
  $handler->display->display_options['arguments']['field_family_industry_nid']['table'] = 'field_data_field_family_industry';
  $handler->display->display_options['arguments']['field_family_industry_nid']['field'] = 'field_family_industry_nid';
  $handler->display->display_options['arguments']['field_family_industry_nid']['relationship'] = 'field_product_family_nid';
  $handler->display->display_options['arguments']['field_family_industry_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_family_industry_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_family_industry_nid']['default_argument_options']['argument'] = '6';
  $handler->display->display_options['arguments']['field_family_industry_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_family_industry_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_family_industry_nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Node: translations Language-Region */
  $handler->display->display_options['arguments']['langreg']['id'] = 'langreg';
  $handler->display->display_options['arguments']['langreg']['table'] = 'language_region';
  $handler->display->display_options['arguments']['langreg']['field'] = 'langreg';
  $handler->display->display_options['arguments']['langreg']['default_action'] = 'default';
  $handler->display->display_options['arguments']['langreg']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['langreg']['default_argument_options']['code'] = '$siteReg = module_invoke(\'fnet_helper\', \'site_region\'); // Return the user\'s site region/language info.
$regLang = $siteReg["regLang"]; // Store the value.
return $regLang;';
  $handler->display->display_options['arguments']['langreg']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['langreg']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['langreg']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['langreg']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product' => 'product',
  );

  /* Display: Product Listing (Datacom Cabling) */
  $handler = $view->new_display('block', 'Product Listing (Datacom Cabling)', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<a href=\'/datacom-cabling\'>Datacom Cabling</a>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print str_ireplace(\' \', \'_\', $data->field_field_product_family[0][\'rendered\'][\'#markup\']); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Family */
  $handler->display->display_options['fields']['field_product_family']['id'] = 'field_product_family';
  $handler->display->display_options['fields']['field_product_family']['table'] = 'field_data_field_product_family';
  $handler->display->display_options['fields']['field_product_family']['field'] = 'field_product_family';
  $handler->display->display_options['fields']['field_product_family']['label'] = '';
  $handler->display->display_options['fields']['field_product_family']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_product_family']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_product_family']['alter']['path'] = '/datacom-cabling?td=products#[php]';
  $handler->display->display_options['fields']['field_product_family']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_family']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_product_family']['delta_offset'] = '0';
  /* Field: Family Node ID */
  $handler->display->display_options['fields']['field_product_family_1']['id'] = 'field_product_family_1';
  $handler->display->display_options['fields']['field_product_family_1']['table'] = 'field_data_field_product_family';
  $handler->display->display_options['fields']['field_product_family_1']['field'] = 'field_product_family';
  $handler->display->display_options['fields']['field_product_family_1']['ui_name'] = 'Family Node ID';
  $handler->display->display_options['fields']['field_product_family_1']['label'] = '';
  $handler->display->display_options['fields']['field_product_family_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_product_family_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_family_1']['type'] = 'node_reference_nid';
  $handler->display->display_options['fields']['field_product_family_1']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Industry (field_family_industry) */
  $handler->display->display_options['arguments']['field_family_industry_nid']['id'] = 'field_family_industry_nid';
  $handler->display->display_options['arguments']['field_family_industry_nid']['table'] = 'field_data_field_family_industry';
  $handler->display->display_options['arguments']['field_family_industry_nid']['field'] = 'field_family_industry_nid';
  $handler->display->display_options['arguments']['field_family_industry_nid']['relationship'] = 'field_product_family_nid';
  $handler->display->display_options['arguments']['field_family_industry_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_family_industry_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_family_industry_nid']['default_argument_options']['argument'] = '6';
  $handler->display->display_options['arguments']['field_family_industry_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_family_industry_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_family_industry_nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Node: translations Language-Region */
  $handler->display->display_options['arguments']['langreg']['id'] = 'langreg';
  $handler->display->display_options['arguments']['langreg']['table'] = 'language_region';
  $handler->display->display_options['arguments']['langreg']['field'] = 'langreg';
  $handler->display->display_options['arguments']['langreg']['default_action'] = 'default';
  $handler->display->display_options['arguments']['langreg']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['langreg']['default_argument_options']['code'] = '$siteReg = module_invoke(\'fnet_helper\', \'site_region\'); // Return the user\'s site region/language info.
$regLang = $siteReg["regLang"]; // Store the value.
return $regLang;';
  $handler->display->display_options['arguments']['langreg']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['langreg']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['langreg']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['langreg']['limit'] = '0';

  /* Display: Product Listing (IT Networking) */
  $handler = $view->new_display('block', 'Product Listing (IT Networking)', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<a href=\'/enterprise-network\'>IT Networking</a>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print str_ireplace(\' \', \'_\', $data->field_field_product_family[0][\'rendered\'][\'#markup\']); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Family */
  $handler->display->display_options['fields']['field_product_family']['id'] = 'field_product_family';
  $handler->display->display_options['fields']['field_product_family']['table'] = 'field_data_field_product_family';
  $handler->display->display_options['fields']['field_product_family']['field'] = 'field_product_family';
  $handler->display->display_options['fields']['field_product_family']['label'] = '';
  $handler->display->display_options['fields']['field_product_family']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_product_family']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_product_family']['alter']['path'] = '/enterprise-network?td=products#[php]';
  $handler->display->display_options['fields']['field_product_family']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_family']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_product_family']['delta_offset'] = '0';
  /* Field: Family Node ID */
  $handler->display->display_options['fields']['field_product_family_1']['id'] = 'field_product_family_1';
  $handler->display->display_options['fields']['field_product_family_1']['table'] = 'field_data_field_product_family';
  $handler->display->display_options['fields']['field_product_family_1']['field'] = 'field_product_family';
  $handler->display->display_options['fields']['field_product_family_1']['ui_name'] = 'Family Node ID';
  $handler->display->display_options['fields']['field_product_family_1']['label'] = '';
  $handler->display->display_options['fields']['field_product_family_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_product_family_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_family_1']['type'] = 'node_reference_nid';
  $handler->display->display_options['fields']['field_product_family_1']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Industry (field_family_industry) */
  $handler->display->display_options['arguments']['field_family_industry_nid']['id'] = 'field_family_industry_nid';
  $handler->display->display_options['arguments']['field_family_industry_nid']['table'] = 'field_data_field_family_industry';
  $handler->display->display_options['arguments']['field_family_industry_nid']['field'] = 'field_family_industry_nid';
  $handler->display->display_options['arguments']['field_family_industry_nid']['relationship'] = 'field_product_family_nid';
  $handler->display->display_options['arguments']['field_family_industry_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_family_industry_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_family_industry_nid']['default_argument_options']['argument'] = '7';
  $handler->display->display_options['arguments']['field_family_industry_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_family_industry_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_family_industry_nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Node: translations Language-Region */
  $handler->display->display_options['arguments']['langreg']['id'] = 'langreg';
  $handler->display->display_options['arguments']['langreg']['table'] = 'language_region';
  $handler->display->display_options['arguments']['langreg']['field'] = 'langreg';
  $handler->display->display_options['arguments']['langreg']['default_action'] = 'default';
  $handler->display->display_options['arguments']['langreg']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['langreg']['default_argument_options']['code'] = '$siteReg = module_invoke(\'fnet_helper\', \'site_region\'); // Return the user\'s site region/language info.
$regLang = $siteReg["regLang"]; // Store the value.
return $regLang;';
  $handler->display->display_options['arguments']['langreg']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['langreg']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['langreg']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['langreg']['limit'] = '0';

  /* Display: Product Listing (Telecom) */
  $handler = $view->new_display('block', 'Product Listing (Telecom)', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<a href=\'/telecom\'>Telecom</a>';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print str_ireplace(\' \', \'_\', $data->field_field_product_family[0][\'rendered\'][\'#markup\']); ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Family */
  $handler->display->display_options['fields']['field_product_family']['id'] = 'field_product_family';
  $handler->display->display_options['fields']['field_product_family']['table'] = 'field_data_field_product_family';
  $handler->display->display_options['fields']['field_product_family']['field'] = 'field_product_family';
  $handler->display->display_options['fields']['field_product_family']['label'] = '';
  $handler->display->display_options['fields']['field_product_family']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_product_family']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_product_family']['alter']['path'] = '/telecom?td=products#[php]';
  $handler->display->display_options['fields']['field_product_family']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_family']['type'] = 'node_reference_plain';
  $handler->display->display_options['fields']['field_product_family']['delta_offset'] = '0';
  /* Field: Family Node ID */
  $handler->display->display_options['fields']['field_product_family_1']['id'] = 'field_product_family_1';
  $handler->display->display_options['fields']['field_product_family_1']['table'] = 'field_data_field_product_family';
  $handler->display->display_options['fields']['field_product_family_1']['field'] = 'field_product_family';
  $handler->display->display_options['fields']['field_product_family_1']['ui_name'] = 'Family Node ID';
  $handler->display->display_options['fields']['field_product_family_1']['label'] = '';
  $handler->display->display_options['fields']['field_product_family_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_product_family_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_product_family_1']['type'] = 'node_reference_nid';
  $handler->display->display_options['fields']['field_product_family_1']['delta_offset'] = '0';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Industry (field_family_industry) */
  $handler->display->display_options['arguments']['field_family_industry_nid']['id'] = 'field_family_industry_nid';
  $handler->display->display_options['arguments']['field_family_industry_nid']['table'] = 'field_data_field_family_industry';
  $handler->display->display_options['arguments']['field_family_industry_nid']['field'] = 'field_family_industry_nid';
  $handler->display->display_options['arguments']['field_family_industry_nid']['relationship'] = 'field_product_family_nid';
  $handler->display->display_options['arguments']['field_family_industry_nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_family_industry_nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_family_industry_nid']['default_argument_options']['argument'] = '8';
  $handler->display->display_options['arguments']['field_family_industry_nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_family_industry_nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_family_industry_nid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Node: translations Language-Region */
  $handler->display->display_options['arguments']['langreg']['id'] = 'langreg';
  $handler->display->display_options['arguments']['langreg']['table'] = 'language_region';
  $handler->display->display_options['arguments']['langreg']['field'] = 'langreg';
  $handler->display->display_options['arguments']['langreg']['default_action'] = 'default';
  $handler->display->display_options['arguments']['langreg']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['langreg']['default_argument_options']['code'] = '$siteReg = module_invoke(\'fnet_helper\', \'site_region\'); // Return the user\'s site region/language info.
$regLang = $siteReg["regLang"]; // Store the value.
return $regLang;';
  $handler->display->display_options['arguments']['langreg']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['langreg']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['langreg']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['langreg']['limit'] = '0';
  $export['product_listing_page'] = $view;

  return $export;
}
