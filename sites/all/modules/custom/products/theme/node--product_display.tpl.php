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

$product_features = $content['product_features'];
$product_moa = $content['product_moa'];
//$product_models = $content['product_models'];
//$product_accessories = $content['product_accessories'];
$myDoc = $content['product_documents'];
$myDemos = $content['product_demos'];
$product_case_studies = $content['product_case_studies'];
$relatedProd = views_get_view_result('product_related_prod');

?>

<div id="stickynav">
  <div class="toc-container">
    <!-- Top -->
    <a href="#topanchor" id="top">&nbsp;&nbsp;&nbsp;</a>

    <?php // Build array of menu item data
    $menuArray = array();

    // Overview
    if( fnet_common_safe_get($field_product_details, 0, 'value') ){
      $menuArray[] = array("overview", "Overview");
    }

    // Features
    if(count($product_features) > 0){
      $menuArray[] = array("features", "Features");
    }

    // Models & Accessories
    if(count($product_moa) > 0){
      $menuArray[] = array("models_and_accessories", "Models & Accessories");
    }

    // Specifications
    if( fnet_common_safe_get($field_product_specs, 0, 'value') ){
      $menuArray[] = array("specifications", "Specifications");
    }

    // Documents
    if($myDoc && count($myDoc) > 0){
      $menuArray[] = array("documents", "Documents");
    }

    // Demos
    if($myDemos && count($myDemos) > 0){
      $menuArray[] = array("demos", "Demos");
    }

    // Case Studies
    if(count($product_case_studies)){
      $menuArray[] = array("case_studies", "Case Studies");
    }

    // Custom Tab 01
    if( fnet_common_safe_get($field_prod_ctab_name_1, 0, 'value')  && fnet_common_safe_get($field_prod_ctab_data_1, 0, 'value') ){
      $menuArray[] = array(str_replace("&","and",str_replace(" ","_",strtolower(fnet_common_safe_get($field_prod_ctab_name_1, 0, 'value')))), fnet_common_safe_get($field_prod_ctab_name_1, 0, 'value'));
    }

    // Custom Tab 02
    if( fnet_common_safe_get($field_prod_ctab_name_2, 0, 'value' ) && fnet_common_safe_get($field_prod_ctab_data_2, 0, 'value')){
      $menuArray[] = array(str_replace("&","and",str_replace(" ","_",strtolower(fnet_common_safe_get($field_prod_ctab_name_2, 0, 'value')))), fnet_common_safe_get($field_prod_ctab_name_2, 0, 'value'));
    }

    // Custom Tab 03
    if( fnet_common_safe_get($field_prod_ctab_name_3, 0, 'value') && fnet_common_safe_get($field_prod_ctab_data_3, 0, 'value')){
      $menuArray[] = array(str_replace("&","and",str_replace(" ","_",strtolower(fnet_common_safe_get($field_prod_ctab_name_3, 0, 'value')))), fnet_common_safe_get($field_prod_ctab_name_3, 0, 'value'));
    }

    // Custom Tab 04
    if (fnet_common_safe_get($field_prod_ctab_name_4, 0, 'value') && fnet_common_safe_get($field_prod_ctab_data_4, 0, 'value')) {
      $menuArray[] = array(str_replace("&","and",str_replace(" ","_",strtolower(fnet_common_safe_get($field_prod_ctab_name_4, 0, 'value')))), fnet_common_safe_get($field_prod_ctab_name_4, 0, 'value'));
    }

    // Custom Tab 05
    if(fnet_common_safe_get($field_prod_ctab_name_5, 0, 'value') && fnet_common_safe_get($field_prod_ctab_data_5, 0, 'value')){
      $menuArray[] = array(str_replace("&","and",str_replace(" ","_",strtolower(fnet_common_safe_get($field_prod_ctab_name_5, 0, 'value')))), fnet_common_safe_get($field_prod_ctab_name_5, 0, 'value'));
    }

/*
only 5 tabs
    // Custom Tab 06
    if(fnet_common_safe_get($field_prod_ctab_name_6, 0, 'value') && fnet_common_safe_get($field_prod_ctab_data_6, 0, 'value')){
      $menuArray[] = array(str_replace("&","and",str_replace(" ","_",strtolower(fnet_common_safe_get($field_prod_ctab_name_6, 0, 'value')))), fnet_common_safe_get($field_prod_ctab_name_6, 0, 'value'));
    }
*/
    for($i=0; $i < count($menuArray); $i++){

      // No-Wrap the last two elements in the section nav to avoid
      // having only one menu item by itself on the bottom row.
      if($i == count($menuArray) - 2){ ?>
        <span style="white-space:nowrap;">
      <?php } ?>

      <a href="#<?php echo $menuArray[$i][0]; ?>"><?php echo $menuArray[$i][1]; ?></a>

      <?php if($i == count($menuArray) - 1){ ?>
        </span>
      <?php }

    } ?>

  </div>
</div>
<!-- Build Page Section Menu - END -->

<article id="node-<?php print $node->nid; ?>" class="product-page <?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>

  <div<?php print $content_attributes; ?>>
    <?php // print render($content); ?>

    <div class="product-page-section column-grid">

      <div class="col-3-5">

        <!-- Product image carousel -->
        <?php $youtubeUrl = "";
        if(fnet_common_safe_get($field_prod_video_img_t_1, 0, 'filename')
          || fnet_common_safe_get($field_prod_carousel_img_lg_1, 0, 'filename')
          || fnet_common_safe_get($field_prod_carousel_img_lg_2, 0, 'filename')
          || fnet_common_safe_get($field_prod_carousel_img_lg_3, 0, 'filename')
          || fnet_common_safe_get($field_prod_carousel_img_lg_4, 0, 'filename')
          || fnet_common_safe_get($field_prod_carousel_img_lg_5, 0, 'filename')
          || fnet_common_safe_get($field_prod_carousel_img_lg_6, 0, 'filename')
          || fnet_common_safe_get($field_prod_carousel_img_lg_7, 0, 'filename')
          || fnet_common_safe_get($field_prod_carousel_img_lg_8, 0, 'filename')
          || fnet_common_safe_get($field_prod_carousel_img_lg_9, 0, 'filename')
          || fnet_common_safe_get($field_prod_carousel_img_lg_10, 0, 'filename') ) {

          if (fnet_common_safe_get($field_prod_video_youtube_url,0,'display_url')) {
            $youtubeUrl = fnet_common_safe_get($field_prod_video_youtube_url, 0, 'display_url');
            if (substr($youtubeUrl, 0, 5) == 'http:') {
              $youtubeUrl = str_replace("http:", "", $youtubeUrl);
            } else if (substr($youtubeUrl, 0, 6) == 'https:') {
              $youtubeUrl = str_replace("https:", "", $youtubeUrl);
            } else if (substr($youtubeUrl, 0, 2) != '//') {
              $youtubeUrl = "//". $youtubeUrl;
            }
          } ?>

          <script>
            (function($) {
              // This is the connector function.
              // It connects one item from the navigation carousel to one item from the
              // stage carousel.
              // The default behaviour is, to connect items with the same index from both
              // carousels. This might _not_ work with circular carousels!
              var connector = function(itemNavigation, carouselStage) {
                return carouselStage.jcarousel('items').eq(itemNavigation.index());
              };

              $(function() {
                // Setup the carousels. Adjust the options for both carousels here.
                var carouselStage      = $('.carousel-stage').jcarousel();
                var carouselNavigation = $('.carousel-navigation').jcarousel({
                  wrap: 'circular'
                });

                // We loop through the items of the navigation carousel and set it up
                // as a control for an item from the stage carousel.
                carouselNavigation.jcarousel('items').each(function() {
                  var item = $(this);

                  // This is where we actually connect to items.
                  var target = connector(item, carouselStage);

                  item
                    .on('jcarouselcontrol:active', function() {
                      carouselNavigation.jcarousel('scrollIntoView', this);
                      item.addClass('active');
                    })
                    .on('jcarouselcontrol:inactive', function() {
                      item.removeClass('active');
                    })
                    .jcarouselControl({
                      target: target,
                      carousel: carouselStage
                    });
                });
              <?php if (fnet_common_safe_get($field_prod_video_img_t_1, 0, 'filename') && $youtubeUrl) { ?>
                $('.image_frame').click(function() {
                  $('#youtubeInnerFrame').attr('src', '');
                });
                $('.video_frame').click(function() {
                  $('#youtubeInnerFrame').attr('src', '<?php print $youtubeUrl; ?>');
                });
              <?php } ?>
                <?php if (fnet_common_safe_get($field_prod_video_img_t_1, 0, 'filename') && fnet_common_safe_get($field_prod_video_lg_1,0,'filename')) { ?>
                $('.image_frame').click(function() {
                  $('#movieFrame').attr('data', '');
                });
                <?php } ?>
                // Setup controls for the stage carousel
                $('.prev-stage')
                  .on('jcarouselcontrol:inactive', function() {
                    $(this).addClass('inactive');
                  })
                  .on('jcarouselcontrol:active', function() {
                    $(this).removeClass('inactive');
                  })
                  .jcarouselControl({
                    target: '-=1'
                  });

                $('.next-stage')
                  .on('jcarouselcontrol:inactive', function() {
                    $(this).addClass('inactive');
                  })
                  .on('jcarouselcontrol:active', function() {
                    $(this).removeClass('inactive');
                  })
                  .jcarouselControl({
                    target: '+=1'
                  });

                // Setup controls for the navigation carousel
                $('.prev-navigation')
                  .on('jcarouselcontrol:inactive', function() {
                    $(this).addClass('inactive');
                  })
                  .on('jcarouselcontrol:active', function() {
                    $(this).removeClass('inactive');
                  })
                  .jcarouselControl({
                    target: '-=1'
                  });

                $('.next-navigation')
                  .on('jcarouselcontrol:inactive', function() {
                    $(this).addClass('inactive');
                  })
                  .on('jcarouselcontrol:active', function() {
                    $(this).removeClass('inactive');
                  })
                  .jcarouselControl({
                    target: '+=1'
                  });
              });
            })(jQuery);
          </script>

          <div class="connected-carousels">
            <div class="stage">
              <div class="carousel carousel-stage">
                <ul>
                  <?php if(fnet_common_safe_get($field_prod_video_img_t_1,0,'filename')) { ?>
                    <li><?php if (fnet_common_safe_get($field_prod_video_lg_1,0,'filename')) { ?>
                        <object id="movieFrame" type="<?php print fnet_common_safe_get($field_prod_video_lg_1,0,'filemime'); ?>" data="<?php echo file_create_url(fnet_common_safe_get($field_prod_video_lg_1,0,'uri')); ?>" style="margin:0 10px;width:488px;height:385px;">
                          <param name="movie" value="<?php echo file_create_url(fnet_common_safe_get($field_prod_video_lg_1,0,'uri')); ?>" />
                          <param name="wmode" value="transparent" />
                          <param name="FlashVars" value="" />
                          <param name="quality" value="high" />
                          <param name="menu" value="false" />
                        </object>
                      <?php } else if ($youtubeUrl) { ?>
                        <iframe width="488px" height="385px" id="youtubeInnerFrame" src="<?php print $youtubeUrl; ?>" frameborder="0" allowfullscreen></></iframe>
                      <?php } else { ?>
                        <img width="488" src="<?php echo file_create_url(fnet_common_safe_get($field_prod_video_img_t_1,0,'uri')); ?>">
                      <?php } ?>
                    </li>
                  <?php } ?>
                  <?php $j = 0;
                    for ($i=1; $i<11; $i++) {
                      $fieldName = "field_prod_carousel_img_lg_".$i;
                      if (fnet_common_safe_get(${$fieldName}, 0, 'filename')) { ?>
                        <li><img width="488"
                               src="<?php echo file_create_url(fnet_common_safe_get(${$fieldName}, 0, 'uri')); ?>">
                        </li>
                    <?php
                        $j++;
                      }
                    } ?>
                </ul>
              </div>
            </div>
            <?php
              if ($j < 5) {
                $selectorWidth = $j*80 - 1; ?>
            <style>
              .product-page .connected-carousels .navigation {
                width: <?php print $selectorWidth; ?>px;
              }
              .product-page .connected-carousels .carousel-navigation {
                width: <?php print $selectorWidth; ?>px;
              }
            </style>
            <?php } ?>
            <div class="navigation">
              <a href="#" class="prev prev-navigation" style="text-decoration: none;">&lt;</a>
              <a href="#" class="next next-navigation">&gt;</a>

              <div class="carousel carousel-navigation">
                <ul>
                  <?php if(fnet_common_safe_get($field_prod_video_img_t_1,0,'filename')) { ?>
                    <li class="video_frame"><div class="thumb_image">
                      <img width="73" height='58px' src="<?php echo file_create_url(fnet_common_safe_get($field_prod_video_img_t_1,0,'uri')); ?>">
                        </div>
                    </li>
                  <?php } ?>
                  <?php
                  $j = 0;
                  for ($i=1; $i<11; $i++) {
                    $fieldName = "field_prod_carousel_img_t_".$i;
                    if (fnet_common_safe_get(${$fieldName}, 0, 'uri')) { ?>
                      <li class="image_frame"><div class="thumb_image">
                          <img width="73px" height='58px' src="<?php echo file_create_url(fnet_common_safe_get(${$fieldName}, 0, 'uri')); ?>">
                          </div>
                      </li>
                    <?php
                      $j++;
                    }
                  } ?>
                </ul>
              </div>
            </div>
          </div>

        <?php } ?>

      </div><!-- .col-3-5 -->

      <div class="col-2-5">

        <div id="At_A_Glance_Wrapper">

          <h1 class="headline"
              title="<?php print $node->title; ?>"><?php print $node->title; ?></h1>
          <h5><?php echo fnet_common_get_field_value('node', $node, 'field_product_desc'); ?></h5>

          <div><?php echo fnet_common_get_field_value('node', $node, 'field_product_ataglance'); ?></div>

          <table class="at-a-glance-buttons" width="100%" cellpadding="0" cellspacing="12px">

            <?php
            $buttonCount = 0; // Used to determine where to add <tr> tags.
            //TODO: figure out how to propigate translation status from $node
            $noTranslation = array(
              'cta_btn' => array(FALSE, FALSE, FALSE, FALSE, FALSE),
              'field_prod_wtb_online' => FALSE,
            );
            $btnSize = fnet_common_get_field_value('node', $node, 'field_prod_btn_cta_size'); // "1 line" or "2 lines"
            for ($i=0; $i<4; $i++) {
              if ( fnet_common_safe_get($field_prod_btn_calltoaction, $i, 'title') && fnet_common_safe_get($field_prod_btn_calltoaction, $i, 'display_url') ) {

                if ($buttonCount == 0 || $buttonCount == 2) {
                  echo "<tr>";
                } // Open table row at beginning of every two button

                if($noTranslation["cta_btn"][$i+1]) echo "<div class='OneLinkNoTx'>\n";

                ?>
                <td
                  <?php 
                  $attr=fnet_common_safe_get($field_prod_btn_calltoaction, $i, 'attributes');
                  if($attr == array("target" => "_blank") ){
                    $attr["onClick"] = "return false;"; ?>
                    onclick="window.open('<?php echo fnet_common_safe_get($field_prod_btn_calltoaction, $i, 'display_url'); ?>');"
                  <?php }else{ ?>
                    onclick="location.href = '<?php echo fnet_common_safe_get($field_prod_btn_calltoaction, $i, 'display_url'); ?>';"
                  <?php } ?>
                  <?php if($btnSize == "2 lines"){ ?>
                    style="height:45px;"
                  <?php } ?>
                  title="<?php echo $field_prod_btn_calltoaction[$i]['title']; ?>"
                  >
                  <?php
                  // apply line breaks in title by splitting title into separate lines
                  $btn_words = fnet_common_safe_get($field_prod_btn_calltoaction, $i, 'title');
                  $btn_url = fnet_common_safe_get($field_prod_btn_calltoaction, $i, 'display_url');
                  $lines = explode('<br>', $btn_words);
                  foreach ($lines as $btn_word) { 
                    echo l( $btn_word , $btn_url ,  array('attributes'=> $attr) );
                    echo '<br>';
                  }
                  ?>

                </td>

                <?php

                if($noTranslation["cta_btn"][$i+1]) echo "</div>\n";
                $buttonCount++;
                if($buttonCount == 2 || $buttonCount == 4) echo "</tr>"; // Close table row after every two buttons.
              }
            }

            if($buttonCount == 1 || $buttonCount == 3) echo "</tr>"; // After buttons are rendered, close table row if it ended on an odd number of buttons.

            ?>

            <?php 
$contact = fnet_common_safe_get($field_prod_contact_sales_button);
$wtb = fnet_common_safe_get($field_prod_where_to_buy_button);
            if ( $contact || $wtb) : ?>
              <tr>
                <?php if ( $contact ): ?>
                  <td
                    class="blue"
                    onclick="location.href = '/contact_sales?epi=<?php print products_clean_string($node->title); ?>';"
                    <?php if($btnSize == "2 lines"){ ?>
                      style="height:45px;"
                    <?php } ?>
                    title="Talk to an Expert"
                    >
                    <a
                      href="/contact_sales?epi=<?php print products_clean_string($node->title); ?>"
                      onclick=javascript:void(0);">
                      Talk to an Expert
                    </a>
                  </td>
                <?php endif ?>
                <?php if ($wtb) : ?>
                  <td
                    class="blue"
                    onclick="location.href = '/wheretobuy?tab=3&product=<?php print $node->nid; ?>';"
                    <?php if($btnSize == "2 lines"){ ?>
                      style="height:45px;"
                    <?php } ?>
                    title="Where to Buy"
                    >
                    <a
                      href="/wheretobuy?tab=3&product=<?php print $node->nid; ?>"
                      onclick=javascript:void(0);">
                      Where to Buy
                    </a>
                  </td>
                <?php endif ?>
              </tr>
            <?php endif ?>
          </table>

          <?php if (isset($field_prod_wtb_online[LANGUAGE_NONE][0]['title']) || isset($field_prod_wtb_online[LANGUAGE_NONE][1]['title']) || isset($field_prod_wtb_online[LANGUAGE_NONE][2]['title'])) { ?>
            <div class='clear_10px'>&nbsp;</div>
            <div id="buy-online-links-list" style="padding-left:15px;">
              <h2>Buy Online</h2>
              <?php
              if ($noTranslation["field_prod_wtb_online"]) print ("<div class=\"OneLinkNoTx\">");
              $wtbBuf = "";
              $linkBuf = "";
              for ($i=0; $i<3; $i++) {
                $addSpace = "";
                if ($field_prod_wtb_online[LANGUAGE_NONE][$i]['title']) {
                  if ($wtbBuf) {
                    $addSpace = ("&nbsp;&nbsp;|&nbsp;&nbsp;");
                    $linkBuf .= "--|--";
                  }
                  $linkBuf .= $field_prod_wtb_online[LANGUAGE_NONE][$i]['title'];
                  $wtbBuf .= ('<div style="float:left;font-weight: bold ;font-size: 13px;">');
                  $wtbBuf .= $addSpace;

                  $wtbBuf .= l($field_prod_wtb_online[LANGUAGE_NONE][$i]['title'], $field_prod_wtb_online[LANGUAGE_NONE][$i]['display_url'], array('attributes' => array('class'=>'buy-online-link', 'target'=>'new', 'title'=>$field_prod_wtb_online[LANGUAGE_NONE][$i]['title'])));
                  $wtbBuf .= ('</div>');
                }
              }
              // Max character to keep all links in one line = 48
              if (strlen($linkBuf) > 43) $wtbBuf = str_ireplace("<div style=\"float:left;font-weight: bold ;font-size: 13px;\">&nbsp;&nbsp;|&nbsp;&nbsp;", "<div style=\"clear:both; line-height: 0px;\">&nbsp;</div><div style=\"float:left;font-weight: bold ;font-size: 13px;\">", $wtbBuf);
              print $wtbBuf;
              if ($noTranslation["field_prod_wtb_online"]) print ("</div>");
              ?>
              <div style="clear:both; line-height: 12px;">&nbsp;</div>
              <?php // if ($node->field_prod_where_to_buy_button[0]['value'] == 'on'): ?>
              <div style="font-weight: bold ;font-size: 13px;">
                <?php print l('See more online resellers or buy locally','wheretobuy',array('query' => array('tab' => '3', 'product' => $node->nid))); ?>
              </div>
            </div>

          <?php } ?>
        </div><!-- #At_A_Glance_Wrapper -->

      </div><!-- .col-2-5 -->
    </div><!-- .column-grid (image carousel, product intro, call to action buttons) -->

    <div>

      <!-- Overview -->
      <?php $overview = fnet_common_safe_get($field_product_details, 0, 'value');
      if (!empty($overview)):
        ?>
      <div class="product-page-section column-grid">
        <a class="toc-anchor" name="overview">&nbsp;</a>
        <div class="section-container">
          <h3 class="product-page-section-title"><span>Overview</span></h3>
          <div><?php echo fnet_common_safe_get($field_product_details, 0, 'value'); ?></div>

        </div>
      </div><!-- Overview -->
      <?php endif; ?>
      <!-- Features -->
      <?php

      if(count($product_features) > 0): ?>

        <div class="product-page-section column-grid">

          <a class="toc-anchor" name="features">&nbsp;</a>
          <div class="section-container">
            <h3 class="product-page-section-title"><span>Features</span></h3>

              <div class="ui-accordion">

                  <?php
                  for($i=0; $i<count($product_features); $i++){ ?>

                    <h6 class="product-feature-title"><strong><?php echo $product_features[$i]->node_title; ?></strong></h6>
                    <div>
                      <div><?php echo $product_features[$i]->field_body[0]['raw']['value']; ?></div>
                      <div style="clear:both;"></div>
                    </div>

                  <?php } ?>

              </div>
          </div>

        </div>

      <?php endif ?><!-- Features -->

      <!-- Models & Accessories -->
      <?php

      if(count($product_moa) > 0): ?>

        <div class="product-page-section column-grid">

          <a class="toc-anchor" name="models_and_accessories">&nbsp;</a>
          <div class="section-container">
            <h3 class="product-page-section-title"><span>Models &amp; Accessories</span></h3>

            <?php foreach (array(
                             "Models",
                             "Suites",
                             "Bundles",
                             "Kits",
                             "Options",
                             "Accessories",
                             "Upgrades",
                             "Professional Services"
                           ) as $modType) {
                $moa = array();
              if ( isset($content['product_moa_' . $modType]) && count( $content['product_moa_' . $modType] ) > 0) {
                $moa = $content['product_moa_' . $modType];
                 ?>
                <div class="clear_15px">&nbsp;</div>
                <h6 class="product-moa-title"><?php print $modType; ?></h6>

                <table id="product-<?php print strtolower($modType); ?>">
                  <thead>
                  <tr class="table-head">
                    <td width="20%">Model Number/Name</td>
                    <td>Description</td>
                  </tr>
                  </thead>

                  <?php for ($i = 0; $i < count($moa); $i++) {
                    $support_options = module_invoke('products', 'support_by_moa', $moa[$i]->nid);
                    if (!empty($support_options)) {
                      $support_link = '<a class="support-link">Gold Support</a>';
                    }
                    ?>

                    <tr class="<?php print ($i % 2 == 0) ? 'odd' : 'even'; ?>">
                      <td width="20%">
                        <?php print $moa[$i]->node_title; ?>
                        <?php if ($support_options) { ?>
                          <div
                            class="show-support-link"><?php print $support_link; ?>
                            <span class="gs_pointer">&raquo;</span></div>
                        <?php } ?>
                      </td>
                      <td>
                        <div><?php print $moa[$i]->field_body[0]['raw']['value']; ?></div>
                      </td>
                    </tr>
                    <?php if ($support_options) { ?>
                      <tr class="<?php print ($i % 2 == 0) ? 'odd' : 'even'; ?>"
                          style="padding-top: 0px;padding-bottom: 0px;">
                        <td colspan="2"
                            style="padding-top: 0px;padding-bottom: 0px;">
                          <div class="support-options show-support">
                            <div
                              class="show-support-div"><?php print $support_options; ?></div>
                          </div>
                        </td>
                      </tr>
                    <?php } ?>
                  <?php } ?>

                </table>

              <?php }
            }
            ?>
          </div>

        </div>

      <?php endif ?><!-- Models & Accessories -->

      <!-- Specifications -->
      <?php if( fnet_common_safe_get($field_product_specs, 0, 'value') ): ?>

        <div class="product-page-section column-grid">

          <a class="toc-anchor" name="specifications">&nbsp;</a>
          <div class="section-container">
            <h3 class="product-page-section-title"><span>Specifications</span></h3>
            <?php echo fnet_common_safe_get($field_product_specs, 0, 'value'); ?>
            <div style="clear:both;"></div>
          </div>

        </div>

      <?php endif ?><!-- Specifications -->

      <!-- Documents -->
      <?php if (count($myDoc) > 0) { ?>

        <div class="product-page-section column-grid">

          <a class="toc-anchor" name="documents">&nbsp;</a>

          <div class="section-container documents-section">
            <h3 class="product-page-section-title"><span>Documents</span></h3>

            <?php foreach (array(
                             'brochures',
                             'data sheets',
                             'catalogs',
                             'application notes',
                             'white papers',
                             'flyers'
                           ) as $type) {
              if (isset($myDoc[$type])) { ?>
                <div class="clear_15px;">&nbsp;</div>
                <h4><?php echo ucwords($type); ?></h4>
                <table width="100%" cellpadding="5">
                  <thead>
                    <tr>
                      <th width="80%">Title/Description</th>
                      <th>Download</th>
                      <th>&nbsp;</th>
                    </tr>
                  </thead>
                  <tbody>
                    <?php echo $myDoc[$type]; ?>
                  </tbody>
                </table>
                <div style="clear:both;"></div>

              <?php }
            } ?>

          </div>

        </div>

      <?php } ?><!-- Documents -->

      <!-- Demos -->
      <?php

      if (!empty($myDemos) > 0) { ?>

        <div class="product-page-section column-grid">

          <a class="toc-anchor" name="demos">&nbsp;</a>
          <div class="section-container">
            <h3 class="product-page-section-title"><span>Demos</span></h3>
            <table width="100%">
              <thead>
              <tr>
                <th width="60%">Title/Description</th>
                <th>Demo</th>
                <th width="1px">&nbsp;</th>
              </tr>
              </thead>
              <tbody>
                <?php echo $myDemos; ?>
              </tbody>
            </table>
            <div style="clear:both;"></div>
          </div>

        </div>

      <?php } ?><!-- Demos -->

      <!-- Case Studies -->
      <div class="product-page-section column-grid">
        <?php if (count($product_case_studies) > 0) {

          $headerPrinted = false;

          foreach ($product_case_studies as $case_study) {

            if (!$headerPrinted){

              $headerPrinted = true; ?>
              <a class="toc-anchor" name="case_studies">&nbsp;</a>
              <div class="section-container">
                <h3 class="product-page-section-title"><span>Case Studies</span></h3>

            <?php } ?>
            <div class="clear_15px;">&nbsp;</div>
            <h6><strong><?php echo $case_study->node_title; ?></strong></h6>
            <div><?php echo $case_study->field_body[0]['rendered']['#markup']; ?></div>
            <div style="clear: both;line-height: 1px;;">&nbsp;</div>
            <div class="clear_1px;"><img
                src="/sites/flukenetworks.com/themes/adaptivetheme_subtheme_fnet/images/hub_product_divider.gif"
                width="650" height="1" border="0"></div>
            <div class="clear_10px;">&nbsp;</div>
          <?php }

          if ($headerPrinted){ ?>
            </div>
          <?php } ?>

        <?php } ?>
      </div><!-- Case Studies -->

      <!-- Custom Tab 1 -->
      <?php if(fnet_common_safe_get($field_prod_ctab_name_1, 0, 'value') && fnet_common_safe_get($field_prod_ctab_data_1, 0, 'value')){ ?>

        <div class="product-page-section column-grid">

          <a class="toc-anchor" name="<?php print str_replace("&","and",str_replace(" ","_",strtolower(fnet_common_safe_get($field_prod_ctab_name_1, 0, 'value')))); ?>">&nbsp;</a>
          <div class="section-container">
            <h3 class="product-page-section-title"><span><?php echo fnet_common_safe_get($field_prod_ctab_name_1, 0, 'value'); ?></span></h3>
            <div><?php echo fnet_common_safe_get($field_prod_ctab_data_1, 0, 'value'); ?></div>
            <div style="clear:both;"></div>
          </div>

        </div>

      <?php } ?><!-- Custom Tab 1 -->

      <!-- Custom Tab 2 -->
      <?php if(fnet_common_safe_get($field_prod_ctab_name_2, 0, 'value') && fnet_common_safe_get($field_prod_ctab_data_2, 0, 'value')){ ?>

        <div class="product-page-section column-grid">

          <a class="toc-anchor" name="<?php print str_replace("&","and",str_replace(" ","_",strtolower(fnet_common_safe_get($field_prod_ctab_name_2, 0, 'value')))); ?>">&nbsp;</a>
          <div class="section-container">
            <h3 class="product-page-section-title"><span><?php echo fnet_common_safe_get($field_prod_ctab_name_2, 0, 'value'); ?></span></h3>
            <div><?php echo fnet_common_safe_get($field_prod_ctab_data_2, 0, 'value'); ?></div>
            <div style="clear:both;"></div>
          </div>

        </div>

      <?php } ?><!-- Custom Tab 2 -->

      <!-- Custom Tab 3 -->
      <?php if(fnet_common_safe_get($field_prod_ctab_name_3, 0, 'value') && fnet_common_safe_get($field_prod_ctab_data_3, 0, 'value')){ ?>

        <div class="product-page-section column-grid">

          <a class="toc-anchor" name="<?php print str_replace("&","and",str_replace(" ","_",strtolower(fnet_common_safe_get($field_prod_ctab_name_3, 0, 'value')))); ?>">&nbsp;</a>
          <div class="section-container">
            <h3 class="product-page-section-title"><span><?php echo fnet_common_safe_get($field_prod_ctab_name_3, 0, 'value'); ?></span></h3>
            <div><?php echo fnet_common_safe_get($field_prod_ctab_data_3, 0, 'value'); ?></div>
            <div style="clear:both;"></div>
          </div>

        </div>

      <?php } ?><!-- Custom Tab 3 -->

      <!-- Custom Tab 4 -->
      <?php if(fnet_common_safe_get($field_prod_ctab_name_4, 0, 'value') && fnet_common_safe_get($field_prod_ctab_data_4, 0, 'value')){ ?>

        <div class="product-page-section column-grid">

          <a class="toc-anchor" name="<?php print str_replace("&","and",str_replace(" ","_",strtolower(fnet_common_safe_get($field_prod_ctab_name_4, 0, 'value')))); ?>">&nbsp;</a>
          <div class="section-container">
            <h3 class="product-page-section-title"><span><?php echo fnet_common_safe_get($field_prod_ctab_name_4, 0, 'value'); ?></span></h3>
            <div><?php echo fnet_common_safe_get($field_prod_ctab_data_4, 0, 'value'); ?></div>
            <div style="clear:both;"></div>
          </div>

        </div>

      <?php } ?><!-- Custom Tab 4 -->

      <!-- Custom Tab 5 -->
      <?php if(fnet_common_safe_get($field_prod_ctab_name_5, 0, 'value') && fnet_common_safe_get($field_prod_ctab_data_5, 0, 'value')){ ?>

        <div class="product-page-section column-grid">

          <a class="toc-anchor" name="<?php print str_replace("&","and",str_replace(" ","_",strtolower(fnet_common_safe_get($field_prod_ctab_name_5, 0, 'value')))); ?>">&nbsp;</a>
          <div class="section-container">
            <h3 class="product-page-section-title"><span><?php echo fnet_common_safe_get($field_prod_ctab_name_5, 0, 'value'); ?></span></h3>
            <div><?php echo fnet_common_safe_get($field_prod_ctab_data_5, 0, 'value'); ?></div>
            <div style="clear:both;"></div>
          </div>

        </div>

      <?php } ?><!-- Custom Tab 5 -->

      <!-- Custom Tab 6 -->
      <?php
      /*
      5 tabs ?
       if(fnet_common_safe_get($field_prod_ctab_name_6, 0, 'value') && fnet_common_safe_get($field_prod_ctab_data_6, 0, 'value')){ ?>

        <div class="product-page-section column-grid">

          <a class="toc-anchor" name="<?php print str_replace("&","and",str_replace(" ","_",strtolower(fnet_common_safe_get($field_prod_ctab_name_6, 0, 'value')))); ?>">&nbsp;</a>
          <div class="section-container">
            <h3 class="product-page-section-title"><span><?php echo fnet_common_safe_get($field_prod_ctab_name_6, 0, 'value'); ?></span></h3>
            <div><?php echo fnet_common_safe_get($field_prod_ctab_data_6, 0, 'value'); ?></div>
            <div style="clear:both;"></div>
          </div>

        </div>

      <?php } 
*/
      ?><!-- Custom Tab 6 -->

      <?php
      $has_related_products = FALSE;
      foreach ($relatedProd as $rProd) {
        if ( (isset($rProd->field_field_prod_related_img[0]) ) &&  ( $rProd->field_field_prod_related_img[0]['rendered']['#path']['path']) ) {

          $related_product_file = $rProd->field_field_prod_related_img[0]['rendered']['#path']['path'];
          $related_product_nid = $rProd->node_field_data_field_prod_relatedprod_nid;
          $related_product_title = $rProd->node_field_data_field_prod_relatedprod_title;

          if ($related_product_file && $related_product_nid && $related_product_title) {
            $has_related_products = TRUE;
          }
        }
      }
      if ($has_related_products) { ?>

        <div class="product-page-section column-grid">

          <a class="toc-anchor" name="related-products">&nbsp;</a>
          <div class="section-container">
            <h3 class="product-page-section-title"><span>Related Products</span></h3>

            <div id="product-page-related-products">
              <ul>

                <?php
                foreach ($relatedProd as $rProd) {
                  if ( (isset($rProd->field_field_prod_related_img[0]) ) && ($rProd->field_field_prod_related_img[0]['rendered']['#path']['path']) ) {
                    $related_product_file = $rProd->field_field_prod_related_img[0]['rendered']['#path']['path'];
                    $related_product_nid = $rProd->node_field_data_field_prod_relatedprod_nid;
                    $related_product_title = $rProd->node_field_data_field_prod_relatedprod_title;

                    if ($related_product_file && $related_product_nid && $related_product_title) { ?>

                      <li>
                          <a href="/<?php echo drupal_lookup_path('alias','node/'.$related_product_nid); ?>">
                            <img src="<?php echo $related_product_file; ?>">
                            <p><?php echo $related_product_title; ?></p>
                          </a>
                      </li>

                    <?php }
                  }

                } ?>

              </ul>

            </div>
          </div>

        </div>

      <?php } ?><!-- Related Products -->

    </div>

  </div>

  <?php if ($links = render($content['links'])): ?>
    <nav<?php print $links_attributes; ?>><?php print $links; ?></nav>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

  <?php print render($title_suffix); ?>
</article>