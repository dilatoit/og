<?php

/*
 * @file
 *
 * Altering menu item edit form.
 *
 */


/**
 * Implementation of hook_form_FORM_ID_alter().
 */
function menu_token_form_menu_edit_item_alter(&$form, &$form_state) {
  // Create new fieldset
  $form['menu']['token'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#weight' => -1,
  );

  // Move form elements to the new fieldset.
  $form['menu']['token']['link_title'] = $form['menu']['link_title'];
  unset($form['menu']['link_title']);
  $form['menu']['token']['link_path'] = $form['menu']['link_path'];
  unset($form['menu']['link_path']);
  
  // Load saved token pathes.
  $menu_token_item = menu_token_get($form['menu']['mlid']['#value']);
  
  // Replace fake path (<front>) with user inputed one.
  if ($menu_token_item) {
    $form['menu']['token']['link_path']['#default_value'] = $menu_token_item['link_path'];
  }

  $form['menu']['token']['token_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use tokens in title and in path.'),
    '#default_value' => isset($menu_token_item),
  );

  // Token substitutions help.
  $form['menu']['token']['token_help'] = array(
    '#title' => t('Replacement patterns'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['menu']['token']['token_help']['help'] = array(
    '#value' => theme('token_help', 'global'),
  );

  // Add custom validation and submit functions.
  array_unshift($form['#validate'], 'menu_token_form_menu_edit_item_validate');
  $form['#submit'][] = 'menu_token_form_menu_edit_item_submit';
}


/**
 * Custom validation for form menu_edit_item.
 */
function menu_token_form_menu_edit_item_validate($form, &$form_state) {
  // If token replacing enabled.
  if ($form_state['values']['menu']['token']['token_enabled']) {
    // Substitute link_path with fake well known '<front>'.
    $form_state['values']['menu']['link_title'] = $form_state['values']['menu']['token']['link_title'];
    $form_state['values']['menu']['link_path'] = '<front>';
    // Set 'alter' option to use hook_translated_menu_link().
    $form_state['values']['menu']['options']['alter'] = TRUE;
  }
  else {
    $form_state['values']['menu']['link_title'] = $form_state['values']['menu']['token']['link_title'];
    $form_state['values']['menu']['link_path'] = $form_state['values']['menu']['token']['link_path'];
  }
}


/**
 * Custom submit function for form menu_edit_form.
 */
function menu_token_form_menu_edit_item_submit($form, &$form_state) {
  $mlid = $form_state['values']['menu']['mlid'];
  if (!$form_state['values']['menu']['token']['token_enabled']) {
    menu_token_unset($mlid);
  }
  else {
    menu_token_set($mlid, array(
      'link_path' => trim($form_state['values']['menu']['token']['link_path'])
    ));
  }
}