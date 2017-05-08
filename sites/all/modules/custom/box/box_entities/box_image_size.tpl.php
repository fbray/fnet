<?php
$link_display_text = isset($element->link_display_text) ? $element->link_display_text :  $element->size_name;
$size = isset($element->size_name) ? $element->size_name : 'default' ;
$classes = 'option-' . strtolower($size) ;
?>
<div class='image-size-name <?php print $classes ; ?>'>
<?php 
// keep original name for browser save file extension
$url = 'extranet/download/' . $element->box_file_id . '/' . $element->box_name;
print l($link_display_text, $url);
?>
</div>