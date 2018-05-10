<?php

/**
 * @file
 * marketo_form.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function marketo_form_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mkt_form_content_grp|node|marketo_form|form';
  $field_group->group_name = 'group_mkt_form_content_grp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'marketo_form';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Form Contents',
    'weight' => '7',
    'children' => array(
      0 => 'field_image',
      1 => 'field_banner_html',
      2 => 'field_remove_nav',
      3 => 'field_left_content',
      4 => 'field_export_control',
      5 => 'field_enable_share_buttons',
      6 => 'field_display_footer',
      7 => 'field_form_bottom',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-mkt-form-content-grp field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_mkt_form_content_grp|node|marketo_form|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mkt_frm_info_grp|node|marketo_form|form';
  $field_group->group_name = 'group_mkt_frm_info_grp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'marketo_form';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Marketo IFRAME Configuration (This entire section default to "Do Not Translate")',
    'weight' => '8',
    'children' => array(
      0 => 'field_mkt_frm_default_lang',
      1 => 'field_marketo_form_title',
      2 => 'field_iframe_height',
      3 => 'field_iframe_url_en_in',
      4 => 'field_iframe_url_en_eu',
      5 => 'field_iframe_url_en',
      6 => 'field_iframe_url_fr',
      7 => 'field_iframe_url_de',
      8 => 'field_iframe_url_cn',
      9 => 'field_iframe_url_jp',
      10 => 'field_iframe_url_ko',
      11 => 'field_iframe_url_pt',
      12 => 'field_iframe_url_ru',
      13 => 'field_bottom_content_en',
      14 => 'field_bottom_content_en_eu',
      15 => 'field_bottom_content_en_in',
      16 => 'field_bottom_content_cn',
      17 => 'field_bottom_content_fr',
      18 => 'field_bottom_content_de',
      19 => 'field_bottom_content_jp',
      20 => 'field_bottom_content_ko',
      21 => 'field_bottom_content_pt',
      22 => 'field_bottom_content_ru',
      23 => 'field_bottom_content_es',
      24 => 'field_iframe_url_es',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-mkt-frm-info-grp field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_mkt_frm_info_grp|node|marketo_form|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Form Contents');
  t('Marketo IFRAME Configuration (This entire section default to "Do Not Translate")');

  return $field_groups;
}
