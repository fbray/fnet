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
class FNETExtranetNewsMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.

    // Individual Fields
    $this->addFieldMapping('field_display_title', 'field_display_title');
  }
}