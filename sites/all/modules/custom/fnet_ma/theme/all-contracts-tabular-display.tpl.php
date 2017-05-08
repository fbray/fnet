<?php
// $Id$

/**
 * @file
 * This file is used to theme the page that displays the listing of 7 Gold contracts
 * on the User's My Account main page.
 */
global $base_url, $user;
?>
<div id='gold_support_section'>
  <?php
  $content_array = array_values($all_gold_contracts);
  $array_total_count = count($content_array);
  if ($array_total_count != 0) {
    ?>
    <div class='full-available-width'>
      <div id='gold-contract-summary-section-expanding-master-key-div'
           Onclick='return toggle_sections("gold-contract-summary-section");'
           class="my-account-headlines my-account-header-minus-background"><?php print t('Your Gold Support Contracts'); ?></div>
      <table id='gold-contract-summary-section'
             class='all_contracts_listing_table' width="100%" border="0"
             cellspacing="0" cellpadding="5">
        <tr class="border-bottom-1px" style='display:table; width:100%'>
          <td valign="top" class='tableHead-only-border-bottom' width='33%'>
            <?php print t('Gold Contracts'); ?>
          </td>
          <td valign="top" class='tableHead-only-border-bottom' width='33%'>
            <?php print t('Expiration<br />dd-mm-yyyy'); ?>
          </td>
          <td valign="top" class='tableHead-only-border-bottom' width='33%'>
            <?php print t('Serial Number'); ?>
          </td>
        </tr>
        <?php
        for ($array_element_count = 0; $array_element_count < $array_total_count; $array_element_count++) {
          if ($array_total_count > 7) {
            if ($array_element_count == 5) {
              break;
            }
          }
          if (trim($content_array[$array_element_count]['vchModelNumber'] != '')) {
            ?>
            <tr style='display:table; width:100%'>
              <td valign="top" width='33%'>
                <span
                  class='actual_values'><?php print $content_array[$array_element_count]['vchModelNumber']; ?></span>
              </td>

              <td valign="top" width='33%'>
                <span
                  class='actual_values'><?php print $content_array[$array_element_count]['dtExpirationDate']; ?></span>
              </td>

              <td valign="top" width='33%'>
                <span
                  class='actual_values'><?php print $content_array[$array_element_count]['vchSerialNumber']; ?></span>
              </td>
            </tr>
          <?php
          }
        }
        ?>
        <tr>
          <td valign="top" colspan='3' class='see-more-link'>
            <?php print l('(see more...)', 'myaccount/gold-contracts'); ?>
            <?php //print ($array_total_count > 7 ? l('(see more...)', 'myaccount/gold-contracts') : ''); ?>
          </td>
        </tr>
      </table>
    </div>
  <?php
  }
  else {
    ?>
    <div class='full-available-width'>
      <div id='gold-contract-summary-section-expanding-master-key-div'
           Onclick='return toggle_sections("gold-contract-summary-section");'
           class="my-account-headlines my-account-header-minus-background"><?php print t('Your Gold Support Contracts'); ?></div>
      <table id='gold-contract-summary-section'
             class='all_contracts_listing_table' width="100%" border="0"
             cellspacing="0" cellpadding="5">
        <tr>
          <td valign="top" align='left' colspan='3'>
            <?php print t('Note: Your gold contracts have expired. You will no longer have access to gold entitlements such as software downloads, exclusive Technical Support and free calibration on products. To renew your gold please !link or contact us at 1-800-283-5853 (United States) or 425-446-4519 (Outside United States).', array(
              '!link' => l('complete this form', 'info/gold/Gold-Contact-Me-Quote', array(
                'html' => TRUE,
                'attributes' => array('target' => '_blank')
              ))
            )); ?>
          </td>
        </tr>
        <tr>
          <td valign="top" align='left' colspan='3'>
            <div class='add-new-products-link-myaccount-page'>
              <?php print theme('fnet_button', array(
                'link' => l('Add Gold Membership #', 'myaccount/' . $user->uid . '/edit/profile', array(
                'fragment' => 'gold-support-credentials-section',
                'external' => FALSE
                )),
                'auto' => TRUE
              )); ?>
            </div>
          </td>
        </tr>
      </table>
    </div>
  <?php
  }
  ?>
</div>