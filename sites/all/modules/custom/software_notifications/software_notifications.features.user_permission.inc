<?php
/**
 * @file
 * software_notifications.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function software_notifications_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'create software_notifications content'.
  $permissions['create software_notifications content'] = array(
    'name' => 'create software_notifications content',
    'roles' => array(
      'administrator' => 'administrator',
      'software notifications author' => 'software notifications author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any software_notifications content'.
  $permissions['delete any software_notifications content'] = array(
    'name' => 'delete any software_notifications content',
    'roles' => array(
      'administrator' => 'administrator',
      'software notifications author' => 'software notifications author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own software_notifications content'.
  $permissions['delete own software_notifications content'] = array(
    'name' => 'delete own software_notifications content',
    'roles' => array(
      'administrator' => 'administrator',
      'software notifications author' => 'software notifications author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any software_notifications content'.
  $permissions['edit any software_notifications content'] = array(
    'name' => 'edit any software_notifications content',
    'roles' => array(
      'administrator' => 'administrator',
      'software notifications author' => 'software notifications author',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own software_notifications content'.
  $permissions['edit own software_notifications content'] = array(
    'name' => 'edit own software_notifications content',
    'roles' => array(
      'administrator' => 'administrator',
      'software notifications author' => 'software notifications author',
    ),
    'module' => 'node',
  );

  return $permissions;
}
