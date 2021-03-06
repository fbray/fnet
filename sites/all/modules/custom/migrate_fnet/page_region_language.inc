<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 5/26/17
 * Time: 3:10 PM
 */

/*
 *  Page Region Language Migration Class
*/
class FNETPageRegionLanguageMigration extends FNETNode7Migration {
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
    $this->addFieldMapping('body', 'body');
    $this->addFieldMapping('body:language', 'body:language');
    $this->addFieldMapping('body:format', 'body:format')
      ->defaultValue('full_html');

    $this->addFieldMapping('field_language_region', 'field_page_reg_lang_lng');
    $this->addFieldMapping('field_tracking_code', 'field_page_adtracker');
    $this->addFieldMapping('field_tracking_code:language', 'field_page_adtracker:language');
    // $this->addFieldMapping('field_tracking_code:format', 'field_page_adtracker:format');

    // Entity References
    $this->addFieldMapping('field_page_region', 'field_page_reg_lang_pagereg')
      ->sourceMigration('PageRegion');
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

    $row->body = $this->stripDomain($row->body);
    $row->body = str_ireplace('/flukenetworks.com/files', '/default/files', $row->body);
    $row->body = str_ireplace('/flukenetworks.com/theme', '/all/theme', $row->body);
    // Replaces .js_3.txt or .js_6.txt script tags
    $row->body = preg_replace("/<script\ssrc=\"\/sites\/default\/files\/versiv-configurator\w?.js\S\d.txt\"><\/script>/", '', $row->body);
    $row->body = preg_replace("/<script\ssrc=\"\/sites\/default\/files\/versiv-configurator\S\S\S.js.txt\"><\/script>/", '', $row->body);
    $row->body = preg_replace("/<link href=\"\/sites\/default\/.*\/>/", '', $row->body);


    // The language/region thing seems to be problematic with the allowed values.
    // Let's trim it down to just the first five characters.
    $row->field_page_reg_lang_lng[0] = substr($row->field_page_reg_lang_lng[0], 0, 5);

    // Check for Versiv Configurator nodes.
    $versiv = [
      'versiv-kit-configurator',
      'copper-cable-testers-selection-guide',
      'fiber-tester-selection-guide',
      'telco-selection-guide',
      'copper-cable-termination-tools-selection-guide'
    ];
    foreach ($versiv as $pattern) {
      if (stripos($row->path, $pattern) !== FALSE) {
        // Set the format of the body field to 'Versiv Plague (versiv_plague).
        $row->{'body:format'} = ['versiv_plague'];
        $row->{'field_page_adtracker:format'} = ['versiv_plague'];
      }
      else {
        $row->{'body:format'} = ['full_html'];
        $row->{'field_page_adtracker:format'} = ['full_html'];
      }
    }
  }

  protected function stripDomain($string) {
    $domains = ['http://www.flukenetworks.com/', 'https://www.flukenetworks.com/', 'http://flukenetworks.com/', 'https://flukenetworks.com/'];
    $stripped = str_ireplace($domains, '/', $string);
    return $stripped;
  }
}