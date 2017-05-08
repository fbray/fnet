<?php
/**
 * @file
 * software_notifications.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function software_notifications_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: management_software-notifications:admin/content/software-notifications
  $menu_links['management_software-notifications:admin/content/software-notifications'] = array(
    'menu_name' => 'management',
    'link_path' => 'admin/content/software-notifications',
    'router_path' => 'admin/content/software-notifications',
    'link_title' => 'Software Notifications',
    'options' => array(
      'identifier' => 'management_software-notifications:admin/content/software-notifications',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'parent_identifier' => 'management_content:admin/content',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Software Notifications');


  return $menu_links;
}
