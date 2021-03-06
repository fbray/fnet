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
    $this->addFieldMapping('field_language_region', 'field_home13lng_lng');
    $this->addFieldMapping('field_home13_banner_html', 'field_home13lng_banner_html');
    $this->addFieldMapping('field_home13_banner_html:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_home13_ads', 'field_home13lng_ads');
    $this->addFieldMapping('field_home13_ads:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_category_description_1', 'field_home13lng_ind_desc_1');
    $this->addFieldMapping('field_category_description_2', 'field_home13lng_ind_desc_2');
    $this->addFieldMapping('field_category_description_3', 'field_home13lng_ind_desc_3');

    // Link Fields
    $this->addFieldMapping('field_home13_exptpc', 'field_home13lng_exptpc');  // Link
    $this->addFieldMapping('field_home13_exptpc:title', 'field_home13lng_exptpc:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_home13_exptpc:attributes', 'field_home13lng_exptpc:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_home13_exprle', 'field_home13lng_exprle');  // Link
    $this->addFieldMapping('field_home13_exprle:title', 'field_home13lng_exprle:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_home13_exprle:attributes', 'field_home13lng_exprle:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_home13_expind', 'field_home13lng_expind');  // Link
    $this->addFieldMapping('field_home13_expind:title', 'field_home13lng_expind:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_home13_expind:attributes', 'field_home13lng_expind:attributes')
      ->defaultValue(NULL);

    // Entity References
    $this->addFieldMapping('field_homepage', 'field_home13lng_homepage')
      ->sourceMigration('homepage2013');

  }

  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    // Check the body field. Replace instances of 'sites/flukenetworks.com' in URLs
    // with 'sites/all'.
    $row->field_home13lng_banner_html = str_replace('/flukenetworks.com/', '/default/', $row->field_home13lng_banner_html);
    $row->field_home13_ads= str_replace('/flukenetworks.com/', '/default/', $row->field_home13_ads);

    // The language/region thing seems to be problematic with the allowed values.
    // Let's trim it down to just the first five characters.
    $row->field_home13lng_lng[0] = substr($row->field_home13lng_lng[0], 0, 5);

    // Also, remove the hard URL.
    $row->field_home13_banner_html = str_replace('https://www.flukenetworks.com/', '/', $row->field_home13_banner_html);
    $row->field_home13_banner_html = str_replace('http://www.flukenetworks.com/', '/', $row->field_home13_banner_html);
    $row->field_home13_ads= str_replace('https://www.flukenetworks.com/', '/', $row->field_home13_ads);
    $row->field_home13_ads= str_replace('http://www.flukenetworks.com/', '/', $row->field_home13_ads);
  }
}