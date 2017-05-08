<?php
// $Id$
/**
 * @file
 * Migrate profile data functions
 *
 */
function fnet_cck_migrations_bedrock() {
  $batch = array(
    'title' => t('Migrating bedrock user auth map'),
    'operations' => array(
      array('fnet_cck_migrations_batch_bedrock', array()),
    ),
    'finished' => 'fnet_cck_migrations_batch_finished',
    'file' => drupal_get_path('module', 'fnet_cck_migrations') . '/' . 'fnet_cck_migrations.bedrock.inc',
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

function fnet_cck_migrations_batch_bedrock(&$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_user'] = 0;
    $context['sandbox']['max'] = db_query("SELECT COUNT(DISTINCT uid) FROM {bedrock_user}")->fetchField();
  }
  $limit = 100;
  try {
    $result = db_select('bedrock_user', 'b')
      ->fields('b')
      ->condition('b.uid', $context['sandbox']['current_user'], '>')
      ->orderBy('b.uid')
      ->range(0, $limit)
      ->execute();
    $got_users = TRUE;
  } catch (Exception $e) {
    drupal_set_message($e->getMessage(), 'error');
    $got_users = FALSE;
  }
  if ($got_users && $result) {
    foreach ($result as $user_data) {
      if ($user = user_load($user_data->uid)) {
        if (is_numeric($user->name)) {
          $user->name = $user->mail;
          user_set_authmaps($user, array("authname_fnet_bedrock_auth" => $user->name));
          try {
            user_save($user);
          } catch (Exception $e) {
            drupal_set_message($e->getMessage(), 'error');
          }
        }
        $context['results'][] = $user->uid . ' : ' . check_plain($user->name);
        $context['sandbox']['progress']++;
        $context['sandbox']['current_user'] = $user->uid;
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

