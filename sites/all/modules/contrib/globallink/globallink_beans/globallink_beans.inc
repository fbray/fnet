<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 * Sends beans for translation.
 *
 * @param array $bids
 *   The array of beans IDs.
 * @param string $pd4
 *   The project director details.
 * @param string $submission_name
 *   The name of the submission.
 * @param string $due_date
 *   When the translation is due.
 * @param string $project_code
 *   The project's registered code.
 * @param string $source_locale
 *   The locale of the content being translated.
 * @param array $target_locale_arr
 *   Array of desired locales to translate into.
 * @param array $submission_details
 *   Associative array of details about the submission.
 *
 * @return object
 *   GlobalLink object that represents active translation.
 */
function globallink_beans_send_for_translations($bids, $pd4, $submission_name, $due_date, $project_code, $source_locale, $target_locale_arr, $submission_details, $submission_priority) {
  module_load_include('inc', 'globallink', 'gl_ws/gl_ws_send_translations');

  $submitter = $submission_details['submitter'];
  $globallink_arr = array();

  foreach ($bids as $bid) {
    $rows = globallink_beans_get_sent_rows_by_bid($bid);
    $target_arr = $target_locale_arr;

    foreach ($rows as $row) {
      if (array_search($row->target, $target_locale_arr)) {
        unset($target_arr[$row->target]);
      }
    }

    if (empty($target_arr)) {
      continue;
    }

    $xml = globallink_beans_get_xml($bid, $target_arr);
    $name = 'Bean_' . $bid . '.xml';
    watchdog('GlobalLink', 'XML - %xml', array('%xml' => $xml), WATCHDOG_DEBUG);

    $globallink = new GlobalLink();
    $globallink->type = 'bean';
    $globallink->metadata = 'bean';
    $globallink->sourceLocale = $source_locale;
    $globallink->targetLocale = $target_arr;
    $globallink->sourceXML = $xml;
    $globallink->sourceFileName = $name;
    $globallink->submissionName = $submission_name;
    $globallink->submissionPriority = $submission_priority;
    $globallink->dueDate = $due_date;
    $globallink->otherObjectId = $bid;
    $globallink->submissionInstructions = $submission_details['instructions'] . "\nSubmitter: " . $submitter;
    $globallink_arr[] = $globallink;
  }

  if (!empty($globallink_arr)) {
    globallink_send_documents_for_translation_to_pd($globallink_arr, $pd4, $project_code, $submitter);
  }

  return $globallink_arr;
}


/**
 * Gets active beans submission rows by node ID.
 *
 * @param string $bids
 *   The array of beans IDs.
 *
 * @return
 *   Associative array of beans active submission rows.  FALSE if the array is empty.
 */
function globallink_beans_get_active_submission_rows($bid) {
  $query = db_select('globallink_core_beans', 'gcb');
  $query->condition('status', 'Sent for Translations', '=');
  $query->condition('object_id', $bid, '=');
  $query->fields('gcb');

  $results = $query->execute();
  $arr = array();

  foreach ($results as $row) {
    if (array_key_exists($row->object_id, $arr)) {
      array_push($arr[$row->object_id], $row);
    }
    else {
      $arr[$row->object_id] = array($row);
    }
  }

  $final_arr = array();

  foreach ($arr as $bnid => $mlid_arr) {
    $sub_arr = array();

    foreach ($mlid_arr as $r) {
      if (array_key_exists($r->submission, $sub_arr)) {
        array_push($sub_arr[$r->submission], $r->target);
      }
      else {
        $sub_arr[$r->submission] = array($r->target);
      }
    }

    if (count($sub_arr) > 0) {
      $final_arr[$bnid] = $sub_arr;
    }
  }

  if (count($final_arr) > 0) {
    return $final_arr;
  }

  return FALSE;
}

/**
 * Gets sent beans rows by node ID.
 *
 * @param string $bid
 *   The bean ID.
 *
 * @return array
 *   Array of beans rows.
 */
function globallink_beans_get_sent_rows_by_bid($bid) {
  $result = db_select('globallink_core_beans', 'gcb')
  ->fields('gcb')
  ->condition('object_id', $bid, '=')
  ->condition('status', array('Sent for Translations', 'Error'), 'IN')
  ->execute();

  $rows = array();

  foreach ($result as $row) {
    $rows[] = $row;
  }

  return $rows;
}

/**
 * Gets XML data from specific bean.
 *
 * @param string $bid
 *   The bean ID.
 * @param string $target_arr
 *  The array of target locales.
 *
 * @return array
 *   Associative array of bean XML data.
 */
function globallink_beans_get_xml($bid, $target_arr) {
  $dom = new DOMDocument('1.0', 'UTF-8');
  $dom->formatOutput = TRUE;

  $root = $dom->createElement('content');
  $dom->appendChild($root);
  
  $id = $dom->createAttribute('bid');
  $id->value = $bid;
  $root->appendChild($id);

  $beans = entity_load('bean', array($bid));
  $key = key($beans);
  $bean = $beans[$key];
  if (module_exists('metatag')) {
      $lang = entity_language('bean', $bean);
    if (isset($bean->metatags)) {
      if (globallink_is_field_configured_for_translation('bean', 'bean:' . $bean->type, 'metatags', 'bean:' . $bean->type)) {
        if (!empty($bean->metatags[$lang])) {
          $metatags = $bean->metatags[$lang];
          foreach ($metatags as $name => $value) {
            if (isset($value['value'])) {
              globallink_insert_child_element($dom, $root, 'metatag', $value['value'], array('entity_type' => 'bean', 'name' => $name, 'label' => 'Metatag - ' . ucwords($name)));
            }
          }
        }
      }
    }
  }
  $fields = globallink_bean_get_fields($bean->type);
  $configured_fields = globallink_get_configured_fields_for_bean($bean->type);
  foreach ($fields as $field) {
    if (empty($bean->$field)) {
      continue;
    }
    $language = field_language('bean', $bean, $field, NULL);
    $field_values = field_get_items('bean', $bean, $field, $language);
    $field_info = field_info_field($field);
    if ($field_values) {
      $parent_fc = '';

      if ($field_info['type'] == 'field_collection') {
        $parent_fc = $field;
        if (isset($field_values[0]['revision_id'])) {
          $field_collection_item_entity = entity_load('field_collection_item', array($field_values[0]['value']), array(
            'revision_id' => $field_values[0]['revision_id']
          ));
        }
        globallink_beans_traverse_fields_and_field_collections('bean', $bean->type, $parent_fc, $bean->type, $bean->bid, $field_values, $field, $dom, $root, $bean, $target_arr, $language);
        continue;
      }
    }
    if (array_key_exists($field, $configured_fields) && $configured_fields[$field]->translatable == 1) {
    
    if (is_array($field_values) && !empty($field_values)) {
      foreach ($field_values as $delta => $values) {
        if ($field_info['type'] == 'link_field') {
          globallink_insert_child_element($dom, $root, 'field', $values['title'], array('field_name' => $field, 'delta' => $delta, 'langcode' => $language));
        }
        elseif ($field_info['type'] == 'image') {
          if (isset($values['alt'])) {
            globallink_insert_child_element($dom, $root, 'field_image', $values['alt'], array('field_name' => $field, 'type' => 'alt', 'delta' => $delta, 'langcode' => $language));
          }
          if (isset($values['title'])) {
            globallink_insert_child_element($dom, $root, 'field_image', $values['title'], array('field_name' => $field, 'type' => 'title', 'delta' => $delta, 'langcode' => $language));
          }
        }
        elseif (!empty($values['value'])) {
          globallink_insert_child_element($dom, $root, 'field', $values['value'], array('field_name' => $field, 'delta' => $delta, 'langcode' => $language));
        }
      }
    }
    elseif (!empty($field_values) && is_string($field_values)) {
      globallink_insert_child_element($dom, $root, 'field', $field_values, array('field_name' => $field));
    }
   }
  } 
  $xml = $dom->saveXML();
  return $xml;
}

/**
 * Recursively adds fields and field collections to translation XML document.
 *
 * @param string $entity_type
 *   The type of entity.
 * @param string $content_type
 *   The content type.
 * @param string $parent_fc
 *   The parent field collection.
 * @param string $bundle
 *   The field collection bundle.
 * @param string $entity_id
 *   The id of the entity.
 * @param array $items
 *   Array of content.
 * @param string $field
 *   The name of the field.
 * @param array $dom
 *   Array representation of the DOM.
 * @param array $root
 *   The root of the DOM.
 * @param object $source_node
 *   The source node.
 * @param array $target_arr
 *   The target array.
 * @param string $langcode
 *   The language code.  Defaults to LANGUAGE_NONE.
 */
function globallink_beans_traverse_fields_and_field_collections($entity_type, $content_type, $parent_fc, $bundle, $entity_id, $items, $field, $dom, $root, $source_node, $target_arr, $langcode = LANGUAGE_NONE) {
  if (!$items) {
    return;
  }
  $field_def = field_read_field($field);
  $max_length = '0';
  if(isset($field_def['settings']) && isset($field_def['settings']['max_length'])) {
    $max_length = $field_def['settings']['max_length'];
  }

  switch ($field_def['type']) {
    case 'list_boolean':
    case 'file':
    case 'taxonomy_term_reference':
    case 'field_collection':
      if (!module_exists('field_collection')) {
        break;
      }

      // Field Collection field, read the entity id from item and load
      // Entity object and then do recursion for nested field collections.
      foreach ($items as $entity_id_arr) {
        if (!isset($entity_id_arr['value'])) {
          continue;
        }

        $fc_entity_id = $entity_id_arr['value'];
        $field_collection_item_entity_arr = array();

        if (isset($entity_id_arr['revision_id'])) {
          $field_collection_item_entity_arr = entity_load('field_collection_item', array($fc_entity_id), array(
            'revision_id' => $entity_id_arr['revision_id']
          ));
        }
        else {
          $field_collection_item_entity_arr = entity_load('field_collection_item', array($fc_entity_id));
        }
        if (!$field_collection_item_entity_arr || !is_array($field_collection_item_entity_arr) || sizeof($field_collection_item_entity_arr) < 1) {
          continue;
        }

        $field_collection_item_entity = $field_collection_item_entity_arr[$fc_entity_id];
        $field_collection_name = $field_collection_item_entity->field_name;
        $field_collection_item_array = get_object_vars($field_collection_item_entity);

        $arr = array_keys($field_collection_item_array);
        foreach ($arr as $key) {
          // Check if this key exists; If true then read this.
          $fc_field_def = field_read_field($key);
          if ($fc_field_def && !empty($fc_field_def) && isset($fc_field_def['type'])) {
            if ($fc_field_def['type'] != 'list_boolean' && $fc_field_def['type'] != 'file' && $fc_field_def['type'] != 'taxonomy_term_reference') {
              $fc_item = field_get_items('field_collection_item', $field_collection_item_entity, $key);
              if ($fc_item) {
                globallink_beans_traverse_fields_and_field_collections('field_collection_item', $content_type, $parent_fc, $field_collection_name, $fc_entity_id, $fc_item, $key, $dom, $root, $source_node, $target_arr);
              }
            }
          }
        }
      }

      break;
    default:
        if (!globallink_is_field_configured_for_translation($entity_type, $bundle, $field, 'bean:' . $content_type)) {
          break;
        }
        // Regular Text Field, get the content directly from items array
        foreach ($items as $delta => $item) {
          if (isset($item['value']) && is_string($item['value'])) {
            $f_label = field_info_instance($entity_type, $field, $bundle);
            $f_value = $item['value'];
            $f_format = (isset($item['format']) && !is_null($item['format'])) ? $item['format'] : '';
            globallink_insert_child_element($dom, $root, 'field', $f_value, array(
              'entity_type' => $entity_type,
              'content_type' => $content_type,
              'parent_fc' => $parent_fc,
              'bundle' => $bundle,
              'entity_id' => $entity_id,
              'field_name' => $field,
              'label' => $f_label['label'],
              'delta' => $delta,
              'format' => $f_format,
              'langcode' => $langcode,
              'max_length' => $max_length
            ));
            $field_info_all = field_info_field($field);
            $sum_field = '';
            if ($field_info_all['type'] == 'text_with_summary' && globallink_is_field_configured_for_translation($entity_type, $bundle, $field . '@summary', $content_type)) {
               $sum_field = $field . '@summary';
               
            }
            if (isset($item['summary']) && is_string($item['summary']) && !empty($sum_field)) {
                if (globallink_is_field_configured_for_translation($entity_type, $bundle, $field, $content_type)) {
                
                $f_label = $field . ' Summary';
                $f_value = $item['summary'];
                $f_format = (isset($item['format']) && !is_null($item['format'])) ? $item['format'] : '';

            globallink_insert_child_element($dom, $root, 'field', $f_value, array(
              'entity_type' => $entity_type,
              'content_type' => $content_type,
              'parent_fc' => $parent_fc,
              'bundle' => $bundle,
              'entity_id' => $entity_id,
              'field_name' => $sum_field,
              'label' => $f_label,
              'delta' => $delta,
              'format' => $f_format,
              'langcode' => $langcode,
              'max_length' => $max_length
            ));
                }
            }
          }
          elseif ($field_def['type'] == 'link_field' && isset($item['title']) && is_string($item['title'])) {
            $f_label = field_info_instance($entity_type, $field, $bundle);
            $f_value = $item['title'];
            $f_format = (isset($item['format']) && !is_null($item['format'])) ? $item['format'] : '';

            globallink_insert_child_element($dom, $root, 'field', $f_value, array(
              'entity_type' => $entity_type,
              'content_type' => $content_type,
              'parent_fc' => $parent_fc,
              'bundle' => $bundle,
              'entity_id' => $entity_id,
              'field_name' => $field,
              'label' => $f_label['label'],
              'delta' => $delta,
              'format' => $f_format,
              'langcode' => $langcode,
              'max_length' => $max_length
            ));
          }
        }
  }    
}
/**
 * Gets bean fields based on bundle.
 *
 * @param string $bundle
 *   The bundle.
 *
 * @return array
 *   Array of fields.
 */
function globallink_bean_get_fields($bundle) {
  $fields = array();
  $info = entity_get_info('bean');
  foreach ($info['bundles'] as $bundle_name => $bundle_info) {
    if ($bundle_name == $bundle) {
      foreach (field_info_instances('bean', $bundle_name) as $field) {
        $fields[] = $field['field_name'];
      }
    }
  }
  return $fields;
}

function globallink_get_configured_fields_for_bean($bean_type) {
  $result = db_select('globallink_field_config', 'gfc')
            ->fields('gfc')
            ->condition('content_type','bean:' . $bean_type, '=')
            ->condition('entity_type', 'bean', '=')
            ->execute();
  $arr = array();
  foreach ($result as $row) {
    $arr[$row->field_name] = $row;
  }
  return $arr;
}

/**
 * Updates bean's ticket ID.
 *
 * @param array $arr
 *   Array of GlobalLink objects.
 * @param string $project_code
 *   The bean's project code.
 */
function globallink_beans_update_ticket_id($arr, $project_code) {
  foreach ($arr as $globallink) {
    $target_locale_arr = $globallink->targetLocale;
    $type = $globallink->type;

    if ($type != 'bean') {
      continue;
    }
    $bid = $globallink->otherObjectId;
    $bean_arr = entity_load('bean', array($bid));
    $key = key($bean_arr);
    $bean = $bean_arr[$key];

    foreach ($target_locale_arr as $target_locale) {
      $row = globallink_bean_get_row($bid, $globallink->sourceLocale, $target_locale);
      $title = 'Title Not Found';

      if (!empty($bean->title)) {
        $title = $bean->title;
      }
      else {
        if (!empty($bean->admin_title)) {
          $title = $bean->admin_title;
        }
      }

      if ($row) {
        db_update('globallink_core_beans')
        ->fields(array(
          'title' => $title,
          'document_ticket' => $globallink->documentTicket,
          'submission' => $globallink->submissionName,
          'submission_ticket' => $globallink->submissionTicket,
          'status' => 'Sent for Translations',
          'timestamp' => REQUEST_TIME,
          'last_modified' => REQUEST_TIME,
          'project_code' => $project_code,
        ))
        ->condition('rid', $row->rid, '=')
        ->execute();
      }
      else {
        db_insert('globallink_core_beans')
        ->fields(array(
          'object_id' => $bid,
          'title' => $title,
          'source' => $globallink->sourceLocale,
          'target' => $target_locale,
          'document_ticket' => $globallink->documentTicket,
          'submission' => $globallink->submissionName,
          'submission_ticket' => $globallink->submissionTicket,
          'status' => 'Sent for Translations',
          'timestamp' => REQUEST_TIME,
          'last_modified' => REQUEST_TIME,
          'project_code' => $project_code,
        ))
        ->execute();
      }
    }
  }
}

/**
 * Retrieves bean's row by ID.
 *
 * @param string $bid
 *   The bean row ID.
 * @param string $source
 *   The bean source.
 * @param string $target
 *   The bean target.
 *
 * @return
 *   The row if bean exists.  FALSE if not.
 */
function globallink_bean_get_row($bid, $source, $target) {
  $result = db_select('globallink_core_beans', 'gcb')
  ->fields('gcb')
  ->condition('object_id', $bid, '=')
  ->condition('source', $source, '=')
  ->condition('target', $target, '=')
  ->execute();

  foreach ($result as $row) {
    return $row;
  }

  return FALSE;
}

function globallink_get_all_translatable_bean_types_and_names() {
  $entity_info = entity_get_info('bean');
  $arr = array();
  if (isset($entity_info) && isset($entity_info['bundles'])) {
    $bundles = $entity_info['bundles'];
    foreach ($bundles as $key => $bundle) {
      $arr['bean:' . $key] = $bundle['label'];
    }
    asort($arr);
  }
  return $arr;
}

/**
 * Gets beans submission status.
 */
function globallink_beans_get_submission_status() {
  module_load_include('inc', 'globallink', 'globallink_settings');
  module_load_include('inc', 'globallink', 'gl_ws/gl_ws_common');

  $query = db_select('globallink_core_beans', 'gcb');
  $query->fields('gcb', array('submission_ticket'));
  $query->distinct();
  $query->condition('status', 'Sent for Translations', '=');

  $results = $query->execute();

  foreach ($results as $row) {
    if ($row->submission_ticket) {
      try {
        $pd4 = globallink_get_project_director_details();

        $status = globallink_get_status($pd4, $row->submission_ticket);

        if (!$status || $status == 'CANCELLED') {
          globallink_beans_update_submission_status($row->submission_ticket);
        }
      }
      catch (SoapFault $se) {
        globallink_beans_update_submission_status($row->submission_ticket);
      }
      catch (Exception $ex) {
        globallink_beans_update_submission_status($row->submission_ticket);
      }
    }
  }
}

/**
 * Updates beans submission status.
 *
 * @param string $submission_ticket
 *   The submission ticket.
 * @param string $status
 *   The submission status.  Defaults to 'Cancelled.'
 */
function globallink_beans_update_submission_status($submission_ticket, $status = 'Cancelled') {
  db_update('globallink_core_beans')
  ->fields(array(
    'status' => $status,
    'timestamp' => REQUEST_TIME,
  ))
  ->condition('submission_ticket', $submission_ticket, '=')
  ->execute();
}

/**
 * Cancels beans submission.
 *
 * @param string $selected_submission
 *   The name of the submission.
 */
function globallink_beans_cancel_submission($selected_submission) {
  $pd4 = globallink_get_project_director_details();
  $globallink = new GlobalLink();
  $submission_name = globallink_beans_get_submission_name($selected_submission);
  $globallink->submissionName = $submission_name;
  $globallink->submissionTicket = $selected_submission;

  globallink_cancel_pd_submission($pd4, $globallink);
  globallink_beans_update_submission($globallink);
}

/**
 * Gets beans submission name.
 *
 * @param string $submission_ticket
 *   The submission ticket.
 *
 * @return string
 *   The beans submission name.
 */
function globallink_beans_get_submission_name($submission_ticket) {
  $query = db_select('globallink_core_beans', 'gcb');
  $query->fields('gcb');
  $query->condition('submission_ticket', $submission_ticket, '=');
  $results = $query->execute();

  foreach ($results as $row) {
    if ($row->submission != '') {
      return $row->submission;
    }
  }
}

/**
 * Updates beans submission.
 *
 * @param object $globallink
 *   GlobalLink object.
 */
function globallink_beans_update_submission(&$globallink) {
  db_update('globallink_core_beans')
  ->fields(array(
    'status' => 'Cancelled',
    'timestamp' => REQUEST_TIME,
  ))
  ->condition('submission_ticket', $globallink->submissionTicket, '=')
  ->condition('submission', $globallink->submissionName, '=')
  ->execute();
}

/**
 * Gets active beans submission names.
 *
 * @return array
 *   Array of active beans submission names.
 */
function globallink_beans_get_active_submission_names() {
  $query = db_select('globallink_core_beans', 'gcb');
  $query->condition('status', array('Sent for Translations', 'Error'), 'IN');
  $query->distinct();
  $query->fields('gcb');

  $results = $query->execute();
  $arr = array('' => '-- Select a Submission --');

  foreach ($results as $row) {
    $arr[$row->submission_ticket] = $row->submission;
  }

  return $arr;
}

/**
 * Checks bean status based on row IDs.
 *
 * @param array $rids_arr
 *   Array of row IDs.
 *
 * @return array
 *   Array of row IDs that have been sent for translation or threw an error.
 */
function globallink_beans_check_status($ids_arr) {
  $status = TRUE;

  $query = db_select('globallink_core_beans', 'gcb')
  ->fields('gcb', array('rid'))
  ->condition('status', array('Sent for Translations', 'Error'), 'IN');

  $results = $query->execute();
  $rows = array();

  foreach ($results as $item) {
    $rows[$item->rid] = $item->rid;
  }

  foreach ($ids_arr as $val) {
    if (!in_array($val, $rows)) {
      unset($ids_arr[$val]);
      $status = FALSE;
    }
  }

  if (!$status) {
    drupal_set_message(t('Cannot cancel documents that have been cancelled in Globallink.'), 'warning', NULL);
  }

  return $ids_arr;
}

/**
 * Cancels beans records.
 *
 * @param array $rowids
 *   Array of beans IDs.
 * @param string $pd4
 *   The project director details.
 */
function globallink_beans_cancel_records($rowids, $pd4) {
  $globallink_arr = array();

  foreach ($rowids as $rid) {
    $row = globallink_beans_get_row_by_id($rid);
    $globallink = new GlobalLink();
    $globallink->tptRowId = $row->rid;
    $globallink->targetLocale = $row->target;
    $globallink->documentTicket = $row->document_ticket;
    $globallink->submissionTicket = $row->submission_ticket;
    $globallink_arr[$rid] = $globallink;
  }

  globallink_cancel_select_documents($pd4, $globallink_arr);
  globallink_beans_update_row_document($globallink_arr);
}

/**
 * Updates beans rows to reflect translation status.
 *
 * @param array $globallink_arr
 *   Array of GlobalLink objects.
 */
function globallink_beans_update_row_document(&$globallink_arr) {
  foreach ($globallink_arr as $globallink) {
    if ($globallink->cancelled) {
      db_update('globallink_core_beans')
      ->fields(array(
        'status' => 'Pending Translations',
        'timestamp' => REQUEST_TIME,
      ))
      ->condition('rid', $globallink->tptRowId, '=')
      ->execute();
    }
  }
}

/**
 * Gets bean row by id.
 *
 * @param string $id
 *   The bean row ID.
 *
 * @return
 *   The bean row.  FALSE if row doesn't exist.
 */
function globallink_beans_get_row_by_id($id) {
  $result = db_select('globallink_core_beans', 'gcb')
  ->fields('gcb')
  ->condition('rid', $id, '=')
  ->execute();

  foreach ($result as $row) {
    return $row;
  }

  return FALSE;
}

/**
 * Clears cancelled beans documents.
 *
 * @return int
 *   Number of cancelled beans documents.
 */
function globallink_beans_clear_cancelled_documents() {
  $count = 0;

  $query = db_select('globallink_core_beans', 'gcb')
  ->fields('gcb', array('submission_ticket'))
  ->distinct()
  ->condition('status', 'Cancelled', '=');

  $results = $query->execute();

  foreach ($results as $item) {
    globallink_beans_update_submission_status($item->submission_ticket, 'Pending Translations');

    $count++;
  }

  return $count;
}

/**
 * Gets distinct active beans submission names.
 *
 * @return array
 *   Array of distinct active beans submission names.
 */
function globallink_beans_get_distinct_active_submission_names() {
  $query = db_select('globallink_core_beans', 'gcb');
  $query->condition('status', array('Sent for Translations', 'Error'), 'IN');
  $query->distinct();
  $query->fields('gcb');

  $results = $query->execute();
  $arr = array('[any]' => t('Any'));

  foreach ($results as $row) {
    $arr[$row->submission] = $row->submission;
  }

  return $arr;
}

/**
 * Gets sent beans row that matches criteria.
 *
 * @param string $submission_ticket
 *   The submission ticket.
 * @param string $document_ticket
 *   The document ticket.
 * @param string $target_locale
 *   The target locale.
 *
 * @return
 *   Beans object that matches criteria.  FALSE if none exists.
 */
function globallink_beans_get_sent_tpt_rows($submission_ticket, $document_ticket, $target_locale) {
  $query = db_select('globallink_core_beans', 'gcb');
  $query->condition('submission_ticket', $submission_ticket, '=');
  $query->condition('document_ticket', $document_ticket, '=');
  $query->condition('target', $target_locale, '=');
  $query->fields('gcb');

  $results = $query->execute();

  foreach ($results as $row) {
    return $row;
  }

  return FALSE;
}

/**
 * Gets bean translation status.
 *
 * @param string $bnid
 *   The bean ID.
 * @param string $tgt_locale
 *   The target locale.
 * @param string $title
 *   The translation title.
 *
 * @return string
 *   Status message.
 */
function globallink_beans_get_translation_status($bnid, $tgt_locale, &$title) {
  $query = db_select('globallink_core_beans', 'gcb');
  $query->condition('object_id', $bnid, '=');
  $query->condition('target', $tgt_locale, '=');
  $query->distinct();
  $query->fields('gcb');

  $results = $query->execute();

  foreach ($results as $row) {
    $title = $row->title;
    $entity_arr = entity_load('bean', array($bnid));
    $key = key($entity_arr);
    $entity = $entity_arr[$key];

    if (empty($entity)) {
      return 'Source Deleted';
    }
    elseif ($row->status == 'Sent for Translations') {
      return 'Translation Completed';
    }
    elseif ($row->status == 'Error') {
      return 'Error';
    }
  }

  return 'Sent for Translations';
}

/**
 * Gets beans row ID from submission details.
 *
 * @param string $submission_ticket
 *   The submission ticket.
 * @param string $document_ticket
 *   The document ticket.
 * @param string $target_locale
 *   The target locale.
 *
 * @return
 *   The beans row ID.  FALSE if the row doesn't exist.
 */
function globallink_beans_get_row_id_from_submission($submission_ticket, $document_ticket, $target_locale) {
  $query = db_select('globallink_core_beans', 'gcb');
  $query->condition('submission_ticket', $submission_ticket, '=');
  $query->condition('document_ticket', $document_ticket, '=');
  $query->condition('target', $target_locale, '=');
  $query->fields('gcb');

  $results = $query->execute();

  foreach ($results as $row) {
    return $row->rid;
  }

  return FALSE;
}

/**
 * Gets number of translated beans.
 *
 * @param string $pd4
 *   The project director details.
 * @param array $globallink_arr
 *   Array of GlobalLink objects.
 *
 * @return int
 *   The number of translated beans.
 */
function globallink_beans_get_translated($pd4, &$globallink_arr) {
  module_load_include('inc', 'globallink', 'globallink');

  $count = 0;

  foreach ($globallink_arr as $globallink) {
    $target_xml = globallink_download_target_resource($pd4, $globallink->targetTicket);
    if ($globallink->sourceDeleted || empty($target_xml)) {
      continue;
    }

    $count++;
    $target_locale = globallink_get_drupal_locale_code($globallink->targetLocale);
    $source_locale = globallink_get_drupal_locale_code($globallink->sourceLocale);

    $translated_arr = globallink_beans_get_translated_array($target_xml);
    try {
      $bnid = $translated_arr['object_id'];
      unset($translated_arr['object_id']);
      $entity_arr = entity_load('bean', array($bnid));
      $key = key($entity_arr);
      $entity = $entity_arr[$key];

      if (empty($entity)) {
        globallink_beans_update_status($globallink, 'Source Deleted');

        continue;
      }

      if (module_exists('metatag')) {
      if (isset($translated_arr['metatag'])) {
        $lang = entity_language('bean', $entity);
        $target_metatag_arr = $translated_arr['metatag'];
        if (!empty($entity->metatags[$lang])) {
          $metatags_names = array_keys($entity->metatags[$lang]);
          $n_metatag = &$entity->metatags;

          foreach ($metatags_names as $name) {
            if (isset($target_metatag_arr[$name]) && isset($target_metatag_arr[$name][0])) {
              $gl_obj = $target_metatag_arr[$name]['0'];

              if (is_object($gl_obj)) {
                $translated_content = $gl_obj->translatedContent;
              }
              else {
                $translated_content = $gl_obj;
              }

              $n_metatag[$target_locale][$name] = array('value' => $translated_content);
            }
          }
        }
      }
    }
    
      $fields = globallink_bean_get_fields($entity->type);
      foreach ($fields as $field) {
        $field_def = field_read_field($field);
        $t_field_lang = LANGUAGE_NONE;
        if (empty($translated_arr[$field])) {
          if (isset($entity->{$field}[$source_locale])) {
            $entity->{$field}[$target_locale] = $entity->{$field}[$source_locale];
          }
          continue;
        }
        if (key($translated_arr[$field]) != LANGUAGE_NONE) {
          $t_field_lang = key($translated_arr[$field]);
        }
        if ($field_def['type'] == 'image') {
          if (!isset($entity->{$field}[$target_locale])) {
            $entity->{$field}[$target_locale] = $entity->{$field}[$source_locale];
          }
        }
        if (empty($entity->{$field}[$target_locale]) && $target_locale != LANGUAGE_NONE) {
          $entity->{$field}[$target_locale] = $entity->{$field}[$t_field_lang];
        }
        $t_field_arr = $translated_arr[$field][$source_locale];
        foreach ($entity->{$field}[$target_locale] as $delta => $fp_field) {
          if (empty($t_field_arr[$delta])) {
            continue;
          }
    
          if (isset($t_field_arr[$delta]->translatedContent)) {
            $translation = $t_field_arr[$delta]->translatedContent;
          }
          if ($field_def['type'] == 'link_field') {
            $entity->{$field}[$target_locale][$delta]['title'] = $translation;
          }
          elseif ($field_def['type'] == 'image') {
            if (isset($t_field_arr[$delta]->alt)) {
              $entity->{$field}[$target_locale][$delta]['alt'] = $t_field_arr[$delta]->alt;
            }
            if (isset($t_field_arr[$delta]->title)) {
              $entity->{$field}[$target_locale][$delta]['title'] = $t_field_arr[$delta]->title;
            }
          }
          else {
            $entity->{$field}[$target_locale][$delta]['value'] = $translation;
          }
        }
      }
      $entity->revision = 1;
      $entity->translations->data[$target_locale] = array(
        'language' => $target_locale, // Target language
        'source' => $source_locale, // Source language
        'uid' => $entity->uid,
        'status' => variable_get('globallink_publish_node', 0), // publish translation
        'translate' => 0, // Translation out of date
        'created' => $entity->created,
      );

      $entity->translations->hook[$target_locale] = array(
        'hook' => 'insert',
        'date' => NULL,
      );

      $result = bean_save($entity);
      if ($result != FALSE) {
        if (module_exists('field_collection') && isset($translated_arr['field_collection'])) {
          globallink_beans_save_field_collections($entity, $translated_arr, $target_locale);
        }
      }
      globallink_beans_update_status($globallink);
      globallink_send_download_confirmation($globallink->targetTicket, $pd4);
    }
    catch (SoapFault $se) {
      $count--;

      globallink_beans_update_status($globallink, 'Error');
      watchdog('GlobalLink', 'SOAP Exception - %function - Code[%faultcode], Message[%faultstring]', array('%function' => __FUNCTION__, '%faultcode' => $se->faultcode, '%faultstring' => $se->faultstring), WATCHDOG_ERROR);
      form_set_error('', t('Web Services Error: @faultcode - @faultstring', array('@faultcode' => $se->faultcode, '@faultstring' => $se->faultstring)));
    }
    catch (Exception $e) {
      $count--;

      globallink_beans_update_status($globallink, 'Error');
      watchdog('GlobalLink', 'Exception - %function - File[%file], Line[%line], Code[%code], Message[%message]', array('%function' => __FUNCTION__, '%file' => $e->getFile(), '%line' => $e->getLine(), '%code' => $e->getCode(), '%message' => $e->getMessage()), WATCHDOG_ERROR);
      form_set_error('', t('Error: @message', array('@message' => $e->getMessage())));
    }
  }

  return $count;
}

function globallink_beans_save_field_collections($entity, $translated_arr, $target_locale) {
  $field_arr = field_info_instances('bean', $entity->type);
  $keys = array_keys($field_arr);
  foreach ($keys as $field) {
    $language = field_language('bean', $entity, $field, NULL);
    $field_values = field_get_items('bean', $entity, $field, $language);
    if (isset($translated_arr['field_collection'][$field])) {
      foreach ($field_values as $entity_id_arr) {
        if (isset($entity_id_arr['value'])) {
          $fc_entity_id = $entity_id_arr['value'];
          globallink_beans_save_field_collections_recursively('bean', $entity, $fc_entity_id, $translated_arr['field_collection'][$field], $target_locale);
        }
      }
    }
  }
}

/**
 * Saves field collections recursively.
 *
 * @param string $entity_type
 *   The type of entity.
 * @param string $host_entity
 *   The host entity.
 * @param string $fc_entity_id
 *   The id of the field collection.
 * @param array $translated_fc_arr
 *   The array of translated field collections.
 */
function globallink_beans_save_field_collections_recursively($entity_type, $host_entity, $fc_entity_id, $translated_fc_arr, $target_locale) {
  $field_collection_item_entity = entity_load_unchanged('field_collection_item', $fc_entity_id);
  if (!$field_collection_item_entity) {
    return;
  }

  $field_collection_name = $field_collection_item_entity->field_name;

  $field_collection_item_array = get_object_vars($field_collection_item_entity);

  $arr = array_keys($field_collection_item_array);
  $new_field_collection_arr = array('field_name' => $field_collection_name);
  foreach ($arr as $key) {
    // Check if this key exists; If true then read this.
    $fc_field_def = field_read_field($key);

    if (!$fc_field_def || empty($fc_field_def) || !isset($fc_field_def['type'])) {
      continue;
    }
    switch ($fc_field_def['type']) {
      case 'list_boolean':
      case 'file':
      case 'taxonomy_term_reference':
        continue 2;
      case 'field_collection':
        $lang = key($field_collection_item_array[$key]);
        if (isset($field_collection_item_array[$key]) && isset($field_collection_item_array[$key][$lang])) {
          $field_data_arr = $field_collection_item_array[$key][$lang];
          $new_field_collection_arr[$key][$target_locale] = $field_data_arr;
        }
        break;
      default:
        $lang = key($field_collection_item_array[$key]);
        if (!isset($field_collection_item_array[$key]) || !isset($field_collection_item_array[$key][$lang])) {
          continue 2;
        }
        $field_data_arr = $field_collection_item_array[$key][$lang];
        foreach ($field_data_arr as $delta => $field_data) {
          if (isset($translated_fc_arr[$field_collection_name][$fc_entity_id][$key][LANGUAGE_NONE][$delta])) {
            $gl_obj = $translated_fc_arr[$field_collection_name][$fc_entity_id][$key][LANGUAGE_NONE][$delta];
            if (is_object($gl_obj)) {
              $translated_content = $gl_obj->translatedContent;
            }
            else {
              $translated_content = $gl_obj;
            }

            if (isset($field_data['format'])) {
              $format = $field_data['format'];

              $new_field_collection_arr[$key][$target_locale][$delta] = array(
                'value' => $translated_content,
                'format' => $format
              );
            }
            else {
              $new_field_collection_arr[$key][$target_locale][$delta] = array(
                'value' => $translated_content
              );
            }
          }
          else {
            $new_field_collection_arr[$key][$target_locale][$delta] = $field_data;
          }
        }
    }
  }
  if ($entity_type != 'node') {
    $host_entity->tpt_skip = TRUE;
  }
  $field_collection_item = entity_create('field_collection_item', $new_field_collection_arr); // Create new field collection item.
  $field_collection_item->setHostEntity($entity_type, $host_entity, $target_locale); // Attach it to the bean.
  $field_collection_item->save(TRUE); // Save field-collection item.
  $host_entity->{$new_field_collection_arr['field_name']}[$target_locale][0] = array(
    'value' => $field_collection_item->item_id,
    'revision_id' => $field_collection_item->revision_id,
  );
  
  $host_entity->save();
  field_attach_presave($entity_type, $host_entity);
  field_attach_update($entity_type, $host_entity);

  // Now set the child FC if any
  foreach ($arr as $key) {
    // Check if this key exists; if true then read this.
    $fc_field_def = field_read_field($key);

    if ($fc_field_def && !empty($fc_field_def) && isset($fc_field_def['type'])) {
      if ($fc_field_def['type'] == 'field_collection') {
        $items = field_get_items('field_collection_item', $field_collection_item_entity, $key);

        if ($items) {
          foreach ($items as $entity_id_arr) {
            if (isset($entity_id_arr['value'])) {
              $fc_entity_id = $entity_id_arr['value'];

              globallink_beans_save_field_collections_recursively('field_collection_item', $field_collection_item, $fc_entity_id, $translated_fc_arr, $target_locale);
            }
          }
        }
      }
    }
  }
}

/**
 * Gets array of translated beans.
 *
 * @param object $xml
 *   XML representation of beans.
 *
 * @return array
 *   Associative array of translated beans.
 */
function globallink_beans_get_translated_array($xml) {
  if (is_null($xml) || !is_string($xml) || $xml == '') {
    return array();
  }

  $dom = new DomDocument;
  $dom->preserveWhiteSpace = FALSE;
  $dom->loadXML($xml);
  $arr = array();

  $titles = $dom->getElementsByTagName('title');

  foreach ($titles as $title) {
    $arr['title'] = $title->nodeValue;
  }

  $contents = $dom->getElementsByTagName('content');

  $bnid = '';

  foreach ($contents as $content) {
    if (!is_null($content->attributes)) {
      foreach ($content->attributes as $attr_name => $attr_node) {
        if ($attr_name == 'bid') {
          $bnid = $attr_node->value;
        }
      }
    }
  }

  if ($bnid == '') {
    return array();
  }

  $arr['object_id'] = $bnid;

 
  $field_image = $dom->getElementsByTagName('field_image');
  foreach ($field_image as $attr) {
    $field_image_object = new GLFieldImage();
    if (!is_null($attr->attributes)) {
      foreach ($attr->attributes as $attr_name => $attr_node) {
        switch ($attr_name) {
          case 'type':
            if ($attr_node->value == 'title') {
              $field_image_object->title = $attr->nodeValue;
            }
            elseif ($attr_node->value == 'alt') {
              $field_image_object->alt = $attr->nodeValue;
            }
            continue 2;
          case 'delta':
            $field_image_object->delta = $attr_node->value;
            continue 2;
          case 'field_name':
            $field_image_object->field_name = $attr_node->value;
            continue 2;
          case 'subfield':
            $field_image_object->subfield = $attr_node->value;
            $field_image_object->{$field_image_object->subfield} = $attr->nodeValue;
            $field_image_object->type = 'file_entity';
            continue 2;
          case 'langcode':
            $field_image_object->langcode = $attr_node->value;
          case 'label':
          case 'subfield_label':
            $field_image_object->{$attr_name} = $attr_node->value;
            continue 2;
        }
      }
      if (is_null($field_image_object->delta)) {
        $field_image_object->delta = '0';
      }
      if (isset($field_image_object->field_name)) {
        if(!isset($arr[$field_image_object->field_name][$field_image_object->langcode][$field_image_object->delta])) $arr[$field_image_object->field_name][$field_image_object->langcode][$field_image_object->delta] = new GLFieldImage();  
        if (isset($field_image_object->title)) {
          $arr[$field_image_object->field_name][$field_image_object->langcode][$field_image_object->delta]->title = $field_image_object->title;
        }
        if (isset($field_image_object->alt)) {
          $arr[$field_image_object->field_name][$field_image_object->langcode][$field_image_object->delta]->alt = $field_image_object->alt;
        }
      }
      else {
        $arr[$field_image_object->field_name][$field_image_object->langcode][$field_image_object->delta] = $field_image_object;
      }
    }
  }

  $fields = $dom->getElementsByTagName('field');
  foreach ($fields as $field) {
    $field_obj = new GLField();
    $field_obj->type = 'field';
    $field_obj->translatedContent = $field->nodeValue;

    if (is_null($field->attributes)) {
      continue;
    }
    foreach ($field->attributes as $attr_name => $attr_node) {
      switch ($attr_name) {
        case 'field_name':
          $field_obj->fieldName = $attr_node->value;
          continue 2;
        case 'delta':
          $field_obj->delta = $attr_node->value;
          continue 2;
        case 'langcode':
          $field_obj->langcode = $attr_node->value;
          continue 2;
        case 'parent_fc':
          $field_obj->parentFCName = $attr_node->value;
           continue 2;
        case 'bundle':
          $field_obj->bundle = $attr_node->value;
          continue 2;
        case 'entity_id':
          $field_obj->entityId = $attr_node->value;
          continue 2;
        case 'entity_type':
            $field_obj->entityType = $attr_node->value;
            continue 2;
      }
    }
    if (is_null($field_obj->langcode)) {
      $field_obj->langcode = LANGUAGE_NONE;
    }

    if (is_null($field_obj->delta)) {
      $field_obj->delta = '0';
    }
    if ($field_obj->entityType == 'field_collection_item'){
      $arr['field_collection'][$field_obj->parentFCName][$field_obj->bundle][$field_obj->entityId][$field_obj->fieldName][$field_obj->langcode][$field_obj->delta] = $field_obj;
    }
    else{
      $arr[$field_obj->fieldName][$field_obj->langcode][$field_obj->delta] = $field_obj;
    }
  }
  $metatags = $dom->getElementsByTagName('metatag');
  foreach ($metatags as $metatag) {
    $metatag_obj = new GLField();
    $metatag_obj->type = 'metatag';
    $metatag_obj->translatedContent = $metatag->nodeValue;

    if (is_null($metatag->attributes)) {
      continue;
    }
    foreach ($metatag->attributes as $attr_name => $attr_node) {
      switch ($attr_name) {
        case 'entity_type':
          $metatag_obj->entityType = $attr_node->value;

          continue 2;
        case 'content_type':
          $field_obj->contentType = $attr_node->value;

          continue 2;
        case 'bundle':
          $field_obj->bundle = $attr_node->value;

          continue 2;
        case 'entity_id':
          $metatag_obj->entityId = $attr_node->value;

          continue 2;
        case 'name':
          $metatag_obj->fieldName = $attr_node->value;

          continue 2;
        case 'label':
          $metatag_obj->fieldLabel = $attr_node->value;

          continue 2;
      }
    }

    if (is_null($metatag_obj->entityId)) {
      $metatag_obj->entityId = '0';
    }

    if (is_null($metatag_obj->bundle)) {
      $metatag_obj->bundle = $metatag_obj->fieldName;
    }

    $arr['metatag'][$metatag_obj->bundle][$metatag_obj->entityId] = $metatag_obj;
  }
  return $arr;
}

/**
 * Updates beans status.
 *
 * @param object $globallink
 *   GlobalLink object.
 * @param string $status
 *   The new status.  Defaults to 'Pending Translations.'
 */
function globallink_beans_update_status(&$globallink, $status = 'Pending Translations') {
  db_update('globallink_core_beans')
  ->fields(array(
    'status' => $status,
    'timestamp' => REQUEST_TIME,
  ))
  ->condition('submission', $globallink->submissionName, '=')
  ->condition('document_ticket', $globallink->documentTicket, '=')
  ->condition('source', $globallink->sourceLocale, '=')
  ->condition('target', $globallink->targetLocale, '=')
  ->execute();
}

/**
 * Updates status for deleted beans.
 *
 * @param string $pd4
 *   The project director details.
 * @param object $globallink
 *   GlobalLink object.
 *
 * @return bool
 *   TRUE if update was successful, FALSE on error.
 */
function globallink_beans_update_deleted_records($pd4, $globallink) {
  try {
    $globallink->status = 'Source Deleted';

    globallink_send_download_confirmation($globallink->targetTicket, $pd4);
    globallink_beans_update_status($globallink, 'Source Deleted');
  }
  catch (SoapFault $se) {
    watchdog('GlobalLink', 'SOAP Exception - %function - Code[%faultcode], Message[%faultstring]', array('%function' => __FUNCTION__, '%faultcode' => $se->faultcode, '%faultstring' => $se->faultstring), WATCHDOG_ERROR);
    form_set_error('', t('Web Services Error: @faultcode - @faultstring', array('@faultcode' => $se->faultcode, '@faultstring' => $se->faultstring)));

    return FALSE;
  }
  catch (Exception $e) {
    watchdog('GlobalLink', 'Exception - %function - File[%file], Line[%line], Code[%code], Message[%message]', array('%function' => __FUNCTION__, '%file' => $e->getFile(), '%line' => $e->getLine(), '%code' => $e->getCode(), '%message' => $e->getMessage()), WATCHDOG_ERROR);
    form_set_error('', t('Error: @message', array('@message' => $e->getMessage())));

    return FALSE;
  }

  return TRUE;
}