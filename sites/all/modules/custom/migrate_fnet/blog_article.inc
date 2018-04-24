<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/16/17
 * Time: 4:36 PM
 */
/*
 *  Blog Article Migration Class
*/
class FNETBlogArticleMigration extends FNETNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Path Alias
    $this->addFieldMapping('path', 'path');

    // Disable Pathauto for now.
    $this->addFieldMapping('pathauto')->defaultValue(0);

    // Redirects
    $this->addFieldMapping('migrate_redirects', 'path');

    // Individual fields
    $this->addFieldMapping('body:language', 'body:language');
    $this->addFieldMapping('body:format')
      ->defaultValue('full_html');

    // Entity References
    $this->addFieldMapping('field_blog_categories', 'taxonomy_vocabulary_16')
      ->sourceMigration('BlogCategories');
    $this->addFieldMapping('field_blog_tags', 'taxonomy_vocabulary_17')
      ->sourceMigration('BlogTags');
  }

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