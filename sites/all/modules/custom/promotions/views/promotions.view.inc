<?php

/**
 * @file
 * promotions.view.inc
 */

$view = new view();
$view->name = 'promotions';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Promotions';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Free Software Trials';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['group_by'] = TRUE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '3600';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '3600';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['style_options']['grouping'] = array(
  0 => array(
    'field' => 'field_promotion_type',
    'rendered' => 1,
    'rendered_strip' => 0,
  ),
);
$handler->display->display_options['row_plugin'] = 'fields';
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
/* Relationship: File Usage: File */
$handler->display->display_options['relationships']['node_to_file']['id'] = 'node_to_file';
$handler->display->display_options['relationships']['node_to_file']['table'] = 'file_usage';
$handler->display->display_options['relationships']['node_to_file']['field'] = 'node_to_file';
/* Field: Content: Promotion Type */
$handler->display->display_options['fields']['field_promotion_type']['id'] = 'field_promotion_type';
$handler->display->display_options['fields']['field_promotion_type']['table'] = 'field_data_field_promotion_type';
$handler->display->display_options['fields']['field_promotion_type']['field'] = 'field_promotion_type';
$handler->display->display_options['fields']['field_promotion_type']['label'] = '';
$handler->display->display_options['fields']['field_promotion_type']['exclude'] = TRUE;
$handler->display->display_options['fields']['field_promotion_type']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_promotion_type']['settings'] = array(
  'bypass_access' => 0,
  'link' => 0,
);
/* Field: Content: External URL */
$handler->display->display_options['fields']['field_external_url']['id'] = 'field_external_url';
$handler->display->display_options['fields']['field_external_url']['table'] = 'field_data_field_external_url';
$handler->display->display_options['fields']['field_external_url']['field'] = 'field_external_url';
$handler->display->display_options['fields']['field_external_url']['label'] = '';
$handler->display->display_options['fields']['field_external_url']['element_type'] = '0';
$handler->display->display_options['fields']['field_external_url']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_external_url']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_external_url']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['field_external_url']['click_sort_column'] = 'url';
$handler->display->display_options['fields']['field_external_url']['type'] = 'link_plain';
$handler->display->display_options['fields']['field_external_url']['group_column'] = 'url';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Intro */
$handler->display->display_options['fields']['field_intro']['id'] = 'field_intro';
$handler->display->display_options['fields']['field_intro']['table'] = 'field_data_field_intro';
$handler->display->display_options['fields']['field_intro']['field'] = 'field_intro';
$handler->display->display_options['fields']['field_intro']['label'] = '';
$handler->display->display_options['fields']['field_intro']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_intro']['type'] = 'text_plain';
$handler->display->display_options['fields']['field_intro']['settings'] = array(
  'field_formatter_filter' => '',
);
/* Field: Content: Promotion Date */
$handler->display->display_options['fields']['field_promotion_date']['id'] = 'field_promotion_date';
$handler->display->display_options['fields']['field_promotion_date']['table'] = 'field_data_field_promotion_date';
$handler->display->display_options['fields']['field_promotion_date']['field'] = 'field_promotion_date';
$handler->display->display_options['fields']['field_promotion_date']['label'] = '';
$handler->display->display_options['fields']['field_promotion_date']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_promotion_date']['alter']['text'] = 'Expires [field_promotion_date]';
$handler->display->display_options['fields']['field_promotion_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_promotion_date']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_promotion_date']['settings'] = array(
  'format_type' => 'long',
  'custom_date_format' => '',
  'fromto' => 'value2',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
);
$handler->display->display_options['fields']['field_promotion_date']['group_columns'] = array(
  'value2' => 'value2',
);
/* Field: File: Path */
$handler->display->display_options['fields']['uri']['id'] = 'uri';
$handler->display->display_options['fields']['uri']['table'] = 'file_managed';
$handler->display->display_options['fields']['uri']['field'] = 'uri';
$handler->display->display_options['fields']['uri']['relationship'] = 'node_to_file';
$handler->display->display_options['fields']['uri']['label'] = '';
$handler->display->display_options['fields']['uri']['element_type'] = '0';
$handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['uri']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
/* Sort criterion: Weight: Weight */
$handler->display->display_options['sorts']['weight']['id'] = 'weight';
$handler->display->display_options['sorts']['weight']['table'] = 'weight_weights';
$handler->display->display_options['sorts']['weight']['field'] = 'weight';
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'promotion' => 'promotion',
);
/* Filter criterion: Content: RegLang Filter */
$handler->display->display_options['filters']['region_language']['id'] = 'region_language';
$handler->display->display_options['filters']['region_language']['table'] = 'node';
$handler->display->display_options['filters']['region_language']['field'] = 'region_language';
/* Filter criterion: Content: Promotion Date - end date (field_promotion_date:value2) */
$handler->display->display_options['filters']['field_promotion_date_value2']['id'] = 'field_promotion_date_value2';
$handler->display->display_options['filters']['field_promotion_date_value2']['table'] = 'field_data_field_promotion_date';
$handler->display->display_options['filters']['field_promotion_date_value2']['field'] = 'field_promotion_date_value2';
$handler->display->display_options['filters']['field_promotion_date_value2']['operator'] = '>=';
$handler->display->display_options['filters']['field_promotion_date_value2']['form_type'] = 'date_text';
$handler->display->display_options['filters']['field_promotion_date_value2']['default_date'] = 'now';

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Promotions';
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'There are no active Promotions at this time. Check back later.';
$handler->display->display_options['empty']['area']['format'] = 'plain_text';
$handler->display->display_options['metatags'] = array(
  'und' => array(
    'title' => array(
      'value' => '[view:title] | [current-page:pager][site:name]',
      'default' => '[view:title] | [current-page:pager][site:name]',
    ),
    'description' => array(
      'value' => 'At Fluke Networks get special offers, free trials and rebates. Customer can purchase promotions DTX2Versiv 2018 Service and Calibration till June 29, 2018, Take Advantage of FREE LinkWare Live Trial! , Try-N-Buy Versiv Cabling Certification Products.',
      'default' => '[view:description]',
    ),
    'abstract' => array(
      'value' => '',
    ),
    'keywords' => array(
      'value' => '',
    ),
    'robots' => array(
      'value' => array(
        'index' => 0,
        'follow' => 0,
        'noindex' => 0,
        'nofollow' => 0,
        'noarchive' => 0,
        'nosnippet' => 0,
        'noodp' => 0,
        'noydir' => 0,
        'noimageindex' => 0,
        'notranslate' => 0,
      ),
    ),
    'news_keywords' => array(
      'value' => '',
    ),
    'standout' => array(
      'value' => '',
    ),
    'rating' => array(
      'value' => '',
    ),
    'referrer' => array(
      'value' => '',
    ),
    'rights' => array(
      'value' => '',
    ),
    'image_src' => array(
      'value' => '',
    ),
    'canonical' => array(
      'value' => '[view:url]',
      'default' => '[view:url]',
    ),
    'set_cookie' => array(
      'value' => '',
    ),
    'shortlink' => array(
      'value' => '[current-page:url:unaliased]',
      'default' => '[current-page:url:unaliased]',
    ),
    'original-source' => array(
      'value' => '',
    ),
    'prev' => array(
      'value' => '',
    ),
    'next' => array(
      'value' => '',
    ),
    'content-language' => array(
      'value' => '',
    ),
    'geo.position' => array(
      'value' => '',
    ),
    'geo.placename' => array(
      'value' => '',
    ),
    'geo.region' => array(
      'value' => '',
    ),
    'icbm' => array(
      'value' => '',
    ),
    'refresh' => array(
      'value' => '',
    ),
    'revisit-after' => array(
      'value' => '',
      'period' => '',
    ),
    'pragma' => array(
      'value' => '',
    ),
    'cache-control' => array(
      'value' => '',
    ),
    'expires' => array(
      'value' => '',
    ),
    'hreflang_xdefault' => array(
      'value' => '',
    ),
    'hreflang_zh-hans' => array(
      'value' => '',
    ),
    'hreflang_zh-hant' => array(
      'value' => '',
    ),
    'hreflang_en' => array(
      'value' => '',
    ),
    'hreflang_en-au' => array(
      'value' => '',
    ),
    'hreflang_en-gb' => array(
      'value' => '',
    ),
    'hreflang_en-ca' => array(
      'value' => '',
    ),
    'hreflang_en-us' => array(
      'value' => '',
    ),
    'hreflang_fr' => array(
      'value' => '',
    ),
    'hreflang_ar' => array(
      'value' => '',
    ),
    'hreflang_fr-ca' => array(
      'value' => '',
    ),
    'hreflang_de' => array(
      'value' => '',
    ),
    'hreflang_it' => array(
      'value' => '',
    ),
    'hreflang_ja' => array(
      'value' => '',
    ),
    'hreflang_ko' => array(
      'value' => '',
    ),
    'hreflang_pt-br' => array(
      'value' => '',
    ),
    'hreflang_pt' => array(
      'value' => '',
    ),
    'hreflang_ru' => array(
      'value' => '',
    ),
    'hreflang_es' => array(
      'value' => '',
    ),
    'og:type' => array(
      'value' => 'article',
      'default' => 'article',
    ),
    'og:url' => array(
      'value' => '[current-page:url:absolute]',
      'default' => '[current-page:url:absolute]',
    ),
    'og:title' => array(
      'value' => '[current-page:title]',
      'default' => '[current-page:title]',
    ),
    'og:determiner' => array(
      'value' => '',
    ),
    'og:description' => array(
      'value' => '',
    ),
    'og:updated_time' => array(
      'value' => '',
    ),
    'og:see_also' => array(
      'value' => '',
    ),
    'og:image' => array(
      'value' => '',
    ),
    'og:image:url' => array(
      'value' => '',
    ),
    'og:image:secure_url' => array(
      'value' => '',
    ),
    'og:image:type' => array(
      'value' => '',
    ),
    'og:image:width' => array(
      'value' => '',
    ),
    'og:image:height' => array(
      'value' => '',
    ),
    'og:latitude' => array(
      'value' => '',
    ),
    'og:longitude' => array(
      'value' => '',
    ),
    'og:street_address' => array(
      'value' => '',
    ),
    'og:locality' => array(
      'value' => '',
    ),
    'og:region' => array(
      'value' => '',
    ),
    'og:postal_code' => array(
      'value' => '',
    ),
    'og:country_name' => array(
      'value' => '',
    ),
    'og:email' => array(
      'value' => '',
    ),
    'og:phone_number' => array(
      'value' => '',
    ),
    'og:fax_number' => array(
      'value' => '',
    ),
    'og:locale' => array(
      'value' => '',
    ),
    'og:locale:alternate' => array(
      'value' => '',
    ),
    'article:author' => array(
      'value' => '',
    ),
    'article:publisher' => array(
      'value' => '',
    ),
    'article:section' => array(
      'value' => '',
    ),
    'article:tag' => array(
      'value' => '',
    ),
    'article:published_time' => array(
      'value' => '',
    ),
    'article:modified_time' => array(
      'value' => '',
    ),
    'article:expiration_time' => array(
      'value' => '',
    ),
    'profile:first_name' => array(
      'value' => '',
    ),
    'profile:last_name' => array(
      'value' => '',
    ),
    'profile:username' => array(
      'value' => '',
    ),
    'profile:gender' => array(
      'value' => '',
    ),
    'og:audio' => array(
      'value' => '',
    ),
    'og:audio:secure_url' => array(
      'value' => '',
    ),
    'og:audio:type' => array(
      'value' => '',
    ),
    'book:author' => array(
      'value' => '',
    ),
    'book:isbn' => array(
      'value' => '',
    ),
    'book:release_date' => array(
      'value' => '',
    ),
    'book:tag' => array(
      'value' => '',
    ),
    'og:video:url' => array(
      'value' => '',
    ),
    'og:video:secure_url' => array(
      'value' => '',
    ),
    'og:video:width' => array(
      'value' => '',
    ),
    'og:video:height' => array(
      'value' => '',
    ),
    'og:video:type' => array(
      'value' => '',
    ),
    'video:actor' => array(
      'value' => '',
    ),
    'video:actor:role' => array(
      'value' => '',
    ),
    'video:director' => array(
      'value' => '',
    ),
    'video:writer' => array(
      'value' => '',
    ),
    'video:duration' => array(
      'value' => '',
    ),
    'video:release_date' => array(
      'value' => '',
    ),
    'video:tag' => array(
      'value' => '',
    ),
    'video:series' => array(
      'value' => '',
    ),
    'twitter:card' => array(
      'value' => 'summary',
      'default' => 'summary',
    ),
    'twitter:creator' => array(
      'value' => '',
    ),
    'twitter:creator:id' => array(
      'value' => '',
    ),
    'twitter:url' => array(
      'value' => '[current-page:url:absolute]',
      'default' => '[current-page:url:absolute]',
    ),
    'twitter:title' => array(
      'value' => '[current-page:title]',
      'default' => '[current-page:title]',
    ),
    'twitter:description' => array(
      'value' => '',
    ),
    'twitter:dnt' => array(
      'value' => '',
    ),
    'twitter:image' => array(
      'value' => '',
    ),
    'twitter:image:width' => array(
      'value' => '',
    ),
    'twitter:image:height' => array(
      'value' => '',
    ),
    'twitter:image:alt' => array(
      'value' => '',
    ),
    'twitter:image0' => array(
      'value' => '',
    ),
    'twitter:image1' => array(
      'value' => '',
    ),
    'twitter:image2' => array(
      'value' => '',
    ),
    'twitter:image3' => array(
      'value' => '',
    ),
    'twitter:player' => array(
      'value' => '',
    ),
    'twitter:player:width' => array(
      'value' => '',
    ),
    'twitter:player:height' => array(
      'value' => '',
    ),
    'twitter:player:stream' => array(
      'value' => '',
    ),
    'twitter:player:stream:content_type' => array(
      'value' => '',
    ),
    'twitter:app:country' => array(
      'value' => '',
    ),
    'twitter:app:name:iphone' => array(
      'value' => '',
    ),
    'twitter:app:id:iphone' => array(
      'value' => '',
    ),
    'twitter:app:url:iphone' => array(
      'value' => '',
    ),
    'twitter:app:name:ipad' => array(
      'value' => '',
    ),
    'twitter:app:id:ipad' => array(
      'value' => '',
    ),
    'twitter:app:url:ipad' => array(
      'value' => '',
    ),
    'twitter:app:name:googleplay' => array(
      'value' => '',
    ),
    'twitter:app:id:googleplay' => array(
      'value' => '',
    ),
    'twitter:app:url:googleplay' => array(
      'value' => '',
    ),
    'twitter:label1' => array(
      'value' => '',
    ),
    'twitter:data1' => array(
      'value' => '',
    ),
    'twitter:label2' => array(
      'value' => '',
    ),
    'twitter:data2' => array(
      'value' => '',
    ),
  ),
);
$handler->display->display_options['path'] = 'promotions';

/* Display: Free Software Trials */
$handler = $view->new_display('page', 'Free Software Trials', 'page_1');
$handler->display->display_options['defaults']['group_by'] = FALSE;
$handler->display->display_options['defaults']['empty'] = FALSE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['empty'] = TRUE;
$handler->display->display_options['empty']['area']['content'] = 'There are no active Software Trials at this time. Check back later.';
$handler->display->display_options['empty']['area']['format'] = 'plain_text';
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: External URL */
$handler->display->display_options['fields']['field_external_url']['id'] = 'field_external_url';
$handler->display->display_options['fields']['field_external_url']['table'] = 'field_data_field_external_url';
$handler->display->display_options['fields']['field_external_url']['field'] = 'field_external_url';
$handler->display->display_options['fields']['field_external_url']['label'] = '';
$handler->display->display_options['fields']['field_external_url']['element_type'] = '0';
$handler->display->display_options['fields']['field_external_url']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_external_url']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['field_external_url']['hide_alter_empty'] = FALSE;
$handler->display->display_options['fields']['field_external_url']['click_sort_column'] = 'url';
$handler->display->display_options['fields']['field_external_url']['type'] = 'link_plain';
$handler->display->display_options['fields']['field_external_url']['group_column'] = 'url';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Content: Intro */
$handler->display->display_options['fields']['field_intro']['id'] = 'field_intro';
$handler->display->display_options['fields']['field_intro']['table'] = 'field_data_field_intro';
$handler->display->display_options['fields']['field_intro']['field'] = 'field_intro';
$handler->display->display_options['fields']['field_intro']['label'] = '';
$handler->display->display_options['fields']['field_intro']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_intro']['type'] = 'text_plain';
$handler->display->display_options['fields']['field_intro']['settings'] = array(
  'field_formatter_filter' => '',
);
/* Field: Content: Promotion Date */
$handler->display->display_options['fields']['field_promotion_date']['id'] = 'field_promotion_date';
$handler->display->display_options['fields']['field_promotion_date']['table'] = 'field_data_field_promotion_date';
$handler->display->display_options['fields']['field_promotion_date']['field'] = 'field_promotion_date';
$handler->display->display_options['fields']['field_promotion_date']['label'] = '';
$handler->display->display_options['fields']['field_promotion_date']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['field_promotion_date']['alter']['text'] = 'Expires [field_promotion_date]';
$handler->display->display_options['fields']['field_promotion_date']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_promotion_date']['hide_empty'] = TRUE;
$handler->display->display_options['fields']['field_promotion_date']['settings'] = array(
  'format_type' => 'long',
  'custom_date_format' => '',
  'fromto' => 'value2',
  'multiple_number' => '',
  'multiple_from' => '',
  'multiple_to' => '',
  'show_remaining_days' => 0,
);
$handler->display->display_options['fields']['field_promotion_date']['group_columns'] = array(
  'value2' => 'value2',
);
/* Field: File: Path */
$handler->display->display_options['fields']['uri']['id'] = 'uri';
$handler->display->display_options['fields']['uri']['table'] = 'file_managed';
$handler->display->display_options['fields']['uri']['field'] = 'uri';
$handler->display->display_options['fields']['uri']['relationship'] = 'node_to_file';
$handler->display->display_options['fields']['uri']['label'] = '';
$handler->display->display_options['fields']['uri']['element_type'] = '0';
$handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['uri']['element_default_classes'] = FALSE;
$handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'promotion' => 'promotion',
);
/* Filter criterion: Content: RegLang Filter */
$handler->display->display_options['filters']['region_language']['id'] = 'region_language';
$handler->display->display_options['filters']['region_language']['table'] = 'node';
$handler->display->display_options['filters']['region_language']['field'] = 'region_language';
/* Filter criterion: Content: Promotion Date - end date (field_promotion_date:value2) */
$handler->display->display_options['filters']['field_promotion_date_value2']['id'] = 'field_promotion_date_value2';
$handler->display->display_options['filters']['field_promotion_date_value2']['table'] = 'field_data_field_promotion_date';
$handler->display->display_options['filters']['field_promotion_date_value2']['field'] = 'field_promotion_date_value2';
$handler->display->display_options['filters']['field_promotion_date_value2']['operator'] = '>=';
$handler->display->display_options['filters']['field_promotion_date_value2']['form_type'] = 'date_text';
$handler->display->display_options['filters']['field_promotion_date_value2']['default_date'] = 'now';
/* Filter criterion: Content: Promotion Type (field_promotion_type) */
$handler->display->display_options['filters']['field_promotion_type_target_id']['id'] = 'field_promotion_type_target_id';
$handler->display->display_options['filters']['field_promotion_type_target_id']['table'] = 'field_data_field_promotion_type';
$handler->display->display_options['filters']['field_promotion_type_target_id']['field'] = 'field_promotion_type_target_id';
$handler->display->display_options['filters']['field_promotion_type_target_id']['value'] = array(
  699 => '699',
);
$handler->display->display_options['path'] = 'free-software-trials-downloads';
