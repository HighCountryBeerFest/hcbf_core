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

  $form = array();
  $form['#attributes'] = array('role' => array('form'));

  if (variable_get('hcbf_volunteer_active', 0) == 1) {
    // The form is open for submission
    $form['info'] = array(
      '#markup' => 'A short description of what we\'re looing for in volunteers and the responsibilities associated with volunteering.',
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );

    $form['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Your name'),
      '#required' => TRUE
    );

    $form['email'] = array(
      '#type' => 'textfield',
      '#title' => t('Email address'),
      '#required' => TRUE
    );

    $form['date_of_birth'] = array(
      '#type' => 'textfield',
      '#title' => t('Date of birth'),
      '#required' => TRUE
    );

    $form['shirt_size'] = array(
      '#type' => 'select',
      '#title' => t('T-shirt size'),
      '#required' => TRUE,
      '#options' => array(
        'small' => t('Small'),
        'medium' => t('Medium'),
        'large' => t('Large'),
        'x-large' => t('X-large'),
        'xx-large' => t('XX-large')
      ),
    );

    $form['previous_volunteer'] = array(
      '#type' => 'radios',
      '#title' => t('Have you volunteered before?'),
      '#required' => TRUE,
      '#options' => array(
        'no' => t('No'),
        'yes' => t('Yes'),
      ),
      '#default_value' => 'no',
    );

    $form['background'] = array(
      '#type' => 'checkboxes',
      '#title' => t('What is your background?'),
      '#required' => FALSE,
      '#options' => array(
        'brewer' => t('Brewer'),
        'enthusiast' => t('Enthusiast'),
      ),
    );

    $form['comments'] = array(
      '#type' => 'textarea',
      '#title' => t('Comments')
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Volunteer')
    );
  }
  else {
    // Message about volunteer registeration being closed
    $form['info'] = array(
      '#markup' => 'We\'re sorry but volunteer registration is closed.',
      '#prefix' => '<p>',
      '#suffix' => '</p>',
    );
  }


  return $form;
}

