<?php
// $Id: node--edoc.tpl.php 2778 2017-09-14 15:04:54Z gkakade $

/**
 * Hide Content and Print it Separately
 *
 * Use the hide() function to hide fields and other content, you can render it
 * later using the render() function. Install the Devel module and use
 * <?php dsm($content); ?> to find variable names to hide() or render().
 */
hide($content['comments']);
hide($content['links']);
?>
<!-- node--edoc.tpl.php -->
<article id="node-<?php print $node->nid; ?>"
         class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>

  <?php if ($title): ?>
    <header<?php print $header_attributes; ?>>
	<?php if (arg(0)== 'node'){?>
      <?php print $print_links; ?>
	<?php } ?>
      <?php if ($title): ?>
        <h1<?php print $title_attributes; ?>>
          <!--<a href="<?php //print $node_url; ?>"
             rel="bookmark"><?php //print $title; ?></a>-->
						 <?php print $title; ?>
        </h1>
      <?php endif; ?>
    </header>
  <?php endif; ?>

  <?php if (!empty($user_picture) || $display_submitted): ?>
    <footer<?php print $footer_attributes; ?>>
      <?php print $user_picture; ?>
      <p class="author-datetime"><?php print $submitted; ?></p>
    </footer>
  <?php endif; ?>

  <div<?php print $content_attributes; ?>>
    <?php print render($content); ?>
  </div>

  <?php if ($links = render($content['links'])): ?>
    <nav<?php print $links_attributes; ?>><?php print $links; ?></nav>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

  <?php print render($title_suffix); ?>
</article>
<!-- end of node--edoc.tpl.php -->