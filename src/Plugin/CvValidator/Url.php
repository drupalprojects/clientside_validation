<?php
/**
 * @file
 * Contains \Drupal\clientside_validation\Plugin\CvValidator\Url.
 */

namespace Drupal\clientside_validation\Plugin\CvValidator;

use Drupal\clientside_validation\CvValidatorBase;
use Drupal\Core\Form\FormStateInterface;

/**
 * Provides a 'url' validator.
 *
 * @CvValidator(
 *   id = "url",
 *   name = @Translation("Url"),
 *   supports = {
 *     "types" = {
 *       "url"
 *     }
 *   }
 * )
 */
class Url extends CvValidatorBase {

  /**
   * {@inheritdoc}
   */
  protected function getRules($element, FormStateInterface $form_state) {
    return [
      'messages' => [
        'url' => t('@title does not contain a valid url.', ['@title' => $element['#title']]),
      ],
    ];
  }

}
