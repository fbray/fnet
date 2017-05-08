<?php
// $Id$
/**
 * @file
 * Migrate marketo_form data functions
 *
 */
function fnet_cck_migrations_digital_asset() {
  $batch = array(
    'title' => t('Migrating digital_asset fields'),
    'operations' => array(
      array('fnet_cck_migrations_batch_digital_asset', array()),
    ),
    'finished' => 'fnet_cck_migrations_batch_finished',
    'file' => drupal_get_path('module', 'fnet_cck_migrations') . '/' . 'fnet_cck_migrations.digital_asset.inc',
  );
  batch_set($batch);
  batch_process('node');

  return array(
    'message' => array(
      '#type' => 'markup',
      '#value' => 'Done.',
    )
  );
}

function fnet_cck_migrations_batch_digital_asset(&$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_node'] = 0;
    $context['sandbox']['max'] = db_query("SELECT COUNT(DISTINCT nid) FROM {node} WHERE type = 'digital_asset'")->fetchField();
  }
  $limit = 10;
  try {
    $result = db_select('node', 'n')
      ->fields('n')
      ->condition('n.type', 'digital_asset', '=')
      ->condition('n.nid', $context['sandbox']['current_node'], '>')
      ->orderBy('n.nid')
      ->range(0, $limit)
      ->execute();
    $got_nodes = TRUE;
  } catch (Exception $e) {
    drupal_set_message($e->getMessage(), 'error');
    $got_nodes = FALSE;
  }
  if ($got_nodes && $result) {
    foreach ($result as $node_data) {
      // Check to see if the old CCK attribute field has any data for this node.
      $old_data = db_select('content_type_digital_asset', 'old')
        ->fields('old')
        ->condition('old.nid', $node_data->nid)
        ->condition('old.vid', $node_data->vid)
        ->orderBy('old.nid', 'ASC')
        ->execute();
      $data = $old_data->fetchAssoc();
      if ($node = node_load($node_data->nid)) {
        $file_size = (empty($data['field_dam_file_size_value'])) ? 0 : (int) $data['field_dam_file_size_value'];
        $node->field_dam_file_size = array(LANGUAGE_NONE => array(array('value' => $file_size)));
        $export = $data['field_dam_export_controlled_value'];
        $export = (empty($export) || strtolower($export) == 'no' || $export == 0) ? FALSE : TRUE;
        $node->field_dam_export_controlled = array(LANGUAGE_NONE => array(array('value' => $export)));
        $bulk = $data['field_dam_bulk_fulfillment_value'];
        $bulk = (empty($bulk) || strtolower($bulk) == 'no' || $bulk == 0) ? FALSE : TRUE;
        $node->field_dam_bulk_fulfillment = array(LANGUAGE_NONE => array(array('value' => $bulk)));
        $keep = $data['field_dam_keep_original_filename_value'];
        $keep = (empty($keep) || strtolower($keep) == 'no' || $keep == 0) ? FALSE : TRUE;
        $node->field_dam_keep_original_filename = array(LANGUAGE_NONE => array(array('value' => $keep)));
        $print = $data['field_dam_print_on_demand_value'];
        $print = (empty($print) || strtolower($print) == 'no' || $print == 0) ? FALSE : TRUE;
        $node->field_dam_print_on_demand = array(LANGUAGE_NONE => array(array('value' => $print)));

        try {
          node_save($node);
        } catch (Exception $e) {
          drupal_set_message($e->getMessage(), 'error');
        }
      }
      $context['results'][] = $node_data->nid;
      $context['sandbox']['progress']++;
      $context['sandbox']['current_node'] = $node_data->nid;
      $context['message'] = 'Processed ' . $context['sandbox']['progress'] . ' of ' . $context['sandbox']['max'];
    }
    if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
      $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
    }
  }
  else {
    $context['finished'] = 1;
  }
}

