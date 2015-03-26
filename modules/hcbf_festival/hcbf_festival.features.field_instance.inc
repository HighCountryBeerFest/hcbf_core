<?php
/**
 * @file
 * hcbf_festival.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function hcbf_festival_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-hcbf_festival-field_hcbf_festival_date'
  $field_instances['node-hcbf_festival-field_hcbf_festival_date'] = array(
    'bundle' => 'hcbf_festival',
    'deleted' => 0,
    'description' => 'The date of the event.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
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
    'field_name' => 'field_hcbf_festival_date',
    'label' => 'Event date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - g:i:sa',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-10:+3',
      ),
      'type' => 'date_select',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Event date');
  t('The date of the event.');

  return $field_instances;
}
