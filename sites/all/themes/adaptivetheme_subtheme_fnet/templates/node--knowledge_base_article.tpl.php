<?php
$searchQuery = isset($_GET["query"]) ? $_GET["query"] : false; // Get the search string from URL if available.
/*
?>
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
        $vid = taxonomy_vocabulary_machine_name_load('knowledge_base')->vid;
        $site_split_tids = site_split_personality_tids();
        $tree = taxonomy_get_tree($vid);

        foreach ($tree as $termObj) {
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

    <?php if ($tparents) { // Loop through array of term parent objects to build breadcrumbs.
      foreach ($tparents as $parent) { ?>
        &nbsp;&nbsp;&gt;&nbsp;&nbsp;<?php echo $parent->name; ?>

      <?php }
    }
    else { ?>
      &nbsp;&nbsp;&gt;&nbsp;&nbsp;All

    <?php } ?>

  </div>
  <!-- END: Breadcrumbs -->

  <?php if ($nid) { ?>

    <!-- START: "Back to List" link -->
    <div id="back-button">
     
      <a href="/knowledge-base"><strong><span
            style="font-size:16px;">&laquo;</span>&nbsp;Back to
          List</strong></a>
    </div>
    <!-- END: "Back to List" link -->

    <!-- START: KB Article -->
    <div id="kb-article" <?php if ($node->do_not_translate) {
      print 'class="OneLinkNoTx"';
    } ?>>
      <h3 id="article-title"><?php echo $node->title; ?></h3>
      <div id="article-body"><?php echo $node->body[$node->language][0]['value']; ?></div>
      <div id="article-author">
        <p class="info"><strong>Author: </strong><?php echo isset($node->field_article_author[0]["value"]) ? $node->field_article_author[0]["value"] : user_load($node->uid)->realname; ?></p>
        <p class="info"><strong>Creation
            Date: </strong><?php echo date('Y-m-d',$node->created); ?></p>
        <p class="info"><strong>Last
            Modified: </strong><?php echo date('Y-m-d',$node->created); ?></p>
        <div style="clear:both; font-size:0; height:0;">&nbsp;</div>
      </div>
    </div>
    <!-- END: KB Article -->

    <?php drupal_set_title("Knowledge Base - " . $node->title); // Set the <title> tag in the HTML doc. ?>

  <?php } ?>

<div style="clear:both;">&nbsp;</div>

</div>
<?php */ ?>
FNORD.
