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

<?php if (isset($field_background_image[0]['uri'])): ?>
    <?php $bgimgpath = file_create_url($field_background_image[0]['uri']); ?>

  <style>
    #page { background-image:url(<?php print $bgimgpath; ?>); }
  </style>

<?php else: ?>
  <style>
    #page { background-image:url('/<?php print drupal_get_path("module", "industries_families"); ?>/css/images/industry_hub_Blank.jpg'); }
  </style>

<?php endif; ?>

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
<?php $banner = ''; ?>
    <div class="jcarousel-wrapper">
        <div class="jcarousel">
            <ul>
                <?php for ($i = 1; $i <= 5; $i++): ?>
                    <?php if (isset(${"field_family_banner_text_$i"}[0]['value'])): ?>
                        <?php $banner = ${"field_family_banner_text_$i"}[0]['value']; ?>
                    <?php elseif (isset(${"field_family_banner_text_$i"}[LANGUAGE_NONE][0]['value'])): ?>
                        <?php $banner = ${"field_family_banner_text_$i"}[LANGUAGE_NONE][0]['value']; ?>
                <?php endif; ?>
                <li><?php print $banner; ?></li>
                <?php endfor; ?>
            </ul>
        </div>
        <a href="#" class="jcarousel-control-prev">&lsaquo;</a>
        <a href="#" class="jcarousel-control-next">&rsaquo;</a>
        <p class="jcarousel-pagination"></p>
    </div>
</div>
<!-- Add and enable Tabs sections. -->
<script>
  $(function() {
    $( "#tabs" ).tabs(); // Instantiate the tabs UI.

    hash = $(location).attr('hash').slice(1);
    if (hash) {
      clickid = $('[name*=' + hash + ']').closest('.ui-tabs-panel').attr('id');
      console.log(clickid);
      $('.ui-tabs-anchor[href=#' + clickid + ']').trigger("click");
      $('html, body').animate({
        scrollTop: $('[name*=' + hash + ']').offset().top
      }, 1000);
    }

    // Enable the "See Products" button to show tab 3.
    $('.show-products').click(function(e){
      e.preventDefault(); // Stop the default behavior.
      $('.ui-tabs-anchor[href=#tabs-3]').trigger("click");
//      location.href = $(this).href(); // Drop to the matching anchor
// // Scroll to top of page.
      $('html, body').animate(
       { scrollTop: $('#industry_tabs').offset().top }
       , 750);
    });
  });
</script>
  <div class="clear_20px">&nbsp;</div>
  <div class="clear_20px">&nbsp;</div>
  <div id="tabs" style="margin-top:1em;">
  <div id="industry_tab_wrapper">
    <div id="industry_tab_main">
      <div id="industry_tabs">
        <ul>
          <!-- Display tab buttons. -->
          <li id="tab1"><a href="#tabs-1">Overview</a></li>
          <li id="tab2"><a href="#tabs-2">Expertise</a></li>
          <li><a id="tab3" href="#tabs-3">Products</a></li>
        </ul>
      </div>
    </div>
  </div>
  <div class="clear_15px;">&nbsp;</div>
  <div class="clear_15px;">&nbsp;</div>
<!-- Display tab content if it exists. -->
<div id="tabs-1">
  <div class="column-grid">

    <!-- Overview -->
    <div class="col-2-3">

      <?php print $field_family_overview[0]['value']; ?>

    </div>

    <!-- "Right Hand Column" Content -->
    <div class="col-1-3">
      <div style="padding:1em;">
        <?php for ($j = 1; $j <= 3; $j++): ?>
            <?php if (isset(${"field_overview_box_" . $j . "_title"}[0]['value'])): ?>
                <h5><?php print ${"field_overview_box_" . $j . "_title"}[0]['value']; ?></h5>
            <?php endif; ?>
            <?php if (isset(${"field_overview_box_" . $j . "_image"}[0]['uri'])): ?>
                <div><img src="<?php print file_create_url(${"field_overview_box_" . $j . "_image"}[0]['uri']); ?>" style="width:auto; max-width:100%;" /></div>
            <?php endif; ?>
            <?php if (isset(${"field_overview_box_" . $j . "_description"}[0]['value'])): ?>
                <p><?php print ${"field_overview_box_" . $j . "_description"}[0]['value']; ?></p>
            <?php endif; ?>
            <?php if (isset(${"field_overview_box_" . $j . "_link"}[0]['title'])): ?>
                <p><a href="<?php print ${"field_overview_box_" . $j . "_link"}[0]['url']; ?>"><?php print ${"field_overview_box_" . $j . "_link"}[0]['title']; ?></a></p>
            <?php endif; ?>
            <?php if (isset(${"field_overview_box_" . $j . "_description"}[0]['value'])): ?>
                <hr style="margin:2em 0; border:0; height:1px; background-color:#eee; clear:both;" />
            <?php endif; ?>
        <?php endfor; ?>
      </div>
    </div>
  </div>
</div><!-- #tabs-1 -->

<div id="tabs-2">
  <div class="column-grid">
    <div class="<?php print $expertise_column_1_class; ?>">

      <?php print $field_family_expertise[0]['value']; ?>

    </div>
    <div class="<?php print $expertise_column_2_class; ?>">
      <div style="padding:1em;">
        <?php for ($k = 1; $k <= 3; $k++): ?>
          
            <?php if (isset(${"field_expert_box_" . $k . "_title"}[0]['value'])): ?>
                <h5><?php print ${"field_expert_box_" . $k . "_title"}[0]['value']; ?></h5>
            <?php endif; ?>
            <?php if (isset(${"field_expert_box_" . $k . "_image"}[0]['uri'])): ?>
                <p><img src="<?php print file_create_url(${"field_expert_box_" . $k . "_image"}[0]['uri']); ?>" style="width:auto; max-width:100%;" /></p>
            <?php endif; ?>
            <?php if (isset(${"field_expert_box_" . $k . "_description"}[0]['value'])): ?>
                <p><?php print ${"field_expert_box_" . $k . "_description"}[0]['value']; ?></p>
            <?php endif; ?>
            <?php if (isset(${"field_expert_box_" . $k . "_link"}[0]['title'])): ?>
                <p><a href="<?php print ${"field_expert_box_" . $k . "_link"}[0]['url']; ?>"><?php print ${"field_expert_box_" . $k . "_link"}[0]['title']; ?></a></p>
            <?php endif; ?>

            <?php if (isset(${"field_expert_box_" . $k . "_description"}[0]['value'])): ?>
                <hr style="margin:2em 0; border:0; height:1px; background-color:#eee; clear:both;" />
            <?php endif; ?>
        <?php endfor; ?>
      </div>
    </div>
  </div>
</div><!-- #tabs-2 -->

<div id="tabs-3">
  <div class="column-grid">

    <!-- List Products By Family -->
    <div class="col-2-3">

        <a name="family-product-list-<?php print $products_by_family[0]; ?>"></a>
        <h2><?php print $products_by_family[1]; ?></h2>
        <div class="clear_10px;">&nbsp;</div>
        <?php foreach ($products_by_family[2] as $product): ?>

          <div class="column-grid">
            <div class="col-1-3">
              <div style="padding:1em;">
                <img src="<?php print file_create_url($product->field_field_prod_hub_img[0]['raw']['uri']); ?>" style="width:auto; max-width:100%;" alt="<?php print $product->field_field_prod_hub_img[0]['raw']['alt']?>" />
              </div>
            </div>
            <div class="col-2-3">
              <h5 class="hub_product_title"><a href="/<?php print drupal_lookup_path('alias', 'node/'.$product->nid); ?>"><?php print $product->node_title; ?></a></h5>
              <div class="hub_product_desc"><?php print $product->field_field_product_desc[0]['raw']['value']; ?></div>
            <div class="hub_product_desc"><div class="btn_143w"><a href="/<?php print drupal_lookup_path('alias', 'node/'.$product->nid); ?>">Learn More &#187;</a></div></div>
            </div>
            <div class='clear_15px'>&nbsp;</div>
            <div class='clear_1px'><img src='/sites/all/themes/adaptivetheme_subtheme_fnet/images/hub_product_divider.gif' width='650' height='1' border='0'></div>
            <div class='clear_15px'>&nbsp;</div>
          </div>

        <?php endforeach; ?>

    </div>

    <div class="col-1-3">
      <div style="margin-left: 25px;padding-top: 15px;">
        <?php for ($l = 1; $l <= 3; $l++): ?>
            <?php if (isset(${"field_product_box_" . $l . "_title"}[0]['value'])): ?>
                <h5><?php print ${"field_product_box_" . $l . "_title"}[0]['value']; ?></h5>
            <?php endif; ?>
            <?php if (isset(${"field_product_box_" .$l . "_image"}[0]['uri'])): ?>
                <p><img src="<?php print file_create_url(${"field_product_box_" .$l . "_image"}[0]['uri']); ?>" style="width:auto; max-width:100%;" /></p>
            <?php endif; ?>
            <?php if (isset(${"field_product_box_" . $l . "_description"}[0]['value'])): ?>
                <p><?php print ${"field_product_box_" . $l . "_description"}[0]['value']; ?></p>
            <?php endif; ?>
            <?php if (isset(${"field_product_box_" . $l . "_link"}[0]['title'])): ?>
            <p><a href="<?php print ${"field_product_box_" . $l . "_link"}[0]['url']; ?>"><?php print ${"field_product_box_" . $l . "_link"}[0]['title']; ?></a></p>
            <?php endif; ?>
            <?php if (isset(${"field_product_box_" . $l . "_description"}[0]['value'])): ?>
                <hr style="margin:2em 0; border:0; height:1px; background-color:#eee; clear:both;" />
            <?php endif; ?>
        <?php endfor; ?>
      </div>
    </div>

  </div>
</div><!-- #tabs-3 -->

</div><!-- #tabs -->

</article>
