<?php

class CvCoreBlackListValidator extends ClientsideValidationValidator {

  public function supports(array $element, array &$form_state) {
    return (
      parent::supports($element, $form_state)
      && isset($element['#type'])
      && $element['#type'] == 'select'
      && isset($element['#required'])
      && $element['#required']
    );
  }

  public function getJavascriptSettings(array $element, array &$form_state) {
    $name = $this->getName($element);
    return array(
      'rules' => array(
        $name => array(
          'blacklist' => array(
            'values' => array('_none'),
            'negate' => FALSE,
          ),
        ),
      ),
      'messages' => array(
        $name => array(
          'blacklist' => '!title field is required.',
        ),
      ),
    );
  }

}

