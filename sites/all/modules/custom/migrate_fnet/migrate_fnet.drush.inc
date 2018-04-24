<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 3/31/18
 * Time: 11:47 AM
 */

/**
 * Thanks for Francine Bray (francine.bray@flukenetworks.com) for the example
 * code that I so shamelessly stole from to make this work.
 *
 * - Ryan Ositis (ryan.ositis@flukenetworks.com)
 */

/**
 * Implements hook_drush_command().
 */
function migrate_fnet_drush_command() {

  $items['clear-highwater'] = [
    'description' => 'Rerun the Fluke Networks migration import.',
    'aliases' => ['chw'],
  ];

  return $items;
}

/**
 * Callback for migration drush command.
 *
 * Manually update database table. migrate_status, setting highwater to
 * 0 so that rerunning the migration will import referenced entities.
 */
function drush_migrate_fnet_clear_highwater() {
  // Set highwater field to 0 on table migrate_status.
  $types = [
    'ProductDisplay',
  ];

  db_update('migrate_status')
    ->fields(['highwater' => 0])
    ->isNotNull('highwater')
    ->condition('machine_name', $types, 'IN')
    ->execute();
}