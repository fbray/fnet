<?php
/**
 * @file
 *
 * A Views field handler for showing the current Moderation State, even if it is not set.
 *
 * Yeah. Using an Outer Join.
 */
class site_split_field_handler_moderation_state_all extends views_handler_field {
  function construct() {
    parent::construct();
  }

  function query() {

  }

  function render($values) {
    $output = '';
    $moderation_state = 'Unmoderated';
    if (isset($values->_field_data['node_workbench_moderation_node_history_nid']['entity']->workbench_moderation)) {
      $moderation_state = $values->_field_data['node_workbench_moderation_node_history_nid']['entity']->workbench_moderation['current']->state;
    }
    /*
    if (module_exists('devel')) {
      dpm($values);
    }
    */
    return ucfirst($moderation_state);
  }
}