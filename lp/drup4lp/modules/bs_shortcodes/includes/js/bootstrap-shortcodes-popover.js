(function($) {
	if (typeof popover == 'function') {
    $("[data-toggle=popover]")
      .on('click', function(e) {e.preventDefault(); return TRUE;})
      .popover()
  }
})(jQuery);
