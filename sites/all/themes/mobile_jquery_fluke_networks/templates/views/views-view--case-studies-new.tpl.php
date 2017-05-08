<?php
/**
 * @file views-view.tpl.php
 * Main view template
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 * - $admin_links: A rendered list of administrative links
 * - $admin_links_raw: A list of administrative links suitable for theme('links')
 *
 * @ingroup views_templates
 */
?>

    <div class="<?php print $classes; ?>">
        <?php if ($admin_links): ?>
            <div class="views-admin-links views-hide">
                <?php print $admin_links; ?>
            </div>
        <?php endif; ?>
        <?php if ($header): ?>
            <div class="view-header">
                <?php print $header; ?>
            </div>
        <?php endif; ?>

        <?php if ($exposed): ?>
            <div class="view-filters">
                <?php print $exposed; ?>
            </div>
        <?php endif; ?>

        <?php if ($attachment_before): ?>
            <div class="attachment attachment-before">
                <?php print $attachment_before; ?>
            </div>
        <?php endif; ?>

        <h1>Case Studies</h1>

        <div class="view-content">
            <?php

            // Fetch all terms from the "Industries" vocabulary (referenced by the id number).
            $vocabTerms;

            $vocabs = taxonomy_get_vocabularies(NULL);
            foreach ($vocabs as $vocab_object) {
                if ($vocab_object->name == "Industries") {
                    $vocabTerms = taxonomy_get_tree($vocab_object->vid);
                }
            }

            // Pulling the term names up to top of new array for easier searching.
            $vocabTermNames = array();
            foreach ($vocabTerms as $vocabTermObj){
                $vocabTermNames[] = $vocabTermObj->name;
            }

            // Loop through each term in the vocabulary to build
            // the view of nodes grouped by term.
            $needBackToTop = false;
            foreach ($vocabTerms as $termObj) {
                $tid = $termObj->tid;
                $tname = $termObj->name;

                $termHeadingHasBeenPrinted = false;

                // Loop through each node in the view to see if it has
                // been tagged with the current term.
                foreach ($view->result as $nodeRecord) {
                    $node = node_load($nodeRecord->nid);
                    $nodeTerms = taxonomy_node_get_terms($node);

                    // Pulling the term names up to top of new array for easier searching.
                    $nodeTermNames = array();
                    foreach ($nodeTerms as $nodeTermObj){
                        $nodeTermNames[] = $nodeTermObj->name;
                    }

                    if (in_array($tname, $nodeTermNames)){

                        // Print header only if a node has been found. Then only print once.
                        if (!$termHeadingHasBeenPrinted){ ?>

                            <div data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">

                                <h3 class="section-header"><?php print $tname; ?></h3>

                                <table width="100%" class="ui-responsive table-stroke table-stripe">

                            <?php
                            $termHeadingHasBeenPrinted = true;
                        } ?>

                        <tr>
                          <td>
                            <p>
                              <a href='/<?php print $node->path; ?>' target='_blank'><?php print $nodeRecord->node_title; ?></a><br />
                              <?php print strip_tags($nodeRecord->node_data_field_expertise_intro_field_expertise_intro_value); ?>
                            </p>
                          </td>
                        </tr>

                    <?php }

                }

                if ($termHeadingHasBeenPrinted){ ?>
                    </table>
                  </div>
                <?php }

            }

            // Loop through each node in the view to see if it has
            // no associated tags from the Industries vocabulary.
            $otherHeadingHasBeenPrinted = false;
            foreach ($view->result as $nodeRecord) {
                $node = node_load($nodeRecord->nid);
                $nodeTerms = taxonomy_node_get_terms($node);

                // Pulling the term names up to top of new array for easier searching.
                $nodeTermNames = array();
                foreach ($nodeTerms as $nodeTermObj){
                    $nodeTermNames[] = $nodeTermObj->name;
                }

                $intersect = array_intersect($nodeTermNames, $vocabTermNames);

                if (count($intersect) == 0){

                    // Print header only if a node has been found. Then only print once.
                    if (!$otherHeadingHasBeenPrinted){ ?>

                        <div data-role="collapsible" data-theme="f" data-content-theme="f" data-collapsed-icon="arrow-r" data-expanded-icon="arrow-d" data-iconpos="right" data-corners="false">

                            <h3 class="section-header">Other</h3>

                            <table width="100%" class="ui-responsive table-stroke table-stripe">

                        <?php $otherHeadingHasBeenPrinted = true;
                    } ?>

                          <tr>
                            <td>
                              <p>
                                <a href='/<?php print $node->path; ?>' target='_blank'><?php print $nodeRecord->node_title; ?></a><br />
                                <?php print strip_tags($nodeRecord->node_data_field_expertise_intro_field_expertise_intro_value); ?>
                              </p>
                            </td>
                          </tr>

                <?php  }
            }

            if ($otherHeadingHasBeenPrinted){ ?>
                  </table>
                </div>
            <?php } ?>

        </div>

        <?php if ($pager): ?>
            <?php print $pager; ?>
        <?php endif; ?>

        <?php if ($attachment_after): ?>
            <div class="attachment attachment-after">
                <?php print $attachment_after; ?>
            </div>
        <?php endif; ?>

        <?php if ($more): ?>
            <?php print $more; ?>
        <?php endif; ?>

        <?php if ($footer): ?>
            <div class="view-footer">
                <?php print $footer; ?>
            </div>
        <?php endif; ?>

        <?php if ($feed_icon): ?>
            <div class="feed-icon">
                <?php print $feed_icon; ?>
            </div>
        <?php endif; ?>

    </div> <?php /* class view */ ?>