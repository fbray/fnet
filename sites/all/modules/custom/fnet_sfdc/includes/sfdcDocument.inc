<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 3/20/18
 * Time: 2:56 PM
 */
class sfdcDocument {

  public function __construct($table = NULL) {
    $this->NewDataSet = new stdClass();
    if (isset($table)) {
      $this->NewDataSet->Table = $table;
    }
    else {
      $this->NewDataSet->Table = '';
    }
  }
}