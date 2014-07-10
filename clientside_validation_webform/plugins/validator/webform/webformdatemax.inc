<?php

$plugin = array(
  'label' => t('Date max'),
  'validator' => array(
    'class' => 'CvWebformDateMaxValidator',
  ),
);

class CvWebformDateMaxValidator extends CvWebformValidator {

  public function supports(array $element, array &$form_state) {
    if (!parent::supports($element, $form_state)) {
      return FALSE;
    }
    return (
      $element['#webform_component']['type'] == 'date'
      && (isset($element['#year_start']) || isset($element['#start_date']))
    );
  }

  public function getJavascriptSettings(array &$element, array &$form_state) {
    $element_name = isset($element['#year_start']) ? $this->getName($element) . '[year]' : 'webform-component-' . str_replace('_', '-', implode('--', array_slice($element['#parents'], 1)));
    $rule_name = isset($element['#year_start']) ? 'max' : 'datemax';
    $settings = array(
      'rules' => array(
        $element_name => array(
          $rule_name => isset($element['#year_start']) ? $element['#year_start'] : explode('-', $element['#end_date']),
        ),
      ),
      'messages' => array(
        $element_name => array(
          $rule_name => isset($element['#year_start']) ? 'The year in the entered date must be after !year' : 'The entered date must be after !date',
        ),
      ),
    );
    return $settings;
  }

  public function jsFiles() {
    $files = parent::jsFiles();
    $files[] = drupal_get_path('module', 'clientside_validation_webform') . '/plugins/validator/webform/js/datemax.cv.js';
    return $files;
  }
}
