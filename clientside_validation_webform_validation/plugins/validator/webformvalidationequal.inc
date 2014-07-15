<?php

$plugin = array(
  'label' => t('Equal'),
  'validator' => array(
    'class' => 'CvWebformValidationEqualValidator',
    'constructor argument' => array(
      'js_rule' => 'equalTo',
      'webform_rule' => 'equal',
    ),
  ),
);

class CvWebformValidationEqualValidator extends CvWebformValidationValidator {

  public function supports(array $element, array &$form_state) {
    if (!parent::supports($element, $form_state)) {
      return FALSE;
    }
    $rule = _clientside_validation_get_webform_validation_rules($element, $form_state['complete form'], $this->webform_rule);
    $first = reset($rule['components']);
    return $first['element_name'] == $this->getName($element);
  }

  public function getJavascriptSettings(array &$element, array &$form_state) {
    $rule = _clientside_validation_get_webform_validation_rules($element, $form_state['complete form'], $this->webform_rule);
    $others = $rule['components'];
    $firstone = array_shift($others);
    $form_key = implode('][', webform_component_parent_keys(node_load($firstone['nid']), $firstone));
    $settings = array();
    foreach ($others as $component) {
      $settings['rules'][$component['element_name']][$this->js_rule] = ':input[name=\'submitted[' . $form_key . ']\']';
      $settings['messages'][$component['element_name']][$this->js_rule] = t('@item_checked does not match @item_first.', array('@item_checked' => $component['name'], '@item_first' => $firstone['name']));
    }
    return $settings;
  }

  public function getMessage(array $element) {
  }
}
