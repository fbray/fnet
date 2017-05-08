<?php

// Can hopefully get rid of this
// Picks up uncaught theme calls to box_thumbnail
if (isset($elements) ) {

	$return = $elements;
	$return['#theme'] = 'box_thumbnail_single';

	return drupal_render($return);

}

?>

