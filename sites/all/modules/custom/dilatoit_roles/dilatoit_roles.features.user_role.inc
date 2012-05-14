<?php

/**
 * Implementation of hook_user_default_roles().
 */
function dilatoit_roles_user_default_roles() {
  $roles = array();

  // Exported role: Admin
  $roles['Admin'] = array(
    'name' => 'Admin',
  );

  // Exported role: Client
  $roles['Client'] = array(
    'name' => 'Client',
  );

  // Exported role: PL
  $roles['PL'] = array(
    'name' => 'PL',
  );

  // Exported role: PM
  $roles['PM'] = array(
    'name' => 'PM',
  );

  // Exported role: Team Member
  $roles['Team Member'] = array(
    'name' => 'Team Member',
  );

  return $roles;
}
