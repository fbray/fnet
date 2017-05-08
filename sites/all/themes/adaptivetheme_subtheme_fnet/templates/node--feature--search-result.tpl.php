<?php
/*
 * $content contains the relevant fields
 * use dpm($content) to see what's in there!
 */
$parent_product = $content['field_feature_product'][0];
unset($content['field_feature_product']);
/* Turn on for testing
if (module_exists('devel')) {
  dpm($content);
  dpm($parent_product);
}
*/
?>
<?php print render($title_prefix); ?>
  <h3 class="title"<?php print $title_attributes; ?>>
    <a href="/<?php print drupal_get_path_alias($parent_product['#href']); ?>"><?php print $parent_product['#title']; ?></a></h3>
<?php print render($title_suffix); ?>
<?php print render($content); ?>