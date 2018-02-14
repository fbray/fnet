<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/26/17
 * Time: 3:12 PM
 */

/*
 *  Product Display Migration Class
 * (Used to be Product content type)
*/
class FNETProductDisplayMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Redirects
    $this->addFieldMapping('migrate_redirects', 'path');

    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity')
      ->description(t('No longer necessary as NetScout split is complete.'))
      ->issueGroup(t('DNM'));
    $this->addFieldMapping(NULL, 'field_onyxhierarchyid')
      ->description(t('Onyx is no longer used.'))
      ->issueGroup(t('DNM'));

    // Individual Fields
    $this->addFieldMapping('field_prod_rating_review', 'field_prod_rating_review');
    $this->addFieldMapping('field_description', 'field_product_desc');
    $this->addFieldMapping('field_description:format', 'field_product_desc:format')
      ->defaultValue('plain_text');
    $this->addFieldMapping('field_at_a_glance', 'field_product_ataglance');
    $this->addFieldMapping('field_at_a_glance:format', 'field_product_ataglance:format')
      ->defaultValue('filtered_html');
    $this->addFieldMapping('field_prod_btn_cta_size', 'field_prod_btn_cta_size');

    $this->addFieldMapping('field_prod_contact_sales_button', 'field_prod_contact_sales_button');
    $this->addFieldMapping('field_prod_where_to_buy_button', 'field_prod_where_to_buy_button');
    $this->addFieldMapping('field_include_price_spider_code', 'field_wtb_pricespider_code');
    $this->addFieldMapping('field_wtb_ps_model_sku', 'field_wtb_ps_model_sku');
    $this->addFieldMapping('field_conversion_code', 'field_conversion_code');
    $this->addFieldMapping('field_conversion_code:format', 'field_conversion_code:format');
    $this->addFieldMapping('field_prod_hide_models_accessory', 'field_prod_hide_models_accessory');
    $this->addFieldMapping('field_product_details', 'field_product_details');
    $this->addFieldMapping('field_product_details:format', 'field_product_details:format')
      ->defaultValue('plain_text');
    $this->addFieldMapping('field_product_specs', 'field_product_specs');
    $this->addFieldMapping('field_product_specs:format', 'field_product_specs:format');

    $this->addFieldMapping('field_prod_ctab_name_1', 'field_prod_ctab_name_1');
    $this->addFieldMapping('field_prod_ctab_data_1', 'field_prod_ctab_data_1');
    $this->addFieldMapping('field_prod_ctab_data_1:format', 'field_prod_ctab_data_1:format')
      ->defaultValue('full_html');

    $this->addFieldMapping('field_prod_ctab_name_2', 'field_prod_ctab_name_2');
    $this->addFieldMapping('field_prod_ctab_data_2', 'field_prod_ctab_data_2');
    $this->addFieldMapping('field_prod_ctab_data_2:format', 'field_prod_ctab_data_2:format')
      ->defaultValue('full_html');

    $this->addFieldMapping('field_prod_ctab_name_3', 'field_prod_ctab_name_3');
    $this->addFieldMapping('field_prod_ctab_data_3', 'field_prod_ctab_data_3');
    $this->addFieldMapping('field_prod_ctab_data_3:format', 'field_prod_ctab_data_3:format')
      ->defaultValue('full_html');

    $this->addFieldMapping('field_prod_ctab_name_4', 'field_prod_ctab_name_4');
    $this->addFieldMapping('field_prod_ctab_data_4', 'field_prod_ctab_data_4');
    $this->addFieldMapping('field_prod_ctab_data_4:format')
      ->defaultValue('full_html');

    $this->addFieldMapping('field_prod_ctab_name_5', 'field_prod_ctab_name_5');
    $this->addFieldMapping('field_prod_ctab_data_5', 'field_prod_ctab_data_5');
    $this->addFieldMapping('field_prod_ctab_data_5:format')
      ->defaultValue('full_html');

    $this->addFieldMapping('field_prod_360_img_lg_1', 'field_prod_360_img_lg_1');
    
    $this->addFieldMapping('field_prod_carousel_img_srt_1', 'field_prod_carousel_img_srt_1');
    $this->addFieldMapping('field_prod_carousel_img_srt_2', 'field_prod_carousel_img_srt_2');
    $this->addFieldMapping('field_prod_carousel_img_srt_3', 'field_prod_carousel_img_srt_3');
    $this->addFieldMapping('field_prod_carousel_img_srt_4', 'field_prod_carousel_img_srt_4');
    $this->addFieldMapping('field_prod_carousel_img_srt_5', 'field_prod_carousel_img_srt_5');
    $this->addFieldMapping('field_prod_carousel_img_srt_6', 'field_prod_carousel_img_srt_6');
    $this->addFieldMapping('field_prod_carousel_img_srt_7', 'field_prod_carousel_img_srt_7');
    $this->addFieldMapping('field_prod_carousel_img_srt_8', 'field_prod_carousel_img_srt_8');
    $this->addFieldMapping('field_prod_carousel_img_srt_9', 'field_prod_carousel_img_srt_9');
    $this->addFieldMapping('field_prod_carousel_img_srt_10', 'field_prod_carousel_img_srt_10');

    $this->addFieldMapping('field_pcatid', 'field_pcatid');
    $this->addFieldMapping('field_prod_sol_title', 'field_prod_sol_title');
    $this->addFieldMapping('field_prod_sol_desc_1', 'field_prod_sol_desc_1');
    $this->addFieldMapping('field_prod_sol_desc_2', 'field_prod_sol_desc_2');
    $this->addFieldMapping('field_prod_sol_desc_3', 'field_prod_sol_desc_3');
    $this->addFieldMapping('field_prod_sol_desc_4', 'field_prod_sol_desc_4');

    $this->addFieldMapping('field_tracking_code', 'field_product_adtracker');
    $this->addFieldMapping('field_tracking_code:format', 'field_product_adtracker:format');
    $this->addFieldMapping('field_do_not_distribute', 'field_do_not_distribute');


    // Image Fields
    $this->addFieldMapping('field_prod_video_img_t_1', 'field_prod_video_img_t_1')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_video_img_t_1:alt', 'field_prod_video_img_t_1:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_video_img_t_1:title', 'field_prod_video_img_t_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_video_img_t_1:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_video_img_t_1:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_prod_wtb_img', 'field_prod_wtb_img')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_wtb_img:alt', 'field_prod_wtb_img:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_wtb_img:title', 'field_prod_wtb_img:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_wtb_img:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_wtb_img:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_prod_360_img_t_1', 'field_prod_360_img_t_1')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_360_img_t_1:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_360_img_t_1:file_class')
      ->defaultValue('MigrateFileFid');


    $this->addFieldMapping('field_prod_carousel_img_lg_1', 'field_prod_carousel_img_lg_1')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_carousel_img_lg_1:alt', 'field_prod_carousel_img_lg_1:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_1:title', 'field_prod_carousel_img_lg_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_1:height', 'field_prod_carousel_img_lg_1:height')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_1:width', 'field_prod_carousel_img_lg_1:width')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_1:language', 'field_prod_carousel_img_lg_1:language')
      ->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('field_prod_carousel_img_lg_1:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_lg_1:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_prod_carousel_img_t_1', 'field_prod_carousel_img_t_1')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_carousel_img_t_1:alt', 'field_prod_carousel_img_t_1:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_1:title', 'field_prod_carousel_img_t_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_1:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_t_1:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_prod_carousel_img_lg_2', 'field_prod_carousel_img_lg_2')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_carousel_img_lg_2:alt', 'field_prod_carousel_img_lg_2:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_2:title', 'field_prod_carousel_img_lg_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_2:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_lg_2:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_t_2', 'field_prod_carousel_img_t_2')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_carousel_img_t_2:alt', 'field_prod_carousel_img_t_2:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_2:title', 'field_prod_carousel_img_t_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_2:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_t_2:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_prod_carousel_img_lg_3', 'field_prod_carousel_img_lg_3')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_carousel_img_lg_3:alt', 'field_prod_carousel_img_lg_3:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_3:title', 'field_prod_carousel_img_lg_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_3:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_lg_3:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_t_3', 'field_prod_carousel_img_t_3')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_carousel_img_t_3:alt', 'field_prod_carousel_img_t_3:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_3:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_t_3:title', 'field_prod_carousel_img_t_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_3:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_prod_carousel_img_lg_4', 'field_prod_carousel_img_lg_4')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_carousel_img_lg_4:alt', 'field_prod_carousel_img_lg_4:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_4:title', 'field_prod_carousel_img_lg_4:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_4:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_lg_4:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_t_4', 'field_prod_carousel_img_t_4')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_carousel_img_t_4:alt', 'field_prod_carousel_img_t_4:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_4:title', 'field_prod_carousel_img_t_4:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_4:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_t_4:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_prod_carousel_img_lg_5', 'field_prod_carousel_img_lg_5')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_carousel_img_lg_5:alt', 'field_prod_carousel_img_lg_5:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_5:title', 'field_prod_carousel_img_lg_5:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_5:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_lg_5:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_t_5', 'field_prod_carousel_img_t_5')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_carousel_img_t_5:alt', 'field_prod_carousel_img_t_5:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_5:title', 'field_prod_carousel_img_t_5:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_5:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_t_5:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_prod_carousel_img_lg_6', 'field_prod_carousel_img_lg_6')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_carousel_img_lg_6:alt', 'field_prod_carousel_img_lg_6:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_6:title', 'field_prod_carousel_img_lg_6:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_6:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_lg_6:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_t_6', 'field_prod_carousel_img_t_6')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_carousel_img_t_6:alt', 'field_prod_carousel_img_t_6:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_6:title', 'field_prod_carousel_img_t_6:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_6:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_t_6:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_prod_carousel_img_lg_7', 'field_prod_carousel_img_lg_7')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_carousel_img_lg_7:alt', 'field_prod_carousel_img_lg_7:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_7:title', 'field_prod_carousel_img_lg_7:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_7:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_lg_7:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_t_7', 'field_prod_carousel_img_t_7')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_carousel_img_t_7:alt', 'field_prod_carousel_img_t_7:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_7:title', 'field_prod_carousel_img_t_7:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_7:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_t_7:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_prod_carousel_img_lg_8', 'field_prod_carousel_img_lg_8')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_carousel_img_lg_8:alt', 'field_prod_carousel_img_lg_8:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_8:title', 'field_prod_carousel_img_lg_8:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_8:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_lg_8:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_t_8', 'field_prod_carousel_img_t_8')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_carousel_img_t_8:alt', 'field_prod_carousel_img_t_8:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_8:title', 'field_prod_carousel_img_t_8:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_8:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_t_8:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_prod_carousel_img_lg_9', 'field_prod_carousel_img_lg_9')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_carousel_img_lg_9:alt', 'field_prod_carousel_img_lg_9:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_9:title', 'field_prod_carousel_img_lg_9:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_9:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_lg_9:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_t_9', 'field_prod_carousel_img_t_9')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_carousel_img_t_9:alt', 'field_prod_carousel_img_t_9:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_9:title', 'field_prod_carousel_img_t_9:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_9:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_t_9:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_prod_carousel_img_lg_10', 'field_prod_carousel_img_lg_10')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_carousel_img_lg_10:alt', 'field_prod_carousel_img_lg_10:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_10:title', 'field_prod_carousel_img_lg_10:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_10:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_lg_10:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_t_10', 'field_prod_carousel_img_t_10')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_carousel_img_t_10:alt', 'field_prod_carousel_img_t_10:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_10:title', 'field_prod_carousel_img_t_10:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_10:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_t_10:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_prod_hub_img', 'field_prod_hub_img')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_hub_img:alt', 'field_prod_hub_img:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_hub_img:title', 'field_prod_hub_img:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_hub_img:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_hub_img:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_prod_related_img', 'field_prod_related_img')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_related_img:alt', 'field_prod_related_img:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_related_img:title', 'field_prod_related_img:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_related_img:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_related_img:file_class')
      ->defaultValue('MigrateFileFid');

    // Link Fields
    $this->addFieldMapping('field_prod_btn_calltoaction', 'field_prod_btn_calltoaction');
    $this->addFieldMapping('field_prod_btn_calltoaction:title', 'field_prod_btn_calltoaction:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_btn_calltoaction:attributes', 'field_prod_btn_calltoaction:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_prod_wtb_online', 'field_prod_wtb_online');
    $this->addFieldMapping('field_prod_wtb_online:title', 'field_prod_wtb_online:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_wtb_online:attributes', 'field_prod_wtb_online:attributes')
      ->defaultValue(NULL);
    
    $this->addFieldMapping('field_prod_ctab_link_1', 'field_prod_ctab_link_1');
    $this->addFieldMapping('field_prod_ctab_link_1:title', 'field_prod_ctab_link_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_ctab_link_1:attributes', 'field_prod_ctab_link_1:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_prod_ctab_link_2', 'field_prod_ctab_link_2');
    $this->addFieldMapping('field_prod_ctab_link_2:title', 'field_prod_ctab_link_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_ctab_link_2:attributes', 'field_prod_ctab_link_2:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_prod_ctab_link_3', 'field_prod_ctab_link_3');
    $this->addFieldMapping('field_prod_ctab_link_3:title', 'field_prod_ctab_link_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_ctab_link_3:attributes', 'field_prod_ctab_link_3:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_prod_ctab_link_4', 'field_prod_ctab_link_4');
    $this->addFieldMapping('field_prod_ctab_link_4:title', 'field_prod_ctab_link_4:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_ctab_link_4:attributes', 'field_prod_ctab_link_4:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_prod_ctab_link_5', 'field_prod_ctab_link_5');
    $this->addFieldMapping('field_prod_ctab_link_5:title', 'field_prod_ctab_link_5:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_ctab_link_5:attributes', 'field_prod_ctab_link_5:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_prod_video_youtube_url', 'field_prod_video_youtube_url');
    $this->addFieldMapping('field_prod_video_youtube_url:title', 'field_prod_video_youtube_url:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_video_youtube_url:attributes', 'field_prod_video_youtube_url:attributes')
      ->defaultValue(NULL);
    
    $this->addFieldMapping('field_prod_sol_link_1', 'field_prod_sol_link_1');
    $this->addFieldMapping('field_prod_sol_link_1:title')->defaultValue(NULL);
    $this->addFieldMapping('field_prod_sol_link_1:attributes')->defaultValue(NULL);

    $this->addFieldMapping('field_prod_sol_link_2', 'field_prod_sol_link_2');
    $this->addFieldMapping('field_prod_sol_link_2:title')->defaultValue(NULL);
    $this->addFieldMapping('field_prod_sol_link_2:attributes')->defaultValue(NULL);

    $this->addFieldMapping('field_prod_sol_link_3', 'field_prod_sol_link_3');
    $this->addFieldMapping('field_prod_sol_link_3:title')->defaultValue(NULL);
    $this->addFieldMapping('field_prod_sol_link_3:attributes')->defaultValue(NULL);

    $this->addFieldMapping('field_prod_sol_link_4', 'field_prod_sol_link_4');
    $this->addFieldMapping('field_prod_sol_link_4:title')->defaultValue(NULL);
    $this->addFieldMapping('field_prod_sol_link_4:attributes')->defaultValue(NULL);

    // File Fields
    $this->addFieldMapping('field_prod_video_lg_1', 'field_prod_video_lg_1')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_prod_video_lg_1:display', 'field_prod_video_lg_1:display');
    $this->addFieldMapping('field_prod_video_lg_1:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_video_lg_1:file_class')
      ->defaultValue('MigrateFileFid');

    // Entity References
    $this->addFieldMapping('field_product_attributes', 'taxonomy_vocabulary_6')
      ->sourceMigration('ProductAttributes');

    $this->addFieldMapping('field_product_status', 'taxonomy_vocabulary_1')
      ->sourceMigration('ProductStatus');

    $this->addFieldMapping('field_product_family', 'field_product_family')
      ->sourceMigration('ProductFamily');

    // Related Products entity reference
    $this->addFieldMapping('field_products', 'field_prod_relatedprod')
      ->sourceMigration('ProductDisplay');

  }

  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Replace any instance of 'http://www.flukenetworks.com'.
    // $row->field_prod_wtb_online = str_ireplace('http://www.flukenetworks.com', '', $row->field_prod_wtb_online);
    $domains = ['http://www.flukenetworks.com/', 'https://www.flukenetworks.com/', 'http://flukenetworks.com/', 'https://flukenetworks.com/'];
    $row->field_prod_btn_calltoaction = str_ireplace($domains, '', $row->field_prod_btn_calltoaction);
  }

  public function createStub($migration) {
    return parent::createStub($migration); // TODO: Change the autogenerated stub

    // TODO: Make sure the titles get made correctly?
  }

  public function complete($node, stdClass $row) {
    return parent::complete($node, $row); // TODO: Change the autogenerated stub
  }


}