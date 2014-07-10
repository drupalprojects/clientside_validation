<?php

$plugin = array(
  'label' => t('Minimum words'),
  'validator' => array(
    'class' => 'CvWebformValidationMinWordsValidator',
    'constructor argument' => array(
      'js_rule' => 'minWords',
      'webform_rule' => 'min_words',
    ),
  ),
);

class CvWebformValidationMinimumLengthValidator extends CvWebformValidationValidator {
  public function getMessage(array $element) {
    return '!title field has to have minimal !min values.';
  }
}
