<?php

$plugin = array(
  'label' => t('Numeric'),
  'validator' => array(
    'class' => 'CvFAPINumericValidator',
    'constructor argument' => array(
      'fapi_rule_callback' => 'fapi_validation_rule_numeric',
      'js_rule' => 'number',
      'js_arg' => TRUE,
    ),
  ),
);

class CvFAPINumericValidator extends CvFAPIValidator {

  public function getMessage(array $element) {
    return '!title field accepts only numbers (use a \'.\' as decimal point).';
  }

}
