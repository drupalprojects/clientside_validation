<?php

$plugin = array(
  'label' => t('Maximum'),
  'validator' => array(
    'class' => 'CvWebformValidationOneOfSeveralValidator',
    'constructor argument' => array(
      'js_rule' => 'require_from_group',
      'webform_rule' => 'oneofseveral',
    ),
  ),
);
