<?php

class NameOfYourProfile2Migration extends Migration {
   public function __construct() {
      parent::__construct();
      $this->description = t('Migrate profile2 entities');
      $this->dependencies = array('ExUser', 'Files');

      $this->map = new MigrateSQLMap($this->machineName,
         array(
            'pid' => array(
               'type' => 'int',
               'unsigned' => TRUE,
               'not null' => TRUE,
            )
         ),
         MigrateDestinationProfile2::getKeySchema()
      );

      $query = Database::getConnection('default', 'name_of_old_database')
         ->select('profile', 'p')
         ->fields('p', array('pid','uid'))
         ->condition('p.type', 'type_of_profile_you_are_migrating');

      // Add tables and fields to your query to include all of your profile2 fields
      $query->leftjoin('field_data_field_name_of_your_table', 'fdfnoyt', 'fdfnoyt.entity_id = p.pid');
      $query->addField('fdfnoyt', 'field_name_of_your_source_field');
      $query->addField('fdfnoyt', 'field_name_of_your_other_source_field');
      $query->leftjoin('field_data_field_name_of_your_photo_field_table', 'fdfnoypft', 'fdfnoypft.entity_id = p.pid');
      $query->addField('fdfnoypft', 'field_name_of_your_source_photo_field_fid');
      $query->addField('fdfnoypft', 'field_name_of_your_source_photo_field_alt');
      $query->addField('fdfnoypft', 'field_name_of_your_source_photo_field_title');
      
      $this->source = new MigrateSourceSQL($query);
      $this->destination = new MigrateDestinationProfile2('type_of_profile_you_are_migrating');
      
      // Add user mapping
      $this->addFieldMapping('uid', 'uid')->sourceMigration('User');
      $this->addFieldMapping('revision_uid', 'uid')->sourceMigration('User');

      // Add field mappings
      $this->addFieldMapping('field_name_of_your_destination_field','field_name_of_your_source_field');
      $this->addFieldMapping('field_name_of_your_other_destination_field','field_name_of_your_other_source_field');
      
      // Add photo field mappings
      $this->addFieldMapping('field_name_of_your_destination_photo_field', 'field_name_of_your_source_photo_field_fid')
         ->sourceMigration('Files');
      $this->addFieldMapping('field_name_of_your_destination_photo_field:file_class')
         ->defaultValue('MigrateFileFid');
      $this->addFieldMapping('field_name_of_your_destination_photo_field:alt', 'field_name_of_your_source_photo_field_alt');
      $this->addFieldMapping('field_name_of_your_destination_photo_field:title',
         'field_name_of_your_source_photo_field_title');
   }
}