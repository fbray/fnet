<?php
/**
 * User: rositis
 * Updated: 8/24/17
 * Time: 11:00 AM
 */

/*
 *  Asset Gateway Migration Class
*/
class FNETAssetGatewayMigration extends FNETNode7Migration {
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
    $this->addFieldMapping('field_ag_redirect_wait', 'field_ag_redirect_wait');
    $this->addFieldMapping('field_add_download_button', 'field_add_download_button');
    $this->addFieldMapping('field_download_button_text', 'field_download_button_text');
    $this->addFieldMapping('field_tracking_code', 'field_ag_tracking_code');
    $this->addFieldMapping('field_tracking_code:format', 'field_ag_tracking_code:format')
      ->defaultValue('full_html');

    // Link Fields
    $this->addFieldMapping('field_ag_redirect', 'field_ag_redirect');
    $this->addFieldMapping('field_ag_redirect:title', 'field_ag_redirect:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_ag_redirect:attributes', 'field_ag_redirect:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_ag_redirect:language', 'field_ag_redirect:language')
      ->defaultValue(LANGUAGE_NONE);
  }
}