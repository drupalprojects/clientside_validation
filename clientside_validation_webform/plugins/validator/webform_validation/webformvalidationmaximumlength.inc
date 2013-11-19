<?php

$plugin = array(
  'label' => t('Maximum length'),
  'validator' => array(
    'class' => 'CvWebformValidationMaximumLengthValidator',
    'constructor argument' => array(
      'js_rule' => 'maxlength',
      'webform_rule' => 'max_length',
    ),
  ),
);
