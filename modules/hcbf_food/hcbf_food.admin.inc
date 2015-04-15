<?php
/**
 * @file
 * The admin pages and forms for the High Country Beer Fest site's food admin pages.
 */

/**
 * Callback for the food admin page.
 */
function hcbf_food_manage() {
  $theme_args = array();

  $food = hcbf_food_current();
  if ($food) {
    $theme_args['food'] = $food;
  }
  else {
    drupal_set_message(t('There are no food vendors registered for this year\'s festival.'), 'warning');
  }

  $all_food = hcbf_food_all();
  if ($all_food) {
    $theme_args['all_food'] = $all_food;
  }

  return theme('hcbf_food_manage', $theme_args);
}
