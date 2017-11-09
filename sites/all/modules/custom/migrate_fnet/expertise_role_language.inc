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
    // Redirects
    $this->addFieldMapping('migrate_redirects', 'path');

    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity')
      ->description(t('No longer necessary as NetScout split is complete.'))
      ->issueGroup(t('DNM'));

    // Individual Fields
    $this->addFieldMapping('field_language_region', 'field_exp_rle_lng_lng');
    $this->addFieldMapping('field_exp_rle_banner_content', 'field_exp_rle_lng_banner_content');

    $this->addFieldMapping('field_exp_rle_tab_title', 'field_exp_rle_lng_tab_title');
    $this->addFieldMapping('field_exp_rle_tab_content', 'field_exp_rle_lng_tab_content');

    $this->addFieldMapping('field_exp_rle_tab2_title', 'field_exp_rle_lng_tab2_title');
    $this->addFieldMapping('field_exp_rle_tab2_content', 'field_exp_rle_lng_tab2_content');

    $this->addFieldMapping('field_exp_rle_tab3_title', 'field_exp_rle_lng_tab3_title');
    $this->addFieldMapping('field_exp_rle_tab3_content', 'field_exp_rle_lng_tab3_content');

    $this->addFieldMapping('field_exp_rle_tab4_title', 'field_exp_rle_lng_tab4_title');
    $this->addFieldMapping('field_exp_rle_tab4_content', 'field_exp_rle_lng_tab4_content');


    // Image Fields
    $this->addFieldMapping('field_exp_rle_banner_image', 'field_exp_rle_lng_banner_image')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_exp_rle_banner_image:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_exp_rle_banner_image:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_exp_rle_banner_image:title')
      ->defaultValue(NULL);

    // Entity Reference Fields
    $this->addFieldMapping('field_expertise_role', 'field_exp_rle_lng_rle')
      ->sourceMigration('ExpertiseRole');
  }

  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // The language/region thing seems to be problematic with the allowed values.
    // Let's trim it down to just the first five characters.
    $row->field_exp_rle_lng_lng[0] = substr($row->field_exp_rle_lng_lng[0], 0, 5);

  }
}