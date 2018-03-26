<?php
if (preg_match('%/truviewlive/contact-us%sim', $data['buy_online_url'])) {
  $button_text = 'Contact Us';
}
else {
  $button_text = 'Buy Online';
}
?>
<li class="<?php print $data['classes'] ?>">
    <h4><?php print $data['name'] ?></h4>

    <div class="buy-online-wrapper">
        <div class="btn_94w" id="edit-submit" style="display: block;">
            <a target="_blank"
               href="<?php print $data['buy_online_url'] ?>"><?php print $button_text; ?></a>
        </div>
    </div>

    <div class="dist-address">

      <?php if (trim($data['toll_free_phone']) != ''): ?>
          Toll-Free: <?php print $data['toll_free_phone'] ?>
          <br/>
      <?php endif; ?>

    </div>
</li>
