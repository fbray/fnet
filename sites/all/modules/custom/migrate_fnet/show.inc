<?php

/*
 *  Show Migration Class
*/
class PlayOn6ShowMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    $this->sourceFields['air_date_from'] = t('The formatted date year compiled from the first Air Date field.');
    $this->sourceFields['air_date_to'] = t('The formatted date year compiled from the second Air Date field.');
    $this->sourceFields['stars'] = t('The list of stars in this show.');
    parent::__construct($arguments);
    
    // Put mapping logic here.
    $this->addFieldMapping(NULL, 'field_fieldposhowfirstairdate'); // Parse this.
    $this->addFieldMapping('field_first_air_date', 'air_date_from');
    $this->addFieldMapping('field_first_air_date:to', 'air_date_to');
    $this->addFieldMapping('field_first_air_date:timezone')
      ->defaultValue('America/Los_Angeles');
    $this->addFieldMapping('field_first_air_date:rrule')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_show_channels', 'field_pochannels')
      ->sourceMigration('Channel');  // Node reference - needs the Entity Reference module
    
    $this->addFieldMapping('field_show_image', 'field_poshowimage')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_show_image:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_show_image:language')
      ->defaultValue('en');
    $this->addFieldMapping('field_show_image:preserve_files')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_show_image:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_show_image:title')
      ->defaultValue(NULL);
    
    
    $this->addFieldMapping(NULL, 'field_poshowstars'); // Parse this.
    $this->addFieldMapping('field_show_stars', 'stars');
    $this->addFieldMapping('field_show_stars:language')
      ->defaultValue('en');
    $this->addFieldMapping(NULL, 'field_poshowtitle');
    $this->addFieldMapping('field_show_ota_notes', 'field_poshow_ota_notes');
    $this->addFieldMapping('field_show_ota_notes:format', 'field_poshow_ota_notes:format')
      ->defaultValue('filtered_html');
    $this->addFieldMapping('field_show_ota_notes:language')
      ->defaultValue('en');
    $this->addFieldMapping('field_digital_purchase_notes', 'field_poshow_purchase_notes');
    $this->addFieldMapping('field_digital_purchase_notes:format', 'field_poshow_purchase_notes:format')
      ->defaultValue('filtered_html');
    $this->addFieldMapping('field_digital_purchase_notes:language')
      ->defaultValue('en');
    $this->addFieldMapping('field_available_ota', 'field_poshow_watch_ota');
    $this->addFieldMapping('field_show_digital_purchase', 'field_poshow_watch_w_purchase');
  }
  
  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    
    // Parse the first air date. Format will need to be YYYY-MM-DD HH:MM:SS
    // Look to see if there is a separator (-)
    $air_date_data = explode('-', $row->field_fieldposhowfirstairdate);
    $air_date_count = count($air_date_data);
    switch($air_date_count) {
      case ($air_date_count > 1):
        // Do additional processing steps.
        $air_date_start = trim($air_date_data[0]);
        $air_date_to = trim($air_date_data[1]);
        // The first number is a year.
        $formatted_air_date_start =  $air_date_start . '-01-01 00:00:01';
        $row->air_date_from = $formatted_air_date_start;
        // If value is 'present', enter current year //TODO
        if($air_date_to == 'present') {
          $row->air_date_to = date('Y-m-d H:i:s');
        }
        else {
          $row->air_date_to = $air_date_to . '-01-01 00:00:01';
        }
        break;
      case 1:
        // Format the data
        $formatted_air_date = $air_date_data[0] . '-01-01 00:00:01';
        $row->air_date_from = $formatted_air_date;
        break;
      default:
        // If null, leave blank.
        $row->air_date_from = NULL;
        break;
    }
        
    $stars = array();
    $stars = explode(',', $row->field_poshowstars);
    $row->stars = $stars;
  }
}