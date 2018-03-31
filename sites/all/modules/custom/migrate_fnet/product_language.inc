<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/26/17
 * Time: 3:13 PM
 */

/*
 * Product Language Migration Class
*/
class FNETProductLanguageMigration extends DrupalNode7Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

    // Put mapping logic here for fields.
    // Path Alias
    $this->addFieldMapping('path', 'path');

    // Disable Pathauto for now.
    $this->addFieldMapping('pathauto')->defaultValue(0);

    // Redirects
    $this->addFieldMapping('migrate_redirects', 'path');
    $this->addFieldMapping('migrate_redirects_language')
      ->defaultValue(LANGUAGE_NONE);

    // Deprecated Fields
    $this->addFieldMapping(NULL, 'field_business_entity')
      ->description(t('No longer necessary as NetScout split is complete.'))
      ->issueGroup(t('DNM'));

    // Individual Fields
    $this->addFieldMapping('field_language_region', 'field_prodlang_language');

    $this->addFieldMapping('field_prodlang_btnact_disable', 'field_prodlang_btnact_disable');
    $this->addFieldMapping('field_prod_btn_cta_size', 	'field_prodlang_btn_cta_size');
    $this->addFieldMapping('field_conversion_code', 	'field_conversion_code_language');
    $this->addFieldMapping('field_conversion_code:format', 	'field_conversion_code_language:format')
      ->defaultValue('full_html');

    $this->addFieldMapping('field_prod_ctab_name_1', 	'field_prodlang_ctab_name_1');
    $this->addFieldMapping('field_prod_ctab_data_1', 	'field_prodlang_ctab_data_1');
    $this->addFieldMapping('field_prod_ctab_name_2', 	'field_prodlang_ctab_name_2');
    $this->addFieldMapping('field_prod_ctab_data_2', 	'field_prodlang_ctab_data_2');
    $this->addFieldMapping('field_prod_ctab_name_3', 	'field_prodlang_ctab_name_3');
    $this->addFieldMapping('field_prod_ctab_data_3', 	'field_prodlang_ctab_data_3');
    $this->addFieldMapping('field_prod_ctab_name_4', 	'field_prodlang_ctab_name_4');
    $this->addFieldMapping('field_prod_ctab_data_4', 	'field_prodlang_ctab_data_4');
    $this->addFieldMapping('field_prod_ctab_name_5', 	'field_prodlang_ctab_name_5');
    $this->addFieldMapping('field_prod_ctab_data_5', 	'field_prodlang_ctab_data_5');

    $this->addFieldMapping('field_prod_carousel_img_srt_1', 	'field_prodlan_carousl_img_srt_1');
    $this->addFieldMapping('field_prod_carousel_img_srt_2', 	'field_prodlan_carousl_img_srt_2');
    $this->addFieldMapping('field_prod_carousel_img_srt_3', 	'field_prodlan_carousl_img_srt_3');
    $this->addFieldMapping('field_prod_carousel_img_srt_4', 	'field_prodlan_carousl_img_srt_4');
    $this->addFieldMapping('field_prod_carousel_img_srt_5', 	'field_prodlan_carousl_img_srt_5');
    $this->addFieldMapping('field_prod_carousel_img_srt_6', 	'field_prodlan_carousl_img_srt_6');
    $this->addFieldMapping('field_prod_carousel_img_srt_7', 	'field_prodlan_carousl_img_srt_7');
    $this->addFieldMapping('field_prod_carousel_img_srt_8', 	'field_prodlan_carousl_img_srt_8');
    $this->addFieldMapping('field_prod_carousel_img_srt_9', 	'field_prodlan_carousl_img_srt_9');
    $this->addFieldMapping('field_prod_carousel_img_srt_10', 	'field_prodlan_carousl_img_srt_10');

    $this->addFieldMapping('field_prodlang_sol_disable', 'field_prodlang_sol_disable');
    $this->addFieldMapping('field_prod_sol_title', 'field_prodlang_sol_title');
    $this->addFieldMapping('field_prod_sol_desc_1', 'field_prodlang_sol_desc_1');
    $this->addFieldMapping('field_prod_sol_desc_2', 'field_prodlang_sol_desc_2');
    $this->addFieldMapping('field_prod_sol_desc_3', 'field_prodlang_sol_desc_3');
    $this->addFieldMapping('field_prod_sol_desc_4', 'field_prodlang_sol_desc_4');

    // Link Fields
    // TODO: URLs should not be absolute using flukenetworks.com. Test and fix if necessary.
    $this->addFieldMapping('field_prod_btn_calltoaction', 	'field_prodlang_btn_calltoaction');
    $this->addFieldMapping('field_prod_btn_calltoaction:title', 	'field_prodlang_btn_calltoaction:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_btn_calltoaction:attributes', 	'field_prodlang_btn_calltoaction:attributes')
      ->defaultValue(NULL);
    
    $this->addFieldMapping('field_prod_wtb_online', 	'field_prodlang_wtb_online');
    $this->addFieldMapping('field_prod_wtb_online:title', 	'field_prodlang_wtb_online:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_wtb_online:attributes', 	'field_prodlang_wtb_online:attributes')
      ->defaultValue(NULL);
    
    $this->addFieldMapping('field_prod_ctab_link_1', 	'field_prodlang_ctab_link_1');
    $this->addFieldMapping('field_prod_ctab_link_1:title', 	'field_prodlang_ctab_link_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_ctab_link_1:attributes', 	'field_prodlang_ctab_link_1:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_ctab_link_2', 	'field_prodlang_ctab_link_2');
    $this->addFieldMapping('field_prod_ctab_link_2:title', 	'field_prodlang_ctab_link_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_ctab_link_2:attributes', 	'field_prodlang_ctab_link_2:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_ctab_link_3', 	'field_prodlang_ctab_link_3');
    $this->addFieldMapping('field_prod_ctab_link_3:title', 	'field_prodlang_ctab_link_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_ctab_link_3:attributes', 	'field_prodlang_ctab_link_3:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_ctab_link_4', 	'field_prodlang_ctab_link_4');
    $this->addFieldMapping('field_prod_ctab_link_4:title', 	'field_prodlang_ctab_link_4:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_ctab_link_4:attributes', 	'field_prodlang_ctab_link_4:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_ctab_link_5', 	'field_prodlang_ctab_link_5');
    $this->addFieldMapping('field_prod_ctab_link_5:title', 	'field_prodlang_ctab_link_5:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_ctab_link_5:attributes', 	'field_prodlang_ctab_link_5:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_prod_video_youtube_url', 	'field_prodlang_video_youtube_url');
    $this->addFieldMapping('field_prod_video_youtube_url:title', 	'field_prodlang_video_youtube_url:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_video_youtube_url:attributes', 	'field_prodlang_video_youtube_url:attributes')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_prod_sol_link_1', 	'field_prodlang_sol_link_1');
    $this->addFieldMapping('field_prod_sol_link_1:title', 	'field_prodlang_sol_link_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_sol_link_1:attributes', 	'field_prodlang_sol_link_1:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_sol_link_2', 	'field_prodlang_sol_link_2');
    $this->addFieldMapping('field_prod_sol_link_2:title', 	'field_prodlang_sol_link_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_sol_link_2:attributes', 	'field_prodlang_sol_link_2:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_sol_link_3', 	'field_prodlang_sol_link_3');
    $this->addFieldMapping('field_prod_sol_link_3:title', 	'field_prodlang_sol_link_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_sol_link_3:attributes', 	'field_prodlang_sol_link_3:attributes')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_sol_link_4', 	'field_prodlang_sol_link_4');
    $this->addFieldMapping('field_prod_sol_link_4:title', 	'field_prodlang_sol_link_4:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_sol_link_4:attributes', 	'field_prodlang_sol_link_4:attributes')
      ->defaultValue(NULL);

    // Image Fields
    $this->addFieldMapping('field_prod_video_img_t_1', 'field_prodlang_video_img_t_1');
    $this->addFieldMapping('field_prod_video_img_t_1:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_video_img_t_1:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_video_img_t_1:alt', 'field_prodlang_video_img_t_1:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_video_img_t_1:title', 'field_prodlang_video_img_t_1:title')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_prod_carousel_img_lg_1', 'field_prodlang_carousel_img_lg_1');
    $this->addFieldMapping('field_prod_carousel_img_lg_1:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_lg_1:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_lg_1:alt', 'field_prodlang_carousel_img_lg_1:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_1:title', 'field_prodlang_carousel_img_lg_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_2', 'field_prodlang_carousel_img_lg_2');
    $this->addFieldMapping('field_prod_carousel_img_lg_2:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_lg_2:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_lg_2:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_3', 'field_prodlang_carousel_img_lg_3');
    $this->addFieldMapping('field_prod_carousel_img_lg_3:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_lg_3:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_lg_3:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_4', 'field_prodlang_carousel_img_lg_4');
    $this->addFieldMapping('field_prod_carousel_img_lg_4:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_lg_4:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_lg_4:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_4:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_5', 'field_prodlang_carousel_img_lg_5');
    $this->addFieldMapping('field_prod_carousel_img_lg_5:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_lg_5:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_lg_5:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_5:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_6', 'field_prodlang_carousel_img_lg_6');
    $this->addFieldMapping('field_prod_carousel_img_lg_6:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_lg_6:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_lg_6:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_6:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_7', 'field_prodlang_carousel_img_lg_7');
    $this->addFieldMapping('field_prod_carousel_img_lg_7:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_lg_7:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_lg_7:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_7:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_8', 'field_prodlang_carousel_img_lg_8');
    $this->addFieldMapping('field_prod_carousel_img_lg_8:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_lg_8:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_lg_8:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_8:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_9', 'field_prodlang_carousel_img_lg_9');
    $this->addFieldMapping('field_prod_carousel_img_lg_9:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_lg_9:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_lg_9:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_9:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_10', 'field_prodlang_carousel_img_lg_0');
    $this->addFieldMapping('field_prod_carousel_img_lg_10:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_lg_10:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_lg_10:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_lg_10:title')
      ->defaultValue(NULL);

    $this->addFieldMapping('field_prod_carousel_img_t_1', 'field_prodlang_carousel_img_t_1');
    $this->addFieldMapping('field_prod_carousel_img_t_1:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_t_1:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_t_1:alt', 'field_prodlang_carousel_img_t_1:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_1:title', 'field_prodlang_carousel_img_t_1:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_2', 'field_prodlang_carousel_img_t_2');
    $this->addFieldMapping('field_prod_carousel_img_t_2:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_t_2:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_t_2:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_2:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_3', 'field_prodlang_carousel_img_t_3');
    $this->addFieldMapping('field_prod_carousel_img_t_3:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_t_3:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_t_3:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_3:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_4', 'field_prodlang_carousel_img_t_4');
    $this->addFieldMapping('field_prod_carousel_img_t_4:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_t_4:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_t_4:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_4:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_5', 'field_prodlang_carousel_img_t_5');
    $this->addFieldMapping('field_prod_carousel_img_t_5:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_t_5:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_t_5:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_5:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_6', 'field_prodlang_carousel_img_t_6');
    $this->addFieldMapping('field_prod_carousel_img_t_6:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_t_6:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_t_6:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_6:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_7', 'field_prodlang_carousel_img_t_7');
    $this->addFieldMapping('field_prod_carousel_img_t_7:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_t_7:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_t_7:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_7:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_8', 'field_prodlang_carousel_img_t_8');
    $this->addFieldMapping('field_prod_carousel_img_t_8:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_t_8:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_t_8:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_8:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_9', 'field_prodlang_carousel_img_t_9');
    $this->addFieldMapping('field_prod_carousel_img_t_9:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_t_9:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_t_9:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_9:title')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_10', 'field_prodlang_carousel_img_t_10');
    $this->addFieldMapping('field_prod_carousel_img_t_10:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_carousel_img_t_10:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_carousel_img_t_10:alt')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_carousel_img_t_10:title')
      ->defaultValue(NULL);


    // File Fields
    $this->addFieldMapping('field_prod_video_lg_1', 'field_prodlang_video_lg_1');
    $this->addFieldMapping('field_prod_video_lg_1:file_class')
      ->defaultValue('MigrateFileFid');
    $this->addFieldMapping('field_prod_video_lg_1:preserve_files')
      ->defaultValue(TRUE);
    $this->addFieldMapping('field_prod_video_lg_1:description', 'field_prodlang_video_lg_1:description')
      ->defaultValue(NULL);
    $this->addFieldMapping('field_prod_video_lg_1:display', 'field_prodlang_video_lg_1:display')
      ->defaultValue(NULL);

    // Entity References
    $this->addFieldMapping('field_source_product', 'field_prodlang_product')
      ->sourceMigration('ProductDisplay');

  }

  /**
   * Implementation of prepareRow()
   *
   * @param $row
   * @return bool
   */
  public function prepareRow($row) {
    // Always include this snippet, in case our parent class decides to ignore the row
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $domains = ['http://www.flukenetworks.com/', 'https://www.flukenetworks.com/', 'http://flukenetworks.com/', 'https://flukenetworks.com/'];
    $row->field_prodlang_btn_calltoaction = $this->stripDomain($row->field_prodlang_btn_calltoaction);
    $row->body = $this->stripDomain($row->body);
    $row->body = str_ireplace('/flukenetworks.com/files', '/default/files', $row->body);
    $row->body = str_ireplace('/flukenetworks.com/theme', '/all/theme', $row->body);

    // The language/region thing seems to be problematic with the allowed values.
    // Let's trim it down to just the first five characters.
    $row->field_prodlang_language[0] = substr($row->field_prodlang_language[0], 0, 5);

  }

  /**
   * Remove the hard-coded Fluke Networks domain from a field.
   *
   * @param $string
   * @return mixed
   */
  protected function stripDomain($string) {
    $domains = ['http://www.flukenetworks.com/', 'https://www.flukenetworks.com/', 'http://flukenetworks.com/', 'https://flukenetworks.com/'];
    $stripped = str_ireplace($domains, '/', $string);
    return $stripped;
  }
}