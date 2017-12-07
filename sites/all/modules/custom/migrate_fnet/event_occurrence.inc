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
class FNETEventOccurrenceMigration extends FNETNode7Migration {
  public function __construct(array $arguments) {
    $this->sourceFields += array(
      'parsed_event_date' => t('The formatted date compiled from the date and time fields.'),
      'parsed_event_date_end' => t('The formatted end date compiled from the date and time fields')
    );
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Redirects
    $this->addFieldMapping('migrate_redirects', 'path');

    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity')
      ->description(t('No longer necessary as NetScout split is complete.'))
      ->issueGroup(t('DNM'));

    // Individual Fields
    $this->addFieldMapping('field_event_occ_cost', 'field_evnt_occ_cost');
    $this->addFieldMapping('field_marketo_program', 'field_evnt_occ_marketo_program');
    $this->addFieldMapping('field_event_occ_req_gold_number', 'field_evnt_occ_req_gold_number');
    $this->addFieldMapping('field_event_occ_req_address', 'field_evnt_occ_req_address');
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
    $this->addFieldMapping('field_address:organisation_name')
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
    $this->addFieldMapping('field_event_date:timezone')
      ->defaultValue($timezone);
    $this->addFieldMapping('field_event_date:rrule')
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
    $date = $row->field_evnt_occ_date[0];

    // Extract the start and end times.
    $times = $this->parseEventTime($row->field_evnt_occ_time[0]);

    // Format should be YYYY-MM-DDTHH:MM:SS (ex. 2013-05-06T00:00:00)
    $row->parsed_event_date = str_replace('00:00:00', $times->start, $date);
    if (isset($times->end)) {
      $row->parsed_event_date_end = str_replace('00:00:00', $times->end, $date);
    }
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
   * Parses the various text entries for time into usable datetimes.
   *
   * @param $time
   * @return \stdClass
   */
  protected function parseEventTime($time) {
    // Output should be formatted in 24hr style as HH:MM:SS. (Ex. 13:30:00)
    $parsed = new stdClass;
    // Extract the start value
    $thing = explode(' ', $time);

    $parsed->start = $this->figureOutTime($thing[0]);

    // Extract the end value
    if (isset($thing[2])) {
      $parsed->end = $this->figureOutTime($thing[2]);
    }
    return $parsed;
  }

  protected function figureOutTime($time = '00:00:00') {
    $meridiem = '';
    // If value is Noon
    if (strtolower($time) == 'noon') {
      return '12:00:00';
    }

    // Replace periods with colons.
    $figured = str_replace('.', ':', $time);

    // Strip off any 'am' or 'pm', but make note of it.
    $pattern = '/(AM|am|PM|pm)/';
    // do a preg_match to see if is in there
    if (preg_match($pattern, $time, $matches) == 1) {
      // if so, find out which one it is
      $meridiem = strtolower($matches[0]);
      // Then remove it.
      $time = str_replace($meridiem, '', $time);
    }


    // Split the value into hours and minutes.
    $split = explode(':', $time);
    $hour = $split[0];
    $minutes = $split[1];
    // Process the hour
    // If hour is greater than 12, it's already in 24hr format.
    // Otherwise, look for AM/PM
    if ($hour < 12) {
      // If PM, convert to 24hr time: Hour + 12
      if ($meridiem == 'pm') {
        $hour = $hour + 12;
      }

    }
    return sprintf("%02d:%02d:%02d", $hour, $minutes, '00');
  }

}