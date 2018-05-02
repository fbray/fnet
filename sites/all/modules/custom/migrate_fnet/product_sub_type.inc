<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/26/17
 * Time: 3:14 PM
 */

/*
 *  Product Sub Type Migration Class
*/
class FNETProductSubTypeMigration extends DrupalNode7Migration {
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
    $this->addFieldMapping('weight', 'field_productsub_sortorder');
    $this->addFieldMapping('body:language', 'body:language')
      ->defaultValue(LANGUAGE_NONE);

    // Image Fields
    $this->addFieldMapping('field_image', 'field_productsub_image')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_image:alt', 'field_productsub_image:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_image:title', 'field_productsub_image:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_image:file_class')
      ->defaultValue('MigrateFileFid');

    // Entity References
    // Product Sub Types Taxonomy
    $this->addFieldMapping('field_product_sub_types', 'taxonomy_vocabulary_2')
      ->sourceMigration('ProductSubtypes');

    // Uses Product Content: Gold Support Contracts references view for nodes that can be referenced.
    $this->addFieldMapping('field_available_support_options', 'field_support_options')
      ->sourceMigration('ProductSubType');

    $this->addFieldMapping('field_related_products', 'field_productsub_product')
      ->sourceMigration('ProductDisplay');

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
    // Remove the extra zero off of the sort order field to accomodate the weight field.
    if (!is_null($row->field_productsub_sortorder)) {
      $row->field_productsub_sortorder = ($row->field_productsub_sortorder[0] / 10);
    }
    // Strip out <strong></strong> tags from the title.
    $html = ['<strong>', '</strong>'];
    $row->title = str_ireplace($html, '', $row->title);

    $row->body = $this->stripDomain($row->body);
    $row->body = str_ireplace('/flukenetworks.com/files', '/default/files', $row->body);
    $row->body = str_ireplace('/flukenetworks.com/theme', '/all/theme', $row->body);
  }

  /**
   * Remove the hard-coded Fluke Networks domain from a field.
   *
   * @param $string
   * @return mixed
   */
  protected function stripDomain($string) {
    $domains = ['http://www.flukenetworks.com/', 'https://www.flukenetworks.com/', 'http://flukenetworks.com/', 'https://flukenetworks.com/'];
    $stripped = str_ireplace($domains, '/', $string);
    return $stripped;
  }
}