<?php
// $Id $
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
<article id="node-<?php print $node->nid; ?>"
         class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>

  <?php if ($title): ?>
    <header<?php print $header_attributes; ?>>
      <?php if ($title): ?>
        <h1<?php print $title_attributes; ?>>
          <a href="<?php print $node_url; ?>"
             rel="bookmark"><?php print $title; ?></a>
        </h1>
      <?php endif; ?>
    </header>
  <?php endif; ?>

  <div<?php print $content_attributes; ?>>
    <?php print render($content); ?>
  </div>
  <div class="button">
    <div class="fb-share-button" data-href="<?php print $fb_data_href; ?>"
         data-layout="button"></div>
    <div id="custom-tweet-button">
      <a
        href="https://twitter.com/intent/tweet?url=<?php print $twitter_encoded_url; ?>&amp;text=<?php print $twitter_encoded_title; ?>"
        target="_blank"></a>
    </div>
  </div>

  <?php print render($title_suffix); ?>
</article>
