<?php
/*
 *  News Migration Class
*/
class PlayOn6NewsMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    $this->sourceFields += array(
      'parsed_url' => t('The parsed URL extracted from the Body field.'),
      'parsed_title' => t('The parsed Title extracted from the Body field.'),
      'parsed_body' => t('The parsed Body extracted from the Body field.'),  // used for press releases.
      'source_article_date' => t('The formatted date compiled from the day, month, and year fields.'),
    );
    parent::__construct($arguments);
    
    // Put mapping logic here.
    $this->addFieldMapping(NULL, 'body');
    $this->addFieldMapping('body', 'parsed_body');
    $this->addFieldMapping(NULL, 'field_article_day')
        ->description(t('The source day.'));
    $this->addFieldMapping(NULL, 'field_article_month')
        ->description(t('The source month.'));
    $this->addFieldMapping(NULL, 'field_article_year')
        ->description(t('The source year.'));
    $this->addFieldMapping('field_source_article_date', 'source_article_date'); 
    $this->addFieldMapping('field_source_article_date:timezone')
      ->defaultValue('America/Los_Angeles');
    $this->addFieldMapping('field_source_article_date:rrule')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_source_article_date:to')
      ->defaultValue(NULL);   
    $this->addFieldMapping('field_is_press_release', 'field_isapressrelease'); 
    $this->addFieldMapping('field_is_playlater', 'field_isplaylater');
    $this->addFieldMapping('body:summary', 'field_newsteaser');
    $this->addFieldMapping('field_source_article_link', 'parsed_url');
    $this->addFieldMapping('field_source_article_link:title', 'parsed_title');
    $this->addFieldMapping('field_source_article_link:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_source_article_link:language')
      ->defaultValue('en');
      
    // Upload field
    $this->addFieldMapping('field_attachments', 'upload')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_attachments:file_class')->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_attachments:preserve_files')->defaultValue(FALSE);
    $this->addFieldMapping('field_attachments:description', 'upload:description');
    $this->addFieldMapping('field_attachments:display')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_attachments:language')
      ->defaultValue('en');

  }
  
  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    $row->source_article_date = $row->field_article_year . '-' . $row->field_article_month . '-'. $row->field_article_day . ' 00:00:00'; // Format the date here. YYYY-MM-DD HH:MM:SS

    if(preg_match("/^<a[^>]*>/", $row->body)) {  // TODO: if body starts with '<a href'
      $row->parsed_url = $this->urlExtract($row->body);
      $row->parsed_title = $this->titleExtract($row->body);
    }
    else {
      $row->parsed_body = $row->body;
      // Extract the link title from the <h1>
      $row->parsed_title = $this->headerExtract($row->body);
      // Extract the link url from the node path.
      $row->parsed_url = $row->path;
    }
  }
  
  private function urlExtract($body) {
    $regex = "/<a\s[^>]*href=\"([^\"]*)\"[^>]*>(.*)<\/a>/siU";
    preg_match($regex, $body, $url);
    return $url[1];
  }

  
  private function titleExtract($body) {
    $regex = "/<a\s[^>]*href=\"([^\"]*)\"[^>]*>(.*)<\/a>/siU";
    preg_match($regex, $body, $url);
    return $url[2];
  }
  
  private function headerExtract($body) {
    $regex = "/<h1>(.*)<\/h1>/iU";
    preg_match($regex, $body, $url);
    return $url[1];
  }
}