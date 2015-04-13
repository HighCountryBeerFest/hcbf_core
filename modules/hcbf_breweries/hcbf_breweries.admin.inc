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

  $all_breweries = hcbf_breweries_all();
  if ($all_breweries) {
    $theme_args['all_breweries'] = $all_breweries;
  }

  return theme('hcbf_breweries_manage', $theme_args);
}
