<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/23/17
 * Time: 1:32 PM
 */

/*
 * TODO: Feck. Need to redo this due to Git stupidity. 9/17/2017. You fecking moron, Ryan.
 *  Product Category Migration Class
*/
class FNETProductCategoryLanguageMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Path Alias
    $this->addFieldMapping('path', 'path');

    // Disable Pathauto for now.
    $this->addFieldMapping('pathauto')->defaultValue(0);

    // Redirects
    $this->addFieldMapping('migrate_redirects', 'path');

    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity')
      ->description(t('No longer necessary as NetScout split is complete.'))
      ->issueGroup(t('DNM'));

    // Individual Fields
    $this->addFieldMapping('field_language_region', 'field_indlang_language');

    // Hero Fields
    $this->addFieldMapping('field_family_banner_sort_1', 'field_indlang_banner_srt_1');
    $this->addFieldMapping('field_family_banner_text_1', 'field_indlang_banner_txt_1');
    $this->addFieldMapping('field_family_banner_text_1:format', 'field_indlang_banner_txt_1:format')
      ->defaultValue('filtered_html');
    $this->addFieldMapping('field_family_banner_sort_2', 'field_indlang_banner_srt_2');
    $this->addFieldMapping('field_family_banner_text_2', 'field_indlang_banner_txt_2');
    $this->addFieldMapping('field_family_banner_text_2:format', 'field_indlang_banner_txt_2:format')
      ->defaultValue('filtered_html');
    $this->addFieldMapping('field_family_banner_sort_3', 'field_indlang_banner_srt_3');
    $this->addFieldMapping('field_family_banner_text_3', 'field_indlang_banner_txt_3');
    $this->addFieldMapping('field_family_banner_text_3:format', 'field_indlang_banner_txt_3:format')
      ->defaultValue('filtered_html');
    $this->addFieldMapping('field_family_banner_sort_4', 'field_indlang_banner_srt_4');
    $this->addFieldMapping('field_family_banner_text_4', 'field_indlang_banner_txt_4');
    $this->addFieldMapping('field_family_banner_text_4:format', 'field_indlang_banner_txt_4:format')
      ->defaultValue('filtered_html');
    $this->addFieldMapping('field_family_banner_sort_5', 'field_indlang_banner_srt_5');
    $this->addFieldMapping('field_family_banner_text_5', 'field_indlang_banner_txt_5');
    $this->addFieldMapping('field_family_banner_text_5:format', 'field_indlang_banner_txt_5:format')
      ->defaultValue('filtered_html');

    // Overview Tab Right-hand Navigation Fields
    $this->addFieldMapping('field_overview_intro', 'field_indlang_overview_intro');
    $this->addFieldMapping('field_overview_intro:format', 'field_indlang_overview_intro:format')
      ->defaultValue('full_html');

    $this->addFieldMapping('field_overview_box_1_disable', 'field_indlang_box_disable_1');
    $this->addFieldMapping('field_overview_box_1_title', 'field_indlang_box_title_1');
    $this->addFieldMapping('field_overview_box_1_description', 'field_indlang_box_desc_1');
    $this->addFieldMapping('field_overview_box_1_link', 'field_indlang_box_link_1'); // Link
    $this->addFieldMapping('field_overview_box_1_link:title', 'field_indlang_box_link_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_overview_box_1_link:attributes', 'field_indlang_box_link_1:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_overview_box_2_disable', 'field_indlang_box_disable_2');
    $this->addFieldMapping('field_overview_box_2_title', 'field_indlang_box_title_2');
    $this->addFieldMapping('field_overview_box_2_description', 'field_indlang_box_desc_2');
    $this->addFieldMapping('field_overview_box_2_link', 'field_indlang_box_link_2'); // Link
    $this->addFieldMapping('field_overview_box_2_link:title', 'field_indlang_box_link_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_overview_box_2_link:attributes', 'field_indlang_box_link_2:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_overview_box_3_disable', 'field_indlang_box_disable_3');
    $this->addFieldMapping('field_overview_box_3_title', 'field_indlang_box_title_3');
    $this->addFieldMapping('field_overview_box_3_description', 'field_indlang_box_desc_3');
    $this->addFieldMapping('field_overview_box_3_link', 'field_indlang_box_link_3'); // Link
    $this->addFieldMapping('field_overview_box_3_link:title', 'field_indlang_box_link_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_overview_box_3_link:attributes', 'field_indlang_box_link_3:attributes')
      ->defaultValue(NULL);

    // Expertise Tab Left-hand Navigation Fields
    $this->addFieldMapping('field_popular_resources_disable', 'field_indlang_pop_res_disable');
    $this->addFieldMapping('field_popular_resources_1', 'field_indlang_pop_res_1'); // Link
    $this->addFieldMapping('field_popular_resources_1:title', 'field_indlang_pop_res_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_popular_resources_1:attributes', 'field_indlang_pop_res_1:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_popular_resources_2', 'field_indlang_pop_res_2'); // Link
    $this->addFieldMapping('field_popular_resources_2:title', 'field_indlang_pop_res_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_popular_resources_2:attributes', 'field_indlang_pop_res_2:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_popular_resources_3', 'field_indlang_pop_res_3'); // Link
    $this->addFieldMapping('field_popular_resources_3:title', 'field_indlang_pop_res_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_popular_resources_3:attributes', 'field_indlang_pop_res_3:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_learn_about_disable', 'field_indlang_learn_abt_disable'); // Link
    $this->addFieldMapping('field_learn_about_1', 'field_indlang_learn_abt_1'); // Link
    $this->addFieldMapping('field_learn_about_1:title', 'field_indlang_learn_abt_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_learn_about_1:attributes', 'field_indlang_learn_abt_1:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_learn_about_2', 'field_indlang_learn_abt_2'); // Link
    $this->addFieldMapping('field_learn_about_2:title', 'field_indlang_learn_abt_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_learn_about_2:attributes', 'field_indlang_learn_abt_2:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_learn_about_3', 'field_indlang_learn_abt_3'); // Link
    $this->addFieldMapping('field_learn_about_3:title', 'field_indlang_learn_abt_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_learn_about_3:attributes', 'field_indlang_learn_abt_3:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_disable_featured_topics', 'field_indlang_fea_top_disable'); // Link
    $this->addFieldMapping('field_featured_topic_1', 'field_indlang_fea_top_1'); // Link
    $this->addFieldMapping('field_featured_topic_1:title', 'field_indlang_fea_top_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_featured_topic_1:attributes', 'field_indlang_fea_top_1:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_featured_topic_2', 'field_indlang_fea_top_2'); // Link
    $this->addFieldMapping('field_featured_topic_2:title', 'field_indlang_fea_top_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_featured_topic_2:attributes', 'field_indlang_fea_top_2:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_featured_topic_3', 'field_indlang_fea_top_3'); // Link
    $this->addFieldMapping('field_featured_topic_3:title', 'field_indlang_fea_top_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_featured_topic_3:attributes', 'field_indlang_fea_top_3:attributes')
      ->defaultValue(NULL);
    
    $this->addFieldMapping('field_expertise_lhn_box', 'field_indlang_expertise_box');
    $this->addFieldMapping('field_expertise_lhn_box:format', 'field_indlang_expertise_box:format')
      ->defaultValue('full_html');

    // Products Tab Right-hand Navigation Fields
    $this->addFieldMapping('field_promotions_disable', 'field_indlang_promo_disable');
    $this->addFieldMapping('field_promotion_1', 'field_indlang_promo_1'); // Link
    $this->addFieldMapping('field_promotion_1:title', 'field_indlang_promo_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_promotion_1:attributes', 'field_indlang_promo_1:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_promotion_2', 'field_indlang_promo_2'); // Link
    $this->addFieldMapping('field_promotion_2:title', 'field_indlang_promo_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_promotion_2:attributes', 'field_indlang_promo_2:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_promotion_3', 'field_indlang_promo_3'); // Link
    $this->addFieldMapping('field_promotion_3:title', 'field_indlang_promo_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_promotion_3:attributes', 'field_indlang_promo_3:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_disable_demos', 'field_indlang_demo_disable');
    $this->addFieldMapping('field_demo_1', 'field_indlang_demo_1'); // Link
    $this->addFieldMapping('field_demo_1:title', 'field_indlang_demo_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_demo_1:attributes', 'field_indlang_demo_1:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_demo_2', 'field_indlang_demo_2'); // Link
    $this->addFieldMapping('field_demo_2:title', 'field_indlang_demo_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_demo_2:attributes', 'field_indlang_demo_2:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_demo_3', 'field_indlang_demo_3'); // Link
    $this->addFieldMapping('field_demo_3:title', 'field_indlang_demo_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_demo_3:attributes', 'field_indlang_demo_3:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_demo_type_1', 'field_indlang_demo_type_1');
    $this->addFieldMapping('field_demo_type_2', 'field_indlang_demo_type_2');
    $this->addFieldMapping('field_demo_type_3', 'field_indlang_demo_type_3');

    $this->addFieldMapping('field_disable_trials', 'field_indlang_trial_disable');
    $this->addFieldMapping('field_trial_1', 'field_indlang_trial_1'); // Link
    $this->addFieldMapping('field_trial_1:title', 'field_indlang_trial_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_trial_1:attributes', 'field_indlang_trial_1:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_trial_2', 'field_indlang_trial_2'); // Link
    $this->addFieldMapping('field_trial_2:title', 'field_indlang_trial_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_trial_2:attributes', 'field_indlang_trial_2:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_trial_3', 'field_indlang_trial_3'); // Link
    $this->addFieldMapping('field_trial_3:title', 'field_indlang_trial_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_trial_3:attributes', 'field_indlang_trial_3:attributes')
      ->defaultValue(NULL);
    
    $this->addFieldMapping('field_trial_type_1', 'field_indlang_trial_type_1');
    $this->addFieldMapping('field_trial_type_2', 'field_indlang_trial_type_2');
    $this->addFieldMapping('field_trial_type_3', 'field_indlang_trial_type_3');

    $this->addFieldMapping('field_products_rhn_box', 'field_indlang_product_box');
    $this->addFieldMapping('field_products_rhn_box:format', 'field_indlang_product_box:format')
      ->defaultValue('full_html');


    // Image Fields
    $this->addFieldMapping('field_overview_box_1_image', 'field_indlang_box_img_1')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_overview_box_1_image:title', 'field_indlang_box_img_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_overview_box_1_image:alt', 'field_indlang_box_img_1:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_overview_box_1_image:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_overview_box_1_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_overview_box_2_image', 'field_indlang_box_img_2')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_overview_box_2_image:title', 'field_indlang_box_img_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_overview_box_2_image:alt', 'field_indlang_box_img_2:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_overview_box_2_image:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_overview_box_2_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_overview_box_3_image', 'field_indlang_box_img_3')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_overview_box_3_image:title', 'field_indlang_box_img_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_overview_box_3_image:alt', 'field_indlang_box_img_3:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_overview_box_3_image:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_overview_box_3_image:preserve_files')
      ->defaultValue(TRUE);

    // Entity References
    $this->addFieldMapping('field_product_category', 'field_indlang_industry')
      ->sourceMigration('ProductCategory');

  }

  /**
   * Implementation of prepareRow()
   *
   * @param $row
   * @return bool
   */
  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    // The language/region thing seems to be problematic with the allowed values.
    // Let's trim it down to just the first five characters.
    $row->field_indlang_language[0] = substr($row->field_indlang_language[0], 0, 5);

    $row->body = $this->stripDomain($row->body);
    $row->body = str_ireplace('/flukenetworks.com/files', '/default/files', $row->body);
    $row->body = str_ireplace('/flukenetworks.com/theme', '/all/theme', $row->body);
  }

  /**
   * Remove the hard-coded Fluke Networks domain from a field.
   *
   * @param $string
   * @return mixed
   */
  protected function stripDomain($string) {
    $domains = ['http://www.flukenetworks.com/', 'https://www.flukenetworks.com/', 'http://flukenetworks.com/', 'https://flukenetworks.com/'];
    $stripped = str_ireplace($domains, '/', $string);
    return $stripped;
  }
}