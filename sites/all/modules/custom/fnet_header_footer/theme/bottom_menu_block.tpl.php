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
      <?php print l(t('Twitter'),'https://twitter.com/FlukeNetDCI',array('attributes' => array('id' => 'footer_social_icon_twitter', 'target' => '_blank'))); ?>
    </div>
    <div class="footer_social_icon">
      <?php print l(t('Facebook'),'https://www.facebook.com/flukenetworks',array('attributes' => array('id' => 'footer_social_icon_facebook', 'target' => '_blank'))); ?>
    </div>
    <div class="footer_social_icon">
      <?php print l(t('YouTube'),'https://www.youtube.com/flukenetworksvideo',array('attributes' => array('id' => 'footer_social_icon_youtube', 'target' => '_blank'))); ?>
    </div>
    <div class="clear_1px">&nbsp;</div>
  </div>
<?php endif; ?>
<div id="footer_nav">
  <?php print l(t('Integrity and
    Compliance Program'),'http://www.fortive.com/integrity-compliance',array('attributes' => array('id' => 'integrity-compliance', 'class'=>'first', 'target' => '_blank'))); ?>
  <?php print l(t('Privacy Policy'),'about/privacy',array('attributes' => array('id' => 'privacy-policy'))); ?>
  <?php print l(t('Terms of Use'),'about/terms-of-use',array('attributes' => array('id' => 'terms-of-use'))); ?>
  <?php print l(t('Sitemap'),'sitemap',array('attributes' => array('id' => 'sitemap', 'class' => 'last'))); ?>
</div>

<div id="copyright" style="width:240px;">
  &copy; 2006-<?php echo date('Y') ?> Fluke Corporation. All rights reserved.
</div>

<div class="clear_1px">&nbsp;</div>
