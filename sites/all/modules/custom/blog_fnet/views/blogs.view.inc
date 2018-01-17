<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 8/23/17
 * Time: 4:18 PM
 */
$view = new view();
$view->name = 'blog_articles';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'Blog Articles';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Blog Articles';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'none';
$handler->display->display_options['cache']['type'] = 'time';
$handler->display->display_options['cache']['results_lifespan'] = '3600';
$handler->display->display_options['cache']['results_lifespan_custom'] = '0';
$handler->display->display_options['cache']['output_lifespan'] = '3600';
$handler->display->display_options['cache']['output_lifespan_custom'] = '0';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '10';
$handler->display->display_options['style_plugin'] = 'default';
$handler->display->display_options['row_plugin'] = 'fields';
/* Relationship: Content: Author */
$handler->display->display_options['relationships']['uid']['id'] = 'uid';
$handler->display->display_options['relationships']['uid']['table'] = 'node';
$handler->display->display_options['relationships']['uid']['field'] = 'uid';
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = '';
$handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['created']['date_format'] = 'custom';
$handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d';
$handler->display->display_options['fields']['created']['second_date_format'] = 'long';
/* Field: Realname: Real name */
$handler->display->display_options['fields']['realname']['id'] = 'realname';
$handler->display->display_options['fields']['realname']['table'] = 'realname';
$handler->display->display_options['fields']['realname']['field'] = 'realname';
$handler->display->display_options['fields']['realname']['relationship'] = 'uid';
$handler->display->display_options['fields']['realname']['label'] = '';
$handler->display->display_options['fields']['realname']['exclude'] = TRUE;
$handler->display->display_options['fields']['realname']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['realname']['link_to_user'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = '';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Entity translation: Body: translated */
$handler->display->display_options['fields']['body_et']['id'] = 'body_et';
$handler->display->display_options['fields']['body_et']['table'] = 'field_data_body';
$handler->display->display_options['fields']['body_et']['field'] = 'body_et';
$handler->display->display_options['fields']['body_et']['label'] = '';
$handler->display->display_options['fields']['body_et']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['body_et']['type'] = 'text_summary_or_trimmed';
$handler->display->display_options['fields']['body_et']['settings'] = array(
  'trim_length' => '600',
);
/* Field: Content: Nid */
$handler->display->display_options['fields']['nid']['id'] = 'nid';
$handler->display->display_options['fields']['nid']['table'] = 'node';
$handler->display->display_options['fields']['nid']['field'] = 'nid';
$handler->display->display_options['fields']['nid']['label'] = '';
$handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
$handler->display->display_options['fields']['nid']['alter']['text'] = 'Read More';
$handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['nid']['element_wrapper_class'] = 'btn_143w';
$handler->display->display_options['fields']['nid']['link_to_node'] = TRUE;
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
  'blog_article' => 'blog_article',
);
/* Filter criterion: Content: Blog Categories (field_blog_categories) */
$handler->display->display_options['filters']['field_blog_categories_target_id']['id'] = 'field_blog_categories_target_id';
$handler->display->display_options['filters']['field_blog_categories_target_id']['table'] = 'field_data_field_blog_categories';
$handler->display->display_options['filters']['field_blog_categories_target_id']['field'] = 'field_blog_categories_target_id';
$handler->display->display_options['filters']['field_blog_categories_target_id']['operator'] = 'not empty';

/* Display: All */
$handler = $view->new_display('page', 'All', 'page');
$handler->display->display_options['display_description'] = 'All blogs';
$handler->display->display_options['defaults']['pager'] = FALSE;
$handler->display->display_options['pager']['type'] = 'some';
$handler->display->display_options['pager']['options']['items_per_page'] = '3';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = '<div id="blog-header-all">
    <h1 class="blog-title"><span>Fluke Networks Blog</span></h1>
<ul class="blog-list columns-2">
        <li class="first">
            <a href="/blog/cabling-chronicles"><h2>Cabling Chronicles</h2></a>
            <div class="copy">
                <p>Copper and Fiber cabling industry news, standard changes/updates, customer insights and shared learnings.</p>
            </div>
            <div class="btn_100p">
                <a href="/blog/cabling-chronicles">Read More</a>
            </div>
        </li>
    </ul>
</div>';
$handler->display->display_options['header']['area']['format'] = 'full_html';
$handler->display->display_options['path'] = 'blog';

/* Display: Cabling Chronicles */
$handler = $view->new_display('page', 'Cabling Chronicles', 'cabling_chronicles');
$handler->display->display_options['defaults']['title'] = FALSE;
$handler->display->display_options['title'] = 'Blog: Cabling Chronicles';
$handler->display->display_options['display_description'] = 'Cabling Chronicles blog';
$handler->display->display_options['defaults']['header'] = FALSE;
/* Header: Global: Text area */
$handler->display->display_options['header']['area']['id'] = 'area';
$handler->display->display_options['header']['area']['table'] = 'views';
$handler->display->display_options['header']['area']['field'] = 'area';
$handler->display->display_options['header']['area']['content'] = '<h1 class="blog-title"><span>Cabling Chronicles</span></h1>';
$handler->display->display_options['header']['area']['format'] = 'full_html';
$handler->display->display_options['path'] = 'blog/cabling-chronicles';
