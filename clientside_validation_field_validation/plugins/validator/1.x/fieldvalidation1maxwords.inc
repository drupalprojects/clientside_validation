<?php

$plugin = array(
  'label' => t('Maximum words'),
  'validator' => array(
    'class' => 'CvFieldValidation1MaxWordsValidator',
    'constructor argument' => array(
      'field_validation_rule' => 'max_words',
      'js_rule' => 'maxWords',
      'js_arg' => NULL,
    ),
  ),
);

class CvFieldValidation1MaxWordsValidator extends CvFieldValidationValidator {

  public function getMessage(array $element) {
    return '!title can not have more than !max words.';
  }

}
