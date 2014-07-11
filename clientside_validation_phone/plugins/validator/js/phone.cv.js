/*jshint strict:true, browser:true, curly:true, eqeqeq:true, expr:true, forin:true, latedef:true, newcap:true, noarg:true, trailing: true, undef:true, unused:true */
/*global Drupal: true, jQuery: true*/
/**
 * @file
 * Decimal comma validator.
 */
(function($, document, Drupal) {
  "use strict";
  //Define a Drupal behaviour with a custom name
  Drupal.behaviors.cvPhone = {
    attach: function(context) {
      // Add an eventlistener to the document reacting on the
      // 'clientsideValidationAddCustomRules' event.
      $(document).bind('clientsideValidationAddCustomRules', function(event) {
        // Support for phone
        $.validator.addMethod("phone", function(value, element, param) {
          var country_code = param;
          var result = false;
          $.ajax({
            'url': Drupal.settings.basePath + 'clientside_validation/phone',
            'type': "POST",
            'data': {
              'value': value,
              'country_code': country_code
            },
            'dataType': 'json',
            'async': false,
            'success': function(res) {
              result = res;
            }
          });
          return this.optional(element) || result.result;

        }, $.validator.format('Please fill in a valid phone number'));
      });
    }
  };
})(jQuery, document, Drupal);
