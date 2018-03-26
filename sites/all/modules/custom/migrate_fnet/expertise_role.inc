<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/18/17
 * Time: 3:41 PM
 */

/*
 *  Expertise Role Migration Class
*/
class FNETExpertiseRoleMigration extends FNETNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity')
      ->description(t('No longer necessary as NetScout split is complete.'))
      ->issueGroup(t('DNM'));

    // Individual Fields
    $this->addFieldMapping('field_exp_rle_banner_content', 'field_exp_rle_banner_content');
    $this->addFieldMapping('field_exp_rle_banner_content:format', 'field_exp_rle_banner_content:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_exp_rle_tab_title', 'field_exp_rle_tab_title');
    $this->addFieldMapping('field_exp_rle_tab_content', 'field_exp_rle_tab_content');
    $this->addFieldMapping('field_exp_rle_tab_content:format', 'field_exp_rle_tab_content:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_exp_rle_tab2_title', 'field_exp_rle_tab2_title');
    $this->addFieldMapping('field_exp_rle_tab2_content', 'field_exp_rle_tab2_content');
    $this->addFieldMapping('field_exp_rle_tab2_content:format', 'field_exp_rle_tab2_content:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_exp_rle_tab3_title', 'field_exp_rle_tab3_title');
    $this->addFieldMapping('field_exp_rle_tab3_content', 'field_exp_rle_tab3_content');
    $this->addFieldMapping('field_exp_rle_tab3_content:format', 'field_exp_rle_tab3_content:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_exp_rle_tab4_title', 'field_exp_rle_tab4_title');
    $this->addFieldMapping('field_exp_rle_tab4_content', 'field_exp_rle_tab4_content');
    $this->addFieldMapping('field_exp_rle_tab4_content:format', 'field_exp_rle_tab4_content:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_exp_rle_region', 'field_exp_rle_region');
    $this->addFieldMapping('field_tracking_code', 'field_tracking_code'); // Move to common ad tracker field.


    // Image Fields
    $this->addFieldMapping('field_exp_rle_thumbnail', 'field_exp_rle_thumbnail')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_exp_rle_thumbnail:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_exp_rle_thumbnail:alt', 'field_exp_rle_thumbnail:alt');
    $this->addFieldMapping('field_exp_rle_thumbnail:title', 'field_exp_rle_thumbnail:title');

    $this->addFieldMapping('field_exp_rle_banner_image', 'field_exp_rle_banner_image')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_exp_rle_banner_image:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_exp_rle_banner_image:alt', 'field_exp_rle_banner_image');
    $this->addFieldMapping('field_exp_rle_banner_image:title', 'field_exp_rle_banner_image');

    // Metatags
  }

  // TODO: File paths in body and other fields.
  public function complete($node, stdClass $row) {
    // Generate URL Redirects.
    parent::generateNodeRedirect($node, $row);
  }
}