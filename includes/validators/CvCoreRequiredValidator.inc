<?php

class CvCoreRequiredValidator extends ClientsideValidationValidator {

  public function supports(array $element, array &$form_state) {
    return
      parent::supports($element, $form_state)
      && isset($element['#required'])
      && ((boolean) $element['#required']);
  }

  public function getJavascriptSettings(array $element, array &$form_state) {
    $name = $this->getName($element);
    return array(
      'rules' => array(
        $name => array(
          'required' => TRUE,
        ),
      ),
      'messages' => array(
        $name => array(
          'required' => t('This field is required!'),
        ),
      )
    );
  }

}
