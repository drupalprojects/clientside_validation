<?php

$plugin = array(
  'label' => t('Select minimum'),
  'validator' => array(
    'class' => 'CvFieldValidation2SelectMinValidator',
    'constructor argument' => array(
      'field_validation_rule' => 'field_validation_number_of_selections_validator',
      'js_rule' => 'minlength',
      'js_arg' => NULL,
    ),
  ),
);

class CvFieldValidation2SelectMinValidator extends CvFieldValidationValidator {

  public function supports(array $element, array &$form_state) {
    if (!parent::supports($element, $form_state)) {
      return FALSE;
    }
    $min = $this->getJsArg($element);
    return $min != '' && is_numeric($min);
  }

  public function getMessage(array $element) {
    return 'You must select more than !min items for !title.';
  }

  public function getJsArg(array $element) {
    $rule = $this->getRule($element);
    return $rule->settings['min'];
  }

}
