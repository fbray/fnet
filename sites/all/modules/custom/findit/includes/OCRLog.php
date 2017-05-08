<?php
// $Id$

/**
 * @file
 * OCR export compliance log of denied requests
 *
 */
class OCRLog {

  private $db_row;

  public $oid;
  public $uid;
  public $locale;
  public $document_id;
  public $date_created;
  public $date_updated;
  public $entity_name;
  public $entity_type;
  public $ocr_status;
  public $ocr_dpl_date;
  public $ocr_key;
  public $email_sent;
  protected $ocr_check_count;

  public function  __construct($uid = NULL, $entity_type = NULL) {
    if ($uid) {
      $this->read($uid, $entity_type);
    }
  }

  public function write() {
    $query = db_select('ocr_log', 'l')
      ->fields('l')
      ->condition('uid', $this->uid)
      ->condition('entity_type', $this->entity_type);
    $result = $query->execute()->fetchAssoc();
    if ($result) {
      $row = (object) $result;
      $this->db_row = $row;
      $this->update();
    }
    else {
      $this->db_row = new stdClass();
      $this->insert();
    }
  }

  private function insert() {
    $this->db_row->uid = $this->uid;
    $this->db_row->locale = $this->locale;
    $this->db_row->document_id = $this->document_id;
    $this->db_row->date_created = $this->db_row->date_updated = time();
    $this->db_row->entity_name = substr($this->entity_name, 0, 50);
    $this->db_row->entity_type = $this->entity_type;
    $this->db_row->ocr_key = substr($this->ocr_key, 0, 50);
    $this->db_row->ocr_status = $this->ocr_status;
    $this->db_row->ocr_dpl_date = strtotime($this->ocr_dpl_date);
    $this->db_row->ocr_check_count = $this->ocr_check_count;
    $result = drupal_write_record('ocr_log', $this->db_row);
    if ($result == SAVED_NEW) {
      $this->oid = $this->db_row->oid;
    }
    else {
      watchdog('findit', 'Error updating ocr_log, uid: %uid, entity_type: %entity_type', array(
          '%uid' => $this->db_row->uid,
          '%entity_type' => $this->db_row->entity_type,
        ), WATCHDOG_ERROR);
    }
  }

  private function update() {
    if (!empty($this->db_row->document_id) && !empty($this->document_id)) {
      if (stripos($this->db_row->document_id, $this->document_id) === FALSE) {
        $this->db_row->document_id .= ', ' . $this->document_id;
        $this->db_row->locale .= ', ' . $this->locale;
      }
    }
    else {
      $this->db_row->document_id = $this->document_id;
      $this->db_row->locale = $this->locale;
    }
    $this->db_row->date_updated = time();
    $this->db_row->entity_name = substr($this->entity_name, 0, 50);
    $this->db_row->entity_type = $this->entity_type;
    $this->db_row->ocr_key = substr($this->ocr_key, 0, 50);
    $this->db_row->ocr_status = $this->ocr_status;
    $this->db_row->ocr_dpl_date = strtotime($this->ocr_dpl_date);
    $this->db_row->email_sent = $this->email_sent;
    $this->db_row->ocr_check_count = $this->ocr_check_count;
    $result = drupal_write_record('ocr_log', $this->db_row, 'oid');
    if ($result != SAVED_UPDATED) {
      watchdog('findit', 'Error updating ocr_log, uid: %uid, entity_type: %entity_type', array(
          '%uid' => $this->db_row->uid,
          '%entity_type' => $this->db_row->entity_type,
        ), WATCHDOG_ERROR);
    }
  }

  public function read($uid, $entity_type) {
    $query = db_select('ocr_log', 'l')
      ->fields('l')
      ->condition('uid', $uid)
      ->condition('entity_type', $entity_type);
    $result = $query->execute()->fetchAssoc();
    if ($result) {
      $row = (object) $result;
      $this->db_row = $row;
      foreach ($this->db_row as $key => $value) {
        switch ($key) {
          case 'ocr_dpl_date':
          case 'date_created':
          case 'date_updated':
            if ($value > 0) {
              $this->$key = date('Y-m-d', $value);
            }
            else {
              $this->$key = NULL;
            }
            break;
          default:
            $this->$key = $value;
            break;
        }
      }
    }
  }

  public function delete() {
    $result = db_delete('ocr_log')->condition('oid', $this->oid)->execute();
    if ($result) {
      foreach ($this as $key => $value) {
        $this->$key = NULL;
      }
    }
  }

  public function increment_check_count() {
    $this->ocr_check_count++;
  }
}
