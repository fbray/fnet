<?php
/**
 * Created by PhpStorm.
 * User: ryanositis
 * Date: 1/1/18
 * Time: 8:37 PM
 */


// TODO: move $node stuff to module

?>


  <?php if ($title): ?>
    <h2><?php print $title; ?></h2>
  <?php endif; ?>

  <?php if ($assets): ?>
    	<div class='dam-asset-list'>
    <?php

    $last_type='';

    foreach ($assets as $item) {

      $link = $item['link'];
      $lang = $item['lang'];
      $type = $item['type'];

      if ($type != $last_type) {
        print '<div><h3 class="asset-list-title">' . $type . '</h2></div>';
        $last_type=$type;
      }

    	?>
    	<div class='asset-list-entry'>
    		<span class='list-entry-field'>
	    	<?php print $link ; ?>
	    </div>
<?php
    } // end foreach
    ?>
    </div>
  <?php endif; ?>

  <?php if ($boxes): ?>
      <div class='extranet-gallery'>
      <h3 class='asset-list-title'>Product Photo Gallery</h3>
    <?php
    foreach ($boxes as $link) {
      print '<div><span class="list-entry-field">' . $link . '</span></div>';
    }
    ?>
    </div>
  <?php endif; ?>

  <?php if ($fex_assets): ?>
    <h3 class='asset-list-title'>Related Items</h3>
      <div class='extranet-story-list'>
    <?php
    foreach ($fex_assets as $link) {
      print '<div><span class="list-entry-field">' . $link . '</span></div>';
    }
    ?>
    </div>
  <?php endif; ?>

  <?php if ($content): ?>
    <?php print $content; ?>
  <?php endif; ?>


<div>
&nbsp;
</div>

