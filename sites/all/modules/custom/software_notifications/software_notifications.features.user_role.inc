<?php
/**
 * @file
 * software_notifications.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function software_notifications_user_default_roles() {
  $roles = array();

  // Exported role: software notifications author.
  $roles['software notifications author'] = array(
    'name' => 'software notifications author',
    'weight' => 0,
  );

  return $roles;
}
