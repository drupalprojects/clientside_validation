/*jshint strict:true, browser:true, curly:true, eqeqeq:true, expr:true, forin:true, latedef:true, newcap:true, noarg:true, trailing: true, undef:true, unused:true */
/*global Drupal: true, jQuery: true*/
/**
 * @file
 * Decimal comma validator.
 */
(function ($, document) {
  "use strict";
  //Define a Drupal behaviour with a custom name
  Drupal.behaviors.cvCaptcha = {
    attach: function (context) {
      // Add an eventlistener to the document reacting on the
      // 'clientsideValidationAddCustomRules' event.
      $(document).bind('clientsideValidationAddCustomRules', function(event){
        $.validator.addMethod("captcha", function (value, element, param) {
          var result = false;
          var sid = $(element).closest('.captcha').find('input[name=captcha_sid]').val();
          $.ajax({
            'url': $.settings.basePath + 'clientside_validation/captcha',
            'type': "POST",
            'data': {
              'value': value,
              'param': [sid, param]
            },
            'dataType': 'json',
            'async': false,
            'success': function(res){
              result = res;
            }
          });
          if (result.result === false) {
            if (typeof result.message !== 'undefined' && result.message.length) {
              $.extend($.validator.messages, {
                "captcha": result.message
              });
            }
          }
          return result.result;
        }, $.validator.format('Wrong answer.'));
      });
    }
  };
})(jQuery, document);
