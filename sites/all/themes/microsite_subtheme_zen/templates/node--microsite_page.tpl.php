<?php
/**
 * @file
 * Returns the HTML for a node.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728164
 */

$background_color = $field_ms_page_bg_color[LANGUAGE_NONE][0]['value'] ? '#'.$field_ms_page_bg_color[LANGUAGE_NONE][0]['value'] : 'transparent';
$background_image = $field_ms_page_bg_image[LANGUAGE_NONE][0]['uri'] ? file_create_url($field_ms_page_bg_image[LANGUAGE_NONE][0]['uri']) : '';
$field_intro_content = $field_ms_page_intro_content[LANGUAGE_NONE][0]['value'] ? $field_ms_page_intro_content[LANGUAGE_NONE][0]['value'] : '';

?>
<article class="node-<?php print $node->nid; ?> <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php if ($unpublished): ?>
    <header>
      <?php if ($unpublished): ?>
        <mark class="unpublished"><?php print t('Unpublished'); ?></mark>
      <?php endif; ?>
    </header>
  <?php endif; ?>

  <?php if ($field_intro_content) { ?>
    <div id="field-intro-content" style="background:url(<?php print $background_image; ?>) center top no-repeat <?php print $background_color; ?>;">
      <div class="content clearfix">
        <?php print $field_intro_content; ?>
      </div>
    </div>
  <?php } ?>

  <div class="content">
    <?php print render($content); ?>
  </div>

</article>
