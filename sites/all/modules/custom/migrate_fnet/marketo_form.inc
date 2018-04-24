<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/24/17
 * Time: 3:17 PM
 */

/*
 *  Marketo Form Migration Class
*/
class FNETMarketoFormMigration extends FNETNode7Migration {
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
    $this->addFieldMapping('field_banner_html', 'field_mkt_banner_html');
    $this->addFieldMapping('field_banner_html:format', 'field_mkt_banner_html:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_left_content', 'field_mkt_left_content');
    $this->addFieldMapping('field_export_control', 'field_mkt_export_ctrl');
    $this->addFieldMapping('field_enable_share_buttons', 'field_mkt_frm_share');
    $this->addFieldMapping('field_display_footer', 'field_mkt_frm_display_footer');
    $this->addFieldMapping('field_remove_nav', 'field_removenav');
    $this->addFieldMapping('field_form_bottom', 'field_mkt_form_bottom');
    $this->addFieldMapping('field_form_bottom:format', 'field_mkt_form_bottom:format')
      ->defaultValue('full_html');
    $this->addFieldMapping('field_mkt_frm_default_lang', 'field_mkt_frm_default_lang');
    $this->addFieldMapping('field_iframe_height', 'field_mkt_iframe_height');
    $this->addFieldMapping('field_marketo_form_title', 'field_mkt_form_title');
    $this->addFieldMapping('field_bottom_content_cn', 'field_mkt_bot_content_cn');
    $this->addFieldMapping('field_bottom_content_de', 'field_mkt_bot_content_de');
    $this->addFieldMapping('field_bottom_content_en', 'field_mkt_bot_content_en');
    $this->addFieldMapping('field_bottom_content_en_eu', 'field_mkt_bot_content_en_eu');
    $this->addFieldMapping('field_bottom_content_en_in', 'field_mkt_bot_content_en_in');
    $this->addFieldMapping('field_bottom_content_es', 'field_mkt_bot_content_es');
    $this->addFieldMapping('field_bottom_content_fr', 'field_mkt_bot_content_fr');
    $this->addFieldMapping('field_bottom_content_jp', 'field_mkt_bot_content_jp');
    $this->addFieldMapping('field_bottom_content_ko', 'field_mkt_bot_content_ko');
    $this->addFieldMapping('field_bottom_content_pt', 'field_mkt_bot_content_pt');
    $this->addFieldMapping('field_bottom_content_ru', 'field_mkt_bot_content_ru');

    $this->addFieldMapping('field_tracking_code', 'field_mkt_form_adtracker');

    // Link Fields
    $this->addFieldMapping('field_iframe_url_cn', 'field_mkt_iframe_url_cn');
    $this->addFieldMapping('field_iframe_url_cn:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_iframe_url_cn:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_iframe_url_cn:language', 'field_mkt_iframe_url_cn:language')
      ->defaultValue(LANGUAGE_NONE);
    $this->addFieldMapping('field_iframe_url_en', 'field_mkt_iframe_url_en');
    $this->addFieldMapping('field_iframe_url_en:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_iframe_url_en:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_iframe_url_en_eu', 'field_mkt_iframe_url_en_eu');
    $this->addFieldMapping('field_iframe_url_en_in', 'field_mkt_iframe_url_en_in');
    $this->addFieldMapping('field_iframe_url_es', 'field_mkt_iframe_url_es');
    $this->addFieldMapping('field_iframe_url_fr', 'field_mkt_iframe_url_fr');
    $this->addFieldMapping('field_iframe_url_de', 'field_mkt_iframe_url_de');
    $this->addFieldMapping('field_iframe_url_jp', 'field_mkt_iframe_url_jp');
    $this->addFieldMapping('field_iframe_url_ko', 'field_mkt_iframe_url_ko');
    $this->addFieldMapping('field_iframe_url_pt', 'field_mkt_iframe_url_pt');
    $this->addFieldMapping('field_iframe_url_ru', 'field_mkt_iframe_url_ru');

    // Image Files
    $this->addFieldMapping('field_image', 'field_mkt_banner_img')
      ->sourceMigration('Files');
    $this->addFieldMapping('field_image:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_image:preserve_files')
      ->defaultValue(TRUE);
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

    // Convert from text field to integer and remove the 'px' from the value.
    $row->field_mkt_iframe_height[0] = str_replace(['px', 'PX'], '', $row->field_mkt_iframe_height[0]);


  }

}