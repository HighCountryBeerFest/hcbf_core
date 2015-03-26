<?php
/**
 * @file
 * The admin pages and forms for the High Country Beer Fest site's admin pages.
 */

/**
 * Provides a listing page for items.
 */
function hcbf_core_menu_block_page() {
  $item = menu_get_item();
  if ($content = system_admin_menu_block($item)) {
    $output = theme('admin_block_content', array('content' => $content));
  }
  else {
    $output = t('You do not have any administrative items.');
  }
  return $output;
}

/**
 * Callback for the HCBF Core admin page.
 */
function hcbf_core_admin() {
  $form = array();

  $form['core'] = array(
    '#type' => 'fieldset',
    '#title' => 'HCBF core options',
  );

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'hcbf_festival')
    ->propertyOrderBy('title', 'ASC');

  $result = $query->execute();
  $festival_nids = array_keys($result['node']);

  $festivals = array(
    0 => 'None',
  );

  foreach ($festival_nids as $festival) {
    $festival_entity = entity_metadata_wrapper('node', $festival);
    $festivals[$festival] = $festival_entity->label();
  }

  $form['core']['hcbf_current_festival'] = array(
    '#type' => 'select',
    '#title' => t('Current festival'),
    '#default_value' => variable_get('hcbf_current_festival', '0'),
    '#options' => $festivals,
    '#description' => t('Select the current festival.'),
  );

  $form['core']['hcbf_core_on_sale'] = array(
    '#type' => 'select',
    '#title' => t('Are tickets on sale?'),
    '#default_value' => variable_get('hcbf_core_on_sale', 0),
    '#options' => array(
      0 => 'No',
      1 => 'Yes',
    ),
    '#description' => t('Are ticketes on sale?'),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}
