<?php



  // Exported field_instance:
  // 'node-event_occurrence-field_evnt_occ_accommodations'
  $field_instances['node-event_occurrence-field_evnt_occ_accommodations'] = array(
    'bundle' => 'event_occurrence',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_evnt_occ_accommodations][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Information about available accommodations for this event occurrence.  This is a rich text field, html is allowed.',
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
        'weight' => -4,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -4,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -4,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_evnt_occ_accommodations',
    'label' => 'Accommodations',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
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
      'type' => 'text_textarea',
      'weight' => -4,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-event_occurrence-field_evnt_occ_capacity'
  $field_instances['node-event_occurrence-field_evnt_occ_capacity'] = array(
    'bundle' => 'event_occurrence',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_evnt_occ_capacity][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Maximum number of registrants for this event occurrence.  Enter 0 if no registration is required.',
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
        'type' => 'number_integer',
        'weight' => 13,
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
        'type' => 'number_integer',
        'weight' => -6,
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
        'type' => 'number_integer',
        'weight' => -6,
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
        'type' => 'number_integer',
        'weight' => -6,
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
        'type' => 'number_integer',
        'weight' => -6,
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
        'type' => 'number_integer',
        'weight' => -6,
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
        'type' => 'number_integer',
        'weight' => -6,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_evnt_occ_capacity',
    'label' => 'Capacity',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => -6,
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(
        'default_value_php' => NULL,
      ),
      'type' => 'number',
      'weight' => -6,
    ),
    'widget_type' => 'number',
  );

  // Exported field_instance: 'node-event_occurrence-field_evnt_occ_contact'
  $field_instances['node-event_occurrence-field_evnt_occ_contact'] = array(
    'bundle' => 'event_occurrence',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_evnt_occ_contact][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Who to contact about this event.',
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
    'field_name' => 'field_evnt_occ_contact',
    'label' => 'Contact Information',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
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

  // Exported field_instance: 'node-event_occurrence-field_evnt_occ_cost'
  $field_instances['node-event_occurrence-field_evnt_occ_cost'] = array(
    'bundle' => 'event_occurrence',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_evnt_occ_cost][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Cost to attend the event.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 30,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -12,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -12,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -12,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -12,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_evnt_occ_cost',
    'label' => 'Cost',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => -12,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 30,
      ),
      'type' => 'text_textfield',
      'weight' => -12,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance: 'node-event_occurrence-field_evnt_occ_date'
  $field_instances['node-event_occurrence-field_evnt_occ_date'] = array(
    'bundle' => 'event_occurrence',
    'deleted' => 0,
    'description' => 'Date of this event occurrence.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'medium',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => -4,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'medium',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => -14,
      ),
      'print' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'medium',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => -14,
      ),
      'rss' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'medium',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => -14,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'medium',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => -14,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'medium',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => -14,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'medium',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_repeat_rule' => 'show',
        ),
        'type' => 'date_default',
        'weight' => -14,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_evnt_occ_date',
    'label' => 'Date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'weight' => -14,
    'widget' => array(
      'active' => 0,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 1,
        'input_format' => 'Y-m-d',
        'input_format_custom' => '',
        'label_position' => 'above',
        'repeat_collapsed' => '',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => -14,
    ),
    'widget_type' => 'date_popup',
  );


  // Exported field_instance:
  // 'node-event_occurrence-field_evnt_occ_marketo_program'
  $field_instances['node-event_occurrence-field_evnt_occ_marketo_program'] = array(
    'bundle' => 'event_occurrence',
    'default_value' => array(
      0 => array(
        'value' => '',
      ),
    ),
    'deleted' => 0,
    'description' => 'The Marketo Program that will track attendees, send email, etc.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 17,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -9,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -9,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -9,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -9,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_evnt_occ_marketo_program',
    'label' => 'Marketo Program Name',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => -9,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 30,
      ),
      'type' => 'options_select',
      'weight' => -9,
    ),
    'widget_type' => 'optionwidgets_select',
  );

  // Exported field_instance: 'node-event_occurrence-field_evnt_occ_notes'
  $field_instances['node-event_occurrence-field_evnt_occ_notes'] = array(
    'bundle' => 'event_occurrence',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_evnt_occ_notes][0][value',
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
        'weight' => 1,
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
    'field_name' => 'field_evnt_occ_notes',
    'label' => 'Notes',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
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

  // Exported field_instance: 'node-event_occurrence-field_evnt_occ_parent'
  $field_instances['node-event_occurrence-field_evnt_occ_parent'] = array(
    'bundle' => 'event_occurrence',
    'default_value' => array(
      0 => array(
        'nid' => NULL,
        '_error_element' => 'default_value_widget][field_evnt_occ_parent][0][nid][nid',
      ),
    ),
    'deleted' => 0,
    'description' => 'The event that this is an occurrence of.',
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
        'weight' => -18,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -18,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -18,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => -18,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_evnt_occ_parent',
    'label' => 'Event',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => -18,
    'widget' => array(
      'active' => 0,
      'module' => 'node_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'node_reference/autocomplete',
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'node_reference_autocomplete',
      'weight' => -18,
    ),
    'widget_type' => 'nodereference_autocomplete',
  );

  // Exported field_instance: 'node-event_occurrence-field_evnt_occ_req_address'
  $field_instances['node-event_occurrence-field_evnt_occ_req_address'] = array(
    'bundle' => 'event_occurrence',
    'default_value' => array(
      0 => array(
        'value' => 'no',
      ),
    ),
    'deleted' => 0,
    'description' => 'Should an address be required on the registration form.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 11,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -7,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -7,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -7,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -7,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_evnt_occ_req_address',
    'label' => 'Require Address',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => -7,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => -7,
    ),
    'widget_type' => 'optionwidgets_onoff',
  );

  // Exported field_instance:
  // 'node-event_occurrence-field_evnt_occ_req_gold_number'
  $field_instances['node-event_occurrence-field_evnt_occ_req_gold_number'] = array(
    'bundle' => 'event_occurrence',
    'default_value' => array(
      0 => array(
        'value' => 'no',
      ),
    ),
    'deleted' => 0,
    'description' => 'Should a \'Gold Number\' field be on the registration form?',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => -7,
      ),
      'full' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -8,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -8,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -8,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -8,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_evnt_occ_req_gold_number',
    'label' => 'Request Gold Number',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => -8,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => -8,
    ),
    'widget_type' => 'optionwidgets_onoff',
  );

  // Exported field_instance: 'node-event_occurrence-field_evnt_occ_thank_you'
  $field_instances['node-event_occurrence-field_evnt_occ_thank_you'] = array(
    'bundle' => 'event_occurrence',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_evnt_occ_thank_you][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'The message that will be displayed after someone registers for an event.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
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
        'type' => 'text_default',
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
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_evnt_occ_thank_you',
    'label' => 'Thank you message',
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
        'rows' => 5,
        'size' => 60,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-event_occurrence-field_evnt_occ_time'
  $field_instances['node-event_occurrence-field_evnt_occ_time'] = array(
    'bundle' => 'event_occurrence',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_evnt_occ_time][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'The time or time range for the event.  This is a text field so values such as TBD can be entered. Examples of proper formatting are 8:00AM PDT, 8:00AM - 5:00PM BST, 19:00 GMT or TBD.',
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
        'weight' => -13,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -13,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -13,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -13,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_evnt_occ_time',
    'label' => 'Time',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => -13,
    'widget' => array(
      'active' => 0,
      'module' => 'text',
      'settings' => array(
        'default_value_php' => NULL,
        'rows' => 5,
        'size' => 30,
      ),
      'type' => 'text_textfield',
      'weight' => -13,
    ),
    'widget_type' => 'text_textfield',
  );

  // Exported field_instance:
  // 'node-event_occurrence-field_evnt_occ_transportation'
  $field_instances['node-event_occurrence-field_evnt_occ_transportation'] = array(
    'bundle' => 'event_occurrence',
    'default_value' => array(
      0 => array(
        'value' => '',
        '_error_element' => 'default_value_widget][field_evnt_occ_transportation][0][value',
      ),
    ),
    'deleted' => 0,
    'description' => 'Information about transportation options.',
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
    'field_name' => 'field_evnt_occ_transportation',
    'label' => 'Transportation',
    'required' => 0,
    'settings' => array(
      'text_processing' => 1,
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
      'type' => 'text_textarea',
      'weight' => -3,
    ),
    'widget_type' => 'text_textarea',
  );

  // Exported field_instance: 'node-event_occurrence-field_evnt_occ_waitlist'
  $field_instances['node-event_occurrence-field_evnt_occ_waitlist'] = array(
    'bundle' => 'event_occurrence',
    'default_value' => array(
      0 => array(
        'value' => 'no',
      ),
    ),
    'deleted' => 0,
    'description' => 'Should registrants over capacity be placed on a waiting list?',
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
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -5,
      ),
      'search_index' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -5,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -5,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => -5,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_evnt_occ_waitlist',
    'label' => 'Waiting list',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'weight' => -5,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'default_value_php' => NULL,
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => -5,
    ),
    'widget_type' => 'optionwidgets_onoff',
  );


