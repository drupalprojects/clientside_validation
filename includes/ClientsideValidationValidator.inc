<?php

abstract class ClientsideValidationValidator {
  public function supports(array $element, array &$form_state) {
    $name = $this->getName($element);
    return !empty($name);
  }
  abstract public function getJavascriptSettings(array $element, array &$form_state);

  public function getName(array $element) {
    if (!isset($element['#name'])) {
      return '';
    }
    return  (isset($element['#multiple']) && $element['#multiple']) ? $element['#name'] . '[]' : $element['#name'];
  }
  public function jsFiles() {
    return array();
  }
}

