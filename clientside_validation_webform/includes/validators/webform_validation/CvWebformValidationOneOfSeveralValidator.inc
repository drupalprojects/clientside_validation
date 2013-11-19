<?php

class CvWebformValidationOneOfSeveralValidator extends CvWebformValidationValidator {

  public function getJavascriptSettings(array $element, array &$form_state) {
    $rule = _clientside_validation_get_webform_validation_rules($element, $form_state['complete form'], $this->webform_rule);
    $name = $this->getName($element);
    $names = array();
    foreach ($rule['components'] as $component) {
      $names[] = $component['element_name'];
    }
    $data = explode('|', $rule['data']);
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
    return 'oneofseveral';
  }
}
