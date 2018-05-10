<?php

/**
 * @file
 * homepage.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function homepage_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_home13_banner_grp|node|homepage2013|form';
  $field_group->group_name = 'group_home13_banner_grp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage2013';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Homepage Hero Banner',
    'weight' => '10',
    'children' => array(
      0 => 'field_home13_banner_html',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-home13-banner-grp field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_home13_banner_grp|node|homepage2013|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_home13_ind_grp|node|homepage2013|form';
  $field_group->group_name = 'group_home13_ind_grp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage2013';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Expertise Industry',
    'weight' => '13',
    'children' => array(
      0 => 'field_home13_expind',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-home13-ind-grp field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_home13_ind_grp|node|homepage2013|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_home13_product_group|node|homepage2013|form';
  $field_group->group_name = 'group_home13_product_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage2013';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Homepage Product Category Description',
    'weight' => '15',
    'children' => array(
      0 => 'field_category_description_1',
      1 => 'field_category_description_2',
      2 => 'field_category_description_3',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-home13-product-group field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_home13_product_group|node|homepage2013|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_home13_rle_grp|node|homepage2013|form';
  $field_group->group_name = 'group_home13_rle_grp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage2013';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Expertise Role',
    'weight' => '12',
    'children' => array(
      0 => 'field_home13_exprle',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-home13-rle-grp field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_home13_rle_grp|node|homepage2013|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_home13_rnd_ads_grp|node|homepage2013|form';
  $field_group->group_name = 'group_home13_rnd_ads_grp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage2013';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Random Ads Box',
    'weight' => '14',
    'children' => array(
      0 => 'field_home13_ads',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-home13-rnd-ads-grp field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_home13_rnd_ads_grp|node|homepage2013|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_home13_tpc_grp|node|homepage2013|form';
  $field_group->group_name = 'group_home13_tpc_grp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage2013';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Expertise Topic',
    'weight' => '11',
    'children' => array(
      0 => 'field_home13_exptpc',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-home13-tpc-grp field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_home13_tpc_grp|node|homepage2013|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_home13lng_ind_desc_grp|node|homepage2013_language|form';
  $field_group->group_name = 'group_home13lng_ind_desc_grp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'homepage2013_language';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Homepage Category Description',
    'weight' => '17',
    'children' => array(
      0 => 'field_category_description_1',
      1 => 'field_category_description_2',
      2 => 'field_category_description_3',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Homepage Category Description',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-home13lng-ind-desc-grp field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_home13lng_ind_desc_grp|node|homepage2013_language|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Expertise Industry');
  t('Expertise Role');
  t('Expertise Topic');
  t('Homepage Category Description');
  t('Homepage Hero Banner');
  t('Homepage Product Category Description');
  t('Random Ads Box');

  return $field_groups;
}
