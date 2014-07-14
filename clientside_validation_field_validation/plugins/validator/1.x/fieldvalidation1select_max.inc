<?php

$plugin = array(
  'label' => t('Select maximum'),
  'validator' => array(
    'class' => 'CvFieldValidation1SelectMaxValidator',
    'constructor argument' => array(
      'field_validation_rule' => 'select_max',
      'js_rule' => 'maxlength',
      'js_arg' => NULL,
    ),
  ),
);

class CvFieldValidation1SelectMaxValidator extends CvFieldValidationValidator {

  public function getMessage(array $element) {
    return 'You must select less than !max items for !title.';
  }

}
