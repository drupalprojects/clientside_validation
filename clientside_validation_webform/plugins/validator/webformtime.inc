<?php

$plugin = array(
  'label' => t('Time'),
  'validator' => array(
    'class' => 'CvWebformTimeRequiredValidator',
  ),
);

class CvWebformTimeRequiredValidator extends CvWebformValidator {

  public function supports(array $element, array &$form_state) {
    if (!parent::supports($element, $form_state)) {
      return FALSE;
    }
    return (
      $element['#webform_component']['type'] == 'time'
      && isset($element['hour']['#name'])
      &&isset($element['#required'])
      && $element['#required']
    );
  }

  public function getJavascriptSettings(array &$element, array &$form_state) {
    $settings = array();
    $hour_name = $this->getName($element['hour']);
    $minute_name = $this->getName($element['minute']);
    $settings = array(
      'rules' => array(
        $hour_name => array(
          'required' => TRUE,
        ),
        $minute_name => array(
          'required' => TRUE,
        ),
      ),
      'messages' => array(
        $hour_name => array(
          'required' => 'Hour in !title field is required.',
        ),
        $minute_name => array(
          'required' => 'Minute in !title field is required.',
        ),
      ),
    );
    return $settings;
  }

  public function getMessage(array $element) {
  }

}
