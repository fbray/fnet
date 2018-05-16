<?php

/**
 * @file
 * fnet_site_search.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function fnet_site_search_views_default_views() {
  $views = array();

  // Exported view.
  $view = new view();
  $view->name = 'main_site_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_main_site_search';
  $view->human_name = 'Main Site Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search Results';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'search_api_views_cache';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'search_result';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'No Results';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<p>Your search has yielded no results.</p>';
  $handler->display->display_options['empty']['area']['format'] = '2';
  /* Field: Indexed Content: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_main_site_search';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_main_site_search';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_main_site_search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['operator'] = 'OR';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'term';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
    2 => '2',
    5 => 0,
    19 => 0,
    1 => 0,
    6 => 0,
    20 => 0,
    4 => 0,
    7 => 0,
    3 => 0,
    21 => 0,
    18 => 0,
    17 => 0,
    12 => 0,
    11 => 0,
    14 => 0,
    16 => 0,
    8 => 0,
    10 => 0,
    13 => 0,
    15 => 0,
    9 => 0,
    22 => 0,
    23 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'metatag_abstract' => 'metatag_abstract',
    'metatag_cache-control' => 'metatag_cache-control',
    'metatag_content-language' => 'metatag_content-language',
    'metatag_description' => 'metatag_description',
    'metatag_expires' => 'metatag_expires',
    'metatag_generator' => 'metatag_generator',
    'metatag_geo.placename' => 'metatag_geo.placename',
    'metatag_geo.position' => 'metatag_geo.position',
    'metatag_geo.region' => 'metatag_geo.region',
    'metatag_icbm' => 'metatag_icbm',
    'metatag_keywords' => 'metatag_keywords',
    'metatag_news_keywords' => 'metatag_news_keywords',
    'metatag_original-source' => 'metatag_original-source',
    'metatag_pragma' => 'metatag_pragma',
    'metatag_rating' => 'metatag_rating',
    'metatag_referrer' => 'metatag_referrer',
    'metatag_refresh' => 'metatag_refresh',
    'metatag_revisit-after' => 'metatag_revisit-after',
    'metatag_rights' => 'metatag_rights',
    'metatag_robots' => 'metatag_robots',
    'metatag_standout' => 'metatag_standout',
    'metatag_title' => 'metatag_title',
    'title' => 'title',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'site-search';

  $views[$view->name] = $view;
  return $views;
}
