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
class FNETMarketoFormMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity');

    // TODO: Marketo Forms will move to a mobile-first design, so this needs to be reworked properly.
    // Individual Fields
    $this->addFieldMapping('field_mkt_banner_html', 'field_mkt_banner_html');
    $this->addFieldMapping('field_mkt_left_content', 'field_mkt_left_content');
    $this->addFieldMapping('field_mkt_export_control', 'field_mkt_export_ctrl');
    $this->addFieldMapping('field_mkt_frm_share', 'field_mkt_frm_share');
    $this->addFieldMapping('field_mkt_frm_display_footer', 'field_mkt_frm_display_footer');
    $this->addFieldMapping('field_removenav', 'field_removenav');
    $this->addFieldMapping('field_mkt_form_bottom', 'field_mkt_form_bottom');
    $this->addFieldMapping('field_mkt_form_bottom:format', 'field_mkt_form_bottom:format');

    $this->addFieldMapping('field_iframe_height', 'field_mkt_iframe_height');
    $this->addFieldMapping('field_marketo_form_title', 'field_mkt_form_title');
    $this->addFieldMapping('field_bottom_content_cn', 'field_mkt_bot_content_cn');
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
    $this->addFieldMapping('field_iframe_url_en', 'field_mkt_iframe_url_en');
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
    $this->addFieldMapping('field_mkt_banner_img', 'field_mkt_banner_img')
      ->sourceMigration('Files');


  }
}