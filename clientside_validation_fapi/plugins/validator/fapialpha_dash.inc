<?php

$plugin = array(
  'label' => t('Alpha dash'),
  'validator' => array(
    'class' => 'CvFAPIAlphaDashValidator',
    'constructor argument' => array(
      'fapi_rule_callback' => 'fapi_validation_rule_alpha_dash',
      'js_rule' => 'regexMatchPCRE',
      'js_arg' => '/^[-\p{L}\p{N}_]*$/uD',
    ),
  ),
);

class CvFAPIAlphaDashValidator extends CvFAPIValidator {

  public function getMessage(array $element) {
    return '!title field does not match the required pattern.';
  }

  public function jsFiles(array &$element) {
    $files = parent::jsFiles($element);
    $files[] = drupal_get_path('module', 'clientside_validation_fapi') . '/plugins/validator/js/regexmatchpcre.cv.js';
    return $files;
  }

  public function getJsArg(array $element) {
    return array('expressions' => array('alpha_dash' => $this->js_arg), 'messages' => array('alpha_dash' => $this->getMessage($element)));
  }
}
