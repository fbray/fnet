<?php
/**
 * @file
 * Adaptivetheme implementation to display a single Drupal page.
 *
 * ###  Full Width Wrappers  ###
 *
 * This page template that has 100% width wrappers, which effectively
 * divide the page up into sections to you can style with full width
 * backgrounds. AT Commerce uses markup similar to this to achieve
 * its style - its worth checking out to see how I did this.
 *
 * To use copy this to your subtheme and rename it page.tpl.php,
 * or enable this in theme settings under "Site Tweaks".
 *
 * Available variables:
 *
 * Adaptivetheme supplied variables:
 * - $site_logo: Themed logo - linked to front with alt attribute.
 * - $site_name: Site name linked to the homepage.
 * - $site_name_unlinked: Site name without any link.
 * - $hide_site_name: Toggles the visibility of the site name.
 * - $visibility: Holds the class .element-invisible or is empty.
 * - $primary_navigation: Themed Main menu.
 * - $secondary_navigation: Themed Secondary/user menu.
 * - $primary_local_tasks: Split local tasks - primary.
 * - $secondary_local_tasks: Split local tasks - secondary.
 * - $tag: Prints the wrapper element for the main content.
 * - $is_mobile: Mixed, requires the Mobile Detect or Browscap module to return
 *   TRUE for mobile.  Note that tablets are also considered mobile devices.
 *   Returns NULL if the feature could not be detected.
 * - $is_tablet: Mixed, requires the Mobile Detect to return TRUE for tablets.
 *   Returns NULL if the feature could not be detected.
 * - *_attributes: attributes for various site elements, usually holds id, class
 *   or role attributes.
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Core Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * Adaptivetheme Regions:
 * - $page['leaderboard']: full width at the very top of the page
 * - $page['menu_bar']: menu blocks placed here will be styled horizontal
 * - $page['secondary_content']: full width just above the main columns
 * - $page['content_aside']: like a main content bottom region
 * - $page['tertiary_content']: full width just above the footer
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see adaptivetheme_preprocess_page()
 * @see adaptivetheme_process_page()
 */
/*
// Check to see if the Term object is set.
if (isset($identifier)) {
  // Is the term a TID?
  if (is_numeric($identifier)) {
    $term = taxonomy_term_load($identifier);
    $term_parents = $term->tid != "all" ? array_reverse(taxonomy_get_parents_all($term->tid)) : false;
    // Using the $term_parents array, build a "flattened" array of just the parent term ids for easier searching.
    $term_parent_ids = array();
    if ($term_parents) {
      foreach($term_parents as $parent) {
        $term_parent_ids[] = $parent->tid;
      }
    }
  }
  else {
      // The default should be 'all'.
  }
}
*/
// TODO: Write defaults for all terms.
$searchQuery = isset($_GET["query"]) ? $_GET["query"] : false; // Get the search string from URL if available.

?>
<div id="page-wrapper">
  <a name="topanchor" style="font-size:0; height:0;"></a>
  <div id="page" class="<?php print $classes; ?>">

    <?php if($page['leaderboard']): ?>
      <div id="leaderboard-wrapper">
        <div class="container clearfix">
          <?php print render($page['leaderboard']); ?>
        </div>
      </div>
    <?php endif; ?>

    <div id="header-wrapper">
      <div class="container clearfix">
        <header<?php print $header_attributes; ?>>

          <?php if (($site_logo || $site_name || $site_slogan) && $show_nav): ?>
            <!-- start: Branding -->
            <div<?php print $branding_attributes; ?>>

              <?php if ($site_logo): ?>
                <div id="logo">
                  <?php print $site_logo; ?>
                </div>
              <?php endif; ?>

              <?php if ($site_name || $site_slogan): ?>
                <!-- start: Site name and Slogan -->
                <div<?php print $hgroup_attributes; ?>>

                  <?php if ($site_name): ?>
                    <h1<?php print $site_name_attributes; ?>><?php print $site_name; ?></h1>
                  <?php endif; ?>

                  <?php if ($site_slogan): ?>
                    <h2<?php print $site_slogan_attributes; ?>><?php print $site_slogan; ?></h2>
                  <?php endif; ?>

                </div><!-- /end #name-and-slogan -->
              <?php endif; ?>


            </div><!-- /end #branding -->
          <?php endif; ?>

          <?php if ($show_nav): ?>
            <?php print render($page['header']); ?>
          <?php endif; ?>

        </header>
      </div>
    </div>

    <?php if (($page['menu_bar'] || $primary_navigation || $secondary_navigation) && $show_nav): ?>
      <div id="nav-wrapper">
        <div class="container clearfix">
          <?php print render($page['menu_bar']); ?>
          <?php if ($primary_navigation): print $primary_navigation; endif; ?>
          <?php if ($secondary_navigation): print $secondary_navigation; endif; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if ($breadcrumb && $show_breadcrumb): ?>
      <div id="breadcrumb-wrapper">
        <div class="container clearfix">
          <?php print $breadcrumb; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if ($messages || $page['help']): ?>
      <div id="messages-help-wrapper">
        <div class="container clearfix">
          <?php print $messages; ?>
          <?php print render($page['help']); ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if ($page['secondary_content']): ?>
      <div id="secondary-content-wrapper">
        <div class="container clearfix">
          <?php print render($page['secondary_content']); ?>
        </div>
      </div>
    <?php endif; ?>

    <div id="content-wrapper"><div class="container">
        <div id="columns"><div class="columns-inner clearfix">
            <div id="content-column"><div class="content-inner">

                <?php print render($page['highlighted']); ?>

                <<?php print $tag; ?> id="main-content">

                <?php print render($title_prefix); ?>

                <?php if ($title || $primary_local_tasks || $secondary_local_tasks || $action_links = render($action_links)): ?>
                  <header<?php print $content_header_attributes; ?>>

                    <?php if ($title && FALSE): ?>
                      <h1 id="page-title"><?php print $title; ?></h1>
                    <?php endif; ?>

                    <?php if ($primary_local_tasks || $secondary_local_tasks || $action_links): ?>
                      <div id="tasks">

                        <?php if ($primary_local_tasks): ?>
                          <ul class="tabs primary clearfix"><?php print render($primary_local_tasks); ?></ul>
                        <?php endif; ?>

                        <?php if ($secondary_local_tasks): ?>
                          <ul class="tabs secondary clearfix"><?php print render($secondary_local_tasks); ?></ul>
                        <?php endif; ?>

                        <?php if ($action_links = render($action_links)): ?>
                          <ul class="action-links clearfix"><?php print $action_links; ?></ul>
                        <?php endif; ?>

                      </div>
                    <?php endif; ?>

                  </header>
                <?php endif; ?>

                <?php if ($content = render($page['content'])): ?>
                  <div id="content">FNORD.
                      <?php
                      /*
                      // TODO: Check if $term is an object. If not, do default stuff.
                      if (isset($term)) {
                        dpm($term);
                      }
                      ?>
                      <div id="knowledge-base">

                          <h2>Knowledge Base</h2>

                          <!-- START: Search Form -->
                          <div id="kb-search">
                              <form name="kbSearch" method="get" action="/knowledge-base">
                                  <input name="query" type="text" value="<?php if ($searchQuery !== FALSE) {
                                    print $searchQuery;
                                  } ?>" style="width:250px;">
                                <?php
                                $site_split_tids = site_split_personality_tids();
                                $tree = taxonomy_get_tree($term->vid);
                                $sorted = array();
                                foreach ($tree as $termObj) {
                                  // Sort these bastards!
                                  $wrapper = entity_metadata_wrapper('taxonomy_term', $termObj->tid);
                                  try {
                                    $business_entity = $wrapper->field_business_entity->tid->value();
                                  } catch (Exception $e) {
                                    $business_entity = NULL;
                                  }
                                  if (!in_array($business_entity, $site_split_tids)) {
                                    continue;
                                  }
                                  if ($termObj->depth == 0) {
                                    $sorted[$termObj->tid]['term'] = $termObj;
                                  }
                                  else {
                                    $sorted[$termObj->parents[0]]['children'][$termObj->tid] = $termObj;
                                  }
                                }
                                ?>
                                  <input name="submit" type="submit" value="Search">

                                  <select name="tid" style="margin-left:50px;">

                                      <option value="all">Filter search by product...</option>


                                    <?php // Use the Sorted array to build the Option list with Optgroups. ?>
                                    <?php foreach($sorted as $term_group): ?>
                                        <optgroup label="<?php print $term_group['term']->name; ?>">
                                          <?php foreach($term_group['children'] as $child_term): ?>
                                            <?php $filter_select = ($searchQuery !== FALSE && $child_term->tid == $term->tid) ? ' selected' : ''; ?>
                                              <option value="<?php echo $child_term->tid; ?>"<?php print $filter_select; ?>><?php echo $child_term->name; ?></option>
                                          <?php endforeach; ?>
                                        </optgroup>
                                    <?php endforeach; ?>
                                  </select>

                              </form>

                          </div>
                          <!-- END: Search Form -->

                          <!-- START: Breadcrumbs -->
                          <div id="kb-breadcrumbs">

                              <a href="/knowledge-base" id="bc-link">KB Home</a>
                            <?php // TODO: Fix the breadcrumb. The parent attribute is not part of the term object as loaded. ?>
                            <?php if (isset($term_parents)): // Loop through array of term parent objects to build breadcrumbs. ?>
                              <?php foreach ($term_parents as $parent): ?>
                                    &nbsp;&nbsp;&gt;&nbsp;&nbsp;<?php echo $parent->name; ?>
                              <?php endforeach; ?>
                            <?php else: ?>
                                &gt;&nbsp;&nbsp;<?php print t('All'); ?>
                            <?php endif; ?>

                          </div>
                          <!-- END: Breadcrumbs -->

                        <?php if ($nid): // Does this ever happen? I don't think so. ?>

                            <!-- START: "Back to List" link -->
                            <div id="back-button">
                              <?php
                              $params = "";
                              if ($term->tid || $searchQuery !== FALSE) {
                                $params = "?";

                                if ($term->tid) {
                                  $params = $params . "&tid=" . $term->$tid;
                                }

                                if ($searchQuery !== FALSE) {
                                  $params = $params . "&query=" . $searchQuery;
                                }
                              }
                              ?>
                                <a href="/knowledge-base<?php echo $params; ?>"><strong><span
                                                style="font-size:16px;">&laquo;</span>&nbsp;Back to
                                        List</strong></a>
                            </div>
                            <!-- END: "Back to List" link -->

                            <!-- START: KB Article -->
                            <div id="kb-article" <?php if ($node->do_not_translate) {
                              print 'class="OneLinkNoTx"';
                            } ?>>
                                <h3 id="article-title"><?php echo $node_title; ?></h3>
                                <div id="article-body"><?php echo $node_body; ?></div>
                                <div id="article-author">
                                    <p class="info"><strong>Author: </strong><?php echo $node_author; ?></p>
                                    <p class="info"><strong>Creation
                                            Date: </strong><?php echo $node_created; ?></p>
                                    <p class="info"><strong>Last
                                            Modified: </strong><?php echo $node_changed; ?></p>
                                    <div style="clear:both; font-size:0; height:0;">&nbsp;</div>
                                </div>
                            </div>
                            <!-- END: KB Article -->

                          <?php drupal_set_title("Knowledge Base - " . $node_title); // Set the <title> tag in the HTML doc. ?>

                        <?php else: ?>

                          <script>
                              $(function () {

                                  // Initialize the nested "accordion" menus.
                                  $(".accordion").accordion({
                                      active: false, // Collapse all menus by default.
                                      collapsible: true,
                                      heightStyle: "content" // Let the height of each menu expand automatically.
                                  });

                                  // If necessary, expand the appropriate top-level accordion menu based on the current selection.
                                  var elem = $("#h4-active-panel"); // Fetch "active" menu heading element to be used in the "index" function.
                                  positionH4 = $("#h4-active-panel").closest(".accordion").find("h4").index(elem); // Determine the index position of the "active" menu element within the containing element.
                                  $("#h4-active-panel").closest(".accordion").accordion("option", "active", positionH4); // Activate (or open) the menu within which is contained the active link selection.

                                  $("#taxonomy-menu").fadeIn(200); // Since the accordion functionality of the menu is initialized/styled on the client side, display it only once this process completes.

                                <?php if ($searchQuery !== FALSE): // If a search was performed then add the search string to the link parameters. ?>

                                  $('#kb-article-list .views-field a[href]').each(function () {
                                      var href = $(this).attr('href'); // Get the current href value of view links.
                                      var param = "query=<?php echo $searchQuery; ?>";

                                      if (href.charAt(href.length - 1) === '?') //Very unlikely
                                          href = href + param;
                                      else if (href.indexOf('?') > 0)
                                          href = href + '&' + param;
                                      else
                                          href = href + '?' + param;

                                      $(this).attr('href', href);
                                  });

                                <?php endif; ?>

                              });
                          </script>

                          <!-- START: Taxonomy Menu -->
                          <div id="taxonomy-menu">
                              <h3>Browse by Category</h3>
                              <div class="accordion" id="top-accordian">

                                <?php
                                $lastDepth = 0;
                                $tree = taxonomy_get_tree($term->vid);
                                ?>
                                <?php foreach ($tree as $termObj): ?>
                                <?php
                                $wrapper = entity_metadata_wrapper('taxonomy_term', $termObj->tid);
                                $step = ''; // Assign a value of "up" or "down" only if the term depth has changed accordingly.
                                if ($lastDepth < $termObj->depth) {
                                  $step = "down";
                                }
                                elseif ($lastDepth > $termObj->depth) {
                                  $step = "up";
                                }
                                ?>
                                <?php if ($termObj->depth == 0): // 1st level terms will act as top level accordion menu headings. ?>
                                <?php if ($step == "up"): ?>
                                  </ul></div>
                            <?php endif; ?>
                            <?php $active_panel = in_array($termObj->tid, $term_parent_ids) ? ' id="h4-active-panel"' : ''; ?>
                              <h4<?php print $active_panel; ?>>
                                <?php $tcatname = str_replace(' ', '-', strtolower($termObj->name)) ;?>
                                <?php echo $termObj->name; ?>
                              </h4>

                            <?php elseif ($termObj->depth == 1): // 2nd level terms will act as nested accordion menu links. ?>
                          <?php if ($step == "down"): ?>
                              <div>
                                  <ul>
                                    <?php endif; ?>
                                    <?php $active_menu_item = ($termObj->tid == $term->tid) ? ' id="active-menu-item"' : ''; ?>
                                      <li<?php print $active_menu_item; ?>>
                                          <!-- <a href="/knowledge-base/?tid=<?php //echo $termObj->tid; ?>"><?php //echo $termObj->name; ?></a> -->
                                        <?php
                                        // $termname = str_replace("/","##",$termObj->name);
                                        $link = url('taxonomy/term/' . $termObj->tid);
                                        ?>
                                          <a href="<?php echo $link; ?>"><?php echo $termObj->name; ?></a>
                                      </li>

                                    <?php endif; ?>
                                    <?php $lastDepth = $termObj->depth; // Capture the term depth so that change in depth can be tracked from one term to the next. ?>
                                    <?php endforeach; ?>
                                    <?php if ($lastDepth == 1): ?>
                                  </ul>
                              </div>
                          <?php endif; ?>

                          </div>

                      </div>
                  <!-- END: Taxonomy Menu -->

                  <!-- START: Article List View -->
                      <div id="kb-article-list">
                          <h3>Articles: <?php echo $term->name; ?></h3>

                        <?php
                        $view = views_get_view('knowledge_base_articles'); // Get Drupal view by name.
                        $view->set_display('block_1'); // Get Drupal view display by name.
                        $view->set_arguments((array) $term->tid); // Pass term id argument to view if available in URL.

                        // Pass search string to exposed view filter if available in URL.
                        if ($searchQuery !== FALSE) {
                          $exposed_filters = array(
                            'query' => $searchQuery
                          );

                          $view->exposed_input = array_merge($exposed_filters, (array) $view->exposed_input);
                          $view->exposed_raw_input = array_merge($exposed_filters, (array) $view->exposed_raw_input);
                          $view->exposed_data = array_merge($exposed_filters, (array) $view->exposed_data);
                        }

                        // Display view results.
                        $output = $view->preview();
                        if ($view->result) {
                          print $output;
                        }
                        $view->destroy();
                        ?>
                      </div>
                      <!-- END: Article List View -->

                    <?php endif; ?>

                      <div style="clear:both;">&nbsp;</div>

                  </div>
                  </div>
                      <?php */ ?>
                <?php endif; ?>

                <?php print $feed_icons; ?>

                <?php print render($title_suffix); // Prints page level contextual links ?>

              </<?php print $tag; ?>>

              <?php print render($page['content_aside']); ?>

              <!-- Nested Content Column Regions 1-3 -->
              <div id="nested-content-columns" class="column-grid clearfix">

                <?php if ($content_column_one = render($page['content_column_one'])): ?>
                  <div class="nested-content-column">
                    <?php print $content_column_one; ?>
                    <div class="clearfix"></div>
                  </div>
                <?php endif; ?>

                <?php if ($content_column_two = render($page['content_column_two'])): ?>
                  <div class="nested-content-column">
                    <?php print $content_column_two; ?>
                    <div class="clearfix"></div>
                  </div>
                <?php endif; ?>

                <?php if ($content_column_three = render($page['content_column_three'])): ?>
                  <div class="nested-content-column">
                    <?php print $content_column_three; ?>
                    <div class="clearfix"></div>
                  </div>
                <?php endif; ?>

                <div class="clearfix"></div>
              </div>

            </div></div>

          <?php print render($page['sidebar_first']); ?>
          <?php print render($page['sidebar_second']); ?>

        </div></div>
    </div></div>

  <?php if ($page['tertiary_content']): ?>
    <div id="tertiary-content-wrapper">
      <div class="container clearfix">
        <?php print render($page['tertiary_content']); ?>
      </div>
    </div>
  <?php endif; ?>
  <div class="clear_0px">&nbsp;</div>
  <?php if (($page['footer'] || $attribution) && $show_nav): ?>
    <div id="footer-wrapper">
      <div class="container clearfix">
        <footer<?php print $footer_attributes; ?>>
          <?php print render($page['footer']); ?>
          <?php print $attribution; ?>
        </footer>
      </div>
    </div>
  <?php endif; ?>

</div>
</div>

<!-- START: EU Cookie Notice (message is dynamically inserted by JavaScript) -->
<div id="eucookie">&nbsp;</div>
<!-- END: EU Cookie Notice -->

<!-- START: Region Menu -->
<div id="selectRegionBox" style="display:none;">
  <div id="selectRegionBoxTitle">Welcome to Fluke Networks</div>
  <form action="" method="post" name="region">
    <div style="padding:10px 5px 5px 5px;"><strong>Select your country:</strong></div>
    <div class='OneLinkNoTx'>
      <select id="regionCountry" name="regionCountry" onchange="countryLanguage(this.value);"
              style="width:auto;font-size:12px;">
        <option value="">-- Country --</option>
      </select>
    </div>
    <div style="padding:10px 5px 5px 5px;"><strong>Select available language:</strong></div>
    <select id="language" name="language" disabled="disabled" style="width:auto;font-size:12px;"">
    <option value="">-- Language --</option>
    </select>
    <div class="clear">&nbsp;</div>
    <div style="text-align:center;">
      <div class="btn_143w" style="margin: 0px auto;"><a href="javascript:setRegion();"
                                                         style="color:#000000;">Submit</a></div>
    </div>
  </form>
  <div class="clear">&nbsp;</div>
</div>
<!-- END: Region Menu -->
