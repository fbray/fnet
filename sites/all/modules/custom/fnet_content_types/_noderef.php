<?php

  // Exported field_instance: 'node-event-field_workshop_industry'
  $field_instances['node-event-field_workshop_industry'] = array(
    'bundle' => 'event',
    'default_value' => array(
      0 => array(
        'nid' => NULL,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 23,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 11,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_workshop_industry',
    'label' => 'Industry',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 11,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'options_buttons',
      'weight' => 11,
    ),
    'widget_type' => 'nodereference_buttons',
  );


  // Exported field_instance: 'node-event-field_workshop_product'
  $field_instances['node-event-field_workshop_product'] = array(
    'bundle' => 'event',
    'default_value' => array(
      0 => array(
        'nid' => NULL,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 12,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_workshop_product',
    'label' => 'Product',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 12,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'default_value_php' => NULL,
        'size' => 100,
      ),
      'type' => 'options_buttons',
      'weight' => 12,
    ),
    'widget_type' => 'nodereference_buttons',
  );


  // Exported field_instance: 'node-exp_tpc_lng-field_exp_tpc_lng_exp_tpc'
  $field_instances['node-exp_tpc_lng-field_exp_tpc_lng_exp_tpc'] = array(
    'bundle' => 'exp_tpc_lng',
    'default_value' => array(
      0 => array(
        'nid' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_nid',
        'weight' => 5,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -3,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -3,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -3,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_tpc_lng_exp_tpc',
    'label' => 'Expertise Topic',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => -3,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'options_buttons',
      'weight' => -3,
    ),
    'widget_type' => 'nodereference_buttons',
  );



  // Exported field_instance: 'node-expertise-field_expertise_industry'
  $field_instances['node-expertise-field_expertise_industry'] = array(
    'bundle' => 'expertise',
    'default_value' => array(
      0 => array(
        'nid' => NULL,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 6,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_expertise_industry',
    'label' => 'Industry',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 2,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'options_buttons',
      'weight' => 2,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-expertise-field_expertise_product'
  $field_instances['node-expertise-field_expertise_product'] = array(
    'bundle' => 'expertise',
    'default_value' => array(
      0 => array(
        'nid' => NULL,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -2,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_expertise_product',
    'label' => 'Product',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 3,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'options_buttons',
      'weight' => 3,
    ),
    'widget_type' => 'nodereference_buttons',
  );


  // Exported field_instance: 'node-family-field_family_industry'
  $field_instances['node-family-field_family_industry'] = array(
    'bundle' => 'family',
    'default_value' => array(
      0 => array(
        'nid' => NULL,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 17,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 6,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_family_industry',
    'label' => 'Industry',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 6,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'options_buttons',
      'weight' => 6,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-feature-field_feature_product'
  $field_instances['node-feature-field_feature_product'] = array(
    'bundle' => 'feature',
    'default_value' => array(
      0 => array(
        'nid' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -1,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -2,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_feature_product',
    'label' => 'Product',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => -2,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'options_buttons',
      'weight' => -2,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance:
  // 'node-homepage2013language-field_home13lng_homepage'
  $field_instances['node-homepage2013language-field_home13lng_homepage'] = array(
    'bundle' => 'homepage2013language',
    'default_value' => array(
      0 => array(
        'nid' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -3,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -3,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -3,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -3,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_home13lng_homepage',
    'label' => 'Homepage',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => -3,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'options_buttons',
      'weight' => -3,
    ),
    'widget_type' => 'nodereference_buttons',
  );




  // Exported field_instance: 'node-industrylanguage-field_indlang_industry'
  $field_instances['node-industrylanguage-field_indlang_industry'] = array(
    'bundle' => 'industrylanguage',
    'default_value' => array(
      0 => array(
        'nid' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 11,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 35,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 35,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 35,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_indlang_industry',
    'label' => 'Industry',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 35,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'options_buttons',
      'weight' => 35,
    ),
    'widget_type' => 'nodereference_buttons',
  );


  // Exported field_instance: 'node-product_distributor_group-field_products'
  $field_instances['node-product_distributor_group-field_products'] = array(
    'bundle' => 'product_distributor_group',
    'default_value' => array(
      0 => array(
        'nid' => '',
      ),
    ),
    'deleted' => 0,
    'description' => 'Select products that belong to this group',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 18,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -2,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -2,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -2,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_products',
    'label' => 'Products',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => -2,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'options_select',
      'weight' => -2,
    ),
    'widget_type' => 'multiselect_select',
  );

  // Exported field_instance: 'node-product-field_prod_relatedprod'
  $field_instances['node-product-field_prod_relatedprod'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'nid' => '',
      ),
    ),
    'deleted' => 0,
    'description' => 'Choose 4 related products',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 6,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 18,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_plain',
        'weight' => 4,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_relatedprod',
    'label' => 'Releated Products',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 18,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'options_buttons',
      'weight' => 18,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-product-field_product_family'
  $field_instances['node-product-field_product_family'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'nid' => NULL,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 12,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_plain',
        'weight' => 3,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_product_family',
    'label' => 'Family',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 12,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'options_buttons',
      'weight' => 12,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-productlanguage-field_prodlang_product'
  $field_instances['node-productlanguage-field_prodlang_product'] = array(
    'bundle' => 'productlanguage',
    'default_value' => array(
      0 => array(
        'nid' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -1,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -1,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -1,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prodlang_product',
    'label' => 'Product',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => -1,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'options_buttons',
      'weight' => -1,
    ),
    'widget_type' => 'nodereference_buttons',
  );



  // Exported field_instance: 'node-productsubtype-field_productsub_product'
  $field_instances['node-productsubtype-field_productsub_product'] = array(
    'bundle' => 'productsubtype',
    'default_value' => array(
      0 => array(
        'nid' => '',
      ),
    ),
    'deleted' => 0,
    'description' => 'Select related product',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 12,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_productsub_product',
    'label' => 'Product',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => -1,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'default_value_php' => NULL,
        'size' => 100,
      ),
      'type' => 'options_buttons',
      'weight' => -1,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-suite-field_suite_family'
  $field_instances['node-suite-field_suite_family'] = array(
    'bundle' => 'suite',
    'default_value' => array(
      0 => array(
        'nid' => NULL,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 9,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_suite_family',
    'label' => 'Family',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 9,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'options_buttons',
      'weight' => 9,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  // Exported field_instance: 'node-page_reg_lang-field_page_reg_lang_pagereg'
  $field_instances['node-page_reg_lang-field_page_reg_lang_pagereg'] = array(
    'bundle' => 'page_reg_lang',
    'default_value' => array(
      0 => array(
        'nid' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -3,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -3,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -3,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_page_reg_lang_pagereg',
    'label' => 'Page Region',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => -3,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'options_buttons',
      'weight' => -3,
    ),
    'widget_type' => 'nodereference_buttons',
  );


