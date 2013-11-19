<?php

$plugin = array(
  'label' => t('Minimum'),
  'validator' => array(
    'class' => 'CvWebformValidationMinimumValidator',
    'constructor argument' => array(
      'js_rule' => 'min',
      'webform_rule' => 'numeric',
    ),
  ),
);
