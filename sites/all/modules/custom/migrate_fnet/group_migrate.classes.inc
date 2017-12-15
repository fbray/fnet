<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 6/14/17
 * Time: 11:36 AM
 */

/*
 *  Group Migration Class
 *  for moving entity content in the Drupal Group module
*/
class MigrateDestinationGroup extends MigrateDestinationEntity {
  static public function getKeySchema() {
    return array(
      'gid' => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'description' => 'ID of destination group',
      ),
    );
  }

  /**
   * Basic initialization
   *
   * @param string $bundle
   *  A.k.a. the content type (page, article, etc.) of the group.
   * @param array $options
   *  Options applied to group.
   */
  public function __construct($bundle, array $options = array()) {
    parent::__construct('group', $bundle, $options);
  }

  /**
   * Returns a list of fields available to be mapped for the group type (bundle)
   *
   * @param Migration $migration
   *  Optionally, the migration containing this destination.
   * @return array
   *  Keys: machine names of the fields (to be passed to addFieldMapping)
   *  Values: Human-friendly descriptions of the fields.
   */
  public function fields($migration = NULL) {
    $fields = array();
    // First the core (groups table) properties
    $fields['gid'] = t('Group: Existing group ID');

    // Then add in anything provided by handlers
    $fields += migrate_handler_invoke_all('Entity', 'fields', $this->entityType, $this->bundle, $migration);
    $fields += migrate_handler_invoke_all('Group', 'fields', $this->entityType, $this->bundle, $migration);
    // print_r($fields);
    return $fields;
  }

  /**
   * Delete a batch of group at once.
   *
   * @param $gids
   *  Array of group IDs to be deleted.
   */
  public function bulkRollback(array $gids) {
    migrate_instrument_start('group_delete_multiple');
    $this->prepareRollback($gids);
    group_delete_multiple($gids);
    $this->completeRollback($gids);
    migrate_instrument_stop('group_delete_multiple');
  }

  /**
   * Import a single group.
   *
   * @param $group
   *  Group object to build. Prefilled with any fields mapped in the Migration.
   * @param $row
   *  Raw source data object - passed through to prepare/complete handlers.
   * @return array
   *  Array of key fields (gid only in this case) of the group that was saved if
   *  successful. FALSE on failure.
   */
  public function import(stdClass $group, stdClass $row) {
    // Updating previously-migrated content?
    print_r($group);
    print_r($row);
    print_r($this);
    // TODO: Path ID? What the hell is it expecting it to be?
    $new_group = entity_create('group', array(
      'field_extranet_group_countries' => $group->field_extranet_group_countries,
      'url' => array('alias' => $row->path),
      'type' => $group->type,
    ));
    $wrapper = entity_metadata_wrapper('group', $new_group);
    print_r($wrapper->getPropertyInfo());
    $migration = Migration::currentMigration();
    $old_group = new stdClass();
    if (isset($row->migrate_map_destid1)) {
      if (isset($group->gid)) {
        if ($group->gid != $row->migrate_map_destid1) {
          throw new MigrateException(t("Incoming gid !gid and map destination gid !destid1 don't match",
            array('!gid' => $group->gid, '!destid1' => $row->migrate_map_destid1)));
        }
      }
      else {
        $group->gid = $row->migrate_map_destid1;
      }
    }
    if ($migration->getSystemOfRecord() == Migration::DESTINATION) {
      if (!isset($group->gid)) {
        throw new MigrateException(t('System-of-record is DESTINATION, but no destination gid provided'));
      }
      $old_group = group_load($group->gid);
      if (empty($old_group)) {
        throw new MigrateException(t('System-of-record is DESTINATION, but group !gid does not exist', array('!gid' => $group->gid)));
      }
    }

    if (!isset($group->type)) {
      // Default the type to our designated destination bundle (by doing this
      // conditionally, we permit some flexibility in terms of implementing
      // migrations which can affect more than one type).
      $group->type = $this->bundle;
    }

    // Invoke migration prepare handlers
    $this->prepare($group, $row);

    // Trying to update an existing group
    if ($migration->getSystemOfRecord() == Migration::DESTINATION) {
      // Incoming data overrides existing data, so only copy non-existent fields
      foreach ($old_group as $field => $value) {
        // An explicit NULL in the source data means to wipe to old value (i.e.,
        // don't copy it over from $old_group)
        if (property_exists($group, $field) && $group->$field === NULL) {
          // Ignore this field
        }
        elseif (!isset($group->$field)) {
          $group->$field = $old_group->$field;
        }
      }
    }

    if (isset($group->gid)) {
      $updating = TRUE;
    }
    else {
      $updating = FALSE;
    }
    // migrate_instrument is to measure time and memory usage.
    migrate_instrument_start('entity_save');
    /* TODO: Doing the entity_save causes an error: Call to undefined method stdClass::addMember() in GroupController->invoke().
     * TODO: Without it, we get the following error:
     * Error: Call to undefined method stdClass::uri() in entity_class_uri() (line 1146 of                                                   [error]
     * /webdev/fluke-networks-pantheon/sites/all/modules/contrib/entity/entity.module).
     * The problem here is that we're using a stdClass object instead of a Group Entity object.
     */
    // group_entity_save($group, 'group');

    $group->save(); // Fastest, cleanest
    // entity_save('group', $new_group);
    migrate_instrument_stop('entity_save');

    if (isset($group->gid)) {
      if ($updating) {
        $this->numUpdated++;
      }
      else {
        $this->numCreated++;
      }

      if (!empty($fields)) {
        // We actually have something to update.
        $query->fields($fields);
        $query->execute();
      }
      $return = array($group->gid);
    }
    else {
      $return = FALSE;
    }

    $this->complete($group, $row);
    return $return;
  }
}


class MigrateDestinationGroupMembership extends MigrateDestination {
  public function __toString() {
    return t('group-membership');
  }

  static public function getKeySchema() {
    return array(
      'mid' => array(
        'description' => "The group membership's unique ID.",
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
    );
  }

  /**
   * Delete a membership.
   *
   * @param array $mids
   *  IDs to be deleted.
   */
  public function rollback(array $mids) {
    group_membership_delete_multiple($mids);
  }


  /**
   * Delete a batch of memberships at once.
   *
   * @param $mids
   *   Array of membership ids to be deleted.
   */
  public function bulkRollback(array $mids) {
    group_membership_delete_multiple($mids);
  }

  /**
   * Import a single membership.
   *
   * @param $group_membership
   *  Object object to build. Prefilled with any fields mapped in the Migration.
   * @param $row
   *  Raw source data object - passed through to prepare/complete handlers.
   * @return array
   *  Array of key fields of the object that was saved if
   *  successful. FALSE on failure.
   */
  public function import(stdClass $group_membership, stdClass $row) {
    if (empty($group_membership->gid)) {
      throw new MigrateException('Missing group ID.');
    }
    if (empty($group_membership->uid)) {
      throw new MigrateException('Missing user ID.');
    }

    $this->prepare($group_membership, $row);

    // Group roles are NOT the same as Drupal roles.
    if (!isset($group_membership->roles)) {
      $group_membership->roles = array();
    }

    entity_save('group_membership', $group_membership);
    $this->complete($group_membership, $row);
    return array($group_membership->mid);
  }

  /**
   * Give handlers a shot at modifying the object before saving it.
   *
   * @param $group_membership
   *   OGMembership object to build. Prefilled with any fields mapped in
   *   the Migration.
   * @param $source_row
   *   Raw source data object - passed through to prepare handlers.
   */
  public function prepare($group_membership, stdClass $row) {
    // We do nothing here but allow child classes to act.
    $migration = Migration::currentMigration();
    $group_membership->migrate = array(
      'machineName' => $migration->getMachineName(),
    );

    // Call any general handlers.
    migrate_handler_invoke_all('group_membership', 'prepare', $group_membership, $row);
    // Then call any prepare handler for this specific Migration.
    if (method_exists($migration, 'prepare')) {
      $migration->prepare($group_membership, $row);
    }
  }

  /**
   * Give handlers a shot at modifying the object (or taking additional action)
   * after saving it.
   *
   * @param $group_membership
   *   OGMembership object to build. This is the complete object after
   *   saving.
   * @param $source_row
   *   Raw source data object - passed through to complete handlers.
   */
  public function complete($group_membership, stdClass $row) {
    // We do nothing here but allow child classes to act.
    $migration = Migration::currentMigration();
    $group_membership->migrate = array(
      'machineName' => $migration->getMachineName(),
    );

    // Call any general handlers.
    migrate_handler_invoke_all('group_membership', 'complete', $group_membership, $row);
    // Then call any complete handler for this specific Migration.
    if (method_exists($migration, 'complete')) {
      $migration->complete($group_membership, $row);
    }
  }

  public function fields() {
    return array(
      'gid' => 'Group entity id',
      'uid' => 'User ID',
      'roles' => 'Array of role names to assign to the user in this group.',
    );
  }
}


/**
 * Base class for all node migrations - handles commonalities across all
 * supported source Drupal versions.
 *
 * In addition to the arguments supported by DrupalMigration, the following
 * must be passed in the $arguments array:
 *
 * source_type - Drupal 6 content type machine name.
 * destination_type - Drupal 7 content type machine name (bundle).
 *
 * The following optional arguments may be passed:
 *
 * user_migration - Machine name of a user migration, used to establish
 *   dependencies and a sourceMigration for the uid mapping.
 * default_uid - Drupal 7 (destination) uid of the user account to use as
 *   the default.
 * default_language - Default language for the node and node body. Defaults
 *   to LANGUAGE_NONE.
 */
abstract class DrupalGroupMigration extends DrupalMigration {
  /**
   * The source and destination content types (bundles) we're dealing with.
   */
  protected $destinationType;

  /**
   * Default language to apply to the node and it's body field.
   *
   * @var string
   */
  protected $defaultLanguage = LANGUAGE_NONE;

  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    $this->destinationType = $arguments['destination_type'];
    $this->sourceType = $arguments['source_type'];
    if (!empty($arguments['user_migration'])) {
      $user_migration = $arguments['user_migration'];
      $this->dependencies[] = $user_migration;
    }
    if (!empty($arguments['default_language'])) {
      $this->defaultLanguage = $arguments['default_language'];
    }
    parent::__construct($arguments);

    // Document known group type fields
    $this->sourceFields += array(
      'gid' => t('Group ID'),
      'type' => t('Type'),
      'title' => t('Title')
    );

    $this->sourceFields += $this->version->getSourceFields('group', $this->sourceType);
    if ($this->moduleExists('path')) {
      $this->sourceFields['path'] = t('Path alias');
    }

    $this->destination = new MigrateDestinationGroup($this->destinationType);

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'gid' => array('type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Source Group ID',
          'alias' => 'g',
        ),
      ),
      MigrateDestinationGroup::getKeySchema()
    );

    // Setup common mappings
    $this->addSimpleMappings(array('title'));
    $this->addFieldMapping('type')->defaultValue($this->destinationType);

    if ($this->moduleExists('path')) {
      $this->addFieldMapping('path', 'path')
        ->description('Handled in prepareRow');
    }

    if (module_exists('pathauto')) {
      $this->addFieldMapping('pathauto')
        ->description('By default, disable in favor of migrated paths')
        ->defaultValue(0);
    }
  }

  /**
   * Called after the query data is fetched - we'll use this to populate the
   * source row with the CCK fields.
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Add the path to the source row, if relevant
    if ($this->moduleExists('path')) {
      $path = $this->version->getPath('group/' . $row->gid);
      if ($path) {
        $row->path = $path;
      }
    }

    $this->version->getSourceValues($row, $row->gid);
  }
}

/**
 * Base class for all node migrations - handles commonalities across all
 * supported source Drupal versions.
 *
 * In addition to the arguments supported by DrupalMigration, the following
 * must be passed in the $arguments array:
 *
 * source_type - Drupal 6 content type machine name.
 * destination_type - Drupal 7 content type machine name (bundle).
 *
 * The following optional arguments may be passed:
 *
 * user_migration - Machine name of a user migration, used to establish
 *   dependencies and a sourceMigration for the uid mapping.
 * default_uid - Drupal 7 (destination) uid of the user account to use as
 *   the default.
 * default_language - Default language for the node and node body. Defaults
 *   to LANGUAGE_NONE.
 */
abstract class DrupalGroupMembershipMigration extends DrupalMigration {
  /**
   * The source and destination content types (bundles) we're dealing with.
   */
  // protected $destinationType;

  /**
   * Default language to apply to the node and it's body field.
   *
   * @var string
   */
  protected $defaultLanguage = LANGUAGE_NONE;

  /**
   * @param array $arguments
   */
  public function __construct(array $arguments) {
    // $this->destinationType = $arguments['destination_type'];
    // $this->sourceType = $arguments['source_type'];
    if (!empty($arguments['user_migration'])) {
      $user_migration = $arguments['user_migration'];
      $this->dependencies[] = $user_migration;
    }
    if (!empty($arguments['default_language'])) {
      $this->defaultLanguage = $arguments['default_language'];
    }
    parent::__construct($arguments);

    // Document known group membership fields
    $this->sourceFields += [
      'mid' => t('Membership ID'),
      'gid' => t('Group ID'),
      'uid' => t('User ID'),
      'status' => t('Membership Status'),
      'blocked_status' => t('Blocked Status'),
      'blocked_on' => t('Blocked On'),
      'blocked_by' => t('Blocked By'),
      'joined_on' => t('Joined On'),
      'requested_on' => t('Requested On'),
      'approved_on' => t('Approved On'),
      'added_on' => t('Added On'),
      'added_by' => t('Added By'),
      'parent_mid' => t('Parent Membership ID'),
      'heritage' => t('Heritage'),
    ];

    // The source fields here are for membership, not group.
    // TODO: Set manually.
    //$this->sourceFields += $this->version->getSourceFields('group_membership');

    $this->destination = new MigrateDestinationGroupMembership();

    // TODO: Finish map.
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'mid' => array('type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Source Group ID',
          'alias' => 'g',
        ),
      ),
      MigrateDestinationGroupMembership::getKeySchema()
    );

    // Setup common mappings
    // $this->addSimpleMappings(array('title'));
    // $this->addFieldMapping('type')->defaultValue($this->destinationType);

  }

  /**
   * Called after the query data is fetched - we'll use this to populate the
   * source row with the fields.
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $this->version->getSourceValues($row, $row->mid);
  }
}