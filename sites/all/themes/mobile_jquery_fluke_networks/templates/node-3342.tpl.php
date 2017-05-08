<?php
// $Id: node.tpl.php,v 1.5 2007/10/11 09:51:29 goba Exp $
?>
<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> clear-block">

  <div class="content">

    <h1><?php print $node->title ?></h1>

    <?php if ($submitted): ?>
      <span class="submitted"><?php print $submitted; ?></span>
    <?php endif; ?>

    <div>
      <?php print $content ?>
    </div>

    <hr />

    <div>

      <?php

      //display industry
      $industryCount = 1;
      $industryList  = views_get_view_result('industry_list');

      foreach ($industryList as $industry) { ?>

        <h2><a href="/<?php print drupal_lookup_path('alias',"node/".$industry->nid); ?>"><?php print $industry->node_title; ?></a></h2>

        <?php
        //display family
        $familyList = views_get_view('industry_family');
        $familyList->set_items_per_page(0);
        $familyList->set_arguments(array($industry->nid));
        $familyList->execute();
        $familyResult = $familyList->result;

        foreach ($familyResult as $family) {

          $familyBookmark = str_replace(" ", "_", $family->node_title);
          $familyBookmark = str_replace(",", "", $familyBookmark);
          ?>

          <div data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">

            <h3><?php print $family->node_title; ?></h3>

            <ul>

              <?php
              $productsList = views_get_view('industry_family_products');
              $productsList->set_items_per_page(0);

              // Fetch regLang value to pass as argument to 'industry_family_products' view
              $region = strtolower($_COOKIE["regLang"]);
              if ($region == "") $region = "en-us";

              $productsList->set_arguments(array($family->nid, $region));
              $productsList->execute();
              $productsListResult = $productsList->result;

              foreach ($productsListResult as $product) { ?>

                <li><a href="/<?php print drupal_lookup_path('alias', "node/" . $product->nid); ?>"><?php print $product->node_title; ?></a></li>

              <?php } ?>

            </ul>

            <?php
            $linkAddress = drupal_lookup_path('alias','node/' . $industry->nid).'?td=products#'.$familyBookmark;
            ?>

            <!-- Link to All Industries  -->
            <a
              href="/<?php print $linkAddress; ?>"
              target="_self"
              data-role="button"
              class="button-yellow family-products-link">
              Learn More
            </a>

          </div>

        <?php } ?>

        <hr />

      <?php } ?>

    </div>

  </div>
