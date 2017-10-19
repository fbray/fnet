<?php

/**
 * @file
 *   Migrate HUG Users.
 */
 

/**
 * Implements hook_migrate_api()
 *
 * Returns 'api' => 2 for the 7.x-2.x branch of Migrate.
 * Registers the migration classes for the 7.x-2.6 branch of Migrate (including
 * 7.x-2.6+xx-dev).
 */
function group_migrate_test_migrate_api() {
  $api = array(
    'api' => 2,

    // Migration Group GroupMigrateTest
    'groups' => array(
      'GroupMigrateTest' => array(
        'title' => t('GroupMigrateTest Users'),
      ),
    ),
      
    // List of GroupMigrateTest
    'migrations' => array(
      'GroupMigrateTest_Step0_Unit' => array(
        'class_name' => 'GroupMigrateTest_Step0_Unit_Migration',
        'group_name' => 'GroupMigrateTest',
      ),
      'GroupMigrateTest_Step1_User' => array(
        'class_name' => 'GroupMigrateTest_Step1_User_Migration',
        'group_name' => 'GroupMigrateTest',
      ),
      'GroupMigrateTest_Step2_Link_Manager' => array(
        'class_name' => 'GroupMigrateTest_Step2_Link_Manager_Migration',
        'group_name' => 'GroupMigrateTest',
      ),
      'GroupMigrateTest_Step3_Link_Hierarchy' => array(
        'class_name' => 'GroupMigrateTest_Step3_Link_Hierarchy_Migration',
        'group_name' => 'GroupMigrateTest',
      ),
      'GroupMigrateTest_Step4_Attach_UsertoUnit' => array(
        'class_name' => 'GroupMigrateTest_Step4_Attach_UsertoUnit_Migration',
        'group_name' => 'GroupMigrateTest',
      ),
      'GroupMigrateTest_Step5_Profile' => array(
        'class_name' => 'GroupMigrateTest_Step5_Profile_Migration',
        'group_name' => 'GroupMigrateTest',
      ),
   ),
  );
  return $api;
}


/**
 * Migration classes for migrating users and profiles
 *
 * based on: drupal.org/node/1269066#comment-4988994
 * and:      drupal.org/node/1190958#comment-4616032
 */

/**
 * Abstract class as a base for all our migration classes
 */
abstract class GroupMigrateTest_Basic_Migration extends Migration {
  public function __construct($arguments) {
    // Always call the parent constructor first for basic setup
    parent::__construct($arguments);
    // Avoid known line ending issue: drupal.org/node/1152158
    ini_set('auto_detect_line_endings', TRUE);
  }  
}

/**
 * Import Units
 */
class GroupMigrateTest_Step0_Unit_Migration extends GroupMigrateTest_Basic_Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t("Import a CSV file which contains a list of Units");
    $columns = array(
      0 => array('unit',  t('Unit code')),
      1 => array('title', t('Title')),
      2 => array('parent', t('Parent')),
      3 => array('manager', t('Manager')),
    );

    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'group_migrate_test') . '/list_units.csv', $columns, array('header_rows' => 1, 'delimiter' => ';'));
    $this->destination = new MigrateDestinationGroup('unit');
    $this->map = new MigrateSQLMap($this->machineName,
        array('unit' => array(
              'type' => 'varchar',
              'length' => 6,
              'not null' => TRUE,
              'description' => t("Unit code")
            )
        ),
        MigrateDestinationGroup::getKeySchema()
    );

    // Mapped fields
    $this->addFieldMapping('title', 'title') 
      ->defaultValue('')
      ->description(t("The unit's Title"));
    $this->addFieldMapping('group_unit_code', 'unit') 
      ->defaultValue('')
      ->description(t("The unit's Code"));
    $this->addFieldMapping('group_temp_parent', 'parent')
      ->defaultValue('')
      ->description(t("The unit's Parent"));
    $this->addFieldMapping('group_temp_manager', 'manager')
      ->defaultValue('')
      ->description(t("The unit's Manager"));
  }
}

/**
 * Import users
 */
class GroupMigrateTest_Step1_User_Migration extends GroupMigrateTest_Basic_Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $this->description = t("Import a CSV file which contains a list of Users");
    $columns = array(
      5 => array('unit', t("The user's Unit")),
      4 => array('mail', t('E-mail')),
      0 => array('name',  t("Username"))
    );
   
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'group_migrate_test') . '/list_users.csv', $columns, array('header_rows' => 1, 'delimiter' => ';'));
    $this->dependencies = array('GroupMigrateTest_Step0_Unit');
    $this->destination = new MigrateDestinationUser();
    $this->map = new MigrateSQLMap($this->machineName,
        array('name' => array(
              'type' => 'varchar',
              'length' => 4,
              'not null' => TRUE,
              'description' => t("Nom d'utilisateur")
            )
        ),
        MigrateDestinationUser::getKeySchema()
    );
    
    // Connecting the user to the Unit:
    $this->addFieldMapping('user_temp_unit', 'unit') 
      ->defaultValue('')
      ->sourceMigration('GroupMigrateTest_Step0_Unit')
      ->description(t("The user's Unit"));

    // Mapped fields
    $this->addFieldMapping('name', 'name') 
      ->defaultValue('')
      ->callbacks('drupal_strtolower')
      ->description(t("The username"));

    $this->addFieldMapping('mail', 'mail') 
      ->defaultValue('')
      ->description(t("The user's e-mail"));

    $this->addFieldMapping('pass')
      ->defaultValue(implode('',array_rand(array_flip(array_merge(range('a','z'),range('A','Z'),range('0','9'))),8)))
      ->description(t("Password (randomly generated)"));

    $this->addFieldMapping('is_new')
      ->defaultValue(TRUE)
      ->description(t("Create a new user (0|1)"));

    $this->addFieldMapping('roles')
      ->defaultValue(DRUPAL_AUTHENTICATED_RID) 
      ->description(DRUPAL_AUTHENTICATED_RID . t(' = "authenticated user"'));

    $this->addFieldMapping('status')
      ->defaultValue(1)
      ->description(t("User active(1) or disabled(0)"));

    $this->addFieldMapping('timezone')
      ->defaultValue(t('Europe/Zurich'))
      ->description(t("User's time zone"));

    $this->addFieldMapping('language')
      ->defaultValue(t('und'))
      ->description(t("User's language"));

    $this->addFieldMapping('picture')
      ->defaultValue(0)  
      ->description(t("User's picture"));
      
    // Unmapped destination fields
    $this->addUnmigratedDestinations(array(
      'init',
      'role_names',
      'data',
      'theme',
      'signature',
      'signature_format',
      'created',
      'access',
      'login',
    ));  
  }

  public function prepareRow($row) {
    // Get all Unit from the user
    $row->unit = explode('|', $row->unit);
  }
}

/**
 * Add the unit manager
 */
class GroupMigrateTest_Step2_Link_Manager_Migration extends GroupMigrateTest_Basic_Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    // Query to retrieve the manager
    $query = db_select('groups', 'g')->fields('g', array('gid'));
    $query->innerjoin('field_data_group_temp_manager', 'a', "a.entity_type='group' AND a.bundle='unit' AND a.entity_id=g.gid");
    $query->addField('a', 'group_temp_manager_value');
   
    $this->source = new MigrateSourceSQL($query);    
    $this->dependencies = array('GroupMigrateTest_Step1_User');
    $this->destination = new MigrateDestinationGroup('unit');    
    $this->map = new MigrateSQLMap($this->machineName,
        array('gid' => array(
              'type' => 'int',
              'not null' => TRUE,
              'description' => t("Group Id")
            )
        ),
        MigrateDestinationGroup::getKeySchema()
    );
    
    // Mapped fields
    $this->addFieldMapping('group_manager', 'group_temp_manager_value')
      ->defaultValue('')
      ->description(t("Unit's Manager"))
      ->sourceMigration('GroupMigrateTest_Step1_User');
    $this->addFieldMapping('gid', 'gid')
      ->description(t("Group Id"));
  }  
}

/**
 * Create hierarchy between units and add the unit manager
 */
class GroupMigrateTest_Step3_Link_Hierarchy_Migration extends GroupMigrateTest_Basic_Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    // Query to retrieve the parent group
    $query = db_select('groups', 'g')->fields('g', array('gid'));
    $query->innerjoin('field_data_group_temp_parent', 'rp', "rp.entity_type='group' AND rp.bundle='unit' AND rp.entity_id=g.gid");    
    $query->addField('rp', 'group_temp_parent_value');

    $this->source = new MigrateSourceSQL($query);    
    $this->dependencies = array('GroupMigrateTest_Step1_User');
    $this->destination = new MigrateDestinationGroup('unit');    
    $this->map = new MigrateSQLMap($this->machineName,
        array('gid' => array(
              'type' => 'int',
              'not null' => TRUE,
              'description' => t("Group Id")
            )
        ),
        MigrateDestinationGroup::getKeySchema()
    );
    
    // Mapped fields
    $this->addFieldMapping('gid', 'gid')
      ->description(t("Group Id"));
  }
  
  // Add Unit's hierarchy
  public function complete($entity, stdClass $row) {
    // Delete previous link
    db_delete('group_entity')->condition('entity_id', $entity->gid)->condition('entity_type', 'group')->execute();

    // Fetch parent ID and link it to Unit through group_entity table
    $parent_id = db_select('field_data_group_unit_code', 'g')->fields('g', array('entity_id'))->condition('group_unit_code_value', $row->group_temp_parent_value)->execute()->fetchField();
    $query = db_insert('group_entity');
    $query->fields(
      array(
        'gid' => $parent_id,
        'entity_id' => $entity->gid,
        'entity_type' => 'group',
        'bundle' => 'unit',
      )
    );
    $query->execute();
  }
}

/**
 * Attach users to Unit groups
 */
class GroupMigrateTest_Step4_Attach_UsertoUnit_Migration extends GroupMigrateTest_Basic_Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    $query = db_select('users', 'u');
    $query->join('field_data_user_temp_unit', 't', 'u.uid = t.entity_id');
    $query->fields('u', array('uid'));
    $query->fields('t', array('user_temp_unit_value'));

    $this->source = new MigrateSourceSQL($query);
    $this->dependencies = array('GroupMigrateTest_Step1_User');
    $this->destination = new MigrateDestinationGroupMembership();
    $this->map = new MigrateSQLMap($this->machineName,
        array('uid' => array(
              'type' => 'int',
              'not null' => TRUE,
              'description' => t("User Id")
            )
        ),
        MigrateDestinationUser::getKeySchema()
    );
    $this->addFieldMapping('uid', 'uid') 
      ->defaultValue('')
      ->description(t("Entity Type Id (Child)"));
    $this->addFieldMapping('entity_type')
      ->defaultValue('user')
      ->description(t("Entitype Type of child"));
    $this->addFieldMapping('gid', 'user_temp_unit_value')
      ->defaultValue('')
      ->description(t("Group Id (Parent)"));
  }
}

/**
 * Import users profile
 */
class GroupMigrateTest_Step5_Profile_Migration extends GroupMigrateTest_Basic_Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);
    global $user;
    $this->description = t("Import a CSV file which contains a list of Users (fields linked to Profile)");
    $columns = array(
      0 => array('name',      t("Username")),
      1 => array('gender',    t('Gender')),
      2 => array('firstname', t('Firstname')),
      3 => array('lastname',  t('Lastname')),
    );

    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'group_migrate_test') . '/list_users.csv', $columns, array('header_rows' => 1, 'delimiter' => ';'));
    $this->dependencies = array('GroupMigrateTest_Step1_User');
    $this->destination = new MigrateDestinationProfile2('profile_test');
    $this->map = new MigrateSQLMap($this->machineName,
        array('name' => array(
              'type' => 'varchar',
              'length' => 4,
              'not null' => TRUE,
              'description' => t("Username")
            )
        ),
        MigrateDestinationProfile2::getKeySchema()
    );

    // Connecting the profile2 to the user:
    $this->addFieldMapping('uid', 'name')
         ->sourceMigration('GroupMigrateTest_Step1_User')
         ->description(t('The assignment of profile2-items to the respective user'));

    // Mapped fields
    $this->addFieldMapping('profile_test_gender', 'gender')      
      ->defaultValue('')
      ->callbacks(array($this, 'fixGender'))
      ->description(t("The user's gender"));
    $this->addFieldMapping('profile_test_gender:language')
      ->defaultValue(t('und'));

    $this->addFieldMapping('profile_test_firstname', 'firstname')
      ->defaultValue('')
      ->description(t("The user's firstname"));
    $this->addFieldMapping('profile_test_firstname:language')
      ->defaultValue(t('und'));

    $this->addFieldMapping('profile_test_lastname', 'lastname')
      ->defaultValue('')
      ->description(t("The user's lastname"));
    $this->addFieldMapping('profile_test_lastname:language')
      ->defaultValue(t('und'));

    // Some internal fields
    $this->addFieldMapping('revision_uid')
      ->defaultValue($user->uid)
      ->description(t('The user ID of the user, who started the migration'));
    $this->addFieldMapping('language')
      ->defaultValue(t('und'))
      ->description(t("The default language of the user (e.g. 'en', 'fr', 'de')"));
  }
  
  // Transform the values for the gender list
  public function fixGender($gender) {
    $value = 0;
    switch($gender) {
      case 'Sir' : $value = 0;break;
      case 'Madam' : $value = 1;break;
    }
    return $value;
  }  
}