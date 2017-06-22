<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/22/17
 * Time: 4:03 PM
 */

/*
 *  Homepage2013 Migration Class
*/
class FNETHomepage2013Migration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity');

    // Individual Fields
    $this->addFieldMapping('field_home13_banner_html', 'field_home13_banner_html');
    $this->addFieldMapping('field_home13_exptpc', 'field_home13_exptpc');  // Link
    $this->addFieldMapping('field_home13_exprle', 'field_home13_exprle');  // Link
    $this->addFieldMapping('field_home13_expind', 'field_home13_expind');  // Link
    $this->addFieldMapping('field_home13_ads', 'field_home13_ads');
    $this->addFieldMapping('field_home13_ind_desc_1', 'field_home13_ind_desc_1');
    $this->addFieldMapping('field_home13_ind_desc_2', 'field_home13_ind_desc_2');
    $this->addFieldMapping('field_home13_ind_desc_3', 'field_home13_ind_desc_3');
    // Move to common Adtracker field
    $this->addFieldMapping('field_adtracker', 'field_home13_adtracker');

    // Entity References
    $this->addFieldMapping('field_home13_langreg', 'field_home13_langreg')
      ->sourceMigration(''); // TODO: References the admin_homepage2013_language view - Uses checkboxes/radio

  }
}