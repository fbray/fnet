<?php
// $Id$
/**
 * @file
 * Migrate profile data functions
 *
 */
function fnet_cck_migrations_profile() {
  $batch = array(
    'title' => t('Migrating profile fields'),
    'operations' => array(
      array('fnet_cck_migrations_batch_profile', array()),
    ),
    'finished' => 'fnet_cck_migrations_batch_finished',
    'file' => drupal_get_path('module', 'fnet_cck_migrations') . '/' . 'fnet_cck_migrations.profile.inc',
  );
  batch_set($batch);
  batch_process();

  return array(
    'message' => array(
      '#type' => 'markup',
      '#value' => 'Done.',
    )
  );
}

function fnet_cck_migrations_batch_profile(&$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_node'] = 0;
    $context['sandbox']['max'] = db_query("SELECT COUNT(DISTINCT nid) FROM {node} WHERE type = 'profile'")->fetchField();
  }
  $limit = 100;
  try {
    $result = db_select('node', 'n')
      ->fields('n')
      ->condition('n.type', 'profile', '=')
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
      $old_data = db_select('content_type_profile', 'old')
        ->fields('old')
        ->condition('old.nid', $node_data->nid)
        ->condition('old.vid', $node_data->vid)
        ->orderBy('old.nid', 'ASC')
        ->execute();

      if ($node = node_load($node_data->nid)) {
        $data = $old_data->fetchAssoc();
        if (is_numeric($data['field_gold_pin_value']) && (strlen($data['field_gold_pin_value']) <= 4)) {
          $node->field_gold_pin = array(LANGUAGE_NONE => array(array('value' => $data['field_gold_pin_value'])));
        }

        $address_field = array(
          'first_name' => $data['field_firstname_value'],
          'last_name' => $data['field_lastname_value'],
          'thoroughfare' => $data['field_address_street'],
          'premise' => $data['field_address_additional'],
          'locality' => $data['field_address_city'],
          'administrative_area' => $data['field_address_province'],
          'postal_code' => $data['field_address_postal_code'],
          'country' => strtoupper($data['field_address_country']),
          'organisation_name' => $data['field_organization_value']
        );
        $node->field_profile_address = array(LANGUAGE_NONE => array($address_field));
        $node->title = db_query("SELECT mail FROM {users} WHERE uid=$node->uid")->fetchField();
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

