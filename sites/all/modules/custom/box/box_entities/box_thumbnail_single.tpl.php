<?php

if (isset($element) ) {
	$box_thumbnail = $element;
} else {
	return;
}

//todo:  move this back into controller:view

$view_mode = isset($box_thumbnail->view_mode) ? $box_thumbnail->view_mode : 'full' ;

$path = $box_thumbnail->thumbnail;

$url = image_style_url('gallery_paged', $path) ;

$thumb = array(
	'path' => $url,
	'title' => $box_thumbnail->original_file_name,
	'alt'	=>  $box_thumbnail->root_folder_name . ': ' . $box_thumbnail->original_file_name,
	'attributes'	=> array(),
	);

$image_sizes = array();
$image_sizes = isset($box_thumbnail->box_image_size) ? $box_thumbnail->box_image_size : array();

$title = isset($box_thumbnail->original_file_name) ? $box_thumbnail->original_file_name : '';



?>
<div class='box-thumbnail-entry downloads-trigger'>

	<div class='box-title'>
	<?php 
	print $title; 
	?>
	</div>
	<div class='box-thumbnail'>
	<?php
	print theme_image($thumb);
	?>
	</div>

  <?php 
  if ($image_sizes)  {
  		if ( count($image_sizes) > 1 ) {
  ?>
		<div class='box-image-sizes multiple-images downloads-trigger'>
		    <ul class='image-size-list'>
			<?php
			foreach ($image_sizes as $id => $box_image_size) {
				$output = box_image_size_render_entity($box_image_size);
				print $output;
			}
		
			?>
		    </ul>
		</div>

		<div class='download-options'>Download Options</div>

<?php
 } else {
?>
	<div class='box-image-sizes single-image'>
<?php
	$item = array_shift($image_sizes) ;
	print box_image_size_render_entity($item);
?>
	</div>
<?php 
		}
  } // end if image_sizes
?>
</div>

