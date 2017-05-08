<?php
// $Id$


/**
 * @file
 * Describe the purpose of the file here.
 *
 */
class MACase {
  public $case_number;
  public $description;
  public $subject;
  public $asset;
  public $comments;
  public $status;
  public $created_date;

  public function __construct(sfdc_SupportCase $sfdc_case) {
    $this->case_number = $sfdc_case->CaseNumber;
    $this->description = $sfdc_case->Description;
    $this->subject = $sfdc_case->Subject;
    if ($sfdc_case->Asset) {
      $this->asset = new MAAsset();
      $this->asset->id = $sfdc_case->Asset->Id;
      $this->asset->name = $sfdc_case->Asset->Name;
      $this->asset->model = $sfdc_case->Asset->Name;
      $this->asset->serial_number = $sfdc_case->Asset->SerialNumber;
      $this->asset->is_gold_product = NULL;
    }
    $this->status = (preg_match('/Closed/', $sfdc_case->Status)) ? 'Closed' : 'Open';
    $this->created_date = date('Y-m-d H:i', strtotime($sfdc_case->CreatedDate));
    if ($sfdc_case->CaseComments) {
      $this->comments = array();
      if (!is_array($sfdc_case->CaseComments->records)) {
        $sfdc_case->CaseComments->records = array($sfdc_case->CaseComments->records);
      }
      foreach ($sfdc_case->CaseComments->records as $comment) {
        $this->comments[] = new MACaseComment($comment->CommentBody, date('Y-m-d H:i', strtotime($comment->CreatedDate)));
      }
    }
  }
}

class MACaseComment {
  public $comment_body;
  public $created_date;

  public function __construct($body, $date) {
    $this->comment_body = $body;
    $this->created_date = $date;
  }
}

class MAAsset {
  public $id;
  public $name;
  public $model;
  public $serial_number;
  public $is_gold_product;
}