<?php
/**
 * @file
 * hcbf_sponsors.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hcbf_sponsors_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function hcbf_sponsors_node_info() {
  $items = array(
    'hcbf_sponsor' => array(
      'name' => t('Sponsor'),
      'base' => 'node_content',
      'description' => t('A sponsor that will be participating in the High Country Craft Food and Beverage Festival'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
