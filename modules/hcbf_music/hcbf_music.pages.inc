<?php
/**
 * @file
 * Page callbacks for the High Country Craft Food and Beverage Festival's website.
 */

/**
 * Page callback for the music page.
 */
function hcbf_music() {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'hcbf_band')
    ->propertyOrderBy('created', 'ASC');

  $result = $query->execute();
  $band_nids = array_keys($result['node']);

  $bands = array();
  foreach ($band_nids as $band) {
    $band_entity = entity_metadata_wrapper('node', $band);
    $band_image = '<img src=' . image_style_url('medium', $band_entity->field_hcbf_band_image->value()['uri']) . ' class="img-responsive center-block" />';
    $new_band = array(
      'image' => array(
        '#type' => 'markup',
        '#markup' => $band_image,
        '#prefix' => '<div class="text-center">',
        '#suffix' => '</div>'
      ),
      'title' => array(
        '#type' => 'markup',
        '#markup' => $band_entity->label(),
        '#prefix' => '<h2>',
        '#suffix' => '</h2>',
      ),
      'description' => array(
        '#type' => 'markup',
        '#markup' => $band_entity->field_hcbf_band_description->value(),
        '#prefix' => '<p class="lead">',
        '#suffix' => '</p>'
      ),
      'website' => array(),
    );

    $band_website = $band_entity->field_hcbf_band_website->value();
    if ($band_website) {
      $new_band['website'] = array(
        '#type' => 'markup',
        '#markup' => l(t('View website'), 
          $band_entity->field_hcbf_band_website->url->value(),
          array(
            'attributes' => array(
              'class' => array('btn', 'btn-default'),
            ),
          )
        ),
        '#prefix' => '<p>',
        '#suffix' => '</p>'
      );
    }
    $bands[] = $new_band;
  }

  return theme('hcbf_music', array('bands' => $bands));
}

