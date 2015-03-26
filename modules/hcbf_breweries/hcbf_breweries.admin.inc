<?php
/**
 * @file
 * The admin pages and forms for the High Country Beer Fest site's breweries admin pages.
 */

/**
 * Callback for the breweries page.
 */
function hcbf_breweries_manage() {
  $theme_args = array();

  $breweries = hcbf_breweries_current();
  if ($breweries) {
    $theme_args['breweries'] = $breweries;
  }

  return theme('hcbf_breweries_manage', $theme_args);
}
