<?php
$region = strtolower($_COOKIE["regLang"]);
if ($region == "") $region = "en-us"; 
?>

<div id="expertise-page-content-wrapper">
  <div id="expertise-banner-wrapper">
    <h1><?php print t('Solutions'); ?></h1>
  </div>
  <div id="expertise-content-wrapper">
    <div id="expertise-left-content-wrapper" style="width:100%;">

      <!-- Start: Topics -->
      <div id="expertise-wp-wrapper" class="section first">
        <h3 class="section-title"><?php print t('Topics'); ?></h3>
        <span class="section-desc">
<?php
//print t(  'Download insights into the most challenging aspects of your work, '
 //       . 'including technical resources and solutions to help you on the job.');
?>
</span>
        <div id="expertise-wp-content-wrapper">
          <?php
						$topicView = views_get_view_result('exp_tpc_view', 'default', $region);
						$tpcCount = 3;
						foreach ($topicView as $tpc) { 
							if (! $tpcCount) break; ?>
							<div class="wp-content-item">
              	<div class="item-title"><a href="<?php print drupal_lookup_path('alias', 'node/'.$tpc->nid); ?>"><?php print $tpc->node_title ?></a></div>
                <div class="item-desc"><?php print truncate_utf8(strip_tags($tpc->node_revisions_body), 185, TRUE, TRUE); ?></div>
              </div>
					<?php 
							$tpcCount--;
						} ?>
          <div class="btn_143w">
            <a href="<?php print url('expertise/topics')?>"><?php print t('All Topics'); ?></a>
          </div>
          <div class="clear_10px">&nbsp;</div>
        </div>
      </div>
      <!-- End: Topics -->

<!-- Start: Roles -->
      <div id="expertise-wp-wrapper" class="section first">
        <h3 class="section-title"><?php print t('Roles'); ?></h3>
        <span class="section-desc">
<?php
//print t(  'Download insights into the most challenging aspects of your work, '
 //       . 'including technical resources and solutions to help you on the job.');
?>
</span>
        <div id="expertise-wp-content-wrapper">
          <?php
						$roleView = views_get_view_result('exp_rle_view', 'default', $region);
						$rleCount = 3;
						foreach ($roleView as $rle) { 
							if (! $rleCount) break; ?>
							<div class="wp-content-item">
              	<div class="item-title"><a href="<?php print drupal_lookup_path('alias', 'node/'.$rle->nid); ?>"><?php print $rle->node_title ?></a></div>
                <div class="item-desc"><?php print truncate_utf8(strip_tags($rle->node_revisions_body), 185, TRUE, TRUE); ?></div>
              </div>
					<?php 
							$rleCount--;
						} ?>
          <div class="btn_143w">
            <a href="<?php print url('expertise/roles')?>"><?php print t('All Roles'); ?></a>
          </div>
          <div class="clear_10px">&nbsp;</div>
        </div>
      </div>
      <!-- End: Roles -->
      
      <!-- Start: Industries -->
      <div id="expertise-wp-wrapper" class="section first">
        <h3 class="section-title"><?php print t('Industries'); ?></h3>
        <span class="section-desc">
<?php
//print t(  'Download insights into the most challenging aspects of your work, '
 //       . 'including technical resources and solutions to help you on the job.');
?>
</span>
        <div id="expertise-wp-content-wrapper">
          <?php
						$industryView = views_get_view_result('exp_ind_view', 'default', $region);
						$indCount = 3;
						foreach ($industryView as $ind) { 
							if (! $indCount) break; ?>
							<div class="wp-content-item">
              	<div class="item-title"><a href="<?php print drupal_lookup_path('alias', 'node/'.$ind->nid); ?>"><?php print $ind->node_title ?></a></div>
                <div class="item-desc"><?php print truncate_utf8(strip_tags($ind->node_revisions_body), 185, TRUE, TRUE); ?></div>
              </div>
					<?php 
							$indCount--;
						} ?>
          <div class="btn_143w">
            <a href="<?php print url('expertise/industries')?>"><?php print t('All Industries'); ?></a>
          </div>
          <div class="clear_10px">&nbsp;</div>
        </div>
      </div>
      <!-- End: Industries -->
      

<!-- Start: Learn About -->
      <div id="expertise-wp-wrapper" class="section first">
        <h3 class="section-title"><?php print t('Learn About'); ?></h3>
        <span class="section-desc">
<?php
 print t(  'Learn definitions, applications and key considerations of core '
        . "networking technologies Fluke Networks' experts know best along "
        . 'with related products and resources.');
?>
</span>
        <div id="expertise-wp-content-wrapper">
          <?php foreach($expertise['learn_about'] AS $learn_about) { ?>
							<div class="wp-content-item">
              	<div class="item-title"><?php print l($learn_about['title'], 'node/'.$learn_about['nid']) ?></div>
                <div class="item-desc"><?php print $learn_about['desc'] ?></div>
              </div>
					<?php 
						} ?>
          <div class="btn_143w">
            <a href="<?php print url('learn-about')?>"><?php print t('All Learn About Topics'); ?></a>
          </div>
          <div class="clear_10px">&nbsp;</div>
        </div>
      </div>
      <!-- End: Learn About -->
      
      <!-- Start: Case Studies -->
      <div id="expertise-cs-wrapper" class="section last">
        <h3 class="section-title"><?php print t('Case Studies'); ?></h3>
        <span class="section-desc">
<?php
print t(  'Learn how businesses are leveraging Fluke Networks tools and '
        . 'solutions to solve their most challenging problems.');
?>
</span>
        <div id="expertise-cs-content-wrapper">
          <?php foreach ($expertise['casestudies'] AS $casestudy) { ?>
          <div class="cs-content-item">
            <div class="item-title"><?php print l($casestudy['title'], 'node/'.$casestudy['nid']) ?></div>
            <div class="item-desc"><?php print $casestudy['desc'] ?></div>
          </div>
          <?php } ?>
          <div class="btn_143w">
            <a href="<?php print url('case-studies'); ?>"><?php print t('All Case Studies'); ?></a>
          </div>
        </div>
      </div>
      <!-- End: Case Studies -->

			<!-- Start: Blogs --><!--
      <div id="expertise-blogs-wrapper" class="section last">
        <h3 class="section-title"><?php print t('Blogs'); ?></h3>
        <span class="section-desc">
<?php
print t('Connect with network pros to share insights on network issues.');
?>
</span>
        <div id="expertise-blogs-content-wrapper">
          <div class="title">
            <a href="http://www.flukenetworks.com/cablingchronicles" class="blogTitle">
<?php
print t('Cabling Chronicles');
?>
</a></div>
          <div class="tag">
            <?php //print t('Copper and Fiber cabling industry news, standard changes/updates, customer insights and shared learnings.'); ?>
          </div>
          <div class="title">
            <a href="http://myaccount.flukenetworks.com/fnet/en-us/Community/Decoder?plckBlogId=Blog%3a0e19ed7b-d712-4672-885e-b6aac80cd073" class="blogTitle">
<?php
print t('The Decoder');
?>
</a></div>
          <div class="tag">
            <?php print t('Solving the mysteries of monitoring, analysis and troubleshooting.'); ?>
          </div>
<?php //          <div class="title">
      //      <a class="blogTitle" href="http://myaccount.flukenetworks.com/fnet/en-us/Community/Packets_in_Paradise.htm?plckBlogId=Blog%3a1d69ff7a-abce-4694-9d65-915308c354a3">
?>
<?php
print t('Packets in Paradise');
?>
<?php
//</a></div>
//          <div class="tag"><?php print t('Tips and Tricks in Protocol Analysis'); ?>
<?php //</div>
?>
        </div>
      </div>
      --><!-- End: Blogs -->
    </div>
  </div>
</div>