<?php
// $Id$

/**
 * @file
 * Describe the purpose of the file here.
 *
 */
?>
<div id="asset-page">
  <div>
    <?php print drupal_render($form['title']); ?>
  </div>
  <div>
    <?php print drupal_render($form['description']); ?>
  </div>
  <div class="form-row">
    <div class="form-element"><?php print drupal_render($form['tags']); ?></div>
  </div>
  <div class="form-row">
    <div
      class="form-element"><?php print drupal_render($form['document_status']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['changed']); ?></div>
  </div>
  <div class="form-row">
    <div
      class="form-element"><?php print drupal_render($form['document_id']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['revision']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['language']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['asset_type']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['export_controlled']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['parent']); ?></div>
  </div>
  <div class="form-row">
    <div
      class="form-element"><?php print drupal_render($form['edoc_url']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['storage_filename']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['file_size']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['cdn_status']); ?></div>
  </div>
  <div class="form-row">
    <div
      class="form-element"><?php print drupal_render($form['findit_link']); ?></div>
  </div>
  <div class="form-row">
    <div
      class="form-element"><?php print drupal_render($form['vftf_link']); ?></div>
  </div>
  <div class="form-row">
    <div
      class="form-element"><?php print drupal_render($form['children']); ?></div>
  </div>
  <div class="form-row">
    <div
      class="form-element"><?php print drupal_render($form['add_child']); ?></div>
  </div>
  <div class="form-row">
    <div
      class="form-element"><?php print drupal_render($form['entitlement_level']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['form_processing_url']); ?></div>
  </div>
  <div class="form-row">
    <div
      class="form-element"><?php print drupal_render($form['access_groups']); ?></div>
  </div>
  <div class="form-row">
    <div
      class="form-element"><?php print drupal_render($form['industry']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['new_industry']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['business_entity']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['owner']); ?></div>
  </div>
  <div class="form-row">
    <div
      class="form-element"><?php print drupal_render($form['related_products']); ?></div>
  </div>
  <div class="form-row">
    <div
      class="form-element"><?php print drupal_render($form['bulk_fulfillment']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['print_on_demand']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['cost_center']); ?></div>
  </div>
  <div class="form-row">
    <div
      class="form-element"><?php print drupal_render($form['asset_file_pod']); ?></div>
  </div>
  <div class="form-row">
    <div
      class="form-element"><?php print drupal_render($form['findit_pod_link']); ?></div>
  </div>
  <div class="form-row">
    <div
      class="form-element"><?php print drupal_render($form['unit_of_measure']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['uom_quantity']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['order_quantity_max']); ?></div>
  </div>
  <div class="form-row">
    <div
      class="form-element"><?php print drupal_render($form['l1_category']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['l2_category']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['l3_category']); ?></div>
    <div
      class="form-element"><?php print drupal_render($form['l4_category']); ?></div>
  </div>
  <div class="form-row">
    <div class="form-element"><?php print drupal_render($form['link']); ?></div>
  </div>

</div>
<?php print drupal_render_children($form); ?>
