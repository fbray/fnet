<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */

$background_color = $field_ms_story_bg_color[LANGUAGE_NONE][0]['value'] ? '#'.$field_ms_story_bg_color[LANGUAGE_NONE][0]['value'] : 'transparent';
$background_image = $field_ms_story_bg_image[LANGUAGE_NONE][0]['uri'] ? file_create_url($field_ms_story_bg_image[LANGUAGE_NONE][0]['uri']) : '';

$display_title = $field_display_title[LANGUAGE_NONE][0]['value'] ? $field_display_title[LANGUAGE_NONE][0]['value'] : '';
$display_title_anchor_string = str_replace(" ", "-", strtolower(trim($display_title)));

?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?> style="background:url(<?php print $background_image; ?>) center top no-repeat <?php print $background_color; ?>;">

  <?php if ($unpublished): ?>
    <header>
      <?php if ($unpublished): ?>
        <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
      <?php endif; ?>
    </header>
  <?php endif; ?>

  <div class="content">
    <?php if ($display_title) { ?>
      <a name="<?php print $display_title_anchor_string; ?>" id="<?php print $display_title_anchor_string; ?>" class="section-anchor"></a>
      <div class="section-header visible"><span><?php print $display_title; ?></span></div>
    <?php } ?>

    <?php print render($content); ?>
  </div>

</article>
