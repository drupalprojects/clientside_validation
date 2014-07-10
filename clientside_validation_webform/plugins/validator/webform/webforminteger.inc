<?php

$plugin = array(
  'label' => t('Integer'),
  'validator' => array(
    'class' => 'CvWebformIntegerValidator',
  ),
);

class CvWebformIntegerValidator extends CvWebformValidator {

  public function supports(array $element, array &$form_state) {
    return (
      parent::supports($element, $form_state)
      && $element['#webform_component']['type'] == 'number'
      && $element['#webform_component']['extra']['integer']
    );
  }

  public function getJavascriptSettings(array &$element, array &$form_state) {
    $name = $this->getName($element);
    return array(
      'rules' => array(
         $name => array(
          'digits' => TRUE,
        ),
      ),
      'messages' => array(
        $name => array(
          'digits' => 'The value in !title is not a valid email address.',
        ),
      ),
    );
  }
}
