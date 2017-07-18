<?php

/**
 * @file
 * Provides Features integration for the GlobalLink module to export settings and field configurations.
 */

/**
 * Implementation of hook_features_export_options. [component_hook]
 *
 * This hook will alert features of which specific items of this component may
 * be exported. For instances, in this case, we want to make available all the
 * existing items.  If there are no items to be exported, this component will
 * not be made available in the features export page.
 *
 * @return array
 *   A keyed array of items, suitable for use with a FormAPI select or
 *   checkboxes element.
 */
function globallink_config_features_export_options() {
  $options = array();
  
  //options for globallink settings
  $options['globallink_pd_url'] = 'URL';
  $options['globallink_pd_username'] = 'User Id';
  $options['globallink_pd_password'] = 'Password';
  $options['globallink_pd_projectid'] = 'Project Short Code(s)';
  $options['globallink_pd_submissionprefix'] = 'Submission Name Prefix';
  $options['globallink_pd_classifier'] = 'Classifier';
  $options['globallink_pd_max_target'] = 'Max Target Count';
  
  //options for adaptor settings
  $options['globallink_pager_limit'] = 'Dashboard Pager Limit';
  $options['globallink_enable_preview'] = 'Enable Preview For Receive Translations';
  $options['globallink_implementation_type'] = 'Node/Field Translation Filter Implementation';
  $options['globallink_publish_node'] = 'Publish Translated Content';
  $options['globallink_cron_type'] = 'Automatic Update Status';
  $options['globallink_proxy_url'] = 'Proxy URL';
  $options['globallink_entity_create_revisions'] = 'Create Revisions for Entities';
  
  //options for globallink field configurations settings
  $result = db_query("SELECT locale_code, locale_desc FROM {globallink_locale} WHERE drupal_locale_code NOT LIKE :code", array(':code' => 'NULL'))->fetchAll();
  
  foreach ($result as $row) {
    $options[$row->locale_code] = $row->locale_desc;
  }
  
  //options for globallink field configurations settings
  $query = "SELECT content_type, field_name FROM {globallink_field_config}";
  $result = db_query($query);
 
  foreach ($result as $row) {
    $options[$row->content_type."|".$row->field_name] = ucfirst($row->content_type).':'.$row->field_name;
  }
  return $options;
}

/**
* Implementation of hook_features_export [component hook]
*
* This is a component hook, rather then a module hook, therefore this is the
* callback from hook_features_api which relates to the specific component we
* are looking to export. When a specific instance of the component we are
* looking to export is selected, this will include the necessariy item, plus
* any dependencies into our export array.
*
* @param array $data
* this is the machine name for the component in question
* @param array &$export
* array of all components to be exported
* @param string $module_name
* The name of the feature module to be generated.
* @return array
* The pipe array of further processors that should be called
*/
function globallink_config_features_export($data, &$export, $module_name = '') {
  $export['dependencies']['globallink'] = 'globallink';
  foreach ($data as $component) {
    $export['features']['globallink_config'][$component] = $component;
  }
  return array();
}

/**
 * Implementation of hook_features_export_render. [component hook]
 *
 * This hook will be invoked in order to export
 * Component hook. The hook should be implemented using the name ot the
 * component, not the module, eg. [component]_features_export() rather than
 * [module]_features_export().
 *
 * Render one or more component objects to code.
 *
 * @param string $module_name
 *   The name of the feature module to be exported.
 * @param array $data
 *   An array of machine name identifiers for the objects to be rendered.
 * @param array $export
 *   The full export array of the current feature being exported. This is only
 *   passed when hook_features_export_render() is invoked for an actual feature
 *   update or recreate, not during state checks or other operations.
 * @return array
 *   An associative array of rendered PHP code where the key is the name of the
 *   hook that should wrap the PHP code. The hook should not include the name
 *   of the module, e.g. the key for `hook_example` should simply be `example`.
 */
function globallink_config_features_export_render($module, $data) {
  $code = array();
  foreach ($data as $component) {
    $data_row = array();
    $pos = strpos($component, '|');
    if($pos) {
      $param = explode('|', $component);
      $data_row = db_query(" SELECT * FROM {globallink_field_config} WHERE content_type = :content_type AND field_name = :field_name  ", array(':content_type' => $param[0], ':field_name' => $param[1]))->fetchAll();
    }
    if(count($data_row) > 0) {
      $code[$component] = get_object_vars($data_row[0]);
    } else {
      $result = db_query("SELECT * FROM {globallink_locale} WHERE locale_code = :code", array(':code' => $component))->fetchAll();
      if(count($result) > 0) {
        $code[$component] = get_object_vars($result[0]);
      } else {
        $code[$component] = variable_get($component);
      }
    }
  }
  $code = " return ". features_var_export($code, ' '). ";";
  
  return array('globallink_config_features_default_settings' => $code);
}

/**
* Implementation of hook_features_rebuild(). [component_hook]
*/
function globallink_config_features_rebuild($module) {
  $items = module_invoke($module, 'globallink_config_features_default_settings');
  foreach ($items as $key => $value) {
    $pos = strpos($key, '|');
    if($pos) {
      $params = explode("|", $key);
      $fid = db_query("select fid from {globallink_field_config} where content_type = :content_type AND field_name = :field_name", array(":content_type" => $params[0], ":field_name" => $params[1]))->fetchAll();
      if(count($fid) > 0) {
        db_update('globallink_field_config')
          ->fields(array(
            'content_type' => $value['content_type'],
            'entity_type' => $value['entity_type'],
            'bundle' => $value['bundle'],
            'field_name' => $value['field_name'],
            'field_type' => $value['field_type'],
            'field_label' => $value['field_label'],
            'field_format' => $value['field_format'],
            'translatable' => $value['translatable']
          ))
        ->condition('fid', $fid[0]->fid, '=')
        ->execute();
      } else {
        db_insert('globallink_field_config')
          ->fields(array(
            'content_type' => $value['content_type'],
            'entity_type' => $value['entity_type'],
            'bundle' => $value['bundle'],
            'field_name' => $value['field_name'],
            'field_type' => $value['field_type'],
            'field_label' => $value['field_label'],
            'field_format' => $value['field_format'],
            'translatable' => $value['translatable']
          ))
        ->execute();
      }
    } else {
      $result = db_query("SELECT * FROM {globallink_locale} WHERE locale_code = :code", array(':code' => $key))->fetchAll();
      if(count($result) > 0) {
        db_update('globallink_locale')
        ->fields(array(
            'locale_code' => $value['locale_code'],
            'locale_desc' => $value['locale_desc'],
            'drupal_locale_code' => $value['drupal_locale_code'],
            'drupal_locale_desc' => $value['drupal_locale_desc']
          ))
        ->condition('locale_code', $key, '=')
        ->execute();
      } else {
        variable_set($key, $value);
      }
    }
  }
}

/**
 * Implementation of hook_features_revert(). [component_hook]
 */
function globallink_config_features_revert($module) {
  globallink_config_features_rebuild($module);
}
