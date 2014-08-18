<?php
/**
 * @file
 * Page callbacks for the High Country Craft Food and Beverage Festival's about pages.
 */

/**
 * Page callback for the about page.
 */
function hcbf_about() {

  drupal_add_css(drupal_get_path('module', 'hcbf_about') . '/css/hcbf_about.css');

  return theme('hcbf_about');
}

