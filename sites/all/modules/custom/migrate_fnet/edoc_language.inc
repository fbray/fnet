<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/18/17
 * Time: 1:21 PM
 */

/*
 *  eDoc Language Migration Class
 *
 * Note: This will be deprecated and will move to the eDoc content type using
 * internationalization in the future.
*/
class FNETeDocLanguageMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated fields
    $this->addFieldMapping(NULL, 'field_business_entity');

    // Individual fields
    // Consolidate this into one common language field.
    $this->addFieldMapping('field_lang_lng', 'field_edoc_lang_lng');

    // TODO: Dependencies?
    // $this->addHardDependencies(array('FNETeDocMigration'));
  }
}