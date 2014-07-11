/*jshint strict:true, browser:true, curly:true, eqeqeq:true, expr:true, forin:true, latedef:true, newcap:true, noarg:true, trailing: true, undef:true, unused:true */
/*global Drupal: true, jQuery: true*/
/**
 * @file
 * Decimal comma validator.
 */
(function($, document, Drupal, window) {
  "use strict";
  //Define a Drupal behaviour with a custom name
  Drupal.behaviors.cvFAPIRegexMatchPCRE = {
    attach: function(context) {
      // Default regular expression support
      var ajaxPCREfn = function(value, element, param) {
        var result = false;

        $.ajax({
          'url': Drupal.settings.basePath + 'clientside_validation/regex-pcre',
          'type': "POST",
          'data': {
            'value': value,
            'param': param
          },
          'dataType': 'json',
          'async': false,
          'success': function(res) {
            result = res;
          }
        });
        if (result.result === false) {
          if (result.message.length) {
            $.extend($.validator.messages, {
              "regexMatchPCRE": result.message
            });
          }
        }
        return result.result;
      };

      // Regular expression support using XRegExp
      var xregexPCREfn = function(value, element, param) {
        if (window.XRegExp && window.XRegExp.version) {
          try {
            var result = true;
            for (var i = 0; i < param.expressions.length; i++) {
              var reg = param.expressions[i];
              var delim = reg.lastIndexOf(reg.charAt(0));
              // Only allow supported modifiers
              var modraw = reg.substr(delim + 1) || '';
              var mod = '';
              if (mod !== '') {
                for (var l = 0; l < 6; l++) {
                  if (modraw.indexOf('gimnsx'[l]) !== -1) {
                    mod += 'gimnsx'[l];
                  }
                }
              }
              reg = reg.substring(1, delim);
              if (!(new XRegExp(reg, mod).test(value))) {
                result = false;
                if (param.messages[i].length) {
                  $.extend($.validator.messages, {
                    "regexMatchPCRE": param.messages[i]
                  });
                }
              }
            }
            return result;
          }
          catch (e) {
            return ajaxPCREfn(value, element, param);
          }
        }
        else {
          return ajaxPCREfn(value, element, param);
        }
      };
      // Add an eventlistener to the document reacting on the
      // 'clientsideValidationAddCustomRules' event.
      $(document).bind('clientsideValidationAddCustomRules', function(event) {
        // Decide which one to use
        if (Drupal.settings.clientsideValidation.general.usexregxp) {
          $.validator.addMethod("regexMatchPCRE", xregexPCREfn, $.validator.format('The value does not match the expected format.'));
        }
        else {
          $.validator.addMethod("regexMatchPCRE", ajaxPCREfn, $.validator.format('The value does not match the expected format.'));
        }
      });
    }
  };
})(jQuery, document, Drupal, window);
