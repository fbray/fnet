<?php // $Id$ ?>
<div id="product-assets-wrapper">
  <table>
    <tr>
      <th><?php print t('Title') . '</th><th>' . t('Download'); ?></th>
      <th></th>
    </tr>
    <?php
    $i = 0;
    foreach ($assets AS $asset) {
      ?>
      <tr class="asset-item <?php echo(($i % 2) ? 'zebra' : '') ?>">
        <td>
          <div class="OneLinkNoTx">
            <h4 class="asset-title"><?php echo $asset['title']; ?></h4>

            <div class="asset-description"><?php echo $asset['desc']; ?></div>
          </div>
        </td>
        <td><?php if (!empty($asset['file_link'])): ?>
            <?php echo $asset['file_link']; ?>
            <?php endif; ?>
          <br/>

          <div class="file-size">
            <?php if (!empty($asset['file_size'])): ?>
              <?php echo '(' . $asset['file_size'] . ')'; ?>
            <?php endif; ?>
          </div>
        </td>
        <td>
          <?php if ($asset['lock_status']) : ?>
            <img src="<?php echo $asset['lock_status']; ?>"/>
          <?php endif; ?>
        </td>
      </tr>
      <?php
      $i++;
    } ?>
  </table>
</div> 