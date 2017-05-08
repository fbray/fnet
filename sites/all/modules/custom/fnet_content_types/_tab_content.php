<?php


// textarea fields
// usually part of a group
// frequently sub-element display (hero banner/ tabs / ) with its own html/style
// can be on all, probably exclude teaser
// render as text to search



  // Exported field_instance: 'node-exp_ind-field_exp_ind_tab_content'
  $field_instances['node-exp_ind-field_exp_ind_tab_content'] = array(
    'bundle' => 'exp_ind',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_ind_tab_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Tab content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 10,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_ind_tab_content',
    'label' => 'Tab content',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 10,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 10,
    ),
    'widget_type' => 'text_textarea',
  );


  // Exported field_instance: 'node-exp_ind_lng-field_exp_ind_lng_tab2_content'
  $field_instances['node-exp_ind_lng-field_exp_ind_lng_tab2_content'] = array(
    'bundle' => 'exp_ind_lng',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_ind_lng_tab2_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Tab content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 11,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 11,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_ind_lng_tab2_content',
    'label' => 'Tab content',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 11,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 11,
    ),
    'widget_type' => 'text_textarea',
  );



  // Exported field_instance: 'node-exp_ind_lng-field_exp_ind_lng_tab_content'
  $field_instances['node-exp_ind_lng-field_exp_ind_lng_tab_content'] = array(
    'bundle' => 'exp_ind_lng',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_ind_lng_tab_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Tab content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 37,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 37,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 37,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 37,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_ind_lng_tab_content',
    'label' => 'Tab content',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 37,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 37,
    ),
    'widget_type' => 'text_textarea',
  );


  // Exported field_instance: 'node-exp_ind-field_exp_ind_tab2_content'
  $field_instances['node-exp_ind-field_exp_ind_tab2_content'] = array(
    'bundle' => 'exp_ind',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_ind_tab2_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Tab content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 13,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 13,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_ind_tab2_content',
    'label' => 'Tab content',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 13,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 13,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-exp_ind-field_exp_ind_tab3_content'
  $field_instances['node-exp_ind-field_exp_ind_tab3_content'] = array(
    'bundle' => 'exp_ind',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_ind_tab3_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Tab content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 14,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 14,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_ind_tab3_content',
    'label' => 'Tab content',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 14,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 14,
    ),
    'widget_type' => 'text_textarea',
  );


  // Exported field_instance: 'node-exp_rle-field_exp_rle_tab_content'
  $field_instances['node-exp_rle-field_exp_rle_tab_content'] = array(
    'bundle' => 'exp_rle',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_rle_tab_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Tab content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 10,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_rle_tab_content',
    'label' => 'Tab content',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 10,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 10,
    ),
    'widget_type' => 'text_textarea',
  );


  // Exported field_instance: 'node-exp_rle_lng-field_exp_rle_lng_tab_content'
  $field_instances['node-exp_rle_lng-field_exp_rle_lng_tab_content'] = array(
    'bundle' => 'exp_rle_lng',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_rle_lng_tab_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Tab content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 37,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 37,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 37,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 37,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_rle_lng_tab_content',
    'label' => 'Tab content',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 37,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 37,
    ),
    'widget_type' => 'text_textarea',
  );


  // Exported field_instance: 'node-exp_tpc-field_exp_tpc_banner_content'
  $field_instances['node-exp_tpc-field_exp_tpc_banner_content'] = array(
    'bundle' => 'exp_tpc',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_tpc_banner_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'If content is present in this field, it will override any banner image that has been set. Leave this blank if you want to use an image and not markup.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 32,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 1,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_tpc_banner_content',
    'label' => 'Banner content',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 1,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
    'widget_type' => 'text_textarea',
  );


  // Exported field_instance: 'node-exp_tpc-field_exp_tpc_tab_content'
  $field_instances['node-exp_tpc-field_exp_tpc_tab_content'] = array(
    'bundle' => 'exp_tpc',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_tpc_tab_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Tab content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 10,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_tpc_tab_content',
    'label' => 'Tab content',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 10,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 10,
    ),
    'widget_type' => 'text_textarea',
  );



  // Exported field_instance:
  // 'node-exp_tpc_lng-field_exp_tpc_lng_banner_content'
  $field_instances['node-exp_tpc_lng-field_exp_tpc_lng_banner_content'] = array(
    'bundle' => 'exp_tpc_lng',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_tpc_lng_banner_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'If content is present in this field, it will override any banner image that has been set. Leave this blank if you want to use an image and not markup.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 32,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 32,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 32,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 32,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_tpc_lng_banner_content',
    'label' => 'Banner content',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 32,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 32,
    ),
    'widget_type' => 'text_textarea',
  );


  // Exported field_instance: 'node-exp_tpc_lng-field_exp_tpc_lng_tab_content'
  $field_instances['node-exp_tpc_lng-field_exp_tpc_lng_tab_content'] = array(
    'bundle' => 'exp_tpc_lng',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_tpc_lng_tab_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Tab content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 37,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 37,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 37,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 37,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_tpc_lng_tab_content',
    'label' => 'Tab content',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 37,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 37,
    ),
    'widget_type' => 'text_textarea',
  );


  // Exported field_instance: 'node-suite-field_suite_tab_content_1'
  $field_instances['node-suite-field_suite_tab_content_1'] = array(
    'bundle' => 'suite',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_suite_tab_content_1][0][value',
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
        'weight' => 12,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 9,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 9,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_suite_tab_content_1',
    'label' => 'Tab Content #1',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 9,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 9,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-suite-field_suite_tab_content_2'
  $field_instances['node-suite-field_suite_tab_content_2'] = array(
    'bundle' => 'suite',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_suite_tab_content_2][0][value',
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
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 12,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 12,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_suite_tab_content_2',
    'label' => 'Tab Content #2',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 12,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 12,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-suite-field_suite_tab_content_3'
  $field_instances['node-suite-field_suite_tab_content_3'] = array(
    'bundle' => 'suite',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_suite_tab_content_3][0][value',
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
        'weight' => 18,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 15,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 15,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_suite_tab_content_3',
    'label' => 'Tab Content #3',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 15,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 15,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-suite-field_suite_tab_content_4'
  $field_instances['node-suite-field_suite_tab_content_4'] = array(
    'bundle' => 'suite',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_suite_tab_content_4][0][value',
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
        'weight' => 21,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 18,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 18,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 18,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_suite_tab_content_4',
    'label' => 'Tab Content #4',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 18,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 18,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-suite-field_suite_tab_content_5'
  $field_instances['node-suite-field_suite_tab_content_5'] = array(
    'bundle' => 'suite',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_suite_tab_content_5][0][value',
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
        'weight' => 8,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 21,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 21,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 21,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 21,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_suite_tab_content_5',
    'label' => 'Tab Content #5',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 21,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 21,
    ),
    'widget_type' => 'text_textarea',
  );




  // Exported field_instance: 'node-exp_ind_lng-field_exp_ind_lng_tab3_content'
  $field_instances['node-exp_ind_lng-field_exp_ind_lng_tab3_content'] = array(
    'bundle' => 'exp_ind_lng',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_ind_lng_tab3_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Tab content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 37,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 12,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 12,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_ind_lng_tab3_content',
    'label' => 'Tab content',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 12,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 12,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-exp_rle-field_exp_rle_tab2_content'
  $field_instances['node-exp_rle-field_exp_rle_tab2_content'] = array(
    'bundle' => 'exp_rle',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_rle_tab2_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Tab content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 13,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 13,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_rle_tab2_content',
    'label' => 'Tab content',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 13,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 13,
    ),
    'widget_type' => 'text_textarea',
  );


  // Exported field_instance: 'node-exp_rle-field_exp_rle_tab3_content'
  $field_instances['node-exp_rle-field_exp_rle_tab3_content'] = array(
    'bundle' => 'exp_rle',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_rle_tab3_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Tab content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 35,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 14,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 14,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_rle_tab3_content',
    'label' => 'Tab content',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 14,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 14,
    ),
    'widget_type' => 'text_textarea',
  );






  // Exported field_instance: 'node-exp_rle-field_exp_rle_tab4_content'
  $field_instances['node-exp_rle-field_exp_rle_tab4_content'] = array(
    'bundle' => 'exp_rle',
    'default_value' => array(
      0 => array(
        'value' => '',
        'format' => 2,
        '_error_element' => 'default_value_widget][field_exp_rle_tab4_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Tab content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 35,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 35,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 35,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 35,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_rle_tab4_content',
    'label' => 'Tab content',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 35,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 35,
    ),
    'widget_type' => 'text_textarea',
  );



  // Exported field_instance: 'node-exp_rle_lng-field_exp_rle_lng_tab2_content'
  $field_instances['node-exp_rle_lng-field_exp_rle_lng_tab2_content'] = array(
    'bundle' => 'exp_rle_lng',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_rle_lng_tab2_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Tab content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 11,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 11,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_rle_lng_tab2_content',
    'label' => 'Tab content',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 11,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 11,
    ),
    'widget_type' => 'text_textarea',
  );


  // Exported field_instance: 'node-exp_rle_lng-field_exp_rle_lng_tab3_content'
  $field_instances['node-exp_rle_lng-field_exp_rle_lng_tab3_content'] = array(
    'bundle' => 'exp_rle_lng',
    'default_value' => array(
      0 => array(
        'value' => '',
        'format' => 2,
        '_error_element' => 'default_value_widget][field_exp_rle_lng_tab3_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Tab content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 12,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 12,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_rle_lng_tab3_content',
    'label' => 'Tab content',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 12,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 12,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-exp_rle_lng-field_exp_rle_lng_tab4_content'
  $field_instances['node-exp_rle_lng-field_exp_rle_lng_tab4_content'] = array(
    'bundle' => 'exp_rle_lng',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_rle_lng_tab4_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Tab content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 37,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 14,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 14,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_rle_lng_tab4_content',
    'label' => 'Tab content',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 14,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 14,
    ),
    'widget_type' => 'text_textarea',
  );


  // Exported field_instance: 'node-exp_tpc-field_exp_tpc_tab2_content'
  $field_instances['node-exp_tpc-field_exp_tpc_tab2_content'] = array(
    'bundle' => 'exp_tpc',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_tpc_tab2_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Tab content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 13,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 13,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_tpc_tab2_content',
    'label' => 'Tab content',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 13,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 13,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-exp_tpc-field_exp_tpc_tab3_content'
  $field_instances['node-exp_tpc-field_exp_tpc_tab3_content'] = array(
    'bundle' => 'exp_tpc',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_tpc_tab3_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Tab content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 14,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 14,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_tpc_tab3_content',
    'label' => 'Tab content',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 14,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 14,
    ),
    'widget_type' => 'text_textarea',
  );


  // Exported field_instance: 'node-exp_tpc_lng-field_exp_tpc_lng_tab2_content'
  $field_instances['node-exp_tpc_lng-field_exp_tpc_lng_tab2_content'] = array(
    'bundle' => 'exp_tpc_lng',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_tpc_lng_tab2_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Tab content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 11,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 11,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_tpc_lng_tab2_content',
    'label' => 'Tab content',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 11,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 11,
    ),
    'widget_type' => 'text_textarea',
  );



  // Exported field_instance: 'node-exp_tpc_lng-field_exp_tpc_lng_tab3_content'
  $field_instances['node-exp_tpc_lng-field_exp_tpc_lng_tab3_content'] = array(
    'bundle' => 'exp_tpc_lng',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_tpc_lng_tab3_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Tab content.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 37,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 12,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 12,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_tpc_lng_tab3_content',
    'label' => 'Tab content',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 12,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 12,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-product-field_prod_ctab_data_1'
  $field_instances['node-product-field_prod_ctab_data_1'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prod_ctab_data_1][0][value',
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
        'weight' => 46,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 44,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 44,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 44,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_ctab_data_1',
    'label' => 'CustomTab Data-1',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 44,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 44,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-product-field_prod_ctab_data_2'
  $field_instances['node-product-field_prod_ctab_data_2'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prod_ctab_data_2][0][value',
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
        'weight' => 48,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 46,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 54,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 46,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 46,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_ctab_data_2',
    'label' => 'CustomTab Data-2',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 46,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 46,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-product-field_prod_ctab_data_3'
  $field_instances['node-product-field_prod_ctab_data_3'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prod_ctab_data_3][0][value',
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
        'weight' => 50,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 48,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 56,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 48,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 48,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_ctab_data_3',
    'label' => 'CustomTab Data-3',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 48,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 48,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-product-field_prod_ctab_data_4'
  $field_instances['node-product-field_prod_ctab_data_4'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prod_ctab_data_4][0][value',
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
        'weight' => 52,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 50,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 58,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 50,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 50,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_ctab_data_4',
    'label' => 'CustomTab Data-4',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 50,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 50,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-product-field_prod_ctab_data_5'
  $field_instances['node-product-field_prod_ctab_data_5'] = array(
    'bundle' => 'product',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 43,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 52,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 60,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 52,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_ctab_data_5',
    'label' => 'CustomTab Data-5',
    'required' => 0,
    'settings' => array(
      'text_processing' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 52,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'rows' => NULL,
        'size' => NULL,
      ),
      'type' => 'text_textarea',
      'weight' => 52,
    ),
    'widget_type' => 'text_textarea',
  );


  // Exported field_instance: 'node-exp_ind-field_exp_ind_banner_content'
  $field_instances['node-exp_ind-field_exp_ind_banner_content'] = array(
    'bundle' => 'exp_ind',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_ind_banner_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'If content is present in this field, it will override any banner image that has been set. Leave this blank if you want to use an image and not markup.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 32,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 1,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_ind_banner_content',
    'label' => 'Banner content',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 1,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
    'widget_type' => 'text_textarea',
  );


  // Exported field_instance:
  // 'node-exp_ind_lng-field_exp_ind_lng_banner_content'
  $field_instances['node-exp_ind_lng-field_exp_ind_lng_banner_content'] = array(
    'bundle' => 'exp_ind_lng',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_ind_lng_banner_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'If content is present in this field, it will override any banner image that has been set. Leave this blank if you want to use an image and not markup.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 32,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 32,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 32,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 32,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_ind_lng_banner_content',
    'label' => 'Banner content',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 32,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 32,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-exp_rle-field_exp_rle_banner_content'
  $field_instances['node-exp_rle-field_exp_rle_banner_content'] = array(
    'bundle' => 'exp_rle',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_rle_banner_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'If content is present in this field, it will override any banner image that has been set. Leave this blank if you want to use an image and not markup.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 32,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 1,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_rle_banner_content',
    'label' => 'Banner content',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 1,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
    'widget_type' => 'text_textarea',
  );


  // Exported field_instance:
  // 'node-exp_rle_lng-field_exp_rle_lng_banner_content'
  $field_instances['node-exp_rle_lng-field_exp_rle_lng_banner_content'] = array(
    'bundle' => 'exp_rle_lng',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_exp_rle_lng_banner_content][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'If content is present in this field, it will override any banner image that has been set. Leave this blank if you want to use an image and not markup.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 32,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 32,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 32,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 32,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_exp_rle_lng_banner_content',
    'label' => 'Banner content',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 32,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 32,
    ),
    'widget_type' => 'text_textarea',
  );


  // Exported field_instance: 'node-expertise-field_expertise_relatedcontent'
  $field_instances['node-expertise-field_expertise_relatedcontent'] = array(
    'bundle' => 'expertise',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_expertise_relatedcontent][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 23,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 1,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_expertise_relatedcontent',
    'label' => 'Related Content',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 1,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 15,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
    'widget_type' => 'text_textarea',
  );



  // Exported field_instance: 'node-product-field_prod_sol_desc_1'
  $field_instances['node-product-field_prod_sol_desc_1'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prod_sol_desc_1][0][value',
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
        'weight' => 22,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 60,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 67,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 60,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 60,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_sol_desc_1',
    'label' => 'Solution Description #1',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 60,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 60,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-product-field_prod_sol_desc_2'
  $field_instances['node-product-field_prod_sol_desc_2'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prod_sol_desc_2][0][value',
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
        'weight' => 24,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 62,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 69,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 62,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 62,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_sol_desc_2',
    'label' => 'Solution Description #2',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 62,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 62,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-product-field_prod_sol_desc_3'
  $field_instances['node-product-field_prod_sol_desc_3'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prod_sol_desc_3][0][value',
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
        'weight' => 26,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 64,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 71,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 64,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 64,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_sol_desc_3',
    'label' => 'Solution Description #3',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 64,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 64,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-product-field_prod_sol_desc_4'
  $field_instances['node-product-field_prod_sol_desc_4'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prod_sol_desc_4][0][value',
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
        'weight' => 19,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 66,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 73,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 66,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 66,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_sol_desc_4',
    'label' => 'Solution Description #4',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 66,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 66,
    ),
    'widget_type' => 'text_textfield',
  );




  // Exported field_instance: 'node-productlanguage-field_prodlang_sol_desc_1'
  $field_instances['node-productlanguage-field_prodlang_sol_desc_1'] = array(
    'bundle' => 'productlanguage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prodlang_sol_desc_1][0][value',
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
        'weight' => 60,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 20,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 20,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prodlang_sol_desc_1',
    'label' => 'Solution Description #1 ',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 20,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 250,
      ),
      'type' => 'text_textfield',
      'weight' => 20,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-productlanguage-field_prodlang_sol_desc_2'
  $field_instances['node-productlanguage-field_prodlang_sol_desc_2'] = array(
    'bundle' => 'productlanguage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prodlang_sol_desc_2][0][value',
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
        'weight' => 62,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 22,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 22,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 22,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 22,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prodlang_sol_desc_2',
    'label' => 'Solution Description #2 ',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 22,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 250,
      ),
      'type' => 'text_textfield',
      'weight' => 22,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-productlanguage-field_prodlang_sol_desc_3'
  $field_instances['node-productlanguage-field_prodlang_sol_desc_3'] = array(
    'bundle' => 'productlanguage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prodlang_sol_desc_3][0][value',
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
        'weight' => 64,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 24,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 24,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 24,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 24,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prodlang_sol_desc_3',
    'label' => 'Solution Description #3 ',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 24,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 250,
      ),
      'type' => 'text_textfield',
      'weight' => 24,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-productlanguage-field_prodlang_sol_desc_4'
  $field_instances['node-productlanguage-field_prodlang_sol_desc_4'] = array(
    'bundle' => 'productlanguage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prodlang_sol_desc_4][0][value',
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
        'weight' => 66,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 26,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 26,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 26,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 26,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prodlang_sol_desc_4',
    'label' => 'Solution Description #4',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 26,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 250,
      ),
      'type' => 'text_textfield',
      'weight' => 26,
    ),
    'widget_type' => 'text_textfield',
  );





  // Exported field_instance: 'node-family-field_family_expert_boxdesc_1'
  $field_instances['node-family-field_family_expert_boxdesc_1'] = array(
    'bundle' => 'family',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_family_expert_boxdesc_1][0][value',
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
        'weight' => 70,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 71,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 71,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 71,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 71,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_family_expert_boxdesc_1',
    'label' => 'Expertise RHN Box1 Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 71,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 3,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 71,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-family-field_family_expert_boxdesc_2'
  $field_instances['node-family-field_family_expert_boxdesc_2'] = array(
    'bundle' => 'family',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_family_expert_boxdesc_2][0][value',
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
        'weight' => 74,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 75,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 75,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 75,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 75,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_family_expert_boxdesc_2',
    'label' => 'Expertise RHN Box2 Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 75,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 3,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 75,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-family-field_family_expert_boxdesc_3'
  $field_instances['node-family-field_family_expert_boxdesc_3'] = array(
    'bundle' => 'family',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_family_expert_boxdesc_3][0][value',
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
        'weight' => 78,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 79,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 79,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 79,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 79,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_family_expert_boxdesc_3',
    'label' => 'Expertise RHN Box3 Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 79,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 3,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 79,
    ),
    'widget_type' => 'text_textarea',
  );


  // Exported field_instance: 'node-family-field_family_overview_boxdesc_1'
  $field_instances['node-family-field_family_overview_boxdesc_1'] = array(
    'bundle' => 'family',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_family_overview_boxdesc_1][0][value',
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
        'weight' => 58,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 59,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 59,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 59,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 59,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_family_overview_boxdesc_1',
    'label' => 'Overview RHN Box1 Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 59,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 3,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 59,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-family-field_family_overview_boxdesc_2'
  $field_instances['node-family-field_family_overview_boxdesc_2'] = array(
    'bundle' => 'family',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_family_overview_boxdesc_2][0][value',
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
        'weight' => 62,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 63,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 63,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 63,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 63,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_family_overview_boxdesc_2',
    'label' => 'Overview RHN Box2 Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 63,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 3,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 63,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-family-field_family_overview_boxdesc_3'
  $field_instances['node-family-field_family_overview_boxdesc_3'] = array(
    'bundle' => 'family',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_family_overview_boxdesc_3][0][value',
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
        'weight' => 66,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 67,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 67,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 67,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 67,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_family_overview_boxdesc_3',
    'label' => 'Overview RHN Box3 Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 67,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 3,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 67,
    ),
    'widget_type' => 'text_textarea',
  );


  // Exported field_instance: 'node-family-field_family_prod_boxdesc_1'
  $field_instances['node-family-field_family_prod_boxdesc_1'] = array(
    'bundle' => 'family',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_family_prod_boxdesc_1][0][value',
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
        'weight' => 82,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 83,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 83,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 83,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 83,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_family_prod_boxdesc_1',
    'label' => 'Product RHN Box1 Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 83,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 3,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 83,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-family-field_family_prod_boxdesc_2'
  $field_instances['node-family-field_family_prod_boxdesc_2'] = array(
    'bundle' => 'family',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_family_prod_boxdesc_2][0][value',
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
        'weight' => 86,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 87,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 87,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 87,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 87,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_family_prod_boxdesc_2',
    'label' => 'Product RHN Box2 Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 87,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 3,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 87,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-family-field_family_prod_boxdesc_3'
  $field_instances['node-family-field_family_prod_boxdesc_3'] = array(
    'bundle' => 'family',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_family_prod_boxdesc_3][0][value',
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
        'weight' => 90,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 91,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 91,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 91,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 91,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_family_prod_boxdesc_3',
    'label' => 'Product RHN Box3 Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 91,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 3,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 91,
    ),
    'widget_type' => 'text_textarea',
  );



  // Exported field_instance:
  // 'node-homepage2013language-field_home13lng_ind_desc_1'
  $field_instances['node-homepage2013language-field_home13lng_ind_desc_1'] = array(
    'bundle' => 'homepage2013language',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_home13lng_ind_desc_1][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Short description for the industry in box 1 (250 characters max)',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 23,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 23,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 23,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 23,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_home13lng_ind_desc_1',
    'label' => 'Industry Desc-1',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 23,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 3,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 23,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance:
  // 'node-homepage2013language-field_home13lng_ind_desc_2'
  $field_instances['node-homepage2013language-field_home13lng_ind_desc_2'] = array(
    'bundle' => 'homepage2013language',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_home13lng_ind_desc_2][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Short description for the industry in box 2 (250 characters max)',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 21,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 24,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 24,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 24,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 24,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_home13lng_ind_desc_2',
    'label' => 'Industry Desc-2',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 24,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 3,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 24,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance:
  // 'node-homepage2013language-field_home13lng_ind_desc_3'
  $field_instances['node-homepage2013language-field_home13lng_ind_desc_3'] = array(
    'bundle' => 'homepage2013language',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_home13lng_ind_desc_3][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Short description for the industry in box 3 (250 characters max)',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 22,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 25,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 25,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 25,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 25,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_home13lng_ind_desc_3',
    'label' => 'Industry Desc-3',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 25,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 3,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 25,
    ),
    'widget_type' => 'text_textarea',
  );




  // Exported field_instance: 'node-industry-field_industry_box_desc_1'
  $field_instances['node-industry-field_industry_box_desc_1'] = array(
    'bundle' => 'industry',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_industry_box_desc_1][0][value',
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
        'weight' => 67,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 40,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 40,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 40,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 40,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_industry_box_desc_1',
    'label' => 'RHN Box1 Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 40,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 8,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 40,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-industry-field_industry_box_desc_2'
  $field_instances['node-industry-field_industry_box_desc_2'] = array(
    'bundle' => 'industry',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_industry_box_desc_2][0][value',
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
        'weight' => 72,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 44,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 44,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 44,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 44,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_industry_box_desc_2',
    'label' => 'RHN Box2 Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 44,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 8,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 44,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-industry-field_industry_box_desc_3'
  $field_instances['node-industry-field_industry_box_desc_3'] = array(
    'bundle' => 'industry',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_industry_box_desc_3][0][value',
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
        'weight' => 77,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 48,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 48,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 48,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 48,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_industry_box_desc_3',
    'label' => 'RHN Box3 Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 48,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 8,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 48,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-industry-field_industry_demo_1'
  $field_instances['node-industry-field_industry_demo_1'] = array(
    'bundle' => 'industry',
    'default_value' => array(
      0 => array(
        'title' => '',
        'url' => '',
        'attributes' => array(
          'target' => '_blank',
        ),
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 8,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 14,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_industry_demo_1',
    'label' => 'Demo #1',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'user',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => '',
      ),
      'enable_tokens' => 0,
      'title' => 'required',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'weight' => 14,
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'link_field',
      'weight' => 14,
    ),
    'widget_type' => 'link',
  );

  // Exported field_instance: 'node-industry-field_industry_demo_2'
  $field_instances['node-industry-field_industry_demo_2'] = array(
    'bundle' => 'industry',
    'default_value' => array(
      0 => array(
        'title' => '',
        'url' => '',
        'attributes' => array(
          'target' => '_blank',
        ),
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 10,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 16,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_industry_demo_2',
    'label' => 'Demo #2',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'user',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => '',
      ),
      'enable_tokens' => 0,
      'title' => 'required',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'weight' => 16,
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'link_field',
      'weight' => 16,
    ),
    'widget_type' => 'link',
  );

  // Exported field_instance: 'node-industry-field_industry_demo_3'
  $field_instances['node-industry-field_industry_demo_3'] = array(
    'bundle' => 'industry',
    'default_value' => array(
      0 => array(
        'title' => '',
        'url' => '',
        'attributes' => array(
          'target' => '_blank',
        ),
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 5,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 18,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 18,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_industry_demo_3',
    'label' => 'Demo #3',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'user',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => '',
      ),
      'enable_tokens' => 0,
      'title' => 'required',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'weight' => 18,
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'link_field',
      'weight' => 18,
    ),
    'widget_type' => 'link',
  );

  // Exported field_instance: 'node-industry-field_industry_demo_type_1'
  $field_instances['node-industry-field_industry_demo_type_1'] = array(
    'bundle' => 'industry',
    'default_value' => array(
      0 => array(
        'value' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 7,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 13,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 13,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_industry_demo_type_1',
    'label' => 'Demo Type #1',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 13,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'options_select',
      'weight' => 13,
    ),
    'widget_type' => 'optionwidgets_select',
  );

  // Exported field_instance: 'node-industry-field_industry_demo_type_2'
  $field_instances['node-industry-field_industry_demo_type_2'] = array(
    'bundle' => 'industry',
    'default_value' => array(
      0 => array(
        'value' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 15,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 15,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_industry_demo_type_2',
    'label' => 'Demo Type #2',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 15,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'options_select',
      'weight' => 15,
    ),
    'widget_type' => 'optionwidgets_select',
  );

  // Exported field_instance: 'node-industry-field_industry_demo_type_3'
  $field_instances['node-industry-field_industry_demo_type_3'] = array(
    'bundle' => 'industry',
    'default_value' => array(
      0 => array(
        'value' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 17,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 17,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 17,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_industry_demo_type_3',
    'label' => 'Demo Type #3',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 17,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'options_select',
      'weight' => 17,
    ),
    'widget_type' => 'optionwidgets_select',
  );



  // Exported field_instance: 'node-suite-field_suite_spot_desc_1'
  $field_instances['node-suite-field_suite_spot_desc_1'] = array(
    'bundle' => 'suite',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 42,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_suite_spot_desc_1',
    'label' => 'Spotlight Description #1',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 24,
    ),
  );

  // Exported field_instance: 'node-suite-field_suite_spot_desc_2'
  $field_instances['node-suite-field_suite_spot_desc_2'] = array(
    'bundle' => 'suite',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_suite_spot_desc_2][0][value',
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
        'weight' => 32,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 28,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 28,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 28,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 28,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_suite_spot_desc_2',
    'label' => 'Spotlight Description #2',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 28,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 28,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-suite-field_suite_spot_desc_3'
  $field_instances['node-suite-field_suite_spot_desc_3'] = array(
    'bundle' => 'suite',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_suite_spot_desc_3][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 23,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 32,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 32,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 32,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 32,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_suite_spot_desc_3',
    'label' => 'Spotlight Description #3',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 32,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 32,
    ),
    'widget_type' => 'text_textfield',
  );


  // Exported field_instance: 'node-suite-field_suite_desc'
  $field_instances['node-suite-field_suite_desc'] = array(
    'bundle' => 'suite',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_suite_desc][0][value',
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
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 11,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 11,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_suite_desc',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 11,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 3,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 11,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-homepage2013-field_home13_ind_desc_1'
  $field_instances['node-homepage2013-field_home13_ind_desc_1'] = array(
    'bundle' => 'homepage2013',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_home13_ind_desc_1][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Short description for the industry in box 1 (250 characters max)',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 17,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 20,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 20,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 20,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_home13_ind_desc_1',
    'label' => 'Industry Desc-1',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 20,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 3,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 20,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-homepage2013-field_home13_ind_desc_2'
  $field_instances['node-homepage2013-field_home13_ind_desc_2'] = array(
    'bundle' => 'homepage2013',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_home13_ind_desc_2][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Short description for the industry in box 2 (250 characters max)',
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
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 21,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 21,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 21,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 21,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_home13_ind_desc_2',
    'label' => 'Industry Desc-2',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 21,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 3,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 21,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-homepage2013-field_home13_ind_desc_3'
  $field_instances['node-homepage2013-field_home13_ind_desc_3'] = array(
    'bundle' => 'homepage2013',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_home13_ind_desc_3][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Short description for the industry in box 3 (250 characters max)',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 19,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 22,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 22,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 22,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 22,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_home13_ind_desc_3',
    'label' => 'Industry Desc-3',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 22,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 3,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 22,
    ),
    'widget_type' => 'text_textarea',
  );




  // Exported field_instance: 'node-industrylanguage-field_indlang_box_desc_1'
  $field_instances['node-industrylanguage-field_indlang_box_desc_1'] = array(
    'bundle' => 'industrylanguage',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 40,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 68,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 68,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 68,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 68,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_indlang_box_desc_1',
    'label' => 'RHN Box1 Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 68,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'rows' => NULL,
        'size' => NULL,
      ),
      'type' => 'text_textarea',
      'weight' => 68,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-industrylanguage-field_indlang_box_desc_2'
  $field_instances['node-industrylanguage-field_indlang_box_desc_2'] = array(
    'bundle' => 'industrylanguage',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 44,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 73,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 73,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 73,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 73,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_indlang_box_desc_2',
    'label' => 'RHN Box2 Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 73,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'rows' => NULL,
        'size' => NULL,
      ),
      'type' => 'text_textarea',
      'weight' => 73,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-industrylanguage-field_indlang_box_desc_3'
  $field_instances['node-industrylanguage-field_indlang_box_desc_3'] = array(
    'bundle' => 'industrylanguage',
    'default_value' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 48,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 78,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 78,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 78,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 78,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_indlang_box_desc_3',
    'label' => 'RHN Box3 Description',
    'required' => 0,
    'settings' => array(
      'text_processing' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 78,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'rows' => NULL,
        'size' => NULL,
      ),
      'type' => 'text_textarea',
      'weight' => 78,
    ),
    'widget_type' => 'text_textarea',
  );


  // Exported field_instance:
  // 'node-industrylanguage-field_indlang_expertise_box'
  $field_instances['node-industrylanguage-field_indlang_expertise_box'] = array(
    'bundle' => 'industrylanguage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_indlang_expertise_box][0][value',
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
        'weight' => 21,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 54,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 54,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 54,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 54,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_indlang_expertise_box',
    'label' => 'Expertise LHN Box',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 54,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 54,
    ),
    'widget_type' => 'text_textarea',
  );




  // Exported field_instance: 'node-industrylanguage-field_indlang_product_box'
  $field_instances['node-industrylanguage-field_indlang_product_box'] = array(
    'bundle' => 'industrylanguage',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_indlang_product_box][0][value',
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
        'weight' => 25,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 18,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 18,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 18,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_indlang_product_box',
    'label' => 'Products RHN Box',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 18,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 18,
    ),
    'widget_type' => 'text_textarea',
  );

  
    // Exported field_instance: 'node-industry-field_industry_expertise_box'
  $field_instances['node-industry-field_industry_expertise_box'] = array(
    'bundle' => 'industry',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_industry_expertise_box][0][value',
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
        'weight' => 71,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 21,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 21,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 21,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 21,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_industry_expertise_box',
    'label' => 'Expertise LHN Box',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 21,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 21,
    ),
    'widget_type' => 'text_textarea',
  );






  // Exported field_instance: 'node-industry-field_industry_product_box'
  $field_instances['node-industry-field_industry_product_box'] = array(
    'bundle' => 'industry',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_industry_product_box][0][value',
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
        'weight' => -1,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 25,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_clean',
        'weight' => 25,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 25,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',

        'weight' => 25,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_industry_product_box',
    'label' => 'Products RHN Box',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 25,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 25,
    ),
    'widget_type' => 'text_textarea',
  );



  // Exported field_instance: 'node-product-field_prod_360_img_lg_1'
  $field_instances['node-product-field_prod_360_img_lg_1'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_prod_360_img_lg_1][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Example Path (URL): http://images.flukenetworks.com/360/Products/XG/config.xml',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 55,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 54,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 63,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 54,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 54,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_360_img_lg_1',
    'label' => '360 Image - Path to XML',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 54,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 200,
      ),
      'type' => 'text_textfield',
      'weight' => 54,
    ),
    'widget_type' => 'text_textfield',
  );
