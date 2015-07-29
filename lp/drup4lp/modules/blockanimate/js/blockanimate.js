/**
 * Initialization of the WOW Javscript object.
 */

(function($) {
  $(document).ready(function($){
    if (typeof WOW === 'function') {
      // Check if class exists, then initialize WOW object.
      new WOW().init();
    }
  });
})(jQuery);
