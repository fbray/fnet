<?php
class BoxThumbnailController extends BoxControllerBase {

  public function load($ids = array(), $conditions = array()) {
    $return = array();

    $entity_array = parent::load($ids, $conditions);

    foreach ($entity_array as $tid => $entity) {

      // Future adjustment: load all Gallery thumbs/image at Gallery load
      // Could be 1 query instead of nested
      if (!isset($entity->box_image_size)) {

        $query = db_select('box_ent_image_size', 'beis');
        $query->fields('beis', array('box_file_id',));
        $query->condition('thumb_id', $tid, '=');
        $results = $query->execute()->fetchAllAssoc('box_file_id');

        if ($results) {
          $ids = array_keys($results);
          $box_image_sizes = entity_load('box_image_size', $ids);
          $entity->box_image_size = $box_image_sizes;
          //			$entity->box_image_sizes = $box_image_sizes;

        }

      }
      $return[$tid] = $entity;
    }

    return $return;
  }

  public function create(array $values = array()) {
      return parent::create($values);
  }

  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
	$temp = parent::buildContent($entity, $view_mode, $langcode, $content);
    return $temp ;
  }

  public function view($entities, $view_mode = 'full', $langcode = NULL, $page = NULL) {

    $parent = parent::view($entities, $view_mode);
    return $parent;

  }
}

