<?php
/**
 * @file
 * hcbf_music.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hcbf_music_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function hcbf_music_node_info() {
  $items = array(
    'hcbf_band' => array(
      'name' => t('Band'),
      'base' => 'node_content',
      'description' => t('A band or artist preforming at the Beer Fest.'),
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  return $items;
}
