<?php
// $Id$
/**
 * @file
 * Migrate user profile data functions
 *
 */
function fnet_cck_migrations_user_profile() {
  $batch = array(
    'title' => t('Migrating profile fields'),
    'operations' => array(
      array('fnet_cck_migrations_batch_user_profile', array()),
    ),
    'finished' => 'fnet_cck_migrations_batch_finished',
    'file' => drupal_get_path('module', 'fnet_cck_migrations') . '/' . 'fnet_cck_migrations.user_profile.inc',
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

function fnet_cck_migrations_batch_user_profile(&$context) {
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
      $node = node_load($node_data->nid, $node_data->vid);
      if ($user = user_load($node_data->uid)) {
        $old_data = db_select('content_type_profile', 'old')
          ->fields('old')
          ->condition('old.nid', $node_data->nid)
          ->condition('old.vid', $node_data->vid)
          ->orderBy('old.nid', 'ASC')
          ->execute();
        $data = $old_data->fetchAssoc();
        if ($data) {
          $user->field_user_first_name[LANGUAGE_NONE][0]['value'] = $data['field_firstname_value'];
          $user->field_user_last_name[LANGUAGE_NONE][0]['value'] = $data['field_lastname_value'];
          $user->field_user_address_line_1[LANGUAGE_NONE][0]['value'] = $data['field_address_street'];
          if (!empty($data['field_address_additional'])) {
            $user->field_user_address_line_2[LANGUAGE_NONE][0]['value'] = $data['field_address_additional'];
          }
          $user->field_user_city[LANGUAGE_NONE][0]['value'] = $data['field_address_city'];
          $user->field_user_province[LANGUAGE_NONE][0]['value'] = $data['field_address_province'];
          $user->field_user_postal_code[LANGUAGE_NONE][0]['value'] = $data['field_address_postal_code'];
          $user->field_user_country[LANGUAGE_NONE][0]['value'] = $data['field_address_country'];
          if (!empty($data['field_organization_value'])) {
            $user->field_user_company[LANGUAGE_NONE][0]['value'] = $data['field_organization_value'];
          }
          $user->field_user_preferred_language[LANGUAGE_NONE][0]['value'] = $data['field_preferred_language_value'];
          if (!empty($data['field_profile_job_role_value'])) {
            $user->field_user_job_role[LANGUAGE_NONE][0]['value'] = $data['field_profile_job_role_value'];
          }
          if (is_numeric($data['field_gold_pin_value']) && (strlen($data['field_gold_pin_value']) <= 4)) {
            $user->field_user_gold_pin[LANGUAGE_NONE][0]['value'] = $data['field_gold_pin_value'];
          }
          if (!empty($data['field_gold_number_value'])) {
            $user->field_user_gold_number[LANGUAGE_NONE][0]['value'] = $data['field_gold_number_value'];
          }
          if (!empty($data['field_phone_value'])) {
            $user->field_user_phone[LANGUAGE_NONE][0]['value'] = $data['field_phone_value'];
          }
          if (!empty($data['field_onyx_individualid_value'])) {
            $user->field_user_onyx_id[LANGUAGE_NONE][0]['value'] = $data['field_onyx_individualid_value'];
          }
          try {
            user_save($user);
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
  }
  else {
    $context['finished'] = 1;
  }
}

