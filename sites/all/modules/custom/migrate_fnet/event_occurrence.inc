<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/18/17
 * Time: 2:03 PM
 */

/*
 *  Event Occurance Migration Class
*/
class FNETEventOccurrenceMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    $this->sourceFields += array(
      'parsed_event_date' => t('The formatted date compiled from the date and time fields.'),
      'parsed_event_date_end' => t('The formatted end date compiled from the date and time fields')
    );
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity');

    // Individual Fields
    $this->addFieldMapping('field_event_occ_cost', 'field_evnt_occ_cost');
    $this->addFieldMapping('field_event_occ_req_gold_number', 'field_evnt_occ_req_gold_number');
    $this->addFieldMapping('field_event_occ_req_address', 'field_evnt_req_address');
    $this->addFieldMapping('field_event_occ_capacity', 'field_evnt_occ_capacity');
    $this->addFieldMapping('field_event_occ_waitlist', 'field_evnt_occ_waitlist');
    $this->addFieldMapping('field_event_occ_accommodations', 'field_evnt_occ_accommodations')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_event_occ_accommodations:format', 'field_evnt_occ_accommodations:format');
    $this->addFieldMapping('field_event_occ_transportation', 'field_evnt_occ_transportation')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_event_occ_transportation:format', 'field_evnt_occ_transportation:format');
    $this->addFieldMapping('field_event_occ_contact', 'field_evnt_occ_contact')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_event_occ_contact:format', 'field_evnt_occ_contact:format');
    $this->addFieldMapping('field_notes', 'field_evnt_occ_notes');
    $this->addFieldMapping('field_notes:format', 'field_evnt_occ_notes:format');
    $this->addFieldMapping('field_event_occ_thank_you', 'field_evnt_occ_thank_you');
    $this->addFieldMapping('field_event_occ_thank_you:format', 'field_evnt_occ_thank_you:format');

    // Convert Location data to Address field
    // Country
    $this->addFieldMapping('field_address', 'country')
      ->defaultValue(NULL);
    // State/Province/Region
    $this->addFieldMapping('field_address:administrative_area', 'province')
      ->defaultValue(NULL);
    // County/District
    $this->addFieldMapping('field_address:sub_administrative_area')
      ->defaultValue(NULL);
    // City
    $this->addFieldMapping('field_address:locality', 'city')
      ->defaultValue(NULL);
    // Dependent Locality
    $this->addFieldMapping('field_address:dependent_locality')
      ->defaultValue(NULL);
    // Postal Code
    $this->addFieldMapping('field_address:postal_code', 'postal_code')
      ->defaultValue(NULL);
    // Street Address
    $this->addFieldMapping('field_address:thoroughfare', 'street')
      ->defaultValue(NULL);
    // Apartment/Suite/Box Number
    $this->addFieldMapping('field_address:premise')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_address:sub_premise')
      ->defaultValue(NULL);
    // Company Name
    $this->addFieldMapping('field_address:organization_name')
      ->defaultValue(NULL);
    // Full Name
    $this->addFieldMapping('field_address:name_line', 'name')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_address:first_name')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_address:last_name')
      ->defaultValue(NULL);
    // Additional Data
    $this->addFieldMapping('field_address:data', 'additional')
      ->defaultValue(NULL);

    // Date fields
    $this->addFieldMapping('field_event_date', 'parsed_event_date');
    $timezone = variable_get('date_default_timezone', '');
    $this->addFieldMapping('field_event_date:timezone', 'parsed_event_date:timezone')
      ->defaultValue($timezone); // TODO: Calculate this from address country?
    $this->addFieldMapping('field_event_date:rrule', 'parsed_event_date:rrule')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_event_date:to', 'parsed_event_date_end');

    // Entity References
    $this->addFieldMapping('field_event_parent', 'field_evnt_occ_parent')
      ->sourceMigration('Event');

    // Internationalization TODO: Sort this out.
    $this->addFieldMapping('field_language_region', 'field_evnt_occ_langreg');  // Move to common reglang field for now.
  }

  /**
   * @param $row
   * @return bool
   */
  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    // TODO: Put the date and time fields together.
    $date = $row->field_evnt_occ_date;

    // Extract the start and end times.
    $times = $this->parseEventTime($row->field_evnt_occ_time);

    // Glom the two together
    // TODO: Figure this out.

    // $row->source_article_date = $row->field_article_year . '-' . $row->field_article_month . '-'. $row->field_article_day . ' 00:00:00'; // Format the date here. YYYY-MM-DD HH:MM:SS
  }

  /**
   * @return \QueryConditionInterface
   */
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

  /**
   * @param $time
   * @return \stdClass
   */
  protected function parseEventTime($time) {
    $parsed = new stdClass;
    // Extract the start value
    // Is it a 24hr value? Use that if available.
    // Noon means 12:00
    // look for AM/PM
    // Start numbers without AM/PM tend to be in the morning. Values between 7 and 12 are generally AM.

    // Extract the end value
    // Is it a 24hr value? Use that if available.
    // Noon means 12:00
    // look for AM/PM
    // End numbers without AM/PM tend to be in the evening. Values

    // format to 24hr time - HH:MM:SS

    return $parsed;
  }
}