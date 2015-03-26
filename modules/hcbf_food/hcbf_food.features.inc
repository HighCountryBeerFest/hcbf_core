<?php
/**
 * @file
 * hcbf_food.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hcbf_food_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function hcbf_food_node_info() {
  $items = array(
    'hcbf_food' => array(
      'name' => t('Food Vendor'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
