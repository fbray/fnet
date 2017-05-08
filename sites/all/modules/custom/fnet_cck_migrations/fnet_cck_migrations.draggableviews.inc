<?php
// $Id$

/**
 * @file
 * migrate draggable views structure table
 *
 */

function fnet_cck_migrations_draggable_views() {
  //rename the old table
  if (db_table_exists('draggableviews_structure')) {
    db_drop_table('draggableviews_structure');
  }
  db_create_table('draggableviews_structure', fnet_cck_migrations_draggable_views_schema());
  try {
    $query = db_select('draggableviews_structure_d6', 'd6dv')
      ->fields('d6dv', array('view_name', 'nid', 'delta', 'args', 'value',))
      ->orderBy('view_name')
      ->orderBy('nid')
      ->execute();
  } catch (Exception $e) {
    drupal_set_message($e->getMessage(), 'error');
  }
  foreach ($query as $row) {
    $view_name = $row->view_name;
    $view_display = 'page_1';
    $entity_id = $row->nid;
    $parent = 0;
    $weight = $row->value;
    $args = '';
    if (!empty($row->args)) {
      $arguments = explode('/', $row->args);
      $args = '';
      foreach ($arguments as $argument) {
        $args .= '"' . $argument . '",';
      }
    }
    $args = '[' . trim($args, ',') . ']';
    try {
      db_insert('draggableviews_structure')->fields(array(
          'view_name',
          'view_display',
          'entity_id',
          'parent',
          'args',
          'weight'
        ), array(
            $view_name,
            $view_display,
            $entity_id,
            $parent,
            $args,
            $weight
          ))->execute();
    } catch (Exception $e) {
      drupal_set_message($e->getMessage(), 'error');
    }
  }
  db_drop_table('draggableviews_structure_d6');
  drupal_set_message('Done.');
}


function fnet_cck_migrations_draggable_views_schema() {
  $schema = array(
    'description' => 'The table saves the order settings of an draggableview.',
    'fields' => array(
      'dvid' => array(
        'description' => 'The primary identifier.',
        'type' => 'serial',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
      'view_name' => array(
        'description' => 'Makes the order unique for each view.',
        'type' => 'varchar',
        'length' => 128,
        'not null' => TRUE,
        'default' => '',
      ),
      'view_display' => array(
        'description' => 'Makes the order unique for each view display.',
        'type' => 'varchar',
        'length' => 64,
        'not null' => TRUE,
        'default' => '',
      ),
      'args' => array(
        'description' => 'Makes the order unique for a given set of arguments',
        'type' => 'varchar',
        'length' => 255,
        'not null' => FALSE,
        'default' => '',
      ),
      'entity_id' => array(
        'description' => 'Id of the entity that we are sorting (node, user, etc.).',
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
      'weight' => array(
        'description' => 'The order weight.',
        'type' => 'int',
        'unsigned' => FALSE,
        'not null' => TRUE,
        'default' => 0,
      ),
      'parent' => array(
        'description' => 'The order parent.',
        'type' => 'int',
        'unsigned' => FALSE,
        'not null' => TRUE,
        'default' => 0,
      ),
    ),
    'indexes' => array(
      'view' => array('view_name', 'view_display', 'args', 'entity_id'),
      'weight' => array('weight'),
      'entity_id' => array('entity_id'),
    ),
    'primary key' => array('dvid'),
  );
  return $schema;

}