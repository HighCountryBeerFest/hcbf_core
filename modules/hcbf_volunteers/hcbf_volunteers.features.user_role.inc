<?php
/**
 * @file
 * hcbf_volunteers.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function hcbf_volunteers_user_default_roles() {
  $roles = array();

  // Exported role: Volunteer Manager.
  $roles['Volunteer Manager'] = array(
    'name' => 'Volunteer Manager',
    'weight' => 2,
  );

  return $roles;
}
