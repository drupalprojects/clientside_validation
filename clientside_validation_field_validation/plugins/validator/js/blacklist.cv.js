/*jshint strict:true, browser:true, curly:true, eqeqeq:true, expr:true, forin:true, latedef:true, newcap:true, noarg:true, trailing: true, undef:true, unused:true */
/*global Drupal: true, jQuery: true*/
/**
 * @file
 * Decimal comma validator.
 */
(function($, document) {
  "use strict";
  //Define a Drupal behaviour with a custom name
  Drupal.behaviors.cvFieldValidationBlacklist = {
    attach: function(context) {
      // Add an eventlistener to the document reacting on the
      // 'clientsideValidationAddCustomRules' event.
      $.validator.addMethod("blacklist", function(value, element, param) {
        if (typeof (value) !== 'object') {
          value = value.split(' ');
        }
        for (var i in value) {
          if (param.values.indexOf(value[i]) !== -1) {
            return param.negate;
          }
        }
        return this.optional(element) || !param.negate;
      });
    }
  };
})(jQuery, document);
