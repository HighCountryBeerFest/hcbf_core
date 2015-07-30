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
    '#title' => t('HCBF core options'),
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

  $form['core']['hcbf_breweries_active'] = array(
    '#type' => 'select',
    '#title' => t('Brewery registration active'),
    '#default_value' => variable_get('hcbf_breweries_active', 0),
    '#options' => array(
      0 => 'No',
      1 => 'Yes',
    ),
    '#required' => TRUE,
  );

  $form['tickets'] = array(
    '#type' => 'fieldset',
    '#title' => t('Ticket info'),
  );

  $form['tickets']['hcbf_core_on_sale'] = array(
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

  $form['tickets']['regular'] = array(
    '#type' => 'fieldset',
    '#title' => t('Regular tickets'),
  );

  $form['tickets']['regular']['hcbf_core_regular_ticket_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Regular ticket link'),
    '#description' => t('Enter the URL for the regular ticket.'),
    '#default_value' => variable_get('hcbf_core_regular_ticket_link', ''),
    '#maxlength' => 512,
  );

  $form['tickets']['regular']['hcbf_core_regular_ticket_price'] = array(
    '#type' => 'textfield',
    '#title' => t('Regular ticket price'),
    '#description' => t('Enter the price for the regular ticket.'),
    '#default_value' => variable_get('hcbf_core_regular_ticket_price', ''),
  );

  $form['tickets']['vip'] = array(
    '#type' => 'fieldset',
    '#title' => t('VIP tickets'),
  );

  $form['tickets']['vip']['hcbf_core_vip_ticket_link'] = array(
    '#type' => 'textfield',
    '#title' => t('VIP ticket link'),
    '#description' => t('Enter the URL for the vip ticket.'),
    '#default_value' => variable_get('hcbf_core_vip_ticket_link', ''),
    '#maxlength' => 512,
  );

  $form['tickets']['vip']['hcbf_core_vip_ticket_price'] = array(
    '#type' => 'textfield',
    '#title' => t('VIP ticket price'),
    '#description' => t('Enter the price for the ticket.'),
    '#default_value' => variable_get('hcbf_core_vip_ticket_price', ''),
  );

  $form['tickets']['dd'] = array(
    '#type' => 'fieldset',
    '#title' => t('Designated driver tickets'),
  );

  $form['tickets']['dd']['hcbf_core_dd_ticket_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Designated driver ticket link'),
    '#description' => t('Enter the URL for the designated driver ticket.'),
    '#default_value' => variable_get('hcbf_core_dd_ticket_link', ''),
    '#maxlength' => 512,
  );

  $form['tickets']['dd']['hcbf_core_dd_ticket_price'] = array(
    '#type' => 'textfield',
    '#title' => t('Designated driver ticket price'),
    '#description' => t('Enter the price for the designated driver ticket.'),
    '#default_value' => variable_get('hcbf_core_dd_ticket_price', ''),
  );

  return system_settings_form($form);
}
