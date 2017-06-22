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
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity');

    // Individual Fields
    $this->addFieldMapping('field_promo_intro_title', 'field_promo_intro_title');
    $this->addFieldMapping('field_promo_intro', 'field_promo_intro');  // Long text field
    $this->addFieldMapping('field_promo_intro:format', 'field_promo_intro:format');
    $this->addFieldMapping('field_promo_priority', 'field_promo_priority');
    $this->addFieldMapping('field_adtracker', 'field_promo_adtracker');

    // TODO: How to deal with Langreg fields?
    $this->addFieldMapping('field_promo_langreg', 'field_promo_langreg');


    // Date fields
    $this->addFieldMapping('field_promo_expdate', 'field_promo_expdate');

    // Link fields
    /* Example
    $this->addFieldMapping('field_video_url', 'field_videourl'); // Link
    $this->addFieldMapping('field_video_url:language')
      ->defaultValue('en');
    $this->addFieldMapping('field_video_url:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_video_url:title')
      ->defaultValue(NULL);
    */
    $this->addFieldMapping('field_promo_extlink', 'field_promo_extlink'); // Link
    $this->addFieldMapping('field_promo_extlink:language', 'field_promo_extlink:language')
      ->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('field_promo_extlink:attributes', 'field_promo_extlink:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_promo_extlink:title', 'field_promo_extlink:title')
      ->defaultValue(NULL);

    // Image Fields
    /* Example
    $this->addFieldMapping('field_device_icon:file_class')
      ->defaultValue('migrateFileFid');
    $this->addFieldMapping('field_device_icon:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_device_icon:language')
      ->defaultValue('en');
    $this->addFieldMapping('field_device_icon:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_device_icon:title')
      ->defaultValue(NULL);
    */
    $this->addFieldMapping('field_promo_thumbnail', 'field_promo_thumbnail')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_promo_thumbnail:preserve_files', 'field_promo_thumbnail:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_promo_thumbnail:language', 'field_promo_thumbnail:language')
      ->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('field_promo_thumbnail:alt', 'field_promo_thumbnail:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_promo_thumbnail:title', 'field_promo_thumbnail:title')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_promo_lgimage', 'field_promo_lgimage')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_promo_lgimage:preserve_files', 'field_promo_lgimage:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_promo_lgimage:language', 'field_promo_lgimage:language')
      ->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('field_promo_lgimage:alt', 'field_promo_lgimage:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_promo_lgimage:title', 'field_promo_lgimage:title')
      ->defaultValue(NULL);

    // Taxonomy References
    /* Example:
    $this->addFieldMapping('field_plugin_categories', 'field_plugin_categories')
      ->sourceMigration('PluginCategory');
    $this->addFieldMapping('field_plugin_categories:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_plugin_categories:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_plugin_categories:ignore_case')
      ->defaultValue(TRUE);
     */
    $this->addFieldMapping('promotion_type', 'taxonomy_vocabulary_5')
      ->sourceMigration('PromotionType');
    $this->addFieldMapping('promotion_type:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('promotion_type:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('promotion_type:ignore_case')
      ->defaultValue(TRUE);

  }
}