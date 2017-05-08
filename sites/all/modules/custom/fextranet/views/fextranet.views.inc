<?php
/**
 * Implements hook_views_data()
 */
function fextranet_views_data() {
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

  // TODO: Add Search Result field handler here.
  // Should be $date['TABLE NAME']['YOUR FIELD NAME HERE']
  $data['fextranet']['search_results'] = array(
    'title' => t('Extranet Search Results'),
    'help' => t('Search Results formatted specifically for the Extranet'),
    'field' => array(
      'handler' => 'fextranet_handler_field_search_results',
    ),
  );

  return $data;
}


/**
 * Implements hook_views_data_alter()
 */
function fextranet_views_data_alter(&$data) {
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

  // TODO: Add DCI Related Products handler here.
  $data['field_data_field_dam_related_product']['dci_related_products'] = array(
    'title' => t('DCI Related Products'),
    'real field' => 'field_dam_related_product_nid',
    'group' => t('Content'),
    'help'=> t('Only DCI Products'),
    'filter' => array(
      'title' => t('Filter by only DCI products.'),
      'handler' => 'fextranet_handler_filter_dci_related_products',
    ),
  );

}

function fextranet_display_views($machine_name = 'default', $display = 'default', $user = NULL) {
  $view = views_get_view($machine_name);
  $view->init();
  if (isset($user)) {
    $view->set_arguments(array($user->uid));
  }
  $view->dom_id = ''; // This is a class you can add to the result.
  $view->set_display($display);
  return $view->render();
}

function fextranet_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'fextranet') . '/views',
    ),
    'handlers' => array(
      'fextranet_handler_filter_dci_related_products' => array(
        'parent' => 'views_handler_filter_ifield_list'
      ),
      'fextranet_handler_field_search_results' => array(
        'parent' => 'views_handler_field'
      )
    )
  );
}
