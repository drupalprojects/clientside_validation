<?php

$plugin = array(
  'label' => t('URL'),
  'validator' => array(
    'class' => 'CvFieldValidation2URLValidator',
  ),
  'constructor argument' => array(
    'field_validation_rule' => 'field_validation_url_validator',
    'js_rule' => 'drupalURL',
    'js_arg' => NULL,
  ),
);


class CvFieldValidation2URLValidator extends CvFieldValidationValidator {

  public function getMessage(array $element) {
    return '!title has to be a valid url.';
  }

  public function getJsArg(array $element) {
    $arg = parent::getJsArg($element);
    if ($arg['external']) {
      return array('absolute' => TRUE);
    }
    return TRUE;
  }
}
