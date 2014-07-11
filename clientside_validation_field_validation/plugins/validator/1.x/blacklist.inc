<?php

$plugin = array(
  'label' => t('Blacklist'),
  'validator' => array(
    'class' => 'CvFieldValidation1BlacklistValidator',
  ),
  'constructor argument' => array(
    'field_validation_rule' => 'blacklist',
    'js_rule' => 'empty',
    'js_arg' => NULL,
  ),
);


class CvFieldValidation1BlacklistValidator extends CvFieldValidationValidator {

  public function getMessage(array $element) {
    return '!title field can not consist of following elements: !elements.';
  }

  public function getJsArg(array $element) {
    $arg = parent::getJsArg($element);
    return explode(',', $arg);
  }

  public function jsFiles() {
    $files = parent::jsFiles();
    $files[] = drupal_get_path('module', 'clientside_validation_field_validation') . '/plugins/validator/js/blacklist.cv.js';;
    return $files;
  }
}
