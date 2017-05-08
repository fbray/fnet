<?php
// $Id:  $

/**
 * Module configuration admin form.
 *
 */
function email_page_admin_form() {
  $form = array();

  $email_template = variable_get('email_page_template', '');
  $form['email_page_template'] = array(
    '#type' => 'textarea',
    '#title' => t('Email page template'),
    '#cols' => 80,
    '#rows' => 20,
    '#required' => true,
    '#description' => 'Enter HTML for email template.  Full HTML is allowed.',
    '#default_value' => $email_template,
  );
  $languages = array(
    'en' => 'English',
    'de' => 'German',
    'fr' => 'French',
    'es' => 'Spanish',
    'ru' => 'Russian',
    'pt' => 'Portuguese',
    'jp' => 'Japanese',
    'ko' => 'Korean',
    'cn' => 'Chinese');
  foreach ($languages as $code => $language){
    $form["email_page_footer_$code"] = array(
      '#type' => 'textarea',
      '#title' => t('%language language footer text', array('%language' => $language)),
      '#cols' => 80,
      '#rows' => 4,
      '#required' => false,
      '#description' => 'Enter HTML for email footer.  Full HTML is allowed. This text will be replaced in template variable %footer.',
      '#default_value' => variable_get("email_page_footer_$code", ''),
    );
  }

  return system_settings_form($form);
}
