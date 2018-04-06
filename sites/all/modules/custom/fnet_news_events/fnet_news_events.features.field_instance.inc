<?php

/**
 * @file
 * fnet_news_events.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function fnet_news_events_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-award-body'.
  $field_instances['node-award-body'] = array(
    'bundle' => 'award',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-award-field_award_date'.
  $field_instances['node-award-field_award_date'] = array(
    'bundle' => 'award',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'default',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => 0,
        ),
        'type' => 'date_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'default',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => 0,
        ),
        'type' => 'date_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_award_date',
    'label' => 'Date Awarded',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-award-field_external_url'.
  $field_instances['node-award-field_external_url'] = array(
    'bundle' => 'award',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Optional external URL for linking to another site.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_external_url',
    'label' => 'External URL',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => '_blank',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-award-field_intro'.
  $field_instances['node-award-field_intro'] = array(
    'bundle' => 'award',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the introduction text here',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
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
    'field_name' => 'field_intro',
    'label' => 'Intro',
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
        'rows' => 10,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-award-field_language_region'.
  $field_instances['node-award-field_language_region'] = array(
    'bundle' => 'award',
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
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_language_region',
    'label' => 'Language/Region',
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-press_release-body'.
  $field_instances['node-press_release-body'] = array(
    'bundle' => 'press_release',
    'default_value' => NULL,
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
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
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
      'weight' => 41,
    ),
  );

  // Exported field_instance: 'node-press_release-field_language_region'.
  $field_instances['node-press_release-field_language_region'] = array(
    'bundle' => 'press_release',
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
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_language_region',
    'label' => 'Language/Region',
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
      'weight' => 44,
    ),
  );

  // Exported field_instance: 'node-press_release-field_release_date'.
  $field_instances['node-press_release-field_release_date'] = array(
    'bundle' => 'press_release',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'default',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => 0,
        ),
        'type' => 'date_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'default',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => 0,
        ),
        'type' => 'date_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_release_date',
    'label' => 'Release Date',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 42,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
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
  t('Body');
  t('Date Awarded');
  t('Enter the introduction text here');
  t('External URL');
  t('Intro');
  t('Language/Region');
  t('Optional external URL for linking to another site.');
  t('Release Date');

  return $field_instances;
}
