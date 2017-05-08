<?php
// $Id$


/**
 * @file
 * Object wrapper for database access
 *
 */
class DatabaseRecord {

  private $db_record_exists;
  protected $table;
  private $key_field;

  public function __construct($key = NULL) {
    $this->get_key();
    if (is_null($key)) {
      return;
    }
    $this->read($key);
  }

  public function read($key) {
    $query = db_select($this->table, 't')
      ->condition($this->key_field, $key)
      ->fields('t');
    $result = $query->execute()->fetchAssoc();
    if ($result) {
      $this->db_record_exists = TRUE;
      foreach ($result as $key => $value) {
        $this->$key = $value;
      }
    }
    else {
      $this->db_record_exists = FALSE;
    }
  }

  public function write() {
    $key_field = $this->key_field;
    if (empty($this->$key_field)) {
      throw new Exception('Key field cannot be blank or null');
    }
    if (is_null($this->db_record_exists)) {
      $query = db_select($this->table, 't')
        ->condition($this->key_field, $this->$key_field)
        ->addExpression('COUNT(*)');
      $count = $query->execute()->fetchCol();
      if ($count == 1) {
        $this->db_record_exists = TRUE;
      }
      else {
        $this->db_record_exists = FALSE;
      }
    }
    if ($this->db_record_exists) {
      $result = drupal_write_record($this->table, $this, array($this->key_field));
    }
    else {
      $result = drupal_write_record($this->table, $this);
      $this->db_record_exists = ($result == SAVED_NEW);
    }
    return $result;
  }

  private function get_key() {
    $sql = "DESCRIBE $this->table";
    $result = db_query($sql);
    foreach ($result as $row) {
      if ($row->Key == 'PRI') {
        $this->key_field = $row->Field;
      }
    }
  }
}