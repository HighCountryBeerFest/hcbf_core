<?php
/**
 * @file
 * Page callbacks for the High Country Craft Food and Beverage Festival's website.
 */

/**
 * Page callback for the homepage.
 */
function hcbf_home() {
  $wheat_image = '/' . drupal_get_path('module', 'hcbf_home') . '/images/wheat.png';

  return theme('hcbf_home', array('wheat_image' => $wheat_image));
}

