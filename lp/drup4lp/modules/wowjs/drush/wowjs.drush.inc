<?php

/**
 * @file
 * Drush integration for wow.js library.
 */

/**
 * The wow.js library URL.
 */
define('WOWJS_DOWNLOAD_URI', 'https://github.com/matthieua/WOW/archive/master.zip');
define('WOWJS_DOWNLOAD_PREFIX', 'WOW-');

/**
 * Implements hook_drush_command().
 *
 * In this hook, you specify which commands your
 * drush module makes available, what it does and
 * description.
 * Notice how this structure closely resembles how
 * you define menu hooks.
 *
 * See `drush topic docs-commands` for a list of recognized keys.
 */
function wowjs_drush_command() {
  $items = array();

  // The key in the $items array is the name of the command.
  $items['wowjs'] = array(
    'callback' => 'drush_wowjs',
    'description' => dt('Download and install the wow.js library.'),
    // No bootstrap.
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'arguments' => array(),
    'aliases' => array(),
  );
  return $items;
}

/**
 * Implements hook_drush_help().
 *
 * This function is called whenever a drush user calls
 * 'drush help <name-of-your-command>'
 */
function wowjs_drush_help($section) {
  switch ($section) {
    case 'drush:wowjs':
      return dt('Download and install the wow.js library in sites/all/libraries.');
  }
}

/**
 * Command to download wow.js library.
 */
function drush_wowjs() {
  $path = 'sites/all/libraries';

  // Create the path if it does not exist.
  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
  }

  // Set the directory to the download location.
  $olddir = getcwd();
  chdir($path);

  // Download the zip archive.
  if ($filepath = drush_download_file(WOWJS_DOWNLOAD_URI)) {
    $filename = basename($filepath);
    $dirname = WOWJS_DOWNLOAD_PREFIX . basename($filepath, '.zip');

    // Remove any existing wow.js library directory.
    if (is_dir($dirname) || is_dir('wow')) {
      drush_delete_dir($dirname, TRUE);
      drush_delete_dir('wow', TRUE);
      drush_log(dt('A existing wow.js library was deleted from @path', array('@path' => $path)), 'notice');
    }

    // Decompress the zip archive.
    drush_tarball_extract($filename);

    // Change the directory name to "wow" if needed.
    if ($dirname != 'wow') {
      drush_move_dir($dirname, 'wow', TRUE);
      $dirname = 'wow';
    }
  }

  if (is_dir($dirname)) {
    drush_log(dt('Wow.js library has been installed in @path', array('@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to install the wow.js library to @path', array('@path' => $path)), 'error');
  }

  // Set working directory back to the previous working directory.
  chdir($olddir);
}
