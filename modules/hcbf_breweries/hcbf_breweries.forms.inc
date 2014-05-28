<?php
/**
 * @file
 * Forms for the High Country Craft Food and Beverage Festival's brewery functionality.
 */

/**
 * Brewery registeration form
 */
function hcbf_brewery_registration_form($form, &$form_state) {

  // Protect the form with honeypot
  honeypot_add_form_protection($form, $form_state, array('honeypot', 'time_restriction'));

  $form = array(
    '#attributes' => array('role' => array('form')),
    '#prefix' => '<div id="brewery-register-wrapper" class="wrapper"><div class="container"><div class="row"><div class="col-xs-12">',
    '#suffix' => '</div></div></div></div>'
  );

  if (variable_get('hcbf_breweries_active', 0) == 1) {

    $form['info'] = array(
      '#markup' => variable_get('hcbf_breweries_intro', 'Use this form to register a brewery for the ' . variable_get('site_name', 'Drupal')),
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );

    $form['brewery_info'] = array(
      '#type' => 'fieldset',
      '#title' => t('Information about your brewery'),
    );

    $form['brewery_info']['brewery_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Brewery name'),
      '#description' => t('Enter the name of your brewery.'),
      '#required' => TRUE,
    );

    $form['brewery_info']['brewery_address_1'] = array(
      '#type' => 'textfield',
      '#description' => t('Enter the first line of your brewery\'s address.'),
      '#title' => t('Brewery address line 1'),
      '#required' => TRUE,
    );

    $form['brewery_info']['brewery_address_2'] = array(
      '#type' => 'textfield',
      '#description' => t('Optionally enter the second line of your brewery\'s address.'),
      '#title' => t('Brewery address line 2'),
      '#required' => FALSE,
    );

    $form['brewery_info']['brewery_city'] = array(
      '#type' => 'textfield',
      '#title' => t('Brewery city'),
      '#description' => t('Enter your brewery\'s city.'),
      '#required' => TRUE,
    );

    $form['brewery_info']['brewery_state'] = array(
      '#type' => 'textfield',
      '#title' => t('Brewery state'),
      '#description' => t('Enter your brewery\'s state.'),
      '#required' => TRUE,
    );

    $form['brewery_info']['brewery_zip'] = array(
      '#type' => 'textfield',
      '#title' => t('Brewery zip code'),
      '#description' => t('Enter your brewery\'s zipcode.'),
      '#required' => TRUE,
    );

    $form['brewery_info']['brewery_website'] = array(
      '#type' => 'textfield',
      '#title' => t('Brewery website'),
      '#description' => t('Enter your brewery\'s website.'),
      '#required' => TRUE,
    );

    $form['contact_wrapper_open'] = array(
      '#prefix' => '<div class="row">',
      '#suffix' => '<div class="col-xs-12 col-md-6">',
    );

    $form['primary_contact_info'] = array(
      '#type' => 'fieldset',
      '#title' => '<span class="glyphicon glyphicon-user"></span> ' . t('Primary contact person')
    );

    $form['primary_contact_info']['info'] = array(
      '#markup' => 'We need some information about the person who will be the primary contact for your brewery.',
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );
    
    $form['primary_contact_info']['primary_contact_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Primary contact name'),
      '#required' => TRUE,
    );

    $form['primary_contact_info']['primary_main_contact_phone'] = array(
      '#type' => 'textfield',
      '#title' => t('Primary contact phone number'),
      '#required' => TRUE,
    );

    $form['primary_contact_info']['primary_email_address'] = array(
      '#type' => 'textfield',
      '#title' => t('Primary contact email address'),
      '#required' => TRUE,
    );

    $form['contact_wrapper_col_1_close'] = array(
      '#prefix' => '</div>',
      '#suffix' => '<div class="col-xs-12 col-md-6">',
    );

    $form['secondary_contact_info'] = array(
      '#type' => 'fieldset',
      '#title' => '<span class="glyphicon glyphicon-user"></span> ' . t('Secondary contact person')
    );
    
    $form['secondary_contact_info']['info'] = array(
      '#markup' => 'We need some information about the person who will be the secondary contact for your brewery.',
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );

    $form['secondary_contact_info']['secondary_contact_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Secondary contact name'),
    );

    $form['secondary_contact_info']['secondary_main_contact_phone'] = array(
      '#type' => 'textfield',
      '#title' => t('Secondary main phone number'),
    );

    $form['secondary_contact_info']['secondary_email_address'] = array(
      '#type' => 'textfield',
      '#title' => t('Secondary contact email address'),
    );

    $form['contact_wrapper_col_2_close'] = array(
      '#prefix' => '</div>',
      '#suffix' => '</div>',
    );

    $form['product_info'] = array(
      '#type' => 'fieldset',
      '#title' => t('Additional product &amp; brewery information')
    );

    $form['product_info']['product_delivery'] = array(
      '#type' => 'radios',
      '#title' => t('Who will deliver your product?'),
      '#required' => TRUE,
      '#options' => array(
        'brewery' => t('Brewery'),
        'distributor' => t('Distributor')
      ),
      '#default_value' => 'brewery',
    );

    $form['product_info']['distributor_name'] = array(
      '#type' => 'textfield',
      '#title' => t('The name of your distributor'),
      '#required' => FALSE,
    );

    $form['product_info']['brewery_beers_bringing'] = array(
      '#type' => 'textarea',
      '#title' => t('What beers do you plan to bring?'),
      '#required' => FALSE,
    );

    $form['product_info']['brewery_staff'] = array(
      '#type' => 'radios',
      '#title' => t('Are you bringing your own staff to pour beer?'),
      '#description' => t('If you check "yes", we will contact you for additional information.'),
      '#required' => TRUE,
      '#options' => array(
        0 => t('No'),
        1 => t('Yes')
      ),
      '#default_value' => 0,
    );

    $form['product_info']['brewery_staff_names'] = array(
      '#type' => 'textarea',
      '#title' => t('Names of staff'),
      '#required' => FALSE,
    );

    $form['product_info']['brewery_hotel'] = array(
      '#type' => 'radios',
      '#title' => t('Do you need a hotel room?'),
      '#description' => t('If you check "yes", we will contact you for additional information.'),
      '#required' => TRUE,
      '#options' => array(
        0 => t('No'),
        1 => t('Yes')
      ),
      '#default_value' => 0,
    );

    $form['product_info']['brewery_hotel_night'] = array(
      '#type' => 'radios',
      '#title' => t('What night do you need a hotel room?'),
      '#description' => t('Select the night you need a holtel room'),
      '#required' => FALSE,
      '#options' => array(
        'friday' => t('Friday'),
        'saturday' => t('Saturday'),
        'both' => t('Both nights'),
      ),
    );

    $form['product_info']['brewery_hotel_bed'] = array(
      '#type' => 'radios',
      '#title' => t('What size bed do you need?'),
      '#description' => t('Select size bed you need.'),
      '#required' => FALSE,
      '#options' => array(
        'king' => t('King'),
        'double' => t('Double'),
      ),
    );

    $form['comments'] = array(
      '#type' => 'textarea',
      '#title' => t('Additional comments/requests'),
      '#required' => FALSE,
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Sign me up'),
      '#attributes' => array('class' => array('btn-success')),
    );
  }
  else {
    // Message about brewery registeration being closed
    $contact_link = l('contact us', 'contact');
    $message = 'We\'re sorry but brewery registration is closed. If you have any questions please ' . $contact_link . '.';
    $form['info'] = array(
      '#markup' => $message,
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );
  }

  return $form;
}

/** 
 * Submit function for the brewery signup form.
 */
function hcbf_brewery_registration_form_submit($form, &$form_state) {
  // See: String offset cast notice in field_invoke_method_multiple() (https://drupal.org/node/1824820)
  $brewery = entity_create('node', array('type' => 'hcbf_brewery'));
  $brewery_entity = entity_metadata_wrapper('node', $brewery);

  // Brewery information
  $brewery_entity->field_hcbf_brewery_name->set(filter_xss($form_state['values']['brewery_name']));
  $brewery_entity->field_hcbf_brewery_brewery_addy1->set(filter_xss($form_state['values']['brewery_address_1']));
  $brewery_entity->field_hcbf_brewery_brewery_addy2->set(filter_xss($form_state['values']['brewery_address_2']));
  $brewery_entity->field_hcbf_brewery_brewery_city->set(filter_xss($form_state['values']['brewery_city']));
  $brewery_entity->field_hcbf_brewery_brewery_state->set(filter_xss($form_state['values']['brewery_state']));
  $brewery_entity->field_hcbf_brewer_brewery_zip->set(filter_xss($form_state['values']['brewery_zip']));
  $brewery_entity->field_hcbf_brewery_brewery_url->set(filter_xss($form_state['values']['brewery_website']));

  // Primary contact information
  $brewery_entity->field_hcbf_brewery_primary_name->set(filter_xss($form_state['values']['primary_contact_name']));
  $brewery_entity->field_hcbf_brewery_primary_phone->set(filter_xss($form_state['values']['primary_main_contact_phone']));
  $brewery_entity->field_hcbf_brewery_primary_email->set(filter_xss($form_state['values']['primary_email_address']));

  // Secondary contact information
  $brewery_entity->field_hcbf_brewery_second_name->set(filter_xss($form_state['values']['secondary_contact_name']));
  $brewery_entity->field_hcbf_brewery_second_phone->set(filter_xss($form_state['values']['secondary_main_contact_phone']));
  $brewery_entity->field_hcbf_brewery_second_email->set(filter_xss($form_state['values']['secondary_email_address']));

  // Product information
  $brewery_entity->field_hcbf_brewery_deliver->set(filter_xss($form_state['values']['product_delivery']));
  $brewery_entity->field_hcbf_brewery_distributer->set(filter_xss($form_state['values']['distributor_name']));
  $brewery_entity->field_hcbf_brewery_beers->set(filter_xss($form_state['values']['brewery_beers_bringing']));
  $brewery_entity->field_hcbf_brewery_staff->set(filter_xss($form_state['values']['brewery_staff']));
  $brewery_entity->field_hcbf_brewery_staff_members->set(filter_xss($form_state['values']['brewery_staff_names']));
  $brewery_entity->field_hcbf_brewery_hotel->set(filter_xss($form_state['values']['brewery_hotel']));
  $brewery_entity->field_hcbf_brewery_hotel_night->set(filter_xss($form_state['values']['brewery_hotel_night']));
  $brewery_entity->field_hcbf_brewery_hotel_bed->set(filter_xss($form_state['values']['brewery_hotel_bed']));

  // Additional comments
  $brewery_entity->field_hcbf_brewery_comments->set(filter_xss($form_state['values']['comments']));

  $brewery_entity->field_hcbf_brewery_accepted->set('no');
  $brewery_entity->status->set(1);

  // Save the entity
  $brewery_entity->save();

  drupal_set_message(t('Thank you for registering your brewery for the High Country Beer Festival. We will be in contact with you soon.'));
}

/**
 * Callback for the breweries/settings form.
 */
function hcbf_breweries_settings_form() {
  $form = array(
    '#attributes' => array('role' => array('form')),
    '#prefix' => '<div id="volunteer-register-wrapper" class="wrapper"><div class="container"><div class="row"><div class="col-xs-12">',
    '#suffix' => '</div></div></div></div>'
  );

  $form['hcbf_breweries_active'] = array(
    '#type' => 'radios',
    '#title' => t('Is them brewery signup form active?'),
    '#default_value' => variable_get('hcbf_breweries_active', 0),
    '#options' => array(
      0 => t('No'),
      1 => t('Yes')
    ),
  );

  $form['hcbf_breweries_intro'] = array(
    '#type' => 'textarea',
    '#title' => t('Intro message'),
    '#default_value' => variable_get('hcbf_breweries_intro', ''),
    '#description' => t('This message displays on the top of the brewery signup form.')
  );

  return system_settings_form($form);
}
