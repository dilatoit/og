<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function pm_administer_book_outlines_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer book outlines
  $permissions['administer book outlines'] = array(
    'name' => 'administer book outlines',
    'roles' => array(
      '0' => 'PM',
    ),
  );

  return $permissions;
}
