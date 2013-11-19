<?php

class CvWebformValidationMinimumLengthValidator extends CvWebformValidationValidator {
  public function getMessage(array $element) {
    return '!title field has to have minimal !min values.';
  }
}
