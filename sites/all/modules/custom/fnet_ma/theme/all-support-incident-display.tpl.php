<?php
/**
 * @file
 * This file is used to theme the page that displays the listing of all the
 * Support Incidents posted/associated by/with a user.
 */

global $base_url, $user;
//Paging Logic starts from here..!
$content_array = array_values($support_incidents);
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
  <div class="dvValid" id="helping-instruction-support-incidents-listing-page">
    <div class="cnt">
      <?php print t("Click to expand and view content."); ?>
    </div>
  </div>
</div>

<?php if (arg(2) != 'products-all-support-incidents'): ?>
  <div id='all-support-incidents-listing-section-expanding-master-key-div'
       Onclick="return toggle_sections('all-support-incidents-listing-section');"
       class='my-account-headlines my-account-header-minus-background'>
    <?php print t('Support Incidents'); ?>
  </div>

  <div id='all-support-incidents-listing-section'
       class='listing-page-helper-section'>
    <?php
    $text = variable_get('myaccount_support_incidents_page_text', t('You must register a product before opening a support incident for it. Then select the product for the support incident. You can come back at a later time to see updates to the incident.'));
    print check_markup($text, 'plain_text', TRUE);
    ?>
  </div>

  <div>
    <div id='search-past-days-form'>
      <?php print $search_form; ?>
    </div>
    <div id="create-support-incident">
      <?php print theme('fnet_button', array(
        'link' => l('Create Support Incident', 'myaccount/report-support-incidents'),
        'auto' => TRUE
      )); ?>
    </div>
  </div>
<?php endif; ?>
<div id='gold_support_section'>
  <?php if (!$array_is_empty): ?>
    <?php for ($div_counter = 1; $div_counter <= $total_number_of_pages; $div_counter++): ?>
      <?php $visible_status = ($div_counter == 1) ? 'display:block' : 'display:none'; ?>
      <div class='full-available-width OneLinkNoTx'>
        <div class='data_divs' id="div_number_<?php print $div_counter; ?>"
             style='<?php print $visible_status; ?>;'>
          <table class='all-support-incident-table'
                 class='full-available-width' border="0" cellspacing="0"
                 cellpadding="5">
            <tr>
              <td valign="top" class='tableHead' width="15%">
                <?php print t('Support <br />Incident Id'); ?>
              </td>
              <td valign="top" class='tableHead' width="30%">
                <?php print t('Subject'); ?>
              </td>
              <td valign="top" class='tableHead' width="20%">
                <?php print t('Related Product'); ?>
              </td>
              <td valign="top" class='tableHead' width="10%">
                <?php print t('Status'); ?>
              </td>
              <td valign="top" class='tableHead' width="25%">
                <?php print t('Created'); ?>
              </td>
            </tr>
            <?php // for ($array_element_count = (($div_counter - 1) * $rows_per_page) + 1; ($array_element_count <= ($div_counter * $rows_per_page) || $array_element_count < ; $array_element_count++): ?>
            <?php $array_element_count = 1; ?>
            <?php foreach($content_array as $incident): ?>
              <?php if (trim($incident['iIncidentId'] != '')): ?>
                <tr <?php print($array_element_count % 2 == 0 ? 'class="trAlternate"' : ''); ?>>
                  <td valign="top">
                    <span
                      class='actual_values'><?php print $incident['iIncidentId']; ?></span>
                  </td>

                  <td valign="top">
                    <span
                      class='actual_values'><?php print $incident['subject']; ?></span>
                  </td>

                  <td valign="top">
                    <span
                      class='actual_values'><?php print $incident['vchProductDesc']; ?></span>
                  </td>

                  <td valign="top">
                    <span
                      class='actual_values'><?php print $incident['vchStatusDesc']; ?></span>
                  </td>

                  <td valign="top">
                    <span
                      class='actual_values'><?php print $incident['dtInsertDate']; ?></span>
                  </td>
                </tr>
              <?php endif; ?>
              <?php $array_element_count++; ?>
            <?php endforeach; ?>
          </table>
          <div class='see_more_link_with_pager'>
            <?php if ($div_counter != 1): ?>
              <a href='Javascript://'
                 Onclick='return move_backward("<?php print($div_counter - 1); ?>");'>
              <span class='actual_values link_text'>
                <?php print t('<< Previous&nbsp;&nbsp;&nbsp;'); ?>
              </span>
              </a>
            <?php endif;?>

            <?php if ($div_counter != $total_number_of_pages): ?>
              <a href='Javascript://'
                 Onclick='return move_forward("<?php print($div_counter + 1); ?>");'>
              <span class='actual_values link_text'>
                <?php print t('Next >>'); ?>
              </span>
              </a>
            <?php endif; ?>

            <div
              class='page_number'><?php print t('Page - '); ?><?php print $div_counter; ?><?php print t(' of '); ?><?php print $total_number_of_pages ?><?php print t(' Pages.'); ?></div>
          </div>
        </div>
      </div>
    <?php endfor; ?>

  <?php else: ?>
    <div class='data_divs'>
      <table width="100%" border="0" cellspacing="0" cellpadding="0">
        <tr>
          <td valign="top" class='tableHead' width="15%">
            <?php print t('Support <br />Incident Id'); ?>
          </td>
          <td valign="top" class='tableHead' width="30%">
            <?php print t('Subject'); ?>
          </td>
          <td valign="top" class='tableHead' width="20%">
            <?php print t('Related Product'); ?>
          </td>
          <td valign="top" class='tableHead' width="20%">
            <?php print t('Status'); ?>
          </td>
          <td valign="top" class='tableHead' width="15%">
            <?php print t('Created <br />dd-mm-yyyy'); ?>
          </td>
        </tr>
        <tr>
          <td valign="top" colspan='3' style="padding-top:15px;">
            <?php print t('No record exists.'); ?>
          </td>
        </tr>
      </table>
    </div>
  <?php endif; ?>
</div>