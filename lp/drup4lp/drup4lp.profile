<?php

function system_form_install_configure_form_alter(&$form, $form_state) {

  $form['site_information']['site_name']['#default_value'] = 'My first Landing Page';

}


function system_form_install_select_profile_form_alter(&$form, $form_state) {

  foreach ($form['profile'] as $key => $element) {

    $form['profile'][$key]['#value'] = 'drup4lp';

  }

}