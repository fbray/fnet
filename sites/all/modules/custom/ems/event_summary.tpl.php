<?php
// $Id$
/**
 * @file Theme event summary information with items from both event node and event_occurrence node.
 */
?>
<div id="event-summary">
  <div class="event-title"><?php print $event->title ?></div>
  <div class="event-occurrence-title"><?php print $occurrence->title ?></div>
  <div
    class="event-intro"><?php print $event->field_event_intro[0]['value'] ?></div>
</div>