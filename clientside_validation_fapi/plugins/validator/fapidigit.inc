<?php

$plugin = array(
  'label' => t('Digit'),
  'validator' => array(
    'class' => 'CvFAPIDigitValidator',
    'constructor argument' => array(
      'fapi_rule_callback' => 'fapi_validation_rule_digit',
      'js_rule' => 'regexMatchPCRE',
      'js_arg' => '/^\d*$/',
    ),
  ),
);

class CvFAPIDigitValidator extends CvFAPIValidator {

  public function getMessage(array $element) {
    return '!title field does not match the required pattern.';
  }

  public function jsFiles(array &$element) {
    $files = parent::jsFiles($element);
    $files[] = drupal_get_path('module', 'clientside_validation_fapi') . '/plugins/validator/js/regexmatchpcre.cv.js';
    return $files;
  }

  public function getJsArg(array $element) {
    return array('expressions' => array('digit' => $this->js_arg), 'messages' => array('digit' => $this->getMessage($element)));
  }
}
