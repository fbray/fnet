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
    <?php print drupal_render($form['body']); ?>
    <?php print drupal_render($form['field_dam_document_status']); ?>
    <?php print drupal_render($form['field_dam_language']); ?>
  </div>
  <div class="digital-asset-form-section">
    <?php print drupal_render($form['author']); ?>
    <?php print drupal_render($form['field_asset_type']); ?>
    <?php print drupal_render($form['field_dam_export_controlled']); ?>
    <?php print drupal_render($form['field_dam_document_id']); ?>
    <?php print drupal_render($form['field_dam_revision_letter']); ?>
  </div>
  <div class="digital-asset-form-section">
    <?php print drupal_render($form['field_dam_asset_file']); ?>
    <?php print drupal_render($form['field_dam_keep_original_filename']); ?>
    <?php print drupal_render($form['storage_file_folder']); ?>
    <?php print drupal_render($form['storage_filename']); ?>
    <?php print drupal_render($form['field_dam_edoc_url']); ?>
    <?php print drupal_render($form['field_dam_bulk_fulfillment']); ?>
  </div>
  <div class="digital-asset-form-section">
    <?php print drupal_render($form['field_dam_entitlement_level']); ?>
    <?php print drupal_render($form['field_dam_form_url']); ?>
    <?php print drupal_render($form['field_dam_industry']); ?>
  </div>
  <div class="digital-asset-form-section clearfix">
    <?php print drupal_render($form['field_related_product']); ?>
  </div>
  <div class="digital-asset-form-section clearfix">
    <?php print drupal_render($form['field_dam_availability_dates']); ?>
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
    <?php print drupal_render($form['field_dam_original_file_name']); ?>
    <?php print drupal_render($form['field_asset_tags']); ?>
  </div>
  <div>
    <?php print drupal_render_children($form); ?>
  </div>
</div>
<script>
  var no_options = '<option value=""></option>';
  var level1, level2, level3;
  $('#edit-field-dam-l1-category-value').change(function () {
    level1 = $(this).val();
    $.get('/digital_asset/ccs_categories_ajax', {'level1': level1}, function (options) {
      $('#edit-field-dam-l2-category-value').html(options);
      $('#edit-field-dam-l3-category-value').html(no_options);
      $('#edit-field-dam-l4-category-value').html(no_options);
    });
  });
  $('#edit-field-dam-l2-category-value').change(function () {
    level2 = $(this).val();
    $.get('/digital_asset/ccs_categories_ajax', {
      'level1': level1,
      'level2': level2
    }, function (options) {
      $('#edit-field-dam-l3-category-value').html(options);
      $('#edit-field-dam-l4-category-value').html(no_options);
    });
  });
  $('#edit-field-dam-l3-category-value').change(function () {
    level3 = $(this).val();
    $.get('/digital_asset/ccs_categories_ajax', {
      'level1': level1,
      'level2': level2,
      'level3': level3
    }, function (options) {
      $('#edit-field-dam-l4-category-value').html(options);
    });
  });
  $('#edit-field-dam-l1-category-value').change();
</script>
