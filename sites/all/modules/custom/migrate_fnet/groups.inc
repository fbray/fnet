<?php
/**
 * @file
 * Implementation of DrupalNodeMigration for Drupal 7 sources.
 */

/**
 * Handling specific to a Drupal 7 source for groups.
 */
class DrupalGroup7Migration extends DrupalGroupMigration {

  /**
   * @param array $arguments
   */
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
      ->select('groups', 'g')
      ->fields('g', array('gid', 'type', 'title'))
      ->condition('g.type', $this->sourceType);
    return $query;
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

  }
}

