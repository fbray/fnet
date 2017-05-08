<?php

if (isset($element) ) {
	$box_gallery = $element;
} else {
	return;
}

$box_thumbnails = isset($box_gallery->box_thumbnails) ? $box_gallery->box_thumbnails : array();

?>
<div id='box-gallery' class='box-gallery-paged'>
  <?php if ($element->box_title): ?>
    <h2><?php 
    print $element->box_title ;
    ?> Gallery</h2>
  <?php endif; ?>


		<div id='box-gallery-thumbs'>
<?php   
  if ($box_thumbnails) { 
  ?>
		<div class='box-thumbnails '>
			<?php
			foreach ($box_thumbnails as $tid => $box_thumbnail) {

				$output = box_thumbnail_render_entity($box_thumbnail);
				print $output;
			}
		
			?>
		</div>
  <?php 

  print theme('pager', array('tags' => array() ) );

  }
?>

</div>
</div>

