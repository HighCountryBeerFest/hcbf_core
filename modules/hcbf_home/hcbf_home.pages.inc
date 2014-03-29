<?php
/**
 * @file
 * Page callbacks for the High Country Craft Food and Beverage Festival's website.
 */

/**
 * Page callback for the homepage.
 */
function hcbf_home() {
  // Load Skrollr library and insert the javascript into the page.
  if (($skrollr = libraries_load('skrollr')) && !empty($skrollr['loaded'])) {
    drupal_add_js(drupal_get_path('module', 'hcbf_home') . '/js/hcbf_home.js');
    drupal_add_css(drupal_get_path('module', 'hcbf_home') . '/css/hcbf_home.css');
  }
  else {
    drupal_set_message('Scrolling failed to load.', 'error');
  }

  return theme('hcbf_home');
}

