<?php

$items_per_row = 3;

$view_mode = isset($element->view_mode) ? $element->view_mode : 'full';

?>
<span id='box-gallery' class='box-carousel-rows'>
  <?php if ($element->box_title): ?>
    <h2><?php print $element->box_title; ?> Gallery</h2>
  <?php endif; ?>

		<div id='box-gallery-thumbs' class='rs-carousel'>
<ul>
<li>
<?php   


$count=0;
foreach (array_keys($element->content['#thumbnails']) as $thumb_id) {
		  $thumb_info = box_thumbnail_page_view($thumb_id, $view_mode);
	print drupal_render( $thumb_info );
	$count++;
	if ($count % $items_per_row == 0) print '</li><li>';
}


?>
</li>
</ul>



</div>
</span>



