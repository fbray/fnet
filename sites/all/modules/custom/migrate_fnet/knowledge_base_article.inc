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
class FNETKnowledgeBaseArticleMigration extends FNETNode7Migration {
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
    $this->addFieldMapping('field_article_author', 'field_article_author');  // Should be changed to node author. Really.

    // Entity References
    $this->addFieldMapping('field_knowledge_base', 'taxonomy_vocabulary_14')
      ->sourceMigration('KnowledgeBase');

    /* Tabled for this round 3/29/2018 - rositis
    // Metatags - Basic
    $this->addFieldMapping('metatag_title', 'metatag_title');
    $this->addFieldMapping('metatag_description', 'metatag_description');
    $this->addFieldMapping('metatag_abstract', 'metatag_abstract');
    $this->addFieldMapping('metatag_keywords', 'metatag_keywords');

    // Metatags - Advanced
    $this->addFieldMapping('metatag_robots', 'metatag_robots');
    $this->addFieldMapping('metatag_news_keywords', 'metatag_news_keywords');
    $this->addFieldMapping('metatag_standout', 'metatag_standout');
    $this->addFieldMapping('metatag_rating', 'metatag_rating');
    $this->addFieldMapping('metatag_referrer', 'metatag_referrer');
    $this->addFieldMapping('metatag_generator', 'metatag_generator');
    $this->addFieldMapping('metatag_rights', 'metatag_rights');
    $this->addFieldMapping('metatag_image_src', 'metatag_image_src');
    $this->addFieldMapping('metatag_canonical', 'metatag_canonical');
    $this->addFieldMapping('metatag_shortlink', 'metatag_shortlink');
    $this->addFieldMapping('metatag_original-source', 'metatag_original-source');
    $this->addFieldMapping('metatag_prev', 'metatag_prev');
    $this->addFieldMapping('metatag_next', 'metatag_next');
    $this->addFieldMapping('metatag_content-language', 'metatag_content-language');
    $this->addFieldMapping('metatag_geo.position', 'metatag_geo.position');
    $this->addFieldMapping('metatag_geo.placename', 'metatag_geo.placename');
    $this->addFieldMapping('metatag_geo.region', 'metatag_geo.region');
    $this->addFieldMapping('metatag_icbm', 'metatag_icbm');
    $this->addFieldMapping('metatag_refresh', 'metatag_refresh');
    $this->addFieldMapping('metatag_revisit-after', 'metatag_revisit-after');
    $this->addFieldMapping('metatag_pragma', 'metatag_pragma');
    $this->addFieldMapping('metatag_cache-control', 'metatag_cache-control');
    $this->addFieldMapping('metatag_expires', 'metatag_expires');

    // Metatags - OpenGraph
    $this->addFieldMapping('metatag_og:site_name', 'metatag_og:site_name');
    $this->addFieldMapping('metatag_og:type', 'metatag_og:type');
    $this->addFieldMapping('metatag_og:url', 'metatag_og:url');
    $this->addFieldMapping('metatag_og:title', 'metatag_og:title');
    $this->addFieldMapping('metatag_og:determiner', 'metatag_og:determiner');
    $this->addFieldMapping('metatag_og:description', 'metatag_og:description');

    // Metatags - Twitter Card
    $this->addFieldMapping('metatag_twitter:card', 'metatag_twitter:card');
    $this->addFieldMapping('metatag_twitter:site', 'metatag_twitter:site');
    $this->addFieldMapping('metatag_twitter:site:id', 'metatag_twitter:site:id');
    $this->addFieldMapping('metatag_twitter:creator', 'metatag_twitter:creator');
    $this->addFieldMapping('metatag_twitter:creator:id', 'metatag_twitter:creator:id');
    $this->addFieldMapping('metatag_twitter:url', 'metatag_twitter:url');
    $this->addFieldMapping('metatag_twitter:title', 'metatag_twitter:title');
    $this->addFieldMapping('metatag_twitter:description', 'metatag_twitter:description');
    $this->addFieldMapping('metatag_twitter:image', 'metatag_twitter:image');
    $this->addFieldMapping('metatag_twitter:image:width', 'metatag_twitter:image:width');

    // Metatags - hreflang
    $this->addFieldMapping('metatag_hreflang_xdefault', 'metatag_hreflang_xdefault');
    $this->addFieldMapping('metatag_hreflang_zh-hant', 'metatag_hreflang_zh-hant');
    $this->addFieldMapping('metatag_hreflang_en', 'metatag_hreflang_en');
    $this->addFieldMapping('metatag_hreflang_en-au', 'metatag_hreflang_en-au');
    $this->addFieldMapping('metatag_hreflang_en-gb', 'metatag_hreflang_en-gb');
    $this->addFieldMapping('metatag_hreflang_en-ca', 'metatag_hreflang_en-ca');
    $this->addFieldMapping('metatag_hreflang_en-us', 'metatag_hreflang_en-us');
    $this->addFieldMapping('metatag_hreflang_fr', 'metatag_hreflang_fr');
    $this->addFieldMapping('metatag_hreflang_fr-ca', 'metatag_hreflang_fr-ca');
    $this->addFieldMapping('metatag_hreflang_de', 'metatag_hreflang_de');
    $this->addFieldMapping('metatag_hreflang_it', 'metatag_hreflang_it');
    $this->addFieldMapping('metatag_hreflang_ja', 'metatag_hreflang_ja');
    $this->addFieldMapping('metatag_hreflang_ko', 'metatag_hreflang_ko');
    $this->addFieldMapping('metatag_hreflang_pt-br', 'metatag_hreflang_pt-br');
    $this->addFieldMapping('metatag_hreflang_pt', 'metatag_hreflang_pt');
    $this->addFieldMapping('metatag_hreflang_ru', 'metatag_hreflang_ru');
    $this->addFieldMapping('metatag_hreflang_es', 'metatag_hreflang_es');
    */
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