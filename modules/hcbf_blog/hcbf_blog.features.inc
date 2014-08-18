<?php
/**
 * @file
 * hcbf_blog.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hcbf_blog_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function hcbf_blog_node_info() {
  $items = array(
    'hcbf_post' => array(
      'name' => t('Post'),
      'base' => 'node_content',
      'description' => t('Content that is blog related.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
