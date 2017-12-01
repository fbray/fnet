<?php
class BoxImageSizeController extends BoxControllerBase {
  public function create(array $values = array()) {
    $values['display_title'] = $values['box_name'];
    return parent::create($values);
  }

  public function load($ids = array(), $conditions = array()) {
    $parent = parent::load($ids, $conditions);
    return $parent;
  }

  public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()) {
    return parent::buildContent($entity, $view_mode, $langcode, $content);
  }

  public function view($entities, $view_mode = 'full', $langcode = NULL, $page = NULL) {
    return parent::view($entities, $view_mode);
  }
}

