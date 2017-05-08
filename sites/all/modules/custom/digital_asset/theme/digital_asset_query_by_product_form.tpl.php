<?php
// $Id$

/**
 * @file
 * Describe the purpose of the file here.
 *
 */
?>
<div id="asset-query-form">
  <div class="form-row">
    <div
      class="form-element"><?php print drupal_render($form['product']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['language']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['asset_type']); ?></div>
  </div>
  <div class="form-row">
    <?php print drupal_render_children($form); ?>
  </div>
</div>