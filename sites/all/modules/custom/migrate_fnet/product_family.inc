<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/22/17
 * Time: 11:11 AM
 */

/*
 *  Product Family Migration Class
 *  TODO: Verify this one.
*/
class FNETProductFamilyMigration extends DrupalNode7Migration {
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
    $this->addFieldMapping('field_description', 'field_family_shortdesc');
    $this->addFieldMapping('field_family_overview', 'field_family_overview');
    $this->addFieldMapping('field_family_expertise', 'field_family_expertise');
    $this->addFieldMapping('field_family_page_active', 'field_family_page_active');

    // Hero Fields
    $this->addFieldMapping('field_family_banner_sort_1', 'field_family_banner_srt_1');
    $this->addFieldMapping('field_family_banner_text_1', 'field_family_banner_txt_1');
    $this->addFieldMapping('field_family_banner_sort_2', 'field_family_banner_srt_2');
    $this->addFieldMapping('field_family_banner_text_2', 'field_family_banner_txt_2');
    $this->addFieldMapping('field_family_banner_sort_3', 'field_family_banner_srt_3');
    $this->addFieldMapping('field_family_banner_text_3', 'field_family_banner_txt_3');
    $this->addFieldMapping('field_family_banner_sort_4', 'field_family_banner_srt_4');
    $this->addFieldMapping('field_family_banner_text_4', 'field_family_banner_txt_4');
    $this->addFieldMapping('field_family_banner_sort_5', 'field_family_banner_srt_5');
    $this->addFieldMapping('field_family_banner_text_5', 'field_family_banner_txt_5');

    // Overview Tab Fields
    $this->addFieldMapping('field_overview_box_1_title', 'field_family_overview_boxtitle_1');
    $this->addFieldMapping('field_overview_box_2_title', 'field_family_overview_boxtitle_2');
    $this->addFieldMapping('field_overview_box_3_title', 'field_family_overview_boxtitle_3');
    $this->addFieldMapping('field_overview_box_1_description', 'field_family_overview_boxdesc_1');
    $this->addFieldMapping('field_overview_box_2_description', 'field_family_overview_boxdesc_2');
    $this->addFieldMapping('field_overview_box_3_description', 'field_family_overview_boxdesc_3');
    
    // Expertise Tab RHN Fields
    $this->addFieldMapping('field_expertise_box_1_title', 'field_family_expert_boxtitle_1');
    $this->addFieldMapping('field_expertise_box_2_title', 'field_family_expert_boxtitle_2');
    $this->addFieldMapping('field_expertise_box_3_title', 'field_family_expert_boxtitle_3');
    $this->addFieldMapping('field_expertise_box_1_desc', 'field_family_expert_boxdesc_1');
    $this->addFieldMapping('field_expertise_box_2_desc', 'field_family_expert_boxdesc_2');
    $this->addFieldMapping('field_expertise_box_3_desc', 'field_family_expert_boxdesc_3');
    
    // Products Tab RHN Fields
    $this->addFieldMapping('field_product_box_1_title', 'field_family_prod_boxtitle_1');
    $this->addFieldMapping('field_product_box_2_title', 'field_family_prod_boxtitle_2');
    $this->addFieldMapping('field_product_box_3_title', 'field_family_prod_boxtitle_3');
    $this->addFieldMapping('field_product_box_1_description', 'field_family_prod_boxdesc_1');
    $this->addFieldMapping('field_product_box_2_description', 'field_family_prod_boxdesc_2');
    $this->addFieldMapping('field_product_box_3_description', 'field_family_prod_boxdesc_3');


    // Link Fields
    $this->addFieldMapping('field_overview_box_1_link', 'field_family_overview_boxlink_1');
    $this->addFieldMapping('field_overview_box_1_link:title', 'field_family_overview_boxlink_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_overview_box_1_link:attributes', 'field_family_overview_boxlink_1:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_overview_box_2_link', 'field_family_overview_boxlink_2');
    $this->addFieldMapping('field_overview_box_2_link:title', 'field_family_overview_boxlink_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_overview_box_2_link:attributes', 'field_family_overview_boxlink_2:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_overview_box_3_link', 'field_family_overview_boxlink_3');
    $this->addFieldMapping('field_overview_box_3_link:title', 'field_family_overview_boxlink_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_overview_box_3_link:attributes', 'field_family_overview_boxlink_3:attributes')
      ->defaultValue(NULL);
    
    $this->addFieldMapping('field_expertise_box_1_link', 'field_family_expert_boxlink_1');
    $this->addFieldMapping('field_expertise_box_1_link:title', 'field_family_expert_boxlink_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_expertise_box_1_link:attributes', 'field_family_expert_boxlink_1:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_expertise_box_2_link', 'field_family_expert_boxlink_2');
    $this->addFieldMapping('field_expertise_box_2_link:title', 'field_family_expert_boxlink_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_expertise_box_2_link:attributes', 'field_family_expert_boxlink_2:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_expertise_box_3_link', 'field_family_expert_boxlink_3');
    $this->addFieldMapping('field_expertise_box_3_link:title', 'field_family_expert_boxlink_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_expertise_box_3_link:attributes', 'field_family_expert_boxlink_3:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_product_box_1_link', 'field_family_prod_boxlink_1');
    $this->addFieldMapping('field_product_box_1_link:title', 'field_family_prod_boxlink_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_product_box_1_link:attributes', 'field_family_prod_boxlink_1:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_product_box_2_link', 'field_family_prod_boxlink_2');
    $this->addFieldMapping('field_product_box_2_link:title', 'field_family_prod_boxlink_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_product_box_2_link:attributes', 'field_family_prod_boxlink_2:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_product_box_3_link', 'field_family_prod_boxlink_3');
    $this->addFieldMapping('field_product_box_3_link:title', 'field_family_prod_boxlink_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_product_box_3_link:attributes', 'field_family_prod_boxlink_3:attributes')
      ->defaultValue(NULL);

    // Image Fields
    $this->addFieldMapping('field_image', 'field_family_image')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_image:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_image:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_image:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_background_image', 'field_family_background_img')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_background_image:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_background_image:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_background_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_background_image:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_hub_image', 'field_family_hub_img')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_hub_image:alt', 'field_family_hub_img:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_hub_image:title', 'field_family_hub_img:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_hub_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_hub_image:file_class')
      ->defaultValue('MigrateFileFid');


    $this->addFieldMapping('field_overview_box_1_image', 'field_family_overview_boximg_1')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_overview_box_1_image:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_overview_box_1_image:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_overview_box_1_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_overview_box_1_image:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_overview_box_2_image', 'field_family_overview_boximg_2')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_overview_box_2_image:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_overview_box_2_image:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_overview_box_2_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_overview_box_2_image:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_overview_box_3_image', 'field_family_overview_boximg_3')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_overview_box_3_image:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_overview_box_3_image:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_overview_box_3_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_overview_box_3_image:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_expertise_box_1_image', 'field_family_expert_boximg_1')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_expertise_box_1_image:alt', 'field_family_expert_boximg_1:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_expertise_box_1_image:title', 'field_family_expert_boximg_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_expertise_box_1_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_expertise_box_1_image:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_expertise_box_2_image', 'field_family_expert_boximg_2')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_expertise_box_2_image:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_expertise_box_2_image:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_expertise_box_2_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_expertise_box_2_image:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_expertise_box_3_image', 'field_family_expert_boximg_3')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_expertise_box_3_image:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_expertise_box_3_image:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_expertise_box_3_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_expertise_box_3_image:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_product_box_1_image', 'field_family_prod_boximg_1')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_product_box_1_image:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_product_box_1_image:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_product_box_1_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_product_box_1_image:file_class')
      ->defaultValue('MigrateFileFid');


    $this->addFieldMapping('field_product_box_2_image', 'field_family_prod_boximg_2')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_product_box_2_image:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_product_box_2_image:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_product_box_2_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_product_box_2_image:file_class')
      ->defaultValue('MigrateFileFid');

    $this->addFieldMapping('field_product_box_3_image', 'field_family_prod_boximg_3')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_product_box_3_image:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_product_box_3_image:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_product_box_3_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_product_box_3_image:file_class')
      ->defaultValue('MigrateFileFid');

    // Entity References
    // This was a node reference to the Industry content type. This is now Product Category.
    $this->addFieldMapping('field_product_category', 'field_family_industry')
      ->sourceMigration('ProductCategory');

  }
}