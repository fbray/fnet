<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 10/24/17
 * Time: 12:55 PM
 */

/*
 * @file
 *
 * A Views filter handler for showing only promotions in the language specified
 * in the Region/Language field (field_language_region).
 *
 * TODO: Yes, this is a language hack. This should be moved to using Entity Translation in the future. -rositis
 */
class promotions_handler_filter_reglang extends views_handler_filter_equality {
  function construct() {
    parent::construct();

  }

  function get_value_options() {
    // Override the input form.
  }

  function query() {
    $table = 'field_data_field_language_region';
    $left_table = $this->table;
    $left_field = 'nid';
    $field = 'entity_id';
    $extra = $table . '.'.'revision_id = ' . $left_table . '.' . 'vid';

    // TODO: Multiple join?
    $join = new views_join();
    $join->construct($table, $left_table, $left_field, $field, array($extra), 'LEFT');
    $alias = 'field_data_field_language_region';
    $alias = $this->query->add_relationship($alias, $join, $this->table_alias, $this->relationship);

    // If regLang = field_language_region_value
    // field_language_region expected value is in format of en-ca
    $siteReg = module_invoke('fnet_helper', 'site_region');
    $regLang = $siteReg["regLang"];
    $utter_field = $table . '.' . 'field_language_region_value';
    $this->query->add_where(0, $utter_field, $regLang);
    $this->ensure_my_table();
  }

}