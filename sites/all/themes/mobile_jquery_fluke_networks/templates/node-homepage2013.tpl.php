<?php
$siteReg = module_invoke('fnet_helper', 'site_region');
$serverName = $siteReg["serverName"];
$langReg = $siteReg["langReg"];
$regLang = $siteReg["regLang"];

$noTranslation = array();
//if ($regLang != "en-us") {
$validLangNode = array();
foreach ($node->field_home13_langreg as $key=>$val) {
  foreach ($val as $k=>$v) {
    if ($k == "nid")
      $validLangNode[$v] = 1;
  }
}
if (count($validLangNode) > 0) {
  $langNodeId = "";
  $view = views_get_view('admin_homepage2013_language');
  $view->set_items_per_page(0);
  $view->set_arguments(array($node->nid));
  $view->execute();
  $homeLang = $view->result;
  if (count($homeLang) > 0) {
    foreach ($homeLang as $lang) {
      if ($validLangNode[$lang->nid] &&
        substr($lang->node_data_field_home13lng_homepage_field_home13lng_lng_value, 0, 5) == $regLang) {
        $langNodeId = $lang->nid;
        break;
      }
    }
    if (! empty($langNodeId)) {
      $langNode = node_load($langNodeId);
      if ($langNode->field_home13lng_banner_html[0]['value'] || $langNode->field_home13lng_banner_html[1]['value'] ||
        $langNode->field_home13lng_banner_html[2]['value'] || $langNode->field_home13lng_banner_html[3]['value'] ||
        $langNode->field_home13lng_banner_html[4]['value']) {
        $noTranslation["field_home13_banner_html"] = true;
        for ($i=0; $i<5; $i++) {
          $node->field_home13_banner_html[$i]['value'] = $langNode->field_home13lng_banner_html[$i]['value'];
        }
      }
      if ($langNode->field_home13lng_ind_desc_1[0]['value']) {
        $noTranslation["field_home13_ind_desc_1"] = true;
        $node->field_home13_ind_desc_1[0]['value'] = $langNode->field_home13lng_ind_desc_1[0]['value'];
      }

      if ($langNode->field_home13lng_ind_desc_2[0]['value']) {
        $noTranslation["field_home13_ind_desc_2"] = true;
        $node->field_home13_ind_desc_2[0]['value'] = $langNode->field_home13lng_ind_desc_2[0]['value'];
      }

      if ($langNode->field_home13lng_ind_desc_3[0]['value']) {
        $noTranslation["field_home13_ind_desc_3"] = true;
        $node->field_home13_ind_desc_3[0]['value'] = $langNode->field_home13lng_ind_desc_3[0]['value'];
      }

      if ($langNode->field_home13lng_exptpc[0]['url'] || $langNode->field_home13lng_exptpc[1]['url'] || $langNode->field_home13lng_exptpc[2]['url']) {
        $noTranslation["field_home13_exptpc"] = true;
        for ($i=0; $i<3; $i++) {
          $node->field_home13_exptpc[$i]['url'] = link_cleanup_url($langNode->field_home13lng_exptpc[$i]['url']);
          $node->field_home13_exptpc[$i]['title'] = $langNode->field_home13lng_exptpc[$i]['title'];
          $node->field_home13_exptpc[$i]['attributes']['target'] = $langNode->field_home13lng_exptpc[$i]['attributes']['target'];
        }
      }

      if ($langNode->field_home13lng_exprle[0]['url'] || $langNode->field_home13lng_exprle[1]['url'] || $langNode->field_home13lng_exprle[2]['url']) {
        $noTranslation["field_home13_exprle"] = true;
        for ($i=0; $i<3; $i++) {
          $node->field_home13_exprle[$i]['url'] = link_cleanup_url($langNode->field_home13lng_exprle[$i]['url']);
          $node->field_home13_exprle[$i]['title'] = $langNode->field_home13lng_exprle[$i]['title'];
          $node->field_home13_exprle[$i]['attributes']['target'] = $langNode->field_home13lng_exprle[$i]['attributes']['target'];
        }
      }

      if ($langNode->field_home13lng_expind[0]['url'] || $langNode->field_home13lng_expind[1]['url'] || $langNode->field_home13lng_expind[2]['url']) {
        $noTranslation["field_home13_expind"] = true;
        for ($i=0; $i<3; $i++) {
          $node->field_home13_expind[$i]['url'] = link_cleanup_url($langNode->field_home13lng_expind[$i]['url']);
          $node->field_home13_expind[$i]['title'] = $langNode->field_home13lng_expind[$i]['title'];
          $node->field_home13_expind[$i]['attributes']['target'] = $langNode->field_home13lng_expind[$i]['attributes']['target'];
        }
      }

      if ($langNode->field_home13lng_ads[0]['value'] || $langNode->field_home13lng_ads[1]['value'] || $langNode->field_home13lng_ads[2]['value'] ||
        $langNode->field_home13lng_ads[3]['value'] || $langNode->field_home13lng_ads[4]['value']) {
        $noTranslation["field_home13_ads"] = true;
        for ($i=0; $i<5; $i++) {
          $node->field_home13_ads[$i]['value'] = $langNode->field_home13lng_ads[$i]['value'];
        }
      }

      if ($langNode->field_mobile_hero_banner_languag[0]['value']) {
        $noTranslation["field_mobile_hero_banner"] = true;
        $node->field_mobile_hero_banner[0]['value'] = $langNode->field_mobile_hero_banner_languag[0]['value'];
      }
    }
  }
}
?>

<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> clear-block">

  <!-- Mobile Hero -->
  <?php if ($node->field_mobile_hero_banner[0]['value']) { ?>

    <div class="<?php $noTranslation["field_mobile_hero_banner"] ? print 'OneLinkNoTx' : print ''; ?>">
      <?php print $node->field_mobile_hero_banner[0]['value']; ?>
    </div><!-- Mobile Hero -->

    <hr />

  <?php } ?>

  <!-- Expertise Links -->
  <div id="topic" class="homepage-expertise-section">
    <h3>Topic</h3>
    <div class="interior <?php $noTranslation['field_home13_exptpc'] ? print 'OneLinkNoTx' : print ''; ?>">

      <!-- Topic Links -->
      <ul class="list-underlined">
        <?php
        for ($i = 0; $i < 3; $i++) {
          if ($node->field_home13_exptpc[$i]['url']) { ?>

            <li>
              <a href="<?php print $node->field_home13_exptpc[$i]['url']; ?>"
                target="<?php $node->field_home13_exptpc[$i]['attributes']['target'] ? print $node->field_home13_exptpc[$i]['attributes']['target'] : print '_self'; ?>">
                <?php print $node->field_home13_exptpc[$i]['title']; ?>
              </a>
            </li>

          <?php }
        }
        ?>
      </ul>

      <!-- Link to All Topics  -->
      <div style="text-align:center;">
        <a href="/expertise/topics" class="button-yellow" data-role="button" data-theme="f" data-inline="true">
          More
        </a>
      </div>

    </div>
  </div><!-- Topic -->

  <hr />

  <div id="role" class="homepage-expertise-section">
    <h3>Role</h3>
    <div class="interior <?php $noTranslation['field_home13_exprle'] ? print 'OneLinkNoTx' : print ''; ?>">

      <!-- Role Links -->
      <ul class="list-underlined">
        <?php
        for ($i = 0; $i < 3; $i++) {
          if ($node->field_home13_exprle[$i]['url']) { ?>

            <li>
              <a href="<?php print $node->field_home13_exprle[$i]['url']; ?>"
                 target="<?php $node->field_home13_exprle[$i]['attributes']['target'] ? print $node->field_home13_exprle[$i]['attributes']['target'] : print '_self'; ?>">
                <?php print $node->field_home13_exprle[$i]['title']; ?>
              </a>
            </li>

          <?php }
        }
        ?>
      </ul>

      <!-- Link to All Roles  -->
      <div style="text-align:center;">
        <a href="/expertise/roles" class="button-yellow" data-role="button" data-theme="f" data-inline="true">
          More
        </a>
      </div>

    </div>
  </div><!-- Role -->

  <hr />

  <div id="industry" class="homepage-expertise-section">
    <h3>Industry</h3>
    <div class="interior <?php $noTranslation['field_home13_expind'] ? print 'OneLinkNoTx' : print ''; ?>">

      <!-- Industry Links -->
      <ul class="list-underlined">
        <?php
        for ($i = 0; $i < 3; $i++) {
          if ($node->field_home13_exptpc[$i]['url']) { ?>

            <li>
              <a href="<?php print $node->field_home13_expind[$i]['url']; ?>"
                 target="<?php $node->field_home13_expind[$i]['attributes']['target'] ? print $node->field_home13_expind[$i]['attributes']['target'] : print '_self'; ?>">
                <?php print $node->field_home13_expind[$i]['title']; ?>
              </a>
            </li>

          <?php }
        }
        ?>
      </ul>

      <!-- Link to All Industries  -->
      <div style="text-align:center;">
        <a href="/expertise/industries" class="button-yellow" data-role="button" data-theme="f" data-inline="true">
          More
        </a>
      </div>

    </div>
  </div><!-- Industry -->

  <hr />
  <!-- END: Expertise Links -->

  <!-- Promotion Box -->
  <div style="text-align:center;" class="<?php $noTranslation['field_home13_ads'] ? print 'OneLinkNoTx' : print ''; ?>">
    <?php
    $promoArray = array();
    $j = 0;
    for ($i = 0; $i < 5; $i++) {
      if ($node->field_home13_ads[$i]['value']) {
        $promoArray[$j++] = $node->field_home13_ads[$i]['value'];
      }
    }
    print $promoArray[rand(101, 999) % ($j)];
    ?>
  </div><!-- Promotion Box -->

  <hr />

  <?php
  $industryArr = array(6,7,8); // Fetch industry by integer.
  ?>

  <!-- Industry/Family Links -->
  <div class="industry-families">
    <h2>Datacom Cabling</h2>

    <div class="<?php if ($noTranslation["field_home13_ind_desc_1"]) print 'OneLinkNoTx'; ?>">
      <div><?php print $node->field_home13_ind_desc_1[0]["value"]; ?></div>

      <ul class="list-underlined">

        <?php
        $familyList = views_get_view('industry_family');
        $familyList->set_items_per_page(0);
        $familyList->set_arguments(array($industryArr[0])); // Get the Datacom Cabling families.
        $familyList->execute();
        $familyResult = $familyList->result;

        foreach($familyResult as $family) {

          if($family->node_data_field_family_shortdesc_field_family_page_active_value=="Yes") { ?>

            <li><a href="/<?php print drupal_lookup_path('alias',"node/".$family->nid); ?>"><?php print $family->node_title; ?></a></li>

          <?php } else {
            $familyBookmark = str_replace(" ", "_", $family->node_title);
            $familyBookmark = str_replace(",", "", $familyBookmark); ?>

            <li><a href="/<?php print drupal_lookup_path('alias','node/6').'?td=products#'.$familyBookmark; ?>"><?php print $family->node_title; ?></a></li>

          <?php }

        }
        ?>

      </ul>

      <div style="text-align:center;">
        <a href="/node/6" class="button-yellow" data-role="button" data-theme="f" data-inline="true">
          More
        </a>
      </div>

    </div>

  </div><!-- Datacom Cabling -->

  <hr />

  <div class="industry-families">
    <h2>IT Networking</h2>

    <div class="<?php if ($noTranslation["field_home13_ind_desc_1"]) print 'OneLinkNoTx'; ?>">
      <div><?php print $node->field_home13_ind_desc_1[0]["value"]; ?></div>

      <ul class="list-underlined">

        <?php
        $familyList = views_get_view('industry_family');
        $familyList->set_items_per_page(0);
        $familyList->set_arguments(array($industryArr[1])); // Get the Datacom Cabling families.
        $familyList->execute();
        $familyResult = $familyList->result;

        foreach($familyResult as $family) {

          if($family->node_data_field_family_shortdesc_field_family_page_active_value=="Yes") { ?>

            <li><a href="/<?php print drupal_lookup_path('alias',"node/".$family->nid); ?>"><?php print $family->node_title; ?></a></li>

          <?php } else {
            $familyBookmark = str_replace(" ", "_", $family->node_title);
            $familyBookmark = str_replace(",", "", $familyBookmark); ?>

            <li><a href="/<?php print drupal_lookup_path('alias','node/7').'?td=products#'.$familyBookmark; ?>"><?php print $family->node_title; ?></a></li>

          <?php }

        }
        ?>

      </ul>

      <div style="text-align:center;">
        <a href="/node/7" class="button-yellow" data-role="button" data-theme="f" data-inline="true">
          More
        </a>
      </div>

    </div>

  </div><!-- IT Networking -->

  <hr />

  <div class="industry-families">
    <h2>Telecom</h2>

    <div class="<?php if ($noTranslation["field_home13_ind_desc_1"]) print 'OneLinkNoTx'; ?>">
      <div><?php print $node->field_home13_ind_desc_1[0]["value"]; ?></div>

      <ul class="list-underlined">

        <?php
        $familyList = views_get_view('industry_family');
        $familyList->set_items_per_page(0);
        $familyList->set_arguments(array($industryArr[2])); // Get the Datacom Cabling families.
        $familyList->execute();
        $familyResult = $familyList->result;

        foreach($familyResult as $family) {

          if($family->node_data_field_family_shortdesc_field_family_page_active_value=="Yes") { ?>

            <li><a href="/<?php print drupal_lookup_path('alias',"node/".$family->nid); ?>"><?php print $family->node_title; ?></a></li>

          <?php } else {
            $familyBookmark = str_replace(" ", "_", $family->node_title);
            $familyBookmark = str_replace(",", "", $familyBookmark); ?>

            <li><a href="/<?php print drupal_lookup_path('alias','node/8').'?td=products#'.$familyBookmark; ?>"><?php print $family->node_title; ?></a></li>

          <?php }

        }
        ?>

      </ul>

      <div style="text-align:center;">
        <a href="/node/8" class="button-yellow" data-role="button" data-theme="f" data-inline="true">
          More
        </a>
      </div>

    </div>

  </div><!-- Telecom -->
  <!-- END: Industry/Family Links -->

  
  
</div>