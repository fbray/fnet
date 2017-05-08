<?php
// $Id: node-edoc.tpl.php 5433 2014-06-17 16:29:57Z sogden1 $
?>
<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?>">

  <?php if ($title): print '<h1>'. html_entity_decode($title) .'</h1>'; endif; ?>
  <?php // if (validTitle($title)) : print '<h2>' . html_entity_decode($title) . '</h2>'; endif; ?>

  <?php print $picture ?>

  <?php if ($page == 0): ?>
    <h3><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h3>
  <?php endif; ?>

  <div class="clearboth">&nbsp;</div>

  <?php if ($subtitle) { ?>
    <h4>
      <?php print $subtitle ?>
    </h4>
  <?php } ?>

  <div class="clearboth">&nbsp;</div>

  <div>
    <?php print $content ?>
  </div>

  <div class="clearboth">&nbsp;</div>

  <div>
    <?php if ($links): ?>
      <div class="links"><?php print $links; ?></div>
    <?php endif; ?>
  </div>

  <div class="clearboth">&nbsp;</div>

  <div>
    <?php
    if ((!$ds_footer) && function_exists('_edoc_generate_footer')) {
      $ds_footer = _edoc_generate_footer($node);
    }
    print $ds_footer;
    ?>
  </div>
</div>