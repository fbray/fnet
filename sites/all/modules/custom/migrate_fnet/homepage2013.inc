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
    $this->addFieldMapping('field_home13_banner_html:format', 'field_home13_banner_html:format');
    $this->addFieldMapping('field_home13_ads', 'field_home13_ads');
    $this->addFieldMapping('field_home13_ind_desc_1', 'field_home13_ind_desc_1');
    $this->addFieldMapping('field_home13_ind_desc_2', 'field_home13_ind_desc_2');
    $this->addFieldMapping('field_home13_ind_desc_3', 'field_home13_ind_desc_3');

    // Move to common Adtracker field
    $this->addFieldMapping('field_tracking_code', 'field_home13_adtracker');

    // Link Fields
    $this->addFieldMapping('field_home13_exptpc', 'field_home13_exptpc');
    $this->addFieldMapping('field_home13_exptpc:title', 'field_home13_exptpc:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_home13_exptpc:attributes', 'field_home13_exptpc:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_home13_exptpc:language', 'field_home13_exptpc:language')
      ->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_home13_exprle', 'field_home13_exprle');
    $this->addFieldMapping('field_home13_exprle:title', 'field_home13_exprle:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_home13_exprle:attributes', 'field_home13_exprle:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_home13_exprle:language', 'field_home13_exprle:language')
      ->defaultValue(LANGUAGE_NONE);

    $this->addFieldMapping('field_home13_expind', 'field_home13_expind');
    $this->addFieldMapping('field_home13_expind:title', 'field_home13_expind:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_home13_expind:attributes', 'field_home13_expind:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_home13_expind:language', 'field_home13_expind:language')
      ->defaultValue(LANGUAGE_NONE);
  }
}