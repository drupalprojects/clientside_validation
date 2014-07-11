<?php

$plugin = array(
  'label' => t('Valid email address'),
  'validator' => array(
    'class' => 'CvFieldValidation2EmailValidator',
  ),
  'constructor argument' => array(
    'field_validation_rule' => 'field_validation_email_validator',
    'js_rule' => 'email',
    'js_arg' => NULL,
  ),
);


class CvFieldValidation2EmailValidator extends CvFieldValidationValidator {

  public function getMessage(array $element) {
    return '!title must be a valid email address.';
  }

  public function getJsArg(array $element) {
    return TRUE;
  }
}
