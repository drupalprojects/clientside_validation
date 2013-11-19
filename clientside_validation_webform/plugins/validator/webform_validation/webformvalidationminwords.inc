<?php

$plugin = array(
  'label' => t('Minimum words'),
  'validator' => array(
    'class' => 'CvWebformValidationMinWordsValidator',
    'constructor argument' => array(
      'js_rule' => 'minWords',
      'webform_rule' => 'min_words',
    ),
  ),
);
