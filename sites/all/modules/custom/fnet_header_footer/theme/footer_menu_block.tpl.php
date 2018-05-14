<?php

/**
 * @file
 * Footer menu block template.
 */
?>

<!-- Footer - Begin -->
<div id="footer_main">
  <div id="footer_wrapper">
    <div id="footer_inner">

      <div class="footer_box">
        <div class="footer_title"><?php print l(t('Solutions'), '/solutions'); ?></div>
        <div class="footer_link"><?php print l(t('Roles'), '/solutions/roles'); ?></div>
         <div class="footer_link"><?php print l(t('Learn About'), '/solutions/learn-about'); ?></div>
        <div class="footer_link"><?php print l(t('Case Studies'), '/solutions/case-studies'); ?></div>
        <div class="clear_15px"></div>
        <div class="footer_title"><?php print l(t('Blog'), '/blog/cabling-chronicles'); ?></div>
        <div class="footer_link"><?php print l(t('Cabling Chronicles'), '/blog/cabling-chronicles'); ?></div>
      </div>

      <div class="footer_box">
        <div class="footer_title"><?php print l(t('Products'), '/products'); ?></div>
        <div class="footer_link"><?php print l(t('Cabling Certification'), '/cabling-certification'); ?></div>
        <div class="footer_link"><?php print l(t('Installation and Test'), '/installation-and-test'); ?></div>
        <div class="footer_link"><?php print l(t('Telecom Test'), '/telecom-test'); ?></div>
        <div class="footer_link"><?php print l(t('Product Finder'), '/product-finder'); ?></div>
        <div class="footer_link"><?php print l(t('See All Products'), '/products'); ?></div>
        <div class="footer_link"><?php print l(t('Promotions'), '/promotions'); ?></div>
      </div>

      <div class="footer_box">
        <div class="footer_title"><?php print l(t('Support'), '/support'); ?></div>
        <div class="footer_link"><?php print l(t('Gold Product Support'), '/content/gold-product-support'); ?></div>
        <div class="footer_link"><?php print l(t('Downloads & Updates'), '/support/downloads'); ?></div>
        <div class="footer_link"><?php print l(t('Knowledge Base'), '/knowledge-base'); ?></div>
        <div class="footer_link"><?php print l(t('Service Centers'), '/support/service-centers'); ?></div>
        <div class="footer_link"><?php print l(t('Warranty Information'), '/content/standard-warranty'); ?></div>
        <div class="footer_link"><?php print l(t('Application Notes'), '/support/application-notes'); ?></div>
        <div class="footer_link"><?php print l(t('Data Sheets'), '/support/datasheets'); ?></div>
        <div class="footer_link"><?php print l(t('Manuals'), '/support/manuals'); ?></div>
      </div>

      <div class="footer_box">
        <div class="footer_title"><?php print l(t('Community'), '/community'); ?></div>
        <div class="clear_20px">&nbsp;</div>
        <div class="footer_title"><?php print l(t('About Us'), '/about-us'); ?></div>
        <div class="footer_link"><?php print l(t('Careers'), 'https://careers.fluke.com', ['attributes' =>['target' => '_blank']]); ?></div>
      </div>

      <div class="footer_box">
        <div class="footer_title"><?php print l(t('News & Events'),'/news-events'); ?></div>
        <div class="footer_link"><?php print l(t('News Articles'), '/news-list'); ?></div>
        <div class="footer_link"><?php print l(t('Upcoming Events'), '/news-events/tradeshows'); ?></div>
        <div class="footer_link"><?php print l(t('Training'), '/news-events/training'); ?></div>
        <div class="footer_link"><?php print l(t('Workshops'), '/news-events/workshops'); ?></div>
      </div>
    </div>
  </div>
</div>

<?php
$qPath = $_GET['q'];
if ((isset($node) && $node->type == 'marketo_form') || $qPath == 'where2buy' || strpos($qPath, 'ems/registration/add/') !== FALSE): ?>
  <script type="text/javascript">llfrmid = 12103</script>
  <script type="text/javascript"
          src="http://formalyzer.com/formalyze_init.js"></script>
  <script type="text/javascript"
          src="http://formalyzer.com/formalyze_call.js"></script>
<?php endif; ?>
