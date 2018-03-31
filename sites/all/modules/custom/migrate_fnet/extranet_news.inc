<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/22/17
 * Time: 10:51 AM
 */
/*
 *  Extranet News Migration Class
*/
class FNETExtranetNewsMigration extends FNETNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Path Alias
    $this->addFieldMapping('path', 'path');

    // Disable Pathauto for now.
    $this->addFieldMapping('pathauto')->defaultValue(0);

    // Redirects
    $this->addFieldMapping('migrate_redirects', 'path');

    // Individual Fields
    $this->addFieldMapping('field_display_title', 'field_display_title');
    $this->addFieldMapping('field_display_title:language', 'field_display_title:language');
    $this->addFieldMapping('body:language', 'body:language');
  }

  /**
   * Implementation of prepareRow()
   *
   * @param $row
   * @return bool
   */
  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $row->body = $this->stripDomain($row->body);
    $row->body = str_ireplace('/flukenetworks.com/files', '/default/files', $row->body);
    $row->body = str_ireplace('/flukenetworks.com/theme', '/all/theme', $row->body);
  }

  /**
   * Remove the hard-coded Fluke Networks domain from a field.
   *
   * @param $string
   * @return mixed
   */
  protected function stripDomain($string) {
    $domains = ['http://www.flukenetworks.com/', 'https://www.flukenetworks.com/', 'http://flukenetworks.com/', 'https://flukenetworks.com/'];
    $stripped = str_ireplace($domains, '/', $string);
    return $stripped;
  }

  /**
   * Code to add imported Extranet News articles to their respective groups.
   *
   * @param $node
   * @param \stdClass $row
   */
  public function complete($node, stdClass $row) {
    // $node is the new, $row is the old.

    // Get the old gids using the old entity id.
    $old_groups = [];
    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('groups', 'g')
      ->fields('g', array('Title' => 'title'));
    $query->join('group_entity', 'ge', 'ge.gid = g.gid');
    $query->condition('ge.entity_id', $row->nid, '=');
    $results = $query->execute();
    foreach ($results as $result) {
      $old_groups[] = $result->title;
    }

    // Match the names of the groups to get the new gid.
    $gid_query = Database::getConnection('default', 'default')
      ->select('groups', 'g')
      ->fields('g', array('gid' => 'gid'))
      ->condition('title', $old_groups, 'IN');
    $gid_results = $gid_query->execute();
    // $gid_results = db_query('SELECT gid FROM {groups} WHERE title IN :title', array(':title' => $old_groups));

    // Insert the new gid, new entity id, entity type 'node', bundle 'extranet_page' into the group_entity table.
    foreach($gid_results as $gid_result) {
      try {
        db_insert('group_entity')
          ->fields(array(
            'gid' => $gid_result->gid,
            'entity_id' => $node->nid,
            'entity_type' => 'node',
            'bundle' => 'extranet_news'
          ))->execute();
      }
      catch (Exception $e) {
        watchdog('migrate_fnet', $e->getMessage());
      }
    }
    return parent::complete($node, $row);
  }

  /**
   * Code to execute after an entity has been rolled back.
   *
   * @param $entity_ids
   */
  public function completeRollback($entity_ids) {
    db_delete('group_entity')
      ->condition('entity_id', $entity_ids, 'IN')
      ->execute();
  }
}