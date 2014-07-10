<?php


/**
 * Set validation rule for required fields.
 */
function _clientside_validation_set_required($name, $title, $required, &$js_rules, $message = '') {
  $title = _clientside_validation_set_title($title);
  if ($required) {
    $js_rules[$name]['required'] = TRUE;
    if (empty($message)) {
      $variables = array(
        'message' => '!title field is required.',
        'placeholders' => array('!title' => $title),
        'error_type' => 'required',
        'element_name' => $name,
      );
    }
    else {
      $variables = array(
        'message' => $message,
        'error_type' => 'required',
        'element_name' => $name,
      );
    }
    $js_rules[$name]['messages']['required'] = theme('clientside_error', $variables);
  }
}

/**
 * Set validation rule for number fields.
 */
function _clientside_validation_set_title($title) {
  $settings = clientside_validation_settings_current_form();
  return $settings['error']['prefix'] . $title . $settings['error']['suffix'];
}

/**
 * Set validation rule for positive or negative integer number fields.
 */
function _clientside_validation_set_number($name, $title, &$js_rules, $message = '') {
  $title = _clientside_validation_set_title($title);
  $js_rules[$name]['digits_negative'] = TRUE;
  if (empty($message)) {
    $variables = array(
      'message' => '!title field accepts only numbers.',
      'placeholders' => array('!title' => $title),
      'error_type' => 'number',
      'element_name' => $name,
    );
  }
  else {
    $variables = array(
      'message' => $message,
      'error_type' => 'number',
      'element_name' => $name,
    );
  }
  $js_rules[$name]['messages']['digits_negative'] = theme('clientside_error', $variables);
}

/**
 * Set validation rule for decimal fields.
 */
function _clientside_validation_set_number_decimal($name, $title, $decimalpoint, &$js_rules, $message = '') {
  $title = _clientside_validation_set_title($title);
  if ($decimalpoint == '.') {
    $js_rules[$name]['number'] = TRUE;
    $variables = array(
      'message' => empty($message) ? '!title field accepts only numbers (use a \'.\' as decimal point).' : $message,
      'placeholders' => empty($message) ? array('!title' => $title) : array(),
      'error_type' => 'number',
      'element_name' => $name,
    );
    $js_rules[$name]['messages']['number'] = theme('clientside_error', $variables);
  }
  else {
    $js_rules[$name]['numberDE'] = TRUE;
    $variables = array(
      'message' => empty($message) ? '!title field accepts only numbers (use a \',\' as decimal point).' : $message,
      'placeholders' => empty($message) ? array('!title' => $title) : array(),
      'error_type' => 'number',
      'element_name' => $name,
    );
    $js_rules[$name]['messages']['numberDE'] = theme('clientside_error', $variables);
  }
}

/**
 * Set validation rule for fields with a minimum and/or a maximum value.
 */
function _clientside_validation_set_minmax($name, $title, $min, $max, &$js_rules, $message = '') {
  $title = _clientside_validation_set_title($title);
  if (isset($min) && $min !== '' && isset($max) && $max !== '') {
    $js_rules[$name]['range'] = array($min, $max);
    if (empty($message)) {
      $variables = array(
        'message' => '!title field has to be between !min and !max.',
        'placeholders' => array('!title' => $title, '!min' => $min, '!max' => $max),
        'error_type' => 'range',
        'element_name' => $name,
      );
    }
    else {
      $variables = array(
        'message' => $message,
        'error_type' => 'range',
        'element_name' => $name,
      );
    }
    $js_rules[$name]['messages']['range'] = theme('clientside_error', $variables);
  }
  elseif (isset($min) && $min !== '') {
    $js_rules[$name]['min'] = $min;
    if (empty($message)) {
      $variables = array(
        'message' => '!title field has to be greater than !min.',
        'placeholders' => array('!title' => $title, '!min' => $min),
        'error_type' => 'min',
        'element_name' => $name,
      );
    }
    else {
      $variables = array(
        'message' => $message,
        'error_type' => 'min',
        'element_name' => $name,
      );
    }
    $js_rules[$name]['messages']['min'] = theme('clientside_error', $variables);
  }
  elseif (isset($max) && $max !== '') {
    $js_rules[$name]['max'] = $max;
    if (empty($message)) {
      $variables = array(
        'message' => '!title field has to be smaller than !max.',
        'placeholders' => array('!title' => $title, '!max' => $max),
        'error_type' => 'max',
        'element_name' => $name,
      );
    }
    else {
      $variables = array(
        'message' => $message,
        'error_type' => 'max',
        'element_name' => $name,
      );
    }
    $js_rules[$name]['messages']['max'] = theme('clientside_error', $variables);
  }
}

function _clientside_validation_set_minmax_date($name, $title, $start_date, $end_date, &$js_rules, $message = '') {
  $title = _clientside_validation_set_title($title);
  if (isset($start_date) && $start_date !== '' && isset($end_date) && $end_date !== '') {
    $js_rules[$name]['daterange'] = array($start_date, $end_date);
    if (empty($message)) {
      $variables = array(
        'message' => '!title field has to be between !min and !max.',
        'placeholders' => array('!title' => $title, '!min' => $start_date, '!max' => $end_date),
        'error_type' => 'daterange',
        'element_name' => $name,
      );
    }
    else {
      $variables = array(
        'message' => $message,
        'error_type' => 'daterange',
        'element_name' => $name,
      );
    }
    $js_rules[$name]['messages']['daterange'] = theme('clientside_error', $variables);
  }
  elseif (isset($start_date) && $start_date !== '') {
    $js_rules[$name]['datemin'] = $start_date;
    if (empty($message)) {
      $variables = array(
        'message' => '!title field has to be greater than !min.',
        'placeholders' => array('!title' => $title, '!min' => $start_date),
        'error_type' => 'datemin',
        'element_name' => $name,
      );
    }
    else {
      $variables = array(
        'message' => $message,
        'error_type' => 'datemin',
        'element_name' => $name,
      );
    }
    $js_rules[$name]['messages']['datemin'] = theme('clientside_error', $variables);
  }
  elseif (isset($end_date) && $end_date !== '') {
    $js_rules[$name]['datemax'] = $end_date;
    if (empty($message)) {
      $variables = array(
        'message' => '!title field has to be smaller than !max.',
        'placeholders' => array('!title' => $title, '!max' => $end_date),
        'error_type' => 'datemax',
        'element_name' => $name,
      );
    }
    else {
      $variables = array(
        'message' => $message,
        'error_type' => 'datemax',
        'element_name' => $name,
      );
    }
    $js_rules[$name]['messages']['datemax'] = theme('clientside_error', $variables);
  }
}

/**
 * Set validation rule for fields with a minimum and/or maximum length.
 */
function _clientside_validation_set_minmaxlength($name, $title, $min, $max, &$js_rules, $message = '') {
  $title = _clientside_validation_set_title($title);
  if ($max == 1) {
    $max = '';
  }
  if (isset($min) && $min !== '' && isset($max) && $max !== '') {
    $js_rules[$name]['rangelength'] = array($min, $max);
    if (empty($message)) {
      $variables = array(
        'message' => '!title field has to have between !min and !max values.',
        'placeholders' => array('!title' => $title, '!min' => $min, '!max' => $max),
        'error_type' => 'rangelength',
        'element_name' => $name,
      );
    }
    else {
      $variables = array(
        'message' => $message,
        'error_type' => 'rangelength',
        'element_name' => $name,
      );
    }
    $js_rules[$name]['messages']['rangelength'] = theme('clientside_error', $variables);
  }
  elseif (isset($min) && $min !== '') {
    $js_rules[$name]['minlength'] = $min;
    if (empty($message)) {
      $variables = array(
        'message' => '!title field has to have minimal !min values.',
        'placeholders' => array('!title' => $title, '!min' => $min),
        'error_type' => 'minlength',
        'element_name' => $name,
      );
    }
    else {
      $variables = array(
        'message' => $message,
        'error_type' => 'minlength',
        'element_name' => $name,
      );
    }
    $js_rules[$name]['messages']['minlength'] = theme('clientside_error', $variables);
  }
  elseif (isset($max) && $max !== '') {
    $js_rules[$name]['maxlength'] = $max;
    if (empty($message)) {
      $variables = array(
        'message' => '!title field has to have maximum !max values.',
        'placeholders' => array('!title' => $title, '!max' => $max),
        'error_type' => 'maxlength',
        'element_name' => $name,
      );
    }
    else {
      $variables = array(
        'message' => $message,
        'error_type' => 'maxlength',
        'element_name' => $name,
      );
    }
    $js_rules[$name]['messages']['maxlength'] = theme('clientside_error', $variables);
  }
}

/**
 * Set validation rule for fields with a minimum and/or maximum length for select options.
 */
function _clientside_validation_set_minmaxlength_select($name, $title, $min, $max, &$js_rules, $message = '', $negate = FALSE) {
  $title = _clientside_validation_set_title($title);
  if ($max == 1) {
    $max = '';
  }
  if (isset($min) && $min !== '' && isset($max) && $max !== '') {
    $js_rules[$name]['selectRangelength']['range'] = array($min, $max);
    $js_rules[$name]['selectRangelength']['negate'] = $negate;
    if (empty($message)) {
      $variables = array(
        'message' => '!title field has to have between !min and !max values.',
        'placeholders' => array('!title' => $title, '!min' => $min, '!max' => $max),
        'error_type' => 'selectRangelength',
        'element_name' => $name,
      );
    }
    else {
      $variables = array(
        'message' => $message,
        'error_type' => 'selectRangelength',
        'element_name' => $name,
      );
    }
    $js_rules[$name]['messages']['selectRangelength'] = theme('clientside_error', $variables);
  }
  elseif (isset($min) && $min !== '') {
    $js_rules[$name]['selectMinlength'] = array('min' => $min, 'negate' => $negate);
    if (empty($message)) {
      $variables = array(
        'message' => '!title field has to have minimal !min values.',
        'placeholders' => array('!title' => $title, '!min' => $min),
        'error_type' => 'selectMinlength',
        'element_name' => $name,
      );
    }
    else {
      $variables = array(
        'message' => $message,
        'error_type' => 'selectMinlength',
        'element_name' => $name,
      );
    }
    $js_rules[$name]['messages']['selectMinlength'] = theme('clientside_error', $variables);
  }
  elseif (isset($max) && $max !== '') {
    $js_rules[$name]['selectMaxlength'] = array('max' => $max, 'negate' => $negate);
    if (empty($message)) {
      $variables = array(
        'message' => '!title field has to have maximum !max values.',
        'placeholders' => array('!title' => $title, '!max' => $max),
        'error_type' => 'selectMaxlength',
        'element_name' => $name,
      );
    }
    else {
      $variables = array(
        'message' => $message,
        'error_type' => 'selectMaxlength',
        'element_name' => $name,
      );
    }
    $js_rules[$name]['messages']['selectMaxlength'] = theme('clientside_error', $variables);
  }
}

/**
 * Set validation rule for fields with a minimum and/or maximum amount of words.
 */
function _clientside_validation_set_minmax_words($name, $title, $min, $max, &$js_rules, $message = '') {
  $title = _clientside_validation_set_title($title);
  if (isset($min) && $min !== '' && isset($max) && $max !== '') {
    $js_rules[$name]['rangewords'] = array($min, $max);
    if (empty($message)) {
      $variables = array(
        'message' => '!title field has to have between !min and !max words.',
        'placeholders' => array('!title' => $title, '!min' => $min, '!max' => $max),
        'error_type' => 'rangewords',
        'element_name' => $name,
      );
    }
    else {
      $variables = array(
        'message' => $message,
        'error_type' => 'rangewords',
        'element_name' => $name,
      );
    }
    $js_rules[$name]['messages']['rangewords'] = theme('clientside_error', $variables);
  }
  elseif (isset($min) && $min !== '') {
    $js_rules[$name]['minwords'] = $min;
    if (empty($message)) {
      $variables = array(
        'message' => '!title field has to have minimal !min words.',
        'placeholders' => array('!title' => $title, '!min' => $min),
        'error_type' => 'minwords',
        'element_name' => $name,
      );
    }
    else {
      $variables = array(
        'message' => $message,
        'error_type' => 'minwords',
        'element_name' => $name,
      );
    }
    $js_rules[$name]['messages']['minwords'] = theme('clientside_error', $variables);
  }
  elseif (isset($max) && $max !== '') {
    $js_rules[$name]['maxwords'] = $max;
    if (empty($message)) {
      $variables = array(
        'message' => '!title field has to have maximum !max words.',
        'placeholders' => array('!title' => $title, '!max' => $max),
        'error_type' => 'maxwords',
        'element_name' => $name,
      );
    }
    else {
      $variables = array(
        'message' => $message,
        'error_type' => 'maxwords',
        'element_name' => $name,
      );
    }
    $js_rules[$name]['messages']['maxwords'] = theme('clientside_error', $variables);
  }
}

/**
 * Set validation rule for plain text fields
 */
function _clientside_validation_set_plain_text($name, $title, $allowed_tags, &$js_rules, $message = '', $negate = FALSE) {
  $title = _clientside_validation_set_title($title);
  $js_rules[$name]['plaintext']['tags'] = empty($allowed_tags) ? '' : $allowed_tags;
  $js_rules[$name]['plaintext']['negate'] = $negate;
  if (empty($message)) {
      $variables = array(
        'message' => (empty($allowed_tags)) ? '!title field can not contain any HTML tags' : '!title field can not contain any HTML tags exept !allowed',
        'placeholders' => array('!title' => $title, '!allowed' => $allowed_tags),
        'error_type' => 'plaintext',
        'element_name' => $name,
      );
    }
    else {
      $variables = array(
        'message' => $message,
        'error_type' => 'plaintext',
        'element_name' => $name,
      );
    }
    $js_rules[$name]['messages']['plaintext'] = theme('clientside_error', $variables);
}

/**
 * Set validation rule for required fields that must equal a value from an other field.
 */
function _clientside_validation_set_equal($name, $title, $value, &$js_rules, $message = '', $webform = FALSE) {
  $title = _clientside_validation_set_title($title);
  if ($webform) {
    $js_rules[$name]['equalTo'] = ':input[name=\'submitted[' . $value['form_key'] . ']\']';
  }
  else {
    $js_rules[$name]['equalTo'] = ':input[name=\'' . $value['element_name'] . '\']';
  }
  if (empty($message)) {
    $variables = array(
      'message' => '!title field has to be equal to !firstone.',
      'placeholders' => array('!title' => $title, '!firstone' => $value['name']),
      'error_type' => 'equalto',
      'element_name' => $name,
    );
  }
  else {
    $variables = array(
      'message' => $message,
      'error_type' => 'plaintext',
      'element_name' => $name,
    );
  }
  $js_rules[$name]['messages']['equalTo'] = theme('clientside_error', $variables);
}

/**
 * Set validation rule for fields that can not be equal to a value from an other field.
 */
function _clientside_validation_set_not_equal($name, $title, $elements, &$js_rules, $message = '', $webform = FALSE) {
  $title = _clientside_validation_set_title($title);
  $items = array('items' => array());
  foreach ($elements as $element) {
     $items['items'][] = $element['name'];
    if ($webform) {
      $js_rules[$name]['notEqualTo'][] = 'input[name="' . $element['element_name'] . '"]';
    }
    else {
      $js_rules[$name]['notEqualTo'][] = 'input[name="' . $element['form_key'] . '"]';
    }
  }
  if (empty($message)) {
    $variables = array(
      'message' => '!title field has to be different from !firstone',
      'placeholders' => array('!title' => $title, '!firstone' => theme('item_list',  $items)),
      'error_type' => 'notequalto',
      'element_name' => $name,
    );
  }
  else {
    $variables = array(
      'message' => $message,
      'error_type' => 'notequalto',
      'element_name' => $name,
    );
  }
  $message = theme('clientside_error', $variables);
  $js_rules[$name]['messages']['notEqualTo'] = $message;
}

/**
 * Set validation rule for fields that must be equal to a specific value.
 */
function _clientside_validation_set_specific_value($name, $title, $value, &$js_rules, $message = '', $case_sensitive = TRUE, $negate = FALSE) {
  if (!is_array($value)) {
    $value = array($value);
  }
  $js_rules[$name]['oneOf'] = array('values' => $value, 'caseSensitive' => $case_sensitive, 'negate' => $negate);
  $title = _clientside_validation_set_title($title);
  if (empty($message)) {
    $variables = array(
      'message' => '!title field has to be one of the following values: !values.',
      'placeholders' => array('!title' => $title, '!values' => implode(', ', $value)),
      'error_type' => 'specific value',
      'element_name' => $name
    );
  }
  else{
    $variables = array(
      'message' => $message,
      'error_type' => 'specific value',
      'element_name' => $name
    );
  }
  $message = theme('clientside_error', $variables);
  $js_rules[$name]['messages']['oneOf'] = $message;
}

/**
 * Set validation rule for fields that consist of one or more of specific values (e.g. string with only a, b and c in it).
 */
function _clientside_validation_set_specific_values($name, $title, $values, &$js_rules, $message = '') {
  $js_rules[$name]['specificVals'] = $values;
  $title = _clientside_validation_set_title($title);
  if (empty($message)) {
    $variables = array(
      'message' => '!title field must consist of following elements only: !elements.',
      'placeholders' => array('!title' => $title, '!elements' => implode(', ', $values)),
      'error_type' => 'specific values',
      'element_name' => $name
    );
  }
  else {
    $variables = array(
      'message' => $message,
      'error_type' => 'specific values',
      'element_name' => $name
    );
  }
  $message = theme('clientside_error', $variables);
  $js_rules[$name]['messages']['specificVals'] = $message;
}

/**
 * Set validation rule for fields that can not consist of one or more specific values
 */
function _clientside_validation_set_blacklist($name, $title, $values, &$js_rules, $message = '', $negate = FALSE) {
  $js_rules[$name]['blacklist']['values'] = $values;
  $js_rules[$name]['blacklist']['negate'] = $negate;
  $title = _clientside_validation_set_title($title);
  if (empty($message)) {
    $variables = array(
      'message' => '!title field can not consist of following elements: !elements.',
      'placeholders' => array('!title' => $title, '!elements' => implode(', ', $values)),
      'error_type' => 'blacklist',
      'element_name' => $name
    );
  }
  else {
    $variables = array(
      'message' => $message,
      'error_type' => 'blacklist',
      'element_name' => $name
    );
  }
  $message = theme('clientside_error', $variables);
  $js_rules[$name]['messages']['blacklist'] = $message;
}

/**
 * Set validation rule for ean number fields.
 */
function _clientside_validation_set_ean($name, $title, &$js_rules, $message = '') {
  $title = _clientside_validation_set_title($title);
  if (empty($message)) {
    $variables = array(
      'message' => '!title field is not a valid EAN number.',
      'placeholders' => array('!title' => $title),
      'error_type' => 'ean',
      'element_name' => $name
    );
  }
  else {
    $variables = array(
      'message' => $message,
      'error_type' => 'ean',
      'element_name' => $name
    );
  }
  $message = theme('clientside_error', $variables);
  $js_rules[$name]['validEAN'] = TRUE;
  $js_rules[$name]['messages']['validEAN'] = $message;
}

/**
 * Set validation rule for fields with regex validation from webform_validation
 */
function _clientside_validation_set_regex($name, $title, &$js_rules, $expression, $message = '', $modifiers = "", $type = 'regex', $negate = FALSE) {
  $title = _clientside_validation_set_title($title);
  if (empty($message)) {
    $variables = array(
      'message' => '!title field does not match the required pattern.',
      'placeholders' => array('!title' => $title),
      'error_type' => $type,
      'element_name' => $name
    );
  }
  else {
    $variables = array(
      'message' => $message,
      'error_type' => $type,
      'element_name' => $name
    );
  }
  $message = theme('clientside_error', $variables);
  $js_rules[$name]['regexMatch']['regex'] = array($expression);
  $js_rules[$name]['regexMatch']['negate'] = $negate;
  if (!empty($modifiers)) {
    $js_rules[$name]['regexMatch']['regex'][] = $modifiers;
  }
  $js_rules[$name]['messages']['regexMatch'] = $message;
}

/**
 * Set validation rule for fields with regex validation from webform_validation
 */
function _clientside_validation_set_regex_pcre($name, $title, &$js_rules, $expression, $message = '', $type = 'regex pcre') {
  $title = _clientside_validation_set_title($title);
  if (empty($message)) {
    $variables = array(
      'message' => '!title field does not match the required pattern.',
      'placeholders' => array('!title' => $title),
      'error_type' => $type,
      'element_name' => $name
    );
  }
  else {
    $variables = array(
      'message' => $message,
      'error_type' => $type,
      'element_name' => $name
    );
  }
  $message = theme('clientside_error', $variables);
  $js_rules[$name]['regexMatchPCRE']['expressions'][] = $expression;
  $js_rules[$name]['regexMatchPCRE']['messages'][] = $message;
}

/**
 * Set validation rule for file fields that must have a certain extension.
 */
function _clientside_validation_set_extensions($name, $extensions, &$js_rules) {
  $extension_list = preg_replace('#,(?![^,]+,)#', ' or', implode(', ', $extensions));
  $js_rules[$name]['accept'] = implode('|', $extensions);
  $variables = array(
    'message' => "Only files with a %exts extension are allowed.",
    'placeholders' => array('%exts' => $extension_list),
    'error_type' => 'extensions',
    'element_name' => $name
  );
  $js_rules[$name]['messages']['accept'] = theme('clientside_error', $variables);
}

/**
 * Set validation rule for checkboxes.
 */
function _clientside_validation_set_checkboxgroup_minmax($name, $title, $id, &$js_rules, $message = '', $min = 1, $max = 99) {
  $title = _clientside_validation_set_title($title);
  $js_rules[$name]['checkboxgroupminmax'] = array($min, $max, $id);
  if ($message == '') {
    if ($min == 1 && $max == 99) {
      $message = '!title field is required.';
      $placeholders = array('!title' => $title);
    }
    if ($min == 0 && $max != 99) {
      $message = 'You can select no more than !max values for !title.';
      $placeholders = array('!title' => $title, '!max' => $max);
    }
    if ($min != 1 && $max == 99) {
      $message = 'You must select at least !min values for !title.';
      $placeholders = array('!title' => $title, '!min' => $min);
    }
    if ($min > 0 && $max != 99) {
      $message = 'You must select between !min and !max values for !title.';
      $placeholders = array('!title' => $title, '!min' => $min, '!max' => $max);
    }
  }
  else {
    $placeholders = array();
  }
  $variables = array(
    'message' => $message,
    'placeholders' => $placeholders,
    'error_type' => 'required',
    'element_name' => $name
  );
  $js_rules[$name]['messages']['checkboxgroupminmax'] = theme('clientside_error', $variables);
}

/**
 * Set validation rule for email fields.
 */
function _clientside_validation_set_email($name, $title, &$js_rules, $message = '') {
  $title = _clientside_validation_set_title($title);
  $js_rules[$name]['email'] = TRUE;
  $variables = array(
    'message' => empty($message) ? 'The value in !title is not a valid email address.' : $message,
    'placeholders' => empty($message) ? array('!title' => $title) : array(),
    'error_type' => 'email',
    'element_name' => $name
  );
  $js_rules[$name]['messages']['email'] = theme('clientside_error', $variables);
}

/**
 * Set validation rule for url fields.
 */
function _clientside_validation_set_url($name, $title, &$js_rules, $message = '') {
  $title = _clientside_validation_set_title($title);
  $js_rules[$name]['url'] = TRUE;
  $variables = array(
    'message' => empty($message) ? 'The value in !title is not a valid url.' : $message,
    'placeholders' => empty($message) ? array('!title' => $title) : array(),
    'error_type' => 'url',
    'element_name' => $name
  );
  $js_rules[$name]['messages']['url'] = theme('clientside_error', $variables);
}

/**
 * Set validation rule for "require at least one of several".
 */
function _clientside_validation_set_require_oneof($names, $titles, $message = "", &$js_rules) {
  $original_message = $message;
  foreach ($names as $key => $name) {
    $temp_titles = $titles;
    unset($temp_titles[$key]);
    if (empty ($original_message)) {
      $string_titles = '<ul><li>' . implode('</li><li>', $temp_titles) . '</li></ul>';
      $message = t('!name field is required unless you specify at least one of these items: !items', array('!name' => $titles[$key], '!items' => $string_titles));
    }
    $js_rules[$name]['requireOneOf'] = array_diff($names, array($name));
    $variables = array(
      'message' => $message,
      'error_type' => 'requireOneOf',
      'element_name' => $name,
    );
    $js_rules[$name]['messages']['requireOneOf'] = theme('clientside_error', $variables);
  }
}

function _clientside_validation_set_phone($name, $title, $country_code, &$js_rules, $message = "") {
  $title = _clientside_validation_set_title($title);
  $js_rules[$name]['phone'] = $country_code;
  $variables = array(
    'message' => empty($message) ? 'The value in !title is not a valid phone number.' : $message,
    'placeholders' => empty($message) ? array('!title' => $title) : array(),
    'error_type' => 'phone',
    'element_name' => $name
  );
  $js_rules[$name]['messages']['phone'] = theme('clientside_error', $variables);
}

function _clientside_validation_set_date($name, $title, $format, &$js_rules, $message = "") {
  $title = _clientside_validation_set_title($title);
  $splitter = '/';
  if (strpos($format, '.') !== FALSE) {
    $splitter = '.';
  }
  elseif (strpos($format, ' ') !== FALSE) {
    $splitter = ' ';
  }
  elseif (strpos($format, '-') !== FALSE) {
    $splitter = '-';
  }
  $parts = explode($splitter, $format);
  $daypos = (array_search('d', $parts) === FALSE) ? array_search('j', $parts) : array_search('d', $parts);
  foreach (array('m', 'M', 'F', 'n') as $m) {
    $monthpos = array_search($m, $parts);
    if ($monthpos !== FALSE) {
      break;
    }
  }
  $yearpos = array_search('Y', $parts);
  $js_rules[$name]['dateFormat'] = array('format' => $format, 'splitter' => $splitter, 'daypos' => $daypos, 'monthpos' => $monthpos, 'yearpos' => $yearpos);
  $variables = array(
    'message' => empty($message) ? 'The value in !title is not a valid date.' : $message,
    'placeholders' => empty($message) ? array('!title' => $title) : array(),
    'error_type' => 'date',
    'element_name' => $name
  );
  $js_rules[$name]['messages']['dateFormat'] = theme('clientside_error', $variables);
}

function _clientside_validation_set_captcha($name, $title, $validate, &$js_rules, $message) {
  $title = _clientside_validation_set_title($title);
  $js_rules[$name]['captcha'] = $validate;
  $variables = array(
    'message' => empty($message) ? 'Wrong answer for !title.' : $message,
    'placeholders' => empty($message) ? array('!title' => $title) : array(),
    'error_type' => 'captcha',
    'element_name' => $name
  );
  $js_rules[$name]['messages']['captcha'] = theme('clientside_error', $variables);
}

