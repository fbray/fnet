<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/18/17
 * Time: 11:39 AM
 */

/*
 *  eDoc Migration Class
*/
class FNETeDocMigration extends FNETNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Redirects
    $this->addFieldMapping('migrate_redirects', 'path');

    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity')
      ->description(t('No longer necessary as NetScout split is complete.'))
      ->issueGroup(t('DNM'));

    // Individal fields
    $this->addFieldMapping('field_subtitle', 'field_edoc_subtitle');

    $this->addFieldMapping('field_literature_id_en', 'field_edoc_lid_en');
    $this->addFieldMapping('field_literature_id_fr', 'field_edoc_lid_fr');
    $this->addFieldMapping('field_literature_id_de', 'field_edoc_lid_de');
    $this->addFieldMapping('field_literature_id_es', 'field_edoc_lid_es');
    $this->addFieldMapping('field_literature_id_cn', 'field_edoc_lid_cn');
    $this->addFieldMapping('field_literature_id_jp', 'field_edoc_lid_jp');
    $this->addFieldMapping('field_literature_id_ko', 'field_edoc_lid_ko');
    $this->addFieldMapping('field_literature_id_pt', 'field_edoc_lid_pt');
    $this->addFieldMapping('field_literature_id_ru', 'field_edoc_lid_ru');

    // Entity References
    $this->addFieldMapping('field_edoc_type', 'taxonomy_vocabulary_13')
      ->sourceMigration('eDocType');
    $this->addFieldMapping('field_brand', 'taxonomy_vocabulary_12')
      ->sourceMigration('Brand');
    $this->addFieldMapping('field_products', 'field_edoc_prod')
      ->sourceMigration('ProductDisplay');

    // Metatags
  }
}

