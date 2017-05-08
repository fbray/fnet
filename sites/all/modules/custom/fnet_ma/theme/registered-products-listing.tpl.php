<?php
// $Id$

global $base_url;
$image_path = $base_url . '/' . drupal_get_path('module', 'fnet_ma') . '/images/';

/**
 * @file
 * This file is used to theme the page that displays the listing of all the
 * Registered Products associated with the user.
 */

global $base_url, $user;
//Paging Logic starts from here..!
$content_array = array_values($registered_product_list);
$array_is_empty = FALSE;
$array_total_count = count($content_array);
if ($array_total_count) {
  $rows_per_page = variable_get('myaccount_pager_count', 20);
  $number_of_blocks_created = $array_total_count / $rows_per_page;
  $intpart = intval($number_of_blocks_created);
  $decpart = ($number_of_blocks_created - $intpart);
  if ($decpart > 0) {
    $total_number_of_pages = $intpart + 1;
  }
  else {
    $total_number_of_pages = $intpart;
  }
}
else {
  $array_is_empty = TRUE;
}
?>
  <div class="posRel">
    <div class="dvValid"
         id="helping-instruction-registered-product-listing-page">
      <div class="cnt">
        <?php print t("Click to expand and view content."); ?>
      </div>
    </div>
  </div>

  <div id='registered-product-listing-section-expanding-master-key-div'
       Onclick="return toggle_sections('registered-product-listing-section');"
       class='my-account-headlines my-account-header-minus-background'>
    <?php print t('Registered Products'); ?>
  </div>

  <div id='registered-product-listing-section'
       class='listing-page-helper-section'>
    <?php
    $text = variable_get('myaccount_registered_products_page_text', t('Registering your products enables you to create support incidents. You will need to have the serial number (Or enter SOFTWARE if registering software) and the purchase date of the product.'));
    print check_markup($text, FILTER_FORMAT_DEFAULT, TRUE);
    ?>
  </div>
  <div>
    <?php print theme('fnet_button', array(
      'link' => l("Register a New Product", 'myaccount/register-products-step-one', array('html' => TRUE)),
      'auto' => TRUE
    )); ?>
  </div>
  <div id='gold_support_section'>
    <?php
    if (!$array_is_empty) {
      for ($div_counter = 1; $div_counter <= $total_number_of_pages; $div_counter++) {
        $visible_status = '';
        if ($div_counter == 1) {
          $visible_status = 'display:block';
        }
        else {
          $visible_status = 'display:none';
        }
        ?>
        <div class='full-available-width OneLinkNoTx'>
          <div class='data_divs' id="div_number_<?php print $div_counter; ?>"
               style='<?php print $visible_status; ?>;'>
            <table class='all_contracts_listing_table'
                   class='full-available-width' border="0" cellspacing="0"
                   cellpadding="5">
              <tr>
                <td valign="top" class='tableHead' width="36%">
                  <?php print t('Product Title'); ?>
                </td>
                <td valign="top" class='tableHead' width="15%">
                  <?php print t('Serial Number'); ?>
                </td>
                <td valign="top" class='tableHead' width="12%">
                  <?php print t('Purchased dd-mm-yyyy'); ?>
                </td>
                <td valign="top" class='tableHead' width="12%">
                  <?php print t('Purchased Options'); ?>
                </td>
                <td valign="top" class='tableHead' width="25%">
                  <?php print t('Active Support Incidents'); ?>
                </td>
              </tr>
              <?php
              for ($array_element_count = (($div_counter - 1) * $rows_per_page) + 1; $array_element_count <= ($div_counter * $rows_per_page); $array_element_count++) {
                if (isset($content_array[$array_element_count - 1]['vchDescription']) && trim($content_array[$array_element_count - 1]['vchDescription'] != '')) {
                  ?>
                  <tr <?php print($array_element_count % 2 == 0 ? 'class="trAlternate"' : ''); ?>>
                    <td valign="top">
                      <span
                        class='actual_values'><?php print $content_array[$array_element_count - 1]['vchDescription']; ?></span>
                    </td>

                    <td valign="top">
                      <span
                        class='actual_values'><?php print $content_array[$array_element_count - 1]['vchSerialNumber']; ?></span>
                    </td>

                    <td valign="top">
                      <span
                        class='actual_values'><?php print $content_array[$array_element_count - 1]['dtPurchaseDate']; ?></span>
                    </td>

                    <td valign="top">
                      <span
                        class='actual_values'><?php print $content_array[$array_element_count - 1]['product_purchase_options_links']; ?></span>
                    </td>

                    <td valign="top">
                      <span
                        class='actual_values'><?php print $content_array[$array_element_count - 1]['product_support_incident_count_url']; ?></span><br/>
                      <span
                        class='actual_values'><?php print $content_array[$array_element_count - 1]['product_support_incident_url']; ?></span><br/>
                    </td>
                  </tr>
                <?php
                }
              }
              ?>
            </table>
            <div class='see_more_link_with_pager'>
              <?php
              if ($div_counter != 1) {
                ?>
                <a href='Javascript://'
                   Onclick='return move_backward("<?php print($div_counter - 1); ?>");'>
                <span class='actual_values link_text'>
                  <?php print t('<< Previous&nbsp;&nbsp;&nbsp;'); ?>
                </span>
                </a>
              <?php
              }
              ?>

              <?php
              if ($div_counter != $total_number_of_pages) {
                ?>
                <span class='actual_values link_text'>
                <a href='Javascript://'
                   Onclick='return move_forward("<?php print($div_counter + 1); ?>");'>
                  <?php print t('Next >>'); ?>
                </a>
              </span>
              <?php
              }
              ?>

              <div
                class='page_number'><?php print t('Page - '); ?><?php print $div_counter; ?><?php print t(' of '); ?><?php print $total_number_of_pages ?><?php print t(' Pages.'); ?></div>
            </div>
          </div>
        </div>
      <?php
      }
    }
    else {
      ?>
      <div class='data_divs'>
        <table class='full-available-width' border="0" cellspacing="0"
               cellpadding="0">
          <tr>
            <td valign="top" class='tableHead' width="36%">
              <?php print t('Product Title'); ?>
            </td>
            <td valign="top" class='tableHead' width="15%">
              <?php print t('Serial Number'); ?>
            </td>
            <td valign="top" class='tableHead' width="12%">
              <?php print t('Purchased dd-mm-yyyy'); ?>
            </td>
            <td valign="top" class='tableHead' width="12%">
              <?php print t('Purchased Options'); ?>
            </td>
            <td valign="top" class='tableHead' width="25%">
              <?php print t('Active Support Incidents'); ?>
            </td>
          </tr>
          <tr>
            <td valign="top" colspan='3' align="left" style="padding-top:15px;">
              <?php print t('No record exists.'); ?>
            </td>
          </tr>
        </table>
      </div>
    <?php
    }
    ?>
  </div>
