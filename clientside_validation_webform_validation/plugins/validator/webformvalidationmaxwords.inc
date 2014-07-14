<?php

$plugin = array(
  'label' => t('Maximum words'),
  'validator' => array(
    'class' => 'CvWebformValidationMaxWordsValidator',
    'constructor argument' => array(
      'js_rule' => 'maxWords',
      'webform_rule' => 'max_words',
    ),
  ),
);

class CvWebformValidationMaxWordsValidator extends CvWebformValidationValidator {
  public function getMessage(array $element) {
    return '!title field has to have maximum !max values.';
  }
}