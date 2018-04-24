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

    $this->addFieldMapping(NULL, 'taxonomy_vocabulary_12')
      ->description(t('Only the Fluke Networks brand is used.'))
      ->issueGroup(t('DNM'));

    // Individal fields
    $this->addFieldMapping('body:language', 'body:language');
    $this->addFieldMapping('body:format')
      ->defaultValue('full_html');
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
      ->sourceMigration('eDocTypes');
    $this->addFieldMapping('field_related_products', 'field_edoc_prod')
      ->sourceMigration('ProductDisplay');

    // Metatags
  }

  /**
   * Implementation of prepareRow()
   *
   * @param $row
   * @return bool
   */
  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $row->body = $this->stripDomain($row->body);
    $row->body = str_ireplace('/flukenetworks.com/files', '/default/files', $row->body);
    $row->body = str_ireplace('/flukenetworks.com/theme', '/all/theme', $row->body);
  }

  protected function stripDomain($string) {
    $domains = ['http://www.flukenetworks.com/', 'https://www.flukenetworks.com/', 'http://flukenetworks.com/', 'https://flukenetworks.com/'];
    $stripped = str_ireplace($domains, '/', $string);
    return $stripped;
  }
}

