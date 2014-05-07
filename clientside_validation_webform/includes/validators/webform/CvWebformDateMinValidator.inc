<?php

class CvWebformDateMinValidator extends CvWebformValidator {

  public function supports(array $element, array &$form_state) {
    if (!parent::supports($element, $form_state)) {
      return FALSE;
    }
    return (
      $element['#webform_component']['type'] == 'date'
      && (isset($element['#year_start']) || isset($element['#start_date']))
    );
  }

  public function getJavascriptSettings(array $element, array &$form_state) {
    $element_name = isset($element['#year_start']) ? $this->getName($element) . '[year]' : 'webform-component-' . str_replace('_', '-', implode('--', array_slice($element['#parents'], 1)));
    $rule_name = isset($element['#year_start']) ? 'min' : 'datemin';
    $settings = array(
      'rules' => array(
        $element_name => array(
          $rule_name => isset($element['#year_start']) ? $element['#year_start'] : explode('-', $element['#end_date']),
        ),
      ),
      'messages' => array(
        $element_name => array(
          $rule_name => isset($element['#year_start']) ? 'The year in the entered date must be before !year' : 'The entered date must be before !date',
        ),
      ),
    );
    return $settings;
  }
}
