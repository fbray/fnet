<?php

$view_mode = isset($element->content['#view_mode']) ? $element->content['#view_mode'] : 'full';

?>
<span id='box-gallery-thumbnails'  >
  <?php if ($element->box_title): ?>
    <h2><?php print $element->box_title; ?> Gallery</h2>
  <?php endif; ?>
		<div class="thumbnail-list thumb_style_<?php print $view_mode; ?>" >
<?php   
foreach (array_keys($element->content['#thumbnails']) as $thumb_id) {
		  $thumb_info = box_thumbnail_page_view($thumb_id, $view_mode);
	print drupal_render( $thumb_info );
}
?>
</div>
</span>



