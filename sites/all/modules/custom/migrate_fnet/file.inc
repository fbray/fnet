<?php

/*
 *  Files Migration Class
*/
class PlayOn6FileMigration extends DrupalFile6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
    // $this->addFieldMapping('destination_file', 'filename');
  }
}