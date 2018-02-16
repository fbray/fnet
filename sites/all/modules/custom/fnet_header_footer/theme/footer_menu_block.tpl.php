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
        <div class="footer_title"><a href="/solutions">SOLUTIONS</a></div>
        <div class="footer_link"><a href="/solutions/roles"><?php print t('Roles'); ?></a></div>
         <div class="footer_link"><a href="/solutions/learn-about"><?php print t('Learn About'); ?></a></div>
        <div class="footer_link"><a href="/solutions/case-studies"><?php print t('Case Studies'); ?></a></div>
        <div class="clear_15px">&nbsp;</div>
        <div class="footer_title"><a href="/blog/cabling-chronicles"><?php print t('BLOG'); ?>:</a></div>
        <div class="footer_link"><a href="/blog/cabling-chronicles"><?php print t('Cabling Chronicles'); ?></a></div>
      </div>

      <div class="footer_box">
        <div class="footer_title"><a href="/products">PRODUCTS</a></div>
        <div class="footer_link"><a href="/cabling-certification"><?php print('Cabling Certification'); ?></a>
        </div>
        <div class="footer_link"><a href="/installation-and-test"><?php print t('Installation and Test'); ?></a>
        </div>
        <div class="footer_link"><a href="/telecom-test"><?php print t('Telecom Test'); ?></a></div>
        <div class="footer_link"><a href="/product_finder"><?php print t('Product Finder'); ?></a>
        </div>
        <div class="footer_link"><a href="/products"><?php print ('See All Products'); ?></a></div>
        <div class="footer_link"><a href="/promotions-home"><?php print ('Promotions'); ?></a></div>
      </div>

      <div class="footer_box">
        <div class="footer_title"><a href="/support">SUPPORT</a></div>
        <div class="footer_link"><a href="/content/gold-product-support"><?php print t('Gold Product Support'); ?></a></div>
        <div class="footer_link"><a href="/support/downloads"><?php print t('Downloads & Updates'); ?></a></div>
        <div class="footer_link"><a href="/knowledge-base"><?php print t('Knowledge Base'); ?></a></div>
        <div class="footer_link"><a href="/support/service-centers"><?php print t('Service
            Centers'); ?></a></div>
        <div class="footer_link"><a href="/content/standard-warranty"><?php print t('Warranty
            Information'); ?></a></div>
        <div class="footer_link"><a href="/support/application-notes"><?php print t('Application
            Notes'); ?></a></div>
        <div class="footer_link"><a href="/support/datasheets"><?php print t('Data Sheets'); ?></a>
        </div>
        <div class="footer_link"><a href="/support/manuals"><?php print t('Manuals'); ?></a></div>
      </div>

      <div class="footer_box">
        <div class="footer_title"><a href="/community">COMMUNITY</a></div>
        <div class="clear_20px">&nbsp;</div>
        <div class="footer_title"><a href="/about-us">ABOUT US</a></div>
        <div class="footer_link"><a href="https://careers.fluke.com" target="_blank">Careers</a></div>
      </div>

      <div class="footer_box">
        <div class="footer_title"><a href="/news-events">NEWS &amp; EVENTS</a></div>
        <div class="footer_link"><a href="/news-list">News Articles</a></div>
        <div class="footer_link"><a href="/news-events/tradeshows">Upcoming Events</a></div>
        <div class="footer_link"><a href="/news-events/training">Training</a></div>
        <div class="footer_link"><a href="/news-events/workshops">Workshops</a></div>
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
