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
                <h1 id="page-title"><?php print t('404 Not Found'); ?></h1>

                <?php print render($title_prefix); ?>

                <?php if ($content = render($page['content'])): ?>
                  <div id="content">
                    <h2><?php print t("We are sorry, the page you requested cannot be found."); ?></h2>
                    <p><?php print t("The URL may be misspelled or the page you're looking for is no longer available."); ?><br />
                        <?php print t('You can visit our <a href="@home-page">home page</a> to get an overview of our products, services and technical support.', array('@home-page' => '/')); ?></p>
                      <p><?php print t('Let us help you find what you\'re looking for! If you were trying to get to specific content areas, click on the links below.'); ?></p>
                      <ul>
                          <li><?php print t('Read articles in our <a href="@blog-page">Blog</a>', array('@blog-page' => url('blog/cabling-chronicles'))); ?></li>
                          <li><?php print t('Get info on <a href="@products-page">Products</a> and <a href="@support-page">Support</a>', array('@products-page' => url('products'), '@support-page' => url('support'))); ?></li>
                          <li><?php print t('Find detailed product and technical information in our <a href="@knowledgebase-page">Knowledge Base</a>', array('@knowledgebase-page' => url('knowledge-base'))); ?></li>
                          <li><?php print t('Take a tour of our <a href="@versive-page">Versiv Configurator</a>', array('@versive-page' => url('versivconfig'))); ?></li>
                          <li><?php print t('Find <a href="@wtb-page">where to buy</a> our products', array('@wtb-page' => url('wheretobuy'))); ?></li>
                          <li><?php print t('Login or sign-up for <a href="@myaccount-page">MyAccount</a>, <a href="@salesinsider-page">Sales Insider</a>, <a href="@opportunity-page">Opportunity Insider</a>', array(
                              '@myaccount-page' => url('user'),
                              '@salesinsider-page' => url('extranet'),
                              '@opportunity-page' => 'https://fnet.secure.force.com/partner/')); ?></li>
                          <li><?php print t('Searching for something else? Check out our <a href="@sitemap-page">sitemap</a> or call us directly at 1-800-283-5853.', array('@sitemap-page' => url('sitemap'))); ?></li>
                      </ul>
                    <?php // print $content; ?>
                  </div>
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
