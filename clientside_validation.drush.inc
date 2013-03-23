<?php

/**
 * Implements hook_drush_command().
 */
function clientside_validation_drush_command() {
  $items['cv-download'] = array(
    'description' => dt('Downloads the jQuery validate library from http://bassistance.de/jquery-plugins/jquery-plugin-validation/.'),
    'arguments' => array(
      'path' => dt('Path to the download folder. This path is relative to the Drupal root. If omitted Drush will use the default location (sites/all/libraries/jquery.validate).'),
    ),
    'callback' => 'drush_clientside_validation_download',
  );
  return $items;
}

/**
 * A command callback.
 */
function drush_clientside_validation_download($path = NULL) {
  // If no path is provided by the user, set our default path.
  if (is_null($path)) {
    $path = 'sites/all/libraries/jquery.validate';
  }
  // If jQuery validate is not installed and libraries module is enabled,
  // try to find jQuery validate by its own means.
  if (!is_dir($path)) {
    if (module_exists('libraries')) {
      // Libraries 1.x will return a path even if it doesn't exist
      // while 2.x will return FALSE.
      $path = libraries_get_path('jquery.validate');
      if (!$path) {
        $path = 'sites/all/libraries/jquery.validate';
      }
    }
  }
  if (is_dir($path)) {
    drush_log(dt('jQuery validate already present at @path. No download required.', array('@path' => $path)), 'ok');
  }
  elseif (drush_shell_exec('wget http://jquery.bassistance.de/validate/jquery-validation-1.11.1.zip -P %s', $path)) {
    drush_log(dt('jQuery validate successfully downloaded to @path.', array('@path' => $path)), 'success');
    if (drush_shell_exec('unzip %s/jquery-validation-1.11.1.zip -d %s', $path, $path)) {
      drush_log(dt('jQuery validate successfully unzipped to @path.', array('@path' => $path)), 'success');
    }
    else {
      drush_log(dt('Could not unzip the jQuery validate archive to @path.', array('@path' => $path)), 'warning');
    }
    drush_shell_exec('rm %s/jquery-validation-1.11.1.zip', $path);
  }
  else {
    drush_log(dt('Drush was unable to donwload jQuery validate to @path.', array('@path' => $path)), 'warning');
  }
}

/**
 * Implements drush_MODULE_post_COMMAND().
 */
function drush_clientside_validation_post_pm_enable() {
  $extensions = func_get_args();
  // Deal with comma delimited extension list.
  if (strpos($extensions[0], ',') !== FALSE) {
    $extensions = explode(',', $extensions[0]);
  }

  if (in_array('clientside_validation', $extensions) && !drush_get_option('skip')) {
    drush_clientside_validation_download();
  }
}