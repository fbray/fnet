<?php
// $Id$

/**
 * @file
 * This file is used to theme the page that displays the listing of all the
 * Registered Products associated with the user on the My Account Summary page.
 */

global $base_url, $user;
$div_counter = 0;
$image_path = $base_url . '/' . drupal_get_path('module', 'fnet_ma') . '/images/';
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
  <div id='gold_support_section'>
<?php
if (!$array_is_empty) {
  for ($div_counter = 1; $div_counter <= $total_number_of_pages; $div_counter++) {
      ?>
      <div class='full-available-width OneLinkNoTx'>
        <div class='data_divs' id="div_number_<?php print $div_counter; ?>">
          <table class='all_contracts_listing_table'
                 class='full-available-width' border="0" cellspacing="0"
                 cellpadding="5">
            <tr class="border-bottom-1px">
              <td valign="top" class='tableHead-only-border-bottom'
                  width="50%">
                <?php print t('Product Title'); ?>
              </td>
              <td valign="top" class='tableHead-only-border-bottom'
                  width="20%">
                <?php print t('Serial Number'); ?>
              </td>
              <td valign="top" class='tableHead-only-border-bottom'
                  width="15%">
                <?php print t('Purchased <br />dd-mm-yyyy'); ?>
              </td>
              <td valign="top" class='tableHead-only-border-bottom'
                  width="15%">
                <?php print t('Purchased Options'); ?>
              </td>
            </tr>
            <?php
            for ($array_element_count = (($div_counter - 1) * $rows_per_page) + 1; $array_element_count <= ($div_counter * $rows_per_page); $array_element_count++) {
              if (isset($content_array[$array_element_count - 1]) && (trim($content_array[$array_element_count - 1]['vchDescription'] != ''))) {
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

                </tr>
              <?php
              }
            }
            ?>
            <tr>
              <td valign="top" colspan='3' class='see-more-link'>
                <?php print l('(see more...)', 'myaccount/registered-products'); ?>
              </td>
            </tr>
          </table>
        </div>
      </div>
    <?php
    }
}
else {
    ?>
  <div class='full-available-width OneLinkNoTx'>
    <div class='data_divs' id="div_number_<?php print $div_counter++; ?>">
      <table class='all_contracts_listing_table' width="100%" border="0"
             cellspacing="0" cellpadding="5">
        <tr class="border-bottom-1px">
          <td valign="top" class='tableHead-only-border-bottom' width="25%">
            <?php print t('Product Title'); ?>
          </td>
          <td valign="top" class='tableHead-only-border-bottom' width="25%">
            <?php print t('Serial Number'); ?>
          </td>
          <td valign="top" class='tableHead-only-border-bottom' width="25%">
            <?php print t('Purchased <br />dd-mm-yyyy'); ?>
          </td>
          <td valign="top" class='tableHead-only-border-bottom' width="25%">
            <?php print t('Purchased Options'); ?>
          </td>
        </tr>
        <tr>
          <td valign="top" colspan='3' align="left">
            <?php print t('No record found.'); ?>
          </td>
        </tr>
      </table>
      <div id='add-new-products-link-myaccount-page'>
        <?php print theme('fnet_button', array(
          'link' => l("Register a Product", 'myaccount/register-products-step-one', array('html' => TRUE)),
          'auto' => TRUE
        )); ?>
      </div>
    </div>
  </div>
  </div>
<?php
}
?>