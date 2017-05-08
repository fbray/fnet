<?php
if ( isset($element['videos']) ) {

	foreach($element['videos'] as $video) {
			$video_id = isset($video['video_id']) ? $video['video_id'] : '';
			$display_url = isset($video['display_url']) ? $video['display_url'] : '';
			$title = isset($video['title']) ? $video['title'] : 'Video';

			if ( $video_id ) {
			?>

<iframe width="600" height="400" src="https://www.youtube.com/embed/<?php print $video_id; ?>">
</iframe> 

			<?php
			} else if ($display_url) {

			print l($title, $display_url);

			} 

	} // end foreach

} // end if

?>
