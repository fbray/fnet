<?php
/**
 * Created by PhpStorm.
 * User: jcaratoz
 * Date: 5/13/14
 * Time: 2:55 PM
 */

$siteReg = module_invoke('fnet_helper', 'site_region');
$serverName = $siteReg["serverName"];
$langReg = $siteReg["langReg"];
$regLang = $siteReg["regLang"];

// Language overrides
$noTranslation = array();

$validLangNode = array();
foreach ($node->field_industry_language as $key=>$val) {
  foreach ($val as $k=>$v) {
    if ($k == "nid")
      $validLangNode[$v] = 1;
  }
}
if (count($validLangNode) > 0) {
  $langNodeId = "";
  $indLang = views_get_view_result('admin_industry_language');
  if (count($indLang) > 0) {
    foreach ($indLang as $lang) {
      if ($validLangNode[$lang->nid] &&
        substr($lang->node_data_field_indlang_industry_field_indlang_language_value, 0, 5) == $regLang) {
        $langNodeId = $lang->nid;
        break;
      }
    }
    if (! empty($langNodeId)) {
      $langNode = node_load($langNodeId);
      if ($langNode->field_indlang_banner_txt_1[0]['value'] || $langNode->field_indlang_banner_txt_2[0]['value'] ||
        $langNode->field_indlang_banner_txt_3[0]['value'] || $langNode->field_indlang_banner_txt_4[0]['value'] ||
        $langNode->field_indlang_banner_txt_5[0]['value']) {
        $noTranslation["home_banner"] = true;
        $node->field_industry_banner_txt_1[0]['value'] = $langNode->field_indlang_banner_txt_1[0]['value'];
        $node->field_industry_banner_srt_1[0]['value'] = $langNode->field_indlang_banner_srt_1[0]['value'];
        $node->field_industry_banner_txt_2[0]['value'] = $langNode->field_indlang_banner_txt_2[0]['value'];
        $node->field_industry_banner_srt_2[0]['value'] = $langNode->field_indlang_banner_srt_2[0]['value'];
        $node->field_industry_banner_txt_3[0]['value'] = $langNode->field_indlang_banner_txt_3[0]['value'];
        $node->field_industry_banner_srt_3[0]['value'] = $langNode->field_indlang_banner_srt_3[0]['value'];
        $node->field_industry_banner_txt_4[0]['value'] = $langNode->field_indlang_banner_txt_4[0]['value'];
        $node->field_industry_banner_srt_4[0]['value'] = $langNode->field_indlang_banner_srt_4[0]['value'];
        $node->field_industry_banner_txt_5[0]['value'] = $langNode->field_indlang_banner_txt_5[0]['value'];
        $node->field_industry_banner_srt_5[0]['value'] = $langNode->field_indlang_banner_srt_5[0]['value'];
      }

      if ($langNode->field_indlang_overview_intro[0]['value']) {
        $noTranslation["field_industry_overview_intro"] = true;
        $node->field_industry_overview_intro[0]['value'] = $langNode->field_indlang_overview_intro[0]['value'];
      }
      if ($langNode->field_indlang_box_disable_1[0]['value'] == "Yes") {
        $node->field_industry_box_title_1[0]['value'] = "";
        $node->field_industry_box_desc_1[0]['value'] = "";
      } else if ($langNode->field_indlang_box_title_1[0]['value'] && $langNode->field_indlang_box_desc_1[0]['value']) {
        $noTranslation["field_industry_box_title_1"] = true;
        $node->field_industry_box_title_1[0]['value'] = $langNode->field_indlang_box_title_1[0]['value'];
        $node->field_industry_box_desc_1[0]['value'] = $langNode->field_indlang_box_desc_1[0]['value'];
        $node->field_industry_box_img_1[0]['fid'] = $langNode->field_indlang_box_img_1[0]['fid'];
        $node->field_industry_box_url_1[0]["title"] = $langNode->field_indlang_box_link_1[0]["title"];
        $node->field_industry_box_url_1[0]["display_url"] = $langNode->field_indlang_box_link_1[0]["url"];
        $node->field_industry_box_url_1[0]["attributes"]["target"] = $langNode->field_indlang_box_link_1[0]["attributes"]["target"];
      }
      if ($langNode->field_indlang_box_disable_2[0]['value'] == "Yes") {
        $node->field_industry_box_title_2[0]['value'] = "";
        $node->field_industry_box_desc_2[0]['value'] = "";
      } else if ($langNode->field_indlang_box_title_2[0]['value'] && $langNode->field_indlang_box_desc_2[0]['value']) {
        $noTranslation["field_industry_box_title_2"] = true;
        $node->field_industry_box_title_2[0]['value'] = $langNode->field_indlang_box_title_2[0]['value'];
        $node->field_industry_box_desc_2[0]['value'] = $langNode->field_indlang_box_desc_2[0]['value'];
        $node->field_industry_box_img_2[0]['fid'] = $langNode->field_indlang_box_img_2[0]['fid'];
        $node->field_industry_box_url_2[0]["title"] = $langNode->field_indlang_box_link_2[0]["title"];
        $node->field_industry_box_url_2[0]["display_url"] = $langNode->field_indlang_box_link_2[0]["url"];
        $node->field_industry_box_url_2[0]["attributes"]["target"] = $langNode->field_indlang_box_link_2[0]["attributes"]["target"];
      }
      if ($langNode->field_indlang_box_disable_3[0]['value'] == "Yes") {
        $node->field_industry_box_title_3[0]['value'] = "";
        $node->field_industry_box_desc_3[0]['value'] = "";
      } else if ($langNode->field_indlang_box_title_3[0]['value'] && $langNode->field_indlang_box_desc_3[0]['value']) {
        $noTranslation["field_industry_box_title_3"] = true;
        $node->field_industry_box_title_3[0]['value'] = $langNode->field_indlang_box_title_3[0]['value'];
        $node->field_industry_box_desc_3[0]['value'] = $langNode->field_indlang_box_desc_3[0]['value'];
        $node->field_industry_box_img_3[0]['fid'] = $langNode->field_indlang_box_img_3[0]['fid'];
        $node->field_industry_box_url_3[0]["title"] = $langNode->field_indlang_box_link_3[0]["title"];
        $node->field_industry_box_url_3[0]["display_url"] = $langNode->field_indlang_box_link_3[0]["url"];
        $node->field_industry_box_url_3[0]["attributes"]["target"] = $langNode->field_indlang_box_link_3[0]["attributes"]["target"];
      }

      if ($langNode->field_indlang_pop_res_disable[0]['value'] == "Yes") {
        $node->field_industry_pop_res_1[0]['title'] = "";
        $node->field_industry_pop_res_2[0]['title'] = "";
        $node->field_industry_pop_res_3[0]['title'] = "";
      } else if ($langNode->field_indlang_pop_res_1[0]['title'] ||
        $langNode->field_indlang_pop_res_2[0]['title'] ||
        $langNode->field_indlang_pop_res_3[0]['title']) {
        $noTranslation["field_industry_pop_res_1"] = true;
        $noTranslation["field_industry_pop_res_2"] = true;
        $noTranslation["field_industry_pop_res_3"] = true;
        $node->field_industry_pop_res_1[0]['title'] = $langNode->field_indlang_pop_res_1[0]['title'];
        $node->field_industry_pop_res_1[0]['display_url'] = $langNode->field_indlang_pop_res_1[0]['url'];
        $node->field_industry_pop_res_1[0]['attributes']['target'] = $langNode->field_indlang_pop_res_1[0]['attributes']['target'];
        $node->field_industry_pop_res_2[0]['title'] = $langNode->field_indlang_pop_res_2[0]['title'];
        $node->field_industry_pop_res_2[0]['display_url'] = $langNode->field_indlang_pop_res_2[0]['url'];
        $node->field_industry_pop_res_2[0]['attributes']['target'] = $langNode->field_indlang_pop_res_2[0]['attributes']['target'];
        $node->field_industry_pop_res_3[0]['title'] = $langNode->field_indlang_pop_res_3[0]['title'];
        $node->field_industry_pop_res_3[0]['display_url'] = $langNode->field_indlang_pop_res_3[0]['url'];
        $node->field_industry_pop_res_3[0]['attributes']['target'] = $langNode->field_indlang_pop_res_3[0]['attributes']['target'];
      }
      if ($langNode->field_indlang_learn_abt_disable[0]['value'] == "Yes") {
        $node->field_industry_learn_abt_1[0]['title'] = "";
        $node->field_industry_learn_abt_2[0]['title'] = "";
        $node->field_industry_learn_abt_3[0]['title'] = "";
      } else if ($langNode->field_indlang_learn_abt_1[0]['title'] ||
        $langNode->field_indlang_learn_abt_2[0]['title'] ||
        $langNode->field_indlang_learn_abt_3[0]['title']) {
        $noTranslation["field_industry_learn_abt_1"] = true;
        $noTranslation["field_industry_learn_abt_2"] = true;
        $noTranslation["field_industry_learn_abt_3"] = true;
        $node->field_industry_learn_abt_1[0]['title'] = $langNode->field_indlang_learn_abt_1[0]['title'];
        $node->field_industry_learn_abt_1[0]['display_url'] = $langNode->field_indlang_learn_abt_1[0]['url'];
        $node->field_industry_learn_abt_1[0]['attributes']['target'] = $langNode->field_indlang_learn_abt_1[0]['attributes']['target'];
        $node->field_industry_learn_abt_2[0]['title'] = $langNode->field_indlang_learn_abt_2[0]['title'];
        $node->field_industry_learn_abt_2[0]['display_url'] = $langNode->field_indlang_learn_abt_2[0]['url'];
        $node->field_industry_learn_abt_2[0]['attributes']['target'] = $langNode->field_indlang_learn_abt_2[0]['attributes']['target'];
        $node->field_industry_learn_abt_3[0]['title'] = $langNode->field_indlang_learn_abt_3[0]['title'];
        $node->field_industry_learn_abt_3[0]['display_url'] = $langNode->field_indlang_learn_abt_3[0]['url'];
        $node->field_industry_learn_abt_3[0]['attributes']['target'] = $langNode->field_indlang_learn_abt_3[0]['attributes']['target'];
      }
      if ($langNode->field_indlang_fea_top_disable[0]['value'] == "Yes") {
        $node->field_industry_fea_top_1[0]['title'] = "";
        $node->field_industry_fea_top_2[0]['title'] = "";
        $node->field_industry_fea_top_3[0]['title'] = "";
      } else if ($langNode->field_indlang_fea_top_1[0]['title'] ||
        $langNode->field_indlang_fea_top_2[0]['title'] ||
        $langNode->field_indlang_fea_top_3[0]['title']) {
        $noTranslation["field_industry_fea_top_1"] = true;
        $noTranslation["field_industry_fea_top_2"] = true;
        $noTranslation["field_industry_fea_top_3"] = true;
        $node->field_industry_fea_top_1[0]['title'] = $langNode->field_indlang_fea_top_1[0]['title'];
        $node->field_industry_fea_top_1[0]['display_url'] = $langNode->field_indlang_fea_top_1[0]['url'];
        $node->field_industry_fea_top_1[0]['attributes']['target'] = $langNode->field_indlang_fea_top_1[0]['attributes']['target'];
        $node->field_industry_fea_top_2[0]['title'] = $langNode->field_indlang_fea_top_2[0]['title'];
        $node->field_industry_fea_top_2[0]['display_url'] = $langNode->field_indlang_fea_top_2[0]['url'];
        $node->field_industry_fea_top_2[0]['attributes']['target'] = $langNode->field_indlang_fea_top_2[0]['attributes']['target'];
        $node->field_industry_fea_top_3[0]['title'] = $langNode->field_indlang_fea_top_3[0]['title'];
        $node->field_industry_fea_top_3[0]['display_url'] = $langNode->field_indlang_fea_top_3[0]['url'];
        $node->field_industry_fea_top_3[0]['attributes']['target'] = $langNode->field_indlang_fea_top_3[0]['attributes']['target'];
      }

      if ($langNode->field_indlang_expertise_box[0]['value']) {
        $noTranslation["field_industry_expertise_box"] = true;
        $node->field_industry_expertise_box[0]['value'] = $langNode->field_indlang_expertise_box[0]['value'];
      }

      if ($langNode->field_indlang_promo_disable[0]['value'] == "Yes") {
        $node->field_industry_promo_1[0]['title'] = "";
        $node->field_industry_promo_2[0]['title'] = "";
        $node->field_industry_promo_3[0]['title'] = "";
      } else if ($langNode->field_indlang_promo_1[0]['title'] ||
        $langNode->field_indlang_promo_2[0]['title'] ||
        $langNode->field_indlang_promo_3[0]['title']) {
        $noTranslation["field_industry_promo_1"] = true;
        $noTranslation["field_industry_promo_2"] = true;
        $noTranslation["field_industry_promo_3"] = true;
        $node->field_industry_promo_1[0]['title'] = $langNode->field_indlang_promo_1[0]['title'];
        $node->field_industry_promo_1[0]['display_url'] = $langNode->field_indlang_promo_1[0]['url'];
        $node->field_industry_promo_1[0]['attributes']['target'] = $langNode->field_indlang_promo_1[0]['attributes']['target'];
        $node->field_industry_promo_2[0]['title'] = $langNode->field_indlang_promo_2[0]['title'];
        $node->field_industry_promo_2[0]['display_url'] = $langNode->field_indlang_promo_2[0]['url'];
        $node->field_industry_promo_2[0]['attributes']['target'] = $langNode->field_indlang_promo_2[0]['attributes']['target'];
        $node->field_industry_promo_3[0]['title'] = $langNode->field_indlang_promo_3[0]['title'];
        $node->field_industry_promo_3[0]['display_url'] = $langNode->field_indlang_promo_3[0]['url'];
        $node->field_industry_promo_3[0]['attributes']['target'] = $langNode->field_indlang_promo_3[0]['attributes']['target'];
      }

      if ($langNode->field_indlang_demo_disable[0]['value'] == "Yes") {
        $node->field_industry_demo_1[0]['title'] = "";
        $node->field_industry_demo_2[0]['title'] = "";
        $node->field_industry_demo_3[0]['title'] = "";
      } else if ($langNode->field_indlang_demo_1[0]['title'] ||
        $langNode->field_indlang_demo_2[0]['title'] ||
        $langNode->field_indlang_demo_3[0]['title']) {
        $noTranslation["field_industry_demo_1"] = true;
        $noTranslation["field_industry_demo_2"] = true;
        $noTranslation["field_industry_demo_3"] = true;
        $node->field_industry_demo_type_1[0]['value'] = $langNode->field_indlang_demo_type_1[0]['value'];
        $node->field_industry_demo_1[0]['title'] = $langNode->field_indlang_demo_1[0]['title'];
        $node->field_industry_demo_1[0]['display_url'] = $langNode->field_indlang_demo_1[0]['url'];
        $node->field_industry_demo_1[0]['attributes']['target'] = $langNode->field_indlang_demo_1[0]['attributes']['target'];
        $node->field_industry_demo_type_2[0]['value'] = $langNode->field_indlang_demo_type_2[0]['value'];
        $node->field_industry_demo_2[0]['title'] = $langNode->field_indlang_demo_2[0]['title'];
        $node->field_industry_demo_2[0]['display_url'] = $langNode->field_indlang_demo_2[0]['url'];
        $node->field_industry_demo_2[0]['attributes']['target'] = $langNode->field_indlang_demo_2[0]['attributes']['target'];
        $node->field_industry_demo_type_3[0]['value'] = $langNode->field_indlang_demo_type_3[0]['value'];
        $node->field_industry_demo_3[0]['title'] = $langNode->field_indlang_demo_3[0]['title'];
        $node->field_industry_demo_3[0]['display_url'] = $langNode->field_indlang_demo_3[0]['url'];
        $node->field_industry_demo_3[0]['attributes']['target'] = $langNode->field_indlang_demo_3[0]['attributes']['target'];
      }

      if ($langNode->field_indlang_trial_disable[0]['value'] == "Yes") {
        $node->field_industry_trial_1[0]['title'] = "";
        $node->field_industry_trial_2[0]['title'] = "";
        $node->field_industry_trial_3[0]['title'] = "";
      } else if ($langNode->field_indlang_trial_1[0]['title'] ||
        $langNode->field_indlang_trial_2[0]['title'] ||
        $langNode->field_indlang_trial_3[0]['title']) {
        $noTranslation["field_industry_trial_1"] = true;
        $noTranslation["field_industry_trial_2"] = true;
        $noTranslation["field_industry_trial_3"] = true;
        $node->field_industry_trial_type_1[0]['value'] = $langNode->field_indlang_trial_type_1[0]['value'];
        $node->field_industry_trial_1[0]['title'] = $langNode->field_indlang_trial_1[0]['title'];
        $node->field_industry_trial_1[0]['display_url'] = $langNode->field_indlang_trial_1[0]['url'];
        $node->field_industry_trial_1[0]['attributes']['target'] = $langNode->field_indlang_trial_1[0]['attributes']['target'];
        $node->field_industry_trial_type_2[0]['value'] = $langNode->field_indlang_trial_type_2[0]['value'];
        $node->field_industry_trial_2[0]['title'] = $langNode->field_indlang_trial_2[0]['title'];
        $node->field_industry_trial_2[0]['display_url'] = $langNode->field_indlang_trial_2[0]['url'];
        $node->field_industry_trial_2[0]['attributes']['target'] = $langNode->field_indlang_trial_2[0]['attributes']['target'];
        $node->field_industry_trial_type_3[0]['value'] = $langNode->field_indlang_trial_type_3[0]['value'];
        $node->field_industry_trial_3[0]['title'] = $langNode->field_indlang_trial_3[0]['title'];
        $node->field_industry_trial_3[0]['display_url'] = $langNode->field_indlang_trial_3[0]['url'];
        $node->field_industry_trial_3[0]['attributes']['target'] = $langNode->field_indlang_trial_3[0]['attributes']['target'];
      }

      if ($langNode->field_indlang_product_box[0]['value']) {
        $noTranslation["field_industry_product_box"] = true;
        $node->field_industry_product_box[0]['value'] = $langNode->field_indlang_product_box[0]['value'];
      }

      if ($langNode->field_mobile_hero_industry_lang[0]['value']) {
        $noTranslation["field_mobile_hero_banner_ind"] = true;
        $node->field_mobile_hero_banner_ind[0]['value'] = $langNode->field_mobile_hero_industry_lang[0]['value'];
      }

    }
  }
}
// END: Language overrides

?>

<script>
  // This code enables the 'tabs' feature on the industry page.
  $(document).ready(function(){

    // Initially hide tab sections.
    $('.page-section-industry').hide();

    // Show tab section if 'active-initial' class is present (would have been set by PHP).
    if ($('.page-section-industry.active-initial').length > 0) {
      $('.page-section-industry.active-initial').show();

    // Otherwise show the first tab section.
    } else {
      $('.page-section-industry').first().show();
    }

    // Show the corresponding content when the tab is clicked.
    $('.tabs-industry a').click(function(event){
      event.preventDefault(); // Stop the browser from scrolling to anchor.
      $('.page-section-industry').hide(); // Hide all tab contents.
      var sectionId = $(this).attr('href'); // Determine which tab was clicked.
      $(sectionId).show(); // Show clicked tab content.
    });

  });
</script>

<script>
  // This code activates the 'Products' tab in the event that
  // a 'Family' link is clicked under the 'Overview' section.
  $(document).ready(function(){

    // Show the corresponding content when the tab is clicked.
    $('a.family-products-link').click(function(event){
      $('.page-section-industry').hide(); // Hide all tab contents.
      $('#content-products').show(); // Show clicked tab content.
    });

  });
</script>

<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> clear-block">

  <div class="content">

    <h1><?php print $node->title ?></h1>

    <!-- Mobile Hero -->
    <?php if ($node->field_mobile_hero_banner_ind[0]['value']) { ?>

      <div class="<?php $noTranslation["field_mobile_hero_banner_ind"] ? print 'OneLinkNoTx' : print ''; ?>">
        <?php print $node->field_mobile_hero_banner_ind[0]['value']; ?>
      </div>

      <hr />

    <?php } ?>
    <!-- Mobile Hero -->

    <div data-role='tabs'>

      <div data-role="navbar">
        <ul class="tabs-industry">
          <li><a href="#content-overview" class="ui-btn-active">Overview</a></li>
          <li><a href="#content-expertise">Expertise</a></li>
          <li><a href="#content-products">Products</a></li>
        </ul>
      </div><!-- /navbar -->

      <div id="content-overview" class="page-section-industry">

        <?php

        $industryFamily = views_get_view_result('industry_family');

        foreach ($industryFamily as $family) { ?>

          <h2><?php print $family->node_title; ?></h2>

          <?php if ($family->node_data_field_family_shortdesc_field_family_hub_img_fid)  {
            $file = field_file_load($family->node_data_field_family_shortdesc_field_family_hub_img_fid);
            if ($file['filepath']) { ?>
              <img src='/<?php print $file['filepath']; ?>' width='146' height='116' border='0' style="float:left; margin:0 1em 1em 0;">
            <?php }
          }

          $linkUrl = str_replace(' ', '_', $family->node_title);
          $linkUrl = str_replace(',', '', $linkUrl);

          ?>

          <?php print $family->node_data_field_family_shortdesc_field_family_shortdesc_value; ?>

          <div style="clear:both; font-size:0; height:0;">&nbsp;</div>

          <!-- Use this link if you want to link to the product listing under the 'Products' tab on the same page. -->
          <a
            href="#<?php print $linkUrl; ?>"
            target="_self"
            data-role="button"
            class="button-yellow family-products-link">
            See Products
          </a>

          <hr />

        <?php } ?>

        <!-- Extra Links -->
        <div>

          <?php
          for ($i=1; $i<4; $i++) {
            $myTitle = 'field_industry_box_title_'.$i;
            $myImage = 'field_industry_box_img_'.$i;
            $myDescription = 'field_industry_box_desc_'.$i;
            $myUrl = 'field_industry_box_url_'.$i;

            $myTitleArr = $node->$myTitle;
            $myImageArr = $node->$myImage;
            $myDescriptionArr = $node->$myDescription;
            $myUrlArr = $node->$myUrl;
            if ($myTitleArr[0]['value'] && $myDescriptionArr[0]['value']) {

              if($noTranslation[$myTitle]) { ?>
                <div class='OneLinkNoTx'>
              <?php } ?>

                <h3><?php print $myTitleArr[0]['value']; ?></h3>

                <?php if ($myImageArr[0]['fid']) {
                  $file = field_file_load($myImageArr[0]['fid']);
                  if ($file['filepath']) { ?>

                    <img src='/<?php print $file['filepath']; ?>' border='0'>

                  <?php }
                } ?>

                <div><?php print $myDescriptionArr[0]['value']; ?></div>

                <?php if ($myUrlArr[0]['display_url'] && $myUrlArr[0]['title']) { ?>

                  <div>
                    <a href='<?php print $myUrlArr[0]['display_url']; ?>'
                       target='<?php print $myUrlArr[0]['attributes']['target'] ? $myUrlArr[0]['attributes']['target'] : "_self"; ?>'
                    >
                      <?php print $myUrlArr[0]['title']; ?>
                    </a>
                  </div>

                <?php }

              if($noTranslation[$myTitle]) { ?>
                </div>
              <?php }

            }
          } ?>

        </div><!-- Extra Links -->

      </div><!-- #content-overview -->

      <div id="content-expertise" class="page-section-industry <?php if ($_REQUEST['td']=='expertise') print 'active-initial'; ?>">

        <?php

        // Mapping the Industry node ID to the corresponding industry ID in MyAccount
        $myAccountIndustryId = "";
        if($node->nid == "6") $myAccountIndustryId = "1"; // Datacom Cabling
        if($node->nid == "7") $myAccountIndustryId = "2"; // IT Networking
        if($node->nid == "8") $myAccountIndustryId = "3"; // Telecom

        ?>

        <div id="white-papers" data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">
          <h3>White Papers</h3>

          <table width="100%" class="ui-responsive table-stroke table-stripe">

            <?php

            if($myAccountIndustryId != ""){

              $myAccountUrl = "http://myaccount.flukenetworks.com/fnet_www/SupportAndDownloads/AssetXML.aspx?IndustryId=".$myAccountIndustryId."&assettype=16&locale=".$langReg."&catalog=FNET-".substr($langReg, 3);

              //FNETAUTH cookie
              if (isset($_COOKIE['FNETAUTH'])) {
                $myAccountUrl .= "&AuthTicket=".urlencode($_COOKIE['FNETAUTH']);
              }
              //FNETAUTHUserGoldContracts_ cookie
              if(isset($_COOKIE['FNETAUTHUserGoldContracts_'])) {
                $myAccountUrl .= "&GoldContracts".urlencode($_COOKIE['FNETAUTHUserGoldContracts_']);
              }
              $ch = curl_init();
              curl_setopt($ch, CURLOPT_URL, $myAccountUrl);
              curl_setopt($ch, CURLOPT_HEADER, 0);
              curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
              curl_setopt($ch, CURLOPT_TIMEOUT, 10);
              $xmldata = curl_exec($ch);
              curl_close($ch);

              $xmlparser = xml_parser_create();
              xml_parse_into_struct($xmlparser,$xmldata,$amsDataArr);
              xml_parser_free($xmlparser);
              $amsAsset = array();

              $i = 0;
              foreach ($amsDataArr as $k1=>$v1) {
                if (is_array($v1)) {
                  $myTag = "";
                  $myVal = "";
                  foreach ($v1 as $k2=>$v2) {
                    if ($myTag == "ASSET" && $k2 == "type" && $v2 == "open") $i++;
                    if ($k2 == "tag") $myTag = $v2;
                    if ($k2 == "value") $myVal = $v2;
                  }
                  if ($myTag && $myVal) $amsAsset[$i][$myTag] = $myVal;
                }
              }

              $whitepaperRowCount = 0;
              for ($j=1; $j<=$i; $j++) {
                $myFileSize = "";
                if ($amsAsset[$j]["FILESIZE"]) {
                  if ($amsAsset[$j]["FILESIZE"] < 1000) $myFileSize = $amsAsset[$j]["FILESIZE"]." b";
                  else if ($amsAsset[$j]["FILESIZE"] < 1000000) $myFileSize = round($amsAsset[$j]["FILESIZE"]/1000) ." kb";
                  else $myFileSize = round($amsAsset[$j]["FILESIZE"]/1000000, 2) ." mb";
                }

                ?>

                <tr>
                  <td width="90%">
                    <a href='http://myaccount.flukenetworks.com/FNet/<?php print $langReg; ?>/findit?Document=<?php print $amsAsset[$j]["ASSETID"]; ?>' target='_blank'>
                      <?php print $amsAsset[$j]["ASSETTITLE"]; ?>
                    </a>
                  </td>
                  <td align="right" nowrap="nowrap"><?php print $myFileSize; ?></td>
                </tr>

              <?php }

            } ?>

          </table>

        </div><!-- #white-papers -->

        <div id="webcasts" data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">
          <h3>Webcasts</h3>

          <table width="100%" class="ui-responsive table-stroke table-stripe">

            <?php

            if($myAccountIndustryId != ""){

              // WebCast
              $myAccountUrl = "http://myaccount.flukenetworks.com/fnet_www/SupportAndDownloads/AssetXML.aspx?IndustryId=".$myAccountIndustryId."&assettype=4194304&locale=".$langReg."&catalog=FNET-".substr($langReg, 3);
              //FNETAUTH cookie
              if (isset($_COOKIE['FNETAUTH'])) {
                $myAccountUrl .= "&AuthTicket=".urlencode($_COOKIE['FNETAUTH']);
              }
              //FNETAUTHUserGoldContracts_ cookie
              if(isset($_COOKIE['FNETAUTHUserGoldContracts_'])) {
                $myAccountUrl .= "&GoldContracts".urlencode($_COOKIE['FNETAUTHUserGoldContracts_']);
              }
              $ch = curl_init();
              curl_setopt($ch, CURLOPT_URL, $myAccountUrl);
              curl_setopt($ch, CURLOPT_HEADER, 0);
              curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
              curl_setopt($ch, CURLOPT_TIMEOUT, 10);
              $xmldata = curl_exec($ch);
              curl_close($ch);

              $xmlparser = xml_parser_create();
              xml_parse_into_struct($xmlparser,$xmldata,$amsDataArr);
              xml_parser_free($xmlparser);
              $amsAsset = array();
              $i = 0;
              foreach ($amsDataArr as $k1=>$v1) {
                if (is_array($v1)) {
                  $myTag = "";
                  $myVal = "";
                  foreach ($v1 as $k2=>$v2) {
                    if ($myTag == "ASSET" && $k2 == "type" && $v2 == "open") $i++;
                    if ($k2 == "tag") $myTag = $v2;
                    if ($k2 == "value") $myVal = $v2;
                  }
                  if ($myTag && $myVal) $amsAsset[$i][$myTag] = $myVal;
                }
              }
              $webcastRowCount = 0;
              for ($j=1; $j<=$i; $j++) { ?>

                <tr>
                  <td>
                    <a href='http://myaccount.flukenetworks.com/FNet/<?php print $langReg; ?>/findit?Document=<?php print $amsAsset[$j]["ASSETID"]; ?>' target='_blank'>
                      <?php print $amsAsset[$j]["ASSETTITLE"]; ?>
                    </a>
                  </td>
                </tr>

              <?php }

            } ?>

          </table>

        </div><!-- #webcasts -->

        <div id="case-studies" data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">
          <h3>Case Studies</h3>

          <?php
          $industryExpertise = views_get_view_result('industry_expertise');
          if (count($industryExpertise) > 0) {
            foreach ($industryExpertise as $expertise) {
              if($expertise->term_data_name == "Case Study"){ ?>

                <h4><?php print $expertise->node_title; ?></h4>
                <div><?php print $expertise->node_revisions_body; ?></div>

              <?php }
            }
          }
          ?>

        </div><!-- #case-studies -->

        <div id="expertise-resources" class="ui-grid-b ui-responsive">

          <div class="ui-block-a">
            <div class="ui-body ui-body-f">

              <?php
              if(
                ($node->field_industry_pop_res_1[0]['display_url'] && $node->field_industry_pop_res_1[0]['title']) ||
                ($node->field_industry_pop_res_2[0]['display_url'] && $node->field_industry_pop_res_2[0]['title']) ||
                ($node->field_industry_pop_res_3[0]['display_url'] && $node->field_industry_pop_res_3[0]['title'])
              ){ ?>

                <h3>Popular Resources</h3>

                <ul>

                  <?php
                  if($node->field_industry_pop_res_1[0]['display_url'] && $node->field_industry_pop_res_1[0]['title']){ ?>
                    <li <?php if($noTranslation["field_industry_pop_res_1"]) print "class='OneLinkNoTx'"; ?>>
                      <a href="<?php print $node->field_industry_pop_res_1[0]['display_url']; ?>"><?php print $node->field_industry_pop_res_1[0]['title']; ?></a>
                    </li>
                  <?php } ?>

                  <?php
                  if($node->field_industry_pop_res_2[0]['display_url'] && $node->field_industry_pop_res_2[0]['title']){ ?>
                    <li <?php if($noTranslation["field_industry_pop_res_2"]) print "class='OneLinkNoTx'"; ?>>
                      <a href="<?php print $node->field_industry_pop_res_2[0]['display_url']; ?>"><?php print $node->field_industry_pop_res_2[0]['title']; ?></a>
                    </li>
                  <?php } ?>

                  <?php
                  if($node->field_industry_pop_res_3[0]['display_url'] && $node->field_industry_pop_res_3[0]['title']){ ?>
                    <li <?php if($noTranslation["field_industry_pop_res_3"]) print "class='OneLinkNoTx'"; ?>>
                      <a href="<?php print $node->field_industry_pop_res_3[0]['display_url']; ?>"><?php print $node->field_industry_pop_res_3[0]['title']; ?></a>
                    </li>
                  <?php } ?>

                </ul>

              <?php } ?>

            </div>
          </div>

          <div class="ui-block-b">
            <div class="ui-body ui-body-f">

              <?php
              if(
                ($node->field_industry_learn_abt_1[0]['display_url'] && $node->field_industry_learn_abt_1[0]['title']) ||
                ($node->field_industry_learn_abt_2[0]['display_url'] && $node->field_industry_learn_abt_2[0]['title']) ||
                ($node->field_industry_learn_abt_3[0]['display_url'] && $node->field_industry_learn_abt_3[0]['title'])
              ){ ?>

                <h3>Learn About</h3>

                <ul>

                  <?php
                  if($node->field_industry_learn_abt_1[0]['display_url'] && $node->field_industry_learn_abt_1[0]['title']){ ?>
                    <li <?php if($noTranslation["field_industry_learn_abt_1"]) print "class='OneLinkNoTx'"; ?>>
                      <a href="<?php print $node->field_industry_learn_abt_1[0]['display_url']; ?>"><?php print $node->field_industry_learn_abt_1[0]['title']; ?></a>
                    </li>
                  <?php } ?>

                  <?php
                  if($node->field_industry_learn_abt_2[0]['display_url'] && $node->field_industry_learn_abt_2[0]['title']){ ?>
                    <li <?php if($noTranslation["field_industry_learn_abt_2"]) print "class='OneLinkNoTx'"; ?>>
                      <a href="<?php print $node->field_industry_learn_abt_2[0]['display_url']; ?>"><?php print $node->field_industry_learn_abt_2[0]['title']; ?></a>
                    </li>
                  <?php } ?>

                  <?php
                  if($node->field_industry_learn_abt_3[0]['display_url'] && $node->field_industry_learn_abt_3[0]['title']){ ?>
                    <li <?php if($noTranslation["field_industry_learn_abt_3"]) print "class='OneLinkNoTx'"; ?>>
                      <a href="<?php print $node->field_industry_learn_abt_3[0]['display_url']; ?>"><?php print $node->field_industry_learn_abt_3[0]['title']; ?></a>
                    </li>
                  <?php } ?>

                </ul>

              <?php } ?>

            </div>
          </div>

          <div class="ui-block-c">
            <div class="ui-body ui-body-f">

              <?php
              if(
                ($node->field_industry_fea_top_1[0]['display_url'] && $node->field_industry_fea_top_1[0]['title']) ||
                ($node->field_industry_fea_top_2[0]['display_url'] && $node->field_industry_fea_top_2[0]['title']) ||
                ($node->field_industry_fea_top_3[0]['display_url'] && $node->field_industry_fea_top_3[0]['title'])
              ){ ?>

                <h3>Featured Topics</h3>

                <ul>

                  <?php
                  if($node->field_industry_fea_top_1[0]['display_url'] && $node->field_industry_fea_top_1[0]['title']){ ?>
                    <li <?php if($noTranslation["field_industry_fea_top_1"]) print "class='OneLinkNoTx'"; ?>>
                      <a href="<?php print $node->field_industry_fea_top_1[0]['display_url']; ?>"><?php print $node->field_industry_fea_top_1[0]['title']; ?></a>
                    </li>
                  <?php } ?>

                  <?php
                  if($node->field_industry_fea_top_2[0]['display_url'] && $node->field_industry_fea_top_2[0]['title']){ ?>
                    <li <?php if($noTranslation["field_industry_fea_top_2"]) print "class='OneLinkNoTx'"; ?>>
                      <a href="<?php print $node->field_industry_fea_top_2[0]['display_url']; ?>"><?php print $node->field_industry_fea_top_2[0]['title']; ?></a>
                    </li>
                  <?php } ?>

                  <?php
                  if($node->field_industry_fea_top_3[0]['display_url'] && $node->field_industry_fea_top_3[0]['title']){ ?>
                    <li <?php if($noTranslation["field_industry_fea_top_3"]) print "class='OneLinkNoTx'"; ?>>
                      <a href="<?php print $node->field_industry_fea_top_3[0]['display_url']; ?>"><?php print $node->field_industry_fea_top_3[0]['title']; ?></a>
                    </li>
                  <?php } ?>

                </ul>

              <?php } ?>

            </div>
          </div>

        </div><!-- #expertise-resources -->

      </div><!-- #content-expertise -->

      <div id="content-products" class="page-section-industry <?php if ($_REQUEST['td']=='products') print 'active-initial'; ?>">

        <?php

          // Loop through and organize products under each family.
          foreach ($industryFamily as $family) {

            $anchorStr = str_replace(' ', '_', $family->node_title);
            $anchorStr = str_replace(',', '', $anchorStr);

            ?>

            <a name="<?php print $anchorStr; ?>"></a>
            <h2><?php print $family->node_title; ?></h2>

            <?php

            // Get products by family using 'industry_family_products' view.
            $view = views_get_view('industry_family_products');
            $view->set_items_per_page(0);

            // Fetch regLang value to pass as argument to 'industry_family_products' view
            $region = strtolower($_COOKIE["regLang"]);
            if ($region == "") $region = "en-us";

            // Pass arguments to view, execute, and gather results.
            $view->set_arguments(array($family->nid, $region));
            $view->execute();
            $result = $view->result;

            // Loop thru and print list of products
            foreach ($result as $myProd) { ?>

              <h3><?php print $myProd->node_title; ?></h3>

              <?php

              // Print product image if it is available.
              if ($myProd->node_data_field_prod_hub_img_field_prod_hub_img_fid) {
                $file = field_file_load($myProd->node_data_field_prod_hub_img_field_prod_hub_img_fid);
                if ($file['filepath']) { ?>
                  <img src='/<?php print $file['filepath']; ?>' width='146' height='116' border='0' style="float:left; margin:0 1em 1em 0;">
                <?php }
              } ?>

              <?php print $myProd->node_data_field_product_desc_field_product_desc_value; ?>

              <div style="clear:both; font-size:0; height:0;">&nbsp;</div>

              <a
                href="/<?php print drupal_lookup_path('alias',"node/".$myProd->nid); ?>"
                target="_self"
                data-role="button"
                class="button-yellow">
                  Learn More
              </a>

              <hr />

            <?php }

          }

        ?>

        <!-- Extra Links -->
        <div>

          <?php

          // Promotions
          $countPromos = 0;
          for ($i=1; $i<4; $i++) {
            $myPromo = 'field_industry_promo_'.$i;
            $myPromoArr = $node->$myPromo;

            if ($myPromoArr[0]['display_url'] && $myPromoArr[0]['title']) { ?>

              <?php if ($countPromos == 0) { ?>
                <h3>Promotions</h3>
              <?php } ?>

              <?php if($noTranslation[$myPromo]) echo "<div class='OneLinkNoTx'>\n"; ?>

              <p>
                <a
                  href='<?php print $myPromoArr[0]['display_url']; ?>'
                  target='<?php print $myPromoArr[0]['attributes']['target'] ? $myPromoArr[0]['attributes']['target'] : "_self"; ?>'>
                  <?php print $myPromoArr[0]['title']; ?>
                </a>
              </p>

              <?php if($noTranslation[$myPromo]) echo "</div>\n";

              $countPromos++;

            }
          }// Promotions

          // Videos & Demos
          $countDemos = 0;
          for ($i=1; $i<4; $i++) {
            $myDemo = 'field_industry_demo_'.$i;
            $myDemoType = 'field_industry_demo_type_'.$i;
            $myDemoArr = $node->$myDemo;
            $myDemoTypeArr = $node->$myDemoType;

            if ($myDemoTypeArr[0]['value'] && $myDemoArr[0]['display_url'] && $myDemoArr[0]['title']) { ?>

              <?php if ($countDemos == 0) { ?>
                <h3>Videos &amp; Demos</h3>
              <?php } ?>

              <?php if($noTranslation[$myDemo]) echo "<div class='OneLinkNoTx'>\n"; ?>

              <p><strong><?php print $myDemoTypeArr[0]['value']; ?></strong><br />
                <a
                  href='<?php print $myDemoArr[0]['display_url']; ?>'
                  target='<?php print $myDemoArr[0]['attributes']['target'] ? $myDemoArr[0]['attributes']['target'] : "_self"; ?>'>
                  <?php print $myDemoArr[0]['title']; ?>
                </a>
              </p>

              <?php if($noTranslation[$myDemo]) echo "</div>\n";

              $countDemos++;

            }
          }// Videos & Demos

          // Trials
          $countTrials = 0;
          for ($i=1; $i<4; $i++) {
            $myTrial = 'field_industry_trial_'.$i;
            $myTrialType = 'field_industry_trial_type_'.$i;
            $myTrialArr = $node->$myTrial;
            $myTrialTypeArr = $node->$myTrialType;

            if ($myTrialTypeArr[0]['value'] && $myTrialArr[0]['display_url'] && $myTrialArr[0]['title']) { ?>

              <?php if ($countTrials == 0) { ?>
                <h3>Trials</h3>
              <?php } ?>

              <?php if($noTranslation[$myTrial]) echo "<div class='OneLinkNoTx'>\n"; ?>

              <p><strong><?php print $myTrialTypeArr[0]['value']; ?></strong><br />
                <a
                  href='<?php print $myTrialArr[0]['display_url']; ?>'
                  target='<?php print $myTrialArr[0]['attributes']['target'] ? $myTrialArr[0]['attributes']['target'] : "_self"; ?>'>
                  <?php print $myTrialArr[0]['title']; ?>
                </a>
              </p>

              <?php if($noTranslation[$myTrial]) echo "</div>\n";

              $countTrials++;

            }
          }// Trials

          ?>

        </div><!-- Extra Links -->

      </div><!-- #content-products -->

    </div>

  </div><!-- .content -->

</div>