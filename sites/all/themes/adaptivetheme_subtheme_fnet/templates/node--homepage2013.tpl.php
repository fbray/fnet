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

    <div class="jcarousel-wrapper">
      <div class="jcarousel">
        <ul>

          <?php foreach ($field_home13_banner_html as $banner_slide): ?>
            <li><?php print $banner_slide['value']; ?></li>
          <?php endforeach; ?>

        </ul>
      </div>
      <a href="#" class="jcarousel-control-prev">&lsaquo;</a>
      <a href="#" class="jcarousel-control-next">&rsaquo;</a>
      <p class="jcarousel-pagination"></p>
    </div>

  </div>

  <div id="homepage-expertise" class="column-grid">

    <div class="col-1-4" id="homepage-box-versiv">
      <div class="inner-box">
        <h2 class="content_hp_expertise_box_title"><?php print t('Versiv'); ?></h2>
        <ul>
          <li class="content_hp_expertise_box_link"><a href="<?php print !empty($field_home13_exptpc[0]['url']) ? $field_home13_exptpc[0]['url'] : ''; ?>"><?php print !empty($field_home13_exptpc[0]['title']) ? $field_home13_exptpc[0]['title'].' &raquo;' : ''; ?></a></li>
          <li class="content_hp_expertise_box_link"><a href="<?php print !empty($field_home13_exptpc[1]['url']) ? $field_home13_exptpc[1]['url'] : ''; ?>"><?php print !empty($field_home13_exptpc[1]['title']) ? $field_home13_exptpc[1]['title'].' &raquo;' : ''; ?></a></li>
          <li class="content_hp_expertise_box_link"><a href="<?php print !empty($field_home13_exptpc[2]['url']) ? $field_home13_exptpc[2]['url'] : ''; ?>"><?php print !empty($field_home13_exptpc[2]['title']) ? $field_home13_exptpc[2]['title'].' &raquo;' : ''; ?></a></li>
          <li class="content_hp_expertise_box_link"><a href="/solutions/topics">More &raquo;</a></li>
        </ul>
      </div>
    </div>

    <div class="col-1-4" id="homepage-box-lwl">
      <div class="inner-box">
        <h2 class="content_hp_expertise_box_title"><?php print t('LinkWare Live'); ?></h2>
        <ul>
          <li class="content_hp_expertise_box_link"><a href="<?php print !empty($field_home13_exprle[0]['url']) ? $field_home13_exprle[0]['url'] : ''; ?>"><?php print !empty($field_home13_exprle[0]['title']) ? $field_home13_exprle[0]['title'].' &raquo;' : ''; ?></a></li>
          <li class="content_hp_expertise_box_link"><a href="<?php print !empty($field_home13_exprle[1]['url']) ? $field_home13_exprle[1]['url'] : ''; ?>"><?php print !empty($field_home13_exprle[1]['title']) ? $field_home13_exprle[1]['title'].' &raquo;' : ''; ?></a></li>
          <li class="content_hp_expertise_box_link"><a href="<?php print !empty($field_home13_exprle[2]['url']) ? $field_home13_exprle[2]['url'] : ''; ?>"><?php print !empty($field_home13_exprle[2]['title']) ? $field_home13_exprle[2]['title'].' &raquo;' : ''; ?></a></li>
          <li class="content_hp_expertise_box_link"><a href="/solutions/roles">More &raquo;</a></li>
        </ul>
      </div>
    </div>

    <div class="col-1-4" id="homepage-box-support">
      <div class="inner-box">
        <h2 class="content_hp_expertise_box_title"><?php print t('Support'); ?></h2>
        <ul>
          <li class="content_hp_expertise_box_link"><a href="<?php print !empty($field_home13_expind[0]['url']) ? $field_home13_expind[0]['url'] : ''; ?>"><?php print !empty($field_home13_expind[0]['title']) ? $field_home13_expind[0]['title'].' &raquo;' : ''; ?></a></li>
          <li class="content_hp_expertise_box_link"><a href="<?php print !empty($field_home13_expind[1]['url']) ? $field_home13_expind[1]['url'] : ''; ?>"><?php print !empty($field_home13_expind[1]['title']) ? $field_home13_expind[1]['title'].' &raquo;' : ''; ?></a></li>
          <li class="content_hp_expertise_box_link"><a href="<?php print !empty($field_home13_expind[2]['url']) ? $field_home13_expind[2]['url'] : ''; ?>"><?php print !empty($field_home13_expind[2]['title']) ? $field_home13_expind[2]['title'].' &raquo;' : ''; ?></a></li>
          <li class="content_hp_expertise_box_link"><a href="/solutions/industries">More &raquo;</a></li>
        </ul>
      </div>
    </div>

    <div class="col-1-4" id="homepage-ad">

      <?php
        // This array is shuffled in the homepage.module file to make sure the first item is randomly selected.
        print !empty($field_home13_ads[0]['value']) ? $field_home13_ads[0]['value'] : '';
      ?>

    </div>

  </div>

  <div id="homepage-industry-families" class="column-grid">

    <div class="col-1-3">
      <div class="inner-box content_hp_industry_box_left">
        <h3><?php print t('Cabling Certification'); ?></h3>
        <p><div style="font-weight: normal;"><?php print $field_category_description_1[0]['value']; ?></div></p>
        <ul>
          <?php foreach ($datacom_cabling_families as $datacom_cabling_family): ?>
            <li class="content_hp_industry_content_link">
            <?php if ($datacom_cabling_family->field_field_family_page_active[0]['raw']['value'] == "Yes"): ?>
              <a href="/<?php print drupal_lookup_path('alias',"node/" . $datacom_cabling_family->nid); ?>#family-product-list-<?php print $datacom_cabling_family->nid; ?>">
            <?php else: ?>
              <a href="/<?php print drupal_lookup_path('alias',"node/6"); ?>#family-product-list-<?php print $datacom_cabling_family->nid; ?>">
            <?php endif; ?>
            <?php print $datacom_cabling_family->node_title; ?> &raquo;</a></li>
          <?php endforeach; ?>
        </ul>
      </div>
    </div>

    <div class="col-1-3">
      <div class="inner-box content_hp_industry_box_left">
        <h3><?php print t('Installation and Test'); ?></h3>
        <p><div style="font-weight: normal;"><?php print $field_category_description_2[0]['value']; ?></div></p>
        <ul>
          <?php foreach ($it_networking_families as $it_networking_family): ?>
            <li class="content_hp_industry_content_link">
            <?php if ($it_networking_family->field_field_family_page_active[0]['raw']['value'] == "Yes"): ?>
              <a href="/<?php print drupal_lookup_path('alias',"node/" . $it_networking_family->nid); ?>#family-product-list-<?php print $it_networking_family->nid; ?>">
            <?php else: ?>
              <a href="/<?php print drupal_lookup_path('alias',"node/7"); ?>#family-product-list-<?php print $it_networking_family->nid; ?>">
            <?php endif; ?>
            <?php print $it_networking_family->node_title; ?> &raquo;</a></li>
          <?php endforeach; ?>
        </ul>
      </div>
    </div>

    <div class="col-1-3">
      <div class="inner-box">
        <h3><?php print t('Telecom Test'); ?></h3>
        <div style="font-weight: normal;"><p><?php print $field_category_description_3[0]['value']; ?></p></div>
        <ul>
          <?php foreach($telecom_families as $telecom_family): ?>
            <li class="content_hp_industry_content_link">
            <?php if ($telecom_family->field_field_family_page_active[0]['raw']['value'] == "Yes"): ?>
              <a href="/<?php print drupal_lookup_path('alias',"node/" . $telecom_family->nid); ?>#family-product-list-<?php print $telecom_family->nid; ?>">
            <?php else: ?>
              <a href="/<?php print drupal_lookup_path('alias',"node/8"); ?>#family-product-list-<?php print $telecom_family->nid; ?>">
            <?php endif; ?><?php print $telecom_family->node_title; ?> &raquo;</a></li>
          <?php endforeach; ?>
        </ul>
      </div>
    </div>

  </div>

  <?php if ($links = render($content['links'])): ?>
    <nav<?php print $links_attributes; ?>><?php print $links; ?></nav>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

  <?php print render($title_suffix); ?>
</article>
