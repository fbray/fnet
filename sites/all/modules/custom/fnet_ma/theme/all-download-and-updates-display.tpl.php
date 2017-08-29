<?php
// $Id: all-download-and-updates-display.tpl.php 48 2015-04-30 22:54:33Z sogden1 $

/**
 * @file
 * This file is used to theme the page that displays the listing of all the
 * Download and updates associated with the logged in user.
 */
global $base_url, $user;
//Paging Logic starts from here..!
if (!is_array($download_and_updates_array)) {
  $array_is_empty = TRUE;
}
else {
  $content_array = array_values($download_and_updates_array);
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
}
?>

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
              <td valign="top" class='tableHead' width="80%">
                <?php print t('Title'); ?>
              </td>
              <td valign="top" class='tableHead' width="15%">
                <?php print t('Download <br /> Options'); ?>
              </td>
              <td valign="top" class='tableHead' width="5%">
                <?php print t(''); ?>
              </td>
            </tr>
            <?php
            //pa($content_array);
            for ($array_element_count = (($div_counter - 1) * $rows_per_page) + 1; $array_element_count <= ($div_counter * $rows_per_page); $array_element_count++) {
              if (trim($content_array[$array_element_count - 1]['AssetName']) != '') {
                $lock_unlock_class = '';
                if ($content_array[$array_element_count - 1]['ImageAccessLevel'] == '/fnet_www/images/lock.gif') {
                  $lock_unlock_class = 'fn_myaccount_lock';
                }
                elseif ($content_array[$array_element_count - 1]['ImageAccessLevel'] == '/fnet_www/images/unlock.gif') {
                  $lock_unlock_class = 'fn_myaccount_unlock';
                }
                ?>
                <tr <?php print($array_element_count % 2 == 0 ? 'class="trAlternate"' : ''); ?>>
                  <td valign="top">
                  <span class='actual_values'>
                    <b>
                      <?php print $content_array[$array_element_count - 1]['AssetName']; ?>
                    </b>
                    <br/>
                    <?php print $content_array[$array_element_count - 1]['Description']; ?>
                  </span>
                  </td>

                  <td valign="top">
                  <span class='actual_values'>
                    <?php print $content_array[$array_element_count - 1]['FNET_URL']; ?>
                    <?php print $content_array[$array_element_count - 1]['FileSize']; ?>
                  </span>
                  </td>

                  <td valign="top">
                    <span
                      class='actual_values <?php print $lock_unlock_class; ?>'></span>
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
      <table width="100%" border="0" cellspacing="5" cellpadding="5">
        <tr>
          <td valign="top" class='tableHead' width="70%">
            <?php print t('Title'); ?>
          </td>
          <td valign="top" class='tableHead' width="20%">
            <?php print t('Download <br /> Options'); ?>
          </td>
          <td valign="top" class='tableHead' width="10%">
            <?php print t(''); ?>
          </td>
        </tr>
        <tr>
          <td valign="top" colspan='3'>
            <?php
            if (check_plain(arg(3)) != '') {
              print t('No records to display.');
            }
            else {
              print t('');
            }
            ?>
          </td>
        </tr>
      </table>
    </div>
  <?php
  }
  ?>
</div>