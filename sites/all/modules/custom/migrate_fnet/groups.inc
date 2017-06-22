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
    $migration = Migration::currentMigration();
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

    migrate_instrument_start('entity_save');
    group_save($group);
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
        'not null' => TRUE,
      ),
    );
  }

  /**
   * Delete a membership.
   *
   * @param $mid
   *  IDs to be deleted.
   */
  public function rollback(array $mid) {
    $group_membership = og_membership_load($mid);
    group_membership_delete($group_membership);
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

    // WARNING !!!! This part needs to be checked
    if (isset($group_membership->roles)) {
      foreach ($group_membership->roles as $role_name) {
        $roles[] = user_role_load_by_name($role_name);
      }
      //$group_membership->grantRoles($roles);
      $group_membership->roles = $roles;
    } else {
      $group_membership->roles = array();
    }

    group_membership_save($group_membership);

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
    migrate_handler_invoke_all('og_membership', 'prepare', $group_membership, $row);
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
    migrate_handler_invoke_all('og_membership', 'complete', $group_membership, $row);
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