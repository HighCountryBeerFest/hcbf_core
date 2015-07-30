<?php
/**
 * @file
 * hcbf_breweries.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hcbf_breweries_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_hcbf_brewery';
  $strongarm->value = '2';
  $export['ant_hcbf_brewery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_hcbf_brewery';
  $strongarm->value = '[node:field_hcbf_brewery_name]';
  $export['ant_pattern_hcbf_brewery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_hcbf_brewery';
  $strongarm->value = 0;
  $export['ant_php_hcbf_brewery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__hcbf_brewery';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '9',
        ),
        'redirect' => array(
          'weight' => '8',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__hcbf_brewery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_hcbf_brewery';
  $strongarm->value = array();
  $export['menu_options_hcbf_brewery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_hcbf_brewery';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_hcbf_brewery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_hcbf_brewery';
  $strongarm->value = array(
    0 => 'revision',
  );
  $export['node_options_hcbf_brewery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_hcbf_brewery';
  $strongarm->value = '1';
  $export['node_preview_hcbf_brewery'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_hcbf_brewery';
  $strongarm->value = 0;
  $export['node_submitted_hcbf_brewery'] = $strongarm;

  return $export;
}
