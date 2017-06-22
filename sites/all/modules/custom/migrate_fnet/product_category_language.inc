<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/23/17
 * Time: 1:32 PM
 */

/*
 * TODO: This one.
 *  Product Category Migration Class
*/
class FNETProductCategoryMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity');

    // Individual Fields
    $this->addFieldMapping('field_product_category_desc', 'field_industry_shortdesc');

    // Hero Fields
    $this->addFieldMapping('field_product_category_banner_srt_1', 'field_industry_banner_srt_1');
    $this->addFieldMapping('field_product_category_banner_txt_1', 'field_industry_banner_txt_1');
    $this->addFieldMapping('field_product_category_banner_srt_2', 'field_industry_banner_srt_2');
    $this->addFieldMapping('field_product_category_banner_txt_2', 'field_industry_banner_txt_2');
    $this->addFieldMapping('field_product_category_banner_srt_3', 'field_industry_banner_srt_3');
    $this->addFieldMapping('field_product_category_banner_txt_3', 'field_industry_banner_txt_3');
    $this->addFieldMapping('field_product_category_banner_srt_4', 'field_industry_banner_srt_4');
    $this->addFieldMapping('field_product_category_banner_txt_4', 'field_industry_banner_txt_4');
    $this->addFieldMapping('field_product_category_banner_srt_5', 'field_industry_banner_srt_5');
    $this->addFieldMapping('field_product_category_banner_txt_5', 'field_industry_banner_txt_5');

    // Overview Tab Right-hand Navigation Fields
    $this->addFieldMapping('field_product_category_overview_intro', 'field_industry_overview_intro');
    $this->addFieldMapping('field_product_category_box_title_1', 'field_industry_box_title_1');
    $this->addFieldMapping('field_product_category_box_desc_1', 'field_industry_box_desc_1');
    $this->addFieldMapping('field_product_category_box_url_1', 'field_industry_box_url_1'); // Link
    $this->addFieldMapping('field_product_category_box_title_2', 'field_industry_box_title_2');
    $this->addFieldMapping('field_product_category_box_desc_2', 'field_industry_box_desc_2');
    $this->addFieldMapping('field_product_category_box_url_2', 'field_industry_box_url_2'); // Link
    $this->addFieldMapping('field_product_category_box_title_3', 'field_industry_box_title_3');
    $this->addFieldMapping('field_product_category_box_desc_3', 'field_industry_box_desc_3');
    $this->addFieldMapping('field_product_category_box_url_3', 'field_industry_box_url_3'); // Link

    // Expertise Tab Left-hand Navigation Fields
    $this->addFieldMapping('field_product_category_pop_res_1', 'field_industry_pop_res_1'); // Link
    $this->addFieldMapping('field_product_category_pop_res_2', 'field_industry_pop_res_2'); // Link
    $this->addFieldMapping('field_product_category_pop_res_3', 'field_industry_pop_res_3'); // Link
    $this->addFieldMapping('field_product_category_learn_abt_1', 'field_industry_learn_abt_1'); // Link
    $this->addFieldMapping('field_product_category_learn_abt_2', 'field_industry_learn_abt_2'); // Link
    $this->addFieldMapping('field_product_category_learn_abt_3', 'field_industry_learn_abt_3'); // Link
    $this->addFieldMapping('field_product_category_fea_top_1', 'field_industry_fea_top_1'); // Link
    $this->addFieldMapping('field_product_category_fea_top_2', 'field_industry_fea_top_2'); // Link
    $this->addFieldMapping('field_product_category_fea_top_3', 'field_industry_fea_top_3'); // Link
    $this->addFieldMapping('field_product_category_expertise_box', 'field_industry_expertise_box');



    // Products Tab Right-hand Navigation Fields
    $this->addFieldMapping('field_product_category_promo_1', 'field_industry_promo_1'); // Link
    $this->addFieldMapping('field_product_category_promo_2', 'field_industry_promo_2'); // Link
    $this->addFieldMapping('field_product_category_promo_3', 'field_industry_promo_3'); // Link
    $this->addFieldMapping('field_product_category_demo_1', 'field_industry_demo_1'); // Link
    $this->addFieldMapping('field_product_category_demo_2', 'field_industry_demo_2'); // Link
    $this->addFieldMapping('field_product_category_demo_3', 'field_industry_demo_3'); // Link
    $this->addFieldMapping('field_product_category_demo_type_1', 'field_industry_demo_type_1');
    $this->addFieldMapping('field_product_category_demo_type_2', 'field_industry_demo_type_2');
    $this->addFieldMapping('field_product_category_demo_type_3', 'field_industry_demo_type_3');
    $this->addFieldMapping('field_product_category_trial_1', 'field_industry_trial_1'); // Link
    $this->addFieldMapping('field_product_category_trial_2', 'field_industry_trial_2'); // Link
    $this->addFieldMapping('field_product_category_trial_3', 'field_industry_trial_3'); // Link
    $this->addFieldMapping('field_product_category_trial_type_1', 'field_industry_trial_type_1');
    $this->addFieldMapping('field_product_category_trial_type_2', 'field_industry_trial_type_2');
    $this->addFieldMapping('field_product_category_trial_type_3', 'field_industry_trial_type_3');
    $this->addFieldMapping('field_product_category_product_box', 'field_industry_product_box');


    // Image Fields
    $this->addFieldMapping('field_product_category_image', 'field_industry_image')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_product_category_box_img_1', 'field_industry_box_img_1')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_product_category_box_img_2', 'field_industry_box_img_2')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_product_category_box_img_3', 'field_industry_box_img_3')
      ->sourceMigration('Files');

    // Entity References
    // TODO: Move to common language field?
    $this->addFieldMapping('field_language', 'field_industry_language')
      ->sourceMigration('Industries'); // TODO: Find migration - Uses checkboxes/radio
    $this->addFieldMapping('field_language_override_exp', 'field_language_override_exp')
      ->sourceMigration('ExpertiseTypes'); // TODO: Find migration - Uses checkboxes/radio

    // Taxonomy References
    // Product Attributes
    $this->addFieldMapping('product_attributes', 'taxonomy_vocabulary_6')
      ->sourceMigration('ProductAttributes');
    $this->addFieldMapping('product_attributes:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('product_attributes:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('product_attributes:ignore_case')
      ->defaultValue(TRUE);

  }
}