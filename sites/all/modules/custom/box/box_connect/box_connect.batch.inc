<?php
/**
 * This function gets the file and folder information from Box and places it in
 * the box_item_temporary table.
 *
 * FIRST TASK
 *
 * @param $box_ids
 * @param $context
 */
function box_batch_iterate($box_ids, &$context) {
  // Initiate the batch
  if ( empty($context['sandbox']) ) {
    $total = count($box_ids);
    $context['finished'] = 1;
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current'] = 0;
    $context['sandbox']['ids'] = $box_ids;
    $context['sandbox']['max'] = $total;
  }

  if ( ( count($box_ids) > 0) || ($context['sandbox']['ids'] != '') ){
    if ( is_array($context['sandbox']['ids']) ) {
      $current = array_shift($context['sandbox']['ids']);  // Get the first item off the array.
    }
    else {
      // if it gets a single item instead of array of 1 item. May never happen.
      $current = $context['sandbox']['ids'];
      // delete else if no entries
    }
    $context['sandbox']['current'] = $current ;
    _process_folder( $current->box_id, FALSE, $current->box_top_folder_name , $current->box_top_folder_id );
    $context['message'] = t('First sync task: Get the folder structure from Box. Processing @folder folder', array('@folder' => $current->box_top_folder_name));

    $context['sandbox']['progress']++;
    if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
      $context['finished'] = ($context['sandbox']['progress'] / $context['sandbox']['max']);
    }
    else {
      // Log the task as complete.
      watchdog('Box Connect', 'Updated Box Item Temporary Table (First task)', array(), WATCHDOG_NOTICE);
    }
  }
}

/**
 * This function compares the box_item_temporary table with the box_item table.
 * If they are not in sync, it begins the syncing process.
 *
 * SECOND TASK
 *
 * @param $context
 */
function box_batch_update(&$context) {
  $log_message = '';
  // Initialize the batch.
  if ( empty($context['sandbox']) ) {
    $context['finished'] = 1;
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current'] = 0;
  }
  // Check to see if the items are current.
  if (_box_connect_compare_tables() == TRUE) {  // TRUE means the box_item table is not up to date.
    $context['results']['synced'] = FALSE;
    // Copy the current box_item_temporary to the box_item table.
    $copy = _box_connect_copy_tables();
    if ($copy == TRUE) {
      // Testing
      drupal_set_message('Copied to the box_item table.');
      $context['message'] = t('Second sync task: Copying data in database.');
    }
    else {
      // End the update and set the error message.
      drupal_set_message('Unable to copy from temp table.');
      $context['finished'] = 1;
    }
  }
  else {
    // $context['results']['synced'] = TRUE;
    $context['results']['synced'] = FALSE; // Forcing the sync for testing.
    drupal_set_message('The site is in sync with Box.');
  }
  $context['finished'] = 1;
  // Log to the database.
  if ($context['results']['synced'] == TRUE) {
    $log_message = t('Compared Box data (Second task). The system is in sync.');
  }
  else {
    $log_message = t('Compared Box data (Second task). The system is not in sync. Beginning the update process.');
  }
  watchdog('Box Connect', $log_message, array(), WATCHDOG_NOTICE);

}

/**
 * This function gets any new items from box_item to process into box_ent_thumb.
 *
 * THIRD TASK
 *
 * @param $context
 * @throws \Exception
 * @throws \InvalidMergeQueryException
 */
function box_batch_update_box_thumbnails(&$context) {
  // If the site was already synced in the previous operations, don't bother with this step.
  if ($context['results']['synced'] != TRUE)  {
    // Initialize the batch.
    if (empty($context['sandbox'])) {
      $context['finished'] = 1;
      $context['sandbox']['progress'] = 0;
      $context['sandbox']['current'] = 0;
      $context['sandbox']['max'] = 0;  // Just in case there are no records in the table;

      // This gets only the new items from box_item to process into box_ent_thumb.
      // TODO: We want to get information about changes, both in new content and altered or deleted content.
      /*
      $sql = "SELECT bi.box_id,
        bi.box_parent_id,
        bi.box_name, 
        bi.box_description, 
        bi.box_top_folder_name, 
        bi.box_top_folder_id, 
        bi.size_name, 
        bi.original_file_name, 
        bi.last_checked,
        beis.box_file_id
      FROM {box_item} bi
      LEFT JOIN {box_ent_image_size} beis ON beis.box_file_id = bi.box_id
      WHERE bi.box_type = 'file'
      AND beis.box_name IS NULL";
      */
      $sql = "SELECT bi.box_id,
        bi.box_parent_id,
        bi.box_name, 
        bi.box_description, 
        bi.box_top_folder_name, 
        bi.box_top_folder_id, 
        bi.size_name,
        bi.file_size,
        bi.original_file_name, 
        bi.last_checked,
        bi.box_id
      FROM {box_item} bi
      WHERE bi.box_type = 'file'";
      $results = db_query($sql, array())->fetchAll();

      $context['sandbox']['max'] = count($results);
      $context['message'] = t('Third sync task: Found @count new thumbnails.', array('@count' => $context['sandbox']['max']));

      $context['sandbox']['thumbnails'] = $results; // Fill the thumbnail sandbox with the array of thumbnails to process.
      watchdog('Box Connect', 'Third sync task: Found @count new thumbnails.', array('@count' => $context['sandbox']['max']), WATCHDOG_NOTICE);
    }
    else {
      $context['message'] = t('Third sync task: Processing thumbnail images.');

    }


    // Do repetitive stuff here.
    if ( ($context['sandbox']['max'] > 0) && ($context['sandbox']['thumbnails'] != '') ) {
      // Grab the first record in the thumbnail array.
      if ( is_array($context['sandbox']['thumbnails']) ) {
        $current = array_shift($context['sandbox']['thumbnails']);  // Get the first item off the array.
      }
      else {
        // if it gets a single item instead of array of 1 item. May never happen.
        $current = $context['sandbox']['thumbnails'];
        // delete else if no entries
      }
      // Using that record, add it into the box_ent_thumb table in the database.

      // Check to see if it exists
      /*
      $query = db_select('box_ent_thumb', 'bet');
          $query->fields('bet', array('root_folder_id', 'tid') );
          $query->condition('bet.original_file_name', $result->original_file_name, '=');
          $query->condition('bet.gallery_id', $result->box_top_folder_id, '=');
          $query->range(0,1);
      */
      $tid = 0;

      if ((!empty($current->box_top_folder_id)) && (!empty($current->original_file_name))) {
        $query_existing = 'SELECT root_folder_id, tid FROM box_ent_thumb WHERE original_file_name = :original AND gallery_id = :folder_id';
        $existing_thumb = db_query($query_existing, array(
          ':original' => $current->original_file_name,
          ':folder_id' => $current->box_top_folder_id
        ))->fetchObject();
        if (!$existing_thumb) {
          // The record is new. Create a new entry.
          $new_thumb_values = array(
            'gallery_id' => $current->box_top_folder_id,
            'original_file_name' => $current->original_file_name,
            'thumbnail' => '',
            'root_folder_id' => $current->box_top_folder_id,
            'root_folder_name' => $current->box_top_folder_name,
            'status' => 1,
            'checked' => time(),
          );
          $new_thumb = entity_create('box_thumbnail', $new_thumb_values);
          $new_thumb->save();
          $tid = $new_thumb->tid;
        }
        else {
          $tid = $existing_thumb->tid;
          // dpm($tid);
        }

        // Once we have an entry for the expected thumbnail, we create the entry for the actual asset and reference the thumbnail.
        db_merge('box_ent_image_size')
          ->key(array(
            'box_file_id' => $current->box_id
          ))
          ->fields(array(
            'box_parent_id' => $current->box_parent_id,
            'box_name' => $current->box_name,
            'box_description' => $current->box_description,
            'thumb_id' => $tid,
            'size_name' => $current->size_name,
            'box_file_size' => $current->file_size,
            'root_folder_id' => $current->box_top_folder_id,
            'root_folder_name' => $current->box_top_folder_name,
            'status' => 1,
            'checked' => time(),
          ))
          ->execute();
      }






      /*
        db_merge('box_ent_thumb')
          ->key(array(
            'original_file_name' => $current->original_file_name,
            'gallery_id' => $current->box_top_folder_id
          ))
          ->fields(array(
            // 'original_file_name' => $current->original_file_name,
            // 'thumbnail' => '',  // Go for the default here. Blank entries will be filled during step five.
            'root_folder_id' => $current->box_top_folder_id,
            'root_folder_name' => $current->box_top_folder_name,
            // 'content_nid' => 0, // Where do we get this?
            'status' => 1,
            'checked' => time(),
            'type' => 'box_thumbnail',
          ))
          ->execute();
        // Return the tid. This apparently only works on inserts, not updates.
        // $tid = Database::getConnection()->lastInsertId();
        watchdog('Box Connect', 'TID: ' . $tid . ' -  File Name ' . $current->original_file_name, array(), WATCHDOG_NOTICE);
*/

      $context['sandbox']['current'] = $current ;

      $context['message'] = t('Third sync task: Updating @thumbnail thumbnail', array('@thumbnail' => $current->original_file_name));

      $context['sandbox']['progress']++;
      if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
        $context['finished'] = ($context['sandbox']['progress'] / $context['sandbox']['max']);
      }
      else {
        // Log the task as complete.
        watchdog('Box Connect', 'Updated Box Thumbnail Data (Third task)', array(), WATCHDOG_NOTICE);
      }
    }
  }
  else {
    watchdog('Box Connect', 'Skipped updating Box Thumbnail Data (Third task) because site is in sync with Box.', array(), WATCHDOG_NOTICE);
  }
}

/**
 * This function updated the box_ent_gallery table with any new file
 * information.
 *
 * FOURTH TASK
 *
 * @param $context
 * @return int
 */
function box_batch_update_box_galleries(&$context) {
  // If the site was already synced in the previous operations, don't bother with this step.
  if ($context['results']['synced'] != TRUE) {
    if (empty($context['sandbox'])) {
      $context['finished'] = 1;
      $context['sandbox']['progress'] = 0;
      $context['sandbox']['current'] = 0;
      $context['sandbox']['max'] = 0;  // Just in case there are no records in the table;
      $total_results = array();
      // TODO: Make this workable with multiple parent folders.
      $top_ids = _box_connect_get_parent_folders();
      foreach($top_ids as $top_id) {
        // Get a list of the existing galleries and their box_item info.
        $query = "SELECT 
          bi.box_id, 
          bi.box_name, 
          bi.box_parent_id, 
          bi.box_description, 
          bi.box_top_folder_id, 
          beg.gid
        FROM box_item bi
        LEFT JOIN box_ent_gallery beg ON beg.gid = bi.box_id
        WHERE bi.box_parent_id = :top_id";
        $results = db_query($query, array(':top_id' => $top_id))->fetchAllAssoc('box_id');
        $total_results = $total_results + $results;
      }


      // Get a list of the products. NID and Title, please.
      $products = db_query("SELECT nid, title FROM node WHERE type = 'product' AND status = 1 ORDER BY title")->fetchAllKeyed(0,1);

      $context['sandbox']['max'] = count($total_results);
      $context['message'] = t('Fourth sync task: Updating @count new image galleries.', array('@count' => $context['sandbox']['max']));

      $context['sandbox']['galleries'] = $total_results; // Fill the gallery sandbox with the array of galleries to process.
      $context['sandbox']['products'] = $products;
    }
    else {
      $context['message'] = t('Fourth sync task: Processing image galleries.');
    }

    // Do repetitive stuff here.
    if ( ($context['sandbox']['max'] > 0) || ($context['sandbox']['galleries'] != '') ) {
      // Grab the first record in the thumbnail array.
      if (is_array($context['sandbox']['galleries'])) {
        $current = array_shift($context['sandbox']['galleries']);  // Get the first item off the array.
      }
      else {
        // if it gets a single item instead of array of 1 item. May never happen.
        $current = $context['sandbox']['galleries'];
        // delete else if no entries
      }

      if (! $current->gid) {
        $content_nid = 0;
        if ( $match = array_search($current->box_name, $context['sandbox']['products']) ) {
          $content_nid = $match;
        }
        db_merge('box_ent_gallery')
          ->key(array(
            'gid' => $current->box_id
          ))
          ->fields(array(
            'box_title' => $current->box_name,
            'content_nid' => $content_nid,
            'box_description' => $current->box_description,
            'box_folder_id' => $current->box_id,
            'checked' => time(),
          ))
          ->execute();
      }


      $context['sandbox']['current'] = $current;
      $context['message'] = t('Fourth sync task: Update image galleries. Processing @gallery gallery', array('@gallery' => $current->box_name));

      $context['sandbox']['progress']++;
      if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
        $context['finished'] = ($context['sandbox']['progress'] / $context['sandbox']['max']);
      }
      else {
        // Log the task as complete.
        watchdog('Box Connect', 'Updated image galleries (Fourth task)', array(), WATCHDOG_NOTICE);
      }
    }
  }
  else {
    watchdog('Box Connect', 'Skipped updating the image galleries (Fourth task) because site is in sync with Box.', array(), WATCHDOG_NOTICE);
  }
}

/**
 * This function goes out and retrieves the actual image file and saves it into the proper directory.
 *
 * FIFTH TASK
 *
 * @param $context
 */
function box_batch_acquire_image_files(&$context) {
  // If the site was already synced in the previous operations, don't bother with this step.
  if ($context['results']['synced'] != TRUE) {
    // Initialize the batch.
    $path = variable_get('box_connect_thumbnail_directory', 'public://extranet/box');
    $box = get_box();
    if (empty($context['sandbox'])) {
      $context['finished'] = 1;
      $context['sandbox']['progress'] = 0;
      $context['sandbox']['current'] = 0;
      $context['sandbox']['max'] = 0;  // Just in case there are no records in the table;}

      // Ge the list of thumbnails that need to be added.
      $query = "SELECT bet.tid, bet.original_file_name, beis.box_file_id, beis.size_name
FROM box_ent_thumb bet
LEFT JOIN box_ent_image_size beis ON beis.thumb_id = bet.tid
WHERE bet.thumbnail = ''";
      $results = db_query($query)->fetchAllAssoc('tid');
      $context['sandbox']['max'] = count($results);
      $context['sandbox']['images'] = $results; // Fill the gallery sandbox with the array of galleries to process.
      $context['message'] = t('Fifth sync task: Downloading @count images from Box.', array('@count' => $context['sandbox']['max']));
      // Connect to Box to get the images.

    }
    else {
      $context['message'] = t('Fifth sync task: Downloading images.');
    }

    // Do repetitive stuff here.
    if (($context['sandbox']['max'] > 0) && ($context['sandbox']['images'] != '')) {
      // Grab the first record in the thumbnail array.
      if (is_array($context['sandbox']['images'])) {
        $current = array_shift($context['sandbox']['images']);  // Get the first item off the array.
      }
      else {
        // if it gets a single item instead of array of 1 item. May never happen.
        $current = $context['sandbox']['images'];
        // delete else if no entries
      }
      $context['sandbox']['current'] = $current;
      $thumbnail = _retrieve_thumb($current->box_file_id, $box, $path);
      if ($thumbnail) {
        $box_ent_thumb = entity_load_unchanged('box_thumbnail', $current->tid);
        $box_ent_thumb->thumbnail = $thumbnail;
        if (isset($box_ent_thumb->tid)) {
          $box_ent_thumb->save();
        }
      }

      $context['message'] = t('Fifth sync task: Importing @image from Box.', array('@image' => $current->original_file_name));
      $context['sandbox']['progress']++;
      if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
        $context['finished'] = ($context['sandbox']['progress'] / $context['sandbox']['max']);
      }
    }
    else {
      watchdog('Box Connect', 'No images needed downloading (Fifth task).', array(), WATCHDOG_NOTICE);
    }
  }
  else {
    watchdog('Box Connect', 'Skipped acquiring image files (Fifth task) because site is in sync with Box.', array(), WATCHDOG_NOTICE);

  }
}

/**
 * This function is to clean up the aftermath of the previous tasks. It finds orphan
 * files that are no longer listed in Box and deletes them from the system.
 *
 * SIXTH TASK
 *
 * @param $context
 */
function box_batch_thumbnails_cleanup(&$context) {
  // If the site was already synced in the previous operations, don't bother with this step.
  if ($context['results']['synced'] != TRUE) {
    // Initialize the batch.
    if (empty($context['sandbox'])) {
      $context['finished'] = 1;
      $context['sandbox']['progress'] = 0;
      $context['sandbox']['current'] = 0;
      $context['sandbox']['max'] = 0;  // Just in case there are no records in the table;}

      // Find orphan records in the box_ent_gallery table.
      $beg_query = "SELECT beg.gid
        FROM box_ent_gallery beg
        LEFT JOIN box_item bi ON bi.box_id = beg.gid
        WHERE bi.box_id IS NULL";
      $beg_results = db_query($beg_query, array())->fetchCol();
      if ($beg_results) {
        db_delete('box_ent_gallery')
          ->condition('gid', $beg_results, 'IN')
          ->execute();
      }

      // Find orphan records in the thumbnail image table
      $bet_query = "SELECT bet.tid
        FROM box_ent_thumb bet
        JOIN box_ent_image_size beis ON beis.thumb_id = bet.tid 
        LEFT JOIN box_item bi ON bi.box_id = beis.box_file_id
        WHERE bi.box_id IS NULL";
      $bet_results = db_query($bet_query)->fetchCol();
      if ($bet_results) {
        db_delete('box_ent_thumb')
          ->condition('tid', $bet_results, 'IN')
          ->execute();
        db_delete('box_ent_image_size')
          ->condition('thumb_id', $bet_results, 'IN')
          ->execute();
      }
    }
  }
  else {
    watchdog('Box Connect', 'Skipped the clean-up (Sixth task) because site is in sync with Box.', array(), WATCHDOG_NOTICE);
  }
}

/**
 * @param $success
 * @param $results
 * @param $operations
 */
function box_batch_finish($success, $results, $operations) {
  // The 'success' parameter means no fatal PHP errors were detected. All
  // other error management should be handled using 'results'.
  if ($success) {
    // Updated the Last Updated variable.
    $update = new DateTime();
    variable_set('box_connect_last_synced', $update->getTimeStamp()); // Save as a timestamp.
    $message = format_plural(count($results), 'One item processed.', '@count items processed.');
    drupal_set_message($message);
  }
  else {
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
    drupal_set_message($message, 'error');
  }
}