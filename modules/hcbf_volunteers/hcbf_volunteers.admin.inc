<?php
/**
 * @file
 * The admin pages and forms for the High Country Beer Fest site's volunteer admin pages.
 */

function hcbf_volunteers_admin() {
  $form = array();

  $form['core'] = array(
    '#type' => 'fieldset',
    '#title' => 'HCBF volunteer options',
  );

  $form['core']['hcbf_volunteer_registration'] = array(
    '#type' => 'select',
    '#title' => t('Is volunteer registration open?'),
    '#default_value' => variable_get('hcbf_volunteer_registration', 0),
    '#options' => array(
      0 => 'No',
      1 => 'Yes',
    ),
    '#description' => t('Should users be able to register to become volunteers?'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

