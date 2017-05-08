<?php
/**
 * @file
 * Adaptivetheme implementation to display a single Drupal page while offline.
 *
 * Not all variables are mirrored from html.tpl.php and page.tpl.php, only those
 * required to deliver a valid html page with branding and site offline messages.
 * $polyfills is included to support HTML5 in IE8 and below.
 *
 * Adaptivetheme variables:
 * - $is_mobile: Mixed, requires the Mobile Detect or Browscap module to return
 *   TRUE for mobile.  Note that tablets are also considered mobile devices.
 *   Returns NULL if the feature could not be detected.
 * - $is_tablet: Mixed, requires the Mobile Detect to return TRUE for tablets.
 *   Returns NULL if the feature could not be detected.
 *
 * @see template_preprocess()
 * @see template_preprocess_maintenance_page()
 * @see adaptivetheme_preprocess()
 * @see adaptivetheme_preprocess_maintenance_page()
 */
?>
<!DOCTYPE html>
<html lang="<?php print $language->language; ?>" dir="<?php print $language->dir; ?>">
<head>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $polyfills; ?>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <section id="main-content" role="main">
    <img src="/sites/flukenetworks.com/files/FNET_logo.png" alt="Fluke Networks" />
    <?php if ($title): ?>
      <h1 id="page-title"><?php print $title; ?></h1>
    <?php endif; ?>
    <?php print $messages; ?>
    <div id="content">
      <?php print $content; ?>
    </div>
  </section>
</body>
</html>
