<?php

/**
 * @file
 * Process theme data.
 *
 * Use this file to run your theme specific implimentations of theme functions,
 * such preprocess, process, alters, and theme function overrides.
 *
 * Preprocess and process functions are used to modify or create variables for
 * templates and theme functions. They are a common theming tool in Drupal, often
 * used as an alternative to directly editing or adding code to templates. Its
 * worth spending some time to learn more about these functions - they are a
 * powerful way to easily modify the output of any template variable.
 *
 * Preprocess and Process Functions SEE: http://drupal.org/node/254940#variables-processor
 * 1. Rename each function and instance of "adaptivetheme_subtheme_fnet" to match
 *    your subthemes name, e.g. if your theme name is "footheme" then the function
 *    name will be "footheme_preprocess_hook". Tip - you can search/replace
 *    on "adaptivetheme_subtheme_fnet".
 * 2. Uncomment the required function to use.
 */


/**
 * Preprocess variables for the html template.
 */
/* -- Delete this line to enable.
function adaptivetheme_subtheme_fnet_preprocess_html(&$vars) {
  global $theme_key;

  // Two examples of adding custom classes to the body.

  // Add a body class for the active theme name.
  // $vars['classes_array'][] = drupal_html_class($theme_key);

  // Browser/platform sniff - adds body classes such as ipad, webkit, chrome etc.
  // $vars['classes_array'][] = css_browser_selector();

}
// */
function adaptivetheme_subtheme_fnet_preprocess_html(&$vars) {
  $occupied_column_one = !empty($vars['page']['content_column_one']);
  $occupied_column_two = !empty($vars['page']['content_column_two']);
  $occupied_column_three = !empty($vars['page']['content_column_three']);
  if ($occupied_column_one && $occupied_column_two && $occupied_column_three) {
    $vars['classes_array'][] = 'nested-content-columns-3';

  } elseif (
    ($occupied_column_one && $occupied_column_two)
    || ($occupied_column_one && $occupied_column_three)
    || ($occupied_column_two && $occupied_column_three)
  ) {

    $vars['classes_array'][] = 'nested-content-columns-2';
  }
}


/**
 * Process variables for the html template.
 */
/* -- Delete this line if you want to use this function
function adaptivetheme_subtheme_fnet_process_html(&$vars) {
}
// */


/**
 * Override or insert variables for the page templates.
 */

function adaptivetheme_subtheme_fnet_preprocess_page(&$vars) {
  $header = drupal_get_http_header('status');
  if ($header == "404 Not Found") {
    $vars['theme_hook_suggestions'][] = 'page__404';
  }
  if ($header == "403 Forbidden") {
    $vars['theme_hook_suggestions'][] = 'page_403';
  }
  if (isset($vars['node'])) {
    $vars['theme_hook_suggestion'] = 'page__type__' . $vars['node']->type;
  }
}

/*
function adaptivetheme_subtheme_fnet_process_page(&$vars) {
}
// */


/**
 * Override or insert variables into the node templates.
 */

function adaptivetheme_subtheme_fnet_preprocess_node(&$vars, $hook) {
  if($vars['view_mode'] == 'search_result') {
    $vars['theme_hook_suggestions'][] = 'search_result';  // Default to the basic search result template.
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__search_result';
  }
}

function adaptivetheme_subtheme_fnet_process_node(&$vars) {
}



/**
 * Override or insert variables into the comment templates.
 */
/* -- Delete this line if you want to use these functions
function adaptivetheme_subtheme_fnet_preprocess_comment(&$vars) {
}
function adaptivetheme_subtheme_fnet_process_comment(&$vars) {
}
// */


/**
 * Override or insert variables into the block templates.
 */
/* -- Delete this line if you want to use these functions
function adaptivetheme_subtheme_fnet_preprocess_block(&$vars) {
}
function adaptivetheme_subtheme_fnet_process_block(&$vars) {
}
// */

function adaptivetheme_subtheme_fnet_form_element($variables) {
  $element = &$variables['element'];

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = array('form-item');
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }

  $form_wrapper_id = (!empty($element['#id'])) ? $element['#id']."-wrapper" : '';

  $output = '<div' . drupal_attributes($attributes) . ' id="'.$form_wrapper_id.'">' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= '<div class="description">' . $element['#description'] . "</div>\n";
  }

  $output .= "</div>\n";

  return $output;
}

function adaptivetheme_subtheme_fnet_fnet_button($variables) {
  if (isset($variables['auto']) && $variables['auto']) {
    $button_class = 'btn_auto';
  }
  else {
    $button_class = 'btn_default';
  }
  if (isset($variables['class'])) {
    $button_class = $variables['class'];
  }
  $output = '<div class="' . $button_class . '">';
  $output .= $variables['link'];
  $output .= '</div>';
  return $output;
}

function adaptivetheme_subtheme_fnet_theme($existing, $type, $theme, $path) {
  return array(
    'fnet_button' => array(
      'link' => NULL,
      'auto' => NULL,
    )
  );
}


/**
 * Returns HTML for a breadcrumb trail.
 *
 * Adaptivetheme renders breadcrumbs as an ordered list (<ol>...</ol>), wrapping
 * crumbs in li elements and the seperators in span elements. Additionally .crumb,
 * .crumb-first and .crumb-last classes are printed on the li elements. We also
 * remove some silly breadcrumbs from various pages.
 *
 * @param $vars
 *   An associative array containing:
 *   - breadcrumb: An array containing the breadcrumb links.
 */
function adaptivetheme_subtheme_fnet_breadcrumb($vars) {
  global $theme_key;
  $theme_name = $theme_key;
  $breadcrumb = $vars['breadcrumb'];
  if (function_exists('fnet_header_footer_breadcrumb')) {
    $breadcrumb = fnet_header_footer_breadcrumb($breadcrumb);
  }

  if (at_get_setting('breadcrumb_display', $theme_name) == 1) {

    if (at_get_setting('breadcrumb_home', $theme_name) == 0) {
      array_shift($breadcrumb);
    }

    // Remove the rather pointless breadcrumbs for reset password and user
    // register pages, they link to the page you are on, doh!
    if (arg(0) === 'user' && (arg(1) === 'password' || arg(1) === 'register')) {
      array_pop($breadcrumb);
    }

    if (!empty($breadcrumb)) {

      $separator = filter_xss_admin(at_get_setting('breadcrumb_separator', $theme_name));

      // Push the page title onto the end of the breadcrumb array
      if (at_get_setting('breadcrumb_title', $theme_name) == 1) {
        if ($page_title = drupal_get_title()) {
          $breadcrumb[] = '<span class="crumb-title">' . $page_title . '</span>';
        }
      }

      $class = 'crumb';
      end($breadcrumb);
      $last = key($breadcrumb);

      $output = '';
      if (at_get_setting('breadcrumb_label', $theme_name) == 1) {
        $output = '<div id="breadcrumb" class="clearfix"><nav class="breadcrumb-wrapper with-breadcrumb-label clearfix" role="navigation" aria-labelledby="breadcrumb-label">';
        $output .= '<h2 id="breadcrumb-label" class="breadcrumb-label">' . t('You are here') . '</h2>';
      }
      else {
        $output = '<div id="breadcrumb" class="clearfix"><nav class="breadcrumb-wrapper clearfix" role="navigation" aria-labelledby="breadcrumb-label">';
        $output .= '<h2 id="breadcrumb-label" class="element-invisible">' . t('You are here') . '</h2>';
      }
      $output .= '<ol id="crumbs" class="clearfix">';
      foreach ($breadcrumb as $key => $crumb) {
        if ($key == $last && count($breadcrumb) != 1) {
          $class = 'crumb crumb-last';
        }
        if ($key == 0) {
          $output .= '<li class="' . $class . ' crumb-first">' . $crumb . '</li>';
        }
        else {
          $output .= '<li class="' . $class . '"><span class="crumb-separator">' . $separator . '</span>' . $crumb . '</li>';
        }
      }
      $output .= '</ol></nav></div>';

      return $output;
    }
  }
  else {
    return;
  }
}
