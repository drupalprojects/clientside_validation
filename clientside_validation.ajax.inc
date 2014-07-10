<?php

function _clientside_validation_ajax_call() {
  $param = $_POST['param'];
  $value = check_plain($_POST['value']);
  $result = array();
  foreach ($param['expressions'] as $key => $regex) {
    if (!(bool) preg_match($regex, (string) $value)) {
      $result = array('result' => FALSE, 'message' => $param['messages'][$key]);
      break;
    }
  }
  if (empty($result)) {
    $result = array('result' => TRUE);
  }
  drupal_json_output($result);
}

function _clientside_validation_ajax_phone() {
  $value = check_plain($_POST['value']);
  $country_code = check_plain($_POST['country_code']);
  if (function_exists('valid_phone_number') && !empty($country_code)) {
    $result['result'] = valid_phone_number($country_code, $value);
  }
  else {
    // elements module provides a telfield, but doesn't do any validation
    $result['result'] = TRUE;

  }
  drupal_json_output($result);
}

function _clientside_validation_ajax_captcha() {
  if (module_exists('captcha')) {
    $captcha_response = filter_xss($_POST['value']);
    $csid = $_POST['param'][0];
    $captcha_validate = $_POST['param'][1];
    $solution = db_query(
      'SELECT solution FROM {captcha_sessions} WHERE csid = :csid',
      array(':csid' => $csid)
    )
    ->fetchField();
    if ($solution === FALSE) {
      return drupal_json_output(array('result' => FALSE, 'message' => t('CAPTCHA validation error: unknown CAPTCHA session ID. Contact the site administrator if this problem persists.')));
    }
    if (!function_exists($captcha_validate)) {
       $captcha_validate = 'captcha_validate_strict_equality';
    }
    watchdog($solution, $captcha_response);
    if ($captcha_validate($solution, $captcha_response)) {
      return drupal_json_output(array('result' => TRUE));
    }
    else {
      return drupal_json_output(array('result' => FALSE));
    }

  }
  return drupal_json_output(array('result' => TRUE));
}

/**
 * Check that a path is valid and accessible for internal and aliased paths, also if the path is an
 * external url, it is validated according to RFC 2396.
 *
 * @param $path
 *   The path to check is valid.
 */
function _clientside_validation_url_validation_callback() {
  $path = $_POST['value'];
  $result = array();
  $result['result'] = FALSE;

  // Check if the url is valid according to RFC 2396.
  if (filter_var($path, FILTER_VALIDATE_URL)) {
    $result['result'] = TRUE;
  }

  // If we have an internal URL, strip out the query string and fragment
  // before attempting to validate the URL.
  if (!url_is_external($path)) {
    $parsed_path = parse_url($path);
    if (isset($parsed_path['query'])) {
      $query = drupal_get_query_array($parsed_path['query']);
    }
    if (isset($parsed_path['fragment'])) {
      $fragment = $parsed_path['fragment'];
    }
    if ($path != $parsed_path['path']) {
      $path = $parsed_path['path'];
    }
  }

  // Checks a path exists and the current user has access to it.
  if (trim($path) && drupal_valid_path($path)) {
    $result['result'] = TRUE;
  }
  else {
    // Check if the aliased path, exists and the current user has access to it.
    $lookup_path = drupal_lookup_path('source', $path);
    if (drupal_valid_path($lookup_path)) {
      $result['result'] = TRUE;
    }
  }

  drupal_json_output($result);
}
