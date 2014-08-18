<?php
/**
 * @file
 * Page callbacks for the High Country Craft Food and Beverage Festival's Sponsors page.
 */

/**
 * Generates the sponsor array
 */
function hcbf_sponsors_get_by_level($level, $chunk) {
  // Get all of the published breweries.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'hcbf_sponsor')
    ->propertyCondition('status', 1)
    ->fieldCondition('field_hcbf_sponsor_sponsor_level', 'value', $level, '=')
    ->propertyOrderBy('created', 'DESC');

  $result = $query->execute();
  $nids = array_keys($result['node']);
  $sponsors = array();
  foreach ($nids as $top) {
    $sponsor_entity = entity_metadata_wrapper('node', $top);

    if ($sponsor_entity->field_hcbf_sponsor_image->value()) {
      $sponsor_logo = '<img src=' . image_style_url('medium', $sponsor_entity->field_hcbf_sponsor_image->value()['uri']) . ' title="' . $sponsor_entity->label(). '" class="img-responsive center-block" />';
    }
    else {
      $sponsor_logo = '<i class="fa fa-leaf no-sponsor-image"></i>';
    }

    if ($sponsor_entity->field_hcbf_sponsor_sponsor_url->url->value()) {
      $sponsor_link = l($sponsor_entity->label(), $sponsor_entity->field_hcbf_sponsor_sponsor_url->url->value());
    }
    else {
      $sponsor_link = $sponsor_entity->label();
    }

    $sponsors[] = array(
      'logo' => array(
        '#type' => 'markup',
        '#markup' => $sponsor_logo,
        '#prefix' => '<div class="text-center">',
        '#suffix' => '</div>'
      ),
      'title' => array(
        '#type' => 'markup',
        '#markup' => $sponsor_link,
        '#prefix' => '<h2 class="text-center">',
        '#suffix' => '</h2>',
      ),
    );
  }
  $sponsors = array_chunk($sponsors, $chunk);

  return $sponsors;
}

/**
 * Page callback for the sponsors page.
 */
function hcbf_sponsors() {
  drupal_set_title('');

  drupal_add_css(drupal_get_path('module', 'hcbf_sponsors') . '/css/hcbf_sponsors.css');

  $level_4_sponsors = hcbf_sponsors_get_by_level(4, 2);
  $level_3_sponsors = hcbf_sponsors_get_by_level(3, 3);
  $level_2_sponsors = hcbf_sponsors_get_by_level(2, 3);
  $level_1_sponsors = hcbf_sponsors_get_by_level(1, 3);

  return theme('hcbf_sponsors', array(
    'level_4_sponsors' => $level_4_sponsors,
    'level_3_sponsors' => $level_3_sponsors,
    'level_2_sponsors' => $level_2_sponsors,
    'level_1_sponsors' => $level_1_sponsors,
  ));
}

