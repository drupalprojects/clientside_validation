<?php

$plugin = array(
  'label' => t('Numeric'),
  'validator' => array(
    'class' => 'CvFieldValidation1NumericValidator',
  ),
  'constructor argument' => array(
    'field_validation_rule' => 'numeric',
    'js_rule' => 'number',
    'js_arg' => NULL,
  ),
);


class CvFieldValidation1NumericValidator extends CvFieldValidationValidator {

  public function getMessage(array $element) {
    return '!title must be numeric.';
  }

  public function getJsArg(array $element) {
    return TRUE;
  }
}
