<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/30/17
 * Time: 2:09 PM
 */

/*
 *  Promotion Migration Class
*/
class FNETPromotionMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Redirects
    $this->addFieldMapping('migrate_redirects', 'path');

    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity')
      ->description(t('No longer necessary as NetScout split is complete.'))
      ->issueGroup(t('DNM'));

    // Individual Fields
    $this->addFieldMapping('field_intro_title', 'field_promo_intro_title');
    $this->addFieldMapping('field_intro', 'field_promo_intro');  // Long text field
    $this->addFieldMapping('field_intro:format', 'field_promo_intro:format');
    // Move to weight field.
    $this->addFieldMapping('weight', 'field_promo_priority');
    $this->addFieldMapping('field_tracking_code', 'field_promo_adtracker');
    $this->addFieldMapping('field_tracking_code:format', 'field_promo_adtracker:format');
    $this->addFieldMapping('field_tracking_code:language', 'field_promo_adtracker:language');

    $this->addFieldMapping('field_language_region', 'field_promo_langreg');


    // Date fields
    // Set the default start date as 1/1/2010.
    $this->addFieldMapping('field_promotion_date')
      ->defaultValue('2010-01-01 00:00:00');
    $timezone = variable_get('date_default_timezone', '');
    $this->addFieldMapping('field_promotion_date:timezone')
      ->defaultValue($timezone);
    $this->addFieldMapping('field_promotion_date:rrule')
      ->defaultValue(NULL);
    // The expiration date should be in the 'to' field for the date.
    $this->addFieldMapping('field_promotion_date:to', 'field_promo_expdate');

    // Link fields
    $this->addFieldMapping('field_external_url', 'field_promo_extlink'); // Link
    $this->addFieldMapping('field_external_url:language', 'field_promo_extlink:language')
      ->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('field_external_url:attributes', 'field_promo_extlink:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_external_url:title', 'field_promo_extlink:title')
      ->defaultValue(NULL);

    // Image Fields
    $this->addFieldMapping('field_thumbnail', 'field_promo_thumbnail')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_thumbnail:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_thumbnail:alt', 'field_promo_thumbnail:alt')
      ->sourceMigration(NULL);

    $this->addFieldMapping('field_image', 'field_promo_lgimage')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_image:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_image:alt', 'field_promo_lgimage:alt')
      ->sourceMigration(NULL);


    // Entity References
    $this->addFieldMapping('field_promotion_type', 'taxonomy_vocabulary_5')
      ->sourceMigration('PromotionType');


  }
}