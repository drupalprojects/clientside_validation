<?php

$plugin = array(
  'label' => t('Maximum length'),
  'validator' => array(
    'class' => 'CvFieldValidation1MaxLengthValidator',
  ),
  'constructor argument' => array(
    'field_validation_rule' => 'max_length',
    'js_rule' => 'maxlength',
    'js_arg' => NULL,
  ),
);


class CvFieldValidation1MaxLengthValidator extends CvFieldValidationValidator {

  public function getMessage(array $element) {
    return '!title field has a maximum length of !minl characters.';
  }

}
