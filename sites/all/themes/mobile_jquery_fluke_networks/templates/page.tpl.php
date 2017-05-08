<!DOCTYPE html>
<html>

<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>

  <?php if (!empty($jqm_scripts)) { print $jqm_scripts; } ?>

</head>

<body class="mobile-theme <?php print $body_classes; ?>">

    <div data-role="page" class="<?php print $node_classes; ?>">

        <div data-role="panel" data-position="left" data-display="reveal" id="panel-navigation">
          <!-- panel content goes here -->
          <ul data-role="listview" data-icon="false" data-divider-theme="f">

            <!-- Top Links -->
            <li data-theme="b" data-inline="true" data-iconshadow="false" class="ui-icon-nodisc" data-icon="home" data-iconpos="left"><a href="/">Home</a></li>

            <!-- Solutions Menu -->
            <li data-theme="b"><a href="/solutions">Solutions</a></li>
            <li><a href="/expertise/topics">&nbsp;Topics</a></li>
            <li><a href="/expertise/roles">&nbsp;Roles</a></li>
            <li><a href="/expertise/industries">&nbsp;Industries</a></li>
            <li><a href="/learn-about">&nbsp;Learn About</a></li>
            <li><a href="/case-studies">&nbsp;Case Studies</a></li>

            <!-- Products Menu -->
            <li data-theme="b"><a href="/products">Products</a></li>
            <li><a href="/datacom-cabling">&nbsp;Datacom Cabling</a></li>
            <li><a href="/enterprise-network">&nbsp;IT Networking</a></li>
            <li><a href="/telecom">&nbsp;Telecom</a></li>

            <!-- Support Menu -->
            <li data-theme="b"><a href="/support">Support</a></li>
            <li><a href="/content/gold-product-support">&nbsp;Gold Product Support</a></li>
            <li><a href="/content/professional-services-overview">&nbsp;Professional Services</a></li>
            <li><a href="/support/downloads">&nbsp;Downloads & Updates</a></li>
            <li><a href="/knowledge-base">&nbsp;Knowledge Base</a></li>
            <li><a href="/support/application-notes">&nbsp;Application Notes</a></li>
            <li><a href="/support/manuals">&nbsp;Manuals</a></li>
            <li><a href="/support/service-centers">&nbsp;Service Centers</a></li>
            
            <!-- Extras -->
            <li data-theme="b"><a href="/community">Community</a></li>
            <li data-theme="b"><a href="/news">News &amp; Events</a></li>
            <li data-theme="b"><a href="/wheretobuy">Where to Buy</a></li>
            <li data-theme="b"><a href="/contact">Contact Us</a></li>

          </ul>

        </div>

        <div data-role="panel" data-position="right" data-display="reveal" id="panel-search">
             <!-- panel content goes here -->
             <ul data-role="listview" data-icon="false">

               <!-- Search -->
               <li data-theme="b">
                 <form name="globalSearchForm" id="globalSearchForm" style="margin:0px;padding:0px;">
                   <input name="password" id="globalSearchInput" value="" placeholder="Search" type="search">
                 </form>
                 <script>
                   // The following, upon search form submission, will construct the search path
                   // and send user to search result page.
                   $(document).ready(function(){

                     $('#globalSearchForm').submit(function(event){
                       event.preventDefault();
                       console.log('/search/node/' + $('#globalSearchInput').val());

                       $(location).attr(
                         'href',
                         '/search/node/' + $('#globalSearchInput').val()
                       );
                     });

                   });
                 </script>
               </li><!-- Search -->

               <li data-theme="b"><a href="/product_finder">Product Finder</a></li>
               <li data-theme="b"><a href="/wheretobuy">Where to Buy</a></li>
               <li data-theme="b"><a href="/sitemap">Sitemap</a></li>
               <li data-theme="b"><a href="/contact">Contact Us</a></li>
               <li data-theme="b"><a href="#selectRegionBox" data-rel="popup" data-transition="pop" onclick="javascript:selectRegion();">Change Country/Language</a></li>

               <div id="selectRegionBox" data-role="popup" style="padding:1em;">

                 <h4>Welcome to Fluke Networks</h4>

                 <form action="" method="post" name="region">

                   <h6>Select your country:</h6>

                   <div class="OneLinkNoTx">
                     <select id="regionCountry" name="regionCountry" onchange="countryLanguage(this.value);">
                       <option value="">-- Country --</option>
                       <option value="US" selected="">United States</option><option value="CA">Canada</option><option value="AF">Afghanistan</option><option value="AL">Albania</option><option value="DZ">Algeria</option><option value="AD">Andorra</option><option value="AO">Angola</option><option value="AR">Argentina</option><option value="AM">Armenia</option><option value="AU">Australia</option><option value="AT">Austria</option><option value="AZ">Azerbaijan</option><option value="BH">Bahrain</option><option value="BD">Bangladesh</option><option value="BY">Belarus</option><option value="BE">Belgium</option><option value="BJ">Benin</option><option value="BT">Bhutan</option><option value="BA">Bosnia and Herzegovina</option><option value="BW">Botswana</option><option value="BR">Brazil</option><option value="BN">Brunei</option><option value="BG">Bulgaria</option><option value="BF">Burkina Faso</option><option value="BI">Burundi</option><option value="KH">Cambodia</option><option value="CM">Cameroon</option><option value="CV">Cape Verde</option><option value="CF">Central African Republic</option><option value="TD">Chad</option><option value="CL">Chile</option><option value="CN">China</option><option value="CO">Colombia</option><option value="KM">Comoros</option><option value="CG">Congo</option><option value="CD">Congo, Democratic Republic of the</option><option value="CR">Costa Rica</option><option value="CI">Côte d'Ivoire</option><option value="HR">Croatia</option><option value="CY">Cyprus</option><option value="CZ">Czech Republic</option><option value="DK">Denmark</option><option value="DJ">Djibouti</option><option value="TP">East Timor</option><option value="EC">Ecuador</option><option value="EG">Egypt</option><option value="GQ">Equatorial Guinea</option><option value="ER">Eritrea</option><option value="EE">Estonia</option><option value="ET">Ethiopia</option><option value="FI">Finland</option><option value="FR">France</option><option value="GA">Gabon</option><option value="GM">Gambia</option><option value="GE">Georgia</option><option value="DE">Germany</option><option value="GH">Ghana</option><option value="GR">Greece</option><option value="GT">Guatemala</option><option value="GN">Guinea</option><option value="GW">Guinea-Bissau</option><option value="HK">Hong Kong</option><option value="HU">Hungary</option><option value="IS">Iceland</option><option value="IN">India</option><option value="ID">Indonesia</option><option value="IQ">Iraq</option><option value="IE">Ireland</option><option value="IL">Israel</option><option value="IT">Italy</option><option value="JM">Jamaica</option><option value="JP">Japan</option><option value="JO">Jordan</option><option value="KZ">Kazakhstan</option><option value="KE">Kenya</option><option value="KR">Korea South</option><option value="XK">Kosovo</option><option value="KW">Kuwait</option><option value="KG">Kyrgyzstan</option><option value="LA">Laos</option><option value="LV">Latvia</option><option value="LB">Lebanon</option><option value="LS">Lesotho</option><option value="LR">Liberia</option><option value="LY">Libya</option><option value="LI">Liechtenstein</option><option value="LT">Lithuania</option><option value="LU">Luxembourg</option><option value="MO">Macau</option><option value="MK">Macedonia</option><option value="MG">Madagascar</option><option value="MW">Malawi</option><option value="MY">Malaysia</option><option value="ML">Mali</option><option value="MT">Malta</option><option value="MR">Mauritania</option><option value="MU">Mauritius</option><option value="MX">Mexico</option><option value="MD">Moldova</option><option value="MC">Monaco</option><option value="MN">Mongolia</option><option value="ME">Montenegro</option><option value="MA">Morocco</option><option value="MZ">Mozambique</option><option value="MM">Myanmar (Burma)</option><option value="NA">Namibia</option><option value="NP">Nepal</option><option value="NL">Netherlands</option><option value="NZ">New Zealand</option><option value="NE">Niger</option><option value="NG">Nigeria</option><option value="NO">Norway</option><option value="OM">Oman</option><option value="PK">Pakistan</option><option value="PA">Panama</option><option value="PE">Peru</option><option value="PH">Philippines</option><option value="PL">Poland</option><option value="PT">Portugal</option><option value="QA">Qatar</option><option value="RO">Romania</option><option value="RU">Russia</option><option value="RW">Rwanda</option><option value="SM">San Marino</option><option value="ST">Sao Tome and Principe</option><option value="SA">Saudi Arabia</option><option value="SN">Senegal</option><option value="RS">Serbia</option><option value="SC">Seychelles</option><option value="SL">Sierra Leone</option><option value="SG">Singapore</option><option value="SK">Slovakia</option><option value="SI">Slovenia</option><option value="SO">Somalia</option><option value="ZA">South Africa</option><option value="ES">Spain</option><option value="LK">Sri Lanka</option><option value="SD">Sudan</option><option value="SZ">Swaziland</option><option value="SE">Sweden</option><option value="CH">Switzerland</option><option value="TW">Taiwan</option><option value="TJ">Tajikistan</option><option value="TZ">Tanzania</option><option value="TH">Thailand</option><option value="TG">Togo</option><option value="TN">Tunisia</option><option value="TR">Turkey</option><option value="TM">Turkmenistan</option><option value="UG">Uganda</option><option value="UA">Ukraine</option><option value="AE">United Arab Emirates</option><option value="GB">United Kingdom</option><option value="UZ">Uzbekistan</option><option value="VA">Vatican City (Holy See)</option><option value="VE">Venezuela</option><option value="VN">Vietnam</option><option value="YE">Yemen</option><option value="ZM">Zambia</option><option value="ZW">Zimbabwe</option>
                     </select>
                   </div>

                   <h6>Select available language:</h6>
                   <select id="language" name="language"></select>

                   <a href="javascript:setRegion();" data-role="button" class="button-yellow family-products-link">Submit</a>

                 </form>

               </div>

             </ul>
        </div>

        <div id="header-blue" data-role="header" data-theme="<?php print $header_data_theme; ?>" data-position="<?php print $header_data_position; ?>">

          <h1>
            <a class="ui-link" href="/">
              <img class="logo" alt="Fluke Networks" src="/<?php print path_to_theme(); ?>/flukenetworks_logo.gif">
              <?php // print $site_name; ?>
            </a>
          </h1>

          <a href="#panel-navigation" data-icon="bars" data-iconpos="notext" data-theme="b" data-inline="true" data-iconshadow="false" class="ui-icon-nodisc" title="Navigation">Navigation</a>

          <a href="#panel-search" data-icon="search" data-iconpos="notext" data-theme="b" data-inline="true" data-iconshadow="false" class="ui-icon-nodisc" title="Search">Search</a>

        </div><!-- /header -->

        <div data-role="content" data-theme="<?php print $content_data_theme; ?>">
            <div class="content-primary">

                <?php print $content; ?>

            </div>
        </div><!-- /data-role="content" -->

        <div id="page-footer" data-role="footer" data-theme="f" data-position="inline">

          <ul class="footer_social_icon">
            <li><a id="footer_social_icon_twitter" href="http://flukenetworksdev.danahertm.com/twitter" target="_blank">Twitter</a></li>
            <li><a id="footer_social_icon_facebook" href="http://www.facebook.com/flukenetworks" target="_blank">Facebook</a></li>
            <li><a id="footer_social_icon_youtube" href="http://www.youtube.com/flukenetworksvideo" target="_blank">YouTube</a></li>
            <li class="last"><a id="footer_social_icon_rss" href="http://flukenetworksdev.danahertm.com/rss" target="_blank">RSS</a></li>
          </ul>

          <ul>
            <li><a href="http://www.danaherintegrity.com/" target="_blank">Integrity and Compliance Program</a></li>
            <li><a href="/about/privacy">Privacy Policy</a></li>
            <li><a href="/about/terms-of-use">Terms of Use</a></li>
            <li class="last"><a href="/sitemap">Sitemap</a></li>
          </ul>

          <p>© 2006-2014 Fluke Corporation. All rights reserved.</p>

        </div><!-- /footer -->

    </div><!-- /page -->

</body>
</html>