<?php

$items_per_row = 3;


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
foreach (array_keys($element->content['thumbnails']) as $thumb_id) {
	print drupal_render( box_thumbnail_page_view($thumb_id, $view_mode) );
	$count++;
	if ($count % $items_per_row == 0) print '</li><li>';
}


?>
</li>
</ul>



</div>
</span>



