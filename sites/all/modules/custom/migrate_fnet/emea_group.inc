<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 8/17/17
 * Time: 5:00 PM
 */

/*
 *  Europe/Middle East Group Migration Class
*/
class EMEAGroupMigration extends DrupalGroup7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    $this->addFieldMapping('field_extranet_group_countries', 'field_extranet_group_countries');

  }
}