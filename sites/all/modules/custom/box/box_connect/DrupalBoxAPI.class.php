<?php

if (!class_exists('Box_API')) {
  $path = drupal_get_path('module', 'box_connect'); 
  include_once($path . '/BoxPHPAPI/library/BoxAPI.class.php');
}

class Drupal_Box_API extends Box_API {

		public function read_token($type = 'file', $json = false) {
          $content = variable_get('box_token', FALSE); // Content is stored as a BLOB, but it's just a JSON string.
          if (!$content) {
            // No token currently saved.
            return FALSE;
          }
          // Check to see if the Refresh Token is expired.
          $array = json_decode($content, TRUE);
          $expires = $array['timestamp'];
          $now = time();
          if (($now - $expires) > 5184000 ) {  // Sixty days (in seconds)
            // The refresh token has expired.
            return FALSE;
          }
          // If the desired format is JSON
          if($json) {
            // Return as a JSON string.
            return $content;
          }
          else {
            // Return as an array.
            return json_decode($content, true);
          }
		}


		public function write_token($token, $type = 'file') {
			$array = json_decode($token, true);
			if(isset($array['error'])){
				$this->error = $array['error_description'];
				return false;
			} else {
				$array['timestamp'] = time();

				variable_set('box_token', json_encode($array) );
				return true;
			}
		}


}