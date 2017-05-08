<?php
// $Id$

/**
 * @file
 * node form template
 *
 */
?>
<div id="digital_asset_form" class="node-form">
  <div class="digital-asset-form-section">
    <?php print drupal_render($form['title']); ?>
    <?php print drupal_render($form['body_field']); ?>
    <?php print drupal_render($form['field_dam_document_status']); ?>
    <?php print drupal_render($form['field_dam_language']); ?>
  </div>
  <div class="digital-asset-form-section">
    <div style="didisplay: none">
      <?php print drupal_render($form['field_dam_asset_type']); ?>
    </div>
    <?php print drupal_render($form['field_dam_owner']); ?>
    <?php print drupal_render($form['field_dam_export_controlled']); ?>
    <?php print drupal_render($form['field_dam_document_id']); ?>
    <?php print drupal_render($form['field_dam_revision_letter']); ?>
  </div>
  <div class="digital-asset-form-section">
    <?php print drupal_render($form['field_dam_keep_original_filename']); ?>
    <?php print drupal_render($form['field_dam_asset_file']); ?>
    <?php print drupal_render($form['field_dam_asset_file_pod']); ?>
    <?php print drupal_render($form['field_dam_edoc_url']); ?>
    <?php print drupal_render($form['field_dam_bulk_fulfillment']); ?>
  </div>
  <div
    class="digital-asset-form-section"<?php //if (!variable_get('digital_asset_show_hidden_fields')) print ' style="display: none;"' ?>>
    <?php print drupal_render($form['field_dam_entitlement_level']); ?>
    <?php print drupal_render($form['field_dam_asset_groups']); ?>
    <?php print drupal_render($form['field_dam_industry']); ?>
    <?php print drupal_render($form['field_dam_new_industry']); ?>
    <?php print drupal_render($form['field_dam_business_entity']); ?>
  </div>
  <div
    class="digital-asset-form-section clearfix"<?php if (!variable_get('digital_asset_show_hidden_fields')) print ' style="display: none;"' ?>
  ">
    <?php print drupal_render($form['field_dam_related_product']); ?>
  </div>
  <div class="digital-asset-form-section">
    <?php print drupal_render($form['field_dam_availability_date']); ?>
  </div>
<div <?php if (!variable_get('digital_asset_show_hidden_fields')) print 'style="display: none;"' ?>>
  <?php print drupal_render($form['group_dam_ccs_printing']['field_dam_storage_filename_pod']); ?>
  <?php print drupal_render($form['group_dam_ccs_printing']['field_dam_storage_file_folder_po']); ?>
  <?php print drupal_render($form['group_dam_ccs_printing']['field_dam_cdn_status_pod']); ?>
</div>
  <div class="digital-asset-form-section">
    <?php print drupal_render($form['group_dam_ccs_printing']); ?>
  </div>

<div <?php if (!variable_get('digital_asset_show_hidden_fields')) print 'style="display: none;"' ?>>
  <?php print drupal_render($form['field_dam_ams_id']); ?>
  <?php print drupal_render($form['field_dam_cdn_status']); ?>
  <?php print drupal_render($form['field_dam_storage_file_folder']); ?>
  <?php print drupal_render($form['field_dam_storage_filename']); ?>
  <?php print drupal_render($form['field_dam_file_size']); ?>
  <?php print drupal_render($form['field_dam_parent']); ?>
  <?php print drupal_render($form['field_dam_original_filename']); ?>
  <?php print drupal_render($form['taxonomy_vocabulary_19']); ?>
  <?php print drupal_render($form['body']); ?>
  <?php print drupal_render($form['field_dam_form_url']); ?>
  <?php print drupal_render($form['field_dam_access_groups']); ?>
</div>
<div>
    <?php print drupal_render_children($form); ?>
  </div>
</div>
