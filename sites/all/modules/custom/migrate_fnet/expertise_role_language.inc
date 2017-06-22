<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/18/17
 * Time: 5:03 PM
 */

/*
 *  Expertise Role Language Migration Class
*/
class FNETExpertiseRoleLanguageMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity');

    // Individual Fields
    $this->addFieldMapping('field_exp_rle_banner_content', 'field_exp_rle_banner_content');
    $this->addFieldMapping('field_exp_rle_tab_title', 'field_exp_rle_tab_title');
    $this->addFieldMapping('field_exp_rle_tab_content', 'field_exp_rle_tab_content');
    $this->addFieldMapping('field_exp_rle_tab_content:format', 'field_exp_rle_tab_content:format');
    $this->addFieldMapping('field_exp_rle_tab2_title', 'field_exp_rle_tab2_title');
    $this->addFieldMapping('field_exp_rle_tab2_content', 'field_exp_rle_tab2_content');
    $this->addFieldMapping('field_exp_rle_tab2_content:format', 'field_exp_rle_tab2_content:format');
    $this->addFieldMapping('field_exp_rle_tab3_title', 'field_exp_rle_tab3_title');
    $this->addFieldMapping('field_exp_rle_tab3_content', 'field_exp_rle_tab3_content');
    $this->addFieldMapping('field_exp_rle_tab3_content:format', 'field_exp_rle_tab3_content:format');
    $this->addFieldMapping('field_exp_rle_tab4_title', 'field_exp_rle_tab4_title');
    $this->addFieldMapping('field_exp_rle_tab4_content', 'field_exp_rle_tab4_content');
    $this->addFieldMapping('field_exp_rle_tab4_content:format', 'field_exp_rle_tab4_content:format');
    $this->addFieldMapping('field_language_region', 'field_exp_rle_region');

    // Image Fields
    $this->addFieldMapping('field_exp_rle_banner_image', 'field_exp_rle_banner_image')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_exp_rle_banner_image:preserve_files', 'field_exp_rle_banner_image');
    $this->addFieldMapping('field_exp_rle_banner_image:file_class', 'field_exp_rle_banner_image');
    $this->addFieldMapping('field_exp_rle_banner_image:destination_dir', 'field_exp_rle_banner_image');
    $this->addFieldMapping('field_exp_rle_banner_image:destination_file', 'field_exp_rle_banner_image');
    $this->addFieldMapping('field_exp_rle_banner_image:file_replace', 'field_exp_rle_banner_image');
    $this->addFieldMapping('field_exp_rle_banner_image:source_dir', 'field_exp_rle_banner_image');
    $this->addFieldMapping('field_exp_rle_banner_image:urlencode', 'field_exp_rle_banner_image');
    $this->addFieldMapping('field_exp_rle_banner_image:alt', 'field_exp_rle_banner_image');
    $this->addFieldMapping('field_exp_rle_banner_image:title', 'field_exp_rle_banner_image');


    // Entity References
    $this->addFieldMapping('field_expertise_role', 'field_exp_rle_lng_rle')
      ->sourceMigration('ExpertiseRole');
  }
}