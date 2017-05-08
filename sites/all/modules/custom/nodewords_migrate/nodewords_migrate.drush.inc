<?php

/**
 * Implements hook_drush_command().
 */
function nodewords_migrate_drush_command() {
  $items['nodewords-migrate'] = array(
    'description' => dt('Run nodewords migration to Metatags'),
    'arguments' => array(),
  );

  return $items;
}

/**
 * Run Nodewords Migration
 */
function drush_nodewords_migrate() {

  //Include nodewords admin inc
  module_load_include('inc', 'nodewords_migrate', 'nodewords_migrate.admin');

  nodewords_migrate_migrate();

  drush_print("Nodewords migration complete");
}