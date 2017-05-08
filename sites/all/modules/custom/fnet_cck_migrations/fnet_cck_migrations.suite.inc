<?php
// $Id$
/**
 * @file
 * Migrate marketo_form data functions
 *
 */
function fnet_cck_migrations_suite() {
  $batch = array(
    'title' => t('Migrating suite fields'),
    'operations' => array(
      array('fnet_cck_migrations_batch_suite', array()),
    ),
    'finished' => 'fnet_cck_migrations_batch_finished',
    'file' => drupal_get_path('module', 'fnet_cck_migrations') . '/' . 'fnet_cck_migrations.suite.inc',
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

function fnet_cck_migrations_batch_suite(&$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_node'] = 0;
    $context['sandbox']['max'] = db_query("SELECT COUNT(DISTINCT nid) FROM {node} WHERE type = 'suite'")->fetchField();
  }
  $limit = 10;
  try {
    $result = db_select('node', 'n')
      ->fields('n')
      ->condition('n.type', 'suite', '=')
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
        // Check to see if the old CCK attribute field has any data for this node.
        $old_data = db_select('content_type_suite', 'old')
          ->fields('old')
          ->condition('old.nid', $node_data->nid)
          ->condition('old.vid', $node_data->vid)
          ->execute();
        $data = $old_data->fetchAssoc();
        $node->field_suite_spot_desc_1 = array(LANGUAGE_NONE => array(array('value' => $data['field_suite_spot_desc_1_value'])));
        $node->field_suite_spot_desc_2 = array(LANGUAGE_NONE => array(array('value' => $data['field_suite_spot_desc_2_value'])));
        $node->field_suite_spot_desc_3 = array(LANGUAGE_NONE => array(array('value' => $data['field_suite_spot_desc_3_value'])));

        try {
          node_save($node);
        } catch (Exception $e) {
          drupal_set_message($e->getMessage(), 'error');
        }
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
  else {
    $context['finished'] = 1;
  }
}

