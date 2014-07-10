<?php

$plugin = array(
  'label' => t('Maximum length'),
  'validator' => array(
    'class' => 'CvWebformValidationMaximumLengthValidator',
    'constructor argument' => array(
      'js_rule' => 'maxlength',
      'webform_rule' => 'max_length',
    ),
  ),
);


class CvWebformValidationMaximumLengthValidator extends CvWebformValidationValidator {
  public function getMessage(array $element) {
    return '!title field has to have maximum !max values.';
  }
}