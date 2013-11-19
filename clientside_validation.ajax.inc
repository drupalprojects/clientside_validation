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
