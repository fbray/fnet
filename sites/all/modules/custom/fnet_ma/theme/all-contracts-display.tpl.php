<?php
// $Id: all-contracts-display.tpl.php 98 2015-05-26 19:58:17Z sogden1 $

/**
 * @file
 * This file is used to theme the page that displays the listing of all the
 * Gold Contracts associated with the Gold Credentials of the User.
 */

global $base_url, $user;
//Paging Logic starts from here..!
$content_array = array_values($all_gold_contracts);
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
<div
  class="my-account-headlines header-border_bottom"><?php print t('Gold Contracts'); ?></div>

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
      <div class='full-available-width'>
        <div class='data_divs' id="div_number_<?php print $div_counter; ?>"
             style='<?php print $visible_status; ?>;'>
          <table class='all_contracts_listing_table'
                 class='full-available-width' border="0" cellspacing="0"
                 cellpadding="5">
            <tr>
              <td valign="top" class='tableHead' width="25%">
                <?php print t('Gold Contracts'); ?>
              </td>
              <td valign="top" class='tableHead' width="25%">
                <?php print t('Expiration<br />dd-mm-yyyy'); ?>
              </td>
              <td valign="top" class='tableHead' width="25%">
                <?php print t('Serial Number'); ?>
              </td>
              <td valign="top" class='tableHead' width="25%">
                <?php print t('Benefits'); ?>
              </td>
            </tr>
            <?php
            for ($array_element_count = (($div_counter - 1) * $rows_per_page) + 1; $array_element_count <= ($div_counter * $rows_per_page); $array_element_count++) {
              if (trim($content_array[$array_element_count - 1]['vchModelNumber'] != '')) {
                ?>
                <tr <?php print($array_element_count % 2 == 0 ? 'class="trAlternate"' : ''); ?>>
                  <td valign="top">
                    <span
                      class='actual_values'><?php print $content_array[$array_element_count - 1]['vchModelNumber']; ?></span>
                  </td>

                  <td valign="top">
                    <span
                      class='actual_values'><?php print $content_array[$array_element_count - 1]['dtExpirationDate']; ?></span>
                  </td>

                  <td valign="top">
                    <span
                      class='actual_values'><?php print $content_array[$array_element_count - 1]['vchSerialNumber']; ?></span>
                  </td>

                  <td valign="top">
                    <span
                      class='actual_values'><?php print l('Access Downloads/Updates', 'myaccount/all-downloads-updates'); ?></span><br/>
                    <span
                      class='actual_values'><?php print l('Create a Support Incident', 'myaccount/report-support-incidents'); ?></span><br/>
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
              <a href='Javascript://'
                 Onclick='return move_forward("<?php print($div_counter + 1); ?>");'>
              <span class='actual_values link_text'>
                <?php print t('Next >>'); ?>
              </span>
              </a>
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
          <td valign="top" colspan='3' align='left'>
            <?php print t('Note: Your gold contracts have expired. You will no longer have access to gold entitlements such as software downloads, exclusive Technical Support and free calibration on products. To renew your gold please !link or contact us at 1-800-283-5853 (United States) or 425-446-4519 (Outside United States).', array(
              '!link' => l('complete this form', 'info/gold/Gold-Contact-Me-Quote', array(
                'html' => TRUE,
                'attributes' => array('target' => '_blank')
              ))
            )); ?>
          </td>
        </tr>
      </table>
    </div>
  <?php
  }
  ?>
</div>