<?php

/*
 *  Files Migration Class
*/
class FNETFileMigration extends DrupalFile7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    // $this->addFieldMapping('destination_file', 'filename');
  }

  public function prepareRow($row) {
    // TODO: Test this.
    // $row->filename = $stripped = str_ireplace('.js.txt', '.js', $row->filename);
  }
}