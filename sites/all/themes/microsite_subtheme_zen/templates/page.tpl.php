<?php
/**
 * @file
 * Returns the HTML for a single Drupal page.
 *
 * Complete documentation for this file is available online.
 * @see https://drupal.org/node/1728148
 */
?>

<div id="page">

  <div id="header">
    <div class="inner-wrapper">

      <div id="change-country-language">
        <a href="#selectRegionBox" onclick="javascript:selectRegion();" id="menu-change-language" class="active">Change Country/Language</a>
      </div>

      <div class="section clearfix">

        <?php print render($page['header']); ?>

      </div>
      <div class="clearboth"></div>

      <div id="section-menu">
        <div class="inner-wrapper">
          <div class="section clearfix">

            <?php print render($page['section_menu']); ?>

          </div>
          <div class="clearboth"></div>
        </div>
      </div> <!-- /.section, /.inner-wrapper, /#section-menu -->

    </div>
  </div> <!-- /.section, /.inner-wrapper, /#header -->

  <div id="main">

    <div id="content" class="column" role="main">
      <div class="section">

        <div id="content-area">

          <div id="content-column">
            <?php print render($page['content']); ?>
            <div class="clearboth"></div>
          </div><!-- .section #content-area #content-column -->

          <div id="region-sideblocks">
            <?php print render($page['sideblocks']); ?>
            <div class="clearboth"></div>
          </div><!-- .section #content-area #region-sideblocks -->

          <div class="clearboth"></div>

        </div><!-- .section #content-area -->

      </div>
    </div>

  </div>

  <div id="footer">
    <div class="section">

      <?php print render($page['footer']); ?>

      <div id="footer-message">&copy; <?php print date("Y"); ?> Fluke Corporation. All rights reserved.</div>

      <div class="clearboth"></div>

    </div>
    <div class="clearboth"></div>
  </div> <!-- /.section, /#footer -->

  <!-- START: Wrapping all analytics code in div to match footer background color in case extra elements are created -->
  <div style="background-color:#ebebeb;">

    <?php if (empty($_SERVER['HTTPS'])) { // Only loading analytics code on non-secure pages. ?>

      <!-- LeadLander -->
      <!-- script type="text/javascript" language="javascript">i=12103</script -->
      <!-- script type="text/javascript" language="javascript" src="http://t2.trackalyzer.com/trackalyze.js"></script -->
      <script type="text/javascript" language="javascript">llactid = 12103</script>
      <script type="text/javascript" language="javascript" src="http://t6.trackalyzer.com/trackalyze.js"></script>
      <?php
      $qPath = $_GET['q'];
      if ($node->type == 'marketo_form' || $qPath == 'where2buy' || strpos($qPath, 'ems/registration/add/') !== FALSE): ?>
        <script type="text/javascript">llfrmid = 12103</script>
        <script type="text/javascript" src="http://formalyzer.com/formalyze_init.js"></script>
        <script type="text/javascript" src="http://formalyzer.com/formalyze_call.js"></script>
      <?php endif; ?>

      <!--Google -->
      <meta name="google-site-verification" content="yH4QxKQIuhIR0gYw8o50ubbthoG-v6TadOK02RbmuWQ"/>

      <!--Bing -->
      <meta name="msvalidate.01" content="3641B35956F1B33717802D1D96205243"/>

      <!-- Baidu - Begin -->
      <?php /* if ($_SERVER["HTTP_X_ORIGINALHOST"] == 'cn.flukenetworks.com') { ?>
        <div style="display:none;">
          <script type="text/javascript">
            var _bdhmProtocol = (("https:" == document.location.protocol) ? " https://" : " http://");
            document.write(unescape("%3Cscript src='" + _bdhmProtocol + "hm.baidu.com/h.js%3F1a84a676e166d764c85ba3991201d4b7' type='text/javascript'%3E%3C/script%3E"));
          </script>
        </div>
      <?php } */ ?>
      <!-- Baidu - End -->

      <!-- Marketo - Begin -->
      <script type="text/javascript">
        $.ajax({
          url: '//munchkin.marketo.net/munchkin.js',
          dataType: 'script',
          cache: true,
          success: function () {
            Munchkin.init('709-HGB-925');
          }
        });
      </script>
      <!-- Marketo - End -->

      <!-- Pop.to Widget Loader Script - Begin -->
      <script type="text/javascript"
              src="//b2c-mlm.marketo.com/jsloader/efa80e1e-483c-4600-874d-bfef6db9cb8f/loader.php.js"></script>
      <!-- Pop.to Widget Loader Script - End -->

      <!-- AdRoll - Begin -->
      <script type="text/javascript">
        adroll_adv_id = "WSU4GPASZNDF3OZ3SRRKQ7";
        adroll_pix_id = "GT6H2PIAPRHMNPRV5CLIXY";
        (function () {
          var oldonload = window.onload;
          window.onload = function () {
            __adroll_loaded = true;
            var scr = document.createElement("script");
            var host = (("https:" == document.location.protocol) ? "https://s.adroll.com" : "http://a.adroll.com");
            scr.setAttribute('async', 'true');
            scr.type = "text/javascript";
            scr.src = host + "/j/roundtrip.js";
            ((document.getElementsByTagName('head') || [null])[0] ||
              document.getElementsByTagName('script')[0].parentNode).appendChild(scr);
            if (oldonload) {
              oldonload()
            }
          };
        }());
      </script>
      <!-- AdRoll - End -->

    <?php } ?>

  </div>
  <!-- END: Wrapping all analytics code in div to match footer background color in case extra elements are created -->

  <!-- START: Select Region Pop-Up Form -->
  <div style="display:none;">
    <div id="selectRegionBox">

      <h6 style="font-size:1em; font-weight:bold;">Welcome to Fluke Networks</h6>

      <form action="" method="post" name="region">

        <h6 style="font-size:1em; font-weight:bold;">Select your country:</h6>

        <div class="OneLinkNoTx">
          <select id="regionCountry" name="regionCountry" onchange="countryLanguage(this.value);">
            <option value="">-- Country --</option>
            <option value="US" selected="">United States</option><option value="CA">Canada</option><option value="AF">Afghanistan</option><option value="AL">Albania</option><option value="DZ">Algeria</option><option value="AD">Andorra</option><option value="AO">Angola</option><option value="AR">Argentina</option><option value="AM">Armenia</option><option value="AU">Australia</option><option value="AT">Austria</option><option value="AZ">Azerbaijan</option><option value="BH">Bahrain</option><option value="BD">Bangladesh</option><option value="BY">Belarus</option><option value="BE">Belgium</option><option value="BJ">Benin</option><option value="BT">Bhutan</option><option value="BA">Bosnia and Herzegovina</option><option value="BW">Botswana</option><option value="BR">Brazil</option><option value="BN">Brunei</option><option value="BG">Bulgaria</option><option value="BF">Burkina Faso</option><option value="BI">Burundi</option><option value="KH">Cambodia</option><option value="CM">Cameroon</option><option value="CV">Cape Verde</option><option value="CF">Central African Republic</option><option value="TD">Chad</option><option value="CL">Chile</option><option value="CN">China</option><option value="CO">Colombia</option><option value="KM">Comoros</option><option value="CG">Congo</option><option value="CD">Congo, Democratic Republic of the</option><option value="CR">Costa Rica</option><option value="CI">Côte d'Ivoire</option><option value="HR">Croatia</option><option value="CY">Cyprus</option><option value="CZ">Czech Republic</option><option value="DK">Denmark</option><option value="DJ">Djibouti</option><option value="TP">East Timor</option><option value="EC">Ecuador</option><option value="EG">Egypt</option><option value="GQ">Equatorial Guinea</option><option value="ER">Eritrea</option><option value="EE">Estonia</option><option value="ET">Ethiopia</option><option value="FI">Finland</option><option value="FR">France</option><option value="GA">Gabon</option><option value="GM">Gambia</option><option value="GE">Georgia</option><option value="DE">Germany</option><option value="GH">Ghana</option><option value="GR">Greece</option><option value="GT">Guatemala</option><option value="GN">Guinea</option><option value="GW">Guinea-Bissau</option><option value="HK">Hong Kong</option><option value="HU">Hungary</option><option value="IS">Iceland</option><option value="IN">India</option><option value="ID">Indonesia</option><option value="IQ">Iraq</option><option value="IE">Ireland</option><option value="IL">Israel</option><option value="IT">Italy</option><option value="JM">Jamaica</option><option value="JP">Japan</option><option value="JO">Jordan</option><option value="KZ">Kazakhstan</option><option value="KE">Kenya</option><option value="KR">Korea South</option><option value="XK">Kosovo</option><option value="KW">Kuwait</option><option value="KG">Kyrgyzstan</option><option value="LA">Laos</option><option value="LV">Latvia</option><option value="LB">Lebanon</option><option value="LS">Lesotho</option><option value="LR">Liberia</option><option value="LY">Libya</option><option value="LI">Liechtenstein</option><option value="LT">Lithuania</option><option value="LU">Luxembourg</option><option value="MO">Macau</option><option value="MK">Macedonia</option><option value="MG">Madagascar</option><option value="MW">Malawi</option><option value="MY">Malaysia</option><option value="ML">Mali</option><option value="MT">Malta</option><option value="MR">Mauritania</option><option value="MU">Mauritius</option><option value="MX">Mexico</option><option value="MD">Moldova</option><option value="MC">Monaco</option><option value="MN">Mongolia</option><option value="ME">Montenegro</option><option value="MA">Morocco</option><option value="MZ">Mozambique</option><option value="MM">Myanmar (Burma)</option><option value="NA">Namibia</option><option value="NP">Nepal</option><option value="NL">Netherlands</option><option value="NZ">New Zealand</option><option value="NE">Niger</option><option value="NG">Nigeria</option><option value="NO">Norway</option><option value="OM">Oman</option><option value="PK">Pakistan</option><option value="PA">Panama</option><option value="PE">Peru</option><option value="PH">Philippines</option><option value="PL">Poland</option><option value="PT">Portugal</option><option value="QA">Qatar</option><option value="RO">Romania</option><option value="RU">Russia</option><option value="RW">Rwanda</option><option value="SM">San Marino</option><option value="ST">Sao Tome and Principe</option><option value="SA">Saudi Arabia</option><option value="SN">Senegal</option><option value="RS">Serbia</option><option value="SC">Seychelles</option><option value="SL">Sierra Leone</option><option value="SG">Singapore</option><option value="SK">Slovakia</option><option value="SI">Slovenia</option><option value="SO">Somalia</option><option value="ZA">South Africa</option><option value="ES">Spain</option><option value="LK">Sri Lanka</option><option value="SD">Sudan</option><option value="SZ">Swaziland</option><option value="SE">Sweden</option><option value="CH">Switzerland</option><option value="TW">Taiwan</option><option value="TJ">Tajikistan</option><option value="TZ">Tanzania</option><option value="TH">Thailand</option><option value="TG">Togo</option><option value="TN">Tunisia</option><option value="TR">Turkey</option><option value="TM">Turkmenistan</option><option value="UG">Uganda</option><option value="UA">Ukraine</option><option value="AE">United Arab Emirates</option><option value="GB">United Kingdom</option><option value="UZ">Uzbekistan</option><option value="VA">Vatican City (Holy See)</option><option value="VE">Venezuela</option><option value="VN">Vietnam</option><option value="YE">Yemen</option><option value="ZM">Zambia</option><option value="ZW">Zimbabwe</option>
          </select>
        </div>

        <h6 style="font-size:1em; font-weight:bold;">Select available language:</h6>
        <select id="language" name="language"></select>

        <p class="centered smaller"><a class="btn" onclick="javascript:setRegion();" href="javascript:void(0);">Submit</a></p>

      </form>

    </div>
  </div>
  <script>
    $(document).ready(function() {

      $("#menu-change-language").fancybox({
        'transitionIn'	:	'elastic',
        'transitionOut'	:	'elastic',
        'speedIn'		:	600,
        'speedOut'		:	200,
        'overlayShow'	:	false
      });

    });
  </script>
  <!-- END: Select Region Pop-Up Form -->

</div>
