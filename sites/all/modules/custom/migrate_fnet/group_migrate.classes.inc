<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 6/14/17
 * Time: 11:36 AM
 */


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
  public function import(stdClass $membership, stdClass $row) {
    if (empty($membership->gid)) {
      throw new MigrateException('Missing group ID.');
    }
    if (empty($membership->uid)) {
      throw new MigrateException('Missing user ID.');
    }

    $this->prepare($membership, $row);


    // Group roles are NOT the same as Drupal roles.
    // TODO: We may need to approach this in a different way.
    if (!isset($membership->roles)) {
      $membership->roles = array();
    }
    // print_r($membership);
    $entity_type = 'group_membership';
    $group_membership = entity_create($entity_type, array('type' => 'group_membership'));
    // $wrapper = entity_metadata_wrapper($entity_type, $group_membership);

    $wrapper = entity_metadata_wrapper($entity_type, NULL, array('bundle' => 'group_membership'));
    $info = $wrapper->getPropertyInfo();
    // print_r($info);

    // Convert stdClass into GroupMembership object.
    try {
      // $group_membership = new GroupMembership();
      $group_membership->roles = array(); // $membership->roles;
      $group_membership->gid = $membership->gid;
      $group_membership->uid = $membership->uid;
      $group_membership->status = $membership->status;
      $group_membership->blocked_status = $membership->blocked_status;
      $group_membership->blocked_by = $membership->blocked_by;
      $group_membership->blocked_on = $membership->blocked_on;
      $group_membership->joined_on = $membership->joined_on;
      $group_membership->requested_on = $membership->requested_on;
      $group_membership->approved_on = $membership->approved_on;
      $group_membership->approved_by = $membership->approved_by;
      $group_membership->added_on = $membership->added_on;
      $group_membership->added_by = $membership->added_by;
      $group_membership->parent_membership = $membership->parent_mid;
      $group_membership->heritage = $membership->heritage;

    }
    catch (Exception $e) {
      watchdog('group_membership', $e->getMessage());
    }

    // This is where the data gets saved into the destination
    // $group_membership->save();
    entity_save('group_membership', $group_membership);
    // print_r($group_membership);
    $this->complete($group_membership, $row);
    return array($group_membership->mid);
  }

  /**
   * Give handlers a shot at modifying the object before saving it.
   *
   * @param $group_membership
   *   Group Membership object to build. Prefilled with any fields mapped in
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

    // print_r($group_membership); // This had the correct UIDs!
/*
    if(empty($row->uid)) {
      return FALSE;
    }
*/
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
    // Can we get these automatically?
    return array(
      'roles' => 'Array of role names to assign to the user in this group.',
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
      'approved_by' => t('Approved By'),
      'added_on' => t('Added On'),
      'added_by' => t('Added By'),
      'parent_mid' => t('Parent Membership ID'),
      'heritage' => t('Heritage'),
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
    $this->addFieldMapping('type')->defaultValue($this->destinationType);

  }

  /**
   * Called after the query data is fetched - we'll use this to populate the
   * source row with the CCK fields.
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    print_r($row->uid);

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
      'approved_by' => t('Approved By'),
      'added_on' => t('Added On'),
      'added_by' => t('Added By'),
      'parent_mid' => t('Parent Membership ID'),
      'heritage' => t('Heritage'),
    ];

    $this->destination = new MigrateDestinationGroupMembership();

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
    $this->addFieldMapping('gid', 'gid');
    $this->addFieldMapping('uid', 'uid')
      ->sourceMigration('FNETUser');
    $this->addFieldMapping('status', 'status');
    $this->addFieldMapping('blocked_status', 'blocked_status');
    $this->addFieldMapping('blocked_on', 'blocked_on');
    $this->addFieldMapping('blocked_by', 'blocked_by')
      ->sourceMigration('FNETUser');
    $this->addFieldMapping('joined_on', 'joined_on');
    $this->addFieldMapping('requested_on', 'requested_on');
    $this->addFieldMapping('approved_on', 'approved_on');
    $this->addFieldMapping('approved_by', 'approved_by')
      ->sourceMigration('FNETUser');
    $this->addFieldMapping('added_on', 'added_on');
    $this->addFieldMapping('added_by', 'added_by')
      ->sourceMigration('FNETUser');
    $this->addFieldMapping('parent_mid', 'parent_mid');
    $this->addFieldMapping('heritage', 'heritage');

  }

  /**
   * Called after the query data is fetched - we'll use this to populate the
   * source row with the fields.
   */
  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $result = db_query('SELECT gid FROM {groups} g WHERE g.title = :title', array(':title' => $row->title));
    $record = $result->fetchField(0);
    $row->gid = $record;

    // print_r($row->uid); // This results in the old UID.



    // Roles
    /*
    $roles = [];
    $results = db_query('SELECT role from group_membership_role where mid = :mid', array(':mid' => $row->mid));
    foreach($results as $result) {
      $roles[] = $result->role;
    }
    $row->roles = $roles;
    */

    $row->roles = [];

    $this->version->getSourceValues($row, $row->mid);
  }
}