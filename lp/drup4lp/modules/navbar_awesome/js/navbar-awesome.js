/**
 * @file
 * Defines the behavior of the Drupal administration navbar.
 */

(function ($, Backbone, Drupal) {

  "use strict";

  /**
   * Navbar sets up quite a few things through JavaScript.
   * @todo: From 1.4 to dev some of these events have changed.
   */
  Drupal.behaviors.navbarAwesome = {
    attach: function(context, settings) {
      var navbarAwesome = Drupal.navbarAwesome;

      // Some events do not automatially broadcast, so we need to invoke.
      navbarAwesome.setupNavbarAwesome(context, settings);


      // Monitor orientation changes to change chevron direction.
      $(document).bind('drupalNavbarOrientationChange', function(event, orientation) {
        navbarAwesome.orientationIcons(context, settings, orientation);
      });

      // Monitor active tab changes to change chevron direction.
      $(document).bind('drupalNavbarTabChange', function(event, tab) {
        navbarAwesome.tabUpdateToggles(context, tab);
      });


    }
  };

  Drupal.navbarAwesome = {

    toggles: {},

    /**
     * Sets up Navbar Awesome's customization on load.
     *
     * @param context
     * @param settings
     */
    setupNavbarAwesome: function(context, settings) {

      // Setup initial icons for vertical orientation
      if ($('body').hasClass('navbar-vertical')) {

        // Set the orientation icons.
        this.orientationIcons(context, settings, 'vertical');

      }
      // Setup initial icons for horizontal orientation.
      else {
        this.orientationIcons(context, settings, 'horizontal');
      }
    },

    /**
     * Adds proper chevron for orientation toggle.
     *
     * @param context
     * @param settings
     * @param orientation
     */
    orientationIcons: function(context, settings, orientation) {
      var orientationButton = $('#navbar-administration .navbar-toggle-orientation button.navbar-toggle', context);

      var verticalIcon = 'fa-chevron-up';
      var horizontalIcon = 'fa-chevron-left';
      if (Drupal.settings.navbarAwesome !== undefined) {
        verticalIcon = Drupal.settings.navbarAwesome.vertical || verticalIcon;
        horizontalIcon = Drupal.settings.navbarAwesome.horizontal || horizontalIcon;
      }
      // Add fa class.
      $(orientationButton)
        .addClass('fa')
        .toggleClass(verticalIcon, (orientation === 'vertical'))
        .toggleClass(horizontalIcon, (orientation === 'horizontal'));

      // When moving to vertical, we need to add handle toggles.
      if (orientation == 'vertical') {
        // We send a junk tab string so that we'll check.
        // @todo: actually check if tab open.
        this.tabUpdateToggles(context, 'navbar-item');
      }

    },

    /**
     * Reacts on a tab change
     *
     * @param context
     * @param tab
     */
    tabUpdateToggles: function(context, tab) {
      console.log('update toggles');
      if (typeof tab !== 'undefined') {
        this.getToggles(context);

        $(this.toggles).each(function() {
          Drupal.navbarAwesome.toggleIcons(this);

          $(this).bind('click', function(e) {
            Drupal.navbarAwesome.toggleIcons(this, e);
          });
        });
      }
    },

    /**
     * Sets all of the available toggle elements.
     *
     * When a tab is open, this will collect all of the available toggle handles
     * so that they can have proper icons assigned.
     *
     * @param context
     */
    getToggles: function(context) {
      this.toggles = $(context).find('#navbar-administration .navbar-box .navbar-handle');
    },

    /**
     * Sets the up/down chevron for toggle handles.
     * @param el
     */
    toggleIcons: function(el, e) {

      var toggleState = $(el).hasClass('open');

      // Having this function setup icons on load and on click is causing
      // goofy actions.
      // @todo: revise this hack.
      if (typeof  e !== 'undefined') {
        toggleState = toggleState ? false : true;
      }

      $(el)
        .toggleClass('fa-chevron-down', !toggleState)
        .toggleClass('fa-chevron-up', toggleState);
    }
  };

}(jQuery, Backbone, Drupal));
