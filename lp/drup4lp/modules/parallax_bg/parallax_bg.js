/**
* @file
* Javascript, modifications of DOM.
*
* Manipulates links to include jquery load funciton
*/

(function ($) {
  Drupal.behaviors.parallax_bg = {
    attach: function (context, settings) {
      var triggers = Drupal.settings.parallax_bg.triggers_fieldset;
      //.parallax(xPosition, speedFactor, outerHeight) options:
      //xPosition - Horizontal position of the element
      //inertia - speed to move relative to vertical scroll. 
      //Example: 0.1 is one tenth the speed of scrolling, 2 is twice the
      //speed of scrolling
      //outerHeight (true/false) - Whether or not jQuery should use it's 
      //outerHeight option to determine when a section is in the     viewport
      $.each(triggers, function(key, trigger) {
        $(trigger.element).parallax(trigger.position, parseFloat(trigger.speed));
      });
    }
  };  

}(jQuery));
