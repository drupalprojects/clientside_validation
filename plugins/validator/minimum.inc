<?php

$plugin = array(
  'label' => t('Minimum'),
  'validator' => array(
    'class' => 'CvCoreMinimumValidator',
  ),
);

class CvCoreMinimumValidator extends ClientsideValidationValidator {

  public function supports(array $element, array &$form_state) {
    if (!parent::supports($element, $form_state)) {
      return FALSE;
    }
    if (!isset($element['#number_type']) || !isset($element['#entity_type'])) {
      return FALSE;
    }
    $instance = field_widget_instance($element, $form_state);
    return isset($instance['settings']['min']);
  }

  public function getJavascriptSettings(array &$element, array &$form_state) {
    $instance = field_widget_instance($element, $form_state);
    $name = $this->getName($element);
    return array(
      'rules' => array(
        $name => array(
          'min' => $instance['settings']['min'],
        ),
      ),
      'messages' => array(
        $name => array(
          'min' => '!title field has to be greater than !min.',
        ),
      ),
    );
  }
}
