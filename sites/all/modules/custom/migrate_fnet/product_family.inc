<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/22/17
 * Time: 11:11 AM
 */

/*
 *  Product Family Migration Class
*/
class FNETProductFamilyMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity');

    // Individual Fields
    $this->addFieldMapping('field_family_shortdesc', 'field_family_shortdesc');
    $this->addFieldMapping('field_family_overview', 'field_family_overview');
    $this->addFieldMapping('field_family_page_active', 'field_family_page_active');

    // Hero Fields
    $this->addFieldMapping('field_family_banner_srt_1', 'field_family_banner_srt_1');
    $this->addFieldMapping('field_family_banner_txt_1', 'field_family_banner_txt_1');
    $this->addFieldMapping('field_family_banner_srt_2', 'field_family_banner_srt_2');
    $this->addFieldMapping('field_family_banner_txt_2', 'field_family_banner_txt_2');
    $this->addFieldMapping('field_family_banner_srt_3', 'field_family_banner_srt_3');
    $this->addFieldMapping('field_family_banner_txt_3', 'field_family_banner_txt_3');
    $this->addFieldMapping('field_family_banner_srt_4', 'field_family_banner_srt_4');
    $this->addFieldMapping('field_family_banner_txt_4', 'field_family_banner_txt_4');
    $this->addFieldMapping('field_family_banner_srt_5', 'field_family_banner_srt_5');
    $this->addFieldMapping('field_family_banner_txt_5', 'field_family_banner_txt_5');

    // Expertise Tab RHN Fields
    $this->addFieldMapping('field_family_expert_boxtitle_1', 'field_family_expert_boxtitle_1');
    $this->addFieldMapping('field_family_expert_boxtitle_2', 'field_family_expert_boxtitle_2');
    $this->addFieldMapping('field_family_expert_boxtitle_3', 'field_family_expert_boxtitle_3');
    $this->addFieldMapping('field_family_expert_boxdesc_1', 'field_family_expert_boxdesc_1');
    $this->addFieldMapping('field_family_expert_boxdesc_2', 'field_family_expert_boxdesc_2');
    $this->addFieldMapping('field_family_expert_boxdesc_3', 'field_family_expert_boxdesc_3');
    $this->addFieldMapping('field_family_expert_boxlink_1', 'field_family_expert_boxlink_1');
    $this->addFieldMapping('field_family_expert_boxlink_2', 'field_family_expert_boxlink_2');
    $this->addFieldMapping('field_family_expert_boxlink_3', 'field_family_expert_boxlink_3');
    
    // Products Tab RHN Fields
    $this->addFieldMapping('field_family_prod_boxtitle_1', 'field_family_prod_boxtitle_1');
    $this->addFieldMapping('field_family_prod_boxtitle_2', 'field_family_prod_boxtitle_2');
    $this->addFieldMapping('field_family_prod_boxtitle_3', 'field_family_prod_boxtitle_3');
    $this->addFieldMapping('field_family_prod_boxdesc_1', 'field_family_prod_boxdesc_1');
    $this->addFieldMapping('field_family_prod_boxdesc_2', 'field_family_prod_boxdesc_2');
    $this->addFieldMapping('field_family_prod_boxdesc_3', 'field_family_prod_boxdesc_3');
    $this->addFieldMapping('field_family_prod_boxlink_1', 'field_family_prod_boxlink_1');
    $this->addFieldMapping('field_family_prod_boxlink_2', 'field_family_prod_boxlink_2');
    $this->addFieldMapping('field_family_prod_boxlink_3', 'field_family_prod_boxlink_3');

    // Image Fields
    $this->addFieldMapping('field_family_image', 'field_family_image')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_family_background_img', 'field_family_background_img')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_family_hub_img', 'field_family_hub_img')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_family_expert_boximg_1', 'field_family_expert_boximg_1')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_family_expert_boximg_2', 'field_family_expert_boximg_2')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_family_expert_boximg_3', 'field_family_expert_boximg_3')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_family_prod_boximg_1', 'field_family_prod_boximg_1')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_family_prod_boximg_2', 'field_family_prod_boximg_2')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_family_prod_boximg_3', 'field_family_prod_boximg_3')
      ->sourceMigration('Files');

    // Entity References
    // Use common field_industry for this one.
    $this->addFieldMapping('field_industry', 'field_family_industry')
      ->sourceMigration('Industries'); // TODO: Find migration - Uses checkboxes/radio
    // TODO: WARNING: Might be referencing Expertise Industry content type.

  }
}