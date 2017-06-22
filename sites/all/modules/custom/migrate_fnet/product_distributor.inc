<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/18/17
 * Time: 11:32 AM
 */

/*
 *  Distributor Migration Class
*/
class FNETProductDistributorMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    $this->addFieldMapping(NULL, 'field_business_entity');

    // Node Reference
    // TODO: Migrate this to Entity Reference?

    // Migrate the fieldset

    // Individual fields
    // TODO: This is a WTF?! Should this just be Node Status? Hmm.
    $this->addFieldMapping('field_custom_publish_content', 'field_custom_publish_content');
  }
}