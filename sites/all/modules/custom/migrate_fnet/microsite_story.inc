<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/26/17
 * Time: 3:03 PM
 */

/*
 *  Microsite Story Migration Class
*/
class FNETMicrositeStoryMigration extends FNETNode7Migration {
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
    $this->addFieldMapping('body:language', 'body:language')
      ->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('field_display_title', 'field_display_title');
    $this->addFieldMapping('field_background_color', 'field_ms_story_bg_color');
    $this->addFieldMapping('weight', 'weight')
      ->defaultValue('0');

    // Image field
    $this->addFieldMapping('field_background_image', 'field_ms_story_bg_image')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_background_image:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_background_image:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_background_image:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_background_image:title')
      ->defaultValue(NULL);

    // Entity References
    $this->addFieldMapping('field_microsite', 'taxonomy_vocabulary_18')
      ->sourceMigration('Microsites');

  }

  /**
   * @return \QueryConditionInterface
   */
  protected function query() {
    $query = parent::query();

    // Join weight table
    $query->join('weight_weights', 'w', 'w.entity_id = n.nid');
    $query->fields('w', ['weight']);

    return $query;
  }

  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    print_r($row->weight);
    // $row->weight = $row->weight[0];

    // Check the various fields. Remove the hard URLs.
    $row->body = $this->stripDomain($row->body);
    $row->body = str_ireplace('/flukenetworks.com/files', '/default/files', $row->body);
    $row->body = str_ireplace('/flukenetworks.com/theme', '/all/theme', $row->body);
  }

  protected function stripDomain($string) {
    $stripped = str_ireplace(['https://www.flukenetworks.com/', 'http://www.flukenetworks.com/'], '/', $string);
    return $stripped;
  }
}