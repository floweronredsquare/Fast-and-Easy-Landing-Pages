<?php

/**
 * @file
 * Plugin to provide access control based on browscap_get_browser().
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('Is Mobile'),
  'description' => t('Is this a mobile device.'),
  'callback' => 'browscap_ctools_browscap_access_ctools_access_check',
  'default' => array('negate' => 0),
  'settings form' => 'browscap_ctools_browscap_access_ctools_access_settings',
  'summary' => 'browscap_ctools_browscap_access_ctools_access_summary',
);

/**
 * Settings form for the 'by parent term' access plugin
 */
function browscap_ctools_browscap_access_ctools_access_settings($form, &$form_state, $conf) {
  // No additional configuration necessary.
  return $form;
}

/**
 * Check for access.
 */
function browscap_ctools_browscap_access_ctools_access_check($conf, $context) {
  $browser = browscap_get_browser();
  if ($browser['ismobiledevice'] == 1) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

/**
 * Provide a summary description based upon the checked terms.
 */
function browscap_ctools_browscap_access_ctools_access_summary($conf, $context) {
  return t('Is mobile device');
}
