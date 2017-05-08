<?php
// $Id$
/**
 * @file
 * Migrate marketo_form data functions
 *
 */
function fnet_cck_migrations_marketo_form() {
  $batch = array(
    'title' => t('Migrating marketo_form fields'),
    'operations' => array(
      array('fnet_cck_migrations_batch_marketo_form', array()),
    ),
    'finished' => 'fnet_cck_migrations_batch_finished',
    'file' => drupal_get_path('module', 'fnet_cck_migrations') . '/' . 'fnet_cck_migrations.marketo_form.inc',
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

function fnet_cck_migrations_batch_marketo_form(&$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_node'] = 0;
    $context['sandbox']['max'] = db_query("SELECT COUNT(DISTINCT nid) FROM {node} WHERE type = 'marketo_form'")->fetchField();
  }
  $limit = 10;
  try {
    $result = db_select('node', 'n')
      ->fields('n')
      ->condition('n.type', 'marketo_form', '=')
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
      $old_data = db_select('content_type_marketo_form', 'old')
        ->fields('old')
        ->condition('old.nid', $node_data->nid)
        ->condition('old.vid', $node_data->vid)
        ->orderBy('old.nid', 'ASC')
        ->execute();

      if ($node = node_load($node_data->nid)) {
        $data = $old_data->fetchAssoc();
        $node->field_mkt_form_title = array(LANGUAGE_NONE => array(array('value' => $data['field_mkt_form_title_value'])));
        $node->field_mkt_iframe_url_en = array(LANGUAGE_NONE => array(array('value' => $data['field_mkt_iframe_url_en_value'])));
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

