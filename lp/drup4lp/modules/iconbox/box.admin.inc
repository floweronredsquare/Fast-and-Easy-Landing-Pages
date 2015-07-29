<?php
/**
 * Form for editing an entire iconbox box order at once.
 */
function iconbox_box_overview_form($form, &$form_state, $iconbox) {
  $form['iconbox_box']['#tree'] = TRUE;
  $result = db_query("SELECT * FROM {iconbox_box} WHERE iconbox_name = :iconbox ORDER BY weight", 
  array(':iconbox' => $iconbox['iconbox_name']), array('fetch' => PDO::FETCH_ASSOC));

  foreach ($result as $box) {
    $form['iconbox_box'][$box['boxid']] = array(
      'box_title' => array(
        '#markup' => check_plain($box['box_title']),
      ),
      'box_content' => array(
        '#markup' => $box['box_content'],
      ),
      'fontawesome_icon' => array(
        '#markup' => theme('iconbox_fontawesome_icon_build', array('class' => $box['fontawesome_icon'])),
      ),
      'weight' => array(
        '#type' => 'weight',
        '#title' => t('Weight'),
        '#default_value' => $box['weight'],
        '#delta' => 50,
        '#title-display' => 'invisible',
      ),
      'edit' => array('#type' => 'link', '#title' => t('edit'), '#href' => "admin/config/user-interface/iconbox/box/". $box['boxid'] ."/edit"),
      'delete' => array('#type' => 'link', '#title' => t('delete'), '#href' => "admin/config/user-interface/iconbox/box/". $box['boxid'] ."/delete"),
    );
  }

  if (element_children($form['iconbox_box'])) {
    $form['actions'] = array('#type' => 'actions');
    $form['actions']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save configuration'),
    );
  }
  else {
    $form['#empty_text'] = t('There are no box yet. <a href="@link">Add box</a>.', 
    array('@link' => url('admin/config/user-interface/iconbox/manage/'. $iconbox['iconbox_name'] .'/add')));
  }
  return $form;
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
function theme_iconbox_fontawesome_icon_build($variables) {
  $output = '<i class="fa '.$variables['class'].' '.$variables['size'].' '.$variables['looks'].'"' .$variables['style'].'></i>';
  return $output;
}

/**
 * Submit handler for the box overview form.
 * @see box_overview_form()
 */
function iconbox_box_overview_form_submit($form, &$form_state) {
  // Because the form elements were keyed with the item ids from the database,
  // we can simply iterate through the submitted values.
  foreach ($form_state['values']['iconbox_box'] as $boxid => $box) {
    db_query("UPDATE {iconbox_box} SET weight = :weight WHERE boxid = :boxid", array(':weight' => $box['weight'], ':boxid' => $boxid));
  }
}

/**
 * Returns HTML for the box overview form into a table.
 *
 * @param $variables
 *   An associative array containing:
 *   - form: A render element representing the form.
 *
 * @ingroup themeable
 */
function theme_iconbox_box_overview_form($variables) {
  libraries_load('fontawesome'); // load fontawesome css file

  $form = $variables['form'];

  $rows = array();
  foreach (element_children($form['iconbox_box']) as $boxid) {
    $form['iconbox_box'][$boxid]['weight']['#attributes']['class'] = array('iconbox-box-weight');

    $rows[] = array(
      'data' => array(
        drupal_render($form['iconbox_box'][$boxid]['box_title']),
        drupal_render($form['iconbox_box'][$boxid]['fontawesome_icon']),
        drupal_render($form['iconbox_box'][$boxid]['box_content']),
        drupal_render($form['iconbox_box'][$boxid]['weight']),
        drupal_render($form['iconbox_box'][$boxid]['edit']),
        drupal_render($form['iconbox_box'][$boxid]['delete']),
      ),
      'class' => array('draggable'),
    );
  }

  if (empty($rows)) {
    $rows[] = array(array('data' => $form['#empty_text'], 'colspan' => '5'));
  }

  $header = array(t('Box Title'), t('Icon'), t('Box Content'), t('Weight'), t('Edit'), t('Delete'));
  $table_id = 'iconbox-overview';

  $output = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => $table_id),
  ));
  $output .= drupal_render_children($form);
  drupal_add_tabledrag($table_id, 'order', 'sibling', 'iconbox-box-weight');
  return $output;
}

/**
 * Menu callback; Build the iconbox box editing form.
 */
function iconbox_box_edit_box($form, &$form_state, $type, $iconbox, $box) {

  if ($type == 'add' || empty($box)) {
    // This is an add form, initialize the box.
    $box = array('iconbox_name' => $iconbox['iconbox_name'], 'boxid' => 0, 'box_title' => '', 'fontawesome_icon' => 'fa-tablet', 'weight' => 0, 'box_content' => '');
  }

  $form['boxid'] = array(
    '#type' => 'hidden',
    '#value' => $box['boxid'],
  );
  $form['iconbox_name'] = array(
    '#type' => 'hidden',
    '#value' => $box['iconbox_name'],
  );
  $form['box_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Box title'),
    '#default_value' => $box['box_title'],
    '#description' => t('The human-readable name of this box'),
    '#required' => TRUE,
  );
  $form['weight'] = array(
    '#type' => 'weight',
    '#title' => t('Weight'),
    '#delta' => 50,
    '#default_value' => $box['weight'],
    '#description' => t('Optional. Box are displayed in ascending order by weight.'),
  );
  $form['fontawesome_icon'] = array(
    '#type' => 'select',
    '#title' => t('Font Awesome icon'),
    '#options' => iconbox_box_fontawesome_parser(libraries_get_path('fontawesome') . '/css/font-awesome.css'),
    '#default_value' => $box['fontawesome_icon'],
    '#description' => t('Please select font awesome icon. For more info see: <a href="http://fortawesome.github.io/Font-Awesome/cheatsheet/" target="_blank">Font Awesome Cheatsheet</a>.'),
  );
  $form['box_content'] = array(
    '#type' => 'textarea',
    '#title' => t('Box Content'),
    '#default_value' => $box['box_content'],
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['actions']['delete'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
    '#access' => $type == 'edit',
    '#submit' => array('iconbox_box_delete_box_submit_call'),
  );
  return $form;
}

/**
 * Submit function for the delete button on the box editing form.
 */
function iconbox_box_delete_box_submit_call($form, &$form_state) {
  $form_state['redirect'] = 'admin/config/user-interface/iconbox/box/' . $form_state['values']['boxid'] . '/delete';
}

/**
 * Process iconbox box add/edit form submissions.
 */
function iconbox_box_edit_box_submit($form, &$form_state) {
  $box = &$form_state['values'];
  $path = 'admin/config/user-interface/iconbox/manage/';
  iconbox_box_save($box);
  drupal_set_message(t('Your configuration has been saved.'));
  $form_state['redirect'] = $path . $box['iconbox_name'];
}

/**
 * Menu callback; check access and get a confirm form for deletion of a box.
 */
function iconbox_box_delete_box($form, &$form_state, $type, $box) {
  $form['#box'] = $box;
  return confirm_form($form, t('Are you sure you want to delete the box %box?', array('%box' => $box['box_title'])), 'admin/config/user-interface/iconbox/manage/' . $box['iconbox_name']);
}

/**
 * Process box delete form submissions.
 */
function iconbox_box_delete_box_submit($form, &$form_state) {
  $box = $form['#box'];
  iconbox_box_delete($box['boxid']);
  $t_args = array('%title' => $box['box_title']);
  drupal_set_message(t('The iconbox box %title has been deleted.', $t_args));
  watchdog('iconbox', 'Deleted iconbox box %title.', $t_args, WATCHDOG_NOTICE);
  $form_state['redirect'] = 'admin/config/user-interface/iconbox/manage/' . $box['iconbox_name'];
}

/**
 * CSS parser from the file of css.
 */
function iconbox_box_fontawesome_parser($path) {
  $css = drupal_load_stylesheet($path, TRUE);

  preg_match_all( '/(?ims)([a-z0-9\s\.\:#_\-@,]+)\{([^\}]*)\}/', $css, $arr);
  $result = array();
  foreach ($arr[0] as $i => $x) {
    $selector = trim($arr[1][$i]);
    $rules = explode(';', trim($arr[2][$i]));
    $rules_arr = array();
    foreach ($rules as $strRule) {
      if (!empty($strRule)) {
        $rule = explode(":", $strRule);
        $rules_arr[trim($rule[0])] = trim($rule[1]);
      }
    }

    $selectors = explode(',', trim($selector));
    foreach ($selectors as $strSel) {
      if(array_key_exists('content', $rules_arr)) {
        $strSel = substr($strSel, 1, -7);
        $result[$strSel] = $strSel;
      }
    }
  }
  return $result;
}