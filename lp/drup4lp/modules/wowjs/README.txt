
-- SUMMARY --

* This module integrates the wow.js library (http://mynameismatthieu.com/WOW/)
 into Drupal. WOW is a Javascript library which works nicely with the Animate
 CSS library to create great cross browser CSS3-based animations in your
 Drupal sites.

* The Animate CSS library provides a complete set of CSS3 animations you can
 apply to any HTML element in your Drupal site using some JQuery code or
 providing some CSS classes on your templates for the HTML elements you want to
 animate. You can see this animations in action in the Animate CSS library's
 webpage: http://daneden.github.io/animate.css/.

* The wow.js library provides more control over those animations, letting you
 to set how many times an animation will be repeated, how much time the
 animation will last, how much time the animation will delay until it will
 start, etc.

* The wow.js library provides another nice feature: if you use the Animate CSS
 library only and you set an animation for an HTML element which is outside the
 fold, when you scroll down the page to see that HTML element, the CSS
 animation will probably have finished. Using the wow.js library with the
 Animate CSS library, the CSS animations of the HTML elements will start when
 those elements become visible as you scroll down the page. You can see a demo
 in the wow.js librarys's home page (http://mynameismatthieu.com/WOW/).

-- REQUIREMENTS --

This module requires the following modules:
* Libraries module (https://www.drupal.org/project/libraries)
* WOW Javascript library (https://github.com/matthieua/WOW)

-- INSTALLATION --

* Download WOW Javascript library from github
 (https://github.com/matthieua/WOW/archive/master.zip).

* Extract the library from the .zip file and rename the extracted folder to
 "wow".

* Copy the "wow" folder to the "sites/all/libraries" folder of your site.

* Check the "wow.min.js" file is located at 
 "sites/all/libraries/wow/dist/wow.min.js" in your site.

* Install this module as usual, see http://drupal.org/node/70151 for further
 information.

* Go to "Reports > Status Report" in the administration interface of your
 Drupal site. If the wow.js library is not correctly installed, you'll see an
 error. Otherwise you'll see a message telling you which version of the WOW
 Javascript library is installed.

This module provides a drush command which executes steps 1 to 4. So, if you
use drush, you can install this module and the required wow.js library this
way:

* Install this module.

* From the command line, clean drush's cache with this command: drush cc drush

* Execute the wowjs command: drush wowjs

* Go to "Reports > Status Report" in the administration interface of your
 Drupal site. If the wow.js library is not correctly installed, you'll see an
 error. Otherwise you'll see a message telling you which version of the WOW
 Javascript library is installed.

* One final step: go to "Configuration > Development > Performance" on your
 Drupal website's administration interface and clear all Drupal's caches.

-- CONFIGURATION --

* By default, this module will load the wow.js library on every page of your
 website. If you only want to load the wow.js library in certain pages, go
 to your theme's configuration settings page and provide the list of pages
 where you want the wow.js library to be loaded (or not loaded). This module
 integrates with Drupal's core PHP filter module, so you can load the wow.js
 library on those pages where certain PHP expression returns true.

-- CUSTOMIZATION --

-- TROUBLESHOOTING --

-- FAQ --

-- CONTACT --

Current maintainers:
* Ángel Fariña (GoddamnNoise) - http://www.drupal.org/user/795168
* David Cereijo (dcereijo)    - http://www.drupal.org/user/1108366

This project has been sponsored by:
* Karakana Factoría TIC
  Spanish software development shop specialized in consulting and planning 
  of Drupal powered sites, Karakana Factoría TIC offers installation, 
  development, theming, customization, and hosting to get you started. 
  Visit http://www.karakana.es for more information.
