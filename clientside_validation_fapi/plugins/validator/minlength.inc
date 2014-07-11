<?php

$plugin = array(
  'label' => t('Minimum length'),
  'validator' => array(
    'class' => 'CvFAPIMinlengthValidator',
  ),
  'constructor argument' => array(
    'fapi_rule_callback' => 'fapi_validation_rule_length',
    'js_rule' => 'minlength',
    'js_arg' => NULL,
  ),
);


class CvFAPIMinlengthValidator extends CvFAPIValidator {

  public function getMessage(array $element) {
    return '!title field has to have minimal !min values.';
  }

  public function getJsArg(array $element) {
    $rule = $this->getRule($element);
    return is_array($rule['params']) ? $rule['params'][0] : $rule['params'];
  }
}
