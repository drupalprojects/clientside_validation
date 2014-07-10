<?php

$plugin = array(
  'label' => t('Require one of two fields'),
  'validator' => array(
    'class' => 'CvWebformValidationOneOfTwoValidator',
    'constructor argument' => array(
      'js_rule' => 'require_from_group',
      'webform_rule' => 'oneoftwo',
    ),
  ),
);


class CvWebformValidationOneOfTwoValidator extends CvWebformValidationValidator {

  public function getJavascriptSettings(array &$element, array &$form_state) {
    $rule = _clientside_validation_get_webform_validation_rules($element, $form_state['complete form'], $this->webform_rule);
    $name = $this->getName($element);
    $names = array();
    foreach ($rule['components'] as $component) {
      $names[] = $component['element_name'];
    }
    return array(
      'rules' => array(
         $name => array(
          $this->js_rule => array(1, implode(', ', $names)),
        ),
      ),
      'messages' => array(
        $name => array(
          $this->js_rule => $this->getMessage($element),
        ),
      ),
    );
  }

  public function getMessage(array $element) {
    return 'oneoftwo';
  }

  public function jsFiles() {
    $files = parent::jsFiles();
    $files[] = drupal_get_path('module', 'clientside_validation_webform') . '/plugins/validator/webform_validation/js/oneof.cv.js';
    return $files;
  }
}
