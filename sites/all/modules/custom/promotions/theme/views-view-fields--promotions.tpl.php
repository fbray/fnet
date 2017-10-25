<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 10/25/17
 * Time: 11:19 AM
 */


/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */

?>
<div class="promotion-instance">
  <div class="promotion-thumbnail">
      <a href="<?php print $fields['field_external_url']->content; ?>" target="_blank"><img width="79" height="81" src="<?php print $fields['uri']->content; ?>" /></a>
  </div>
  <div class="promotion-details">
    <h4 class="promotion-title"><?php print $fields['title']->content; ?></h4>

    <div class="promotion-description">
      <?php print $fields['field_intro']->content; ?>
    </div>
  </div>
  <div class="promotion-button">
    <div class="promotion-date">
      <?php print $fields['field_promotion_date']->content; ?>
    </div>
    <div class="btn_143w">
      <a href="<?php print $fields['field_external_url']->content; ?>" target="_blank"><?php print t('Get Details'); ?></a>
    </div>
  </div>
  <div style="clear:both;"></div>
</div>
