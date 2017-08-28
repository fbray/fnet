<div class="mkto-content-main" class="content clear-block">
  <div id="mkt-prod-banner">
  	<?php if($node->field_fnet_mkto_banner_img[LANGUAGE_NONE][0]['uri']){ ?>
  		<img src="<?php print file_create_url($node->field_fnet_mkto_banner_img[LANGUAGE_NONE][0]['uri']); ?>" />
  	<?php }else{ ?>
  		<?php print $node->field_fnet_mkto_banner_html[LANGUAGE_NONE][0]['value']; ?>
  	<?php } ?>
  </div>
  <div id="mkto-content">
    <div id="mkt-prod-details">
      <div id="mkt-prod-title" class="t1-title">
        <?php
          print $node->title;
        ?>
      </div>
		<?php if(isset($node->field_fnet_mkto_prod_img_left)){ ?>
      <div id="mkt-prod-img-left">
        <img src="<?php print file_create_url($node->field_fnet_mkto_prod_img_left[LANGUAGE_NONE][0]['uri']); ?>" />
      </div>
		<?php }else{ ?>
			 <div id="mkt-prod-img-right">
        <img src="<?php print file_create_url($node->field_fnet_mkto_prod_img_right[LANGUAGE_NONE][0]['uri']); ?>" />
      </div>
		<?php } ?>
      <div id="mkt-prod-content">
        <?php
          print $node->field_fnet_mkto_main_content[LANGUAGE_NONE][0]['value'];
        ?>
      </div> 
    </div>
    <div id="mkto-content-main-form">
      <div id="mkto-form-header">
        <?php print $node->field_fnet_mkto_title[LANGUAGE_NONE][0]['value']; ?>
      </div>
      <div id="mkto-form">
        <?php print $fnet_marketo_form; ?>
      </div>
    </div>
    <div id="mkt-more-links-content">
      <?php     
      for ($i=0; $i<count($node->field_fnet_mkto_add_links[LANGUAGE_NONE]); $i++) { 
      ?>
        <div id="mkt-more-links">
          <a href="<?php echo $node->field_fnet_mkto_add_links[LANGUAGE_NONE][$i]['display_url'] ?>"><?php echo $node->field_fnet_mkto_add_links[LANGUAGE_NONE][$i]['title']; ?></a>
        </div>
      <?php
        }
      ?>
    </div>
    <div id="mkt-contact-info">
      <?php print $node->field_fnet_mkto_form_btm_html[LANGUAGE_NONE][0]['value'] ?>
    </div> 
  </div>
</div>