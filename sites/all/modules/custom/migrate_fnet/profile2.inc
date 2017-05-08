<?php
/**
* @file
* Examples and test fodder for migration into profile2 entities.
*/

class PlayOn6Profile2Migration extends Migration {
  public function __construct() {
    parent::__construct();
    $this->description = t('Migration of User profiles into profile2 entities');
    $this->dependencies = array('ExUser', 'Files');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'D6 Unique Node ID',
          'alias' => 'n',
        )
      ),
      MigrateDestinationProfile2::getKeySchema()
    );

    $query = db_select(playon_drupal6 . '.node', 'n')
      ->fields('n', array('nid', 'vid', 'type', 'language', 'title', 'uid', 'status', 'created', 'changed', 'comment', 'promote', 'moderate', 'sticky', 'tnid', 'translate'))
      ->condition('n.type', 'profile', '=');
    $query->join(playon_drupal6 . '.node_revisions', 'nr', 'n.vid = nr.vid');
    $query->addField('nr', 'body');
    $query->addField('nr', 'teaser');
    $query->addField('nr', 'format');
    $query->join(playon_drupal6 . '.users', 'u', 'n.uid = u.uid');
    $query->addField('u', 'name');
    $query->leftJoin(playon_drupal6 . '.content_type_profile', 'ctp', 'n.nid = ctp.nid AND n.vid = ctp.vid');
    $query->addField('ctp','field_name_last');
    $query->addField('ctp','field_name_first');
    $query->addField('ctp','field_name_middle');
    $query->addField('ctp','field_name_prefix');
    $query->addField('ctp','field_name_suffix');
    $query->orderBy('n.nid', 'ASC');

    $source_fields = array(
      'nid' => t('The node ID of the page'),
      'uid' => t('The user ID of a user'),
      'lid' => t('The location ID of a location instance'),
    );

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query, $source_fields);
    $this->destination = new MigrateDestinationProfile2('customer');

    // Add a few field mappings.
    $this->addFieldMapping('field_name_first', 'field_name_first');
    $this->addFieldMapping('field_name_last', 'field_name_last');
      
    // Unmapped destination fields
    $this->addUnmigratedDestinations(array('id'));
    $this->addUnmigratedSources(array('vid', 'type', 'language', 'moderate', 'tnid', 'translate', 'teaser', 'format', 'name'));
  }
}
