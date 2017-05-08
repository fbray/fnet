<?php
/**
 * @file
 * blog_fnet.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function blog_fnet_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'blog_articles';
  $view->description = 'This view is used to aggregate Blog Article content types which can then be filtered by category.';
  $view->tag = '';
  $view->base_table = 'node';
  $view->human_name = '';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Blog Articles';
  $handler->display->display_options['items_per_page'] = 0;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['exclude'] = TRUE;
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
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'uid';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h2 class="[php]">[title]</h2>';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<div class="blog-author-details">
<div class="blog-author-picture">
   <?php if ($row->picture) { ?>
      <img src="<?php print $row->picture; ?>" /></div>
   <?php } ?>
</div>
<div class="blog-author-name"><?php print $row->realname; ?></div>
<div class="blog-author-date"><?php print date("Y-m-d", $row->created); ?></div>
<div class="clearboth"></div>
</div>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = '<div class="btn_143w"><a href="/node/[nid]">Read More</a></div>';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog_article' => 'blog_article',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = '0';
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Admin Page */
  $handler = $view->new_display('page', 'Admin Page', 'page_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    5 => 5,
    19 => 19,
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = '';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'name' => 'name',
    'created' => 'created',
    'status' => 'status',
    'edit_node' => 'edit_node',
    'delete_node' => 'delete_node',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'name' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'created' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'status' => array(
      'sortable' => 1,
      'separator' => '',
    ),
    'edit_node' => array(
      'separator' => '',
    ),
    'delete_node' => array(
      'separator' => '',
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h2>[title]</h2>';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Post Date';
  $handler->display->display_options['fields']['created']['alter']['text'] = '<div class="blog-author-details">
<div class="blog-author-picture">[picture]</div>
<div class="blog-author-name">[name]</div>
<div class="blog-author-date">[created] </div>
<div class="clearboth"></div>
</div>';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog_article' => 'blog_article',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  $handler->display->display_options['path'] = 'admin/content/blog-articles';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Blog Articles';
  $handler->display->display_options['menu']['weight'] = '0';

  /* Display: All */
  $handler = $view->new_display('page', 'All', 'page_2');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['text']['id'] = 'text';
  $handler->display->display_options['header']['text']['table'] = 'views';
  $handler->display->display_options['header']['text']['field'] = 'area';
  $handler->display->display_options['header']['text']['content'] = '<style>
#blog-header-all ul.blog-list.columns-2 li {
    font-size: 130%;
}
#blog-header-all ul.blog-list li h2 {
font-size: 1.5em;
}
</style>
<div id="blog-header-all">

    <!-- div class="hero-image">
        <img src="#">
    </div -->
    
    <h1 class="blog-title"><span>Fluke Networks Blog</span></h1>
    
    <ul class="blog-list columns-2">
        <li class="first">
            <!-- img src="http://www.flukenetworks.com/sites/flukenetworks.com/files/assets/cabling_chronicles.gif" class="thumbnail" -->
            <a href="/blog/cabling-chronicles"><h2>Cabling Chronicles</h2></a>
            <div class="copy">
                <p>Copper and Fiber cabling industry news, standard changes/updates, customer insights and shared learnings.</p>
            </div>
            <div class="btn_100p">
                <a href="/blog/cabling-chronicles">Read More</a>
            </div>
        </li>
        <!-- li>
            <img src="http://images.flukenetworks.com/Decoder.gif" class="thumbnail">
            <a href="/blog/decoder"><h2>The Decoder</h2></a>
            <div class="copy">
                <p>Solving the mysteries of monitoring, analysis and troubleshooting.</p>
            </div>
            <div class="btn_100p">
                <a href="/blog/decoder">Read More</a>
            </div>
        </li>
        <li>
            <img src="http://images.flukenetworks.com/AirWise_60x60.jpg" class="thumbnail">
            <a href="/blog/airwise"><h2>AirWise</h2></a>
            <div class="copy">
                <p>A blog on wireless network technology, trends and best practices related to security, performance, troubleshooting, management, design and regulatory compliance.</p>
            </div>
            <div class="btn_100p">
                <a href="/blog/airwise">Read More</a>
            </div>
        </li -->
        <li class="last">
            <!-- img src="http://www.flukenetworks.com/sites/flukenetworks.com/files/assets/cabling_chronicles.gif" class="thumbnail" -->
            <a href="/blog/network-insider"><h2>Network Insider</h2></a>
            <div class="copy">
                <p>Solving the mysteries of network monitoring, analysis and troubleshooting</p>
            </div>
            <div class="btn_100p">
                <a href="/blog/network-insider">Read More</a>
            </div>
        </li>
        <!-- li class="last">
            <img src="http://www.flukenetworks.com/sites/flukenetworks.com/files/images/blog-link-solutions.png" class="thumbnail">
            <a href="/blog/link-solutions"><h2>Link-Solutions</h2></a>
            <div class="copy">
                <p>Providing complete end-to-end network connectivity testing and automated reporting to Link-Live Cloud Service</p>
            </div>
            <div class="btn_100p">
                <a href="/blog/link-solutions">Read More</a>
            </div>
        </li -->
    </ul>

</div>';
  $handler->display->display_options['header']['text']['format'] = '5';
  $handler->display->display_options['path'] = 'blog';

  /* Display: AirWise */
  $handler = $view->new_display('page', 'AirWise', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Blog: AirWise';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['text']['id'] = 'area';
  $handler->display->display_options['header']['text']['table'] = 'views';
  $handler->display->display_options['header']['text']['field'] = 'area';
  $handler->display->display_options['header']['text']['content'] = '<h1 class="blog-title"><span>AirWise</span></h1>';
  $handler->display->display_options['header']['text']['format'] = '5';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog_article' => 'blog_article',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    0 => '417',
  );
  $handler->display->display_options['filters']['tid']['group'] = '0';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'blog_categories';
  $handler->display->display_options['path'] = 'blog/airwise';

  /* Display: The Decoder */
  $handler = $view->new_display('page', 'The Decoder', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Blog: The Decoder';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['text']['id'] = 'area';
  $handler->display->display_options['header']['text']['table'] = 'views';
  $handler->display->display_options['header']['text']['field'] = 'area';
  $handler->display->display_options['header']['text']['content'] = '<h1 class="blog-title"><span>The Decoder</span></h1>';
  $handler->display->display_options['header']['text']['format'] = '5';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog_article' => 'blog_article',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    416 => '416',
  );
  $handler->display->display_options['filters']['tid']['group'] = '0';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'blog_categories';
  $handler->display->display_options['path'] = 'blog/decoder';

  /* Display: Cabling Chronicles */
  $handler = $view->new_display('page', 'Cabling Chronicles', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Blog: Cabling Chronicles';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['text']['id'] = 'area';
  $handler->display->display_options['header']['text']['table'] = 'views';
  $handler->display->display_options['header']['text']['field'] = 'area';
  $handler->display->display_options['header']['text']['content'] = '<h1 class="blog-title"><span>Cabling Chronicles</span></h1>';
  $handler->display->display_options['header']['text']['format'] = '5';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog_article' => 'blog_article',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    417 => '417',
  );
  $handler->display->display_options['filters']['tid']['group'] = '0';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'vocabulary_16';
  $handler->display->display_options['path'] = 'blog/cabling-chronicles';

  /* Display: Network Insider */
  $handler = $view->new_display('page', 'Network Insider', 'page_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Blog: Network Insider';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['text']['id'] = 'area';
  $handler->display->display_options['header']['text']['table'] = 'views';
  $handler->display->display_options['header']['text']['field'] = 'area';
  $handler->display->display_options['header']['text']['content'] = '<h1 class="blog-title"><span>Network Insider</span></h1>';
  $handler->display->display_options['header']['text']['format'] = '5';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'blog_article' => 'blog_article',
  );
  $handler->display->display_options['filters']['type']['group'] = '0';
  $handler->display->display_options['filters']['type']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Has taxonomy term */
  $handler->display->display_options['filters']['tid']['id'] = 'tid';
  $handler->display->display_options['filters']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['filters']['tid']['field'] = 'tid';
  $handler->display->display_options['filters']['tid']['value'] = array(
    416 => '416',
    421 => '421',
    419 => '419',
    418 => '418',
  );
  $handler->display->display_options['filters']['tid']['group'] = '0';
  $handler->display->display_options['filters']['tid']['expose']['operator'] = FALSE;
  $handler->display->display_options['filters']['tid']['type'] = 'select';
  $handler->display->display_options['filters']['tid']['vocabulary'] = 'vocabulary_16';
  $handler->display->display_options['path'] = 'blog/network-insider';
  $translatables['blog_articles'] = array(
    t('Defaults'),
    t('Blog Articles'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('author'),
    t('<h2 class="[php]">[title]</h2>'),
    t('<div class="btn_143w"><a href="/node/[nid]">Read More</a></div>'),
    t('Admin Page'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Title'),
    t('<h2>[title]</h2>'),
    t('Name'),
    t('Post Date'),
    t('<div class="blog-author-details">
<div class="blog-author-picture">[picture]</div>
<div class="blog-author-name">[name]</div>
<div class="blog-author-date">[created] </div>
<div class="clearboth"></div>
</div>'),
    t('Published'),
    t('All'),
    t('<style>
#blog-header-all ul.blog-list.columns-2 li {
    font-size: 130%;
}
#blog-header-all ul.blog-list li h2 {
font-size: 1.5em;
}
</style>
<div id="blog-header-all">

    <!-- div class="hero-image">
        <img src="#">
    </div -->
    
    <h1 class="blog-title"><span>Fluke Networks Blog</span></h1>
    
    <ul class="blog-list columns-2">
        <li class="first">
            <!-- img src="http://www.flukenetworks.com/sites/flukenetworks.com/files/assets/cabling_chronicles.gif" class="thumbnail" -->
            <a href="/blog/cabling-chronicles"><h2>Cabling Chronicles</h2></a>
            <div class="copy">
                <p>Copper and Fiber cabling industry news, standard changes/updates, customer insights and shared learnings.</p>
            </div>
            <div class="btn_100p">
                <a href="/blog/cabling-chronicles">Read More</a>
            </div>
        </li>
        <!-- li>
            <img src="http://images.flukenetworks.com/Decoder.gif" class="thumbnail">
            <a href="/blog/decoder"><h2>The Decoder</h2></a>
            <div class="copy">
                <p>Solving the mysteries of monitoring, analysis and troubleshooting.</p>
            </div>
            <div class="btn_100p">
                <a href="/blog/decoder">Read More</a>
            </div>
        </li>
        <li>
            <img src="http://images.flukenetworks.com/AirWise_60x60.jpg" class="thumbnail">
            <a href="/blog/airwise"><h2>AirWise</h2></a>
            <div class="copy">
                <p>A blog on wireless network technology, trends and best practices related to security, performance, troubleshooting, management, design and regulatory compliance.</p>
            </div>
            <div class="btn_100p">
                <a href="/blog/airwise">Read More</a>
            </div>
        </li -->
        <li class="last">
            <!-- img src="http://www.flukenetworks.com/sites/flukenetworks.com/files/assets/cabling_chronicles.gif" class="thumbnail" -->
            <a href="/blog/network-insider"><h2>Network Insider</h2></a>
            <div class="copy">
                <p>Solving the mysteries of network monitoring, analysis and troubleshooting</p>
            </div>
            <div class="btn_100p">
                <a href="/blog/network-insider">Read More</a>
            </div>
        </li>
        <!-- li class="last">
            <img src="http://www.flukenetworks.com/sites/flukenetworks.com/files/images/blog-link-solutions.png" class="thumbnail">
            <a href="/blog/link-solutions"><h2>Link-Solutions</h2></a>
            <div class="copy">
                <p>Providing complete end-to-end network connectivity testing and automated reporting to Link-Live Cloud Service</p>
            </div>
            <div class="btn_100p">
                <a href="/blog/link-solutions">Read More</a>
            </div>
        </li -->
    </ul>

</div>'),
    t('AirWise'),
    t('Blog: AirWise'),
    t('<h1 class="blog-title"><span>AirWise</span></h1>'),
    t('The Decoder'),
    t('Blog: The Decoder'),
    t('<h1 class="blog-title"><span>The Decoder</span></h1>'),
    t('Cabling Chronicles'),
    t('Blog: Cabling Chronicles'),
    t('<h1 class="blog-title"><span>Cabling Chronicles</span></h1>'),
    t('Network Insider'),
    t('Blog: Network Insider'),
    t('<h1 class="blog-title"><span>Network Insider</span></h1>'),
  );
  $export['blog_articles'] = $view;

  return $export;
}
