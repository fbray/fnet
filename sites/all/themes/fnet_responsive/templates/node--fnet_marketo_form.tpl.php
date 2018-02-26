<?php

  global $language;
  $currlang = $language->language;
?>

<div class="mkto-content-main" class="content clear-block">
  <div id="mkt-prod-banner">
    <?php if(!empty($node->field_fnet_mkto_banner_img[$currlang])):
        print render($content['field_fnet_mkto_banner_img']);
      else:
        print render($content['field_fnet_mkto_banner_html']);
      endif;
    ?>
  </div>
  <div id="mkto-content">
    <div id="mkt-prod-details">
      <div id="mkt-prod-title" class="t1-title">
        <?php
          $disp_title = field_view_field('node', $node, 'field_fnet_mkto_disp_title', array('label' => 'hidden'));
          print render($disp_title);
        ?>
      </div>
  <?php if(render($content['field_fnet_mkto_prod_img_left'])): ?>
      <div id="mkt-prod-img-left">
        <?php
          print render($content['field_fnet_mkto_prod_img_left']);
        ?>
      </div>
  <?php elseif(render($content['field_fnet_mkto_prod_img_right'])): ?>
   <div id="mkt-prod-img-right">
        <?php
          print render($content['field_fnet_mkto_prod_img_right']);
        ?>
      </div>
  <?php endif; ?>
      <div id="mkt-prod-content">
        <?php print render($content['field_fnet_mkto_main_content']); ?>
      </div>
    </div>
    <div id="mkto-content-main-form">
      <div id="mkto-form-header">
        <?php print render($content['field_fnet_mkto_title']); ?>
      </div>
      <div id="mkto-form">
        <?php
          if ($ip_embargoed) {
            print t("Download of this content is not available. Sorry for the inconvenience. Please contact your local Fluke Networks Representative if you feel you have reached this message in error.");
          }
          else {
        ?>
        <form id="mktoForm_<?php print $form_number ?>"></form>
        <!-- / Call DTP and load form \ -->
        <script>
        function receiveFormDTO(domain,dataSrc,fieldsProp){
          var DTO = new SimpleDTO({
            debug: true,
            domain: domain,
            dataSrc: dataSrc,
            mode: "receive",
            cb: function(instance){
              var mktoFields = DTO.getGlobal()[fieldsProp];
              DTO.cleanup();
              MktoForms2.whenReady(function(form) {
                form.setValuesCoerced(mktoFields);
              });
            }
          });
        }
        receiveFormDTO("flukenetworks.com", "http://info.flukenetworks.com/Form-Prefill-Guided-Landing-Page.html", "mktoPreFillFields");

        MktoForms2.loadForm("//app-sjo.marketo.com", "<?php print $marketo_key ?>", <?php print $form_number ?>, function(form) {
          form.onSuccess(function(values, followUpUrl) {
            location.href = "<?php print $follow_up_url ?>";
            return false;
          });
        });
        </script>

        <?php
          }
        ?>
      </div>
    </div>
    <div id="mkt-more-links-content">
      <?php print render($content['field_fnet_mkto_add_links']); ?>
    </div>
    <div id="mkt-contact-info">
      <?php
        $btm_html = $content['field_fnet_mkto_form_btm_html'];
        print render($btm_html);
      ?>
    </div>
  </div>
</div>
