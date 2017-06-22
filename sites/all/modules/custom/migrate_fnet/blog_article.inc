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

    // Taxonomy References
    $this->addFieldMapping('field_blog_categories', 'taxonomy_vocabulary_16')
      ->sourceMigration('BlogCategories');
    $this->addFieldMapping('field_blog_categories:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_blog_categories:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_blog_categories:ignore_case')
      ->defaultValue(TRUE);

    $this->addFieldMapping('field_blog_tags', 'taxonomy_vocabulary_17')
      ->sourceMigration('BlogTags');
    $this->addFieldMapping('field_blog_tags:source_type')
      ->defaultValue('tid');
    $this->addFieldMapping('field_blog_tags:create_term')
      ->defaultValue(FALSE);
    $this->addFieldMapping('field_blog_tags:ignore_case')
      ->defaultValue(TRUE);
  }
}