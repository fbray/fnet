<?php

// hidden on all view modes



  // Exported field_instance: 'node-asset_gateway-field_ag_redirect'
  $field_instances['node-asset_gateway-field_ag_redirect'] = array(
    'bundle' => 'asset_gateway',
    'default_value' => array(
      0 => array(
        'url' => '',
      ),
    ),
    'deleted' => 0,
    'description' => 'The target URL of the content. If this field is left empty, no redirect will take place and the user will remain on this page.<br />
<br />
<em>Example:</em> http://assets.example.com/asset/123',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 45,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -1,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -1,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ag_redirect',
    'label' => 'Redirect URL',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => 'asset_gateway_url',
        'rel' => 'nofollow',
        'target' => 'default',
        'title' => 'null',
      ),
      'display' => array(
        'url_cutoff' => 255,
      ),
      'enable_tokens' => 0,
      'title' => 'none',
      'title_label_use_field_label' => FALSE,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'weight' => -1,
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'link_field',
      'weight' => -1,
    ),
    'widget_type' => 'link',
  );

  // Exported field_instance: 'node-asset_gateway-field_ag_redirect_wait'
  $field_instances['node-asset_gateway-field_ag_redirect_wait'] = array(
    'bundle' => 'asset_gateway',
    'default_value' => array(
      0 => array(
        'value' => 5,
      ),
    ),
    'deleted' => 0,
    'description' => 'The number of seconds before the user will be redirected to the target page. If no redirect URL is configured above, this value is ignored.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_ag_redirect_wait',
    'label' => 'Redirect wait',
    'required' => 0,
    'settings' => array(
      'max' => 10,
      'min' => 0,
      'prefix' => '',
      'suffix' => 'second|seconds',
      'user_register_form' => FALSE,
    ),
    'weight' => 0,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'options_select',
      'weight' => 0,
    ),
    'widget_type' => 'optionwidgets_select',
  );

  // Exported field_instance: 'node-asset_gateway-field_ag_tracking_code'
  $field_instances['node-asset_gateway-field_ag_tracking_code'] = array(
    'bundle' => 'asset_gateway',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_ag_tracking_code][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Include any HTML or javascript tracking code. This content will be placed directly into the page, so be sure to include any necessary script or html tags.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_ag_tracking_code',
    'label' => 'Ad tracking code',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 1,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
    'widget_type' => 'text_textarea',
  );


  // Exported field_instance: 'node-page-field_removenav'
  $field_instances['node-page-field_removenav'] = array(
    'bundle' => 'page',
    'default_value' => array(
      0 => array(
        'value' => NULL,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_removenav',
    'label' => 'Remove Top Navigation & Footer',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 0,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
        'display_label' => 0,
      ),
      'type' => 'hidden',
      'weight' => 0,
    ),
    'widget_type' => 'optionwidgets_onoff',
  );


  // Exported field_instance: 'node-page_reg-field_removenav'
  $field_instances['node-page_reg-field_removenav'] = array(
    'bundle' => 'page_reg',
    'default_value' => array(
      0 => array(
        'value' => 'No',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'email',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -2,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_removenav',
    'label' => 'Remove Top Navigation & Footer',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 1,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
        'display_label' => 0,
      ),
      'type' => 'hidden',
      'weight' => 1,
    ),
    'widget_type' => 'optionwidgets_onoff',
  );


  // Exported field_instance:
  // 'node-product_distributor_group-field_custom_publish_content'
  $field_instances['node-product_distributor_group-field_custom_publish_content'] = array(
    'bundle' => 'product_distributor_group',
    'default_value' => array(
      0 => array(
        'value' => NULL,
      ),
    ),
    'deleted' => 0,
    'description' => 'Published/Not-Published is same as Active/In-Active',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 32,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'hidden',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_custom_publish_content',
    'label' => 'Published',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 8,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
        'display_label' => 0,
      ),
      'type' => 'hidden',
      'weight' => 8,
    ),
    'widget_type' => 'optionwidgets_onoff',
  );




  // Exported field_instance: 'node-productsubtype-field_support_options'
  $field_instances['node-productsubtype-field_support_options'] = array(
    'bundle' => 'productsubtype',
    'default_value' => array(
      0 => array(
        'nid' => NULL,
        '_error_element' => 'default_value_widget][field_support_options][0][nid][nid',
      ),
    ),
    'deleted' => 0,
    'description' => 'If this sub-product has specific support options available for it, please specify them here. This information will appear in the <em>Models & Accessories</em> tab of the parent product page. <strong>Note:</strong> values configured here may take up to an hour to display on the product page due to data caching.
',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_support_options',
    'label' => 'Available support options',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 1,
    'widget' => array(
      'active' => 0,
      'module' => 'node_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'node_reference/autocomplete',
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 128,
      ),
      'type' => 'node_reference_autocomplete',
      'weight' => 1,
    ),
    'widget_type' => 'nodereference_autocomplete',
  );


  // Exported field_instance: 'node-industrylanguage-field_indlang_demo_disable'
  $field_instances['node-industrylanguage-field_indlang_demo_disable'] = array(
    'bundle' => 'industrylanguage',
    'default_value' => array(
      0 => array(
        'value' => 'No',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 50,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_indlang_demo_disable',
    'label' => 'Disable All Demo',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 4,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'hidden',
      'weight' => 4,
    ),
    'widget_type' => 'optionwidgets_buttons',
  );

  // Exported field_instance:
  // 'node-industrylanguage-field_indlang_box_disable_1'
  $field_instances['node-industrylanguage-field_indlang_box_disable_1'] = array(
    'bundle' => 'industrylanguage',
    'default_value' => array(
      0 => array(
        'value' => 'No',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 70,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 65,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 65,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 65,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 65,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_indlang_box_disable_1',
    'label' => 'Disable RHN Box1',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 65,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'hidden',
      'weight' => 65,
    ),
    'widget_type' => 'optionwidgets_buttons',
  );

  // Exported field_instance:
  // 'node-industrylanguage-field_indlang_box_disable_2'
  $field_instances['node-industrylanguage-field_indlang_box_disable_2'] = array(
    'bundle' => 'industrylanguage',
    'default_value' => array(
      0 => array(
        'value' => 'No',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 75,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 70,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 70,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 70,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 70,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_indlang_box_disable_2',
    'label' => 'Disable RHN Box2',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 70,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'hidden',
      'weight' => 70,
    ),
    'widget_type' => 'optionwidgets_buttons',
  );

  // Exported field_instance:
  // 'node-industrylanguage-field_indlang_box_disable_3'
  $field_instances['node-industrylanguage-field_indlang_box_disable_3'] = array(
    'bundle' => 'industrylanguage',
    'default_value' => array(
      0 => array(
        'value' => 'No',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 75,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 75,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_indlang_box_disable_3',
    'label' => 'Disable RHN Box3',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 75,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'hidden',
      'weight' => 75,
    ),
    'widget_type' => 'optionwidgets_buttons',
  );


  // Exported field_instance:
  // 'node-industrylanguage-field_indlang_fea_top_disable'
  $field_instances['node-industrylanguage-field_indlang_fea_top_disable'] = array(
    'bundle' => 'industrylanguage',
    'default_value' => array(
      0 => array(
        'value' => 'No',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 46,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 50,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 50,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
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
    'field_name' => 'field_indlang_fea_top_disable',
    'label' => 'Disable All Featured Topics',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 50,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'hidden',
      'weight' => 50,
    ),
    'widget_type' => 'optionwidgets_buttons',
  );


  // Exported field_instance:
  // 'node-industrylanguage-field_indlang_learn_abt_disable'
  $field_instances['node-industrylanguage-field_indlang_learn_abt_disable'] = array(
    'bundle' => 'industrylanguage',
    'default_value' => array(
      0 => array(
        'value' => 'No',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 46,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 46,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
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
    'field_name' => 'field_indlang_learn_abt_disable',
    'label' => 'Disable All Learn About',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 46,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'hidden',
      'weight' => 46,
    ),
    'widget_type' => 'optionwidgets_buttons',
  );


  // Exported field_instance:
  // 'node-industrylanguage-field_indlang_pop_res_disable'
  $field_instances['node-industrylanguage-field_indlang_pop_res_disable'] = array(
    'bundle' => 'industrylanguage',
    'default_value' => array(
      0 => array(
        'value' => 'No',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 42,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_indlang_pop_res_disable',
    'label' => 'Disable All Popular Resources',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 42,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'hidden',
      'weight' => 42,
    ),
    'widget_type' => 'optionwidgets_buttons',
  );


  // Exported field_instance:
  // 'node-industrylanguage-field_indlang_promo_disable'
  $field_instances['node-industrylanguage-field_indlang_promo_disable'] = array(
    'bundle' => 'industrylanguage',
    'default_value' => array(
      0 => array(
        'value' => 'No',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_indlang_promo_disable',
    'label' => 'Disable All Promotions',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 0,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'hidden',
      'weight' => 0,
    ),
    'widget_type' => 'optionwidgets_buttons',
  );



  // Exported field_instance:
  // 'node-industrylanguage-field_indlang_trial_disable'
  $field_instances['node-industrylanguage-field_indlang_trial_disable'] = array(
    'bundle' => 'industrylanguage',
    'default_value' => array(
      0 => array(
        'value' => 'No',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 65,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_indlang_trial_disable',
    'label' => 'Disable All Trials',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 11,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'hidden',
      'weight' => 11,
    ),
    'widget_type' => 'optionwidgets_buttons',
  );


  // Exported field_instance: 'node-product-field_prod_btn_cta_size'
  $field_instances['node-product-field_prod_btn_cta_size'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '1 line',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 61,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_btn_cta_size',
    'label' => 'Button Size',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 52,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'hidden',
      'weight' => 52,
    ),
    'widget_type' => 'optionwidgets_buttons',
  );

  // Exported field_instance:
  // 'node-productlanguage-field_prodlang_btnact_disable'
  $field_instances['node-productlanguage-field_prodlang_btnact_disable'] = array(
    'bundle' => 'productlanguage',
    'default_value' => array(
      0 => array(
        'value' => 'No',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prodlang_btnact_disable',
    'label' => 'Disable All Call to Action Buttons',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 0,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'hidden',
      'weight' => 0,
    ),
    'widget_type' => 'optionwidgets_buttons',
  );

  // Exported field_instance: 'node-productlanguage-field_prodlang_btn_cta_size'
  $field_instances['node-productlanguage-field_prodlang_btn_cta_size'] = array(
    'bundle' => 'productlanguage',
    'default_value' => array(
      0 => array(
        'value' => '1 line',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 52,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prodlang_btn_cta_size',
    'label' => 'Button Size',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 1,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'hidden',
      'weight' => 1,
    ),
    'widget_type' => 'optionwidgets_buttons',
  );


  // Exported field_instance: 'node-productlanguage-field_prodlang_sol_disable'
  $field_instances['node-productlanguage-field_prodlang_sol_disable'] = array(
    'bundle' => 'productlanguage',
    'default_value' => array(
      0 => array(
        'value' => 'No',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 17,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_prodlang_sol_disable',
    'label' => 'Disable All Solutions',
    'required' => 1,
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
      'type' => 'hidden',
      'weight' => 17,
    ),
    'widget_type' => 'optionwidgets_buttons',
  );



  // Exported field_instance: 'node-product-field_do_not_distribute'
  $field_instances['node-product-field_do_not_distribute'] = array(
    'bundle' => 'product',
    'default_value' => NULL,
    'default_value_function' => '',
    'default_value_php' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 74,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 76,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 74,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_do_not_distribute',
    'label' => 'Do not distribute',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multiselect',
      'settings' => array(),
      'type' => 'multiselect',
      'weight' => 75,
    ),
  );

  // Exported field_instance: 'node-product-field_onyxhierarchyid'
  $field_instances['node-product-field_onyxhierarchyid'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_onyxhierarchyid][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'hidden',
        'weight' => 16,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_onyxhierarchyid',
    'label' => 'Onyx Hierarchy ID',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 0,
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'number',
      'weight' => 0,
    ),
    'widget_type' => 'number',
  );


  // Exported field_instance: 'node-product-field_pcatid'
  $field_instances['node-product-field_pcatid'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pcatid][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'PCATID from legacy FNET system.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -1,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'hidden',
        'weight' => -1,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pcatid',
    'label' => 'PCATID',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => -1,
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'number',
      'weight' => -1,
    ),
    'widget_type' => 'number',
  );

  // Exported field_instance: 'node-product-field_prod_contact_sales_button'
  $field_instances['node-product-field_prod_contact_sales_button'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => 'off',
      ),
    ),
    'deleted' => 0,
    'description' => '<strong>Note:</strong> If any Online Store is present for the region, then the Contact Sales button will not display even if it is checked.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_contact_sales_button',
    'label' => 'Contact Sales Button',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 4,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
        'display_label' => 0,
      ),
      'type' => 'hidden',
      'weight' => 4,
    ),
    'widget_type' => 'optionwidgets_onoff',
  );


  // Exported field_instance: 'node-product-field_prod_rating_review'
  $field_instances['node-product-field_prod_rating_review'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => NULL,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 57,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 65,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 57,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 57,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_rating_review',
    'label' => 'Enable Ratings and Reviews',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 57,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
        'display_label' => 0,
      ),
      'type' => 'hidden',
      'weight' => 57,
    ),
    'widget_type' => 'optionwidgets_onoff',
  );

  // Exported field_instance: 'node-product-field_prod_where_to_buy_button'
  $field_instances['node-product-field_prod_where_to_buy_button'] = array(
    'bundle' => 'product',
    'default_value' => array(
      0 => array(
        'value' => 'off',
      ),
    ),
    'deleted' => 0,
    'description' => '<strong>Note:</strong> If any Online Store is present for the region, then the Where to Buy button will not display even if it is checked. Instead, this will be included as a link titled "See more online resellers or buy locally".',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_where_to_buy_button',
    'label' => 'Where to Buy Button',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 5,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
        'display_label' => 0,
      ),
      'type' => 'hidden',
      'weight' => 5,
    ),
    'widget_type' => 'optionwidgets_onoff',
  );

  // Exported field_instance: 'node-localized_email-field_email_from'
  $field_instances['node-localized_email-field_email_from'] = array(
    'bundle' => 'localized_email',
    'default_value' => array(
      0 => array(
        'email' => '',
      ),
    ),
    'deleted' => 0,
    'description' => 'The email address that the email should be from.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -4,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'email',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -3,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'email',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -3,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'email',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -3,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'email',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_email_from',
    'label' => 'From address',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => -3,
    'widget' => array(
      'active' => 0,
      'module' => 'email',
      'settings' => array(
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => -3,
    ),
    'widget_type' => 'email_textfield',
  );

  // Exported field_instance: 'node-localized_email-field_email_from_name'
  $field_instances['node-localized_email-field_email_from_name'] = array(
    'bundle' => 'localized_email',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_email_from_name][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'The name of the person or entity the email message should be from.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -4,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -4,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -4,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_email_from_name',
    'label' => 'From name',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => -4,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -4,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-localized_email-field_email_reply_to'
  $field_instances['node-localized_email-field_email_reply_to'] = array(
    'bundle' => 'localized_email',
    'default_value' => array(
      0 => array(
        'email' => '',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 55,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'email',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -2,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'email',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -2,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'email',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -2,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'email',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_email_reply_to',
    'label' => 'Reply-to address',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => -2,
    'widget' => array(
      'active' => 0,
      'module' => 'email',
      'settings' => array(
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => -2,
    ),
    'widget_type' => 'email_textfield',
  );

  // Exported field_instance: 'node-localized_email-field_email_subject'
  $field_instances['node-localized_email-field_email_subject'] = array(
    'bundle' => 'localized_email',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_email_subject][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -1,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -1,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => -1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_email_subject',
    'label' => 'Subject',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => -1,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -1,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-family-field_family_page_active'
  $field_instances['node-family-field_family_page_active'] = array(
    'bundle' => 'family',
    'default_value' => array(
      0 => array(
        'value' => 'No',
      ),
    ),
    'deleted' => 0,
    'description' => 'This check to activate the family landing page',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 51,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'hidden',
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
    'field_name' => 'field_family_page_active',
    'label' => 'Family Page Active',
    'required' => 1,
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
      'type' => 'hidden',
      'weight' => 15,
    ),
    'widget_type' => 'optionwidgets_buttons',
  );

