<?php
/**
 * @file
 * Contains \Drupal\clientside_validation\Plugin\CvValidator\MaxLength.
 */

namespace Drupal\clientside_validation\Plugin\CvValidator;

use Drupal\clientside_validation\CvValidatorBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Provides a 'maxlength' validator.
 *
 * @CvValidator(
 *   id = "maxlength",
 *   name = @Translation("Maximum length"),
 *   supports = {
 *     "attributes" = {"maxlength"}
 *   }
 * )
 */
class MaxLength extends CvValidatorBase {

  /**
   * {@inheritdoc}
   */
  protected function getRules($element, FormStateInterface $form_state) {
    // Drupal already adds the required attribute, so we don't need to set the
    // required rule.
    if (isset($element['#maxlength'])) {
      if ($element['#type'] == 'select') {
        return [
          'messages' => [
            'maxlength' => t('@title field can only have a maximum of @max values.', ['@title' => $element['#title'], '@max' => $element['#maxlength']]),
          ],
        ];
      }
      return [
        'messages' => [
          'maxlength' => t('@title field has a maximum length of @max.', ['@title' => $element['#title'], '@max' => $element['#maxlength']]),
        ],
      ];
    }
  }

}
