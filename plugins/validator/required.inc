<?php

$plugin = array(
  'label' => t('Required'),
  'validator' => array(
    'class' => 'CvCoreRequiredValidator',
  ),
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
      $class = 'cv-checkboxes-' . $group++;
      $element['#attributes']['class'][] = $class;
      return array(
        'rules' => array(
          $name => array(
            'require_from_group' => array(1, $class . ' input[type="checkbox"]'),
          ),
        ),
        'messages' => array(
          $name => array(
            'required' => t('This field is required!'),
          ),
        )
      );
    }
    if ($element['#type'] == 'select') {
      return array(
        'rules' => array(
          $name => array(
            'oneOf' => array(
              'values' => array('_none'),
              'negate' => TRUE,
            ),
          ),
        ),
        'messages' => array(
          $name => array(
            'oneOf' => '!title field is required.',
          ),
        ),
      );
    }
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
