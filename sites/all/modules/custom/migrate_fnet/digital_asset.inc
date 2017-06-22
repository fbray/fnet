<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 6/7/17
 * Time: 1:39 PM
 */
/*
 *  Digital Asset Migration Class
*/
class FNETDigitalAssetMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity');

    // Individual Fields
    $this->addFieldMapping('field_expertise_intro', 'field_expertise_intro');
    $this->addFieldMapping('field_expertise_relatedcontent', 'field_expertise_related_content');
    // Move to a common Sort Order integer field.
    $this->addFieldMapping('field_sortorder', 'field_expertise_sortorder');

    // TODO: Image file!
    $this->addFieldMapping('field_expertise_image', 'field_expertise_image');

    // Entity References
    // TODO: Move to common field_industry?
    $this->addFieldMapping('field_industry', 'field_expertise_industry')
      ->sourceMigration('Industries'); // TODO: Find migration - Uses checkboxes/radio
    // TODO: WARNING: Might be referencing Expertise Industry content type.
    $this->addFieldMapping('field_expertise_product', 'field_expertise_product')
      ->sourceMigration('ExpertiseTypes'); // TODO: Find migration - Uses checkboxes/radio
    $this->addFieldMapping('field_language_override_exp', 'field_language_override_exp')
      ->sourceMigration('ExpertiseTypes'); // TODO: Find migration - Uses checkboxes/radio

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
    $this->addFieldMapping('expertise_types', 'taxonomy_vocabulary_8')
      ->sourceMigration('ExpertiseTypes');
    $this->addFieldMapping('expertise_types:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('expertise_types:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('expertise_types:ignore_case')
      ->defaultValue(TRUE);

    $this->addFieldMapping('industries', 'taxonomy_vocabulary_15')  // TODO: Double check the destination field name for the new reference.
    ->sourceMigration('Industries');
    $this->addFieldMapping('industries:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('industries:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('industries:ignore_case')
      ->defaultValue(TRUE);

  }
}