<?php

/**
 * @file
 * globallink_field_configuration.inc is a file that contains most functions
 * needed on the Field Configuration UI.
 */

/**
 * Returns form for globallink_field page.
 */
function globallink_field_page() {
  return drupal_get_form('globallink_field');
}

/**
 * Renders form for globallink_field.
 */
function globallink_field() {
  module_load_include('inc', 'globallink', 'globallink');
  module_load_include('inc', 'globallink', 'globallink_taxonomy/globallink_taxonomy');

  $selected_value = '';
  $entity_type = 'node';

  if (!empty($_SESSION['globallink_selected_content_type'])) {
    $selected_value = $_SESSION['globallink_selected_content_type'];
  }
  if (globallink_starts_with($selected_value, 'fpp:')) {
    $entity_type = 'fieldable_panels_pane';
  }
  else if (globallink_starts_with($selected_value, 'tax:')) {
    $entity_type = 'taxonomy_term';
    $arr_avail = globallink_get_all_translatable_taxonomy_types_and_names();
    if (!array_key_exists($selected_value, $arr_avail)) {
      $selected_value = '';
    }
  }
  else if (globallink_starts_with($selected_value, 'bean:')) {
      $entity_type = 'bean';
  }

  $form = array();

  $n_arr = array('' => t('--Select Content Type--'));
  $t_arr = globallink_get_translatable_node_types_and_names();

  $node_types = $n_arr + $t_arr;

  if (module_exists('globallink_fieldable_panels')) {
    module_load_include('inc', 'globallink', 'globallink_fieldable_panels/globallink_fieldable_panels');
    $t_arr = globallink_get_all_translatable_fpp_types_and_names();
    if (!empty($t_arr)) {
      $node_types += array('_fpp_' => t('--Select FPP Type--'));
      $node_types += $t_arr;
    }
  }
  if (module_exists('globallink_taxonomy')) {
    module_load_include('inc', 'globallink', 'globallink_taxonomy/globallink_taxonomy');
    $t_arr = globallink_get_all_translatable_taxonomy_types_and_names();
    if (!empty($t_arr)) {
      $node_types += array('_tax_' => t('--Select Vocabulary--'));
      $node_types += $t_arr;
    }
  }
  if (module_exists('globallink_beans')) {
      module_load_include('inc', 'globallink', 'globallink_beans/globallink_beans');
      $t_arr = globallink_get_all_translatable_bean_types_and_names();
      if (!empty($t_arr)) {
          $node_types += array('_bean_' => t('--Select Bean Type--'));
          $node_types += $t_arr;
      }
  }
  
  $form['#attributes']['class'][] = 'globallink-field';

  $form['select_field'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('container-inline')),
  );

  $form['select_field']['select_type'] = array(
    '#type' => 'select',
    '#title' => t('Content Type'),
    '#options' => $node_types,
    '#default_value' => $selected_value,
    '#attributes' => array(
      'class' => array('globallink-field-select-type'),
    ),
    '#field_suffix' => '&nbsp;&nbsp;&nbsp;&nbsp;',
  );

  $form['select_field']['select_entity_type'] = array(
    '#type' => 'hidden', '#value' => $entity_type
  );

  $form['select_field']['go'] = array(
    '#type' => 'submit',
    '#value' => t('Go'),
    '#attributes' => array('style' => 'display: none;'),
  );

  if ($selected_value != '') {
    $disabled = FALSE;

    $f_arr = array('[all]' => t('All'));
    switch($entity_type) {
      case 'node':
        $p_arr = globallink_get_pending_fields($selected_value, $entity_type);
	break;
      case 'fieldable_panels_pane':
        $fpp_type = str_replace('fpp:', '', $selected_value);
        $p_arr = globallink_get_pending_fields($fpp_type, $entity_type);
	break;
      case 'taxonomy_term':
        $tax_type = str_replace('tax:', '', $selected_value);
	$p_arr = globallink_get_pending_fields($tax_type, $entity_type);
        break;
      case 'bean':
        $bean_type = str_replace('bean:', '', $selected_value);
        $p_arr = globallink_get_pending_fields($bean_type, $entity_type);
        break;
    }

    $pending_fields = $f_arr + $p_arr;

    if (count($pending_fields) == 1) {
      $pending_fields = array('' => '--Select--');
      $disabled = TRUE;
    }

    $form['select_field']['pending_fields'] = array(
      '#type' => 'select',
      '#title' => '&nbsp;&nbsp;Fields:&nbsp;&nbsp;',
      '#options' => $pending_fields,
      '#field_suffix' => '&nbsp;&nbsp;&nbsp;&nbsp;',
    );

    $form['select_field']['add_field'] = array(
      '#type' => 'submit',
      '#value' => t('Add'),
      '#disabled' => $disabled,
    );

    $form['select_field']['br_markup'] = array(
      '#type' => 'markup',
      '#markup' => '<BR/><BR/>',
    );

    $header = array(
      'field_label' => array(
        'field' => 'field_label',
        'data' => t('Field Label'),
      ),
      'field_name' => array(
        'field' => 'field_name',
        'data' => t('Field Name'),
      ),
      'field_type' => array(
        'field' => 'field_type',
        'data' => t('Field Type'),
      ),
    );

    $ignore_field_types = array('list_boolean', 'file', 'taxonomy_term_reference', 'entityreference');
    $query = db_select('globallink_field_config', 'tf')
    ->fields('tf')
    ->condition('content_type', $selected_value, '=')
    ->condition('field_type', $ignore_field_types, 'NOT IN')
    ->extend('TableSort') // Sorting Extender
    ->orderByHeader($header) // Field to sort on is picked from $header
    ;

    $results = $query->execute();

    $count = 0;

    $rows = array();

    $default_values = array();

    $field_types = field_info_field_types();

    $field_bundles = field_info_bundles();

    foreach ($results as $item) {
      if ($item->field_type == 'field_collection') {
        continue;
      }
      
      if ($item->entity_type != 'node' || ($item->entity_type == 'node' && entity_translation_node_supported_type($item->content_type))) {
        if ($item->field_name != 'metatags' && (strpos($item->field_name, '@summary') == FALSE)) {
            $query = db_select('field_config', 'tf')
              ->fields('tf', array('field_name'))
              ->condition('field_name', $item->field_name, '=')
              ->condition(db_or()->condition(db_and()->condition('translatable', '1', '='))
                           ->condition(db_and()->condition('type', 'image', '=')));
            $result_field = $query->execute();
            $row_count = $result_field->rowCount();
            if (!$row_count) {
              continue 1;
            }
        }
      }
      $count++;

      $bundle_info = $field_bundles[$item->entity_type];
      $bundle_text = $item->bundle;
      switch($item->entity_type) {
        case 'node':
          if(isset($bundle_info[$item->content_type])) {
            $bundle_text = $bundle_info[$item->content_type]['label'];    
          }
          break;
        case 'fieldable_panels_pane':
          $exploded_bl = explode(':', $item->bundle);
          $bundle = $exploded_bl[1];
          if(isset($bundle_info[$bundle])) {
            $bundle_text = $bundle_info[$bundle]['label'];    
          }
          break;
        case 'taxonomy_term':
          $exploded_bl = explode(':', $item->bundle);
          $bundle = $exploded_bl[1];
          if(isset($bundle_info[$bundle])) {
            $bundle_text = $bundle_info[$bundle]['label'];    
          }
          break;
        case 'bean':
          $exploded_bl = explode(':', $item->bundle);
          $bundle = $exploded_bl[1];
          if(isset($bundle_info[$bundle])) {
            $bundle_text = $bundle_info[$bundle]['label'];
          }
          break;
      }  
      $rows[$item->fid] = array(
        'field_label' => $item->field_label,
	'bundle' => $bundle_text,
        'field_name' => $item->field_name,
        'field_type' => isset($field_types[$item->field_type]) ? $field_types[$item->field_type]['label'] : $item->field_type,
      );

      if ($item->translatable == 1) {
        $default_values[$item->fid] = 1;
      }
      else {
        $default_values[$item->fid] = 0;
      }
    }

    $form['field-heading'] = array(
      '#type' => 'container',
    );

    $form['field-heading'][] = array(
      '#markup' => '<em>' . t('Check all the fields that you wish to translate for this content type.') . '</em><br>',
    );

    $form['table'] = array(
      '#type' => 'tableselect',
      '#header' => $header,
      '#options' => $rows,
      '#empty' => t('No items available'),
      '#default_value' => $default_values,
    );

    if (globallink_content_type_workbench_enabled($selected_value)) {
      if ($states = workbench_moderation_state_labels()) {
        $mod_key = '';
        $current_value = variable_get('globallink_moderation_' . $selected_value, FALSE);

        if ($current_value) {
          $states_value = $states[$current_value];
          unset($states[$current_value]);

          $new_value = array(
            $mod_key => t('Current: @state', array(
              '@state' => $states_value,
            )
          ));

          $states = array_merge($new_value, $states);
        }

        $form['state'] = array(
          '#title' => t('Moderation state (after import)'),
          '#type' => 'select',
          '#options' => $states,
          '#default_value' => $mod_key,
        );
      }
    }

    if ($count > 0) {
      $form['submit_field_update'] = array(
        '#type' => 'submit',
        '#value' => t('Update'),
      );
    }
  }

  return $form;
}

/**
 * Handles submission of globallink_field form.
 */
function globallink_field_submit($form, &$form_state) {
  $op = isset($form_state['values']['op']) ? $form_state['values']['op'] : '';

  switch ($op) {
    case t('Go'):
      $_SESSION['globallink_selected_content_type'] = $form_state['values']['select_type'];

      break;
    case t('Update'):
      $type = $form_state['values']['select_type'];

      $fids = array_filter($form_state['values']['table']);

      globallink_update_gl_field_config($type, $fids);

      $state = isset($form_state['input']['state']) ? $form_state['input']['state'] : FALSE;

      if ($state) {
        variable_set('globallink_moderation_' . $type, $state);
      }

      drupal_set_message(t('Field configurations have been saved successfully.'));

      break;
    case t('Add'):
      $field = $form_state['values']['pending_fields'];
      globallink_insert_gl_field_config($field, $_SESSION['globallink_selected_content_type'], $form_state['values']['select_entity_type']);
      drupal_set_message(t('Field configurations have been added successfully.'));

      break;
  }
}

/**
 * Updates GlobalLink field configuration.
 *
 * @param string $type
 *   The content type.
 * @param array $fids
 *   The array of field IDs.
 */
function globallink_update_gl_field_config($type, $fids) {
  // First update everything to 0 for this type
  db_update('globallink_field_config')
  ->fields(array('translatable' => 0))
  ->condition('content_type', $type, '=')
  ->execute();

  foreach ($fids as $fid) {
    db_update('globallink_field_config')
    ->fields(array('translatable' => 1))
    ->condition('fid', $fid, '=')
    ->execute();
  }
}

/**
 * Inserts GlobalLink field configuration.
 *
 * @param string $field_name
 *   The field name.
 * @param string $content_type
 *   The content type.
 */
function globallink_insert_gl_field_config($field_name, $content_type, $entity_type) {
  if ($entity_type == 'node') {
    $p_arr = globallink_get_pending_fields($content_type, $entity_type);
  }
  else if ($entity_type == 'fieldable_panels_pane') {
    $fpp_type = str_replace('fpp:', '', $content_type);
    $p_arr = globallink_get_pending_fields($fpp_type, $entity_type);
  }
  else if ($entity_type == 'taxonomy_term') {
    $tax_type = str_replace('tax:', '', $content_type);
    $p_arr = globallink_get_pending_fields($tax_type, $entity_type);
  }
  else if ($entity_type == 'bean') {
    $bean_type = str_replace('bean:', '', $content_type);
    $p_arr = globallink_get_pending_fields($bean_type, $entity_type);
  }
  if ($field_name == '[all]') {
    $f_keys = array_keys($p_arr);

    foreach ($f_keys as $f_key) {
      if ($f_key == '[all]') {
        continue;
      }
      $sum_field = '';
      if (strpos($f_key, '@summary') !== false) {
          $sum_field = $f_key;
      }
      if ($f_key != 'title' && $f_key != 'metatags' && empty($sum_field)) {
        $field = field_info_field($f_key);

        switch ($field['type']) {
          case 'list_boolean':
          case 'file':
          case 'taxonomy_term_reference':
	  case 'entityreference':
          case 'field_collection':
            break;
          default:
            db_insert('globallink_field_config')
            ->fields(array(
              'content_type' => $content_type,
              'entity_type' => $entity_type,
              'bundle' => $content_type,
              'field_name' => $f_key,
              'field_type' => $field['type'],
              'field_label' => $p_arr[$f_key],
              'translatable' => 1,
            ))->execute();
        }
      }
      else {
        db_insert('globallink_field_config')
        ->fields(array(
          'content_type' => $content_type,
          'entity_type' => $entity_type,
          'bundle' => $content_type,
          'field_name' => $f_key,
          'field_type' => 'text',
          'field_label' => $p_arr[$f_key],
          'translatable' => 1
        ))->execute();
      }
    }

    if (module_exists('field_collection')) {
      globallink_insert_fc_fields($content_type);
    }
  }
  else {
      $sum_field = '';
      if (strpos($field_name, '@summary') !== false) {
          $sum_field = $field_name;
      }
    if ($field_name != 'title' && $field_name != 'metatags' && empty($sum_field)) {
      $field = field_info_field($field_name);

      switch ($field['type']) {
        case 'list_boolean':
        case 'file':
	case 'entityreference':
        case 'taxonomy_term_reference':
          break;
        case 'field_collection':
          globallink_insert_fc('node', $field_name, $content_type, $content_type);

          break;
        default:
          db_insert('globallink_field_config')
          ->fields(array(
            'content_type' => $content_type,
            'entity_type' => $entity_type,
            'bundle' => $content_type,
            'field_name' => $field_name,
            'field_type' => $field['type'],
            'field_label' => $p_arr[$field_name],
            'translatable' => 1,
          ))->execute();
      }
    }
    else {
      db_insert('globallink_field_config')
      ->fields(array('content_type' => $content_type,
        'entity_type' => $entity_type,
        'bundle' => $content_type,
        'field_name' => $field_name,
        'field_type' => 'text',
        'field_label' => $p_arr[$field_name],
        'translatable' => 1,
      ))->execute();
    }
  }
}

/**
 * Inserts field collection fields.
 *
 * @param string $node_type
 *   The node type.
 */
function globallink_insert_fc_fields($node_type) {
  $entity_type = 'node';
  $bean_type = $node_type;
  if (strpos($node_type, 'bean:') !== false) {
    $bean_type = str_replace('bean:', '', $node_type);
    $entity_type = 'bean';
  }
  $field_arr = field_info_instances($entity_type, $bean_type);

  $keys = array_keys($field_arr);

  foreach ($keys as $field_name) {
    $field_info = field_info_field($field_name);

    if ($field_info['type'] != 'field_collection') {
      continue;
    }

    db_insert('globallink_field_config')
    ->fields(array(
      'content_type' => $node_type,
      'entity_type' => $entity_type,
      'bundle' => $node_type,
      'field_name' => $field_name,
      'field_type' => $field_info['type'],
      'field_label' => $field_arr[$field_name]['label'],
      'translatable' => 0,
    ))->execute();

    $fc_field_infos = field_info_instances('field_collection_item');

    if (isset($fc_field_infos) && isset($fc_field_infos[$field_name]) && is_array($fc_field_infos[$field_name])) {
      $fc_items = array_keys($fc_field_infos[$field_name]);

      foreach ($fc_items as $fc_item) {
          if (globallink_is_field_configured_for_translation('field_collection_item', $field_name, $fc_item, $node_type)) {
              continue;
          }
        globallink_insert_fc_item_fields($node_type, $field_name, $fc_item);
      }
    }
  }
}

/**
 * Inserts field collection item fields.
 *
 * @param string $content_type
 *   The content type.
 * @param string $parent_field_name
 *   The parent's field name.
 * @param string $field_name
 *   The field name.
 */
function globallink_insert_fc_item_fields($content_type, $parent_field_name, $field_name) {
  $fc_field_info = field_info_field($field_name);
  $fc_field_instance = field_info_instance('field_collection_item', $field_name, $parent_field_name);

  switch ($fc_field_info['type']) {
    case 'list_boolean':
    case 'file':
    case 'taxonomy_term_reference':
      break;
    case 'field_collection':
      db_insert('globallink_field_config')
      ->fields(array(
        'content_type' => $content_type,
        'entity_type' => 'field_collection_item',
        'bundle' => $parent_field_name,
        'field_name' => $field_name,
        'field_type' => $fc_field_info['type'],
        'field_label' => $fc_field_instance['label'],
        'translatable' => 0,
      ))->execute();

      $fc_field_infos = field_info_instances('field_collection_item');

      if (isset($fc_field_infos) && isset($fc_field_infos[$field_name]) && is_array($fc_field_infos[$field_name])) {
        $fc_items = array_keys($fc_field_infos[$field_name]);

        foreach ($fc_items as $fc_item) {
          globallink_insert_fc_item_fields($content_type, $field_name, $fc_item);
        }
      }

      break;
    default:
      $translatable = 1;

      db_insert('globallink_field_config')
      ->fields(array(
        'content_type' => $content_type,
        'entity_type' => 'field_collection_item',
        'bundle' => $parent_field_name,
        'field_name' => $field_name,
        'field_type' => $fc_field_info['type'],
        'field_label' => $fc_field_instance['label'],
        'translatable' => $translatable,
      ))->execute();
  }
}
