<?php
// $Id$
/**
 * @file
 * Migrate promotion_fulfillment data functions
 *
 */
function fnet_cck_migrations_promotion_fulfillment() {
  $batch = array(
    'title' => t('Migrating promotion_fulfillment fields'),
    'operations' => array(
      array('fnet_cck_migrations_batch_promotion_fulfillment', array()),
    ),
    'finished' => 'fnet_cck_migrations_batch_finished',
    'file' => drupal_get_path('module', 'fnet_cck_migrations') . '/' . 'fnet_cck_migrations.promotion_fulfillment.inc',
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

function fnet_cck_migrations_batch_promotion_fulfillment(&$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_node'] = 0;
    $context['sandbox']['max'] = db_query("SELECT COUNT(DISTINCT nid) FROM {node} WHERE type = 'promotion_fulfillment'")->fetchField();
  }
  $limit = 10;
  try {
    $result = db_select('node', 'n')
      ->fields('n')
      ->condition('n.type', 'promotion_fulfillment', '=')
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
      if ($node = node_load($node_data->nid)) {
        $fields = array(
          'field_available_products',
          'field_pf_disqualified_purchases',
        );
        foreach ($fields as $field) {
          $values = array();
          $old_data = db_select("content_$field", 'old')
            ->fields('old')
            ->condition('old.nid', $node_data->nid)
            ->condition('old.vid', $node_data->vid)
            ->orderBy('old.delta', 'ASC')
            ->execute();
          foreach ($old_data as $row) {
            $field_name = "{$field}_value";
            $values[] = array('value' => $row->$field_name);
          }
          $node->$field = array(LANGUAGE_NONE => $values);
        }
        try {
          node_save($node);
        } catch (Exception $e) {
          drupal_set_message($e->getMessage(), 'error');
        }
        $context['results'][] = $node->nid . ' : ' . check_plain($node->title);
        $context['sandbox']['progress']++;
        $context['sandbox']['current_node'] = $node->nid;
        $context['message'] = 'Processed ' . $context['sandbox']['progress'] . ' of ' . $context['sandbox']['max'];
      }
    }
    if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
      $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
    }
  }
  else {
    $context['finished'] = 1;
  }
}

