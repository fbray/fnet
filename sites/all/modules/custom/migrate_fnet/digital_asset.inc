<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 6/7/17
 * Time: 1:39 PM
 */
/*
 *  Digital Asset Migration Class
*/
class FNETDigitalAssetMigration extends FNETNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Path Alias
    $this->addFieldMapping('path', 'path');

    // Disable Pathauto for now.
    $this->addFieldMapping('pathauto')->defaultValue(0);

    // Redirects
    $this->addFieldMapping('migrate_redirects', 'path');

    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_dam_business_entity')
      ->description(t('No longer necessary as NetScout split is complete.'))
      ->issueGroup(t('DNM'));

    // Individual Fields

    $this->addFieldMapping('field_dam_language', 'field_dam_language');
    $this->addFieldMapping('field_dam_document_id', 'field_dam_document_id');
    $this->addFieldMapping('field_dam_ams_id', 'field_dam_ams_id');
    $this->addFieldMapping('field_dam_revision_letter', 'field_dam_revision_letter');
    $this->addFieldMapping('field_dam_storage_file_folder', 'field_dam_storage_file_folder');
    $this->addFieldMapping('field_dam_storage_file_name', 'field_dam_storage_filename');
    $this->addFieldMapping('field_dam_cdn_status', 'field_dam_cdn_status');
    $this->addFieldMapping('field_dam_file_size', 'field_dam_file_size');
    $this->addFieldMapping('field_dam_original_file_name', 'field_dam_original_filename');
    $this->addFieldMapping('field_dam_keep_original_filename', 'field_dam_keep_original_filename');


    $this->addFieldMapping('field_asset_type', 'field_dam_asset_type');

    $this->addFieldMapping('field_dam_export_controlled', 'field_dam_export_controlled');
    $this->addFieldMapping('field_dam_document_status', 'field_dam_document_status');
    $this->addFieldMapping('field_dam_entitlement_level', 'field_dam_entitlement_level');

    $this->addFieldMapping('field_dam_bulk_fulfillment', 'field_dam_bulk_fulfillment');
    $this->addFieldMapping('field_dam_storage_file_folder_po', 'field_dam_storage_file_folder_po');
    $this->addFieldMapping('field_dam_storage_filename_pod', 'field_dam_storage_filename_pod');
    $this->addFieldMapping('field_dam_cdn_status_pod', 'field_dam_cdn_status_pod');
    $this->addFieldMapping('field_dam_cost_center', 'field_dam_cost_center');
    $this->addFieldMapping('field_dam_print_on_demand', 'field_dam_print_on_demand');
    $this->addFieldMapping('field_dam_quantity', 'field_dam_quantity');
    $this->addFieldMapping('field_dam_unit_of_measure', 'field_dam_unit_of_measure');
    $this->addFieldMapping('field_dam_uom_quantity', 'field_dam_uom_quantity');
    $this->addFieldMapping('field_dam_order_quantity_max', 'field_dam_order_quantity_max');
    $this->addFieldMapping('field_dam_l1_category', 'field_dam_l1_category');
    $this->addFieldMapping('field_dam_l2_category', 'field_dam_l2_category');
    $this->addFieldMapping('field_dam_l3_category', 'field_dam_l3_category');
    $this->addFieldMapping('field_dam_l4_category', 'field_dam_l4_category');

    $this->addFieldMapping('field_dam_industry', 'field_dam_industry');

    // Link Fields
    $this->addFieldMapping('field_dam_edoc_url', 'field_dam_edoc_url');
    $this->addFieldMapping('field_dam_edoc_url:title', 'field_dam_edoc_url:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_dam_edoc_url:attributes', 'field_dam_edoc_url:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_dam_edoc_url:language', 'field_dam_edoc_url:language')
      ->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_dam_form_url', 'field_dam_form_url');
    $this->addFieldMapping('field_dam_form_url:title', 'field_dam_form_url:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_dam_form_url:attributes', 'field_dam_form_url:attributes')
      ->defaultValue(NULL);

    // Date Fields
    $this->addFieldMapping('field_dam_availability_dates', 'field_dam_availability_date');
    $timezone = variable_get('date_default_timezone', '');
    $this->addFieldMapping('field_dam_availability_dates:timezone')
      ->defaultValue($timezone);
    $this->addFieldMapping('field_dam_availability_dates:rrule')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_dam_availability_dates:to', 'field_dam_availability_date:value2');

    // Entity References
    $this->addFieldMapping('field_related_products', 'field_dam_related_product')
      ->sourceMigration('ProductDisplay');

    $this->addFieldMapping('field_dam_parent', 'field_dam_parent')
      ->sourceMigration('DigitalAsset');

    $this->addFieldMapping('field_asset_tags', 'taxonomy_vocabulary_19')
      ->sourceMigration('AssetTags');

    // File Fields
    $this->addFieldMapping('field_asset_file', 'field_dam_asset_file')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_asset_file:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_asset_file:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_asset_file:display', 'field_dam_asset_file:display');
    $this->addFieldMapping('field_asset_file:description', 'field_dam_asset_file:description')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_dam_asset_file_pod', 'field_dam_asset_file_pod')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_dam_asset_file_pod:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_dam_asset_file_pod:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_dam_asset_file_pod:display', 'field_dam_asset_file_pod:display');
    $this->addFieldMapping('field_dam_asset_file_pod:description', 'field_dam_asset_file_pod:description')
      ->defaultValue(NULL);

  }

  /**
   * Implementation of prepareRow()
   *
   * @param $row
   * @return bool
   *
   */
  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Correct the language field.
    /*
    // Traditional Chinese
    if ($row->field_dam_language == 'tw') {
      $row->field_dam_language = 'zh-hant';
    }
    // Simplified Chinese
    if ($row->field_dam_language == 'zh') {
      $row->field_dam_language = 'zh-hans';
    }
    */
    // Check the various fields. Remove the hard URLs.
    // Remove the absolute URL in the Form URL and eDoc URL fields.
    // Check the body field. Replace and instanes of 'sites/flukenetworks.com' in URLs
    // with 'sites/all'.

    $row->body = $this->stripDomain($row->body);
    $row->field_dam_form_url = $this->stripDomain($row->field_dam_form_url);
    $row->field_dam_edoc_url = $this->stripDomain($row->field_dam_edoc_url);
    $row->body = str_ireplace('/flukenetworks.com/files', '/default/files', $row->body);
    $row->body = str_ireplace('/flukenetworks.com/theme', '/all/theme', $row->body);



    // Stupid Asset Type field.
    $type = [
      'application notes' => 'application_notes',
      'brochures' => 'brochure',
      'case studies' => 'case_study',
      'catalogs' => 'catalog',
      'corporate' => 'corporate',
      'data sheets' => 'data_sheet',
      'extended specifications' => 'extended_specification',
      'flyers' => 'flyer',
      'gold training' => 'gold_training',
      'images' => 'image',
      'letters' => 'letter',
      'manuals' => 'manual',
      'miscellaneous' => 'miscellaneous',
      'powerpoint presentations' => 'presentation',
      'product software' => 'product_software',
      'product software release notes' => 'product_software_release_notes',
      'sales guides' => 'sales_guide',
      "user's guide" => 'user_guide',
      'videos' => 'video',
      'virtual demos' => 'virtual_demonstration',
      'webcasts' => 'webcast',
      'white papers' => 'white_paper',
    ];
    $row->field_dam_asset_type[0] = $type[$row->field_dam_asset_type[0]];

    // Use Proper case for L# categories.
    // $row->field_dam_l1_category =
  }

  /**
   * Code to add imported Digital Assets to their respective groups.
   *
   * @param $node
   * @param \stdClass $row
   */

  public function complete($node, stdClass $row) {
    // $node is the new, $row is the old.

    // Get the old gids using the old entity id.
    $old_groups = [];
    $query = Database::getConnection('legacy', $this->sourceConnection)
      ->select('groups', 'g')
      ->fields('g', ['Title' => 'title']);
    $query->join('group_entity', 'ge', 'ge.gid = g.gid');
    $query->condition('ge.entity_id', $row->nid, '=');
    $results = $query->execute();
    foreach ($results as $result) {
      $old_groups[] = $result->title;
    }

    // Match the names of the groups to get the new gid.
    $gid_query = Database::getConnection('default', $this->sourceConnection)
      ->select('groups', 'g')
      ->fields('g', ['gid' => 'gid'])
      ->condition('title', $old_groups, 'IN');
    $gid_results = $gid_query->execute();
    // $gid_results = db_query('SELECT gid FROM {groups} WHERE title IN :title', array(':title' => $old_groups));

    // Insert the new gid, new entity id, entity type 'node', bundle 'extranet_page' into the group_entity table.
    foreach($gid_results as $gid_result) {
      try {
        db_insert('group_entity')
          ->fields([
            'gid' => $gid_result->gid,
            'entity_id' => $node->nid,
            'entity_type' => 'node',
            'bundle' => 'digital_asset'
          ])->execute();
      }
      catch (Exception $e) {
        watchdog('migrate_fnet', $e->getMessage());
      }

    }

    return parent::complete($node, $row); // TODO: Change the autogenerated stub
  }

  /**
   * Code to execute after an entity has been rolled back.
   *
   * @param $entity_ids
   */

  public function completeRollback($entity_ids) {
    db_delete('group_entity')
      ->condition('entity_id', $entity_ids, 'IN')
      ->execute();
  }


  protected function stripDomain($string) {
    $domains = ['http://www.flukenetworks.com/', 'https://www.flukenetworks.com/', 'http://flukenetworks.com/', 'https://flukenetworks.com/'];
    $stripped = str_ireplace($domains, '/', $string);
    return $stripped;
  }
}