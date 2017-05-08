<?php
// $Id$

/**
 * @file
 * Describe the purpose of the file here.
 *
 */
?>

<link rel="stylesheet" type="text/css" media="screen"
      href="http://info.flukenetworks.com/css/mktLPSupport.css"/>
<script type="text/javascript"
        src="//b2c-mlm.marketo.com/jsloader/efa80e1e-483c-4600-874d-bfef6db9cb8f/loader.php.js"></script>
<span class="lpContentsItem formSpan">
<div class="subscribe_div">
  <div class="subscribe_div_title">
    <h3><span id="word-subscribe">Subscribe</span><br /><span id="word-and">and</span> <span id="word-connect">Connect</span></h3>
    <p>Gain insight on new approaches and technologies, delivered to your inbox!</p>
  </div>
  <div id="socialSignOnHoldingPen" class="cf_widget cf_widget_socialsignon">
    <script type="text/javascript"
            src="http://info.flukenetworks.com/js/mktFormSupport.js"></script>

    <script type="text/javascript">
      var formEdit = false;

      var socialSignOn = {
        isEnabled: false,
        enabledNetworks: [''],
        cfId: '',
        codeSnippet: ''
      };
    </script>
  </div>
  <div class="subscribe_div_form">
  <form class="lpeRegForm formNotEmpty" method="post"
        enctype="application/x-www-form-urlencoded"
        action="http://info.flukenetworks.com/index.php/leadCapture/save"
        id="mktForm_3574" name="mktForm_3574" style="padding:0px;margin:0px;">
    <div id="cio-brief-input-wrapper">
      <input class='mktFormText mktFormEmail mktFReq Network_On-Black3'
                   placeholder="Email address" name="Email" id="Email"
                   type='text' maxlength='255' tabIndex='1'
                   onFocus="javascript:clearEmailForm();"/>
      <span class='mktFormMsg'></span>
    </div>
    <div id="cio-brief-subscribe-button">
        <a href="#"
           onclick='formSubmit(document.getElementById("mktForm_3574")); return false;'><?php print t('Subscribe'); ?></a>
    </div>
    <span style="display:none;">
      <input type="text" name="_marketo_comments" value=""/>
    </span>
    <input type="hidden" name="lpId" value="15781"/>
    <input type="hidden" name="subId" value="217"/>
    <input type="hidden" name="munchkinId" value="709-HGB-925"/>
    <input type="hidden" name="kw" value=""/>
    <input type="hidden" name="cr" value=""/>
    <input type="hidden" name="searchstr" value=""/>
    <input type="hidden" name="lpurl"
           value="http://info.flukenetworks.com/CIONewsletterSubscription.html?cr={creative}&kw={keyword}"/>
    <input type="hidden" name="formid" value="3574"/>
    <input type="hidden" name="returnURL"
           value="http://www.flukenetworks.com/content/cio-newsletter-subscribed"/>
    <input type="hidden" name="retURL"
           value="http://www.flukenetworks.com/content/cio-newsletter-subscribed"/>
    <input type="hidden" name="returnLPId" value="-1"/>
    <input type="hidden" name="_mkt_disp" value="return"/>
    <input type="hidden" name="_mkt_trk"
           value="id:709-HGB-925&token:_mch-flukenetworks.com-1360694405383-21882"/>
  </form>
  </div>
  <div id="cio-brief-social-wrapper">
    <ul class="social_media">
      <li><a href="https://twitter.com/FlukeNetENT" title="Twitter"><i class="fa fa-twitter"></i></a></li>
      <li><a href="https://www.facebook.com/flukenetworks?fref=ts" title="Facebook"><i class="fa fa-facebook"></i></a></li>
      <li><a href="https://www.linkedin.com/company/fluke-networks?goback=.fcs_GLHD_fluke+networks_false_*2_*2_*2_*2_*2_*2_*2_*2_*2_*2_*2_*2&trk=ncsrch_hits" title="LinkedIn"><i class="fa fa-linkedin"></i></a></li>
      <li><a href="https://www.youtube.com/user/FlukeNetworksVideo/featured" title="YouTube"><i class="fa fa-youtube"></i></a></li>
      <li><a href="/blog"><i class="fa fa-rss" title="Fluke Networks Blog"></i></a></li>
    </ul>
  </div>
  <div class="clearfix"></div>
</span>
</div>
<script type="text/javascript">

  var mktoPreFillFields = {"Email": null};

  function fieldValidate(field) {
    /* call Mkto.setError(field, message) and return false to mark a field value invalid */
    /* return 'skip' to bypass the built-in validations */
    return true;
  }
  function getRequiredFieldMessage(domElement, label) {
    return "This field is required";
  }
  function getTelephoneInvalidMessage(domElement, label) {
    return "Please enter a valid telephone number";
  }
  function getEmailInvalidMessage(domElement, label) {
    return "Please enter a valid email address";
  }
</script>

<script type="text/javascript"
        src="http://info.flukenetworks.com/js/public/jquery-latest.min.js"></script>
<script type="text/javascript"
        src="http://info.flukenetworks.com/rs/fluke/images/stateCountryPlusAustralia.js"></script>

<script type="text/javascript">
  // set no conflict mode for jquery
  var $jQ = jQuery.noConflict();

  $jQ(document).ready(function () {
    // all form submits will open in a new window
    $jQ('.lpeRegForm').attr('target', '_top');

    var ridUrl = getQueryVariable("retid");
    var rUrl = getQueryVariable("ret");

    if (ridUrl) {
      ridUrl = "http://myaccount.flukenetworks.com/FNet/en-us/findit?Document=" + ridUrl;
      $jQ("input[name='returnURL']").attr('value', ridUrl);
      $jQ("input[name='retURL']").attr('value', ridUrl);
    } else if (rUrl) {
      $jQ("input[name='returnURL']").attr('value', rUrl);
      $jQ("input[name='retURL']").attr('value', rUrl);
    }
  });

  function getQueryVariable(variable) {
    var query = window.location.search.substring(1);
    var vars = query.split("&");
    for (var i = 0; (i < vars.length); i++) {
      var pair = vars[i].split("=");
      if (pair[0] == variable) {
        return unescape(pair[1]);
      }
    }
    return false;
  }
</script>

<script type="text/javascript"
        src="http://info.flukenetworks.com/js/mktFormSupport.js"></script>
<script type="text/javascript">
  function formSubmit(elt) {
    if (document.mktForm_3574.Email.value == "") {
      alert("Enter an email address");
      return false;
    } else {
      return Mkto.formSubmit(elt);
    }
  }
  function formReset(elt) {
    return Mkto.formReset(elt);
  }
</script>

<script type="text/javascript">
  var profiling = {
    isEnabled: false,
    numberOfProfilingFields: 3,
    alwaysShowFields: ['mktDummyEntry']
  };
  var mktFormLanguage = 'English'

  function clearEmailForm() {
    if (document.mktForm_3574.Email.value == "Enter Email Address") {
      document.mktForm_3574.Email.value = "";
    }
  }
</script>
<script type="text/javascript"> function mktoGetForm() {
    return document.getElementById('mktForm_3574');
  }</script>
