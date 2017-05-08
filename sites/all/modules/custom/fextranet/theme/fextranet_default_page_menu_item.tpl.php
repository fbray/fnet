<ul class="admin-list">
  <?php foreach($items as $item): ?>
    <li class="leaf">
      <a href="/<?php print $item['path']; ?>"><?php print $item['title']; ?></a>
        <div class="description"><?php print $item['description']; ?></div>
    </li>
  <?php endforeach; ?>
</ul>
