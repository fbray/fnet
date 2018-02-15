<?php
/**
 * Created by PhpStorm.
 * User: mositis
 * Date: 7/26/2017
 * Time: 11:22 AM
 */
$lastDepth = 0;
$vocabulary = taxonomy_vocabulary_machine_name_load('knowledge_base');
$tree = taxonomy_get_tree($vocabulary->vid); // Get the VID for the Knowledge Base Vocabulary.
?>
<div id="taxonomy-menu">
  <h3><?php print t('Browse by Category'); ?></h3>
  <div class="accordion" id="top-accordian">
    <?php foreach ($tree as $term): ?>
      <?php
      $wrapper = entity_metadata_wrapper('taxonomy_term', $term->tid);
      $term_parents = array_reverse(taxonomy_get_parents_all($term->tid));
      // Using the $term_parents array, build a "flattened" array of just the parent term ids for easier searching.
      $term_parent_ids = array();
      if ($term_parents) {
        foreach($term_parents as $parent) {
          $term_parent_ids[] = $parent->tid;
        }
      }
      $step = ''; // Assign a value of "up" or "down" only if the term depth has changed accordingly.
      if ($lastDepth < $term->depth) {
        $step = "down";
      }
      elseif ($lastDepth > $term->depth) {
        $step = "up";
      }
      ?>
      <?php if ($term->depth == 0): // 1st level terms will act as top level accordion menu headings. ?>
        <?php if ($step == "up"): ?>
          </ul></div>
        <?php endif; ?>
        <?php $active_panel = in_array($term->tid, $term_parent_ids) ? ' id="h4-active-panel"' : ''; ?>
        <h4<?php print $active_panel; ?>>
          <?php echo $term->name; ?>
        </h4>
      <?php elseif ($term->depth == 1): // 2nd level terms will act as nested accordion menu links. ?>
        <?php if ($step == "down"): ?>
          <div>
            <ul>
        <?php endif; ?>
        <?php
        $active_menu_item = ($term->tid == $term->tid) ? ' id="active-menu-item"' : '';
        $link = url('taxonomy/term/' . $term->tid);
        ?>
        <li<?php print $active_menu_item; ?>><a href="<?php echo $link; ?>"><?php echo $term->name; ?></a></li>
      <?php endif; ?>
      <?php $lastDepth = $term->depth; // Capture the term depth so that change in depth can be tracked from one term to the next. ?>
    <?php endforeach; ?>
    <?php if ($lastDepth == 1): ?>
      </ul>
    </div>
    <?php endif; ?>
</div>
