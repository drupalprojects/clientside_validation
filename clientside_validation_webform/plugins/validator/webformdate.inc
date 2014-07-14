<?php

$plugin = array(
  'label' => t('Date'),
  'validator' => array(
    'class' => 'CvWebformDateValidator',
  ),
);

class CvWebformDateValidator extends CvWebformValidator {

  public function supports(array $element, array &$form_state) {
    if (!parent::supports($element, $form_state)) {
      return FALSE;
    }
    return (
      $element['#webform_component']['type'] == 'date'
    );
  }

  public function getJavascriptSettings(array &$element, array &$form_state) {
    $settings = array();
    if (isset($element['#required']) && $element['#required']) {
      // TODO: min & max date.
      $day_name = $this->getName($element) . '[day]';
      $month_name = $this->getName($element) . '[month]';
      $year_name = $this->getName($element) . '[year]';
      $settings = array(
        'rules' => array(
          $day_name => array(
            'required' => TRUE,
          ),
          $month_name => array(
            'required' => TRUE,
          ),
          $year_name => array(
            'required' => TRUE,
          ),
        ),
        'messages' => array(
          $day_name => array(
            'required' => 'Day in !title field is required.',
          ),
          $month_name => array(
            'required' => 'Month in !title field is required.',
          ),
          $year_name => array(
            'required' => 'Year in !title field is required.',
          ),
        ),
      );
    }
    return $settings;
  }

  public function getMessage(array $element) {
  }

}
