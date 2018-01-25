<?php
/**
 * @file
 * Implementation of DrupalNodeMigration for Drupal 7 sources.
 */


class DrupalGroupMembership7Migration extends DrupalGroupMembershipMigration {

  public function __construct(array $arguments) {
    parent::__construct($arguments);

    $this->source = new MigrateSourceSQL($this->query(), $this->sourceFields, NULL,
      $this->sourceOptions);
  }

  /**
   * Query for basic node fields from Drupal 7.
   *
   * @return QueryConditionInterface
   */
  protected function query() {
    $query = Database::getConnection('default', $this->sourceConnection)
      ->select('group_membership', 'gm')
      ->fields('gm', array(
        'mid',
        'gid',
        'uid',
        'status',
        'blocked_status',
        'blocked_on',
        'blocked_by',
        'joined_on',
        'requested_on',
        'approved_on',
        'added_on',
        'parent_mid',
        'heritage',
      ))
      ->fields('g', array('Title' => 'title'));
      $query->join('groups', 'g', 'g.gid = gm.gid');
    return $query;
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }



  }
}