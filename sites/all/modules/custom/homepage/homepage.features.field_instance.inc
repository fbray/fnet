<?php

/**
 * @file
 * homepage.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function homepage_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-homepage2013-body'.
  $field_instances['node-homepage2013-body'] = array(
    'bundle' => 'homepage2013',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'search_result' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => TRUE,
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-homepage2013-field_category_description_1'.
  $field_instances['node-homepage2013-field_category_description_1'] = array(
    'bundle' => 'homepage2013',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Short description for the Product Category in box 1 (250 characters max)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_category_description_1',
    'label' => 'Category Description 1',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 47,
    ),
  );

  // Exported field_instance: 'node-homepage2013-field_category_description_2'.
  $field_instances['node-homepage2013-field_category_description_2'] = array(
    'bundle' => 'homepage2013',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Short description for the Product Category in box 2 (250 characters max)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_category_description_2',
    'label' => 'Category Description 2',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 48,
    ),
  );

  // Exported field_instance: 'node-homepage2013-field_category_description_3'.
  $field_instances['node-homepage2013-field_category_description_3'] = array(
    'bundle' => 'homepage2013',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Short description for the Product Category in box 3 (250 characters max)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_category_description_3',
    'label' => 'Category Description 3',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
      ),
      'type' => 'text_textarea',
      'weight' => 49,
    ),
  );

  // Exported field_instance: 'node-homepage2013-field_home13_ads'.
  $field_instances['node-homepage2013-field_home13_ads'] = array(
    'bundle' => 'homepage2013',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_home13_ads',
    'label' => 'Ads HTML',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
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
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-homepage2013-field_home13_banner_html'.
  $field_instances['node-homepage2013-field_home13_banner_html'] = array(
    'bundle' => 'homepage2013',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_home13_banner_html',
    'label' => 'Hero Banner HTML',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 54,
    ),
  );

  // Exported field_instance: 'node-homepage2013-field_home13_expind'.
  $field_instances['node-homepage2013-field_home13_expind'] = array(
    'bundle' => 'homepage2013',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 5,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_home13_expind',
    'label' => 'Industry',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'user',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 250,
      ),
      'enable_tokens' => 0,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'required',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 52,
    ),
  );

  // Exported field_instance: 'node-homepage2013-field_home13_exprle'.
  $field_instances['node-homepage2013-field_home13_exprle'] = array(
    'bundle' => 'homepage2013',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 4,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_home13_exprle',
    'label' => 'Role',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'user',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 250,
      ),
      'enable_tokens' => 0,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'required',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'node-homepage2013-field_home13_exptpc'.
  $field_instances['node-homepage2013-field_home13_exptpc'] = array(
    'bundle' => 'homepage2013',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 3,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_home13_exptpc',
    'label' => 'Topic',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'user',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 250,
      ),
      'enable_tokens' => 0,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'required',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 45,
    ),
  );

  // Exported field_instance:
  // 'node-homepage2013-field_homepage_language_override'.
  $field_instances['node-homepage2013-field_homepage_language_override'] = array(
    'bundle' => 'homepage2013',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<ul>
<li>en-au (<strong>English/Australia</strong>)</li>
<li>en-ca (<strong>English/Canada</strong>)</li>
<li>en-eu (<strong>English/Europe</strong>)</li>
<li>en-in (<strong>English/India</strong>)</li>
<li>en-ln (<strong>English/Latin America</strong>)</li>
<li>en-su (<strong>English/Southeast Asia</strong>)</li>
<li>fr-eu (<strong>French/Europe</strong>)</li>
<li>fr-ca (<strong>French/Canada</strong>)</li>
<li>de-eu (<strong>German/Europe</strong>)</li>
<li>es-eu (<strong>Spanish/Europe</strong>)</li>
<li>es-ln (<strong>Spanish/Latin America</strong>)</li>
<li>pt-eu (<strong>Portuguese/Europe</strong>)</li>
<li>pt-br (<strong>Portuguese/Brazil</strong>)</li>
<li>cn-zh (<strong>Chinese/China</strong>)</li>
<li>jp-ja (<strong>Japanese/Japan</strong>)</li>
<li>ko-kr (<strong>Korean/Korea</strong>)</li>
<li>ru-ru (<strong>Russian/Russia</strong>)</li>
</ul>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 11,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_homepage_language_override',
    'label' => 'Language Override',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-homepage2013-field_tracking_code'.
  $field_instances['node-homepage2013-field_tracking_code'] = array(
    'bundle' => 'homepage2013',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'search_result' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tracking_code',
    'label' => 'Ad Tracking Code',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-homepage2013_language-body'.
  $field_instances['node-homepage2013_language-body'] = array(
    'bundle' => 'homepage2013_language',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => TRUE,
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 4,
    ),
  );

  // Exported field_instance:
  // 'node-homepage2013_language-field_category_description_1'.
  $field_instances['node-homepage2013_language-field_category_description_1'] = array(
    'bundle' => 'homepage2013_language',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_category_description_1',
    'label' => 'Category Description 1',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
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
      'weight' => 16,
    ),
  );

  // Exported field_instance:
  // 'node-homepage2013_language-field_category_description_2'.
  $field_instances['node-homepage2013_language-field_category_description_2'] = array(
    'bundle' => 'homepage2013_language',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_category_description_2',
    'label' => 'Category Description 2',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
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
      'weight' => 17,
    ),
  );

  // Exported field_instance:
  // 'node-homepage2013_language-field_category_description_3'.
  $field_instances['node-homepage2013_language-field_category_description_3'] = array(
    'bundle' => 'homepage2013_language',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_category_description_3',
    'label' => 'Category Description 3',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
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
      'weight' => 18,
    ),
  );

  // Exported field_instance: 'node-homepage2013_language-field_home13_ads'.
  $field_instances['node-homepage2013_language-field_home13_ads'] = array(
    'bundle' => 'homepage2013_language',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_home13_ads',
    'label' => 'Ads HTML',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 14,
    ),
  );

  // Exported field_instance:
  // 'node-homepage2013_language-field_home13_banner_html'.
  $field_instances['node-homepage2013_language-field_home13_banner_html'] = array(
    'bundle' => 'homepage2013_language',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_formatter_filter' => NULL,
        ),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_home13_banner_html',
    'label' => 'Hero Banner HTML',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-homepage2013_language-field_home13_expind'.
  $field_instances['node-homepage2013_language-field_home13_expind'] = array(
    'bundle' => 'homepage2013_language',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_home13_expind',
    'label' => 'Industry',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 8,
    ),
  );

  // Exported field_instance: 'node-homepage2013_language-field_home13_exprle'.
  $field_instances['node-homepage2013_language-field_home13_exprle'] = array(
    'bundle' => 'homepage2013_language',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_home13_exprle',
    'label' => 'Role',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 7,
    ),
  );

  // Exported field_instance: 'node-homepage2013_language-field_home13_exptpc'.
  $field_instances['node-homepage2013_language-field_home13_exptpc'] = array(
    'bundle' => 'homepage2013_language',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_home13_exptpc',
    'label' => 'Topic',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 0,
      'entity_translation_sync' => FALSE,
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-homepage2013_language-field_homepage'.
  $field_instances['node-homepage2013_language-field_homepage'] = array(
    'bundle' => 'homepage2013_language',
    'default_value' => array(
      0 => array(
        'target_id' => 161,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'bypass_access' => FALSE,
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_homepage',
    'label' => 'Homepage',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'node-homepage2013_language-field_language_region'.
  $field_instances['node-homepage2013_language-field_language_region'] = array(
    'bundle' => 'homepage2013_language',
    'default_value' => NULL,
    'default_value_function' => '',
    'default_value_php' => '',
    'deleted' => 0,
    'description' => '<ul>
<li>en-us (<strong>English/United States</strong>)</li>
<li>en-au (<strong>English/Australia</strong>)</li>
<li>en-ca (<strong>English/Canada</strong>)</li>
<li>en-eu (<strong>English/Europe</strong>)</li>
<li>en-in (<strong>English/India</strong>)</li>
<li>en-ln (<strong>English/Latin America</strong>)</li>
<li>en-su (<strong>English/Southeast Asia</strong>)</li>
<li>fr-eu (<strong>French/Europe</strong>)</li>
<li>fr-ca (<strong>French/Canada</strong>)</li>
<li>de-eu (<strong>German/Europe</strong>)</li>
<li>es-eu (<strong>Spanish/Europe</strong>)</li>
<li>es-ln (<strong>Spanish/Latin America</strong>)</li>
<li>pt-eu (<strong>Portuguese/Europe</strong>)</li>
<li>pt-br (<strong>Portuguese/Brazil</strong>)</li>
<li>cn-zh (<strong>Chinese/China</strong>)</li>
<li>jp-ja (<strong>Japanese/Japan</strong>)</li>
<li>ko-kr (<strong>Korean/Korea</strong>)</li>
<li>ru-ru (<strong>Russian/Russia</strong>)</li>
</ul>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_language_region',
    'label' => 'Language/Region',
    'required' => 1,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<ul>
<li>en-au (<strong>English/Australia</strong>)</li>
<li>en-ca (<strong>English/Canada</strong>)</li>
<li>en-eu (<strong>English/Europe</strong>)</li>
<li>en-in (<strong>English/India</strong>)</li>
<li>en-ln (<strong>English/Latin America</strong>)</li>
<li>en-su (<strong>English/Southeast Asia</strong>)</li>
<li>fr-eu (<strong>French/Europe</strong>)</li>
<li>fr-ca (<strong>French/Canada</strong>)</li>
<li>de-eu (<strong>German/Europe</strong>)</li>
<li>es-eu (<strong>Spanish/Europe</strong>)</li>
<li>es-ln (<strong>Spanish/Latin America</strong>)</li>
<li>pt-eu (<strong>Portuguese/Europe</strong>)</li>
<li>pt-br (<strong>Portuguese/Brazil</strong>)</li>
<li>cn-zh (<strong>Chinese/China</strong>)</li>
<li>jp-ja (<strong>Japanese/Japan</strong>)</li>
<li>ko-kr (<strong>Korean/Korea</strong>)</li>
<li>ru-ru (<strong>Russian/Russia</strong>)</li>
</ul>');
  t('<ul>
<li>en-us (<strong>English/United States</strong>)</li>
<li>en-au (<strong>English/Australia</strong>)</li>
<li>en-ca (<strong>English/Canada</strong>)</li>
<li>en-eu (<strong>English/Europe</strong>)</li>
<li>en-in (<strong>English/India</strong>)</li>
<li>en-ln (<strong>English/Latin America</strong>)</li>
<li>en-su (<strong>English/Southeast Asia</strong>)</li>
<li>fr-eu (<strong>French/Europe</strong>)</li>
<li>fr-ca (<strong>French/Canada</strong>)</li>
<li>de-eu (<strong>German/Europe</strong>)</li>
<li>es-eu (<strong>Spanish/Europe</strong>)</li>
<li>es-ln (<strong>Spanish/Latin America</strong>)</li>
<li>pt-eu (<strong>Portuguese/Europe</strong>)</li>
<li>pt-br (<strong>Portuguese/Brazil</strong>)</li>
<li>cn-zh (<strong>Chinese/China</strong>)</li>
<li>jp-ja (<strong>Japanese/Japan</strong>)</li>
<li>ko-kr (<strong>Korean/Korea</strong>)</li>
<li>ru-ru (<strong>Russian/Russia</strong>)</li>
</ul>');
  t('Ad Tracking Code');
  t('Ads HTML');
  t('Body');
  t('Category Description 1');
  t('Category Description 2');
  t('Category Description 3');
  t('Hero Banner HTML');
  t('Homepage');
  t('Industry');
  t('Language Override');
  t('Language/Region');
  t('Role');
  t('Short description for the Product Category in box 1 (250 characters max)');
  t('Short description for the Product Category in box 2 (250 characters max)');
  t('Short description for the Product Category in box 3 (250 characters max)');
  t('Topic');

  return $field_instances;
}
