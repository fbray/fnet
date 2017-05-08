<?php
// $Id$

/**
 * @file
 * Template file for query form digital_asset_asset_query_form
 *
 */
?>
<div id="asset-query-form">
  <div class="form-row">
    <div
      class="form-element"><?php print drupal_render($form['document_id']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['title']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['asset_type']); ?></div>
  </div>
  <div class="form-row">
    <div class="form-element"><?php print drupal_render($form['tags']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['language']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['status']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['owner']); ?></div>
  </div>
  <div class="form-row">
    <?php print drupal_render_children($form); ?>
  </div>
</div>