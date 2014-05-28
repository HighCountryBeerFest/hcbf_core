<?php
/**
 * @file
 * Forms for the High Country Beer Fest's contact form.
 */

/**
 * Contact form
 */
function hcbf_contact_form($form, &$form_state) {

  // Protect the form with honeypot
  honeypot_add_form_protection($form, $form_state, array('honeypot', 'time_restriction'));

  $form = array(
    '#attributes' => array('role' => array('form')),
    '#prefix' => '<div class="wrapper form-wrapper"><div class="container"><div class="row"><div class="col-xs-12">',
    '#suffix' => '</div></div></div></div>'
  );

  $form['contact_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Your name'),
    '#required' => TRUE,
  );

  $form['contact_email'] = array(
    '#type' => 'textfield',
    '#title' => t('Your e-mail address'),
    '#required' => TRUE,
  );

  $form['contact_message'] = array(
    '#type' => 'textarea',
    '#title' => t('Your message'),
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Contact us'),
    '#attributes' => array('class' => array('btn-success')),
  );

  return $form;
}

/**
 * Validation function for the contact form
 */
function hcbf_contact_form_validate($form, &$form_state) {
  if (!valid_email_address($form_state['values']['contact_email'])) {
    form_set_error('contact_email', t('That e-mail address is not valid.'));
  }
}

/**
 * Submit function for the contact form
 */
function hcbf_contact_form_submit($form, &$form_state) {
  hcbf_contact_send_mail($form_state['values']);
}

