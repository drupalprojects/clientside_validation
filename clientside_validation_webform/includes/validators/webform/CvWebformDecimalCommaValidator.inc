<?php

class CvWebformDecimalCommaValidator extends CvWebformValidator {

  public function supports(array $element, array &$form_state) {
    if (!parent::supports($element, $form_state)) {
      return FALSE;
    }
    return (
      $element['#webform_component']['type'] == 'number'
      && !$element['#webform_component']['extra']['integer']
      && $element['#webform_component']['extra']['point'] == ','
    );
  }

  public function getJavascriptSettings(array $element, array &$form_state) {
    $name = $this->getName($element);
    return array(
      'rules' => array(
         $name => array(
          'numberDE' => TRUE,
        ),
      ),
      'messages' => array(
        $name => array(
          'numberDE' => '!title field accepts only numbers (use a \',\' as decimal point).',
        ),
      ),
    );
  }
}
