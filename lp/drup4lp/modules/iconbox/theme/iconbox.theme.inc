<?php
/**
 * @file
 * Theming functions for the iconbox module.
 * 
 * Preprocessor functions fill variables for templates and helper
 * functions to make theming easier.
 */

/**
 * Template preprocess handler for 'iconbox_content' theme.
 */
function template_preprocess_iconbox_content(&$vars) {
  // Each iconbox instance gets a unique id
  $iconbox_id = &drupal_static('iconbox_id', 0);
  $vars['id'] = ++$iconbox_id;
  $vars['i']  = 0;

  $vars['icon_size_custom']	= NULL;
  $vars['icon_color']		= NULL;
  $vars['icon_bg_color']	= NULL;
  $vars['icon_border']		= NULL;
  $vars['icon_border_color']= NULL;
  $vars['icon_bg_border']	= NULL;
  $vars['box_bg_color']		= NULL;
  $vars['box_border_color']	= NULL;
  $vars['box_border']		= NULL;
  $vars['box_padding']		= NULL;

  
  // define width, height, bgcolor, bgimage for iconbox
  if(!empty($vars['settings'])) {
    $vars['grid']				= $vars['settings']['grid'];
    $vars['icon_position']		= 'iconbox-icon-position-'.$vars['settings']['icon-position'];
    $vars['icon_looks']			= 'iconbox-icon-style-'.$vars['settings']['icon-style'];
    $vars['icon_size']			= 'iconbox-icon-size-'.$vars['settings']['icon-size'];

    if($vars['settings']['icon-size']			== 'custom')	{$vars['icon_size_custom']	= 'font-size:'.$vars['settings']['icon-size-custom'].'px;';}
    if($vars['settings']['icon-color']			== 'custom')	{$vars['icon_color']		= 'color:'.$vars['settings']['icon-color-custom'].';';}
    if($vars['settings']['icon-bg-color']		== 'none')		{$vars['icon_bg_color']		= 'background-color:transparent;';}
    if($vars['settings']['icon-bg-color']		== 'custom')	{$vars['icon_bg_color']		= 'background-color:'.$vars['settings']['icon-bg-color-custom'].';';}
    if($vars['settings']['icon-border-color']	== 'custom')	{$vars['icon_border_color']	= 'border-color:'.$vars['settings']['icon-border-color-custom'].';';}
    if($vars['settings']['icon-border']			== 1) 			{$vars['icon_border']		= 'border-width:'.$vars['settings']['icon-border-width'].'px;border-style:'.$vars['settings']['icon-border-style'].';'.$vars['icon_border_color'];}
    if($vars['settings']['icon-style']			!= 'none')		{$vars['icon_bg_border']	= $vars['icon_bg_color'] . $vars['icon_border']; }

    $vars['icon_style']							= 'style='.$vars['icon_size_custom'] . $vars['icon_color'] . $vars['icon_bg_border']; // icon styles

    if($vars['settings']['box-bg-color']		== 'none')		{$vars['box_bg_color']		= 'background-color:transparent;';}
    if($vars['settings']['box-bg-color']		== 'custom')	{$vars['box_bg_color']		= 'background-color:'.$vars['settings']['box-bg-color-custom'].';';}
    if($vars['settings']['box-border-color']	== 'custom')	{$vars['box_border_color']	= 'border-color:'.$vars['settings']['box-border-color-custom'].';';}
    if($vars['settings']['box-border']			== 1) 			{$vars['box_border']		= 'border-width:'.$vars['settings']['box-border-width'].'px;border-style:'.$vars['settings']['box-border-style'].';'.$vars['box_border_color'];}
    
    $vars['box_style']							= 'style='.$vars['box_bg_color'].$vars['box_border']; // box styles
    
    if($vars['settings']['box-bg-color']		!= 'none')		{$vars['box_padding']		= 'iconbox-padding';}
    if($vars['settings']['box-border']			== 1)			{$vars['box_padding']		= 'iconbox-padding';}

  }

  //
  $vars['items'] = array();
  foreach ($vars['iconbox_data'] as $box => $item ) {
    $vars['items'][$box] = $item;
  }

}