<?php

/**
 * Sends taxonomies for translation.
 *
 * @param array $lids
 *   The array of taxonomy LIDs.
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
function globallink_taxonomy_send_for_translations($lids, $pd4, $submission_name, $due_date, $project_code, $source_locale, $target_locale_arr, $submission_details, $submission_priority) {
  module_load_include('inc', 'globallink', 'gl_ws/gl_ws_send_translations');
  module_load_include('inc', 'globallink', 'globallink');

  $submitter = $submission_details['submitter'];
  $globallink_arr = array();
  $override_localize = variable_get('globallink_override_localize', 0);
  $vocabs = taxonomy_get_vocabularies();
  foreach ($lids as $lid) {
    $rows = globallink_taxonomy_get_sent_rows_by_bid($lid);
    $target_arr = $target_locale_arr;

    foreach ($rows as $row) {
      if (array_search($row->target, $target_locale_arr)) {
        unset($target_arr[$row->target]);
      }
    }

    if (empty($target_arr)) {
      continue;
    }

    $term = taxonomy_term_load($lid);
    $path = drupal_lookup_path('alias', 'taxonomy/term/' . $lid, globallink_get_drupal_locale_code($source_locale));

    if (empty($term->name)) {
      continue;
    }
    
    $vocab = '';
    if (isset($vocabs[$term->vid])) {
      $vocab = $vocabs[$term->vid];
    }
    else {
      continue;
    }
    
    $entity_version = system_get_info('module', 'entity_translation');
    if ($entity_version['version'] == '7.x-1.0-beta5') {
      if ($vocab->i18n_mode == I18N_MODE_LOCALIZE) {
        if ($override_localize == 1) {
          $xml = globallink_get_taxonomy_xml_for_I18N_MODE_ENTITY_TRANSLATE($term, NULL);
        }
        else {
          $xml = globallink_get_taxonomy_xml_for_I18N_MODE_LOCALIZE($term, $path);
        }
      }
      else if ($vocab->i18n_mode == I18N_MODE_TRANSLATE) {
        $xml = globallink_get_taxonomy_xml_for_I18N_MODE_ENTITY_TRANSLATE($term, NULL);
      }
      else {
        continue;
      }
    }
    else {
      if ($vocab->i18n_mode == I18N_MODE_LOCALIZE) {
        $xml = globallink_get_taxonomy_xml_for_I18N_MODE_LOCALIZE($term, $path);
       }
      else if ($vocab->i18n_mode == I18N_MODE_ENTITY_TRANSLATION) {
        $xml = globallink_get_taxonomy_xml_for_I18N_MODE_ENTITY_TRANSLATE($term, NULL);
      }
      else if ($vocab->i18n_mode == I18N_MODE_TRANSLATE) {
        $xml = globallink_get_taxonomy_xml_for_I18N_MODE_ENTITY_TRANSLATE($term, NULL);
      }
      else {
        continue;
      }
    }

    $name = 'Taxonomy_' . $lid . '.xml';

    $globallink = new GlobalLink();
    $globallink->type = 'taxonomy';
    $globallink->metadata = 'taxonomy';
    $globallink->sourceLocale = $source_locale;
    $globallink->targetLocale = $target_arr;
    $globallink->sourceXML = $xml;
    $globallink->sourceFileName = $name;
    $globallink->submissionName = $submission_name;
    $globallink->submissionPriority = $submission_priority;
    $globallink->dueDate = $due_date;
    $globallink->otherObjectId = $lid;
    $globallink->submissionInstructions = $submission_details['instructions'] . "\nSubmitter: " . $submitter;
    $globallink_arr[] = $globallink;
  }

  if (!empty($globallink_arr)) {
    globallink_send_documents_for_translation_to_pd($globallink_arr, $pd4, $project_code, $submitter);
  }

  return $globallink_arr;
}

function globallink_get_taxonomy_xml_for_I18N_MODE_ENTITY_TRANSLATE($term, $path) {
    $dom = new DOMDocument('1.0', 'UTF-8');
    $dom->formatOutput = TRUE;

    $root = $dom->createElement("content");
    $dom->appendChild($root);

    $id = $dom->createAttribute('bid');
    $id->value = $term->tid;
    $root->appendChild($id);

    if (!empty($path)) {
        globallink_insert_child_element($dom, $root, "taxonomy", $path, array('name' => 'path', 'label' => 'Path'));
    }

    $language = $term->language;
    $fields = get_taxonomy_fields($term->vocabulary_machine_name);
    $configured_fields = get_configured_fields_for_taxonomy($term->vocabulary_machine_name);
    foreach ($fields as $field) {
            if (array_key_exists($field, $configured_fields) && $configured_fields[$field]->translatable == 1) {
                if (!empty($term->$field)) {
                    $field_values = $term->$field;
                    if (is_array($field_values) && !empty($field_values[$language])) {
                        foreach ($field_values[$language] as $delta => $values) {
                            globallink_insert_child_element($dom, $root, 'field', $values['value'], array('field' => $field, 'delta' => $delta, 'langcode' => $language, 'label' => $configured_fields[$field]->field_label));
                        }
                    } elseif (!empty($field_values) && is_string($field_values)) { // Test this without field translation
                        globallink_insert_child_element($dom, $root, 'field', $field_values, array('field' => $field, 'label' => $configured_fields[$field]->field_label));
                    }
                }
            }
    }

    if (array_key_exists('metatags', $configured_fields)) {
        if (isset($term->metatags) && isset($term->metatags[$language])) {
            $mt = $term->metatags[$language];
            if (isset($mt['title']) && isset($mt['title']['value'])) {
                globallink_insert_child_element($dom, $root, 'metatag', $mt['title']['value'], array('field' => 'title', 'delta' => '0', 'langcode' => $language, 'label' => 'MetaTag Title'));
            }
            if (isset($mt['description']) && isset($mt['description']['value'])) {
                globallink_insert_child_element($dom, $root, 'metatag', $mt['description']['value'], array('field' => 'description', 'delta' => '0', 'langcode' => $language, 'label' => 'MetaTag Description'));
            }
            if (isset($mt['abstract']) && isset($mt['abstract']['value'])) {
                globallink_insert_child_element($dom, $root, 'metatag', $mt['abstract']['value'], array('field' => 'abstract', 'delta' => '0', 'langcode' => $language, 'label' => 'MetaTag Abstract'));
            }
            if (isset($mt['keywords']) && isset($mt['keywords']['value'])) {
                globallink_insert_child_element($dom, $root, 'metatag', $mt['keywords']['value'], array('field' => 'keywords', 'delta' => '0', 'langcode' => $language, 'label' => 'MetaTag Keywords'));
            }
        }
    }


    $xml = $dom->saveXML();
    return $xml;
}


/**
 * Gets XML data from specific taxonomy.
 *
 * @param object $term
 *   The taxonomy term.
 * @param string $path
 *   The taxonomy path.
 *
 * @return array
 *   Associative array of block XML data.
 */
function globallink_get_taxonomy_xml_for_I18N_MODE_LOCALIZE($term, $path)  {
  $dom = new DOMDocument('1.0', 'UTF-8');
    $dom->formatOutput = TRUE;

    $root = $dom->createElement("content");
    $dom->appendChild($root);

    $id = $dom->createAttribute('bid');
    $id->value = $term->tid;
    $root->appendChild($id);

    if (!empty($term->name)) {
        globallink_insert_child_element($dom, $root, "taxonomy", $term->name, array('name' => 'name', 'label' => 'Name'));
    }
    if (!empty($term->description)) {
        globallink_insert_child_element($dom, $root, "taxonomy", $term->description, array('name' => 'description', 'label' => 'Description'));
    }
    if (!empty($path)) {
        globallink_insert_child_element($dom, $root, "taxonomy", $path, array('name' => 'path', 'label' => 'Path'));
    }

  $xml = $dom->saveXML();

  return $xml;
}

/**
 * Gets taxonomy strings.
 *
 * @param string $language
 *   The taxonomy language.  Defaults to NULL.
 * @param string $group
 *   The node group.  Defaults to 'taxonomy.'
 *
 * @return array
 *   Array of taxonomy strings
 */
function globallink_taxonomy_get_strings($language = NULL, $group = 'taxonomy') {
  if (isset($language)) {
    $result = db_query('SELECT s.lid, s.source, s.context, s.location, t.plid, t.plural FROM {locales_source} s LEFT JOIN {locales_target} t ON s.lid = t.lid AND t.language = :language WHERE s.textgroup = :textgroup ORDER BY t.plid, t.plural', array(
      ':language' => $language,
      ':textgroup' => $group,
    ));
  }
  else {
    $result = db_query('SELECT s.lid, s.source, s.context, s.location, t.plid, t.plural FROM {locales_source} s LEFT JOIN {locales_target} t ON s.lid = t.lid WHERE s.textgroup = :textgroup ORDER BY t.plid, t.plural', array(
      ':textgroup' => $group,
    ));
  }

  $strings = array();

  foreach ($result as $child) {
    $string = array(
      'lid' => $child->lid,
      'location' => $child->location,
      'source' => $child->source,
      'context' => $child->context,
    );

    $strings[$child->location] = $string;
  }

  return $strings;
}

/**
 * Updates taxonomy ticket ID on GlobalLink.
 *
 * @param array $arr
 *   Array of GlobalLink objects.
 * @param string $project_code
 *   The taxonomy's project code.
 */
function globallink_taxonomy_update_ticket_id($arr, $project_code) {
  foreach ($arr as $globallink) {
    $target_locale_arr = $globallink->targetLocale;
    $type = $globallink->type;

    if ($type != 'taxonomy') {
      continue;
    }

    $bid = $globallink->otherObjectId;
    $taxonomy = taxonomy_term_load($bid);

    foreach ($target_locale_arr as $target_locale) {
      $row = globallink_taxonomy_get_row($bid, $type, $globallink->sourceLocale, $target_locale);

      if ($row) {
        db_update('globallink_core_taxonomy')
        ->fields(array(
          'title' => $taxonomy->name,
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
        db_insert('globallink_core_taxonomy')
        ->fields(array(
          'object_id' => $bid,
          'object_type' => $globallink->type,
          'title' => $taxonomy->name,
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
 * Retrieves taxonomy's row by ID.
 *
 * @param string $object_id
 *   The object ID.
 * @param string $object_type
 *   The object type.
 * @param string $source
 *   The target source.
 * @param string $target
 *   The target.
 *
 * @return
 *   The row if taxonomy exists.
 */
function globallink_taxonomy_get_row($object_id, $object_type, $source, $target) {
  $result = db_select('globallink_core_taxonomy', 'tco')
  ->fields('tco')
  ->condition('object_id', $object_id, '=')
  ->condition('object_type', $object_type, '=')
  ->condition('source', $source, '=')
  ->condition('target', $target, '=')
  ->execute();

  foreach ($result as $row) {
    return $row;
  }

  return FALSE;
}

/**
 * Updates status for deleted taxonomies.
 *
 * @param string $pd4
 *   The project director details.
 * @param object $globallink
 *   GlobalLink object.
 *
 * @return bool
 *   TRUE if update was successful, FALSE on error.
 */
function globallink_taxonomy_update_deleted_records($pd4, $globallink) {
  try {
    $globallink->status = 'Source Deleted';

    globallink_send_download_confirmation($globallink->targetTicket, $pd4);
    globallink_taxonomy_update_status($globallink, 'Source Deleted');
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

/**
 * Gets taxonomy translation status.
 *
 * @param string $bid
 *   The taxonomy object ID.
 * @param string $tgt_locale
 *   The target locale.
 * @param string $title
 *   The translation title.
 *
 * @return string
 *   Status message.
 */
function globallink_taxonomy_get_translation_status($bid, $tgt_locale, &$title) {
  $query = db_select('globallink_core_taxonomy', 'tco');
  $query->condition('object_id', $bid, '=');
  $query->condition('target', $tgt_locale, '=');
  $query->distinct();
  $query->fields('tco');
  $results = $query->execute();

  foreach ($results as $row) {
    $title = $row->title;
    $s_taxonomy = taxonomy_term_load($bid);

    if (!$s_taxonomy || is_null($s_taxonomy)) {
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
 * Gets active taxonomy submission names.
 *
 * @return array
 *   Array of active taxonomy submission names.
 */
function globallink_taxonomy_get_active_submission_names() {
  $query = db_select('globallink_core_taxonomy', 'tco');
  $query->condition('status', array('Sent for Translations', 'Error'), 'IN');
  $query->distinct();
  $query->fields('tco');
  $results = $query->execute();

  $arr = array('' => '-- Select a Submission --');

  foreach ($results as $row) {
    $arr[$row->submission_ticket] = $row->submission;
  }

  return $arr;
}

/**
 * Cancels taxonomy records.
 *
 * @param array $rowids
 *   Array of taxonomy IDs.
 * @param string $pd4
 *   The project director details.
 */
function globallink_taxonomy_cancel_records($rowids, $pd4) {
  $globallink_arr = array();

  foreach ($rowids as $rid) {
    $row = globallink_get_other_row($rid, 'taxonomy');

    $globallink = new GlobalLink();
    $globallink->tptRowId = $row->rid;
    $globallink->targetLocale = $row->target;
    $globallink->documentTicket = $row->document_ticket;
    $globallink->submissionTicket = $row->submission_ticket;
    $globallink_arr[$rid] = $globallink;
  }

  globallink_cancel_select_documents($pd4, $globallink_arr);
  globallink_taxonomy_update_row_document($globallink_arr);
}

/**
 * Updates taxonomy rows to reflect translation status.
 *
 * @param array $globallink_arr
 *   Array of GlobalLink objects.
 */
function globallink_taxonomy_update_row_document(&$globallink_arr) {
  foreach ($globallink_arr as $globallink) {
    if ($globallink->cancelled) {
      db_update('globallink_core_taxonomy')
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
 * Cancels taxonomy submission.
 *
 * @param string $selected_submission
 *   The name of the submission.
 */
function globallink_taxonomy_cancel_submission($selected_submission) {
  $pd4 = globallink_get_project_director_details();

  $globallink = new GlobalLink();

  $submission_name = globallink_taxonomy_get_submission_name($selected_submission);
  $globallink->submissionName = $submission_name;
  $globallink->submissionTicket = $selected_submission;

  globallink_cancel_pd_submission($pd4, $globallink);
  globallink_taxonomy_update_submission($globallink);
}

/**
 * Gets taxonomy submission name.
 *
 * @param string $submission_ticket
 *   The submission ticket.
 *
 * @return string
 *   The taxonomy submission name.
 */
function globallink_taxonomy_get_submission_name($submission_ticket) {
  $query = db_select('globallink_core_taxonomy', 'tc');
  $query->fields('tc');
  $query->condition('submission_ticket', $submission_ticket, '=');
  $results = $query->execute();

  foreach ($results as $row) {
    if ($row->submission != '') {
      return $row->submission;
    }
  }
}

/**
 * Updates taxonomy submission.
 *
 * @param object $globallink
 *   GlobalLink object.
 */
function globallink_taxonomy_update_submission(&$globallink) {
  db_update('globallink_core_taxonomy')
  ->fields(array(
    'status' => 'Cancelled',
    'timestamp' => REQUEST_TIME,
  ))
  ->condition('submission_ticket', $globallink->submissionTicket, '=')
  ->condition('submission', $globallink->submissionName, '=')
  ->execute();
}

/**
 * Gets number of translated taxonomies.
 *
 * @param string $pd4
 *   The project director details.
 * @param array $globallink_arr
 *   Array of GlobalLink objects.
 *
 * @return int
 *   The number of translated taxonomies.
 */
function globallink_taxonomy_get_translated($pd4, &$globallink_arr) {
  module_load_include('inc', 'globallink', 'globallink');
  $count = 0;
  $vocabs = taxonomy_get_vocabularies();
  $override_localize = variable_get('globallink_override_localize', 0);
  $entity_version = system_get_info('module', 'entity_translation');
  
  foreach ($globallink_arr as $globallink) {
    if ($globallink->sourceDeleted) {
      continue;
    }

    $target_xml = globallink_download_target_resource($pd4, $globallink->targetTicket);

    if (!isset($target_xml)) {
      continue;
    }

    $count++;

    $target_locale = globallink_get_drupal_locale_code($globallink->targetLocale);
    $translated_arr = globallink_taxonomy_get_translated_items($target_xml);
    try {
      $bid = $translated_arr['bid'];
      unset($translated_arr['bid']);

      $term = taxonomy_term_load($bid);

      if (empty($term)) {
        continue;
      }
      if (isset($vocabs[$term->vid])) {
        $vocab = $vocabs[$term->vid];
      } 
      else {
        continue;
      }

      if ($vocab->i18n_mode == I18N_MODE_LOCALIZE) {
        if ($override_localize == 1 && $entity_version['version'] == '7.x-1.0-beta5') {
                    // Use i18n fields translation
          $source_locale = $term->language;
          $fields = get_configured_fields_for_taxonomy($vocab->machine_name);
          $field_names = array_keys($fields);

          foreach ($field_names as $fieldName) {
            if ($fieldName == 'metatags') {
              if (empty($translated_arr[$fieldName])) {
                if (isset($term->$fieldName) && isset($term->{$fieldName}[$source_locale])) {
                  $term->{$fieldName}[$target_locale] = $term->{$fieldName}[$source_locale];
                }
                continue;
              }
              foreach ($translated_arr['metatags'] as $metatag) {
                if (key($metatag) !== LANGUAGE_NONE) {
                  $t_field_lang = key($metatag);
                }
                if (empty($term->{$fieldName}[$target_locale]) && $target_locale != LANGUAGE_NONE) {
                  $term->{$fieldName}[$target_locale] = $term->{$fieldName}[$t_field_lang];
                }
                $t_field_arr = $metatag[$source_locale];
                $mt_name = $t_field_arr->fieldName;
                if (empty($t_field_arr->translatedContent)) {
                  continue;
                }
                if (empty($term->{$fieldName}[$target_locale][$mt_name])) {
                  continue;
                }
                $translation = $t_field_arr->translatedContent;
                $term->{$fieldName}[$target_locale][$mt_name]['value'] = $translation;
              }
              continue;
            }
            $t_field_lang = LANGUAGE_NONE;
            if (empty($translated_arr[$fieldName])) {
              if (isset($term->$fieldName) && isset($term->{$fieldName}[$source_locale])) {
                $term->{$fieldName}[$target_locale] = $term->{$fieldName}[$source_locale];
              }
              continue;
            }
            if (key($translated_arr[$fieldName]) !== LANGUAGE_NONE) {
              $t_field_lang = key($translated_arr[$fieldName]);
            }
            if (empty($term->{$fieldName}[$target_locale]) && $target_locale != LANGUAGE_NONE) {
              $term->{$fieldName}[$target_locale] = $term->{$fieldName}[$t_field_lang];
            }
            $t_field_arr = $translated_arr[$fieldName][$source_locale];
            foreach ($term->{$fieldName}[$target_locale] as $delta => $fp_field) {
              if (empty($t_field_arr[$delta])) {
                continue;
              }
              $translation = $t_field_arr[$delta]->translatedContent;
              $term->{$fieldName}[$target_locale][$delta]['value'] = $translation;
            }
          }
          if (!isset($term->translations->data[$target_locale])) {
            $term->translations->data[$target_locale] = array(
              'language' => $target_locale, // Target language
              'source' => $term->language, // Source language
              'uid' => $term->translations->data[$term->language]['uid'],
              'status' => variable_get('globallink_publish_node', 0), // publish translation
              'created' => $term->translations->data[$term->language]['created'],
            );
            $term->translations->hook[$target_locale] = array(
              'hook' => 'insert',
              'date' => NULL,
            );
          }
          else {
            $term->translations->data[$target_locale]['status'] = variable_get('globallink_publish_node', 0); // publish translation
            $term->translations->hook[$target_locale] = array(
              'hook' => 'update',
              'date' => NULL,
            );
          }
        }
        else {
          unset($term->tid);
          $term->language = $target_locale;
          $new_term = taxonomy_term_save($term);
          if ($new_term != 1) {
            form_set_error('', check_plain('Unable to save new term for ' . $bid . ' where language is ' . $target_locale));
            continue;
          }
                    // Use strings for name and description
          foreach ($translated_arr as $attribute => $translations) {
            if ($attribute == 'name') {
              $term->name = $translations['translation'];
            }
            elseif ($attribute == 'description') {
              $term->description = $translations['translation'];
            }
            elseif ($attribute == 'path') {
              $term->path['pathauto'] = FALSE;
              $uri = taxonomy_term_uri($term);
              $new_path = path_load($uri['path']);
              $new_path['alias'] = $translations['translation'];
              path_save($new_path);
            }
          }
        }
      }
      else if (($entity_version['version'] != '7.x-1.0-beta5' && $vocab->i18n_mode == I18N_MODE_ENTITY_TRANSLATION) || ($entity_version['version'] == '7.x-1.0-beta5' && $vocab->i18n_mode == I18N_MODE_TRANSLATE)) {
                        // Use i18n fields translation
        $source_locale = $term->language;
        $fields = get_configured_fields_for_taxonomy($vocab->machine_name);
        $field_names = array_keys($fields);
        foreach ($field_names as $fieldName) {
          if ($fieldName == 'metatags') {
            if (empty($translated_arr[$fieldName])) {
              if (isset($term->$fieldName) && isset($term->{$fieldName}[$source_locale])) {
                $term->{$fieldName}[$target_locale] = $term->{$fieldName}[$source_locale];
              }
              continue;
            }
            foreach ($translated_arr['metatags'] as $metatag) {
              if (key($metatag) !== LANGUAGE_NONE) {
                $t_field_lang = key($metatag);
              }
              if (empty($term->{$fieldName}[$target_locale]) && $target_locale != LANGUAGE_NONE) {
                $term->{$fieldName}[$target_locale] = $term->{$fieldName}[$t_field_lang];
              }
              $t_field_arr = $metatag[$source_locale];
              $mt_name = $t_field_arr->fieldName;
              if (empty($t_field_arr->translatedContent)) {
                continue;
              }
              if (empty($term->{$fieldName}[$target_locale][$mt_name])) {
                continue;
              }
              $translation = $t_field_arr->translatedContent;
              $term->{$fieldName}[$target_locale][$mt_name]['value'] = $translation;
            }
            continue;
          }
          $t_field_lang = LANGUAGE_NONE;
          if (empty($translated_arr[$fieldName])) {
            if (isset($term->$fieldName) && isset($term->{$fieldName}[$source_locale])) {
              $term->{$fieldName}[$target_locale] = $term->{$fieldName}[$source_locale];
            }
            continue;
          }
          if (key($translated_arr[$fieldName]) !== LANGUAGE_NONE) {
            $t_field_lang = key($translated_arr[$fieldName]);
          }
          if (empty($term->{$fieldName}[$target_locale]) && $target_locale != LANGUAGE_NONE) {
            $term->{$fieldName}[$target_locale] = $term->{$fieldName}[$t_field_lang];
          }
          $t_field_arr = $translated_arr[$fieldName][$source_locale];
          foreach ($term->{$fieldName}[$target_locale] as $delta => $fp_field) {
            if (empty($t_field_arr[$delta])) {
              continue;
            }
            $translation = $t_field_arr[$delta]->translatedContent;
            $term->{$fieldName}[$target_locale][$delta]['value'] = $translation;
          }
        }
        if (!isset($term->translations->data[$target_locale])) {
          $term->translations->data[$target_locale] = array(
            'language' => $target_locale, // Target language
            'source' => $term->language, // Source language
            'uid' => $term->translations->data[$term->language]['uid'],
            'status' => variable_get('transperfect_publish_node', 0), // publish translation
            'created' => $term->translations->data[$term->language]['created'],
          );
          $term->translations->hook[$target_locale] = array(
            'hook' => 'insert',
            'date' => NULL,
          );
        }
        else {
          $term->translations->data[$target_locale]['status'] = variable_get('transperfect_publish_node', 0); // publish translation
          $term->translations->hook[$target_locale] = array(
            'hook' => 'update',
            'date' => NULL,
          );
        }
      }
      else if ($vocab->i18n_mode == I18N_MODE_TRANSLATE && $entity_version['version'] != '7.x-1.0-beta5') {
        $vocabulary = $term->vocabulary_machine_name;
        $translation_set = !empty($term->i18n_tsid) ? i18n_translation_set_load($term->i18n_tsid) : NULL;
        if ($translation_set == NULL) {
          $translation_set = i18n_translation_set_create('taxonomy_term', $vocabulary)->add_item($term);
        }
        $tsid = $translation_set->tsid;
        $source_locale = $term->language;
        $term->i18n_tsid = $tsid;
        taxonomy_term_save($term);
        $set = 0;
                      //Added the condition here for loading existing term, so that it gets updated and not recreated.
        $trans_set = $translation_set->load_translations();
        $keys = array_keys($trans_set);
        foreach ($keys as $key) {
          if ($key == $target_locale) {
            $term = taxonomy_term_load($trans_set[$key]->tid);
            $set = 1;
          }
        }
        if ($set != 1) {
          unset($term->tid);
          $term->language = $target_locale;
          $term->i18n_tsid = $tsid;
          $new_term = taxonomy_term_save($term);
          if ($new_term != 1) {
            form_set_error('', check_plain('Unable to save new term for ' . $bid . ' where language is ' . $target_locale));
            continue;
          }
        }
                // Use i18n fields translation
        $fields = get_configured_fields_for_taxonomy($vocab->machine_name);
        $field_names = array_keys($fields);
        $term->i18n_tsid = $tsid;
        foreach ($field_names as $fieldName) {
          if ($fieldName == 'metatags') {
            if (empty($translated_arr[$fieldName])) {
              if (isset($term->$fieldName) && isset($term->{$fieldName}[$source_locale])) {
                $term->{$fieldName}[$target_locale] = $term->{$fieldName}[$source_locale];
              }
              continue;
            }
            foreach ($translated_arr['metatags'] as $metatag) {
              if (key($metatag) !== LANGUAGE_NONE) {
                $t_field_lang = key($metatag);
              }
              if (empty($term->{$fieldName}[$target_locale]) && $target_locale != LANGUAGE_NONE) {
                $term->{$fieldName}[$target_locale] = $term->{$fieldName}[$t_field_lang];
              }
              $t_field_arr = $metatag[$source_locale];
              $mt_name = $t_field_arr->fieldName;
              if (empty($t_field_arr->translatedContent)) {
                continue;
              }
              if (empty($term->{$fieldName}[$target_locale][$mt_name])) {
                continue;
              }
              $translation = $t_field_arr->translatedContent;
              $term->{$fieldName}[$target_locale][$mt_name]['value'] = $translation;
            }
            continue;
          }
          $t_field_lang = LANGUAGE_NONE;
          $t_field_arr = $translated_arr[$fieldName][$source_locale];
          foreach ($term->{$fieldName}[$source_locale] as $delta => $fp_field) {
            if (empty($t_field_arr[$delta])) {
              continue;
            }
            $translation = $t_field_arr[$delta]->translatedContent;
            $term->{$fieldName}[$target_locale][$delta]['value'] = $translation;
            $term->{$fieldName}[$source_locale][$delta]['value'] = $translation;
          }
        }
      }
      else {
        continue;
      }
      taxonomy_term_save($term);
      globallink_taxonomy_update_status($globallink);
      globallink_send_download_confirmation($globallink->targetTicket, $pd4);
    }
    catch (SoapFault $se) {
      $count--;
      globallink_taxonomy_update_status($globallink, 'Error');
      watchdog('GlobalLink', 'SOAP Exception - %function - Code[%faultcode], Message[%faultstring]', array('%function' => __FUNCTION__, '%faultcode' => $se->faultcode, '%faultstring' => $se->faultstring), WATCHDOG_ERROR);
      form_set_error('', t('Web Services Error: @faultcode - @faultstring', array('@faultcode' => $se->faultcode, '@faultstring' => $se->faultstring)));
    }
    catch (Exception $e) {
      $count--;
      globallink_taxonomy_update_status($globallink, 'Error');
      watchdog('GlobalLink', 'Exception - %function - File[%file], Line[%line], Code[%code], Message[%message]', array('%function' => __FUNCTION__, '%file' => $e->getFile(), '%line' => $e->getLine(), '%code' => $e->getCode(), '%message' => $e->getMessage()), WATCHDOG_ERROR);
      form_set_error('', t('Error: @message', array('@message' => $e->getMessage())));
    }
  }
  return $count;
}

/**
 * Gets translated taxonomies from XML data.
 *
 * @param object $xml
 *   XML representation of taxonomies.
 *
 * @return array
 *   Array of taxonomies.
 */
function globallink_taxonomy_get_translated_items($xml) {
  if (is_null($xml) || !is_string($xml) || $xml == '') {
    return array();
  }

  $dom = new DomDocument;
  $dom->preserveWhiteSpace = FALSE;
  $dom->loadXML($xml);

  $contents = $dom->getElementsByTagName('content');

  $bid = '';

  foreach ($contents as $content) {
    if (!is_null($content->attributes)) {
      foreach ($content->attributes as $attr_name => $attr_node) {
        if ($attr_name == 'bid') {
          $bid = $attr_node->value;
        }
      }
    }
  }

  if ($bid == '') {
    return array();
  }

  $taxonomy_arr = array();
  $taxonomy_arr['bid'] = $bid;

  $taxonomies = $dom->getElementsByTagName('taxonomy');

  foreach ($taxonomies as $taxonomy) {
    if (!is_null($taxonomy->attributes)) {
      $b_arr = array();

      foreach ($taxonomy->attributes as $attr_name => $attr_node) {
        $b_arr[$attr_name] = $attr_node->value;
      }

      $b_arr['translation'] = $taxonomy->nodeValue;
      $taxonomy_arr[$b_arr['name']] = $b_arr;
    }
  }

  $fields = $dom->getElementsByTagName('field');
  foreach ($fields as $field) {
    $field_object = new GLField();
    $field_object->type = 'field';
    $field_object->translatedContent = $field->nodeValue;
    if (!is_null($field->attributes)) {
      foreach ($field->attributes as $attr_name => $attr_node) {
        switch ($attr_name) {
          case 'field':
            $field_object->fieldName = $attr_node->value;
            continue 2;
          case 'delta':
            $field_object->delta = $attr_node->value;
            continue 2;
          case 'langcode':
            $field_object->langcode = $attr_node->value;
            continue 2;
        }
      }
      if (is_null($field_object->langcode)) {
        $field_object->langcode = LANGUAGE_NONE;
      }
      if (is_null($field_object->delta)) {
        $field_object->delta = '0';
      }
      $taxonomy_arr[$field_object->fieldName][$field_object->langcode][$field_object->delta] = $field_object;
    }
  }

  $metatags = $dom->getElementsByTagName('metatag');
  foreach ($metatags as $metatag) {
    $metatag_object = new GLField();
    $metatag_object->type = 'metatag';
    $metatag_object->translatedContent = $metatag->nodeValue;
    if (!is_null($metatag->attributes)) {
      foreach ($metatag->attributes as $attr_name => $attr_node) {
        switch ($attr_name) {
          case 'field':
            $metatag_object->fieldName = $attr_node->value;
            continue 2;
          case 'delta':
            $metatag_object->delta = $attr_node->value;
            continue 2;
          case 'langcode':
            $metatag_object->langcode = $attr_node->value;
            continue 2;
          case 'label':
            $metatag_object->fieldLabel = $attr_node->value;
            continue 2;
        }
      }
      if (is_null($metatag_object->delta)) {
        $metatag_object->entityId = '0';
      }
      if (is_null($metatag_object->langcode)) {
        $metatag_object->langcode = LANGUAGE_NONE;
      }
    }
      $taxonomy_arr['metatags'][$metatag_object->fieldName][$metatag_object->langcode] = $metatag_object;
  }

  return $taxonomy_arr;
}

/**
 * Updates taxonomy status.
 *
 * @param object $globallink
 *   GlobalLink object.
 * @param string $status
 *   The new status.  Defaults to 'Pending Translations.'
 */
function globallink_taxonomy_update_status(&$globallink, $status = 'Pending Translations') {
  db_update('globallink_core_taxonomy')
  ->fields(array('status' => $status, 'timestamp' => REQUEST_TIME))
  ->condition('submission', $globallink->submissionName, '=')
  ->condition('document_ticket', $globallink->documentTicket, '=')
  ->condition('source', $globallink->sourceLocale, '=')
  ->condition('target', $globallink->targetLocale, '=')
  ->execute();
}

/**
 * Gets active taxonomy submission rows by object ID.
 *
 * @param string $object_id
 *   The object ID.
 *
 * @return
 *   Associative array of taxonomy active submission rows.  FALSE if the array is empty.
 */
function globallink_taxonomy_get_active_submission_rows($object_id) {
  $query = db_select('globallink_core_taxonomy', 'tc');
  $query->condition('status', 'Sent for Translations', '=');
  $query->condition('object_id', $object_id, '=');
  $query->fields('tc');
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

  foreach ($arr as $bid => $bid_arr) {
    $sub_arr = array();

    foreach ($bid_arr as $r) {
      if (array_key_exists($r->submission, $sub_arr)) {
        array_push($sub_arr[$r->submission], $r->target);
      }
      else {
        $sub_arr[$r->submission] = array($r->target);
      }
    }

    if (count($sub_arr) > 0) {
      $final_arr[$bid] = $sub_arr;
    }
  }

  if (count($final_arr) > 0) {
    return $final_arr;
  }

  return FALSE;
}

/**
 * Gets active taxonomy submission rows by object ID.
 *
 * @param string $bid
 *   The taxonomy object ID.
 *
 * @return
 *   Associative array of taxonomy active submission rows.  FALSE if the array is empty.
 */
function globallink_taxonomy_get_sent_rows_by_bid($bid) {
  $result = db_select('globallink_core_taxonomy', 'tc')
  ->fields('tc')
  ->condition('object_id', $bid, '=')
  ->condition('status', 'Sent for Translations', '=')
  ->execute();

  $rows = array();

  foreach ($result as $row) {
    $rows[] = $row;
  }

  return $rows;
}

/**
 * Gets taxonomy row ID from submission details.
 *
 * @param string $submission_ticket
 *   The submission ticket.
 * @param string $document_ticket
 *   The document ticket.
 * @param string $target_locale
 *   The target locale.
 *
 * @return string
 *   The taxonomy row ID.  FALSE if the row doesn't exist.
 */
function globallink_taxonomy_get_row_id_from_submission($submission_ticket, $document_ticket, $target_locale) {
  $result = db_select('globallink_core_taxonomy', 'tc')
  ->condition('submission_ticket', $submission_ticket, '=')
  ->condition('document_ticket', $document_ticket, '=')
  ->condition('target', $target_locale, '=')
  ->fields('tc')
  ->execute();

  foreach ($result as $row) {
    return $row->rid;
  }
}

/**
 * Gets array of taxonomies from XML data.
 *
 * @param object $xml
 *   The XML data.
 *
 * @return array
 *   Array of taxonomies.
 */
function globallink_taxonomy_get_arr_items($xml) {
  if (is_null($xml) || !is_string($xml) || $xml == '') {
    return array();
  }

  $dom = new DomDocument;
  $dom->preserveWhiteSpace = FALSE;
  $dom->loadXML($xml);

  $contents = $dom->getElementsByTagName('content');
  $bid = '';

  foreach ($contents as $content) {
    if (!is_null($content->attributes)) {
      foreach ($content->attributes as $attr_name => $attr_node) {
        if ($attr_name == 'bid') {
          $bid = $attr_node->value;
        }
      }
    }
  }

  if ($bid == '') {
    return array();
  }

  $taxonomy_arr = array();
  $taxonomy_arr['bid'] = $bid;
  $blocks = $dom->getElementsByTagName('taxonomy');

  foreach ($blocks as $block) {
    if (!is_null($block->attributes)) {
      $b_arr = array();

      foreach ($block->attributes as $attr_name => $attr_node) {
        $b_arr[$attr_name] = $attr_node->value;
      }
      $b_arr['translation'] = $block->nodeValue;
      $taxonomy_arr[$b_arr['name']] = $b_arr;
    }
  }

  $t_fields = $dom->getElementsByTagName('field');
  foreach ($t_fields as $t_field) {
     $fieldObject = new GLField();
     $fieldObject->type = 'field';
     $fieldObject->translatedContent = $t_field->nodeValue;

    if (!is_null($t_field->attributes)) {
      foreach ($t_field->attributes as $attrName => $attrNode) {
        switch ($attrName) {
          case 'field':
            $fieldObject->fieldName = $attrNode->value;
            continue 2;
          case 'delta':
            $fieldObject->delta = $attrNode->value;
            continue 2;
          case 'langcode':
            $fieldObject->langcode = $attrNode->value;
            continue 2;
          case 'label':
            $fieldObject->fieldLabel = $attrNode->value;
            continue 2;
          case 'parent_fc':
            $fieldObject->parentFCName = $attrNode->value;
            continue 2;
          case 'bundle':
            $fieldObject->bundle = $attrNode->value;
            continue 2;
          case 'entity_id':
            $fieldObject->entityId = $attrNode->value;
            continue 2;
          case 'entity_type':
            $fieldObject->entityType = $attrNode->value;
            continue 2;
          case 'content_type':
            $fieldObject->contentType = $attrNode->value;
            continue 2;
        }
      }
      if (is_null($fieldObject->langcode)) {
        $fieldObject->langcode = LANGUAGE_NONE;
      }
      if (is_null($fieldObject->delta)) {
        $fieldObject->delta = '0';
      }
    }
    $taxonomy_arr[$fieldObject->fieldName][$fieldObject->langcode][$fieldObject->delta] = $fieldObject;
  }

  $t_metatags = $dom->getElementsByTagName('metatag');
  foreach ($t_metatags as $t_metatag) {
    $fieldObject = new GLField();
    $fieldObject->type = 'metatag';
    $fieldObject->translatedContent = $t_metatag->nodeValue;

    if (!is_null($t_metatag->attributes)) {
      foreach ($t_metatag->attributes as $attrName => $attrNode) {
        switch ($attrName) {
          case 'field':
            $fieldObject->fieldName = $attrNode->value;
            continue 2;
          case 'delta':
            $fieldObject->delta = $attrNode->value;
            continue 2;
          case 'langcode':
            $fieldObject->langcode = $attrNode->value;
            continue 2;
          case 'label':
            $fieldObject->fieldLabel = $attrNode->value;
            continue 2;
        }
      }
      if (is_null($fieldObject->langcode)) {
        $fieldObject->langcode = LANGUAGE_NONE;
      }
      if (is_null($fieldObject->delta)) {
        $fieldObject->delta = '0';
      }
    }
   $taxonomy_arr['metatags'][$fieldObject->fieldName][$fieldObject->langcode] = $fieldObject;
  }

  return $taxonomy_arr;
}

/**
 * Gets taxonomy vocabulary list.
 *
 * @return array
 *   Array of taxonomy vocabulary.
 */
function globallink_taxonomy_get_vocabulary_list() {
  $v_arr = array('[any]' => 'Any');
  $arr = array();

  $vocabs = taxonomy_vocabulary_load_multiple(FALSE);

  foreach ($vocabs as $vocab) {
    if ($vocab->i18n_mode == I18N_MODE_LOCALIZE || $vocab->i18n_mode == I18N_MODE_TRANSLATE) {
      $arr[$vocab->vid] = $vocab->name;
    }
  }

  asort($arr);

  return $v_arr + $arr;
}

/**
 * Gets distinct active taxonomy submission names.
 *
 * @return array
 *   Array of distinct active taxonomy submission names.
 */
function globallink_taxonomy_get_distinct_active_submission_names() {
  $query = db_select('globallink_core_taxonomy', 'tc');
  $query->condition('status', array('Sent for Translations', 'Error'), 'IN');
  $query->distinct();
  $query->fields('tc');
  $results = $query->execute();

  $arr = array('[any]' => t('Any'));

  foreach ($results as $row) {
    $arr[$row->submission] = $row->submission;
  }

  return $arr;
}

/**
 * Updates taxonomy submission status.
 *
 * @param string $submission_ticket
 *   The submission ticket.
 * @param string $status
 *   The submission status.  Defaults to 'Cancelled.'
 */
function globallink_taxonomy_update_submission_status($submission_ticket, $status = 'Cancelled') {
  db_update('globallink_core_taxonomy')
  ->fields(array(
    'status' => $status,
    'timestamp' => REQUEST_TIME,
  ))
  ->condition('submission_ticket', $submission_ticket, '=')
  ->execute();
}

/**
 * Gets taxonomy submission status.
 */
function globallink_taxonomy_get_submission_status() {
  module_load_include('inc', 'globallink', 'globallink_settings');
  module_load_include('inc', 'globallink', 'gl_ws/gl_ws_common');

  $query = db_select('globallink_core_taxonomy', 'tc');
  $query->fields('tc', array('submission_ticket'));
  $query->distinct();
  $query->condition('status', 'Sent for Translations', '=');
  $results = $query->execute();

  foreach ($results as $row) {
    if ($row->submission_ticket) {
      try {
        $pd4 = globallink_get_project_director_details();

        $doc_status = globallink_get_status($pd4, $row->submission_ticket);

        if (!$doc_status || $doc_status == 'CANCELLED') {
          globallink_taxonomy_update_submission_status($row->submission_ticket);
        }
      }
      catch (SoapFault $se) {
        globallink_taxonomy_update_submission_status($row->submission_ticket);
      }
      catch (Exception $ex) {
        globallink_taxonomy_update_submission_status($row->submission_ticket);
      }
    }
  }
}

/**
 * Checks taxonomy status based on row IDs.
 *
 * @param array $rids_arr
 *   Array of row IDs.
 *
 * @return array
 *   Array of row IDs that have been sent for translation or threw an error.
 */
function globallink_taxonomy_check_status($rids_arr) {
  $status = TRUE;

  $query = db_select('globallink_core_taxonomy', 'tc')
  ->fields('tc', array('rid'))
  ->condition('status', array('Sent for Translations', 'Error'), 'IN');

  $results = $query->execute();

  $rows = array();

  foreach ($results as $item) {
    $rows[$item->rid] = $item->rid;
  }

  foreach ($rids_arr as $val) {
    if (!in_array($val, $rows)) {
      unset($rids_arr[$val]);
      $status = FALSE;
    }
  }

  if (!$status) {
    drupal_set_message(t('Cannot cancel documents that have been cancelled in Globallink.'), 'warning', NULL);
  }

  return $rids_arr;
}

/**
 * Clears cancelled taxonomy documents.
 *
 * @return int
 *   Number of cancelled taxonomy documents.
 */
function globallink_taxonomy_clear_cancelled_documents() {
  $count = 0;

  $query = db_select('globallink_core_taxonomy', 'tc')
  ->fields('tc', array('submission_ticket'))
  ->distinct()
  ->condition('status', 'Cancelled', '=');

  $results = $query->execute();

  foreach ($results as $item) {
    globallink_taxonomy_update_submission_status($item->submission_ticket, 'Pending Translations');

    $count++;
  }

  return $count;
}

function get_configured_fields_for_taxonomy($taxonomy_type) {
    $result = db_select('globallink_field_config', 'tfg')
            ->fields('tfg')
            ->condition('content_type', 'tax:' . $taxonomy_type, '=')
            ->condition('entity_type', 'taxonomy_term', '=')
            ->execute();
    $arr = array();
    foreach ($result as $row) {
        $arr[$row->field_name] = $row;
    }

    return $arr;
}

function get_taxonomy_fields($taxonomy_type) {
    $fields = array();
    $info = entity_get_info('taxonomy_term');
    foreach ($info['bundles'] as $bundle_name => $bundle_info) {
        if ($bundle_name == $taxonomy_type) {
            foreach (field_info_instances('taxonomy_term', $bundle_name) as $field) {
                $fields[] = $field['field_name'];
            }
        }
    }
    return $fields;
}

function globallink_get_all_translatable_taxonomy_types_and_names() {
  $override_localize = variable_get('globallink_override_localize', 0);
  $entity_version = system_get_info('module', 'entity_translation');
  $entity_info = entity_get_info('taxonomy_term');
  $arr = array();
  if (isset($entity_info) && isset($entity_info['bundles'])) {
    $bundles = $entity_info['bundles'];
    foreach ($bundles as $key => $bundle) {
      $vocab = taxonomy_vocabulary_machine_name_load($key);
      if ($entity_version['version'] == '7.x-1.0-beta5') {
        if (($vocab->i18n_mode == I18N_MODE_TRANSLATE) || ($vocab->i18n_mode == I18N_MODE_LOCALIZE && $override_localize == 1)) {
          $arr['tax:' . $key] = $bundle['label'];
        }
      }
      else {
        if (($vocab->i18n_mode == I18N_MODE_TRANSLATE) || ($vocab->i18n_mode == I18N_MODE_ENTITY_TRANSLATION)) {
          $arr['tax:' . $key] = $bundle['label'];
        }
      }
    }
    asort($arr);
  }
  return $arr;
}
