<?php
/**
 * @file
 * microsite_page_fix.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function microsite_page_fix_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'node-microsite_page-field_ms_page_language_override'
  $field_instances['node-microsite_page-field_ms_page_language_override'] = array(
    'bundle' => 'microsite_page',
    'default_value' => array(
      0 => array(
        'nid' => NULL,
      ),
    ),
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
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
      'full' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
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
    'field_name' => 'field_ms_page_language_override',
    'label' => 'Language Override',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'weight' => 1,
    'widget' => array(
      'active' => 0,
      'module' => 'options',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'default_value_php' => NULL,
        'size' => 60,
      ),
      'type' => 'options_buttons',
      'weight' => 7,
    ),
    'widget_type' => 'nodereference_buttons',
  );

  return $field_instances;

}
