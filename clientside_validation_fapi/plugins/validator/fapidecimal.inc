<?php

$plugin = array(
  'label' => t('Decimal'),
  'validator' => array(
    'class' => 'CvFAPIDecimalValidator',
    'constructor argument' => array(
      'fapi_rule_callback' => 'fapi_validation_rule_decimal',
      'js_rule' => 'regexMatchPCRE',
      'js_arg' => NULL,
    ),
  ),
);

class CvFAPIDecimalValidator extends CvFAPIValidator {

  public function getMessage(array $element) {
    return '!title field does not match the required pattern.';
  }

  public function getJsArg(array $element) {
    $rule = $this->getRule($element);
    if (count($rule['params']) == 2) {
      $expression = '/^[0-9]{' . $rule['params'][0] . '}\.[0-9]{' . $rule['params'][1] . '}$/';
    }
    else {
      $expression = '/\d+\.\d+/';
    }
    return array('expressions' => array('decimal' => $expression), 'messages' => array('decimal' => $this->getMessage($element)));

  }

  public function jsFiles(array &$element) {
    $files = parent::jsFiles($element);
    $files[] = drupal_get_path('module', 'clientside_validation_fapi') . '/plugins/validator/js/regexmatchpcre.cv.js';
    return $files;
  }

}
