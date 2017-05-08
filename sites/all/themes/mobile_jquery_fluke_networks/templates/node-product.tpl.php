<?php
$siteReg = module_invoke('fnet_helper', 'site_region');
$serverName = $siteReg["serverName"];
$langReg = $siteReg["langReg"];
$regLang = $siteReg["regLang"];

// Use this to determine if we should run conversion code
// when 'Buy Online' links are clicked.
$has_conversion_code = !empty($node->field_conversion_code[0]['value']);

$noTranslation = array();
//if ($regLang != "en-us") {
$validLangNode = array();
foreach ($node->field_prod_language as $key=>$val) {
  foreach ($val as $k=>$v) {
    if ($k == "nid")
      $validLangNode[$v] = 1;
  }
}
if (count($validLangNode) > 0) {
  $langNodeId = "";
  $prodLang = views_get_view_result('admin_product_language');
  if (count($prodLang) > 0) {
    foreach ($prodLang as $lang) {
      if ($validLangNode[$lang->nid] &&
        substr($lang->node_data_field_prodlang_product_field_prodlang_language_value, 0, 5) == $regLang) {
        $langNodeId = $lang->nid;
        break;
      }
    }

    if (! empty($langNodeId)) {

      $langNode = node_load($langNodeId);

      // In the event that there is no default conversion code, set the boolean accordingly in the event that there is conversion code for an override.
      if (!$has_conversion_code) $has_conversion_code = !empty($langNode->field_conversion_code_language[0]['value']);

      node_view($langNode);
      if ($langNode->field_prodlang_btnact_disable[0]['value'] == "Yes") {
        for ($i=0; $i<4; $i++) {
          $node->field_prod_btn_calltoaction[$i]["title"] = "";
          $node->field_prod_btn_calltoaction[$i]["display_url"] = "";
        }
      } else {
        $enableLangBtn = false;
        for ($i=0; $i<4; $i++) {
          if ($langNode->field_prodlang_btn_calltoaction[$i]["title"] &&
            $langNode->field_prodlang_btn_calltoaction[$i]["display_url"]) {
            $enableLangBtn = true;
            break;
          }
        }
        if ($enableLangBtn) {
          for ($i=0; $i<4; $i++) {
            $noTranslation["cta_btn"][$i+1] = true;
            $node->field_prod_btn_calltoaction[$i]["title"] = $langNode->field_prodlang_btn_calltoaction[$i]["title"];
            $node->field_prod_btn_calltoaction[$i]["display_url"] = $langNode->field_prodlang_btn_calltoaction[$i]["display_url"];
            $node->field_prod_btn_calltoaction[$i]["attributes"]["target"] = $langNode->field_prodlang_btn_calltoaction[$i]["attributes"]["target"];
          }
          if ($langNode->field_prodlang_btn_cta_size[0]['value'])
            $node->field_prod_btn_cta_size[0]['value'] = $langNode->field_prodlang_btn_cta_size[0]['value'];
        }
      }

      if ($langNode->field_prodlang_video_img_t_1[0]['filepath']) {
        $node->field_prod_video_img_t_1[0]['filepath'] = $langNode->field_prodlang_video_img_t_1[0]['filepath'];
        $node->field_prod_video_youtube_url[0]['url'] = $langNode->field_prodlang_video_youtube_url[0]['url'];
        $node->field_prod_video_youtube_url[0]['display_url'] = $langNode->field_prodlang_video_youtube_url[0]['display_url'];
        $node->field_prod_video_youtube_url[0]['query'] = $langNode->field_prodlang_video_youtube_url[0]['query'];

        $node->field_prod_video_lg_1[0]['filepath'] = $langNode->field_prodlang_video_lg_1[0]['filepath'];
        $node->field_prod_video_lg_1[0]['filemime'] = $langNode->field_prodlang_video_lg_1[0]['filemime'];
        $node->field_prod_video_img_t_1[0]['data']['alt'] = $langNode->field_prodlang_video_img_t_1[0]['data']['alt'];
      }

      if ($langNode->field_prodlang_sol_disable[0]['value'] == "Yes") {
        for ($i=0; $i<4; $i++) {
          $fieldName = "field_prod_sol_link_".($i+1);
          $node->{$fieldName}[0]["title"] = "";
          $node->{$fieldName}[0]["display_url"] = "";
        }
      } else if ($langNode->field_prodlang_sol_link_1[0]['title'] ||
        $langNode->field_prodlang_sol_link_2[0]['title'] ||
        $langNode->field_prodlang_sol_link_3[0]['title'] ||
        $langNode->field_prodlang_sol_link_4[0]['title']) {
        $node->field_prod_sol_title[0]['value'] = $langNode->field_prodlang_sol_title[0]['value'];
        $noTranslation["field_prod_solutions"] = true;
        $node->field_prod_sol_link_1[0]['title'] = $langNode->field_prodlang_sol_link_1[0]['title'];
        $node->field_prod_sol_link_1[0]['display_url'] = $langNode->field_prodlang_sol_link_1[0]['display_url'];
        $node->field_prod_sol_link_1[0]['attributes']['target'] = $langNode->field_prodlang_sol_link_1[0]['attributes']['target'];
        $node->field_prod_sol_desc_1[0]['value'] = $langNode->field_prodlang_sol_desc_1[0]['value'];

        $node->field_prod_sol_link_2[0]['title'] = $langNode->field_prodlang_sol_link_2[0]['title'];
        $node->field_prod_sol_link_2[0]['display_url'] = $langNode->field_prodlang_sol_link_2[0]['display_url'];
        $node->field_prod_sol_link_2[0]['attributes']['target'] = $langNode->field_prodlang_sol_link_2[0]['attributes']['target'];
        $node->field_prod_sol_desc_2[0]['value'] = $langNode->field_prodlang_sol_desc_2[0]['value'];

        $node->field_prod_sol_link_3[0]['title'] = $langNode->field_prodlang_sol_link_3[0]['title'];
        $node->field_prod_sol_link_3[0]['display_url'] = $langNode->field_prodlang_sol_link_3[0]['display_url'];
        $node->field_prod_sol_link_3[0]['attributes']['target'] = $langNode->field_prodlang_sol_link_3[0]['attributes']['target'];
        $node->field_prod_sol_desc_3[0]['value'] = $langNode->field_prodlang_sol_desc_3[0]['value'];

        $node->field_prod_sol_link_4[0]['title'] = $langNode->field_prodlang_sol_link_4[0]['title'];
        $node->field_prod_sol_link_4[0]['display_url'] = $langNode->field_prodlang_sol_link_4[0]['display_url'];
        $node->field_prod_sol_link_4[0]['attributes']['target'] = $langNode->field_prodlang_sol_link_4[0]['attributes']['target'];
        $node->field_prod_sol_desc_4[0]['value'] = $langNode->field_prodlang_sol_desc_4[0]['value'];
      }

      if ($langNode->field_prodlang_wtb_online[0]['title'] || $langNode->field_prodlang_wtb_online[1]['title'] || $langNode->field_prodlang_wtb_online[2]['title']) {
        $noTranslation["field_prod_wtb_online"] = true;
        $node->field_prod_wtb_online[0]['title'] = $langNode->field_prodlang_wtb_online[0]['title'];
        $node->field_prod_wtb_online[0]['display_url'] = $langNode->field_prodlang_wtb_online[0]['display_url'];
        $node->field_prod_wtb_online[1]['title'] = $langNode->field_prodlang_wtb_online[1]['title'];
        $node->field_prod_wtb_online[1]['display_url'] = $langNode->field_prodlang_wtb_online[1]['display_url'];
        $node->field_prod_wtb_online[2]['title'] = $langNode->field_prodlang_wtb_online[2]['title'];
        $node->field_prod_wtb_online[2]['display_url'] = $langNode->field_prodlang_wtb_online[2]['display_url'];
      }
    }
  }
}
?>

<script type="text/javascript">
  /*======
   Use document ready or window load events
   For example:
   With jQuery: $(function() { ...code here... })
   Or window.onload = function() { ...code here ...}
   Or document.addEventListener('DOMContentLoaded', function(){ ...code here... }, false)
   =======*/

  window.onload = function() {
    var mySwiper = new Swiper('.swiper-container',{
      //Your options here:
      mode:'horizontal',
      loop: true,
      pagination: '.pagination',
      paginationClickable: true,
      autoplay: 5000
      //etc..
    });
  }

</script>

<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> clear-block">

    <?php print $picture ?>
    <?php if (!$page): ?>
        <h2><a href="<?php print $node_url ?>" title="<?php print $title ?>"><?php print $title ?></a></h2>
    <?php endif; ?>

    <div class="meta">
        <?php if ($submitted): ?>
            <span class="submitted"><?php print $submitted ?></span>
        <?php endif; ?>
    </div>

    <div class="content">
        <!-- ?php print $content ? -->

        <!-- Product name -->
        <h1><?php echo html_entity_decode($title); ?></h1>

        <!-- Product image carousel -->
        <?php if(
            $node->field_prod_carousel_img_lg_1[0]['filepath']
            || $node->field_prod_carousel_img_lg_2[0]['filepath']
            || $node->field_prod_carousel_img_lg_3[0]['filepath']
            || $node->field_prod_carousel_img_lg_4[0]['filepath']
            || $node->field_prod_carousel_img_lg_5[0]['filepath']
            || $node->field_prod_carousel_img_lg_6[0]['filepath']
            || $node->field_prod_carousel_img_lg_7[0]['filepath']
            || $node->field_prod_carousel_img_lg_8[0]['filepath']
            || $node->field_prod_carousel_img_lg_9[0]['filepath']
            || $node->field_prod_carousel_img_lg_10[0]['filepath'] ) { ?>

                <div class="swiper-container">
                    <div class="swiper-wrapper">

                        <?php if($node->field_prod_carousel_img_lg_1[0]['filepath']) { ?>
                            <div class="swiper-slide">
                                <img class="popphoto" src="/<?php echo $node->field_prod_carousel_img_lg_1[0]['filepath']; ?>">
                            </div>
                        <?php } ?>

                        <?php if($node->field_prod_carousel_img_lg_2[0]['filepath']) { ?>
                            <div class="swiper-slide">
                                <img class="popphoto" src="/<?php echo $node->field_prod_carousel_img_lg_2[0]['filepath']; ?>">
                            </div>
                        <?php } ?>

                        <?php if($node->field_prod_carousel_img_lg_3[0]['filepath']) { ?>
                            <div class="swiper-slide">
                                <img class="popphoto" src="/<?php echo $node->field_prod_carousel_img_lg_3[0]['filepath']; ?>">
                            </div>
                        <?php } ?>

                        <?php if($node->field_prod_carousel_img_lg_4[0]['filepath']) { ?>
                            <div class="swiper-slide">
                                <img class="popphoto" src="/<?php echo $node->field_prod_carousel_img_lg_4[0]['filepath']; ?>">
                            </div>
                        <?php } ?>

                        <?php if($node->field_prod_carousel_img_lg_5[0]['filepath']) { ?>
                            <div class="swiper-slide">
                                <img class="popphoto" src="/<?php echo $node->field_prod_carousel_img_lg_5[0]['filepath']; ?>">
                            </div>
                        <?php } ?>

                        <?php if($node->field_prod_carousel_img_lg_6[0]['filepath']) { ?>
                            <div class="swiper-slide">
                                <img class="popphoto" src="/<?php echo $node->field_prod_carousel_img_lg_6[0]['filepath']; ?>">
                            </div>
                        <?php } ?>

                        <?php if($node->field_prod_carousel_img_lg_7[0]['filepath']) { ?>
                            <div class="swiper-slide">
                                <img class="popphoto" src="/<?php echo $node->field_prod_carousel_img_lg_7[0]['filepath']; ?>">
                            </div>
                        <?php } ?>

                        <?php if($node->field_prod_carousel_img_lg_8[0]['filepath']) { ?>
                            <div class="swiper-slide">
                                <img class="popphoto" src="/<?php echo $node->field_prod_carousel_img_lg_8[0]['filepath']; ?>">
                            </div>
                        <?php } ?>

                        <?php if($node->field_prod_carousel_img_lg_9[0]['filepath']) { ?>
                            <div class="swiper-slide">
                                <img class="popphoto" src="/<?php echo $node->field_prod_carousel_img_lg_9[0]['filepath']; ?>">
                            </div>
                        <?php } ?>

                        <?php if($node->field_prod_carousel_img_lg_10[0]['filepath']) { ?>
                            <div class="swiper-slide">
                                <img class="popphoto" src="/<?php echo $node->field_prod_carousel_img_lg_10[0]['filepath']; ?>">
                            </div>
                        <?php } ?>

                    </div>
                    <div class="pagination"></div>
                </div>
        <?php } ?>

        <!-- Product "at a glance" information" -->
        <p><?php echo $node->field_product_desc[0]['value'] ?></p>
        <p><?php echo $node->field_product_ataglance[0]['value']; ?></p>

        <!-- Product yellow buttons -->
        <?php
            for ($i=0; $i<4; $i++) { // Loop through buttons array (up to four possible buttons).
                if (!empty($node->field_prod_btn_calltoaction[$i]["title"]) && !empty($node->field_prod_btn_calltoaction[$i]["display_url"])) {

                    if($noTranslation["cta_btn"][$i+1]) echo "<div class='OneLinkNoTx'>\n"; // Wrap in "no translate" div if needed. ?>

                    <a
                        href="<?php echo $node->field_prod_btn_calltoaction[$i]['display_url']; ?>"
                        target="<?php echo $node->field_prod_btn_calltoaction[$i]['attributes']['target'] ? $node->field_prod_btn_calltoaction[$i]['attributes']['target'] : '_self'; ?>"
                        data-role="button"
                        class="button-yellow">
                        <?php echo strip_tags ($node->field_prod_btn_calltoaction[$i]['title']); ?>
                    </a>

                    <?php if($noTranslation["cta_btn"][$i+1]) echo "</div>\n"; // Close no translate div in needed.
                }
            }
        ?>
        <!-- END: Product yellow buttons -->

        <!-- Product "Talk to an Expert" button -->
        <?php if ($node->field_prod_contact_sales_button[0]['value'] == 'on'): ?>
            <a
                href="/contact_sales?epi=<?php echo products_clean_string($node->title); ?>"
                data-role="button"
                class="button-talk-to-expert">
                Talk to an Expert
            </a>
        <?php endif ?>
        <!-- END: Product "Talk to an Expert" button -->

        <!-- Product "Where to Buy" button -->
        <?php if ($node->field_prod_where_to_buy_button[0]['value'] == 'on'): ?>
            <a
                href="/wheretobuy?tab=3&product=<?php echo $node->nid; ?>"
                data-role="button"
                class="button-where-to-buy">
                Where To Buy
            </a>
        <?php endif ?>
        <!-- END: Product "Where to Buy" button -->

        <hr />

        <!-- START: Buy Online Buttons -->
        <?php if ($node->field_prod_wtb_online[0]['title'] || $node->field_prod_wtb_online[1]['title'] || $node->field_prod_wtb_online[2]['title']) { ?>

          <h3>Buy Online</h3>

          <div class="<?php if ($noTranslation["field_prod_wtb_online"]) print 'OneLinkNoTx'; ?>">

            <ul>

              <?php
              for ($i=0; $i<3; $i++) {
                if ($node->field_prod_wtb_online[$i]['title']) {

                  // Add 'launch-conversion-code' class to anchor tag if there exists conversion code.
                  // If no conversion code then add only the 'buy-online-link' class
                  $anchor_class = $has_conversion_code ? 'buy-online-link launch-conversion-code' : 'buy-online-link';
                  ?>

                  <li>
                    <a
                      href="<?php print $node->field_prod_wtb_online[$i]['display_url']; ?>"
                      title="<?php print $node->field_prod_wtb_online[$i]['title']; ?>"
                      target="_blank"
                      class="<?php print $anchor_class; ?>">
                      <?php print $node->field_prod_wtb_online[$i]['title']; ?>
                    </a>
                  </li>

                <?php }
              } ?>

              <li>
                <a
                  href="/wheretobuy?tab=3&product=<?php print $node->nid; ?>"
                  title="<?php print $node->field_prod_wtb_online[$i]['title']; ?>">
                  See more online resellers or buy locally
                </a>
              </li>

            </ul>

          </div>

          <hr />

        <?php } ?>
        <!-- START: Buy Online Buttons -->

        <!-- Sections -->
        <div>

            <!-- Overview -->
            <?php if(!empty($node->field_product_details[0]["value"])): ?>

                    <div data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">
                        <h3>Overview</h3>
                        <?php echo $node->field_product_details[0]["value"]; ?>
                        <div style="clear:both;"></div>
                    </div>

            <?php endif ?>
            <!-- END: Overview -->

            <!-- Features -->
            <?php
                $productFeatures = views_get_view_result('product_feature');

                if(count($productFeatures) > 0): ?>

                    <div data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">
                        <h3>Features</h3>
                        <div>

                            <?php
                                for($i=0; $i<count($productFeatures); $i++){ ?>

                                  <div data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">
                                    <h4><?php echo $productFeatures[$i]->node_title; ?></h4>
                                    <?php echo $productFeatures[$i]->node_revisions_body; ?>
                                    <div style="clear:both;"></div>
                                  </div>

                            <?php } ?>

                        </div>
                    </div>

            <?php endif ?>
            <!-- END: Features -->

            <!-- Models & Accessories -->
            <?php
                $productMOA = views_get_view_result('product_moa');
                if (count($productMOA) > 0){ ?>

                    <div data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">
                        <h3>Models & Accessories</h3>

                        <h4><?php echo "Models" ?></h4>
                        <table width="100%" data-role="table" id="documents-table" data-mode="reflow" class="ui-responsive table-stroke table-stripe moa">

                            <thead>
                                <tr>
                                    <th width="30%">Name</th>
                                    <th>Description</th>
                                </tr>
                            </thead>
                            <tbody>

                                <?php foreach ($productMOA as $moa) {
                                    $support_options = module_invoke('node_product_sub_type', 'support_by_moa', $moa->nid); ?>

                                    <?php if($moa->term_data_name == "Models"){ ?>
                                            <tr>
                                                <td>
                                                    <strong><?php echo $moa->node_title; ?></strong>
                                                    <?php if($support_options){ ?>
                                                        &nbsp;<a href="#popupInfo<?php echo $moa->nid; ?>" class="button-yellow btn-models-accessories-gold-suppport" data-rel="popup" data-role="button" data-mini="true" data-inline="true" data-transition="pop">Gold Support</a>
                                                        <div data-role="popup" class="models-accessories-gold-suppport ui-content" id="popupInfo<?php echo $moa->nid; ?>" data-corners="false">
                                                            <a href="#" data-rel="back" data-role="button" data-icon="delete" data-iconpos="notext" class="ui-btn-right">Close</a>
                                                            <?php echo $support_options; ?>
                                                        </div>
                                                    <?php } ?>
                                                </td>
                                                <td>
                                                    <?php echo $moa->node_revisions_body; ?>
                                                </td>
                                            </tr>

                                    <?php } ?>
                                <?php } ?>

                            </tbody>
                        </table>
                        <div style="clear:both;"></div>

                        <h4><?php echo "Accessories" ?></h4>
                        <table width="100%" data-role="table" id="documents-table" data-mode="reflow" class="ui-responsive table-stroke table-stripe moa">

                            <thead>
                                <tr>
                                    <th width="30%">Name</th>
                                    <th>Description</th>
                                </tr>
                            </thead>
                            <tbody>

                                <?php foreach ($productMOA as $moa) {
                                    $support_options = module_invoke('node_product_sub_type', 'support_by_moa', $moa->nid); ?>

                                    <?php if($moa->term_data_name == "Accessories"){ ?>

                                        <tr>
                                            <td>
                                                <strong><?php echo $moa->node_title; ?></strong>
                                            </td>
                                            <td>
                                                <?php echo $moa->node_revisions_body; ?>
                                            </td>
                                        </tr>

                                    <?php } ?>
                                <?php } ?>

                            </tbody>
                        </table>
                        <div style="clear:both;"></div>

                    </div>

            <?php } ?>
            <!-- END: Models & Accessories -->

            <!-- Specifications -->
            <?php if(!empty($node->field_product_specs[0]["value"])): ?>

                <div data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">
                    <h3>Specifications</h3>
                    <?php echo $node->field_product_specs[0]["value"]; ?>
                    <div style="clear:both;"></div>
                </div>

            <?php endif ?>
            <!-- END: Specifications -->

            <!-- Documents & Demos -->
            <?php
                $siteReg = module_invoke('fnet_helper', 'site_region');
                $serverName = $siteReg["serverName"];
                $langReg = $siteReg["langReg"];
                $regLang = $siteReg["regLang"];

                $pCatId = $node->field_pcatid[0]["value"];
                $myDemo = "";
                $myDownload = "";
                $myDoc = array();
                if ($pCatId) {
                    $Url = "http://myaccount.flukenetworks.com/fnet_www/SupportAndDownloads/AssetXML.aspx?ProductID=".$pCatId."&locale=".$langReg."&catalog=FNET-".substr($langReg, 3);
                    //FNETAUTH cookie
                    if (isset($_COOKIE['FNETAUTH'])) {
                        $Url .= "&AuthTicket=".urlencode($_COOKIE['FNETAUTH']);
                    }
                    //FNETAUTHUserGoldContracts_ cookie
                    if(isset($_COOKIE['FNETAUTHUserGoldContracts_'])) {
                        $Url .= "&GoldContracts".urlencode($_COOKIE['FNETAUTHUserGoldContracts_']);
                    }

                    $ch = curl_init();
                    curl_setopt($ch, CURLOPT_URL, $Url);
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
                    $demoRowCount = 0;
                    $downloadRowCount = 0;
                    $docRowCount = array();
                    for ($j=1; $j<=$i; $j++) {
                        $myFileSize = "";
                        $myLockStatus = "";
                        if ($amsAsset[$j]["FILESIZE"]) {
                            if ($amsAsset[$j]["FILESIZE"] < 1000) $myFileSize = " (".$amsAsset[$j]["FILESIZE"]."&nbsp;B)";
                            else if ($amsAsset[$j]["FILESIZE"] < 1000000) $myFileSize = " (". round($amsAsset[$j]["FILESIZE"]/1000) ."&nbsp;KB)";
                            else $myFileSize = " (". round($amsAsset[$j]["FILESIZE"]/1000000, 2) ."&nbsp;MB)";
                        }
                        if ($amsAsset[$j]["LOCKED"]) {
                            if ($amsAsset[$j]["LOCKED"] == "True") $myLockStatus = " <img src='/".$base_path.$directory."/images/lock.gif' border='0'>";
                            else if ($amsAsset[$j]["LOCKED"] == "Unlocked") $myLockStatus = " <img src='/".$base_path.$directory."/images/unlock.gif' border='0'>";
                        }
                        switch ($amsAsset[$j]["ASSETTYPEDESCRIPTION"]) {
                            case "Virtual Demo":
                                $myDemo .= "<tr class='row".($demoRowCount%2)."'><td><div class='OneLinkNoTx'><strong>".$amsAsset[$j]["ASSETTITLE"]."</strong></div></td>";
                                $myDemo .= "<td><a href='http://myaccount.flukenetworks.com/FNet/".$langReg."/findit?Document=".$amsAsset[$j]["ASSETID"]."'  target='_blank'>View Demo</a></td>";
                                $myDemo .= "<td valign='top'>".$myLockStatus."</td></tr>";
                                $demoRowCount++;
                                break;
                            case "Software":
                                $myDownload .= "<tr class='row".($downloadRowCount%2)."'><td><div class='OneLinkNoTx'><strong>".$amsAsset[$j]["ASSETTITLE"]."</strong><br>".$amsAsset[$j]["ASSETDESCRIPTION"]."</div></td>";
                                $myDownload .= "<td><a href='http://myaccount.flukenetworks.com/FNet/".$langReg."/findit?Document=".$amsAsset[$j]["ASSETID"]."'>Download</a><br>".$myFileSize."</td>";
                                $myDownload .= "<td valign='top'>".$myLockStatus."</td></tr>";
                                $downloadRowCount++;
                                break;
                            case "Application Note":
                            case "White Paper":
                            case "Datasheet":
                            case "Brochure":
                            case "Catalog":
                            case "Flyer":
                                if (! $docRowCount[$amsAsset[$j]["ASSETTYPEDESCRIPTION"]]) $docRowCount[$amsAsset[$j]["ASSETTYPEDESCRIPTION"]] = 0;
                                $myDoc[$amsAsset[$j]["ASSETTYPEDESCRIPTION"]] .= "<tr class='row".($docRowCount[$amsAsset[$j]["ASSETTYPEDESCRIPTION"]]%2)."'><td>";
                                $myDoc[$amsAsset[$j]["ASSETTYPEDESCRIPTION"]] .= "<div class='OneLinkNoTx'>\n";
                                $myDoc[$amsAsset[$j]["ASSETTYPEDESCRIPTION"]] .= "<strong>".$amsAsset[$j]["ASSETTITLE"]."</strong><br>".$amsAsset[$j]["ASSETDESCRIPTION"];
                                $myDoc[$amsAsset[$j]["ASSETTYPEDESCRIPTION"]] .= "</div>\n";
                                $myDoc[$amsAsset[$j]["ASSETTYPEDESCRIPTION"]] .= "</td>";
                                $myDoc[$amsAsset[$j]["ASSETTYPEDESCRIPTION"]] .= "<td><a href='http://myaccount.flukenetworks.com/FNet/".$langReg."/findit?Document=".$amsAsset[$j]["ASSETID"]."'>PDF</a> ".$myFileSize."</td>";
                                $myDoc[$amsAsset[$j]["ASSETTYPEDESCRIPTION"]] .= "<td valign='top'>".$myLockStatus."</td></tr>";
                                $docRowCount[$amsAsset[$j]["ASSETTYPEDESCRIPTION"]]++;
                                break;
                            default:
                        }
                    }
                }
            ?>

            <!-- Documents -->
            <?php if (count($myDoc) > 0) { ?>

                <div data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">
                    <h3>Documents</h3>

                    <?php $rowCount2 = 0;

                    foreach (array("Brochure","Datasheet","Catalog","Application Note","White Paper","Flyer") as $type) {
                        if ($myDoc[$type]) { ?>

                            <h4><?php echo $type; ?></h4>
                            <table width="100%" data-role="table" id="documents-table" data-mode="reflow" class="ui-responsive table-stroke table-stripe">
                                <thead>
                                    <tr>
                                        <th width="60%">Title/Description</th>
                                        <th>Download</th>
                                        <th width="1px">&nbsp;</th>
                                    </tr>
                                </thead>
                                <tbody>
                                    <?php echo $myDoc[$type]; ?>
                                </tbody>
                            </table>
                            <div style="clear:both;"></div>

                            <?php $rowCount2++;
                        }
                    } ?>

                </div>
            <?php } ?>

            <!-- Demos -->
            <?php if ($myDemo) { ?>

                <div data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">
                    <h3>Demos</h3>
                    <table width="100%" data-role="table" id="demos-table" data-mode="reflow" class="ui-responsive table-stroke table-stripe">
                        <thead>
                            <tr>
                                <th width="60%">Title/Description</th>
                                <th>Demo</th>
                                <th width="1px">&nbsp;</th>
                            </tr>
                        </thead>
                        <tbody>
                            <?php echo $myDemo; ?>
                        </tbody>
                    </table>
                    <div style="clear:both;"></div>
                </div>

            <?php } ?>
            <!-- END: Documents & Demos -->

            <!-- Case Studies -->
            <?php
                $prodExpertise = views_get_view_result('product_expertise');

                if (count($prodExpertise) > 0) {

                    $headerPrinted = false;

                    foreach ($prodExpertise as $expertise) {
                        if ($expertise->term_data_name == "Case Study") {

                            if (!$headerPrinted){

                                $headerPrinted = true; ?>

                                <div data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">
                                <h3>Case Studies</h3>

                            <?php } ?>

                            <h4><?php echo $expertise->node_title; ?></h4>
                            <?php echo $expertise->node_revisions_body; ?>
                            <div style="clear:both;"></div>

                        <?php }
                    }

                    if ($headerPrinted){ ?>
                        </div>
                    <?php } ?>

            <?php } ?>
            <!-- END: Case Studies -->

            <!-- Custom Tabs -->
            <?php if(!empty($node->field_prod_ctab_name_1[0]["value"]) && !empty($node->field_prod_ctab_data_1[0]["value"])){ ?>

                <div data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">
                    <h3><?php echo $node->field_prod_ctab_name_1[0]["value"]; ?></h3>
                    <?php echo $node->field_prod_ctab_data_1[0]["value"]; ?>
                    <div style="clear:both;"></div>
                </div>

            <?php } ?>

            <?php if(!empty($node->field_prod_ctab_name_2[0]["value"]) && !empty($node->field_prod_ctab_data_2[0]["value"])){ ?>

                <div data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">
                    <h3><?php echo $node->field_prod_ctab_name_2[0]["value"]; ?></h3>
                    <?php echo $node->field_prod_ctab_data_2[0]["value"]; ?>
                    <div style="clear:both;"></div>
                </div>

            <?php } ?>

            <?php if(!empty($node->field_prod_ctab_name_3[0]["value"]) && !empty($node->field_prod_ctab_data_3[0]["value"])){ ?>

                <div data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">
                    <h3><?php echo $node->field_prod_ctab_name_3[0]["value"]; ?></h3>
                    <?php echo $node->field_prod_ctab_data_3[0]["value"]; ?>
                    <div style="clear:both;"></div>
                </div>

            <?php } ?>

            <?php if(!empty($node->field_prod_ctab_name_4[0]["value"]) && !empty($node->field_prod_ctab_data_4[0]["value"])){ ?>

                <div data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">
                    <h3><?php echo $node->field_prod_ctab_name_4[0]["value"]; ?></h3>
                    <?php echo $node->field_prod_ctab_data_4[0]["value"]; ?>
                    <div style="clear:both;"></div>
                </div>

            <?php } ?>

            <?php if(!empty($node->field_prod_ctab_name_5[0]["value"]) && !empty($node->field_prod_ctab_data_5[0]["value"])){ ?>

                <div data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">
                    <h3><?php echo $node->field_prod_ctab_name_5[0]["value"]; ?></h3>
                    <?php echo $node->field_prod_ctab_data_5[0]["value"]; ?>
                    <div style="clear:both;"></div>
                </div>

            <?php } ?>

            <?php if(!empty($node->field_prod_ctab_name_6[0]["value"]) && !empty($node->field_prod_ctab_data_6[0]["value"])){ ?>

               <div data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">
                    <h3><?php echo $node->field_prod_ctab_name_6[0]["value"]; ?></h3>
                    <?php echo $node->field_prod_ctab_data_6[0]["value"]; ?>
                    <div style="clear:both;"></div>
                </div>

            <?php } ?>
            <!-- END: Custom Tabs -->

        </div>
        <!-- END: Sections -->

        <!-- Related Products -->
        <?php

            $relatedProd = views_get_view_result('product_related_prod');

            if (count($relatedProd) > 0) {
                $count = 0;
                $letterArray = array("a", "b");
                ?>

                <h3>Related Products</h3>
                <div id="related-products" class="ui-grid-a ui-responsive">

                    <?php foreach ($relatedProd as $rProd) {
                        if ($rProd->node_node_data_field_prod_relatedprod_node_data_field_prod_related_img_field_prod_related_img_fid) {
                            $file = field_file_load($rProd->node_node_data_field_prod_relatedprod_node_data_field_prod_related_img_field_prod_related_img_fid);
                            if ($file['filepath']) { ?>

                                <?php if ($count % 2 == 0 && $count != 0) { ?>
                                    </div>
                                    <div id="related-products" class="ui-grid-a ui-responsive">
                                <?php } ?>

                                <div class="ui-block-<?php echo $letterArray[$count++ % 2]; ?>">
                                    <div class="ui-body ui-body-f">
                                        <a href="/<?php echo drupal_lookup_path('alias','node/'.$rProd->node_node_data_field_prod_relatedprod_nid); ?>">
                                            <img src="/<?php echo $file['filepath']; ?>">
                                            <p><?php echo $rProd->node_node_data_field_prod_relatedprod_title; ?></p>
                                        </a>
                                    </div>
                                </div>

                            <?php }
                        }
                    } ?>

                </div>

        <?php } ?>
        <!-- END: Related Products -->

    </div>


</div>