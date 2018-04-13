<div id="support-page-content-wrapper">
  <div id="support-banner-wrapper">
    <h1><?php print t('Support'); ?></h1>
    <div class="desc">
<?php
print t('Fluke Networks offers world-class service and support. Contact a '
        . 'Fluke<br/>Networks authorized service center and get more information.');
?>
    </div>
  </div>
  <div id="support-content-wrapper">
    <div id="support-left-content-wrapper">

      <!-- Start: Knowledge base -->
      <div id="support-kb-wrapper" class="section">
        <h3 class="section-title"><?php print t('Knowledge Base'); ?></h3>
        <span class="section-desc"><?php print t('Find answers to questions online right now.'); ?></span>

        <!-- Start: Search for KB topics -->
        <div id="search-kb-form-wrapper" class="subsection first">
          <form id="search-kb-form" name="search_kb_form" method="POST" action="#">
            <h4 class="subsection-title"><?php print t('Search for KB topics'); ?></h4>
              <!-- input type="radio" id="search-kb-radio-fn" name="search_kb_radios" value="fn" rel="GET<::>http://myaccount.flukenetworks.com/fnet/en-us/supportAndDownloads/KB/searchResults.htm<::>query" checked / -->
              <input type="radio" id="search-kb-radio-fn" name="search_kb_radios" value="fn" rel="GET<::>/knowledge-base?query=<::>query" checked />
            <span class="radio-label"><?php print t('Fluke Networks'); ?></span><br/>
            <input type="text" id="search-kb-text" name="query" value="<?php print t('Enter text here.'); ?>" /><br/>
            <div class="btn_143w">
              <a id="search-kb-btn" name="search_kb_btn"  href="#"><?php print t('Search'); ?></a>
            </div>
            <input type="hidden" name="page" value="index_s" />
            <input type="hidden" name="mode" value="DB" />
          </form>
        </div>
        <!-- End: Search for KB topics -->

        <!-- Start: Browse by Product -->
        <div id="browse-by-product-wrapper" class="subsection">
          <h4 class="subsection-title"><?php print t('Browse by Product'); ?></h4>
          <ul>
            <li>
              <a href="/knowledge-base">
              <?php print t('Fluke Networks products'); ?></a>
            </li>
          </ul>
        </div>
        <!-- End: Browse by Product -->
        
        <!-- Start: Training Videos -->
        <div id="training-videos-wrapper" class="subsection last">
          <h4 class="subsection-title"><?php print t('Training Videos'); ?></h4>
          <?php $product_assets_training_form = drupal_get_form('product_assets_training_form');
          print render( $product_assets_training_form ); ?>
          <div id="training-videos-desc">
<?php
print t('More training is available on our <a href="@training-page">Training page</a>.',
        array('@training-page' => url('support/training'))
       );
?>
          </div>
        </div>
        <!-- End: Training Videos -->
      </div>
      <!-- End: Knowledge base -->

      <!-- Start: Product Documentation and Downloads -->
      <div id="support-pdd-wrapper" class="section">
        <h3 class="section-title"><?php print t('Product Documentation and Downloads'); ?></h3>
        <span class="section-desc">
        <?php print t('Find product manuals and software and firmware updates and installers.'); ?></span>

        <!-- Start: Find by Product name -->
        <div id="fbpn-wrapper" class="subsection first">
          <h4 class="subsection-title"><?php print t('Find by Product Name'); ?></h4>
          <input type="radio" id="software-by-product" name="fbpn_radios" value="softwares" checked />
          <span class="radio-label"><?php print t('Software Downloads'); ?></span><br/>
          <input type="radio" id="manuals-by-product" name="fbpn_radios" value="manuals" />
          <span class="radio-label"><?php print t('Product Manuals'); ?></span><br/>
          <div id="software-downloads-form-wrapper">
            <?php $product_assets_download_form = drupal_get_form('product_assets_download_form') ;
            print render( $product_assets_download_form ); ?>
          </div>
          <div id="product-manuals-form-wrapper">
            <?php $product_assets_manuals_form = drupal_get_form('product_assets_manuals_form');
            print render( $product_assets_manuals_form ); ?>
          </div>
        </div>
        <!-- End: Find by Product name -->
        <div class="subsection last" style="width: 60%;">
          <p>Some product software is only available to Gold customers. Gold customers must add their
            active Gold identification and PIN to their account to enable the downloads.
            Visit the <a href="/content/gold-product-support" target="_blank">Gold Services page</a> for more
            information.</p>
        </div>

      </div>
      <!-- End: Product Documentation and Downloads -->

      <!-- Start: Service Center -->
      <div id="support-sc-wrapper" class="section last">
        <h3 class="section-title"><?php print t('Service Center'); ?></h3>
        <span class="section-desc">
        <?php print t(  'You will receive outstanding service for calibration or '
                      . 'repair from any of the Authorized Fluke Networks '
                      . 'Service Centers listed below.'); ?>
        </span>

        <!-- Start: Find the service center newares you: -->
        <div id="fscnu-wrapper" class="subsection first">
          <h4 class="subsection-title"><?php print t('Service Contact Information'); ?></h4>
          <ul>
              <li><?php print l(t('North America'), '/content/north-america-contact-information'); ?></li>
              <li><?php print l(t('South America'), '/content/south-america-contact-information'); ?></li>
              <li><?php print l(t('Europe'),        '/content/europe-contact-information'); ?></li>
              <li><?php print l(t('Asia'),          '/content/asia-contact-information'); ?></li>
              <li><?php print l(t('Africa'),        '/content/africa-contact-information'); ?></li>
              <li><?php print l(t('Middle East'),   '/content/middle-east-contact-information'); ?></li>
              <li><?php print l(t('Pacific Rim'),   '/content/pacific-rim-contact-information'); ?></li>
              <li><?php print l(t('Russia/CIS'),    '/content/russiacis-contact-information'); ?></li>
          </ul>
        </div>
        <!-- End: Find the service center newares you: -->

        <!-- Start: Calibration & Repair -->
        <div id="car-wrapper" class="subsection">
          <h4 class="subsection-title"><?php print t('Calibration &amp; Repair'); ?></h4>
          <span class="subsection-desc">
          <?php print t(  "Fluke Networks' Service Centers are dedicated to "
                        . 'providing the best possible service to our customers.');
          ?>
          </span>
          <ul>
            <li><?php print l(t('Get Calibration'), '/content/calibration-services'); ?></li>
            <li><?php print l(t('How To Schedule Repair'), '/content/repair-services'); ?></li>
          </ul>
        </div>
        <!-- End: Calibration & Repair -->

        <!-- Start: Online RMA -->
        <div id="orma-wrapper" class="subsection last">
          <h4 class="subsection-title"><?php print t('Online RMA'); ?></h4>
          <span class="subsection-desc">
          <?php print t(  'Receive a quote for service with our online RMA tool '
                        . 'via the Fluke Customer Support Services web site.');
          ?>
          </span>
          <ul>
            <li><?php print l(t('Find out More'), '/content/online-rma'); ?></li>
            <li><?php print l(t('Online Services RMA'), 'http://www.fluke.com/ServiceRMA'); ?></li>
          </ul>
        </div>
        <!-- End: Online RMA -->
      </div>
      <!-- End: Service Center -->
    </div>
    <div id="support-right-content-wrapper">
      <!-- Start: Contact Support -->
      <div id="contact-support-wrapper" class="section first">
        <h3 class="section-title"><?php print t('Contact Support'); ?></h3>

        <!-- Start: Phone -->
        <div id="phone-wrapper" class="subsection">
          <h4 class="subsection-title"><?php print t('Phone'); ?></h4>
          <div id="phone-no">1-800-283-5853</div>
          <span class="subsection-desc"><?php print t('North America'); ?></span>
          <?php print l(t('See more support numbers'), 'contact-support'); ?>
        </div>
        <!-- End: Phone -->

        <!-- Start: Online -->
        <div id="online-wrapper" class="subsection">
          <h4 class="subsection-title"><?php print t('Online'); ?></h4>
          <span class="subsection-desc">
          <?php print t(  'Submit a new support incident online or track '
                        . 'existing support incidents and tickets using a '
                        . 'registered account.');
          ?>
          </span>
          <?php print l(t('Create/View Support incident'), '/myaccount/all-support-incidents'); ?>
        </div>
        <!-- End: Online -->
        
      </div>
      <!-- End: Contact Support -->

      <!-- Start: Gold Support -->
      <div id="gold-support-wrapper" class="section">
        <h3 class="section-title"><?php print t('Gold Support'); ?></h3>
        <span class="section-desc">
        <?php print t(  'Gold Membership ensures a better return on your '
                      . 'investment by lowering your cost of ownership. With '
                      . 'lower tools, training, service and support, Gold '
                      . 'Support gives you the vision and support you need '
                      . 'to maximize your investment.');
        ?>
        </span>
        <div class="btn_143w">
          <?php print l(t('Get Gold Support'),'gold-product-support'); ?>
        </div>
      </div>
      <!-- End: Gold Support -->

      <!-- Start: Register your Product -->
      <div id="register-product-wrapper" class="section last">
        <h3 class="section-title"><?php print t('Register your Product'); ?></h3>
        <span class="section-desc">
        <?php print t(  'Protect your investment and stay informed about the '
                      . 'latest developments by registering your new Fluke '
                      . 'Networks product. Product registration allows you to '
                      . 'view product information for all of your registered '
                      . 'products, browse our Knowledge Base, or submit and '
                      . 'view support incidents.');
        ?>
        </span>

        <div class="btn_143w">
          <?php print l(t('Fluke Networks Products'), '/myaccount/register-products-step-one'); ?>
        </div>
      </div>
      <!-- End: Register your Product -->
    </div>
  </div>
</div>
