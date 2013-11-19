<?php

class CvCoreMaximumValidator extends ClientsideValidationValidator {

  public function supports(array $element, array &$form_state) {
    if (!parent::supports($element, $form_state)) {
      return FALSE;
    }
    if (!isset($element['#number_type']) || !isset($element['#entity_type'])) {
      return FALSE;
    }
    $instance = field_widget_instance($element, $form_state);
    return isset($instance['settings']['max']);
  }

  public function getJavascriptSettings(array $element, array &$form_state) {
    $instance = field_widget_instance($element, $form_state);
    $name = $this->getName($element);
    return array(
      'rules' => array(
        $name => array(
          'max' => $instance['settings']['max'],
        ),
      ),
      'messages' => array(
        $name => array(
          'max' => '!title field has to be smaller than !max.',
        ),
      ),
    );
  }

}
