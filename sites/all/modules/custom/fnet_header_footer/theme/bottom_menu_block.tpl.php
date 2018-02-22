<?php
// $Id$

/**
 * @file
 * Bottom menu block template
 *
 */
?>

<div class="clear_20px">&nbsp;</div>

<?php if ((!isset($_COOKIE['regLang'])) || (isset($_COOKIE["regLang"]) && ($_COOKIE["regLang"] != "CN-ZH"))): ?>
  <div id="footer_social">
    <div class="footer_social_icon">
      <!-- <a id="footer_social_icon_twitter" href="/twitter" target="_blank">Twitter12</a> -->
			<?php print l(t('Twitter'),'https://twitter.com/FlukeNetDCI',array('attributes' => array('id' => 'footer_social_icon_twitter'))); ?>
    </div>
    <div class="footer_social_icon">
      <!-- <a id="footer_social_icon_facebook" href="http://www.facebook.com/flukenetworks" target="_blank">Facebook</a> -->
			<?php print l(t('Facebook'),'https://www.facebook.com/flukenetworks',array('attributes' => array('id' => 'footer_social_icon_facebook'))); ?>
    </div>
    <div class="footer_social_icon">
      <!-- <a id="footer_social_icon_youtube" href="http://www.youtube.com/flukenetworksvideo" target="_blank">YouTube</a> -->
			<?php print l(t('YouTube'),'https://www.youtube.com/flukenetworksvideo',array('attributes' => array('id' => 'footer_social_icon_youtube'))); ?>
    </div>
    <?php
    //<div class="footer_social_icon">
    // <a id="footer_social_icon_rss" href="/rss" target="_blank">RSS Feed</a>
    //</div>-->
    ?>
    <div class="clear_1px">&nbsp;</div>
  </div>
<?php endif; ?>
<div id="footer_nav">
  <a href="http://www.fortive.com/integrity-compliance" target="_blank">Integrity and
    Compliance Program</a>&nbsp;&nbsp;|&nbsp;&nbsp;
  <a href="/about/privacy">Privacy Policy</a>&nbsp;&nbsp;|&nbsp;&nbsp;
  <a href="/about/terms-of-use">Terms of Use</a>&nbsp;&nbsp;|&nbsp;&nbsp;
  <a href="/sitemap">Sitemap</a>
</div>

<div id="copyright" style="width:240px;">
  &copy; 2006-<?php echo date('Y') ?> Fluke Corporation. All rights reserved.
</div>

<div class="clear_1px">&nbsp;</div>
