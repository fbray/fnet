<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 8/9/17
 * Time: 5:11 PM
 */

/*
 *  Asia-Pacific Group Migration Class
*/
class APACGroupMigration extends DrupalGroup7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Redirects
    $this->addFieldMapping('migrate_redirects', 'path');

    $this->addFieldMapping('field_extranet_group_countries', 'field_extranet_group_countries');

  }
}