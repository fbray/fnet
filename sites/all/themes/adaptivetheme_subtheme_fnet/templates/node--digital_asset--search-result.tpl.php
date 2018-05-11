<?php
/*
 * $content contains the relevant fields
 * use dpm($content) to see what's in there!
 */
?>
<?php print render($title_prefix); ?>
<h3 class="title"<?php print $title_attributes; ?>>
  <?php if(isset($content['field_dam_document_id'][0])): ?>
    <a href="/vftf/<?php print render($content['field_dam_document_id'][0]); ?>"><?php print $title; ?> - <?php print render($title); ?></a>
  <?php else: ?>
    <?php print $title; ?>
  <?php endif; ?>
</h3>
<?php print render($title_suffix); ?>
<?php print render($content); ?>
<section class="field field-type-list-text field-label-inline clearfix view-mode-search_result">
  <h2 class="field-label"><?php print t('Last Updated: '); ?>  </h2>
  <div class="field-items">
    <div class="field-item"> <?php print format_date($node->changed); ?></div>
  </div>
</section>
