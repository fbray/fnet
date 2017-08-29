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
class FNETBlogArticleMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Entity References
    $this->addFieldMapping('field_blog_categories', 'taxonomy_vocabulary_16')
      ->sourceMigration('BlogCategories');
    $this->addFieldMapping('field_blog_tags', 'taxonomy_vocabulary_17')
      ->sourceMigration('BlogTags');
  }
}