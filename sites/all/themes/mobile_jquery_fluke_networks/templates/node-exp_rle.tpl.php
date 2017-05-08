<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> clear-block">

  <h1><?php print $node->title ?></h1>
  <div><?php print $node->body ?></div>

  <?php if($node->field_exp_rle_tab_title[0]['value'] && $node->field_exp_rle_tab_content[0]['value']){ ?>

    <div data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">
      <h2 class="section-header"><?php print $node->field_exp_rle_tab_title[0]['value']; ?></h2>
      <div>
        <?php print $node->field_exp_rle_tab_content[0]['value']; ?>
      </div>
    </div>

  <?php } ?>

  <?php if($node->field_exp_rle_tab2_title[0]['value'] && $node->field_exp_rle_tab2_content[0]['value']){ ?>

    <div data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">
      <h2 class="section-header"><?php print $node->field_exp_rle_tab2_title[0]['value']; ?></h2>
      <div>
        <?php print $node->field_exp_rle_tab2_content[0]['value']; ?>
      </div>
    </div>

  <?php } ?>

  <?php if($node->field_exp_rle_tab3_title[0]['value'] && $node->field_exp_rle_tab3_content[0]['value']){ ?>

    <div data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">
      <h2 class="section-header"><?php print $node->field_exp_rle_tab3_title[0]['value']; ?></h2>
      <div>
        <?php print $node->field_exp_rle_tab3_content[0]['value']; ?>
      </div>
    </div>

  <?php } ?>

</div>