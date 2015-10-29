<?php
/**
 * @file
 * school_ratings.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function school_ratings_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'schools';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Schools';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Schools';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'api_score' => 'api_score',
    'class_sizes' => 'class_sizes',
    'location' => 'location',
    'parent_education' => 'parent_education',
    'state_rank' => 'state_rank',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'api_score' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'class_sizes' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'location' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'parent_education' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'state_rank' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['location']['id'] = 'location';
  $handler->display->display_options['fields']['location']['table'] = 'field_data_location';
  $handler->display->display_options['fields']['location']['field'] = 'location';
  /* Field: Content: API Score */
  $handler->display->display_options['fields']['api_score']['id'] = 'api_score';
  $handler->display->display_options['fields']['api_score']['table'] = 'field_data_api_score';
  $handler->display->display_options['fields']['api_score']['field'] = 'api_score';
  $handler->display->display_options['fields']['api_score']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: State Rank */
  $handler->display->display_options['fields']['state_rank']['id'] = 'state_rank';
  $handler->display->display_options['fields']['state_rank']['table'] = 'field_data_state_rank';
  $handler->display->display_options['fields']['state_rank']['field'] = 'state_rank';
  /* Field: Content: Parent Education */
  $handler->display->display_options['fields']['parent_education']['id'] = 'parent_education';
  $handler->display->display_options['fields']['parent_education']['table'] = 'field_data_parent_education';
  $handler->display->display_options['fields']['parent_education']['field'] = 'parent_education';
  /* Field: Content: Class Sizes */
  $handler->display->display_options['fields']['class_sizes']['id'] = 'class_sizes';
  $handler->display->display_options['fields']['class_sizes']['table'] = 'field_data_class_sizes';
  $handler->display->display_options['fields']['class_sizes']['field'] = 'class_sizes';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'school' => 'school',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Location (location) */
  $handler->display->display_options['filters']['location_value']['id'] = 'location_value';
  $handler->display->display_options['filters']['location_value']['table'] = 'field_data_location';
  $handler->display->display_options['filters']['location_value']['field'] = 'location_value';
  $handler->display->display_options['filters']['location_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['location_value']['group'] = 1;
  $handler->display->display_options['filters']['location_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['location_value']['expose']['operator_id'] = 'location_value_op';
  $handler->display->display_options['filters']['location_value']['expose']['label'] = 'Location';
  $handler->display->display_options['filters']['location_value']['expose']['description'] = 'Contains';
  $handler->display->display_options['filters']['location_value']['expose']['operator'] = 'location_value_op';
  $handler->display->display_options['filters']['location_value']['expose']['identifier'] = 'location_value';
  $handler->display->display_options['filters']['location_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: API Score (api_score) */
  $handler->display->display_options['filters']['api_score_value']['id'] = 'api_score_value';
  $handler->display->display_options['filters']['api_score_value']['table'] = 'field_data_api_score';
  $handler->display->display_options['filters']['api_score_value']['field'] = 'api_score_value';
  $handler->display->display_options['filters']['api_score_value']['operator'] = '>=';
  $handler->display->display_options['filters']['api_score_value']['group'] = 1;
  $handler->display->display_options['filters']['api_score_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['api_score_value']['expose']['operator_id'] = 'api_score_value_op';
  $handler->display->display_options['filters']['api_score_value']['expose']['label'] = 'API Score';
  $handler->display->display_options['filters']['api_score_value']['expose']['description'] = 'Greater than or equal to';
  $handler->display->display_options['filters']['api_score_value']['expose']['operator'] = 'api_score_value_op';
  $handler->display->display_options['filters']['api_score_value']['expose']['identifier'] = 'api_score_value';
  $handler->display->display_options['filters']['api_score_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: State Rank (state_rank) */
  $handler->display->display_options['filters']['state_rank_value']['id'] = 'state_rank_value';
  $handler->display->display_options['filters']['state_rank_value']['table'] = 'field_data_state_rank';
  $handler->display->display_options['filters']['state_rank_value']['field'] = 'state_rank_value';
  $handler->display->display_options['filters']['state_rank_value']['operator'] = '>=';
  $handler->display->display_options['filters']['state_rank_value']['group'] = 1;
  $handler->display->display_options['filters']['state_rank_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state_rank_value']['expose']['operator_id'] = 'state_rank_value_op';
  $handler->display->display_options['filters']['state_rank_value']['expose']['label'] = 'State Rank';
  $handler->display->display_options['filters']['state_rank_value']['expose']['description'] = 'Greater than or equal to';
  $handler->display->display_options['filters']['state_rank_value']['expose']['operator'] = 'state_rank_value_op';
  $handler->display->display_options['filters']['state_rank_value']['expose']['identifier'] = 'state_rank_value';
  $handler->display->display_options['filters']['state_rank_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Parent Education (parent_education) */
  $handler->display->display_options['filters']['parent_education_value']['id'] = 'parent_education_value';
  $handler->display->display_options['filters']['parent_education_value']['table'] = 'field_data_parent_education';
  $handler->display->display_options['filters']['parent_education_value']['field'] = 'parent_education_value';
  $handler->display->display_options['filters']['parent_education_value']['operator'] = '>=';
  $handler->display->display_options['filters']['parent_education_value']['group'] = 1;
  $handler->display->display_options['filters']['parent_education_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['parent_education_value']['expose']['operator_id'] = 'parent_education_value_op';
  $handler->display->display_options['filters']['parent_education_value']['expose']['label'] = 'Parent Education';
  $handler->display->display_options['filters']['parent_education_value']['expose']['description'] = 'Greater than or equal to';
  $handler->display->display_options['filters']['parent_education_value']['expose']['operator'] = 'parent_education_value_op';
  $handler->display->display_options['filters']['parent_education_value']['expose']['identifier'] = 'parent_education_value';
  $handler->display->display_options['filters']['parent_education_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'schools';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Schools';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $export['schools'] = $view;

  return $export;
}
