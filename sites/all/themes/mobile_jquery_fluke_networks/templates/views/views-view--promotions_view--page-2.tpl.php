
<?php //print_r($view); ?>

<div id="promotions-page-content">

  <?php require_once("includes/region_dropdown.php"); ?>
  <?php
  /*
      $module = 'product_assets';
      $delta = 1;
      $siteLang = module_invoke($module, 'block', 'view', $delta); // Defaults to 'en' if X-OrignalLang header is not found.
  */	?>
  <?php

  $vocabId = 5;
  $terms = taxonomy_get_tree($vocabId);
  $termCount = 0;
  $region = strtolower($_COOKIE["regLang"]); // $view->args[0];
  if ((strlen($view->args[0]) < 5 || $view->args[0] != $region)&&($region!="")) {
    //redirect to correct region
    $newurl = "/free-software-trials-downloads/" . $region;
    header("Location: $newurl");
  } else {
    $region = $view->args[0];
  }

  //get all promotions to determine valid regions
  $regionview = views_get_view_result('promotions_view');
  $viewHeader = $view->display['default']->display_options['header'];

  if($viewHeader){ ?>

    <div id=promotions-header">
      <?php print $viewHeader; ?>
    </div>

  <?php }

  //loop through each term and display available promotions
  $promoNotFound = true;
  //foreach ( $terms as $term )
  for ($i=0; $i<count($terms); $i++)
  {

    // The two lines of code here have the effect of displaying
    // the first term in the $terms array last on the page.
    $index = ($i + 1) % count($terms);
    $term = $terms[$index];

    //verify there are promotions available for this term, excluding the term "Generic No Index"
    $termCount = 0;
    if (count($view->style_plugin->rendered_fields)) {
      foreach($view->style_plugin->rendered_fields as $rowArray){

        $mydate = str_replace('</span>','',$rowArray['field_promo_expdate_value']);
        $mydate = str_replace('<span class="date-display-single">','',$mydate);
        $promodate = strtotime($mydate);
        $todays_date = date("Y-m-d");
        $today = strtotime($todays_date);

        if($rowArray['tid_1'] == $term->name
          && $rowArray['tid_1'] != "Generic No Index"
          && ($mydate == '' || $promodate > $today)){ // Make sure, if there is an expiration date, that it has not passed.

          $termCount++;
        }
      }
    }
    if($termCount > 0)
    {
      $promoNotFound = false;

      $termNameToPrint = $term->name == "Software Trials" ? "Free Software Trials" : $term->name;

      //print term header
      ?>
      <div class="page-section-title">
        <span><?php print $termNameToPrint; ?></span>
      </div>
      <?php

      //print each promotion for this term
      foreach($view->style_plugin->rendered_fields as $rowArray)
      {
        if($rowArray['tid_1'] == $term->name)
        {
          $fulldate = '';
          $ahref = '';
          $target = '';

          if(strlen($rowArray['field_promo_expdate_value']) > 4)
          {
            $mydate = str_replace('</span>','',$rowArray['field_promo_expdate_value']);
            $mydate = str_replace('<span class="date-display-single">','',$mydate);
            $promodate = strtotime($mydate);
            $todays_date = date("Y-m-d");
            $today = strtotime($todays_date);
            $fulldate = "Expires " . date('F j, Y',$promodate);
          }

          if(strlen($rowArray['field_promo_extlink_url']) > 4)
          {
            $ahref = $rowArray['field_promo_extlink_url'];
            $target = $rowArray['nid'];
          }
          else
          {
            $ahref = $rowArray['path'];
          }

          //only display unexpired promos or promos with no date
          if ($fulldate == '' || $promodate > $today)
          {
            if ($rowArray['field_promo_notranslation_value'] == "Do Not Translate") print "<div class=\"OneLinkNoTx\">";
            ?>

            <div class="promotion-instance">

              <div class="promotion-thumbnail">
                <a href="<?php print $ahref; ?>" target="_<?php print $target; ?>"><?php print $rowArray['field_promo_thumbnail_fid']; ?></a>
              </div>
              <div class="promotion-details">
                <h4 class="promotion-title"><?php print $rowArray['field_promo_intro_title_value']; ?></h4>
                <div class="promotion-description"><?php print $rowArray['field_promo_intro_value']; ?></div>
              </div>
              <div class="promotion-button">
                <div class="promotion-date"><?php print $fulldate; ?></div>
                <div class="btn_143w">
                  <a href="<?php print $ahref; ?>" target="_<?php print $target; ?>">Get Details</a>
                </div>
              </div>

              <div style="clear:both;"></div>

            </div>

            <?php
            if ($rowArray['field_promo_notranslation_value'] == "Do Not Translate") print "</div>";
          }
        }
      }
    }
  }
  if ($promoNotFound) {
    print "There are currently no promotion.";
  }
  ?>

</div>
