<?php
/**
 * Module configuration admin form.
 *
 * @param $form
 * @param $form_state
 * @return array|mixed
 */
function marketo_form_admin_form($form, &$form_state) {
  global $user;
  $form = array();
  $regions = marketo_get_regions();
  foreach ($regions as $reg_name => $reg_description) {
    $footer_name = 'marketo_form_footer_' . $reg_name;
    $footer_text = variable_get($footer_name, '');
    $form[$footer_name] = array(
      '#type' => 'textarea',
      '#title' => t('%reg_name (%reg_description) footer', array('%reg_name' => $reg_name, '%reg_description' => $reg_description)),
      '#cols' => 60,
      '#rows' => 4,
      '#required' => false,
      '#description' => 'Enter text for the left hand footer.  Full HTML is allowed.',
      '#default_value' => $footer_text,
    );

  }
  $form = system_settings_form($form);
  return $form;
}
