<?php

$plugin = array(
  'label' => t('Maximum'),
  'validator' => array(
    'class' => 'CvWebformValidationMaximumValidator',
    'constructor argument' => array(
      'js_rule' => 'max',
      'webform_rule' => 'numeric',
    ),
  ),
);
