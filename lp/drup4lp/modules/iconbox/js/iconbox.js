(function ($) {

  // Behavior to load iconbox
  Drupal.behaviors.iconbox = {
    attach: function(context, settings) {
      $('.iconbox', context).once('iconbox', function() {
        $(this).each(function() {

          /*--- get max icon width ----*/
          fa_icon_size = 0;
          $(this).find(".iconbox-icon .fa").each(function(){
            fa_width = parseInt($(this).width());
            if (fa_width > fa_icon_size) {
              fa_icon_size = fa_width;
            }
          });

          if($(this).find(".iconbox-icon-size-custom").length>0 && $(this).find(".iconbox-icon-style-none").length==0){
	        fa_icon_size = fa_icon_size+(fa_icon_size/2);
          }

          $(this).find(".iconbox-icon .fa").width(fa_icon_size);
          $(this).find(".iconbox-icon .fa").height(fa_icon_size);
          $(this).find(".iconbox-icon .fa").css('line-height', fa_icon_size+'px');
          fa_icon_pos_left = $(this).find(".iconbox-icon-position-left");
          fa_icon_pos_right = $(this).find(".iconbox-icon-position-right");
          fa_icon_pos_boxcut = $(this).find(".iconbox-icon-position-boxcut");

          if(fa_icon_pos_left.length>0){
	        $(this).find( ".iconbox-title-content" ).css('margin-left', fa_icon_size+20);
          }
          if(fa_icon_pos_right.length>0){
	        $(this).find( ".iconbox-title-content" ).css('margin-right', fa_icon_size+20);
          }
          if(fa_icon_pos_boxcut.length>0){
            padding_top = parseInt($(this).find(".iconbox-box").css('padding-top'));
	        $(this).find(".iconbox-box").css('margin-top', (fa_icon_size/2));
	        $(this).find(".iconbox-icon").css('margin-top', -(padding_top + fa_icon_size/2));
          }

          /*--- get max iconbox box height ----*/
          box_height = 0;
          $(this).find(".iconbox-box").each(function(){
            b_height = parseInt($(this).height());
            if (b_height > box_height) {
              box_height = b_height;
            }
          });
          $(this).find(".iconbox-box").height(box_height);

        }); 
      });
    }
  };

}(jQuery));