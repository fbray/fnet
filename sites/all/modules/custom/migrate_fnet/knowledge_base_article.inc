<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/23/17
 * Time: 1:33 PM
 */

/*
 *  Knowledge Base Article Migration Class
*/
class FNETKnowledgeBaseArticleMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity');

    // Individual Fields
    $this->addFieldMapping('field_article_author', 'field_article_author');  // Should be changed to node author. Really.

    // Entity References
    $this->addFieldMapping('field_knowledge_base', 'taxonomy_vocabulary_14')
      ->sourceMigration('KnowledgeBase');
  }
}