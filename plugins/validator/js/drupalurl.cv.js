/*jshint strict:true, browser:true, curly:true, eqeqeq:true, expr:true, forin:true, latedef:true, newcap:true, noarg:true, trailing: true, undef:true, unused:true */
/*global Drupal: true, jQuery: true*/
/**
 * @file
 * Decimal comma validator.
 */
(function($, document) {
  "use strict";
  //Define a Drupal behaviour with a custom name
  Drupal.behaviors.cvCoreDrupalUrl = {
    attach: function(context) {
      // Add an eventlistener to the document reacting on the
      // 'clientsideValidationAddCustomRules' event.
      $(document).bind('clientsideValidationAddCustomRules', function(event) {
        // Support for Drupal urls.
        $.validator.addMethod("drupalURL", function(value, element, param) {
          var result = false;
          if (this.settings['name_event'] == 'onkeyup') {
            return true;
          }
          if (jQuery.validator.methods.url.call(this, value, element)) {
            return true;
          }
          if (param.absolute === true) {
            return false;
          }
          jQuery.ajax({
            'url': Drupal.settings.basePath + 'clientside_validation/drupalURL',
            'type': "POST",
            'data': {
              'value': value
            },
            'dataType': 'json',
            'async': false,
            'success': function(res) {
              result = res;
            }
          });
          return result.result;
        }, $.validator.format('Please fill in a valid url'));
      });
    }
  };
})(jQuery, document);
