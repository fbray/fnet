<?php
// $Id$
/**
 * @file
 * Migrate user profile data functions
 *
 */
function fnet_cck_migrations_new_users() {
  $batch = array(
    'title' => t('Migrating new users'),
    'operations' => array(
      array('fnet_cck_migrations_batch_new_users', array()),
    ),
    'finished' => 'fnet_cck_migrations_batch_finished',
    'file' => drupal_get_path('module', 'fnet_cck_migrations') . '/' . 'fnet_cck_migrations.new_users.inc',
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

function fnet_cck_migrations_batch_new_users(&$context) {
  $cutoff = '2015-07-09-10';
  if (empty($context['sandbox'])) {
    db_set_active('drupal6');
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_uid'] = 0;
    $context['sandbox']['max'] = db_query("SELECT COUNT(uid) FROM users WHERE FROM_UNIXTIME(created, '%Y-%m-%d-%H') > '$cutoff';")->fetchField();
    db_set_active();
  }
  $current_uid = $context['sandbox']['current_uid'];
  $limit = 1000;
  $sql = <<<eot
SELECT
u.uid,
u.`name`,
u.mail,
p.field_firstname_value,
p.field_lastname_value,
p.field_phone_value,
p.field_organization_value,
p.field_gold_number_value,
p.field_gold_pin_value,
p.field_onyx_individualid_value,
p.field_migrated_user_value,
p.field_reg_language_value,
p.field_address_is_primary,
p.field_address_aname,
p.field_address_country,
p.field_address_province,
p.field_address_city,
p.field_address_street,
p.field_address_additional,
p.field_address_postal_code,
p.field_preferred_language_value,
p.field_profile_job_role_value
FROM
users AS u
INNER JOIN node AS n ON u.uid = n.uid
INNER JOIN content_type_profile AS p ON n.nid = p.nid AND n.vid = p.vid
WHERE
FROM_UNIXTIME(u.created, '%Y-%m-%d-%H') > '$cutoff'
AND u.uid > $current_uid
ORDER BY u.uid
eot;

  try {
    db_set_active('drupal6');
    $result = db_query($sql);
    $got_nodes = TRUE;
  } catch (Exception $e) {
    drupal_set_message($e->getMessage(), 'error');
    $got_nodes = FALSE;
  }
  db_set_active();
  if ($got_nodes && $result) {
    db_set_active('drupal6');
    $users = array();
    while ($data = $result->fetchAssoc()) {
      $users[] = $data;
    }
    db_set_active();
    if (!empty($users)) {
      foreach ($users as $data) {
        $user = user_load($data['uid']);
        if ($user) {
          continue;
        }
        $user = new stdClass();
        $user->mail = $data['mail'];
        $name = preg_replace('/@.*$/', '', $data['mail']);
        $user->name = fnet_cck_migrations_unique_username($name, $data['uid']);
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
        $context['results'][] = $user->name;
        $context['sandbox']['progress']++;
        $context['sandbox']['current_uid'] = $data['uid'];
        $context['message'] = 'Processed ' . $context['sandbox']['progress'] . ' of ' . $context['sandbox']['max'];
      }
    }
  }
  else {
    $context['finished'] = 1;
  }

}

function fnet_cck_migrations_unique_username($name, $uid) {
  // Iterate until we find a unique name.
  $i = 0;
  do {
    $new_name = empty($i) ? $name : $name . '_' . $i;
    $found = db_query_range("SELECT uid from {users} WHERE uid <> :uid AND name = :name", 0, 1, array(
      ':uid' => $uid,
      ':name' => $new_name
    ))->fetchAssoc();
    $i++;
  } while (!empty($found));

  return $new_name;
}

