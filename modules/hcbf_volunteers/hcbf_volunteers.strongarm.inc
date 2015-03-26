<?php
/**
 * @file
 * hcbf_volunteers.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function hcbf_volunteers_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_hcbf_volunteer';
  $strongarm->value = '1';
  $export['ant_hcbf_volunteer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_pattern_hcbf_volunteer';
  $strongarm->value = '[node:field_hcbf_volunteer_name]';
  $export['ant_pattern_hcbf_volunteer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'ant_php_hcbf_volunteer';
  $strongarm->value = 0;
  $export['ant_php_hcbf_volunteer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__hcbf_volunteer';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '-5',
        ),
        'path' => array(
          'weight' => '30',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__hcbf_volunteer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_hcbf_volunteer';
  $strongarm->value = array();
  $export['menu_options_hcbf_volunteer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_hcbf_volunteer';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_hcbf_volunteer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_hcbf_volunteer';
  $strongarm->value = array(
    0 => 'revision',
  );
  $export['node_options_hcbf_volunteer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_hcbf_volunteer';
  $strongarm->value = '1';
  $export['node_preview_hcbf_volunteer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_hcbf_volunteer';
  $strongarm->value = 1;
  $export['node_submitted_hcbf_volunteer'] = $strongarm;

  return $export;
}
