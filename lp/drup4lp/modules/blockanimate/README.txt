-- SUMMARY --

* Block Animate module extends Drupal’s block configuration system providing
 new fields which let you leverage Animate CSS and WOW Javascript libraries
 to add CSS3 cross-browser animations to any block on your Drupal website.

* Animate CSS library [https://github.com/daneden/animate.css] provides these
 nice CSS3 cross-browser animations, while WOW Javascript library
 [http://mynameismatthieu.com/WOW/docs.html] provides greater control over
 those animations. Thanks to the WOW Javscript library, those animations will
 start when the animated blocks appear as you scroll down the page.

-- REQUIREMENTS --

* This module requires the following modules:

  - Animate CSS [https://www.drupal.org/project/animate_css]

  - WOW JS [https://www.drupal.org/project/wowjs]

-- INSTALLATION --

* Install this module as usual
 [https://www.drupal.org/documentation/install/modules-themes/modules-7].

-- CONFIGURATION --

* Once you’ve installed this module and its dependencies, give the administer
 block animate permission to the roles who will be able to configure the
 animation of the blocks on your Drupal site.

* To configure the animation for one of your blocks, go to “Structure > Blocks”
 and click on the “configure” link of the block you want to animate. On the
 “Animate CSS Animation” section you’ll see these new options:

  - Select Animation: choose the animation effect you want to apply to the
   block or choose “-- No Animation --” if you don’t want any animation applied
   to your block.

  - Apply an infinite loop to this animation: check this if you want the
   animation to repeat forever. If this option is not checked, by default the
   animation will be executed once. You can’t check this option if you provide
   a value for the Animation Iteration option.

* In the “Advanced Options” section you’ve more options which provide you with
 more control over the animation applied to your block:

  - Animation Duration: by default the animation will last 1 second. You can
   set the animation duration in seconds using this field. Examples: 5, 3.8,
   etc.
  
  - Animation Delay: by default the animation will start when the block becomes
   visible. You can add a delay in seconds providing a value for this field.
   Example: if you select 2.5 seconds for this field, the animation will start
   2.5 seconds after the block becomes visible.

  - Animation Offset: by default the animation will start when the block
   becomes visible. You can add an offset in pixels providing a value for this
   field. This offset is measured from the browser bottom. 

  - Animation Iteration: by default the animation will be executed once. You
   can set the number of iterations the animation will be repeated providing a
   value for this field. If you provide a value for this field, uncheck the
   “Apply an infinite loop to this animation” option.

-- RESOURCES --

* If you need more information about these libraries, go to their websites: 

  - More information about Animate CSS library
   [https://github.com/daneden/animate.css].

  - More information about WOW Javscript library
   [http://mynameismatthieu.com/WOW/docs.html].

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
