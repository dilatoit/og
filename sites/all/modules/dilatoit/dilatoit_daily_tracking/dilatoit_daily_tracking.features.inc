<?php

/**
 * Implementation of hook_node_info().
 */
function dilatoit_daily_tracking_node_info() {
  $items = array(
    'daily_tracking' => array(
      'name' => t('Daily Tracking'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Daily report'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
