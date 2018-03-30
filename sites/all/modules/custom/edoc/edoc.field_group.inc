<?php

/**
 * @file
 * edoc.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function edoc_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_edoc_doc_group|node|edoc|form';
  $field_group->group_name = 'group_edoc_doc_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'edoc';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Document',
    'weight' => '14',
    'children' => array(
      0 => 'field_literature_id_en',
      1 => 'field_literature_id_fr',
      2 => 'field_literature_id_cn',
      3 => 'field_literature_id_jp',
      4 => 'field_literature_id_de',
      5 => 'field_literature_id_ko',
      6 => 'field_literature_id_ru',
      7 => 'field_literature_id_pt',
      8 => 'field_literature_id_es',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-edoc-doc-group field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_edoc_doc_group|node|edoc|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Document');

  return $field_groups;
}
