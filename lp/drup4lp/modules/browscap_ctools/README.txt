
/**
 * @file
 * README file for Browscap CTools.
 */
 
Provides access plugin for CTools using browscap_get_browser(), will return TRUE
if mobile device is detected (whatever Browscap returns as ismobiledevice).

Requires the Browscap module, CTools (Page manager) and Panels:

http://drupal.org/project/browscap
http://drupal.org/project/ctools
http://drupal.org/project/panels


Install as usual, should be under Other package right below Browscap.

 - visit your Panel "Content" tab.
 - under Visibility rules for a pane select "add new rule".
 - check "Is Mobile", click next.

If you want to show the pane just click save and you are done.

If you want to hide the pane in mobile check the "Reverse (NOT)" checkbox
and save.
