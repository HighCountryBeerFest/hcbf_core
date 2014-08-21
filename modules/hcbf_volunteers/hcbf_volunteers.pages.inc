<?php
/**
 * @file
 * Page callbacks for the High Country Craft Food and Beverage Festival's volunteer functionality.
 */

/**
 * Page callback for the volunteers export page
 */
function hcbf_volunteer_export() {
  drupal_add_http_header('Content-Type', 'text/csv');
  drupal_add_http_header('Content-Disposition', 'attachment;filename=hcbf_volunteer.csv');

  $fp = fopen('php://output', 'w');

  $header = array(
    'name',
    'dob',
    'phone',
    'email',
    'shirt_size',
    'shift',
    'job',
    'comments',
  );

  fputcsv($fp, $header);

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'hcbf_volunteer')
    ->propertyOrderBy('created', 'DESC');

  $result = $query->execute();
  $volunteer_nids = array_keys($result['node']);

  foreach ($volunteer_nids as $volunteer) {
    $volunteer_entity = entity_metadata_wrapper('node', $volunteer);

    $line = array(
      $volunteer_entity->field_hcbf_volunteer_name->value(),
      $volunteer_entity->field_hcbf_volunteer_dob->value(),
      $volunteer_entity->field_hcbf_volunteer_phone->value(),
      $volunteer_entity->field_hcbf_volunteer_email->value(),
      $volunteer_entity->field_hcbf_volunteer_shirt->value(),
      $volunteer_entity->field_hcbf_volunteer_shift->value(),
      $volunteer_entity->field_hcbf_volunteer_job->value(),
      $volunteer_entity->field_hcbf_volunteer_comments->value(),
    );

    fputcsv($fp, $line);
  }

  fclose($fp);
  drupal_exit();
}

/**
 * Page callback for the breweries page.
 */
function hcbf_volunteer_manage() {

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'hcbf_volunteer')
    ->propertyOrderBy('created', 'DESC');

  $result = $query->execute();
  $volunteer_nids = array_keys($result['node']);

  $volunteers = array();
  $count = 0;
  foreach ($volunteer_nids as $volunteer) {
    $volunteer_entity = entity_metadata_wrapper('node', $volunteer);
    $count++;

    $approved = array(
      '#type' => 'markup',
      '#markup' => 'Accepted',
    );
    $row_class = 'success';
    if ($volunteer_entity->field_hcbf_volunteer_accepted->value() == 'no') {
      $approved['#markup'] = 'Not accepted';
      $row_class = 'danger';
    }

    $volunteers[] = array(
      'count' => array(
        '#type' => 'markup',
        '#markup' => $count,
      ),
      'name' => array(
        '#type' => 'markup',
        '#markup' => $volunteer_entity->label(),
      ),
      'phone' => array(
        '#type' => 'markup',
        '#markup' => $volunteer_entity->field_hcbf_volunteer_phone->value(),
        '#prefix' => '<a href="tel:' . $volunteer_entity->field_hcbf_volunteer_phone->value() . '">',
        '#suffix' => '</a>'
      ),
      'job' => array(
        '#type' => 'markup',
        '#markup' => $volunteer_entity->field_hcbf_volunteer_job->optionsList()[$volunteer_entity->field_hcbf_volunteer_job->value()],
      ),
      'shift' => array(
        '#type' => 'markup',
        '#markup' => $volunteer_entity->field_hcbf_volunteer_shift->optionsList()[$volunteer_entity->field_hcbf_volunteer_shift->value()],
      ),
      'approved' => $approved,
      'email' => array(
        '#type' => 'markup',
        '#markup' => l(t('Email'), 'mailto:' . $volunteer_entity->field_hcbf_volunteer_email->value(), array('absolute' => TRUE)),
        '#prefix' => '<i class="fa fa-inbox"></i> ',
      ),
      'shirt_size' => array(
        '#type' => 'markup',
        '#markup' => $volunteer_entity->field_hcbf_volunteer_shirt->value(),
      ),
      'view' => array(
        '#type' => 'markup',
        '#markup' => l(t('View'), 'node/' . $volunteer_entity->nid->value()),
        '#prefix' => '<span class="glyphicon glyphicon-search"></span> ',
      ),
      'edit' => array(
        '#type' => 'markup',
        '#markup' => l(t('Edit'), 'node/' . $volunteer_entity->nid->value() . '/edit', array('query' => array('destination' => 'volunteer/manage'))),
        '#prefix' => '<span class="glyphicon glyphicon-pencil"></span> ',
      ),
      'delete' => array(
        '#type' => 'markup',
        '#markup' => l(t('Delete'), 'node/' . $volunteer_entity->nid->value() . '/delete', array('query' => array('destination' => 'volunteer/manage'))),
        '#prefix' => '<span class="glyphicon glyphicon-trash"></span> ',
      ),
      'row_class' => $row_class,
    );
  }

  return theme('hcbf_volunteer_manage', array('volunteers' => $volunteers));
}

