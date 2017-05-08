<?php
// $Id:  $
/**
 * @file
 * promotions-home page template.
 *
 */

?>
<div id="promotions-page-content">
  <div id="promotions-header">
    <img src='/sites/flukenetworks.com/files/images/Special_Offer_Banner.jpg'
         style='width:100%;'/>
  </div>
  <?php foreach ($variables['page_section'] as $section): ?>
    <div class="page-section-title">
      <span><?php print $section['title']; ?></span>
    </div>
    <?php if (isset($section['promotions'])): ?>
      <?php foreach ($section['promotions'] as $promotion): ?>
        <div class="promotion-instance">
          <div class="promotion-thumbnail">
            <a href="<?php print $promotion['link']; ?>" target="_blank"><img width="79" height="81" src="<?php print $promotion['image_uri']; ?>"></a>
          </div>
          <div class="promotion-details">
            <h4 class="promotion-title"><?php print $promotion['title']; ?></h4>

            <div class="promotion-description">
                <?php print $promotion['intro']; ?>
            </div>
          </div>
         <div class="promotion-button">
            <div class="promotion-date">
                <?php print $promotion['date']; ?>
            </div>
            <div class="btn_143w">
              <a href="<?php print $promotion['link']; ?>" target="_blank">Get
              Details</a>
            </div>
          </div>
          <div style="clear:both;"></div>
        </div>
      <?php endforeach; ?>    
    <?php else:
			switch($section['title']){
				case 'Purchase Promotions':
					print t("There are no active Promotions at this time. Check back later.");
				break;
				case 'Software Trials':
					print t("There are no active Software Trials at this time. Check back later.");
				break;
				case 'Hardware Trials':
					print t("There are no active Hardware Trials at this time. Check back later.");
				break;				
			}
		?>
    <?php endif; ?>
  <?php endforeach; ?>
 </div>
