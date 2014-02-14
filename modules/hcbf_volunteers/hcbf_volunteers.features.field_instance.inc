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

  // Translatables
  // Included for use with string extractors like potx.
  t('Name');
  t('The name of the volunteer.');

  return $field_instances;
}
