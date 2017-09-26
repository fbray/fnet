<?php
// $Id: event_summary.tpl.php 26 2015-03-31 22:37:44Z sogden1 $
/**
 * @file Theme event summary information with items from both event node and event_occurrence node.
 */
?>
<div id="event-summary">
  <div class="event-title"><?php print $event->title ?></div>
  <div class="event-occurrence-title"><?php print $occurrence->title ?></div>
  <div
    class="event-intro"><?php print $intro; ?></div>
</div>