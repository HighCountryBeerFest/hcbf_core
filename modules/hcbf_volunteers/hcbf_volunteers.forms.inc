<?php
/**
 * @file
 * Forms for the High Country Craft Food and Beverage Festival's volunteer functionality.
 */

/**
 * Volunteer form
 */
function hcbf_volunteer_form($form, &$form_state) {

  // Protect the form with honeypot
  honeypot_add_form_protection($form, $form_state, array('honeypot', 'time_restriction'));

  $form = array(
    '#attributes' => array('role' => array('form')),
    '#prefix' => '<div class="wrapper form-wrapper"><div class="container"><div class="row"><div class="col-xs-12">',
    '#suffix' => '</div></div></div></div>'
  );

  if (variable_get('hcbf_volunteer_active', 0) == 1) {
    $form['info'] = array(
      '#markup' => variable_get('hcbf_volunteer_intro', 'Fill out this form to volunteer for the High Country Craft Food and Beverage Festival.'),
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );

    $form['volunteer_wrapper_open'] = array(
      '#prefix' => '<div class="row">',
      '#suffix' => '<div class="col-xs-12 col-md-6">',
    );

    // The form is open for submission
    $form['personal_info'] = array(
      '#type' => 'fieldset',
      '#title' => t('Personal Information')
    );

    $form['personal_info']['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Your full name'),
      '#description' => t('Enter your full name.'),
      '#required' => TRUE,
      '#attributes' => array('placeholder' => array('Your Name')),
    );

    $form['personal_info']['email'] = array(
      '#type' => 'textfield',
      '#title' => t('Your email address'),
      '#description' => t('Enter an email address that we can contact you at.'),
      '#required' => TRUE,
      '#rules' => array('email'),
      '#attributes' => array('placeholder' => array('you@domain.com')),
    );

    $form['personal_info']['phone'] = array(
      '#type' => 'textfield',
      '#title' => t('Your phone number'),
      '#description' => t('Enter a phone number where we can contact you.'),
      '#required' => TRUE,
      '#attributes' => array('placeholder' => array('(555) 555-5555')),
    );

    $form['personal_info']['dob'] = array(
      '#type' => 'textfield',
      '#title' => t('Your birthday'),
      '#description' => t('Enter your date of birth. You must 21 or older to volunteer.'),
      '#required' => TRUE,
      '#attributes' => array('placeholder' => array('6/19/1985')),
    );

    $form['volunteer_wrapper_col_1_close'] = array(
      '#prefix' => '</div>',
      '#suffix' => '<div class="col-xs-12 col-md-6">',
    );

    $form['other_info'] = array(
      '#type' => 'fieldset',
      '#title' => t('Other Information')
    );

    $form['other_info']['reference'] = array(
      '#type' => 'textfield',
      '#title' => t('Referenced by'),
      '#description' => t('Who refered you to be a volunteer?'),
    );

    $form['other_info']['shirt'] = array(
      '#type' => 'radios',
      '#title' => t('Your shirt size'),
      '#options' => array(
        'small' => t('Small'),
        'medium' => t('Medium'),
        'large' => t('Large'),
        'x-large' => t('X-large'),
        'xx-large' => t('XX-large')
      ),
    );

    $form['other_info']['previous_volunteer'] = array(
      '#type' => 'radios',
      '#title' => t('Have you volunteered before?'),
      '#options' => array(
        'no' => t('No'),
        'yes' => t('Yes'),
      ),
    );

    $form['other_info']['comments'] = array(
      '#type' => 'textarea',
      '#title' => t('Additional information'),
      '#description' => t('Please describe your previous experience with other festivals, time limitations due to other responsibilities, and any additional information.'),
    );

    $form['volunteer_wrapper_col_2_close'] = array(
      '#prefix' => '</div>',
      '#suffix' => '</div>',
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Sign me up'),
      '#attributes' => array('class' => array('btn-success')),
    );
  }
  else {
    // Message about volunteer registeration being closed
    $contact_link = l('contact us', 'contact');
    $message = 'We\'re sorry but volunteer registration is closed. If you have any questions please ' . $contact_link . '.';
    $form['info'] = array(
      '#markup' => $message,
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );
  }

  return $form;
}

/**
 * Validation for the volunteer form
 */
function hcbf_volunteer_form_validate($form, &$form_state) {
  // Validate that the person attempting to volunteer is 21 or older.
  // See: http://drupalcode.org/project/validateage.git/blob/refs/heads/6.x-1.x:/validateage.module#l540
}

/**
 * Submit function for the volunteer form
 */
function hcbf_volunteer_form_submit($form, &$form_state) {
  // Create a volunteer node
  $volunteer = entity_create('node', array('type' => 'hcbf_volunteer'));
  $volunteer_entity = entity_metadata_wrapper('node',$volunteer);
  $volunteer_entity->field_hcbf_volunteer_name->set(filter_xss($form_state['values']['name']));
  $volunteer_entity->field_hcbf_volunteer_email->set(filter_xss($form_state['values']['email']));
  $volunteer_entity->field_hcbf_volunteer_phone->set(filter_xss($form_state['values']['phone']));
  $volunteer_entity->field_hcbf_volunteer_dob->set(filter_xss($form_state['values']['dob']));
  $volunteer_entity->field_hcbf_volunteer_shirt->set(filter_xss($form_state['values']['shirt']));
  $volunteer_entity->field_hcbf_volunteer_volunteer->set(filter_xss($form_state['values']['previous_volunteer']));
  $volunteer_entity->field_hcbf_volunteer_comments->set(filter_xss($form_state['values']['comments']));
  $volunteer_entity->field_hcbf_volunteer_accepted->set('no');
  $volunteer_entity->save();

  hcbf_volunteers_send_mail($form_state['values']);

  // Notify the responsable role a volunteer has volunteered
}

/**
 * Callback for the volunteer/settings form.
 */
function hcbf_volunteer_settings_form() {
  $form = array(
    '#attributes' => array('role' => array('form')),
    '#prefix' => '<div id="volunteer-register-wrapper" class="wrapper"><div class="container"><div class="row"><div class="col-xs-12">',
    '#suffix' => '</div></div></div></div>'
  );

  $form['hcbf_volunteer_active'] = array(
    '#type' => 'radios',
    '#title' => t('Is volunteer active?'),
    '#default_value' => variable_get('hcbf_volunteer_active', 0),
    '#options' => array(
      0 => t('No'),
      1 => t('Yes')
    ),
  );

  $form['hcbf_volunteer_intro'] = array(
    '#type' => 'textarea',
    '#title' => t('Intro message'),
    '#default_value' => variable_get('hcbf_volunteer_intro', ''),
    '#description' => t('This message displays on the top of the Volunteer form.')
  );

  return system_settings_form($form);
}

