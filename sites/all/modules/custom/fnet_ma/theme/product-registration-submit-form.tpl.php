<?php
// $Id: product-registration-submit-form.tpl.php 446 2015-07-14 19:28:26Z sogden1 $

/**
 * @file
 * This file is used to theme the Product Registration Page.
 */

global $base_url;
?>
<div
  class="my-account-headlines header-border_bottom"><?php print t('Register Products'); ?></div>
<div id="product_registration_form">
  <table border="0" cellspacing="0" cellpadding="0" width="70%">
    <tr>
      <td colspan='2'>
        <?php print drupal_render($form['message_submit_form']) . l('How to find the Serial Number', 'node/' . variable_get('fn_myaccount_wtf_location_of_serial_numbers', ''), array(
            'html' => TRUE,
            'attributes' => array('target' => '_blank')
          )); ?>
      </td>
    </tr>
    <tr>
      <td>
        <?php print drupal_render($form['product_serial_number_1']); ?>
      </td>

      <td>
        <?php print drupal_render($form['product_purchase_date_1']); ?>
      </td>
    </tr>
    <tr>
      <td colspan='2'>
        <?php print drupal_render($form['message']); ?>
      </td>
    </tr>
    <tr>
      <td>
        <?php print drupal_render($form['product_serial_number_2']); ?>
      </td>
      <td>
        <?php print drupal_render($form['product_purchase_date_2']); ?>
      </td>
    </tr>
    <tr>
      <td>
        <?php print drupal_render($form['product_serial_number_3']); ?>
      </td>
      <td>
        <?php print drupal_render($form['product_purchase_date_3']); ?>
      </td>
    </tr>
    <tr>
      <td>
        <?php print drupal_render($form['product_serial_number_4']); ?>
      </td>
      <td>
        <?php print drupal_render($form['product_purchase_date_4']); ?>
      </td>
    </tr>
    <tr>
      <td>
        <?php print drupal_render($form['product_serial_number_5']); ?>
      </td>
      <td>
        <?php print drupal_render($form['product_purchase_date_5']); ?>
      </td>
    </tr>
  </table>
</div>

<div id='display_add_more_link'>
  <a href="Javascript://" onclick="return show_more_serial_number();">
    <?php print drupal_render($form['add_more_serial_no']); ?>
  </a>
</div>

<div id="product_registration_form_additional">
  <table border="0" cellspacing="0" cellpadding="0" width="70%">
    <tr>
      <td>
        <?php print drupal_render($form['product_serial_number_6']); ?>
      </td>

      <td>
        <?php print drupal_render($form['product_purchase_date_6']); ?>
      </td>
    </tr>
    <td>
      <?php print drupal_render($form['product_serial_number_7']); ?>
    </td>

    <td>
      <?php print drupal_render($form['product_purchase_date_7']); ?>
    </td>
    </tr>

    <tr>
      <td>
        <?php print drupal_render($form['product_serial_number_8']); ?>
      </td>

      <td>
        <?php print drupal_render($form['product_purchase_date_8']); ?>
      </td>
    </tr>

    <tr>
      <td>
        <?php print drupal_render($form['product_serial_number_9']); ?>
      </td>

      <td>
        <?php print drupal_render($form['product_purchase_date_9']); ?>
      </td>
    </tr>
    <tr>
      <td>
        <?php print drupal_render($form['product_serial_number_10']); ?>
      </td>

      <td>
        <?php print drupal_render($form['product_purchase_date_10']); ?>
      </td>
    <tr>
      <td colspan='2'>
        <?php print drupal_render($form['contact_us_text']); ?>
      </td>
    </tr>
  </table>
  <br/><?php print  t('Note: You can only register 10 products at a time.  To register more products, please complete this process again. '); ?>
  <br/>
</div>

<div id="button_section">
  <table border="0" cellspacing="0" cellpadding="0">
    <tr>
      <td style='margin-right:20px;'>
        <?php print drupal_render($form['clear_form']); ?>
      </td>

      <td>
        <?php print drupal_render($form['submit']); ?>
      </td>
    </tr>
  </table>
</div>

<div>
  <?php
  print drupal_render_children($form);
  ?>
</div>