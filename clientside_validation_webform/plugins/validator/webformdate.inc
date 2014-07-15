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
            'required' => t('Day in !title field is required.', array('@title' => $element['#title'])),
          ),
          $month_name => array(
            'required' => t('Month in !title field is required.', array('@title' => $element['#title'])),
          ),
          $year_name => array(
            'required' => t('Year in !title field is required.', array('@title' => $element['#title'])),
          ),
        ),
      );
    }
    return $settings;
  }

  public function getMessage(array $element) {
  }

}
