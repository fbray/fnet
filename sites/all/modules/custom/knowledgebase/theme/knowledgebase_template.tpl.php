<div id="knowledge-base">

  <h2>Knowledge Base</h2>

  <!-- START: Search Form -->
  <div id="kb-search">
    <form name="kbSearch" method="get" action="/knowledge-base">
      <input name="query" type="text" value="<?php if ($searchQuery !== FALSE) {
        print $searchQuery;
      } ?>" style="width:250px;">

      <input name="submit" type="submit" value="Search">

      <select name="tid" style="margin-left:50px;">

        <option value="all">Filter search by product...</option>

        <?php
        $site_split_tids = site_split_personality_tids();
        $tree = taxonomy_get_tree($vid);
        dpm($tree);
        $sorted = array();
        foreach ($tree as $termObj) {
            // Sort these bastards!
          if ($termObj->depth == 0) {
              $sorted[$termObj->tid] = $termObj;
          }
          else {}
          $wrapper = entity_metadata_wrapper('taxonomy_term', $termObj->tid);
          try {
            $business_entity = $wrapper->field_business_entity->tid->value();
          } catch (Exception $e) {
            $business_entity = NULL;
          }
          if (!in_array($business_entity, $site_split_tids)) {
            continue;
          }
          if ($termObj->depth == 0) { ?>
            $sorted[$termObj->tid] = $termObj;
            <option disabled><strong><?php echo $termObj->name; ?></strong>
            </option>

          <?php }
          elseif ($termObj->depth == 1) { ?>
            <option
              value="<?php echo $termObj->tid; ?>" <?php if ($searchQuery !== FALSE && $termObj->tid == $tid) {
              print "selected";
            } ?>>&nbsp;&nbsp;<?php echo $termObj->name; ?></option>

          <?php }
          else { ?>
            <option
              value="<?php echo $termObj->tid; ?>" <?php if ($searchQuery !== FALSE && $termObj->tid == $tid) {
              print "selected";
            } ?>>&nbsp;&nbsp;&nbsp;&nbsp;<?php echo $termObj->name; ?></option>

          <?php }
        } ?>

      </select>

    </form>

  </div>
  <!-- END: Search Form -->

  <!-- START: Breadcrumbs -->
  <div id="kb-breadcrumbs">

    <a href="/knowledge-base" id="bc-link">KB Home</a>

    <?php if ($tparents): // Loop through array of term parent objects to build breadcrumbs. ?>
      <?php foreach ($tparents as $parent): ?>
        &nbsp;&nbsp;&gt;&nbsp;&nbsp;<?php echo $parent->name; ?>
      <?php endforeach; ?>
    <?php else: ?>
      &gt;&nbsp;&nbsp;<?php print t('All'); ?>
    <?php endif; ?>

  </div>
  <!-- END: Breadcrumbs -->

  <?php if ($nid): ?>

    <!-- START: "Back to List" link -->
    <div id="back-button">
      <?php
      $params = "";
      if ($tid || $searchQuery !== FALSE) {
        $params = "?";

        if ($tid) {
          $params = $params . "&tid=" . $tid;
        }

        if ($searchQuery !== FALSE) {
          $params = $params . "&query=" . $searchQuery;
        }
      }
      ?>
      <a href="/knowledge-base<?php echo $params; ?>"><strong><span
            style="font-size:16px;">&laquo;</span>&nbsp;Back to
          List</strong></a>
    </div>
    <!-- END: "Back to List" link -->

    <!-- START: KB Article -->
    <div id="kb-article" <?php if ($node->do_not_translate) {
      print 'class="OneLinkNoTx"';
    } ?>>
      <h3 id="article-title"><?php echo $node_title; ?></h3>
      <div id="article-body"><?php echo $node_body; ?></div>
      <div id="article-author">
        <p class="info"><strong>Author: </strong><?php echo $node_author; ?></p>
        <p class="info"><strong>Creation
            Date: </strong><?php echo $node_created; ?></p>
        <p class="info"><strong>Last
            Modified: </strong><?php echo $node_changed; ?></p>
        <div style="clear:both; font-size:0; height:0;">&nbsp;</div>
      </div>
    </div>
    <!-- END: KB Article -->

    <?php drupal_set_title("Knowledge Base - " . $node_title); // Set the <title> tag in the HTML doc. ?>

  <?php else: ?>

  <script>
    $(function () {

      // Initialize the nested "accordion" menus.
      $(".accordion").accordion({
        active: false, // Collapse all menus by default.
        collapsible: true,
        heightStyle: "content" // Let the height of each menu expand automatically.
      });

      // If necessary, expand the appropriate top-level accordion menu based on the current selection.
      var elem = $("#h4-active-panel"); // Fetch "active" menu heading element to be used in the "index" function.
      positionH4 = $("#h4-active-panel").closest(".accordion").find("h4").index(elem); // Determine the index position of the "active" menu element within the containing element.
      $("#h4-active-panel").closest(".accordion").accordion("option", "active", positionH4); // Activate (or open) the menu within which is contained the active link selection.

      $("#taxonomy-menu").fadeIn(200); // Since the accordion functionality of the menu is initialized/styled on the client side, display it only once this process completes.

      <?php if ($searchQuery !== FALSE): // If a search was performed then add the search string to the link parameters. ?>

      $('#kb-article-list .views-field a[href]').each(function () {
        var href = $(this).attr('href'); // Get the current href value of view links.
        var param = "query=<?php echo $searchQuery; ?>";

        if (href.charAt(href.length - 1) === '?') //Very unlikely
          href = href + param;
        else if (href.indexOf('?') > 0)
          href = href + '&' + param;
        else
          href = href + '?' + param;

        $(this).attr('href', href);
      });

      <?php endif; ?>

    });
    </script>

  <!-- START: Taxonomy Menu -->
    <div id="taxonomy-menu">
        <h3>Browse by Category</h3>
        <div class="accordion" id="top-accordian">

<?php
$lastDepth = 0;
$tree = taxonomy_get_tree($vid);
dpm($tree);
?>
<?php foreach ($tree as $termObj): ?>
    <?php
    // echo "Term obj <pre>"; print_r($termObj); echo "</pre>"; exit;
    $wrapper = entity_metadata_wrapper('taxonomy_term', $termObj->tid);
    $step = ''; // Assign a value of "up" or "down" only if the term depth has changed accordingly.
    if ($lastDepth < $termObj->depth) {
        $step = "down";
    }
    elseif ($lastDepth > $termObj->depth) {
      $step = "up";
    }
    ?>
    <?php if ($termObj->depth == 0): // 1st level terms will act as top level accordion menu headings. ?>
        <?php if ($step == "up"): ?>
            </ul></div>
        <?php endif; ?>
        <?php $active_panel = in_array($termObj->tid, $tParentIds) ? ' id="h4-active-panel"' : ''; ?>
        <h4<?php print $active_panel; ?>>
            <?php $tcatname = str_replace(' ', '-', strtolower($termObj->name)) ;?>
            <?php echo $termObj->name; ?>
        </h4>

    <?php elseif ($termObj->depth == 1): // 2nd level terms will act as nested accordion menu links. ?>
        <?php if ($step == "down"): ?>
      <div>
      <ul>
        <?php endif; ?>
        <?php $active_menu_item = ($termObj->tid == $tid) ? ' id="active-menu-item"' : ''; ?>
        <li<?php print $active_menu_item; ?>>
				<!-- <a href="/knowledge-base/?tid=<?php //echo $termObj->tid; ?>"><?php //echo $termObj->name; ?></a> -->
				<?php
					$termname = str_replace("/","##",$termObj->name);
					$link = url('taxonomy/term/' . $termObj->tid);
				?>
				<a href="<?php echo $link; ?>"><?php echo $termObj->name; ?></a>
        </li>

    <?php endif; ?>
    <?php $lastDepth = $termObj->depth; // Capture the term depth so that change in depth can be tracked from one term to the next. ?>
<?php endforeach; ?>
<?php if ($lastDepth == 1): ?>
      </ul>
    </div>
<?php endif; ?>

  </div>

</div>
<!-- END: Taxonomy Menu -->

<!-- START: Article List View -->
<div id="kb-article-list">
  <h3>Articles: <?php echo $tname; ?></h3>

  <?php
  $view = views_get_view('knowledge_base_articles'); // Get Drupal view by name.
  $view->set_display('block_1'); // Get Drupal view display by name.
  $view->set_arguments((array) $tid); // Pass term id argument to view if available in URL.

  // Pass search string to exposed view filter if available in URL.
  if ($searchQuery !== FALSE) {
    $exposed_filters = array(
      'query' => $searchQuery
    );

    $view->exposed_input = array_merge($exposed_filters, (array) $view->exposed_input);
    $view->exposed_raw_input = array_merge($exposed_filters, (array) $view->exposed_raw_input);
    $view->exposed_data = array_merge($exposed_filters, (array) $view->exposed_data);
  }

  // Display view results.
  $output = $view->preview();
  if ($view->result) {
    print $output;
  }
  $view->destroy();
  ?>
</div>
<!-- END: Article List View -->

<?php endif; ?>

<div style="clear:both;">&nbsp;</div>

</div>
