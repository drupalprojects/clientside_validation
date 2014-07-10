<?php

$plugin = array(
  'label' => t('Max'),
  'validator' => array(
    'class' => 'CvWebformMaxValidator',
  ),
);

class CvWebformMaxValidator extends CvWebformValidator {

  public function supports(array $element, array &$form_state) {
    return (
      parent::supports($element, $form_state)
      && isset($element['#webform_component']['extra']['max'])
    );
  }

  public function getJavascriptSettings(array &$element, array &$form_state) {
    $name = $this->getName($element);
    $settings = $element['#webform_component']['extra'];
    $rule = (isset($settings['step']) && !empty($settings['step']) && $settings['step'] != 'any') ? 'Html5Max' : 'max';
    return array(
      'rules' => array(
         $name => array(
          $rule => $rule == 'max' ? $settings['max'] : array($settings['max'], $settings['step']),
        ),
      ),
      'messages' => array(
        $name => array(
          $rule => $rule == 'max' ? '!title field has to be smaller than !max.' : '!title field has to be smaller than !max and must be dividable by !step.',
        ),
      ),
    );
  }
}