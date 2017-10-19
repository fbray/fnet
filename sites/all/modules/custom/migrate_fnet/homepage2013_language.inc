<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/22/17
 * Time: 4:15 PM
 */

/*
 *  Homepage2013 Language Migration Class
*/
class FNETHomepage2013LanguageMigration extends FNETNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity')
      ->description(t('No longer necessary as NetScout split is complete.'))
      ->issueGroup(t('DNM'));

    // Individual Fields
    // TODO: Move to fields common with Homepage 2013 content type.
    $this->addFieldMapping('field_home13_banner_html', 'field_home13lng_banner_html');
    $this->addFieldMapping('field_home13_exptpc', 'field_home13lng_exptpc');  // Link
    $this->addFieldMapping('field_home13_exprle', 'field_home13lng_exprle');  // Link
    $this->addFieldMapping('field_home13_expind', 'field_home13lng_expind');  // Link
    $this->addFieldMapping('field_home13_ads', 'field_home13lng_ads');
    $this->addFieldMapping('field_home13_ind_desc_1', 'field_home13lng_ind_desc_1');
    $this->addFieldMapping('field_home13_ind_desc_2', 'field_home13lng_ind_desc_2');
    $this->addFieldMapping('field_home13_ind_desc_3', 'field_home13lng_ind_desc_3');

    // Entity References
    $this->addFieldMapping('field_home13lng_homepage', 'field_home13lng_homepage')
      ->sourceMigration('FNETHomepage2013Migration'); // Uses checkboxes/radio

  }

  public function complete($node, stdClass $row) {
    // Generate URL Redirects.
    parent::generateNodeRedirect($node, $row);
  }
}