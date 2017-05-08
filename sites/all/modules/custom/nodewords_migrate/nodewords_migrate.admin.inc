<?php

/**
 * @file nodewords_migrate.admin.inc
 * Code to process data migration.
 */

/**
 * Form generator for the migration selection form.
 */
function nodewords_migrate_form($form, &$form_state) {
  $form['actions']['migrate'] = array(
    '#type' => 'submit',
    '#value' => t('Migrate'),
  );

  return $form;
}

/**
 * Handles submission of the nodewords migration form.
 */
function nodewords_migrate_form_submit($form, &$form_state) {
  nodewords_migrate_migrate();
  drupal_set_message('Nodewords migration complete.');
}

/**
 * Migrates Nodewords data to the Meta tags module.
 *
 * @todo: Properly filter default values.
 */
function nodewords_migrate_migrate() {
  // Retrieve nodewords data.
  $results = db_query("SELECT nw.type, nw.id, n.vid, nw.`name`, nw.content FROM nodewords AS nw LEFT JOIN node AS n ON nw.id = n.nid ORDER BY nw.type ASC, nw.id ASC");

  // Convert nodewords data into the meta tags format.
  foreach ($results as $result) {
    $type = nodewords_migrate_type($result->type);
    $metatag = (object) array(
      'entity_type' => $type,
      'entity_id' => $result->id,
      'revision_id' => $result->vid,
      'entity_type_id' => $result->type,
      'data' => nodewords_migrate_metatag($type, $result->name, unserialize($result->content)),
    );

    // If the metatags value is not empty.
    if (!empty($metatag->data[$result->name]['value'])) {

      // If a current records exists.
      if (isset($record)) {
        // If the metatag belongs to the current record.
        if ($metatag->entity_type == $record->entity_type && $metatag->entity_id == $record->entity_id) {
          // Add this metatag to the current record.
          $record->data = array_merge($record->data, $metatag->data);
        }
        else {
          // Store record and create a new one.
          $records[] = $record;
          $record = $metatag;
        }
      }
      else {
        // Create a new record.
        $record = $metatag;
      }
    }
  }
  // Add the last record to the list of records.
  $records[] = $record;

  // Merge all nodewords with meta tags.
  foreach ($records as $record) {
    // If there is data to merge.
    if ($record->data) {
      switch ($record->entity_type) {
        // Nodewords defaults are metatag configuration.
        case 'global':
        case 'global:frontpage':
          $metatags = metatag_config_load($record->entity_type);

          // If a configuration was found.
          if ($metatags) {
            // Merge in Nodewords defaults.
            $metatags->config = array_merge($metatags->config, $record->data);
          }
          else {
            // Create a new configuration.
            $metatags = (object) array(
              'instance' => $record->entity_type,
              'config' => $record->data,
            );
          }

          metatag_config_save($metatags);
          break;

        // These are metatags for a specified entity.
        case 'node':
          $metatags = metatag_metatags_load($record->entity_type, $record->entity_id);
          $metatags = array(LANGUAGE_NONE => array_merge($metatags, $record->data));
          metatag_metatags_save($record->entity_type, $record->entity_id, $record->revision_id, $metatags, LANGUAGE_NONE);
          break;
        case 'taxonomy_term':
          $metatags = metatag_metatags_load($record->entity_type, $record->entity_id);
          $metatags = array(LANGUAGE_NONE => array_merge($metatags, $record->data));
          $term = taxonomy_term_load($record->entity_id);
          metatag_metatags_save($record->entity_type, $record->entity_id, $term->vid, $metatags, $term->language);
          break;
        case 'vocabulary':
          $metatags = metatag_metatags_load($record->entity_type, $record->entity_id);
          $metatags = array(LANGUAGE_NONE => array_merge($metatags, $record->data));
          $vocabulary = taxonomy_vocabulary_load($record->entity_id);
          metatag_metatags_save($record->entity_type, $record->entity_id, $vocabulary->vid, $metatags, $vocabulary->language);
          break;
      }
    }
  }
}

/**
 * Converts the nodewords type to a metatage type or metatag config instance.
 *
 * @param $type
 *   Nodewords type.
 *
 * @return
 *   Meta tags type or configuration instance.
 */
function nodewords_migrate_type($type) {
//  define('NODEWORDS_TYPE_DEFAULT',    1);
//  define('NODEWORDS_TYPE_ERRORPAGE',  2);
//  define('NODEWORDS_TYPE_FRONTPAGE',  3);
//  define('NODEWORDS_TYPE_NONE',       0);
//  define('NODEWORDS_TYPE_NODE',       5);
//  define('NODEWORDS_TYPE_PAGE',      10);
//  define('NODEWORDS_TYPE_PAGER',      4);
//  define('NODEWORDS_TYPE_TERM',       6);
//  define('NODEWORDS_TYPE_TRACKER',    7);
//  define('NODEWORDS_TYPE_USER',       8);
//  define('NODEWORDS_TYPE_VOCABULARY', 9);
  switch ($type) {
    case 1:
      return 'global';

    case 3:
      return 'global:frontpage';

    case 5:
      return 'node';

    case 6:
      return 'taxonomy_term';

    case 8:
      return 'user';

    case 9:
      return 'vocabulary';
  }

  return FALSE;
}

/**
 * Converts metatag data from nodewords to meta tags format.
 *
 * @param $type
 *   Metatag type.
 * @param $name
 *   Metatag name.
 * @param $data
 *   Metatag data in nodewords format.
 *
 * @return
 *   Metatag name and data in meta tags format if name is supported by type.
 */
function nodewords_migrate_metatag($type, $name, $data) {
  $empty = array(
    $name => array(
      'value' => '',
    ),
  );

  $default = array(
    $name => $data,
  );

  $structured = array(
    $name => array(
      'value' => $data,
    ),
  );

  // Format the metatag based on the type and name.
  switch ($type) {
    // Configurations.
    case 'global':
    case 'global:frontpage':
      switch ($name) {
        // @todo: Create custom meta tags if possible.
        case 'abstract':
        case 'revisit-after':
          return $default;

        // @todo: Convert robots.
        case 'robots':
          return $default;

        //case 'canonical':
        //case 'copyright':
        default:
          return $default;
      }

    // Content.
    //case 'node':
    default:
      switch ($name) {
        // @todo: Create custom meta tags if possible.
        case 'abstract':
        case 'revisit-after':
          return $empty;
          break;

        // Not supported for content.
        case 'canonical':
        case 'copyright':
          return $empty;
          break;

        // Robots settings
        case 'robots':
          // Robots needs some extra processing
          $robot_data = array();
          // Convert each value to display the name if it is "on" and 0 if it is off;
          foreach ($data as $robot_key => $robot_val) {
            $robot_data[$robot_key] = ($robot_val == 0 ? 0 : $robot_key);
          }
          // Return the data in the right structure
          return array($name => array('value' => $robot_data));
          break;

        // Structured data types (where the value is actually more arrays)
        case 'location':
          return $structured;
          break;

        // Everything else
        default:
          return $default;
      }
  }
}
