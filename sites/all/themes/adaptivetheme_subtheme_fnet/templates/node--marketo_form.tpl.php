<div id="mkto-content-main" class="content clear-block">
  <div id="mkto-content-left">
    <?php
    print "<div $do_not_translate>";
    print $node->field_left_content[LANGUAGE_NONE][0]['value'];
    print "</div>";
    print $marketo_form_footer; ?>
    <?php if ($bottomContent): ?>
      <div style="clear:both;">&nbsp;</div>
      <div class="OneLinkNoTx">
        <?php print $bottomContent; ?>
      </div>
    <?php endif; ?>
  </div>
  <div id="mkto-content-right">
    <div style='height:<?php print $iFrameHeight; ?>'>
      <?php if (isset($node->field_marketo_form_title[LANGUAGE_NONE][0]['value'])): ?>
        <div <?php print $do_not_translate; ?>>
          <div style="font-weight:bold;font-size:14px;padding-left:10px;margin-bottom:5px;">
            <?php print $node->field_marketo_form_title[LANGUAGE_NONE][0]['value']; ?></div>
          <div style="clear:both;">&nbsp;</div>
        </div>
      <?php endif; ?>
      
      <?php
      $showShareButton = TRUE;
      if ($node->field_export_control[LANGUAGE_NONE][0]['value'] == "1") {
        if ($ip_embargoed) {
          $showShareButton = FALSE;
          print t("Download of this content is not available. Sorry for the inconvenience. Please contact your local Fluke Networks Representative if you feel you have reached this message in error.");
        }
        else {
          print $marketo_form;
        }
      }
      else {
        print $marketo_form;
      }
      ?>
    </div>
    <?php if ($showShareButton): ?>
      <?php if (isset($node->field_enable_share_buttons[LANGUAGE_NONE][0]['value'])): ?>
        <?php if ($node->field_enable_share_buttons[LANGUAGE_NONE][0]['value'] == "1"): ?>
          <div style="margin-top:0px;padding-left:35px;">
            <span class='st_sharethis' displayText='ShareThis'></span>
            <span class='st_facebook' displayText='&nbsp;'></span>
            <span class='st_twitter' displayText='&nbsp;'></span>
            <span class='st_linkedin' displayText='&nbsp;'></span>
            <span class='st_email' displayText='&nbsp;'></span>
            <script type="text/javascript">var switchTo5x = false;</script>
            <script type="text/javascript" src="http://w.sharethis.com/button/buttons.js"></script>
            <script type="text/javascript">stLight.options({publisher: '396ae8ac-55d4-49d8-a774-f95d0a794c67'});</script>
          </div>
        <?php endif; ?>
      <?php endif; ?>

    <?php endif; ?>
    <?php if (isset($node->field_form_bottom[LANGUAGE_NONE][0]['value']) && $node->field_form_bottom[LANGUAGE_NONE][0]['value']): ?>
      <div <?php print $do_not_translate; ?>>
        <div style="margin-top:100px;padding-left:5px;">
          <?php print $node->field_form_bottom[LANGUAGE_NONE][0]['value']; ?>
        </div>
      </div>
      <div style="clear:both;">&nbsp;</div>
    <?php endif; ?>
  </div>
</div>
