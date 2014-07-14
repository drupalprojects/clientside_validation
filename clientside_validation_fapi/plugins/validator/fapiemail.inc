<?php

$plugin = array(
  'label' => t('Email'),
  'validator' => array(
    'class' => 'CvFAPIEmailValidator',
    'constructor argument' => array(
      'fapi_rule_callback' => 'fapi_validation_rule_email',
      'js_rule' => 'email',
      'js_arg' => TRUE,
    ),
  ),
);

class CvFAPIEmailValidator extends CvFAPIValidator {

  public function getMessage(array $element) {
    return 'The value in !title is not a valid email address.';
  }

}
