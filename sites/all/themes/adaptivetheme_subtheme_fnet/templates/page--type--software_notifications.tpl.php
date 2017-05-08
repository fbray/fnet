<?php
$content = drupal_render($page['content']);
$dom = new simple_html_dom($content);
$form = $dom->find('form');
if ($form) {
  $content = $form[0];
}
else {
  $content = '';
}
?>
<!DOCTYPE html>
<html>
<head>
  <title><?php echo $node->title; ?></title>
  <meta name="latest-version"
        content="<?php echo $node->field_latest_version[LANGUAGE_NONE][0]['value']; ?>">
  <meta name="version-location"
        content="<?php echo $node->field_version_location[LANGUAGE_NONE][0]['url']; ?>">
</head>
<body>
<?php if ($content) {
  print '<div>' . $content . '</div>';
} ?>
<div id="release-notes">
  <?php echo $node->field_release_notes[LANGUAGE_NONE][0]["value"]; ?>
</div>
</body>
</html>