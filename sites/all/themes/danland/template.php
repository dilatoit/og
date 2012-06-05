<?php
// $Id: template.php,v 1.10 2010/07/19 22:05:33 danprobo Exp $
function phptemplate_body_class($left, $right) {
	if ($left && $right) {
		$class = 'sidebars-2';
		$id = 'sidebar-side-2';	
	}
	else if ($left || $right) {
		$class = 'sidebars-1';
		$id = 'sidebar-side-1';
	}
	
	if(isset($class)) {
		print ' class="'. $class .'"';
	}
		if(isset($id)) {
		print ' id="'. $id .'"';
	}
}

if (drupal_is_front_page()) {
  drupal_add_js(drupal_get_path('theme', 'danland') . '/scripts/jquery.cycle.all.js');
}


/**
* Override theme_breadcrumb().
*/
function danland_breadcrumb($breadcrumb) {
  $links = array();
  $title = '';
  $path = '';
  // Get URL arguments
  $arguments = explode('/', request_uri());
  $arguments = array_values($arguments);
  $count_array = count($arguments);
  $title = t('Homepage');
  $path = '<front>';
  $links[] = l($title,$path);
  if ($count_array ==4 && $arguments[2] == 'pm') {
    $title = t('Project Management');
    $links[] = $title;
  }
  elseif ($count_array ==4 && $arguments[2] == 'rm') {
    $title = t('Resource Management');
    $links[] = $title;
  }
  elseif ($count_array ==5 && $arguments[2] == 'pm' && $arguments[4] == 'daily-report') {
    $title = t('Project Management');
    $path = "pm/$arguments[3]";
    $links[] = l($title,$path);
    $title = 'Report';
    $links[] = $title;
  }
  elseif ($count_array ==5 && $arguments[2] == 'rm' && $arguments[4] == 'resource-assignments') {
    $title = t('Resource Management');
    $path = "rm/$arguments[3]";
    $links[] = l($title,$path);
    $title = 'Resource Assignment';
    $links[] = $title;
  }
  elseif ($count_array ==5 && $arguments[2] == 'rm' && $arguments[4] == 'timesheets') {
    $title = t('Resource Management');
    $path = "rm/$arguments[3]";
    $links[] = l($title,$path);
    $title = 'Timesheet';
    $links[] = $title;
  }
  elseif ($count_array ==5 && $arguments[2] == 'book' && $arguments[4] == 'list') {
    $title = t('Knowledge Management');
    $links[] = $title;
  }
  elseif ($count_array ==5 && $arguments[2] == 'km' && $arguments[4] == 'queries') {
    $title = t('Knowledge Management');
    $path = "book/$arguments[3]/list";
    $links[] = l($title,$path);
    $title = 'Query Collection';
    $links[] = $title;
  }
  elseif ($count_array ==4 && $arguments[2] == 'node') {
    $node = node_load($arguments[3]);
    $type = $node->type;
    if ($type == 'management_issue') {
      $title = t('Customer Portal');
      $group = $node->og_groups;
      $site_id;
      foreach ($group as $key => $value) {
        $site_id = $key;
      }
      $path = "node/$site_id";
      $links[] = l($title,$path);
      $title = "$node->title";
      $links[] = $title;
    }
    elseif ($type == 'query') {
      $title = t('Customer Portal');
      $group = $node->og_groups;
      $site_id;
      foreach ($group as $key => $value) {
        $site_id = $key;
      }
      $path = "node/$site_id";
      $links[] = l($title,$path);
      $title = "$node->title";
      $links[] = $title;
    }
	elseif ($type == 'daily_tracking') {
      $title = t('Project Management');
      $group = $node->og_groups;
      $site_id;
      foreach ($group as $key => $value) {
        $site_id = $key;
      }
      $path = "node/$site_id";
      $links[] = l($title,$path);
      $title = 'Report';
      $path = "node/$site_id/daily-report";
      $links[] = l($title,$path);
      $title = "$node->title";
      $links[] = $title;
    }
    elseif ($type == 'book') {
	  $title = t('Knowledge Management');
      $group = $node->og_groups;
      $site_id;
      foreach ($group as $key => $value) {
        $site_id = $key;
      }
      $path = "book/$site_id/list";
      $links[] = l($title,$path);
      $title = "$node->title";
      $links[] = $title;
    }
  }
  // Set custom breadcrumbs
  drupal_set_breadcrumb($links);
  // Get custom breadcrumbs
  $breadcrumb = drupal_get_breadcrumb();
  // Hide breadcrumbs if only 'Home' exists
  if (count($breadcrumb) > 1) {
    return '<div class="breadcrumb">'. implode(' &raquo; ', $breadcrumb) .'</div>';
  }
}