Parallax Background

This a simple module that allows to set a vertical Parallax effect on the background of any element on the DOM.
Installation

Download and enable Parallax Background Module.

From jQuery Parallax on GitHub download, rename and save jquery.scrollTo.js and jquery.parallax.js on the module's /js directory.

They should look like this:
parallax_bg/js/jquery.scrollTo.js
parallax_bg/js/jquery.parallax.js
Configuration

    Goto admin page in /admin/config/user-interface/parallax_bg
    Define the element you want to apply the Parallax effect using any valid jQuery selector. The selector should point to the element that holds the background, for example: #top-content, body.one-page #super-banner
    Additionally you need to define the inertia (relative speed) of the background and its horizontal position.

CSS Note

Depending on the position of your element, you need to apply some top-padding to align the background when entering viewport.
Plugins needed

This module uses the jQuery Parallax and jQuery.ScrollTo plugins.