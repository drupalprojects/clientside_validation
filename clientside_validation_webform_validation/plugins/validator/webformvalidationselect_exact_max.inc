<?php

$plugin = array(
  'label' => t('Exact selection length (max)'),
  'validator' => array(
    'class' => 'CvWebformValidationSelectExactMaxValidator',
    'constructor argument' => array(
      'js_rule' => 'maxlength',
      'webform_rule' => 'select_exact',
    ),
  ),
);

class CvWebformValidationSelectExactMaxValidator extends CvWebformValidationValidator {
  public function getMessage(array $element) {
    return 'Select a maximum of !max items for !title.';
  }
}
