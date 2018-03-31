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
class FNETHomepage2013Migration extends FNETNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Path Alias
    $this->addFieldMapping('path', 'path');

    // Disable Pathauto for now.
    $this->addFieldMapping('pathauto')->defaultValue(0);

    // Redirects
    $this->addFieldMapping('migrate_redirects', 'path');

    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity')
      ->description(t('No longer necessary as NetScout split is complete.'))
      ->issueGroup(t('DNM'));

    // Individual Fields
    $this->addFieldMapping('field_home13_banner_html', 'field_home13_banner_html');
    $this->addFieldMapping('field_home13_banner_html:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_home13_ads', 'field_home13_ads');
    $this->addFieldMapping('field_home13_ads:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_category_description_1', 'field_home13_ind_desc_1');
    $this->addFieldMapping('field_category_description_1:format', 'field_home13_ind_desc_1:format')
      ->defaultValue('plain_text');
    $this->addFieldMapping('field_category_description_2', 'field_home13_ind_desc_2');
    $this->addFieldMapping('field_category_description_2:format', 'field_home13_ind_desc_2:format')
      ->defaultValue('plain_text');
    $this->addFieldMapping('field_category_description_3', 'field_home13_ind_desc_3');
    $this->addFieldMapping('field_category_description_3:format', 'field_home13_ind_desc_3:format')
      ->defaultValue('plain_text');

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

  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Check the body field. Replace and instanes of 'sites/flukenetworks.com' in URLs
    // with 'sites/all'.
    $row->field_home13_banner_html = str_replace('/flukenetworks.com/', '/default/', $row->field_home13_banner_html);
    $row->field_home13_ads= str_replace('/flukenetworks.com/', '/default/', $row->field_home13_ads);

    // Also, remove the hard URL.
    $row->field_home13_banner_html = str_replace('https://www.flukenetworks.com/', '/', $row->field_home13_banner_html);
    $row->field_home13_banner_html = str_replace('http://www.flukenetworks.com/', '/', $row->field_home13_banner_html);
    $row->field_home13_ads= str_replace('https://www.flukenetworks.com/', '/', $row->field_home13_ads);
    $row->field_home13_ads= str_replace('http://www.flukenetworks.com/', '/', $row->field_home13_ads);
  }
}