<?php
/**
 * @file
 * Page callbacks for the High Country Craft Food and Beverage Festival's brewery functionality.
 */

/**
 * Page callback for the breweries page.
 */
function hcbf_breweries_manage() {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'hcbf_brewery')
    ->propertyOrderBy('created', 'DESC');

  $result = $query->execute();
  $brewery_nids = array_keys($result['node']);

  $breweries = array();
  foreach ($brewery_nids as $brewery) {
    $brewery_entity = entity_metadata_wrapper('node', $brewery);

    $approved = array(
      '#type' => 'markup',
      '#markup' => 'Accepted',
    );
    $row_class = 'success';
    if ($brewery_entity->field_hcbf_brewery_accepted->value() == 'no') {
      $approved['#markup'] = 'Not accepted';
      $row_class = 'danger';
    }

    $breweries[] = array(
      'name' => array(
        '#type' => 'markup',
        '#markup' => $brewery_entity->label(),
      ),
      'city' => array(
        '#type' => 'markup',
        '#markup' => $brewery_entity->field_hcbf_brewery_brewery_city->value(),
      ),
      'view' => array(
        '#type' => 'markup',
        '#markup' => l(t('View'), 'node/' . $brewery_entity->nid->value()),
        '#prefix' => '<span class="glyphicon glyphicon-search"></span> ',
      ),
      'edit' => array(
        '#type' => 'markup',
        '#markup' => l(t('Edit'), 'node/' . $brewery_entity->nid->value() . '/edit', array('query' => array('destination' => 'breweries/manage'))),
        '#prefix' => '<span class="glyphicon glyphicon-pencil"></span> ',
      ),
      'delete' => array(
        '#type' => 'markup',
        '#markup' => l(t('Delete'), 'node/' . $brewery_entity->nid->value() . '/delete', array('query' => array('destination' => 'breweries/manage'))),
        '#prefix' => '<span class="glyphicon glyphicon-trash"></span> ',
      ),
      'row_class' => $row_class,
    );
  };

  return theme('hcbf_breweries_manage', array('breweries' => $breweries));
}

/**
 * Page callback for the breweries page.
 */
function hcbf_breweries() {

  drupal_add_css(drupal_get_path('module', 'hcbf_breweries') . '/css/hcbf_breweries.css');
  drupal_set_title(t('The breweries'));

  // Get all of the published breweries.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'hcbf_brewery')
    ->propertyCondition('status', 1)
    ->fieldCondition('field_hcbf_brewery_accepted', 'value', 'yes', '=')
    ->propertyOrderBy('title', 'ASC');

  $result = $query->execute();
  $breweries_nids = array_keys($result['node']);

  $breweries = array();
  foreach ($breweries_nids as $brewery) {
    $brewery_entity = entity_metadata_wrapper('node', $brewery);
    $brewery_logo = '<img src=' . image_style_url('medium', $brewery_entity->field_hcbf_brewery_logo->value()['uri']) . ' class="img-responsive center-block" />';
    $brewery_link = l($brewery_entity->label(), $brewery_entity->field_hcbf_brewery_brewery_url->value()); 

    $breweries[] = array(
      'logo' => array(
        '#type' => 'markup',
        '#markup' => $brewery_logo,
        '#prefix' => '<div class="text-center">',
        '#suffix' => '</div>'
      ),
      'title' => array(
        '#type' => 'markup',
        '#markup' => $brewery_link,
        '#prefix' => '<h2 class="text-center">',
        '#suffix' => '</h2>',
      ),
      'location' => array(
        '#type' => 'markup',
        '#markup' => $brewery_entity->field_hcbf_brewery_brewery_city->value() . ', ' . $brewery_entity->field_hcbf_brewery_brewery_state->value(),
        '#prefix' => '<p class="text-center">',
        '#suffix' => '</p>',
      ),
    );
  }

  $breweries = array_chunk($breweries, 3);
  return theme('hcbf_breweries', array('breweries' => $breweries));
}

