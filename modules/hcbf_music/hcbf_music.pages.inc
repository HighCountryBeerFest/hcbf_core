<?php
/**
 * @file
 * Page callbacks for the High Country Craft Food and Beverage Festival's website.
 */

/**
 * Page callback for the music page.
 */
function hcbf_music() {

  $bands = array();

  return theme('hcbf_music');
}
