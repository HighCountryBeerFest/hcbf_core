<?php
/**
 * @file
 * Forms for the High Country Craft Food and Beverage Festival's sponsors functionality.
 */

/**
 * sponsor registeration form
 */
function hcbf_sponsors_registration_form($form, &$form_state) {

  // Protect the form with honeypot
  honeypot_add_form_protection($form, $form_state, array('honeypot', 'time_restriction'));

  $form = array(
    '#attributes' => array('role' => array('form')),
    '#prefix' => '<div id="sponsor-register-wrapper" class="wrapper"><div class="container"><div class="row"><div class="col-xs-12">',
    '#suffix' => '</div></div></div></div>'
  );

  $form['sponsor_info'] = array(
    '#type' => 'fieldset',
    '#title' => t('Information about your business'),
  );

  $form['sponsor_info']['sponsor_business_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Business name'),
    '#description' => t('Enter the name of your business.'),
    '#required' => TRUE,
  );

  $form['sponsor_info']['sponsor_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Your name'),
    '#description' => t('The name of the primary person to contact.'),
    '#required' => TRUE,
  );

  $form['sponsor_info']['sponsor_phone'] = array(
    '#type' => 'textfield',
    '#title' => t('Your phone number'),
    '#required' => TRUE,
  );

  $form['sponsor_info']['sponsor_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Your email address'),
    '#required' => TRUE,
  );

  $form['sponsor_info']['sponsor_level'] = array(
    '#type' => 'radios',
    '#title' => t('Sponsorship level'),
    '#required' => TRUE,
    '#options' => array(
      1 => t('$250 - Listed in festival program, 2 t-shirts, 2 tickets.'),
      2 => t('$500 - Listed in festival program, 2 t-shirts, 4 tickets.'),
      3 => t('$1000 - Logo on t-shirt, listed in festival program, social media mentions, 4 t-shirts, 4 tickets.'),
      4 => t('$2500 - Logo on all marketing material, listed in festival program, social media mentions, 4 t-shirts, 8 tickets.'),
    ),
    '#default_value' => 1,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Sign me up'),
    '#attributes' => array('class' => array('btn-success')),
  );

  return $form;
}

/**
 * Validation function for the sponsorship registration form
 */
function hcbf_sponsors_registration_form_validate($form, &$form_state) {
  if (!valid_email_address($form_state['values']['sponsor_email'])) {
    form_set_error('sponsor_email', t('That e-mail address is not valid.'));
  }
}

function hcbf_sponsors_registration_form_submit($form, &$form_state) {
  // See: String offset cast notice in field_invoke_method_multiple() (https://drupal.org/node/1824820)
  $sponsor = entity_create('node', array('type' => 'hcbf_sponsor'));
  $sponsor_entity = entity_metadata_wrapper('node', $sponsor);

  // sponsor information
  $sponsor_entity->field_hcbf_sponsor_name->set(filter_xss($form_state['values']['sponsor_business_name']));
  $sponsor_entity->field_hcbf_sponsor_contact_name->set(filter_xss($form_state['values']['sponsor_name']));
  $sponsor_entity->field_hcbf_sponsor_contact_phone->set(filter_xss($form_state['values']['sponsor_email']));
  $sponsor_entity->field_hcbf_sponsor_sponsor_level->set(filter_xss($form_state['values']['sponsor_level']));

  $sponsor_entity->status->set(1);

  // Save the entity
  $sponsor_entity->save();

  drupal_set_message(t('Thank you for registering to sponsor the High Country Beer Festival. We will be in contact with you soon.'));
}
