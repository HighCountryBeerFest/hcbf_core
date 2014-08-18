<?php
/**
 * @file
 * hcbf_blog.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hcbf_blog_taxonomy_default_vocabularies() {
  return array(
    'hcbf_post_tags' => array(
      'name' => 'Post Tags',
      'machine_name' => 'hcbf_post_tags',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
