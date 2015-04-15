<?php
/**
 * @file
 * Page callbacks for the High Country Craft Food and Beverage Festival's website.
 */

/**
 * Page callback for the music page.
 */
function hcbf_food() {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'hcbf_food')
    ->propertyOrderBy('title', 'ASC');

  $result = $query->execute();
  $food_nids = array_keys($result['node']);

  $food_entities = hcbf_food_current();

  $foods = array();
  foreach ($food_entities as $food) {

    $foods[] = array(
      'image' => array(
        '#type' => 'markup',
        '#markup' => $food['image'],
        '#prefix' => '<div class="text-center">',
        '#suffix' => '</div>'
      ),
      'title' => array(
        '#type' => 'markup',
        '#markup' => l($food['title'], $food['link']),
        '#prefix' => '<h2>',
        '#suffix' => '</h2>',
      ),
      'description' => array(
        '#type' => 'markup',
        '#markup' => $food['description'],
        '#prefix' => '<p class="lead">',
        '#suffix' => '</p>'
      ),
    );
  }

  return theme('hcbf_food', array('foods' => $foods));
}
