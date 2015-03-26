<?php
/**
 * @file
 * hcbf_festival.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hcbf_festival_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function hcbf_festival_node_info() {
  $items = array(
    'hcbf_festival' => array(
      'name' => t('Festival'),
      'base' => 'node_content',
      'description' => t('A content type for each year\'s festival. '),
      'has_title' => '1',
      'title_label' => t('Year'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
