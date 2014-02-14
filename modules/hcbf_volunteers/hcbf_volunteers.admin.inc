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

  return system_settings_form($form);
}

