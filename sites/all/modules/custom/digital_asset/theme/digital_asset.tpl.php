<?php
// $Id$

/**
 * @file
 * display digital asset
 *
 */

$filename = $node->field_dam_asset_file[0]['filename'];
$file_path = $node->field_dam_asset_file[0]['filepath'];
$parent = $node->field_dam_parent[0]['nid'];
?>
<div class="content">
  <h2>Description</h2>

  <p><?php print $node->body; ?></p>

  <h2>Asset file</h2>

  <p><?php print l($filename, $file_path, array('attributes' => array('target' => '_blank'))); ?></p>
  <?php if ($parent) : ?>
    <h2>Parent</h2>
    <?php print l('Link to parent', "digital_asset/$parent/view"); ?>
  <?php endif; ?>
  <p><?php print l('Return to Asset List', 'digital_asset/list'); ?></p>

  <p><?php print l('Return to AMS Menu', 'admin/content/digital_assets'); ?></p>
</div>
