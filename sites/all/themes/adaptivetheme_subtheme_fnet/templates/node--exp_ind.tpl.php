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
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>

  <div<?php print $content_attributes; ?>>
    <?php // print render($content); ?>

    <?php if (isset($node->field_exp_ind_banner_content['und'][0]['value']) && !isset($node->field_exp_ind_banner_image['und'][0]['value'])) { ?>
      <div>
        <?php print $node->field_exp_ind_banner_content['und'][0]['value']; ?>
      </div>

    <?php } elseif (isset($node->field_exp_ind_banner_image['und'][0]['value'])) { ?>
      <div>
        <?php print $node->field_exp_ind_banner_image['und'][0]['value']; ?>
      </div>

    <?php } ?>

    <?php if (isset($node->body['und'][0]['value'])) { ?>
      <div>
        <?php print $node->body['und'][0]['value']; ?>
      </div>
    <?php } ?>

    <script>
      $(function() {
        $( "#tabs" ).tabs();
      });
    </script>
    <div id="solutions_tabs_wrapper">
      <div id="tabs">
        <?php $tabCount = 0;
        $tab1 = false;
        $tab2 = false;
        $tab3 = false;
        $tab4 = false;
        $tabWidth = '0';
        if (isset($node->field_exp_ind_tab_title['und'][0]['value']) && isset($node->field_exp_ind_tab_content['und'][0]['value'])) {
          $tab1 = true;
          $tabCount++;
        }
        if (isset($node->field_exp_ind_tab2_title['und'][0]['value']) && isset($node->field_exp_ind_tab2_content['und'][0]['value'])) {
          $tab2 = true;
          $tabCount++;
        }
        if (isset($node->field_exp_ind_tab3_title['und'][0]['value']) && isset($node->field_exp_ind_tab3_content['und'][0]['value'])) {
          $tab3 = true;
          $tabCount++;
        }
        if (isset($node->field_exp_ind_tab4_title['und'][0]['value']) && isset($node->field_exp_ind_tab4_content['und'][0]['value'])) {
          $tab4 = true;
          $tabCount++;
        }
        switch ($tabCount) {
          case '4': $tabWidth = '228px'; break;
          case '3': $tabWidth = '308px'; break;
          case '2': $tabWidth = '462px'; break;
          case '1': $tabWidth = '928px'; break;
          default:
        }
        ?>
        <div id="tabs-seperator"><center>
            <ul>
              <!-- Display tab buttons if content exists. -->
              <?php if ($tab1) { ?>
                <li style="width: <?php print $tabWidth?>;"><a href="#tabs-1"><?php print $node->field_exp_ind_tab_title['und'][0]['value']; ?></a></li>
              <?php } ?>
              <?php if ($tab2) { ?>
                <li style="width: <?php print $tabWidth?>;"><a href="#tabs-2"><?php print $node->field_exp_ind_tab2_title['und'][0]['value']; ?></a></li>
              <?php } ?>
              <?php if ($tab3) { ?>
                <li style="width: <?php print $tabWidth?>;"><a href="#tabs-3"><?php print $node->field_exp_ind_tab3_title['und'][0]['value']; ?></a></li>
              <?php } ?>
              <?php if ($tab4) { ?>
                <li style="width: <?php print $tabWidth?>;"><a href="#tabs-4"><?php print $node->field_exp_ind_tab4_title['und'][0]['value']; ?></a></li>
              <?php } ?>
            </ul></center>
        </div>
        <!-- Display tab content if it exists. -->
        <?php if ($tab1) { ?>
          <div id="tabs-1">
            <?php print $node->field_exp_ind_tab_content['und'][0]['value']; ?>
          </div><!-- #tabs-1 -->
        <?php } ?>
        <?php if ($tab2) { ?>
          <div id="tabs-2">
            <?php print $node->field_exp_ind_tab2_content['und'][0]['value']; ?>
          </div><!-- #tabs-2 -->
        <?php } ?>
        <?php if ($tab3) { ?>
          <div id="tabs-3">
            <?php print $node->field_exp_ind_tab3_content['und'][0]['value']; ?>
          </div><!-- #tabs-3 -->
        <?php } ?>
        <?php if ($tab4) { ?>
          <div id="tabs-4">
            <?php print $node->field_exp_ind_tab4_content['und'][0]['value']; ?>
          </div><!-- #tabs-4 -->
        <?php } ?>

      </div>
    </div>
    <div class="clear_1px">&nbsp;</div>
  </div>

  <?php if ($links = render($content['links'])): ?>
    <nav<?php print $links_attributes; ?>><?php print $links; ?></nav>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

  <?php print render($title_suffix); ?>
</article>
