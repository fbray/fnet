<?php

/**
 * @file
 * product_assets.views.inc
 */

/**
 * Implements hook_views_data_alter().
 */
function product_assets_views_data_alter(&$data) {
  $data['field_data_field_dam_language']['product_assets_language'] = array(
    'title' => t('Software Download Languages'),
    'real field' => 'field_dam_language',
    'group' => t('Content'),
    'help' => t('Languages available in Software Downloads'),
    'filter' => array(
      'title' => t('Filter by Languages available in Software Downloads.'),
      'handler' => 'product_assets_handler_filter_download_languages',
    ),
  );

}
