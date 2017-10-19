<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 10/5/17
 * Time: 9:32 AM
 */
/*
 *  Expertise Role Language Migration Class
*/
class FNETExpertiseRoleLanguageMigration extends FNETNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity')
      ->description(t('No longer necessary as NetScout split is complete.'))
      ->issueGroup(t('DNM'));

    // Individual Fields
    $this->addFieldMapping('field_language_region', 'field_exp_rle_banner_content');
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

    // Image Fields
    $this->addFieldMapping('field_exp_rle_banner_image', 'field_exp_rle_banner_image')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_exp_rle_banner_image:file_class')
      ->defaultValue('MigrateFileFid');

    // Entity Reference Fields
    $this->addFieldMapping('field_expertise_role', 'field_exp_rle_lng_rle')
      ->sourceMigration('ExpertiseRole');
  }

  public function complete($node, stdClass $row) {
    // Generate URL Redirects.
    parent::generateNodeRedirect($node, $row);
  }
}