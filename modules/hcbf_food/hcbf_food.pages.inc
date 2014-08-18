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

  $foods = array();
  foreach ($food_nids as $food) {
    $food_entity = entity_metadata_wrapper('node', $food);
    $food_image = '<img src=' . image_style_url('medium', $food_entity->field_hcbf_food_image->value()['uri']) . ' class="img-responsive center-block" />';

    $new_food = array(
      'image' => array(
        '#type' => 'markup',
        '#markup' => $food_image,
        '#prefix' => '<div class="text-center">',
        '#suffix' => '</div>'
      ),
      'title' => array(
        '#type' => 'markup',
        '#markup' => $food_entity->label(),
        '#prefix' => '<h2>',
        '#suffix' => '</h2>',
      ),
      'description' => array(
        '#type' => 'markup',
        '#markup' => $food_entity->field_hcbf_food_description->value(),
        '#prefix' => '<p class="lead">',
        '#suffix' => '</p>'
      ),
      'website' => array(),
    );

    $food_website = $food_entity->field_hcbf_food_website->value();
    if ($food_website) {
      $new_food['website'] = array(
        '#type' => 'markup',
        '#markup' => l(t('View website'), 
          $food_entity->field_hcbf_food_website->url->value(),
          array(
            'attributes' => array(
              'class' => array('btn', 'btn-default'),
            ),
          )
        ),
        '#prefix' => '<p>',
        '#suffix' => '</p>'
      );
    }
    $foods[] = $new_food;
  }

  return theme('hcbf_food', array('foods' => $foods));
}


