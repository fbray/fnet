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

<div id="node-<?php print $node->nid; ?>" class="node-blog-article node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?>">

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
      <?php if($node->picture) { ?>
        <div class="blog-author-picture">
          <img src="/<?php print $node->picture; ?>">
        </div>
      <?php } ?>
      <div class="blog-author-name"><?php print $author_name; ?></div>
      <div class="blog-author-date"><?php if($dateCreated) print $dateCreated; ?></div>
      <div class="clearboth"></div>
    </div>

    <div>
      <?php print render($content); ?>
    </div>
	<!-- Social Icons -->
	<div id="cio-brief-social-wrapper" class="blog-article-social-icons">
	  <ul class="social_media" style="padding: 0px;margin: 0px;">
        <li><a title="Twitter" href="https://twitter.com/FlukeNetDCI" target="_blank"><img alt="" src="<?php echo base_path() . path_to_theme(); ?>/css/images/GR_twitter-534_34px.jpg" style="width: 30px; height: 30px;"></a></li>
        <li><a href="https://www.facebook.com/flukenetworks?fref=ts" title="Facebook" target="_blank"><img alt="" src="<?php echo base_path() . path_to_theme(); ?>/css/images/GR_facebook-534_34px.jpg" style="width: 30px; height: 30px;"></a></li>
        <li><a href="https://www.linkedin.com/company/fluke-networks?goback=.fcs_GLHD_fluke+networks_false_*2_*2_*2_*2_*2_*2_*2_*2_*2_*2_*2_*2&amp;trk=ncsrch_hits" title="LinkedIn" target="_blank"><img alt="" src="<?php echo base_path() . path_to_theme(); ?>/css/images/GR_LinkedIn-534_34px.jpg" style="width: 30px; height: 30px;"></a></li>
        <li><a href="https://www.youtube.com/user/FlukeNetworksVideo/featured" title="YouTube" target="_blank"><img alt="" src="<?php echo base_path() . path_to_theme(); ?>/css/images/GR_youtube-534_34px.jpg" style="width: 30px; height: 30px;"></a></li>
        <li><a href="/blog" target="_blank"><img alt="" src="<?php echo base_path() . path_to_theme(); ?>/css/images/GR_blog-534_34px.jpg" style="width: 30px; height: 30px;"></a></li>
      </ul>
	</div> 
	<?php
		$bl = module_invoke('custom_blocks', 'block_view', 'subscribe_blog');
		print render($bl['content']);
	?>
  </div>
</div>
