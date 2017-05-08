<?php
/*
 * $content contains the relevant fields
 * use dpm($content) to see what's in there!
 */
// dpm($node);
// dpm($content);
?>
<?php print render($title_prefix); ?>
<h3 class="title"<?php print $title_attributes; ?>>
  <a href="/<?php print $node->path['alias']; ?>"><?php print $title; ?></a></h3>
<?php print render($title_suffix); ?>
<?php print render($content); ?>



