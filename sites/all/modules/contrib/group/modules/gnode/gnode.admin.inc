<?php

/**
 * @file
 * Contains all admin functions for the Group Node module.
 */

/**
 * Menu settings callback.
 *
 * @see gnode_menu().
 */
function gnode_settings($form, &$form_state) {

  $form['gnode_group_choice_admin_element'] = array(
    '#type' => 'radios',
    '#title' => t('Admin group selection mode'),
    '#default_value' => variable_get('gnode_group_choice_admin_element', 'auto_complete'),
    '#description' => t('Choose the type of form element administrators use to select which groups a node should be in.'),
    '#options' => array(
      'select' => t('Select dropdown  '),
      'auto_complete' => t('Auto complete'),
      'checkbox' => t('Checkboxes or radios'),
    ),
  );

  $form['gnode_group_choice_standard_element'] = array(
    '#type' => 'radios',
    '#title' => t('Standard user group selection mode'),
    '#default_value' => variable_get('gnode_group_choice_standard_element', 'select'),
    '#description' => t('Choose the type of form element standard users use to select which groups a node should be in.'),
    '#options' => array(
      'select' => t('Select dropdown'),
      'auto_complete' => t('Auto complete'),
      'checkbox' => t('Checkboxes or radios'),
    ),
  );

  $form['group_node_multiple_groups'] = array(
    '#type' => 'radios',
    '#title' => t('Nodes in multiple groups'),
    '#default_value' => variable_get('group_node_multiple_groups', GROUP_NODE_SINGLE_GROUPS_MODE),
    '#description' => t('Choose if a node can only be in one group or can be in multiple groups. Nodes in multiple groups can be updated and deleted by users with the necessary permissions in any of the groups it is in. After changing this session you must clear the site cache. It is not recommended that you go from multiple to single on a site which has nodes in multiple groups without testing.'),
    '#options' => array(
      GROUP_NODE_SINGLE_GROUPS_MODE => t('A node can only be in a single group.'),
      GROUP_NODE_MULTIPLE_GROUPS_MODE => t('A node can be placed into multiple groups.'),
    ),
  );

  $form['group_node_mode'] = array(
    '#type' => 'radios',
    '#title' => t('Group node access mode'),
    '#default_value' => _gnode_get_mode(),
    '#description' => t('In safe mode, access to nodes within a Group is controlled by the Group module alone. In compliance mode, other Drupal modules may allow access to nodes within a Group which permissions within the Group may have not allowed. If this setting is changed then you will be prompted to rebuild node access permissions.'),
    '#options' => array(
      GROUP_NODE_SAFE_MODE => t('Safe mode'),
      GROUP_NODE_COMPLIANCE_MODE => t('Compliance mode'),
    ),
  );

  $form['#submit'][] = 'gnode_settings_form_submit';

  return system_settings_form($form);
}

/**
 * Form submission handler.
 *
 * @see gnode_settings().
 */
function gnode_settings_form_submit(&$form, &$form_submit) {
  $selected_group_mode = $form_submit['values']['group_node_mode'];

  // If the access mode has changed then node access needs rebuilding.
  if ($selected_group_mode !== _gnode_get_mode()) {
    node_access_needs_rebuild(TRUE);
  }

  $selected_multiple_mode = $form_submit['values']['group_node_multiple_groups'];

  if ($selected_multiple_mode !== variable_get('group_node_multiple_groups', GROUP_NODE_SINGLE_GROUPS_MODE)) {
    drupal_set_message(t('The site cache should be cleared now because the nodes in multiple groups setting has changed. !link', array(
      '!link' => l(t('Go to performance settings'), 'admin/config/development/performance'),
      )), 'warning');
  }
}

