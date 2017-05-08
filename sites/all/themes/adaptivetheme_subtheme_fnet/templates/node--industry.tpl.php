<?php
/**
 * @file
 * Adaptivetheme implementation to display a node.
 *
 * Adaptivetheme variables:
 * AT Core sets special time and date variables for use in templates:
 * - $submitted: Submission information created from $name and $date during
 *   adaptivetheme_preprocess_node(), uses the $publication_date variable.
 * - $datetime: datetime stamp formatted correctly to ISO8601.
 * - $publication_date: publication date, formatted with time element and
 *   pubdate attribute.
 * - $datetime_updated: datetime stamp formatted correctly to ISO8601.
 * - $last_update: last updated date/time, formatted with time element and
 *   pubdate attribute.
 * - $custom_date_and_time: date time string used in $last_update.
 * - $header_attributes: attributes such as classes to apply to the header element.
 * - $footer_attributes: attributes such as classes to apply to the footer element.
 * - $links_attributes: attributes such as classes to apply to the nav element.
 * - $is_mobile: Mixed, requires the Mobile Detect or Browscap module to return
 *   TRUE for mobile.  Note that tablets are also considered mobile devices.
 *   Returns NULL if the feature could not be detected.
 * - $is_tablet: Mixed, requires the Mobile Detect to return TRUE for tablets.
 *   Returns NULL if the feature could not be detected.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined, e.g. $node->body becomes $body. When needing to access
 * a field's raw values, developers/themers are strongly encouraged to use these
 * variables. Otherwise they will have to explicitly specify the desired field
 * language, e.g. $node->body['en'], thus overriding any language negotiation
 * rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 * @see adaptivetheme_preprocess_node()
 * @see adaptivetheme_process_node()
 */

/**
 * Hide Content and Print it Separately
 *
 * Use the hide() function to hide fields and other content, you can render it
 * later using the render() function. Install the Devel module and use
 * <?php dsm($content); ?> to find variable names to hide() or render().
 */
hide($content['comments']);
hide($content['links']);

?>

<?php if (fnet_common_safe_get($field_ind_background_img, 0, 'uri')) {

  $bgimgpath = file_create_url(fnet_common_safe_get($field_ind_background_img, 0, 'uri')); ?>

  <style>
    #page { background-image:url(<?php print $bgimgpath; ?>); }
  </style>

<?php } else { ?>
  <style>
    #page { background-image:url('/<?php print drupal_get_path("module", "industries_families"); ?>/css/images/industry_hub_Blank.jpg'); }
  </style>

<?php } ?>

<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>

  <?php if ($title && !$page): ?>
    <header<?php print $header_attributes; ?>>
      <?php if ($title): ?>
        <h1<?php print $title_attributes; ?>>
          <a href="<?php print $node_url; ?>" rel="bookmark"><?php print $title; ?></a>
        </h1>
      <?php endif; ?>
    </header>
  <?php endif; ?>

  <div<?php print $content_attributes; ?>>
    <?php // print render($content); ?>

    <div class="jcarousel-wrapper">
      <div class="jcarousel">
        <ul>

          <?php 
          // $banners is created in industries_families

          foreach ($banners as $banner_slide) { 
            if ($banner_slide) {             ?>
              <li><?php print $banner_slide; ?></li>
            <?php } 
          }
          ?>

        </ul>
      </div>
      <a href="#" class="jcarousel-control-prev">&lsaquo;</a>
      <a href="#" class="jcarousel-control-next">&rsaquo;</a>
      <p class="jcarousel-pagination"></p>
    </div>

    <!-- Add and enable Tabs sections. -->
    <script>
      $(function() {
        $( "#tabs" ).tabs(); // Instantiate the tabs UI.

        hash = $(location).attr('hash').slice(1);
        if (hash) {
          clickid = $('[name*=' + hash + ']').closest('.ui-tabs-panel').attr('id');
          $('.ui-tabs-anchor[href=#' + clickid + ']').trigger("click");
          $('html, body').animate({
//            scrollTop: $('[name*=' + hash + ']').offset().top
            scrollTop: $('#' + hash).offset().top
          }, 1000);
        }

        // Enable the "See Products" button to show tab 3.
        $('.show-products').click(function(e){
          e.preventDefault(); // Stop the default behavior.
          $("[href='#tabs-3']").trigger( "click" ); // Select the third tab.
          location.href = $(this).attr("href"); // Drop to the matching anchor.
        });
      });

    </script>
    <div class="clear_20px">&nbsp;</div>
    <div class="clear_20px">&nbsp;</div>
    <a name="top"></a>
    <div id="tabs" style="margin-top:1em;">

          <div id="industry_tab_wrapper">
            <div id="industry_tab_main">
              <div id="industry_tabs">
                <ul>
                  <!-- Display tab buttons. -->
                  <li><a href="#tabs-1">Overview</a></li>
                  <li><a href="#tabs-2">Expertise</a></li>
                  <li><a href="#tabs-3">Products</a></li>
                </ul>
              </div>
            </div>
          </div>
      <div class="clear_15px;">&nbsp;</div>
      <div class="clear_15px;">&nbsp;</div>

      <!-- Display tab content if it exists. -->
      <div id="tabs-1">
        <div class="column-grid">

          <!-- List Families -->
          <div class="col-2-3">

            <?php foreach ($industry_families as $family) { ?>

              <div class="column-grid">
                <div class="col-1-3">
                  <div style="padding:1em;">
                    <img src="<?php print file_create_url(  fnet_common_get_field_value('family', $family, 'field_family_hub_img', 'uri')   ); ?>" style="width:auto; max-width:100%;" />
                  </div>
                </div>
                <div class="col-2-3">
                  <h4><?php print $family->title; ?></h4>
                  <?php print fnet_common_get_field_value('family', $family, 'field_family_shortdesc', 'value'); ?>
                  <div class="btn_143w"><a class="show-products" href="#family-product-list-<?php print $family->nid; ?>">See Products &#187;</a></div>
                </div>
              </div>
              <div class='clear_15px'>&nbsp;</div>
              <div class='clear_1px'><img src='/sites/flukenetworks.com/themes/adaptivetheme_subtheme_fnet/images/hub_product_divider.gif' width='650' height='1' border='0'></div>
              <div class='clear_15px'>&nbsp;</div>

            <?php } ?>

          </div>

          <!-- "Right Hand Column" Content -->
          <div class="col-1-3">
            <div style="margin-left: 25px;padding-top: 15px;">

              <?php if (fnet_common_safe_get($field_industry_box_title_1, 0, 'value')) { ?>
                <h5><?php print fnet_common_safe_get($field_industry_box_title_1, 0, 'value'); ?></h5>
              <?php } ?>
              <?php if (fnet_common_safe_get($field_industry_box_img_1, 0, 'uri')) { ?>
                <p><img
                    src="<?php print file_create_url(fnet_common_safe_get($field_industry_box_img_1, 0, 'uri')); ?>"
                    style="width:auto; max-width:100%;"/></p>
              <?php } ?>
              <?php if (fnet_common_safe_get($field_industry_box_desc_1, 0, 'value')) { ?>
                <p><?php print fnet_common_safe_get($field_industry_box_desc_1, 0, 'value'); ?></p>
              <?php } ?>
              <?php if (fnet_common_safe_get($field_industry_box_url_1, 0, 'title')) { ?>
                <p><a
                    href="<?php print fnet_common_safe_get($field_industry_box_url_1, 0, 'url'); ?>"><?php print fnet_common_safe_get($field_industry_box_url_1, 0, 'title'); ?></a>
                </p>
              <?php } ?>

              <?php if (fnet_common_safe_get($field_industry_box_desc_1, 0, 'value')) { ?>
                <hr style="margin:2em 0; border:0; height:1px; background-color:#eee;" />
              <?php } ?>

              <?php if (fnet_common_safe_get($field_industry_box_title_2, 0, 'value')) { ?>
                <h5><?php print fnet_common_safe_get($field_industry_box_title_2, 0, 'value'); ?></h5>
              <?php } ?>
              <?php if (fnet_common_safe_get($field_industry_box_img_2, 0, 'uri')) { ?>
                <p><img
                    src="<?php print file_create_url(fnet_common_safe_get($field_industry_box_img_2, 0, 'uri')); ?>"
                    style="width:auto; max-width:100%;"/></p>
              <?php } ?>
              <?php if (fnet_common_safe_get($field_industry_box_desc_2, 0, 'value')) { ?>
                <p><?php print fnet_common_safe_get($field_industry_box_desc_2, 0, 'value'); ?></p>
              <?php } ?>
              <?php if (fnet_common_safe_get($field_industry_box_url_2, 0, 'title')) { ?>
                <p><a
                    href="<?php print fnet_common_safe_get($field_industry_box_url_2, 0, 'url'); ?>"><?php print fnet_common_safe_get($field_industry_box_url_2, 0, 'title'); ?></a>
                </p>
              <?php } ?>

              <?php if (fnet_common_safe_get($field_industry_box_desc_2, 0, 'value')) { ?>
                <hr style="margin:2em 0; border:0; height:1px; background-color:#eee;" />
              <?php } ?>

              <?php if (fnet_common_safe_get($field_industry_box_title_3, 0, 'value')) { ?>
                <h5><?php print fnet_common_safe_get($field_industry_box_title_3, 0, 'value'); ?></h5>
              <?php } ?>
              <?php if (fnet_common_safe_get($field_industry_box_img_3, 0, 'uri')) { ?>
                <p><img
                    src="<?php print file_create_url(fnet_common_safe_get($field_industry_box_img_3, 0, 'uri')); ?>"
                    style="width:auto; max-width:100%;"/></p>
              <?php } ?>
              <?php if (fnet_common_safe_get($field_industry_box_desc_3, 0, 'value')) { ?>
                <p><?php print fnet_common_safe_get($field_industry_box_desc_3, 0, 'value'); ?></p>
              <?php } ?>
              <?php if (fnet_common_safe_get($field_industry_box_url_3, 0, 'title')) { ?>
                <p><a
                    href="<?php print fnet_common_safe_get($field_industry_box_url_3, 0, 'url'); ?>"><?php print fnet_common_safe_get($field_industry_box_url_3, 0, 'title'); ?></a>
                </p>
              <?php } ?>

              <?php if (fnet_common_safe_get($field_industry_box_desc_3, 0, 'value')) { ?>
                <hr style="margin:2em 0; border:0; height:1px; background-color:#eee;" />
              <?php } ?>

            </div>
          </div>
        </div>
      </div><!-- #tabs-1 -->

      <div id="tabs-2">
        <div class="column-grid">
          <div class="col-1-3">
            <div class="grid-inner-padding">

              <h5>POPULAR RESOURCES</h5>
              <?php if (fnet_common_safe_get($field_industry_pop_res_1, 0, 'title')) { ?>
                <p><a
                    href="<?php print fnet_common_safe_get($field_industry_pop_res_1, 0, 'url'); ?>"><?php print fnet_common_safe_get($field_industry_pop_res_1, 0, 'title'); ?></a>
                </p>
              <?php } ?>
              <?php if (fnet_common_safe_get($field_industry_pop_res_2, 0, 'title')) { ?>
                <p><a
                    href="<?php print fnet_common_safe_get($field_industry_pop_res_2, 0, 'url'); ?>"><?php print fnet_common_safe_get($field_industry_pop_res_2, 0, 'title'); ?></a>
                </p>
              <?php } ?>
              <?php if (fnet_common_safe_get($field_industry_pop_res_3, 0, 'title')) { ?>
                <p><a
                    href="<?php print fnet_common_safe_get($field_industry_pop_res_3, 0, 'url'); ?>"><?php print fnet_common_safe_get($field_industry_pop_res_3, 0, 'title'); ?></a>
                </p>
              <?php } ?>

              <hr style="margin:2em 0; border:0; height:1px; background-color:#eee;" />

              <h5>LEARN ABOUT</h5>
              <?php if (fnet_common_safe_get($field_industry_learn_abt_1, 0, 'title')) { ?>
                <p><a
                    href="<?php print fnet_common_safe_get($field_industry_learn_abt_1, 0, 'url'); ?>"><?php print fnet_common_safe_get($field_industry_learn_abt_1, 0, 'title'); ?></a>
                </p>
              <?php } ?>
              <?php if (fnet_common_safe_get($field_industry_learn_abt_2, 0, 'title')) { ?>
                <p><a
                    href="<?php print fnet_common_safe_get($field_industry_learn_abt_2, 0, 'url'); ?>"><?php print fnet_common_safe_get($field_industry_learn_abt_2, 0, 'title'); ?></a>
                </p>
              <?php } ?>
              <?php if (fnet_common_safe_get($field_industry_learn_abt_3, 0, 'title')) { ?>
                <p><a
                    href="<?php print fnet_common_safe_get($field_industry_learn_abt_3, 0, 'url'); ?>"><?php print fnet_common_safe_get($field_industry_learn_abt_3, 0, 'title'); ?></a>
                </p>
              <?php } ?>

              <hr style="margin:2em 0; border:0; height:1px; background-color:#eee;" />

              <h5>FEATURED TOPICS</h5>
              <?php if (fnet_common_safe_get($field_industry_fea_top_1, 0, 'title')) { ?>
                <p><a
                    href="<?php print fnet_common_safe_get($field_industry_fea_top_1, 0, 'url'); ?>"><?php print fnet_common_safe_get($field_industry_fea_top_1, 0, 'title'); ?></a>
                </p>
              <?php } ?>
              <?php if (fnet_common_safe_get($field_industry_fea_top_2, 0, 'title')) { ?>
                <p><a
                    href="<?php print fnet_common_safe_get($field_industry_fea_top_2, 0, 'url'); ?>"><?php print fnet_common_safe_get($field_industry_fea_top_2, 0, 'title'); ?></a>
                </p>
              <?php } ?>
              <?php if (fnet_common_safe_get($field_industry_fea_top_3, 0, 'title')) { ?>
                <p><a
                    href="<?php print fnet_common_safe_get($field_industry_fea_top_3, 0, 'url'); ?>"><?php print fnet_common_safe_get($field_industry_fea_top_3, 0, 'title'); ?></a>
                </p>
              <?php } ?>

              <hr style="margin:2em 0; border:0; height:1px; background-color:#eee;" />

            </div>

          </div>
          <div class="col-2-3">
            <div id="industries-links">
              <a name="top"></a>
              <?php print $industries_links; ?>
            </div>
            <?php if ($whitepapers) { ?>
              <a name="white_papers"></a>
              <h4>White Papers</h4>
            <?php print $whitepapers; ?>
              <div style="text-align:right;"><a href="#top">Back to top</a>
              </div>
            <?php } ?>
            <?php if ($webcasts) { ?>
              <a name="webcasts"></a>
              <h4>Webcasts</h4>
              <?php print $webcasts; ?>
              <div style="text-align:right;"><a href="#top">Back to top</a>
              </div>
            <?php } ?>
            <?php if ($case_studies) { ?>
              <a name="case_studies"></a>
              <h4>Case Studies</h4>
              <?php print $case_studies; ?>
              <div style="text-align:right;"><a href="#top">Back to top</a>
              </div>
            <?php } ?>
          </div>
        </div>
      </div><!-- #tabs-2 -->

      <div id="tabs-3">
        <div class="column-grid">

          <!-- List Products By Family -->
          <div class="col-2-3">

            <?php foreach ($products_by_family as $family_list) { ?>

              <a name="family-product-list-<?php print $family_list[0]; ?>"
                 id="family-product-list-<?php print $family_list[0]; ?>"></a>
              <h2><?php print $family_list[1]; ?></h2>
              <div class="clear_10px;">&nbsp;</div>

              <?php foreach ($family_list[2] as $product) { ?>

                <div class="column-grid">
                  <div class="col-1-3">
                    <div style="padding:1em;">
                      <?php if(isset($product->field_field_prod_hub_img[0]['raw']['uri'])): ?>
                        <img src="<?php print file_create_url($product->field_field_prod_hub_img[0]['raw']['uri']); ?>" style="width:auto; max-width:100%;" />
                      <?php endif; ?>
                    </div>
                  </div>
                  <div class="col-2-3">
                    <h5 class="hub_product_title"><a href="/<?php print drupal_lookup_path('alias', 'node/'.$product->nid); ?>"><?php print $product->node_title; ?></a></h5>
                    <div class="hub_product_desc">
                      <?php if (isset($product->field_field_product_desc[0]['raw']['value'])): ?>
                        <?php print $product->field_field_product_desc[0]['raw']['value']; ?>
                      <?php endif; ?></div>
                    <div class="hub_product_desc"><div class="btn_143w"><a href="/<?php print drupal_lookup_path('alias', 'node/'.$product->nid); ?>">Learn More</a></div></div>
                  </div>
                </div>

                <div class='clear_15px'>&nbsp;</div>
                <div class='clear_1px'><img src='/sites/flukenetworks.com/themes/adaptivetheme_subtheme_fnet/images/hub_product_divider.gif' width='650' height='1' border='0'></div>
                <div class='clear_15px'>&nbsp;</div>

              <?php } ?>
              
              <div style='text-align:right;'><a href='#top'>Back to top</a></div>
              <div class='clear_15px'>&nbsp;</div>
              <div class='clear_1px'><img src='/sites/flukenetworks.com/themes/adaptivetheme_subtheme_fnet/images/hub_product_divider.gif' width='650' height='1' border='0'></div>
              <div class='clear_15px'>&nbsp;</div>
            <?php } ?>

          </div>

          <div class="col-1-3">
					<div style="margin-left: 25px;padding-top: 15px;">

							<h5>PROMOTIONS</h5>
              <?php if (fnet_common_safe_get($field_industry_promo_1, 0, 'title')) { ?>
                <p>
                  <strong>
										<a
                      href="<?php print fnet_common_safe_get($field_industry_promo_1, 0, 'url'); ?>"><?php print fnet_common_safe_get($field_industry_promo_1, 0, 'title'); ?></a></strong>
                </p>
              <?php } ?>
              <?php if (fnet_common_safe_get($field_industry_promo_2, 0, 'title')) { ?>
                <p>
                  <strong>
										<a
                      href="<?php print fnet_common_safe_get($field_industry_promo_2, 0, 'url'); ?>"><?php print fnet_common_safe_get($field_industry_promo_2, 0, 'title'); ?></a></strong>
                </p>
              <?php } ?>
              <?php if (fnet_common_safe_get($field_industry_promo_3, 0, 'title')) { ?>
                <p>
                  <strong>
										<a
                      href="<?php print fnet_common_safe_get($field_industry_promo_3, 0, 'url'); ?>"><?php print fnet_common_safe_get($field_industry_promo_3, 0, 'title'); ?></a></strong>
                </p>
              <?php } ?>

            </div>						
            <div style="margin-left: 25px;padding-top: 15px;">

              <?php if (fnet_common_safe_get($field_industry_demo_1, 0, 'title')) { ?>
                <h5>VIDEOS &amp; DEMOS</h5>
                <p>
                  <strong><?php print fnet_common_safe_get($field_industry_demo_type_1, 0, 'value'); ?>
                    :<br/><a
                      href="<?php print fnet_common_safe_get($field_industry_demo_1, 0, 'url'); ?>"><?php print fnet_common_safe_get($field_industry_demo_1, 0, 'title'); ?></a></strong>
                </p>
              <?php } ?>
              <?php if (fnet_common_safe_get($field_industry_demo_2, 0, 'title')) { ?>
                <p>
                  <strong><?php print fnet_common_safe_get($field_industry_demo_type_2, 0, 'value'); ?>
                    :<br/><a
                      href="<?php print fnet_common_safe_get($field_industry_demo_2, 0, 'url'); ?>"><?php print fnet_common_safe_get($field_industry_demo_2, 0, 'title'); ?></a></strong>
                </p>
              <?php } ?>
              <?php if (fnet_common_safe_get($field_industry_demo_3, 0, 'title')) { ?>
                <p>
                  <strong><?php print fnet_common_safe_get($field_industry_demo_type_3, 0, 'value'); ?>
                    :<br/><a
                      href="<?php print fnet_common_safe_get($field_industry_demo_3, 0, 'url'); ?>"><?php print fnet_common_safe_get($field_industry_demo_3, 0, 'title'); ?></a></strong>
                </p>
              <?php } ?>

            </div>
						<div style="margin-left: 25px;padding-top: 15px;">

              <?php if (fnet_common_safe_get($field_industry_trial_1, 0, 'title')) { ?>
                <h5>TRIALS</h5>
                <p>
                  <strong><?php print fnet_common_safe_get($field_industry_trial_type_1, 0, 'value'); ?>
                    :<br/><a
                      href="<?php print fnet_common_safe_get($field_industry_trial_1, 0, 'url'); ?>"><?php print fnet_common_safe_get($field_industry_trial_1, 0, 'title'); ?></a></strong>
                </p>
              <?php } ?>
              <?php if (fnet_common_safe_get($field_industry_trial_2, 0, 'title')) { ?>
                <p>
                  <strong><?php print fnet_common_safe_get($field_industry_trial_type_2, 0, 'value'); ?>
                    :<br/><a
                      href="<?php print fnet_common_safe_get($field_industry_trial_2, 0, 'url'); ?>"><?php print fnet_common_safe_get($field_industry_trial_2, 0, 'title'); ?></a></strong>
                </p>
              <?php } ?>
              <?php if (fnet_common_safe_get($field_industry_trial_3, 0, 'title')) { ?>
                <p>
                  <strong><?php print fnet_common_safe_get($field_industry_trial_type_3, 0, 'value'); ?>
                    :<br/><a
                      href="<?php print fnet_common_safe_get($field_industry_trial_3, 0, 'url'); ?>"><?php print fnet_common_safe_get($field_industry_trial_3, 0, 'title'); ?></a></strong>
                </p>
              <?php } ?>

            </div>
          
          </div>

        </div>
      </div><!-- #tabs-3 -->
    </div><!-- #tabs -->
    </div>
  </div>

</article>
