<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/26/17
 * Time: 2:05 PM
 */

/*
 *  Microsite Page Migration Class
*/
class FNETMicrositePageMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    $this->sourceFields += array(
      'parsed_language' => t('The languages values for this row.'), // TODO: Could be multiple.
    );
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity');
    $this->addFieldMapping(NULL, 'field_removenav');

    // Individual Fields
    $this->addFieldMapping('field_intro', 'field_ms_page_intro_content');
    $this->addFieldMapping('field_intro:language', 'field_ms_page_intro_content');  // TODO: Make this the parsed language.
    $this->addFieldMapping('field_background_color', 'field_ms_page_bg_color');
    $this->addFieldMapping('field_tracking_code', 'field_microsite_page_adtracker');

    // TODO: Image file!
    $this->addFieldMapping('field_background_image', 'field_ms_page_bg_image')
      ->sourceMigration('Files');

    // Entity References
    $this->addFieldMapping('microsite', 'taxonomy_vocabulary_18')
      ->sourceMigration('Microsites');
  }

  // TODO: Do some PrepareRow magic
  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

  }

  // TODO: We're going to have to do some fuckery in the query() function to get the associated language fields from microsite_page_language.
  /**
   * @return \QueryConditionInterface
   */
  protected function query() {
    $query = parent::query();

    // Join the associated microsite_page_language fields.
    $query->join('field_data_field_ms_page_language_ms_page', 'p', 'p.field_ms_page_language_ms_page_nid = n.nid');
    $query->join('node', 'nf', 'p.entity_id = nf.nid AND p.revision_id = nf.vid');
    $query->join('field_data_field_ms_page_language_language', 'l', 'l.entity_id = nf.nid AND l.revision_id = nf.vid');
    $query->join('field_data_field_ms_page_language_intro', 'i', 'i.entity_id = nf.nid AND i.revision_id = nf.vid');
    $query->join('field_data_body', 'b', 'b.entity_id = nf.nid AND b.revision_id = nf.vid');
    $query->fields('l', array(
      'field_ms_page_language_language_value'));
    $query->fields('i', array(
      'field_ms_page_language_intro_value'));
    $query->fields('b', array(
      'body_value', 'language', 'body_format', 'body_summary'));

    /*
    SELECT
    n.nid as nid,
    l.field_ms_page_language_language_value as parsed_language,
    i.field_ms_page_language_intro_value as intro,
    nf.body
    FROM node n
    JOIN field_data_field_ms_page_language_ms_page p ON p.field_ms_page_language_ms_page_nid = n.nid
    JOIN node nf ON p.entity_id = nf.nid AND p.revision_id = nf.vid
    JOIN field_data_field_ms_page_language_language l on l.entity_id = nf.nid AND l.revision_id = nf.vid
    JOIN field_data_field_ms_page_language_intro i on i.entity_id = nf.nid AND i.revision_id = nf.vid
    WHERE n.type = 'microsite_page';

     */
    return $query;
  }

  // TODO: Some more fuckery to insert the translation information into the Entity Translation table.
  function complete($entity, stdClass $row) {
    // TODO: Create some shit from this example.
    // Add a translation into the system only if it exists.
    /*
    if (!is_null($entity->title_field['fr'][0]['value'])) {
      // Create a record for the french translation in the entity translation table.
      $nid = db_insert('entity_translation')
        ->fields(array(
          'entity_type' => 'node',
          'entity_id' => $entity->nid,
          'language' => 'fr',
          'source' => $entity->language,
          'uid' => $entity->uid,
          'status' => $entity->status,
          'translate' => $entity->translate,
          'created' => $entity->created,
          'changed' => $entity->changed,
        ))
        ->execute();
    } */
  }
}