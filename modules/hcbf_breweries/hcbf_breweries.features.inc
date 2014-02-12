<?php
/**
 * @file
 * hcbf_breweries.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hcbf_breweries_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function hcbf_breweries_node_info() {
  $items = array(
    'hcbf_brewery' => array(
      'name' => t('Brewery'),
      'base' => 'node_content',
      'description' => t('A brewery that will be participating in the High Country Craft Food and Beverage Festival'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
