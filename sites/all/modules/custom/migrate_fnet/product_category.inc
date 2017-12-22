<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/22/17
 * Time: 4:24 PM
 */

/*
 *  Product Category Migration Class
*/
class FNETProductCategoryMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity');

    // Individual Fields
    $this->addFieldMapping('field_description', 'field_industry_shortdesc');
    $this->addFieldMapping('field_description:format', 'field_industry_shortdesc');

    // Hero Fields
    $this->addFieldMapping('field_family_banner_sort_1', 'field_industry_banner_srt_1');
    $this->addFieldMapping('field_family_banner_text_1', 'field_industry_banner_txt_1');
    $this->addFieldMapping('field_family_banner_sort_2', 'field_industry_banner_srt_2');
    $this->addFieldMapping('field_family_banner_text_2', 'field_industry_banner_txt_2');
    $this->addFieldMapping('field_family_banner_sort_3', 'field_industry_banner_srt_3');
    $this->addFieldMapping('field_family_banner_text_3', 'field_industry_banner_txt_3');
    $this->addFieldMapping('field_family_banner_sort_4', 'field_industry_banner_srt_4');
    $this->addFieldMapping('field_family_banner_text_4', 'field_industry_banner_txt_4');
    $this->addFieldMapping('field_family_banner_sort_5', 'field_industry_banner_srt_5');
    $this->addFieldMapping('field_family_banner_text_5', 'field_industry_banner_txt_5');
    
    // Overview Tab Right-hand Navigation Fields
    $this->addFieldMapping('field_overview_intro', 'field_industry_overview_intro');
    $this->addFieldMapping('field_overview_box_1_title', 'field_industry_box_title_1');
    $this->addFieldMapping('field_overview_box_1_description', 'field_industry_box_desc_1');
    $this->addFieldMapping('field_overview_box_1_link', 'field_industry_box_url_1'); // Link
    $this->addFieldMapping('field_overview_box_1_link:title', 'field_industry_box_url_1:title');
    $this->addFieldMapping('field_overview_box_1_link:attributes', 'field_industry_box_url_1:attributes');
    $this->addFieldMapping('field_overview_box_1_link:language', 'field_industry_box_url_1:language')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_overview_box_2_title', 'field_industry_box_title_2');
    $this->addFieldMapping('field_overview_box_2_description', 'field_industry_box_desc_2');
    $this->addFieldMapping('field_overview_box_2_link', 'field_industry_box_url_2'); // Link
    $this->addFieldMapping('field_overview_box_2_link:title', 'field_industry_box_url_2:title');
    $this->addFieldMapping('field_overview_box_2_link:attributes', 'field_industry_box_url_2:attributes');
    $this->addFieldMapping('field_overview_box_2_link:language', 'field_industry_box_url_2:language')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_overview_box_3_title', 'field_industry_box_title_3');
    $this->addFieldMapping('field_overview_box_3_description', 'field_industry_box_desc_3');
    $this->addFieldMapping('field_overview_box_3_link', 'field_industry_box_url_3'); // Link
    $this->addFieldMapping('field_overview_box_3_link:title', 'field_industry_box_url_3:title');
    $this->addFieldMapping('field_overview_box_3_link:attributes', 'field_industry_box_url_3:attributes');
    $this->addFieldMapping('field_overview_box_3_link:language', 'field_industry_box_url_3:language')
      ->defaultValue(NULL);

    // Expertise Tab Left-hand Navigation Fields
    $this->addFieldMapping('field_popular_resources_1', 'field_industry_pop_res_1'); // Link
    $this->addFieldMapping('field_popular_resources_1:title', 'field_industry_pop_res_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_popular_resources_1:attributes', 'field_industry_pop_res_1:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_popular_resources_1:language', 'field_industry_pop_res_1:language')
      ->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_popular_resources_2', 'field_industry_pop_res_2'); // Link
    $this->addFieldMapping('field_popular_resources_2:title', 'field_industry_pop_res_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_popular_resources_2:attributes', 'field_industry_pop_res_2:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_popular_resources_2:language', 'field_industry_pop_res_2:language')
      ->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_popular_resources_3', 'field_industry_pop_res_3'); // Link
    $this->addFieldMapping('field_popular_resources_3:title', 'field_industry_pop_res_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_popular_resources_3:attributes', 'field_industry_pop_res_3:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_popular_resources_3:language', 'field_industry_pop_res_3:language')
      ->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_learn_about_1', 'field_industry_learn_abt_1'); // Link
    $this->addFieldMapping('field_learn_about_1:title', 'field_industry_learn_abt_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_learn_about_1:attributes', 'field_industry_learn_abt_1:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_learn_about_1:language', 'field_industry_learn_abt_1:language')
      ->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_learn_about_2', 'field_industry_learn_abt_2'); // Link
    $this->addFieldMapping('field_learn_about_2:title', 'field_industry_learn_abt_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_learn_about_2:attributes', 'field_industry_learn_abt_2:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_learn_about_2:language', 'field_industry_learn_abt_2:language')
      ->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_learn_about_3', 'field_industry_learn_abt_3'); // Link
    $this->addFieldMapping('field_learn_about_3:title', 'field_industry_learn_abt_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_learn_about_3:attributes', 'field_industry_learn_abt_3:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_learn_about_3:language', 'field_industry_learn_abt_3:language')
      ->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_featured_topic_1', 'field_industry_fea_top_1'); // Link
    $this->addFieldMapping('field_featured_topic_1:title', 'field_industry_fea_top_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_featured_topic_1:attributes', 'field_industry_fea_top_1:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_featured_topic_1:language', 'field_industry_fea_top_1:language')
      ->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_featured_topic_2', 'field_industry_fea_top_2'); // Link
    $this->addFieldMapping('field_featured_topic_2:title', 'field_industry_fea_top_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_featured_topic_2:attributes', 'field_industry_fea_top_2:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_featured_topic_2:language', 'field_industry_fea_top_2:language')
      ->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_featured_topic_3', 'field_industry_fea_top_3'); // Link
    $this->addFieldMapping('field_featured_topic_3:title', 'field_industry_fea_top_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_featured_topic_3:attributes', 'field_industry_fea_top_3:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_featured_topic_3:language', 'field_industry_fea_top_3:language')
      ->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_expertise_lhn_box', 'field_industry_expertise_box');
    $this->addFieldMapping('field_expertise_lhn_box:format', 'field_industry_expertise_box:format');


    // Products Tab Right-hand Navigation Fields
    $this->addFieldMapping('field_promotion_1', 'field_industry_promo_1'); // Link
    $this->addFieldMapping('field_promotion_1:title', 'field_industry_promo_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_promotion_1:attributes', 'field_industry_promo_1:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_promotion_1:language', 'field_industry_promo_1:language')
      ->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_promotion_2', 'field_industry_promo_2'); // Link
    $this->addFieldMapping('field_promotion_2:title', 'field_industry_promo_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_promotion_2:attributes', 'field_industry_promo_2:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_promotion_2:language', 'field_industry_promo_2:language')
      ->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_promotion_3', 'field_industry_promo_3'); // Link
    $this->addFieldMapping('field_promotion_3:title', 'field_industry_promo_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_promotion_3:attributes', 'field_industry_promo_3:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_promotion_3:language', 'field_industry_promo_3:language')
      ->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_demo_1', 'field_industry_demo_1'); // Link
    $this->addFieldMapping('field_demo_1:title', 'field_industry_demo_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_demo_1:attributes', 'field_industry_demo_1:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_demo_1:language', 'field_industry_demo_1:language')
      ->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_demo_2', 'field_industry_demo_2'); // Link
    $this->addFieldMapping('field_demo_2:title', 'field_industry_demo_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_demo_2:attributes', 'field_industry_demo_2:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_demo_2:language', 'field_industry_demo_2:language')
      ->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_demo_3', 'field_industry_demo_3'); // Link
    $this->addFieldMapping('field_demo_3:title', 'field_industry_demo_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_demo_3:attributes', 'field_industry_demo_3:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_demo_3:language', 'field_industry_demo_3:language')
      ->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_demo_type_1', 'field_industry_demo_type_1');
    $this->addFieldMapping('field_demo_type_2', 'field_industry_demo_type_2');
    $this->addFieldMapping('field_demo_type_3', 'field_industry_demo_type_3');

    $this->addFieldMapping('field_trial_1', 'field_industry_trial_1'); // Link
    $this->addFieldMapping('field_trial_1:title', 'field_industry_trial_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_trial_1:attributes', 'field_industry_trial_1:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_trial_1:language', 'field_industry_trial_1:language')
      ->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_trial_type_1', 'field_industry_trial_type_1');
    $this->addFieldMapping('field_trial_type_2', 'field_industry_trial_type_2');
    $this->addFieldMapping('field_trial_type_3', 'field_industry_trial_type_3');

    $this->addFieldMapping('field_products_rhn_box', 'field_industry_product_box');
    $this->addFieldMapping('field_products_rhn_box:format', 'field_industry_product_box:format');


    // Image Fields
    $this->addFieldMapping('field_image', 'field_industry_image')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_image:file_class' )
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_background_image', 'field_ind_background_img')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_background_image:file_class' )
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_overview_box_1_image', 'field_industry_box_img_1')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_overview_box_1_image:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_overview_box_2_image', 'field_industry_box_img_2')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_overview_box_2_image:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_overview_box_3_image', 'field_industry_box_img_3')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_overview_box_3_image:file_class')
      ->defaultValue('MigrateFileFid');


    // Entity References
    $this->addFieldMapping('product_attributes', 'taxonomy_vocabulary_6')
      ->sourceMigration('ProductAttributes');

  }
}