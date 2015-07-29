<?php
/**
 * @file
 * Default output for a iconbox.
*/
?>
<div class="iconbox-wrapper">
  <div class="iconbox" id="iconbox-<?php print $id; ?>">
    <div class="iconbox-grid iconbox-grid-<?php print $grid; ?>"><div class="iconbox-grid-inner">
      <?php foreach($items as $item) : ?>
        <?php // Add first, last, odd, even class
          $i++;
          $col_class[0] = 'iconbox-col';
          $col_class[1] = 'iconbox-col-'.$i;
          if ($i == 1) { $col_class[2] = 'col-first';}
          if ($i == count($items)) {$col_class[2] = 'col-last';}
          if ($i % 2 == 0) {$col_class[4] = 'col-even';}
          if ($i % 2 != 0) {$col_class[4] = 'col-odd';}
        ?>

        <div <?php print drupal_attributes(array('class' => $col_class)) ?>><div class="iconbox-col-inner">
          <div class="iconbox-box <?php print $icon_position.' '.$box_padding; ?>" <?php print $box_style; ?>>
            <div class="iconbox-icon"><?php print theme('iconbox_fontawesome_icon_build', array('class' => $item['fontawesome_icon'], 'size' => $icon_size, 'looks' => $icon_looks, 'style' => $icon_style)); ?></div>
            <div class="iconbox-title-content">
              <h3 class="iconbox-title"><?php print render($item['box_title']); ?></h3>
              <div class="iconbox-content"><?php print render($item['box_content']); ?></div>
            </div>
          </div>
        </div></div>
      <?php endforeach; ?>
      <div class="clear"></div>
    </div></div>
  </div>
</div>