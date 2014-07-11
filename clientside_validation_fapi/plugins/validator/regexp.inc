<?php

$plugin = array(
  'label' => t('Regular expression'),
  'validator' => array(
    'class' => 'CvFAPIRegexpValidator',
  ),
  'constructor argument' => array(
    'fapi_rule_callback' => 'fapi_validation_rule_regexp',
    'js_rule' => 'regexMatchPCRE',
    'js_arg' => NULL,
  ),
);


class CvFAPIRegexpValidator extends CvFAPIValidator {

  public function getMessage(array $element) {
    return '!title field does not match the required pattern.';
  }

  public function getJsArg(array $element) {
    $rule = $this->getRule($element);
    return is_array($rule['params']) ? $rule['params'][0] : $rule['params'];
  }

  public function jsFiles() {
    $files = parent::jsFiles();
    $files[] = drupal_get_path('module', 'clientside_validation_fapi') . '/plugins/validator/js/regexmatchpcre.cv.js';
    return $files;
  }
}
