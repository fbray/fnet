<?php
/*
* Callback for Extranet request form
*/
function fextranet_custom_request_form($form, &$form_state, $gid) {
  $form = array();

  $form['instructions'] = array(
    '#markup' => variable_get('extranet_instructions_request_access', ''),
  );

  $form['gid'] = array(
    '#type' => 'hidden',
    '#name' => 'gid',
    '#value' => $gid,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Request Sales Insider access'),
  );

  return $form;
}

/*
* Submit handler for Extranet request form
*/
function fextranet_custom_request_form_submit($form, &$form_state) {
  global $user;
  $gid = $form_state['values']['gid'];
 //  $uid = $form_state['values']['uid'];

  if ($gid && $user->uid) {
    $out = entity_create('group_membership', array(
      'uid' => $user->uid,
      'gid' => $gid,
      'status' => 'requested',
      'requested_on' => time(),
    ));
    // Saving the Group Membership entity triggers a number of Rules for sending emails.
    entity_save('group_membership', $out);
    // Direct the user to the Request Received page.
    $form_state['redirect'] = 'extranet/request-received';
  }
  else {
    watchdog('fextranet', 'Access Request problem: Missing GID or UID.');
    drupal_set_message(t("We're unable to process your request."));
  }
}