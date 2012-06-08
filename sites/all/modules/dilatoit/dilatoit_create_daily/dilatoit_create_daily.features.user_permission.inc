<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function dilatoit_create_daily_user_default_permissions() {
  $permissions = array();

  // Exported permission: create daily_tracking content
  $permissions['create daily_tracking content'] = array(
    'name' => 'create daily_tracking content',
    'roles' => array(
      '0' => 'PL',
      '1' => 'PM',
      '2' => 'Team Member',
    ),
  );

  return $permissions;
}
