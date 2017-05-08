<?php
// $Id: node.tpl.php,v 1.5 2007/10/11 09:51:29 goba Exp $

// Find out which 'Blog Categories' vocabulary term is associated with this article.
$blog_category_term = '';
if (isset($node->taxonomy) && is_array($node->taxonomy)) {
  $term_array = $node->taxonomy;
  foreach ($term_array as $term_object) {
    $vocab = taxonomy_vocabulary_load($term_object->vid);
    if ($vocab->name == 'Blog Categories') {
      $blog_category_term = $term_object->name;
      if ($blog_category_term == 'AirWise' || $blog_category_term == 'Link-Solutions' || $blog_category_term == 'The Decoder') {
        $blog_category_term = 'Network Insider';
      }
    }
  }
}

?>

<div id="node-<?php print $node->nid; ?>"
     class="node-blog-article node<?php if ($sticky) {
       print ' sticky';
     } ?><?php if (!$status) {
       print ' node-unpublished';
     } ?>">

  <div class="blog-title"><span><?php print $blog_category_term; ?></span></div>

  <a class="back-to-blogs" href="/blog">Back to all blogs</a>

  <h1><?php print $title ?></h1>

  <?php if ($submitted): ?>
    <!-- span class="submitted"><?php print $submitted; ?></span -->
  <?php endif; ?>

  <div class="content clear-block">

    <?php
    // Gather author information to be displayed in head of article.
    $dateCreated = date("Y-m-d", $created);

    // Get user's 'realname' for displaying.
    $user = user_load($node->uid);
    $author_name = $user ? $user->realname : '';

    ?>

    <div class="blog-author-details">
      <?php if ($node->picture) { ?>
        <div class="blog-author-picture">
          <img src="/<?php print $node->picture; ?>">
        </div>
      <?php } ?>
      <div class="blog-author-name"><?php print $author_name; ?></div>
      <div class="blog-author-date"><?php if ($dateCreated) {
          print $dateCreated;
        } ?></div>
      <div class="clearboth"></div>
    </div>

    <div>
      <?php print render($content); ?>
    </div>

  </div>

</div>
