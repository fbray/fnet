<?php
/*
 * @file
 *
 * A Views filter handler for showing only DCI related node reference items.
 */
class fextranet_handler_filter_dci_related_products extends views_handler_filter_field_list {

  function get_value_options() {
    // The field is a list of products
    $products = array();

    // database query
    $result = db_query("SELECT related.field_dam_related_product_nid, n.title
FROM {field_data_field_dam_related_product} AS related
LEFT OUTER JOIN {field_data_field_business_entity} AS be ON be.entity_id = related.field_dam_related_product_nid
LEFT OUTER JOIN {field_data_taxonomy_vocabulary_1} AS tv ON tv.entity_id = related.field_dam_related_product_nid
LEFT OUTER JOIN {taxonomy_term_data} AS betid ON betid.tid = be.field_business_entity_tid
LEFT OUTER JOIN {taxonomy_term_data} AS bettv ON bettv.tid = tv.taxonomy_vocabulary_1_tid
INNER JOIN {node} as n ON n.nid = related.field_dam_related_product_nid
WHERE bettv.name = 'Active' AND betid.name = 'Fluke DCI' AND n.status = 1");

    /* SQL Query for testing
    SELECT DISTINCT related.field_dam_related_product_nid, n.title, n.status, betid.name, bettv.name
FROM field_data_field_dam_related_product AS related
LEFT OUTER JOIN field_data_field_business_entity AS be ON be.entity_id = related.entity_id
LEFT OUTER JOIN field_data_taxonomy_vocabulary_1 AS tv ON tv.entity_id = related.field_dam_related_product_nid
LEFT OUTER JOIN taxonomy_term_data AS betid ON betid.tid = be.field_business_entity_tid
LEFT OUTER JOIN taxonomy_term_data AS bettv ON bettv.tid = tv.taxonomy_vocabulary_1_tid
INNER JOIN node as n ON n.nid = related.field_dam_related_product_nid
WHERE bettv.name = 'Active' AND betid.name = 'Fluke DCI'
    */

    if (!empty($result)) {

      foreach ($result as $node) {
        $products[$node->field_dam_related_product_nid] = $node->title;
      }
      natsort($products);
      $this->value_options = $products;
    }
    return $products;
  }
}
