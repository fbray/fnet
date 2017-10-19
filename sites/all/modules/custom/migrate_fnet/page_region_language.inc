<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/26/17
 * Time: 3:10 PM
 */

/*
 *  Page Region Language Migration Class
*/
class FNETPageRegionLanguageMigration extends FNETNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity')
      ->description(t('No longer necessary as NetScout split is complete.'))
      ->issueGroup(t('DNM'));

    // Individual Fields
    $this->addFieldMapping('field_language_region', 'field_page_reg_lang_lng');
    $this->addFieldMapping('field_tracking_code', 'field_page_adtracker');

    // Entity References
    $this->addFieldMapping('field_page_region', 'field_page_reg_lang_pagereg')
      ->sourceMigration('PageRegion');
  }

  public function complete($node, stdClass $row) {
    // Generate URL Redirects.
    parent::generateNodeRedirect($node, $row);
  }
}