<?php

$plugin = array(
  'label' => t('Unique'),
  'validator' => array(
    'class' => 'CvWebformValidationUniqueValidator',
    'constructor argument' => array(
      'js_rule' => 'notEqualTo',
      'webform_rule' => 'equal',
    ),
  ),
);

class CvWebformValidationUniqueValidator extends CvWebformValidationValidator {

  public function getJavascriptSettings(array &$element, array &$form_state) {
    $rule = _clientside_validation_get_webform_validation_rules($element, $form_state['complete form'], $this->webform_rule);
    $settings = array();
    $all = $rule['components'];
    while (count($all) > 1) {
      $firstone = array_shift($all);
      foreach ($all as $component) {
        $settings['rules'][$firstone['element_name']]['notEqualTo'][] = ':input[name="' . $component['element_name'] . '"]';
      }
      $settings['messages'][$firstone['element_name']]['notEqualTo'] = $this->getMessage($element);
    }
    return $settings;
  }

  public function getMessage(array $element) {
    return '!title field has to be equal to !firstone.';
  }

  public function jsFiles() {
    $files = parent::jsFiles();
    $files[] = drupal_get_path('module', 'clientside_validation_webform') . '/plugins/validator/webform_validation/js/notequalto.cv.js';
    return $files;
  }
}
