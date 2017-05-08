<?php



  // Exported field_instance: 'node-promotion-field_promo_expdate'
  $field_instances['node-promotion-field_promo_expdate'] = array(
    'bundle' => 'promotion',
    'deleted' => 0,
    'description' => 'Expiration date for promotion. Once date is passed, promo will not display on Index page.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 38,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'short',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 5,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'short',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 5,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'short',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 5,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'short',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'short',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_promo_expdate',
    'label' => 'Expiration Date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 5,
    'widget' => array(
      'active' => 0,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 1,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'repeat_collapsed' => '',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_text',
      'weight' => 5,
    ),
    'widget_type' => 'date_text',
  );



  // Exported field_instance: 'node-promotion-field_promo_intro_title'
  $field_instances['node-promotion-field_promo_intro_title'] = array(
    'bundle' => 'promotion',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_promo_intro_title][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Intro title link for Promotions Index page',
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
        'weight' => -2,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -2,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -2,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_promo_intro_title',
    'label' => 'Intro Title',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => -2,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 100,
      ),
      'type' => 'text_textfield',
      'weight' => -2,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-promotion-field_promo_lgimage'
  $field_instances['node-promotion-field_promo_lgimage'] = array(
    'bundle' => 'promotion',
    'default_value' => '',
    'deleted' => 0,
    'description' => 'Optional large image for display on promotions page',
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
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 4,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 4,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 4,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_promo_lgimage',
    'label' => 'Large Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => 0,
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 4,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 4,
    ),
    'widget_type' => 'imagefield_widget',
  );


  // Exported field_instance: 'node-promotion-field_promo_thumbnail'
  $field_instances['node-promotion-field_promo_thumbnail'] = array(
    'bundle' => 'promotion',
    'default_value' => '',
    'deleted' => 0,
    'description' => 'Thumbnail for Promotions Index page',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -13,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_promo_thumbnail',
    'label' => 'Thumbnail',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '65x65',
      'min_resolution' => 0,
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 1,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => 1,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-promotion-taxonomy_vocabulary_5'
  $field_instances['node-promotion-taxonomy_vocabulary_5'] = array(
    'bundle' => 'promotion',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'taxonomy_vocabulary_5',
    'label' => 'Promotion Type',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 0,
    ),
  );




  // Exported field_instance:
  // 'node-promotion_fulfillment-field_available_products'
  $field_instances['node-promotion_fulfillment-field_available_products'] = array(
    'bundle' => 'promotion_fulfillment',
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
        'type' => 'list_default',
        'weight' => 69,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_available_products',
    'label' => 'Available products',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multiselect',
      'settings' => array(),
      'type' => 'multiselect',
      'weight' => 41,
    ),
  );

  // Exported field_instance:
  // 'node-promotion_fulfillment-field_fullfillment_email'
  $field_instances['node-promotion_fulfillment-field_fullfillment_email'] = array(
    'bundle' => 'promotion_fulfillment',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_fullfillment_email][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Configure one or more email addresses to which promotional requests should be sent. The people at these addresses will be responsible for fulfilling the request for free products.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 0,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_fullfillment_email',
    'label' => 'Fulfillment email',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 4,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance:
  // 'node-promotion_fulfillment-field_gold_contract_bonus'
  $field_instances['node-promotion_fulfillment-field_gold_contract_bonus'] = array(
    'bundle' => 'promotion_fulfillment',
    'default_value' => array(
      0 => array(
        'value' => 0,
        '_error_element' => 'default_value_widget][field_gold_contract_bonus][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'If offering additional bonus dollars for Gold support customers, enter the dollar amount that will be credited to the user for each contract purchased.',
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
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
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
        'type' => 'number_decimal',
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
        'type' => 'number_decimal',
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
        'type' => 'number_decimal',
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
        'type' => 'number_decimal',
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
        'type' => 'number_decimal',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_gold_contract_bonus',
    'label' => 'Gold contract bonus',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '$',
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

  // Exported field_instance: 'node-promotion_fulfillment-field_marketo_flags'
  $field_instances['node-promotion_fulfillment-field_marketo_flags'] = array(
    'bundle' => 'promotion_fulfillment',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_marketo_flags][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Set the <em>Lead_Source_Most_Recent__c</em> value to be sent to Marketo. It is OK to leave this field empty.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 15,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_marketo_flags',
    'label' => 'Lead source most recent',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => 3,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance:
  // 'node-promotion_fulfillment-field_page_one_message'
  $field_instances['node-promotion_fulfillment-field_page_one_message'] = array(
    'bundle' => 'promotion_fulfillment',
    'default_value' => array(
      0 => array(
        'value' => '',
        'format' => 2,
        '_error_element' => 'default_value_widget][field_page_one_message][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'This is the welcome page for the promotion (page one of three). Include an explanation of the promotion as well as any special instructions for the user. This content will appear along with a general user information form which will collect information and send it to Marketo. ',
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
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_page_one_message',
    'label' => 'Page one message',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 5,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 5,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance:
  // 'node-promotion_fulfillment-field_page_two_message'
  $field_instances['node-promotion_fulfillment-field_page_two_message'] = array(
    'bundle' => 'promotion_fulfillment',
    'default_value' => array(
      0 => array(
        'value' => '',
        'format' => 2,
        '_error_element' => 'default_value_widget][field_page_two_message][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'This message will be presented on page two, after the user has submitted his initial details. Page two is where users will be able to enter an invoice amount and select the free products they would like to receive. ',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 30,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_page_two_message',
    'label' => 'Page two message',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 6,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 10,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 6,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance:
  // 'node-promotion_fulfillment-field_pf_disqualified_purchases'
  $field_instances['node-promotion_fulfillment-field_pf_disqualified_purchases'] = array(
    'bundle' => 'promotion_fulfillment',
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
        'type' => 'list_default',
        'weight' => 70,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pf_disqualified_purchases',
    'label' => 'Disqualified purchases',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'multiselect',
      'settings' => array(),
      'type' => 'multiselect',
      'weight' => 42,
    ),
  );

  // Exported field_instance: 'node-promotion_fulfillment-field_pf_promo_codes'
  $field_instances['node-promotion_fulfillment-field_pf_promo_codes'] = array(
    'bundle' => 'promotion_fulfillment',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_pf_promo_codes][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => '<p>Enter valid promotional codes. The format is the code followed by \'|\' and the cash value of that code. For example:</p>
<blockquote>
<pre>
FNET123|200
GOLDEN1|500
PLATINUM3|1000
</pre>
</blockquote>
<p>Code values are <em>not</em> case sensitive .</p>

<p>The code\'s value will be added to the sum of the customers invoice before the reward conversion is calculated.</p>',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 16,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -1,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -1,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pf_promo_codes',
    'label' => 'Promotional codes',
    'required' => 0,
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
      'type' => 'text_textarea',
      'weight' => -1,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance:
  // 'node-promotion_fulfillment-field_reward_conversion'
  $field_instances['node-promotion_fulfillment-field_reward_conversion'] = array(
    'bundle' => 'promotion_fulfillment',
    'default_value' => array(
      0 => array(
        'value' => '12000 & above = 2000
9500 - 11999 = 1600
5000 - 9499 = 1200
2500 - 4999 = 800
500 - 2499 = 400',
        '_error_element' => 'default_value_widget][field_reward_conversion][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Define the amount of dollars available for free gifts based on the dollar amount of the submitted invoice. A sample configuration is provided. Please modify it as needed. You may enter as many or as few lines as you need.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 68,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -2,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -2,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -2,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_reward_conversion',
    'label' => 'Reward conversion',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => -2,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => -2,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-promotion_fulfillment-field_thank_you_page'
  $field_instances['node-promotion_fulfillment-field_thank_you_page'] = array(
    'bundle' => 'promotion_fulfillment',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_thank_you_page][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'This content will be shown to users once they have completed the entire process.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 33,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_thank_you_page',
    'label' => 'Thank you page',
    'required' => 1,
    'settings' => array(
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'weight' => 7,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 7,
    ),
    'widget_type' => 'text_textarea',
  );


  // Exported field_instance: 'node-promotion_product-field_prod_hub_img'
  $field_instances['node-promotion_product-field_prod_hub_img'] = array(
    'bundle' => 'promotion_product',
    'default_value' => '',
    'deleted' => 0,
    'description' => 'Please upload an image of this product. Images will be automatically scaled to the correct size, but for best results, submit images that adhere to the indicated dimensions.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -2,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -1,
      ),
      'rss' => array(
        'label' => 'inline',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -1,
      ),
      'search_index' => array(
        'label' => 'inline',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -1,
      ),
      'search_result' => array(
        'label' => 'inline',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -1,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => -1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_prod_hub_img',
    'label' => 'Product image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => 'images/prod/hub',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '140x140',
      'min_resolution' => '110x110',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => -1,
    'widget' => array(
      'active' => 0,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'bar',
        'use_default_image' => 0,
      ),
      'type' => 'image_image',
      'weight' => -1,
    ),
    'widget_type' => 'imagefield_widget',
  );

  // Exported field_instance: 'node-promotion_product-field_product_id'
  $field_instances['node-promotion_product-field_product_id'] = array(
    'bundle' => 'promotion_product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_product_id][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Enter information that will be used to identify this product when the promotional request is processed. This value should correspond to a unique key such as SKU or database ID.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 83,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -3,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -3,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -3,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_product_id',
    'label' => 'Product model',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => -3,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -3,
    ),
    'widget_type' => 'text_textfield',
  );


  // Exported field_instance: 'node-promotion_product-field_product_item'
  $field_instances['node-promotion_product-field_product_item'] = array(
    'bundle' => 'promotion_product',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_product_item][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Item value of product from master inventory list',
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
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -2,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -2,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -2,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_product_item',
    'label' => 'Product item',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => -2,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -2,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-promotion_product-field_product_value'
  $field_instances['node-promotion_product-field_product_value'] = array(
    'bundle' => 'promotion_product',
    'default_value' => array(
      0 => array(
        'value' => '0.00',
        '_error_element' => 'default_value_widget][field_product_value][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Indicate the product value. This amount will be subtracted from a customer\'s remaining credit when he selects this product.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => -2,
      ),
      'full' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 1,
      ),
      'print' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 1,
      ),
      'rss' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 1,
      ),
      'search_index' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 1,
      ),
      'search_result' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 1,
      ),
      'token' => array(
        'label' => 'inline',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_decimal',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_product_value',
    'label' => 'Value',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '$',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => 1,
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'number',
      'weight' => 1,
    ),
    'widget_type' => 'number',
  );

  // Exported field_instance: 'node-promotion_product-taxonomy_vocabulary_11'
  $field_instances['node-promotion_product-taxonomy_vocabulary_11'] = array(
    'bundle' => 'promotion_product',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'taxonomy_vocabulary_11',
    'label' => 'Promotion product category',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 0,
    ),
  );



