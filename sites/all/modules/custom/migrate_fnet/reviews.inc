<?php
class ReviewMigration extends Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);
  }
}

/**
 * Base class for all comment migrations - handles commonalities across all
 * supported source Drupal versions.
 *
 * In addition to the arguments supported by DrupalMigration, the following
 * must be passed in the $arguments array:
 *
 * source_type - Drupal 6 content type machine name.
 * destination_type - Drupal 7 entity machine name (@todo: set automatically)
 * node_migration - The node migration machine name for source_type
 *
 * The following optional arguments may be passed:
 *
 * user_migration - Machine name of a user migration, used to establish
 *   dependencies and a sourceMigration for the uid mapping.
 * node_migration - Machine name of the parent node migration.
 * default_uid - Drupal 7 (destination) uid of the user account to use as
 *   the default.
 */
class PlayOn6ReviewMigration extends Migration {

  protected $sourceType;
  protected $destinationType;
  protected $nodeMigration;

  /**
   * @param array $arguments
   */
   public function __construct(array $arguments) {
    // $this->sourceType = $arguments['source_type'];
    $this->destinationType = $arguments['destination_type'];
    if (!empty($arguments['node_migration'])) {
      $this->nodeMigration = $arguments['node_migration'];
      $this->dependencies[] = $this->nodeMigration;
    }

    if (!empty($arguments['user_migration'])) {
      $user_migration = $arguments['user_migration'];
      $this->dependencies[] = $user_migration;
    }
  
    parent::__construct($arguments);
    
    /*$this->sourceFields += $this->version->getSourceFields(
      'comment', 'comment_node_' . $this->sourceType);  // Change this to the plugin_review table. */
    // Create our three main objects - source, destination, and map
    $query = Database::getConnection('default', 'drupal6plugin')
      ->select('plugin_review', 'pr')
      ->fields('pr', array('id', 'nid', 'vid', 'uid', 'content',
               'created', 'approve', 'email', 'fb_id'));
    $query->condition('approve', '9999', '<>'); // Leave out users with approve status of 9999. Those ones are spam.
           
    $this->source = new MigrateSourceSQL($query);
    // Note that the machine name passed for comment migrations is
    // 'comment_node_' followed by the machine name of the node type these
    // comments are attached to.
    $this->destination = new MigrateDestinationComment('comment_node_' . $this->destinationType);

    $this->map = new MigrateSQLMap($this->machineName,
      array('id' => array(
            'type' => 'int',
            'not null' => TRUE,
           )
         ),
      MigrateDestinationComment::getKeySchema()
    );

    // Mapped fields
    if (!empty($this->nodeMigration)) {
      $this->addFieldMapping('nid', 'nid')
           ->sourceMigration($this->nodeMigration);
    }
    else {
      $this->addFieldMapping('nid', 'nid');
    }
    
    if (isset($arguments['default_uid'])) {
      $default_uid = $arguments['default_uid'];
    }
    else {
      $default_uid = 0;
    }
    if (isset($user_migration)) {
      $this->addFieldMapping('uid', 'uid')
           ->sourceMigration($user_migration)
           ->defaultValue($default_uid);
    }
    else {
      $this->addFieldMapping('uid')
           ->defaultValue($default_uid);
    }
    
    $this->addFieldMapping('created', 'created');
    $this->addFieldMapping('language')
      ->defaultValue('en');
    $this->addFieldMapping('mail', 'email');
    $this->addFieldMapping('comment_body', 'content');
    $this->addFieldMapping('comment_body:language')
      ->defaultValue('en');
    $this->addFieldMapping('comment_body:format')
      ->defaultValue('plain_text');
    $this->addFieldMapping('status')
      ->defaultValue('2');
    $this->addFieldMapping('pid')
      ->defaultValue(NULL);
    $this->addFieldMapping('subject')
      ->defaultValue(NULL);

    // No unmapped source fields

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array(
      'changed',
       // 'comment_body:format', 'comment_body:language',
     // 'created',
      'homepage',
      'hostname',
      //'language',
      'thread',
    ));

    $destination_fields = $this->destination->fields();
    if (isset($destination_fields['path'])) {
      $this->addFieldMapping('path')
           ->issueGroup(t('DNM'));
      if (isset($destination_fields['pathauto'])) {
        $this->addFieldMapping('pathauto')
             ->issueGroup(t('DNM'));
      }
    } 
  }
}