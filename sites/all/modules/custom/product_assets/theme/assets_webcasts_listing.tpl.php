<?php // $Id$?>
<div id="product-assets-wrapper">
  <table>
    <tr>
      <th><?php print t('Title') . '</th><th>' . t('Download'); ?></th>
    </tr>
    <?php
    $i = 0;
    foreach ($assets AS $asset) { ?>
      <tr class="asset-item <?php echo(($i % 2) ? 'zebra' : '') ?>">
        <td>
          <div class="OneLinkNoTx">
            <h4 class="asset-title"><?php echo $asset['title'] ?></h4>
          </div>
        </td>
        <td>
          <?php if (!empty($asset['file_link'])) {
            echo $asset['file_link'];
          } ?>
          <?php if ($asset['lock_status']) : ?>
            &nbsp;&nbsp;&nbsp;&nbsp;<img
              src="<?php echo $asset['lock_status'] ?>"/>
          <?php endif; ?>
        </td>
      </tr>
      <?php
      $i++;
    } ?>
  </table>
</div> 