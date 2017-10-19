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
class FNETeDocLanguageMigration extends FNETNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity')
      ->description(t('No longer necessary as NetScout split is complete.'))
      ->issueGroup(t('DNM'));

    // Individual fields
    $this->addFieldMapping('field_language_region', 'field_edoc_lang_lng');

    // Entity References
    $this->addFieldMapping('field_edoc', 'field_edoc_lang_edoc')
      ->sourceMigration('eDoc');

    // Metatags
  }

  public function complete($node, stdClass $row) {
    // Generate URL Redirects.
    parent::generateNodeRedirect($node, $row);
  }
}