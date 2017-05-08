<?php

$view_mode = $element->content['#view_mode'] ;

?>
<span id='box-gallery'>
  <?php if ($element->box_title): ?>
    <h2><?php print $element->box_title; ?> Gallery</h2>
  <?php endif; ?>

<?php
if ( $view_mode == 'carousel') { 
?>
		<div id='box-gallery-thumbs' class='rs-carousel'>

<?php
	 } else { 
?>
		<div id='box-gallery-thumbs'>
<?php }  

if ( $view_mode == 'carousel') print '<ul>';

foreach (array_keys($element->content['thumbnails']) as $thumb_id) {
	print drupal_render( box_thumbnail_page_view($thumb_id, $view_mode) );
}

if ( $view_mode == 'carousel') {
?>
</ul>


<?php
}
?>


</div>
</span>



