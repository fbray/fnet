<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/18/17
 * Time: 1:43 PM
 */

/*
 *  Event Migration Class
*/
class FNETEventMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity');

    // Individual Fields
    $this->addFieldMapping('field_intro', 'field_event_intro');
    $this->addFieldMapping('field_intro:format', 'field_event_intro:format');
    $this->addFieldMapping('field_intro:language', 'field_event_intro:language')
      ->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('weight', 'field_event_priority'); // Move to Weight
    $this->addFieldMapping('field_tracking_code', 'field_event_adtracker');
    $this->addFieldMapping('field_tracking_code:format', 'field_event_adtracker:format');

    // Link fields
    $this->addFieldMapping('field_workshop_reglink', 'field_workshop_link');
    $this->addFieldMapping('field_workshop_reglink:title', 'field_workshop_link:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_workshop_reglink:attributes', 'field_workshop_link:attributes');
    $this->addFieldMapping('field_workshop_reglink:language', 'field_workshop_link:language')
      ->defaultValue(LANGUAGE_NONE);

    // Date fields
    $this->addFieldMapping('field_event_date', 'field_event_date');
    $this->addFieldMapping('field_event_date:timezone', 'field_event_date:timezone');
    $this->addFieldMapping('field_event_date:rrule', 'field_event_date:rrule');
    $this->addFieldMapping('field_event_date:to', 'field_event_date:to');

    // Address Field - convert from Location
    // TODO: Is this necessary? Hmm.
    // It doesn't appear to be used for anything.

    // Taxonomy References
    $this->addFieldMapping('event_types', 'taxonomy_vocabulary_10')
      ->sourceMigration('EventTypes');
    $this->addFieldMapping('event_types:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('event_types:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('event_types:ignore_case')
      ->defaultValue(TRUE);

    // Entity References
    $this->addFieldMapping('field_product_category', 'field_workshop_industry')
      ->sourceMigration('ProductCategory')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_products', 'field_workshop_product')
      ->sourceMigration('ProductDisplay')
      ->defaultValue(NULL);

    // Internationalization TODO: Sort this out.
    $this->addFieldMapping('language', 'field_event_langreg');
  }

  protected function query() {
    $query = parent::query();

    // Join location table
    $query->join('location_instance', 'i', 'i.nid = n.nid AND i.vid = n.vid');
    $query->join('location', 'l', 'l.lid = i.lid');
    $query->fields('l', array(
      'name',
      'street',
      'additional',
      'city',
      'province',
      'postal_code',
      'country')
    );

    return $query;
  }
}