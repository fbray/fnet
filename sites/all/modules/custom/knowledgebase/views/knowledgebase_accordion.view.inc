<?php

/**
 * @file
 * knowledgebase_accordion.view.inc
 *
 * The block from this view provides the accordian of terms for the
 * Knowledge Base article listing at /knowledge-base.
 */

$view = new view();
$view->name = 'knowledge_base_accordion';
$view->description = 'Display KB taxonomy in accordion format in a block.';
$view->tag = 'fnet';
$view->base_table = 'taxonomy_term_data';
$view->human_name = 'Knowledge Base Accordion';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Browse by Category';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '21600';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '21600';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['style_plugin'] = 'views_accordion';
$handler->display->display_options['style_options']['grouping'] = array(
  0 => array(
    'field' => 'name_1',
    'rendered' => 1,
    'rendered_strip' => 0,
  ),
);
$handler->display->display_options['style_options']['use-grouping-header'] = 1;
$handler->display->display_options['style_options']['collapsible'] = 1;
$handler->display->display_options['style_options']['row-start-open'] = 'none';
$handler->display->display_options['row_plugin'] = 'fields';
/* Relationship: Taxonomy term: Parent term */
$handler->display->display_options['relationships']['parent']['id'] = 'parent';
$handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
$handler->display->display_options['relationships']['parent']['field'] = 'parent';
$handler->display->display_options['relationships']['parent']['required'] = TRUE;
/* Field: Taxonomy term: Name */
$handler->display->display_options['fields']['name_1']['id'] = 'name_1';
$handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['name_1']['field'] = 'name';
$handler->display->display_options['fields']['name_1']['relationship'] = 'parent';
$handler->display->display_options['fields']['name_1']['label'] = '';
$handler->display->display_options['fields']['name_1']['exclude'] = TRUE;
$handler->display->display_options['fields']['name_1']['element_label_colon'] = FALSE;
/* Field: Taxonomy term: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = '';
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
$handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
/* Sort criterion: Taxonomy term: Name */
$handler->display->display_options['sorts']['name_1']['id'] = 'name_1';
$handler->display->display_options['sorts']['name_1']['table'] = 'taxonomy_term_data';
$handler->display->display_options['sorts']['name_1']['field'] = 'name';
$handler->display->display_options['sorts']['name_1']['relationship'] = 'parent';
/* Sort criterion: Taxonomy term: Name */
$handler->display->display_options['sorts']['name']['id'] = 'name';
$handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
$handler->display->display_options['sorts']['name']['field'] = 'name';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Taxonomy vocabulary: Machine name */
$handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
$handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
$handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
$handler->display->display_options['filters']['machine_name']['value'] = array(
  'knowledge_base' => 'knowledge_base',
);

/* Display: Tree Accordion Block */
$handler = $view->new_display('block', 'Accordion Block', 'block');
$handler->display->display_options['display_description'] = 'Display Accordion of KB terms';
