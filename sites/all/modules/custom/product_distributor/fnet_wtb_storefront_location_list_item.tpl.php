<li class="<?php print $data['classes'] ?>">
  <h4><?php print $data['name'] ?></h4>

  <div class="buy-online-wrapper">
    <?php if($data['is_online']): ?>
    <div class="btn_94w" style="display: block;">
      <a target="_blank" href="<?php print $data['buy_online_url'] ?>">Buy Online</a>
    </div>
    <?php endif; ?>
  </div>

  <div class="dist-address">
    <?php print $data['address'] ?>

    <div class="dist-phone-other">
      <?php if (trim($data['toll_free_phone']) != ''): ?>
      Toll-Free: <?php print $data['toll_free_phone'] ?>
      <br/>
      <?php endif; ?>
      
      <?php if (trim($data['phone']) != ''): ?>
      Phone: <?php print $data['phone'] ?>
      <br/>
      <?php endif; ?>
      
      <?php if (trim($data['fax']) != ''): ?>
      Fax: <?php print $data['fax'] ?>
      <br/>
      <?php endif; ?>
      
      <?php if (trim($data['email']) != ''): ?>
      Email: <a href="mailto:<?php print $data['email'] ?>"><?php print $data['email'] ?></a>
      <br/>
      <?php endif; ?>
      
      <?php if (trim($data['url']) != ''): ?>
      Web: <a href="<?php print $data['url'] ?>" target="_blank"><?php print str_replace('http://', '', $data['url']) ?></a>
      <br/>
      <?php endif; ?>
      
      <?php if (isset($_GET['postal']) && isset($data['dist'])): ?>
      <div class="dist-wrapper">
        Distance: <?php print $data['dist'] ?> <?php print
        $data['dist_unit'] ?>
      </div>
      <?php endif; ?>
    </div>
    
  </div>
</li>
