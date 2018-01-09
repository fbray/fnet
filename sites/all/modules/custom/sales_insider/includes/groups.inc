<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 1/8/18
 * Time: 2:13 PM
 */

/**
 * Helper function to save the Sales Insider group types.
 */
function _sales_insider_group_type_entities() {
  // Get the group type definitions
  $group_types = _sales_insider_get_group_type_entities();
  $info = entity_load_multiple_by_name('group_type', array_keys($group_types));
  // Save them!
  foreach ($group_types as $name => $group_type) {
    if (!isset($info[$name])) {
      entity_save('group_type', $group_type);
    }
  }
}

/**
 * Helper function for defining \Sales Insider group types.
 *
 * @return array
 */
function _sales_insider_get_group_type_entities() {
  $types = array();
  // Sales Insider Region
  $types['sales_insider_region'] = entity_import('group_type', '{
  "name" : "sales_insider_region",
  "label" : "Sales Insider Region",
  "anonymous_permissions" : [],
  "outsider_permissions" : [],
  "member_permissions" : [
    "view extranet_news node",
    "view extranet_page node",
    "view extranet_promotion node"
  ],
  "config" : { 
    "subgroup" : { 
      "sales_insider_subgroup" : {
        "member" : {
          "member" : "member",
          "content_author" : 0,
          "region_owner" : 0,
          "group_admin" : 0
        },
        "content_author" : {
          "content_author" : "content_author",
          "member" : 0,
          "region_owner" : 0,
          "group_admin" : 0
        },
        "region_owner" : {
          "region_owner" : "region_owner",
          "member" : 0,
          "content_author" : 0,
          "group_admin" : 0
        },
        "group_admin" : {
          "group_admin" : "group_admin",
          "member" : 0,
          "content_author" : 0,
          "region_owner" : 0
        }
      }
    }
  },
  "weight" : "-10",
  "rdf_mapping" : [],
  "roles" : [] }');

  // Sales Insider Subgroup
  $types['sales_insider_subgroup'] = entity_import('group_type', '{
  "name" : "sales_insider_subgroup",
  "label" : "Sales Insider Subgroup",
  "anonymous_permissions" : [],
  "outsider_permissions" : [],
  "member_permissions" : [
    "view digital_asset node",
    "view extranet_news node",
    "view extranet_page node",
    "view extranet_promotion node"
  ],
  "config" : [],
  "weight" : "-5",
  "rdf_mapping" : [],
  "roles" : [] }');
  return $types;
}

/**
 * Helper function for Sales Insider default groups.
 *
 * @return array
 */
function _sales_insider_get_group_entities() {
  $groups = [
    'sales_insider_region' => [
      'Asia-Pacific',
      'EMEA',
      'Latin America',
      'North America'
    ],
    'sales_insider_subgroup' => [
      'Asia-Pacific Channel Partners',
      'Asia-Pacific Channel Partners China',
      'Asia-Pacific Internal Employees',
      'EMEA Distributors',
      'EMEA Internal Employees',
      'Latin America Channel Partners',
      'Latin America Internal Employees',
      'North America Distribution Partner Marketing',
      'North America Distribution Representatives',
      'North America Internal Sales & Marketing',
    ],
  ];
  return $groups;
}

/**
 * Helper function to create the individual groups.
 */
function _sales_insider_group_entities() {
  $groups = _sales_insider_get_group_entities();
  foreach ($groups as $type => $group) {
    if (!group_load_by_type($type)) {
      foreach($group as $name) {
        $values = [
          'type' => $type,
          'title' => $name,
        ];
      }
      $new_group = entity_create('group', $values);
      entity_save('group', $new_group);
      drupal_set_message('Created group ' . $name);
    }
  }
}

