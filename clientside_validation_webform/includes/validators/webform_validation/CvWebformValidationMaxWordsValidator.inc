<?php

class CvWebformValidationMaxWordsValidator extends CvWebformValidationValidator {
  public function getMessage(array $element) {
    return '!title field has to have maximum !max values.';
  }
}
