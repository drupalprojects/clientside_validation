<?php

$plugin = array(
  'label' => t('Maximum selection length'),
  'validator' => array(
    'class' => 'CvWebformValidationSelectMaxValidator',
    'constructor argument' => array(
      'js_rule' => 'maxlength',
      'webform_rule' => 'select_max',
    ),
  ),
);

class CvWebformValidationSelectMaxValidator extends CvWebformValidationValidator {
  public function getMessage(array $element) {
    return 'Select a maximum of !max items for !title.';
  }
}
