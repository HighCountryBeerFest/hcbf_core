<?php
/**
 * @file
 * Page callbacks for the High Country Craft Food and Beverage Festival's website.
 */

/**
 * Page callback for the music page.
 */
function hcbf_music() {

  $band_entities = hcbf_music_current();

  $bands = array();
  foreach ($band_entities as $band) {
    $bands[] = array(
      'image' => array(
        '#type' => 'markup',
        '#markup' => $band['image'],
        '#prefix' => '<div class="text-center">',
        '#suffix' => '</div>'
      ),
      'title' => array(
        '#type' => 'markup',
        '#markup' => $band['title'],
        '#prefix' => '<h2>',
        '#suffix' => '</h2>',
      ),
      'description' => array(
        '#type' => 'markup',
        '#markup' => $band['description'],
        '#prefix' => '<p class="lead">',
        '#suffix' => '</p>'
      ),
      'website' => array(
        '#type' => 'markup',
        '#markup' => l(t('View website'), 
          $band['website'],
          array(
            'attributes' => array(
              'class' => array('btn', 'btn-default'),
            ),
          )
        ),
        '#prefix' => '<p>',
        '#suffix' => '</p>'
      ),
    );
  }

  return theme('hcbf_music', array('bands' => $bands));
}

