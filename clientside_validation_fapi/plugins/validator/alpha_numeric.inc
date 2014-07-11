<?php

$plugin = array(
  'label' => t('Alpha numeric'),
  'validator' => array(
    'class' => 'CvFAPIAlphaNumericValidator',
  ),
  'constructor argument' => array(
    'fapi_rule_callback' => 'fapi_validation_rule_alpha_numeric',
    'js_rule' => 'regexMatchPCRE',
    'js_arg' => '/^[\p{L}\p{N}]*$/uD',
  ),
);


class CvFAPIAlphaNumericValidator extends CvFAPIValidator {

  public function getMessage(array $element) {
    return '!title field does not match the required pattern.';
  }

  public function jsFiles() {
    $files = parent::jsFiles();
    $files[] = drupal_get_path('module', 'clientside_validation_fapi') . '/plugins/validator/js/regexmatchpcre.cv.js';
    return $files;
  }
}
