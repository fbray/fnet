<?php
// $Id: node.tpl.php,v 1.5 2007/10/11 09:51:29 goba Exp $

// Find out which 'Blog Categories' vocabulary term is associated with this article.
$blog_category_term = '';
if (is_array($node->taxonomy)) {
  $term_array = $node->taxonomy;
  foreach ($term_array as $term_object) {
    $vocab = taxonomy_vocabulary_load($term_object->vid);
    if ($vocab->name == 'Blog Categories') {
      $blog_category_term = $term_object->name;
    }
  }
}

?>

<div id="node-<?php print $node->nid; ?>" class="node-blog-article node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?>">

  <h2><?php print $blog_category_term; ?></h2>

  <a class="back-to-blogs" href="/blog">Back to all blogs</a>

  <?php print $picture ?>

  <h1 class="<?php if (!isset($node->do_not_translate) || $node->do_not_translate == "1") print 'OneLinkNoTx'; ?>"><?php print $title ?></h1>

  <?php if ($submitted): ?>
    <!-- span class="submitted"><?php print $submitted; ?></span -->
  <?php endif; ?>

  <div class="content clear-block">

    <?php
    // Gather author information to be displayed in head of article.
    $dateCreated = date("Y-m-d", $created);
    ?>

    <div class="blog-author-details">
      <?php if($node->picture) { ?>
        <div class="blog-author-picture">
          <img src="/<?php print $node->picture; ?>">
        </div>
      <?php } ?>
      <div class="blog-author-name"><?php if($node->name) print $node->name; ?></div>
      <div class="blog-author-date"><?php if($dateCreated) print $dateCreated; ?></div>
      <div class="clearboth"></div>
    </div>

    <?php print $content ?>

  </div>

</div>
