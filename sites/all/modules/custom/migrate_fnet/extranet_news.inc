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
    // Redirects
    $this->addFieldMapping('migrate_redirects', 'path');

    // Individual Fields
    $this->addFieldMapping('field_display_title', 'field_display_title');
  }

  /**
   * @return \QueryConditionInterface
   */
  protected function query() {
    $query = parent::query();

    // Join the Groups Membership table
    $query->leftJoin('group_entity', 'ge', 'ge.entity_id = n.nid');
    $query->fields('ge', array(
      'gid',
      'entity_id',
      'entity_type',
      'bundle'
    ));

    return $query;
  }
}