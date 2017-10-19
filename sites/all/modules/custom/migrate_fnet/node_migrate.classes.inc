<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 10/5/17
 * Time: 8:36 AM
 */

class FNETNode7Migration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }

  public function generateNodeRedirect($node, $row) {
    // get a list of existing redirects for this particular row.
    // try the knowledgebase format, e.g 'http://www.flukenetworks.com/knowledge-base?nid=YOURNIDHERE&tid=375'
    $kb_format = 'http://www.flukenetworks.com/knowledge-base?nid=' . $row->nid . '&tid=375';
    // Make sure this is done on the legacy database.
    db_set_active('legacy');
    $query = db_select('redirect', 'r');
    $query->fields('r', array( 'hash', 'source', 'source_options', 'redirect_options', 'language'));
    // filter by count. If the count is less than X, don't bother. Deprecate it.
    // $query->condition('count', 10, '>');
    // filter by status
    // $query->condition('status', 1, '=');
    // filter by access date
    $one_year_ago = strtotime('-1 year');
    // $query->condition('access', $one_year_ago, '>');
    $query->condition(db_or()
      ->condition('redirect', 'node/' . $row->nid, '=')
      // ->condition('redirect', $kb_format, '=')
    );
    $query->execute()->fetchAll();
    // Return to using the default database;
    dpr($query);
    db_set_active();


    // for each redirect, create an redirect object.
/*
    foreach($query as $existing) {
      // print_r($existing); // Look at the row to see where to get the source.
      // Create an object with our redirect parameters

      $redirect = new stdClass();
      redirect_object_prepare($redirect);
      $redirect->source = $existing->source;
      $redirect->source_options = array();
      $redirect->redirect = 'node/' . $node->nid; // New system path
      $redirect->redirect_options = array();
      $redirect->type = 'redirect';
      $redirect->language = $existing->language;

      $alias = db_query('SELECT alias FROM {url_alias} WHERE source = :src_path', array(':src_path' => 'node/'. $node->nid))->fetchField();

      // Create the redirect, if it does not exist already
      if ($alias && $alias != $redirect->source) {
        redirect_save($redirect);
      }
    }
*/
  }

  public function generateGroupNodeRelationship($node, $row) {
    db_set_active('legacy');
    $query = $query = db_select('group_entity', 'ge');
    $query->fields('ge', array( 'gid', 'entity_id', 'entity_type', 'bundle'));
    $query->condition('entity_id', $row->nid, '=');
    $query->execute();
    db_set_active();

    foreach($query as $gnode) {
      // insert the record into the group entity table.
      // It's not an entity, unfortunately, so direct insert may be required.

    }

  }
}