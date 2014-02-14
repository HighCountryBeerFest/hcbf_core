<?php
/**
 * @file
 * hcbf_volunteers.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hcbf_volunteers_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function hcbf_volunteers_node_info() {
  $items = array(
    'hcbf_volunteer' => array(
      'name' => t('Volunteer'),
      'base' => 'node_content',
      'description' => t('A volunteer that will be volunteering for the High Country Craft Food and Beverage Festival.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
