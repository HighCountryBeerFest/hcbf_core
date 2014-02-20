<?php
/**
 * @file
 * Admin forms for the High Country Craft Food and Beverage Festival's volunteer functionality.
 */

/**
 * Callback for the admin/config/hcbf_volunteers page.
 */
function hcbf_volunteer_settings_form() {
  $form = array();

  $form['hcbf_volunteer_active'] = array(
    '#type' => 'radios',
    '#title' => t('Is volunteer active?'),
    '#default_value' => variable_get('hcbf_volunteer_active', 0),
    '#options' => array(
      0 => t('No'),
      1 => t('Yes')
    ),
  );

  $form['hcbf_volunteer_intro'] = array(
    '#type' => 'textarea',
    '#title' => t('Intro message'),
    '#default_value' => variable_get('hcbf_volunteer_intro', ''),
    '#description' => t('This message displays on the top of the Volunteer form.')
  );

  return system_settings_form($form);
}

