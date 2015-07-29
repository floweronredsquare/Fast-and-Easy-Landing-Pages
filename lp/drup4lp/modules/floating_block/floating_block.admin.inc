<?php

/**
 * @file
 * Admin page callbacks for the floating_block module.
 */

/**
 * Form to config floating block settings.
 */
function floating_block_admin() {
  $form = array();

  $form['floating_blocks'] = array(
    '#type' => 'textarea',
    '#title' => t('Floating block settings'),
    '#default_value' => _floating_block_admin_convert_array_to_text(variable_get('floating_blocks', array())),
    '#description' => t('Floating block configurations, one per line in the formation <code>[css selector]|[extra settings]</code>.'),
  );

  $form['floating_block_min_width'] = array(
    '#type' => 'textfield',
    '#title' => t('Disable floating blocks for screens under this width'),
    '#description' => t('Use any value that could be used in a !code min-width query, for example, %example. Set to 0 to leave floating blocks enabled for all screen sizes.',
      array(
        '!code' => '<code>window.mediaMatch</code>',
        '%example' => '850px',
      )),
    '#default_value' => variable_get('floating_block_min_width', 0),
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

function floating_block_admin_validate($form, &$form_state) {
  $array = _floating_block_admin_convert_text_to_array($form_state['values']['floating_blocks']);
  $string = _floating_block_admin_convert_array_to_text($array);

  // Compare that floating block settings string to array conversion is
  // idempotent. New line characters \n and \r get make comparison difficult.
  if (str_replace(array("\n", "\r"), '', $string) != str_replace(array("\n", "\r"), '', $form_state['values']['floating_blocks'])) {
    form_set_error('floating_blocks', t('Each line must of the format: <code>selector|setting_key=setting_value,setting_key=setting_value,...</code>'));
  }
}

/**
 * Submit handler for floating_block admin form.
 *
 * Saves floating_blocks variable.
 */
function floating_block_admin_submit($form, &$form_state) {
  variable_set('floating_blocks', _floating_block_admin_convert_text_to_array($form_state['values']['floating_blocks']));
  variable_set('floating_block_min_width', $form_state['values']['floating_block_min_width']);
  drupal_set_message(t('The configuration options have been saved.'));
}

/**
 * Converts a string representation of floating block settings to an array.
 *
 * @param $floating_blocks
 *   A string representation of floating block settings.
 *
 * @return
 *   An array representation of floating block settings.
 */
function _floating_block_admin_convert_text_to_array($floating_blocks) {
  $floating_blocks = preg_split("/(\r\n|\n)/", $floating_blocks, NULL, PREG_SPLIT_NO_EMPTY);
  $output = array();

  foreach ($floating_blocks as $floating_block) {
    $settings = explode('|', $floating_block);
    $output[$settings[0]] = array();
    if (isset($settings[1])) {
      preg_match_all("/([^=|,]*)=([^=|,]*),?/", $settings[1], $matches, PREG_SET_ORDER);
      foreach ($matches as $match) {
        $output[$settings[0]][$match[1]] = $match[2];
      }
    }
  }
  return $output;
}

/**
 * Converts an array representation of floating block settings to a string.
 *
 * @param $floating_blocks
 *   An array representation of floating block settings.
 *
 * @return
 *   A string representation of floating block settings.
 */
function _floating_block_admin_convert_array_to_text($floating_blocks) {
  $output = array();
  foreach ($floating_blocks as $selector => $settings) {
    $output_line = $selector;
    if (count($settings)) {
      $settings_line = array();
      foreach ($settings as $key => $value) {
        $settings_line[] = $key . '=' . $value;
      }
      $output_line .= '|' . implode(',', $settings_line);
    }
    $output[] = $output_line;
  }
  return implode("\n", $output);
}
