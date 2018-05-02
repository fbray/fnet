<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/18/17
 * Time: 2:52 PM
 */

/*
 *  Expertise Migration Class
*/
class FNETExpertiseMigration extends FNETNode7Migration {
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
    $this->addFieldMapping('body:language', 'body:language');
    $this->addFieldMapping('field_intro', 'field_expertise_intro');
    $this->addFieldMapping('field_intro:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_intro:language', 'language')
      ->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('field_expertise_related_content', 'field_expertise_relatedcontent');
    $this->addFieldMapping('field_expertise_related_content:language', 'field_expertise_relatedcontent:language');
    $this->addFieldMapping('field_expertise_related_content:format')
      ->defaultValue('full_html');

    // Convert this one to use the Weight module.
    $this->addFieldMapping('weight', 'field_expertise_sortorder');

    // Image Fields
    $this->addFieldMapping('field_expertise_image', 'field_expertise_image')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_expertise_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_expertise_image:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_expertise_image:alt', 'field_expertise_image:alt');
    $this->addFieldMapping('field_expertise_image:title', 'field_expertise_image:title');

    // Entity References
    $this->addFieldMapping('field_expertise_types', 'taxonomy_vocabulary_8')  // Taxonomy Term
    ->sourceMigration('ExpertiseTypes');
    $this->addFieldMapping('field_industry', 'field_expertise_industry')  // Taxonomy term
      ->sourceMigration('Industries');
    $this->addFieldMapping('field_products', 'field_expertise_product') // Node
      ->sourceMigration('ProductDisplay');
    $this->addFieldMapping('field_product_category', 'field_expertise_industry') // Node
    ->sourceMigration('ProductCategory');

  }

  /**
   * @param $row
   * @return bool
   */
  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    // Remove the extra zero off of the sort order field to accomodate the weight field.
    if (!is_null($row->field_expertise_sortorder)) {
      $row->field_expertise_sortorder = ($row->field_expertise_sortorder[0] / 10);
    }

    // Check the various fields. Remove the hard URLs.
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