<?php

/**
 * Implements Admin page for Versiv Configurator module.
 * TODO: Fix the language thing by making this a internationalized variable.
 * TODO: Better yet, remove the variable altogether. We don't change it.
 *
 * Yep. It's a direct port from the Email Page module.
 *
 * @return mixed
 */
function versiv_configurator_admin_form() {
  $form = [];

  $form['email_page_template'] = [
    '#type' => 'textarea',
    '#title' => t('Email page template'),
    '#cols' => 80,
    '#rows' => 20,
    '#required' => TRUE,
    '#description' => 'Enter HTML for email template.  Full HTML is allowed.',
    '#default_value' => variable_get('email_page_template', ''),
  ];
  $languages = [
    'en' => 'English',
    'de' => 'German',
    'fr' => 'French',
    'es' => 'Spanish',
    'ru' => 'Russian',
    'pt' => 'Portuguese',
    'jp' => 'Japanese',
    'ko' => 'Korean',
    'cn' => 'Chinese'
  ];
  foreach ($languages as $code => $language){
    $form["email_page_footer_$code"] = [
      '#type' => 'textarea',
      '#title' => t('%language language footer text', ['%language' => $language]),
      '#cols' => 80,
      '#rows' => 4,
      '#required' => false,
      '#description' => 'Enter HTML for email footer.  Full HTML is allowed. This text will be replaced in template variable %footer.',
      '#default_value' => variable_get("email_page_footer_$code", ''),
    ];
  }

  return system_settings_form($form);
}