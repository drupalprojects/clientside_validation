<?php

$plugin = array(
  'label' => t('Maximum words'),
  'validator' => array(
    'class' => 'CvWebformValidationMaxWordsValidator',
    'constructor argument' => array(
      'js_rule' => 'maxWords',
      'webform_rule' => 'max_words',
    ),
  ),
);
