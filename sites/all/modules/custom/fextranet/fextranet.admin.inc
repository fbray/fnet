<?php
/**
 * Implements Admin Page
 */
function fextranet_admin() {

  // TODO: Instructions. This should be the Admin landing page

  return 'Fnord';
}

/**
 * Implements Admin Page for text instructions.
 */
function fextranet_admin_instructions_form($form, &$form_state) {
  $form = array();

  $form['extranet_instructions_request_access'] = array(
    '#type' => 'textarea',
    '#title' => t('Request Access'),
    '#description' => t('The instruction text for when a user requests access to the Extranet'),
    '#default_value' => variable_get('extranet_instructions_request_access', ''),
  );

  $form['extranet_instructions_main'] = array(
    '#type' => 'textarea',
    '#title' => t('Main Page'),
    '#description' => t('The instruction text for the main page.'),
    '#default_value' => variable_get('extranet_instructions_main', ''),
  );

  $form['extranet_instructions_sales_tools'] = array(
    '#type' => 'textarea',
    '#title' => t('Sales Tools'),
    '#description' => t('The instruction text for the Sales Tools page.'),
    '#default_value' => variable_get('extranet_instructions_sales_tools', ''),
  );

  $form['extranet_instructions_services'] = array(
    '#type' => 'textarea',
    '#title' => t('Services & Support text'),
    '#description' => t('The instruction text for the Services & Support page.'),
    '#default_value' => variable_get('extranet_instructions_services', ''),
  );

  $form['extranet_instructions_access_denied'] = array(
    '#type' => 'textarea',
    '#title' => t('Access Denied text'),
    '#description' => t('Instruction text for the Access Denied page'),
    '#default_value' => variable_get('extranet_instructions_access_denied', ''),
  );

  return system_settings_form($form);
}

/**
 * The form for uploading the public key for Salesforce.
 *
 * @param $form
 * @param $form_state
 * @return array
 */
function fextranet_admin_salesforce_config($form, &$form_state) {
  $form = array();

  $form['extranet_salesforce'] = array(
    '#type' => 'fieldset',
    '#title' => t('Salesforce Public Key'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  $form['extranet_salesforce']['salesforce_public_key'] = array(
    '#type' => 'file',
    '#title' => t('Upload the Salesforce PEM file.'),
    '#default_value' => variable_get('salesforce_public_key'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
  );
  return $form;
}

/**
 * Validation and saving the file to Drupal.
 *
 * @param $form
 * @param $form_state
 */
function fextranet_admin_salesforce_config_validate($form, &$form_state) {
  $pem_file = file_save_upload('salesforce_public_key');
  if (isset($pem_file)) {
    // File upload was attempted.
    if ($pem_file) {
      // The temporary file should be put in form_values so we can save it on submit.
      $form_state['values']['pem_file_upload'] = $pem_file;
      drupal_set_message('The file upload was attempted.');
    }
    else {
      // file upload error.
      form_set_error('salesforce_public_key', t('The file cannot be uploaded.'));
    }
  }
}

/**
 * Submit function for the Salesforce config form.
 *
 * @param $form
 * @param $form_state
 */
function fextranet_admin_salesforce_config_submit($form, &$form_state) {
  dpm($form_state);
  $values = $form_state['values'];
  if ($file = $values['pem_file_upload']) {
    unset($values['pem_file_upload']);
    $filename = file_unmanaged_copy($file->uri);
    $values['salesforce_public_key'] = $filename;
    drupal_set_message('The file was successfully uploaded.');
  }
  variable_set('salesforce_public_key', $values['salesforce_public_key']);
}


/**
 * Gets the available groups
 */
function get_admin_groups($uid =FALSE) {

  if (! $uid) {
  	global $user;
  	$uid = $user->uid;
  }

  $return = FALSE;

  $query = db_select('group_membership', 'gm');
  $query->leftJoin('groups', 'g', 'g.gid = gm.gid');
  $query->leftJoin('group_membership_role', 'gmr', 'gm.mid=gmr.mid');
  $query->leftJoin('group_role', 'gr', 'gmr.role = gr.name');
  
  $query->fields('gm', array('mid', 'gid', 'status'));
  $query->fields('gmr', array('role'));
  $query->fields('g', array('title'));

  $query->condition('gm.uid', $uid, '=');
  $query->condition('gmr.role', NULL, 'IS NOT');
  $query->condition('gmr.role', 'user', '!=');
  $query->condition('gm.status', array('blocked', 'requested'), 'NOT IN');
  $results = $query->execute()->fetchAllAssoc('gid');

  if ($results) {
  	$return = array();
	  foreach ($results as $result) {
	  	$gid = $result->gid;

	  	// move substrings off 0 so can skip !== FALSE
	  	$role =  $result->role ? 'role_' . $result->role : 'default';

	  	if ( strpos( $role, 'admin') || strpos( $role, 'author') )  $return[$gid] = $result;

	  }
	}

	return $return;
}



function _fex_approve_deal_form($gid, $did) {

  $register_deal = entity_load_single('register_deal', $did);

  $form_state = array();
  $form_state['#approve_deal'] = TRUE;
  $form_state['redirect'] = 'admin/extranet';

  $register_deal_edit = entity_ui_get_form('register_deal', $register_deal, 'edit', $form_state );

  return $register_deal_edit;

}


/*
*   Produces audit report for Extranet nodes
*   Loops over group/region users, and tests to see if they pass/fail added access restrictions
*/
function fextranet_audit($nid) {

    $group_ids = _fextranet_get_nid_groups($nid);
    $groups = group_load_multiple($group_ids);

    $rows = array();

    if ($groups) {
      $node = node_load($nid);

      foreach ( $groups as $gid => $group) {
        
        $memberships = $group->getMembers();

          $row = array(
              'data'  =>  array(  $group->title , ' ',  ' ',  ' ', ),
              'attributes'  => array(),
              'no_striping' => TRUE,
            );

        $rows[]  = $row;

        foreach ($memberships as $mid => $ms) {
          if ($ms->status == 'active') {
            $uid = $ms->uid;
            $user = user_load($uid);

            $result1 = _fextranet_check_countries($user, $node, $group) ? 'yes' : 'no';
            $result2 = _fextranet_check_roles($user, $node, $group) ? 'yes' : 'no';
     //       $result3 = _fextranet_check_distributor($user, $node, $group) ? 'yes' : 'no';
            //phase 2
            $result3 = '';

            $row = array(
              'data'  =>  array($user->mail, $result1,  $result2,  $result3, ),
              'attributes'  => array(),
              'no_striping' => FALSE,
            );



            $rows[] = $row;

          } 

        } //end for users


      } // end for gid
    } // end if results



    $header = array(
      array('data'  => 'User Email',),
      array('data'  => 'Country Check',),
      array('data'  => 'Role Check',),
      // phase2
  //    array('data'  => 'Distributor Check',),
      array('data'  => '',),
      );

    $full_rows = array(
      'data'  => $rows,
      'attributes'  => array(),
      'no_striping' => FALSE,
      );

  $table = array (
    'header'  => $header,
    'rows'  =>  $rows,
    'attributes'  => array(),
    'caption' =>  'Extranet User Access Audit',
    'colgroups' => array(),
    'sticky'  =>  FALSE,
    'empty' => 'empty',
    );


  $tt = theme_table($table);

  return $tt;

}


