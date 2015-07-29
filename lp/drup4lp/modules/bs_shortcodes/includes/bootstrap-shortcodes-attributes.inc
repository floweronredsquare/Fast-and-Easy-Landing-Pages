<?php
/**
 * @file
 * Adds attribute callbacks for shortcode wysiwyg integration
 * @author Jurriaan Roelofs
 * @see migrate-attributes-github2drupal.html
 * @see https://github.com/filipstefansson/bootstrap-3-shortcodes/blob/master/README.md
 */

function bs_shortcodes_container_attributes($form, $form_state) {
  $form['fluid'] = array(
  '#type' => 'select',
  '#title' => t('fluid'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'container'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'container'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'container'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_row_attributes($form, $form_state) {
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'row'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'row'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_column_attributes($form, $form_state) {
  $form['xs'] = array(
  '#type' => 'select',
  '#title' => t('xs'),
  '#options' => array(
    '' => t('None'),
    '1' => t('1'),
    '2' => t('2'),
    '3' => t('3'),
    '4' => t('4'),
    '5' => t('5'),
    '6' => t('6'),
    '7' => t('7'),
    '8' => t('8'),
    '9' => t('9'),
    '10' => t('10'),
    '11' => t('11'),
    '12' => t('12'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'column'),
    ),
  ),
  '#prefix' => '<div class="col-md-4">',
  '#suffix' => '</div>',
  );
  $form['sm'] = array(
  '#type' => 'select',
  '#title' => t('sm'),
  '#options' => array(
    '' => t('None'),
    '1' => t('1'),
    '2' => t('2'),
    '3' => t('3'),
    '4' => t('4'),
    '5' => t('5'),
    '6' => t('6'),
    '7' => t('7'),
    '8' => t('8'),
    '9' => t('9'),
    '10' => t('10'),
    '11' => t('11'),
    '12' => t('12'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'column'),
    ),
  ),
  '#prefix' => '<div class="col-md-4">',
  '#suffix' => '</div>',
  );
  $form['md'] = array(
  '#type' => 'select',
  '#title' => t('md'),
  '#options' => array(
    '' => t('None'),
    '1' => t('1'),
    '2' => t('2'),
    '3' => t('3'),
    '4' => t('4'),
    '5' => t('5'),
    '6' => t('6'),
    '7' => t('7'),
    '8' => t('8'),
    '9' => t('9'),
    '10' => t('10'),
    '11' => t('11'),
    '12' => t('12'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'column'),
    ),
  ),
  '#prefix' => '<div class="col-md-4">',
  '#suffix' => '</div>',
  );
  $form['lg'] = array(
  '#type' => 'select',
  '#title' => t('lg'),
  '#options' => array(
    '' => t('None'),
    '1' => t('1'),
    '2' => t('2'),
    '3' => t('3'),
    '4' => t('4'),
    '5' => t('5'),
    '6' => t('6'),
    '7' => t('7'),
    '8' => t('8'),
    '9' => t('9'),
    '10' => t('10'),
    '11' => t('11'),
    '12' => t('12'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'column'),
    ),
  ),
  '#prefix' => '<div class="col-md-4">',
  '#suffix' => '</div>',
  );
  $form['offset_xs'] = array(
  '#type' => 'select',
  '#title' => t('offset_xs'),
  '#options' => array(
    '' => t('None'),
    '1' => t('1'),
    '2' => t('2'),
    '3' => t('3'),
    '4' => t('4'),
    '5' => t('5'),
    '6' => t('6'),
    '7' => t('7'),
    '8' => t('8'),
    '9' => t('9'),
    '10' => t('10'),
    '11' => t('11'),
    '12' => t('12'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'column'),
    ),
  ),
  '#prefix' => '<div class="col-md-4">',
  '#suffix' => '</div>',
  );
  $form['offset_sm'] = array(
  '#type' => 'select',
  '#title' => t('offset_sm'),
  '#options' => array(
    '' => t('None'),
    '1' => t('1'),
    '2' => t('2'),
    '3' => t('3'),
    '4' => t('4'),
    '5' => t('5'),
    '6' => t('6'),
    '7' => t('7'),
    '8' => t('8'),
    '9' => t('9'),
    '10' => t('10'),
    '11' => t('11'),
    '12' => t('12'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'column'),
    ),
  ),
  '#prefix' => '<div class="col-md-4">',
  '#suffix' => '</div>',
  );
  $form['offset_md'] = array(
  '#type' => 'select',
  '#title' => t('offset_md'),
  '#options' => array(
    '' => t('None'),
    '1' => t('1'),
    '2' => t('2'),
    '3' => t('3'),
    '4' => t('4'),
    '5' => t('5'),
    '6' => t('6'),
    '7' => t('7'),
    '8' => t('8'),
    '9' => t('9'),
    '10' => t('10'),
    '11' => t('11'),
    '12' => t('12'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'column'),
    ),
  ),
  '#prefix' => '<div class="col-md-4">',
  '#suffix' => '</div>',
  );
  $form['offset_lg'] = array(
  '#type' => 'select',
  '#title' => t('offset_lg'),
  '#options' => array(
    '' => t('None'),
    '1' => t('1'),
    '2' => t('2'),
    '3' => t('3'),
    '4' => t('4'),
    '5' => t('5'),
    '6' => t('6'),
    '7' => t('7'),
    '8' => t('8'),
    '9' => t('9'),
    '10' => t('10'),
    '11' => t('11'),
    '12' => t('12'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'column'),
    ),
  ),
  '#prefix' => '<div class="col-md-4">',
  '#suffix' => '</div>',
  );
  $form['pull_xs'] = array(
  '#type' => 'select',
  '#title' => t('pull_xs'),
  '#options' => array(
    '' => t('None'),
    '1' => t('1'),
    '2' => t('2'),
    '3' => t('3'),
    '4' => t('4'),
    '5' => t('5'),
    '6' => t('6'),
    '7' => t('7'),
    '8' => t('8'),
    '9' => t('9'),
    '10' => t('10'),
    '11' => t('11'),
    '12' => t('12'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'column'),
    ),
  ),
  '#prefix' => '<div class="col-md-4">',
  '#suffix' => '</div>',
  );
  $form['pull_sm'] = array(
  '#type' => 'select',
  '#title' => t('pull_sm'),
  '#options' => array(
    '' => t('None'),
    '1' => t('1'),
    '2' => t('2'),
    '3' => t('3'),
    '4' => t('4'),
    '5' => t('5'),
    '6' => t('6'),
    '7' => t('7'),
    '8' => t('8'),
    '9' => t('9'),
    '10' => t('10'),
    '11' => t('11'),
    '12' => t('12'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'column'),
    ),
  ),
  '#prefix' => '<div class="col-md-4">',
  '#suffix' => '</div>',
  );
  $form['pull_md'] = array(
  '#type' => 'select',
  '#title' => t('pull_md'),
  '#options' => array(
    '' => t('None'),
    '1' => t('1'),
    '2' => t('2'),
    '3' => t('3'),
    '4' => t('4'),
    '5' => t('5'),
    '6' => t('6'),
    '7' => t('7'),
    '8' => t('8'),
    '9' => t('9'),
    '10' => t('10'),
    '11' => t('11'),
    '12' => t('12'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'column'),
    ),
  ),
  '#prefix' => '<div class="col-md-4">',
  '#suffix' => '</div>',
  );
  $form['pull_lg'] = array(
  '#type' => 'select',
  '#title' => t('pull_lg'),
  '#options' => array(
    '' => t('None'),
    '1' => t('1'),
    '2' => t('2'),
    '3' => t('3'),
    '4' => t('4'),
    '5' => t('5'),
    '6' => t('6'),
    '7' => t('7'),
    '8' => t('8'),
    '9' => t('9'),
    '10' => t('10'),
    '11' => t('11'),
    '12' => t('12'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'column'),
    ),
  ),
  '#prefix' => '<div class="col-md-4">',
  '#suffix' => '</div>',
  );
  $form['push_xs'] = array(
  '#type' => 'select',
  '#title' => t('push_xs'),
  '#options' => array(
    '' => t('None'),
    '1' => t('1'),
    '2' => t('2'),
    '3' => t('3'),
    '4' => t('4'),
    '5' => t('5'),
    '6' => t('6'),
    '7' => t('7'),
    '8' => t('8'),
    '9' => t('9'),
    '10' => t('10'),
    '11' => t('11'),
    '12' => t('12'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'column'),
    ),
  ),
  '#prefix' => '<div class="col-md-4">',
  '#suffix' => '</div>',
  );
  $form['push_sm'] = array(
  '#type' => 'select',
  '#title' => t('push_sm'),
  '#options' => array(
    '' => t('None'),
    '1' => t('1'),
    '2' => t('2'),
    '3' => t('3'),
    '4' => t('4'),
    '5' => t('5'),
    '6' => t('6'),
    '7' => t('7'),
    '8' => t('8'),
    '9' => t('9'),
    '10' => t('10'),
    '11' => t('11'),
    '12' => t('12'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'column'),
    ),
  ),
  '#prefix' => '<div class="col-md-4">',
  '#suffix' => '</div>',
  );
  $form['push_md'] = array(
  '#type' => 'select',
  '#title' => t('push_md'),
  '#options' => array(
    '' => t('None'),
    '1' => t('1'),
    '2' => t('2'),
    '3' => t('3'),
    '4' => t('4'),
    '5' => t('5'),
    '6' => t('6'),
    '7' => t('7'),
    '8' => t('8'),
    '9' => t('9'),
    '10' => t('10'),
    '11' => t('11'),
    '12' => t('12'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'column'),
    ),
  ),
  '#prefix' => '<div class="col-md-4">',
  '#suffix' => '</div>',
  );
  $form['push_lg'] = array(
  '#type' => 'select',
  '#title' => t('push_lg'),
  '#options' => array(
    '' => t('None'),
    '1' => t('1'),
    '2' => t('2'),
    '3' => t('3'),
    '4' => t('4'),
    '5' => t('5'),
    '6' => t('6'),
    '7' => t('7'),
    '8' => t('8'),
    '9' => t('9'),
    '10' => t('10'),
    '11' => t('11'),
    '12' => t('12'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'column'),
    ),
  ),
  '#prefix' => '<div class="col-md-4">',
  '#suffix' => '</div>',
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'column'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'column'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_lead_attributes($form, $form_state) {
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'lead'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'lead'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_emphasis_attributes($form, $form_state) {
  $form['type'] = array(
  '#type' => 'select',
  '#title' => t('type'),
  '#options' => array(
    'muted' => t('muted'),
    'primary' => t('primary'),
    'success' => t('success'),
    'info' => t('info'),
    'warning' => t('warning'),
    'danger' => t('danger'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'emphasis'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'emphasis'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'emphasis'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_code_attributes($form, $form_state) {
  $form['inline'] = array(
  '#type' => 'select',
  '#title' => t('inline'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'code'),
    ),
  ),
  );
  $form['scrollable'] = array(
  '#type' => 'select',
  '#title' => t('scrollable'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'code'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'code'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'code'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_table_wrap_attributes($form, $form_state) {
  $form['bordered'] = array(
  '#type' => 'select',
  '#title' => t('bordered'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'table-wrap'),
    ),
  ),
  );
  $form['striped'] = array(
  '#type' => 'select',
  '#title' => t('striped'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'table-wrap'),
    ),
  ),
  );
  $form['hover'] = array(
  '#type' => 'select',
  '#title' => t('hover'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'table-wrap'),
    ),
  ),
  );
  $form['condensed'] = array(
  '#type' => 'select',
  '#title' => t('condensed'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'table-wrap'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'table-wrap'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'table-wrap'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_button_attributes($form, $form_state) {
  $form['type'] = array(
  '#type' => 'select',
  '#title' => t('type'),
  '#options' => array(
    '' => t('default'),
    'primary' => t('primary'),
    'success' => t('success'),
    'info' => t('info'),
    'warning' => t('warning'),
    'danger' => t('danger'),
    'link' => t('link'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'button'),
    ),
  ),
  );
  $form['size'] = array(
  '#type' => 'select',
  '#title' => t('size'),
  '#options' => array(
    '' => t('default'),
    'xs' => t('xs'),
    'sm' => t('sm'),
    'lg' => t('lg'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'button'),
    ),
  ),
  );
  $form['block'] = array(
  '#type' => 'select',
  '#title' => t('block'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'button'),
    ),
  ),
  );
  $form['dropdown'] = array(
  '#type' => 'select',
  '#title' => t('dropdown'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'button'),
    ),
  ),
  );
  $form['active'] = array(
  '#type' => 'select',
  '#title' => t('active'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'button'),
    ),
  ),
  );
  $form['disabled'] = array(
  '#type' => 'select',
  '#title' => t('disabled'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'button'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'button'),
      ),
    ),
  );
  $form['link'] = array(
    '#type' => 'textfield',
    '#title' => t('link'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'button'),
      ),
    ),
  );
  $form['target'] = array(
    '#type' => 'textfield',
    '#title' => t('target'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'button'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'button'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_img_attributes($form, $form_state) {
  $form['type'] = array(
  '#type' => 'select',
  '#title' => t('type'),
  '#options' => array(
    'rounded' => t('rounded'),
    'circle' => t('circle'),
    'thumbnail' => t('thumbnail'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'img'),
    ),
  ),
  );
  $form['responsive'] = array(
  '#type' => 'select',
  '#title' => t('responsive'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'img'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'img'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'img'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_reponsive_attributes($form, $form_state) {
  $form['visible'] = array(
  '#type' => 'select',
  '#title' => t('visible'),
  '#options' => array(
    'xs' => t('xs'),
    'sm' => t('sm'),
    'md' => t('md'),
    'lg' => t('lg'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'reponsive'),
    ),
  ),
  );
  $form['hidden'] = array(
  '#type' => 'select',
  '#title' => t('hidden'),
  '#options' => array(
    'xs' => t('xs'),
    'sm' => t('sm'),
    'md' => t('md'),
    'lg' => t('lg'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'reponsive'),
    ),
  ),
  );
  $form['block'] = array(
  '#type' => 'select',
  '#title' => t('block'),
  '#options' => array(
    'xs' => t('xs'),
    'sm' => t('sm'),
    'md' => t('md'),
    'lg' => t('lg'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'reponsive'),
    ),
  ),
  );
  $form['inline'] = array(
  '#type' => 'select',
  '#title' => t('inline'),
  '#options' => array(
    'xs' => t('xs'),
    'sm' => t('sm'),
    'md' => t('md'),
    'lg' => t('lg'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'reponsive'),
    ),
  ),
  );
  $form['inline_block'] = array(
  '#type' => 'select',
  '#title' => t('inline_block'),
  '#options' => array(
    'xs' => t('xs'),
    'sm' => t('sm'),
    'md' => t('md'),
    'lg' => t('lg'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'reponsive'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'reponsive'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'reponsive'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_icon_attributes($form, $form_state) {
  $form['type'] = array(
    '#type' => 'textfield',
    '#title' => t('type'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'icon'),
      ),
    ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'icon'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'icon'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_button_group_attributes($form, $form_state) {
  $form['size'] = array(
  '#type' => 'select',
  '#title' => t('size'),
  '#options' => array(
    '' => t('default'),
    'xs' => t('xs'),
    'sm' => t('sm'),
    'lg' => t('lg'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'button-group'),
    ),
  ),
  );
  $form['justified'] = array(
  '#type' => 'select',
  '#title' => t('justified'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'button-group'),
    ),
  ),
  );
  $form['vertical'] = array(
  '#type' => 'select',
  '#title' => t('vertical'),
  '#options' => array(
    'falsetd>' => t('falsetd>'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'button-group'),
    ),
  ),
  );
  $form['dropup'] = array(
  '#type' => 'select',
  '#title' => t('dropup'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'button-group'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'button-group'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'button-group'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_button_toolbar_attributes($form, $form_state) {
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'button-toolbar'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'button-toolbar'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_dropdown_attributes($form, $form_state) {
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'dropdown'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'dropdown'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_dropdown_item_attributes($form, $form_state) {
  $form['link'] = array(
    '#type' => 'textfield',
    '#title' => t('link'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'dropdown-item'),
      ),
    ),
  );
  $form['disabled'] = array(
  '#type' => 'select',
  '#title' => t('disabled'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'dropdown-item'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'dropdown-item'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'dropdown-item'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_dropdown_header_attributes($form, $form_state) {
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'dropdown-header'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'dropdown-header'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_caret_attributes($form, $form_state) {
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'caret'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'caret'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_divider_attributes($form, $form_state) {
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'divider'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'divider'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_nav_attributes($form, $form_state) {
  $form['type'] = array(
  '#type' => 'select',
  '#title' => t('type'),
  '#options' => array(
    'tabs' => t('tabs'),
    'pills' => t('pills'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'nav'),
    ),
  ),
  );
  $form['stacked'] = array(
  '#type' => 'select',
  '#title' => t('stacked'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'nav'),
    ),
  ),
  );
  $form['justified'] = array(
  '#type' => 'select',
  '#title' => t('justified'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'nav'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'nav'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'nav'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_nav_item_attributes($form, $form_state) {
  $form['link'] = array(
    '#type' => 'textfield',
    '#title' => t('link'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'nav-item'),
      ),
    ),
  );
  $form['active'] = array(
  '#type' => 'select',
  '#title' => t('active'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'nav-item'),
    ),
  ),
  );
  $form['disabled'] = array(
  '#type' => 'select',
  '#title' => t('disabled'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'nav-item'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'nav-item'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'nav-item'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_breadcrumb_attributes($form, $form_state) {
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'breadcrumb'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'breadcrumb'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_breadcrumb_item_attributes($form, $form_state) {
  $form['link'] = array(
    '#type' => 'textfield',
    '#title' => t('link'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'breadcrumb-item'),
      ),
    ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'breadcrumb-item'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'breadcrumb-item'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_label_attributes($form, $form_state) {
  $form['type'] = array(
  '#type' => 'select',
  '#title' => t('type'),
  '#options' => array(
    '' => t('default'),
    'primary' => t('primary'),
    'success' => t('success'),
    'info' => t('info'),
    'warning' => t('warning'),
    'danger' => t('danger'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'label'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'label'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'label'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_badge_attributes($form, $form_state) {
  $form['right'] = array(
  '#type' => 'select',
  '#title' => t('right'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'badge'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'badge'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'badge'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_jumbotron_attributes($form, $form_state) {
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('title'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'jumbotron'),
      ),
    ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'jumbotron'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'jumbotron'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_page_header_attributes($form, $form_state) {
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'page-header'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'page-header'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_thumbnail_attributes($form, $form_state) {
  $form['has_content'] = array(
  '#type' => 'select',
  '#title' => t('has_content'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'thumbnail'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'thumbnail'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'thumbnail'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_alert_attributes($form, $form_state) {
  $form['type'] = array(
  '#type' => 'select',
  '#title' => t('type'),
  '#options' => array(
    'success' => t('success'),
    'info' => t('info'),
    'warning' => t('warning'),
    'danger' => t('danger'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'alert'),
    ),
  ),
  );
  $form['dismissable'] = array(
  '#type' => 'select',
  '#title' => t('dismissable'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'alert'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'alert'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'alert'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_progress_attributes($form, $form_state) {
  $form['striped'] = array(
  '#type' => 'select',
  '#title' => t('striped'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'progress'),
    ),
  ),
  );
  $form['animated'] = array(
  '#type' => 'select',
  '#title' => t('animated'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'progress'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'progress'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'progress'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_progress_bar_attributes($form, $form_state) {
  $form['percent'] = array(
    '#type' => 'textfield',
    '#title' => t('percent'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'progress-bar'),
      ),
    ),
  );
  $form['label'] = array(
  '#type' => 'select',
  '#title' => t('label'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'progress-bar'),
    ),
  ),
  );
  $form['type'] = array(
  '#type' => 'select',
  '#title' => t('type'),
  '#options' => array(
    '' => t('default'),
    'primary' => t('primary'),
    'success' => t('success'),
    'info' => t('info'),
    'warning' => t('warning'),
    'danger' => t('danger'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'progress-bar'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'progress-bar'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'progress-bar'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_media_attributes($form, $form_state) {
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'media'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'media'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_media_object_attributes($form, $form_state) {
  $form['pull'] = array(
  '#type' => 'select',
  '#title' => t('pull'),
  '#options' => array(
    'left' => t('left'),
    'right' => t('right'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'media-object'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'media-object'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'media-object'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_media_body_attributes($form, $form_state) {
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('title'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'media-body'),
      ),
    ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'media-body'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'media-body'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_list_group_attributes($form, $form_state) {
  $form['linked'] = array(
  '#type' => 'select',
  '#title' => t('linked'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'list-group'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'list-group'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'list-group'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_list_group_item_attributes($form, $form_state) {
  $form['link'] = array(
    '#type' => 'textfield',
    '#title' => t('link'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'list-group-item'),
      ),
    ),
  );
  $form['type'] = array(
  '#type' => 'select',
  '#title' => t('type'),
  '#options' => array(
    '' => t('default'),
    'primary' => t('primary'),
    'success' => t('success'),
    'info' => t('info'),
    'warning' => t('warning'),
    'danger' => t('danger'),
    'link' => t('link'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'list-group-item'),
    ),
  ),
  );
  $form['active'] = array(
  '#type' => 'select',
  '#title' => t('active'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'list-group-item'),
    ),
  ),
  );
  $form['target'] = array(
    '#type' => 'textfield',
    '#title' => t('target'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'list-group-item'),
      ),
    ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'list-group-item'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'list-group-item'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_list_group_item_heading_attributes($form, $form_state) {
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'list-group-item-heading'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'list-group-item-heading'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_list_group_item_text_attributes($form, $form_state) {
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'list-group-item-text'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'list-group-item-text'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_panel_attributes($form, $form_state) {
  $form['type'] = array(
  '#type' => 'select',
  '#title' => t('type'),
  '#options' => array(
    '' => t('default'),
    'primary' => t('primary'),
    'success' => t('success'),
    'info' => t('info'),
    'warning' => t('warning'),
    'danger' => t('danger'),
    'link' => t('link'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'panel'),
    ),
  ),
  );
  $form['heading'] = array(
    '#type' => 'textfield',
    '#title' => t('heading'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'panel'),
      ),
    ),
  );
  $form['title'] = array(
  '#type' => 'select',
  '#title' => t('title'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'panel'),
    ),
  ),
  );
  $form['footer'] = array(
    '#type' => 'textfield',
    '#title' => t('footer'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'panel'),
      ),
    ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'panel'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'panel'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_well_attributes($form, $form_state) {
  $form['size'] = array(
  '#type' => 'select',
  '#title' => t('size'),
  '#options' => array(
    'sm' => t('sm'),
    'lg' => t('lg'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'well'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'well'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'well'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_tabs_attributes($form, $form_state) {
  $form['type'] = array(
  '#type' => 'select',
  '#title' => t('type'),
  '#options' => array(
    'tabs' => t('tabs'),
    'pills' => t('pills'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'tabs'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'tabs'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'tabs'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_tab_attributes($form, $form_state) {
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('title'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'tab'),
      ),
    ),
  );
  $form['active'] = array(
  '#type' => 'select',
  '#title' => t('active'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'tab'),
    ),
  ),
  );
  $form['fade'] = array(
  '#type' => 'select',
  '#title' => t('fade'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'tab'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'tab'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'tab'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_tooltip_attributes($form, $form_state) {
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('title'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'tooltip'),
      ),
    ),
  );
  $form['placement'] = array(
  '#type' => 'select',
  '#title' => t('placement'),
  '#options' => array(
    'left' => t('left'),
    'top' => t('top'),
    'bottom' => t('bottom'),
    'right' => t('right'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'tooltip'),
    ),
  ),
  );
  $form['animation'] = array(
    '#type' => 'textfield',
    '#title' => t('animation'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'tooltip'),
      ),
    ),
  );
  $form['html'] = array(
  '#type' => 'select',
  '#title' => t('html'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'tooltip'),
    ),
  ),
  );
  return $form;

}

function bs_shortcodes_popover_attributes($form, $form_state) {
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('title'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'popover'),
      ),
    ),
  );
  $form['text'] = array(
    '#type' => 'textfield',
    '#title' => t('text'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'popover'),
      ),
    ),
  );
  $form['placement'] = array(
  '#type' => 'select',
  '#title' => t('placement'),
  '#options' => array(
    'left' => t('left'),
    'top' => t('top'),
    'bottom' => t('bottom'),
    'right' => t('right'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'popover'),
    ),
  ),
  );
  $form['animation'] = array(
    '#type' => 'textfield',
    '#title' => t('animation'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'popover'),
      ),
    ),
  );
  $form['html'] = array(
  '#type' => 'select',
  '#title' => t('html'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'popover'),
    ),
  ),
  );
  return $form;

}

function bs_shortcodes_collapsibles_attributes($form, $form_state) {
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'collapsibles'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'collapsibles'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_collapse_attributes($form, $form_state) {
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('title'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'collapse'),
      ),
    ),
  );
  $form['type'] = array(
  '#type' => 'select',
  '#title' => t('type'),
  '#options' => array(
    '' => t('default'),
    'primary' => t('primary'),
    'success' => t('success'),
    'info' => t('info'),
    'warning' => t('warning'),
    'danger' => t('danger'),
    'link' => t('link'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'collapse'),
    ),
  ),
  );
  $form['active'] = array(
  '#type' => 'select',
  '#title' => t('active'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'collapse'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'collapse'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'collapse'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_carousel_attributes($form, $form_state) {
  $form['interval'] = array(
    '#type' => 'textfield',
    '#title' => t('interval'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'carousel'),
      ),
    ),
  );
  $form['wrap'] = array(
  '#type' => 'select',
  '#title' => t('wrap'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'carousel'),
    ),
  ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'carousel'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'carousel'),
      ),
    ),
  );
  return $form;

}

function bs_shortcodes_carousel_item_attributes($form, $form_state) {
  $form['active'] = array(
  '#type' => 'select',
  '#title' => t('active'),
  '#options' => array(
    '' => t('false'),
    'true' => t('true'),
  ),
  '#states' => array(
    'visible' => array(
      ':input[name="shortcode"]' => array('value' => 'carousel-item'),
    ),
  ),
  );
  $form['caption'] = array(
    '#type' => 'textfield',
    '#title' => t('caption'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'carousel-item'),
      ),
    ),
  );
  $form['xclass'] = array(
    '#type' => 'textfield',
    '#title' => t('xclass'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'carousel-item'),
      ),
    ),
  );
  $form['data'] = array(
    '#type' => 'textfield',
    '#title' => t('data'),
    '#size' => 30,
    '#maxlength' => 30,
    '#states' => array(
      'visible' => array(
        ':input[name="shortcode"]' => array('value' => 'carousel-item'),
      ),
    ),
  );
  return $form;

}
