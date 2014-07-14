<?php

$plugin = array(
  'label' => t('Min'),
  'validator' => array(
    'class' => 'CvWebformMinValidator',
  ),
);

class CvWebformMinValidator extends CvWebformValidator {

  public function supports(array $element, array &$form_state) {
    return (
      parent::supports($element, $form_state)
      && isset($element['#webform_component']['extra']['min'])
    );
  }

  public function getJavascriptSettings(array &$element, array &$form_state) {
    $name = $this->getName($element);
    $settings = $element['#webform_component']['extra'];
    $rule = (isset($settings['step']) && !empty($settings['step']) && $settings['step'] != 'any') ? 'webformMin' : 'min';
    return array(
      'rules' => array(
         $name => array(
          $rule => $rule == 'min' ? $settings['min'] : array($settings['min'], $settings['step']),
        ),
      ),
      'messages' => array(
        $name => array(
          $rule => $this->getMessage($element),
        ),
      ),
    );
  }

  public function getMessage(array $element) {
    $settings = $element['#webform_component']['extra'];
    return (isset($settings['step']) && !empty($settings['step']) && $settings['step'] != 'any') ? '!title field has to be greater than !min and must be dividable by !step.' : '!title field has to be greater than !min.';
  }

  public function jsFiles(array &$element) {
    $files = parent::jsFiles($element);
    $files[] = drupal_get_path('module', 'clientside_validation_webform') . '/plugins/validator/js/min_max.cv.js';
    return $files;
  }
}
