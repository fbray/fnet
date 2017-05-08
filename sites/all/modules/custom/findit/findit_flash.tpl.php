<?php
// $Id$

/**
 * @file
 * Theme template for findit flash objects
 *
 */
?>
<div>
  <object type="application/x-shockwave-flash"
          data="<?php echo $swf_file ?>"
          width="865" height="750">
    <param name="movie" value="<?php echo $swf_file ?>"/>
    <param name="quality" value="high"/>
  </object>

</div>
