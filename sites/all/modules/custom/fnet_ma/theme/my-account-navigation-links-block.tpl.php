<?php
/**
 * @file
 * This file is used to theme the block that displays My Account related links in a block on the left sidebar.
 */

global $base_url, $user;
$user_id = $user->uid;
$has_gold_role = fnet_ma_user_has_gold_role();
?>
<div id="content_inner_left_nav">
    <ul>
      <li class="left_nav_item">
        <?php print l(t('My Account Home'), "myaccount", array(
          'html' => TRUE,
          'attributes' => array('class' => array('link'))
        )); ?>
      </li>

      <li class="left_nav_item">
        <?php print l(t('Registered Products'), "myaccount/registered-products", array(
          'html' => TRUE,
          'attributes' => array('class' => array('link'))
        )); ?>
      </li>

      <li class="left_nav_item">
        <?php print l(t('Register a Product'), "myaccount/register-products-step-one", array(
          'html' => TRUE,
          'attributes' => array('class' => array('link'))
        )); ?>
      </li>

      <li class="left_nav_item">
        <?php print l(t('Support Incidents'), "myaccount/all-support-incidents", array(
          'html' => TRUE,
          'attributes' => array('class' => array('link'))
        )); ?>
      </li>

      <li class="left_nav_item">
        <?php print l(t('Downloads And Updates'), "support/downloads", array(
          'html' => TRUE,
          'attributes' => array('class' => array('link'))
        )); ?>
      </li>

      <?php if (!$has_gold_role) : ?>
        <li class="left_nav_item" id='add-gold-contracts-navigation-link'>
          <?php print l(t('Add Gold Membership #'), 'myaccount/' . $user->uid . '/edit/profile', array(
            'fragment' => 'gold-support-credentials-section',
            'external' => FALSE
          )); ?>
        </li>
      <?php endif ?>
      <?php
      if ($has_gold_role) :
        ?>
        <li class="left_nav_item">
          <?php print l(t('Gold Support Contact Numbers'), 'myaccount/gold-support-contact-numbers', array(
            'html' => TRUE,
            'attributes' => array('class' => array('link'))
          )); ?>
        </li>

        <li class="left_nav_item">
          <?php print l(t('Using Your Gold Benefits'), 'gold/benefits', array(
            'html' => TRUE,
            'attributes' => array(
              'class' => array('link'),
              'target' => '_blank'
            )
          )); ?>
        </li>

        <li class="left_nav_item">
          <?php print l(t('Gold Contracts'), "myaccount/gold-contracts", array(
            'html' => TRUE,
            'attributes' => array('class' => array('link'))
          )); ?>
        </li>

      <?php endif ?>
      <li class="left_nav_item">
        <?php print l(t('Online Training'), "support/training", array(
          'html' => TRUE,
          'attributes' => array(
            'class' => array('link'),
            'target' => '_blank'
          )
        )); ?>
      </li>

      <li class="left_nav_item">
        <?php print l(t('Edit My Password'), "myaccount/" . $user_id . "/edit", array(
          'html' => TRUE,
          'attributes' => array('class' => array('link'))
        )); ?>
      </li>

      <li class="left_nav_item">
        <?php print l(t('Edit My Profile'), "myaccount/" . $user_id . "/edit/profile", array(
          'html' => TRUE,
          'attributes' => array('class' => array('link'))
        )); ?>
      </li>

    </ul>
</div>