<?php
// $Id$

/**
 * @file
 * Digital asset system main menu
 *
 */
?>
<h2>Digital Asset Management System Menu</h2>
<br/>
<?php
$rows = array();
foreach ($menu_items as $description => $link) {
  $rows[] = array($link);
}
print theme('table', array(
  'header' => array('Action'),
  'rows' => $rows,
  'attributes' => array('style' => 'width: 300px;'),
)); ?>

<br/>
