<?php

$plugin = array(
  'label' => t('Minimum length'),
  'validator' => array(
    'class' => 'CvWebformValidationMinimumLengthValidator',
    'constructor argument' => array(
      'js_rule' => 'minlength',
      'webform_rule' => 'min_length',
    ),
  ),
);

class CvWebformValidationMinimumLengthValidator extends CvWebformValidationValidator {
  public function getMessage(array $element) {
    return '!title field has to have minimal !min values.';
  }
}
