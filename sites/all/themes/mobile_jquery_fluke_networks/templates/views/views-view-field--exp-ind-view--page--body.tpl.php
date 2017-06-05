<?php
// $Id: views-view-field.tpl.php,v 1.1 2008/05/16 22:22:32 merlinofchaos Exp $
/**
 * This template is used to print a single field in a view. It is not
 * actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the
 * template is perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
$fid = $row->{$view->field['field_exp_ind_thumbnail_fid']->field_alias};
if ($fid){
  $filepath = db_result(db_query("SELECT filepath FROM {files} WHERE fid=%d", $fid));
  ?>
  <div>
    <img style="margin-top:15px; width:100%; max-width:300px;" src='/<?php print $filepath; ?>'>
  </div>
<?php } ?>

<div><?php print $output; ?></div>