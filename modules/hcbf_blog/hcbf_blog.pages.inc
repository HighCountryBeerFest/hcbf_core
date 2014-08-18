<?php
/**
 * @file
 * Page callbacks for the High Country Craft Food and Beverage Festival's website.
 */

/**
 * Page callback for the blog page.
 */
function hcbf_blog() {

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'hcbf_post')
    ->propertyCondition('status', 1)
    ->propertyOrderBy('created', 'DESC')
    ->pager(10);

  $result = $query->execute();
  $post_nids = array_keys($result['node']);

  $posts = array();
  foreach ($post_nids as $post) {
    $post_entity = entity_metadata_wrapper('node', $post);
    $post_link = l($post_entity->label(), 'node/' . $post_entity->nid->value());
    $posts[] = array(
      'title' => array(
        '#type' => 'markup',
        '#markup' => $post_link,
        '#prefix' => '<h1>',
        '#suffix' => '</h1>'
      ),
      'body' => array(
        '#type' => 'markup',
        '#markup' => $post_entity->field_hcbf_post_body->value()['safe_value']
      ),
    );
  }

  // Figure out recent posts
  $recent_query = new EntityFieldQuery();
  $recent_query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'hcbf_post')
    ->propertyCondition('status', 1)
    ->propertyOrderBy('created', 'DESC')
    ->range(0, 10);

  $result = $recent_query->execute();
  $recent_post_nids = array_keys($result['node']);

  $recent_posts = array();
  foreach ($recent_post_nids as $post) {
    $post_entity = entity_metadata_wrapper('node', $post);
    $post_link = l($post_entity->label(), 'node/' . $post_entity->nid->value());
    $recent_posts[] = array(
      'link' => array(
        '#type' => 'markup',
        '#markup' => $post_link,
        '#prefix' => '<li>',
        '#suffix' => '</li>'
      ),
    );
  }

  return theme('hcbf_blog', array('posts' => $posts, 'recent_posts' => $recent_posts));
}

