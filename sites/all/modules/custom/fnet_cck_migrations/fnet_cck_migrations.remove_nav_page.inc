<?php
// $Id$
/**
 * @file
 * Migrate marketo_form data functions
 *
 */
function fnet_cck_migrations_remove_nav_page() {
  $batch = array(
    'title' => t('Migrating remove nav fields from pages'),
    'operations' => array(
      array('fnet_cck_migrations_batch_remove_nav_page', array()),
    ),
    'finished' => 'fnet_cck_migrations_batch_finished',
    'file' => drupal_get_path('module', 'fnet_cck_migrations') . '/' . 'fnet_cck_migrations.remove_nav_page.inc',
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

function fnet_cck_migrations_batch_remove_nav_page(&$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_node'] = 0;
    $context['sandbox']['max'] = db_query("SELECT COUNT(DISTINCT nid) FROM {node} WHERE type = 'page'")->fetchField();
  }
  $limit = 10;
  try {
    $result = db_select('node', 'n')
      ->fields('n')
      ->condition('n.type', 'page', '=')
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
        $old_data = db_select('content_field_removenav', 'old')
          ->fields('old')
          ->condition('old.nid', $node_data->nid)
          ->condition('old.vid', $node_data->vid)
          ->execute();
        $data = $old_data->fetchAssoc();
        if (strtolower($data['field_removenav_value']) == 'yes') {
          $node->field_removenav[LANGUAGE_NONE][0]['value'] = TRUE;
        }
        else {
          $node->field_removenav[LANGUAGE_NONE][0]['value'] = FALSE;
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

