
	<?php //print $view->args[0] ?>
	<?php //print_r($view); ?>


	<div>

	<?php // require_once("includes/region_dropdown.php"); ?>

	<?php 
	/*
	$module = 'product_assets';
	$delta = 1;
	$siteLang = module_invoke($module, 'block', 'view', $delta); // Defaults to 'en' if X-OrignalLang header is not found.
	*/
/*	$siteReg = module_invoke('fnet_helper', 'site_region');
	$serverName = $siteReg["serverName"];
	$langReg = $siteReg["langReg"]; 
	$regLang = $siteReg["regLang"]; 
*/	?>

	<?php

	$vocabId = 10;
	$terms = taxonomy_get_tree($vocabId);
	$termCount = 0;
	// $region = $view->args[0];
	$region = strtolower($_COOKIE["regLang"]); // $view->args[0];
	if ((strlen($view->args[0]) < 5 || $view->args[0] != $region)&&($region!="")) {
		//redirect to correct region
		$newurl = "/news-events/" . $region;
		header("Location: $newurl");
	} else {
		$region = $view->args[0];
	}

	//if no arg, check X Header
/*	if(strlen($region) < 2)
	{
		if (!empty($siteLang))
		{
			switch (strtolower($siteLang))
			{
				case "fr": $region = "fr";
						   break;
				case "de": $region = "de";
						   break;
				case "es": $region = "es";
						   break;
				case "zh": $region = "cn";
						   break;
				case "ja": $region = "jp";
						   break;
				case "pt": $region = "br";
						   break;
				case "ru": $region = "ru";
						   break;
				case "za": $region = "za";
						   break;
				default: $region = "us";
			}
		}
		else
		{
			$region = "us";
		}
		//redirect to correct region
		$newurl = "/news-events/" . $region;
		header("Location: $newurl");
	}
*/
	//if cookie doesn't match region, send to cookie's region
	//if(isset($_COOKIE['region']))
	//{
		//$cookievalue = $_COOKIE['region'];
		//if($cookievalue != $region)
		//{
			//$nexturl = "/news-events/" . $cookievalue;
			//header("Location: $nexturl");
		//}
	//}

	//get all events to determine valid regions
	$regionview = views_get_view_result('events_view');

//	print "<div style='float:right;padding-right:25px;'>" . generateRegionSelect($ddregions, $regionview, $region, '/news-events/') . "</div>";
	//get top 5 press releases
	$news = views_get_view_result('top_pressreleases', $region);
  $awards = views_get_view_result('awards_regions_view', $region);
/*	$awards = views_get_view_result('awards_view');
	$awardcount = 0;
	// print_r ($awards);
	foreach($awards as $row)
	{
		//if(strtolower($row->location_country) == $region)
		if ($row->node_data_field_award_langreg_field_award_langreg_value == $region)
		{
			$awardcount++;
		}
	} */
	?>

	<h1>News and Events</h1>

	<h3>News</h3>
    <?php //print_r($news);
    foreach($news as $row)
    {
        $newsdate = strtotime($row->node_data_field_news_date_field_news_date_value);
        print date('F j, Y',$newsdate);
        print "<br/>";
        print "<a href='/node/". $row->nid . "'>". html_entity_decode($row->node_title) . "</a><p/>";

    }
    ?>

    <a
      href="/news-list/<?php echo $region; ?>"
      data-role="button"
      class="button-yellow">
      More News
    </a>


    <?php
        $buf = "";
        foreach($awards as $row)
        {
          $ahref = '';
          $target = '';

          if(strlen($row->node_data_field_award_intro_field_award_link_url) > 4)
          {
            $ahref = $row->node_data_field_award_intro_field_award_link_url;
            $target = "target='_" .$row->nid . "'";
          }
          else
          {
            $ahref = "/node/" . $row->nid;
          }

          $newsdate = strtotime($row->node_data_field_award_date_field_award_date_value);
          $buf .= date('F j, Y',$newsdate);
          $buf .= "<br/>";
          $buf .= "<a href='". $ahref . "' " . $target . ">". $row->node_title . "</a>";
          $buf .= "<p/>";
        }

        if ($buf) {
          print "<h3>Awards</h3>";
          print $buf;
          ?>

          <a
            href="/awards-list/<?php echo $region; ?>"
            data-role="button"
            class="button-yellow">
            More Awards
          </a>

        <?php }
/*
				if($awardcount > 0)
				{
					print "<h3>Awards 2</h3>";
					foreach($awards as $row)
					{
            //print_r ($awards);
            //print "<hr>";
						$ahref = '';
						$target = '';

						if(strlen($row->node_data_field_award_intro_field_award_link_url) > 4)
						{
							$ahref = $row->node_data_field_award_intro_field_award_link_url;
							$target = "target='_" .$row->nid . "'";
						}
						else
						{
							$ahref = "/node/" . $row->nid;
						}

						//if(strtolower($row->location_country) == $region)
						 if ($row->node_data_field_award_langreg_field_award_langreg_value == $region)
            //if ($row->translations_langreg == $region)
						{  //print $region . "--" . $row->translations_langreg . "~~" .$row->node_data_field_award_langreg_field_award_langreg_value. "<hr>";
							$newsdate = strtotime($row->node_data_field_award_date_field_award_date_value);
							print date('F j, Y',$newsdate);
							print "<br/>";
							print "<a href='". $ahref . "' " . $target . ">". $row->node_title . "</a>";
							//print $row->node_data_field_award_intro_field_award_intro_value;
							print "<p/>";
						}
					}
					print "<p/><a href='/awards-list'><b>More Awards</b></a><p/>";
				}
*/
				?>


				<h3>Webcasts</h3>
				<?php //<a href="https://flukenetworks.webex.com/flukenetworks/mywebex/default.php?Rnd7939=0.05788203105803641" target="_fnetwebex"><b>Live Webcasts</b></a><br/>?>
        <?php
        $count = 0;
        if (is_array($view->style_plugin->rendered_fields)){
          foreach ($view->style_plugin->rendered_fields as $rowArray) {
            if (($rowArray['tid'] == "Webcasts") && ($count < 4)) {

              $fulldate = '';
              $ahref = '';
              $target = '';

              if (strlen($rowArray['field_event_date_value']) > 4) {
                $mydate = str_replace('</span>', '', $rowArray['field_event_date_value']);
                $mydate = str_replace('<span class="date-display-single">', '', $mydate);
                $eventdate = strtotime($mydate);
                $todays_date = date("Y-m-d");
                $today = strtotime($todays_date);
                $fulldate = "Expires " . date('F j, Y', $eventdate);
              }

              if (strlen($rowArray['field_workshop_reglink_url']) > 4) {
                $ahref = $rowArray['field_workshop_reglink_url'];
                $target = "target='_" . $rowArray['nid'] . "'";
              } else {
                $ahref = $rowArray['path'];
              }

              //only display unexpired promos or promos with no date
              if ($fulldate == '' || $eventdate > $today) {
                $count++;
                print "<div><a href='" . $ahref . "' " . $target . "><b>" . $rowArray['title'] . "</b></a></div>";
                print "<p>" . str_replace('<p>', '', $rowArray['field_event_intro_value']) . "</p>";
                //print "<div style='padding-bottom:10px;'><div class='btn_143w'><a href='" . $ahref . "' " . $target. ">Get Details</a></div></div>";
              }
            }
          }
        }
        if ($count == 4){
          print "<p/><a href='/news-events/webcasts/$region'><b>More Webcasts</b></a><p/>";
        }
        ?>

        <a
          href="/support/technical-docs/webcasts"
          data-role="button"
          class="button-yellow">
          On Demand Webcasts
        </a>


        <?php
          //loop through each term and display available promotions
          foreach ( $terms as $term )
          {
            //echo "<hr>";
            //	print_r ($term);
            //verify there are events available for this term
            $termCount = 0;
            if (is_array($view->style_plugin->rendered_fields)) {
                      foreach($view->style_plugin->rendered_fields as $rowArray) {
                if($rowArray['tid'] == $term->name) {
                  $termCount++;
                }
              }
            }

            if(($termCount > 0) && ($term->name !== "Webcasts"))
            {
                //print term header
                print "<h3>" . $term->name . "</h3>";
                $count = 0;
                //print each event for this term
                foreach($view->style_plugin->rendered_fields as $rowArray)
                {
                    if(($rowArray['tid'] == $term->name)&& ($count < 4))
                    {

                        $fulldate = '';
                        $ahref = '';
                        $target = '';

                        if(strlen($rowArray['field_event_date_value']) > 4)
                        {
                            $mydate = str_replace('</span>','',$rowArray['field_event_date_value']);
                            $mydate = str_replace('<span class="date-display-single">','',$mydate);
                            $eventdate = strtotime($mydate);
                            $todays_date = date("Y-m-d");
                            $today = strtotime($todays_date);
                            $fulldate = "Expires " . date('F j, Y',$eventdate);
                        }

                        if(strlen($rowArray['field_workshop_reglink_url']) > 4)
                        {
                            $ahref = $rowArray['field_workshop_reglink_url'];
                            $target = "target='_" .$rowArray['nid'] . "'";
                        }
                        else
                        {
                            $ahref = $rowArray['path'];
                        }

                        //only display unexpired promos or promos with no date
                        if ($fulldate == '' || $eventdate > $today)
                        {
                            $count++;
                            print "<div><a href='" . $ahref ."' " .$target . "><b>" . $rowArray['title'] . "</b></a></div>";
                            print "<p>". str_replace('<p>','',$rowArray['field_event_intro_value']) . "</p>";
                            //print "<div style='padding-bottom:10px;'><div class='btn_143w'><a href='" . $ahref . "' " . $target. ">Get Details</a></div></div>";
                        }
                    }
                }
                $compressed_term = strtolower(str_replace(' ', '', $term->name));
                if ($count == 4){
                  print "<p/><a href='/news-events/$compressed_term/$region'><b>More $term->name</b></a><p/>";

                }
            }
        }

        ?>


	</div>
