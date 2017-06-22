<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/18/17
 * Time: 11:39 AM
 */

/*
 *  eDoc Migration Class
*/
class FNETeDocMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity');


    // Individal fields
    $this->addFieldMapping('field_subtitle', 'field_edoc_subtitle');

    // TODO: Preprocess these to create language variants.
    /*
    $this->addFieldMapping('field_edoc_lid_en', 'field_edoc_lid_en');
    $this->addFieldMapping('field_edoc_lid_fr', 'field_edoc_lid_fr');
    $this->addFieldMapping('field_edoc_lid_de', 'field_edoc_lid_de');
    $this->addFieldMapping('field_edoc_lid_es', 'field_edoc_lid_es');
    $this->addFieldMapping('field_edoc_lid_cn', 'field_edoc_lid_cn');
    $this->addFieldMapping('field_edoc_lid_jp', 'field_edoc_lid_jp');
    $this->addFieldMapping('field_edoc_lid_ko', 'field_edoc_lid_ko');
    $this->addFieldMapping('field_edoc_lid_pt', 'field_edoc_lid_pt');
    $this->addFieldMapping('field_edoc_lid_ru', 'field_edoc_lid_ru');
*/
  }

  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    /*
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
    */
  }

  function complete($entity, stdClass $row) {
    // TODO: Create translations in the entity translation table for each of the literature IDs.

  }
}

