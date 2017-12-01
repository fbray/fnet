<?php
class BoxGalleryController extends BoxControllerBase {

  public function __construct($entityType='box_gallery') {
    parent::__construct($entityType);
  }


  public function load($ids = array(), $conditions = array()) {
    $return = array();
    $entity_array = parent::load($ids, $conditions);
    return $entity_array;
  }


  public function create(array $values = array()) {

      $values['display_title'] = $values['box_title']; 
      return parent::create($values);
  }

  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {

        $path = drupal_get_path('module', 'box_entities');
        $entity->view_mode = $view_mode;

        $query = db_select('box_ent_thumb', 'bet');
        $query->fields('bet', array('tid',) );
        $query->condition('gallery_id', $entity->gid, '=');

        if ( $view_mode == 'gallery_paged') {
          $content['#attached']['css'][] =  $path . '/css/gallery_paged.css';
          $content['#attached']['js'][] =  $path . '/js/gallery_paged.js';
          $query = $query->extend('PagerDefault');
          $query->limit(12);
        }

        $results = $query->execute()->fetchAllAssoc('tid');

        if ($results) {
          $ids = array_keys($results);
          $box_thumbnails = entity_load('box_thumbnail', $ids );
          $entity->box_thumbnails = $box_thumbnails;
          $content['box_thumbnails'] = $box_thumbnails;
        }

        $built = parent::buildContent($entity, $view_mode, $langcode, $content);

      return $built;
  }

  public function view($entities, $view_mode = 'full', $langcode = NULL, $page = NULL) {
    $parent = parent::view($entities, $view_mode);
    return $parent;
  }


}



