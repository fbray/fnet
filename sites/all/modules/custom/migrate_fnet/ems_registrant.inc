<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 9/25/17
 * Time: 9:48 AM
 */
/**
 * There are four essential components to set up in your constructor:
 *  $this->source - An instance of a class derived from MigrateSource, this
 *    will feed data to the migration.
 *  $this->destination - An instance of a class derived from MigrateDestination,
 *    this will receive data that originated from the source and has been mapped
 *    by the Migration class, and create Drupal objects.
 *  $this->map - An instance of a class derived from MigrateMap, this will keep
 *    track of which source items have been imported and what destination
 *    objects they map to.
 *  Field mappings - Use $this->addFieldMapping to tell the Migration class what
 *    source fields correspond to what destination fields, and additional
 *    information associated with the mappings.
 */
class EventRegistrantMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    // Human-friendly description of your migration process. Be as detailed as
    // you like.
    $this->description = t('Registrants for an event');

    // In this example, we're using tables that have been added to the existing
    // Drupal database but which are not Drupal tables. You can examine the
    // various tables (starting here with migrate_example_beer_topic) using a
    // database browser such as phpMyAdmin.
    // First, we set up a query for this data. Note that by ordering on
    // style_parent, we guarantee root terms are migrated first, so the
    // parent_name mapping below will find that the parent exists.
    $query = Database::getConnection('default', $arguments['source_connection'])
      ->select('ems_registrant', 'emsr')
      ->fields('emsr', array('rid', 'first_name', 'last_name', 'email', 'job_title',
        'job_role', 'company', 'address', 'phone', 'city', 'state', 'postal_code', 'country'));

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->source = new MigrateSourceSQL($query);

    $table_name = 'ems_registrant';

    // Create a map object for tracking the relationships between source rows
    // and their resulting Drupal objects. We will use the MigrateSQLMap class,
    // which uses database tables for tracking. Pass the machine name (BeerTerm)
    // of this migration to use in generating map and message table names.
    // And, pass schema definitions for the primary keys of the source and
    // destination - we need to be explicit for our source, but the destination
    // class knows its schema already.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'rid' => array(
          'description' => 'Registrant ID',
          'type' => 'serial',
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
    $this->addSimpleMappings(array(
      'first_name',
      'last_name',
      'email',
      'job_title',
      'job_role',
      'company',
      'address',
      'phone',
      'city',
      'state',
      'postal_code',
      'country'));
  }
}