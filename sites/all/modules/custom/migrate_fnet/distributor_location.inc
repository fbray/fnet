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
class FNETDistributorMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    // TODO: This is likely better handled by node status
    $this->addFieldMapping(NULL, 'field_custom_publish_content');

    // Individual Fields
    $this->addFieldMapping('field_display_name', 'field_display_name');
    $this->addFieldMapping('field_toll_free_phone_number', 'field_toll_free_phone'); // Uses telephone module
    // TODO: Convert this from Text to Email field
    $this->addFieldMapping('field_email_contact', 'field_email_contact');

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

    // TODO: This is a comment field! Switch to using comments for this Content Type.
    // $this->addFieldMapping('field_comments', 'field_comments');

    $this->addFieldMapping('field_gsa_schedule', 'field_gsa_schedule');
    $this->addFieldMapping('field_delivery_type', 'field_delivery_type');  // Uses checkboxes/radio
    $this->addFieldMapping('field_stocking_rating', 'field_stocking_rating');
    $this->addFieldMapping('field_salesforce_rating', 'field_sales_force_rating'); // Note the elimination of the space in the destination field.
    $this->addFieldMapping('field_distributor_type_rating', 'field_distributor_type_rating');
    $this->addFieldMapping('field_point_of_sale_rating', 'field_point_of_sale_rating');
    $this->addFieldMapping('field_stocking_rating', 'field_stocking_rating');


    // Entity References
    $this->addFieldMapping('field_product_groups', 'field_product_groups')
      ->sourceMigration('ProductDistributor'); // Uses Select List

  }
}