<?php
/**
 * @file
 * Page callbacks for the High Country Craft Food and Beverage Festival's Sponsors page.
 */

/**
 * Page callback for the sponsors page.
 */
function hcbf_sponsors() {
  drupal_set_title('');
  drupal_add_css(drupal_get_path('module', 'hcbf_sponsors') . '/css/hcbf_sponsors.css');

  $sponsors = hcbf_sponsors_current();

  return theme('hcbf_sponsors', array(
    'sponsors' => $sponsors,
  ));
}
