<?php

/**
 * Implementation of hook_context_default_contexts().
 */
function menu_display_context_default_contexts() {
  $export = array();

  $context = new stdClass;
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'menu_display';
  $context->description = '';
  $context->tag = 'menu';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
        '~admin/*' => '~admin/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-primary-links' => array(
          'module' => 'menu',
          'delta' => 'primary-links',
          'region' => 'superfish_menu',
          'weight' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('menu');
  $export['menu_display'] = $context;

  return $export;
}
