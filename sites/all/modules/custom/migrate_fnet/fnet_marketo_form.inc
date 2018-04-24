<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 2/21/18
 * Time: 12:56 PM
 */


/*
 *  FNET Marketo Form 2.0 Migration Class
*/
class FNETNewMarketoFormMigration extends FNETNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Path Alias
    $this->addFieldMapping('path', 'path');

    // Disable Pathauto for now.
    $this->addFieldMapping('pathauto')->defaultValue(0);

    // Redirects
    $this->addFieldMapping('migrate_redirects', 'path');

    // Individual Fields
    $this->addFieldMapping('field_fnet_mkto_disp_title', 'field_fnet_mkto_disp_title');
    $this->addFieldMapping('field_fnet_mkto_disp_title:language', 'field_fnet_mkto_disp_title:language')
      ->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('field_fnet_mkto_banner_html', 'field_fnet_mkto_banner_html');
    $this->addFieldMapping('field_fnet_mkto_banner_html:format', 'field_fnet_mkto_banner_html:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_fnet_mkto_banner_html:language', 'field_fnet_mkto_banner_html:language')
      ->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('field_fnet_mkto_main_content', 'field_fnet_mkto_main_content');
    $this->addFieldMapping('field_fnet_mkto_main_content:format', 'field_fnet_mkto_main_content:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_fnet_mkto_main_content:language', 'field_fnet_mkto_main_content:language')
      ->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('field_fnet_mkto_export_ctrl', 'field_fnet_mkto_export_ctrl');
    $this->addFieldMapping('field_fnet_mkto_title', 'field_fnet_mkto_title');
    $this->addFieldMapping('field_fnet_mkto_title:format', 'field_fnet_mkto_title:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_fnet_mkto_title:language', 'field_fnet_mkto_title:language')
      ->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('field_fnet_mkto_form_btm_html', 'field_fnet_mkto_form_btm_html');
    $this->addFieldMapping('field_fnet_mkto_form_btm_html:format', 'field_fnet_mkto_form_btm_html:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_fnet_mkto_form_btm_html:language', 'field_fnet_mkto_form_btm_html:language')
      ->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('field_fnet_mkto_adtracker', 'field_fnet_mkto_adtracker');
    $this->addFieldMapping('field_fnet_mkto_adtracker:format', 'field_fnet_mkto_adtracker:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_fnet_mkto_form_number', 'field_fnet_mkto_form_number');


    // Link Fields
    // Product Image Left Link
    $this->addFieldMapping('field_fnet_mkto_form_prdimg_llnk', 'field_fnet_mkto_form_prdimg_llnk');
    $this->addFieldMapping('field_fnet_mkto_form_prdimg_llnk:title', 'field_fnet_mkto_form_prdimg_llnk:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_fnet_mkto_form_prdimg_llnk:attributes', 'field_fnet_mkto_form_prdimg_llnk:attributes')
      ->defaultValue(NULL);

    // Product Image Right Link
    $this->addFieldMapping('field_fnet_mkto_form_prdimg_rlnk', 'field_fnet_mkto_form_prdimg_rlnk');
    $this->addFieldMapping('field_fnet_mkto_form_prdimg_rlnk:title', 'field_fnet_mkto_form_prdimg_rlnk:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_fnet_mkto_form_prdimg_rlnk:attributes', 'field_fnet_mkto_form_prdimg_rlnk:attributes')
      ->defaultValue(NULL);

    // Add Links
    $this->addFieldMapping('field_fnet_mkto_add_links', 'field_fnet_mkto_add_links');
    $this->addFieldMapping('field_fnet_mkto_add_links:title', 'field_fnet_mkto_add_links:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_fnet_mkto_add_links:attributes', 'field_fnet_mkto_add_links:attributes')
      ->defaultValue(NULL);

    // Marketo Follow Up URL
    $this->addFieldMapping('field_fnet_mkto_form_url', 'field_fnet_mkto_form_url');
    $this->addFieldMapping('field_fnet_mkto_form_url:title', 'field_fnet_mkto_form_url:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_fnet_mkto_form_url:attributes', 'field_fnet_mkto_form_url:attributes')
      ->defaultValue(NULL);


    // Image Files
    $this->addFieldMapping('field_fnet_mkto_banner_img', 'field_fnet_mkto_banner_img')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_fnet_mkto_banner_img:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_fnet_mkto_banner_img:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_fnet_mkto_banner_img:title', 'field_fnet_mkto_banner_img:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_fnet_mkto_banner_img:alt', 'field_fnet_mkto_banner_img:alt')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_fnet_mkto_banner_img:language', 'field_fnet_mkto_banner_img:language')
      ->defaultValue(LANGUAGE_NONE);

    // Product Image Left
    $this->addFieldMapping('field_fnet_mkto_prod_img_left', 'field_fnet_mkto_prod_img_left')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_fnet_mkto_prod_img_left:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_fnet_mkto_prod_img_left:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_fnet_mkto_prod_img_left:title', 'field_fnet_mkto_prod_img_left:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_fnet_mkto_prod_img_left:alt', 'field_fnet_mkto_prod_img_left:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_fnet_mkto_prod_img_left:language', 'field_fnet_mkto_prod_img_left:language')
      ->defaultValue(LANGUAGE_NONE);

    // Product Image Right
    $this->addFieldMapping('field_fnet_mkto_prod_img_right', 'field_fnet_mkto_prod_img_right')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_fnet_mkto_prod_img_right:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_fnet_mkto_prod_img_right:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_fnet_mkto_prod_img_right:title', 'field_fnet_mkto_prod_img_right:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_fnet_mkto_prod_img_right:alt', 'field_fnet_mkto_prod_img_right:alt')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_fnet_mkto_prod_img_right:language', 'field_fnet_mkto_prod_img_right:language')
      ->defaultValue(LANGUAGE_NONE);
  }

  /**
   * @param $row
   * @return bool
   */
  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

  }

}