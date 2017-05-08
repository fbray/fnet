<?php
// $Id$
/**
 * @file
 * Migrate marketo_form data functions
 *
 */
function fnet_cck_migrations_product() {
  $batch = array(
    'title' => t('Migrating product fields'),
    'operations' => array(
      array('fnet_cck_migrations_batch_product', array()),
    ),
    'finished' => 'fnet_cck_migrations_batch_finished',
    'file' => drupal_get_path('module', 'fnet_cck_migrations') . '/' . 'fnet_cck_migrations.product.inc',
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

function fnet_cck_migrations_batch_product(&$context) {
  if (empty($context['sandbox'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_node'] = 0;
    $context['sandbox']['max'] = db_query("SELECT COUNT(DISTINCT nid) FROM {node} WHERE type = 'product'")->fetchField();
  }
  $limit = 10;
  try {
    $result = db_select('node', 'n')
      ->fields('n')
      ->condition('n.type', 'product', '=')
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
      if ($node = node_load($node_data->nid)) {
        // Check to see if the old CCK attribute field has any data for this node.
        $old_data = db_select('content_type_product', 'old')
          ->fields('old')
          ->condition('old.nid', $node_data->nid)
          ->condition('old.vid', $node_data->vid)
          ->execute();
        $data = $old_data->fetchAssoc();
        $image_data = unserialize($data['field_prod_carousel_img_lg_1_data']);
        $image_field = array();
        $image_field['fid'] = $data['field_prod_carousel_img_lg_1_fid'];
        if (isset($image_data->alt)) {
          $image_field['alt'] = $image_data->alt;
        }
        //$node->field_prod_carousel_img_lg_1 = array(LANGUAGE_NONE => array($image_field));
        $node->field_product_specs[LANGUAGE_NONE][0]['value'] = $data['field_product_specs_value'];
        $fields = array(
//          'field_prod_relatedprod',
//          'field_product_family',
//          'field_prod_language',
//          'field_do_not_distribute',
        );
        foreach ($fields as $field) {
          $values = array();
          $old_data = db_select("content_$field", 'old')
            ->fields('old')
            ->condition('old.nid', $node_data->nid)
            ->condition('old.vid', $node_data->vid)
            ->orderBy('old.delta', 'ASC')
            ->execute();
          foreach ($old_data as $row) {
            switch ($field) {
              case 'field_do_not_distribute_value':
                $field_name = "{$field}_value";
                $values[] = array('value' => $row->$field_name);
                break;
              default:
                $field_name = "{$field}_nid";
                $values[] = array('nid' => $row->$field_name);
                break;
            }
          }
          $node->$field = array(LANGUAGE_NONE => $values);
        }
        try {
          node_save($node);
        } catch (Exception $e) {
          drupal_set_message($e->getMessage(), 'error');
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

