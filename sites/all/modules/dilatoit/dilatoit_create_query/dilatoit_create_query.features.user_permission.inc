<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function dilatoit_create_query_user_default_permissions() {
  $permissions = array();

  // Exported permission: create query content
  $permissions['create query content'] = array(
    'name' => 'create query content',
    'roles' => array(
      '0' => 'PL',
      '1' => 'PM',
      '2' => 'Team Member',
    ),
  );

  return $permissions;
}
