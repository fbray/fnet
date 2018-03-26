<?php
// $Id: tabular-support-incident-display.tpl.php 519 2015-07-28 17:41:31Z sogden1 $

/**
 * @file
 * This file is used to theme the block that displays the listing of all the
 * Registered Products associated with the user on the user's My Account Summary page.
 */

global $base_url, $user;
// Paging Logic starts from here..!
$content_array = array_values($support_incidents);
?>
<?php if (isset($content_array[0]) && ($content_array[0] == 'webservice_exception_error')): ?>
  <span class="red-text"><?php print variable_get('myaccount_webservices_failure_notification_message', t('Our apologies. Your request is not currently available. A notification has been delivered to our web team to correct. If you need immediate assistance please call us at +1 425 446-4519.')); ?></span>
<?php else: ?>
  <?php
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
    <?php if (!$array_is_empty): ?>
      <?php for ($div_counter = 1; $div_counter <= $total_number_of_pages; $div_counter++): ?>
        <?php
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
            <table class='support-incident-summary-table'
                   class='full-available-width' border="0" cellspacing="0"
                   cellpadding="5">
              <tr class="border-bottom-1px">
                <td valign="top" class='tableHead-only-border-bottom'
                    width="15%">
                  <?php print t('Support <br />Incident Id'); ?>
                </td>
                <td valign="top" class='tableHead-only-border-bottom'
                    width="30%">
                  <?php print t('Subject'); ?>
                </td>
                <td valign="top" class='tableHead-only-border-bottom'
                    width="20%">
                  <?php print t('Related Product'); ?>
                </td>
                <td valign="top" class='tableHead-only-border-bottom'
                    width="15%">
                  <?php print t('Status'); ?>
                </td>
                <td valign="top" class='tableHead-only-border-bottom'
                    width="20%">
                  <?php print t('Created'); ?>
                </td>
              </tr>
              <?php for ($array_element_count = (($div_counter - 1) * $rows_per_page) + 1; ($array_element_count <= ($div_counter * $rows_per_page) && ($array_element_count <= $array_total_count)); $array_element_count++): ?>
                <?php if (trim($content_array[$array_element_count - 1]['iIncidentId'] != '')): ?>
                  <tr <?php print($array_element_count % 2 == 0 ? 'class="trAlternate"' : ''); ?>>
                    <td valign="top">
                      <span class='actual_values'><?php print $content_array[$array_element_count - 1]['iIncidentId']; ?></span>
                    </td>

                    <td valign="top">
                      <span class='actual_values'><?php print $content_array[$array_element_count - 1]['subject']; ?></span>
                    </td>

                    <td valign="top">
                      <span class='actual_values'><?php print $content_array[$array_element_count - 1]['vchProductDesc']; ?></span>
                    </td>

                    <td valign="top">
                      <span class='actual_values'><?php print $content_array[$array_element_count - 1]['vchStatusDesc']; ?></span>
                    </td>

                    <td valign="top">
                      <span class='actual_values'><?php print $content_array[$array_element_count - 1]['dtInsertDate']; ?></span>
                    </td>
                  </tr>
                <?php endif; ?>
              <?php endfor; ?>
              <tr>
                <td valign="top" colspan='5' class='see-more-link'>
                  <?php if (isset($display) && ($display == 'view-registered-product')): ?>
                    <?php print l(t('(see more...)'), 'myaccount/all-support-incidents/365/' . trim(check_plain(arg(3))));
                    print theme('fnet_button', array(
                      'link' => l(t('Create Support Incident'), 'myaccount/product-support-incidents/' . trim(check_plain(arg(3)))),
                      'auto' => TRUE
                    )); ?>
                  <?php else: ?>
                    <?php print l('(see more...)', 'myaccount/all-support-incidents'); ?>
                  <?php endif; ?>
                </td>
              </tr>
            </table>
          </div>
        </div>
      <?php endfor; ?>
    <?php else: ?>
      <div class='data_divs'>
        <table class='support-incident-summary-table' width="100%" border="0"
               cellspacing="0" cellpadding="5">
          <tr class="border-bottom-1px">
            <td valign="top" class='tableHead-only-border-bottom' width="15%">
              <?php print t('Support <br />Incident Id'); ?>
            </td>
            <td valign="top" class='tableHead-only-border-bottom' width="30%">
              <?php print t('Subject'); ?>
            </td>
            <td valign="top" class='tableHead-only-border-bottom' width="20%">
              <?php print t('Related Product'); ?>
            </td>
            <td valign="top" class='tableHead-only-border-bottom' width="15%">
              <?php print t('Status'); ?>
            </td>
            <td valign="top" class='tableHead-only-border-bottom' width="20%">
              <?php print t('Created <br />dd-mm-yyyy'); ?>
            </td>
          </tr>
          <tr>
            <td valign="top" colspan='3'>
              <?php
              print t('No records found.');
              if (isset($display) && ($display == 'view-registered-product')) {
                print "<br /><br />" . l('Create Support Incident', 'myaccount/product-support-incidents/' . trim(check_plain(arg(3))));
              }
              ?>
            </td>
          </tr>
        </table>
      </div>
      <?php if (isset($display) && ($display != 'view-registered-product')): ?>
        <div id='add-new-products-link-myaccount-page'>
          <?php print theme('fnet_button', array(
            'link' => l(t('Create Support Incident'), 'myaccount/report-support-incidents'),
            'auto' => TRUE
          )); ?>
        </div>
      <?php endif; ?>
    <?php endif; ?>
  </div>
<?php endif; ?>