  -----------------------------------------------------------------------------------------
                                    ABOUT THE MODULE
  -----------------------------------------------------------------------------------------
  This is a simple module that adds custom classes per node
  
  
  
  -----------------------------------------------------------------------------------------
                                    HOW TO USE NODE CLASS - Drupal 6 Only
  -----------------------------------------------------------------------------------------
  Open your node.tpl.php in your theme and add the following :
  <?php print node_class($node) ?>
  
  So your whole tag will look like :
  <div id="node-<?php print $node->nid; ?>" class="<?php print node_class($node) ?> 
  node<?php if ($sticky) { print ' sticky'; } ?><?php if (!$status) { print ' node-unpublished'; } ?>">