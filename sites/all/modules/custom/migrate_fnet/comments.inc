<?php

/*
 *  Comments Migration Class
*/
class PlayOn6CommentMigration extends DrupalComment6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }
  public function sourceFieldList() {
    $fields = parent::sourceFieldList();
    return $fields;
  }
}

