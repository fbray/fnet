<?php
// $Id$

/**
 * @file
 * Theme template for FindIt downloads
 *
 */
?>
  <h2>Digital Library Fulfillment Center</h2>
<?php if ($document_url): ?>
  <p>The file you requested, <?php echo $document_name; ?>, is ready.</p>
  <p>If download doesn't start
    automatically <?php echo l('Click here', $document_url); ?></p>
  <script>
    ga('send', 'event', {
      'eventCategory': 'findit',
      'eventAction': 'download',
      'eventLabel': '<?php echo $document_name; ?>'
    });
    setTimeout('top.location = "<?php echo $document_url;?>"', 3000);
  </script>
<?php endif; ?>