<?php

$plugin = array(
  'label' => t('Specific value'),
  'validator' => array(
    'class' => 'CvFieldValidation2SpecificValValidator',
  ),
  'constructor argument' => array(
    'field_validation_rule' => 'field_validation_specific_value_validator',
    'js_rule' => 'oneOf',
    'js_arg' => NULL,
  ),
);


class CvFieldValidation2SpecificValValidator extends CvFieldValidationValidator {

  public function getMessage(array $element) {
    return '!title field has to be one of the following values: !values.';
  }

  public function getJsArg(array $element) {
    $arg = parent::getJsArg($element);
    return array($arg);
  }

  public function jsFiles() {
    $files = parent::jsFiles();
    $files[] = drupal_get_path('module', 'clientside_validation_field_validation') . '/plugins/validator/js/oneof.cv.js';
    return $files;
  }
}
