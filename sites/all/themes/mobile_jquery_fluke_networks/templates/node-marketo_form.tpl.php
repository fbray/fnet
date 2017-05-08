<?php
/**
 * Created by PhpStorm.
 * User: jcaratoz
 * Date: 8/18/14
 * Time: 1:58 PM
 */
?>

<div id="node-<?php print $node->nid; ?>" class="node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?> clear-block">

  <!-- START: Content -->
  <div class="content">

    <!-- banner html or image -->
    <?php
    if ($node->field_mkt_banner_html[0]['value']) { ?>

      <div style='margin:0 auto; width:auto;'>
        <?php print $node->field_mkt_banner_html[0]['value']; ?>
      </div>

    <?php } else if ($node->field_mkt_banner_img[0]['filepath']) { ?>

      <div style='margin:0 auto; width:auto;'>
        <img
          src="/<?php print $node->field_mkt_banner_img[0]['filepath']; ?>"
          alt="<?php print $node->field_mkt_banner_img[0]['data']['alt']; ?>"
          title="<?php print $node->field_mkt_banner_img[0]['data']['alt']; ?>"
          styl="width:100%;" />
      </div>

    <?php } ?><!-- END: banner html or image -->

    <div>

      <div <?php print $do_not_translate; ?>>
        <?php print $node->field_mkt_left_content[0]['value']; ?>
      </div>

      <div>
        <?php
          if ($node->field_mkt_form_title[0]['value']) { ?>
            <h2><?php print $node->field_mkt_form_title[0]['value']; ?></h2>
          <?php }

          //if ($node->field_mkt_export_ctrl[0]['value'] == "Yes" || $ip_embargoed) {
          //  print t("Download of this content is not available. Sorry for the inconvenience. Please contact your local Fluke Networks Representative if you feel you have reached this message in error.");

          //} else {
            print $marketo_form;
          //}

        ?>
        <div class="clearboth"></div>
      </div>

      <div>
        <?php print $marketo_form_footer; ?>
      </div>

      <div <?php print $do_not_translate; ?>>
        <?php if ($node->field_mkt_form_bottom[0]['value']) print $node->field_mkt_form_bottom[0]['value']; ?>
      </div>

      <div class="OneLinkNoTx">
        <?php print $bottomContent; ?>
      </div>

    </div>

  </div>
  <!-- END: Content -->

</div>


<?php
//check for any adtracker code
$adtracker = $node->field_mkt_form_adtracker[0]['value'];
//place session variable in adtracker pixel
if(strstr($adtracker, 'XXXX'))
{
  if(isset($_SESSION['fnetadpixel']))
  {
    $adtracker = str_replace('XXXX', $_SESSION['fnetadpixel'], $adtracker);
  }
  else
  {
    $randnum = rand(1000,9999);
    $adtracker = str_replace('XXXX', $randnum, $adtracker);
    $_SESSION['fnetadpixel'] = $randnum;
  }
}
print $adtracker;
?>