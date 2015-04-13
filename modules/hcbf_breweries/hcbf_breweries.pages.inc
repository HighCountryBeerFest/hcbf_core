<?php
/**
 * @file
 * Page callbacks for the High Country Craft Food and Beverage Festival's brewery functionality.
 */

/**
 * Page callback for the breweries export page
 */
function hcbf_breweries_export() {
  drupal_add_http_header('Content-Type', 'text/csv');
  drupal_add_http_header('Content-Disposition', 'attachment;filename=hcbfbreweries.csv');

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'hcbf_brewery')
    ->propertyOrderBy('created', 'DESC');

  $result = $query->execute();
  $brewery_nids = array_keys($result['node']);

  $fp = fopen('php://output', 'w');
  
  $header = array(
    'Name',
    'Address 1',
    'Address 2',
    'City',
    'State',
    'Zip Code',
    'Website',
    'Primary Contact Name',
    'Primary Contact Email',
    'Secondary Contact Name',
    'Secondary Contact Phone Number',
    'Secondary Contact Email',
    'Who will deliver your product',
    'The name of your distributor',
    'Are you bringing your own staff to pour beer?',
    'Do you need a hotel room?',
    'What beers do you plan to bring?',
    'Additional Comments',
    'Hotel night',
    'Hotel Bed',
    'Staff members',
  );

  fputcsv($fp, $header);

  foreach ($brewery_nids as $brewery) {
    $brewery_entity = entity_metadata_wrapper('node', $brewery);
    $line = array(
      $brewery_entity->label(),
      $brewery_entity->field_hcbf_brewery_brewery_addy1->value(),
      $brewery_entity->field_hcbf_brewery_brewery_addy2->value(),
      $brewery_entity->field_hcbf_brewery_brewery_city->value(),
      $brewery_entity->field_hcbf_brewery_brewery_state->value(),
      $brewery_entity->field_hcbf_brewer_brewery_zip->value(),
      $brewery_entity->field_hcbf_brewery_brewery_url->value(),
      $brewery_entity->field_hcbf_brewery_primary_name->value(),
      $brewery_entity->field_hcbf_brewery_second_name->value(),
      $brewery_entity->field_hcbf_brewery_second_phone->value(),
      $brewery_entity->field_hcbf_brewery_second_email->value(),
      $brewery_entity->field_hcbf_brewery_deliver->value(),
      $brewery_entity->field_hcbf_brewery_distributer->value(),
      ($brewery_entity->field_hcbf_brewery_staff->value() == 1) ? "Yes": "No",
      ($brewery_entity->field_hcbf_brewery_hotel->value() == 1) ? "Yes": "No",
      $brewery_entity->field_hcbf_brewery_beers->value(),
      $brewery_entity->field_hcbf_brewery_comments->value(),
      $brewery_entity->field_hcbf_brewery_hotel_night->value(),
      $brewery_entity->field_hcbf_brewery_hotel_bed->value(),
      $brewery_entity->field_hcbf_brewery_staff_members->value(),
    );

    fputcsv($fp, $line);
  }

  fclose($fp);
  drupal_exit();
}

/**
 * Page callback for the breweries page.
 */
function hcbf_breweries() {

  drupal_add_css(drupal_get_path('module', 'hcbf_breweries') . '/css/hcbf_breweries.css');
  drupal_set_title(t('The breweries'));

  $brewery_entities = hcbf_breweries_current();

  $breweries = array();
  foreach ($brewery_entities as $brewery) {
    $breweries[] = array(
      'logo' => array(
        '#type' => 'markup',
        '#markup' => $brewery['logo'],
        '#prefix' => '<div class="text-center">',
        '#suffix' => '</div>'
      ),
      'title' => array(
        '#type' => 'markup',
        '#markup' => $brewery['link'],
        '#prefix' => '<h2 class="text-center">',
        '#suffix' => '</h2>',
      ),
      'location' => array(
        '#type' => 'markup',
        '#markup' => $brewery['location'],
        '#prefix' => '<p class="text-center">',
        '#suffix' => '</p>',
      ),
    );
  }

  if (!empty($breweries)) {
    $breweries = array_chunk($breweries, 3);
  }
  return theme('hcbf_breweries', array('breweries' => $breweries));
}
