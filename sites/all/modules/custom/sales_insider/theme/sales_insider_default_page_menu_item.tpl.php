<?php
/**
 * Created by PhpStorm.
 * User: rositis
 * Date: 1/4/18
 * Time: 3:10 PM
 */
?>
<ul class="admin-list">
  <?php foreach($items as $item): ?>
    <li class="leaf">
      <a href="/<?php print $item['path']; ?>"><?php print $item['title']; ?></a>
        <div class="description"><?php print $item['description']; ?></div>
    </li>
  <?php endforeach; ?>
</ul>