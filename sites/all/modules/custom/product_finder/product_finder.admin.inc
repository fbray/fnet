<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 8/31/17
 * Time: 10:59 AM
 */
/**
 * Implements hook_form for admin settings form
 *
 * @param $form
 * @param $form_state
 * @return array
 */
// TODO: This is unneeded. Seriously.
function product_finder_settings_form($form, &$form_state) {
  $form       = array();
  $node_types = _node_types_build();
  $vars       = variable_get('product_finder_settings', array());
  $vocabulary = taxonomy_get_vocabularies();
  $vocabs     = array(); /* Change to array('0' => '--none--'); if you want a none option*/

  foreach ($vocabulary as $item) {
    $key          = $item->vid;
    $value        = $item->name;
    $vocabs[$key] = $value;
  }

  $form['node_type'] = array(
    '#type' => 'select',
    '#title' => t('Content type in use'),
    '#default_value' => $vars['node_type'],
    '#options' => $node_types->names,
    '#description' => t('Content type of industries.'),
    '#required' => TRUE,
  );
  $form['vocabulary'] = array(
    '#type' => 'select',
    '#title' => t('Vocabulary in use'),
    '#default_value' => $vars['vocabulary'],
    '#options' => $vocabs,
    '#description' => t('Vocabulary related to selected content type.'),
    '#required' => TRUE,
  );
  $form['page_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Results per page for pagination'),
    '#default_value' => $vars['page_size'],
    '#size' => 60,
    '#required' => TRUE,
  );
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 10,
  );

  return system_settings_form($form);
}
