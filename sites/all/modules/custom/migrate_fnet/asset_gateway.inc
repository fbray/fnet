<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/16/17
 * Time: 4:12 PM
 */

/*
 *  Asset Gateway Migration Class
*/
class FNETAssetGatewayMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity');

    // Individual Fields
    $this->addFieldMapping('field_ag_redirect', 'field_ag_redirect');
    $this->addFieldMapping('field_ag_redirect_wait', 'field_ag_redirect_wait');
    $this->addFieldMapping('field_add_download_button', 'field_add_download_button');
    $this->addFieldMapping('field_download_button', 'field_download_button_text');
    $this->addFieldMapping('field_adtracker', 'field_ag_tracking_code');
  }
}