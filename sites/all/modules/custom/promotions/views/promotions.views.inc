<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 10/24/17
 * Time: 1:07 PM
 */

/**
 * Implements hook_views_data_alter().
 */
function promotions_views_data_alter(&$data) {
  $data['node']['region_language']['title'] = 'RegLang Filter';
  $data['node']['region_language']['help'] = 'Filter content by the users current RegLang';
  $data['node']['region_language']['filter']['handler'] = 'promotions_handler_filter_reglang';
}