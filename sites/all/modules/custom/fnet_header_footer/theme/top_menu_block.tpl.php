<?php
// $Id$

/**
 * @file
 * Top menu block template
 *
 */
?>

<div id="utility_nav">
  <ul>
    <?php if ($user->uid == 0): // User is anonymous. ?>
      <li style="border:0;"><a href="/contact" class="utility_link">Contact Us</a></li>
    <?php else: ?>
      <li style='border:0;'><?php print l('Log Out', 'user/logout', array('attributes' => array('class' => 'utility_link',))); ?></li>
      <li><?php print l('My Account', '/myaccount', array('attributes' => array('class' => 'utility_link',))); ?></li>
      <li><a href="/contact" class="utility_link">Contact Us</a></li>
    <?php endif; ?>
    <li><a href="javascript:selectRegion();" class="utility_link"><?php print t('Change Country/Language'); ?></a></li>
    <li><a href="/extranet" class="utility_link"><?php print t('Sales Insider'); ?></a></li>
    <?php if ($user->uid == 0): ?>
      <li><a href="/user" class="utility_link"><?php print t('Sign In'); ?></a></li>
    <?php endif; ?>
  </ul>
</div>
