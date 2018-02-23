<?php
/**
 * @file
 * fnet_marketo_form.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function fnet_marketo_form_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fnet_mkto_form_cnts|node|fnet_marketo_form|form';
  $field_group->group_name = 'group_fnet_mkto_form_cnts';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'fnet_marketo_form';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Form Contents',
    'weight' => '2',
    'children' => array(
      0 => 'field_fnet_mkto_banner_img',
      1 => 'field_fnet_mkto_banner_html',
      2 => 'field_fnet_mkto_prod_img_left',
      3 => 'field_fnet_mkto_form_prdimg_llnk',
      4 => 'field_fnet_mkto_prod_img_right',
      5 => 'field_fnet_mkto_form_prdimg_rlnk',
      6 => 'field_fnet_mkto_main_content',
      7 => 'field_fnet_mkto_export_ctrl',
      8 => 'field_fnet_mkto_title',
      9 => 'field_fnet_mkto_add_links',
      10 => 'field_fnet_mkto_form_btm_html',
      11 => 'field_fnet_mkto_form_number',
      12 => 'field_fnet_mkto_form_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-fnet-mkto-form-cnts field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_fnet_mkto_form_cnts|node|fnet_marketo_form|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Form Contents');

  return $field_groups;
}
