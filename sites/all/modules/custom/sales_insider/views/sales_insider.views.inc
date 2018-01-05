<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 1/4/18
 * Time: 2:51 PM
 */

/**
 * Implements hook_views_data()
 */
function sales_insider_views_data() {
  $data = array();

  $data['group_entity']['table']['group'] = t('Group Entity Ownership');
  $data['group_entity']['table']['base'] = array(
    'field' => 'gid',
    'title' => t('Group ID'),
    'help' => t('Group / NID mapping'),
    'weight' => -10,
  );

  $data['group_entity']['table']['join'] = array(
    'node' => array(
      'left_field' => 'entity_id',
      'field' => 'nid',
    ),
  );

  $data['group_entity']['table']['join'] = array(
    'group' => array(
      'left_field' => 'gid',
      'field' => 'gid',
    ),
  );

  $data['group_entity']['entity_id'] = array(
    'title' => t('Node Owner'),
    'help' => t(' content that references a node.'),
    'relationship' => array(
      'base' => 'node', // The name of the table to join with.
      'base field' => 'nid', // The name of the field on the joined table.
      'handler' => 'views_handler_relationship',
      'label' => t('Node. Default label for the relationship'),
      'title' => t('Node. Title shown when adding the relationship'),
      'help' => t('Node. More information on this relationship'),
    ),
  );

  $data['group_entity']['gid'] = array(
    'title' => t('Group group'),
    'help' => t(' Group mapping.'),
    // Define a relationship to the {node} table, so example_table views can
    // add a relationship to nodes. If you want to define a relationship the
    // other direction, use hook_views_data_alter(), or use the 'implicit' join
    // method described above.
    'relationship' => array(
      'base' => 'group', // The name of the table to join with.
      'base field' => 'gid', // The name of the field on the joined table.
      'handler' => 'views_handler_relationship',
      'label' => t('Group to Group Entity label'),
      'title' => t('Group to Group Entity title'),
      'help' => t('Group to Group Entity help'),
    ),
  );


  // Should be $date['TABLE NAME']['YOUR FIELD NAME HERE']
  $data['sales_insider']['search_results'] = array(
    'title' => t('Extranet Search Results'),
    'help' => t('Search Results formatted specifically for the Extranet'),
    'field' => array(
      'handler' => 'sales_insider_handler_field_search_results',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_data_alter()
 */
function sales_insider_views_data_alter(&$data) {
  $data['group_membership_role']['table']['join'] = array(
    'group_role' => array(
      'left_field' => 'role',
      'field' => 'name',
    ),
  );

  $data['group_membership_role']['role'] = array(
    'title' => t('GMR group role map'),
    'help' => t(' Group Membership Role map'),

    'relationship' => array(
      'base' => 'group_role', // The name of the table to join with.
      'base field' => 'name', // The name of the field on the joined table.
      'handler' => 'views_handler_relationship',
      'label' => t('Title GMR RM map'),
      'title' => t('GMR RM map. Title '),
      'help' => t('GMR RM map'),
    ),
  );
}
