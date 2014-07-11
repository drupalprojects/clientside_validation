<?php

$plugin = array(
  'label' => t('URL'),
  'validator' => array(
    'class' => 'CvFAPIURLValidator',
  ),
  'constructor argument' => array(
    'fapi_rule_callback' => 'fapi_validation_rule_url',
    'js_rule' => 'drupalURL',
    'js_arg' => NULL,
  ),
);


class CvFAPIURLValidator extends CvFAPIValidator {

  public function getMessage(array $element) {
    return 'The value in !title is not a valid url.';
  }

  public function getJsArg(array $element) {
    $rule = $this->getRule($element);
    $param = is_array($rule['params']) ? $rule['params'][0] : $rule['params'];
    if ($param == 'absolute') {
      return array('absolute' => TRUE);
    }
    return TRUE;
  }

  public function jsFiles() {
    $files = parent::jsFiles();
    $files[] = drupal_get_path('module', 'clientside_validation') . '/plugins/validator/js/drupalurl.cv.js';
    return $files;
  }
}
