<?php

/*
 *  Files Migration Class
*/
class FNETFileMigration extends DrupalFile7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    // $this->addFieldMapping('destination_file', 'filename');
  }
}