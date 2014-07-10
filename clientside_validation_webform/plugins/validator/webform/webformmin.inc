<?php

$plugin = array(
  'label' => t('Min'),
  'validator' => array(
    'class' => 'CvWebformMinValidator',
  ),
);

class CvWebformMinValidator extends CvWebformValidator {

  public function supports(array $element, array &$form_state) {
    return (
      parent::supports($element, $form_state)
      && isset($element['#webform_component']['extra']['min'])
    );
  }

  public function getJavascriptSettings(array &$element, array &$form_state) {
    $name = $this->getName($element);
    $settings = $element['#webform_component']['extra'];
    $rule = (isset($settings['step']) && !empty($settings['step']) && $settings['step'] != 'any') ? 'Html5Min' : 'min';
    return array(
      'rules' => array(
         $name => array(
          $rule => $rule == 'min' ? $settings['min'] : array($settings['min'], $settings['step']),
        ),
      ),
      'messages' => array(
        $name => array(
          $rule => $rule == 'min' ? '!title field has to be greater than !min.' : '!title field has to be greater than !min with steps of !step.',
        ),
      ),
    );
  }
}
