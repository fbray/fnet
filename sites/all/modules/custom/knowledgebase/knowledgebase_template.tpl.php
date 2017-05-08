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
        ?>

        <?php foreach($tree as $termObj): ?>
          <?php
          $wrapper = entity_metadata_wrapper('taxonomy_term', $termObj->tid);
          try {
            $business_entity = $wrapper->field_business_entity->tid->value();
          } catch (Exception $e) {
            $business_entity = NULL;
          }
          if (!in_array($business_entity, $site_split_tids)) {
            continue;
          }
          ?>
          <?php if ($termObj->depth == 0): ?>
            <option disabled><strong><?php echo $termObj->name; ?></strong>
            </option>

          <?php elseif ($termObj->depth == 1): ?>
            <option
              value="<?php echo $termObj->tid; ?>" <?php if ($searchQuery !== FALSE && $termObj->tid == $tid) {
              print "selected";
            } ?>>&nbsp;&nbsp;<?php echo $termObj->name; ?></option>

          <?php else: ?>
            <option
              value="<?php echo $termObj->tid; ?>" <?php if ($searchQuery !== FALSE && $termObj->tid == $tid) {
              print "selected";
            } ?>>&nbsp;&nbsp;&nbsp;&nbsp;<?php echo $termObj->name; ?></option>

          <?php endif; ?>
        <?php endforeach; ?>

      </select>

    </form>

  </div>
  <!-- END: Search Form -->

  <!-- START: Breadcrumbs -->
  <div id="kb-breadcrumbs">

    <a href="/knowledge-base" id="bc-link">KB Home</a>
    <?php dpm($tparents); ?>
    <?php if ($tparents): // Loop through array of term parent objects to build breadcrumbs. ?>
      <?php foreach ($tparents as $parent): ?>
        &nbsp;&nbsp;&gt;&nbsp;&nbsp;<?php print $parent->name; ?>
      <?php endforeach; ?>
    <?php else: ?>
      &nbsp;&nbsp;&gt;&nbsp;&nbsp;All
    <?php endif; ?>

  </div>
  <!-- END: Breadcrumbs -->


  <?php if (isset($nid)): // If there is a NID to display ?>

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
    <div id="kb-article" <?php if ($node->do_not_translate): ?>
      class="OneLinkNoTx"
    <?php endif; ?>>
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

  <?php else: // If there is no NID to display. ?>

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
      positionH4 = elem.closest(".accordion").find("h4").index(elem); // Determine the index position of the "active" menu element within the containing element.
      elem.closest(".accordion").accordion("option", "active", positionH4); // Activate (or open) the menu within which is contained the active link selection.

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
    });
    </script>

  <!-- START: Taxonomy Menu -->
  <div id="taxonomy-menu" style="display:none;">

    <h3>Browse by Category</h3>

    <div class="accordion" id="top-accordian">
    <?php
      $tree = taxonomy_get_tree($vid);
      $lastDepth = 0;

      foreach ($tree as $termObj) {
        $wrapper = entity_metadata_wrapper('taxonomy_term', $termObj->tid);
        try {
          $business_entity = $wrapper->field_business_entity->tid->value();
        }
        catch (Exception $e) {
          $business_entity = NULL;
        }
        if (!in_array($business_entity, $site_split_tids)) {
          continue;
        }

        $step = ""; // Assign a value of "up" or "down" only if the term depth has changed accordingly.
        if ($lastDepth < $termObj->depth) {
          $step = "down";
        }
        elseif ($lastDepth > $termObj->depth) {
          $step = "up";
        }

        if ($termObj->depth == 0) { // 1st level terms will act as top level accordion menu headings.
          if ($step == "up") {
            print "</ul></div>";
          }
          if (in_array($termObj->tid, $tParentIds)) {
            print '<h4 id="h4-active-panel">';
          }
          else {
            print '<h4>';
          }
          print $termObj->name . '</h4>';
        }
        elseif ($termObj->depth == 1) { // 2nd level terms will act as nested accordion menu links.
          if ($step == "down") {
            print '<div><ul>';
          }
          if ($termObj->tid == $tid) {
            print '<li id="active-menu-item"><a
            href="/knowledge-base/?tid=' . $termObj->tid . '">' . $termObj->name . '</a></li>';
          }
          $lastDepth = $termObj->depth; // Capture the term depth so that change in depth can be tracked from one term to the next.
        }
      } // End of foreach term.
    if ($lastDepth == 1) { // Close up any open elements.
      print "</ul></div>";
    }
    ?>
  </div>
  <?php endif; ?>
</div>
<!-- END: Taxonomy Menu -->

<!-- START: Article List View -->
<div id="kb-article-list">
  <h3>Articles: <?php print $tname; ?></h3>

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