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
      <a id="footer_social_icon_twitter" href="/twitter"
         target="_blank">Twitter</a>
    </div>
    <div class="footer_social_icon">
      <a id="footer_social_icon_facebook"
         href="http://www.facebook.com/flukenetworks"
         target="_blank">Facebook</a>
    </div>
    <div class="footer_social_icon">
      <a id="footer_social_icon_youtube"
         href="http://www.youtube.com/flukenetworksvideo" target="_blank">YouTube</a>
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
  <a href="http://www.danaherintegrity.com/" target="_blank">Integrity and
    Compliance Program</a>&nbsp;&nbsp;|&nbsp;&nbsp;
  <a href="/about/privacy">Privacy Policy</a>&nbsp;&nbsp;|&nbsp;&nbsp;
  <a href="/about/terms-of-use">Terms of Use</a>&nbsp;&nbsp;|&nbsp;&nbsp;
  <a href="/sitemap">Sitemap</a>
</div>

<div id="copyright" style="width:240px;">
  &copy; 2006-<?php echo date('Y') ?> Fluke Corporation. All rights reserved.
</div>

<div class="clear_1px">&nbsp;</div>
