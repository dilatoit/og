<?php

/**
 * Implementation of hook_node_info().
 */
function dilatoit_query_node_info() {
  $items = array(
    'query' => array(
      'name' => t('Query'),
      'module' => 'features',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'has_body' => '1',
      'body_label' => t('Details'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}
