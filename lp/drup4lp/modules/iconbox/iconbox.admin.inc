<?php
/**
 * @file
 * Administrative page callbacks for iconbox module.
 */

/**
 * Menu callback which shows an overview page of all the iconbox.
 */
function iconbox_overview_page() {
  $result = db_query("SELECT * FROM {iconbox} ORDER BY title", array(), array('fetch' => PDO::FETCH_ASSOC));
  if($result->rowCount() > 0) {
    $header = array(t('Iconbox Name'), array('data' => t('Operations'), 'colspan' => '4'));
    $rows = array();
    foreach ($result as $iconbox) {
      $row = array(theme('iconbox_admin_overview', array('title' => $iconbox['title'], 'name' => $iconbox['iconbox_name'])));
      $row[] = array('data' => l(t('edit'), 'admin/config/user-interface/iconbox/manage/' . $iconbox['iconbox_name'] . '/edit'));
      $row[] = array('data' => l(t('delete'), 'admin/config/user-interface/iconbox/manage/' . $iconbox['iconbox_name'] . '/delete'));
      $row[] = array('data' => l(t('list box'), 'admin/config/user-interface/iconbox/manage/' . $iconbox['iconbox_name']));
      $row[] = array('data' => l(t('add box'), 'admin/config/user-interface/iconbox/manage/' . $iconbox['iconbox_name'] . '/add'));
      $rows[] = $row;
    }
  }
  else {
    $header = array(t('Iconbox Name'), array('data' => t('Operations')));
    $rows = array();
    $rows[] = array(array('data' => t('There are no iconbox yet. <a href="@link">Add iconbox</a>.', 
    array('@link' => url('admin/config/user-interface/iconbox/add'))), 'colspan' => '4'));
  }
  return theme('table', array('header' => $header, 'rows' => $rows));
}

/**
 * Returns HTML for a iconbox title and description for the iconbox overview page.
 *
 * @param $variables
 *   An associative array containing:
 *   - title: The iconbox's title.
 *
 * @ingroup themeable
 */
function theme_iconbox_admin_overview($variables) {
  $output = check_plain($variables['title']);
  return $output;
}

/**
 * Menu callback; Build the form that handles the adding/editing of a iconbox.
 */
function iconbox_edit_box($form, &$form_state, $type, $iconbox = array()) {
  drupal_add_css(drupal_get_path('module', 'iconbox') . '/css/iconbox_admin.css');

  $iconbox += array(
    'iconbox_name' => '',
    'old_name' => !empty($iconbox['iconbox_name']) ? $iconbox['iconbox_name'] : '',
    'title' => '',
    'optionset' => '',
  );
  // Allow iconbox_edit_box_submit() and other form submit handlers to determine
  // whether the iconbox already exists.
  $form['#insert'] = empty($iconbox['old_name']);
  $form['old_name'] = array(
    '#type' => 'value',
    '#value' => $iconbox['old_name'],
  );

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => $iconbox['title'],
    '#required' => TRUE,
  );

  $form['iconbox_name'] = array(
    '#type' => 'machine_name',
    '#title' => t('iconbox name'),
    '#default_value' => $iconbox['iconbox_name'],
    '#maxlength' => 27,
    '#description' => t('A unique name to construct the URL for the iconbox. It must only contain lowercase letters, numbers and hyphens.'),
    '#machine_name' => array(
      'exists' => 'iconbox_edit_box_name_exists',
      'source' => array('title'),
      'replace_pattern' => '[^a-z0-9-]+',
      'replace' => '-',
    ),
    // A iconbox's machine name cannot be changed.
    '#disabled' => !empty($iconbox['old_name']),
  );

  $optionset = unserialize($iconbox['optionset']); // get the icons options from database

  // Grid Type
  $form['grid']['grid'] = array(
    '#type' => 'select',
    '#title' => t('Grid'),
    '#options' => array('1' => 1, 2, 3, 4, 5, 6, 7, 8),
    '#default_value' => isset($optionset['grid']) ? $optionset['grid'] : 3,
  );

  // Appearance Settings
  $form['apperance'] = array(
    '#type' => 'fieldset',
    '#title' => t('Apperance'),
  );
  $form['apperance']['icon-type'] = array(
    '#type' => 'select',
    '#title' => t('Icon Type'),
    '#description' => t("Select icon type."),
    '#options' => array(
      "fontawesome"	=> t('Fontawesome'),
    ),
    '#default_value' => isset($optionset['icon-type']) ? $optionset['icon-type'] : 'fontawesome',
  );
  $form['apperance']['icon-position'] = array(
    '#type' => 'select',
    '#title' => t('Icon Position'),
    '#description' => t("Select icon position."),
    '#options' => array(
      "top"  => t('Top'),
      "left" => t('Left'),
      "right"  => t('Right'),
      "boxcut" => t('Boxcut'),
    ),
    '#default_value' => isset($optionset['icon-position']) ? $optionset['icon-position'] : 'top',
  );
  $form['apperance']['icon-style'] = array(
    '#type' => 'select',
    '#title' => t('Icon Style'),
    '#options' => array(
      "none" => t('None'),
      "circle" => t('Circle'),
      "square"  => t('Square'),
    ),
    '#default_value' => isset($optionset['icon-style']) ? $optionset['icon-style'] : 'none',
  );

/*----------- icon size -----------*/
  $form['apperance']['icon-size-container'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Icon Size'), 
    '#attributes' => array('class' => array('container-inline')), 
  );
  $form['apperance']['icon-size-container']['icon-size'] = array(
    '#type' => 'select',
    '#title' => t('Icon Size'),
    '#title_display' => 'invisible',
    '#options' => array(
      "large"  => t('Large'),
      "medium" => t('Medium'),
      "small"  => t('Small'),
      "custom" => t('Custom'),
    ),
    '#default_value' => isset($optionset['icon-size']) ? $optionset['icon-size'] : 'medium',
  );
  $form['apperance']['icon-size-container']['icon-size-custom'] = array(
    '#type' => 'textfield',
    '#title' => t('Icon Custom Size'),
    '#title_display' => 'invisible',
    '#size' => 10,
    '#maxlenght' => 4,
    '#description' => t('px'),
    '#element_validate' => array('_iconbox_validate_positive_integer'),
    '#default_value' => isset($optionset['icon-size-custom']) ? $optionset['icon-size-custom'] : '30',
    '#states' => array(
      'visible' => array(':input[name="icon-size"]' => array('value' => 'custom')),
      'required' => array(':input[name="icon-size"]' => array('value' => 'custom')),
    ),
  );
/*----------- end icon size -----------*/

/*----------- icon color -----------*/
  $form['apperance']['icon-color-container'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Icon Color'), 
    '#attributes' => array('class' => array('container-inline')), 
  );
  $form['apperance']['icon-color-container']['icon-color'] = array(
    '#type' => 'select',
    '#title' => t('Icon Color'),
    '#title_display' => 'invisible',
    '#options' => array(
      "default" => t('Default'),
      "custom"  => t('Custom'),
    ),
    '#default_value' => isset($optionset['icon-color']) ? $optionset['icon-color'] : 'default',
  );
  $form['apperance']['icon-color-container']['icon-color-custom'] = array(
    '#type' => 'textfield',
    '#title' => t('Icon Custom Color'),
    '#title_display' => 'invisible',
    '#size' => 10,
    '#maxlenght' => 4,
    '#description' => t('Enter background color'),
    '#element_validate' => array('_iconbox_validate_color_value'),
    '#default_value' => isset($optionset['icon-color-custom']) ? $optionset['icon-color-custom'] : '#333333',
    '#states' => array(
      'visible'  => array(':input[name="icon-color"]' => array('value' => 'custom')),
      'required' => array(':input[name="icon-color"]' => array('value' => 'custom')),
    ),
  );
/*----------- end icon color -----------*/

/*----------- icon bg color -----------*/
  $form['apperance']['icon-bg-color-container'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Icon Background Color'), 
    '#attributes' => array('class' => array('container-inline')),
    '#states' => array(
      'invisible'  => array(':input[name="icon-style"]' => array('value' => 'none')),
    ),
  );
  $form['apperance']['icon-bg-color-container']['icon-bg-color'] = array(
    '#type' => 'select',
    '#title' => t('Icon Background Color'),
    '#title_display' => 'invisible',
    '#options' => array(
      "none"	=> t('None'),
      "custom"	=> t('Custom'),
    ),
    '#default_value' => isset($optionset['icon-bg-color']) ? $optionset['icon-bg-color'] : 'none',
  );
  $form['apperance']['icon-bg-color-container']['icon-bg-color-custom'] = array(
    '#type' => 'textfield',
    '#title' => t('Icon Custom Background Color'),
    '#title_display' => 'invisible',
    '#size' => 10,
    '#maxlenght' => 4,
    '#description' => t('Enter background color'),
    '#element_validate' => array('_iconbox_validate_color_value'),
    '#default_value' => isset($optionset['icon-bg-color-custom']) ? $optionset['icon-bg-color-custom'] : '#333333',
    '#states' => array(
      'visible'  => array(':input[name="icon-bg-color"]' => array('value' => 'custom')),
      'required' => array(':input[name="icon-bg-color"]' => array('value' => 'custom')),
    ),
  );
/*----------- end icon bg color -----------*/

/*----------- icon border -----------*/
  $form['apperance']['icon-border-container'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Icon Border'), 
    '#attributes' => array('class' => array('container-inline')),
    '#states' => array(
      'invisible'  => array(':input[name="icon-style"]' => array('value' => 'none')),
    ),
  );
  $form['apperance']['icon-border-container']['icon-border'] = array(
    '#type' => 'checkbox',
    '#title' => t('Icon Border'),
    '#title_display' => 'invisible',
    '#default_value' => isset($optionset['icon-border']) ? $optionset['icon-border'] : false,
  );
  $form['apperance']['icon-border-container']['icon-border-width'] = array(
    '#type' => 'select',
    '#title' => t('Icon Border Width'),
    '#title_display' => 'invisible',
    '#options' => array('1' => 1, 2, 3, 4, 5, 6, 7, 8),
    '#default_value' => isset($optionset['icon-border-width']) ? $optionset['icon-border-width'] : 1,
    '#states' => array(
      'visible'  => array(':input[name="icon-border"]' => array('checked' => TRUE)),
      'required' => array(':input[name="icon-border"]' => array('checked' => TRUE)),
    ),
  );
  $form['apperance']['icon-border-container']['icon-border-style'] = array(
    '#type' => 'select',
    '#title' => t('Icon Border Style'),
    '#title_display' => 'invisible',
    '#options' => array(
      "solid"	=> t('Solid'),
      "dashed"	=> t('Dashed'),
      "dotted"	=> t('Dotted'),
      "double"	=> t('Double'),
    ),
    '#default_value' => isset($optionset['icon-border-style']) ? $optionset['icon-border-style'] : 1,
    '#states' => array(
      'visible'  => array(':input[name="icon-border"]' => array('checked' => TRUE)),
      'required' => array(':input[name="icon-border"]' => array('checked' => TRUE)),
    ),
  );
  $form['apperance']['icon-border-container']['icon-border-color'] = array(
    '#type' => 'select',
    '#title' => t('Icon Border Color'),
    '#title_display' => 'invisible',
    '#options' => array(
      "default"	=> t('Default'),
      "custom"	=> t('Custom'),
    ),
    '#default_value' => isset($optionset['icon-border-color']) ? $optionset['icon-border-color'] : 'default',
    '#states' => array(
      'visible'  => array(':input[name="icon-border"]' => array('checked' => TRUE)),
      'required' => array(':input[name="icon-border"]' => array('checked' => TRUE)),
    ),
  );
  $form['apperance']['icon-border-container']['icon-border-color-custom'] = array(
    '#type' => 'textfield',
    '#title' => t('Icon Custom Border Color'),
    '#title_display' => 'invisible',
    '#size' => 10,
    '#maxlenght' => 4,
    '#description' => t('Enter background color'),
    '#element_validate' => array('_iconbox_validate_color_value'),
    '#default_value' => isset($optionset['icon-border-color-custom']) ? $optionset['icon-border-color-custom'] : '#efefef',
    '#states' => array(
      'visible' => array(
        ':input[name="icon-border"]' => array('checked' => TRUE),
        ':input[name="icon-border-color"]' => array('value' => 'custom'),
      ),
      'required' => array(':input[name="icon-border-color"]' => array('value' => 'custom')),
    ),
  );
/*----------- end icon border -----------*/

/*----------- Box background -----------*/
  $form['apperance']['box-bg-container'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Box Background Color'),
    '#attributes' => array('class' => array('container-inline')), 
  );
  $form['apperance']['box-bg-container']['box-bg-color'] = array(
    '#type' => 'select',
    '#title' => t('Box Background Color'),
    '#title_display' => 'invisible',
    '#options' => array(
      "none"	=> t('None'),
      "custom"	=> t('Custom'),
    ),
    '#default_value' => isset($optionset['box-bg-color']) ? $optionset['box-bg-color'] : 'none',
  );
  $form['apperance']['box-bg-container']['box-bg-color-custom'] = array(
    '#type' => 'textfield',
    '#title' => t('Box Custom Background Color'),
    '#title_display' => 'invisible',
    '#size' => 10,
    '#maxlenght' => 4,
    '#description' => t('Enter background color'),
    '#element_validate' => array('_iconbox_validate_color_value'),
    '#default_value' => isset($optionset['box-bg-color-custom']) ? $optionset['box-bg-color-custom'] : '#efefef',
    '#states' => array(
      'visible'  => array(':input[name="box-bg-color"]' => array('value' => 'custom')),
      'required' => array(':input[name="box-bg-color"]' => array('value' => 'custom')),
    ),
  );
/*----------- end Box background -----------*/

/*----------- box border -----------*/
  $form['apperance']['box-border-container'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Box Border'), 
    '#attributes' => array('class' => array('container-inline')), 
  );
  $form['apperance']['box-border-container']['box-border'] = array(
    '#type' => 'checkbox',
    '#title' => t('Box Border'),
    '#title_display' => 'invisible',
    '#default_value' => isset($optionset['box-border']) ? $optionset['box-border'] : false,
  );
  $form['apperance']['box-border-container']['box-border-width'] = array(
    '#type' => 'select',
    '#title' => t('Box Border Width'),
    '#title_display' => 'invisible',
    '#options' => array('1' => 1, 2, 3, 4, 5, 6, 7, 8),
    '#default_value' => isset($optionset['box-border-width']) ? $optionset['box-border-width'] : 1,
    '#states' => array(
      'visible'  => array(':input[name="box-border"]' => array('checked' => TRUE)),
      'required' => array(':input[name="box-border"]' => array('checked' => TRUE)),
    ),
  );
  $form['apperance']['box-border-container']['box-border-style'] = array(
    '#type' => 'select',
    '#title' => t('Box Border Style'),
    '#title_display' => 'invisible',
    '#options' => array(
      "solid"	=> t('Solid'),
      "dashed"	=> t('Dashed'),
      "dotted"	=> t('Dotted'),
      "double"	=> t('Double'),
    ),
    '#default_value' => isset($optionset['box-border-style']) ? $optionset['box-border-style'] : 1,
    '#states' => array(
      'visible'  => array(':input[name="box-border"]' => array('checked' => TRUE)),
      'required' => array(':input[name="box-border"]' => array('checked' => TRUE)),
    ),
  );
  $form['apperance']['box-border-container']['box-border-color'] = array(
    '#type' => 'select',
    '#title' => t('Box Border Color'),
    '#title_display' => 'invisible',
    '#options' => array(
      "default"	=> t('Default'),
      "custom"	=> t('Custom'),
    ),
    '#default_value' => isset($optionset['box-border-color']) ? $optionset['box-border-color'] : 'default',
    '#states' => array(
      'visible'  => array(':input[name="box-border"]' => array('checked' => TRUE)),
      'required' => array(':input[name="box-border"]' => array('checked' => TRUE)),
    ),
  );
  $form['apperance']['box-border-container']['box-border-color-custom'] = array(
    '#type' => 'textfield',
    '#title' => t('Box Custom Border Color'),
    '#title_display' => 'invisible',
    '#size' => 10,
    '#maxlenght' => 4,
    '#description' => t('Enter background color'),
    '#element_validate' => array('_iconbox_validate_color_value'),
    '#default_value' => isset($optionset['box-border-color-custom']) ? $optionset['box-border-color-custom'] : '#efefef',
    '#states' => array(
      'visible' => array(
        ':input[name="box-border"]' => array('checked' => TRUE),
        ':input[name="box-border-color"]' => array('value' => 'custom'),
      ),
      'required' => array(':input[name="box-border-color"]' => array('value' => 'custom')),
    ),
  );
/*----------- end box border -----------*/

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['actions']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
    '#access' => $type == 'edit',
    '#submit' => array('iconbox_delete_box_submit_call'),
  );
  return $form;
}

/**
 * Returns whether a iconbox name already exists.
 *
 * @see iconbox_edit_box()
 * @see form_validate_machine_name()
 */
function iconbox_edit_box_name_exists($value) {
  // 'iconbox-' is added to the iconbox name to avoid name-space conflicts.
  $value = 'iconbox-' . $value;
  $iconbox_exists = db_query_range('SELECT 1 FROM {iconbox} WHERE iconbox_name = :iconbox', 0, 1, array(':iconbox' => $value))->fetchField();

  return $iconbox_exists;
}

/**
 * Submit function for the 'Delete' button on the iconbox editing form.
 */
function iconbox_delete_box_submit_call($form, &$form_state) {
  $form_state['redirect'] = 'admin/config/user-interface/iconbox/manage/' . $form_state['values']['iconbox_name'] . '/delete';
}

/**
 * Submit function for adding or editing a iconbox.
 */
function iconbox_edit_box_submit($form, &$form_state) {
  $iconbox = $form_state['values'];

  $iconbox['optionset']['grid']						= (int)$form_state['values']['grid'];
  $iconbox['optionset']['icon-type']				= $form_state['values']['icon-type'];
  $iconbox['optionset']['icon-position']			= $form_state['values']['icon-position'];
  $iconbox['optionset']['icon-style']				= $form_state['values']['icon-style'];
  $iconbox['optionset']['icon-size']				= $form_state['values']['icon-size'];
  $iconbox['optionset']['icon-size-custom']			= (int)$form_state['values']['icon-size-custom'];
  $iconbox['optionset']['icon-color']				= $form_state['values']['icon-color'];
  $iconbox['optionset']['icon-color-custom']		= $form_state['values']['icon-color-custom'];
  $iconbox['optionset']['icon-bg-color']			= $form_state['values']['icon-bg-color'];
  $iconbox['optionset']['icon-bg-color-custom']		= $form_state['values']['icon-bg-color-custom'];
  $iconbox['optionset']['icon-border']				= $form_state['values']['icon-border'];
  $iconbox['optionset']['icon-border-width']		= (int)$form_state['values']['icon-border-width'];
  $iconbox['optionset']['icon-border-style']		= $form_state['values']['icon-border-style'];
  $iconbox['optionset']['icon-border-color']		= $form_state['values']['icon-border-color'];
  $iconbox['optionset']['icon-border-color-custom']	= $form_state['values']['icon-border-color-custom'];

  $iconbox['optionset']['box-bg-color']				= $form_state['values']['box-bg-color'];
  $iconbox['optionset']['box-bg-color-custom']		= $form_state['values']['box-bg-color-custom'];
  $iconbox['optionset']['box-border']				= $form_state['values']['box-border'];
  $iconbox['optionset']['box-border-width']			= (int)$form_state['values']['box-border-width'];
  $iconbox['optionset']['box-border-style']			= $form_state['values']['box-border-style'];
  $iconbox['optionset']['box-border-color']			= $form_state['values']['box-border-color'];
  $iconbox['optionset']['box-border-color-custom']	= $form_state['values']['box-border-color-custom'];

  $path = 'admin/config/user-interface/iconbox/';
  if ($form['#insert']) {
    // Add 'iconbox-' to the iconbox name to help avoid name-space conflicts.
    $iconbox['iconbox_name'] = 'iconbox-' . $iconbox['iconbox_name'];
    iconbox_save($iconbox);
  }
  else {
    iconbox_save($iconbox);
  }
  drupal_set_message(t('Your configuration has been saved.'));
  $form_state['redirect'] = $path;
}

/**
 * Menu callback; check access and get a confirm form for deletion of a iconbox.
 */
function iconbox_delete_box($form, &$form_state, $iconbox) {
  $form['#iconbox'] = $iconbox;
  $caption = '';
  $caption .= '<p>' . t('This action cannot be undone.') . '</p>';
  return confirm_form($form, t('Are you sure you want to delete the iconbox %title?', array('%title' => $iconbox['title'])), 
  'admin/config/user-interface/iconbox/', $caption, t('Delete'));
}

/**
 * Delete a iconbox.
 */
function iconbox_delete_box_submit($form, &$form_state) {
  $iconbox = $form['#iconbox'];
  $form_state['redirect'] = 'admin/config/user-interface/iconbox';

  // Delete the iconbox and all its boxes.
  iconbox_delete($iconbox);

  $t_args = array('%title' => $iconbox['title']);
  drupal_set_message(t('The iconbox %title has been deleted.', $t_args));
  watchdog('iconbox', 'Deleted iconbox %title and all its boxes.', $t_args, WATCHDOG_NOTICE);
}

/**
 * Validate a form element that should have an integer value.
 */
function _iconbox_validate_positive_integer($element, &$form_state) {
  $value = $element['#value'];
  if (!is_numeric($value) || intval($value) != $value || $value < 0) {
    form_error($element, t('%name must be a positive integer.', array('%name' => $element['#title'])));
  }
}

/**
 * Validate a form element that should have an valid color value.
 */
function _iconbox_validate_color_value($element, &$form_state) {
  $value = $element['#value'];
  // Only accept hexadecimal CSS color strings.
  if (!preg_match('/^#([a-f0-9]{3}){1,2}$/iD', $value) && $value != 'transparent') {
    form_error($element, t('%name must be a valid hexadecimal CSS color value.', array('%name' => $element['#title'])));
  }
}