<?php
/**
 * @file
 * hcbf_volunteers.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function hcbf_volunteers_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-hcbf_volunteer-field_hcbf_volunteer_accepted'
  $field_instances['node-hcbf_volunteer-field_hcbf_volunteer_accepted'] = array(
    'bundle' => 'hcbf_volunteer',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select if the volunteer is selected for the festival.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_hcbf_volunteer_accepted',
    'label' => 'Accepted',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-hcbf_volunteer-field_hcbf_volunteer_comments'
  $field_instances['node-hcbf_volunteer-field_hcbf_volunteer_comments'] = array(
    'bundle' => 'hcbf_volunteer',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_hcbf_volunteer_comments',
    'label' => 'Comments',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-hcbf_volunteer-field_hcbf_volunteer_dob'
  $field_instances['node-hcbf_volunteer-field_hcbf_volunteer_dob'] = array(
    'bundle' => 'hcbf_volunteer',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'A date of birth for this volunteer.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_hcbf_volunteer_dob',
    'label' => 'Date of birth',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -1,
    ),
  );

  // Exported field_instance: 'node-hcbf_volunteer-field_hcbf_volunteer_email'
  $field_instances['node-hcbf_volunteer-field_hcbf_volunteer_email'] = array(
    'bundle' => 'hcbf_volunteer',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'An email address for this volunteer.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'email',
        'settings' => array(),
        'type' => 'email_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_hcbf_volunteer_email',
    'label' => 'Email',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => -3,
    ),
  );

  // Exported field_instance: 'node-hcbf_volunteer-field_hcbf_volunteer_gender'
  $field_instances['node-hcbf_volunteer-field_hcbf_volunteer_gender'] = array(
    'bundle' => 'hcbf_volunteer',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_hcbf_volunteer_gender',
    'label' => 'Gender',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 31,
    ),
  );

  // Exported field_instance: 'node-hcbf_volunteer-field_hcbf_volunteer_job'
  $field_instances['node-hcbf_volunteer-field_hcbf_volunteer_job'] = array(
    'bundle' => 'hcbf_volunteer',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select this volunteer\'s job.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_hcbf_volunteer_job',
    'label' => 'Job',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-hcbf_volunteer-field_hcbf_volunteer_name'
  $field_instances['node-hcbf_volunteer-field_hcbf_volunteer_name'] = array(
    'bundle' => 'hcbf_volunteer',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The name of the volunteer.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_hcbf_volunteer_name',
    'label' => 'Name',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -4,
    ),
  );

  // Exported field_instance: 'node-hcbf_volunteer-field_hcbf_volunteer_phone'
  $field_instances['node-hcbf_volunteer-field_hcbf_volunteer_phone'] = array(
    'bundle' => 'hcbf_volunteer',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'A phone number for this volunteer.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_hcbf_volunteer_phone',
    'label' => 'Phone',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => -2,
    ),
  );

  // Exported field_instance: 'node-hcbf_volunteer-field_hcbf_volunteer_shift'
  $field_instances['node-hcbf_volunteer-field_hcbf_volunteer_shift'] = array(
    'bundle' => 'hcbf_volunteer',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Select the shift this volunteer will be part of.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_hcbf_volunteer_shift',
    'label' => 'Shift',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-hcbf_volunteer-field_hcbf_volunteer_shirt'
  $field_instances['node-hcbf_volunteer-field_hcbf_volunteer_shirt'] = array(
    'bundle' => 'hcbf_volunteer',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'The shirt size for this volunteer.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_hcbf_volunteer_shirt',
    'label' => 'Shirt Size',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-hcbf_volunteer-field_hcbf_volunteer_volunteer'
  $field_instances['node-hcbf_volunteer-field_hcbf_volunteer_volunteer'] = array(
    'bundle' => 'hcbf_volunteer',
    'default_value' => array(
      0 => array(
        'value' => 'no',
      ),
    ),
    'deleted' => 0,
    'description' => 'Have you volunteered before?',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_hcbf_volunteer_volunteer',
    'label' => 'Volunteered Before?',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('A date of birth for this volunteer.');
  t('A phone number for this volunteer.');
  t('Accepted');
  t('An email address for this volunteer.');
  t('Comments');
  t('Date of birth');
  t('Email');
  t('Gender');
  t('Have you volunteered before?');
  t('Job');
  t('Name');
  t('Phone');
  t('Select if the volunteer is selected for the festival.');
  t('Select the shift this volunteer will be part of.');
  t('Select this volunteer\'s job.');
  t('Shift');
  t('Shirt Size');
  t('The name of the volunteer.');
  t('The shirt size for this volunteer.');
  t('Volunteered Before?');

  return $field_instances;
}
