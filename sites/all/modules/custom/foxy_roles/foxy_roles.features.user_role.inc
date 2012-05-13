<?php

/**
 * Implementation of hook_user_default_roles().
 */
function foxy_roles_user_default_roles() {
  $roles = array();

  // Exported role: Developer
  $roles['Developer'] = array(
    'name' => 'Developer',
  );

  return $roles;
}
