<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 9/25/17
 * Time: 9:48 AM
 */

/**
 * Class EventRegistrationtMigration
 */
class EventRegistrationMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    // Human-friendly description of your migration process. Be as detailed as
    // you like.
    $this->description = t('Registration for an event_occurrence');
    if (!empty($arguments['dependencies'])) {
      $registrant_migration = $arguments['dependencies'];
      $this->dependencies[] = $registrant_migration;
    }
    // In this example, we're using tables that have been added to the existing
    // Drupal database but which are not Drupal tables. You can examine the
    // various tables (starting here with migrate_example_beer_topic) using a
    // database browser such as phpMyAdmin.
    // First, we set up a query for this data. Note that by ordering on
    // style_parent, we guarantee root terms are migrated first, so the
    // parent_name mapping below will find that the parent exists.
    $query = $query = Database::getConnection('default', $arguments['source_connection'])
      ->select('ems_registration', 'r')
      ->fields('r', array('nid', 'rid', 'gold_number', 'payment_status', 'region', 'language',
        'registration_status', 'registration_sequence', 'cancellation_token'));

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query);

    $table_name = 'ems_registration';

    // Create a map object for tracking the relationships between source rows
    // and their resulting Drupal objects. We will use the MigrateSQLMap class,
    // which uses database tables for tracking. Pass the machine name (BeerTerm)
    // of this migration to use in generating map and message table names.
    // And, pass schema definitions for the primary keys of the source and
    // destination - we need to be explicit for our source, but the destination
    // class knows its schema already.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'nid' => array(
          'description' => 'node id of event_occurrence',
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        ),
        'rid' => array(
          'description' => 'registrant id',
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationTable::getKeySchema($table_name)
    );
    $this->destination =
      new MigrateDestinationTable($table_name);

    // Assign mappings TO destination fields FROM source fields. To discover
    // the names used in these calls, use the drush commands
    //  drush migrate-fields-destination BeerTerm
    //  drush migrate-fields-source BeerTerm
    // or review the detail pages in the UI.
    $this->addSimpleMappings(array('gold_number', 'payment_status', 'region', 'language', 'registration_status', 'registration_sequence', 'cancellation_token'));
    if (isset($registrant_migration)) {
      $this->addFieldMapping('rid', 'rid')
        ->sourceMigration('EventRegistrants');
    }
    $this->addFieldMapping('nid', 'nid')
      ->sourceMigration('EventOccurrence');
  }
}