<?php

/**
 * @file
 * Convert data from Nodewords to Metatag.
 */

/**
 * Form generator for the migration selection form.
 */
function metatag_page_title_importer_form($form, &$form_state) {

  $types = array('Page Titles');
  $form['types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Records to import'),
    '#options' => $types,
    '#disabled' => FALSE,
  );

  $form['actions']['migrate'] = array(
    '#type' => 'submit',
    '#value' => t('Migrate all records'),
  );

  return $form;
}

/**
 * Handles submission of the Nodewords migration form.
 */
function metatag_page_title_importer_form_submit($form, &$form_state) {
  _metatag_page_title_importer_import();
}

/**
 * Migrates Nodewords data to the Metatag module.
 */
function _metatag_page_title_importer_import() {
  $batch = array(
    'title' => t('Importing Page Title data..'),
    'operations' => array(
      array('_metatag_page_title_importer_migrate', array()),
    ),
    'finished' => '_metatag_page_title_importer_finished',
    'file' => drupal_get_path('module', 'metatag_page_title_importer') . '/metatag_page_title_importer.admin.inc',
  );
  batch_set($batch);

  // Kick off the batch.
  batch_process();
}

/**
 * Migrates Nodewords data to the Metatag module.
 */
function _metatag_page_title_importer_migrate(&$context = array()) {
  // Process this number of {Page Title} records at a time.
  $limit = 50;

  if (empty($context['sandbox'])) {

    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current'] = 0;
    $query = db_select('page_title', 'pt')
      ->fields('pt', array('id'))
      ->orderBy('pt.id');
    $context['sandbox']['dataset'] = array_keys($query->execute()
      ->fetchAllAssoc('id', PDO::FETCH_ASSOC));
    $context['sandbox']['max'] = count($context['sandbox']['dataset']);

    // Track all of the entities that could not be loaded.
    $context['sandbox']['skipped'] = array();
  }

  // Retrieve Nodewords data.
  $query = db_select('page_title', 'pt')->fields('pt', array(
      'id',
      'type',
      'page_title'
    ))// Continue on from the last record that was processed.
    ->condition('pt.id', $context['sandbox']['current'], '>')->orderBy('pt.id');
  $query->range(0, $limit);
  $results = $query->execute();

  // Records that are being converted.
  $records = array();

  // Convert Nodewords data into the Metatag format.
  foreach ($results as $result) {
    // Log the progress.
    $context['sandbox']['current'] = $result->id;
    $context['sandbox']['progress']++;
    $context['results'][] = $result->id;

    // Convert the Nodewords record 'type' into something Metatag can use.
    $type = 'node';

    // This could be an entity ID, but also possibly just a placeholder integer.
    $record_id = $result->id;

    // If this record is for an entity, verify that the entity exists.
    $entity = entity_load($type, array($record_id));
    if (empty($entity)) {
      $context['sandbox']['skipped'][$type][$record_id] = $record_id;
      watchdog('metatag_page_title_importer', 'Unable to load @entity_type ID @id', array(
        '@entity_type' => $type,
        '@id' => $record_id
      ), WATCHDOG_WARNING);
    }

    // Process the meta tag value, possibly also rename the meta tag name
    // itself.
    $meta_tag = 'title';
    $value = array('value' => $result->page_title);
    // Don't import empty values.
    if (!empty($value)) {
      // Add the value to the stack.
      $records[$type][$record_id][$meta_tag] = $value;
    }
  }

// Update or create Metatag records.
  foreach ($records as $type => $data) {
    foreach ($data as $record_id => $values) {
      switch ($type) {
        // Standard D7 entities are converted to {metatag} records using
        // metatag_metatags_save().
        case 'node':
          try {
            $entity = entity_load($type, array($record_id));
            $entity = reset($entity);
            $langcode = metatag_entity_get_language($type, $entity);
            list($entity_id, $revision_id, $bundle) = entity_extract_ids($type, $entity);
          } catch (Exception $e) {
            watchdog('metatag_page_title_importer', $e->getMessage(), array(), WATCHDOG_ERROR);
            continue;
          }

          // Add these meta tags to the entity, overwriting anything that's
          // already there.
          foreach ($values as $name => $value) {
            $entity->metatags[$langcode][$name] = $value;
          }
          metatag_metatags_save($type, $entity_id, $revision_id, $entity->metatags, $langcode);
          // watchdog('metatag_page_title_importer', 'Imported meta tags for @entity_type ID @id.', array('@entity_type' => $type, '@id' => $record_id), WATCHDOG_INFO);
          break;
      }
    }
  }

  $context['finished'] = (empty($context['sandbox']['max']) || $context['sandbox']['progress'] >= $context['sandbox']['max']) ? TRUE : ($context['sandbox']['progress'] / $context['sandbox']['max']);
  $context['message'] = t('processed: !count of !total', array(
    '!count' => $context['sandbox']['progress'],
    '!total' => $context['sandbox']['max']
  ));
  if ($context['finished'] === TRUE) {
    drupal_set_message(t('Imported @imported page title records.', array('@imported' => $context['sandbox']['progress'])));
  }
}

/**
 * BatchAPI callback for when the import finishes.
 */
function _metatag_page_title_importer_finished($success, $results, $operations) {
  if ($success) {
    // Here we do something meaningful with the results.
    $message = t("!count items were processed.", array(
      '!count' => count($results),
    ));
    //$message .= theme('item_list', array('items' => $results));
    drupal_set_message($message);
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array(
      '%error_operation' => $error_operation[0],
      '@arguments' => print_r($error_operation[1], TRUE),
    ));
    drupal_set_message($message, 'error');
  }
}


