<?php

$plugin = array(
  'label' => t('Exact selection length (min)'),
  'validator' => array(
    'class' => 'CvWebformValidationSelectExactMinValidator',
    'constructor argument' => array(
      'js_rule' => 'minlength',
      'webform_rule' => 'select_exact',
    ),
  ),
);

class CvWebformValidationSelectExactMinValidator extends CvWebformValidationValidator {
  public function getMessage(array $element) {
    return 'Select a minimum of !min items for !title.';
  }
}
