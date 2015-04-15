<?php
/**
 * @file
 * The admin pages and forms for the High Country Beer Fest site's music admin pages.
 */

/**
 * Callback for the music page.
 */
function hcbf_music_manage() {
  $theme_args = array();

  $music = hcbf_music_current();
  if ($music) {
    $theme_args['music'] = $music;
  }

  $all_music = hcbf_music_all();
  if ($all_music) {
    $theme_args['all_music'] = $all_music;
  }

  return theme('hcbf_music_manage', $theme_args);
}

