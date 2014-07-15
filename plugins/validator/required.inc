<?php

$plugin = array(
  'label' => t('Required'),
  'validator' => array(
    'class' => 'CvCoreRequiredValidator',
  ),
  'weight' => -99,
);

class CvCoreRequiredValidator extends ClientsideValidationValidator {

  public function supports(array $element, array &$form_state) {
    return
      parent::supports($element, $form_state)
      && isset($element['#required'])
      && ((boolean) $element['#required']);
  }

  public function getJavascriptSettings(array &$element, array &$form_state) {
    static $group = 0;
    $name = $this->getName($element);
    if ($element['#type'] == 'checkboxes') {
      $settings = array();
      $class = 'cv-checkboxes-' . $group++;
      $element['#attributes']['class'][] = $class;
      foreach (array_keys($element['#options']) as $child) {
        $settings['rules'][$this->getName($element[$child])]['require_from_group'] = array(1, '.' . $class . ' input[type="checkbox"]');
        $settings['messages'][$this->getName($element[$child])]['require_from_group'] = $this->getMessage($element);
        $settings['groups'][$class][] = $this->getName($element[$child]);
      }
      return $settings;
    }
    return array(
      'rules' => array(
        $name => array(
          'required' => TRUE,
        ),
      ),
      'messages' => array(
        $name => array(
          'required' => $this->getMessage($element),
        ),
      )
    );
  }

  public function getMessage(array $element) {
    return isset($element['#required_error']) ? $element['#required_error'] : t('@title field is required.', array('@title' => $element['#title']));
  }
}
