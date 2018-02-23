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
    // Redirects
    $this->addFieldMapping('migrate_redirects', 'path');

    // Individual Fields
    $this->addFieldMapping('field_fnet_mkto_disp_title', 'field_fnet_mkto_disp_title');
    $this->addFieldMapping('field_fnet_mkto_disp_title:language', 'field_fnet_mkto_disp_title:language')
      ->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('field_fnet_mkto_banner_html', 'field_fnet_mkto_banner_html');
    $this->addFieldMapping('field_fnet_mkto_banner_html:format', 'field_fnet_mkto_banner_html:format');
    $this->addFieldMapping('field_fnet_mkto_main_content', 'field_fnet_mkto_main_content');
    $this->addFieldMapping('field_fnet_mkto_main_content:format', 'field_fnet_mkto_main_content:format');
    $this->addFieldMapping('field_fnet_mkto_export_ctrl', 'field_fnet_mkto_export_ctrl');
    $this->addFieldMapping('field_fnet_mkto_title', 'field_fnet_mkto_title');
    $this->addFieldMapping('field_fnet_mkto_title', 'field_fnet_mkto_title:format');
    $this->addFieldMapping('field_fnet_mkto_form_btm_html', 'field_fnet_mkto_btm_html');
    $this->addFieldMapping('field_fnet_mkto_form_btm_html:format', 'field_fnet_mkto_btm_html:format');
    $this->addFieldMapping('field_fnet_mkto_adtracker', 'field_fnet_mkto_adtracker');
    $this->addFieldMapping('field_fnet_mkto_adtracker:format', 'field_fnet_mkto_adtracker:format');
    $this->addFieldMapping('field_fnet_mkto_form_number', 'field_fnet_mkto_form_number');


    // Link Fields
    // Product Image Left Link
    $this->addFieldMapping('field_fnet_mkto_form_prdimg_llnk', 'field_fnet_mkto_prdimg_llnk');
    $this->addFieldMapping('field_fnet_mkto_form_prdimg_llnk:title', 'field_fnet_mkto_prdimg_llnk:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_fnet_mkto_form_prdimg_llnk:attributes', 'field_fnet_mkto_prdimg_llnk:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_fnet_mkto_form_prdimg_llnk:language', 'field_fnet_mkto_prdimg_llnk:language')
      ->defaultValue(LANGUAGE_NONE);

    // Product Image Right Link
    $this->addFieldMapping('field_fnet_mkto_form_prdimg_rlnk', 'field_fnet_mkto_prdimg_rlnk');
    $this->addFieldMapping('field_fnet_mkto_form_prdimg_rlnk:title', 'field_fnet_mkto_prdimg_rlnk:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_fnet_mkto_form_prdimg_rlnk:attributes', 'field_fnet_mkto_prdimg_rlnk:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_fnet_mkto_form_prdimg_rlnk:language', 'field_fnet_mkto_prdimg_rlnk:language')
      ->defaultValue(LANGUAGE_NONE);

    // Add Links
    $this->addFieldMapping('field_fnet_mkto_add_links', 'field_fnet_mkto_add_links');
    $this->addFieldMapping('field_fnet_mkto_add_links:title', 'field_fnet_mkto_add_links:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_fnet_mkto_add_links:attributes', 'field_fnet_mkto_add_links:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_fnet_mkto_add_links:language', 'field_fnet_mkto_add_links:language')
      ->defaultValue(LANGUAGE_NONE);

    // Marketo Follow Up URL
    $this->addFieldMapping('field_fnet_mkto_form_url', 'field_fnet_mkto_form_url');
    $this->addFieldMapping('field_fnet_mkto_form_url:title', 'field_fnet_mkto_form_url:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_fnet_mkto_form_url:attributes', 'field_fnet_mkto_form_url:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_fnet_mkto_form_url:language', 'field_fnet_mkto_form_url:language')
      ->defaultValue(LANGUAGE_NONE);


    // Image Files
    $this->addFieldMapping('field_fnet_mkto_banner_img', 'field_fnet_mkto_banner_img')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_fnet_mkto_banner_img:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_fnet_mkto_banner_img:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_fnet_mkto_banner_img:title', 'field_fnet_mkto_banner_img:title');
    $this->addFieldMapping('field_fnet_mkto_banner_img:width', 'field_fnet_mkto_banner_img:width');
    $this->addFieldMapping('field_fnet_mkto_banner_img:height', 'field_fnet_mkto_banner_img:height');

    // Product Image Left
    $this->addFieldMapping('field_fnet_mkto_prod_img_left', 'field_fnet_mkto_prod_img_left')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_fnet_mkto_prod_img_left:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_fnet_mkto_prod_img_left:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_fnet_mkto_prod_img_left:title', 'field_fnet_mkto_prod_img_left:title');
    $this->addFieldMapping('field_fnet_mkto_prod_img_left:width', 'field_fnet_mkto_prod_img_left:width');
    $this->addFieldMapping('field_fnet_mkto_prod_img_left:height', 'field_fnet_mkto_prod_img_left:height');

    // Product Image Right
    $this->addFieldMapping('field_fnet_mkto_prod_img_right', 'field_fnet_mkto_prod_img_right')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_fnet_mkto_prod_img_right:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_fnet_mkto_prod_img_right:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_fnet_mkto_prod_img_right:title', 'field_fnet_mkto_prod_img_right:title');
    $this->addFieldMapping('field_fnet_mkto_prod_img_right:width', 'field_fnet_mkto_prod_img_right:width');
    $this->addFieldMapping('field_fnet_mkto_prod_img_right:height', 'field_fnet_mkto_prod_img_right:height');
  }

}