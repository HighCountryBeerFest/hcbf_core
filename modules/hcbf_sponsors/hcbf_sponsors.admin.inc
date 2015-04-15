<?php
/**
 * @file
 * The admin pages and forms for the High Country Beer Fest site's sponsors admin pages.
 */

/**
 * Callback for the sponsors page.
 */
function hcbf_sponsors_manage() {
  $theme_args = array();

  $sponsors = hcbf_sponsors_current();
  if ($sponsors) {
    $theme_args['sponsors'] = $sponsors;
  }
  else {
    drupal_set_message(t('There are no sponsors registered for this year\'s festival.'), 'warning');
  }

  $all_sponsors = hcbf_sponsors_all();
  if ($all_sponsors) {
    $theme_args['all_sponsors'] = $all_sponsors;
  }

  return theme('hcbf_sponsors_manage', $theme_args);
}

