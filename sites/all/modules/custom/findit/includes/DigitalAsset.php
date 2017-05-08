<?php
// $Id$

/**
 * @file
 * class file for FindItAsset
 *
 */
class DigitalAsset {

  public $AccessLevel;
  public $AssetStatus;
  public $AssetType;
  public $CDN_Path;
  public $CDN_Required;
  public $DocumentId;
  public $edocPath;
  public $EndDate;
  public $ExportCompliance;
  public $FileAsset;
  public $FileSize;
  public $FormProcessingURL;
  public $Id;
  public $Locale;
  public $location;
  public $Name;
  public $nid;
  public $POD_Filename;
  public $POD_Path;
  public $POD_url;
  public $StartDate;
  public $ThumbnailPath;
  public $url;
  public $filename;

  public function __construct($document_id, $locale) {
    $this->DocumentId = $document_id;
    $this->Locale = $locale;
    $this->getAsset();
    $this->make_asset_url();
    $this->make_asset_pod_url();
  }

  private function getAsset() {
    $nid = db_select('field_data_field_dam_document_id', 'd')
      ->fields('d', array('entity_id'))
      ->condition('field_dam_document_id_value', $this->DocumentId)
      ->execute()
      ->fetchField();
    if ($nid) {
      $asset = node_load($nid);
    }
    else {
      $asset = NULL;
    }

    if (!empty($asset)) {
      $this->nid = $nid;
      $this->Id = fnet_common_get_field_value('digital_asset', $asset, 'field_dam_document_id');
      $this->DocumentId = fnet_common_get_field_value('digital_asset', $asset, 'field_dam_document_id');
      $this->AssetStatus = strtolower(fnet_common_get_field_value('digital_asset', $asset, 'field_dam_document_status'));
      $this->Name = preg_replace('/[^a-zA-Z!-?\s]/im', '', $asset->title);
      $this->POD_Filename = fnet_common_get_field_value('digital_asset', $asset, 'field_dam_storage_filename_pod');
      if (!empty($this->POD_Filename)) {
        $this->POD_Path = fnet_common_get_field_value('digital_asset', $asset, 'field_dam_storage_file_folder_po') . '/' . fnet_common_get_field_value('digital_asset', $asset, 'field_dam_storage_filename_pod');
      }
      $this->FileAsset = fnet_common_get_field_value('digital_asset', $asset, 'field_dam_storage_filename');
      $this->FileSize = fnet_common_get_field_value('digital_asset', $asset, 'field_dam_file_size');
      $asset_url = fnet_common_get_field_value('digital_asset', $asset, 'field_dam_edoc_url', 'url');
      if (empty($asset_url)) {
        $this->CDN_Required = TRUE;
        $asset_path = $this->download_path(fnet_common_get_field_value('digital_asset', $asset, 'field_dam_storage_file_folder')) . '/' . fnet_common_get_field_value('digital_asset', $asset, 'field_dam_storage_filename');
        $this->CDN_Path = $asset_path;
        $this->location = 'CDN';
      }
      else {
        $this->CDN_Required = FALSE;
        $this->edocPath = fnet_common_get_field_value('digital_asset', $asset, 'field_dam_edoc_url', 'url');
        $this->location = 'edoc';
      }
      $this->secure = FALSE;
      $form_url = fnet_common_get_field_value('digital_asset', $asset, 'field_dam_form_url', 'url');
      if (!empty($form_url)) {
        $this->FormProcessingURL = $this->fix_form_url($form_url);
      }
      else {
        $this->FormProcessingURL = NULL;
      }
      $this->AssetType = ucwords(fnet_common_get_field_value('digital_asset', $asset, 'field_dam_asset_type'));
      $this->AccessLevel = fnet_common_get_field_value('digital_asset', $asset, 'field_dam_entitlement_level');
      $start_date = fnet_common_get_field_value('digital_asset', $asset, 'field_dam_availability_date');
      $end_date = fnet_common_get_field_value('digital_asset', $asset, 'field_dam_availability_date', 'value2');
      $temp = explode('T', $start_date);
      list($year, $month, $day) = explode('-', $temp[0]);
      $start = mktime(0, 0, 0, $month, $day, $year);
      if (($end_date == $start_date) || empty($end_date)) {
        $end = $start + (60 * 60 * 24 * 365 * 20); //20 years
      }
      else {
        $temp = explode('T', $end_date);
        list($year, $month, $day) = explode('-', $temp[0]);
        $end = mktime(0, 0, 0, $month, $day, $year);
      }
      $this->StartDate = date('Y-m-d', $start);
      $this->EndDate = date('Y-m-d', $end);
      $export_controlled = fnet_common_get_field_value('digital_asset', $asset, 'field_dam_export_controlled');
      if (($export_controlled == 1) || ($export_controlled == 'yes')) {
        $this->ExportCompliance = TRUE;
      }
      else {
        $this->ExportCompliance = FALSE;
      }
      $this->Locale = fnet_common_get_field_value('digital_asset', $asset, 'field_dam_language');
      $this->ThumbnailPath = fnet_common_get_field_value('digital_asset', $asset, 'field_dam_thumbnail');
    }
  }

  private function download_path($ftp_file_folder) {
    $tree = explode('/', $ftp_file_folder);
    // get rid of empty element caused by leading /
    if (empty($tree[0])) {
      array_shift($tree);
    }
    // get rid of /published
    if (strtolower($tree[0]) == 'published') {
      array_shift($tree);
    }
    // get rid of /FNet
    if (strtolower($tree[0]) == 'fnet') {
      array_shift($tree);
    }
    $path = implode('/', $tree);
    return $path;
  }

  private function make_asset_url() {
    if (($this->CDN_Required) && (!empty($this->CDN_Path))) {
      $base_path = variable_get('findit_level3_base_http_url', 'http://download.flukenetworks.com/');
      $this->url = $base_path . $this->CDN_Path;
      $parts = explode('/', $this->CDN_Path);
      $this->filename = $parts[count($parts) - 1];
    }
    elseif (preg_match('%http://|https://|ftp://%i', $this->edocPath)) {
      $this->url = $this->edocPath;
    }
  }

  private function make_asset_pod_url() {
    if (!empty($this->POD_Filename)) {
      $base_path = variable_get('findit_level3_base_http_url', 'http://download.flukenetworks.com/');
      $this->POD_url = $base_path . $this->POD_Path;
    }
  }

  private function fix_form_url($url) {
    $serverName = $_SERVER['SERVER_NAME'];
    $parsed_url = parse_url($url);
    if ($parsed_url) {
      if (strtolower($parsed_url['host']) == 'www.flukenetworks.com') {
        $fixed_url = $parsed_url['scheme'] . '://';
        $fixed_url .= $serverName . $parsed_url['path'] . '?' . $parsed_url['query'];
        return $fixed_url;
      }
      else {
        return $url;
      }
    }
    else {
      return NULL;
    }
  }
}
