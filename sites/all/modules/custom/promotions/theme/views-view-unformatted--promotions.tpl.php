<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 10/25/17
 * Time: 11:27 AM
 */
/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <div class="page-section-title">
    <span><?php print $title; ?></span>
  </div>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
    <?php print $row; ?>
  </div>
<?php endforeach; ?>