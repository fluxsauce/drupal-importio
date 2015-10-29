<?php
/**
 * @file
 * school_ratings.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function school_ratings_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_schools:schools.
  $menu_links['main-menu_schools:schools'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'schools',
    'router_path' => 'schools',
    'link_title' => 'Schools',
    'options' => array(
      'identifier' => 'main-menu_schools:schools',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Schools');

  return $menu_links;
}
