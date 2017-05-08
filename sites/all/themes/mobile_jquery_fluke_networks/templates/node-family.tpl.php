<style>

  #hero_industry_h1,
  .hero_marquee,
  .btn_143w {
    padding:0 !important;
  }

  .swiper-slide * {
    background:none !important;
    width:auto !important;
    height:auto !important;
    padding:0 !important;
    margin:0 !important;
    text-align:left !important;
    font-color:#999 !important;
    font-size:16px !important;
  }

</style>

<script>
  $(document).ready(function(){

    // On page load, show only the first tab content.
    $('.page-section-family').hide();
    $('.page-section-family').first().show();

    $('.tabs-family a').click(function(event){
      event.preventDefault(); // Stop the browser from scrolling to anchor.
      $('.page-section-family').hide(); // Hide all tab contents.
      var sectionId = $(this).attr('href'); // Determine which tab was clicked.
      $(sectionId).show(); // Show clicked tab content.
    });

  });
</script>

<script type="text/javascript">
  /*======
   Use document ready or window load events
   For example:
   With jQuery: $(function() { ...code here... })
   Or window.onload = function() { ...code here ...}
   Or document.addEventListener('DOMContentLoaded', function(){ ...code here... }, false)
   =======*/

  $(document).ready(function() {
    var mySwiper = new Swiper('.swiper-container',{
      //Your options here:
      mode:'horizontal',
      loop: true,
      pagination: '.pagination',
      paginationClickable: true,
      autoplay: 5000
      //etc..
    });
  });

</script>

<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> clear-block">

  <h1><?php print $node->title ?></h1>

  <div class="swiper-container">
    <div class="swiper-wrapper">

      <?php
      $bannerArray = array();
      for ($i=1; $i<6; $i++) {
        // Get string to set as $bannerArray key.
        $keyLabel = 'field_family_banner_srt_'.$i;
        $key = $node->$keyLabel;
        $keyString = $key[0]['value'] ? $key[0]['value'] : "0";

        // Get string to set as $bannerArray value.
        $valueLabel = 'field_family_banner_txt_'.$i;
        $value =  $node->$valueLabel;
        $valueString =  $value[0]['value'];

        // Set $bannerArray key/value pair.
        $bannerArray[$keyString] = $valueString;
      }
      asort($bannerArray);

      foreach ($bannerArray as $k) {

        if ($k != null) { ?>

          <div class="swiper-slide">
            <?php print str_replace(array('<br>', '<br />', '<br/>'), '', $k); ?>
          </div>

        <?php }

      } ?>

    </div>
    <div class="pagination"></div>
  </div><!-- .swiper-container -->

  <?php

  $view = views_get_view('industry_family_products');
  $view->set_items_per_page(0);
  $view->set_arguments(array($node->nid));
  $view->execute();
  $result = $view->result;

  foreach ($result as $myProd){ ?>

    <h2><?php print $myProd->node_title; ?></h2>

    <?php
    if ($myProd->node_data_field_prod_hub_img_field_prod_hub_img_fid) {
      $file = field_file_load($myProd->node_data_field_prod_hub_img_field_prod_hub_img_fid);
      if ($file['filepath']){ ?>

        <img src="/<?php print $file['filepath']; ?>" width="146" height="116" border="0" style="float:left; margin:0 1em 1em 0;">

      <?php }
    } ?>

    <div><?php print $myProd->node_data_field_product_desc_field_product_desc_value; ?></div>

    <a
      href="/<?php print drupal_lookup_path('alias',"node/".$myProd->nid); ?>"
      target="_self"
      data-role="button"
      class="button-yellow">
      Learn More
    </a>

  <?php } ?>

  <div data-role='tabs'>

    <div data-role="navbar">
      <ul class="tabs-family">
        <li><a href="#content-overview" class="ui-btn-active">Overview</a></li>
        <li><a href="#content-expertise">Expertise</a></li>
        <li><a href="#content-products">Products</a></li>
      </ul>
    </div><!-- /navbar -->

    <div id="content-overview" class="page-section-family">

      <div>

        <?php print $node->field_family_overview[0]['value']; ?>

        <div class="clearboth;"></div>

      </div>

      <!-- Extra Links -->
      <div>

        <?php
        for ($i=1; $i<4; $i++) {
          $myTitle = 'field_family_overview_boxtitle_'.$i;
          $myImage = 'field_family_overview_boximg_'.$i;
          $myDescription = 'field_family_overview_boxdesc_'.$i;
          $myLink = 'field_family_overview_boxlink_'.$i;

          $myTitleArr = $node->$myTitle;
          $myImageArr = $node->$myImage;
          $myDescriptionArr = $node->$myDescription;
          $myLinkArr = $node->$myLink;
          if ($myTitleArr[0]['value'] && $myDescriptionArr[0]['value']) { ?>

            <h3><?php print $myTitleArr[0]['value']; ?></h3>

            <?php
            if ($myImageArr[0]['fid']) {
              $file = field_file_load($myImageArr[0]['fid']);

              if ($file['filepath']) { ?>
                <div><img src='/<?php print $file['filepath']; ?>' border='0'></div>
              <?php }

            } ?>

            <div><?php print $myDescriptionArr[0]['value']; ?></div>

            <?php if ($myLinkArr[0]['url'] && $myLinkArr[0]['title']) { ?>

              <div>
                <a
                  href='<?php print $myLinkArr[0]['url']; ?>'
                  target='<?php print $myLinkArr[0]['attributes']['target'] ? $myLinkArr[0]['attributes']['target'] : "_self"; ?>'>
                  <?php print $myLinkArr[0]['title']; ?>
                </a>
              </div>

            <?php }
          }
        }
        ?>

        <div class="clearboth;"></div>

      </div><!-- Extra Links -->

    </div><!-- #content-overview -->

    <div id="content-expertise" class="page-section-family">

      <div>

        <?php print $node->field_family_expertise[0]['value']; ?>

        <div class="clearboth"></div>

      </div>

      <!-- Extra Links -->
      <div>

        <?php
        for ($i=1; $i<4; $i++) {

          $myTitle = 'field_family_expert_boxtitle_'.$i;
          $myImage = 'field_family_expert_boximg_'.$i;
          $myDescription = 'field_family_expert_boxdesc_'.$i;
          $myLink = 'field_family_expert_boxlink_'.$i;

          $myTitleArr = $node->$myTitle;
          $myImageArr = $node->$myImage;
          $myDescriptionArr = $node->$myDescription;
          $myLinkArr = $node->$myLink;

          if ($myTitleArr[0]['value'] && $myDescriptionArr[0]['value']) { ?>

            <h3><?php print $myTitleArr[0]['value']; ?></h3>

            <?php if ($myImageArr[0]['fid']) {
              $file = field_file_load($myImageArr[0]['fid']);
              if ($file['filepath']) { ?>

                <div><img src='/<?php print $file['filepath']; ?>' border='0'></div>

              <?php }
            } ?>

            <div><?php print $myDescriptionArr[0]['value']; ?></div>

            <?php if ($myLinkArr[0]['url'] && $myLinkArr[0]['title']) { ?>

              <div>
                <a
                  href='<?php print $myLinkArr[0]['url']; ?>'
                  target='<?php print $myLinkArr[0]['attributes']['target'] ? $myLinkArr[0]['attributes']['target'] : "_self"; ?>'>
                  <?php print $myLinkArr[0]['title']; ?>
                </a>
              </div>

            <?php }
          }
        }
        ?>

        <div class="clearboth"></div>

      </div><!-- Extra Links -->

    </div><!-- #content-expertise -->

    <div id="content-products" class="page-section-family">

      <!-- Products -->
      <div>

        <h2><?php echo $node->title; ?></h2>

        <?php
        $view = views_get_view('industry_family_products');
        $view->set_items_per_page(0);

        // Fetch regLang value to pass as argument to 'industry_family_products' view
        $region = strtolower($_COOKIE["regLang"]);
        if ($region == "") $region = "en-us";

        $view->set_arguments(array($node->nid, $region));
        $view->execute();
        $result = $view->result;
        $prodArray = array();

        foreach ($result as $myProd) {
          if ($myProd->node_data_field_prod_hub_img_field_prod_hub_img_fid) {

            $file = field_file_load($myProd->node_data_field_prod_hub_img_field_prod_hub_img_fid);

            if ($file['filepath']) { ?>

              <div><img src='/<?php print $file['filepath']; ?>' style='width:100%; max-width:146px;' border='0'></div>

            <?php }

          } ?>

          <div>
            <a href='/<?php print drupal_lookup_path('alias',"node/".$myProd->nid); ?>'><?php print $myProd->node_title; ?></a>
          </div>

          <div><?php print $myProd->node_data_field_product_desc_field_product_desc_value; ?></div>

          <div><a href='/<?php print drupal_lookup_path('alias',"node/".$myProd->nid); ?>'>Learn More &#187;</a></div>

        <?php } ?>

        <div class="clearboth"></div>

      </div><!-- Products -->

      <!-- Extra Links -->
      <div>

        <?php
        for ($i=1; $i<4; $i++) {

          $myTitle = 'field_family_prod_boxtitle_'.$i;
          $myImage = 'field_family_prod_boximg_'.$i;
          $myDescription = 'field_family_prod_boxdesc_'.$i;
          $myLink = 'field_family_prod_boxlink_'.$i;

          $myTitleArr = $node->$myTitle;
          $myImageArr = $node->$myImage;
          $myDescriptionArr = $node->$myDescription;
          $myLinkArr = $node->$myLink;

          if ($myTitleArr[0]['value'] && $myDescriptionArr[0]['value']) { ?>

            <h3><?php print $myTitleArr[0]['value']; ?></h3>

            <?php if ($myImageArr[0]['fid']) {
              $file = field_file_load($myImageArr[0]['fid']);

              if ($file['filepath']) { ?>

                <div><img src='/<?php print $file['filepath']; ?>' border='0'></div>

              <?php }

            } ?>

            <div><?php print $myDescriptionArr[0]['value']; ?></div>

            <?php if ($myLinkArr[0]['url'] && $myLinkArr[0]['title']) { ?>

              <div>
                <a
                  href='<?php print $myLinkArr[0]['url']; ?>'
                  target='<?php print $myLinkArr[0]['attributes']['target'] ? $myLinkArr[0]['attributes']['target'] : "_self"; ?>'>
                  <?php print $myLinkArr[0]['title']; ?>
                </a>
              </div>

            <?php }
          }
        }
        ?>

        <div class="clearboth"></div>

      </div><!-- Extra Links -->

    </div><!-- #content-products -->

  </div>

</div>