<?php
// $Id: print--node--edoc.tpl.php 971 2015-10-28 17:32:42Z ychung $
?>

<!DOCTYPE html >
<html xmlns="http://www.w3.org/1999/xhtml"
      xml:lang="<?php print $language->language; ?>" version="XHTML+RDFa 1.0"
      dir="<?php print $language->dir; ?>">
<head>
  <?php print $head; ?>
  <base href='<?php print $url ?>'/>
  <title><?php print $print_title; ?></title>
  <?php print $css; ?>
</head>
<body>
<!-- print--node--edoc.tpl.php -->
<?php print $edoc_brand_header; ?>
<div id="print_view">
  <?php if ($edoc_type): ?>
    <div class="edocs_type_display">| <?php print t($edoc_type); ?> |</div>
  <?php endif; ?>
  <div class="edocs_page_header">
    <div style="clear:both;">&nbsp;</div>
  </div>
  <?php if ($print_logo): ?>
    <div class="print-logo"><?php print $print_logo; ?></div>
  <?php endif; ?>
  <div
    class="ds_title"><?php print html_entity_decode($print['title']); ?></div>
  <div class="ds_content"><?php print $content; ?></div>
  <div class="ds_footer">
    <?php print $ds_footer; ?>
  </div>
  <div class="print-footer"><?php print theme('print_footer'); ?></div>
  <hr class="print-hr"/>
</div>
<!-- end of print--node--edoc.tpl.php -->
</body>
</html>
