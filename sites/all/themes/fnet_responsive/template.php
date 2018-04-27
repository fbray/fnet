<?php

/**
 * @file
 * Process theme data.
 *
 * Use this file to run your theme specific implimentations of theme functions,
 * such preprocess, process, alters, and theme function overrides.
 *
 * Preprocess and process functions are used to modify or create variables for
 * templates and theme functions. They are a common theming tool in Drupal,
 * often used as an alternative to directly editing or adding code to templates.
 * It's worth spending some time to learn more about these functions - they are
 * a powerful way to easily modify the output of any template variable.
 *
 * Preprocess and Process Functions
 * SEE: http://drupal.org/node/254940#variables-processor
 * 1. Rename each function and instance of "adaptivetheme_subtheme" to match
 *    your subthemes name, e.g. if your theme name is "footheme" then the
 *    function name will be "footheme_preprocess_hook".
 *    Tip - you can search/replace on "adaptivetheme_subtheme".
 * 2. Uncomment the required function to use.
 */

/**
 * Implements hook_preprocess_page().
 */
function fnet_responsive_preprocess_page(&$variables) {
  // Get the entire main menu tree.
  $main_menu_tree = menu_tree_all_data('menu-main-header-menu');

  // Add the rendered output to the $main_menu_expanded variable.
  $variables['main_menu_expanded'] = menu_tree_output($main_menu_tree);

  // Get the entire Footer menu tree.
  $footer_menu_tree = menu_tree_all_data('menu-footer-more-links');
  // Add the rendered output to the $main_menu_expanded variable.
  $variables['footer_menu_expanded'] = menu_tree_output($footer_menu_tree);
}

/**
 * Implements hook_menu_tree__MENU_NAME().
 */
function fnet_responsive_menu_tree__menu_main_header_menu(&$variables) {
  return '<ul class="menu nav navbar-nav" id="fnet-main-menu">' . $variables['tree'] . '</ul>';
}

/**
 * Implements hook_form_views_exposed_form_alter().
 *
 * Ensures that exposed Select form elements are sorted alphabetically. This
 * helps with Entity Reference select elements.
 *
 * @param $form
 * @param $form_state
 */
function fnet_responsive_form_views_exposed_form_alter(&$form, &$form_state){
  if (isset($form['category']['#options'])) {
    asort($form['category']['#options']);
  }
}
