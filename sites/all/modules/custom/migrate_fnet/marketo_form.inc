<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/24/17
 * Time: 3:17 PM
 */

/*
 *  Marketo Form Migration Class
*/
class FNETMarketoFormMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // TODO: FUCK FUCK FUCK

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity');

    // TODO: Marketo Forms will move to a mobile-first design, so this needs to be reworked properly.
    // Individual Fields
    $this->addFieldMapping('field_mkt_banner_html', 'field_mkt_banner_html');
    $this->addFieldMapping('field_mkt_export_control', 'field_mkt_export_ctrl');

    // Display control fields.
    $this->addFieldMapping('field_mkt_frm_share', 'field_mkt_frm_share');
    $this->addFieldMapping('field_mkt_frm_display_footer', 'field_mkt_frm_display_footer');
    $this->addFieldMapping('field_removenav', 'field_removenav');

    // TODO: Design-specific fields. Migrate to a more generic field.
    $this->addFieldMapping('field_mkt_left_content', 'field_mkt_left_content');
    $this->addFieldMapping('field_mkt_form_bottom', 'field_mkt_form_bottom');
    $this->addFieldMapping('field_mkt_form_bottom:format', 'field_mkt_form_bottom:format');

    $this->addFieldMapping('field_expertise_relatedcontent', 'field_expertise_related_content');
    // Move to a common Sort Order integer field.
    $this->addFieldMapping('field_sortorder', 'field_expertise_sortorder');

    // TODO: Image file!
    $this->addFieldMapping('field_mkt_banner_img', 'field_mkt_banner_img')
      ->sourceMigration('Files');

    // Entity References
    // TODO: Move to common field_industry?
    $this->addFieldMapping('field_industry', 'field_expertise_industry')
      ->sourceMigration('Industries'); // TODO: Find migration - Uses checkboxes/radio
    // TODO: WARNING: Might be referencing Expertise Industry content type.
    $this->addFieldMapping('field_expertise_product', 'field_expertise_product')
      ->sourceMigration('ExpertiseTypes'); // TODO: Find migration - Uses checkboxes/radio
    $this->addFieldMapping('field_language_override_exp', 'field_language_override_exp')
      ->sourceMigration('ExpertiseTypes'); // TODO: Find migration - Uses checkboxes/radio

  }
}