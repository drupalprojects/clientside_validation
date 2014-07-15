<?php

$plugin = array(
  'label' => t('IPv4'),
  'validator' => array(
    'class' => 'CvFAPIIPv4Validator',
    'constructor argument' => array(
      'fapi_rule_callback' => 'fapi_validation_rule_ipv4',
      'js_rule' => 'regexMatchPCRE',
      'js_arg' => '/^([1-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])(\.([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])){3}$/',
    ),
  ),
);

class CvFAPIIPv4Validator extends CvFAPIValidator {

  public function getMessage(array $element) {
    $rule = $this->getRule($element);
    return isset($rule['error']) && $rule['error'] ? $rule['error'] : t('Invalid format of @title.', array('@title' => $element['#title']));
  }

  public function jsFiles(array &$element) {
    $files = parent::jsFiles($element);
    $files[] = drupal_get_path('module', 'clientside_validation_fapi') . '/plugins/validator/js/regexmatchpcre.cv.js';
    return $files;
  }

  public function getJsArg(array $element) {
    return array('expressions' => array('ipv4' => $this->js_arg), 'messages' => array('ipv4' => $this->getMessage($element)));
  }
}
