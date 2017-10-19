<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/24/17
 * Time: 1:25 PM
 */

/*
 *  Distributor Migration Class
*/
class FNETDistributorLocationMigration extends FNETNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    // This is likely better handled by node status
    $this->addFieldMapping(NULL, 'field_custom_publish_content');

    // Individual Fields
    $this->addFieldMapping('field_display_name', 'field_display_name')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_toll_free_phone_number', 'field_toll_free_phone')
      ->defaultValue(NULL); // Uses telephone module
    $this->addFieldMapping('field_email_contact', 'field_email_contact')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_notes', 'field_comments')
      ->defaultValue(NULL);

    // Convert former Location module data to Address Field
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
    $this->addFieldMapping('field_address:name_line')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_address:first_name')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_address:last_name')
      ->defaultValue(NULL);
    // Additional Data
    $this->addFieldMapping('field_address:data', 'additional')
      ->defaultValue(NULL);

    // Convert this from Text to Link field
    $this->addFieldMapping('field_website_url', 'field_website_url');
    $this->addFieldMapping('field_website_url:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_website_url:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_website_url:language')
      ->defaultValue(LANGUAGE_NONE);
    // Convert this from Text to Link field
    $this->addFieldMapping('field_buy_online_url', 'field_buy_online_url');
    $this->addFieldMapping('field_buy_online_url:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_buy_online_url:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_buy_online_url:language')
      ->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_gsa_schedule', 'field_gsa_schedule');
    $this->addFieldMapping('field_delivery_type', 'field_delivery_type');  // Uses checkboxes/radio
    $this->addFieldMapping('field_stocking_rating', 'field_stocking_rating');
    $this->addFieldMapping('field_salesforce_rating', 'field_sales_force_rating'); // Note the elimination of the space in the destination field.
    $this->addFieldMapping('field_distributor_type_rating', 'field_distributor_type_rating');
    $this->addFieldMapping('field_point_of_sale_rating', 'field_point_of_sale_rating');


    // Entity References
    $this->addFieldMapping('field_product_distributor_groups', 'field_product_groups')
      ->sourceMigration('ProductDistributor'); // Uses Select List

    // Metatags

  }

  protected function query() {
    $query = parent::query();
    // Join location table
    $query->join('location_instance', 'i', 'i.nid = n.nid AND i.vid = n.vid');
    $query->join('location', 'l', 'l.lid = i.lid');
    $query->fields('l', array(
      'street',
      'additional',
      'city',
      'province',
      'postal_code',
      'country')
    );

    return $query;
  }

  public function complete($node, stdClass $row) {
    // Generate URL Redirects.
    parent::generateNodeRedirect($node, $row);
  }
}